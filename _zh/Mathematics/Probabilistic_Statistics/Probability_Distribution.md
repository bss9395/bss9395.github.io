---
layout:    zh_post
Topic:     概率统计
Title:     概率分布
Revised:   2018-05-11 00:35:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 累积概率分布

> $$
> \begin{array}{l|l|l}
>                                 & P (X \lt \beta) = C (\beta^-)           & P (\alpha \lt X \lt \beta) = C(\beta^-) - C (\alpha) \\
>                                 & P (X \le \beta) = C (\beta)             & P (\alpha \lt X \le \beta) = C (\beta) - C (\alpha) \\
> C_{umulative} (x) = P (X \le x) & P (X = \beta) = C (\beta) - C (\beta^-) & \\
>                                 & P (X \ge \beta) = 1 - C (\beta^-)       & P (\alpha \le X \lt \beta) = C (\beta^-) - C (\alpha^-) \\
>                                 & P (X \gt \beta) = 1 - C (\beta)         & P (\alpha \le X \le \beta) = C (\beta) - C (\alpha^-) \\
> \end{array}
> $$
>

> ### 累积概率分布的性质

> $$
> \begin{array}{ll|l}
> \fbox{1} & x \lt y \implies C (x) \le C (y) \\
> \fbox{2} & C (-\infty) = \lim\limits_{-\infty} C (x) = 0 & C (+\infty) = \lim\limits_{+\infty} C (x) = 1 \\
> \fbox{3} & C (x_0) = \lim\limits_{x_0^+} C (x)           & C (x_0^-) \le C (x_0) = C (x_0^+) \\
> \end{array}
> $$
>

> ### 离散概率密度

> $$
> \begin{alignedat}{3}
>   p (x_i) &= P (X = x_i) = C (x_i) - C (x_i^-) \\
> p_f (y_i) &= P [f (X) = y_i] = p (x_i) \\
> \end{alignedat}
> $$
>

> ### 离散概率密度的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & p (x_i) \ge 0 \\
> \fbox{2}\quad & \sum\limits_{-\infty}^{+\infty} p (x_i) = 1 \\
> \fbox{3}\quad & \sum\limits_{-\infty}^x p (x_i) = C (x) \\
> \end{alignedat}
> $$
>

> ### 连续概率密度

> $$
> \begin{alignedat}{3}
>   p (x) &= \dfrac{P (x \lt X \le x + \mathrm{d} x)}{\mathrm{d} x} = \dfrac{\mathrm{d} C (x)}{\mathrm{d} x} \\
> p_f (y) &= \dfrac{P [y \lt f (X) \le y + \mathrm{d} y]}{\mathrm{d} y} = p [f^{- 1} (y)] \cdot \left| \dfrac{\mathrm{d} f^{- 1} (y)}{\mathrm{d} y} \right| \\
> \end{alignedat}
> $$
>

> ### 连续概率密度的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & p (x) \ge 0 \\
> \fbox{2}\quad & \int_{-\infty}^{+\infty} p (x) \mathrm{d} x = 1 \\
> \fbox{3}\quad & \int_{-\infty}^x p (x) \mathrm{d} x = C (x) \\
> \end{alignedat}
> $$
>

