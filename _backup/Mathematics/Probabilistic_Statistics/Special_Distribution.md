---
layout:    zh_post
Topic:     概率统计
Title:     特殊分布
Revised:   2018-06-12 17:34:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 正态分布与 $\Chi^2$ 分布

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           &&                                                          X &\mapsto \mathrm{No} (\mu, \sigma^2) \\
> \Uparrow\quad           &&                                                 \mathbf{Y} &= \mathbf{L} \, \mathbf{X} \quad\Leftarrow\quad \det \mathbf{L} = 1 = \mathbf{L} \, \mathbf{L}^\mathrm{T} = \mathbf{L}^\mathrm{T} \, \mathbf{L} \\
> \Downarrow\quad         && \sum_{i = 1}^n Y_i^2 = \mathbf{Y}^\mathrm{T} \, \mathbf{Y} &= \mathbf{X}^\mathrm{T} \, \mathbf{L}^\mathrm{T} \, \mathbf{L} \, \mathbf{X} = \sum_{i = 1}^n X_i^2 \\
> \Downarrow\quad         && \begin{bmatrix}
>                            Y_1 = \sqrt{n} \overline{X} \\
>                            Y_2 \\
>                            \vdots \\
>                            Y_n \\
>                            \end{bmatrix} &= \begin{bmatrix}
>                                             \dfrac{1}{\sqrt{n}}           & \dfrac{1}{\sqrt{n}}           & \dfrac{1}{\sqrt{n}}           & \cdots & \dfrac{1}{\sqrt{n}} \\
>                                             - \dfrac{1}{\sqrt{2 \cdot 1}} & \dfrac{1}{\sqrt{2 \cdot 1}}   & 0                             & \cdots & 0 \\
>                                             - \dfrac{1}{\sqrt{3 \cdot 2}} & - \dfrac{1}{\sqrt{3 \cdot 2}} & \dfrac{2}{\sqrt{3 \cdot 2}}   & \cdots & 0 \\
>                                             \vdots                        & \vdots                        & \vdots                        & \ddots & \vdots \\
>                                             - \dfrac{1}{\sqrt{n (n - 1)}} & - \dfrac{1}{\sqrt{n (n - 1)}} & - \dfrac{1}{\sqrt{n (n - 1)}} & \cdots & \dfrac{n - 1}{\sqrt{n (n - 1)}} \\
>                                             \end{bmatrix} \begin{bmatrix}
>                                                           X_1 \\
>                                                           \vdots \\
>                                                           X_n \\
>                                                           \end{bmatrix} \\
> \Downarrow\quad         && \begin{bmatrix}
>                            \mathrm{Exp} [Y_1] \\
>                            \mathrm{Exp} [Y_2] \\
>                            \vdots \\
>                            \mathrm{Exp} [Y_n] \\
>                            \end{bmatrix} &= \mathbf{L} \, \begin{bmatrix} 
>                                                           \mathrm{Exp} [X_1] \\
>                                                           \vdots \\
>                                                           \mathrm{Exp} [X_n] \\
>                                                           \end{bmatrix} = \begin{bmatrix}
>                                                                           \sqrt{n} \mu \\
>                                                                           0 \\
>                                                                           \vdots \\
>                                                                           0 \\
>                                                                           \end{bmatrix} \\
> \Downarrow\quad         && \begin{bmatrix}
>                            \mathrm{Var} [Y_1]      & \cdots & \mathrm{CoV} [Y_1, Y_n] \\
>                            \vdots                  & \ddots & \vdots \\
>                            \mathrm{CoV} [Y_n, Y_1] & \cdots &\mathrm{Var} [Y_n] \\
>                            \end{bmatrix} &= \mathbf{L} \, \begin{bmatrix}
>                                                           \mathrm{Var} [X_1]      & \cdots & \mathrm{CoV} [X_1, X_n] \\
>                                                           \vdots                  & \ddots & \vdots \\
>                                                           \mathrm{Cov} [X_n, X_1] & \cdots &  \mathrm{Var} [X_n] \\
>                                                           \end{bmatrix} \mathbf{L}^\mathrm{T} = \begin{bmatrix}
>                                                                                                 \sigma^2 & \cdots & 0 \\
>                                                                                                 \vdots   & \ddots & \vdots \\
>                                                                                                 0        & \cdots & \sigma^2 \\
>                                                                                                 \end{bmatrix} \\
> \end{alignedat}
> $$
>

> $$
> \begin{alignedat}{3}
> \Downarrow\quad         &&                                                                                              Y_1 &\mapsto \mathrm{No} (\sqrt{n} \mu, \sigma^2) \\
> \Downarrow\quad         &&                                                                                 Y_2, \cdots, Y_n &\mapsto \mathrm{No} (0, \sigma^2) \\
> \Uparrow\quad           &&                                                                            \sqrt{n} \overline{X} &= Y_1 \\
> \Uparrow\quad           &&                                                            \sum_{i = 1}^n (X_i - \overline{X})^2 &= \sum_{i = 1}^n X_i^2 - n \cdot \overline{X} \\
>                         &&                                                                                                  &= \sum_{i = 1}^n Y_i^2 - Y_1^2 \\
>                         &&                                                                                                  &= \sum_{i = 2}^n Y_i^2 \\
> \fbox{1}\Downarrow\quad &&                                                             \overline{X} = \dfrac{Y_1}{\sqrt{n}} &\mapsto \mathrm{No} \left( \mu, \dfrac{\sigma^2}{n} \right) \\
> \fbox{2}\Downarrow\quad && \sum_{i = 1}^n \dfrac{(X_i - \overline{X})^2}{\sigma^2} = \sum_{i = 2}^n \dfrac{Y_i^2}{\sigma^2} &\mapsto \mathrm{Ch} (n - 1) \\
> \end{alignedat}
> $$
>

> ### 正态分布与 $\Xi$ 分布

> $$
> \begin{alignedat}{3}
>                                                                                                                 X &\mapsto \mathrm{No} (\mu_X, \sigma_X^2) \\
>                                                                                                                 Y &\mapsto \mathrm{No} (\mu_Y, \sigma_Y^2) \\
>                                                         \sum_{i = 1}^n \dfrac{(X_i - \overline{X})^2}{\sigma_X^2} &\mapsto \mathrm{Ch} (n - 1) \\
>                                                         \sum_{i = 1}^m \dfrac{(Y_i - \overline{Y})^2}{\sigma_Y^2} &\mapsto \mathrm{Ch} (m - 1) \\
> \dfrac{m \sigma_Y^2}{n \sigma_X^2} \cdot \dfrac{\sum_1^n (X_i - \overline{X})^2}{\sum_1^m (Y_i - \overline{Y})^2} &\mapsto \mathrm{Xi} (n - 1, m - 1) \\
> \end{alignedat}
> $$
>

> ### 正态分布与 $\Delta$ 分布

> $$
> \begin{alignedat}{3}
>                                                                   X &\mapsto \mathrm{No} (\mu, \sigma^2) \\
>                                                        \overline{X} &\mapsto \mathrm{No} \left( \mu, \dfrac{\sigma^2}{n} \right) \\
>                       \dfrac{\sqrt{n} (\overline{X} - \mu)}{\sigma} &\mapsto \mathrm{No} (0, 1^2) \\
>             \sum_{i = 1}^n \dfrac{(X_i - \overline{X})^2}{\sigma^2} &\mapsto \mathrm{Ch} (n - 1) \\
> \dfrac{n \cdot\overline{X}}{\sqrt{\sum_1^n (X_i - \overline{X})^2}} &\mapsto \mathrm{De} (n - 1) \\
> \end{alignedat}
> $$
>