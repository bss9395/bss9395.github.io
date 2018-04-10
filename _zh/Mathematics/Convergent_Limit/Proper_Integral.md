---
layout:    zh_post
Topic:     收敛极限
Title:     常义积分
Revised:   2018-04-11 03:40:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 常义积分的性质

> $$
> \begin{alignedat}{3}
> \fbox{0}\; && \int_\alpha^\alpha f (x) \mathrm{d} x = 0; &\quad \int_\alpha^\beta f (x) \mathrm{d} x = - \int_\beta^\alpha f (x) \mathrm{d} x \\
> \fbox{1}\; && \int_\alpha^\beta C \mathrm{d} x &= C (\alpha - \beta) \\
> \fbox{2}\; && \int_\alpha^\gamma f (x) \mathrm{d} x &= \int_\alpha^\beta f (x) \mathrm{d} x + \int_\beta^\gamma f (x) \mathrm{d} x \\
> \fbox{3}\; && \int_\alpha^\beta [\lambda f (x) + \mu g (x)] \mathrm{d} x &= \lambda \int_\alpha^\beta f (x) \mathrm{d} x + \mu \int_\alpha^\beta g (x) \mathrm{d} x \\
> \fbox{4}\; && f (x) \le g (x) \quad&\mathop{\Longrightarrow}_{f \equiv g}\quad \int_\alpha^\beta f (x) \mathrm{d} x \le \int_\alpha^\beta g (x) \mathrm{d} x \\
> \fbox{5}\; && \left\lvert \int_\alpha^\beta f (x) \mathrm{d} x \right\rvert &\le \int_\alpha^\beta \lvert f (x) \rvert \mathrm{d} x \\
>
> \end{alignedat}
> $$
>

> ### 积分中值定理

> $$
> \begin{alignedat}{3}
> \fbox{1}\; &&     \int_\alpha^\beta f (x) g^\updownarrow (x) \mathrm{d} x &= f (\xi) \int_\alpha^\beta g^\updownarrow (x) \mathrm{d} x \\
>            &&                        \int_\alpha^\beta f (x) \mathrm{d} x &= f (\xi) \cdot (\beta - \alpha)                                                              &&\;\Leftarrow\; g^\updownarrow (x) = 1 \\
> \fbox{2}\; && \int_\alpha^\beta \lambda^\downarrow (x) f (x) \mathrm{d} x &= \lambda (\alpha) \int_\alpha^\xi f (x) \mathrm{d} x                                         &&\;\Leftarrow\; \lambda^\downarrow (x) \ge 0 \\
>            &&     \int_\alpha^\beta g^\updownarrow (x) f (x) \mathrm{d} x &= g (\alpha) \int_\alpha^\xi f (x) \mathrm{d} x + g (\beta) \int_\xi^\beta f (x) \mathrm{d} x &&\;\Leftarrow\; \lambda^\downarrow (x) = \dfrac{g^\updownarrow (x) - g (b)}{g (a) - g (b)} \\
> \end{alignedat}
> $$
>