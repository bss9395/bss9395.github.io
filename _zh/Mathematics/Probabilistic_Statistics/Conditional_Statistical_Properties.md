---
layout:    zh_post
Topic:     概率统计
Title:     条件统计特性
Revised:   2018-05-24 22:11:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 条件离散期望

> $$
> \begin{alignedat}{3}
>                    \mathrm{Exp} [X \mid Y_1, \cdots, Y_n] &= \sum_x x \cdot p_X (x \mid y_1, \cdots, y_n) \\
>                                                           &= \sum_x \dfrac{x \cdot p (x, y_1, \cdots, y_n)}{p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n)} \\
> \mathrm{Exp} [f (X_1, \cdots, X_m) \mid Y_1, \cdots, Y_n] &= \sum_{(x_1, \cdots, x_m)} f (x_1, \cdots, x_m) \cdot p_{X_1, \cdots, X_m} (x_1, \cdots, x_m \mid y_1, \cdots, y_n) \\
>                                                           &= \sum_{x_1} \cdots \sum_{x_m} \dfrac{f (x_1, \cdots, x_m) \cdot p (x_1, \cdots, x_m, y_1, \cdots, y_n)}{p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n)} \\
> \end{alignedat}
> $$
>

> ### 条件离散再期望

> $$
> \begin{alignedat}{3}
>                    \mathrm{Exp} [\mathrm{Exp} [X \mid Y_1, \cdots, Y_n]] &= \sum_{(y_1, \cdots, y_n)} \mathrm{Exp} [X \mid Y_1 = y_1, \cdots, Y_n = y_n] \cdot p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n) \\
>                                                                          &= \sum_{(y_1, \cdots, y_n)} \sum_x x \cdot p (x, y_1, \cdots, y_n) \\
>                                                                          &= \sum_x x \cdot \sum_{(y_1, \cdots, y_n)} p (x, y_1, \cdots, y_n) \\
>                                                                          &= \sum_x x \cdot p_X (x) \\
>                                                                          &= \mathrm{Exp} [X] \\
> \mathrm{Exp} [\mathrm{Exp} [f (X_1, \cdots, X_m) \mid Y_1, \cdots, Y_n]] &= \sum_{(y_1, \cdots, y_n)} \mathrm{Exp} [f (X_1, \cdots, X_m) \mid Y_1 = y_1, \cdots, Y_n = y_n] \cdot p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n) \\
>                                                                          &= \sum_{(y_1, \cdots, y_n)} \sum_{(x_1, \cdots, x_m)} f (x_1, \cdots, x_m) \cdot p (x_1, \cdots, x_m, y_1, \cdots, y_n) \\
>                                                                          &= \sum_{(x_1, \cdots, x_m)} f (x_1, \cdots, x_m) \cdot \sum_{y_1, \cdots, y_n} p (x_1, \cdots, x_m, y_1, \cdots, y_n) \\
>                                                                          &= \sum_{x_1} \cdots \sum_{x_m} f (x_1, \cdots, x_m) \cdot p_{X_1, \cdots, X_m} (x_1, \cdots, x_m) \\
>                                                                          &= \mathrm{Exp} [f (X_1, \cdots, X_m)] \\
> \end{alignedat}
> $$
>

> ### 条件连续期望

> $$
> \begin{alignedat}{3}
>                    \mathrm{Exp} [X \mid Y_1, \cdots, Y_n] &= \int_x x \cdot p_X (x \mid y_1, \cdots, y_n) \mathrm{d} x \\
>                                                           &= \int_x \dfrac{x \cdot p (x, y_1, \cdots, y_n)}{p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n)} \mathrm{d} x \\
> \mathrm{Exp} [f (X_1, \cdots, X_m) \mid Y_1, \cdots, Y_n] &= \int_{(x_1, \cdots, x_m)} f (x_1, \cdots, x_m) \cdot p_{X_1, \cdots, X_m} (x_1, \cdots, x_m \mid y_1, \cdots, y_n) \mathrm{d} (x_1, \cdots, x_m) \\
>                                                           &= \int_{x_1} \cdots \int_{x_m} \dfrac{f (x_1, \cdots, x_m) \cdot p (x_1, \cdots, x_n, y_1, \cdots, y_n)}{p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n)} \mathrm{d} x_1 \cdots \mathrm{d} x_m \\
> \end{alignedat}
> $$
>

> ### 条件连续再期望

