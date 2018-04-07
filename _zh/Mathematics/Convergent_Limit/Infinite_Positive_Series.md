---
layout:    zh_post
Topic:     收敛极限
Title:     无穷正项级数
Revised:   2018-04-07 18:46:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 正项级数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \sum^{+\infty} s_n \to \mathcal{Conv.} \Leftrightarrow \sum^n s_n < M \\
> \fbox{2}\; & \varliminf_{+\infty} \dfrac{s_{n + 1}}{s_n} \le \varliminf_{+\infty} \sqrt[n]{s_n} \le \varlimsup_{+\infty} \sqrt[n]{s_n} \le \varlimsup_{+\infty} \dfrac{s_{n + 1}}{s_n} \\
> \end{alignedat}
> $$
>

> ###  $s_n \le t_n$审敛法

> $$
> \begin{alignedat}{3}
> \Uparrow\;           &&                  \exists N \in \mathbb{N}; n > N &; s_n \le t_n \\
> \fbox{1}\Downarrow\; &&      \sum^{+\infty} s_n \to \mathcal{Conv.} \quad&\Leftarrow\quad \sum^{+\infty} t_n \to \mathcal{Conv.} \\
> \fbox{2}\Downarrow\; && \sum^{+\infty} s_n \not \to \mathcal{Conv.} \quad&\Rightarrow\quad \sum^{+\infty} t_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### $s_n \le t_n$审敛法的极限形式

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

> ### $\int^{+\infty} \mathrm{d} x$审敛法

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&                      f_\downarrow (\alpha + n + 1) \le f_\downarrow & (x) \le f_\downarrow (\alpha + n) \\
> \Downarrow\; &&    \int_\alpha^{+\infty} f_\downarrow (\alpha + n + 1) \mathrm{d} x &= \sum_0^{+\infty} \int_{\alpha + n}^{\alpha + n + 1} f_\downarrow (\alpha + n + 1) \mathrm{d} x \\
> \le\;        &&                 \int_\alpha^{+\infty} f_\downarrow (x) \mathrm{d} x &= \sum_0^{+\infty} \int_{\alpha + n}^{\alpha + n + 1} f_\downarrow (x) \mathrm{d} x \\
> \le\;        &&        \int_\alpha^{+\infty} f_\downarrow (\alpha + n) \mathrm{d} x &= \sum_0^{+\infty} \int_{\alpha + n}^{\alpha + n + 1} f_\downarrow (\alpha + n) \mathrm{d} x \\
> \Downarrow\; && \mathcal{Conv.} \gets \int^{+\infty} f_\downarrow (x) \mathcal{d} x &\Leftrightarrow \sum^{+\infty} f_\downarrow (\alpha + n) \to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### $\frac{s_{n + 1}}{s_n}$审敛法

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \exists N \in \mathbb{N}; n > N; \dfrac{s_{n + 1}}{s_n} \le q < 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \fbox{2}\; &&     \exists N \in \mathbb{N}; n > N; \dfrac{s_{n + 1}}{s_n} \gt 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### $\frac{s_{n + 1}}{s_n}$审敛法的极限形式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \varlimsup_{+\infty} \dfrac{s_{n + 1}}{s_n} < 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \fbox{2}\; &&   \varliminf_{+\infty} \dfrac{s_{n_1}}{s_n} > 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### $\sqrt[n]{s_n}$审敛法

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \exists N \in \mathbb{N}; n > N; \sqrt[n]{s_n} \le q < 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \fbox{2}\; &&     \exists N \in \mathbb{N}; n > N; \sqrt[n]{s_n} \ge 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### $\sqrt[n]{s_n}$审敛法的极限形式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \varlimsup_{+\infty} \sqrt[n]{s_n} < 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \fbox{2}\; && \varlimsup_{+\infty} \sqrt[n]{s_n} > 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### $q^n$审敛法的极限形式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; &&          \varlimsup_{+\infty} \sqrt[n]{s_n} < 1 \quad&\Rightarrow\quad \lim_{+\infty} \dfrac{s_n}{\langle q < 1 \rangle^n} \to 0 \\
> \fbox{2}\; && \varlimsup_{+\infty} \dfrac{s_{n + 1}}{s_n} < 1 \quad&\Rightarrow\quad \lim_{+\infty} \dfrac{s_n}{\langle q < 1 \rangle^n} \to 0 \\
> \end{alignedat}
> $$
>

