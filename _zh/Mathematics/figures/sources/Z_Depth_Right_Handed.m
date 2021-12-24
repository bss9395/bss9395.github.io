clear;
close all;
clc;

syms z;
z_near = -0.1;
z_far = -100.0;

figure(1); hold on;
f(z) = 1 - 2 * (1 / z - 1 / z_near) / (1 / z_far - 1 / z_near);
fplot(f(z));
fplot(0, 'k-.');
box on; grid on; grid minor;
axis square equal;
xlim([z_far/10, 0]);
ylim([-1, +1]);
ax = gca;
ax.TickLabelInterpreter = 'latex';
ax.XTick = [z_far/10, z_far/20, z_far/50, z_far/100, z_far/200, z_near];
ax.YTick = [-1, -1/2, 0, +1/2, +1];
ax.XTickLabels = {'$\frac{z_{\mathrm{far}}}{10}$', '$\frac{z_{\mathrm{far}}}{20}$', '$\frac{z_{\mathrm{far}}}{50}$', '$\frac{z_{\mathrm{far}}}{100}$', '$\frac{z_{\mathrm{far}}}{200}$', '$\frac{z_{\mathrm{near}}}{1}$'};
ax.YTickLabels = {'$-1$','$-\frac{1}{2}$','$0$','$+\frac{1}{2}$','$+1$'};
title('Z-Depth\_Right-Handed');
legend({'$f(z) = 1 - 2 \cdot \left( \frac{1}{z} - \frac{1}{z_{\mathrm{near}}} \right) / \left( \frac{1}{z_{\mathrm{far}}} - \frac{1}{z_{\mathrm{near}}} \right)$'}, 'Interpreter', 'latex', 'Location', 'NorthWest');
