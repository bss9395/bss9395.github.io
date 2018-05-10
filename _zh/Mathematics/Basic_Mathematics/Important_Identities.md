---
layout:    zh_post
Topic:     基础数学
Title:     重要恒等式
Revised:   2018-05-10 20:11:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 等比恒等式

> $$
> \begin{alignedat}{3}
> y^{n + 1} - x^{n + 1} &= (y - x) \cdot \sum_{i = 0}^n y^{n - i} x^i  \\
>               1 - x^n &= (1 - x) \cdot \sum_{i = 0}^{n - 1} x^i \\
> \end{alignedat}
> $$
>

> ### 周期恒等式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \int_{- x}^x f (x) \mathrm{d} x \xlongequal{x = - t} 0                               &&\;\Leftarrow\; f (- x) = - f (x) \\
> \fbox{2}\; & \int_{- x}^x f (x) \mathrm{d} x \xlongequal{x = - t} 2 \int_0^x f (x) \mathrm{d} x   &&\;\Leftarrow\; f (- x) = f (x) \\
> \fbox{3}\; & \int_x^{x + T} f (x) \mathrm{d} x \xlongequal{x = t + T} \int_0^T f (x) \mathrm{d} x &&\;\Leftarrow\; f (x + T) = f (x) \\
> \end{alignedat}
> $$
>

> ### 级数恒等式

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \sum_{i = m}^n \sum_{j = m}^i = \sum_{j = m}^n \sum_{i = j}^n \\
> \fbox{2}\quad & \int_\alpha^\beta \int_\alpha^y \mathrm{d} x \mathrm{d} y = \int_\alpha^\beta \int_x^\beta \mathrm{d} y \mathrm{d} x \\
> \fbox{3}\quad & \left( \sum_{i = 0}^n c_i x^i \right) \cdot \left( \sum_{j = 0}^m d_j x^j \right) = \sum_{l = 0}^{n + m} \left( \sum_{k = 0}^l c_k d_{l - k} \right) x^l \\
> \end{alignedat}
> $$
>

> ### 三角恒等式

> $$
> \begin{alignedat}{3}
> \arctan x + \arctan y = \arctan \left( \dfrac{u + v}{1 - u  \cdot v} \right) \mod \pi \\
> \end{alignedat}
> $$
>

> ### 复数恒等式

> $$
> \begin{array}{l|l|l}
> \fbox{0}\; & \imath = - \dfrac{1}{\imath} \\
> \fbox{1}\; & e^{\imath x} = \cos x + \imath \sin x                   & e^{\imath \pi} + 1 = 0 \\
> \fbox{2}\; & (\cos x + \imath \sin x)^r = \cos r x + \imath \sin r x & (\cos x + \imath \sin x)^n = \cos n x + \imath \sin n x \\
> \fbox{3}\; & \cos x = \dfrac{1}{2} (e^{\imath x} + e^{- \imath x})   & \sin x = \dfrac{1}{2 \imath} (e^{\imath x} - e^{- \imath x}) & \tan x = \dfrac{e^{- \imath x} - e^{\imath x}}{e^{- \imath x} + e^{\imath x}} \\
> \end{array}
> $$
>

> ### 阶乘恒等式

> $$
> \begin{alignedat}{3}
> n ! = \sqrt{2 \pi n} \left( \dfrac{n}{e} \right)^n \cdot e^\frac{\langle 0 \lt \theta (n) \lt 1 \rangle}{12 n} \\
> \end{alignedat}
> $$
>

> ### 概率恒等式

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad &&   \int_0^{+\infty} P (Y \ge y) \mathrm{d} y &= \int_0^{+\infty} x \cdot p_Y (x) \mathrm{d} x \\
> \fbox{2}\quad && \int_0^{+\infty} P (Y \lt - y) \mathrm{d} y &= - \int_{-\infty}^0 x \cdot p_Y (x) \mathrm{d} x \\
> \end{alignedat}
> $$
>

