---
layout:    zh_post
Topic:     渐进极限
Title:     重要极限
Revised:   2018-03-30 19:10:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 反向积和极限

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&                \left[ \sum_{i = 1}^n s_n \cdot t_{n - i + 1} \right] &= \left\lvert \sum_1^n s_n \cdot t_{n - i + 1} \right\rvert \quad\Leftarrow\quad \sum_1^{+\infty} \lvert s_n \rvert = S \land \lim_{+\infty} t_n \to 0 \\
>              &&                                                                      &\le \left[ (\lvert s_1 \rvert \cdot \lvert t_n \rvert + \cdots + \lvert s_{n - N} \rvert \cdot \lvert t_{N + 1} \rvert) + (\lvert s_{n - N + 1} \rvert \cdot \lvert t_N \rvert + \cdots + \lvert s_n \rvert \cdot \lvert t_1 \rvert) \right] \\
>              &&                                                                      &\lt \left( \sum_1^{n - N} \lvert s_n \rvert \right) \cdot \varepsilon + \left( \sum_{n - N + 1}^n \lvert s_n \rvert \right) \cdot M \\
>              &&                                                                      &\lt S \cdot \varepsilon + \varepsilon \cdot M \\
> \Downarrow\; && \lim_{+\infty} \left[ \sum_{i = 1}^n s_n \cdot t_{n - i + 1} \right] &\to 0 \quad\Leftarrow\quad \sum_1^{+\infty} \lvert s_n \rvert = S \land \lim_{+\infty} t_n \to 0 \\
> \end{alignedat}
> $$
>