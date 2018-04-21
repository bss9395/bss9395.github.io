---
layout:    zh_post
Topic:     收敛极限
Title:     多项式
Revised:   2018-04-21 01:34:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 一致逼近

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \exists P (n, x) \rightrightarrows f (x) \implies | f (x) | \le M \\
> \fbox{2}\; & f (x) \in \mathcal{Integ.} \implies \int_\alpha^\beta | \exists P (n, x) - f (x) | \mathrm{d} x \rightrightarrows 0 \\
> \fbox{3}\; & \exists P (n, x) \rightrightarrows f (x \in (-\infty, +\infty)) \implies f (x) \in \mathcal{Poly.} \\ 
> \end{alignedat}
> $$
>

> ### 二项式函数多项式

> $$
> \begin{alignedat}{3}
> \Uparrow\;         &&           \sum_{i = 0}^n f \left( \dfrac{i}{n} \right) \cdot \mathcal{C}_n^i x^i y^{n - i} &= F (f ([0, 1]); n; x, y) \\
> \fbox{1}\Uparrow\; &&                                                                                  (x + y)^n &= \sum_{i = 0}^n 1 \cdot \mathcal{C}_n^i x^i y^{n - i} \\
> \Downarrow\;       &&                                                                                          1 &= F (f = 1; n; x; 1 - x) \\
> \fbox{2}\Uparrow\; &&                                                                          x (x + y)^{n - 1} &= \sum_{i = 0}^n \dfrac{i}{n} \cdot \mathcal{C}_n^i x^i y^{n - i} \quad\Leftarrow\quad \dfrac{\mathrm{d}}{\mathrm{d} x} (x + y)^n \\
> \Downarrow\;       &&                                                                                          x &= F (f = x; n; x; 1 - x) \\
> \fbox{3}\Uparrow\; &&                      \dfrac{n - 1}{n} x^2 (x + y)^{n - 2} + \dfrac{1}{n} x (x + y)^{n - 1} &= \sum_{i = 0}^n \dfrac{i^2}{n^2} \cdot \mathcal{C}_n^i x^i y^{n - i} \quad\Leftarrow\quad \dfrac{\mathrm{d}}{\mathrm{d} x} [x (x + y)^{n - 1}] \\
> \Downarrow\;       &&                                        \left(1 - \dfrac{1}{n} \right) x^2 + \dfrac{1}{n} x &= F (f = x^2; n; x; 1 - x) \\
> \fbox{4}\Uparrow\; && \sum_{i = 0}^n \left( \dfrac{i}{n} - x \right)^2 \cdot \mathcal{C}_n^i x^i (1 - x)^{n - i} &= 1 \cdot \sum_{i = 0}^n \dfrac{i^2}{n^2} \cdot \mathcal{C}_n^i x^i (1 - x)^{n - i} - 2 x \cdot \sum_{i = 0}^n \dfrac{i}{n} \cdot \mathcal{C}_n^i x^i (1 - x)^{n - i} + x^2 \cdot \sum_{i = 0}^n 1 \cdot \mathcal{C}_n^i x^i (1 - x)^{n - i} \\
>                    &&                                                                                            &= 1 \cdot F (f = x^2; n; x, 1 - x) - 2 n^2 x \cdot F (f = x; n; x, 1- x) + n^2 x^2 \cdot F (f = 1; n; x; 1 - x) \\
>                    &&                                                                                            &= 1 \cdot \left[ \left( 1 - \dfrac{1}{n} \right) x^2 + \dfrac{1}{n} x \right] - 2 x \cdot x + x^2 \cdot 1 \\
>                    &&                                                                                            &= \dfrac{1}{n} (x - x^2) \\
>                    &&                                                                                            &\le \dfrac{1}{4 n} \quad\Leftarrow\quad x = \dfrac{1}{2} \\
> \end{alignedat}
> $$
>

> ### 二项式函数多项式一致逼近连续函数