> ### $n \cdot s_n$审敛法

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\; && \varlimsup_{+\infty} \dfrac{s_{n + 1}}{s_n} < 1 \quad&\Leftrightarrow\quad \varlimsup_{+\infty} \dfrac{(n + 1) \cdot s_{n + 1}}{n \cdot s_n} < 1 \\
> \fbox{2}\Uparrow\; &&          \varlimsup_{+\infty} \sqrt[n]{s_n} < 1 \quad&\Leftrightarrow\quad \varlimsup_{+\infty} \sqrt[n]{n \cdot s_n} < 1 \\
> \fbox{3}\Uparrow\; &&              \lim_{+\infty} \dfrac{s_n}{n \cdot s_n} &= \lim_{+\infty} \dfrac{1}{n} \to 0 \\
> \Downarrow\;       &&        \mathcal{Conv.} \gets \sum^{+\infty} s_n \quad&\Leftarrow\quad \sum^{+\infty} n \cdot s_n \to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### $\frac{1}{n^\alpha}$审敛法

> $$
> \begin{alignedat}{3}
> \Uparrow\;         &&                                    \exists N \in \mathbb{N}; n > N; s_n \le \dfrac{M}{n^{\langle \alpha > 1 \rangle}} \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \Uparrow\;         &&                            \exists N \in \mathbb{N}; n > N; M \ge n^\alpha \cdot s_n > (n + 1)^\alpha \cdot s_{n + 1} \quad&\Rightarrow\quad \dfrac{s_n}{s_{n + 1}} > \left( 1 + \dfrac{1}{n} \right)^\alpha  \\
> \Uparrow\;         && \exists N \in \mathbb{N}; n > N; \dfrac{s_n}{s_{n + 1}} \ge 1 + \dfrac{r}{n} > \left( 1 + \dfrac{1}{n} \right)^\alpha \quad&\Leftarrow\quad \lim_{+\infty} n \cdot \left[ \left( 1 + \dfrac{1}{n} \right)^\alpha - 1 \right] = \alpha < r \\
> \fbox{1}\Uparrow\; &&                                \exists N \in \mathbb{N}; n > N; n \left( \dfrac{s_n}{s_{n + 1}} - 1 \right) \ge r > 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \fbox{2}\Uparrow\; &&                                    \exists N \in \mathbb{N}; n > N; n \left( \dfrac{s_n}{s_{n + 1}} - 1 \right) \le 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### $\frac{1}{n^\alpha}$审敛法的极限形式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \varliminf_{+\infty} n \left( \dfrac{s_n}{s_{n + 1}} - 1 \right) > 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \fbox{2}\; && \varlimsup_{+\infty} n \left( \dfrac{s_n}{s_{n + 1}} - 1 \right) < 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### $\frac{1}{n \cdot \ln^\beta n}$审敛法

