---
layout:    zh_post
Topic:     无穷级数
Title:     无穷函数级数
Revised:   2018-03-24 18:47:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 函数级数的等价性命题

> $$
> \begin{alignedat}{3}
> \fbox{1}\; &&                                                 \lim_\mathcal{B} \sum^{+\infty} s_n (x) = \lim_\mathcal{B} \lim_{+\infty} \sum^n s_n (x) = \lim_\mathcal{B} \lim_{+\infty} S_n (x) &\mathop{=}^{?} \lim_{+\infty} \lim_\mathcal{B} S_n (x) = \lim_{+\infty} \lim_\mathcal{B} \sum^n s_n (x) = \sum^{+\infty} \lim_\mathcal{B} s_n (x) \\
> \fbox{2}\; &&                            \int \mathrm{d} x \cdot \sum^{+\infty} s_n (x) = \int \mathrm{d} x \cdot \lim_{+\infty} \sum^n s_n (x) = \int \mathrm{d} x \cdot \lim_{+\infty} S_n (x) &\mathop{=}^{?} \lim_{+\infty} \int \mathrm{d} x \cdot S_n (x) = \lim_{+\infty} \int \mathrm{d} x \cdot \sum^n s_n (x) = \sum^{+\infty} \int \mathrm{d} x \cdot s_n (x) \\
> \fbox{3}\; && \dfrac{\mathrm{d}}{\mathrm{d} x} \sum^{+\infty} s_n (x) = \dfrac{\mathrm{d}}{\mathrm{d} x} \lim_{+\infty} \sum^n s_n (x) = \dfrac{\mathrm{d}}{\mathrm{d} x} \lim_{+\infty} S_n (x) &\mathop{=}^{?} \lim_{+\infty} \dfrac{\mathrm{d}}{\mathrm{d} x} S_n (x) = \lim_{+\infty} \dfrac{\mathrm{d}}{\mathrm{d} x} \sum^n s_n (x) = \sum^{+\infty} \dfrac{\mathrm{d}}{\mathrm{d} x} s_n (x) \\
> \end{alignedat}
> $$
>

> ### 一致收敛

> $$
> \begin{alignedat}{3}
> \fbox{1}\; &&               \sum^n s_n (x) = S_n (x) \to S (x) &:= \forall x \in I; \forall \varepsilon > 0; \exists N = N (x, \varepsilon) \in \mathbb{N}; n > N \implies \lvert S (x) - S_n (x) \rvert \lt \varepsilon \\
> \fbox{2}\; && \sum^n s_n (x) = S_n (x) \rightrightarrows S (x) &:= \forall x \in I; \forall \varepsilon > 0 ; \exist N = N (\varepsilon) \in \mathbb{N}; n > N \implies \lvert S (x) - S_n (x) \rvert \lt \varepsilon \\
> \end{alignedat}
> $$
>

> ### 一致收敛的性质

> $$
> \begin{alignedat}{3}
>                               \sum^n s_n (x) = S_n (x) \rightrightarrows S (x) &\Leftrightarrow \lim_{+\infty} \sup_x \lvert S (x) - S_n (x) \rvert \to 0 && \Leftrightarrow \lim_{+\infty} \sup_x \left\lvert \sum_{n + 1}^{+\infty} s_n (x) \right\rvert \to 0 \\
> \forall \varepsilon > 0; \exists N = N (\varepsilon) \in \mathbb{N}; n, m > N; &\Leftrightarrow  \lvert S_n (x) - S_m (x) \rvert \lt \varepsilon && \Leftrightarrow \left\lvert \sum_{m + 1}^n s_n (x) \right\rvert \lt \varepsilon \\
>                                                                                &\Rightarrow s_n (x) \rightrightarrows 0 &&\Leftrightarrow \lim_{+\infty} \sup_x \lvert s_n (x) \rvert \to 0 \\
> \end{alignedat}
> $$
>

> ### 优级数审敛法

> $$
> \begin{alignedat}{3}
> \lvert s_n (x) \rvert \le t_n (x) \land \sum^{+\infty} t_n (x) \rightrightarrows T (x) \implies \sum^{+\infty} s_n (x) \rightrightarrows S (x) \\
> \end{alignedat}
> $$
>