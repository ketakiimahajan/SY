close all;
clear all;
clc;

% Define the parameters
fs = 1000; % Sampling frequency
N = 1024; % Number of samples
t = linspace(0, 2*pi, N); % Time vector for one period of the sine function

% Define an even function (used sine)
f = 1; % Frequency of the sine function
A = 0.8; % Amplitude of the sine function
x = A * cos(2 * pi * f * t); 

% Plot the original signal
subplot(3,1,1);
plot(t, x);
grid;
xlabel('Time');
ylabel('Amplitude');
title('Odd Input Signal');

% Calculate the Fourier coefficients
N = length(x);
n = 0:N-1;
k = 0:N-1;
X = zeros(size(k));
for i = 1:length(k)
    X(i) = sum(x .* exp(-1i*2*pi*k(i)*n/N));
end

% Extracting the Fourier coefficients
ao = X(1)/N;
an = 2*real(X(2:end))/N;
bn = -2*imag(X(2:end))/N;

% Printing the coefficients
fprintf('Fourier Coefficients: \na0 = %.4f\n', ao);
for i = 1:length(an)
    fprintf('a%d = %.4f, b%d = %.4f\n', i, an(i), i, bn(i));
end

% Calculate the magnitude spectrum
Xmag = abs(X);
subplot(3,1,2);
plot(k, Xmag);
grid;
xlabel('Frequency');
ylabel('Magnitude');
title('Magnitude Spectrum of Odd Signal');

% Calculate the phase spectrum
Xphase = angle(X) * (180/pi);
subplot(3,1,3);
plot(k, Xphase);
grid;
xlabel('Frequency');
ylabel('Phase (degrees)');
title('Phase Spectrum of Odd Signal');
