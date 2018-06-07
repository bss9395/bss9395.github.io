---
layout:    zh_post
Topic:     概率统计
Title:     大数定律
Revised:   2018-06-07 06:35:00 +08 @ 中国-新疆-乌鲁木齐 +06
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
> \Uparrow\quad           && P [|X - \mathrm{Exp} [X]| \ge \varepsilon] &\le \dfrac{\mathrm{Exp} [|X - \mathrm{Exp} [X]|]^h}{\varepsilon^h} \\
> \fbox{1}\Downarrow\quad && P [|X - \mathrm{Exp} [X]| \ge \varepsilon] &\le \dfrac{\mathrm{Var} [X]}{\varepsilon^2} \\
> \fbox{2}\Downarrow\quad && P [|X - \mathrm{Exp} [X]| \lt \varepsilon] &\ge 1 - \dfrac{\mathrm{Var} [X]}{\varepsilon^2} \\
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
> P \left[ \lim_{n \to +\infty} \middle| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \middle| \ge \varepsilon \right] &= 0 \\
> P \left[ \lim_{n \to +\infty} \middle| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \middle| \lt \varepsilon \right] &= 1 \\
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

> ### 独立弱大数定律

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           && \ln \lim_{n \to +\infty} \mathrm{Exp} \left[ e^{\imath t \cdot \frac{1}{n} \sum_1^n X_n} \right] &= \lim_{n \to +\infty} \ln \prod_{i = 1}^n \mathrm{Exp} \left[ e^{\imath t \cdot \frac{1}{n} X_i} \right] \quad\Leftarrow\quad p (x_1, \cdots, x_n) = p_{X_1} (x_1) \cdots p_{X_n} (x_n) \\
>                         &&                                                                                                  &\xlongequal{e^x = 1 + x \cdot e^{\theta \cdot x}} \lim_{n \to +\infty} \sum_{i = 1}^n \ln \mathrm{Exp} \left[ 1 + \dfrac{\imath t \cdot X_i}{n} \cdot e^\frac{\theta_{i 1} \imath t \cdot X_i}{n} \right] \\
>                         &&                                                                                                  &\xlongequal{\ln (1 + x) = \frac{x}{1 + \theta \cdot x}} \lim_{n \to +\infty} \sum_{i = 1}^n \dfrac{\mathrm{Exp} \left[ \frac{\imath t \cdot X_i}{n} \cdot e^{\frac{\theta_{i 1} \imath t \cdot X_i}{n}} \right]}{1 + \theta_{i 2} \cdot \mathrm{Exp} \left[ \frac{\imath t \cdot X_i}{n} \cdot e^{\frac{\theta_{i 1} \imath t \cdot X_i}{n}} \right]} \\
> \fbox{1}\Uparrow\quad   &&          P \left[ \lim_{n \to +\infty} \sup_{i \le n} |\theta_{i 1}| \ge \varepsilon \right] = 0 &\iff P \left[ \lim_{n \to +\infty} \sup_{i \le n} \dfrac{|X_i|}{n} \ge \varepsilon \right] = 0 \\
> \fbox{2}\Uparrow\quad   &&          P \left[ \lim_{n \to +\infty} \sup_{i \le n} |\theta_{i 2}| \ge \varepsilon \right] = 0 &\iff P \left[ \lim_{n \to +\infty} \sup_{i \le n} \dfrac{|\mathrm{Exp} [X_i]|}{n} \ge \varepsilon \right] 0 \\
> \Downarrow\quad         && \ln \lim_{n \to +\infty} \mathrm{Exp} \left[ e^{\imath t \cdot \frac{1}{n} \sum_1^n X_n} \right] &= \imath t \cdot \lim_{n \to +\infty} \dfrac{1}{n} \sum_1^n \mathrm{Exp} [X_n] \\
> \Downarrow\quad         &&     \lim_{n \to +\infty} \mathrm{Exp} \left[ e^{\imath t \cdot \frac{1}{n} \sum_1^n X_n} \right] &= e^{\imath t \cdot \lim\limits_{n \to +\infty} \frac{1}{n} \sum_1^n \mathrm{Exp} [X_n]} \\
>                         &&                                                                                                  &= \mathrm{Exp} \left[ e^{\imath t \cdot \lim\limits_{n \to +\infty} \frac{1}{n} \sum_1^n \mathrm{Exp} [X_n]} \right] \\
> \Downarrow\quad         &&                            \lim_{n \to +\infty} P \left[ \dfrac{1}{n} \sum_1^n X_n \le x \right] &\xlongequal[X \equiv \lim\limits_{n \to +\infty} \frac{1}{n} \sum_1^n \mathrm{Exp} \lbrack X_n \rbrack]{\forall x \in \mathcal{Conti.}} P [X \le x] \\
> \fbox{1}\Downarrow\quad &&                                                                           \lim_{n \to +\infty} P & \left[ \left| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \right| \ge \varepsilon \right] = 0 \\
> \fbox{2}\Downarrow\quad &&                                                                           \lim_{n \to +\infty} P & \left[ \left| \dfrac{1}{n} \sum_1^n (X_n - \mathrm{Exp} [X_n]) \right| \lt \varepsilon \right] = 1 \\
> \end{alignedat}
> $$
>

