---
layout:    zh_post
Topic:     概率统计
Title:     正态分布
Revised:   2018-06-10 22:58:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 正态分布与 $\Chi^2$ 分布

> $$
> \begin{alignedat}{3}
>                                                                                                X &\mapsto \mathrm{No} (\mu, \sigma^2) \\
>                                                                                       \mathbf{Y} &= \mathbf{L} \, \mathbf{X} \quad\Leftarrow\quad \det \mathbf{L} = 1 = \mathbf{L} \, \mathbf{L}^\mathrm{T} = \mathbf{L}^\mathrm{T} \, \mathbf{L} \\
>                                       \sum_{i = 1}^n Y_i^2 = \mathbf{Y}^\mathrm{T} \, \mathbf{Y} &= \mathbf{X}^\mathrm{T} \, \mathbf{L}^\mathrm{T} \, \mathbf{L} \, \mathbf{X} = \sum_{i = 1}^n X_i^2 \\
>                                                                                    \begin{bmatrix}
>                                                                                    Y_1 \\
>                                                                                    Y_2 \\
>                                                                                    \vdots \\
>                                                                                    Y_n \\
>                                                                                    \end{bmatrix} &= \begin{bmatrix}
>                                                                                                     \dfrac{1}{\sqrt{n}}           & \dfrac{1}{\sqrt{n}}           & \dfrac{1}{\sqrt{n}}           & \cdots & \dfrac{1}{\sqrt{n}} \\
>                                                                                                     - \dfrac{1}{\sqrt{2 \cdot 1}} & \dfrac{1}{\sqrt{2 \cdot 1}}   & 0                             & \cdots & 0 \\
>                                                                                                     - \dfrac{1}{\sqrt{3 \cdot 2}} & - \dfrac{1}{\sqrt{3 \cdot 2}} & \dfrac{2}{\sqrt{3 \cdot 2}}   & \cdots & 0 \\
>                                                                                                     \vdots                        & \vdots                        & \vdots                        & \ddots & \vdots \\
>                                                                                                     - \dfrac{1}{\sqrt{n (n - 1)}} & - \dfrac{1}{\sqrt{n (n - 1)}} & - \dfrac{1}{\sqrt{n (n - 1)}} & \cdots & \dfrac{n - 1}{\sqrt{n (n - 1)}} \\
>                                                                                                     \end{bmatrix} \begin{bmatrix}
>                                                                                                                   X_1 \\
>                                                                                                                   \vdots \\
>                                                                                                                   X_n \\
>                                                                                                                   \end{bmatrix} \\
>                                                                            \sqrt{n} \overline{X} &= Y_1 \\
>                                                            \sum_{i = 1}^n (X_i - \overline{X})^2 &= \sum_{i = 1}^n X_i^2 - n \cdot \overline{X} \\
>                                                                                                  &= \sum_{i = 1}^n Y_i^2 - Y_1^2 \\
>                                                                                                  &= \sum_{i = 2}^n Y_i^2 \\
>                                                          p_{X_1, \cdots, X_n} (x_1, \cdots, x_n) &= \dfrac{1}{(\sqrt{2 \pi} \sigma)^n} e^{- \frac{1}{2 \sigma^2} \sum_1^n (x_n - \mu)^2} \\
>                                                                                                  &= \dfrac{1}{(\sqrt{2 \pi} \sigma)^n} e^{- \frac{1}{2 \sigma^2} [\sum_1^n x_n^2 - 2 n \overline{x} \mu + n \mu^2]} \\
>                                                          p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n) &= \dfrac{1}{(\sqrt{2 \pi} \sigma)^n} e^{- \frac{1}{2 \sigma^2} [\sum_1^n y_n^2 - 2 n y_1 \mu + n \mu^2]} \\
>                                                                                                  &= \dfrac{1}{(\sqrt{2 \pi} \sigma)^n} e^{- \frac{1}{2 \sigma^2} [\sum_2^n y_n^2 + (y_1 - \sqrt{n} \mu)^2]} \\
>                                                                                                  &= \dfrac{1}{\sqrt{2 \pi} \sigma} e^{- \frac{(y_1 - \sqrt{n} \mu)^2}{2 \sigma^2}} \cdot \prod_{i = 2}^n \dfrac{1}{\sqrt{2 \pi} \sigma} e^{- \frac{y_i^2}{2 \sigma^2}} \\
>                                                                                                  &= p_{Y_1} (y_1) \cdot p_{Y_2} (y_2) \cdots p_{Y_n} (y_n) \\
>                                                                                              Y_1 &\mapsto \mathrm{No} (\sqrt{n} \mu, \sigma^2) \\
>                                                                                 Y_2, \cdots, Y_n &\mapsto \mathrm{No} (0, \sigma^2) \\
>                                                             \overline{X} = \dfrac{Y_1}{\sqrt{n}} &\mapsto \mathrm{No} \left( \mu, \dfrac{\sigma^2}{n} \right) \\
> \sum_{i = 1}^n \dfrac{(X_i - \overline{X})^2}{\sigma^2} = \sum_{i = 2}^n \dfrac{Y_i^2}{\sigma^2} &\mapsto \mathrm{Ch} (n - 1) \\
> \end{alignedat}
> $$
>

