clear;
close;
figure;
hold on;

x = (0:0.01:10)';
y = [log2(x),log(x),log10(x)];
y = [-y, y];

plot(x,y);

box on;
grid on;
ax = gca();
ax.XTick = 0:1:10;
ax.YTick = -10:1:10;
axis square equal;
axis([0,10,-3,3]);

a = [5,5,5,5,5,5];
b = [-log2(5),-log(5),-log10(5),log2(5),log(5),log10(5)];
c = {'$\log_\frac{1}{2} x$','$\log_\frac{1}{e} x$','$\log_\frac{1}{10} x$','$\log_2 x$','$\log_e x$','$\log_10 x$'};
text(a,b,c,'Interpreter','latex');
text(8,0,'$y = \log_L x$','Interpreter','latex');
