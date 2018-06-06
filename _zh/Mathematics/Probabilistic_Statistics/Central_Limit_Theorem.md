---
layout:    zh_post
Topic:     概率统计
Title:     中心极限定理
Revised:   2018-06-07 00:25:00 +08 @ 中国-新疆-乌鲁木齐 +06
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
> \Uparrow\quad         && \ln \lim_{n \to +\infty} \mathrm{Exp} \left[ e^{\imath t \cdot \frac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] &= \lim_{n \to +\infty} \ln \prod_{i = 1}^n \mathrm{Exp} \left[ e^{\imath t \cdot \frac{X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] \quad\Leftarrow\quad p (x_1, \cdots, x_n) = p_{X_1} (x_1) \cdots p_{X_n} (x_n) \\
>                       &&                                                                                                                                                        &\xlongequal{e^x = 1 + x + \frac{x^2}{2} \cdot e^{\theta \cdot x}} \lim_{n \to +\infty} \sum_{i = 1}^n \ln \mathrm{Exp} \left[ 1 + \imath t \cdot \dfrac{X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} + (\imath t)^2 \cdot \dfrac{[X_i - \mathrm{Exp} [X_i]]^2}{2 \sum_1^n \mathrm{Var} [X_n]} \cdot e^{\theta_{i 1} \imath t \cdot \frac{X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] \\
>                       &&                                                                                                                                                        &\xlongequal{\ln (1 + x) = \frac{x}{1 + \theta \cdot x}} \lim_{n \to +\infty} \sum_{i = 1}^n \dfrac{(\imath t)^2 \cdot \mathrm{Exp} \left[ \dfrac{[X_i - \mathrm{Exp} [X_i]]^2}{2 \sum_1^n \mathrm{Var} [X_n]} \cdot e^{\theta_{i 1} \imath t \cdot \frac{X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right]}{1 + \theta_{i 2} (\imath t)^2 \cdot \mathrm{Exp} \left[ \dfrac{[X_i - \mathrm{Exp} [X_i]]^2}{2 \sum_1^n \mathrm{Var} [X_n]} \cdot e^{\theta_{i 1} \imath t \cdot \frac{X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right]} \\
> \fbox{1}\Uparrow\quad &&            P \left[ \lim_{n \to +\infty} \sup_{i \le n} \dfrac{|X_i - \mathrm{Exp} [X_i]|}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \ge \varepsilon \right] &\to 0 \iff P\left[ \lim_{n \to +\infty} |\theta_{i 1}| \ge \varepsilon \right] \rightrightarrows 0 \\
> \fbox{2}\Uparrow\quad &&                                                            \lim_{n \to +\infty} \sup_{i \le n} \dfrac{\mathrm{Var} [X_i]}{\sum_1^n \mathrm{Var} [X_n]} &\to 0 \iff \lim_{n \to +\infty} \theta_{i 2} \rightrightarrows 0 \\
> \Downarrow\quad       && \ln \lim_{n \to +\infty} \mathrm{Exp} \left[ e^{\imath t \cdot \frac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] &= - \dfrac{t^2}{2} \\
> \Downarrow\quad       &&     \lim_{n \to +\infty} \mathrm{Exp} \left[ e^{\imath t \cdot \frac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}}} \right] &= e^{- \frac{t^2}{2}} \\
>                       &&                                                                                                                                                        &= \mathrm{Exp} [e^{\imath t \cdot U}] \\
> \Downarrow\quad       &&                            \lim_{n \to +\infty} P \left[ \dfrac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \lt x \right] &\xlongequal{\forall x \in \mathcal{Conti.}} P [U \lt x] \\
> \Downarrow\quad       &&                            \lim_{n \to +\infty} P \left[ \dfrac{\sum_1^n (X_n - \mathrm{Exp} [X_n])}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \lt x \right] &= \dfrac{1}{\sqrt{2 \pi}} \int_{-\infty}^x e^{- \frac{t^2}{2}} \mathrm{d} t \\
> \end{alignedat}
> $$
>

> ### 独立中心极限定理的条件

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\quad && P \left[ \lim_{n \to +\infty} \sup_{i \le n} \dfrac{|X_i - \mathrm{Exp} [X_i]|}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \ge \varepsilon \right] &= \lim_{n \to +\infty} P \left[ \bigcup_{i = 1}^n \middle( \dfrac{|X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \ge \varepsilon \middle) \right] \\
>                       &&                                                                                                                                             &\le \lim_{n \to +\infty} \sum_{i = 1}^n P \left[ \dfrac{|X_i - \mathrm{Exp} [X_i]}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \ge \varepsilon \right] \\
>                       &&                                                                                                                                             &\le \lim_{n \to +\infty} \sum_{i = 1}^n \int_{\frac{|X_i - \mathrm{Exp} [X_i]|}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \ge \varepsilon} \dfrac{|X_i - \mathrm{Exp} [X_i]|^2}{\sum_1^n \mathrm{Var} [X_n]} \mathrm{d} C (X_i) \\
>                       &&                                                                                                                                             &= \lim_{n \to +\infty} \dfrac{1}{\sum_1^n \mathrm{Var} [X_n]} \sum_{i = 1}^n \int_{\frac{|X_i - \mathrm{Exp} [X_i]|}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \ge \varepsilon} |X_i - \mathrm{Exp} [X_i]|^2 \mathrm{d} C (X_i) \\
> \Downarrow\quad       &&                                                                  \lim_{n \to +\infty} \dfrac{1}{\sum_1^n \mathrm{Var} [X_n]} \sum_{i = 1}^n & \int_{\frac{|X_i - \mathrm{Exp} [X_i]|}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \ge \varepsilon} |X_i - \mathrm{Exp} [X_i]|^2 \mathrm{d} C (X_i) \to 0 \implies \lim_{n \to +\infty} \sup_{i \le n} \dfrac{|X_i - \mathrm{Exp} [X_i]|}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \to 0 \\
> \fbox{2}\Uparrow\quad &&                                                 \lim_{n \to +\infty} \sup_{i \le n} \dfrac{\mathrm{Var} [X_i]}{\sum_1^n \mathrm{Var} [X_n]} &= \lim_{n \to +\infty} \sup_{i \le n} \left[ \int_{\frac{|X_i - \mathrm{Exp} [X_i]|}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \lt \varepsilon} + \int_{\frac{|X_i - \mathrm{Exp} [X_i]|}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \ge \varepsilon} \right] \dfrac{|X_i - \mathrm{Exp} [X_i]|^2}{\sum_1^n \mathrm{Var} [X_n]} \mathrm{d} C (X_i) \\
>                       &&                                                                                                                                             &\lt \varepsilon^2 + \lim_{n \to +\infty} \dfrac{1}{\sum_1^n \mathrm{Var} [X_n]} \sum_{i = 1}^n \int_{\frac{|X_i - \mathrm{Exp} [X_i]|}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \ge \varepsilon} |X_i - \mathrm{Exp} [X_i]|^2 \mathrm{d} C (X_i) \\
> \Downarrow\quad       &&                                                                  \lim_{n \to +\infty} \dfrac{1}{\sum_1^n \mathrm{Var} [X_n]} \sum_{i = 1}^n & \int_{\frac{|X_i - \mathrm{Exp} [X_i]|}{\sqrt{\sum_1^n \mathrm{Var} [X_n]}} \ge \varepsilon} |X_i - \mathrm{Exp} [X_i]|^2 \mathrm{d} C (X_i) \to 0 \implies \lim_{n \to +\infty} \sup_{i \le n} \dfrac{\mathrm{Var} [X_i]}{\sum_1^n \mathrm{Var} [X_n]} \to 0 \\
> \end{alignedat}
> $$
>

