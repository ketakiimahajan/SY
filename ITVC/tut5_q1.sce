clear; clc;
L = %pi;
x = 0:0.01:2*L;
f = x - x.^2; // define function f(x)

a0 = (1/(2*L)) * inttrap(x, f); // calculate a0

for n = 1:100
    f1 = f .* cos(%pi * n * x / L);
    a(n) = (1/L) * inttrap(x, f1); // define Fourier constant a(n)
end

for n = 1:100
    f2 = f .* sin(%pi * n * x / L);
    b(n) = (1/L) * inttrap(x, f2); // define Fourier constant b(n)
end

subplot(2, 1, 1);
plot(x, f);
title('Original Function');

u = 0; y = 0;
for n = 1:100
    u = a(n) * cos(%pi * n * x / L) + b(n) * sin(%pi * n * x / L);
    y = y + u;
end
fs = y + a0;

subplot(2, 1, 2);
plot(x, fs);
title('Ketaki Mahajan 16014022050 Question 1 if n=100','fontsize',5);
