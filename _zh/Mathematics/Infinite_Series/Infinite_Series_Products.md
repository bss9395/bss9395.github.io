---
layout:    zh_post
Topic:     无穷级数
Title:     无穷级数乘积
Revised:   2018-03-30 19:39:00 +08 @ 中国-新疆-乌鲁木齐 +06
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

> ### 绝对收敛审敛法

> $$
> \begin{alignedat}{3}
> \Uparrow\;   & \sum_1^{+\infty} \lvert s_n \rvert \to \mathcal{Conv.} \land \sum_1^{+\infty} s_n =S \land \sum_1^{+\infty} \lvert t_n \rvert \to \mathcal{Conv.} \land \sum_1^{+\infty} t_n =T \\
> \Downarrow\; & \sum_1^n \left\lvert \sum_1^n s_i t_{n - i + 1} \right\rvert \le \sum_1^n \lvert s_n \rvert \cdot \sum_1^n \lvert t_n \rvert \le \sum_1^{+\infty} \lvert s_n \rvert \cdot \sum_1^{+\infty} \lvert t_n \rvert \\
> \Downarrow\; & \sum_1^{+\infty} \left\lvert \sum_1^n s_i t_{n - i + 1} \right\rvert \to \mathcal{Conv.} \\
> \Downarrow\; & \sum_1^{+\infty} s_n \cdot \sum_1^{+\infty} t_n = S \cdot T \\
> \end{alignedat}
> $$
>

> ### 条件收敛审敛法

> $$
> \begin{alignedat}{3}
> \Uparrow\;   & \sum_1^{+\infty} \lvert s_n \rvert \to \mathcal{Conv.} \land \sum_1^{+\infty} s_n = S \land \sum_1^{+\infty} t_n = T \\
> \Downarrow\; & \sum_{i = 1}^n s_i T_{n - i + 1} = \sum_{i = 1}^n s_i T + \sum_{i = 1}^n s_i (T_{n - i + 1} - T) \\
> \Downarrow\; & \lim_{+\infty} \left[ \sum_{i = 1}^n s_i T_{n - i + 1} \right] = S \cdot T \quad\Leftarrow\quad \lim_{+\infty} \left[ \sum_{i = 1}^n s_i (T_{n - i + 1} - T) \right] \to 0 \\
>
> \end{alignedat}
> $$
>

