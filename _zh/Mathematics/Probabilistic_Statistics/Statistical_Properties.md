---
layout:    zh_post
Topic:     概率统计
Title:     统计特性
Revised:   2018-05-23 21:14:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 离散期望值 $\mathrm{Exp_{ectation}}$

> $$
> \begin{alignedat}{3}
>                    \mathrm{Exp} [X] &= \sum_{x} x \cdot p (x)                                         &&\quad\Leftarrow\quad \sum_{x} |x| \cdot p (x) \to \mathcal{Conv.} \\
>                \mathrm{Exp} [f (X)] &= \sum_{(x)_j} (y)_j \cdot P [f (X) = (y)_j] \\
>                                     &= \sum_{(x)_j} f (x)_j \sum_{(x)_i : f (x)_i = f (x)_j} p (x)_i \\
>                                     &= \sum_{(x)_i} p (x)_i \sum_{(x)_j : f (x)_j = f (x)_i}  f (x)_j \\
>                                     &= \sum_{x} f (x) \cdot p (x)                                     &&\quad\Leftarrow\quad \sum_{x} |f (x)| \cdot p (x) \to \mathcal{Conv.} \\
>                  \mathrm{Exp} [X]^h &= \sum_{x} x^h \cdot p (x)                                       &&\quad\Leftarrow\quad f (X) = X^h \\
> \end{alignedat} \\
> \begin{alignedat}{3}
> \mathrm{Exp} [f (X_1, \cdots, X_m)] &= \sum_{(x_1, \cdots, x_m)_j} (y)_j \cdot P [f (X_1, \cdots, X_m) = (y)_j] \\
>                                     &= \sum_{(x_1, \cdots, x_m)_j} f (x_1, \cdots, x_m)_j \sum_{(x_1, \cdots, x_m)_i : f (x_1, \cdots, x_m)_i = f (x_1, \cdots, x_m)_j} p (x_1, \cdots, x_m)_i \\
>                                     &= \sum_{(x_1, \cdots, x_m)_i} p (x_1, \cdots, x_m)_i \sum_{(x_1, \cdots, x_m)_j : f (x_1, \cdots, x_m)_j = f (x_1, \cdots, x_m)_i} f (x_1, \cdots, x_m)_j \\
>                                     &= \sum_{x_1} \cdots \sum_{x_m} f (x_1, \cdots, x_m) \cdot p (x_1, \cdots, x_m) \\
> \end{alignedat}
> $$
>

> ### 连续期望值 $\mathrm{Exp_{ectation}}$

> $$
> \begin{alignedat}{3}
>                    \mathrm{Exp} [X] &= \int_x x \cdot p (x) \mathrm{d} x                                                                                                                   &&\quad\Leftarrow\quad \int_x |x| \cdot p (x) \mathrm{d} x \to \mathcal{Conv.} \\
>                \mathrm{Exp} [f (X)] &= \int_0^{+\infty} P [f (X) \ge y] \mathrm{d} y - \int_0^{+\infty} P [f (X) \lt - y] \mathrm{d} y \\
>                                     &= \int_0^{+\infty} \int_{x : f (x) \ge y} p (x) \mathrm{d} x \mathrm{d} y - \int_0^{+\infty} \int_{x : - f (x) \gt y} p (x) \mathrm{d} x \mathrm{d} y \\
>                                     &= \int_{x : f (x) \ge 0} p (x) \int_0^{f (x)} \mathrm{d} y \mathrm{d} x - \int_{x : f (x) \lt 0} p (x) \int_{0}^{- f (x)} \mathrm{d} y \mathrm{d} x \\
>                                     &= \int_x f (x) \cdot p (x) \mathrm{d} x                                                                                                               &&\quad\Leftarrow\quad \int_x |f (x)| \cdot p (x) \mathrm{d} x \to \mathcal{Conv.} \\ 
>                  \mathrm{Exp} [X]^h &= \int_x x^h \cdot p (x) \mathrm{d} x                                                                                                                 &&\quad\Leftarrow\quad f (X) = X^h \\
> \end{alignedat} \\
> \begin{alignedat}{3}
> \mathrm{Exp} [f (X_1, \cdots, X_m)] &= \int_0^{+\infty} P [f (X_1, \cdots, X_m) \ge y] \mathrm{d} y - \int_0^{+\infty} P [f (X_1, \cdots, X_m) \lt - y] \mathrm{d} y \\
>                                     &= \int_0^{+\infty} \int_{(x_1, \cdots, x_m) : f (x_1, \cdots, x_m) \ge y} p (x_1, \cdots, x_m) \mathrm{d} (x_1, \cdots, x_m) \mathrm{d} y - \int_0^{+\infty} \int_{(x_1, \cdots, x_m) : f (x_1, \cdots, x_m) \lt y} p (x_1, \cdots, x_m) \mathrm{d} (x_1, \cdots, x_m) \mathrm{d} y \\
>                                     &= \int_{(x_1, \cdots, x_m) : f (x_1, \cdots, x_m) \ge 0} p (x_1, \cdots, x_m) \int_0^{f (x_1, \cdots, x_m)} \mathrm{d} y \mathrm{d} (x_1, \cdots, x_m) - \int_{(x_1, \cdots, x_m) : f (x_1, \cdots, x_m) \lt 0} p (x_1, \cdots, x_m) \int_0^{- f (x_1, \cdots, x_m)} \mathrm{d} y \mathrm{d} (x_1, \cdots, x_m) \\
>                                     &= \int_{x_1} \cdots \int_{x_m} f (x_1, \cdots, x_m) p (x_1, \cdots, x_m) \mathrm{d} x_1 \cdots \mathrm{d} x_m \\
> \end{alignedat}
> $$
>

