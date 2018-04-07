---
layout:    zh_post
Topic:     收敛极限
Title:     无穷级数乘积
Revised:   2018-04-01 20:40:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 级数乘积的性质

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&                 \sum_1^n s_n \cdot \sum_1^m t_m &= \sum_1^n \sum_1^m \begin{pmatrix}
>                                                                                      s_1 t_1 & s_1 t_2 & \cdots & s_1 t_m \\
>                                                                                      s_2 t_1 & s_2 t_2 & \cdots & s_2 t_m \\
>                                                                                      \vdots  & \vdots  & \ddots & \vdots \\
>                                                                                      s_n t_1 & s_n t_2 & \cdots & s_n t_m \\
>                                                                                      \end{pmatrix} \\
> \Downarrow\; && \sum_1^{+\infty} s_n \cdot \sum_1^{+\infty} t_n &= (s_1 t_1) + (s_1 t_2 + s_2 t_1) + \cdots + (s_1 t_n + s_2 t_{n - 1} + \cdots + s_n t_1) + \cdots \\
>              &&                                      \fbox{1}\; &= \sum_1^{+\infty} \left[ \sum_{i = 1}^n s_i t_{n - i + 1} \right] \\
>              &&                                      \fbox{2}\; &= \lim_{+\infty} \left[ \sum_{i = 1}^n s_i T_{n - i + 1} \right] \\
> \Downarrow\; && \sum_1^{+\infty} s_n \cdot \sum_1^{+\infty} t_n &= (s_1 t_1) + (s_1 t_2 + s_2 t_2 + s_2 t_1) + \cdots + (s_1 t_n + s_2 t_n + \cdots + s_n t_n + \cdots + s_n t_2 + s_n t_1) + \cdots \\
>              &&                                      \fbox{3}\; &= \sum_1^{+\infty} \left[ - s_n t_n + \sum_{i = 1}^n (s_i t_n + s_n t_i) \right] \\
> \end{alignedat}
> $$
>

> ### 条件收敛审敛法

> $$
> \begin{alignedat}{3}
>                    & \sum_1^{+\infty} s_n = S;\quad \sum_1^{+\infty} t_n = T \\
> \fbox{1}\Uparrow\; & \sum_1^{+\infty} \lvert s_n \rvert \to \mathcal{Conv.} \quad\Rightarrow\quad\lim_{+\infty} \sum_{i + j = n + 1} s_i \cdot (T_j - T) \to 0 \\
> \Uparrow\;         & \sum_{i + j = n + 1} s_i \cdot T_j = \sum_{i = 1}^n s_i \cdot T + \sum_{i + j = n + 1} s_i \cdot (T_j - T) \\
> \fbox{2}\Uparrow\; & \lim_{+\infty} \sum_{i + j = n + 1} s_i \cdot T_j \to \mathcal{Conv.} \\
> \Uparrow\;         & \lim_{+\infty} \sum_{i + j = n + 1} s_i \cdot T_j = \lim_{+\infty} \dfrac{1}{m} \sum_{n = 1}^m \left( \sum_{i + j = n + 1} s_i \cdot T_j \right) = \lim_{+\infty} \dfrac{1}{m} \sum_{i + j = m + 1} S_i \cdot T_j \\
> \Downarrow\;       & \sum_1^{+\infty} s_n \cdot \sum_1^{+\infty} t_n = S \cdot T = \lim_{+\infty} \sum_{i + j = n + 1} s_i \cdot T_j \\
> \end{alignedat}
> $$
>

> ### 绝对收敛审敛法

> $$
> \begin{alignedat}{3}
>              & \sum_1^{+\infty} s_n =S;\quad \sum_1^{+\infty} t_n =T \\
> \Uparrow\;   & \sum_1^n \left\lvert \sum_{i + j = n + 1} s_i \cdot t_j \right\rvert \le \sum_1^n \lvert s_n \rvert \cdot \sum_1^n \lvert t_n \rvert \le \sum_1^{+\infty} \lvert s_n \rvert \cdot \sum_1^{+\infty} \lvert t_n \rvert \\
> \Uparrow\;   &  \sum_1^{+\infty} \lvert s_n \rvert \to \mathcal{Conv.} \land  \sum_1^{+\infty} \lvert t_n \rvert \to \mathcal{Conv.} \\
> \Downarrow\; & \sum_1^{+\infty} \left\lvert \sum_{i + j = n + 1} s_i \cdot t_j \right\rvert \to \mathcal{Conv.} \\
> \Downarrow\; & \sum_1^{+\infty} \sum_{i + j = n + 1} s_i \cdot t_j = \sum_1^{+\infty} s_n \cdot \sum_1^{+\infty} t_n = S \cdot T \\
> \end{alignedat}
> $$
>