> $$
> \begin{alignedat}{3}
>                    \mathrm{Exp} [\mathrm{Exp} [X \mid Y_1, \cdots, Y_n]] &= \int_{(y_1, \cdots, y_n)} \mathrm{Exp} [X \mid Y_1 = y_1, \cdots, Y_n = y_n] \cdot p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n) \mathrm{d} (y_1, \cdots, y_n) \\
>                                                                          &= \int_{(y_1, \cdots, y_n)} \int_x x \cdot p (x, y_1, \cdots, y_n) \mathrm{d} x \mathrm{d} (y_1, \cdots, y_n) \\
>                                                                          &= \int_x x \cdot \int_{(y_1, \cdots, y_n)} p (x, y_1, \cdots, y_n) \mathrm{d} (y_1, \cdots, y_n) \mathrm{d} x \\
>                                                                          &= \int_x x \cdot p_X (x) \mathrm{d} x \\
>                                                                          &= \mathrm{Exp} [X] \\
> \mathrm{Exp} [\mathrm{Exp} [f (X_1, \cdots, X_m) \mid Y_1, \cdots, Y_n]] &= \int_{(y_1, \cdots, y_n)} \mathrm{Exp} [f (X_1, \cdots, X_m) \mid Y_1 = y_1, \cdots, Y_n = y_n] \cdot p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n) \mathrm{d} (y_1, \cdots, y_n) \\
>                                                                          &= \int_{(y_1, \cdots, y_n)} \int_{(x_1, \cdots, x_m)} f (x_1, \cdots, x_m) \cdot p (x_1, \cdots, x_m, y_1, \cdots, y_n) \mathrm{d} (x_1, \cdots, x_m) \mathrm{d} (y_1, \cdots, y_n) \\
>                                                                          &= \int_{(x_1, \cdots, x_m)} f (x_1, \cdots, x_m) \cdot \int_{(y_1, \cdots, y_n)} p (x_1, \cdots, x_m, y_1, \cdots, y_n) \mathrm{d} (y_1, \cdots, y_n) \mathrm{d} (x_1, \cdots, x_m) \\
>                                                                          &= \int_{x_1} \cdots \int_{x_m} f (x_1, \cdots, x_m) \cdot p_{X_1, \cdots, X_m} (x_1, \cdots, x_m) \mathrm{d} x_1 \cdots \mathrm{d} x_m \\
>                                                                          &= \mathrm{Exp} [f (X_1, \cdots, X_m)] \\
> \end{alignedat}
> $$
>

> ### 同分布随机变量之和的期望

> $$
> \begin{alignedat}{3}
> \mathrm{Exp} \left[ \sum_{i = 1}^N X_i \right] &= \mathrm{Exp} \left[ \mathrm{Exp} \left[ \sum_{i = 1}^N X_i \middle| N \right] \right] \\
>                                                &= \sum_{n = 1}^{+\infty} \mathrm{Exp} \left[ \sum_{i = 1}^n X_i \middle| N = n \right] \cdot p_N (n) \\
>                                                &= \sum_{i = 1}^{+\infty} n \cdot \mathrm{Exp} [X \mid N = n] \cdot p_N (n) \\
>                                                &= \mathrm{Exp} [X] \cdot \sum_{i = 1}^{+\infty} n \cdot p_N (n) \\
>                                                &= \mathrm{Exp} [X] \cdot \mathrm{Exp} [N] \\
> \end{alignedat}
> $$
>

> ### 条件方差

> $$
> \begin{alignedat}{3}
> \mathrm{CoV} [X, Y \mid Z] &= \mathrm{Exp} [(X - \mathrm{Exp} [X \mid Z]) \cdot (Y - \mathrm{Exp} [Y \mid Z]) \mid Z] \\
>                            &= \mathrm{Exp} [X Y \mid Z] - \mathrm{Exp} [X \mid Z] \cdot \mathrm{Exp} [Y \mid Z] \\
>    \mathrm{Var} [X \mid Z] &= \mathrm{CoV} [X, X \mid Z] \\
>                            &= \mathrm{Exp} [X \mid Z]^2 - \mathrm{Exp}^2 [X \mid Z] \\
> \end{alignedat}
> $$
>

