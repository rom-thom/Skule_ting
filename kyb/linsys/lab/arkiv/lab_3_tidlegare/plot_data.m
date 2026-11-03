S = load("LQR_alle_1.mat");

data = S.ans;

t = data(1,:);
signals = data([1, 2, 5, 7, 8]+1, :);

plot(t, signals.');
xlabel("Time");
ylabel("Value");
legend("x", "y", "Pitch", "Elevation", "Elevation rate");
grid on
% pitch ref, elevation rate, travel, travel rate,  pitch, pitch rate, elevation, elevation rate