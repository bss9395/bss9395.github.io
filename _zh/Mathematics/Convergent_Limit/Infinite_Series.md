---
layout:    zh_post
Topic:     收敛极限
Title:     无穷级数
Revised:   2018-04-10 14:51:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 收敛级数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \forall \varepsilon > 0; \exists N \in \mathbb{N}; n > N \Rightarrow \left\lvert \sum_{n + 1}^{n + m} s_i \right\rvert < \varepsilon \\
> \fbox{2}\; & \lim_{+\infty} s_n \to 0 \\
> \fbox{3}\; & \sum^{+\infty} c \cdot s_n = c \sum^{+\infty} s_n \\
> \fbox{4}\; & \sum^{+\infty} (s_n \pm t_n) = \sum^{+\infty} s_n \pm \sum^{+\infty} t_n \\
> \fbox{5}\; & \sum_{n_1}^{+\infty} s_n \leftrightarrow \mathcal{Conv.} \Leftrightarrow \sum_{n_2}^{+\infty} s_n \leftrightarrow \mathcal{Conv.} \\
> \fbox{6}\; & \sum^{+\infty} s_n \to \mathcal{Conv.} \Rightarrow \sum^{+\infty} (s_{n_{i - 1}} + \cdots + s_{n_i}) \to \mathcal{Conv.} \\
> \fbox{7}\; & \sum^{+\infty} (s_{n_{i - 1}} + \cdots + \langle s_{n_i} \lessgtr 0 \rangle) \to \mathcal{Conv.} \Rightarrow \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

>### 列项相消法

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&          s_n &= \dfrac{1}{t_n (t_n + d) \cdots (t_n + m d)} \\
>              &&              &= \dfrac{1}{m d} \left[ \dfrac{1}{t_n \cdots [t_n + (m - 1) d]} - \dfrac{1}{(t_n + d) \cdots (t_n + m d)} \right] \\
> \Downarrow\; && \sum_1^n s_n &= \dfrac{1}{m d} \left[ \dfrac{1}{t_1 \cdots (t_1 + (m - 1) d)} - \dfrac{1}{(t_n + d) \cdots (t_n + m d)} \right] \\
> \end{alignedat}
> $$
>

> ### 分部求和法

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&                          \sum_{m + 1}^n s_n \cdot t_n &= \sum_{m + 1}^n (S_n - S_{n - 1}) \cdot t_n \\
>              &&                                                       &= S_n \cdot t_n + \sum_{m + 1}^{n - 1} S_n \cdot t_n - \sum_{m + 1}^{n - 1} S_n \cdot t_{n + 1} - S_m \cdot t_{m + 1} \\
>              &&                                                       &= S_n \cdot t_n - S_m \cdot t_{m + 1} + \sum_{m + 1}^{n - 1} S_n \cdot (t_n - t_{n + 1}) \\
> \Uparrow\;   &&                               \lvert S_n \rvert \le M &\land t_n \gtreqless t_{n + 1} \\
> \Downarrow\; && \left\lvert \sum_{m + 1}^n s_n \cdot t_n \right\rvert &\le \lvert S_n \rvert \cdot \lvert t_n \rvert + \lvert S_m \rvert \cdot \lvert t_{m + 1} \rvert + \sum_{m + 1}^{n - 1} \lvert S_n \rvert \cdot \lvert t_n - t_{n + 1} \rvert \\
>              &&                                                       &\le 2 M (\lvert t_{m + 1} \rvert + \lvert t_n \rvert) \\
> \end{alignedat}
> $$
>

> ### 优级数审敛法

