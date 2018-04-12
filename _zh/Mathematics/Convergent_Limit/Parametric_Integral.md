---
layout:    zh_post
Topic:     收敛极限
Title:     参变量积分
Revised:   2018-04-12 02:34:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 参变量积分的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & f (x, u), \alpha (u), \beta (u) \to \mathcal{Conti.} \quad\Rightarrow\quad \int_{\alpha (u)}^{\beta (u)} f (x, u) \mathrm{d} x \to \mathcal{Conti.} \\
> \fbox{2}\; & \dfrac{\mathrm{d}}{\mathrm{d} u} \int_{\alpha (u)}^{\beta (u)} f (x, u) \mathrm{d} x = \int_{\alpha (u)}^{\beta (u)} \dfrac{\mathrm{d}}{\mathrm{d} u} f (x, u) \mathrm{d} x + \int_{\alpha (u)}^{\frac{\mathrm{d}}{\mathrm{d} u} \beta (u)} f (x, u) \mathrm{d} x - \int_{\frac{\mathrm{d}}{\mathrm{d} u} \alpha (u)}^{\beta (u)} f (x, u) \mathrm{d} x \\
> \end{alignedat}
> $$
>

> ### 一致收敛

> $$
> \begin{alignedat}{3}
> \fbox{1}\; &&               \int^{+\infty} f (x, u) \mathrm{d} x \to \mathcal{Conv.} &:= \forall \varepsilon > 0; \exists \Alpha (\varepsilon, u); \Alpha (\varepsilon, u) < A \implies \left\lvert \int_A^{+\infty} f (x, u) \mathrm{d} x \right\rvert \lt \varepsilon \\
> \fbox{2}\; &&                  \int_\alpha f (x, u) \mathrm{d} x \to \mathcal{Conv.} &:= \forall \varepsilon > 0; \exists \Alpha (\varepsilon, u); \Alpha (\varepsilon, u) > a \implies \left\lvert \int_\alpha^a f (x, u) \mathrm{d} x \right\rvert \lt \varepsilon \\
> \fbox{3}\; && \int^{+\infty} f (x, u) \mathrm{d} x \rightrightarrows \mathcal{Conv.} &:= \forall \varepsilon > 0; \exists \Alpha (\varepsilon); \Alpha (\varepsilon) < A \implies \left\lvert \int_A^{+\infty} f (x, u) \mathrm{d} x \right\rvert \lt \varepsilon \\
> \fbox{4}\; &&    \int_\alpha f (x, u) \mathrm{d} x \rightrightarrows \mathcal{Conv.} &:= \forall \varepsilon > 0; \exists \Alpha (\varepsilon); \Alpha (\varepsilon) > a \implies \left\lvert \int_\alpha^a f (x, u) \mathrm{d} x \right\rvert \lt \varepsilon \\
> \fbox{5}\; && \int^{+\infty} f (x, u) \mathrm{d} x \rightrightarrows \mathcal{Conv.} &\Leftrightarrow \lim_{+\infty} \sup_{u} \left\lvert \int_A^{+\infty} f (x, u) \mathrm{d} x \right\rvert \to 0 \\
>            &&                                                                        &\Leftrightarrow \left\lvert \int_A^B f (x, u) \mathrm{d} x \right\rvert \lt \varepsilon \\
> \end{alignedat}
> $$
>

> ### 优函数审敛法

> $$
> \begin{alignedat}{3}
> \Uparrow\; && \lvert f (x, u) \rvert \le g (x, u) \\
> \fbox{1}\Downarrow\; && \int_\alpha^{+\infty} g (x, u) \mathrm{d} x \rightrightarrows \mathcal{Conv.} \;&\Rightarrow\; \int_\alpha^{+\infty} \lvert f (x, u) \rvert \mathrm{d} x \rightrightarrows \mathcal{Conv.} \\
> \fbox{2}\Downarrow\; && \int_\alpha^{+\infty} \lvert f (x, u) \rvert \mathrm{d} x \not\rightrightarrows \mathcal{Conv.} \;&\Rightarrow\; \int_\alpha^{+\infty} g (x, u) \mathrm{d} x \\
> \end{alignedat}
> $$
>

> ### 优函数审敛法的极限形式

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\; && 0 \le \varlimsup_\mathcal{B} \dfrac{\lvert f (x, u) \rvert}{g (x, u)} &\lt +\infty \\
> \Downarrow\; && \mathcal{Conv.} \leftleftarrows \int_\alpha^{+\infty} \lvert f (x, u) \rvert \mathrm{d} x \;&\Leftarrow\; \int_\alpha^{+\infty} g (x, u) \mathrm{d} x \rightrightarrows \mathcal{Conv.} \\
> \fbox{2}\Uparrow\; &&                    0 \lt \varliminf_\mathcal{B} \dfrac{g (x, u)}{\lvert f (x, u) \rvert} &\le +\infty \\
> \Downarrow\;       && \mathcal{Conv.} \not\gets \int_\alpha^{+\infty} \lvert f (x, u) \rvert \mathrm{d} x \;&\Rightarrow\; \int_\alpha^{+\infty} g (x, u) \mathrm{d} x \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 分部审敛法

> $$
> \begin{alignedat}{3}
> \Uparrow\;         &&                                         \left\lvert \int_a^b \lambda^\updownarrow (x, u) f (x, u) \mathrm{d} x \right\rvert &\le \lvert \lambda (a, u) \rvert \cdot \left\lvert \int_a^\xi f (x, u) \mathrm{d} x  \right\rvert + \lvert \lambda (b, u) \rvert \cdot \left\lvert \int_\xi^b f (x) \mathrm{d} x \right\rvert \\
> \fbox{1}\Uparrow\; &&                 \lambda^\updownarrow (x, u) \rightrightarrows 0 \;\land\; \left\lvert \int_s^t f (x, u) \mathrm{d} x \right\rvert \le M \;&\Rightarrow\; \left\lvert \int_a^b \lambda^\updownarrow (x, u) f (x, u) \mathrm{d} x \right\rvert \le \varepsilon \cdot 2M + \varepsilon \cdot 2 M \to 0 \\
> \fbox{2}\Uparrow\; && \lvert \lambda^\updownarrow (x, u) \rvert \le M \;\land\; \int_\alpha^{+\infty} f (x, u) \mathrm{d} x \rightrightarrows \mathcal{Conv.} \;&\Rightarrow\; \left\lvert \int_a^b \lambda^\updownarrow (x, u) f (x, u) \mathrm{d} x \right\rvert \le M \cdot \varepsilon + M \cdot \varepsilon \to 0 \\
> \Downarrow\;       &&                                                     \int_\alpha^{+\infty} \lambda^\updownarrow (x) f (x) \mathrm{d} x &\rightrightarrows \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

