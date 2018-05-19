---
layout:    zh_post
Topic:     概率统计
Title:     重要连续概率分布
Revised:   2018-05-18 21:58:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 连续均匀分布 $X \mapsto \mathrm{C_{ontinuous} U_{niform}} (\alpha, \beta)$

> $$
> \begin{alignedat}{3}
>                                                           p (x) &= \dfrac{1}{\beta - \alpha} \quad\Leftarrow\quad x \in [\alpha, \beta] \\
>                                                           C (x) &= \dfrac{x - \alpha}{\beta - \alpha} \\
>                    \mathrm{Exp} [\mathrm{CU} (\alpha, \beta)]^h &= \int_\alpha^\beta x^h \dfrac{1}{\beta - \alpha} \mathrm{d} x \\
>                                                                 &= \left. \dfrac{1}{\beta - \alpha} \dfrac{x^{h + 1}}{h + 1} \right|_\alpha^\beta \\
>                                                                 &= \dfrac{\beta^{h + 1} - \alpha^{h + 1}}{(h + 1) (\beta - \alpha)} \\
> \mathrm{Exp} [\mathrm{CU} (\alpha, \beta) - \mathrm{Exp} [X]]^h &= \int_\alpha^\beta \left( x - \dfrac{\beta + \alpha}{2} \right)^h \dfrac{1}{\beta - \alpha} \mathrm{d} x \\
>                                                                 &= \dfrac{1}{\beta - \alpha} \dfrac{1}{h + 1} \left. \left( x - \dfrac{\beta + \alpha}{2} \right)^{h + 1} \right|_\alpha^\beta \\
>                                                                 &= \dfrac{(\beta - \alpha)^{h + 1} - (\alpha - \beta)^{h + 1}}{2^{h + 1} (h + 1) (\beta - \alpha)} \\
> \end{alignedat} \\
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \dfrac{\beta - \alpha}{2 \sqrt{3}} & \mathrm{Exp} [X]^1 = \dfrac{\beta + \alpha}{2}                                                              & \mathrm{Exp} [X - \mathrm{Exp} [X]]^1 = 0 \\
> \mathrm{Var} [X] = \dfrac{(\beta - \alpha)^2}{12}    & \mathrm{Exp} [X]^2 = \dfrac{\beta^2 + \beta \alpha + \alpha^2}{3}                                           & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = \dfrac{(\beta - \alpha)^2}{12} \\
> \mathrm{Skew} [X] = 0                                & \mathrm{Exp} [X]^3 = \dfrac{\beta^3 + \beta^2 \alpha + \beta \alpha^2 + \alpha^3}{4}                        & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = 0 \\
> \mathrm{Kurt} [X] = - 1.2                            & \mathrm{Exp} [X]^4 = \dfrac{\beta^4 + \beta^3 \alpha^1 + \beta^2 \alpha^2 + \beta^1 \alpha^3 + \alpha^4}{5} & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = \dfrac{(\beta - \alpha)^4}{80} \\
> \hline
> \end{array}
> $$
>

> ### 独立连续均匀分布的可加性

> $$
> \begin{alignedat}{3}
> \Uparrow\quad && X_1 \mapsto \mathrm{CU} (\alpha, \beta) \quad&\land\quad X_2 \mapsto \mathrm{CU} (\alpha, \beta) \\
> \Uparrow\quad && p (z) &= \int_{-\infty}^{+\infty} p_{X_1} (x) \cdot p_{X_2} (z - x) \mathrm{d} x \\
> && &= \int_\alpha^\beta \dfrac{1}{\beta - \alpha} \cdot p_{X_2} (z - x) \mathrm{d} x \\
> && &\xlongequal{t = z - x} \dfrac{1}{\beta - \alpha} \int_{z - \beta}^{z - \alpha} p_{X_2} (t) \mathrm{d} t \\
> && \fbox{1} &\xlongequal{z - \alpha \in [\alpha, \beta]} \dfrac{1}{(\beta - \alpha)^2} \int_{\alpha}^{z - \alpha} \mathrm{d} t \\
> && &= \dfrac{z - 2 \alpha}{(\beta - \alpha)^2} \quad\Leftarrow\quad z \in [2 \alpha, \alpha + \beta] \\
> && \fbox{2} &\xlongequal{z - \beta \in [\alpha, \beta]} \dfrac{1}{(\beta - \alpha)^2} \int_{z - \beta}^\beta \mathrm{d} t \\
> && &= \dfrac{2 \beta - z}{(\beta - \alpha)^2} \quad\Leftarrow\quad z \in [\alpha + \beta, 2 \beta] \\
> \end{alignedat}
> $$
>

