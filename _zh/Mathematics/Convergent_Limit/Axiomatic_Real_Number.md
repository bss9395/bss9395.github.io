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