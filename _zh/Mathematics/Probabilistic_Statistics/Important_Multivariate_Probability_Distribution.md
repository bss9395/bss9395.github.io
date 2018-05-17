---
layout:    zh_post
Topic:     概率统计
Title:     重要多维概率分布
Revised:   2018-05-17 16:04:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 多项分布 $(X_1, \cdots, X_m) \mapsto \mathrm{M_{ulti} n_{omial}} (n, p_1, \cdots, p_m)$

> $$
> \begin{alignedat}{3}
> P (X_1 = k_1, \cdots, X_m = k_m) &= \dfrac{n !}{k_1 ! \cdots k_m !} p_1^{k_1} \cdots p_m^{k_m} \quad\Leftarrow\quad n = \sum_1^m k_m \\
>                    M_{X_1} (x_1) &= \sum_{k_2, \cdots, k_m} \dfrac{n !}{k_1 ! \cdots k_m !} p_1^{k_1} \cdots p_m^{k_m} \\
>                                  &= \dfrac{n !}{k_1 ! (n - k_1) !} p_1^{k_1} \sum_{k2, \cdots, k_m} \dfrac{(n - k_1) !}{k_2 ! \cdots k_m !} p_2^{k_2} \cdots p_m^{k_m} \\
>                                  &= \dfrac{n !}{k_1 ! (n - k_1) !} p_1^{k_1} (p_2 + \cdots + p_m)^{n - k_1} \\
>                                  &= \dfrac{n !}{k_1 ! (n - k_1) !} p_1^{k_1} (1 - p_1)^{n - k_1} \\
> \end{alignedat}
> $$
>

> ### 多维超几何分布 $(X_1, \cdots, X_m) \mapsto \mathrm{M_{ultivariate} H_{yper geometric}} (N_1, \cdots, N_m, n)$

> $$
> \begin{alignedat}{3}
> P (X_1 = k_1, \cdots, X_m = k_m) &= \dfrac{{N_1 \choose k_1} \cdots {N_m \choose k_m}}{{N_1 + \cdots + N_m \choose n}} \quad\Leftarrow\quad n = \sum_1^m k_m \\
> \end{alignedat}
> $$
>

> ### 多维均匀分布 $(X_1, \cdots, X_m) \mapsto \mathrm{M_{ultivariate} U_{niform}} (D)$

> $$
> \begin{alignedat}{3}
> p (x_1, \cdots, x_m) &= \dfrac{1}{S_{ize} (D)} \quad\Leftarrow\quad (x_1, \cdots, x_m) \in D \\
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

> ### 二维指数分布 $(X, Y) \mapsto \mathrm{B_{ivariate} E_{xponential}} (\lambda)$

> $$
> \begin{alignedat}{3}
> J (x, y) &= 1 - e^{- x} - e^{- y} + e^{- x - y - \lambda x y} \quad\Leftarrow\quad x, y \in (0, +\infty) \\
>  M_X (x) &= 1 - e^{- x} \quad\Leftarrow\quad x \in (0, +\infty) \\
>  M_Y (y) &= 1 - e^{- y} \quad\Leftarrow\quad y \in (0, +\infty) \\
> \end{alignedat}
> $$
>

> ### 独立最大值分布 $Y \mapsto \mathrm{Ma_x} (X_1, \cdots, X_m)$

> $$
> \begin{alignedat}{3}
> C (y) &= P (\max (X_1, \cdots, X_m) \le y) \\
>       &= P (X_1 \le y, \cdots, X_m \le y) \\
>       &= \prod_1^m C_{X_m} (y) \\
> \end{alignedat}
> $$
>

> ### 独立最小值分布 $Y \mapsto \mathrm{Mi_n} (X_1, \cdots, X_m)$

> $$
> \begin{alignedat}{3}
> C (y) &= P (\min (X_1, \cdots, X_m) \le y) \\
>       &= 1 - P (\min (X_1, \cdots, X_m) \gt y) \\
>       &= 1 - P (X_1 \gt y, \cdots, X_m \gt y) \\
>       &= 1 - \prod_1^m (1 - C_{X_m} (y)) \\
> \end{alignedat}
> $$
>

