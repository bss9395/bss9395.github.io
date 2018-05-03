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
> \fbox{01} & A \cup B = B \cup A                                                                       & \\
> \fbox{02} & A \cap B = B \cap A                                                                       & A B = B A \\
> \fbox{03} & (A \cup B) \cup C = A \cup (B \cup C)                                                     & \\
> \fbox{04} & (A \cap B) \cap C = A \cap (B \cap C)                                                     & (A B) C = A (B C) \\
> \fbox{05} & (A \cup B) \cap C = (A \cap C) \cup (B \cap C)                                            & \\
> \fbox{06} & (A \cap B) \cup C = (A \cup C) \cap (B \cup C)                                            & \\
> \fbox{07} & \overline{A \cup B} = \overline{A} \cap \overline{B}                                      & \overline{\bigcup A_n} = \bigcap \overline{A_n} \\
> \fbox{08} & \overline{A\cap B} = \overline{A} \cup \overline{B}                                       & \overline{\bigcap A_n} = \bigcup \overline{A_n} \\
> \fbox{09} & A - B = A \overline{B}                                                                    & A - B = A - A B \\
> \fbox{10} & A \cup B = (A \overline{B}) \cup B                                                        & A \cup B = (A - A B) \cup B \\
> \fbox{11} & E_n \subseteq E_{n + 1} \implies \lim\limits_{+\infty} E_n = \bigcup\limits^{+\infty} E_n & \\
> \fbox{12} & E_n \supseteq E_{n + 1} \implies \lim\limits_{+\infty} E_n = \bigcap\limits^{+\infty} E_n & \\
> \end{array}
> $$
>

> ### 事件域

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \Omega \in \mathscr{E} \\
> \fbox{2}\quad & E \in \mathscr{E} \implies \overline{E} \in \mathscr{E} \\
> \fbox{3}\quad & E \in \mathscr{E} \implies \bigcup E_n \in \mathscr{E} \\
> \end{alignedat}
> $$
>

> ### 古典概率

> $$
> \begin{alignedat}{3}
> P (E) = \dfrac{N_{umber} (E)}{N_{umber} (\Omega)} \\
> \end{alignedat}
> $$
>

> ### 频率概率

> $$
> \begin{alignedat}{3}
> P (E) &= \lim_{+\infty} \left\langle f_n (E) = \dfrac{T_{rial} (E)}{T_{rial} (\Omega)} \right\rangle \\
> \end{alignedat}
> $$
>

> ### 几何概率

> $$
> \begin{alignedat}{3}
> P (E) = \dfrac{S_{ize} (E)}{S_{ize} (\Omega)} \\
> \end{alignedat}
> $$
>

> ### 主观概率

> $$
> \begin{alignedat}{3}
> P (E) = C_{onfidence} (E) \\
> \end{alignedat}
> $$
>

> ### 公理化概率

> $$
> \begin{array}{lll}
> \fbox{1} & \text{Non-Negativity:}       & E \in \mathscr{E} \implies 0 \le P (E) \\
> \fbox{2} & \text{Regularity:}           & P (\Omega) = 1 \\
> \fbox{3} & \text{Countable Additivity:} & E_n \cap E_m = \varnothing \implies P \left( \bigcup E_n \right) = \sum P (E_n) \\
> \end{array}
> $$
>

> ### 概率的性质

> $$
> \begin{array}{ll|l}
> \fbox{01} & P (\varnothing) = 0                                                                                             & \\
> \fbox{02} & P (\overline{A}) = 1 - P (A)                                                                                    & P (A) + P (\overline{A}) = 1 \\
> \fbox{03} & P (A \overline{B}) = P (A) - P (A B)                                                                            & P (A) \ge P (A B) \\
> \fbox{04} & P (A \cup B) = P (A) + P (B) - P (A B)                                                                          & P (A) + P (B) \ge P (A \cup B) \\
> \fbox{05} & P (\bigcup A_n) = \sum\limits_1^n (- 1)^{n - 1} \sum\limits_{1 \le i \le \cdots \le j \le n} P (A_i \cdots A_j) & \sum P (A_n) \ge P (\bigcup A_n) \\
> \fbox{06} & \lim\limits_{+\infty} P (E_n) = P \left( \lim\limits_{+\infty} E_n \right)                                      & \\
> \end{array}
> $$
>

> ### 阅读文摘

> 在概率论发展的历史上，曾有过概率的古典定义、概率的几何定义、概率的频率定义和概率的主观定义。这些定义各适合一类随机现象。那么如何给出适合一切随机现象的概率的最一般的定义呢？1900年数学家希尔伯特（Hilbert，1862~1943）提出要建立概率的公理化定义以解决这个问题，即以最少的几条本质特性出发去刻画概率的概念。1933年苏联数学家柯尔莫哥洛夫（Kolmogorov，1903~1987）首次提出了概率的公理化定义，这个定义既概括了历史上几种概率定义中的共同特性，又避免了各自的局限性和含混之处，不管什么随机现象，只有满足该定义中的三条公理，才能说它是概率。这一公理化体系迅速获得举世公认，是概率论发展史上的一个里程碑。有了这个公理化定义以后，概率论得到了迅速发展。
>
> ——《$\S$ 1.2 概率的定义及其确定方法》
> ——《概率论与数理统计教程 (第二版)》茆诗松/程依明/濮晓龙/等著
