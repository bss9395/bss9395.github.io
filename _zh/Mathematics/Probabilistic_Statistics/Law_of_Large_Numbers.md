---
layout:    zh_post
Topic:     概率统计
Title:     大数定律
Revised:   2018-06-05 01:55:00 +08 @ 中国-新疆-乌鲁木齐 +06
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
> \lim_{n \to +\infty} P \left[ \middle| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \middle| \ge \varepsilon \right] &= 0 \\
> \lim_{n \to +\infty} P \left[ \middle| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \middle| \lt \varepsilon \right] &= 1 \\
> \end{alignedat}
> $$
>

> ### 强大数定律

> $$
> \begin{alignedat}{3}
> P \left[ \lim_{n \to +\infty} \middle| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \middle| \ge \varepsilon \right] = 0 \\
> P \left[ \lim_{n \to +\infty} \middle| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \middle| \lt \varepsilon \right] = 1 \\
> \end{alignedat}
> $$
>

> ### 非独立弱大数定律

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           & P \left[ \middle| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \middle| \ge \varepsilon \right] \le \dfrac{1}{n^2 \varepsilon^2} \mathrm{Var} \left[ \sum_1^n X_n \right] \\
> \Uparrow\quad           & \lim_{n \to +\infty} \dfrac{1}{n^2} \mathrm{Var} \left[ \sum_1^n X_n \right] \to 0 \\
> \fbox{1}\Downarrow\quad & \lim_{n \to +\infty} P \left[ \middle| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \middle| \ge \varepsilon \right] = 0 \\
> \fbox{2}\Downarrow\quad & \lim_{n \to +\infty} P \left[ \middle| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \middle| \lt \varepsilon \right] = 1 \\
> \end{alignedat}
> $$
>

> ### 独立同分布弱大数定律

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           && \lim_{n \to +\infty} \mathrm{Exp} \left[ e^{\imath t \cdot \frac{1}{n} \sum\limits_{i = 1}^n X_i} \right] &= \lim_{n \to +\infty} \prod_{i = 1}^n \mathrm{Exp} [e^{\imath t \cdot \frac{1}{n} X_i}] \quad\Leftarrow\quad p (x_1, \cdots, x_n) = p_{X_1} (x_1) \cdots p_{X_n} (x_n) \\
>                         &&                                                                                                           &= \lim_{n \to +\infty} \mathrm{Exp}^n [e^{\imath t \cdot \frac{1}{n} X'}] \quad\Leftarrow\quad X_1, \cdots, X_n \mapsto X' \\
>                         &&                                                                                                           &\xlongequal{\frac{\mathrm{d}^h}{\mathrm{d} x^h} e^x} \lim_{n \to +\infty} \left[ 1 + \dfrac{\imath t \cdot \mathrm{Exp} [X']}{n} + \dfrac{o (\imath t) \cdot \mathrm{Exp} [X']}{n} \right]^n \\
>                         &&                                                                                                           &= e^{(\imath t + o (\imath t)) \cdot \mathrm{Exp} [X']} \\
>                         &&                                                                                                           &= \mathrm{Exp} [e^{\imath t \cdot \mathrm{Exp} [X']}] \\
> \Downarrow\quad         &&                                           \lim_{n \to +\infty} C \left( \dfrac{1}{n} \sum_1^n X_n \right) &\mathop{\longrightarrow}^{\mathcal{Weak}} C (X \equiv \mathrm{Exp} [X']) \iff \lim_{n \to +\infty} \dfrac{1}{n} \sum_1^n X_n \mathop{\longrightarrow}^{\mathcal{Prob.}} \mathrm{Exp} [X'] \\
> \fbox{1}\Downarrow\quad &&                                                                                    \lim_{n \to +\infty} P & \left[ \left| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \right| \ge \varepsilon \right] = 0 \\
> \fbox{2}\Downarrow\quad &&                                                                                    \lim_{n \to +\infty} P & \left[ \left| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \right| \lt \varepsilon \right] = 1 \\
> \end{alignedat}
> $$
>

> ### 独立强大数定律

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           && P \left[ \lim_{n \to +\infty} \middle| \dfrac{1}{n} \sum_{i = 1}^{n} (X_i - \mathrm{Exp} [X_i]) \middle| \ge \varepsilon \right] &= \lim_{N \to +\infty} P \left[ \bigcup_{n = N}^{+\infty} \middle( \middle| \dfrac{1}{n} \sum_{i = 1}^n (X_i - \mathrm{Exp} [X_i]) \middle| \ge \varepsilon \middle) \right] \\
>                         &&                                                                                                                                  &\le \lim_{N \to +\infty} P \left[ \sup_{n \ge N} \middle| \dfrac{1}{n} \sum_{i = 1}^n (X_i - \mathrm{Exp} [X_i]) \middle| \ge \varepsilon \right] \\
>                         &&                                                                                                                                  &\le \lim_{N \to +\infty} \sup_{n \ge N} \dfrac{1}{n^2 \varepsilon^2} \mathrm{Var} \left[ \sum_{i = 1}^n X_i \right] \\
>                         &&                                                                                                                                  &= \lim_{N \to +\infty} \sup_{n \ge N} \dfrac{1}{n^2 \varepsilon^2} \sum_{i = 1}^n \mathrm{Var} [X_i] \quad\Leftarrow\quad p (x_1, \cdots, x_n) = p_{X_1} (x_1) \cdots p_{X_n} (x_n) \\
>                         &&                                                                                                                                  &\le \lim_{N \to +\infty} \dfrac{1}{N^2 \varepsilon^2} \sum_{i = 1}^N \mathrm{Var} [X_i] + \lim_{N \to +\infty} \sum_{i = N + 1}^n \dfrac{\mathrm{Var} [X_i]}{i^2 \varepsilon^2} \\
>                         &&                                                                                                                                  &\le \lim_{N \to +\infty} \dfrac{\max \mathrm{Var} [X_i]}{N \varepsilon^2} + \lim_{N \to +\infty} \sum_{i = N + 1}^{+\infty} \dfrac{\mathrm{Var} [X_i]}{i^2 \varepsilon^2} \\
> \Uparrow\quad           && \sum_1^{+\infty} \dfrac{\mathrm{Var} [X_n]}{n^2} \le M &\implies \lim_{N \to +\infty} \sum_{i = N + 1}^{+\infty} \dfrac{\mathrm{Var} [X_i]}{i^2} \to 0 \\
> \fbox{1}\Downarrow\quad && P \left[ \lim_{n \to +\infty} \middle| \dfrac{1}{n} \sum_{i = 1}^{n} (X_i - \mathrm{Exp} [X_i]) \middle| \ge \varepsilon \right] &= 0 \\
> \fbox{2}\Downarrow\quad && P \left[ \lim_{n \to +\infty} \middle| \dfrac{1}{n} \sum_{i = 1}^{n} (X_i - \mathrm{Exp} [X_i]) \middle| \lt \varepsilon \right] &= 1 \\
> \end{alignedat}
> $$
>

