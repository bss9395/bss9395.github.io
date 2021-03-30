clear;
close all;
clc;

syms x;

figure(1); hold on;
fplot(sinh(x));
fplot(cosh(x));
fplot(tanh(x));
fplot(x,'k--');
fplot(0,'k:');
box on; grid on; grid minor;
axis square equal;
xlim([-pi,+pi]);
ylim([-pi,+pi]);
ax = gca;
ax.TickLabelInterpreter = 'latex';
ax.XTick = [-pi,-pi/2,-1,0,+1,+pi/2,+pi];
ax.YTick = [-pi,-pi/2,-1,0,+1,+pi/2,+pi];
ax.XTickLabels = {'$-\pi$','$-\frac{\pi}{2}$','-1','$0$','+1','$+\frac{\pi}{2}$','$+\pi$'};
ax.YTickLabels = {'$-\pi$','$-\frac{\pi}{2}$','-1','$0$','+1','$+\frac{\pi}{2}$','$+\pi$'};
title('Hyperbolic Functions');
legend({'$\sinh x$','$\cosh x$','$\tanh x$','$x$'}, 'Interpreter', 'latex', 'Location', 'NorthWest');
