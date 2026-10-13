% FOR HELICOPTER NR 1-2
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert høsten 2006 av Jostein Bakkeheim
% Oppdatert høsten 2008 av Arnfinn Aas Eielsen
% Oppdatert høsten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;


%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.40; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.65; % Motor mass [kg]
J_p = 2*m_p*l_p^2; % Moment of intertia pitch [kgm^2]
J_e = m_c*l_c^2 + 2*m_p*l_h^2; % Moment of inertia elevation [kgm^2]
J_la = m_c*l_c^2 + 2*m_p*(l_h^2 + l_p^2); % Moment of inertia travel [kgm^2]

%%%%%%%%%%% Measured and calculated constants
elev_ref = 0.48;
V_s0 = 6.5;%6.76; % Voltage for e=0 [V]
K_f = -g * (m_c*l_c - 2*m_p*l_h)/(l_h*V_s0); % Motor force constant [N]

L_2 = g*(m_c*l_c - 2*m_p*l_h);
L_3 = m_p * l_h * K_f;

K_1 = l_p * K_f / J_p; % Constant 1
K_2 = l_h * K_f / J_e; % Constant 2
K_3 = l_h * K_f * V_s0 / J_la; % Constant 3

la_1 = -3 + 5i; 
la_2 = -3 - 5i;

K_pp = la_1 * la_2 / K_1; % Proportional constant 
K_pd = -(la_1 + la_2) / K_1; % Derivative constant

%a = -5;
%b = 0;

%K_pp = (a^2+b^2)/K_1;
%K_pd = -2*a;

