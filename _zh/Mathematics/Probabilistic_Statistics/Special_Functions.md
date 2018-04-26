---
layout:    zh_post
Topic:     概率统计
Title:     特殊函数
Revised:   2018-04-27 00:05:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### $\Gamma$ 函数

> $$
> 0 < t \implies
> \left\lbrace\begin{alignedat}{3}
> \fbox{1}\; & \Gamma (t) = \int_0^{+\infty} x^{t - 1} e^{- x} \mathrm{d} x \\
> \fbox{2}\; & \Gamma (t) = \lim_{+\infty} \dfrac{n^t \cdot n !}{\prod\limits_0^n (t + n)} \\
> \end{alignedat}\right.
> $$
>

> ![max-width:360px;](figures/Gamma_Function.svg)

> ### $\Gamma$ 函数的唯一性

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \Gamma (t) \ge 0, \Gamma (1) = 1 \\
> \fbox{2}\; & \Gamma (t + 1) = t \Gamma (t) \\
> \fbox{3}\; & \ln \Gamma \left( \dfrac{t_p}{p} + \dfrac{t_q}{q} \right) \le \dfrac{1}{p} \ln \Gamma (t_p) + \dfrac{1}{q} \ln \Gamma (t_q) &&\;\Leftarrow \dfrac{1}{p} + \dfrac{1}{q} = 1 \\
> \end{alignedat}
> $$
>

> ### $\Gamma$ 函数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \Gamma (t + 1) = \prod_0^n (t - n) \cdot \Gamma (t - n) &&\;\Rightarrow\; \Gamma (n + 1) = n ! \\
> \fbox{2}\; & \Gamma (t + 1) = \sqrt{2 \pi t} \left( \dfrac{t}{e} \right)^t e^{\frac{\langle 0 < \theta (t) < 1 \rangle}{12 t}} \\
> \fbox{2}\; & \Gamma (t) \cdot \Gamma (1 - t) = \dfrac{\pi}{\sin (t \pi)} &&\;\Rightarrow\; \Gamma \left( \dfrac{1}{2} \right) = \sqrt{\pi} \\
> \fbox{3}\; & \Gamma (2 t) = \dfrac{2^{2 t - 1}}{\sqrt{\pi}} \Gamma \left( t + \dfrac{1}{2} \right) \Gamma (t) \\
> \end{alignedat}
> $$
>

> ### $\Beta$ 函数

> $$
> 0 < t, 0 < s \implies
> \left\lbrace\begin{alignedat}{3}
> \fbox{1}\; & \Beta (t, s) = \int_0^1 x^{t - 1} (1 - x)^{s - 1} \mathrm{d} x \\
> \fbox{2}\; & \Beta (t, s) = \dfrac{\Gamma (t) \cdot \Gamma (s)}{\Gamma (t + s)} \\
> \fbox{3}\; & \Beta (t, s) \xlongequal{y = \frac{x}{1 - x}} \int_0^{+\infty} \dfrac{y^{t - 1}}{(1 + y)^{t + s}} \mathrm{d} y \\
> \fbox{4}\; & \Beta (t, s) \xlongequal{z = \frac{1}{y}} \int_0^1 \dfrac{y^{t - 1} + y^{s - 1}}{(1 + y)^{t + s}} \mathrm{d} y \\
> \fbox{5}\; & \Beta (t, s) \xlongequal{x = \sin^2 \theta} 2 \int_0^\frac{\pi}{2} \sin^{2 t - 1} \theta \cos^{2 s - 1} \theta \mathrm{d} \theta \\
> \fbox{6}\; & \Beta (t, s) \xlongequal{x = \cos^2 \theta} 2 \int_0^\frac{\pi}{2} \cos ^{2 t - 1} \theta \sin^{2 s - 1} \theta \mathrm{d} \theta \\
> \end{alignedat}\right.
> $$
>

> ### $\Beta$ 函数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \Beta (t, s) = \Beta (s, t) \\
> \fbox{2}\; & \Beta (t + 1, s) = \dfrac{t}{t + s} \Beta (t, s) \\
> \fbox{3}\; & \Beta (t + 1, s + 1) = \dfrac{t \cdot s}{(t + s + 1) \cdot (t + s)} \Beta (t, s) \\
> \end{alignedat}
> $$
>
