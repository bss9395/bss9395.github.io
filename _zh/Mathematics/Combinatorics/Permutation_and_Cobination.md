---
layout:    zh_post
Topic:     组合数学
Title:     排列组合
Revised:   2018-05-07 01:13:00 +08 @ 中国-新疆-乌鲁木齐 +06
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
> n^k \\
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
> {n + k - 1 \choose k} \\
> \end{alignedat}
> $$
>

> ### 组合的性质

> $$
> \begin{array}{lll}
> \fbox{1} & {n \choose k} = {n \choose n - k} \\
> \fbox{2} & {n \choose k} = {n - 1 \choose k - 1} + {n - 1 \choose k} \\
> \fbox{3} & \sum\limits_{k = 0}^n {n \choose k} = 2^n \\
> \fbox{4} & \sum\limits_{k = 1}^n k {n \choose k} = n 2^{n - 1} \\
> \fbox{5} & \sum\limits_{l = 0}^k {n \choose l} {m \choose k - l} = {n + m \choose k} &\Leftarrow\; \left[ \sum\limits_{i = 0}^n {n \choose i} x^i \right] \cdot \left[ \sum\limits_{j = 0}^m {m \choose j} x^j \right] \xlongequal[(1 + x)^{n + m}]{(1 + x)^n \cdot (1 + x)^m} \sum\limits_{k = 0}^{n + m} {n + m \choose k} x^k \\
> \fbox{6} & \sum\limits_{k = 0}^n {n \choose k}^2 = {2 n \choose n} \\
> \end{array}
> $$
>

