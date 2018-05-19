---
layout:    zh_post
Topic:     概率统计
Title:     重要多维概率分布
Revised:   2018-05-18 21:58:00 +08 @ 中国-新疆-乌鲁木齐 +06
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

> ### 标准二维正态分布 $(U, V) \mapsto \mathrm{B_{ivariate} N_{ormal}} (0, 0, 1^2, 1^2, 0)$

> $$
> \begin{alignedat}{3}
>                                         p (u, v) &= \dfrac{1}{2 \pi} e^{- \frac{u^2 + v^2}{2}} \\
>                                          p_U (u) &= \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{u^2}{2}} \\
>                                          p_V (v) &= \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{v^2}{2}} \\
>                                     p (u \mid v) &= \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{u^2}{2}} \quad\Leftarrow\quad \dfrac{p (u, v)}{p_V (v)} \\
>                                     p (v \mid u) &= \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{v^2}{2}} \quad\Leftarrow\quad \dfrac{p (u, v)}{p_U (u)} \\
> \mathrm{CoV} [\mathrm{BN} (0, 0, 1^2, 1^2, 0)]^h &= \int_{-\infty}^{+\infty} \int_{-\infty}^{+\infty} (u v)^h \dfrac{1}{2 \pi} e^{- \frac{u^2 + v^2}{2}} \mathrm{d} u \mathrm{d} v \\
>                                                  &= \int_{-\infty}^{+\infty} u^h \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{u^2}{2}} \mathrm{d} u \int_{-\infty}^{+\infty} v^h \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{v^2}{2}} \mathrm{d} v \\
>                                                  &= \mathrm{Exp}^2 [\mathrm{No} (0, 1^2)]^h
> \end{alignedat} \\
> \begin{array}{l|l|l}
> \hline
> \mathrm{Exp} [U]^1 = 0 & \mathrm{Exp} [V]^1 = 0 & \mathrm{Exp} [U V]^1 = 0 \\
> \mathrm{Var} [U]^1 = 1 & \mathrm{Var} [V]^1 = 1 & \mathrm{CoV} [U, V]^1 = 0 \\
> \mathrm{SD} [U] = 1    & \mathrm{SD} [V] = 1    & \mathrm{Corr} [U, V] = 0 \\
> \hline
> \end{array}
> $$
>

> ### 二维正态分布 $(X, Y) \mapsto \mathrm{B_{ivariate} N_{ormal}} (\mu_X, \mu_Y, \sigma_X^2, \sigma_Y^2, \rho)$

