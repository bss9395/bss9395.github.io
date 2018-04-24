---
layout:    zh_post
Topic:     收敛极限
Title:     统一收敛极限理论
Revised:   2018-04-25 01:47:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 符号表示

> $$
> \begin{alignedat}{3}
> && \lim_{\mathcal{B} (z)} F (f; z, u) \rightrightarrows F (f; \infty, u) &\iff \left\lbrace\begin{alignedat}{3}
>                                                                                & \lim_{\mathcal{B} (z)} f (z, \cancel{u}) \to f (\infty, \cancel{u}) \\
>                                                                                & \lim_{\mathcal{B} (z)} \left\langle f'_z (z, \cancel{u}) =  \dfrac{\mathrm{d} f}{\mathrm{d} z} (z, \cancel{u}) \right\rangle \to \left\langle f'_z (\infty, \cancel{u}) = \dfrac{\mathrm{d} f}{\mathrm{d} z} (\infty, \cancel{u}) \right\rangle \\
>                                                                                & \lim_{z \to +\infty} \left\langle S_z (\cancel{u}) = \sum_1^z f_z (\cancel{u}) \right\rangle \to \left\langle S_{+\infty} (\cancel{u}) = \sum_1^{+\infty} f_z (\cancel{u}) \right\rangle \\
>                                                                                & \lim_{z \to +\infty} \int_\alpha^z f (z, \cancel{u}) \mathrm{d} z \to \int_\alpha^{+\infty} f (z, \cancel{u}) \mathrm{d} z \\
>                                                                                & \lim_{z \to \alpha^+} \int_z^\beta f (z, \cancel{u}) \mathrm{d} z \to \int_{\alpha^+}^\beta f (z, \cancel{u}) \mathrm{d} z \\
>                                                                                \end{alignedat}\right.
>                                                                                &\quad& \left\lbrace\begin{alignedat}{3}
>                                                                                        & \lim_{\mathcal{B} (z)} f (z, u) \rightrightarrows f (\infty, u) \\
>                                                                                        & \lim_{\mathcal{B} (z)} \left\langle f'_z (z, u) = \dfrac{\mathrm{d} f}{\mathrm{d} z} (z, u) \right\rangle \rightrightarrows \left\langle f'_z (\infty, u) = \dfrac{\mathrm{d} f}{\mathrm{d} z} (\infty, u) \right\rangle \\
>                                                                                        & \lim_{z \to +\infty} \left\langle S_z (u) = \sum_1^z f_z (u) \right\rangle \rightrightarrows \left\langle S_{+\infty} (u) = \sum_1^{+\infty} f_z (u) \right\rangle \\
>                                                                                        & \lim_{z \to +\infty} \int_\alpha^z f (z, u) \mathrm{d} z \rightrightarrows \int_\alpha^{+\infty} f (z, u) \mathrm{d} z \\
>                                                                                        & \lim_{z \to \alpha^+} \int_z^\beta f (z, u) \mathrm{d} z \rightrightarrows \int_{\alpha^+}^\beta f (z, u) \mathrm{d} z \\
>                                                                                        \end{alignedat}\right. \\
> && \left\Updownarrow\begin{alignedat}{3}
>    - [F (f; z, u) - F (f; \infty, u)] \\
>    F (f; z \to \infty, u) \\
>    \end{alignedat}\right. &\iff \left\lbrace\begin{alignedat}{3}
>                                 & f (\infty, \cancel{u}) - f (z, \cancel{u}) \\
>                                 & \left\langle f'_z (\infty, \cancel{u}) - f'_z (z, \cancel{u}) = \dfrac{\mathrm{d} f}{\mathrm{d} z} (\infty, \cancel{u}) - \dfrac{\mathrm{d} f}{\mathrm{d} z} (z, \cancel{u}) \right\rangle \\
>                                 & \left\langle S_{+\infty} (\cancel{u}) - S_z (\cancel{u}) = \sum_{z + 1}^{+\infty} f_z (\cancel{u}) \right\rangle \\
>                                 & \int_z^{+\infty} f (z, \cancel{u}) \mathrm{d} z \\
>                                 & \int_{\alpha^+}^z f (z, \cancel{u}) \mathrm{d} z \\
>                                 \end{alignedat}\right.
>                                 &\quad& \left\lbrace\begin{alignedat}{3}
>                                         & f (\infty, u) - f (z, u) \\
>                                         & \left\langle f'_z (\infty, u) - f'_z (z, u) = \dfrac{\mathrm{d} f}{\mathrm{d} z} (\infty, u) - \dfrac{\mathrm{d} f}{\mathrm{d} z} (z, u) \right\rangle \\
>                                         & \left\langle S_{+\infty} (u) - S_z (u) = \sum_{z + 1}^{+\infty} f_z (u) \right\rangle \\
>                                         & \int_z^{+\infty} f (z, u) \mathrm{d} z \\
>                                         & \int_{\alpha^+}^z f (z, u) \mathrm{d} z \\
>                                         \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### 收敛极限理论

