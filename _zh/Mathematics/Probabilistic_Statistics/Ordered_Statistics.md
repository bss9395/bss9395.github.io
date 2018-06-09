---
layout:    zh_post
Topic:     概率统计
Title:     顺序统计量
Revised:   2018-06-09 23:51:00 +08 @ 中国-新疆-乌鲁木齐 +06
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
> EC_n (x) &= \dfrac{\sup\limits_{x_{(i)} \le x} i}{n} = \dfrac{1}{n} \sum_{i = 1}^n \Iota [x_i \le x] \quad&&\Leftarrow\quad \Iota [x_{i} \le x] \mapsto \mathrm{Tw} (P [x_i \le x]) = \mathrm{Tw} (C (x)) \\
>    0 = P & \left[ \lim_{n \to +\infty} \sup_x \middle| EC_n (x) - C (x) \middle| \ge \varepsilon \right]   &&= P \left[ \lim_{n \to +\infty} \sup_x \middle| \dfrac{1}{n} \sum_{i = 1}^n (\Iota_i [x_i \le x] - \mathrm{Exp} [\mathrm{Tw} (C (x))]) \middle| \ge \varepsilon \right] \\
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

> ### 顺序统计量

> $$
> \begin{alignedat}{3}
>                \Iota [X_i \le x] &\mapsto \mathrm{Tw} (P [X_i \le x]) = \mathrm{Tw} (C (x)) \\
> \sum_{i = 1}^n \Iota [X_i \le x] &\mapsto \mathrm{Bn} (C (x)) \\
>                  C_{X_{(i)}} (x) &= P [X_{(i)} \le x] \\
>                                  &= P \left[ \sum_{i = 1}^n \Iota [X_i \le x] \ge i \right] \\
>                                  &= \sum_{j = i}^n {n \choose j} [C (x)]^j \cdot [1 - C (x)]^{n - j} \\
>                                  &= \dfrac{n !}{(i - 1) ! (n - i) !} \int_0^{C (x)} t^{i - 1} \cdot (1 - t)^{n - i} \mathrm{d} t \\
>                  C_{X_{(1)}} (x) &= 1 - [1 - C (x)]^n \\
>                  C_{X_{(n)}} (x) &= [C (x)]^n \\
>                  p_{X_{(i)}} (x) &\xlongequal{p_{X(i)} (x) \in \mathcal{Conti.}} \dfrac{n !}{(i - 1) ! (n - i) !} [C (x)]^{i - 1} \cdot [1 - C (x)]^{n - i} \cdot p_X (x) \\
>                  p_{X_{(1)}} (x) &= n \cdot [1 - C (x)]^{n - 1} \cdot p_X (x) \\
>                  p_{X_{(n)}} (x) &= n \cdot [C (x)]^{n - 1} \cdot p_X (x) \\
> \end{alignedat}
> $$
>

