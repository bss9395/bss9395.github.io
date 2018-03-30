clear;
close;
figure;
hold on;

P = [-3,  -2, -1/2,-1/3, 1/3, 1/2, 2,   3];

x = (0:0.01:2)';
y = x.^P;

plot(x,y);
plot(x,x.^1,'k--',x,x.^(-1),'k--');
ax = gca();
ax.XTick = 0:0.5:2;
ax.YTick = 0:0.5:2;
axis square equal;
axis([0,2,0,2]);
grid on;
box on;

a = [0.8192, 0.7549,0.4656,0.3803,   0.3177,0.3820,0.6180,  0.6823];
b = a.^P;
c = {'$x^{-3}$','$x^{-2}$','$x^{- \frac{1}{2}}$','$x^{- \frac{1}{3}}$', '$x^{\frac{1}{3}}$','$x^{\frac{1}{2}}$','$x^2$','$x^3$'};
text(a,b,c,'Interpreter','latex');
text(0.5,1,'y = x^P');