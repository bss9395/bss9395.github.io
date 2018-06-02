---
layout:    zh_post
Topic:     概率统计
Title:     大数定律
Revised:   2018-06-02 20:44:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ###  概率不等式

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           && P [|X| \ge \varepsilon] &= \int_{|x| \ge \varepsilon} \mathrm{d} C (x) \\
>                         &&                         &\le\int_{|x| \ge \varepsilon} \dfrac{|x|^h}{\varepsilon^h} \mathrm{d} C (x) \\
>                         &&                         &\le \dfrac{1}{\varepsilon^h} \int_{x} |x|^h \cdot \mathrm{d} C (x) \\
> \fbox{1}\Downarrow\quad && P [|X| \ge \varepsilon] &\le \dfrac{\mathrm{Exp} [|X|]^h}{\varepsilon^h} \\
> \fbox{2}\Downarrow\quad && P [|X| \lt \varepsilon] &\ge 1 - \dfrac{\mathrm{Exp} [|X|]^h}{\varepsilon^h} \\
> \end{alignedat}
> $$
>

> ### 偏差概率不等式

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           && P (|X - \mathrm{Exp} [X]| \ge \varepsilon) &\le \dfrac{\mathrm{Exp} [|X - \mathrm{Exp} [X]|]^h}{\varepsilon^h} \\
> \fbox{1}\Downarrow\quad && P (|X - \mathrm{Exp} [X]| \ge \varepsilon) &\le \dfrac{\mathrm{Var} [X]}{\varepsilon^2} \\
> \fbox{2}\Downarrow\quad && P (|X - \mathrm{Exp} [X]| \lt \varepsilon) &\ge 1 - \dfrac{\mathrm{Var} [X]}{\varepsilon^2} \\
> \end{alignedat}
> $$
>

> ### 弱大数定律

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad && \lim_{n \to +\infty} P \left[ \middle| \dfrac{1}{n} \sum_1^n X_n - p_n \middle| \ge \varepsilon \right] &= 0 \\
> \fbox{2}\quad && \lim_{n \to +\infty} P \left[ \middle| \dfrac{1}{n} \sum_1^n X_n - p_n \middle| \lt \varepsilon \right] &= 1 \\
> \end{alignedat}
> $$
>

> ### 偏差大数定律

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           & \lim_{n \to +\infty} \dfrac{1}{n^2} \mathrm{Var} \left[ \sum_1^n X_n \right] \to 0 \\
> \Downarrow\quad         & P \left[ \middle| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \middle| \ge \varepsilon \right] \le \dfrac{1}{n^2 \varepsilon^2} \mathrm{Var} \left[ \sum_1^n X_n \right] \\
> \fbox{1}\Downarrow\quad & \lim_{n \to +\infty} P \left[ \middle| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \middle| \ge \varepsilon \right] = 0 \\
> \fbox{2}\Downarrow\quad & \lim_{n \to +\infty} P \left[ \middle| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \middle| \lt \varepsilon \right] = 1 \\
> \end{alignedat}
> $$
>

> ### 独立同分布大数定律

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   && \lim_{n \to +\infty} \mathrm{Exp} \left[ e^{\imath t \cdot \frac{1}{n} \sum\limits_{i = 1}^n X_i} \right] &= \lim_{n \to +\infty} \prod_{i = 1}^n \mathrm{Exp} [e^{\imath t \cdot \frac{1}{n} X_i}] \quad\Leftarrow\quad p (x_1, \cdots, x_n) = p_{X_1} (x_1) \cdots p_{X_n} (x_n) \\
>                 &&                                                                                                           &= \lim_{n \to +\infty} \mathrm{Exp}^n [e^{\imath t \cdot \frac{1}{n} X'}] \quad\Leftarrow\quad X_1, \cdots, X_n \mapsto X' \\
>                 &&                                                                                                           &\xlongequal{\frac{\mathrm{d}^h}{\mathrm{d} t^h} e^{\imath t \cdot \frac{1}{n} X'}} \lim_{n \to +\infty} \left[ 1 + \dfrac{\imath t \cdot \mathrm{Exp} [X']}{n} + \dfrac{o (\imath t) \cdot \mathrm{Exp} [X']}{n} \right]^n \\
>                 &&                                                                                                           &= e^{(\imath t + o (\imath t)) \cdot \mathrm{Exp} [X']} \\
>                 &&                                                                                                           &= \mathrm{Exp} [e^{\imath t \cdot \mathrm{Exp} [X']}] \\
> \Downarrow\quad &&                                           \lim_{n \to +\infty} C \left( \dfrac{1}{n} \sum_1^n X_n \right) &\mathop{\longrightarrow}^{\mathcal{Weak}} C (X \equiv \mathrm{Exp} [X']) \iff \lim_{n \to +\infty} \dfrac{1}{n} \sum_1^n X_n \mathop{\longrightarrow}^{\mathcal{Prob.}} \mathrm{Exp} [X'] \\
> \fbox{1}\Downarrow\quad &&                                                                                    \lim_{n \to +\infty} P & \left[ \left| \dfrac{1}{n} \sum_1^n X_n - \mathrm{Exp} [X'] \right| \ge \varepsilon \right] = 0 \\
> \fbox{2}\Downarrow\quad &&                                                                                    \lim_{n \to +\infty} P & \left[ \left| \dfrac{1}{n} \sum_1^n X_n - \mathrm{Exp} [X'] \right| \lt \varepsilon \right] = 1 \\
> \end{alignedat}
> $$
>