> ### 连续累积分布函数服从连续均匀分布

> $$
> \begin{alignedat}{3}
>       y &= C (x) \quad\Rightarrow\quad y \in [0, 1] \\
> p_C (y) &=  p (x) \cdot \left| \dfrac{\mathrm{d} x}{\mathrm{d} C (x)} \right| \\
>         &= p (x) \cdot \dfrac{1}{p (x)} \\
>         &= 1 \\
> \end{alignedat}
> $$
>

> ### 标准正态分布 $U \mapsto \mathrm{No_{rmal}} (0, 1^2)$

> $$
> \begin{alignedat}{3}
>                                                    p (u) &= \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{u^2}{2}} \quad\Leftarrow\quad u \in (-\infty, +\infty) \\
>                                         \Phi (u) = C (u) &= \dfrac{1}{2} \left[ 1 + \mathrm{E_{rr}} \left( \dfrac{u}{\sqrt{2}} \right) \right] \\
>                    \mathrm{Exp} [\mathrm{No} (0, 1^2)]^h &= \int_{-\infty}^{+\infty} u^h \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{u^2}{2}} \mathrm{d} x \\
>                                                          &\xlongequal{t = \frac{u^2}{2}} (h - 1 \mod 2) \dfrac{\sqrt{2}^h}{\sqrt{\pi}} \int_0^{+\infty} t^{\frac{h + 1}{2} - 1} e^{- t} \mathrm{d} t \\
>                                                          &= (h - 1 \mod 2) \dfrac{\sqrt{2}^h}{\sqrt{\pi}} \Gamma \left( {\dfrac{h + 1}{2}} \right) \\
> \mathrm{Exp} [\mathrm{No} (0, 1^2) - \mathrm{Exp} [U]]^h &= \mathrm{Exp} [\mathrm{No} (0, 1^2)]^h \\
> \end{alignedat} \\
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [U] = 1   & \mathrm{Exp} [U]^1 = 0 & \mathrm{Exp} [\mathrm{X} - \mathrm{Exp} [U]]^1 = 0 \\
> \mathrm{Var} [U] = 1  & \mathrm{Exp} [U]^2 = 1 & \mathrm{Exp} [\mathrm{X} - \mathrm{Exp} [U]]^2 = 1 \\
> \mathrm{Skew} [U] = 0 & \mathrm{Exp} [U]^3 = 0 & \mathrm{Exp} [\mathrm{X} - \mathrm{Exp} [U]]^3 = 0 \\
> \mathrm{Kurt} [U] = 0 & \mathrm{Exp} [U]^4 = 3 & \mathrm{Exp} [\mathrm{X} - \mathrm{Exp} [U]]^4 = 3 \\
> \hline
> \end{array}
> $$
>

> ### 正态分布 $X \mapsto \mathrm{No_{rmal}} (\mu, \sigma^2)$

