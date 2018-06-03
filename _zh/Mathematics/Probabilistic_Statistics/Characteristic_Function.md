---
layout:    zh_post
Topic:     概率统计
Title:     特征函数
Revised:   2018-06-03 22:32:00 +08 @ 中国-新疆-乌鲁木齐 +06
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
> \sum_{i = 1}^n \sum_{j = 1}^n \mathrm{Exp} [e^{\imath (t_i - t_j) \cdot X}] z_i \overline{z_j} &= \int_x \mathrm{d} C (x) \sum_{i = 1}^n z_i e^{\imath t_i \cdot X} \sum_{j = 1}^n \overline{z_j} e^{- \imath t_j \cdot X} \\
>                                                                                                &= \int_x \mathrm{d} C (x) \left[ \sum_{i = 1}^n z_i e^{\imath t_i \cdot X} \right]^2 \\
>                                                                                                &\ge 0 \\
> \end{alignedat}
> $$
>

> ### 反演公式

> $$
> \begin{alignedat}{3}
>         \Uparrow\quad   && \dfrac{1}{2 \pi} \int_{-\infty}^{+\infty} \dfrac{e^{- \imath t \cdot \alpha} - e^{- \imath t \cdot \beta}}{\imath t} \mathrm{Exp} [e^{\imath t \cdot X}] \mathrm{d} t &= \dfrac{1}{2 \pi} \int_{-\infty}^{+\infty} \int_x \dfrac{e^{\imath t \cdot (x - \alpha)} - e^{\imath t \cdot (x - \beta)}}{\imath t} \mathrm{d} C (x) \mathrm{d} t \\
>                         &&                                                                                                                                                                       &= \dfrac{1}{2 \pi} \int_x \int_0^{+\infty} \left[ \dfrac{e^{\imath t \cdot (x - \alpha)} - e^{- \imath t \cdot (x - \alpha)}}{\imath t} - \dfrac{e^{\imath t \cdot (x - \beta)} - e^{- \imath t \cdot (x - \beta)}}{\imath t} \right] \mathrm{d} t \mathrm{d} C (x) \\
>                         &&                                                                                                                                                                       &= \dfrac{1}{\pi} \int_x \int_0^{+\infty} \left[ \dfrac{\sin (x - \alpha) t}{t} - \dfrac{\sin (x - \beta) t}{t} \right] \mathrm{d} t \mathrm{d} C (x) \\
>                         &&                                                                                                                                                                       &= \left[ \dfrac{1}{2} \int_{x = \alpha} + \int_{\alpha \lt x \lt \beta} + \dfrac{1}{2} \int_{x = \beta} \right] \mathrm{d} C (x) \\
>                         &&                                                                                                                                                                       &= \dfrac{C (\alpha) - C (\alpha^-)}{2} + C (\beta^-) - C (\alpha) + \dfrac{C (\beta) - C (\beta^-)}{2} \\
> \fbox{1}\Downarrow\quad &&                                                                                             \dfrac{C (\beta) + C (\beta^-)}{2} - \dfrac{C (\alpha) + C (\alpha^-)}{2} &= \dfrac{1}{2 \pi} \int_{-\infty}^{+\infty} \dfrac{e^{- \imath t \cdot \alpha} - e^{- \imath t \cdot \beta}}{\imath t} \mathrm{Exp} [e^{\imath t \cdot X}] \mathrm{d} t \\
> \fbox{2}\Downarrow\quad &&                                                                                                  \alpha, \beta \in \mathcal{Conti.^-} \implies C (\beta) - C (\alpha) &= \dfrac{1}{2 \pi} \int_{-\infty}^{+\infty} \dfrac{e^{- \imath t \cdot \alpha} - e^{- \imath t \cdot \beta}}{\imath t} \mathrm{Exp} [e^{\imath t \cdot X}] \mathrm{d} t \\
> \end{alignedat}
> $$
>

> ### 特征函数唯一决定分布函数

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad &&                                           \dfrac{C (\beta) + C (\beta^-)}{2} &= \lim_{\alpha \to -\infty} \dfrac{1}{2 \pi} \int_{-\infty}^{+\infty} \dfrac{e^{- \imath t \cdot \alpha} - e^{- \imath t \cdot \beta}}{\imath t} \mathrm{Exp} [e^{\imath t \cdot X}] \mathrm{d} t \\
> \fbox{2}\quad &&                              \beta \in \mathcal{Conti.^-} \implies C (\beta) &= \lim_{\alpha \to -\infty} \dfrac{1}{2 \pi} \int_{-\infty}^{+\infty} \dfrac{e^{- \imath t \cdot \alpha} - e^{- \imath t \cdot \beta}}{\imath t} \mathrm{Exp} [e^{\imath t \cdot X}] \mathrm{d} t \\
> \fbox{3}\quad &&                        \beta \not\in \mathcal{Conti.^-} \implies C (\beta^-) &= \lim_{u \to \beta^-} \lim_{\alpha \to -\infty} \dfrac{1}{2 \pi} \int_{-\infty}^{+\infty} \dfrac{e^{- \imath t \cdot \alpha} - e^{- \imath t \cdot u}}{\imath t} \mathrm{Exp} [e^{\imath t \cdot X}] \mathrm{d} t \\
> \fbox{4}\quad && \lim_{n \to +\infty} C (X_n) \mathop{\longrightarrow}^{\mathcal{Weak}} C (X) &\iff \mathrm{Exp} [e^{\imath t \cdot X}] \\
> \end{alignedat}
> $$
>

