---
layout:    zh_post
Topic:     无穷级数
Title:     无穷乘积
Revised:   2018-04-01 22:34:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 收敛乘积的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\; &                               \prod^{+\infty} p_n \not\to 0 \\
> \fbox{2}\; &                                      \lim_{+\infty} p_n = 1 &&\implies p_n = 1 + s_n \\
> \fbox{3}\; &                             \prod^{+\infty} (1 + s_n) \to 0 &&\iff \prod^{+\infty} \lvert 1 + s_n \rvert \to 0                    &&\iff \sum^{+\infty} \ln \lvert 1 + s_n \rvert \to -\infty               &&\mathop{\iff}_{s_n } \sum_N^{+\infty} \ln (1 + s_n) \to -\infty \\
> \fbox{4}\; &               \prod^{+\infty} (1 + s_n) \to \mathcal{Conv.} &&\iff \sum_N^{+\infty} \ln (1 + s_n) \to \mathcal{Conv.}             &&\mathop{\iff}_{s_n \gtreqless 0} \sum^{+\infty} s_n \to \mathcal{Conv.} \\
> \fbox{5}\; & \prod^{+\infty} (1 + \lvert s_n \rvert) \to \mathcal{Conv.} &&\iff \sum^{+\infty} \ln (1 + \lvert s_n \rvert) \to \mathcal{Conv.} &&\iff \sum^{+\infty} \lvert s_n \rvert \to \mathcal{Conv.}               &&\iff \sum_N^{+\infty} \lvert \ln (1 + s_n) \rvert \to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 平方审敛法

> $$
> \begin{alignedat}{3}
> \Uparrow\;         & \lim_{+\infty} \dfrac{s_n - \ln (1 + s_n)}{s_n^2} = \lim_{+\infty} \dfrac{1}{2 (1 + s_n)} = \dfrac{1}{2} \\
> \fbox{1}\Uparrow\; & \sum^{+\infty} s_n^2 \to \mathcal{Conv.} \quad\Rightarrow\quad \lim_{+\infty} s_n \to 0 \\
> \Downarrow\;       & \sum^{+\infty} [s_n - \ln (1 + s_n)] \to \mathcal{Conv.} \\
> \Downarrow\;       & \sum^{+\infty} s_n \to \mathcal{Conv.} \quad\Leftrightarrow\quad \sum_N^{+\infty} \ln (1 + s_n) \to \mathcal{Conv.} \quad\Leftrightarrow\quad \prod^{+\infty} (1 + s_n) \to \mathcal{Conv.} \\
> \fbox{2}\Uparrow\; & \sum^{+\infty} s_n \to \mathcal{Conv.} \land \sum^{+\infty} s_n^2 \to +\infty \\
> \Downarrow\;       & \sum_N^{+\infty} \ln (1 + s_n) \to -\infty \\
> \Downarrow\;       & \prod^{+\infty} (1 + s_n) \to 0 \\
> \end{alignedat}
> $$
>

> ### 绝对收敛乘积的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \prod^{+\infty} (1 + \lvert s_n \rvert) \to \mathcal{Conv.} \iff \sum_N^{+\infty} \lvert \ln (1 + s_n) \rvert \to \mathcal{Conv.} \implies \sum_N^{+\infty} \ln (1 + s_n) \to \mathcal{Conv.} \iff \prod^{+\infty} (1 + s_n) \to \mathcal{Conv.} \\
> \fbox{2}\; & \prod^{+\infty} (1 + \lvert s_n \rvert) \to \mathcal{Conv.} \implies \sum_N^{+\infty} \ln (1 + s_n) = \sum_N^{+\infty} \ln (1 + s_m) \implies \prod^{+\infty} (1 + s_n) = \prod^{+\infty} (1 + s_m) \\
> \end{alignedat}
> $$
>

> ### 条件收敛乘积的性质

> $$
> \begin{alignedat}{3}
> \Uparrow\;           && \prod^{+\infty} (1 + \lvert s_n \rvert) \not\to \mathcal{Conv.} &\land \prod_N^{+\infty} (1 + s_n) \to \mathcal{Conv.} \\
> \fbox{1}\Downarrow\; &&                         \sum_N^{+\infty} \ln (1 + s_m) = S \quad&\Rightarrow\quad \prod_N^{+\infty} (1 + s_m) = P \\
> \fbox{2}\Downarrow\; &&                 \sum_N^{+\infty} \ln (1 + s_m) \to -\infty \quad&\Rightarrow\quad \prod_N^{+\infty} (1 + s_m) \to 0 \\
> \fbox{3}\Downarrow\; &&                 \sum_N^{+\infty} \ln (1 + s_m) \to +\infty \quad&\Rightarrow\quad \prod_N^{+\infty} (1 + s_m) \to +\infty \\
> \fbox{4}\Downarrow\; &&     \sum_N^{+\infty} \ln (1 + s_m) \not\to \mathcal{Conv.} \quad&\Rightarrow\quad \prod_N^{+\infty} (1 + s_m) \not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>