> ### 期望值的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \mathrm{Exp} [c] = c \\
> \fbox{2}\quad & \mathrm{Exp} [c \cdot X + d] = c \cdot \mathrm{E} [X] + d \\
> \fbox{3}\quad & \mathrm{Exp} [X - \mathrm{Exp} [X]]^h = \sum_{i = 0}^h {h \choose i} (- \mathrm{Exp} [X])^{h - i} \cdot \mathrm{Exp} [X]^i \\
> \fbox{4}\quad & \mathrm{Exp} [f_1 (X_1) + \cdots + f_m (X_m)] = \mathrm{Exp} [f (X_1)] + \cdots + \mathrm{Exp} [f_m (X_m)] \\
> \fbox{5}\quad & \mathrm{Exp} [f_1 (X_1) \cdots f_m (X_m)] = \mathrm{Exp} [f_1 (X_1)] \cdots \mathrm{Exp} [f_m (X_m)] &&\;\Leftarrow\; p (x_1, \cdots, x_m) = p_{X_1} (x_1) \cdots p_{X_m} (x_m) \\
> \end{alignedat}
> $$
>

> ### 矩母函数 $\mathrm{M_{oment} G_{enerating} F_{unction}}$

> $$
> \begin{alignedat}{3}
>                      \mathrm{MGF} [t \cdot X] &= \mathrm{Exp} [e^{t \cdot X}] \\
> \mathrm{MGF} [t \cdot (X - \mathrm{Exp} [X])] &= e^{- t \cdot \mathrm{Exp} [X]} \cdot \mathrm{Exp} [e^{t \cdot X}] \\
>                            \mathrm{Exp} [X]^h &= \lim_{t \to 0} \dfrac{\mathrm{d}^h}{\mathrm{d} t^h} \mathrm{MGF} [t \cdot X] \\
>         \mathrm{Exp} [X - \mathrm{Exp} [X]]^h &= \lim_{t \to 0} \dfrac{\mathrm{d}^h}{\mathrm{d} t^h} \mathrm{MGF} [t \cdot (X - \mathrm{Exp} [X])] \\
> \end{alignedat}
> $$
>

> ### 矩母函数的性质

> $$
> \begin{alignedat}{3}
> \mathrm{MGF} \left[ t \cdot [ f_1 (X_1) + \cdots + f_m (X_m) ] \right] &= \mathrm{MGF} [t \cdot f_1 (X_1)] \cdots \mathrm{MGF} [t \cdot f_m (X_m)] \quad\Leftarrow\quad p (x_1, \cdots, x_m) = p_{X_1} (x_1) \cdots p_{X_m} (x_m) \\
> \end{alignedat}
> $$
>

> ### 协方差 $\mathrm{CoV_{ariance}}$

> $$
> \begin{alignedat}{3}
> \mathrm{CoV} [X, Y] &=  \mathrm{Exp} [(X - \mathrm{Exp} [X]) \cdot (Y - \mathrm{Exp} [Y])] \\
>                     &= \mathrm{Exp} [X Y - X \cdot \mathrm{Exp} [Y] - Y \cdot \mathrm{Exp} [X] + \mathrm{Exp} [X] \cdot \mathrm{Exp} [Y]] \\
>                     &= \mathrm{Exp} [X Y] - \mathrm{Exp} [X] \cdot \mathrm{Exp} [Y] \\
> \end{alignedat}
> $$
>