> ### 独立连续和分布 $Z = \mathrm{Ad_{dittion}} (X, Y)$

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   && C (z) &= P (X + Y \le z) \\
>                 &&       &= \iint\limits_{x + y \le z} p_X (x) \cdot p_Y (y) \mathrm{d} x \mathrm{d} y \\
>                 &&       &= \int_{-\infty}^{+\infty} \int_{-\infty}^{z - x} p_X (x) \cdot p_Y (y) \mathrm{d} y \mathrm{d} x \\
>                 &&       &\xlongequal{t = x + y} \int_{-\infty}^{+\infty} \int_{-\infty}^z p_X (x) \cdot p_Y (t - y) \mathrm{d} t \mathrm{d} x \\
>                 &&       &= \int_{-\infty}^z \int_{-\infty}^{+\infty} p_X (x) \cdot p_Y (t - y) \mathrm{d} x \mathrm{d} t \\
> \Downarrow\quad && p (z) &= \int_{-\infty}^{+\infty} p_X (x) \cdot p_Y (z - x) \mathrm{d} x \\
>                 &&       &\xlongequal{y = z - x} \int_{-\infty}^{+\infty} p_X (z - y) \cdot p_Y (y) \mathrm{d} x \\
> \end{alignedat}
> $$
>

> ### 独立连续积分布 $Z \mapsto \mathrm{Mu_{ltiplication}} (X, Y)$

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   &&            & \left\lbrace\begin{alignedat}{3}
>                                 z &= x y \\
>                                 t &= x \\
>                                 \end{alignedat}\right. \quad\Rightarrow\quad \left\lbrace\begin{alignedat}{3}
>                                                                              x &= t \\
>                                                                              y &= \dfrac{z}{t} \\
>                                                                              \end{alignedat}\right. \quad\Rightarrow\quad \dfrac{\partial (x, y)}{\partial (z, t)} = - \dfrac{1}{t} \\
> \Downarrow\quad && p_f (z, t) &= p (x, y) \cdot \left| \dfrac{\partial (x, y)}{\partial (z, t)} \right| \\
>                 &&            &= p_X (t) \cdot p_Y \left( \dfrac{z}{t} \right) \cdot \dfrac{1}{|t|} \\
> \Downarrow\quad &&    p_Z (z) &= \int_{-\infty}^{+\infty}p_X (t) \cdot p_Y \left( \dfrac{z}{t} \right) \cdot \dfrac{1}{|t|} \mathrm{d} t \\
>                 &&            &\xlongequal{s = \frac{z}{t}} \int_{-\infty}^{+\infty} p_X \left( \dfrac{z}{s} \right) \cdot p_Y (s) \cdot \dfrac{1}{|s|} \mathrm{d} s \\
> \end{alignedat}
> $$
>

> ### 独立连续商分布 $Z \mapsto \mathrm{Di_{vision}} (X, Y)$

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   &&            & \left\lbrace\begin{alignedat}{3}
>                                 z &= \dfrac{x}{y} \\
>                                 t &= x \\
>                                 \end{alignedat}\right. \quad\Rightarrow\quad \left\lbrace\begin{alignedat}{3}
>                                                                              x &= t \\
>                                                                              y &= \dfrac{t}{z} \\
>                                                                              \end{alignedat}\right. \quad\Rightarrow\quad \dfrac{\partial (x, y)}{\partial (z, t)} = \dfrac{t}{z^2} \\
> \Downarrow\quad && p_f (z, t) &= p (x, y) \cdot \left| \dfrac{\partial (x, y)}{\partial (z, t)} \right| \\
>                 &&            &= p_X (t) \cdot p_Y \left( \dfrac{t}{z} \right) \cdot \left| \dfrac{t}{z^2} \right| \\
> \Downarrow\quad &&    p_Z (z) &= \int_{-\infty}^{+\infty} p_X (t) \cdot p_Y \left( \dfrac{t}{z} \right) \cdot \left| \dfrac{t}{z^2} \right| \mathrm{d} t \\
>                 &&            &\xlongequal{s = \frac{t}{z}} \int_{-\infty}^{+\infty} p_X (z s) \cdot p_Y (s) \cdot |s| \mathrm{d} s \\
> \end{alignedat}
> $$
>
