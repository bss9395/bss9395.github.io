---
layout:    zh_post
Topic:     收敛极限
Title:     重要积分
Revised:   2018-04-17 02:44:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 复数积分

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \int e^{\alpha x} \cdot e^{\imath \beta x} \mathrm{d} x = \dfrac{e^{\alpha x} \cdot e^{\imath \beta x}}{\alpha + \imath \beta} \\
> \fbox{2}\; & \int e^{\alpha x} \cdot \sin \beta x \mathrm{d} x = \dfrac{e^{\alpha x}}{\alpha^2 + \beta^2} (a \sin \beta x - \beta \cos \beta x) \\
> \fbox{3}\; & \int e^{\alpha x} \cdot \cos \beta x \mathrm{d} x = \dfrac{e^{\alpha x}}{\alpha^2 + \beta^2} (\alpha \cos \beta x + \beta \sin \beta x) \\
> \end{alignedat}
> $$
>

> ### 调和积分

> $$
> \begin{alignedat}{3}
> \fbox{1}\; &&         \int_0^\alpha \dfrac{\mathrm{d} x}{x^p} &= \left\lbrace\begin{alignedat}{3}
>                                                                  & \dfrac{\alpha^{1 - p}}{1 - p} &&\;\Leftarrow\; p \lt 1 \\
>                                                                  & +\infty                       &&\;\Leftarrow\; p \ge 1 \\
>                                                                  \end{alignedat}\right. \\
> \fbox{2}\; && \int_\alpha^{+\infty} \dfrac{\mathrm{d} x}{x^p} &= \left\lbrace\begin{alignedat}{3}
>                                                                  & \dfrac{1}{(p - 1) \alpha^{p - 1}} &&\;\Leftarrow\; p \gt 1 \\
>                                                                  & +\infty                           &&\;\Leftarrow\; p \le 1 \\
>                                                                  \end{alignedat}\right. \\
> \fbox{3}\; &&      \int_0^{+\infty} \dfrac{\mathrm{d} x}{x^p} &= +\infty \\
> \end{alignedat}
> $$
>

> ### 对数积分

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \int_2^{+\infty} \dfrac{\mathrm{d} x}{x \ln^p x} \xlongequal[]{t = \ln x} \left\lbrace\begin{alignedat}{3}
>                                                                                        & +\infty                          &\;\Leftarrow\; p \le 1 \\
>                                                                                        & \dfrac{1}{(p - 1) \ln^{p - 1} x} &\;\Leftarrow\; p \gt 1 \\
>                                                                                        \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### 指数积分

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \int_0^{+\infty} e^{- x^2} \mathrm{d} x \xlongequal{} \dfrac{\sqrt{\pi}}{2} \\
> \end{alignedat}
> $$
>

> ### 三角积分

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
> \fbox{5}\; & \int_0^{+\infty} \sin x^2 \mathrm{d} x = \int_0^{+\infty} \cos x^2 \mathrm{d} x = \dfrac{1}{2} \sqrt{\dfrac{\pi}{2}} \\
> \fbox{6}\; & \int_0^\pi \ln (1 - 2 r \cos x + r^2) \mathrm{d} x \xlongequal[\langle \lvert r \rvert < 1 \rangle]{t = \tan \frac{x}{2}} 0 \\
> \fbox{7}\; & \int_{- \pi}^\pi \dfrac{1 - r^2}{1 - 2 r \cdot \cos x + r^2} \mathrm{d} x \xlongequal[\langle 0 \lt r \lt 1 \rangle]{t = \tan \frac{x}{2}} 2 \pi \\
> \fbox{8}\; & \int_0^\pi \dfrac{\sin \left( n + \dfrac{1}{2} \right) x}{\sin \dfrac{x}{2}} \mathrm{d} x \xlongequal{\sum_1^n \cos n x} \pi \\
> \end{alignedat}
> $$
>

