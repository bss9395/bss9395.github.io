---
layout:    zh_post
Topic:     概率统计
Title:     概率分布
Revised:   2018-06-11 21:48:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 随机向量

> $$
> \mathbf{X} = \begin{bmatrix}
>              X_1 \\
>              \vdots \\
>              X_n \\
>              \end{bmatrix} \\
> $$
>

> ### 随机向量的线性变换

> $$
> \begin{alignedat}{3}
> \mathbf{Y} &= \mathbf{L} \, \mathbf{X} \\
> \mathbf{Y}^\mathrm{T} &= \mathbf{X}^\mathrm{T} \, \mathbf{L}^\mathrm{T} \\
> \begin{bmatrix}
> Y_1 \\
> \vdots \\
> Y_n \\
> \end{bmatrix} &= \begin{bmatrix}
>                  l_{1 1} & \cdots & l_{1 n} \\
>                  \vdots  &        & \vdots \\
>                  l_{n 1} & \cdots & l_{n n} \\
>                  \end{bmatrix} \begin{bmatrix}
>                                X_1 \\
>                                \vdots \\
>                                X_n
>                                \end{bmatrix} &&= \begin{bmatrix}
>                                                  \sum\limits_{i = 1}^n l_{1 i} \cdot X_i \\
>                                                  \vdots \\
>                                                  \sum\limits_{i = 1}^n l_{n i} \cdot X_i
>                                                  \end{bmatrix} \\
> \begin{bmatrix} 
> Y_1 & \cdots & Y_n
> \end{bmatrix} &= \begin{bmatrix}
>                  X_1 & \cdots & X_n
>                  \end{bmatrix} \begin{bmatrix}
>                                l_{1 1} & \cdots & l_{n 1} \\
>                                \vdots  &        & \vdots \\
>                                l_{1 n} & \cdots & l_{n n} \\
>                                \end{bmatrix} &&= \begin{bmatrix}
>                                                  \sum\limits_{i = 1}^n l_{1 i} \cdot X_i & \cdots & \sum\limits_{i = 1}^n l_{n i} \cdot X_i \\
>                                                  \end{bmatrix} \\
> \end{alignedat}
> $$
>

> ### 随机向量的均值

> $$
> \begin{alignedat}{3}
> \mathrm{Exp} [\mathbf{Y}] &= \mathbf{L} \, (\mathrm{Exp} [\mathbf{X}]) \\
> \mathrm{Exp} [\mathbf{Y}^\mathrm{T}] &= (\mathrm{Exp} [\mathbf{X}^\mathrm{T}]) \, \mathbf{L}^\mathrm{T} \\
> \begin{bmatrix}
> \mathrm{Exp} [Y_1] \\
> \vdots \\
> \mathrm{Exp} [Y_n]
> \end{bmatrix} &= \begin{bmatrix}
>                  \mathrm{Exp} \left[ \sum\limits_{i = 1}^n l_{1 i} \cdot X_i \right] \\
>                  \vdots \\
>                  \mathrm{Exp} \left[ \sum\limits_{i = 1}^n l_{n i} \cdot X_i \right] \\
>                  \end{bmatrix} &&= \begin{bmatrix}
>                                    l_{1 1} & \cdots & l_{1 n} \\
>                                    \vdots  &        & \vdots \\
>                                    l_{n 1} & \cdots & l_{n n} \\
>                                    \end{bmatrix} \begin{bmatrix}
>                                                  \mathrm{Exp} [X_1] \\
>                                                  \vdots \\
>                                                  \mathrm{Exp} [X_n] \\
>                                                  \end{bmatrix} \\
> \begin{bmatrix}
> \mathrm{Exp} [Y_1] & \cdots & \mathrm{Exp} [Y_n] \\
> \end{bmatrix} &= \begin{bmatrix}
>                  \mathrm{Exp} \left[ \sum\limits_{i = 1}^n l_{1 i} \cdot X_i \right] & \cdots & \mathrm{Exp} \left[ \sum\limits_{i = 1}^n l_{n i} \cdot X_i \right] \\
>                  \end{bmatrix} &&= \begin{bmatrix}
>                                    \mathrm{Exp} [X_1] & \cdots & \mathrm{Exp} [X_n] \\
>                                    \end{bmatrix} \begin{bmatrix} 
>                                                  l_{1 1} & \cdots & l_{n 1} \\
>                                                  \vdots  &        & \vdots \\
>                                                  l_{1 n} & \cdots & l_{n n} \\
>                                                  \end{bmatrix} \\
> \end{alignedat}
> $$
>

> ### 随机向量的方差

> $$
> \begin{alignedat}{3}
> \mathrm{Var} [\mathbf{X}] &= \mathrm{Exp} [(\mathbf{X} - \mathrm{Exp} [\mathbf{X}]) (\mathbf{X} - \mathrm{Exp} [\mathbf{X}])^\mathrm{T}] \\
>                           &= \mathrm{Exp} \begin{bmatrix}
>                                           (X_1 - \mathrm{Exp} [X_1]) (X_1 - \mathrm{Exp} [X_1]) & \cdots & (X_1 - \mathrm{Exp} [X_1]) (X_n - \mathrm{Exp} [X_n]) \\
>                                           \vdots                                                &        & \vdots \\
>                                           (X_n - \mathrm{Exp} [X_n]) (X_1 - \mathrm{Exp} [X_1]) & \cdots & (X_n - \mathrm{Exp} [X_n]) (X_n - \mathrm{Exp} [X_n])
>                                           \end{bmatrix} \\
>                           &= \begin{bmatrix}
>                              \mathrm{Var} [X_1]      & \cdots & \mathrm{CoV} [X_1, X_n] \\
>                              \vdots                  &        & \vdots \\
>                              \mathrm{CoV} [X_n, X_1] & \cdots & \mathrm{Var} [X_n] \\
>                              \end{bmatrix} \\
> \mathrm{Var} [\mathbf{Y}] &= \mathrm{Exp} [(\mathbf{Y} - \mathrm{Exp} [\mathbf{Y}]) (\mathbf{Y} - \mathrm{Exp} [\mathbf{Y}])^\mathrm{T}] \\
>                           &= \mathrm{Exp} [\mathbf{L} \, (\mathbf{X} - \mathrm{Exp} [\mathbf{X}]) (\mathbf{X} - \mathrm{Exp} [\mathbf{X}])^\mathrm{T} \, \mathbf{L}^\mathrm{T}] \\
>                           &= \mathbf{L} \, (\mathrm{Exp} [(\mathbf{X} - \mathrm{Exp} [\mathbf{X}]) (\mathbf{X} - \mathrm{Exp} [\mathbf{X}])^\mathrm{T}]) \, \mathbf{L}^\mathrm{T} \\
>                           &= \mathbf{L} \, (\mathrm{Var} [\mathbf{X}]) \, \mathbf{L}^\mathrm{T} \\
> \end{alignedat}
> $$
>

