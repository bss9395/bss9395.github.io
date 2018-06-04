---
layout:    zh_post
Topic:     概率统计
Title:     中心极限定理
Revised:   2018-06-05 04:54:00 +08 @ 中国-新疆-乌鲁木齐 +06
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

> ### 独立中心极限定理

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   && \ln \lim_{n \to +\infty} \mathrm{Exp} \left[ e^{\imath t \cdot \frac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] &= \lim_{n \to +\infty} \ln \prod_{i = 1}^n \mathrm{Exp} \left[ e^{\imath t \cdot \frac{X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] \quad\Leftarrow\quad p (x_1, \cdots, x_n) = p_{X_1} (x_1) \cdots p_{X_n} (x_n) \\
>                 &&                                                                                                                                                        &= \lim_{n \to +\infty} \ln \prod_{i = 1}^n \left[ 1 + \dfrac{\imath t \cdot \mathrm{Exp} [X_i - \mathrm{Exp} [X_i]]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} + \dfrac{(\imath t)^2 \cdot \mathrm{Exp} [X_i - \mathrm{Exp} [X_i]]^2}{2 \sum_1^n \mathrm{Var} [X_n]} + o \middle( \dfrac{(\imath t)^2 \cdot \mathrm{Exp} [X_i - \mathrm{Exp} [X_i]]^2}{\sum_1^n \mathrm{Var} [X_i]} \middle) \right] \\
>                 &&                                                                                                                                                        &= \lim_{n \to +\infty} \sum_{i = 1}^n \ln \left[ 1 + \dfrac{- t^2 \cdot \mathrm{Var} [X_i]}{2 \sum_1^n \mathrm{Var} [X_n]} + \dfrac{- o (t^2) \cdot \mathrm{Var} [X_i]}{\sum_1^n \mathrm{Var} [X_n]} \right] \\
> \Uparrow\quad   &&                                                                     \lim_{n \to +\infty} \dfrac{\mathrm{Var} [X_i]}{\sum_1^n \mathrm{Var} [X_n]} \to 0 & \\
> \Downarrow\quad && \ln \lim_{n \to +\infty} \mathrm{Exp} \left[ e^{\imath t \cdot \frac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] &\xlongequal{\ln (1 + x) = x + o (x)} \left( - \frac{t^2}{2} - o (t^2) \right) \cdot \lim_{n \to +\infty} \sum_{i = 1}^n \dfrac{\mathrm{Var} [X_i]}{\sum_1^n \mathrm{Var} [X_n]} \\
>                 &&                                                                                                                                                        &\xlongequal{x = x + o (x)} - \dfrac{t^2}{2} \\
> \Downarrow\quad &&     \lim_{n \to +\infty} \mathrm{Exp} \left[ e^{\imath t \cdot \frac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] &= e^{- \frac{t^2}{2}} \\
>                 &&                                                                                                                                                        &= \mathrm{Exp} [e^{\imath t \cdot U}] \\
> \Downarrow\quad &&                                                                                                                                 \lim_{n \to +\infty} P & \left[ \dfrac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \lt x \right] = P [U \lt x] \\
> \Downarrow\quad &&                                                                                                                                 \lim_{n \to +\infty} P & \left[ \dfrac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \lt x \right] = \dfrac{1}{\sqrt{2 \pi}} \int_{-\infty}^x e^{- \frac{t^2}{2}} \mathrm{d} t \\
> \end{alignedat}
> $$
>

