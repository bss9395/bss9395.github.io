clear;
close;
figure;
hold on;

b = [1/10, 1/exp(1),1/2 , 2,exp(1), 10];
x = (-3:0.01:3)';
y = b.^x;

plot(x,y);

box on;
grid on;
ax = gca();
ax.XTick = -3:1:3;
ax.YTick = 0:1:10;
axis square equal;
axis([-3,3,0,10]);

a = [-0.6990, -1.6094, -2.3219, 2.3219, 1.6094, 0.6990];
b = [5, 5, 5, 5, 5, 5];
c = {'$(\frac{1}{10})^x$','$(\frac{1}{e})^x$','$(\frac{1}{2})^x$','$2^x$','$e^x$','$10^x$'};
text(a,b,c, 'Interpreter','latex');
text(0,8,'y = E^x');