> ### 独立强大数定律

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           && P \left[ \lim_{n \to +\infty} \middle| \dfrac{1}{n} \sum_{i = 1}^{n} (X_i - \mathrm{Exp} [X_i]) \middle| \ge \varepsilon \right] &= P \left[ \lim_{N \to +\infty} \bigcup_{n = N}^{+\infty} \middle( \middle| \dfrac{1}{n} \sum_{i = 1}^n (X_i - \mathrm{Exp} [X_i]) \middle| \ge \varepsilon \middle) \right] \\
>                         &&                                                                                                                                  &= \lim_{N \to +\infty} P \left[ \sup_{n \ge N} \middle| \dfrac{1}{n} \sum_{i = 1}^n (X_i - \mathrm{Exp} [X_i]) \middle| \ge \varepsilon \right] \\
>                         &&                                                                                                                                  &\le \lim_{N \to +\infty} \sup_{n \ge N} \dfrac{1}{n^2 \varepsilon^2} \mathrm{Var} \left[ \sum_{i = 1}^n X_i \right] \\
>                         &&                                                                                                                                  &= \lim_{N \to +\infty} \sup_{n \ge N} \dfrac{1}{n^2 \varepsilon^2} \sum_{i = 1}^n \mathrm{Var} [X_i] \quad\Leftarrow\quad p (x_1, \cdots, x_n) = p_{X_1} (x_1) \cdots p_{X_n} (x_n) \\
>                         &&                                                                                                                                  &\le \lim_{N \to +\infty} \dfrac{1}{N^2 \varepsilon^2} \sum_{i = 1}^N \mathrm{Var} [X_i] + \lim_{N \to +\infty} \sup_{n \ge N} \sum_{i = N + 1}^n \dfrac{\mathrm{Var} [X_i]}{i^2 \varepsilon^2} \\
>                         &&                                                                                                                                  &\le \lim_{N \to +\infty} \dfrac{\max\limits_{i \le N} (\mathrm{Var} [X_i])}{N \varepsilon^2} + \lim_{N \to +\infty} \sum_{i = N + 1}^{+\infty} \dfrac{\mathrm{Var} [X_i]}{i^2 \varepsilon^2} \\
> \Uparrow\quad           &&                                                                           \sum_1^{+\infty} \dfrac{\mathrm{Var} [X_n]}{n^2} \le M &\implies \lim_{N \to +\infty} \sum_{i = N + 1}^{+\infty} \dfrac{\mathrm{Var} [X_i]}{i^2} \to 0 \\
> \fbox{1}\Downarrow\quad && P \left[ \lim_{n \to +\infty} \middle| \dfrac{1}{n} \sum_{i = 1}^{n} (X_i - \mathrm{Exp} [X_i]) \middle| \ge \varepsilon \right] &= 0 \\
> \fbox{2}\Downarrow\quad && P \left[ \lim_{n \to +\infty} \middle| \dfrac{1}{n} \sum_{i = 1}^{n} (X_i - \mathrm{Exp} [X_i]) \middle| \lt \varepsilon \right] &= 1 \\
> \end{alignedat}
> $$
>
