


function[x_pred, P_pred] = prediction(A_d, B_d, Q_d, x_hat, P_hat, u) 
    x_pred = A_d * x_hat + B_d * u;
    P_pred = A_d * P_hat * A_d' + Q_d;
end




