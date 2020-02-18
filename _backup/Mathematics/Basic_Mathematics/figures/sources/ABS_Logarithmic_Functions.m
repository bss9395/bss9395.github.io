clear;
close all;
clc;

syms x;

figure(1); hold on;
fplot(abs(log(1+x)), [-1, 5]); fplot(abs(x), 'k--'); fplot(log(1+abs(x))); fplot(log(abs(1+x))); fplot(log(1+x), [-1, 5]); fplot(x, [-5, 0], 'k-.'); fplot(0, 'k');
box on; grid on; grid minor;
axis square equal;
xlim([-4, 3]);
ylim([-2.5, 2.5]);
ax = gca;
ax.YTick = [-2.5, -1.5, -0.5, 0, 0.5, 1.5, 2.5];
legend({'$|\ln (1 + x)|$', '$|x|$', '$\ln (1 + |x|)$', '$\ln (|1 + x|)$', '$\ln (1 + x)$'}, 'Interpreter', 'latex', 'Location', 'SouthEast');
