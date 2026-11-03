

function[x_cor, P_cor] = correction(P_prev, x_prev, C_d, R_d, y, new_data)
    
    if new_data
        I = eye(size(P_prev, 1));
        L = P_prev * C_d' \ ((C_d * P_prev * C_d' + R_d));
        x_cor = x_prev + L * (y - C_d * x_prev);
        P_cor = (I- L * C_d) * P_prev * (I - L * C_d)' + L * R_d * L';
    else
        x_cor = x_prev;
        P_cor = P_prev;
    end

end