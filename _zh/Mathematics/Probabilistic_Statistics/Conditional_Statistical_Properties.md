---
layout:    zh_post
Topic:     概率统计
Title:     条件统计特性
Revised:   2018-05-23 21:45:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 条件离散期望

> $$
> \begin{alignedat}{3}
>                    \mathrm{Exp} [X \mid Y_1 = y_1, \cdots, Y_n = y_n] &= \sum_x x \cdot p_X (x \mid y_1, \cdots, y_n) \\
>                                                                       &= \sum_x \dfrac{x \cdot p (x, y_1, \cdots, y_n)}{p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n)} \\
> \mathrm{Exp} [f (X_1, \cdots, X_m) \mid Y_1 = y_1, \cdots, Y_n = y_n] &= \sum_{(x_1, \cdots, x_m)} f (x_1, \cdots, x_m) \cdot p_{X_1, \cdots, X_m} (x_1, \cdots, x_m \mid y_1, \cdots, y_n) \\
>                                                                       &= \sum_{x_1} \cdots \sum_{x_m} \dfrac{f (x_1, \cdots, x_m) \cdot p (x_1, \cdots, x_m, y_1, \cdots, y_n)}{p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n)} \\
> \end{alignedat}
> $$
>

> ### 条件离散再期望

> $$
> \begin{alignedat}{3}
>                  \mathrm{Exp} [\mathrm{Exp} [X \mid Y_1, \cdots, Y_n]] &= \sum_{(y_1, \cdots, y_n)} \mathrm{Exp} [X \mid Y_1 = y_1, \cdots, Y_n = y_n] \cdot p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n) \\
>                                                                        &= \sum_{(y_1, \cdots, y_n)} \sum_x x \cdot p (x, y_1, \cdots, y_n) \\
>                                                                        &= \sum_x x \cdot \sum_{(y_1, \cdots, y_n)} p (x, y_1, \cdots, y_n) \\
>                                                                        &= \sum_x x \cdot p_X (x) \\
> \mathrm{Exp} [\mathrm{Exp} f (X_1, \cdots, X_m) \mid Y_1, \cdots, Y_n] &= \sum_{(y_1, \cdots, y_n)} \mathrm{Exp} [f (X_1, \cdots, X_m) \mid Y_1 = y_1, \cdots, Y_n = y_n] \cdot p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n) \\
>                                                                        &= \sum_{(y_1, \cdots, y_n)} \sum_{(x_1, \cdots, x_m)} f (x_1, \cdots, x_m) \cdot p (x_1, \cdots, x_m, y_1, \cdots, y_n) \\
>                                                                        &= \sum_{(x_1, \cdots, x_m)} f (x_1, \cdots, x_m) \cdot \sum_{y_1, \cdots, y_n} p (x_1, \cdots, x_m, y_1, \cdots, y_n) \\
>                                                                        &= \sum_{x_1} \cdots \sum_{x_m} f (x_1, \cdots, x_m) \cdot p_{X_1, \cdots, X_m} (x_1, \cdots, x_m) \\
> \end{alignedat}
> $$
>

> ### 条件连续期望

> $$
> \begin{alignedat}{3}
>                    \mathrm{Exp} [X \mid Y_1 = y_1, \cdots, Y_n = y_n] &= \int_x x \cdot p_X (x \mid y_1, \cdots, y_n) \mathrm{d} x \\
>                                                                       &= \int_x \dfrac{x \cdot p (x, y_1, \cdots, y_n)}{p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n)} \mathrm{d} x \\
> \mathrm{Exp} [f (X_1, \cdots, X_m) \mid Y_1 = y_1, \cdots, Y_n = y_n] &= \int_{(x_1, \cdots, x_m)} f (x_1, \cdots, x_m) \cdot p_{X_1, \cdots, X_m} (x_1, \cdots, x_m \mid y_1, \cdots, y_n) \mathrm{d} (x_1, \cdots, x_m) \\
>                                                                       &= \int_{x_1} \cdots \int_{x_m} \dfrac{f (x_1, \cdots, x_m) \cdot p (x_1, \cdots, x_n, y_1, \cdots, y_n)}{p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n)} \mathrm{d} x_1 \cdots \mathrm{d} x_m \\
> \end{alignedat}
> $$
>

> ### 条件连续再期望

> $$
> \begin{alignedat}{3}
> \mathrm{Exp} [\mathrm{Exp} [X \mid Y_1, \cdots, Y_n]] &= \int_{(y_1, \cdots, y_n)} \mathrm{Exp} [X | Y_1 = y_1, \cdots, Y_n = y_n] \cdot p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n) \mathrm{d} (y_1, \cdots, y_n) \\
> &= \int_{(y_1, \cdots, y_n)} \int_x x \cdot p (x, y_1, \cdots, y_n) \mathrm{d} x \mathrm{d} (y_1, \cdots, y_n) \\
> &= \int_x x \cdot \int_{(y_1, \cdots, y_n)} p (x, y_1, \cdots, y_n) \mathrm{d} (y_1, \cdots, y_n) \mathrm{d} x \\
> &= \int_x x \cdot p_X (x) \mathrm{d} x \\
> \mathrm{Exp} [\mathrm{Exp} [f (X_1, \cdots, X_m) \mid Y_1, \cdots, Y_n]] &= \int_{(y_1, \cdots, y_n)} \mathrm{Exp} [f (X_1, \cdots, X_m) \mid Y_1 = y_1, \cdots, Y_n = y_n] \cdot p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n) \mathrm{d} (y_1, \cdots, y_n) \\
> &= \int_{(y_1, \cdots, y_n)} \int_{(x_1, \cdots, x_m)} f (x_1, \cdots, x_m) \cdot p (x_1, \cdots, x_m, y_1, \cdots, y_n) \mathrm{d} (x_1, \cdots, x_m) \mathrm{d} (y_1, \cdots, y_n) \\
> &= \int_{(x_1, \cdots, x_m)} f (x_1, \cdots, x_m) \cdot \int_{(y_1, \cdots, y_n)} p (x_1, \cdots, x_m, y_1, \cdots, y_n) \mathrm{d} (y_1, \cdots, y_n) \mathrm{d} (x_1, \cdots, x_m) \\
> &= \int_{x_1} \cdots \int_{x_m} f (x_1, \cdots, x_m) \cdot p_{X_1, \cdots, X_m} (x_1, \cdots, x_m) \mathrm{d} x_1 \mathrm{d} x_m
> \end{alignedat}
> $$
>