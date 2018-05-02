---
layout:    zh_post
Topic:     概率统计
Title:     公理化概率
Revised:   2018-05-03 01:03:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 事件的性质

> $$
> \begin{array}{ll|l}
> \fbox{01} & A \cup B = B \cup A                                                                       & A B = B A \\
> \fbox{02} & (A \cup B) \cup C = A \cup (B \cup C)                                                     & (A B) C = A (B C) \\
> \fbox{03} & (A \cup B) \cap C = (A \cap C) \cup (B \cap C)                                            & \\
> \fbox{04} & (A \cap B) \cup C = (A \cup C) \cap (B \cup C)                                            & \\
> \fbox{05} & \overline{A \cup B} = \overline{A} \cap \overline{B}                                      & \overline{\bigcup A_n} = \bigcap \overline{A_n} \\
> \fbox{06} & \overline{A \cap B} = \overline{A} \cup \overline{B}                                      & \overline{\bigcap A_n} = \bigcup \overline{A_n} \\
> \fbox{07} & A - B = A - A B                                                                           & A B \subseteq A \\
> \fbox{08} & A \cup B = (A - B) \cup B                                                                 & A \cup B = (A - A B) \cup B \\
> \fbox{09} & A \overline{B} = A - B                                                                    & A \overline{B} = A - A B \\
> \fbox{10} & E_n \subseteq E_{n + 1} \implies \lim\limits_{+\infty} E_n = \bigcup\limits^{+\infty} E_n & E_n \supseteq E_{n + 1} \implies \lim\limits_{+\infty} E_n = \bigcap\limits^{+\infty} E_n \\
> \end{array}
> $$
>

> ### 事件域

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \Omega \in \mathscr{E} \\
> \fbox{2}\quad & A \in \mathscr{E} \implies \overline{A} \in \mathscr{E} \\
> \fbox{3}\quad & A \in \mathscr{E} \implies \bigcup A_n \in \mathscr{E} \\
> \end{alignedat}
> $$
>

> ### 古典概率

> $$
> \begin{alignedat}{3}
> P (A) = \dfrac{n_A}{N} \\
> \end{alignedat}
> $$
>

> ### 频率概率

> $$
> \begin{alignedat}{3}
> P (A) &= \lim_{+\infty} \left\langle f_n (A) = \dfrac{n (A)}{N} \right\rangle \\
> \end{alignedat}
> $$
>

> ### 几何概率

> $$
> \begin{alignedat}{3}
> P (A) = \dfrac{S_A}{S_\Omega} \\
> \end{alignedat}
> $$
>

> ### 主观概率

> 一个事件的概率是人们根据经验对该事件发生的可能性所给出的个人信念。

> ### 公理化概率

> $$
> \begin{array}{lll}
> \fbox{1} & \text{Non-Negativity:}       & A \in \mathscr{E} \implies 0 \le P (A) \\
> \fbox{2} & \text{Regularity:}           & P (\Omega) = 1 \\
> \fbox{3} & \text{Countable Additivity:} & A_n \cap A_m = \emptyset \implies P \left( \bigcup A_n \right) = \sum P (A_n) \\
> \end{array}
> $$
>

> ### 概率的性质

> $$
> \begin{array}{ll|l}
> \fbox{1} & P (\varnothing) = 0                                                                                             & \\
> \fbox{2} & P (\overline{A}) = 1 - P (A)                                                                                    & P (A) + P (\overline{A}) = 1 \\
> \fbox{3} & A \supseteq B \implies P (A - B) = P (A) - P (B)                                                                & P (B) \le P (A) \\
> \fbox{4} & P (A - B) = P (A) - P (A B)                                                                                     & P (A B) \le P (A) \\
> \fbox{5} & P (A \cup B) = P (A) + P (B) - P (A B)                                                                          & P (A \cup B) \le P (A) + P (B)  \\
> \fbox{6} & P (\bigcup A_n) = \sum\limits_1^n (- 1)^{n - 1} \sum\limits_{1 \le i \le \cdots \le j \le n} P (A_i \cdots A_j) & P (\bigcup A_n) \le \sum P (A_n) \\
> \fbox{7} & \lim\limits_{+\infty} P (E_n) =P \left( \lim\limits_{+\infty} E_n \right)                                       & \\
>
> \end{array}
> $$
>

> ### 阅读文摘

> 在概率论发展的历史上，曾有过概率的古典定义、概率的几何定义、概率的频率定义和概率的主观定义。这些定义各适合一类随机现象。那么如何给出适合一切随机现象的概率的最一般的定义呢？1900年数学家希尔伯特（Hilbert，1862~1943）提出要建立概率的公理化定义以解决这个问题，即以最少的几条本质特性出发去刻画概率的概念。1933年苏联数学家柯尔莫哥洛夫（Kolmogorov，1903~1987）首次提出了概率的公理化定义，这个定义既概括了历史上几种概率定义中的共同特性，又避免了各自的局限性和含混之处，不管什么随机现象，只有满足该定义中的三条公理，才能说它是概率。这一公理化体系迅速获得举世公认，是概率论发展史上的一个里程碑。有了这个公理化定义以后，概率论得到了迅速发展。
>
> ——《$\S$ 1.2 概率的定义及其确定方法》
> ——《概率论与数理统计教程 (第二版)》茆诗松/程依明/濮晓龙/等著

