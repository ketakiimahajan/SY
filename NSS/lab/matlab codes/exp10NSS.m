% experiment 10 mini project (NSS)
% ketaki mahajan / A-3 / 16014022050

t = 0:0.001:1;
% Sinosoidal signal, we can add any signal here
signal = sin(2 * pi * 10 * t);

% To make noisy signal we make use of randn to add gausian white noise to the signal
noisy_signal = sin(2 * pi * 10 * t) + 0.5 * randn(size(t));

% Design a Butterworth low-pass filter
order = 10; % Filter order
cutoff_frequency = 20; % Cutoff frequency in Hz
sampling_frequency = 1000; % Sampling frequency in Hz
[b, a] = butter(order, cutoff_frequency / (sampling_frequency / 2));

% Apply the filter to the noisy signal
filtered_signal = filtfilt(b, a, noisy_signal);

% Plot the original and filtered signals
figure;

subplot(3,1,1);
plot(t, signal);
title(['Given Signal (exp 10 - ketaki)']);

subplot(3,1,2);
plot(t, noisy_signal);
title('Noisy Signal (exp 10 - ketaki)');

subplot(3,1,3);
plot(t, filtered_signal);
title('Filtered Signal (exp 10 - ketaki)');