> $$
> \begin{alignedat}{3}
>                                                                  p (x, y) &= \dfrac{1}{2 \pi \sigma_X \sigma_Y \sqrt{1 - \rho^2}} e^{- \frac{1}{2 (1 - \rho^2)} \left[ \frac{(x - \mu_X)^2}{\sigma_X^2} - 2 \rho \frac{(x - \mu_X) (y - \mu_Y)}{\sigma_X \sigma_Y} + \frac{(y - \mu_Y)^2}{\sigma_Y^2} \right]} \quad\Leftarrow\quad x, y \in (-\infty, +\infty) \\
>                                                                   p_X (x) &= \dfrac{1}{\sqrt{2 \pi} \sigma_X} e^{- \frac{(x - \mu_X)^2}{2 \sigma_X^2}} \\
>                                                                   p_Y (y) &= \dfrac{1}{\sqrt{2 \pi} \sigma_Y} e^{- \frac{(y - \mu_Y)^2}{2 \sigma_Y^2}} \quad\Leftarrow\quad p_V (v) \cdot \left| \dfrac{\mathrm{d} v}{\mathrm{d} y} \right| \\
>                                                              p (x \mid y) &= \dfrac{1}{\sqrt{2 \pi \sigma_X^2 (1 - \rho^2)}} e^{- \frac{1}{2 \sigma_X^2 (1 - \rho^2)} \left[ x - \left( \mu_X + \rho \frac{\sigma_X}{\sigma_Y} (y - \mu_Y) \right) \right]^2} \quad\Leftarrow\quad p (x \mid y) = \dfrac{p (x, y)}{p_Y (y)} \\
>                                                              p (y \mid x) &= \dfrac{1}{\sqrt{2 \pi \sigma_Y^2 (1 - \rho^2)}} e^{- \frac{1}{2 \sigma_Y^2 (1 - \rho^2)} \left[ y - \left( \mu_Y + \rho \frac{\sigma_Y}{\sigma_X} (x - \mu_X) \right) \right]^2} \quad\Leftarrow\quad p (y \mid x) = \dfrac{p (x, y)}{p_X (x)} \\
> \mathrm{CoV} [\mathrm{BN} (\mu_X, \mu_Y, \sigma_X^2, \sigma_Y^2, \rho)]^h &= \int_{-\infty}^{+\infty} \int_{-\infty}^{+\infty} (x - \mu_X)^h (y - \mu_Y)^h \dfrac{1}{2 \pi \sigma_X \sigma_Y \sqrt{1 - \rho^2}} e^{- \frac{1}{2 (1 - \rho^2)} \left[ \frac{(x - \mu_X)^2}{\sigma_X^2} - 2 \rho \frac{(x - \mu_X) (y - \mu_Y)}{\sigma_X \sigma_Y} + \frac{(y - \mu_Y)^2}{\sigma_Y^2} \right]} \mathrm{d} x \mathrm{d} y \\
>                                                                           &\xlongequal[v = \frac{y - \mu_Y}{\sigma_Y}]{u = \frac{1}{\sqrt{1 - \rho^2}} \left( \frac{x - \mu_X}{\sigma_X} - \rho \frac{y - \mu_Y}{\sigma_Y} \right)} \dfrac{\sigma_X^h \sigma_Y^h}{2 \pi} \int_{-\infty}^{+\infty} \int_{-\infty}^{+\infty} \left( \sqrt{1 - \rho^2} u v + \rho v^2 \right)^h e^{- \frac{u^2 + v^2}{2}} \mathrm{d} u \mathrm{d} v \\
> \end{alignedat} \\
> \begin{array}{l|l|l}
> \hline
> \mathrm{Exp} [X]^1 = \mu_X      & \mathrm{Exp} [Y]^1 = \mu_Y      & \mathrm{Exp} [X Y]^1 = \rho \sigma_X \sigma_Y + \mu_X \mu_Y \\
> \mathrm{Var} [X]^1 = \sigma_X^2 & \mathrm{Var} [Y]^1 = \sigma_Y^2 & \mathrm{CoV} [X, Y]^1 = \rho \sigma_X \sigma_Y \\
> \mathrm{SD} [X] = \sigma_X      & \mathrm{SD} [Y] = \sigma_Y      & \mathrm{Cor} [X, Y] = \rho \\
> \hline
> \end{array}
> $$
>

> ### 二维正态分布的标准化

> $$
> \begin{alignedat}{3}
>          (X, Y) &\mapsto \mathrm{BN} (\mu_X, \mu_Y, \sigma_X^2, \sigma_Y^2, \rho) \\
> p_{U, V} (u, v) &\xlongequal[v = \frac{y - \mu_Y}{\sigma_Y}]{u = \frac{1}{\sqrt{1 - \rho^2}} \left( \frac{x - \mu_X}{\sigma_X} - \rho \frac{y - \mu_Y}{\sigma_Y} \right)} p (x, y) \cdot \left| \dfrac{\partial (x, y)}{\partial (u, v)} \right| \\
>                 &= \dfrac{1}{2 \pi} e^{- \frac{u^2 + v^2}{2}} \quad\Leftarrow\quad \dfrac{\partial (x, y)}{\partial (u, v)} = \left. 1 \middle/ \dfrac{\partial (u, v)}{\partial (x, y)} \right. = \sigma_X \sigma_Y \sqrt{1 - \rho^2} \\
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
