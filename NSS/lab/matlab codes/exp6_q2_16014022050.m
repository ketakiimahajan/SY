% Clearing all variables, closing all figures, and clearing the command window
clear all;
close all;
clc;

% Creating the discrete time vector
n = 0:10;

% Defining the original discrete signal
x = sin(0.2*pi*n);

% Amplitude scaling
amp_scale = 2;
x_amp_scaled = amp_scale * x;

% Time scaling
time_scale = 2;
n_scaled = time_scale * n;
x_time_scaled = sin(0.2*pi*n_scaled);

% Folding
n_folded = -fliplr(n); % Flip the signal values
x_folded = sin(0.2*pi*(-n_folded)); % Adjusted folding operation

% Time shifting
n_shifted = n + 2;
x_shifted = sin(0.2*pi*n_shifted);

% Plotting the results using subplot
subplot(3, 2, 1);
stem(n, x, 'filled', 'LineWidth', 2);
xlabel('Time');
ylabel('Amplitude');
title('Original Discrete Signal (ketaki)');

subplot(3, 2, 2);
stem(n, x_amp_scaled, 'filled', 'LineWidth', 2);
xlabel('Time');
ylabel('Amplitude');
title('Amplitude Scaled Discrete Signal (ketaki)');

subplot(3, 2, 3);
stem(n_scaled, x_time_scaled, 'filled', 'LineWidth', 2);
xlabel('Time');
ylabel('Amplitude');
title('Time Scaled Discrete Signal (ketaki)');

subplot(3, 2, 4);
stem(n_folded, x_folded, 'filled', 'LineWidth', 2);
xlabel('Time');
ylabel('Amplitude');
title('Folded Discrete Signal (ketaki)');

subplot(3, 2, 5);
stem(n_shifted, x_shifted, 'filled', 'LineWidth', 2);
xlabel('Time');
ylabel('Amplitude');
title('Time Shifted Discrete Signal (ketaki)');
