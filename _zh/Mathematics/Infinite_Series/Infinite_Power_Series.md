---
layout:    zh_post
Topic:     无穷级数
Title:     无穷幂级数
Revised:   2018-04-05 00:59:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 收敛半径

> $$
> \begin{alignedat}{3}
> \Uparrow\;           & \varlimsup_{+\infty} \sqrt[n]{\lvert s_n (x - x_0)^n \rvert} &&= \varlimsup_{+\infty} \dfrac{\lvert x - x_0 \rvert}{\dfrac{1}{\sqrt[n]{\lvert s_n \rvert}}} \implies R = \varlimsup_{+\infty} \dfrac{1}{\sqrt[n]{\lvert s_n \rvert}} \\
> \Uparrow\;           &                                  \lvert x - x_0 \rvert \lt R &&\Rightarrow \sum^{+\infty} s_n (x - x_0)^n \to \mathcal{Conv.} \\
> \fbox{1}\Downarrow\; & R = 0                                                        &&\Rightarrow x - x_0 = 0; \\
> \fbox{2}\Downarrow\; & R \gt 0                                                      &&\Rightarrow x - x _0 \in (-R, R); \\
> \fbox{3}\Downarrow\; & R = +\infty                                                  &&\Rightarrow x - x_0 \in (-\infty, +\infty); \\
> \end{alignedat}
> $$
>