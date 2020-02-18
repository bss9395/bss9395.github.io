---
layout:    zh_post
Topic:     收敛极限
Title:     反常积分
Revised:   2018-04-12 01:10:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 反常积分

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \int_{-\infty}^{+\infty} f (x) \mathrm{d} x &= \lim_{u \to -\infty} \int_u^\xi f (x) \mathrm{d} x + \lim_{v \to +\infty} \int_\xi^v f (x) \mathrm{d} x \\
>            &&                                             &= \left[ F (\xi) - \lim_{u \to -\infty} F (u) \right] + \left[ \lim_{v \to +\infty} F (v) - F (\xi) \right] \\
>            &&                                             &= F (+\infty) - F (-\infty) \\
> \fbox{2}\; &&        \int_\alpha^\beta f (x) \mathrm{d} x &= \lim_{u \to \xi^-} \int_\alpha^u f (x) \mathrm{d} x + \lim_{v \to \xi^+} \int_v^\beta f (x) \mathrm{d} x \quad&&\Leftarrow\quad f (\xi) = \infty \\ 
>            &&                                             &= \left[ \lim_{u \to \xi^-} F (u) - F (\alpha) \right] + \left[ F (\beta) - \lim_{v \to \xi^+} F (v) \right] \\
>            &&                                             &= F (\beta) - F (\xi^+) + F (\xi^-) - F (\alpha) \\
> \fbox{3}\; &&    \int_\alpha^{+\infty} f (x) \mathrm{d} x &= \lim_{v \to +\infty} \int_\xi^v f (x) \mathrm{d} x + \lim_{u \to \alpha^+} \int_u^\xi f (x) \mathrm{d} x \quad&&\Leftarrow\quad f (\alpha) = \infty \\
>            &&                                             &= \left[ \lim_{v \to +\infty} F (v) - F (\xi) \right] + \left[ F (\xi) - \lim_{u \to \alpha^+} F (u) \right] \\
>            &&                                             &= F (+\infty) - F (\alpha^+) \\
> \fbox{4}\; &&              \int_\alpha^\gamma f (x) \mathrm{d} x &\xlongequal{t = \frac{1}{x - \alpha}} \int_{\frac{1}{\gamma - \alpha}}^{+\infty} f \left( \alpha + \dfrac{1}{t} \right) \cdot \dfrac{1}{t^2} \mathrm{d} t \xlongequal{t = \frac{\gamma - \alpha}{x - \alpha}} \int_1^{+\infty} f \left( \alpha + \dfrac{\gamma - \alpha}{t} \right) \cdot \dfrac{1}{t^2} \mathrm{d} t \\
> \end{alignedat}
> $$
>

> ### 反常积分的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \int^{+\infty} f (x) \mathrm{d} x \to \mathcal{Conv.} &\;\land\; f (x) \ge 0 \;\not\Rightarrow\; \lim_{+\infty} f (x) \to 0 \\
> \fbox{2}\; && \int^{+\infty} f (x) \mathrm{d} x \to \mathcal{Conv.} &\;\land\; \lim_{+\infty} f (x) \to \mathcal{Conv.} \;\Rightarrow\; \lim_{+\infty} f (x) \to 0 \\
> \fbox{3}\; && \int^{+\infty} f (x) \mathrm{d} x \to \mathcal{Conv.} &\;\land\; f (x) \rightrightarrows \mathcal{Conti.} \;\Rightarrow\; \lim_{+\infty} f (x) \to 0 \\
> \end{alignedat}
> $$
>

> ### 优函数审敛法

> $$
> \begin{alignedat}{3}
> \Uparrow\;           &&                                                              \lvert f (x) \rvert &\le g (x) \\
> \fbox{1}\Downarrow\; &&                   \int_\alpha^{+\infty} g (x) \mathrm{d} x \to \mathcal{Conv.} \;&\Rightarrow\; \int_\alpha^{+\infty} \lvert f (x) \rvert \mathrm{d} x \to \mathcal{Conv.} \\
> \fbox{2}\Downarrow\; && \int_\alpha^{+\infty} \lvert f (x) \rvert \mathrm{d} x \not\to \mathcal{Conv.} \;&\Rightarrow\; \int_\alpha^{+\infty} g (x) \mathrm{d} x \to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 优函数审敛法的极限形式

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\; &&                    0 \le \varlimsup_\mathcal{B} \dfrac{\lvert f (x) \rvert}{g (x)} &\lt +\infty \\
> \Downarrow\;       &&     \mathcal{Conv.} \gets \int_\alpha^{+\infty} \lvert f (x) \rvert \mathrm{d} x \;&\Leftarrow\; \int_\alpha^{+\infty} g (x) \mathrm{d} x \to \mathcal{Conv.} \\
> \fbox{2}\Uparrow\; &&                    0 \lt \varliminf_\mathcal{B} \dfrac{g (x)}{\lvert f (x) \rvert} &\le +\infty \\
> \Downarrow\;       && \mathcal{Conv.} \not\gets \int_\alpha^{+\infty} \lvert f (x) \rvert \mathrm{d} x \;&\Rightarrow\; \int_\alpha^{+\infty} g (x) \mathrm{d} x \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 调和审敛法

