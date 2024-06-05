% experiment 8

% finding convolution of two discrete-time signals

clc; close all; 

x = input('enter sequence 1: ');
h = input('enter sequence 2: ');

Nx = length(x); Nh = length(h);
Ny = Nx + Nh - 1;
newx = [x, zeros(1, Ny-Nx)];
newh = [h, zeros(1, Ny-Nh)];

for n=0:Ny-1
    sum=0;
    for k=0:n
        sum = sum + newx(k+1)*newh(n-k+1);
    end
    y(n+1) = sum;
end

autoConv = conv(x, x);

nx=0:1:Nx-1;
subplot(4,1,1); stem(nx,x);
title('Discrete Signal 1 (ketaki)');
xlabel('discrete time n'); ylabel('amplitude');
axis([min(nx)-0.5 max(nx)+0.5 0 max(x)+1]);
nh=0:1:Nh-1;

subplot(4,1, 2); stem(nh,h);
title('Discrete Signal 2 (ketaki)');
xlabel('discrete time n'); ylabel('amplitude');
axis([min(nh)-0.5 max(nh)+0.5 0 max(h)+1]);
ny=min(nx)+min(nh):max(nx)+max(nh);

subplot(4,1,3); stem(ny,y);
title('Convoluted Graph (ketaki)');
xlabel('discrete time n'); ylabel('amplitude');
axis([min(ny)-0.5 max(ny)+0.5 0 max(y)+1]);

% auto-convolution of sequence 1
nAutoConv = 0:1:length(autoConv)-1;
subplot(4,1,4); stem(nAutoConv, autoConv);
title('Auto Convolution Graph of Signal 1 (ketaki');
xlabel('discrete time n'); ylabel('amplitude');
axis([min(nAutoConv)-0.5 max(nAutoConv)+0.5 0 max(autoConv)+1]);

disp(y)