> ### 协方差的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \mathrm{CoV} [c, Y] = 0 \\
> \fbox{2}\quad & \mathrm{CoV} [X, Y] = \mathrm{CoV} [Y, X] \\
> \fbox{3}\quad & \mathrm{CoV} [c X, Y] = c \cdot \mathrm{CoV} [X, Y] \\
> \fbox{4}\quad & \mathrm{CoV} \left[ \sum_1^n f_n (X_n), \sum_1^m g_m (Y_m) \right] = \sum_1^n \sum_1^m \mathrm{CoV} [f_n (X_n), g_m (Y_m)] \\
> \fbox{5}\quad & p (x, y) = p_X (x) \cdot p_Y (y) \quad\Rightarrow\quad \mathrm{CoV} [f (X), g (Y)] = 0 \\
> \fbox{6}\quad & \mathrm{CoV}^2 [X, Y] \le \mathrm{Var} [X] \cdot \mathrm{Var} [Y] \\
> \end{alignedat}
> $$
>

> ### 方差 $\mathrm{Var_{iance}}$

> $$
> \begin{alignedat}{3}
> \mathrm{Var} [X] &= \mathrm{CoV} [X, X] \\
>                  &= \mathrm{Exp} [X]^2 - \mathrm{Exp}^2 [X] \\
> \end{alignedat}
> $$
>

> ### 方差的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\quad & \mathrm{Var} [c] = 0 \\
> \fbox{2}\quad & \mathrm{Var} [c \cdot X + d] = c^2 \cdot \mathrm{Var} [X] \\
> \fbox{3}\quad & \mathrm{Var} [X] + \mathrm{Exp}^2 [X] = \mathrm{Exp} [X]^2 = 0 \implies \mathrm{Exp} [X] = 0 \;\and\; \mathrm{Var} [X] = 0 \\
> \fbox{4}\quad & \mathrm{Var} [X] = 0 \iff P (X = \mathrm{Exp} [X]) = 1  \\
> \fbox{5}\quad & \mathrm{Var} \left[ \sum_1^n f_n (X_n) \right] = \sum_1^n \mathrm{Var} [f_n (X_n)] + 2 \sum_{i = 1}^n \sum_{j = 1}^{i - 1} \mathrm{CoV} [f_i (X_i), f_j (X_j)] \\
> \fbox{6}\quad & \mathrm{Var} \left[ \sum_1^n f_n (X_n) \right] = \sum_1^n \mathrm{Var} [f_n (X_n)] \quad\Leftarrow\quad p (x_1, \cdots, x_m) = p_{X_1} (x_1) \cdots p_{X_m} (x_m) \\
> \end{alignedat}
> $$
>

> ### 标准差 $\mathrm{S_{tandard} D_{eviation}}$

> $$
> \begin{alignedat}{3}
> \mathrm{SD} [X] &= \sqrt{\mathrm{Var} [X]} \\
>                 &= \sqrt{\mathrm{Exp} [X]^2 - \mathrm{Exp}^2 [X]} \\
> \end{alignedat}
> $$
>

> ### 偏差概率

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   && P (|X - \mathrm{Exp} [X]| \ge \varepsilon) &= \mathop{\left\langle \sum \int \right\rangle}\limits_{|x_i - \mathrm{Exp} [X]| \ge \varepsilon} p (x_i) \\
>                 &&                                            &\le \mathop{\left\langle \sum \int \right\rangle}\limits_{|x_i - \mathrm{Exp} [X]| \ge \varepsilon} \dfrac{(x_i - \mathrm{Exp} [X])^2}{\varepsilon^2} p (x_i) \\
>                 &&                                            &\le {\left\langle \sum \int \right\rangle} \dfrac{(x_i - \mathrm{Exp} [X])^2}{\varepsilon^2} p (x_i) \\
>                 &&                                            &= \dfrac{\mathrm{Var} [X]}{\varepsilon^2} \\
> \Downarrow\quad && P (|X - \mathrm{Exp} [X]| \lt \varepsilon) &= 1 - P (|X - \mathrm{Exp} [X]| \ge \varepsilon) \\
>                 &&                                            &\ge 1 - \dfrac{\mathrm{Var} [X]}{\varepsilon^2} \\
> \end{alignedat}
> $$
>

> ### 分位数 $\mathrm{Quan_{tile}}$

> $$
> \begin{alignedat}{3}
> & \mathrm{Quan} [_q X] = x \iff C (x) = q \\
> & \mathrm{Quan} [^q X] = x \iff 1 - C (x) = q \\
> & \mathrm{Quan} [_q X] = \mathrm{Qua} [^{1 - q} X] \\
> \end{alignedat}
> $$
>

> ### 变异度 $\mathrm{Coe_{fficient} {_{of}} {_{variance}}}$

> $$
> \begin{alignedat}{3}
> \mathrm{Coe} [X] = \dfrac{\mathrm{SD} [X]}{\mathrm{Exp} [X]} \\
> \end{alignedat}
> $$
>

> ### 偏度 $\mathrm{Skew_{ness}}$