> $$
> \begin{alignedat}{3}
>                                                           p (x) &= \dfrac{1}{\sqrt{2 \pi} \sigma} e^{- \frac{(x - \mu)^2}{2 \sigma^2}} \quad\Leftarrow\quad x \in (-\infty, +\infty) \\
>                                                           C (x) &= \dfrac{1}{2} \left[ 1 + \mathrm{E_{rr}} \left( \dfrac{x - \mu}{\sqrt{2} \sigma} \right) \right] \\
>                    \mathrm{Exp} [\mathrm{No} (\mu, \sigma^2)]^h &= \int_{-\infty}^{+\infty} x^h \dfrac{1}{\sqrt{2 \pi} \sigma} e^{- \frac{(x - \mu)^2}{2 \sigma^2}} \mathrm{d} x \\
>                                                                 &\xlongequal{t = \frac{x - \mu}{\sigma}} \int_{-\infty}^{+\infty} (\sigma t + \mu)^h \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{t^2}{2}} \mathrm{d} t \\
>                                                                 &= \mathrm{Exp} [\sigma \cdot \mathrm{No} (0, 1^2) + \mu]^h \\
> \mathrm{Exp} [\mathrm{No} (\mu, \sigma^2) - \mathrm{Exp} [X]]^h &= \int_{-\infty}^{+\infty} (x - \mu)^h \dfrac{1}{\sqrt{2 \pi} \sigma} e^{- \frac{(x - \mu)^2}{2 \sigma^2}} \mathrm{d} x \\
>                                                                 &\xlongequal{t = \frac{x - \mu}{\sigma}} \int_{-\infty}^{+\infty} (\sigma t)^h \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{t^2}{2}} \mathrm{d} x \\
>                                                                 &= \sigma^h \cdot \mathrm{Exp} [\mathrm{No} (0, 1^2)]^h \\
> \end{alignedat} \\
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \sigma    & \mathrm{Exp} [X]^1 = \mu                                   & \mathrm{Exp} [X - \mathrm{Exp} [X]]^1 = 0 \\
> \mathrm{Var} [X] = \sigma^2 & \mathrm{Exp} [X]^2 = \sigma^2 + \mu^2                      & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = \sigma^2 \\
> \mathrm{Skew} [X] = 0       & \mathrm{Exp} [X]^3 = 3 \sigma^2 \mu + \mu^3                & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = 0 \\
> \mathrm{Kurt} [X] = 0       & \mathrm{Exp} [X]^4 = 3 \sigma^4 + 6 \sigma^2 \mu^2 + \mu^4 & \mathrm{Exp} [X - \mathrm{Exp} [X]]^4 = 3 \sigma^4 \\
> \hline
> \end{array}
> $$
>

> ### 正态分布的标准化

> $$
> \begin{alignedat}{3}
>       X &\mapsto \mathrm{No} (\mu, \sigma^2) \\
> p_U (u) &\xlongequal{u = \frac{x - \mu}{\sigma}} p (x) \cdot \left| \dfrac{\mathrm{d} x}{\mathrm{d} u} \right| \\
>         &= \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{u^2}{2}} \quad\Leftarrow\quad \dfrac{\mathrm{d} x}{\mathrm{d} u} = \left. 1 \middle/ \dfrac{\mathrm{d} u}{\mathrm{d} x} \right. = \sigma \\
> p_Y (y) &\xlongequal{y = c \cdot x + d} p (x) \cdot \left| \dfrac{\mathrm{d} x}{\mathrm{d} y} \right| \\
>         &= \dfrac{1}{\sqrt{2 \pi} |c \cdot \sigma|} e^{- \frac{[y - (c \cdot \mu + d)]^2}{2 (c \cdot \sigma)^2}} \quad\Leftarrow\quad \dfrac{\mathrm{d} x}{\mathrm{d} y} = \left. 1 \middle/ \dfrac{\mathrm{d} y}{\mathrm{d} x} \right. = \dfrac{1}{c} \\
>       Y &\mapsto \mathrm{No} (c \cdot \mu + d, c^2 \cdot \sigma^2) \\
> \end{alignedat}
> $$
>

