---
layout:    zh_post
Topic:     概率统计
Title:     概率统计中的反例
Revised:   2018-05-31 23:48:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 矩母函数不能唯一确定分布函数

> 考察如下分布函数 $F (x)$，其密度函数为：
> 
> $$
> p (x) = k e^{- \alpha x^\lambda} \quad\Leftarrow\quad x \in (0, +\infty) 
> $$
> 
> 其中 $\alpha >0, 0 < \lambda < \frac{1}{2}$，而常数 $k$ 由正则性条件决定。
>
> 记 $\beta = \alpha \tan \lambda \pi$，考察如下函数
> 
> $$
> g (x) = k e^{- \alpha x^\lambda} [1 + \varepsilon \sin (\beta x^\lambda)] \quad\Leftarrow\quad |\varepsilon| < 1, x \in (0, +\infty)
> $$
> 
> 显然 $g (x) \ge 0$。为了说明 $g (x)$ 是密度函数，且其 $n$ 阶矩与 $F$ 的 $n$ 阶矩相等，关键是要验证如下等式成立。
> 
> $$
> \int_0^{+\infty} x^n e^{- \alpha x^\lambda} \sin \beta x^\lambda \mathrm{d} x = 0 \quad\Leftarrow\quad \forall n \ge 0
> $$
> 
> 为此我们利用如下积分等式：对 $p > 0$ 和复数 $q$ 的实部 $\mathrm{Re} q > 0$，有：
> 
> $$
> \int_0^{+\infty} t^{p - 1} e^{- q t} \mathrm{d} t = \dfrac{\Gamma (p)}{q^p}
> $$
> 
> 若在上式中取 $p = \dfrac{(n + 1)}{\lambda}, q = \alpha + \imath \beta, t = x^\lambda$，则上式可改写为：
> 
> $$
> \int_0^{+\infty} x^{\lambda \left( \frac{n + 1}{\lambda} - 1 \right)} e^{- (\alpha + \imath \beta) x^\lambda} \lambda x^{\lambda - 1} \mathrm{d} x = \dfrac{1}{(\alpha + \imath \beta)^{\frac{n + 1}{\lambda}}} \Gamma \left( \dfrac{n + 1}{\lambda} \right) 
> $$
> 
> 上式右端的分母为：
> 
> $$
> \begin{alignedat}{3}
> (\alpha + \imath \beta)^\frac{n + 1}{\lambda} &= (\alpha + \imath \alpha \tan \lambda \pi)^\frac{n + 1}{\lambda} \\
>                                               &= \alpha^\frac{n + 1}{\lambda} (1 + \imath \tan \lambda \pi)^\frac{n + 1}{\lambda} \\
>                                               &= \alpha^\frac{n + 1}{\lambda} (\cos \lambda \pi)^{- \frac{n + 1}{\lambda}} (\cos \lambda \pi + \imath \sin \lambda \pi)^\frac{n + 1}{\lambda} \\
>                                               &= \alpha^\frac{n + 1}{\lambda} (\cos \lambda \pi)^{- \frac{n + 1}{\lambda}} e^{\imath (n + 1) \pi} \\
>                                               &= \alpha^\frac{n + 1}{\lambda} (\cos \lambda \pi)^{- \frac{n + 1}{\lambda}} [\cos (n + 1) \pi + \imath \sin (n + 1) \pi] \\
>                                               &= \alpha^\frac{n + 1}{\lambda} (\cos \lambda \pi)^{- \frac{n + 1}{\lambda}} \cos (n + 1) \pi \\
> \end{alignedat}
> $$
> 
> 其中 $\sin (n + 1) \pi = 0$，最后结果表明：上式右端是实的。
>
> 另一方面，上式左端可化简为：
> 
> $$
> \lambda \int_0^{+\infty} x^n e^{- (\alpha + \imath \beta) x^\lambda} \mathrm{d} x = \lambda \int_0^{+\infty} x^n e^{- \alpha x^\lambda} \cos \beta x^\lambda \mathrm{d} x - \imath \lambda \int_0^{+\infty} x^n e^{- \alpha x^\lambda} \sin \beta x^\lambda \mathrm{d} x
> $$
> 
> 由于上式右端只有实部，故左端的虚部必为 $0$，这就表明等式成立。故取 $g (x)$ 为分布函数 $G (x)$ 的密度函数，那么 $F$ 与 $G$ 的一切阶矩都相等，但其分布不同。