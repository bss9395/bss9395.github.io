---
layout:    zh_post
Topic:     收敛极限
Title:     无穷幂级数
Revised:   2018-04-09 22:09:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 收敛半径

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\;   & \varlimsup_{+\infty} \sqrt[n]{\lvert s_n (x - x_0)^n \rvert}                                       &&= \varlimsup_{+\infty} \dfrac{\lvert x - x_0 \rvert}{\dfrac{1}{\sqrt[n]{\lvert s_n \rvert}}} \quad\Rightarrow\quad R = \varlimsup_{+\infty} \dfrac{1}{\sqrt[n]{\lvert s_n \rvert}} \\
> \fbox{2}\Uparrow\;   & \varlimsup_{+\infty} \left\lvert \dfrac{s_{n + 1} (x - x_0)^{n + 1}}{s_n (x - x_0)^n} \right\rvert &&= \varlimsup_{+\infty} \dfrac{\lvert x - x_0 \rvert}{\left\lvert \dfrac{s_n}{s_{n + 1}} \right\rvert} \quad\Rightarrow\quad R = \varlimsup_{+\infty} \left\lvert \dfrac{s_n}{s_{n + 1}} \right\rvert \\
> \Uparrow\;           &                                                                        \lvert x - x_0 \rvert \lt R &&\Rightarrow \sum^{+\infty} \lvert s_n (x - x_0)^n \rvert \to \mathcal{Conv.} \\
> \fbox{1}\Downarrow\; & R = 0                                                                                              &&\Rightarrow x - x_0 = 0; \\
> \fbox{2}\Downarrow\; & R \gt 0                                                                                            &&\Rightarrow x - x _0 \in (-R, R); \\
> \fbox{3}\Downarrow\; & R = +\infty                                                                                        &&\Rightarrow x - x_0 \in (-\infty, +\infty); \\
> \end{alignedat}
> $$
>

> ### 幂级数的性质

> $$
> \begin{alignedat}{3}
> \fbox{1}\; & \sum_0^{+\infty} s_n x^n \in \mathcal{Conti.}                                                                                                                &&\;\Rightarrow\; R = \varlimsup_{+\infty} \dfrac{1}{\sqrt[n]{\lvert s_n \rvert}} \\
> \fbox{2}\; & \int_0^x \left( \sum_0^{+\infty} s_n x^n \right) \mathrm{d} x = \sum_0^{+\infty} \int_0^x s_n x^n \mathrm{d} x = \sum_0^{+\infty} \dfrac{s_n}{n + 1} x^{n + 1} &&\;\Rightarrow\; R = \varlimsup_{+\infty} \sqrt[n]{\dfrac{n + 1}{s_n}} = \varlimsup_{+\infty} \dfrac{1}{\sqrt[n]{s_n}} \\
> \fbox{3}\; & \left( \sum_0^{+\infty} s_n x^n \right)^{(k)} = \sum_0^{+\infty} (s_n x^n)^{(k)} = \sum_k^{+\infty} \dfrac{n !}{k !} s_n x^{(n - k)}                         &&\;\Rightarrow\; R = \varlimsup_{+\infty} \sqrt[n]{\dfrac{k !}{n ! s_n}} \\
> \fbox{4}\; & \sum_0^{+\infty} s_n \langle \pm R \rangle^n \to \mathcal{Conv.} \;\Rightarrow\; \sum_0^{+\infty} s_n x^n \rightrightarrows \mathcal{Conv.}                  &&\;\Rightarrow\; \sum_0^{+\infty} s_n \langle \pm R \rangle^n = \lim_{\pm R} \sum_0^{+\infty} s_n x^n = \sum_0^{+\infty} \lim_{\pm R} s_n x^n \\
> \fbox{5}\; & \lim_{\pm R} \sum_0^{+\infty} s_n \to S \;\land\; s_n \ge 0                                                                                                  &&\;\Rightarrow\; \sum_0^{+\infty} s_n \langle \pm R \rangle^n = S \\
> \fbox{6}\; & \lim_{\pm R} \sum_0^{+\infty} s_n \to S \;\land\; s_n = o \left( \dfrac{1}{n} \right)                                                                        &&\;\Rightarrow\; \sum_0^{+\infty} s_n \langle \pm R \rangle^n = S \\
> \end{alignedat}
> $$
>

> ### 幂级数的乘积

