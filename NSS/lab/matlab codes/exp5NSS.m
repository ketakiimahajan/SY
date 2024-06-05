% impulse response of system
% h = [1, -0.5, 0.25, -0.125, 0.0625];

% frequency response using frequency
% [H, w] = freqz(h, 1);

% Plot magnitude and phase of frequency response ﬁgure
% subplot(2, 1, 1);
% plot(w, abs(H));
% title('Magnitude of Frequency Response'); xlabel('Frequency (radians/sample)'); ylabel('Magnitude');

% subplot(2, 1, 2);
% plot(w, angle(H));
% title('Phase of Frequency Response'); xlabel('Frequency (radians/sample)'); ylabel('Phase (radians)');


syms t s;
A = 1; % Amplitude
f = 1; % Frequency (in Hz) 
n = 2; % Exponent for t^n

% Deﬁne the functions 
constant = 1; 
exponential = A * exp(t); 
power = t^n;
sine_wave = A * sin(2 * pi * f * t); 
cos_wave = A * cos(2 * pi * f * t); 
sinh_wave = A * sinh(t); 
cosh_wave = A * cosh(t);

% Store the functions in a cell array
functions = {constant, exponential, power, sine_wave, cos_wave, sinh_wave, cosh_wave}; function_names = {'Constant', 'Exponential', 't^n', 'Sine Wave', 'Cosine Wave', 'Hyperbolic Sine', 'Hyperbolic Cosine'};

for i = 1:length(functions)
    F = laplace(functions{i}, t, s);

% Display the Laplace transform expression 
disp(['Laplace Transform of ', function_names{i}, ':']); 
disp(F);
% disp('................'); 
end