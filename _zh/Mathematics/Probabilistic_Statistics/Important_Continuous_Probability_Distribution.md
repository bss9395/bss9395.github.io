---
layout:    zh_post
Topic:     概率统计
Title:     重要连续概率分布
Revised:   2018-05-09 00:49:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 均匀分布 $X \mapsto \mathrm{U_{niform}} (\alpha, \beta)$

> $$
> \begin{alignedat}{3}
>                                       p (x) &= \dfrac{1}{\beta - \alpha} \quad\Leftarrow\quad x \in [\alpha, \beta] \\
>                                       C (x) &= \dfrac{x - \alpha}{\beta - \alpha} \\
> \mathrm{Exp} [\mathrm{U} (\alpha, \beta)]^h &= \\
> \mathrm{Exp} [\mathrm{U} (\alpha, \beta)]^1 &= \dfrac{\beta - \alpha}{2} \\
> \mathrm{Exp} [\mathrm{U} (\alpha, \beta)]^2 &= \dfrac{\alpha^2 + \alpha \beta + \beta^2}{3} \\
>   \mathrm{Var} [\mathrm{U} (\alpha, \beta)] &= \dfrac{(b - a)^2}{12} \\
> \end{alignedat}
> $$
>

> ### 正态分布 $X \mapsto \mathrm{N_{ormal}} (\mu, \sigma^2)$

> $$
> \begin{alignedat}{3}
>                                       p (x) &= \dfrac{1}{\sqrt{2 \pi} \sigma} e^{- \frac{(x - \mu)^2}{2 \sigma^2}} \quad\Leftarrow\quad x \in (-\infty, +\infty) \\
>                                       C (x) &= \dfrac{1}{2} \left[ 1 + \mathrm{E_{rr}} \left( \dfrac{x - \mu}{\sqrt{2} \sigma} \right) \right] \\
> \mathrm{Exp} [\mathrm{N} (\mu, \sigma^2)]^h &= \\
> \mathrm{Exp} [\mathrm{N} (\mu, \sigma^2)]^1 &= \mu \\
> \mathrm{Exp} [\mathrm{N} (\mu, \sigma^2)]^2 &= \mu^2 + \sigma^2 \\
>     \mathrm{Var} [\mathrm{N} (\mu, \sigma)] &= \sigma^2 \\
> \end{alignedat}
> $$
>

> ### 正态分布的标准化

> $$
> \begin{alignedat}{3}
>         \Uparrow\quad   &&       P (c X + d \le x) &= P \left( X \le \dfrac{x - d}{c} \right) \\
>         \Downarrow\quad &&         C_{c X + d} (x) &= C_X \left( \dfrac{x - d}{c} \right) \\
>         \Downarrow\quad &&         p_{c X + d} (x) &= \dfrac{1}{c} \cdot p_X \left( \dfrac{x - d}{c} \right) \\
>         \Downarrow\quad &&         p_{c X + d} (x) &= \dfrac{1}{\sqrt{2 \pi} (c \sigma)} e^{- \frac{(x - c \mu - d)^2}{2 (c \sigma)^2}} \\
> \fbox{1}\Downarrow\quad &&                 c X + d &\mapsto \mathrm{N} (c \mu + d, c^2 \sigma^2) \\
> \fbox{2}\Downarrow\quad && \dfrac{X - \mu}{\sigma} &\mapsto \mathrm{N} (0, 1^2) \\
> \end{alignedat}
> $$
>

> ### 标准正态分布 $X \mapsto \mathrm{N_{ormal}} (0, 1^2)$

> $$
> \begin{alignedat}{3}
>                                p (x) &= \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{x^2}{2}} \quad\Leftarrow\quad x \in (-\infty, +\infty) \\
>                     \Phi (x) = C (x) &= \dfrac{1}{\sqrt{2 \pi}} \int_{-\infty}^x e^{- \frac{x^2}{2}} \mathrm{d} x \\
> \mathrm{Exp} [\mathrm{N} (0, 1^2)]^h &= \\
> \mathrm{Exp} [\mathrm{N} (0, 1^2)]^1 &= 0 \\
> \mathrm{Exp} [\mathrm{N} (0, 1^2)]^2 &= 1 \\
>   \mathrm{Var} [\mathrm{N} (0, 1^2)] &= 1 \\
> \end{alignedat}
> $$
>

> ### 正态分布的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \Phi (- x) = 1 - \Phi (x) \\
> \fbox{2}\quad & P (X \le x) = \Phi \left( \dfrac{x - \mu}{\sigma} \right) \\
> \fbox{3}\quad & P (|X| \le x) = 2 \Phi \left( \dfrac{x - \mu}{\sigma} \right)  - 1 \\
> \fbox{4}\quad & P (|X - \mu| \lt n \sigma) = 
> \end{alignedat}
> $$
>

> ### 指数分布 $X \mapsto \mathrm{E_{xponential}} (\lambda)$

> $$
> \begin{alignedat}{3}
>                                 p (x) &= \lambda e^{- \lambda x} \quad\Leftarrow\quad x \in [0, +\infty) \\
>                                 C (x) &= 1 - e^{- \lambda x} \\
> \mathrm{Exp} [\mathrm{E} (\lambda)]^h &= \\
> \mathrm{Exp} [\mathrm{E} (\lambda)]^1 &= \dfrac{1}{\lambda} \\
> \mathrm{Exp} [\mathrm{E} (\lambda)]^2 &= \dfrac{2}{\lambda^2} \\
>   \mathrm{Var} [\mathrm{E} (\lambda)] &= \dfrac{1}{\lambda^2} \\
> \end{alignedat}
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