> ### 独立正态分布的可加性

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           &&                  X_1 \mapsto \mathrm{No} (\mu_1, \sigma_1^2) \quad&\land\quad X_2 \mapsto \mathrm{No} (\mu_2, \sigma_2^2) \\
> \Uparrow\quad           &&                                                             p (z) &= \int_{-\infty}^{+\infty} p_{X_1} (x) \cdot p_{X_2} (z - x) \mathrm{d} x \\
>                         &&                                                                   &= \int_{-\infty}^{+\infty} \dfrac{1}{\sqrt{2 \pi} \sigma_1} e^{- \frac{(x - \mu_1)^2}{2 \sigma_1^2}} \cdot \dfrac{1}{\sqrt{2 \pi} \sigma_2} e^{- \frac{(z - x - \mu_2)^2}{2 \sigma_2^2}} \mathrm{d} x \\
>                         &&                                                                   &= \dfrac{1}{\sqrt{2 \pi (\sigma_1^2 + \sigma_2^2)}} e^{- \frac{(z - \mu_1 - \mu_2)^2}{2 (\sigma_1^2 + \sigma_2^2)}} \int_{-\infty}^{+\infty} \dfrac{1}{\sqrt{2 \pi}} \sqrt{\dfrac{\sigma_1^2 + \sigma_2^2}{\sigma_1^2 \sigma_2^2}} e^{- \frac{\sigma_1^2 + \sigma_2^2}{2 \sigma_1^2 \sigma_2^2} \left[ x - \frac{\sigma_2^2 \mu_1 + \sigma_1^2 (z - \mu_2)}{\sigma_2^2 + \sigma_2^2} \right]^2} \mathrm{d} x \\
>                         &&                                                                   &= \dfrac{1}{\sqrt{2 \pi (\sigma_1^2 + \sigma_2^2)}} e^{- \frac{(z - \mu_1 - \mu_2)^2}{2 (\sigma_1^2 + \sigma_2^2)}} \\
> \fbox{1}\Downarrow\quad && \mathrm{No} (\mu_1, \sigma_1^2) * \mathrm{No} (\mu_2, \sigma_2^2) &= \mathrm{No} (\mu_1 + \mu_2, \sigma_1^2 + \sigma_2^2) \\
> \fbox{2}\Downarrow\quad &&                                   [\mathrm{No} (\mu, \sigma^2)]^h &= \mathrm{No} (h \mu, h \sigma^2) \\
> \end{alignedat}
> $$
>

> ### 正态分布的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \Phi (- x) = 1 - \Phi (x) \\
> \fbox{2}\quad & P (X \le x) = \Phi \left( \dfrac{x - \mu}{\sigma} \right) \\
> \fbox{3}\quad & P (|X| \le x) = 2 \Phi \left( \dfrac{x - \mu}{\sigma} \right)  - 1 \\
> \fbox{4}\quad & P (|X - \mu| \lt n \sigma) = 2 \Phi (n) - 1 \\
> \end{alignedat}
> $$
>

> ### 对数正态分布 $e^{X \mapsto \mathrm{No} (\mu, \sigma^2)} = Y \mapsto \mathrm{L_{og} N_{ormal}} (\mu, \sigma^2)$

> $$
> \begin{alignedat}{3}
>                                                     p_{e^X} (y) &= p (\ln y) \cdot \left| \dfrac{\mathrm{d}}{\mathrm{d} y} \ln y \right| \quad\Leftarrow\quad y \in (0, +\infty) \\
>                                                                 &= \dfrac{1}{\sqrt{2 \pi} \sigma y} e^{- \frac{(\ln y - \mu)^2}{2 \sigma^2}} \\
>                    \mathrm{Exp} [\mathrm{LN} (\mu, \sigma^2)]^h &= \int_{-\infty}^{+\infty} (e^x)^h \dfrac{1}{\sqrt{2 \pi} \sigma} e^{- \frac{(x - \mu)^2}{2 \sigma^2}} \mathrm{d} x \\
>                                                                 &= e^{\mu h + \frac{\sigma^2 h^2}{2}} \cdot \int_{-\infty}^{+\infty} \dfrac{1}{\sqrt{2 \pi} \sigma} e^{- \frac{[x - (\mu + \sigma^2 h)]^2}{2 \sigma^2}} \mathrm{d} x \\
>                                                                 &= e^{\mu h + \frac{\sigma^2 h^2}{2}} \\
> \mathrm{Exp} [\mathrm{LN} (\mu, \sigma^2) - \mathrm{Exp} [Y]]^h &= \mathrm{Exp} \left[ Y - e^{\mu + \frac{\sigma^2}{2}} \right]^h \\
> \end{alignedat} \\
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [Y] = e^{\mu + \frac{\sigma^2}{2}} \sqrt{e^{\sigma^2} - 1}       & \mathrm{Exp} [Y]^1 = e^{\mu + \frac{\sigma^2}{2}}     & \mathrm{Exp} [Y - \mathrm{Exp} [Y]]^1 = 0 \\
> \mathrm{Var} [Y] = e^{2 \mu + \sigma^2} (e^{\sigma^2} - 1)                   & \mathrm{Exp} [Y]^2 = e^{2 \mu + 2 \sigma^2}           & \mathrm{Exp} [Y - \mathrm{Exp} [Y]]^2 = e^{2 \mu + \sigma^2} (e^{\sigma^2} - 1) \\
> \mathrm{Skew} [Y] = (e^{\sigma^2} + 2) \sqrt{e^{\sigma^2} - 1}               & \mathrm{Exp} [Y]^3 = e^{3 \mu + \frac{9 \sigma^2}{2}} & \mathrm{Exp} [Y - \mathrm{Exp} [Y]]^3 = e^{3 \mu + \frac{3 \sigma^2}{2}} (e^{\sigma^2} - 1)^2 (e^{\sigma^2} + 2) \\
> \mathrm{Kurt} [Y] = e^{4 \sigma^2} + 2 e^{3 \sigma^2} + 3 e^{2 \sigma^2} - 6 & \mathrm{Exp} [Y]^4 = e^{4 \mu + 8 \sigma^2}           & \mathrm{Exp} [Y - \mathrm{Exp} [Y]]^4 = e^{4 \mu + 2 \sigma^2} (e^{\sigma^2} - 1)^2 (e^{4 \sigma^2} + 2 e^{3 \sigma^3} + 3 e^{\sigma^2} - 3) \\
> \hline
> \end{array}
> $$
>

