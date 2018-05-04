---
layout:    zh_post
Topic:     概率统计
Title:     概率分布
Revised:   2018-05-04 19:50:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 累积概率分布函数

> $$
> \begin{array}{l|l|l}
>                     & P (X \lt \beta) = C (\beta^-)           & P (\alpha \lt X \lt \beta) = C(\beta^-) - C (\alpha) \\
>                     & P (X \le \beta) = C (\beta)             & P (\alpha \lt X \le \beta) = C (\beta) - C (\alpha) \\
> C (x) = P (X \le x) & P (X = \beta) = C (\beta) - C (\beta^-) & \\
>                     & P (X \ge \beta) = 1 - C (\beta^-)       & P (\alpha \le X \lt \beta) = C (\beta^-) - C (\alpha^-) \\
>                     & P (X \gt \beta) = 1 - C (\beta)         & P (\alpha \le X \le \beta) = C (\beta) - C (\alpha^-) \\
> \end{array}
> $$
>

> ### 累积概率分布函数的性质

> $$
> \begin{array}{ll|l}
> \fbox{1} & x \lt y \implies F (x) \le F (y) \\
> \fbox{2} & F (-\infty) = \lim\limits_{-\infty} F (x) = 0 & F (+\infty) = \lim\limits_{+\infty} F (x) = 1 \\
> \fbox{3} & F (x_0) = \lim\limits_{x_0^+} F (x)           & F (x_0^-) \le F (x_0) = F (x_0^+) \\
> \end{array}
> $$
>

> ### 离散概率密度函数

> $$
> \begin{array}{lll}
> p (x_i) = P (X = x_i) = C (x_i) - C (x_i^-) \\
> \end{array}
> $$
>

> ### 离散概率密度函数的性质

> $$
> \begin{array}{lll}
> \fbox{1} & p (x_i) \ge 0 \\
> \fbox{2} & \sum\limits_{-\infty}^{+\infty} p (x_i) = 1 \\
> \fbox{3} & C (x) = \sum\limits_{-\infty}^x p (x_i) \\
> \end{array}
> $$
>

> ### 连续概率密度函数

> $$
> \begin{array}{lll}
> p (x) = \dfrac{P (x \lt X \lt x + \mathrm{d} x)}{\mathrm{d} x} = \dfrac{\mathrm{d} C (x)}{\mathrm{d} x} \\
> \end{array}
> $$
>

> ### 连续概率密度函数的性质

> $$
> \begin{array}{lll}
> \fbox{1} & p (x) \ge 0 \\
> \fbox{2} & \int_{-\infty}^{+\infty} p (x) = 1 \\
> \fbox{3} & C (x) = \int_{-\infty}^x p (x) \\
> \end{array}
> $$
>

