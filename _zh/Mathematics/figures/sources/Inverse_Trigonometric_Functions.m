clear;
close all;
clc;

syms x;

figure(1); hold on;
fplot(csc(x));
fplot(sec(x));
fplot(cot(x));
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
title('Inverse Trigonometric Functions');
legend({'$\sin^{-1} x$','$\cos^{-1} x$','$\tan^{-1} x$','$x$'}, 'Interpreter', 'latex', 'Location', 'SouthEast');
