% experiment 8

% finding correlation and autocorrelation of sequences

% signal 1
n1 = 0:1:10;
signal1 = sin(n1);

% signal 2
n2 = 0:1:3;
signal2 = [1 2 3 4];

% correlation
correlation_result = xcorr(signal1, signal2);

% auto correlation of any one of the signals
auto_correlation_result = xcorr(signal1);

subplot(4,1,1);
stem(n1, signal1);
xlabel('discrete time n'); ylabel('amplitude');
title('Discrete Signal 1 (ketaki)');

subplot(4,1,2);
stem(n2, signal2);
xlabel('discrete time n'); ylabel('amplitude');
title('Discrete Signal 2 (ketaki)');

subplot(4,1,3);
stem(correlation_result);
xlabel('discrete time n'); ylabel('amplitude');
title('Correlation of Signal 1 and Signal 2 (ketaki)');

subplot(4,1,4);
stem(auto_correlation_result);
xlabel('discrete time n'); ylabel('amplitude');
title('Auto-correlation of Signal 1 (ketaki)');
