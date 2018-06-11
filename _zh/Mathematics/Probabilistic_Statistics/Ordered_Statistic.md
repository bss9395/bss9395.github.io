---
layout:    zh_post
Topic:     概率统计
Title:     次序统计量
Revised:   2018-06-10 22:58:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 次序样本

> $$
> \begin{alignedat}{3}
>                           X &\mapsto C (x) \\
>                             &\Downarrow\; \text{Choose} \\
>              \chi_1, \cdots &, \chi_i, \cdots, \chi_n \\
>                             &\Downarrow\; \text{Sort} \\
> \chi_{\langle1\rangle}, \le &, \chi_{\langle i\rangle}, \le, \chi_{\langle n \rangle} \\
> \end{alignedat}
> $$
>

> ### 经验累积概率分布 $E_{mpirical} C_{umulative} P_{robability} D_{istribution}$

> $$
> \begin{alignedat}{3}
> EC_n (x) &= \dfrac{\sup\limits_{\chi_{\langle i \rangle} \le x} i}{n} = \dfrac{1}{n} \sum_{i = 1}^n \Iota [\chi_i \le x] \quad&&\Leftarrow\quad \Iota [\chi_{i} \le x] \mapsto \mathrm{Tw} (P [\chi_i \le x]) = \mathrm{Tw} (C (x)) \\
>    0 = P & \left[ \lim_{n \to +\infty} \sup_x \middle| EC_n (x) - C (x) \middle| \ge \varepsilon \right]                      &&= P \left[ \lim_{n \to +\infty} \sup_x \middle| \dfrac{1}{n} \sum_{i = 1}^n (\Iota [\chi_i \le x] - \mathrm{Exp} [\mathrm{Tw} (C (x))]) \middle| \ge \varepsilon \right] \\
> \end{alignedat}
> $$
>

> ### 次序统计量 $O_{rdered} S_{tatistic}$

> $$
> \begin{alignedat}{3}
> OS &= OS [\chi_{\langle 1 \rangle}, \cdots, \chi_{\langle n \rangle}] \quad\Leftarrow\quad p (\chi_1, \cdots, \chi_n) = p_X (\chi_1) \cdots p_X (\chi_n) \\
> \end{alignedat}
> $$
>

> ### 次序统计量的概率分布

> $$
> \begin{alignedat}{3}
>                                                                 \Iota [X_i \le x] &\mapsto \mathrm{Tw} (P [X_i \le x]) = \mathrm{Tw} (C (x)) \\
> \left( \sum_{i = 1}^n \Iota [X_i \le x], \sum_{i = 1}^n \Iota [x \lt X_i] \right) &\mapsto \mathrm{Mn} (n, C (x), 1 - C (x)) \\
>                                                     C_{X_{\langle k \rangle}} (x) &= P [X_{\langle k \rangle} \le x] \\
>                                                                                   &= P \left[ \sum_{i = 1}^n \Iota [X_i \le x] \ge k \right] \\
>                                                                                   &= \sum_{j = k}^n {n \choose j} [C (x)]^j \cdot [1 - C (x)]^{n - j} \\
>                                                                                   &= \dfrac{n !}{(k - 1) ! (n - k) !} \int_0^{C (x)} t^{k - 1} \cdot (1 - t)^{n - k} \mathrm{d} t \\
>                                                     C_{X_{\langle 1 \rangle}} (x) &= 1 - [1 - C (x)]^n \\
>                                                     C_{X_{\langle n \rangle}} (x) &= [C (x)]^n \\
>                                                     p_{X_{\langle k \rangle}} (x) &= \dfrac{n !}{(k - 1) ! (n - k) !} [C (x)]^{k - 1} \cdot [1 - C (x)]^{n - k} \cdot p_X (x) \\
>                                                     p_{X_{\langle 1 \rangle}} (x) &= n \cdot [1 - C (x)]^{n - 1} \cdot p_X (x) \\
>                                                     p_{X_{\langle n \rangle}} (x) &= n \cdot [C (x)]^{n - 1} \cdot p_X (x) \\
> \end{alignedat}
> $$
>

> ### 次序统计量的联合概率分布