> ### $\Gamma$ 分布 $X \mapsto \mathrm{Ga_{mma}} (t, \lambda)$

> $$
> \begin{alignedat}{3}
>                                                        p (x) &= \dfrac{\lambda}{\Gamma (t)} (\lambda x)^{t - 1} e^{- \lambda x} \quad\Leftarrow\quad x \in [0, +\infty) \\
>                                                        C (x) &= \dfrac{\lambda}{\Gamma (t)} \int_0^x (\lambda x)^{t - 1} e^{- \lambda x} \mathrm{d} x \\
>                    \mathrm{Exp} [\mathrm{Ga} (t, \lambda)]^h &= \dfrac{\lambda}{\Gamma (t)} \int_0^{+\infty} x^h (\lambda x)^{t - 1} e^{- \lambda x} \mathrm{d} x \\
>                                                              &\xlongequal{y = \lambda x} \dfrac{1}{\lambda^h \Gamma (t)} \int_0^{+\infty} y^{t + h - 1} e^{- y} \mathrm{d} y \\
>                                                              &= \dfrac{\Gamma (t + h)}{\lambda^h \Gamma (t)} \\
> \mathrm{Exp} [\mathrm{Ga} (t, \lambda) - \mathrm{Exp} [X]]^h &= \dfrac{\lambda}{\Gamma (t)} \int_0^{+\infty} \left( x - \dfrac{t}{\lambda} \right)^h (\lambda x)^{t - 1} e^{- \lambda x} \mathrm{d} x \\
>                                                              &= \dfrac{1}{\lambda^h \Gamma (t)} \int_0^{+\infty} (\lambda x - t)^{h - 1} \mathrm{d} [- (\lambda x)^t e^{- \lambda x}] \\
>                                                              &= \dfrac{(h - 1) \cdot \Gamma (t + 1)}{\lambda^h \cdot \Gamma (t)} \dfrac{\lambda}{\Gamma (t + 1)} \int_0^{+\infty} (\lambda x - t)^{h - 2} (\lambda x)^{t} e^{- \lambda x} \mathrm{d} x \\
>                                                              &= \dfrac{(h - 1) t}{\lambda^h} \mathrm{Exp} [\lambda \cdot \mathrm{Ga} (t + 1, \lambda) - t]^{h - 2} \\
> \end{alignedat} \\
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \dfrac{\sqrt{t}}{\lambda} & \mathrm{Exp} [X]^1 = \dfrac{t}{\lambda}                           & \mathrm{Exp} [X - \mathrm{Exp} [X]]^1 = 0 \\
> \mathrm{Var} [X] = \dfrac{t}{\lambda^2}     & \mathrm{Exp} [X]^2 = \dfrac{t (t + 1)}{\lambda^2}                 & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = \dfrac{t}{\lambda^2} \\
> \mathrm{Skew} [X] = \dfrac{2}{\sqrt{t}}     & \mathrm{Exp} [X]^3 = \dfrac{t (t + 1) (t + 2)}{\lambda^3}         & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = \dfrac{2 t}{\lambda^3} \\
> \mathrm{Kurt} [X] = \dfrac{6}{t}            & \mathrm{Exp} [X]^4 = \dfrac{t (t + 1) (t + 2) (t + 3)}{\lambda^4} & \mathrm{Exp} [X - \mathrm{Exp} [X]]^4 = \dfrac{3 t (t + 2)}{\lambda^4} \\
> \hline
> \end{array}
> $$
>

