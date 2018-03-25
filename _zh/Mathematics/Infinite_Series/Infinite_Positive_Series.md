---
layout:    zh_post
Topic:     无穷级数
Title:     无穷正项级数
Revised:   2018-03-25 21:05:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 正项级数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & s_n \ge 0 \Rightarrow \left\langle \sum^{+\infty} s_n \to \mathcal{Conv.} \Leftrightarrow \sum^n s_n < M \right\rangle \\
> \fbox{2}\; & \varliminf_{+\infty} \dfrac{s_{n + 1}}{s_n} \le \varliminf_{+\infty} \sqrt[n]{s_n} \le \varlimsup_{+\infty} \sqrt[n]{s_n} \le \varlimsup_{+\infty} \dfrac{s_{n + 1}}{s_n} \\
> \end{alignedat}
> $$
>

> ###  比较判别法

> $$
> \begin{alignedat}{3}
> \Uparrow\;           && \exists N \in \mathbb{N}; n > N &\Rightarrow s_n \le t_n \\
> \fbox{1}\Downarrow\; && \sum^{+\infty} s_n \to \mathcal{Conv.} \quad&\Leftarrow\quad \sum^{+\infty} t_n \to \mathcal{Conv.} \\
> \fbox{2}\Downarrow\; && \sum^{+\infty} s_n \not \to \mathcal{Conv.} \quad&\Rightarrow\quad \sum^{+\infty} t_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 比较判别法的极限形式

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\; &&                   \lim_{+\infty} \dfrac{s_n}{t_n} &= l \\
> \Downarrow\;       &&     \mathcal{Conv.} \gets \sum^{+\infty} s_n \quad&\Leftrightarrow\quad \sum^{+\infty} t_n \to \mathcal{Conv.} \\
> \fbox{2}\Uparrow\; &&                   \lim_{+\infty} \dfrac{s_n}{t_n} &\to 0 \\
> \Downarrow\;       &&     \mathcal{Conv.} \gets \sum^{+\infty} s_n \quad&\Leftarrow\quad \sum^{+\infty} t_n \to \mathcal{Conv.} \\
> \fbox{3}\Uparrow\; &&                   \lim_{+\infty} \dfrac{s_n}{t_n} &\to +\infty \\
> \Downarrow\;       && \mathcal{Conv.} \not\gets \sum^{+\infty} s_n \quad&\Rightarrow\quad \sum^{+\infty} t_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 积分判别法

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&                      f_\downarrow (\alpha + n + 1) \le f_\downarrow & (x) \le f_\downarrow (\alpha + n) \\
> \Downarrow\; &&               \int_\alpha^{+\infty} f (\alpha + n + 1) \mathrm{d} x &= \sum_0^{+\infty} \int_{\alpha + n}^{\alpha + n + 1} f (\alpha + n + 1) \mathrm{d} x \\
> \le\;        &&                            \int_\alpha^{+\infty} f (x) \mathrm{d} x &= \sum_0^{+\infty} \int_{\alpha + n}^{\alpha + n + 1} f (x) \mathrm{d} x \\
> \le\;        &&                   \int_\alpha^{+\infty} f (\alpha + n) \mathrm{d} x &= \sum_0^{+\infty} \int_{\alpha + n}^{\alpha + n + 1} f (\alpha + n) \mathrm{d} x \\
> \Downarrow\; && \mathcal{Conv.} \gets \int^{+\infty} f_\downarrow (x) \mathcal{d} x &\Leftrightarrow \sum^{+\infty} f_\downarrow (\alpha + n) \to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 比值判别法

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \exists N \in \mathbb{N}; n > N; \dfrac{s_{n + 1}}{s_n} \le q < 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \fbox{2}\; &&     \exists N \in \mathbb{N}; n > N; \dfrac{s_{n + 1}}{s_n} \gt 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 比值判别法的极限形式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \varlimsup_{+\infty} \dfrac{s_{n + 1}}{s_n} < 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \fbox{2}\; &&   \varliminf_{+\infty} \dfrac{s_{n_1}}{s_n} > 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 根值判别法

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \exists N \in \mathbb{N}; n > N; \sqrt[n]{s_n} \le q < 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \fbox{2}\; &&     \exists N \in \mathbb{N}; n > N; \sqrt[n]{s_n} \ge 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 根值判别法的极限形式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \varlimsup_{+\infty} \sqrt[n]{s_n} < 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \fbox{2}\; && \varlimsup_{+\infty} \sqrt[n]{s_n} > 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 等比判别法

> $$
> \begin{alignedat}{3}
> \fbox{1}\; &&          \varlimsup_{+\infty} \sqrt[n]{s_n} < 1 \quad&\Rightarrow\quad \lim_{+\infty} \dfrac{s_n}{\langle r < 1 \rangle^n} \to 0 \\
> \fbox{2}\; && \varlimsup_{+\infty} \dfrac{s_{n + 1}}{s_n} < 1 \quad&\Rightarrow\quad \lim_{+\infty} \dfrac{s_n}{\langle r < 1 \rangle^n} \to 0 \\
> \end{alignedat}
> $$
>

> ### $\frac{1}{n^\alpha}$判别法

> $$
> \begin{alignedat}{3}
>
> \end{alignedat}
> $$
>