> $$
> \begin{alignedat}{3}
>                                                                                                         \Iota [X_i \le x] &\mapsto \mathrm{Tw} (P [X_i \le x]) = \mathrm{Tw} (C (x)) \\
> \left( \sum_{i = 1}^n \Iota [X_i \le x], \sum_{i = 1}^n \Iota [x \lt X_i \le y], \sum_{i = 1}^n \Iota [y \lt X_i] \right) &\mapsto \mathrm{Mn} (n, C (x), C (y) - C (x), 1 - C (y)) \\
>                                                      J_{X_{\langle k \rangle}, X_{\langle l \rangle}} (x, y \mid k \lt l) &= P [X_{\langle k \rangle} \le x, X_{\langle l \rangle} \le y \mid k \lt l] \\
>                                                                                                                           &= P \left[ \sum_{i = 1}^n \Iota [X_i \le x] \ge k, \sum_{i = 1}^n \Iota [X_i \le y] \ge l \middle| k \lt l \right] \\
>                                                                                                                           &= \sum_{j = l}^n \sum_{i = k}^j \dfrac{n !}{i ! (j - i) ! (n - j) !} [C (x)]^i \cdot [C (y) - C (x)]^{j - i} \cdot [1 - C (y)]^{n - j} \\
>                                                                                                                           &= \sum_{j = l}^n \dfrac{n !}{j ! (n - j) !} [1 - C (y)]^{n - j} \cdot \sum_{i = k}^j \dfrac{j !}{i ! (j - i) !} [C (x)]^i \cdot [C (y) - C (x)]^{j - i} \\
>                                                                                                                           &= \sum_{j = l}^n \dfrac{n !}{j ! (n - j) !} [1 - C (y)]^{n - j} \cdot \dfrac{j !}{(k - 1) ! (j - k) !} \int_0^{C (x)} t^{k - 1} \cdot [C (y) - t]^{j - k} \mathrm{d} t \\
>                                                                                                                           &= \int_0^{C (x)} \dfrac{n !}{(k - 1) ! (n - k) !} t^{k - 1} \mathrm{d} t \cdot \sum_{j = l}^n \dfrac{(n - k) !}{(j - k) ! (n - j) !} [C (y) - t]^{j - k} \cdot [1 - C (y)]^{n - j} \\
>                                                                                                                           &= \int_0^{C (x)} \dfrac{n !}{(k - 1) ! (n - k) !} t^{k - 1} \mathrm{d} t \cdot \dfrac{(n - k) !}{(l - k - 1) ! (n - l) !} \int_0^{C (y) - t} s^{l - k - 1} \cdot (1 - t - s)^{n - l} \mathrm{d} s \\
>                                                                                                                           &= \int_0^{C (x)} \int_0^{C (y) - t} \dfrac{n !}{(k - 1) ! (l - k - 1) ! (n - l) !} t^{k - 1} \cdot s^{l - k - 1} \cdot (1 - t - s)^{n - l} \mathrm{d} s \mathrm{d} t \\
>                                                                   J_{X_{\langle 1 \rangle}, X_{\langle n \rangle}} (x, y) &= \sum_{i = 1}^n \dfrac{n !}{i ! (n - i) !} [C (x)]^i \cdot [C (y) - C (x)]^{n - i} \\
>                                                                                                                           &= \int_0^{C (x)} \int_0^{C (y) - t} \dfrac{n !}{(n - 2) !} s^{n - 2} \mathrm{d} s \mathrm{d} t \\
>                                                      p_{X_{\langle k \rangle}, X_{\langle l \rangle}} (x, y \mid k \lt l) &= \dfrac{n !}{(k - 1) ! (l - k - 1) ! (n - l) !} [C (x)]^{k - 1} \cdot [C (y) - C (x)]^{l - k - 1} \cdot [1 - C (y)]^{n - l} \cdot p_X (x) \cdot p_X (y) \\
>                                                                   p_{X_{\langle 1 \rangle}, X_{\langle n \rangle}} (x, y) &= \dfrac{n !}{(n - 2) !} [C (y) - C (x)]^{n - 2} \cdot p_{X} (x) \cdot p_X (y) \\
>                                               p_{X_{\langle 1 \rangle}, \cdots, X_{\langle n \rangle}} (y_1, \cdots, y_n) &= n ! \cdot p_X (y_1) \cdots p_{X} (y_n) \\
> \end{alignedat}
> $$
>

> ### 次序统计量极差的概率分布

> $$
> \begin{alignedat}{3}
> C_{X_{\langle n \rangle} - X_{\langle 1 \rangle}} (z) &= P [X_{\langle n \rangle} - X_{\langle 1 \rangle} \le z] \\
>                                                       &= \int_{(x, y): y - x \le z} p_{X_{(1)}, X_{(n)}} (x, y) \mathrm{d} (x, y) \\
>                                                       &= \int_{-\infty}^{+\infty} \int_x^{x + z} p_{X_{\langle 1 \rangle}, {X_{\langle n \rangle}}} (x, y) \mathrm{d} y \mathrm{d} x \\
>                                                       &= \int_{-\infty}^{+\infty} \int_x^{x + z} \dfrac{n !}{(n - 2) !} [C (y) - C (x)]^{n - 2} \cdot p_{X} (x) \cdot p_X (y) \mathrm{d} y \mathrm{d} x \\
>                                                       &= n \int_{-\infty}^{+\infty} [C (x + z) - C (x)]^{n - 1} \cdot p_X (x) \mathrm{d} x \\
> p_{X_{\langle n \rangle} - X_{\langle 1 \rangle}} (z) &= n \cdot (n - 1) \int_{-\infty}^{+\infty} [C (x + z) - C (x)]^{n - 2} \cdot p_X (x + z) \cdot p_X (x) \mathrm{d} x \\
> \end{alignedat}
> $$
>

> ### 次序样本分位数 $\mathrm{Q_{uantile}}$

> $$
> \begin{alignedat}{3}
> {_\frac{1}{2} \chi} &:= \dfrac{\chi_{\langle\lceil \frac{n}{2} \rceil\rangle} + \chi_{\langle\lfloor \frac{n + 1}{2} \rfloor\rangle}}{2} \\
> {_Q \chi} &:= \dfrac{\chi_{\langle\lceil n \cdot Q \rceil\rangle} + \chi_{\langle\lfloor (n + 1) \cdot Q \rfloor\rangle}}{2} \\
> \end{alignedat}
> $$
>

