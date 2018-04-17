---
layout:    zh_post
Topic:     收敛极限
Title:     无穷三角级数
Revised:   2018-04-17 02:57:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 正交三角系

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \int_{- \pi}^\pi e^{\imath m x} \cdot e^{- \imath n x} \mathrm{d} x = \left\lbrace\begin{alignedat}{3}
>                                                                                    & 0     &&\;\Leftarrow\; m \ne n \\
>                                                                                    & 2 \pi &&\;\Leftarrow\; m = n \\
>                                                                                    \end{alignedat}\right. \\
> \fbox{2}\; & \int_{- \pi}^\pi \sin m x \cdot \sin n x \mathrm{d} x = \left\lbrace\begin{alignedat}{3}
>                                                                      & 0   &&\;\Leftarrow\; m \ne n \\
>                                                                      & \pi &&\;\Leftarrow\; m = n \ne 0 \\
>                                                                      \end{alignedat}\right. \\
> \fbox{3}\; & \int_{- \pi}^\pi \cos m x \cdot \cos n x \mathrm{d} x = \left\lbrace\begin{alignedat}{3}
>                                                                      & 0     &&\;\Leftarrow\; m \ne n \\
>                                                                      & \pi   &&\;\Leftarrow\; m = n \ne 0 \\
>                                                                      & 2 \pi &&\;\Leftarrow\; m = n = 0 \\
>                                                                      \end{alignedat}\right. \\
> \fbox{4}\; & \int_{- \pi}^\pi \sin m x \cdot \cos n x \mathrm{d} x = \int_{- \pi}^\pi \cos m x \cdot \sin n x \mathrm{d} x = 0 \\
> \end{alignedat}
> $$
>