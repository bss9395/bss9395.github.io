---
layout:    zh_post
Topic:     收敛极限
Title:     收敛极限中的反例
Revised:   2018-04-09 15:32:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 非一致收敛

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & F_n (x) = x^n                   &&= 1 + \sum_1^n \left[ x^n - x^{n - 1} \right]                                         &&\;\Leftarrow\; x \in (0, 1) \\
> \fbox{2}\; & F_n (x) = n e^{- n x}           &&= 0 + \sum_1^n \left[ n e^{- n x} - (n - 1) e^{- (n - 1) x} \right]                   &&\;\Leftarrow\; x \in (0, 1) \\
> \fbox{3}\; & F_n (x) = e^{- n^2 x^2}         &&= 1 + \sum_1^n \left[ e^{- n^2 x^2} - e^{- (n - 1)^2 x^2} \right]                     &&\;\Leftarrow\; x \in (0, 1) \\
> \fbox{4}\; & F_n (x) = 2 n^2 x e^{- n^2 x^2} &&= 0 + \sum_1^n \left[ 2 n^2 x e^{- n^2 x^2} - 2 (n - 1)^2 x e^{- (n - 1) x^2} \right] &&\;\Leftarrow\; x \in (0, 1) \\
> \end{alignedat}
> $$
>

> ### 绝对收敛且一致收敛非绝对一致收敛

> $$
> \begin{alignedat}{3}
> & \sum_1^n \dfrac{(- 1)^{n - 1}}{n} x^n \;\Leftarrow\; x \in (0, 1) \\
> & \sum_1^n \left\lvert \dfrac{(- 1)^{n - 1}}{n} x^n \right\rvert \to \mathcal{Conv.}; \sum_1^n \dfrac{(- 1)^{n - 1}}{n} x^n \rightrightarrows \mathcal{Conv.}; \sum_1^n \left\lvert \dfrac{(- 1)^{n - 1}}{n} x^n \right\rvert \to \not\rightrightarrows \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 发散的幂级数展开

> $$
> \begin{alignedat}{3}
> & f (x) = \sum_0^{+\infty} \dfrac{\sin 2^n x}{n !} = \sum_0^{+\infty} \dfrac{(- 1)^l e^{2^{2 l + 1}}}{(2 l + 1) !} x^{2 l + 1} \not\to \mathcal{Conv.} \quad\Leftarrow\quad \dfrac{s_{n + 1}}{s_n} \to +\infty \\
> & f^{(k)} (0) = \sum_0^{+\infty} \dfrac{(2^n)^k \sin \dfrac{k \pi}{2}}{n !} \xlongequal[]{k = 2 l + 1} \sum_0^{+\infty} \dfrac{(- 1)^l (2^{2 l + 1})^n}{n !} = (- 1)^l e^{2^{2 l + 1}} \\
> \end{alignedat}
> $$
>

> ### 非收敛于自身的幂级数展开

> $$
> \begin{alignedat}{3}
>       f (x) &= \left\lbrace\begin{alignedat}{3}
>                & 0                 &&\;\Leftarrow\; x \le 0 \\
>                & e^{- \frac{1}{x}} &&\;\Leftarrow\; x \gt 0 \\
>                \end{alignedat}\right. \\
> f^{(k)} (x) &= \left\lbrace\begin{alignedat}{3}
>                & 0                                                       &&\;\Leftarrow\; x \le 0 \\
>                & e^{- \frac{1}{x}} \cdot P_k \left( \dfrac{1}{x} \right) &&\;\Leftarrow\; x \gt 0 \\
>                \end{alignedat}\right. \\
> f^{(k)} (x) &= 0 \quad\Leftarrow\quad \lim_{0^+} \dfrac{f^{(k)} (x) - 0}{x - 0} \xlongequal{t = \frac{1}{x}} \lim_{+\infty} \dfrac{P_k (t)}{e^t} \to 0 \\
>       f (x) &\ne \sum_0^{+\infty} \dfrac{f^{(k)} (x)}{n !} x^n \\
> \end{alignedat}
> $$
>

> ![max-width:360px;](figures/Power_Series_not_Convergent_to_Itself.svg)

