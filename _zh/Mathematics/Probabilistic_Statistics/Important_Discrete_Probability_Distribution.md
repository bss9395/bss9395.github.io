---
layout:    zh_post
Topic:     概率统计
Title:     重要离散概率分布
Revised:   2018-05-07 02:17:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 二项分布 $X \mapsto \mathrm{B_{inary}} (n, p)$

> $$
> \begin{alignedat}{3}
>        P (X = k) &= {n \choose k} p^k (1 - p)^{n - k} \quad\Leftarrow\quad k \in \lbrace 0, 1, \cdots, n \rbrace \\
>   \mathrm{E} (X) &= \sum_0^n k {n \choose k} p^k (1 - p)^{n - k} \\
>                  &= n p \sum_1^n {n - 1 \choose k - 1} p^{k - 1} (1 - p)^{(n - 1) - (k - 1)} \\
>                  &= np \\
> \mathrm{E} (X^2) &= \sum_0^n k^2 {n \choose k} p^k (1 - p)^{n - k} \\
>                  &= \sum_2^n k (k - 1) {n \choose k} p^k (1 - p)^{n - k} + \sum_1^n k {n \choose k} p^k (1 - p)^{n - k} \\
>                  &= n (n - 1) p^2 \sum_2^n {n - 2 \choose k - 2} p^{k - 2} (1 - p)^{(n - 2) - (k - 2)} + n p \sum_1^n {n - 1 \choose k - 1} p^{k - 1} (1 - p)^{(n - 1) - (k - 1)} \\
>                  &= n (n - 1) p^2 + n p \\
> \mathrm{Var} (X) &= E (X^2) - [E (X)]^2 \\
>                  &= n p (1 - p) = n p q \\
> \end{alignedat}
> $$
>

> ### 二点分布 $X \mapsto \mathrm{B_{inary}} (1, p)$

> $$
> \begin{alignedat}{3}
>        P (X = k) &= p^k (1 - p)^{1 - k} \quad\Leftarrow\quad k \in \lbrace 0, 1 \rbrace \\
>   \mathrm{E} (X) &= p \\
> \mathrm{E} (X^2) &= p \\
> \mathrm{Var} (X) &= p (1 - p) = p q \\
> \end{alignedat}
> $$
>

> ### 随机分布 $X \mapsto \mathrm{S_{tochastic}} (\lambda)$

> $$
> \begin{alignedat}{3}
>        P (X = k) &= \dfrac{\lambda^k}{k !} e^{- \lambda} \quad\Leftarrow\quad e^\lambda = \sum_0^{+\infty} \dfrac{\lambda^k}{k !} \quad\Leftarrow\quad k \in \mathbb{N} \\
>   \mathrm{E} (X) &= \sum_0^{+\infty} k \dfrac{\lambda^k}{k !} e^{- \lambda} \\
>                  &= \lambda e^{- \lambda} \sum_1^{+\infty} \dfrac{\lambda^{k - 1}}{(k - 1) !} \\
>                  &= \lambda \\
> \mathrm{E} (X^2) &= \sum_0^{+\infty} k^2 \dfrac{\lambda^k}{k !} e^{- \lambda} \\
>                  &= \sum_2^{+\infty} k (k - 1) \dfrac{\lambda^k}{k !} e^{- \lambda} + \sum_1^{+\infty} k \dfrac{\lambda^k}{k !} e^{- \lambda} \\
>                  &= \lambda^2 e^{- \lambda} \sum_2^{+\infty} \dfrac{\lambda^{k - 2}}{(k - 2) !} + \lambda e^{- \lambda} \sum_1^{+\infty} \dfrac{\lambda^{k - 1}}{(k - 1) !} \\
>                  &= \lambda (\lambda + 1) \\
> \mathrm{Var} (X) &= \mathrm{E} (X^2) - [\mathrm{E} (X)]^2 \\
>                  &= \lambda \\
> \end{alignedat}
> $$
>

> ### 二项分布的随机分布近似

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   && \lim_{+\infty} n \cdot p_n = \lambda \\
> \Downarrow\quad && \lim_{+\infty} {n \choose k} p_n^k (1 - p_n)^{n - k} &= \lim_{+\infty} \dfrac{n !}{k ! (n - k) !} \left( \dfrac{\lambda}{n} \right)^k \left( 1 - \dfrac{\lambda}{n} \right)^{n - k} \\
>                 &&                                                      &= \lim_{+\infty} \dfrac{\prod\limits_1^{k} (n - k + 1)}{n^k} \dfrac{\lambda^k}{k !} \left( 1 - \dfrac{\lambda}{n} \right)^n \left( 1 - \dfrac{\lambda}{n} \right)^{- k} \\
>                 &&                                                      &= \dfrac{\lambda^k}{k !} \cdot \lim_{+\infty} \prod_1^k \left( 1 - \dfrac{k + 1}{n} \right) \cdot \lim_{+\infty} \left( 1 - \dfrac{\lambda}{n} \right)^n \cdot \lim_{+\infty} \left( 1 - \dfrac{\lambda}{n} \right)^{- k} \\
>                 &&                                                      &= \dfrac{\lambda^k}{k !} e^{- \lambda} \\
> \Downarrow\quad &&                    {n \choose k} p^k (1 - p)^{n - k} &\approx \dfrac{(n \cdot p)^k}{k !} e^{- (n \cdot p)}
> \end{alignedat}
> $$
>

> ### 超几何分布 $X \mapsto \mathrm{H_{ypergeometric}} (N, K, n) $

> $$
> \begin{alignedat}{3}
>      P (X = k) &= \dfrac{{K \choose k} {N - K \choose n - k}}{{N \choose n}} \quad\Leftarrow\quad k \in \lbrace 0, 1, \cdots, \min (K, n) \rbrace \\
> \mathrm{E} (X) &= \sum_0^{\min (K, n)} k \dfrac{{K \choose k} {N - K \choose n - k}}{{N \choose n}} \\
>                &= \dfrac{n K}{N} \sum_0^{\min (K, n)} \dfrac{{K - 1 \choose k - 1} {N - K \choose n - k}}{{N - 1 \choose n - 1}} \\
>                &= \dfrac{n K}{N} \\
> \end{alignedat}
> $$
>