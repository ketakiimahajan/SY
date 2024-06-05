clear all;
close all;
clc;

% Creating the time vector
t = 0:0.01:1;

% Defining the original signal
x = sin(2*pi*4*t);

% Amplitude scaling
amp_scale = 2;
x_amp_scaled = amp_scale * x;

% Time scaling
time_scale = 2;
t_scaled = time_scale * t;
x_time_scaled = sin(2*pi*4*t_scaled);

% Folding
t_folded = -t;
x_folded = sin(2*pi*4*t_folded);

% Time shifting
t_shifted = t + 0.5;
x_shifted = sin(2*pi*4*t_shifted);

% Plotting the results
subplot(2,3,1);
plot(t,x);
xlabel('Time');
ylabel('Amplitude');
title('Original Continuous Signal (ketaki)');

subplot(2,3,2);
plot(t,x_amp_scaled);
xlabel('Time');
ylabel('Amplitude');
title('Amplitude Scaled Signal (ketaki)');

subplot(2,3,3);
plot(t_scaled,x_time_scaled);
xlabel('Time');
ylabel('Amplitude');
title('Time Scaled Signal (ketaki)');

subplot(2,3,4);
plot(t,x_folded);
xlabel('Time');
ylabel('Amplitude');
title('Folded Signal (ketaki)');

subplot(2,3,5);
plot(t,x_shifted);
xlabel('Time');
ylabel('Amplitude');
title('Time Shifted Signal (ketaki)');
