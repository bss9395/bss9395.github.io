clear;
close;
figure;
hold on;

x = (-3/2*pi:pi/100:3/2*pi)';
y1 = sin(x); y1(y1>10) = Inf;
y2 = cos(x); y2(y2>10) = Inf;
y3 = tan(x); y3(y3>10) = Inf;

plot(x,[y1,y2,y3]);
plot([-10,10],[0,0],'k--');
plot([-pi,-pi;-1/2*pi,-1/2*pi;0,0;1/2*pi,1/2*pi;pi,pi],[-10,10],'k--');

box on;
grid minor;
axis square equal;
axis([-3/2*pi,3/2*pi,-3,3]);
ax = gca();
ax.XTick = -3/2*pi:pi/2:3/2*pi;
ax.YTick = -3:1:3;
ax.TickLabelInterpreter = 'latex';
ax.XTickLabel = {'$- \frac{3}{2} \pi$','$- \pi$','$- \frac{1}{2} \pi$', '$0$','$\frac{1}{2} \pi$','$\pi$','$\frac{3}{2} \pi$'};

legend({'$\sin x$','$\cos x$','$\tan x$'},'Interpreter','latex','Location','NorthWest');