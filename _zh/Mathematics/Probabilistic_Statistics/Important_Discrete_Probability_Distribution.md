---
layout:    zh_post
Topic:     概率统计
Title:     重要离散概率分布
Revised:   2018-05-06 01:06:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 二项分布 $X \mapsto \mathrm{B_{inary}} (n, p)$

> $$
> \begin{alignedat}{3}
> && P (X = k) &= {n \choose k} p^k (1 - p)^{n - k} \quad\Leftarrow\quad k \in \lbrace 0, 1, \cdots, n \rbrace \\
> && \mathrm{E} (X) &= \sum_0^n k {n \choose k} p^k (1 - p)^{n - k} \\
> && &= n p \sum_1^n {n - 1 \choose k - 1} p^{k - 1} (1 - p)^{(n - 1) - (k - 1)} \\
> && &= np \\
> && \mathrm{E} (X^2) &= \sum_0^n k^2 {n \choose k} p^k (1 - p)^{n - k} \\
> && &= \sum_2^n k (k - 1) {n \choose k} p^k (1 - p)^{n - k} + \sum_1^n k {n \choose k} p^k (1 - p)^{n - k} \\
> && &= n (n - 1) p^2 \sum_2^n {n - 2 \choose k - 2} p^{k - 2} (1 - p)^{(n - 2) - (k - 2)} + n p \sum_1^n {n - 1 \choose k - 1} p^{k - 1} (1 - p)^{(n - 1) - (k - 1)} \\
> && &= n (n - 1) p^2 + n p \\
> && \mathrm{Var} (X) &= E (X^2) - [E (X)]^2 \\
> && &= n p (1 - p) = n p q \\
> \end{alignedat}
> $$
>

> ### 二点分布 $X \mapsto \mathrm{B_{inary}} (1, p)$

> $$
> \begin{alignedat}{3}
> && P (X = k) &= p^k (1 - p)^{1 - k} \quad\Leftarrow\quad k \in \lbrace 0, 1 \rbrace \\
> && \mathrm{E} (X) &= p \\
> && \mathrm{E} (X^2) &= p \\
> && \mathrm{Var} (X) &= p (1 - p) = p q \\
> \end{alignedat}
> $$
>

> ### 