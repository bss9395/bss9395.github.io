clear ;
close all;
clc;
reset(symengine);

figure; hold on;
fplot(@gamma);


t = 1.46:0.00001:1.47;
s = gamma(t);
x = [t(min(s) == s), t(min(s) == s)];
y = [0, min(s)];
plot(x, y, 'k--');
plot([0, 2], [1, 1], 'k--');

patch([-5, 5], [0, 0], 'black'); patch([5, 5 - 0.2, 5 - 0.2], [0, 0.1, -0.1], 'black');
patch([0, 0], [-5, 5], 'black'); patch([0, 0 - 0.1, 0 + 0.1], [5, 5 - 0.2, 5 - 0.2], 'black');
patch([-4:4; -4:4], [zeros(1, 9); 0.1 * ones(1, 9)], 'black');
text([-4:4], [zeros(1, 9)], {'-4', '-3', '-2', '-1', '0', '1', '2', '3', '4'}, 'verticalalign', 'top', 'horizontalalign', 'center');
patch([zeros(1, 9); 0.1 * ones(1, 9)], [-4:4; -4:4], 'black');
text([zeros(1, 8)], [-4:-1, 1:4], {'-4 ', '-3 ', '-2 ', '-1 ', '1 ', '2 ', '3 ', '4 '}, 'verticalalign', 'middle', 'horizontalalign', 'right');

axis image;
xlim([-5, 5]);
ylim([-5, 5]);
set(gca, 'visible', 'off');