> ### 方差与条件方差

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\quad &&                                                                   \mathrm{Exp} [\mathrm{CoV} [X, Y \mid Z]] &= \mathrm{Exp} [\mathrm{Exp} [X Y \mid Z]] - \mathrm{Exp} [\mathrm{Exp} [X \mid Z] \cdot \mathrm{Exp} [Y \mid Z]] \\
> \fbox{2}\Uparrow\quad &&                                             \mathrm{CoV} [\mathrm{Exp} [X \mid Z], \mathrm{Exp} [Y \mid Z]] &= \mathrm{Exp} [\mathrm{Exp} [X \mid Z] \cdot \mathrm{Exp} [Y \mid Z]] - \mathrm{Exp} [\mathrm{Exp} [X \mid Z]] \cdot \mathrm{Exp} [\mathrm{Exp} [Y \mid Z]] \\
> \Downarrow\quad       && \mathrm{Exp} [\mathrm{CoV} [X, Y \mid Z]] + \mathrm{CoV} [\mathrm{Exp} [X \mid Z], \mathrm{Exp} [Y \mid Z]] &= \mathrm{Exp} [\mathrm{Exp} [X Y \mid Z]] - \mathrm{Exp} [\mathrm{Exp} [X \mid Z]] \cdot \mathrm{Exp} [\mathrm{Exp} [Y \mid Z]] \\
>                       &&                                                                                                             &= \mathrm{Exp} [X Y] - \mathrm{Exp} [X] \cdot \mathrm{Exp} [Y] \\
>                       &&                                                                                                             &= \mathrm{CoV} [X, Y] \\
> \Downarrow\quad       &&                                                                                            \mathrm{Var} [X] &= \mathrm{Exp} [\mathrm{Var} [X \mid Z]] + \mathrm{Var} [\mathrm{Exp} [X \mid Z]] \\
> \end{alignedat}
> $$
>

> ### 独立同分布随机变量之和的方差

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\quad && \mathrm{Exp} \left[ \sum_{i = 1}^N X_i \middle| N \right] &= N \cdot \mathrm{Exp} [X] \\
> \fbox{2}\Uparrow\quad && \mathrm{Var} \left[ \sum_{i = 1}^N X_i \middle| N \right] &= N \cdot \mathrm{Var} [X] \quad\Leftarrow\quad p (x_1, \cdots, x_N) = p_{X_1} (x_1) \cdots p_{X_N} (x_N) \\
> \Downarrow\quad       &&            \mathrm{Var} \left[ \sum_{i = 1}^N X_i \right] &= \mathrm{Exp} \left[ \mathrm{Var} \left[ \sum_{i = 1}^N X_i \middle| N \right] \right] + \mathrm{Var} \left[ \mathrm{Exp} \left[ \sum_{i = 1}^N X_i \middle| N \right] \right] \\
>                       &&                                                           &= \mathrm{Var} [X] \cdot \mathrm{Exp} [N] + \mathrm{Exp}^2 [X] \cdot \mathrm{Var} [N] \\
> \end{alignedat}
> $$
>

> ### 均方误差与条件期望

> $$
> \begin{alignedat}{3}
> \Uparrow\quad && \mathrm{Exp} [Y - f (X) \mid X]^2 &= \mathrm{Exp} [Y - \mathrm{Exp} [Y \mid X] + \mathrm{Exp} [Y \mid X] - f (X) \mid X]^2 \\
> && &= \mathrm{Exp} [Y - \mathrm{Exp} [Y \mid X] \mid X]^2 + \mathrm{Exp} [\mathrm{Exp} [Y \mid X] - f (X) \mid X]^2 + 2 \mathrm{Exp} [Y - \mathrm{Exp} [Y \mid X] \mid X] \cdot \mathrm{Exp} [\mathrm{Exp} [Y \mid X] - f (X) \mid X] \\
> && &= \mathrm{Exp} [Y - \mathrm{Exp} [Y \mid X] \mid X]^2 + \mathrm{Exp} [\mathrm{Exp} [Y \mid X] - f (X) \mid X]^2 + 0 \\
> && &\ge \mathrm{Exp} [Y - \mathrm{Exp} [Y \mid X] \mid X]^2 \\
> \Downarrow\quad && \mathrm{Exp} [Y - f (X)]^2 &= \mathrm{Exp} [\mathrm{Exp} [Y - f (X) \mid X]^2] \\
> && &\ge \mathrm{Exp} [\mathrm{Exp} [Y - \mathrm{Exp} [Y \mid X] \mid X]^2] \\
> \end{alignedat}
> $$
>