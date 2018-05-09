---
layout:    zh_post
Topic:     概率统计
Title:     重要连续概率分布
Revised:   2018-05-09 20:47:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 均匀分布 $X \mapsto \mathrm{Un_{iform}} (\alpha, \beta)$

> $$
> \begin{alignedat}{3}
>                                        p (x) &= \dfrac{1}{\beta - \alpha} \quad\Leftarrow\quad x \in [\alpha, \beta] \\
>                                        C (x) &= \dfrac{x - \alpha}{\beta - \alpha} \\
> \mathrm{Exp} [\mathrm{Un} (\alpha, \beta)]^h &= \int_\alpha^\beta x^h \dfrac{1}{\beta - \alpha} \mathrm{d} x \\
>                                              &= \left. \dfrac{1}{\beta - \alpha} \dfrac{x^{h + 1}}{h + 1} \right|_\alpha^\beta \\
>                                              &= \dfrac{\beta^{h + 1} - \alpha^{h + 1}}{(\beta - \alpha) (h + 1)} \\
>                           \mathrm{Exp} [X]^1 &= \dfrac{\beta + \alpha}{2} \\
>                           \mathrm{Exp} [X]^2 &= \dfrac{\beta^2 + \beta \alpha + \alpha^2}{3} \\
>                             \mathrm{Var} [X] &= \dfrac{(\beta - \alpha)^2}{12} \\
> \end{alignedat}
> $$
>

> ### 标准正态分布 $X \mapsto \mathrm{No_{rmal}} (0, 1^2)$

> $$
> \begin{alignedat}{3}
>                                 p (x) &= \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{x^2}{2}} \quad\Leftarrow\quad x \in (-\infty, +\infty) \\
>                      \Phi (x) = C (x) &= \dfrac{1}{2} \left[ 1 + \mathrm{E_{rr}} \left( \dfrac{x}{\sqrt{2}} \right) \right] \\
> \mathrm{Exp} [\mathrm{No} (0, 1^2)]^h &= \int_{-\infty}^{+\infty} x^h \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{x^2}{2}} \mathrm{d} x \\
>                                       &\xlongequal{t = \frac{x^2}{2}} (h - 1 \mod 2) \dfrac{\sqrt{2}^h}{\sqrt{\pi}} \int_0^{+\infty} t^{\frac{h + 1}{2} - 1} e^{- t} \mathrm{d} t \\
>                                       &= (h - 1 \mod 2) \dfrac{\sqrt{2}^h}{\sqrt{\pi}} \Gamma \left( {\dfrac{h + 1}{2}} \right) \\
>                    \mathrm{Exp} [X]^1 &= 0 \\
>                    \mathrm{Exp} [X]^2 &= 1 \\
>                      \mathrm{Var} [X] &= 1 \\
> \end{alignedat}
> $$
>

> ### 正态分布 $X \mapsto \mathrm{No_{rmal}} (\mu, \sigma^2)$

> $$
> \begin{alignedat}{3}
>                                        p (x) &= \dfrac{1}{\sqrt{2 \pi} \sigma} e^{- \frac{(x - \mu)^2}{2 \sigma^2}} \quad\Leftarrow\quad x \in (-\infty, +\infty) \\
>                                        C (x) &= \dfrac{1}{2} \left[ 1 + \mathrm{E_{rr}} \left( \dfrac{x - \mu}{\sqrt{2} \sigma} \right) \right] \\
> \mathrm{Exp} [\mathrm{No} (\mu, \sigma^2)]^h &= \int_{-\infty}^{+\infty} x^h \dfrac{1}{\sqrt{2 \pi} \sigma} e^{- \frac{(x - \mu)^2}{2 \sigma^2}} \mathrm{d} x \\
>                                              &\xlongequal{t = \frac{x - \mu}{\sigma}} \int_{-\infty}^{+\infty} (\sigma t + \mu)^h \dfrac{1}{\sqrt{2 \pi}} e^{- \frac{t}{2}} \mathrm{d} t \\
>                                              &= \mathrm{Exp} [\sigma \cdot \mathrm{No} (0, 1^2) + \mu]^h \\
>                           \mathrm{Exp} [X]^1 &= \mu \\
>                           \mathrm{Exp} [X]^2 &= \sigma^2 + \mu^2 \\
>                             \mathrm{Var} [X] &= \sigma^2 \\
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
> \fbox{1}\Downarrow\quad &&                 c X + d &\mapsto \mathrm{No} (c \mu + d, c^2 \sigma^2) \\
> \fbox{2}\Downarrow\quad && \dfrac{X - \mu}{\sigma} &\mapsto \mathrm{No} (0, 1^2) \\
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

> ### $\Gamma$ 分布 $X \mapsto \mathrm{Ga_{mma}} (t, \lambda)$

