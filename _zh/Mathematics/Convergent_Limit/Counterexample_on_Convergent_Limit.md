---
layout:    zh_post
Topic:     收敛极限
Title:     收敛极限中的反例
Revised:   2017-10-10 19:47:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 非一致收敛

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & F_n (x) = x^n &&= 1 + \sum_1^n \left[ x^n - x^{n - 1} \right] &&\;\Leftarrow\; x \in (0, 1) \\
> \fbox{2}\; & F_n (x) = n e^{- n x} &&= 0 + \sum_1^n \left[ n e^{- n x} - (n - 1) e^{- (n - 1) x} \right] &&\;\Leftarrow\; x \in (0, 1) \\
> \fbox{3}\; & F_n (x) = e^{- n^2 x^2} &&= 1 + \sum_1^n \left[ e^{- n^2 x^2} - e^{- (n - 1)^2 x^2} \right] &&\;\Leftarrow\; x \in (0, 1) \\
> \fbox{4}\; & F_n (x) = 2 n^2 x e^{- n^2 x^2} &&= 0 + \sum_1^n \left[ 2 n^2 x e^{- n^2 x^2} - 2 (n - 1)^2 x e^{- (n - 1) x^2} \right] &&\;\Leftarrow\; x \in (0, 1) \\
> \end{alignedat}
> $$
>

> ### 绝对且一致收敛

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & F_n (x) = \sum_1^n \dfrac{(- 1)^{n - 1}}{n} x^n \;\Leftarrow\; x \in (0, 1) \\
>            & \lvert F_n (x) \rvert \to \mathcal{Conv.}; F_n (x) \rightrightarrows \mathcal{Conv.}; \lvert F_n (x) \rvert \not\rightrightarrows \mathcal{Conv.} \\
> \end{alignedat}
> $$
>