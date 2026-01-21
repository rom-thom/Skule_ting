import matplotlib.pyplot as plt
import numpy as np
import sympy as sp


def feil_analyse(parameters: dict, utrykk, uvisse_variablar: dict, målte_verdiar: np.ndarray, std_uvisse: float, plot_it=True, antall_error_bars=50):
    """
    parameters: {sympy.symbols(variablane): verdiane til symbola som har konstantar.
    Dersom det er dei målte verdiane har du inn måledata (x-verdiane) som eit numpy.array(). parameters[sympy.symbols('x')] = x_verdiar  (må ikkje vere x)}
    
    utrykk: teoretisk utrykk med variablar som sympy.symbols
    
    uvisse_variablar: variablane som kan ha uvisse i utrykket dei skal innehalde uvissa til kvar variabel
    (uvissa til verdien vi har eit utrykk for er ikkje med), same form som parameters

    målte_verdiar: dei verdiane som blir målt, må vere like lang som x_verdiane i parameters. 

    Denne er bare rett dersom ein veit at variablane ikkje er avhengige og at det bare er ein variabel som er ei liste av mange tal. 
    """

    # Initialiserer fin visning av uttrykka
    sp.init_printing()

    # Plotteparametera for å få store, tydelige plott som utnytter tilgjengelig skjermareal
    fontsize = 20
    newparams = {'axes.titlesize': fontsize, 'axes.labelsize': fontsize,
                'lines.linewidth': 2, 'lines.markersize': 7,
                'figure.figsize': (16, 5), 'ytick.labelsize': fontsize,
                'xtick.labelsize': fontsize, 'legend.fontsize': fontsize,
                'legend.handlelength': 1.5} 
    plt.rcParams.update(newparams) # Dersom du lurar på kva dette er:   ¯\_(ツ)_/¯


    # Dette er kva som er verdien kor parameters[x_index] = liste av x_verdiar
    x_variable = 0
    for val in parameters:
        if type(parameters[val]) == np.ndarray:
            x_variable = val

    if x_variable == 0:
        raise ValueError("\n\nDen eine parameteren må innehalde ein np.array(), som er x-verdiane i funksjonen")
    if parameters[x_variable].size != målte_verdiar.size:
        raise ValueError(f"\n\nAntall x-verdiar må vere lik som antall målte verdiar (y-verdiar). \n" +
                          f"No hadde du {parameters[x_variable].size} x_verdiar, medan du hadde {målte_verdiar.size} y-verdiar")



    måle_x_pos = parameters[x_variable]
    uvisse_variablar_liste = []

    dfdx = []
    uvisse_verdi = []
    for i in uvisse_variablar:
        dfdx.append(sp.diff(utrykk, i))
        uvisse_verdi.append(uvisse_variablar[i])
        uvisse_variablar_liste.append(i)
        

    # finds the values that each element is supposed to be at position x
    def elements_and_values(x):
        """
        returns a list of the elements inside and theier values [(x, x), (I, 1.0), (N, 330), ...]
        """
        elements_inside = []
        for val in parameters:
            if type(parameters[val]) != np.ndarray:
                elements_inside.append((val, parameters[val]))
            else:
                elements_inside.append((val, x))
        return elements_inside
    
    

    # Verdiane utan x-verdiane inni utrykk_av_x = f(x)
    utrykk_av_x = utrykk.subs(elements_and_values(x_variable))
    
    # berekna verdiar (i teorien)
    x_calculated = np.linspace(min(måle_x_pos), max(måle_x_pos), 200)
    feil_verdiar = np.zeros(x_calculated.shape)
    
    Values_calculated_array = [utrykk_av_x.subs([(x_variable, x_calculated[i])]) for i in range(len(x_calculated))]
    Values_calculated_array = np.array(Values_calculated_array).astype(np.float64)


    
    # Time to feil-analysere:
    for i in range(len(x_calculated)):
        

        gaus_part = 0
        for j, uvisse in enumerate(uvisse_verdi):
            gaus_part += (dfdx[j].subs(elements_and_values(x_calculated[i]))*uvisse)**2
                

        feil_verdiar[i] = np.sqrt(float(gaus_part))


    # Berekner bidraga

    bidrag = np.zeros((len(uvisse_verdi), len(x_calculated)))
    for i in range(len(uvisse_verdi)):

        bidrag[i] = [dfdx[i].subs(elements_and_values(x_calculated[j]))*uvisse_verdi[i] for j in range(len(x_calculated))]

    if plot_it:
        # Plotter
        plt.figure()
        plt.plot(x_calculated, Values_calculated_array, label="Utrekna data")
        plt.fill_between(x_calculated, (Values_calculated_array - feil_verdiar), (Values_calculated_array + feil_verdiar), label='Berekna kurve med $\pm \Delta f$', alpha=0.5)
        
        
        # Velger kor mange errorbars. Du gjer dette øvst når du kallar funksjonen btw.
        if std_uvisse:
            indices = np.linspace(0, len(måle_x_pos) - 1, antall_error_bars, dtype=int)
            måle_pos_subset = måle_x_pos[indices]
            målte_verdiar_subset = målte_verdiar[indices]
            plt.errorbar(måle_pos_subset, målte_verdiar_subset, yerr=std_uvisse, fmt='r.', label='Std avvik i måledata')

        
        plt.plot(måle_x_pos, målte_verdiar, label="Målte verdiar", color="black")
        plt.xlabel('$x$')
        plt.ylabel('Målte verdiar')
        plt.legend(loc='upper left')
        


        plt.figure()
        # Plotter bidrag til uvissa
        for i, enkelt_bidrag in enumerate(bidrag):
            plt.plot(x_calculated, (np.abs(enkelt_bidrag)**2)/(feil_verdiar**2), '-',
                    label=rf'$\left(\frac{{\Delta {uvisse_variablar_liste[i]}}}{{\Delta \text{{gausfeil}}}}\right)^2$')

        plt.ylabel('Relative bidrag til $\Delta f$ [-]')
        plt.xlabel('$x$')
        plt.legend(loc='upper left')
        plt.show()

    # Ting du kanskje vil ha returnert
    # dei forskjellige bidraga i derivert (same rekjefølge som dfdx er derivert aka som uvissevariablar), dfdx = sum (df/dn * ) (same rekjefølge som uvisse_variablar)
    [bidrag, dfdx] 

    # Returnerar gaus sin feil for 200 verdiar mellom max og minste x-verdi
    return feil_verdiar


        