> $$
> \begin{alignedat}{3}
> \Uparrow\;           &&                                                                 f (x \in [0, 1]) \to \mathcal{Conti.} \quad&\Rightarrow\quad | f (x') - f (x'') | \lt \varepsilon \\
> \Uparrow\;           &&                                                                    | F (f ([0, 1]); n; x, 1 - x) - f (x) | &\le \sum_{i = 0}^n \left| f \left( \dfrac{i}{n} \right) - f (x) \right| \cdot \mathcal{C}_n^i x^i (1 - x)^{n - i} \\
>                      &&                                                                                                            &= \left( \sum_{| \frac{i}{n} - x | \lt \delta}^n + \sum_{| \frac{i}{n} - x | \ge \delta}^n \right) \left| f \left( \dfrac{i}{n} \right) - f (x) \right| \cdot \mathcal{C}_n^i x^i (1 - x)^{n - i} \\
>                      &&                                                                                                            &\le \varepsilon \cdot \sum_{| \frac{i}{n} - x | \lt \delta}^n \mathcal{C}_n^i x^i (1 - x)^{n - i} + \dfrac{2 M}{\delta^2} \cdot \sum_{| \frac{i}{n} - x | \ge \delta}^n \delta^2 \cdot \mathcal{C}_n^i x^i (1 - x)^{n - i} \\
>                      &&                                                                                                            &\le \varepsilon + \dfrac{2 M}{\delta^2} \cdot \sum_{i = 0}^n \left( \dfrac{i}{n} - x \right)^2 \cdot \mathcal{C}_n^i x^i (1 - x)^{n - i} \\
>                      &&                                                                                                            &\le \varepsilon + \dfrac{2 M}{\delta^2} \cdot \dfrac{1}{4 n} \rightrightarrows 0 \\
> \Downarrow\;         &&                                                                                F (f ([0, 1]); n; x, 1 - x) &\rightrightarrows f (x \in [0, 1]) \\
> \Uparrow\;           &&                                                    f (x \in [0, 1]) = g (\alpha + (\beta - \alpha) x) \quad&\Rightarrow\quad x = \dfrac{t - \alpha}{\beta - \alpha} \\
> \fbox{1}\Downarrow\; && F \left( f ([0, 1]); n; \dfrac{t - \alpha}{\beta - \alpha}, 1 - \dfrac{t - \alpha}{\beta - \alpha} \right) &\rightrightarrows f \left( x = \dfrac{t - \alpha}{\beta - \alpha} \right) = g (t \in [\alpha, \beta]) \\
> \fbox{2}\Downarrow\; &&                                                                 f (x \in [0, 1]) \to \mathcal{Conti.} \quad& \\
> \end{alignedat}
> $$
>

> ### 三角多项式

> $$
> \begin{alignedat}{3}
> \fbox{01}\; &&     T^{\cos} (n, x) \cdot \cos x &\in T^{\cos} (n + 1, x)  \\
> \fbox{02}\; &&     T^{\cos} (n, x) \cdot \sin x &\in T^{\sin} (n + 1, x) \\
> \fbox{03}\; &&     T^{\sin} (n, x) \cdot \cos x &\in T^{\sin} (n + 1, x) \\
> \fbox{04}\; &&     T^{\sin} (n, x) \cdot \sin x &\in T^{\cos} (n + 1, x) \\
> \fbox{05}\; &&                T (n, x + \alpha) &\in T (n, x) \\
> \fbox{06}\; &&                         \cos^n x &\in T^{\cos} (n, x) \\
> \fbox{07}\; &&               f (x \in [0, \pi]) &= f (\arccos t) \leftleftarrows \exists P (n, t) = \exists T^{\cos} (n, x \in [0, \pi]) \\
> \fbox{08}\; &&                  f (x) = f (- x) &= f (x + 2 \pi) \quad\Rightarrow\quad f (x) \leftleftarrows \exists T^{\cos} (n, x) \\
> \fbox{09}\; && [f (x^{2 \pi}) + f (- x)] \cos x &\leftleftarrows \exists T^{\cos} (n, x) \\
> \fbox{10}\; && [f (x^{2 \pi}) - f (- x)] \sin x &\leftleftarrows \exists T^{\sin} (n, x) \\
> \fbox{11}\; &&                  2 f (x^{2 \pi}) &= [f (x^{2 \pi}) + f (- x)] \cos x \cdot \cos x + [f (x^{2 \pi}) - f (- x)] \sin x \cdot \sin x \\
>             &&                                  &\leftleftarrows \exists T_1^{\cos} (n, x) \cdot \cos x + \exists T_2^{\cos} (n, x) \cdot \sin x \\
>             &&                                  &\leftleftarrows \exists T (n + 1, x) \\
> \end{alignedat}
> $$
>