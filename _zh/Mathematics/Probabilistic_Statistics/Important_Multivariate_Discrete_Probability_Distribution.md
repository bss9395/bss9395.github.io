---
layout:    zh_post
Topic:     概率统计
Title:     重要多维离散概率分布
Revised:   2018-05-14 00:56:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 多项分布 $(X_1, \cdots, X_m) \mapsto \mathrm{M_{ulti} n_{omial}} (n, p_1, \cdots, p_m)$

> $$
> \begin{alignedat}{3}
> P (X_1 = k_1, \cdots, X_m = k_m) &= \dfrac{n !}{k_1 ! \cdots k_m !} p_1^{k_1} \cdots p_m^{k_m} \quad\Leftarrow\quad n = \sum_1^m k_m \\
>                    M_{X_1} (x_1) &= \sum_{k_2, \cdots, k_m} \dfrac{n !}{k_1 ! \cdots k_m !} p_1^{k_1} \cdots p_m^{k_m} \\
>                                  &= \dfrac{n !}{k_1 ! (n - k_1) !} p_1^{k_1} \sum_{k2, \cdots, k_m} \dfrac{(n - k_1) !}{k_2 ! \cdots k_m !} p_2^{k_2} \cdots p_m^{k_m} \\
>                                  &= \dfrac{n !}{k_1 ! (n - k_1) !} p_1^{k_1} (p_2 + \cdots + p_m)^{n - k_1} \\
>                                  &= \dfrac{n !}{k_1 ! (n - k_1) !} p_1^{k_1} (1 - p_1)^{n - k_1} \\
> \end{alignedat}
> $$
>

> ### 多维超几何分布 $(X_1, \cdots, X_m) \mapsto \mathrm{M_{ultivariate} H_{yper geometric}} (N_1, \cdots, N_m, n)$

> $$
> \begin{alignedat}{3}
> P (X_1 = k_1, \cdots, X_m = k_m) &= \dfrac{{N_1 \choose k_1} \cdots {N_m \choose k_m}}{{N_1 + \cdots + N_m \choose n}} \quad\Leftarrow\quad n = \sum_1^m k_m \\
> \end{alignedat}
> $$
>