> $$
> \begin{alignedat}{3}
> \Uparrow\;           & \left( \sum_0^{+\infty} s_n x^n \right) \cdot \left( \sum_0^{+\infty} t_n x^n \right) &&= \sum_0^{+\infty} \sum_{i + j = n} s_i t_j x^n \\
> \fbox{1}\Downarrow\; &                      \sum_0^{+\infty} s_n \cdot \sum_0^{+\infty} t_n = S \cdot T \quad&&\Leftarrow\quad \sum_0^{+\infty} \sum_{i + j = n} s_i t_j \to \mathcal{Conv.} \\
> \fbox{2}\Downarrow\; &             \dfrac{1}{1 - x} \sum_0^{+\infty} t_n x^n = \sum_0^{+\infty} T_n x^n \quad&&\Leftarrow\quad s_n = 1  \\
> \end{alignedat}
> $$
>

> ### 幂级数的余项

> $$
> \begin{alignedat}{3}
> \Uparrow\;           &&                                    F (t) &:= f (t) + \sum_1^n \dfrac{f^{(n)} (t)}{n !} (x - t)^n \quad\Rightarrow\quad R_n (x - x_0) \equiv F (x) - F (x_0) \\
> \Downarrow\;         &&                                   F' (t) &= f^{(1)} (t) + \sum_1^n \dfrac{f^{(n + 1)} (t)}{n !} (x - t)^n - \sum_1^n \dfrac{f^{(n)} (t)}{(n - 1) !} (x - t)^{n - 1} \\
>                      &&                                          &= f^{(1)} (t) + \sum_2^{n + 1} \dfrac{f^{(n)} (t)}{(n - 1) !} (x - t)^{n - 1} - \sum_2^n \dfrac{f^{(n)} (t)}{(n - 1) !} (x - t)^{n - 1} - f^{(1)} (t) \\
>                      &&                                          &= \dfrac{f^{(n + 1)} (t)}{n !} (x - t)^n \\
> \Uparrow\;           && \dfrac{F (x) - F (x_0)}{G (x) - G (x_0)} &\xlongequal[\mathring{x_0}]{} \dfrac{F' (\xi)}{G' (\xi)} \quad\Leftarrow\quad G (x) - G (x_0) \equiv o (x - x_0) \\
> \fbox{1}\Downarrow\; &&                            R_n (x - x_0) &\equiv \dfrac{f^{(n + 1)} (\xi)}{n !} (x - \xi)^n \cdot \dfrac{G (x) - G (x_0)}{G' (\xi)} \\
> \fbox{2}\Downarrow\; &&                            R_n (x - x_0) &\equiv \dfrac{f^{(n + 1)} (\xi)}{n !} (x - \xi)^n (x - x_0) \quad\Leftarrow\quad G (t) := (x - t) \\
> \fbox{3}\Downarrow\; &&                            R_n (x - x_0) &\equiv \dfrac{f^{(n + 1)} (\xi)}{(n + 1) !} (x - x_0)^{n + 1} \quad\Leftarrow\quad G (t) := (x - t)^{n + 1} \\
> \fbox{4}\Downarrow\; &&                            R_n (x - x_0) &\equiv O [(x - x_0)^{n + 1}] \\
> \fbox{5}\Downarrow\; &&                            R_n (x - x_0) &\equiv o [(x - x_0)^n] \\
> \fbox{6}\Downarrow\; &&                            R_n (x - x_0) &\equiv \int_{x_0}^x \dfrac{f^{(n + 1)} (t)}{n !} (x - t)^n \mathrm{d} t \quad\Leftarrow\quad G (t) := \int_x^t \dfrac{f^{(n + 1)} (t)}{n !} (x - t)^n \mathrm{d} t \\
> \end{alignedat}
> $$
>

> ### 无穷幂级数展开

> $$
> \begin{alignedat}{3}
> \Uparrow\;             & f (x) = f (x_0) + \sum_1^n \dfrac{f^{(n)} (x_0)}{n !} (x - x_0)^n + R_n (x - x_0) \\
> \fbox{1}\Updownarrow\; & 0 = \lim_{+\infty} R_n (x - x_0) = \lim_{+\infty} \left[ f (x) - \sum_0^n \dfrac{f^{(n)} (x_0)}{n !} (x - x_0)^n \right] \\
> \fbox{2}\Uparrow\;     & \forall n; \lvert f^{(n)} (x) \rvert \le M \quad\Rightarrow\quad \lvert R_n (x - x_0) \rvert = \left\lvert \dfrac{f^{(n + 1)} (\xi)}{(n + 1) !} (x - x_0)^{n + 1} \right\rvert \le \dfrac{M}{(n + 1) !} R^{n + 1} \to 0 \\
> \Downarrow\;           & f (x) = f (x_0) + \sum_1^{+\infty} \dfrac{f^{(n)} (x_0)}{n !} (x - x_0)^n \\
> \end{alignedat}
> $$
>

