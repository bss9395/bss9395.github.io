---
layout:    zh_post
Topic:     基础数学
Title:     特殊符号
Revised:   2018-04-21 00:05:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 数列符号

> $$
> \begin{alignedat}{3}
> s_n^+ &= \left\lbrace\begin{alignedat}{3}
>          + s_n \quad&\Leftarrow\quad s_n \ge 0 \\
>              0 \quad&\Leftarrow\quad s_n \lt 0 \\
>          \end{alignedat}\right. \\
> s_n^- &= \left\lbrace\begin{alignedat}{3}
>              0 \quad&\Leftarrow\quad s_n \ge 0 \\
>          - s_n \quad&\Leftarrow\quad s_n \lt 0 \\
>          \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### 取整符号

> $$
> \begin{alignedat}{3}
>   \lceil x \rceil &:= \min \lbrace z \in \mathbb{Z} \mid x \le z \rbrace \\
> \lfloor x \rfloor &:= \max \lbrace z \in \mathbb{Z} \mid z \le x \rbrace \\
>                 x &:= [x] + \lbrace x \rbrace \\ 
> \end{alignedat}
> $$
>

> ### 渐近符号

> $$
> \begin{alignedat}{3}
> f \mathop{=}\limits_\mathcal{B} o (g) &\iff \lim_\mathcal{B} \dfrac{f (x)}{g (x)} = 0 \\
> f \mathop{=}\limits_\mathcal{B} O (g) &\iff \left\lvert \lim_\mathcal{B} \dfrac{f (x)}{g (x)} \right\rvert \le \mathcal{Const.} \\
> f \mathop{\sim}\limits_\mathcal{B} g &\iff \lim_\mathcal{B} \dfrac{f (x)}{g (x)} = 1 \\ 
> \end{alignedat}
> $$
>

> ### $\Vert$符号

> $$
> \begin{alignedat}{3}
> \lVert {^m x} \rVert &= \sqrt{\langle {^m x}, {^m x} \rangle} \\
> \lvert {^1 x} \rvert &= \left\lbrace\begin{alignedat}{3}
>                         - {^1 x} &\quad\Leftarrow\quad {^1 x} \le {^1 0} \\
>                         + {^1 x} &\quad\Leftarrow\quad {^1 0} \le {^1 x} \\                  
>                         \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### $!$符号

> $$
> \begin{alignedat}{3}
>          n ! &:= \prod_1^n n \\
>     (2 n) !! &:= \prod_1^n (2 n) = 2^n n ! \\
> (2 n - 1) !! &:= \prod_1^n (2 n - 1) \\
> \end{alignedat}
> $$
>

> ### $\delta^{i j}$符号

> $$
> \begin{alignedat}{3}
> \delta^{i j} = \left\lbrace\begin{alignedat}{3}
>                0 &\quad\Leftarrow\quad i \ne j \\
>                1 &\quad\Leftarrow\quad i = j \\
>                \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### $\mathop{\rm{sgn}}$符号

> $$
> \begin{alignedat}{3}
> \mathop{\rm{sgn}} x &= \left\lbrace\begin{alignedat}{3}
>                        - 1 &\quad\Leftarrow\quad x \lt 0 \\
>                        0   &\quad\Leftarrow\quad x = 0 \\
>                        + 1 &\quad\Leftarrow\quad x \gt 0 \\
>                        \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### $\mathcal{D}$符号

> $$
> \begin{alignedat}{3}
> \mathcal{D} (x) &= \left\lbrace\begin{alignedat}{3}
>                    0 &\quad\Leftarrow\quad x \notin \mathbb{Q} \\
>                    1 &\quad\Leftarrow\quad x \in \mathbb{Q} \\
>                    \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### $\chi_C$符号

> $$
> \begin{alignedat}{3}
> \chi_C (x) = \left\lbrace\begin{alignedat}{3}
>                 0 &\quad\Leftarrow\quad x \notin C \\
>                 1 &\quad\Leftarrow\quad x \in C \\
>                 \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### $\mathcal{R}$符号

> $$
> \begin{alignedat}{3}
> \mathcal{R} (x) = \left\lbrace\begin{alignedat}{3}
>                              0 &\quad\Leftarrow\quad x \notin \mathbb{Q} \\
>                   \dfrac{1}{n} &\quad\Leftarrow\quad \left( \dfrac{z \in \mathbb{Z}}{n \in \mathbb{N}} = x \in \mathbb{Q} \right) \land (\gcd (\lvert z \rvert, n) = 1) \\
>                   \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### $\mathrm{lcm}$符号

> $$
> \begin{alignedat}{3}
> \mathrm{lcm} := \mathrm{\mathbf{l}_{owest} \mathbf{c}_{ommon} \mathbf{m}_{ultiple}} \\
> \end{alignedat}
> $$
>

> ### $\gcd$符号

> $$
> \begin{alignedat}{3}
> \gcd := \mathrm{\mathbf{g}_{reatest} \mathbf{c}_{ommon} \mathbf{d}_{ivisor}} \\
> \end{alignedat}
> $$
>

> ### 特殊符号之间的联系

> $$
> \begin{alignedat}{3}
> \fbox{1}\; &&             \mathcal{D} &\equiv \mathrm{sgn} (\mathcal{R} (x)) \\
> \fbox{2}\; && \lvert x \cdot y \rvert &\equiv \mathrm{lcm} (x, y) \cdot  \gcd (x, y) \\
> \end{alignedat}
> $$
>

> ### 多项式符号

> $$
> \begin{alignedat}{3}
>        \mathcal{P} (n, x) &= \sum_0^n \alpha_n x^n \\
>        \mathcal{T} (n, x) &= \Alpha + \sum_1^{n} (\alpha_n \cos n x + \beta_n \sin n x) \\
> \mathcal{T}^{\cos} (n, x) &= \Alpha + \sum_1^n \alpha_n \cos n x \\
> \mathcal{T}^{\sin} (n, x) &= \Alpha + \sum_1^n \beta_n \sin n x \\
> \end{alignedat}
> $$
>