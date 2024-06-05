close all;
clear all;
clc;

% Define the parameters
fs = 1000; % Sampling frequency
N = 1024; % Number of samples
t = (0:N-1) * (1/fs); % Time vector

% Define a continuous-time signal (cosine in this case)
f = 10; % Frequency of the cosine function
A = 0.8; % Amplitude of the cosine function
x = A * cos(2 * pi * f * t);

% Plot the original signal
subplot(3,1,1);
plot(t, x);
grid;
xlabel('Time');
ylabel('Amplitude');
title('Continuous Time Signal (ketaki)');

% Compute the Fourier transform
X = fft(x);

% Compute the magnitude spectrum
Xmag = abs(X);
frequencies = linspace(0, fs, N);
subplot(3,1,2);
plot(frequencies, Xmag);
grid;
xlabel('Frequency (Hz)');
ylabel('Magnitude');
title('Magnitude Spectrum of Continuous Time Signal (ketaki)');

% Compute the phase spectrum
Xphase = angle(X) * (180/pi);
subplot(3,1,3);
plot(frequencies, Xphase);
grid;
xlabel('Frequency (Hz)');
ylabel('Phase (degrees)');
title('Phase Spectrum of Continuous Time Signal (ketaki)');
