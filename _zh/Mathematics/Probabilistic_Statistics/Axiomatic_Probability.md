---
layout:    zh_post
Topic:     概率统计
Title:     公理化概率
Revised:   2018-05-02 20:01:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 事件的性质

> $$
> \begin{array}{ll|l}
> \fbox{1}\; & A \cup B = B \cup A &A B = B A \\
> \fbox{2}\; & (A \cup B) \cup C = A \cup (B \cup C) & (A B) C = A (B C) \\
> \fbox{3}\; & (A \cup B) \cap C = (A \cap C) \cup (B \cap C) \\
> \fbox{4}\; & (A \cap B) \cup C = (A \cup C) \cap (B \cup C) \\
> \fbox{5}\; & \overline{A \cup B} = \overline{A} \cap \overline{B} & \overline{\bigcup A_n} = \bigcap \overline{A_n} \\
> \fbox{6}\; & \overline{A \cap B} = \overline{A} \cup \overline{B} & \overline{\bigcap A_n} = \bigcup \overline{A_n} \\
> \end{array}
> $$
>

> ### 事件域

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \Omega \in \mathscr{J} \\
> \fbox{2}\quad & A \in \mathscr{J} \implies \overline{A} \in \mathscr{J} \\
> \fbox{3}\quad & A \in \mathscr{J} \implies \bigcup A_n \in \mathscr{J} \\
> \end{alignedat}
> $$
>

> ### 公理化概率

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \text{Non-Negativity:}\quad && A \in \mathscr{J} \implies 0 \le P (A) \\
> \fbox{2}\quad & \text{Regularity:}\quad && P (\Omega) = 1 \\
> \fbox{3}\quad & \text{Countable Additivity:}\quad && A_n \cap A_m = \emptyset \implies P \left( \bigcup A_n \right) = \sum P (A_n) \\
> \end{alignedat}
> $$
>

> ### 古典概率

> $$
> \begin{alignedat}{3}
> P (A) = \dfrac{k}{n} \\
> \end{alignedat}
> $$
>

> ### 频率概率

> $$
> \begin{alignedat}{3}
> P (A) &= \lim_{+\infty} \left\langle f_n (A) = \dfrac{n (A)}{n} \right\rangle \\
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

> ### 阅读文摘

> 在概率论发展的历史上，曾有过概率的古典定义、概率的几何定义、概率的频率定义和概率的主观定义。这些定义各适合一类随机现象。那么如何给出适合一切随机现象的概率的最一般的定义呢？1900年数学家希尔伯特（Hilbert，1862~1943）提出要建立概率的公理化定义以解决这个问题，即以最少的几条本质特性出发去刻画概率的概念。1933年苏联数学家柯尔莫哥洛夫（Kolmogorov，1903~1987）首次提出了概率的公理化定义，这个定义既概括了历史上几种概率定义中的共同特性，又避免了各自的局限性和含混之处，不管什么随机现象，只有满足该定义中的三条公理，才能说它是概率。这一公理化体系迅速获得举世公认，是概率论发展史上的一个里程碑。有了这个公理化定义以后，概率论得到了迅速发展。
> 
> ——摘录自《概率论与数理统计教程 (第二版)》茆诗松/程依明/濮晓龙 等著

