---
layout:    zh_post
Topic:     概率统计
Title:     顺序统计量
Revised:   2018-06-08 23:03:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 顺序样本

> $$
> \begin{alignedat}{3}
>            X &\mapsto C (x) \\
>              &\Downarrow\; \text{Choose} \\
>  x_1, \cdots &, x_i, \cdots, x_n \\
>              &\Downarrow\; \text{Sort} \\
> x_{(1)}, \le &, x_{(i)}, \le, x_{(n)} \\
> \end{alignedat}
> $$
>

> ### 经验累积概率分布 $E_{mpirical} C_{umulative} P_{robability} D_{istribution}$

> $$
> \begin{alignedat}{3}
> EC_n (x) &= \dfrac{\sup\limits_{x_{(i)} \le x} i}{n} = \dfrac{1}{n} \sum_{i = 1}^n \Chi_i [x_i \le x] \quad&&\Leftarrow\quad \Chi_i [x_{i} \le x] \mapsto \mathrm{Tw} (C (x)) \\
>    0 = P & \left[ \lim_{n \to +\infty} \sup_x \middle| EC_n (x) - C (x) \middle| \ge \varepsilon \right]   &&= P \left[ \lim_{n \to +\infty} \sup_x \middle| \dfrac{1}{n} \sum_{i = 1}^n (\Chi_i [x_i \le x] - \mathrm{Exp} [C (x)]) \middle| \ge \varepsilon \right] \\
> \end{alignedat}
> $$
>

> ### 顺序统计量 $O_{rdered} S_{tatistic}$

> $$
> \begin{alignedat}{3}
> OS &= OS [x_{(1)}, \cdots, x_{(n)}] \\
> \end{alignedat}
> $$
>