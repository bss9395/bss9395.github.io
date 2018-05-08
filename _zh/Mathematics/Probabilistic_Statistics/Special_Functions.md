---
layout:    zh_post
Topic:     概率统计
Title:     特殊函数
Revised:   2018-05-08 17:59:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 误差函数

> $$
> \begin{alignedat}{3}
> \mathrm{Err_{or}} (x) &= \dfrac{1}{\sqrt{\pi}} \int_{- x}^x e^{- x^2} \mathrm{d} x \\
> &= \dfrac{2}{\sqrt{\pi}} \int_0^x e^{- x^2} \mathrm{d} x \\
> \end{alignedat}
> $$
>

> ### $\Gamma (\langle t > 0 \rangle)$ 函数

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \Gamma (t) = \int_0^{+\infty} x^{t - 1} e^{- x} \mathrm{d} x \\
> \fbox{2}\quad & \Gamma (t) = \lim_{+\infty} \dfrac{n^t \cdot n !}{\prod\limits_0^n (t + n)} \\
> \fbox{3}\quad & \Gamma (t) = \dfrac{1}{t} \prod_1^{+\infty} \dfrac{\left( 1 + \dfrac{1}{n} \right)^t}{1 + \dfrac{t}{n}} \\
> \end{alignedat}
> $$
>

> ![max-width:360px;](figures/Gamma_Function.svg)

> ### $\Gamma$ 函数的唯一性

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \Gamma (t) \ge 0, \Gamma (1) = 1 \\
> \fbox{2}\quad & \Gamma (t + 1) = t \Gamma (t) \\
> \fbox{3}\quad & \ln \Gamma \left( \dfrac{t_p}{p} + \dfrac{t_q}{q} \right) \le \dfrac{1}{p} \ln \Gamma (t_p) + \dfrac{1}{q} \ln \Gamma (t_q) &&\quad\Leftarrow\quad \dfrac{1}{p} + \dfrac{1}{q} = 1 \\
> \end{alignedat}
> $$
>

> ### $\Gamma$ 函数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \Gamma (t + 1) = \prod_0^n (t - n) \cdot \Gamma (t - n)                                                           &&\quad\Rightarrow\quad \Gamma (n + 1) = n ! \\
> \fbox{2}\quad & \Gamma (t + 1) = \sqrt{2 \pi t} \left( \dfrac{t}{e} \right)^t e^{\frac{\langle 0 < \theta (t) < 1 \rangle}{12 t}} \\
> \fbox{2}\quad & \Gamma (t) \cdot \Gamma (1 - t) = \dfrac{\pi}{\sin (t \pi)}                                                       &&\quad\Rightarrow\quad \Gamma \left( \dfrac{1}{2} \right) = \sqrt{\pi} \\
> \fbox{3}\quad & \Gamma (2 t) = \dfrac{2^{2 t - 1}}{\sqrt{\pi}} \Gamma \left( t + \dfrac{1}{2} \right) \Gamma (t) \\
> \end{alignedat}
> $$
>

> ### $\Beta (\langle t > 0, s > 0 \rangle)$ 函数

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \Beta (t, s) = \int_0^1 x^{t - 1} (1 - x)^{s - 1} \mathrm{d} x \\
> \fbox{2}\quad & \Beta (t, s) = \dfrac{\Gamma (t) \cdot \Gamma (s)}{\Gamma (t + s)} \\
> \fbox{3}\quad & \Beta (t, s) \xlongequal{y = \frac{x}{1 - x}} \int_0^{+\infty} \dfrac{y^{t - 1}}{(1 + y)^{t + s}} \mathrm{d} y \\
> \fbox{4}\quad & \Beta (t, s) \xlongequal{z = \frac{1}{y}} \int_0^1 \dfrac{y^{t - 1} + y^{s - 1}}{(1 + y)^{t + s}} \mathrm{d} y \\
> \fbox{5}\quad & \Beta (t, s) \xlongequal{x = \sin^2 \theta} 2 \int_0^\frac{\pi}{2} \sin^{2 t - 1} \theta \cos^{2 s - 1} \theta \mathrm{d} \theta \\
> \fbox{6}\quad & \Beta (t, s) \xlongequal{x = \cos^2 \theta} 2 \int_0^\frac{\pi}{2} \cos ^{2 t - 1} \theta \sin^{2 s - 1} \theta \mathrm{d} \theta \\
> \end{alignedat}
> $$
>

> ### $\Beta$ 函数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \Beta (1, s) = \dfrac{1}{s} \\
> \fbox{2}\quad & \Beta (t, s) = \Beta (s, t) \\
> \fbox{3}\quad & \Beta (t, t) \xlongequal{\frac{1}{2} - x = \frac{1}{2} \sqrt{y}} \dfrac{1}{2^{2 t - 1}} \Beta \left( \dfrac{1}{2}, t \right) \\
> \fbox{4}\quad & \Beta (t, 1 - t) = \dfrac{\pi}{\sin \pi t}  \\
> \fbox{5}\quad & \Beta (t, s + 1) = \dfrac{s}{t + s} \Beta (t, s) \\
> \fbox{6}\quad & \Beta (t, n) = \dfrac{(n - 1) !}{\prod\limits_1^{n} (t + n - 1)} \\
> \fbox{7}\quad & \Beta (t + 1, s + 1) = \dfrac{t \cdot s}{(t + s + 1) \cdot (t + s)} \Beta (t, s) \\
> \end{alignedat}
> $$
>
