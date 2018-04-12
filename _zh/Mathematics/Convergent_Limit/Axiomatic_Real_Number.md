---
layout:    zh_post
Topic:     收敛极限
Title:     公理化实数系
Revised:   2017-09-21 23:09:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 加法群公理

> $$
> \begin{array}{lll}
> 1_+ & \exists 0 \in \mathbb{R}; \forall x \in \mathbb{R};    & 0 + x = x \\
> 2_+ & \forall x \in \mathbb{R}; \exists (-x) \in \mathbb{R}; & x + (-x) = 0 \\
> 3_+ & \forall x, y, z \in \mathbb{R};                        & x + (y + z) = (x + y) + z \\
> 4_+ & \forall x, y \in \mathbb{R};                           & x + y = y + z \\
> \end{array}
> $$
>

> ### 乘法域公理

> $$
> \begin{array}{lll}
> 1_\times     & \exists 1 \in \mathbb{R_{-0}}; \forall x \in \mathbb{R};           & x \times 1 = x \\
> 2_\times     & \forall x \in \mathbb{R_{-0}}; \exists x^{-1} \in \mathbb{R_{-0}}; & x \times x^{-1} = 1 \\
> 3_\times     & \forall x, y, z \in \mathbb{R};                                    & x \times (y \times z) = (x \times y) \times z \\
> 4_\times     & \forall x, y \in \mathbb{R};                                       & x \times y = y \times x \\
> 5_{+ \times} & \forall x, y, z \in \mathbb{R};                                    & (x + y) \times z = x \times z + y \times z \\
> \end{array}
> $$
>

> ### 线性序公理

> $$
> \begin{array}{lll}
> 1_\le          & \forall x \in \mathbb{R};       & x \le x \\
> 2_\le          & \forall x, y \in \mathbb{R};    & (x \le y) \land (y \le x) \implies (x = y) \\
> 3_\le          & \forall x, y, z \in \mathbb{R}; & (x \le y) \land (y \le z) \implies (x \le z) \\
> 4_\le          & \forall x, y \in \mathbb{R};    & (x \le y) \lor (y \le x) \\
> 5_{\le +}      & \forall x, y, z \in \mathbb{R}; & (x \le y) \implies (x + z) \le (y + z) \\
> 6_{\le \times} & \forall x, y \in \mathbb{R};    & (0 \le x) \land (0 \le y) \implies (0 \le x \times y) \\
> \end{array}
> $$
>

> ### 连续性公理

> $$
> \begin{array}{ll}
> 1_r & \forall X \subset \mathbb{R}; \forall Y \subset \mathbb{R}; (\forall x \in X; \forall y \in Y; (x \le y) \implies \exists r \in \mathbb{R}; \forall x \in X; \forall y \in Y; (x \le r \le y)) \\
> \end{array}
> $$
>

> ### 连续性命题的等价性

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad && & s_n \le M \implies \exists! \sup \lbrace s_n \rbrace \\
> \fbox{2}\quad && & \mathop{s_n \le s_m}\limits_{(n \lt m)} \implies \exists! \lim s_n \\
> \fbox{3}\quad && & \mathop{ {\LARGE\supset} [s_n, t_n]}\limits_{\lvert t_n - s_n \rvert \to 0} \implies \exists! r \in \bigcap \lbrace[s_n, t_n] \rbrace \\
> \fbox{4}\quad && & [s, t] \subset \bigcup \lbrace (s_n, t_n) \rbrace \implies [s, t] \subset \bigcup^{\exists N} \lbrace (s_n, t_n) \rbrace \\
> \fbox{5}\quad && & \lvert s_{+ \infty} \rvert \le M \implies \exists \lim s_n \\
> \fbox{6}\quad && & \lvert s_n \rvert \le M \implies \exists \lim s_{n_i} \\
> \fbox{7}\quad && & \lvert s_{n \ge N} - s_{n + m} \rvert \le \varepsilon \implies \exists! \lim s_n \\
> \end{alignedat}
> $$
>