> $$
> \begin{alignedat}{3}
> \mathrm{Skew} [X] = \dfrac{\mathrm{Exp} [X - \mathrm{Exp} [X]]^3}{\mathrm{SD}^3 [X]} \\
> \end{alignedat}
> $$
>

> ### 峰度 $\mathrm{Kurt_{osis}}$

> $$
> \begin{alignedat}{3}
> \mathrm{Kurt} [X] &= \dfrac{\mathrm{Exp} [X - \mathrm{Exp} [X]]^4}{\mathrm{SD}^4 [X]} - \mathrm{Exp} [\mathrm{No} (0, 1^2)]^4 \\
>                   &= \dfrac{\mathrm{Exp} [X - \mathrm{Exp} [X]]^4}{\mathrm{SD}^4 [X]} - 3 \\
> \end{alignedat}
> $$
>

> ### 线性相关系数 $\mathrm{Corr_{elation}}$ 

> $$
> \begin{alignedat}{3}
> \mathrm{Corr} (X, Y) &= \dfrac{\mathrm{CoV} [X, Y]}{\mathrm{SD} [X] \cdot \mathrm{SD} [Y]} \\
>                      &= \dfrac{\mathrm{CoV} [X - \mathrm{Exp} [X], Y - \mathrm{Exp} [Y]]}{\mathrm{SD} [X] \cdot \mathrm{SD} [Y]} \\
>                      &= \mathrm{CoV} \left[ \dfrac{X - \mathrm{Exp} [X]}{\mathrm{SD} [X]}, \dfrac{Y - \mathrm{Exp} [Y]}{\mathrm{SD} [Y]} \right] \\
>                      &= \mathrm{CoV} [X^*, Y^*] \\
> \end{alignedat}
> $$
>

> ### 均方差与线性相关系数

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           &&                                           e &= \mathrm{Exp} [Y - (c \cdot X + d)]^2 \\
> \Downarrow\quad         && \dfrac{1}{2} \dfrac{\partial e}{\partial c} &= \mathrm{Exp} [c \cdot X^2 + d \cdot X - X \cdot Y] \\
>                         &&                                             &= c \cdot \mathrm{Exp} [X]^2 + d \cdot \mathrm{Exp} [X] - \mathrm{Exp} [X \cdot Y] \\
> \Downarrow\quad         && \dfrac{1}{2} \dfrac{\partial e}{\partial d} &= \mathrm{Exp} [c \cdot X + d - Y] \\
>                         &&                                             &= c \cdot \mathrm{Exp} [X] + d - \mathrm{Exp} [Y] \\
> \Downarrow\quad         && \left\lbrace\begin{alignedat}{3}
>                            \dfrac{\partial e}{\partial c} &= 0 \\
>                            \dfrac{\partial e}{\partial d} &= 0 \\
>                            \end{alignedat}\right. &\Rightarrow \left\lbrace\begin{alignedat}{3}
>                                                                c0 &= \dfrac{\mathrm{CoV} [X, Y]}{\mathrm{Var} [X]} = \mathrm{Corr} [X, Y] \cdot \dfrac{\mathrm{SD} [Y]}{\mathrm{SD} [X]} \\
>                                                                d0 &= \mathrm{Exp} [Y] - \mathrm{Exp} [X] \cdot \dfrac{\mathrm{CoV} [X, Y]}{\mathrm{Var} [X]} \\
>                                                                \end{alignedat}\right. \\
> \Downarrow\quad         &&                             \min_{c0, d0} e &= \mathrm{Var} [Y - (c0 \cdot X + d0)] + \mathrm{Exp}^2 [Y - (c0 \cdot X + d0)] \\
>                         &&                                             &= \mathrm{Var} [Y - c0 \cdot X] \\
>                         &&                                             &= \mathrm{Var} [Y] - c0^2 \cdot \mathrm{Var} [X] - 2 c0 \cdot \mathrm{CoV} [X, Y] \\
>                         &&                                             &= \mathrm{Var} [Y] \cdot \left( 1 - \dfrac{\mathrm{CoV}^2 [X, Y]}{\mathrm{Var} [X] \cdot \mathrm{Var} [Y]} \right) \\
> \Downarrow\quad         &&                             \min_{c0, d0} e &= \mathrm{Var} [Y] \cdot (1 - \mathrm{Corr}^2 [X, Y]) \\
> \fbox{1}\Downarrow\quad &&                      |\mathrm{Corr} [X, Y]| &\le 1 \\
> \fbox{2}\Downarrow\quad &&                      |\mathrm{Corr} [X, Y]| &= 1 \iff Y = \pm \dfrac{\mathrm{SD} [Y]}{\mathrm{SD} [X]} \cdot X + \mathrm{Exp} [Y] \mp \mathrm{Exp} [X] \cdot \dfrac{\mathrm{SD} [Y]}{\mathrm{SD} [X]} \\
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