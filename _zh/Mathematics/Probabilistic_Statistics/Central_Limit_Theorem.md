---
layout:    zh_post
Topic:     概率统计
Title:     中心极限定理
Revised:   2018-06-03 02:41:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 中心极限定理

> $$
> \begin{alignedat}{3}
> \lim_{n \to +\infty} P \left[ \dfrac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \lt x \right] = \dfrac{1}{\sqrt{2 \pi}} \int_{-\infty}^x e^{- \frac{t^2}{2}} \mathrm{d} t \\
> \end{alignedat}
> $$
>

> ### 独立同分布中心极限定理

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   && \lim_{n \to +\infty} \mathrm{Exp} \left[ e^{\imath t \cdot \frac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] &= \lim_{n \to +\infty} \prod_{i = 1}^n \mathrm{Exp} \left[ e^{\imath t \cdot \frac{X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] \quad\Leftarrow\quad p (x_1, \cdots, x_n) = p_{X_1} (x_1) \cdots p_{X_n} (x_n) \\
>                 &&                                                                                                                                                    &= \lim_{n \to +\infty} \mathrm{Exp}^n \left[ e^{\imath t \cdot \frac{X' - \mathrm{Exp} [X']}{\sqrt{n \mathrm{Var} [X']}}} \right] \quad\Leftarrow\quad X_1, \cdots, X_n \mapsto X' \\
>                 &&                                                                                                                                                    &= \lim_{n \to +\infty} \left[ 1 + \dfrac{\imath t \cdot \mathrm{Exp} [X' - \mathrm{Exp} [X']]}{\sqrt{n \mathrm{Var} [X']}} + \dfrac{(\imath t)^2 \cdot \mathrm{Exp} [X' - \mathrm{Exp} [X']]^2}{2 n \mathrm{Var} [X']} + o \middle( \dfrac{(\imath t)^2 \cdot \mathrm{Exp} [X' - \mathrm{Exp} [X']]^2}{n \mathrm{Var} [X']} \middle) \right]^n \\
>                 &&                                                                                                                                                    &= \lim_{n \to +\infty} \left[ 1 + \dfrac{- t^2}{2 n} + \dfrac{- o (t^2)}{n} \right]^n \\
>                 &&                                                                                                                                                    &= e^{- \frac{t^2}{2} - o (t^2)} \\
>                 &&                                                                                                                                                    &= \mathrm{Exp} [e^{\imath t \cdot U}] \\
> \Downarrow\quad &&                               \lim_{n \to +\infty} C & \left( \frac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \right) \mathop{\longrightarrow}^{\mathcal{Weak}} C (U) \\
> \Downarrow\quad &&                        \lim_{n \to +\infty} P & \left[ \dfrac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \lt x \right] = \dfrac{1}{\sqrt{2 \pi}} \int_{-\infty}^x e^{- \frac{t^2}{2}} \mathrm{d} t \\
> \end{alignedat}
> $$
>

> ### 独立非同分布中心极限定理

> $$
> \begin{alignedat}{3}
> \lim_{n \to +\infty} \ln \mathrm{Exp} \left[ e^{\imath t \cdot \frac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] &= \lim_{n \to +\infty} \ln \prod_{i = 1}^n \mathrm{Exp} \left[ e^{\imath t \cdot \frac{X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] \quad\Leftarrow\quad p (x_1, \cdots, x_n) = p_{X_1} (x_1) \cdots p_{X_n} (x_n) \\
> &= \lim_{n \to +\infty} \ln \prod_{i = 1}^n \left[ 1 + \dfrac{\imath t \cdot \mathrm{Exp} [X_i - \mathrm{Exp} [X_i]]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} + \dfrac{(\imath t)^2 \cdot \mathrm{Exp} [X_i - \mathrm{Exp} [X_i]]^2}{2 \sum_1^n \mathrm{Var} [X_n]} + o \middle( \dfrac{(\imath t)^2 \cdot \mathrm{Exp} [X_i - \mathrm{Exp} [X_i]]^2}{\sum_1^n \mathrm{Var} [X_i]} \middle) \right] \\
> &= \lim_{n \to +\infty} \ln \prod_{i = 1}^n \left[ 1 + \dfrac{- t^2 \cdot \mathrm{Var} [X_i]}{2 \sum_1^n \mathrm{Var} [X_n]} + \dfrac{- o (t^2) \cdot \mathrm{Var} [X_i]}{\sum_1^n \mathrm{Var} [X_n]} \right] \\
> &= \lim_{n \to +\infty} \sum_1^n 
> \end{alignedat}
> $$
>

