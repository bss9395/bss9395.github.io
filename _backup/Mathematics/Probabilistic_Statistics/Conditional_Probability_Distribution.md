---
layout:    zh_post
Topic:     概率统计
Title:     条件概率分布
Revised:   2018-05-20 17:38:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 条件概率

> $$
> \begin{alignedat}{3}
> P (B | A) = \dfrac{P (B A)}{P (A)} \\
> \end{alignedat}
> $$
>

> ### 条件概率的性质

> $$
> \begin{array}{ll|l}
> \fbox{1} & P (B A) = P (A) \cdot P (B | A) \\
> \fbox{2} & P (A_1 \cdots A_n) = P (A_1 | \Omega) \cdot P (A_2 | A_1) \cdots P (A_n | A_1 \cdots A_{n - 1}) \\
> \end{array}
> $$
>

> ### 全概率

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           & B_n \cap B_m = \varnothing \quad\land\quad \bigcup B_n = \Omega \\
> \Downarrow\quad         & A = A \Omega = A \left( \bigcup B_n \right) = \bigcup (A B_n) \\
> \Downarrow\quad         & P (A) = P \left( \bigcup (A B_n) \right) = \sum P (A B_n) \\
> \fbox{1}\Downarrow\quad & P (A) = \sum P (B_n) \cdot P (A | B_n) \\
> \fbox{2}\Downarrow\quad & P (A) = P (B) \cdot P (A | B) + P (\overline{B}) \cdot P (A | \overline{B}) \\
> \fbox{3}\Downarrow\quad & P (B_i | A) = \dfrac{P (B_i) \cdot P (A | B_i)}{\sum_1^n P (B_n) \cdot P (A | B_n)} \\
> \end{alignedat}
> $$
>

> ### 独立事件

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           &&                     P (B | A) &= P (B) \quad\land\quad P (A | B) = P (A) \\
> \fbox{1}\Downarrow\quad &&                       P (A B) &= P (A) \cdot P (B) \\
> \fbox{2}\Downarrow\quad &&            P (A \overline{B}) &= P (A) - P (A B) \\
>                         &&                               &= P (A) \cdot P (\overline{B}) \\
> \fbox{3}\Downarrow\quad &&            P (\overline{A} B) &= P (B) - P (A B) \\
>                         &&                               &= P (\overline{A}) \cdot P (B) \\
> \fbox{4}\Downarrow\quad && P (\overline{A} \overline{B}) &= P (\overline{A}) - P (\overline{A} B) \\
>                         &&                               &= P (\overline{A}) \cdot P (\overline{B}) \\
> \end{alignedat}
> $$
>

> ### 独立事件的性质

> $$
> \begin{array}{ll|l}
> \fbox{1} & P (A_1 \cdots A_n) = P (A_1) \cdot P (A_2 \cdots A_n) \\
> \fbox{2} & P (A_1 \overline{\cdots A_n}) = P (A_1) \cdot P (\overline{A_2 \cdots A_n}) \\
> \fbox{3} & P (\overline{A_1} \cdots A_n) = P (\overline{A_1}) \cdot P (A_2 \cdots A_n) \\
> \fbox{4} & P (\overline{A_1 \cdots A_n}) = P (\overline{A_1}) \cdot P (\overline{A_2 \cdots A_n}) \\
> \end{array}
> $$
>

> ### 独立随机变量

> $$
> \begin{alignedat}{3}
> \forall x_1, \cdots, x_m;\;  J (x_1, \cdots, x_m) &= M_{X_1} (x_1) \cdots M_{X_m} (x_m) \\
> \end{alignedat}
> $$
>

> ### 独立随机变量的性质

> $$
> \begin{alignedat}{3}
> \forall x_1, \cdots, x_m;\; p (x_1, \cdots, x_m) = p_{X_1} (x_1) \cdots p_{X_m} (x_m) \\
> \end{alignedat}
> $$
>

> ### 条件概率分布

> $$
> \begin{alignedat}{3}
> p_{X_1, \cdots, X_m} (x_1, \cdots, x_m \mid y_1, \cdots, y_n) &= \dfrac{p (x_1, \cdots, x_m, y_1, \cdots, y_n)}{p_{Y_1, \cdots, Y_n} (y_1, \cdots, y_n)} \\
>                                                p_X (x \mid y) &= \dfrac{p (x, y)}{p_Y (y)} \\
> \end{alignedat}
> $$
>