> $$
> \begin{alignedat}{3}
>                                     p (x) &= \dfrac{\lambda}{\Gamma (t)} (\lambda x)^{t - 1} e^{- \lambda x} \quad\Leftarrow\quad x \in [0, +\infty) \\
>                                     C (x) &= \dfrac{\lambda}{\Gamma (t)} \int_0^x (\lambda x)^{t - 1} e^{- \lambda x} \mathrm{d} x \\
> \mathrm{Exp} [\mathrm{Ga} (t, \lambda)]^h &= \dfrac{\lambda}{\Gamma (t)} \int_0^{+\infty} x^h (\lambda x)^{t - 1} e^{- \lambda x} \mathrm{d} x \\
>                                           &= \dfrac{\Gamma (t + 1)}{\lambda \Gamma (t)} \dfrac{\lambda}{\Gamma (t + 1)} \int_0^{+\infty} x^{h - 1} (\lambda x)^t e^{- \lambda x} \mathrm{d} x \\
>                                           &= \dfrac{t}{\lambda} \mathrm{Exp} [\mathrm{Ga} (t + 1, \lambda)]^{h - 1} \\
>                        \mathrm{Exp} [X]^1 &= \dfrac{t}{\lambda} \\
>                        \mathrm{Exp} [X]^2 &= \dfrac{t (t + 1)}{\lambda^2} \\
>                          \mathrm{Var} [X] &= \dfrac{t}{\lambda^2} \\
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
>                                  p (x) &= \lambda e^{- \lambda x} \quad\Leftarrow\quad x \in [0, +\infty) \\
>                                  C (x) &= 1 - e^{- \lambda x} \\
> \mathrm{Exp} [\mathrm{Ex} (\lambda)]^h &= \mathrm{Exp} [\mathrm{Ga} (1, \lambda)]^h \\
>                     \mathrm{Exp} [X]^1 &= \dfrac{1}{\lambda} \\
>                     \mathrm{Exp} [X]^2 &= \dfrac{2}{\lambda^2} \\
>                       \mathrm{Var} [X] &= \dfrac{1}{\lambda^2} \\
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

> ### $\chi^2$ 分布 $X \mapsto \mathrm{Ch_i} (n) = \mathrm{Ga} (\frac{n}{2}, \frac{1}{2})$

> $$
> \begin{alignedat}{3}
>                            p (x) &= \dfrac{1}{2^\frac{n}{2} \Gamma (\frac{n}{2})} x^{\frac{n}{2} - 1} e^{- \frac{x}{2}} \quad\Leftarrow\quad x \in [0, +\infty) \\
>                            C (x) &= \dfrac{1}{2^\frac{n}{2} \Gamma (\frac{n}{2})} \int_0^x x^{\frac{n}{2} - 1} e^{- \frac{x}{2}} \quad\Leftarrow\quad x \in [0, +\infty) \mathrm{d} x \\
> \mathrm{Exp} [\mathrm{Ch} (n)]^h &= \mathrm{Exp} \left[ \mathrm{Ga} \left( \dfrac{n}{2}, \dfrac{1}{2} \right) \right]^h \\
>               \mathrm{Exp} [X]^1 &= n \\
>               \mathrm{Exp} [X]^2 &= n (n + 2) \\
>                 \mathrm{Var} [X] &= 2 n \\
> \end{alignedat}
> $$
>

> ### $\Beta$ 分布 $X \mapsto \mathrm{Be_{ta}} (t, s)$

> $$
> \begin{alignedat}{3}
>                               p (x) &= \dfrac{1}{\Beta (t, s)} x^{t - 1} (1 - x)^{s - 1} \quad\Leftarrow\quad x \in [0, 1] \\
>                               C (x) &= \dfrac{1}{\Beta (t, s)} \int_0^x x^{t - 1} (1 - x)^{s - 1} \mathrm{d} x \\
> \mathrm{Exp} [\mathrm{Be} (t, s)]^h &= \dfrac{1}{\Beta (t, s)} \int_0^1 x^h x^{t - 1} (1 - x)^{s - 1} \mathrm{d} x \\
>                                     &= \dfrac{1}{\Beta (t, s)} \Beta (h + t, s) \\
>                                     &= \dfrac{\Gamma (t + s)}{\Gamma (t)} \dfrac{\Gamma (t + h)}{\Gamma (t + s + h)} \\
>                  \mathrm{Exp} [X]^1 &= \dfrac{t}{t + s} \\
>                  \mathrm{Exp} [X]^2 &= \dfrac{t (t + 1)}{(t + s) (t + s + 1)} \\
>                    \mathrm{Var} [X] &= \dfrac{t s}{(t + s)^2 (t + s + 1)} \\
> \end{alignedat}
> $$
>

> ### 反正切分布 $X \mapsto \mathrm{A_{rc} T_{angent}} (\mu, \lambda)$

> $$
> \begin{alignedat}{3}
>                                       p (x) &= \dfrac{1}{\pi} \dfrac{\lambda}{\lambda^2 + (x - \mu)^2} \quad\Leftarrow\quad x \in (-\infty, +\infty) \\
>                                       C (x) &= \dfrac{1}{\pi} \left[ \arctan \left( \dfrac{x - \mu}{\lambda} \right) + \dfrac{\pi}{2} \right] \\
> \mathrm{Exp} |\mathrm{AT} (\mu, \lambda)^h| &= \dfrac{1}{\pi} \int_{-\infty}^{+\infty} |x^h| \dfrac{\lambda}{\lambda^2 + (x - \mu)^2} \mathrm{d} x \\
>                                             &\to +\infty \\
>                          \mathrm{Exp} [X]^1 &= \mathcal{Undef.} \\
>                          \mathrm{Exp} [X]^2 &= \mathcal{Undef.} \\
>                            \mathrm{Var} [X] &= \mathcal{Undef.} \\
> \end{alignedat}
> $$
>