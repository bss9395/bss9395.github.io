---
layout:    zh_post
Topic:     组合数学
Title:     重要图案
Revised:   2018-05-14 00:35:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 二项式三角形

> ![max-width:360px;](figures/Binomial_Triangle.svg)

> ### 二项式定理

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   &&       (u + v)^1 &= {1 \choose 0} u^0 v^1 + {1 \choose 1} u^1 v^0 \\
> \Uparrow\quad   && (u + v)^{n + 1} &= \sum_{i = 0}^n {n \choose i} u^{n - i + 1} v^i + \sum_{j = 0}^n {n \choose j} u^{n - j} v^{j + 1} \\
>                 &&                 &= u^{n + 1} +  \sum_{i = 1}^n {n \choose i} u^{n - i + 1} v^i + \sum_{j = 0}^{n - 1} {n \choose j} u^{n - j} v^{j + 1} + v^{n + 1} \\
>                 &&                 &= u^{n + 1} + \sum_{k = 1}^n \left[ {n \choose k} + {n \choose k - 1} \right] u^{n - k + 1} v^k + v^{n + 1} \\
> \Downarrow\quad && (u + v)^{n + 1} &= \sum_{k = 0}^{n + 1} {n + 1 \choose k} u^{n + 1 - k} v^k \\
> \end{alignedat}
> $$
>

> ### 多项式定理

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   && {n \choose n_1} {n - n_1 \choose n_2} \cdots {n - n_1 - n_2 \cdots - n_{m - 1} \choose n_m} &= \dfrac{n !}{n_1 ! (n - n_1) !} \dfrac{(n - n_1) !}{n_2 ! (n - n_1 - n_2) !} \cdots \dfrac{(n - n_1 - n_2 \cdots - n_{m - 1}) !}{n_m ! (n - n_1 - n_2 \cdots - n_{m - 1} - n_m) !} \\
>                 &&                                                                                             &= \dfrac{n !}{n_1 ! n_2 ! \cdots n_m !} \quad\Leftarrow\quad n = n_1 + n_2 \cdots n_m \\
> \Downarrow\quad &&                                                                  (p_1 + p_2 + \cdots p_m)^n &= \sum_{n_1 + n_2 + \cdots + n_m = n} \dfrac{n !}{n_1 ! n_2 ! \cdots n_m !} p_1^{n_1} p_2^{n_2} \cdots p_m^{n_m} \\
> \end{alignedat}
> $$
>