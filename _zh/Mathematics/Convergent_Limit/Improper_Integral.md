---
layout:    zh_post
Topic:     收敛极限
Title:     广义积分
Revised:   2018-04-10 01:18:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 反常积分的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \int_{-\infty}^{+\infty} f (x) \mathrm{d} x &= \lim_{v \to -\infty} \int_v^\alpha f (x) \mathrm{d} x + \lim_{u \to +\infty} \int_\alpha^u f (x) \mathrm{d} x \\
>            &&                                             &= \left[ F (\alpha) - \lim_{v \to -\infty} F (v) \right] + \left[ \lim_{u \to +\infty} F (u) - F (\alpha) \right] \\
>            &&                                             &= F (+\infty) - F (-\infty) \\
> \fbox{2}\; &&        \int_\alpha^\beta f (x) \mathrm{d} x &= \lim_{v \to \gamma^-} \int_\alpha^v f (x) \mathrm{d} x + \lim_{u \to \gamma^+} \int_u^\beta f (x) \mathrm{d} x \quad&&\Leftarrow\quad f (\gamma) = \infty \\ 
>            &&                                             &= \left[ \lim_{v \to \gamma^-} F (v) - F (\alpha) \right] + \left[ F (\beta) - \lim_{u \to \gamma^+} F (u) \right] \\
>            &&                                             &= F (\beta) - F (\gamma^+) + F (\gamma^-) - F (\alpha) \\
> \fbox{2}\; &&       \int \lvert f (x) \rvert \mathrm{d} x &\to \mathcal{Conv.} \;\Rightarrow\; \int f (x) \mathrm{d} x \to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 优积分审敛法

> $$
> \begin{alignedat}{3}
> \Uparrow\;           &&                                                              \lvert f (x) \rvert &\le g (x) \\
> \fbox{1}\Downarrow\; &&                   \int_\alpha^{+\infty} g (x) \mathrm{d} x \to \mathcal{Conv.} \;&\Rightarrow\; \int_\alpha^{+\infty} \lvert f (x) \rvert \mathrm{d} x \to \mathcal{Conv.} \\
> \fbox{2}\Downarrow\; && \int_\alpha^{+\infty} \lvert f (x) \rvert \mathrm{d} x \not\to \mathcal{Conv.} \;&\Rightarrow\; \int_\alpha^{+\infty} g (x) \mathrm{d} x \to \mathrm{Conv.} \\
> \end{alignedat}
> $$
>

> ### 优积分审敛法的极限形式

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\; &&                      0 \lt \varliminf_{+\infty} \dfrac{\lvert f (x) \rvert}{g (x)} &\le \varlimsup_{+\infty} \dfrac{\lvert f (x) \rvert}{g (x)} \lt +\infty \\
> \Downarrow\;       &&     \mathcal{Conv.} \gets \int_\alpha^{+\infty} \lvert f (x) \rvert \mathrm{d} x \;&\Leftrightarrow\; \int_\alpha^{+\infty} g (x) \mathrm{d} x \to \mathcal{Conv.} \\
> \fbox{2}\Uparrow\; &&                                  \lim_{+\infty} \dfrac{\lvert f (x) \rvert}{g (x)} &\to 0 \\
> \Downarrow\;       &&     \mathcal{Conv.} \gets \int_\alpha^{+\infty} \lvert f (x) \rvert \mathrm{d} x \;&\Leftarrow\; \int_\alpha^{+\infty} g (x) \mathrm{d} x \to \mathcal{Conv.} \\
> \fbox{3}\Uparrow\; &&                                  \lim_{+\infty} \dfrac{\lvert f (x) \rvert}{g (x)} &\to +\infty \\
> \Downarrow\;       && \mathcal{Conv.} \not\gets \int_\alpha^{+\infty} \lvert f (x) \rvert \mathrm{d} x \;&\Rightarrow\; \int_\alpha^{+\infty} g (x) \mathrm{d} x \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### $\frac{1}{x^p}$ 审敛法

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \lvert f (x) \rvert \le \dfrac{1}{x^{\langle p \gt 1 \rangle}} \;&&\Rightarrow\; \int_\alpha^{+\infty} \lvert f (x) \rvert \mathrm{d} x \to \mathcal{Conv.} \\
> \fbox{2}\; & \lvert f (x) \rvert \ge \dfrac{1}{x^{\langle p \le 1 \rangle}} \;&&\Rightarrow\; \int_\alpha^{+\infty} \lvert f (x) \rvert \mathrm{d} x \not\to \mathcal{Conv.}
> \end{alignedat}
> $$
>

> ### $\frac{1}{x^p}$ 审敛法的极限形式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; &&            0 \le \varlimsup_{+\infty} x^{\langle p \gt 1 \rangle} \lvert f (x) \rvert \lt +\infty \;&\Rightarrow\; \int_\alpha^{+\infty} \lvert f (x) \rvert \mathrm{d} x \to \mathcal{Conv.} \\
> \fbox{2}\; && 0 \lt \varliminf_{+\infty} \dfrac{1}{x^{\langle p \le 1 \rangle} \lvert f (x) \rvert} \le +\infty \;&\Rightarrow\; \int_\alpha^{+\infty} \lvert f (x) \rvert \mathrm{d} x \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 