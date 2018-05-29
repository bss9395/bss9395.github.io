---
layout:    zh_post
Topic:     概率统计
Title:     特征函数
Revised:   2018-05-29 20:01:00 +08 @ 中国-新疆-乌鲁木齐 +06
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
> \fbox{4}\quad & \mathrm{Exp} \left[ e^{t \cdot [ f_1 (X_1) + \cdots + f_m (X_m)]} \right] = \mathrm{Exp} [e^{t \cdot f_1 (X_1)}] \cdots \mathrm{Exp} [e^{t \cdot f_m (X_m)}] \quad\Leftarrow\quad p (x_1, \cdots, x_m) = p_{X_1} (x_1) \cdots p_{X_m} (x_m) \\
> \end{alignedat}
> $$
>

> ### 特征函数 $\mathrm{C_{haracteristic} F_{unction}}$

> $$
> \begin{alignedat}{3}
>      e^{\imath \cdot X} &= \cos X + \imath \sin X                                           \;&&\Rightarrow\; |e^{\imath \cdot X}| = 1  \\
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

> ### 特征函数的一致连续性

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   &&                   |\mathrm{Exp} [e^{\imath (t + \mathrm{d} t) \cdot X}] - \mathrm{Exp} [e^{\imath t \cdot X}]| &= |\mathrm{Exp} [e^{\imath t \cdot X} \cdot (e^{\imath \mathrm{d} t \cdot X} - 1)]| \\
>                 &&                                                                                                                &\le \mathrm{Exp} [|e^{\imath \mathrm{d} t \cdot X} - 1|] \\
>                 &&                                                                                                                &= \mathrm{Exp} [|e^{\frac{1}{2} \imath \mathrm{d} t \cdot X} \cdot (e^{\frac{1}{2} \imath \mathrm{d} t \cdot X} - e^{- \frac{1}{2} \imath \mathrm{d} t \cdot X})|] \\
>                 &&                                                                                                                &= \mathrm{Exp} \left[ 2 \middle| \sin \dfrac{\mathrm{d} t \cdot X}{2} \middle| \right] \\
>                 &&                                                                                                                &\le 2 \\
> \Downarrow\quad && \lim_{\mathrm{d} t \to 0} \mathrm{Exp} \left[ 2 \middle| \sin \dfrac{\mathrm{d} t \cdot X}{2} \middle| \right] &\to 0 \\
> \Downarrow\quad &&                                         \mathrm{Exp} [e^{\imath t \cdot X}] \rightrightarrows \mathcal{Conti.} & (-\infty, +\infty) \\
> \end{alignedat}
> $$
>

> ### 特征函数的非负定性

> $$
> \begin{alignedat}{3}
> \sum_{i = 1}^n \sum_{j = 1}^n \mathrm{Exp} [e^{\imath (t_i - t_j) \cdot X}] z_i \overline{z_j} &= \mathop{\left\langle \sum \int \mathrm{d} x \right\rangle}_{x} p (x) \sum_{i = 1}^n z_i e^{\imath t_i \cdot X} \sum_{j = 1}^n \overline{z_j} e^{- \imath t_j \cdot X} \\
>                                                                                                &= \mathop{\left\langle \sum \int \mathrm{d} x \right\rangle}_{x} p (x) \left[ \sum_{i = 1}^n z_i e^{\imath t_i \cdot X} \right]^2 \\
>                                                                                                &\ge 0 \\
> \end{alignedat}
> $$
>