---
layout:    zh_post
Topic:     概率统计
Title:     特征函数
Revised:   2018-05-27 01:56:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 矩母函数 $\mathrm{M_{oment} G_{enerating} F_{unction}}$

> $$
> \begin{alignedat}{3}
>                      \mathrm{MGF} [t \cdot X] &= \mathrm{Exp} [e^{t \cdot X}] \\
> \mathrm{MGF} [t \cdot (X - \mathrm{Exp} [X])] &= \mathrm{Exp} [e^{t \cdot X}] \cdot e^{- t \cdot \mathrm{Exp} [X]} \\
>                            \mathrm{Exp} [X]^h &= \lim_{t \to 0} \dfrac{\mathrm{d}^h}{\mathrm{d} t^h} \mathrm{MGF} [t \cdot X] \\
>         \mathrm{Exp} [X - \mathrm{Exp} [X]]^h &= \lim_{t \to 0} \dfrac{\mathrm{d}^h}{\mathrm{d} t^h} \mathrm{MGF} [t \cdot (X - \mathrm{Exp} [X])] \\
> \end{alignedat}
> $$
>

> ### 矩母函数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \mathrm{Exp} [e^{0 \cdot X}] = 1 \\
> \fbox{2}\quad & |\mathrm{Exp} [e^{t \cdot X}]| \le \mathrm{Exp} [|e^{t \cdot X}|] \\
> \fbox{3}\quad & \mathrm{Exp} [e^{t \cdot (c X + d)}] = \mathrm{Exp} [e^{t \cdot c X}] \cdot e^{t \cdot d} \\
> \fbox{4}\quad & \mathrm{Exp} \left[ e^{t \cdot [ f_1 (X_1) + \cdots + f_m (X_m)]} \right] &= \mathrm{Exp} [e^{t \cdot f_1 (X_1)}] \cdots \mathrm{Exp} [e^{t \cdot f_m (X_m)}] \quad\Leftarrow\quad p (x_1, \cdots, x_m) = p_{X_1} (x_1) \cdots p_{X_m} (x_m) \\
> \end{alignedat}
> $$
>

> ### 特征函数 $\mathrm{C_{haracteristic} F_{unction}}$

> $$
> \begin{alignedat}{3}
>      e^{\imath \cdot X} &= \cos X + \imath \sin X              \;&&\Rightarrow\; |e^{\imath \cdot X}| = 1  \\
> \mathrm{CF} [t \cdot X] &= \mathrm{Exp} [e^{\imath t \cdot X}] = \mathrm{MGF} [i t \cdot X] \;&&\Leftarrow\; \mathrm{Exp} [|e^{\imath t \cdot X}|] = 1 \\
> \end{alignedat}
> $$
>

> ### 特征函数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \mathrm{Exp} [|e^{\imath t \cdot X}|] = 1 \\
> \fbox{2}\quad & \mathrm{Exp} [e^{- \imath t \cdot X}] = \mathrm{Exp} [\overline{e^{\imath t \cdot X}}] = \overline{\mathrm{Exp} [e^{\imath t \cdot X}]} \\
> \end{alignedat}
> $$
>