> $$
> \left.\begin{alignedat}{3}
> \fbox{1}\quad & \lim_{\mathcal{B} (z)} F (f; z, \cancel{u}) \to F (f; \infty, \cancel{u}) \\
> \fbox{2}\quad & \lim_{\mathcal{B} (z)} F (f; z \to \infty, \cancel{u}) \to 0 \\
> \fbox{3}\quad & \lim_{\mathcal{B} (z)} |F (f; z \to \infty, \cancel{u})| \to 0 \\
> \fbox{4}\quad & \lim_{\mathcal{B} (z)} |F (f; z \to \infty, \cancel{u})|^2 \to 0 \\
>               & \\
> \fbox{5}\quad & \lim_{\mathcal{B} (z)} F (f; z' \to z'', \cancel{u}) \to 0 \\
> \fbox{6}\quad & \lim_{\mathcal{B} (z)} |F (f; z' \to z'', \cancel{u})| \to 0 \\
> \fbox{7}\quad & \lim_{\mathcal{B} (z)} |F (f; z' \to z'', \cancel{u})|^2 \to 0 \\
> \end{alignedat}\middle\Updownarrow \begin{alignedat}{3}
>                                    & \lim_{\mathcal{B} (z)} F (f; z, u) \rightrightarrows F (f; \infty, u) &&\quad\Leftrightarrow\quad \Updownarrow                                                   &&\quad\Rightarrow\quad \lim_{\mathcal{B} (z)} F (f; z, u) \to F (f; \infty, u) \\
>                                    & \lim_{\mathcal{B} (z)} F (f; z \to \infty, u) \rightrightarrows 0     &&\quad\Leftrightarrow\quad \Updownarrow                                                   &&\quad\Rightarrow\quad \lim_{\mathcal{B} (z)} F (f; z \to \infty, u) \to 0 \\
>                                    & \lim_{\mathcal{B} (z)} |F (f; z \to \infty, u)| \rightrightarrows 0   &&\quad\Leftrightarrow\quad \lim_{\mathcal{B} (z)} \sup_u |F (f; z \to \infty, u)| \to 0   &&\quad\Rightarrow\quad \Updownarrow \\
>                                    & \lim_{\mathcal{B} (z)} |F (f; z \to \infty, u)|^2 \rightrightarrows 0 &&\quad\Leftrightarrow\quad \lim_{\mathcal{B} (z)} \sup_u |F (f; z \to \infty, u)|^2 \to 0 &&\quad\Rightarrow\quad \Updownarrow \\
>                                    & \lim_{\mathcal{B} (z)} F (f; z' \to z'', u) \rightrightarrows         && \lim_{\mathcal{B} (z)} F (f; \infty \to z'', u) \\
>                                    & \lim_{\mathcal{B} (z)} F (f; z' \to z'', u) \rightrightarrows 0       &&\quad\Leftrightarrow\quad \Updownarrow                                                   &&\quad\Rightarrow\quad \lim_{\mathcal{B} (z)} F (f; z' \to z'', u) \to 0 \\
>                                    & \lim_{\mathcal{B} (z)} |F (f; z' \to z'', u)| \rightrightarrows 0     &&\quad\Leftrightarrow\quad \lim_{\mathcal{B} (z)} \sup_u |F (f; z' \to z'', u)| \to 0     &&\quad\Rightarrow\quad \Updownarrow \\
>                                    & \lim_{\mathcal{B} (z)} |F (f; z' \to z'', u)|^2 \rightrightarrows0    &&\quad\Leftrightarrow\quad \lim_{\mathcal{B} (z)} \sup_u |F (f; z' \to z'', u)|^2 \to 0   &&\quad\Rightarrow\quad \Updownarrow \\
>                                    \end{alignedat}\right.
> $$
>

> ### 优函数审敛法

> $$
> \begin{alignedat}{9}
> \Uparrow\;   & F (f; z, u) \le F (|f|; z, u) \le F (g; z, u) \quad\mathop\Leftarrow\quad f (z, u) \le |f (z, u)| \le g (z, u) \\
> \Downarrow\; & \lim_{\mathcal{B} (z)} \sup_u |F (f; z \to \infty, u)| \le \lim_{\mathcal{B} (z)} \sup_u |F (|f|; z \to \infty, u)| \le \lim_{\mathcal{B} (z)} \sup_u |F (g; z \to \infty, u)| \\
> \Downarrow\; & \lim_{\mathcal{B} (z)} F (f; z, u) \rightrightarrows F (f; \infty, u) \quad\Leftarrow\quad \lim_{\mathcal{B} (z)} F (|f|; z, u) \rightrightarrows F (|f|; \infty, u) \quad\Leftarrow\quad \lim_{\mathcal{B} (z)} F (g; z, u) \rightrightarrows F (g; \infty, u) \\
> \end{alignedat}
> $$
>

> ### 分部审敛法

> $$
> \begin{alignedat}{9}
> \fbox{1}\Uparrow\; & \lim_{\mathcal{B} (z)} f (z, u) \rightrightarrows 0 \quad\land \quad \lim_{\mathcal{B} (z)} \sup_u |F (|g|; z, u)| \le M \\
> \Downarrow\;       & \lim_{\mathcal{B} (z)} \sup_u |F (f \cdot g; z \to \infty, u)| \le \lim_{\mathcal{B} (z)} \sup_u F (|f| \cdot |g|; z \to \infty, u) \le \lim_{\mathcal{B} (z)} \sup_u [|f (z, u)| \cdot F (|g|; z \to \infty, u)] \to 0 \\
> \fbox{2}\Uparrow\; & \lim_{\mathcal{B} (z)} f^\updownarrow (z, u) \rightrightarrows 0 \quad\land\quad \lim_{\mathcal{B} (z)} \sup_u |F (g; z, u)| \le M \\
> \Downarrow\;       & \lim_{\mathcal{B} (z)} \sup_u |F (f^\updownarrow \cdot g; z \to \infty, u)| \le \lim_{\mathcal{B} (z)} \sup_u |f^\updownarrow (z, u) \cdot F (g; z \to \infty, u)| = \lim_{\mathcal{B} (z)} \sup_u [|f^\updownarrow (z, u)| \cdot |F (g; z \to \infty, u)|] \to 0 \\
> \fbox{3}\Uparrow\; & \lim_{\mathcal{B} (z)} \sup_u |f^\updownarrow (z, u)| \le M \quad\land\quad \lim_{\mathcal{B} (z)} F (g; z, u) \rightrightarrows F (g; \infty, u) \\
> \Downarrow\;       & \lim_{\mathcal{B} (z)} \sup_u |F (f^\updownarrow \cdot g; z \to \infty, u)| \le \lim_{\mathcal{B} (z)} \sup_u |f^\updownarrow (z, u) \cdot F (g; z \to \infty, u)| = \lim_{\mathcal{B} (z)} \sup_u [|f^\updownarrow (z, u)| \cdot |F (g; z \to \infty, u)|] \to 0 \\
> \Downarrow\;       & \lim_{\mathcal{B} (z)} F (f \cdot g; z, u) \mathop{\rightrightarrows} F (f \cdot g; \infty, u) \\
> \end{alignedat}
> $$
>

> ### 一致收敛可交换运算次序

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&                 \lim_{\mathcal{B} (u)} L \left( F (f; z, u); z, u \right) \rightrightarrows L (F (f; z, u); z, \infty) \quad&\lor\quad \lim_{\mathcal{B} (z)} F (L (f; z, u); z, u) \rightrightarrows F (L (f; z, u); \infty, u) \\
> \Downarrow\; &&                                                 \lim_{\mathcal{B} (u)} \sup_z |L (F (f; z, u); z, u \to \infty)| \to 0 \quad&\lor\quad \lim_{\mathcal{B} (z)} \sup_u |F (L (f; z, u); z \to \infty, u)| \to 0 \\
> \Downarrow\; && L (F (f; \infty, u); \cancel{z}, \infty) = \lim_{\mathcal{B} (u)} L \left( \lim_{\mathcal{B} (z)} F (f; z, u); z, u \right) &= \lim_{\mathcal{B} (z)} F \left( \lim_{\mathcal{B} (u)} L (f; z, u); z, u \right) = F (L (f; z, \infty); \infty, \cancel{u}) \\
> \end{alignedat}
> $$
>