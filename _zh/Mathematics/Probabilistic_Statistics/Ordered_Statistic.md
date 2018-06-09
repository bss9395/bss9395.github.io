---
layout:    zh_post
Topic:     概率统计
Title:     次序统计量
Revised:   2018-06-10 06:58:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 次序样本

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
>    0 = P & \left[ \lim_{n \to +\infty} \sup_x \middle| EC_n (x) - C (x) \middle| \ge \varepsilon \right]   &&= P \left[ \lim_{n \to +\infty} \sup_x \middle| \dfrac{1}{n} \sum_{i = 1}^n (\Iota [x_i \le x] - \mathrm{Exp} [\mathrm{Tw} (C (x))]) \middle| \ge \varepsilon \right] \\
> \end{alignedat}
> $$
>

> ### 次序统计量 $O_{rdered} S_{tatistic}$

> $$
> \begin{alignedat}{3}
> OS &= OS [x_{(1)}, \cdots, x_{(n)}] \quad\Leftarrow\quad p (x_1, \cdots, x_n) = p_{X_1} (x_1) \cdots p_{X_n} (x_n) \\
> \end{alignedat}
> $$
>

> ### 次序统计量的概率分布

> $$
> \begin{alignedat}{3}
>                                                                 \Iota [X_i \le x] &\mapsto \mathrm{Tw} (P [X_i \le x]) = \mathrm{Tw} (C (x)) \\
> \left( \sum_{i = 1}^n \Iota [X_i \le x], \sum_{i = 1}^n \Iota [x \lt X_i] \right) &\mapsto \mathrm{Mn} (n, C (x), 1 - C (x)) \\
>                                                                   C_{X_{(k)}} (x) &= P [X_{(k)} \le x] \\
>                                                                                   &= P \left[ \sum_{i = 1}^n \Iota [X_i \le x] \ge k \right] \\
>                                                                                   &= \sum_{j = k}^n {n \choose j} [C (x)]^j \cdot [1 - C (x)]^{n - j} \\
>                                                                                   &= \dfrac{n !}{(k - 1) ! (n - k) !} \int_0^{C (x)} t^{k - 1} \cdot (1 - t)^{n - k} \mathrm{d} t \\
>                                                                   C_{X_{(1)}} (x) &= 1 - [1 - C (x)]^n \\
>                                                                   C_{X_{(n)}} (x) &= [C (x)]^n \\
>                                                                   p_{X_{(k)}} (x) &= \dfrac{n !}{(k - 1) ! (n - k) !} [C (x)]^{k - 1} \cdot [1 - C (x)]^{n - k} \cdot p_X (x) \\
>                                                                   p_{X_{(1)}} (x) &= n \cdot [1 - C (x)]^{n - 1} \cdot p_X (x) \\
>                                                                   p_{X_{(n)}} (x) &= n \cdot [C (x)]^{n - 1} \cdot p_X (x) \\
> \end{alignedat}
> $$
>

> ### 次序统计量的联合概率分布

> $$
> \begin{alignedat}{3}
>                                                                                                         \Iota [X_i \le x] &\mapsto \mathrm{Tw} (P [X_i \le x]) = \mathrm{Tw} (C (x)) \\
> \left( \sum_{i = 1}^n \Iota [X_i \le x], \sum_{i = 1}^n \Iota [x \lt X_i \le y], \sum_{i = 1}^n \Iota [y \lt X_i] \right) &\mapsto \mathrm{Mn} (n, C(x), C (y) - C (x), 1 - C (y)) \\
>                                                                                  J_{X_{(k)}, X_{(l)}} (x, y \mid k \lt l) &= P [X_{(k)} \le x, X_{(l)} \le y \mid k \lt l] \\
>                                                                                                                           &= P \left[ \sum_{i = 1}^n \Iota [X_i \le x] \ge k, \sum_{i = 1}^n \Iota [X_i \le y] \ge l \middle| k \lt l \right] \\
>                                                                                                                           &= \sum_{j = l}^n \sum_{i = k}^j \dfrac{n !}{i ! (j - i) ! (n - j) !} [C (x)]^i \cdot [C (y) - C (x)]^{j - i} \cdot [1 - C (y)]^{n - j} \\
>                                                                                                                           &= \sum_{j = l}^n \dfrac{n !}{j ! (n - j) !} [1 - C (y)]^{n - j} \cdot \sum_{i = k}^j \dfrac{j !}{i ! (j - i) !} [C (x)]^i \cdot [C (y) - C (x)]^{j - i} \\
>                                                                                                                           &= \sum_{j = l}^n \dfrac{n !}{j ! (n - j) !} [1 - C (y)]^{n - j} \cdot \dfrac{j !}{(k - 1) ! (j - k) !} \int_0^{C (x)} t^{k - 1} \cdot [C (y) - t]^{j - k} \mathrm{d} t \\
>                                                                                                                           &= \int_0^{C (x)} \dfrac{n !}{(k - 1) ! (n - k) !} t^{k - 1} \mathrm{d} t \cdot \sum_{j = l}^n \dfrac{(n - k) !}{(j - k) ! (n - j) !} [C (y) - t]^{j - k} \cdot [1 - C (y)]^{n - j} \\
>                                                                                                                           &= \int_0^{C (x)} \dfrac{n !}{(k - 1) ! (n - k) !} t^{k - 1} \mathrm{d} t \cdot \dfrac{(n - k) !}{(l - k - 1) ! (n - l) !} \int_0^{C (y) - t} s^{l - k - 1} \cdot (1 - t - s)^{n - l} \mathrm{d} s \\
>                                                                                                                           &= \int_0^{C (x)} \int_0^{C (y) - t} \dfrac{n !}{(k - 1) ! (l - k - 1) ! (n - l) !} t^{k - 1} \cdot s^{l - k - 1} \cdot (1 - t - s)^{n - l} \mathrm{d} s \mathrm{d} t \\
>                                                                                  p_{X_{(k)}, X_{(l)}} (x, y \mid k \lt l) &= \dfrac{n !}{(k - 1) ! (l - k - 1) ! (n - l) !} [C (x)]^{k - 1} \cdot [C (y) - C (x)]^{l - k - 1} \cdot [1 - C (y)]^{n - l} \cdot p_X (x) \cdot p_X (y) \\
> \end{alignedat}
> $$
>