> $$
> \begin{alignedat}{3}
> \Uparrow\;         &&                                                                         \exists N \in \mathbb{N}; n > N; s_n \le \dfrac{M}{n \cdot \ln^{\langle \beta > 1 \rangle} n} \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \Uparrow\;         &&                                                \exists N \in \mathbb{N}; n > N; M \ge n \cdot \ln^\beta n \cdot s_n > (n + 1) \cdot \ln^\beta (n + 1) \cdot s_{n + 1} \quad&\Rightarrow\quad \dfrac{s_n}{s_{n + 1}} - \dfrac{n + 1}{n} \cdot \left[ \dfrac{\ln (n + 1)}{\ln n} \right]^\beta > 0 \\
> \Uparrow\;         && \exists N \in \mathbb{N}; n >\dfrac{s_n}{s_{n + 1}} = 1 + \dfrac{1}{n} + \dfrac{\langle r > \beta \rangle}{n \cdot \ln n} + o \left( \dfrac{1}{n \cdot \ln n} \right) \quad&\Leftarrow\quad \dfrac{\ln (n + 1)}{\ln n} = 1 + \dfrac{1}{\ln n} \cdot \left[ \dfrac{1}{n} + o \left( \dfrac{1}{n} \right) \right] \\ 
> \fbox{1}\Uparrow\; && \exists N \in \mathbb{N}; n > N; \dfrac{s_n}{s_{n + 1}} = 1 + \dfrac{1}{n} + \dfrac{\langle r > 1 \rangle}{n \cdot \ln n} + o \left( \dfrac{1}{n \cdot \ln n} \right) \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \fbox{2}\Uparrow\; &&  \exists N \in \mathbb{N}; n > N; \dfrac{s_n}{s_{n + 1}} = 1 + \dfrac{1}{n} + \dfrac{\langle r < 1 \rangle}{n \cdot \ln n} + o \left( \dfrac{1}{n \cdot \ln n} \right) \quad&\Rightarrow\quad \sum^{+\infty} s_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### $\frac{1}{n \cdot \ln^\beta n}$审敛法的极限形式

> $$
> \begin{alignedat}{3}
> \Uparrow\;           && \exists N \in \mathbb{N}; n > N; \dfrac{s_n}{s_{n + 1}} &= 1 + \dfrac{1}{n} + \dfrac{r_n}{n \cdot \ln n} + o \left( \dfrac{1}{n \cdot \ln n} \right) \\
> \fbox{1}\Downarrow\; &&                             \lim_{+\infty} r_n > 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \fbox{2}\Downarrow\; &&                             \lim_{+\infty} r_n < 1 \quad&\Rightarrow\quad \sum^{+\infty} s_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 构造性收敛正项级数

> $$
> \begin{alignedat}{3}
> \Uparrow\; &&                                                                               1 = \dfrac{s_n}{(S - S_{n - 1}) - (S - S_n)} \quad&\Leftarrow\quad 0 < s_n = S_n - S_{n - 1} \\
> \Uparrow\; && 0 \gets \lim_{+\infty} \dfrac{s_n \cdot \left( \sqrt{S - S_{n - 1}} + \sqrt{S - S_n} \right)}{(S - S_{n - 1}) - (S - S_n)} \quad&\Leftarrow\quad 0 \gets \lim_{+\infty} \sqrt{S - S_n} \\
> \Uparrow\; &&                                                                                    0 \gets \lim_{+\infty} \dfrac{s_n}{t_n} \quad&\Leftarrow\quad t_n = \sqrt{S - S_{n - 1}} - \sqrt{S - S_n} \\
> \Uparrow\; &&   0 \gets \lim_{+\infty} \dfrac{\widetilde{s}_n}{t_n} = \lim_{+\infty} \dfrac{\widetilde{s}_n}{s_n} \cdot \dfrac{s_n}{t_n} \quad&\Leftarrow\quad s_n = \left\lbrace\begin{alignedat}{3}
>                                                                                                                                                                                 s_n \quad&\Leftarrow\quad 0 < s_n \\
>                                                                                                                                                                      \dfrac{1}{2^n} \quad&\Leftarrow\quad 0 = \widetilde{s}_n \\
>                                                                                                                                                                      \end{alignedat}\right. \\
> \Uparrow\; &&                                                                           \widetilde{S} = \sum_1^{+\infty} \widetilde{s}_n \quad&\Leftrightarrow\quad \sum_1^{+\infty} \left\langle t_n = \sqrt{S - S_{n - 1}} - \sqrt{S - S_n} \right\rangle = \sqrt{S} \\
> \end{alignedat}
> $$
>

