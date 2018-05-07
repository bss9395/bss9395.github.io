---
layout:    zh_post
Topic:     组合数学
Title:     排列组合
Revised:   2018-05-08 02:08:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 非重复排列

> $$
> \begin{alignedat}{3}
> k \le n \implies \mathcal{P}_n^k = \dfrac{n !}{(n - k) !} \\
> \end{alignedat}
> $$
>

> ### 重复排列

> $$
> \begin{alignedat}{3}
> \mathcal{P} = n^k \\
> \end{alignedat}
> $$
>

> ### 非重复组合

> $$
> \begin{alignedat}{3}
> k \le n \implies {n \choose k} &= \mathcal{C}_n^k = \dfrac{\mathcal{P}_n^k}{k !} = \dfrac{n !}{k ! (n - k) !} \\
> \end{alignedat}
> $$
>

> ### 重复组合

> $$
> \begin{alignedat}{3}
> \mathcal{C} = {n + k - 1 \choose k} \\
> \end{alignedat}
> $$
>

> ### 组合的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & {n \choose k} = {n \choose n - k} \\
> \fbox{2}\quad & {n \choose k} = \dfrac{n}{k} {n - 1 \choose k - 1} \\
> \fbox{3}\quad & {n \choose k} = {n - 1 \choose k - 1} + {n - 1 \choose k} \\
> \fbox{4}\quad & {n + k - 1 \choose k} = (- 1)^k \dfrac{(- n) (- n - 1) \cdots (- n - k + 1)}{k !} = (- 1)^k {- n \choose k}  \\
> \fbox{5}\quad & \sum\limits_{k = 0}^n {n \choose k} = (1 + 1)^n = 2^n \\
> \fbox{6}\quad & \sum_{k = 0}^{+\infty} {n + k - 1 \choose k} p^k = \sum_{k = 0}^{+\infty} {- n \choose k} (- p)^k = (1 - p)^{- n} \\
> \fbox{7}\quad & \sum\limits_{k = 0}^n k {n \choose k} = n \sum_{k = 1}^n {n - 1 \choose k - 1} = n 2^{n - 1} \\
> \fbox{8}\quad & \sum\limits_{\max (0, k - m)}^{\min (n, k)} {n \choose i} {m \choose k - i} = \sum\limits_{\max (k -n, 0)}^{\min (k, m)} {n \choose k - j} {m \choose j} = {n + m \choose k} \quad\Leftarrow\quad \left[ \sum\limits_{i = 0}^n {n \choose i} x^i \right] \cdot \left[ \sum\limits_{j = 0}^m {m \choose j} x^j \right] \xlongequal[(1 + x)^{n + m}]{(1 + x)^n \cdot (1 + x)^m} \sum\limits_{k = 0}^{n + m} {n + m \choose k} x^k \\
> \fbox{9}\quad & \sum\limits_{k = 0}^n {n \choose k}^2 = {2 n \choose n} \\
> \end{alignedat}
> $$
>