> ### 独立 $\Gamma$ 分布的可加性

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           &&   X_1 \mapsto \mathrm{Ga} (t_1, \lambda) \quad&\land\quad X_2 \mapsto \mathrm{Ga} (t_2, \lambda) \\
> \Downarrow\quad         &&                                         p (z) &= \dfrac{\lambda^2}{\Gamma (t_1) \Gamma(t_2)} \int_0^z (\lambda x)^{t_1 - 1} e^{- \lambda x} \cdot [\lambda (z - x)]^{t_2 - 1} e^{- \lambda (z - x)} \mathrm{d} x \\
>                         &&                                               &\xlongequal{y = \frac{x}{z}} \dfrac{\lambda^{t_1 + t_2} e^{- \lambda z}}{\Gamma (t_1) \Gamma (t_2)} z^{t_1 + t_2 - 1} \int_0^1 y^{t_1 - 1} (1 - y)^{t_2 - 1} \mathrm{d} y \\
>                         &&                                               &= \dfrac{\lambda \Beta(t_1, t_2)}{\Gamma (t_1) \Gamma (t_2)} (\lambda z)^{t_1 + t_2 - 1} e^{- \lambda z} \\
>                         &&                                               &= \dfrac{\lambda}{\Gamma (t_1 + t_2)} (\lambda z)^{t_1 + t_2 - 1} e^{- \lambda z} \\
> \fbox{1}\Downarrow\quad && \Gamma (t_1, \lambda) * \Gamma (t_2, \lambda) &= \Gamma (t_1 + t_2, \lambda) \\
> \fbox{2}\Downarrow\quad &&                       [\Gamma (t, \lambda)]^h &= \Gamma (h t, \lambda) \\
> \end{alignedat}
> $$
>

> ### 随机分布与 $\Gamma$ 分布

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   &&           N &\mapsto \mathrm{St} (\lambda t) \\
> \Downarrow\quad && P (N \ge n) &= \sum_n^{+\infty} \dfrac{(\lambda t)^n}{n !} e^{- \lambda t} \\
>                 &&             &= \int_0^t \dfrac{\mathrm{d}}{\mathrm{d} t} \left[ \sum_n^{+\infty} \dfrac{(\lambda t)^n}{n !} e^{- \lambda t} \right] \mathrm{d} t \\
>                 &&             &= \dfrac{\lambda }{\Gamma (t)} \int_0^t (\lambda t)^{n - 1} e^{- \lambda t} \mathrm{d} t \\
> \Downarrow\quad && P (T \le t) &= P (N \ge n) \\
> \Downarrow\quad &&           T &\mapsto \mathrm{Ga} (n, \lambda) \\
> \end{alignedat}
> $$
>

> ### 指数分布 $X \mapsto \mathrm{Ex_{ponential}} (\lambda) = \mathrm{Ga} (1, \lambda)$

