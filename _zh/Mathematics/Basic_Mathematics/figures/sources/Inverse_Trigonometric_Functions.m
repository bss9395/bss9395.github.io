clear;
close;
figure;
hold on;

syms x;
fplot(asin(x));
fplot(acos(x));
fplot(atan(x));

fplot(x,'k--');
fplot(0,'k--');
plot([0,0],[-10,10],'k--');
fplot(1/2*pi,'k--');

x = -pi:pi/100:-pi/100;
plot(x,acot(x)+pi,'g--');


box on;
grid minor;
axis square equal;
axis([-3,3,-pi/2,pi]);

legend({'$\arcsin x$','$\arccos x$','$\arctan x$'},'Interpreter','latex','Location','West');
ax = gca();
ax.XTick = -3:1:3;
ax.YTick = -pi/2:pi/2:pi;
ax.YTickLabel = {'$-\frac{\pi}{2}$','$0$','$\frac{\pi}{2}$','$\pi$'};
ax.TickLabelInterpreter = 'latex';