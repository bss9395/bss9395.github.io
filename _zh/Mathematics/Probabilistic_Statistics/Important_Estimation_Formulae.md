---
layout:    zh_post
Topic:     概率统计
Title:     重要估算公式
Revised:   2018-04-16 00:55:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 阶乘估算公式

> $$
> \begin{alignedat}{3}
> \Uparrow\;   & \ln \dfrac{1 + x}{1 - x} = 2 x \cdot \left[ 1 + \sum_1^{+\infty} \dfrac{x^{2 m}}{2 m + 1} \right] \quad\Leftarrow\quad x \in (-1, +1) \\
> \Downarrow\; & 1 \lt \ln \left( \dfrac{1 + x}{1 - x} \right)^\frac{1}{2 x} \lt 1 + \dfrac{1}{3} \sum_1^{+\infty} x^{2 m} = 1 + \dfrac{x^2}{3 (1 - x^2)} \\
> \Uparrow\;   & \dfrac{1+ x}{1 - x} = \dfrac{n + 1}{n} \quad\Rightarrow\quad x = \dfrac{1}{2 n + 1} \in (0, \dfrac{1}{3}] \\
> \Downarrow\; & e \lt \left( \dfrac{n + 1}{n} \right)^{\frac{1}{2} + n} \lt e^{1 + \frac{1}{12} (\frac{1}{n} - \frac{1}{n + 1})} \\
> \Downarrow\; & 1 \lt \dfrac{s_{n + 1}}{s_n} = \left. \dfrac{(n + 1)^{\frac{1}{2} + (n + 1)}}{(n + 1) ! \cdot e^{n + 1}} \middle/ \dfrac{n^{\frac{1}{2} + n}}{n ! \cdot e^n} \right. \lt \left. e^\frac{1}{12 n} \middle/ e^\frac{1}{12 (n + 1)} \right. \quad\Rightarrow\quad s_n = \dfrac{n^{\frac{1}{2} + n}}{n ! \cdot e^n} = \dfrac{\sqrt{n}}{n !} \left( \dfrac{n}{e} \right)^n \\
> \Downarrow\; & 0 \lt s_n \lt s_{n + 1} \quad\land\quad 0 \lt e^\frac{1}{12 (n + 1)} \cdot s_{n + 1} \lt e^\frac{1}{12 n} \cdot s_n \\
> \Downarrow\; & s_n \lt s = \lim_{+\infty} \dfrac{n^{\frac{1}{2} + n}}{n ! \cdot e^n} \lt e^\frac{1}{12 n} \cdot s_n \quad\Rightarrow\quad s = e^\frac{\langle 0 \lt \theta (n) \lt 1 \rangle}{12 n} \cdot s_n \\
> \Downarrow\; & n ! = \dfrac{\sqrt{n}}{s_n} \left( \dfrac{n}{e} \right)^n = \dfrac{\sqrt{n}}{s} \left( \dfrac{n}{e} \right)^n e^\frac{\theta (n)}{12 n} \\
> \Uparrow\;   & \dfrac{\pi}{2} = \lim_{+\infty} \dfrac{1}{2 n + 1} \left[ \dfrac{(2 n) !!}{(2 n - 1) !!} \right]^2 = \lim_{+\infty} \dfrac{1}{2 n + 1} \left[ \dfrac{(2^n \cdot n !)^2}{(2 n) !} \right]^2 \\
> \Downarrow\; & \dfrac{\pi}{2} = \lim_{+\infty} \dfrac{1}{2 n + 1} \dfrac{1}{s^2} \dfrac{n}{2} e^\frac{4 \theta (n) - \theta (2 n)}{12 n} = \dfrac{1}{4 s^2} \quad\Rightarrow\quad s = \dfrac{1}{\sqrt{2 \pi}} \\
> \Downarrow\; & n ! = \sqrt{2 \pi n} \left( \dfrac{n}{e} \right)^n e^\frac{\langle 0 \lt \theta (n) \lt 1 \rangle}{12 n} \\
> \Downarrow\; & n ! \mathop{\sim}_{+\infty} \sqrt{2 \pi n} \left( \dfrac{n}{e} \right)^n
> \end{alignedat}
> $$
>

> $$
> \begin{alignedat}{3}
>
> \end{alignedat}
> $$
>