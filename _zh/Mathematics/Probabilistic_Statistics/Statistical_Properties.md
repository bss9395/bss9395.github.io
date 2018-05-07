---
layout:    zh_post
Topic:     概率统计
Title:     统计特性
Revised:   2018-05-08 04:16:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 离散期望值

> $$
> \begin{alignedat}{3}
>     \mathrm{E_{xpected}} [X] &= \sum x_i \cdot p (x_i)     &&\;\Leftarrow\; \sum |x_i| \cdot p (x_i) \to \mathcal{Conv.} \\
> \mathrm{E_{xpected}} [f (X)] &= \sum f (x_i) \cdot p (x_i) &&\;\Leftarrow\; \sum |f (x_i)| \cdot p (x_i) \to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 连续期望值

> $$
> \begin{alignedat}{3}
>     \mathrm{E_{xpected}} [X] &= \int x \cdot p (x) \mathrm{d} x     &&\;\Leftarrow\; \int |x| \cdot p (x) \mathrm{d} x \to \mathcal{Conv.} \\
> \mathrm{E_{xpected}} [f (X)] &= \int f (x) \cdot p (x) \mathrm{d} x &&\;\Leftarrow\; \int |f (x)| \cdot p (x) \mathrm{d} x \to \mathcal{Conv.} \\ 
> \end{alignedat}
> $$
>

> ### 期望值的性质

> $$
> \begin{array}{lll}
> \fbox{1} & \mathrm{E} [c] = c \\
> \fbox{2} & \mathrm{E} [c \cdot X] = c \cdot \mathrm{E} [X] \\
> \fbox{3} & \mathrm{E} [f (X) + g (X)] = \mathrm{E} [f (X)] + \mathrm{E} [g (X)] \\
> \end{array}
> $$
>

> ### 方差

> $$
> \begin{alignedat}{3}
> \mathrm{Var_{riance}} [X] &= E [X - E [X]]^2 \\
>                           &= E [X^2 - 2 X \cdot E [X] + E^2 [X]] \\
>                           &= E [X]^2 - E^2 [X] \\
> \end{alignedat}
> $$
>

> ### 方差的性质

> $$
> \begin{array}{lll}
> \fbox{1} & \mathrm{Var} [c] = 0 \\
> \fbox{2} & \mathrm{Var} [c \cdot X + d] = c^2 \cdot \mathrm{Var} [X] \\
> \fbox{3} & \mathrm{Var} [X] + \mathrm{E}^2 [X] = \mathrm{E} [X]^2 = 0 \implies \mathrm{E} [X] = 0 \;\and\; \mathrm{Var} [X] = 0 \\
> \fbox{4} & \mathrm{Var} [X] = 0 \iff P (X = \mathrm{E} [X]) = 1  \\
> \end{array}
> $$
>

> ### 标准差

> $$
> \begin{alignedat}{3}
> \mathrm{S_{tandard} D_{eviation}} [X] &= \sqrt{\mathrm{Var} [X]} \\
>                                       &= \sqrt{E [X]^2 - E^2 [X]} \\
> \end{alignedat}
> $$
>

> ### 偏差概率

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   && P (|X - \mathrm{E} [X]| \ge \varepsilon) &= \sum_{|x_i - \mathrm{E} [X]| \ge \varepsilon} p (x_i) \\
>                 &&                                          &\le \sum_{|x_i - \mathrm{E} [X]| \ge \varepsilon} \dfrac{(x_i - \mathrm{E} [X])^2}{\varepsilon^2} p (x_i) \\
>                 &&                                          &\le \sum \dfrac{(x_i - \mathrm{E} [X])^2}{\varepsilon^2} p (x_i) \\
>                 &&                                          &= \dfrac{\mathrm{Var} [X]}{\varepsilon^2} \\
> \Downarrow\quad && P (|X - \mathrm{E} [X]| \lt \varepsilon) &= 1 - P (|X - \mathrm{E} [X]| \ge \varepsilon) \\
>                 &&                                          &\ge 1 - \dfrac{\mathrm{Var} [X]}{\varepsilon^2} \\
> \end{alignedat}
> $$
>

> ### 阅读文摘

> **分赌本问题**  17世纪中叶，一位赌徒向法国数学家帕斯卡 (Pascal, 1623~1662) 提出一个使他苦恼长久的分赌本问题：甲、乙两赌徒赌技不相上下，各出赌注 $50$ 法郎，每局中无平局。他们约定，谁先赢三局，则得全部赌本 $100$ 法郎。当甲赢了二局、乙赢了一局时，因故（国王召见）要中止赌博。现问这 $100$ 法郎如何分才算公平？
>
> 这个问题引起了不少人的兴趣。首先大家都认识到：平均分对甲不公平，全部归甲对乙不公平。合理的分法是，按一定的比例，甲多分些，乙少分些。所以问题的焦点在于：按怎样的比例来分？以下有两种分法：
>
> 1. 甲得 $100$ 法郎中的 $2/3$ ，乙得 $100$ 法郎中的 $1/3$ .这是基于已赌局数：甲赢了二局、乙赢了一局。
>
> 2. 1654年帕斯卡提出如下的分法：设想再赌下去，则甲最终所得 $X$ 为一个随机变量，其可能取值为 $0$ 或 $100$ .再赌两局必可结束，其结果不外乎以下四种情况之一：
>    $$
>    \text{甲甲、甲乙、乙甲、乙乙}
>    $$
>    其中，“甲乙”表示第一局甲胜第二局乙胜。在这四种情况中有三种可使甲获 $100$ 法郎，只有一种情况（乙乙）下甲获 $0$ 法郎。因为赌技不相上下，所以甲获得 $100$ 法郎的可能性为 $3/4$ ，获得 $0$ 法郎的可能性为 $1/4$ ，即 $X$ 的分布列为
>    $$
>    \begin{array}{c|cc}
>    X & 0    & 100 \\
>    \hline
>    P & 0.25 & 0.75 \\
>    \end{array}
>    $$
>    经上述分析，帕斯卡认为，甲的“期望”所得应为：$0 \times 0.25 + 100 \times 0.75 = 75$ (法郎)。即甲得 $75$ 法郎，乙得 $25$ 法郎。这种分法不仅考虑了已赌局数，还包括了对再赌下去的一种“期望”，它比分法一更为合理。
>
> 这就是数学期望这个名称的由来，其实这个名称称为“均值”更形象易懂，对上例而言，也就是再赌下去的话，甲“平均”可以赢 $75$ 法郎。