> $$
> \begin{alignedat}{3}
>                                                     p (x) &= \lambda e^{- \lambda x} \quad\Leftarrow\quad x \in [0, +\infty) \\
>                                                     C (x) &= 1 - e^{- \lambda x} \\
>                    \mathrm{Exp} [\mathrm{Ex} (\lambda)]^h &= \mathrm{Exp} [\mathrm{Ga} (1, \lambda)]^h \\
> \mathrm{Exp} [\mathrm{Ex} (\lambda) - \mathrm{Exp} [X]]^h &= \mathrm{Exp} [\mathrm{Ga} (1, \lambda) - \mathrm{Exp} [X]]^h \\
> \end{alignedat} \\
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \dfrac{1}{\lambda}    & \mathrm{Exp} [X]^1 = \dfrac{1}{\lambda}    & \mathrm{Exp} [X - \mathrm{Exp} [X]]^1 = 0 \\
> \mathrm{Var} [X] = \dfrac{1}{\lambda^2} & \mathrm{Exp} [X]^2 = \dfrac{2}{\lambda^2}  & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = \dfrac{1}{\lambda^2} \\
> \mathrm{Skew} [X] = 2                   & \mathrm{Exp} [X]^3 = \dfrac{6}{\lambda^3}  & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = \dfrac{2}{\lambda^3} \\
> \mathrm{Kurt} [X] = 6                   & \mathrm{Exp} [X]^4 = \dfrac{24}{\lambda^4} & \mathrm{Exp} [X - \mathrm{Exp} [X]]^4 = \dfrac{9}{\lambda^2} \\
> \hline
> \end{array}
> $$
>

> ### 指数分布的无记忆性

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   &&                  P (X \gt t) &= 1 - C (x) \\
>                 &&                              &= e^{- \lambda t} \\
> \Downarrow\quad && P (x \gt t + s \mid X \gt t) &= e^{- \lambda s} \\
> \Downarrow\quad && P (x \gt t + s \mid X \gt t) &= P (X \gt s) \\
> \end{alignedat}
> $$
>

> ### $\chi^2$ 分布 $X \mapsto \mathrm{Ch_i} (n) = \mathrm{Ga} (\frac{n}{2}, \frac{1}{2})$

> $$
> \begin{alignedat}{3}
>                                               p (x) &= \dfrac{1}{2^\frac{n}{2} \Gamma (\frac{n}{2})} x^{\frac{n}{2} - 1} e^{- \frac{x}{2}} \quad\Leftarrow\quad x \in [0, +\infty) \\
>                                               C (x) &= \dfrac{1}{2^\frac{n}{2} \Gamma (\frac{n}{2})} \int_0^x x^{\frac{n}{2} - 1} e^{- \frac{x}{2}} \quad\Leftarrow\quad x \in [0, +\infty) \mathrm{d} x \\
>                    \mathrm{Exp} [\mathrm{Ch} (n)]^h &= \mathrm{Exp} \left[ \mathrm{Ga} \left( \dfrac{n}{2}, \dfrac{1}{2} \right) \right]^h \\
> \mathrm{Exp} [\mathrm{Ch} (n) - \mathrm{Exp} [X]]^h &= \mathrm{Exp} \left[ \mathrm{Ga} \left( \dfrac{n}{2}, \dfrac{1}{2} \right) - \mathrm{Exp} [X] \right]^h \\
> \end{alignedat} \\
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \sqrt{2 n}            & \mathrm{Exp} [X]^1 = n                         & \mathrm{Exp} [X - \mathrm{Exp} [X]]^1 = 0 \\
> \mathrm{Var} [X] = 2 n                  & \mathrm{Exp} [X]^2 = n (n + 2)                 & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = 2 n \\
> \mathrm{Skew} [X] = \sqrt{\dfrac{8}{n}} & \mathrm{Exp} [X]^3 = n (n + 2) (n + 4)         & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = 8 n \\
> \mathrm{Kurt} [X] = \dfrac{12}{n}       & \mathrm{Exp} [X]^4 = n (n + 2) (n + 4) (n + 6) & \mathrm{Exp} [X - \mathrm{Exp} [X]]^4 = 12 n (n + 4) \\
> \hline
> \end{array}
> $$
>

> ### $\Beta$ 分布 $X \mapsto \mathrm{Be_{ta}} (t, s)$

