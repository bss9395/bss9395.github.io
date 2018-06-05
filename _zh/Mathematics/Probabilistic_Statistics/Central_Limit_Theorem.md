---
layout:    zh_post
Topic:     概率统计
Title:     中心极限定理
Revised:   2018-06-05 04:56:00 +08 @ 中国-新疆-乌鲁木齐 +06
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
> \Uparrow\quad   &&    \ln \lim_{n \to +\infty} \mathrm{Exp} \left[ e^{t \cdot \frac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] &= \lim_{n \to +\infty} \ln \prod_{i = 1}^n \mathrm{Exp} \left[ e^{t \cdot \frac{X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] \quad\Leftarrow\quad p (x_1, \cdots, x_n) = p_{X_1} (x_1) \cdots p_{X_n} (x_n) \\
>                 &&                                                                                                                                                    &\xlongequal{e^x = 1 + x + \frac{x^2}{2} \cdot e^{\theta \cdot x}} \lim_{n \to +\infty} \sum_{i = 1}^n \ln \mathrm{Exp} \left[ 1 + t \cdot \dfrac{X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} + t^2 \cdot \dfrac{[X_i - \mathrm{Exp} [X_i]]^2}{2 \sum_1^n \mathrm{Var} [X_n]} \cdot e^{\theta_{i 1} t \cdot \frac{X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] \\
>                 &&                                                                                                                                                    &\xlongequal{\ln (1 + x) = \frac{x}{1 + \theta \cdot x}} \lim_{n \to +\infty} \sum_{i = 1}^n \dfrac{t^2 \cdot \mathrm{Exp} \left[ \dfrac{[X_i - \mathrm{Exp} [X_i]]^2}{2 \sum_1^n \mathrm{Var} [X_n]} \cdot e^{\theta_{i 1} t \cdot \frac{X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right]}{1 + \theta_{i 2} t^2 \cdot \mathrm{Exp} \left[ \dfrac{[X_i - \mathrm{Exp} [X_i]]^2}{2 \sum_1^n \mathrm{Var} [X_n]} \cdot e^{\theta_{i 1} t \cdot \frac{X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right]} \\
> \Uparrow\quad   &&                                                           \lim_{n \to +\infty} \dfrac{\mathrm{Var} [X_i]}{\sum_1^n \mathrm{Var} [X_n]} \to 0 \quad &= \dfrac{t^2}{2} \\
> \Downarrow\quad && \lim_{n \to +\infty} \mathrm{Exp} \left[ e^{\imath t \cdot \frac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] &= e^{- \frac{t^2}{2}} \\
>                 &&                                                                                                                                                    &= \mathrm{Exp} [e^{\imath t \cdot U}] \\
> \Downarrow\quad &&                                                                                                                             \lim_{n \to +\infty} P & \left[ \dfrac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \lt x \right] \xlongequal{\forall x \in \mathcal{Conti.}} P [U \lt x] \\
> \Downarrow\quad &&                                                                                                                             \lim_{n \to +\infty} P & \left[ \dfrac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \lt x \right] = \dfrac{1}{\sqrt{2 \pi}} \int_{-\infty}^x e^{- \frac{t^2}{2}} \mathrm{d} t \\
> \end{alignedat}
> $$
>

