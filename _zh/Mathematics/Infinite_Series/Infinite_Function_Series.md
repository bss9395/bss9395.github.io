---
layout:    zh_post
Topic:     无穷级数
Title:     无穷函数级数
Revised:   2018-03-24 18:47:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 一致收敛函数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\; &&               \sum^n f_n (x) = F_n (x) \to F (x) &:= \forall x \in I; \forall \varepsilon > 0; \exists N = N (x, \varepsilon) \in \mathbb{N}; && n > N \implies \lvert F (x) - F_n (x) \rvert \lt \varepsilon \\
> \fbox{2}\; && \sum^n f_n (x) = F_n (x) \rightrightarrows F (x) &:= \forall x \in I; \forall \varepsilon > 0 ; \exist N = N (\varepsilon) \in \mathbb{N};    && n > N \implies \lvert F (x) - F_n (x) \rvert \lt \varepsilon \\
> \fbox{3}\; && \sum^n f_n (x) = F_n (x) \rightrightarrows F (x) &\Leftrightarrow \lim_{+\infty} \sup_x \lvert F (x) - F_n (x) \rvert \to 0                   && \Leftrightarrow \lim_{+\infty} \sup_x \left\lvert \sum_{n + 1}^{+\infty} f_n (x) \right\rvert \to 0 \\
>            &&                                                  &\Leftrightarrow  \lvert F_n (x) - F_m (x) \rvert \lt \varepsilon                            && \Leftrightarrow \left\lvert \sum_{m + 1}^n f_n (x) \right\rvert \lt \varepsilon \\
>            &&                                                  &\Rightarrow f_n (x) \rightrightarrows 0                                                     &&\Leftrightarrow \lim_{+\infty} \sup_x \lvert f_n (x) \rvert \to 0 \\
> \end{alignedat}
> $$
>

> ### 一致收敛函数级数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\; &&                                                 \lim_\mathcal{B} \sum^{+\infty} f_n (x) = \lim_\mathcal{B} \lim_{+\infty} \sum^n f_n (x) = \lim_\mathcal{B} \lim_{+\infty} F_n (x) &\mathop{=}^{?} \lim_{+\infty} \lim_\mathcal{B} F_n (x) = \lim_{+\infty} \lim_\mathcal{B} \sum^n f_n (x) = \sum^{+\infty} \lim_\mathcal{B} f_n (x) \\
> \fbox{2}\; &&                            \int \mathrm{d} x \cdot \sum^{+\infty} f_n (x) = \int \mathrm{d} x \cdot \lim_{+\infty} \sum^n f_n (x) = \int \mathrm{d} x \cdot \lim_{+\infty} F_n (x) &\mathop{=}^{?} \lim_{+\infty} \int \mathrm{d} x \cdot F_n (x) = \lim_{+\infty} \int \mathrm{d} x \cdot \sum^n f_n (x) = \sum^{+\infty} \int \mathrm{d} x \cdot f_n (x) \\
> \fbox{3}\; && \dfrac{\mathrm{d}}{\mathrm{d} x} \sum^{+\infty} f_n (x) = \dfrac{\mathrm{d}}{\mathrm{d} x} \lim_{+\infty} \sum^n f_n (x) = \dfrac{\mathrm{d}}{\mathrm{d} x} \lim_{+\infty} F_n (x) &\mathop{=}^{?} \lim_{+\infty} \dfrac{\mathrm{d}}{\mathrm{d} x} F_n (x) = \lim_{+\infty} \dfrac{\mathrm{d}}{\mathrm{d} x} \sum^n f_n (x) = \sum^{+\infty} \dfrac{\mathrm{d}}{\mathrm{d} x} f_n (x) \\
> \end{alignedat}
> $$
>

> ### 优级数审敛法

> $$
> \begin{alignedat}{3}
> \lvert f_n (x) \rvert \le g_n (x) \land \sum^{+\infty} g_n (x) \rightrightarrows G (x) \implies \sum^{+\infty} f_n (x) \rightrightarrows F (x) \\
> \end{alignedat}
> $$
>

