---
layout:    zh_post
Topic:     概率统计
Title:     重要估算公式
Revised:   2018-04-26 19:07:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 阶乘估算公式

> $$
> \begin{alignedat}{3}
> \Uparrow\;           & \ln \dfrac{1 + t}{1 - t} = 2 t \cdot \left[ 1 + \sum_1^{+\infty} \dfrac{t^{2 m}}{2 m + 1} \right] \quad\Leftarrow\quad t \in (- 1, + 1) \\
> \Downarrow\;         & 1 < \ln \left( \dfrac{1 + t}{1 - t} \right)^\frac{1}{2 t} < 1 + \dfrac{1}{3} \sum_1^{+\infty} t^{2 m} = 1 + \dfrac{t^2}{3 (1 - t^2)} \\
> \Uparrow\;           & \dfrac{1 + t}{1 - t}\equiv \dfrac{x + 1}{x} \quad\Rightarrow\quad x = \dfrac{1 - t}{2 t} \not\in [-1, 0] \\
> \Downarrow\;         & e < \left( \dfrac{x + 1}{x} \right)^{\frac{1}{2} + x} < e^{1 + \frac{1}{12} (\frac{1}{x} - \frac{1}{x + 1})} \\
> \Downarrow\;         & 1 < \dfrac{f (x + 1)}{f (x)} \equiv \left. \dfrac{(x + 1)^{\frac{1}{2} + x + 1}}{e^{x + 1} \cdot \Gamma (x + 2)} \middle/ \dfrac{x^{\frac{1}{2} + x}}{e^x \cdot \Gamma (x + 1)} \right. < \left. e^{\frac{1}{12 x}} \middle/ e^{\frac{1}{12 (x + 1)}} \right. \quad\Rightarrow\quad f (x) = \dfrac{x^{\frac{1}{2} + x}}{e^x \cdot \Gamma (x + 1)} \\
> \Downarrow\;         & 0 < f (x) < f (x + 1) \quad\land\quad 0 < f (x + 1) \cdot e^{\frac{1}{12 (x + 1)}} < f (x) \cdot e^{\frac{1}{12 x}} \\
> \Downarrow\;         & f (x) < f (+\infty) = f (x) \cdot e^{\frac{\langle 0 < \theta (x) < 1 \rangle}{12 x}}  < f (x) \cdot e^{\frac{1}{12 x}} \\
> \Downarrow\;         & \Gamma (x + 1) = \dfrac{\sqrt{x}}{f (+\infty)} \left( \dfrac{x}{e} \right)^x \cdot  e^{\frac{\theta (x)}{12 x}} \quad\Rightarrow\quad \Gamma (n + 1) = n ! = \dfrac{\sqrt{n}}{f (+\infty)} \left( \dfrac{n}{e} \right)^n \cdot e^{\frac{\theta (n)}{12 n}} \\
> \Uparrow\;           & \dfrac{\pi}{2} = \lim_{+\infty} \dfrac{1}{2 n + 1} \left[ \dfrac{(2 n) !!}{(2 n - 1) !!} \right]^2 = \lim_{+\infty} \dfrac{1}{2 n + 1} \left[ \dfrac{(2^n \cdot n !)^2}{(2 n) !} \right]^2 \\
> \Downarrow\;         & \dfrac{\pi}{2} = \lim_{+\infty} \dfrac{1}{2 n + 1} \dfrac{n}{2 f^2 (+\infty)} e^{\frac{4 \theta (n) - \theta (2 n)}{12 n}} \quad\Rightarrow\quad f (+\infty) = \dfrac{1}{\sqrt{2 \pi}} \\
> \fbox{1}\Downarrow\; & \Gamma (x + 1) = \sqrt{2 \pi x} \left( \dfrac{x}{e} \right)^x \cdot e^{\frac{\langle 0 < \theta (x) < 1 \rangle}{12 x}} \\
> \fbox{2}\Downarrow\; &\Gamma (n + 1) = n ! = \sqrt{2 \pi n} \left( \dfrac{n}{e} \right)^n \cdot e^{\frac{\langle 0 < \theta (n) < 1 \rangle}{12 n}} \\
> \end{alignedat}
> $$
>

