---
layout:    zh_post
Topic:     概率统计
Title:     概率分布
Revised:   2018-05-19 19:03:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 累积概率分布

> $$
> \begin{array}{l|l|l}
>                                 & P [X \lt \beta] = C [\beta^-]           & P [\alpha \lt X \lt \beta] = C [\beta^-] - C [\alpha] \\
>                                 & P [X \le \beta] = C [\beta]             & P [\alpha \lt X \le \beta] = C [\beta] - C [\alpha] \\
> C_{umulative} (x) = P [X \le x] & P [X = \beta] = C [\beta] - C [\beta^-] & \\
>                                 & P [X \ge \beta] = 1 - C [\beta^-]       & P [\alpha \le X \lt \beta] = C [\beta^-] - C [\alpha^-] \\
>                                 & P [X \gt \beta] = 1 - C [\beta]         & P [\alpha \le X \le \beta] = C [\beta] - C [\alpha^-] \\
> \end{array}
> $$
>

> ### 联合概率分布

> $$
> \begin{alignedat}{3}
> J_{oint} (\cdots, x_i, \cdots) = P [\cdots, X_i \le x_i, \cdots] \\
> \end{alignedat}
> $$
>

> ### 边际概率分布

> $$
> \begin{alignedat}{3}
> {M_{arginal}}_{X_i} (x_i) &= J (+\infty, \cdots, x_i, \cdots, +\infty) \\
> \end{alignedat}
> $$
>

> ### 概率分布的性质

> $$
> \begin{array}{ll|l}
> \fbox{1} & C (x) \equiv J (x)                                                              & x_i \lt y_i \implies J (\cdots, x_i, \cdots) \le J (\cdots, y_i, \cdots) \\
> \fbox{2} & J (\cdots, -\infty, \cdots) = \lim\limits_{-\infty} J (\cdots, x_i, \cdots) = 0 & J (+\infty, \cdots, +\infty) = \lim\limits_{+\infty} \cdots \lim\limits_{+\infty} J (x_1, \cdots, x_m) = 1 \\
> \fbox{3} & J (\cdots, x0, \cdots) = \lim\limits_{x0^+} J (\cdots, x_i, \cdots)             & J (\cdots, x0^-, \cdots) \le J (\cdots, x0, \cdots) = J (\cdots, x0^+, \cdots) \\
> \fbox{4} & P (\alpha_1 \lt X_1 \le \beta_1, \alpha_2 \lt X_2 \le \beta_2)                  &= J (\beta_1, \beta_2) - J (\alpha_1, \beta_2) - J (\alpha_2, \beta_1) + J (\alpha_1, \alpha_2) \\
> \end{array}
> $$
>

> ### 离散概率密度

> $$
> \begin{alignedat}{3}
> p (\cdots, x_i, \cdots) &= P [\cdots, X_i = x_i, \cdots] = J (\cdots, x_i, \cdots) - J (\cdots, x_i^-, \cdots) \\
>           p_{X_i} (x_i) &= P [+\infty, \cdots, X_i = x_i, \cdots, +\infty] = J (+\infty, \cdots, x_i, \cdots, +\infty) - J (+\infty, \cdots, x_i^-, \cdots, +\infty) \\
>  p_f (y_1, \cdots, y_m) &= P [f_1 (X_1, \cdots, X_m) = y_1, \cdots, f_m (X_1, \cdots, X_m) = y_m] = p (x_1, \cdots, x_m) \\
>                 p_f (y) &= P [f (X) = y] = p (x) \\
> \end{alignedat}
> $$
>

> ### 离散概率密度的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & p (\cdots, x_i, \cdots) \ge 0 \\
> \fbox{2}\quad & \sum\limits_{-\infty}^{+\infty} \cdots \sum\limits_{-\infty}^{+\infty} p (x_1, \cdots, x_m) = 1 \\
> \fbox{3}\quad & \sum\limits_{-\infty}^{x_i} p (\cdots, x_i, \cdots) = C (\cdots, x_i, \cdots) \\
> \end{alignedat}
> $$
>

> ### 连续概率密度

> $$
> \begin{alignedat}{3}
> p (\cdots, x_i, \cdots) &= \dfrac{P [\cdots, x_i \lt X_i \le x_i + \partial x_i, \cdots]}{\partial x_i} = \dfrac{\partial J (\cdots, x_i, \cdots)}{\partial x_i} \\
>           p_{X_i} (x_i) &= \dfrac{P [+\infty, \cdots, x_i \lt X_i \le x_i + \partial x_i, \cdots, +\infty]}{\partial x_i} = \dfrac{\partial J (+\infty, \cdots, x_i, \cdots, +\infty)}{\partial x_i} \\
>  p_f (y_1, \cdots, y_m) &= \dfrac{P [y_1 \lt f_1 (X_1, \cdots, X_m) \le y_1 + \partial y_1, \cdots, y_m \lt f_m (X_1, \cdots, X_m) \le y_m + \partial y_m]}{\partial (y_1, \cdots, y_m)} = p (x_1, \cdots, x_m) \cdot \left| \dfrac{\partial (x_1, \cdots, x_m)}{\partial (y_1, \cdots, y_m)} \right| \\
>                 p_f (y) &= \dfrac{P [y \lt f (X) \le y + \mathrm{d} y]}{\mathrm{d} y} = p (x) \cdot \left| \dfrac{\mathrm{d} x}{\mathrm{d} y} \right| \\
> \end{alignedat}
> $$
>

> ### 连续概率密度的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & p (\cdots, x_i, \cdots) \ge 0 \\
> \fbox{2}\quad & \int_{-\infty}^{+\infty} \cdots \int_{-\infty}^{+\infty} p (x_1, \cdots, x_m) \mathrm{d} x_1 \cdots \mathrm{d} x_m = 1 \\
> \fbox{3}\quad & \int_{-\infty}^{x_i} p (\cdots, x_i, \cdots) \mathrm{d} x_i = C (\cdots, x_i, 
> \cdots) \\
> \end{alignedat}
> $$
>
