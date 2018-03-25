---
layout:    zh_post
Topic:     无穷级数
Title:     无穷级数
Revised:   2018-03-25 18:02:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 级数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \forall \varepsilon > 0; \exists N \in \mathbb{N}; n > N \Rightarrow \left\lvert \sum_{n + 1}^{n + m} s_i \right\rvert < \varepsilon \\
> \fbox{2}\; & \lim_{+\infty} s_n \to 0 \\
> \fbox{3}\; & \sum^{+\infty} c \cdot s_n = c \sum^{+\infty} s_n \\
> \fbox{4}\; & \sum^{+\infty} (s_n \pm t_n) = \sum^{+\infty} s_n \pm \sum^{+\infty} t_n \\
> \fbox{5}\; & \sum_{n_1}^{+\infty} s_n \leftrightarrow \mathcal{Conv.} \Leftrightarrow \sum_{n_2}^{+\infty} s_n \leftrightarrow \mathcal{Conv.} \\
> \fbox{6}\; & \sum^{+\infty} s_n \to \mathcal{Conv.} \Rightarrow \sum^{+\infty} (s_{n_{i - 1}} + \cdots + s_{n_i}) \to \mathcal{Conv.} \\
> \fbox{7}\; & \sum^{+\infty} (s_{n_{i - 1}} + \cdots + \langle s_{n_i} \lessgtr 0 \rangle) \to \mathcal{Conv.} \Rightarrow \sum^{+\infty} \to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

>### 列项相消法

> $$
> \begin{alignedat}{3}
> s_n &= \dfrac{1}{\alpha (\alpha + d) \cdots (\alpha + m d)} \\
> &= \dfrac{1}{m d} \left[ \dfrac{1}{\alpha \cdots [\alpha + (m - 1) d]} - \dfrac{1}{(\alpha + d) \cdots (\alpha + m d)} \right] \\
> &= t_n - t_{n + 1} \quad\Leftarrow\quad t_n = \dfrac{1}{\alpha \cdots [\alpha + (m - 1) d]} \\
> \end{alignedat}
> $$
>
