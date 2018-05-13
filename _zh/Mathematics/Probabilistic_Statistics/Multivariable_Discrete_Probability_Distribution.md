---
layout:    zh_post
Topic:     概率统计
Title:     多变量概率分布
Revised:   2018-05-14 00:56:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 多项分布 $X \mapsto \mathrm{M_{ulti} N_{omial}} (n, p_1, \cdots, p_m)$

> $$
> \begin{alignedat}{3}
> P (X_1 = k_1, \cdots, X_m = k_m) &= \dfrac{n !}{k_1 ! \cdots k_m !} p_1^{k_1} \cdots p_m^{k_m} \quad\Leftarrow\quad n = \sum_1^m k_m \\
> 
> \end{alignedat}
> $$
>

> ### 多维超几何分布 $X \mapsto \mathrm{M_{ulti} H_{yper geometric}} (N, N_1, \cdots, N_m, n)$

> $$
> \begin{alignedat}{3}
> P (X_1 = n_1, \cdots, X_m = n_m) &= \dfrac{{N_1 \choose n_1} \cdots {N_m \choose n_m}}{{N \choose n}} \\
> \end{alignedat}
> $$
>