---
layout:    zh_post
Topic:     概率统计
Title:     重要连续概率分布
Revised:   2018-05-08 16:18:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 正态分布 $X \mapsto \mathrm{N_{ormal}} (\mu, \sigma^2)$

> $$
> \begin{alignedat}{3}
> p (x) &= \dfrac{1}{\sqrt{2 \pi} \sigma} e^{- \frac{(x - \mu)^2}{2 \sigma^2}} \quad\Leftarrow\quad x \in (-\infty, +\infty) \\
> C (x) &= \dfrac{1}{\sqrt{2 \pi} \sigma} \int_{-\infty}^x e^{- \frac{(x - \mu)^2}{2 \sigma^2}} \mathrm{d} x \\
> \mathrm{E} [\mathrm{N} (\mu, \sigma^2)]^h &= 
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

> ### 标准正态分布 $X \mapsto \mathrm{N} (0, 1^2)$

> $$
> \begin{alignedat}{3}
>            p (x) &= \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{x^2}{2}} \quad\Leftarrow\quad x \in (-\infty, +\infty) \\
> \Phi (x) = C (x) &= \dfrac{1}{\sqrt{2 \pi}} \int_{-\infty}^x e^{- \frac{x^2}{2}} \mathrm{d} x \\
> \mathrm{E} [\mathrm{N} (0, 1^2)]^h &= \\
> \mathrm{E} [\mathrm{N} (0, 1^2)]^1 &= 0 \\
> \mathrm{E} [\mathrm{N} (0, 1^2)]^2 &= 1 \\
> \mathrm{Var} [\mathrm{N} (0, 1^2)] &= 1^2 \\
> \end{alignedat}
> $$
>

> ### 标准正态分布的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \Phi (- x) = 1 - \Phi (x) \\
> \fbox{2}\quad & P (X \le x) = \Phi \left( \dfrac{x - \mu}{\sigma} \right) \\
> \fbox{3}\quad & P (|X| \le x) = 2 \Phi \left( \dfrac{x - \mu}{\sigma} \right)  - 1 \\
> \end{alignedat}
> $$
>

> ### 