# Skjer bare dersom denne fila sjølve kjørar
if __name__ == "__main__":


    """Eksempelkode:"""



    # Eksperimentelle måleposisjonar
    xe = np.array([0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.10, 0.11, 0.12, 0.13, 0.14,
                0.15, 0.16, 0.17, 0.18, 0.19, 0.20, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28,
                0.285, 0.29, 0.295, 0.3, 0.305, 0.31, 0.315, 0.32, 0.33, 0.34, 0.35, 0.36, 0.37,
                0.38, 0.39, 0.4, 0.41, 0.42, 0.43, 0.44, 0.45, 0.46, 0.47, 0.48, 0.49, 0.50])


    # Eksperimentelle magnetfeltstyrker 
    Be = np.array([0.22, 0.26, 0.3, 0.50, 0.42, 0.49, 0.58, 0.67, 0.79, 0.92, 1.09, 1.27, 1.51, 1.79,
                2.14, 2.57, 3.1, 3.75, 4.58, 5.62, 6.97, 8.59, 10.74, 13.3, 16.36, 19.85, 23.41,
                26.57, 27.76, 28.71, 29.2, 30.26, 28.91, 28.13, 26.97, 20, 22.19, 18.53, 15.21,
                12.31, 9.96, 8.04, 6.47, 5.26, 2, 3.51, 2.9, 1, 2.02, 1.7, 1.43, 1.21, 1.03,
                0.87]) *1e-4 



    # Definerer variablene som inngår i uttrykkene for Biot-Savarts lov for alle geometriane
    mu0, I, R, N, l, x, z = sp.symbols('mu0 I R N l x z')
    uvisse_v = {x: 0.01, I: 0.01, R: 0.0005}
    verdi = [N, I, R, x, mu0]
    std_uvisse = 0.0001

    kort_spole = (N*I*mu0)/(2*R)*(1 + (x/R)**2)**(-3/2)

    # Ein av desse må vere np.array() med lik lengde som målte verdiar. Denne blir da x-verdien:
    verdi_dict = {I: 1, N: 330, R: 0.07, mu0: 4*np.pi*1e-7, x: xe} 



    feil_analyse(verdi_dict, kort_spole, uvisse_v, Be, std_uvisse)





