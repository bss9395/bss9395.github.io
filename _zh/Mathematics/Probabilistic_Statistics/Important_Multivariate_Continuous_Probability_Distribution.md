---
layout:    zh_post
Topic:     概率统计
Title:     重要多变量连续概率分布
Revised:   2018-05-15 01:35:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 多维均匀分布 $(X_1, \cdots, X_m) \mapsto \mathrm{M_{ultivariate} U_{niform}} (D)$

> $$
> \begin{alignedat}{3}
> p (x_1, \cdots, x_m) &= \dfrac{1}{S_{ize} (D)} \quad\Leftarrow\quad (x_1, \cdots, x_m) \in D \\
> \end{alignedat}
> $$
>

> ### 多维正态分布 $(X_1, \cdots, X_m) \mapsto \mathrm{M_{ultivariate} N_{ormal}}$

> $$
> \begin{alignedat}{3}
> 
> \end{alignedat}
> $$
>

> ### 二维正态分布 $(X, Y) \mapsto \mathrm{B_{ivariate} N_{ormal}} (\mu_X, \mu_Y, \sigma_X^2, \sigma_Y^2, \rho)$

> $$
> \begin{alignedat}{3}
> p (x, y) &= \dfrac{1}{2 \pi \sigma_X \sigma_Y \sqrt{1 - \rho^2}} e^{- \frac{1}{2 (1 - \rho^2)} \left[ \frac{(x - \mu_X)^2}{\sigma_X^2} - 2 \rho \frac{(x - \mu_X) (y - \mu_Y)}{\sigma_X \sigma_Y} + \frac{(y - \mu_Y)^2}{\sigma_Y^2} \right]} \quad\Leftarrow\quad x, y \in (-\infty, +\infty) \\
>        P &= \dfrac{1}{2 \pi \sigma_X \sigma_Y \sqrt{1 - \rho^2}} \iint_D e^{- \frac{1}{2 (1 - \rho^2)} \left[ \frac{(x - \mu_X)^2}{\sigma_X^2} - 2 \rho \frac{(x - \mu_X) (y - \mu_Y)}{\sigma_X \sigma_Y} + \frac{(y - \mu_Y)^2}{\sigma_Y^2} \right]} \mathrm{d} x \mathrm{d} y \\
>          &\xlongequal[v = \frac{y - \mu_Y}{\sigma_Y} \sqrt{1 - \rho^2}]{u = \frac{x - \mu_X}{\sigma_X} - \rho \frac{y - \mu_Y}{\sigma_Y}} \dfrac{1}{2 \pi (1 - \rho^2)} \iint_D e^{- \frac{u^2 + v^2}{2 (1 - \rho^2)}} \mathrm{d} u \mathrm{d} v \quad\Leftarrow\quad \dfrac{\partial (u, v)}{\partial (x, y)} = \dfrac{\sqrt{1 - \rho^2}}{\sigma_X \sigma_Y} \\
> \end{alignedat}
> $$
>

