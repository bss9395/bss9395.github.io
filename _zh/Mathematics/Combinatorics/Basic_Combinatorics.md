---
layout:    zh_post
Topic:     组合数学
Title:     基础组合数学
Revised:   2018-05-02 17:29:00 +08 @ 中国-新疆-乌鲁木齐 +06
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
>                  {n \choose k} &= {n \choose n - k} \\
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