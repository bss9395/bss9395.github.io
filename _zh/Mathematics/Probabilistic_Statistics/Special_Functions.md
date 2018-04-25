---
layout:    zh_post
Topic:     概率统计
Title:     特殊函数
Revised:   2018-04-26 00:41:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### $\Gamma$ 函数

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \Gamma (\langle t > 0 \rangle) = \int_0^{+\infty} x^{t - 1} e^{- x} \mathrm{d} x \\
> \fbox{2}\; & \Gamma (\langle t > 0 \rangle) = \lim_{+\infty} \dfrac{n^t \cdot n !}{\prod\limits_0^n (t + n)} \\
> \end{alignedat}
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
> \fbox{2}\; & \Gamma (t + 1) = \sqrt{2 \pi x} \left( \dfrac{x}{e} \right)^x e^{\frac{\langle 0 < \theta (x) < 1 \rangle}{12 x}} \\
> \fbox{2}\; & \Gamma (t) \cdot \Gamma (1 - t) = \dfrac{\pi}{\sin (t \pi)} &&\;\Rightarrow\; \Gamma (t) = \sqrt{\pi} \\
> \fbox{3}\; & \Gamma (2 t) = \dfrac{2^{2 t - 1}}{\sqrt{\pi}} \Gamma \left( t + \dfrac{1}{2} \right) \Gamma (t) \\
> \end{alignedat}
> $$
>

> ### $\Beta$ 函数

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \Beta (\langle t > 0 \rangle, \langle s > 0 \rangle) = \int_0^1 x^{t - 1} (1 - x)^{s - 1} \mathrm{d} x \\
> \fbox{2}\; & \Beta (\langle t > 0 \rangle, \langle s > 0 \rangle) = \dfrac{\Gamma (t) \cdot \Gamma (s)}{\Gamma (t + s)} \\
>
> \end{alignedat}
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
