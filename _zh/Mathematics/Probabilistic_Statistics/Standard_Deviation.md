---
layout:    zh_post
Topic:     概率统计
Title:     标准差
Revised:   2018-05-05 23:33:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 方差

> $$
> \begin{alignedat}{3}
>              \mathrm{Var_{riance}} (X) &= E (X - E (X))^2 \\
>                                        &= E (X^2 - 2 X \cdot E (X) + E^2 (X)) \\
>                                        &= E (X^2) - E^2 (X) \\
>  \mathrm{S_{tandard} D_{eviation}} (X) &= \sqrt{\mathrm{Var} (X)} \\
>                                        &= \sqrt{E (X^2) - E^2 (X)} \\
> \end{alignedat}
> $$
>

> ### 方差的性质

> $$
> \begin{array}{lll}
> \fbox{1} & \mathrm{Var} (c) = 0 \\
> \fbox{2} & \mathrm{Var} (c \cdot X + d) = c^2 \cdot \mathrm{Var} (X) \\
> \fbox{3} & \mathrm{Var} (X) + \mathrm{E}^2 (X) = \mathrm{E} (X^2) = 0 \implies \mathrm{E} (X) = 0 \;\and\; \mathrm{Var} (X) = 0 \\
> \fbox{4} & \mathrm{Var} (X) = 0 \iff P (X = \mathrm{E} (X)) = 1  \\
> \end{array}
> $$
>

> ### 离散标准差

> $$
> \begin{alignedat}{3}
>              \mathrm{Var_{iance}} (X) &= \sum x_i^2 \cdot p (x_i) - \left[ \sum x_i \cdot p (x_i) \right]^2 \\
> \mathrm{S_{tandard} D_{eviation}} (X) &= \sqrt{\sum x_i^2 \cdot p (x_i) - \left[ \sum x_i \cdot p (x_i) \right]^2}
> \end{alignedat}
> $$
>

> ### 连续标准差

> $$
> \begin{alignedat}{3}
>              \mathrm{Var_{iance}} (X) &= \int x^2 \cdot p (x) \mathrm{d} x - \left[ \int x \cdot p (x) \mathrm{d} x \right]^2 \\
> \mathrm{S_{tandard} D_{eviation}} (X) &= \sqrt{\int x^2 \cdot p (x) \mathrm{d} x - \left[ \int x \cdot p (x) \mathrm{d} x \right]^2} \\
> \end{alignedat}
> $$
>

> ### 偏差概率

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   && P (|X - \mathrm{E} (X)| \ge \varepsilon) &= \sum_{|x_i - \mathrm{E} (X)| \ge \varepsilon} p (x_i) \\
>                 &&                                          &\le \sum_{|x_i - \mathrm{E} (X)| \ge \varepsilon} \dfrac{(x_i - \mathrm{E} (X))^2}{\varepsilon^2} p (x_i) \\
>                 &&                                          &\le \sum \dfrac{(x_i - \mathrm{E} (X))^2}{\varepsilon^2} p (x_i) \\
>                 &&                                          &= \dfrac{\mathrm{Var} (X)}{\varepsilon^2} \\
> \Downarrow\quad && P (|X - \mathrm{E} (X)| \lt \varepsilon) &= 1 - P (|X - \mathrm{E} (X)| \ge \varepsilon) \\
>                 &&                                          &\ge 1 - \dfrac{\mathrm{Var} (X)}{\varepsilon^2} \\
> \end{alignedat}
> $$
>