> $$
> \begin{alignedat}{3}
> \fbox{1}\; &&            \lvert f (x) \rvert \le \dfrac{1}{x^{\langle p \gt 1 \rangle}} \;&\Rightarrow\; \int^{+\infty} \lvert f (x) \rvert \mathrm{d} x \to \mathcal{Conv.} \\
> \fbox{2}\; &&            \lvert f (x) \rvert \ge \dfrac{1}{x^{\langle p \le 1 \rangle}} \;&\Rightarrow\; \int^{+\infty} \lvert f (x) \rvert \mathrm{d} x \not\to \mathcal{Conv.} \\
> \fbox{3}\; && \lvert f (x) \rvert \le \dfrac{1}{(x - \alpha)^{\langle p \lt 1 \rangle}} \;&\Rightarrow\; \int_\alpha \lvert f (x) \rvert \mathrm{d} x \to \mathcal{Conv.} \\
> \fbox{4}\; && \lvert f (x) \rvert \ge \dfrac{1}{(x - \alpha)^{\langle p \ge 1 \rangle}} \;&\Rightarrow\; \int_\alpha \lvert f (x) \rvert \mathrm{d} x \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 调和审敛法的极限形式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; &&                        0 \le \varlimsup_{+\infty} x^{\langle p \gt 1 \rangle} \cdot \lvert f (x) \rvert \lt +\infty \;&\Rightarrow\; \int^{+\infty} \lvert f (x) \rvert \mathrm{d} x \to \mathcal{Conv.} \\
> \fbox{2}\; &&             0 \lt \varliminf_{+\infty} \dfrac{1}{x^{\langle p \le 1 \rangle} \cdot \lvert f (x) \rvert} \le +\infty \;&\Rightarrow\; \int^{+\infty} \lvert f (x) \rvert \mathrm{d} x \not\to \mathcal{Conv.} \\
> \fbox{3}\; &&            0 \le \varlimsup_{\alpha^+} (x - \alpha)^{\langle p \lt 1 \rangle} \cdot \lvert f (x) \rvert \lt +\infty \;&\Rightarrow\; \int_\alpha \lvert f (x) \rvert \mathrm{d} x \to \mathcal{Conv.} \\
> \fbox{4}\; && 0 \lt \varliminf_{\alpha^+} \dfrac{1}{(x - \alpha)^{\langle p \ge 1 \rangle} \cdot \lvert f (x) \rvert} \le +\infty \;&\Rightarrow\; \int_\alpha \lvert f (x) \rvert \mathrm{d} x \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 分部审敛法

> $$
> \begin{alignedat}{3}
> \Uparrow\;         &&                                         \left\lvert \int_u^v \lambda^\updownarrow (x) f (x) \mathrm{d} x \right\rvert &\le \lvert \lambda (u) \rvert \cdot \left\lvert \int_u^\xi f (x) \mathrm{d} x  \right\rvert + \lvert \lambda (v) \rvert \cdot \left\lvert \int_\xi^v f (x) \mathrm{d} x \right\rvert \\
> \fbox{1}\Uparrow\; &&                 \lambda^\updownarrow (x) \to 0 \;\land\; \left\lvert \int_s^t f (x) \mathrm{d} x \right\rvert \le M \;&\Rightarrow\; \left\lvert \int_u^v \lambda^\updownarrow (x) f (x) \mathrm{d} x \right\rvert \le \varepsilon \cdot 2M + \varepsilon \cdot 2 M \to 0 \\
> \fbox{2}\Uparrow\; && \lvert \lambda^\updownarrow (x) \rvert \le M \;\land\; \int_\alpha^{+\infty} f (x) \mathrm{d} x \to \mathcal{Conv.} \;&\Rightarrow\; \left\lvert \int_u^v \lambda^\updownarrow (x) f (x) \mathrm{d} x \right\rvert \le M \cdot \varepsilon + M \cdot \varepsilon \to 0 \\
> \Downarrow\;       &&                                                     \int_\alpha^{+\infty} \lambda^\updownarrow (x) f (x) \mathrm{d} x &\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

