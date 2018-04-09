---
layout:    zh_post
Topic:     收敛极限
Title:     重要乘积
Revised:   2018-04-09 20:08:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### $\mathcal{C}_\alpha^{+\infty}$乘积

> $$
> \begin{alignedat}{3}
> \Uparrow\;         &&         \mathcal{C}_\alpha^n &= \dfrac{\alpha (\alpha - 1) \cdots (\alpha - n + 1)}{n !} \\
> \Downarrow\;       &&  (-1)^n \mathcal{C}_\alpha^n &= \left( 1 - \dfrac{\alpha + 1}{1} \right) \left( 1 - \dfrac{\alpha +1}{2} \right) \cdots \left( 1 - \dfrac{\alpha + 1}{n} \right) \\
>                    &&                              &= \prod_1^n \left( 1 - \dfrac{\alpha + 1}{n} \right) \\
> \fbox{1}\Uparrow\; &&             \alpha > -1 \quad&\Rightarrow\quad \sum_1^{+\infty} \dfrac{\alpha + 1}{n} \to +\infty \\
> \Downarrow\;       && \mathcal{C}_\alpha^{+\infty} &= \lim_{+\infty} (-1)^n \prod_1^n \left( 1 - \dfrac{\alpha + 1}{n} \right) \to 0 \\
> \fbox{2}\Uparrow\; &&             \alpha < -1 \quad&\Rightarrow\quad \sum_1^{+\infty} \dfrac{\alpha + 1}{n} \to -\infty \\
> \Downarrow\;       && \mathcal{C}_\alpha^{+\infty} &= \lim_{+\infty} (-1)^n \prod_1^n \left( 1 - \dfrac{\alpha + 1}{n} \right) \to \infty \\
> \fbox{3}\Uparrow\; &&             \alpha = -1 \quad&\Rightarrow\quad \sum_1^{+\infty} \dfrac{\alpha + 1}{n} = 0 \\
> \Downarrow\;       && \mathcal{C}_\alpha^{+\infty} &= (-1)^n \\
> \end{alignedat}
> $$
>

> ### $\pi$ 乘积

> $$
> \begin{alignedat}{3}
> \Uparrow\;   & \int_0^\frac{\pi}{2} \sin^{2 n + 1} x \mathrm{d} x < \int_0^\frac{\pi}{2} \sin^{2 n} x \mathrm{d} x < \int_0^\frac{\pi}{2} \sin^{2 n - 1} x \mathrm{d} x \\
> \Downarrow\; & \dfrac{(2 n) !!}{(2 n + 2) !!} < \dfrac{(2 n -1) !!}{(2 n) !!} \cdot  \dfrac{\pi}{2} < \dfrac{(2 n - 1) !!}{(2 n - 1) !!} \\
> \Downarrow\; & \dfrac{1}{2 n + 1} \left[ \dfrac{(2 n) !!}{(2 n - 1) !!} \right]^2 < \dfrac{\pi}{2} < \dfrac{1}{2 n} \left[ \dfrac{(2 n) !!}{(2 n - 1) !!} \right]^2 \\
> \Downarrow\; & \dfrac{2 n}{2 n + 1} \cdot \dfrac{\pi}{2} < \dfrac{1}{2 n + 1} \left[ \dfrac{(2 n) !!}{(2 n - 1) !!} \right]^2 < \dfrac{\pi}{2} \\
> \Downarrow\; & \dfrac{\pi}{2} = \prod_1^{+ \infty} \dfrac{(2 n)^2}{(2 n - 1) (2 n + 1)} = \dfrac{1}{2 n + 1} \prod_1^{+\infty} \left[ \dfrac{2 n}{2 n - 1} \right]^2 = \dfrac{1}{2 n + 1} \left[ \dfrac{(2 n) !!}{(2 n - 1) !!} \right]^2 \\
> \end{alignedat}
> $$
>
