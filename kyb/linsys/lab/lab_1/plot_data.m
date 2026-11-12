S = load(fullfile(fileparts(mfilename('fullpath')), 'data', 'data2.mat'));

data = S.ans;

t = data(1,:);
signals = data(4:6, :);

plot(t, signals.');
xlabel("Time");
ylabel("Value");
legend("Pitch", "Pitch rate", "Elevation");
grid on
