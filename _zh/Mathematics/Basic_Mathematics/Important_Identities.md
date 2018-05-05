---
layout:    zh_post
Topic:     基础数学
Title:     重要恒等式
Revised:   2018-05-06 00:50:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 等比恒等式

> $$
> \begin{alignedat}{3}
> 1 - x^n = (1 - x) \cdot \sum_0^{n - 1} x^n \\
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

> ### 级数和恒等式

> $$
> \begin{alignedat}{3}
> \sum_{m = m_0}^n \sum_{l = l_0}^m = \sum_{l = l_0}^n \sum_{m = l + m_0 - l_0}^n = \sum_{l = l_0}^n \sum_{m - m_0 \ge l - l_0} \\
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

> ### 组合恒等式

> $$
> \begin{alignedat}{3}
> k \mathcal{C}_n^k = k {n \choose k} = k \cdot \dfrac{n !}{k ! (n - k) !} = n \cdot \dfrac{(n - 1) !}{(k - 1) ! (n - k) !} = n {n - 1 \choose k - 1} = n \mathcal{C}_{n - 1}^{k - 1} \\
> \end{alignedat}
> $$
>