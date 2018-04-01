---
layout:    zh_post
Topic:     渐进极限
Title:     重要极限
Revised:   2018-03-30 19:10:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 平均值极限

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&                                 \lim_{+\infty} s_n = s, \pm\infty \\
> \Uparrow\;   && \left\lvert s - \dfrac{1}{n} \sum_1^n s_n \right\rvert &\le \dfrac{1}{n} \sum_1^N \lvert s - s_n \rvert + \dfrac{1}{n} \sum_{N + 1}^n \lvert s - s_n \rvert \\
>              &&                                                        &\le \varepsilon_1 + \dfrac{\varepsilon_2}{n} \\
> \Downarrow\; &&               \lim_{+\infty} \dfrac{1}{n} \sum_1^n s_n &= s, \pm\infty \\
> \end{alignedat}
> $$
>

> ### 卷积平均值极限

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&                                                            \lim_{+\infty} s_n = s \land \lim_{+\infty} t_n = t \\
> \Downarrow\; && \left\lvert s \cdot \dfrac{1}{n} \sum_{1}^n t_n - \dfrac{1}{n} \sum_{i + j = n + 1} s_i \cdot t_j \right\rvert &= \left\lvert \dfrac{1}{n} \sum_{i + j = n + 1} (s - s_i) \cdot t_j \right\rvert \\
>              &&                                                                                                                &\le \dfrac{M}{n} \sum_1^n \lvert s - s_i \rvert \\
>              &&                                                                                                                &\le M \cdot \varepsilon \\
> \Downarrow\; &&                                     \lim_{+\infty} \dfrac{1}{n} \sum_{i + j = n + 1} s_i \cdot t_j = s \cdot t &= \lim_{+\infty} s \cdot \dfrac{1}{n} \sum_1^n t_n \\
> \end{alignedat}
> $$
>

> ### 卷积极限

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&                      \sum_1^{+\infty} \lvert s_n \rvert = S &\land \lim_{+\infty} t_n \to 0 \\
> \Uparrow\;   && \left\lvert \sum_{i + j = n + 1} s_i \cdot t_j \right\rvert &\le (\lvert s_1 \rvert \cdot \lvert t_n \rvert + \cdots + \lvert s_{n - N} \rvert \cdot \lvert t_{N + 1} \rvert) + (\lvert s_{n - N + 1} \rvert \cdot \lvert t_N \rvert + \cdots + \lvert s_n \rvert \cdot \lvert t_1 \rvert) \\
>              &&                                                             &\lt \left( \sum_1^{n - N} \lvert s_n \rvert \right) \cdot \varepsilon_1 + \left( \sum_{n - N + 1}^n \lvert s_n \rvert \right) \cdot M \\
>              &&                                                             &\lt S \cdot \varepsilon_1 + \varepsilon_2 \cdot M \\
> \Downarrow\; &&           \lim_{+\infty} \sum_{i + j = n + 1} s_i \cdot t_j &\to 0 \\
> \end{alignedat}
> $$
>