import matplotlib.pyplot as plt
import numpy as np
fig=plt.figure()
ax=fig.add_subplot(1,1,1)
###################################
### Fyll inn deres eksperimentelle verdier her! ###
################################### Eksperimentelle data
masse_P = 1 * 30.9738/136.086 # gram med P = gram KH2PO4 * molvekt P/molvekt KH2PO4
konsentrasjonIStandarlosning = masse_P / 250 * 10**6 #ug/ml eller mg/l
Vstart = [0, 0.1, 0.2, 0.3, 0.4, 0.5] # ml i byretten ved start av titrering av de ulike løsningene
Vstopp = [1, 1, 1, 1, 1, 1] # ml i byretten ved titreringsslutt
Abs470 = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6] # - absorbans for løsningene ved 470 nm lys
Abs490 = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6] # - absorbans for løsningene ved 490 nm lys
AbsUkjent470 = 0.1
AbsUkjent490 = 0.1
################################### Utregninger
konsentrasjonP=[]
for i in range(len(Vstart)):
    konsentrasjonP.append( konsentrasjonIStandarlosning * (Vstopp[i]-Vstart[i])/100) # ug/ml etter fortynning til 100 ml
a470,b470 = np.polyfit(konsentrasjonP, Abs470, 1) # y = ax + b
Kukjent470=(AbsUkjent470-b470)/a470 # finne ukjent konsentrasjon av P fra regresjonslinje
a490,b490 = np.polyfit(konsentrasjonP, Abs490, 1)# y = ax + b
Kukjent490=(AbsUkjent490-b490)/a490 # finne ukjent konsentrasjon av P fra regresjonslinje
################################### Plot 470
plt.plot(konsentrasjonP,Abs470,color='red',marker='+',linestyle='None', label='470 nm') # plot eksp. data
plt.plot([0,40],[b470,a470*40+b470],color='red') #plot lineær regresjon
plt.plot([Kukjent470,Kukjent470],[0,AbsUkjent470],color='red') # hjelpelinje
plt.plot([0,Kukjent470],[AbsUkjent470,AbsUkjent470],color='red') # hjelpelinje
plt.text(Kukjent470+1,AbsUkjent470-0.05,"%.2f mg/l" %Kukjent470) # resultat som tekst i plottet
################################### Plot 490
plt.plot(konsentrasjonP,Abs490,color='blue',marker='+',linestyle='None', label='490 nm')
plt.plot([Kukjent490,Kukjent490],[0,AbsUkjent490],color='blue')
plt.plot([0,Kukjent490],[AbsUkjent490,AbsUkjent490],color='blue')
plt.plot([0,40],[b490,a490*40+b490],color='blue')
plt.text(Kukjent490+1,AbsUkjent490-0.05,"%.2f mg/l" %Kukjent490)
################################### Ferdiggjøring og lagring av plot
plt.legend(loc=2)
plt.ylabel('Absorbance [-]')
plt.xlabel('Concentration of P [mg/l]')
ax.set_ylim([0,ax.get_ylim()[1]]) # fiksere bunnen av y-aksen til 0
plt.savefig('plot.pdf')