> $$
> \begin{alignedat}{3}
> \Uparrow\;           & \forall \varepsilon \gt 0; \exists N \in \mathbb{N};     && \lvert s_n \rvert \le t_n; \\
> \fbox{1}\Downarrow\; & \sum^{+\infty} \lvert s_n \rvert \to \mathcal{Conv.}     &&\;\Leftarrow\; \sum^{+\infty} t_n \to \mathcal{Conv.} \\
> \fbox{2}\Downarrow\; & \sum^{+\infty} \lvert s_n \rvert \not\to \mathcal{Conv.} &&\;\Rightarrow\; \sum^{+\infty} t_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 优级数审敛法的极限形式

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\; &&    0 \le \varlimsup_{+\infty} \dfrac{\lvert s_n \rvert}{t_n} &\lt +\infty \\
> \Downarrow\;       &&     \mathcal{Conv.} \gets \sum^{+\infty} \lvert s_n \rvert \;&\Leftarrow\; \sum^{+\infty} t_n \to \mathcal{Conv.} \\
> \fbox{2}\Uparrow\; &&    0 \lt \varliminf_{+\infty} \dfrac{t_n}{\lvert s_n \rvert} &\le +\infty \\
> \Downarrow\;       && \mathcal{Conv.} \not\gets \sum^{+\infty} \lvert s_n \rvert \;&\Rightarrow\; \sum^{+\infty} t_n \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 分部审敛法

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\; &&                              \lvert S_n \rvert \le M \land t^\updownarrow_n \to 0 \quad&\Rightarrow\quad \left\lvert \sum_{N + 1}^{N + m} s_n \cdot t_n \right\rvert \le 2 (2 M) (\lvert t_{N + 1} \rvert + \lvert t_{N + m} \rvert) \to 0 \\
> \fbox{2}\Uparrow\; && \sum^{+\infty} s_n \to \mathcal{Conv.} \land \lvert t^\updownarrow_n \rvert \le M \quad&\Rightarrow\quad \left\lvert \sum_{N + 1}^{N + m} s_n \cdot t_n \right\rvert \le 2 \varepsilon (M + M) \to 0 \\
> \Downarrow\;       &&         \left\lvert \sum^{+\infty} s_n \cdot t_n \right\rvert \to \mathcal{Conv.} \quad& \\
> \end{alignedat}
> $$
>

> ### 交错审敛法

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \sum^{+\infty} (- 1)^n \cdot s_n = S \quad\Leftarrow\quad \langle s^{\downarrow}_n \ge 0 \rangle \to 0 \\
> \fbox{2}\; & S_{2 n + 2} \ge S_{2 n} \\
> \fbox{3}\; & S_{2 n + 1} \le S_{2 n - 1} \\
> \fbox{4}\; & \lvert S_n - S \rvert \le s_{n + 1} \\
> \end{alignedat}
> $$
>

> ### 对数审敛法

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \sum^{+\infty} \ln (1 + \lvert s_n \rvert) \to \mathcal{Conv.} \quad\Leftrightarrow\quad \sum^{+\infty} \lvert s_n \rvert \to \mathcal{Conv.} \quad\Leftrightarrow\quad \sum_N^{+\infty} \lvert \ln (1 + s_n) \rvert \mathop{\to}_{s_n \ne -1} \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 绝对收敛级数的性质

> $$
> \begin{alignedat}{3}
> \Uparrow\;           & \exists N \in \mathbb{N}; n > N; \left\lvert \sum_{n + 1}^{n + m} s_n \right\rvert \le \sum_{n + 1}^{n + m} \lvert s_n \rvert \lt \varepsilon \\
> \fbox{1}\Downarrow\; & \sum^{+\infty} \lvert s_n \rvert \to \mathcal{Conv.} \quad\Rightarrow\quad \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \Uparrow\;           & \sum^{+\infty} \lvert s_n \rvert = \sum^{+\infty} s_n^+ + \sum^{+\infty} s_n^- \\
> \fbox{2}\Downarrow\; & \sum^{+\infty} \lvert s_n \rvert \to \mathcal{Conv.} \quad\Leftrightarrow\quad \sum^{+\infty} s_n^+ \to \mathcal{Conv.} \land \sum^{+\infty} s_n^- \to \mathcal{Conv.} \\
> \Uparrow\;           & \sum^{+\infty} s_m^+ \le \sum^{+\infty} s_n^+ \land \sum^{+\infty} s_n^+ \le \sum^{+\infty} s_m^+ \\
> \fbox{3}\Downarrow\; & \sum^{+\infty} s_m^+ = \sum^{+\infty} s_n^+ \quad\Rightarrow\quad \sum^{+\infty} s_m = \sum^{+\infty} s_n \\
> \end{alignedat}
> $$
>

> ### 条件收敛级数的性质

> $$
> \begin{alignedat}{3}
>                      & \sum^{+\infty} \lvert s_n \rvert \not\to \mathcal{Conv.} \land \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \Uparrow\;           & \sum^{+\infty} s_n = \sum^{+\infty} s_n^+ - \sum^{+\infty} s_n^- \\
> \fbox{1}\Downarrow\; & \sum^{+\infty} s_n^+ \to +\infty \land \sum^{+\infty} s_n^- \to +\infty \\
> \fbox{2}\Downarrow\; & \sum^{+\infty} s_m = S \\
> \fbox{3}\Downarrow\; & \sum^{+\infty} s_m = \pm \infty \\
> \fbox{4}\Downarrow\; & \sum^{+\infty} s_m \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>