> $$
> \begin{alignedat}{3}
>                                                  p (x) &= \dfrac{1}{\Beta (t, s)} x^{t - 1} (1 - x)^{s - 1} \quad\Leftarrow\quad x \in [0, 1] \\
>                                                  C (x) &= \dfrac{1}{\Beta (t, s)} \int_0^x x^{t - 1} (1 - x)^{s - 1} \mathrm{d} x \\
>                    \mathrm{Exp} [\mathrm{Be} (t, s)]^h &= \dfrac{1}{\Beta (t, s)} \int_0^1 x^h x^{t - 1} (1 - x)^{s - 1} \mathrm{d} x \\
>                                                        &= \dfrac{1}{\Beta (t, s)} \Beta (h + t, s) \\
>                                                        &= \dfrac{\Gamma (t + s)}{\Gamma (t)} \dfrac{\Gamma (t + h)}{\Gamma (t + s + h)} \\
> \mathrm{Exp} [\mathrm{Be} (t, s) - \mathrm{Exp} [X]]^h &= \dfrac{1}{\mathrm{\Beta} (t, s)} \int_0^1 \left( x - \dfrac{t}{t + s} \right)^h x^{t - 1} (1 - x)^{s - 1} \mathrm{d} x \\
>                                                        &= \dfrac{1}{(t + s)^h \cdot \mathrm{\Beta} (t, s)} \int _0^1 [(t + s) x - t]^{h - 1} \mathrm{d} [- x^t (1 - x)^s] \\
>                                                        &= \dfrac{(h - 1) \cdot \Beta (t + 1, s + 1)}{(t + s)^{h - 1} \cdot \Beta (t, s)} \dfrac{1}{\Beta (t + 1, s + 1)} \int_0^1 [(t + s) x - t]^{h - 2} x^t (1 - x)^s \mathrm{d} x \\
>                                                        &= \dfrac{(h - 1) t s}{(t + s)^h (t + s + 1)} \mathrm{Exp} [(t + s) \cdot \mathrm{\Beta} (t + 1, s + 1) - t]^{h - 2} \\
> \end{alignedat} \\
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \dfrac{1}{t + s} \sqrt{\dfrac{t s}{t +s + 1}}                                      & \mathrm{Exp} [X]^1 = \dfrac{t}{t + s}                                                               & \mathrm{Exp} [X - \mathrm{Exp} [X]]^1 = 0 \\
> \mathrm{Var} [X] = \dfrac{t s}{(t + s)^2 (t + s + 1)}                                                & \mathrm{Exp} [X]^2 = \dfrac{t (t + 1)}{(t + s) (t + s + 1)}                                         & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = \dfrac{t s}{(t + s)^2 (t + s + 1)} \\
> \mathrm{Skew} [X] = \dfrac{2 (s - t)}{t + s + 2} \sqrt{\dfrac{t + s + 1}{t s}}                       & \mathrm{Exp} [X]^3 = \dfrac{t (t + 1) (t + 2)}{(t + s) (t + s + 1) (t + s + 2)}                     & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = \dfrac{2 t s (s - t)}{(t + s)^3 (t + s + 1) (t + s + 2)} \\
> \mathrm{Kurt} [X] = \dfrac{6 [(t - s)^2 (t + s + 1) - t s (t + s + 2)]}{t s (t + s + 2) (t + s + 3)} & \mathrm{Exp} [X]^4 = \dfrac{t (t + 1) (t + 2) (t + 3)}{(t + s) (t + s + 1) (t + s + 2) (t + s + 3)} & \mathrm{Exp} [X - \mathrm{Exp} [X]]^4 = \dfrac{3 s t [2 (t - s)^2 + s t (t + s + 2)]}{(t + s)^4 (t + s + 1) (t + s + 2) (t + s + 3)} \\
> \hline
> \end{array}
> $$
>

> ### 反正切分布 $X \mapsto \mathrm{A_{rc} T_{angent}} (\mu, \lambda)$

> $$
> \begin{alignedat}{3}
>                                       p (x) &= \dfrac{1}{\pi} \dfrac{\lambda}{\lambda^2 + (x - \mu)^2} \quad\Leftarrow\quad x \in (-\infty, +\infty) \\
>                                       C (x) &= \dfrac{1}{\pi} \left[ \arctan \left( \dfrac{x - \mu}{\lambda} \right) + \dfrac{\pi}{2} \right] \\
> \mathrm{Exp} |\mathrm{AT} (\mu, \lambda)^h| &= \dfrac{1}{\pi} \int_{-\infty}^{+\infty} |x^h| \dfrac{\lambda}{\lambda^2 + (x - \mu)^2} \mathrm{d} x \\
>                                             &\to +\infty \\
> \end{alignedat}
> $$
>
