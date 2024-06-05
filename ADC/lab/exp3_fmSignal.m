% Set the sampling frequency to 1kHz and carrier frequency to 200 Hz.
fs = 1000;
fc = 200;
t = (0:1/fs:0.2)';

% Create two-tone sinusoidal signal with frequencies 30 and 60 Hz.
x = sin(2*pi*30*t) + 2*sin(2*pi*60*t);

% Set the frequency deviation to 50 Hz.
fDev = 50;

% Frequency modulate x.
y = fmmod(x, fc, fs, fDev);

% Create a figure
figure;

% Plot the graphs to show the original signal and modulated signal
subplot(2, 1, 1)
plot(t, x)
xlabel('Time (s)')
ylabel('Amplitude')
legend('Original Signal')
grid on;
title('Original Signal')

subplot(2, 1, 2)
plot(t, y)
xlabel('Time (s)')
ylabel('Amplitude')
legend('Modulated Signal')
grid on;
title('Frequency Modulated Signal')

sgtitle('ADC Experiment 3: Graphs of Original & Frequency Modulated Signals | 16014022042')
