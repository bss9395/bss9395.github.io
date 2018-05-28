---
layout:    zh_post
Topic:     概率统计
Title:     大数定律
Revised:   2018-05-28 01:30:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ###  累积概率不等式

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           && P [|X| \ge \varepsilon] &= \mathop{\left\langle \sum \int \right\rangle}_{|x| \ge \varepsilon} p (x) \\
>                         &&                         &\le \mathop{\left\langle \sum \int \right\rangle}_{|x| \ge \varepsilon} \dfrac{x^2 \cdot p (x)}{\varepsilon^2} \\
>                         &&                         &\le \dfrac{1}{\varepsilon^2} \mathop{\left\langle \sum \int \right\rangle}_{x} x^2 \cdot p (x) \\
> \fbox{1}\Downarrow\quad && P [|X| \ge \varepsilon] &\le \dfrac{\mathrm{Exp} [X]^2}{\varepsilon^2} \\
> \fbox{2}\Downarrow\quad && P [|X| \lt \varepsilon] &\ge 1 - \dfrac{\mathrm{Exp} [X]^2}{\varepsilon^2} \\
> \end{alignedat}
> $$
>

> ### 偏差概率不等式

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           && P (|X - \mathrm{Exp} [X]| \ge \varepsilon) &\le \dfrac{\mathrm{Exp} [X - \mathrm{Exp} [X]]^2}{\varepsilon^2} \\
> \fbox{1}\Downarrow\quad && P (|X - \mathrm{Exp} [X]| \ge \varepsilon) &\le \dfrac{\mathrm{Var} [X]}{\varepsilon^2} \\
> \fbox{2}\Downarrow\quad && P (|X - \mathrm{Exp} [X]| \lt \varepsilon) &\ge 1 - \dfrac{\mathrm{Var} [X]}{\varepsilon^2} \\
> \end{alignedat}
> $$
>

> ### 弱大数定律

> $$
> \begin{alignedat}{3}
> \lim_{n \to +\infty} P \left[ \left| \dfrac{1}{n} \sum X_n - p_n \right| \lt \varepsilon \right] = 1 \\
> \end{alignedat}
> $$
>

> ### 强大数定律

> $$
> \begin{alignedat}{3}
> P \left[ \lim_{n \to + \infty} \dfrac{1}{n} \sum_1^n X_n - p \right] = 1 \\
> \end{alignedat}
> $$
>

> ### 二项大数定律

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   & X \mapsto \mathrm{Bn} (n, p) \\
> \Downarrow\quad & \lim_{n \to +\infty} P \left[ \left| \dfrac{k}{n} - p \right| \lt \varepsilon \right] = 1 \\
> \end{alignedat}
> $$
>

> ### 偏差大数定律

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   & \lim_{n \to +\infty} \dfrac{1}{n^2} \mathrm{Var} \left[ \sum_1^n X_n \right] \to 0 \\
> \Downarrow\quad & \lim_{n \to +\infty} P \left[ \left| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \right| \lt \varepsilon \right] = 1 \\ 
> \end{alignedat}
> $$
>

> ### 独立同分布大数定律

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\quad & p (x_1, \cdots, x_n) = p_{X_1} (x_1) \cdots p_{X_n} (x_n) \\
> \fbox{2}\Uparrow\quad & X_1, \cdots, X_n \mapsto X \\
> \Downarrow\quad       & \lim_{n \to +\infty} P \left[ \left| \dfrac{1}{n} \sum_1^n X_n - \mathrm{Exp} [X] \right| \lt \varepsilon \right] = 1 \\
> \end{alignedat}
> $$
>