> ### 特征函数与连续密度函数

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           &&                               p (x) &= \dfrac{\mathrm{d}}{\mathrm{d} x} C (x) \\
>                         &&                                     &= \dfrac{\mathrm{d}}{\mathrm{d} x} \lim_{\alpha \to -\infty} \dfrac{1}{2 \pi} \int_{-\infty}^{+\infty} \dfrac{e^{- \imath t \cdot \alpha} - e^{- \imath t \cdot x}}{\imath t} \mathrm{Exp} [e^{\imath t \cdot X}] \mathrm{d} t \\
>                         &&                                     &= \lim_{\alpha \to -\infty} \dfrac{1}{2 \pi} \int_{-\infty}^{+\infty} \dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{e^{- \imath t \cdot \alpha} - e^{- \imath t \cdot x}}{\imath t} \mathrm{Exp} [e^{\imath t \cdot X}] \mathrm{d} t \\
> \fbox{1}\Downarrow\quad &&                               p (x) &= \dfrac{1}{2 \pi} \int_{-\infty}^{+\infty} e^{- \imath t \cdot x} \cdot \mathrm{Exp} [e^{\imath t \cdot X}] \mathrm{d} t \\
> \fbox{2}\Downarrow\quad && \mathrm{Exp} [e^{\imath t \cdot X}] &= \int_{-\infty}^{+\infty} e^{\imath t \cdot x} \cdot p (x) \mathrm{d} x \\
> \end{alignedat}
> $$
>

> ### 多维矩母函数 $\mathrm{M_{oment} G_{enerating} F_{unction}}$

> $$
> \begin{alignedat}{3}
> \mathrm{MGF} [t_1 \cdot X_1 + \cdots + t_m \cdot X_m] &= \mathrm{Exp} [e^{t_1 \cdot X_1 + \cdots + t_m \cdot X_m}] \\
>             \mathrm{Exp} [X_1^{h_1} \cdots X_m^{h_m}] &= \lim_{(t_1, \cdots, t_m) \to (0, \cdots, 0)} \dfrac{\partial^{h_1 + \cdots + h_m}}{\partial t_1^{h_1} \cdots \partial t_m^{h_m}} \mathrm{MGF} [t_1 \cdot X_1 + \cdots + t_m \cdot X_m] \\
> \end{alignedat}
> $$
>

> ### 多维矩母函数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \mathrm{Exp} [e^{0 \cdot X_1 + \cdots + 0 \cdot X_m}] = 1 \\
> \fbox{2}\quad & |\mathrm{Exp} [e^{t_1 \cdot X_1 + \cdots + t_m \cdot X_m}]| \le \mathrm{Exp} [|e^{t_1 \cdot X_1 + \cdots + t_m \cdot X_m}|] \\
> \end{alignedat}
> $$
>

> ### 多维特征函数 $\mathrm{C_{haracteristic} F_{unction}}$

> $$
> \begin{alignedat}{3}
>   \mathrm{CF} [t_1 \cdot X_1 + \cdots + t_m \cdot X_m] &= \mathrm{Exp} [e^{\imath (t_1 \cdot X_1 + \cdots + t_m \cdot X_m)}] = \mathrm{MGF} [\imath (t_1 \cdot X_1 + \cdots + t_m \cdot X_m)] \;\Leftarrow\; \mathrm{Exp} [|e^{\imath (t_1 \cdot X_1 + \cdots + t_m \cdot X_m)}|] = 1 \\
> \mathrm{CF} [\cdots + \cancel{t_i \cdot X_i} + \cdots] &= \mathrm{CF} [\cdots + 0 \cdot X_i + \cdots] \\
> \end{alignedat}
> $$
>

> ### 多维特征函数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \mathrm{Exp} [|e^{\imath (t_1 \cdot X_1 + \cdots + t_m \cdot X_m)}|] = 1 \\
> \fbox{2}\quad & \mathrm{Exp} [e^{- \imath (t_1 \cdot X_1 + \cdots + t_m \cdot X_m)}] = \mathrm{Exp} [\overline{e^{\imath (t_1 \cdot X_1 + \cdots + t_m \cdot X_m)}}] = \overline{\mathrm{Exp} [e^{\imath (t_1 \cdot X_1 + \cdots + t_m \cdot X_m)}]} \\
> \end{alignedat}
> $$
>