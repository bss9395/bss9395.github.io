---
layout:    zh_post
Topic:     概率统计
Title:     大数定理
Revised:   2018-05-25 23:22:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ###  累积概率不等式

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           && P [|X| \ge \varepsilon] &= \mathop{\left\langle \sum \int \right\rangle}_{|x| \ge \varepsilon} p (x) \\
>                         &&                         &\le \mathop{\left\langle \sum \int \right\rangle}_{|x| \ge \varepsilon} \dfrac{|x| \cdot p (x)}{\varepsilon} \\
>                         &&                         &\le \dfrac{1}{\varepsilon} \mathop{\left\langle \sum \int \right\rangle}_{x} |x| \cdot p (x) \\
> \fbox{1}\Downarrow\quad && P [|X| \ge \varepsilon] &\le \dfrac{\mathrm{Exp} [|X|]}{\varepsilon} \\
> \fbox{2}\Downarrow\quad && P [|X| \lt \varepsilon] &\ge 1 - \dfrac{\mathrm{Exp} [|X|]}{\varepsilon} \\
> \end{alignedat}
> $$
>

> ### 偏差概率不等式

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           && P (|X - \mathrm{Exp} [X]| \ge \varepsilon) &= \mathop{\left\langle \sum \int \right\rangle}\limits_{|x - \mathrm{Exp} [X]| \ge \varepsilon} p (x) \\
>                         &&                                            &\le \mathop{\left\langle \sum \int \right\rangle}\limits_{|x - \mathrm{Exp} [X]| \ge \varepsilon} \dfrac{(x - \mathrm{Exp} [X])^2}{\varepsilon^2} p (x) \\
>                         &&                                            &\le \mathop{\left\langle \sum \int \right\rangle}_{x} \dfrac{(x - \mathrm{Exp} [X])^2}{\varepsilon^2} p (x) \\
> \fbox{1}\Downarrow\quad && P (|X - \mathrm{Exp} [X]| \ge \varepsilon) &\le \dfrac{\mathrm{Var} [X]}{\varepsilon^2} \\
> \fbox{2}\Downarrow\quad && P (|X - \mathrm{Exp} [X]| \lt \varepsilon) &\ge 1 - \dfrac{\mathrm{Var} [X]}{\varepsilon^2} \\
> \end{alignedat}
> $$
>

> ### 弱大数定理

> $$
> \begin{alignedat}{3}
>
> \end{alignedat}
> $$
>