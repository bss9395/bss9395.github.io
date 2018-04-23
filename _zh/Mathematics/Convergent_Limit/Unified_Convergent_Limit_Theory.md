---
layout:    zh_post
Topic:     收敛极限
Title:     统一收敛极限理论
<<<<<<< HEAD
Revised:   2018-04-24 00:35:00 +08 @ 中国-新疆-乌鲁木齐 +06
=======
Revised:   2018-04-23 00:35:00 +08 @ 中国-新疆-乌鲁木齐 +06
>>>>>>> ab3aeabde487c66a6ccb7a30bea371d7df83f57f
Authors:   璀璨星辰
Resources:
---

> ### 符号表示

> $$
> \begin{alignedat}{3}
<<<<<<< HEAD
> && \lim_{\mathcal{B} (z)} F (f, z, u) \rightrightarrows F (f, \infty) &\iff \left\lbrace\begin{alignedat}{3}
>                                                                             & \lim_{\mathcal{B} (x)} f (x) \to f (\infty) \\                                                                                                                                                                                          
>                                                                             & \lim_{n \to +\infty} \left\langle S_n = \sum_1^n s_n \right\rangle \to \left\langle S_{+\infty} = \sum_1^{+\infty} s_n \right\rangle \\
>                                                                             & \lim_{r \to +\infty} \int_\alpha^r f (x) \mathrm{d} x \to \int_\alpha^{+\infty} f (x) \mathrm{d} x \\                                  
>                                                                             & \lim_{r \to \alpha^+} \int_r^\beta f (x) \mathrm{d} x \to \int_{\alpha^+}^\beta f (x) \mathrm{d} x \\                                  
>                                                                             \end{alignedat}\right.
>                                                                             &\quad& \left\lbrace\begin{alignedat}{3}
>                                                                                     & \lim_{\mathcal{B} (x)} f (x, u) \rightrightarrows f (\infty) \\
>                                                                                     & \lim_{n \to +\infty} \left\langle S_n (x) = \sum_1^n s_n (x) \right\rangle \rightrightarrows \left\langle S_{+\infty} = \sum_1^{+\infty} s_n \right\rangle \\
>                                                                                     & \lim_{r \to +\infty} \int_\alpha^r f (x, u) \mathrm{d} x \rightrightarrows \int_\alpha^{+\infty} f (x) \mathrm{d} x \\
>                                                                                     & \lim_{r \to \alpha^+} \int_r^\beta f (x, u) \mathrm{d} x \rightrightarrows \int_{\alpha^+}^\beta f (x) \mathrm{d} x \\
>                                                                                     \end{alignedat}\right. \\
> && \left\Updownarrow\begin{alignedat}{3}
>    - [F (f, z, u) - F (f, \infty)] \\
>    F (f, z \to \infty, u) \\
>    \end{alignedat}\right. &\iff \left\lbrace\begin{alignedat}{3}
>                                 & f (\infty) - f (x) \\
>                                 & \left\langle S_{+\infty} - S_n = \sum_{n + 1}^{+\infty} s_n \right\rangle \\
>                                 & \int_r^{+\infty} f (x) \mathrm{d} x \\
>                                 & \int_{\alpha^+}^r f (x) \mathrm{d} x \\
>                                 \end{alignedat}\right. 
>                                 &\quad& \left\lbrace\begin{alignedat}{3}
>                                         & f (\infty, u) - f (x, u) \\
>                                         & \left\langle S_{+\infty} (x) - S_n (x) = \sum_{n + 1}^{+\infty} s_n (x) \right\rangle \\
>                                         & \int_r^{+\infty} f (x, u) \mathrm{d} x \\
>                                         & \int_{\alpha^+}^r f (x, u) \mathrm{d} x \\
>                                         \end{alignedat}\right. \\
> && \lim_{\mathcal{B} (u)} L \left( \lim_{\mathcal{B} (z)} F (f, z, u), u \right) &\iff \left\lbrace\begin{alignedat}{3}
>                                                                                        & \lim_{\mathcal{B} (u)} \lim_{\mathcal{B} (x)} f (x, u) \\
>                                                                                        & \lim_{\mathcal{B} (x)} \lim_{n \to +\infty} \left\langle S_n (x) =  \sum_1^n s_n (x) \right\rangle \\
>                                                                                        & \int_\alpha^\beta \mathrm{d} x \cdot \lim_{n \to +\infty} \left\langle S_n (x) = \sum_1^n s_n (x) \right\rangle \\
>                                                                                        & \int_\alpha^{+\infty} \mathrm{d} x \cdot \lim_{n \to +\infty} \left\langle S_n (x) = \sum_1^n s_n (x) \right\rangle \\
>                                                                                        & \int_{\alpha^+}^\beta \mathrm{d} x \cdot \lim_{n \to +\infty} \left\langle S_n (x) = \sum_1^n s_n (x) \right\rangle \\
>                                                                                        & \dfrac{\mathrm{d}}{\mathrm{d} x} \lim_{n \to +\infty} \left\langle S_n (x) = \sum_1^n s_n (x) \right\rangle \\
>                                                                                        \end{alignedat}\right. \\
=======
> && \lim_{\mathcal{B} (z)} F (f, z, u) \rightrightarrows F (f, \infty, u) &\iff \left\lbrace\begin{alignedat}{3}
>                                                                                & \lim_{n \to +\infty} \left\langle S_n = \sum_1^n s_n \right\rangle \to \left\langle S_{+\infty} = \sum_1^{+\infty} s_n \right\rangle \\
>                                                                                & \lim_{n \to +\infty} \left\langle S_n (x) = \sum_1^n s_n (x) \right\rangle \rightrightarrows \left\langle S_{+\infty} (x) = \sum_1^{+\infty} s_n (x) \right\rangle \\
>                                                                                & \lim_{r \to +\infty} \int_\alpha^r f (x) \mathrm{d} x \to \int_\alpha^{+\infty} f (x) \mathrm{d} x \\
>                                                                                & \lim_{r \to +\infty} \int_\alpha^r f (x, u) \mathrm{d} x \rightrightarrows \int_\alpha^{+\infty} f (x, u) \mathrm{d} x \\
>                                                                                & \lim_{r \to \alpha^+} \int_r^\beta f (x) \mathrm{d} x \to \int_{\alpha^+}^\beta f (x) \mathrm{d} x \\
>                                                                                & \lim_{r \to \alpha^+} \int_r^\beta f (x, u) \mathrm{d} x \rightrightarrows \int_{\alpha^+}^\beta f (x, u) \mathrm{d} x \\
>                                                                                \end{alignedat}\right. \\
> && \left\Updownarrow\begin{alignedat}{3}
>    - [F (f, z, u) - F (f, \infty, u)] \\
>    F (f, z \to \infty, u)
>    \end{alignedat}\right. &\iff \left\lbrace\begin{alignedat}{3}
>                                 & \left\langle S_{+\infty} - S_n = \sum_{n + 1}^{+\infty} s_n \right\rangle \\
>                                 & \left\langle S_{+\infty} (x) - S_n (x) = \sum_{n + 1}^{+\infty} s_n (x) \right\rangle \\
>                                 & \int_r^{+\infty} f (x) \mathrm{d} x \\
>                                 & \int_r^{+\infty} f (x, u) \mathrm{d} x \\
>                                 & \int_{\alpha^+}^r f (x) \mathrm{d} x \\
>                                 & \int_{\alpha^+}^r f (x, u) \mathrm{d} x \\
>                                 \end{alignedat}\right. \\ 
>>>>>>> ab3aeabde487c66a6ccb7a30bea371d7df83f57f
> \end{alignedat}
> $$
>

> ### 收敛极限理论

> $$
> \begin{alignedat}{9}
<<<<<<< HEAD
> \fbox{1}\quad & \lim_{\mathcal{B} (z)} F (f, z) \to F (f, \infty)       &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} F (f, z, u) \rightrightarrows F (f, \infty) &&\quad\Leftrightarrow\quad \Updownarrow                                                   &&\quad\Rightarrow\quad \lim_{\mathcal{B} (z)} F (f, z, u) \to F (f, \infty) \\
=======
> \fbox{1}\quad & \lim_{\mathcal{B} (z)} F (f, z) \to F (f, \infty)       &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} F (f, z, u) \rightrightarrows F (f, \infty, u) &&\quad\Leftrightarrow\quad \Updownarrow                                                   &&\quad\Rightarrow\quad \lim_{\mathcal{B} (z)} F (f, z, u) \to F (f, \infty, u) \\
>>>>>>> ab3aeabde487c66a6ccb7a30bea371d7df83f57f
> \fbox{2}\quad & \lim_{\mathcal{B} (z)} F (f, z \to \infty, u) \to 0     &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} F (f, z \to \infty, u) \rightrightarrows 0     &&\quad\Leftrightarrow\quad \Updownarrow                                                   &&\quad\Rightarrow\quad \lim_{\mathcal{B} (z)} F (f, z \to \infty, u) \to 0     \\
> \fbox{3}\quad & \lim_{\mathcal{B} (z)} |F (f, z \to \infty, u)| \to 0   &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} |F (f, z \to \infty, u)| \rightrightarrows 0   &&\quad\Leftrightarrow\quad \lim_{\mathcal{B} (z)} \sup_u |F (f, z \to \infty, u)| \to 0   &&\quad\Rightarrow\quad \Updownarrow                                            \\
> \fbox{4}\quad & \lim_{\mathcal{B} (z)} |F (f, z \to \infty, u)|^2 \to 0 &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} |F (f, z \to \infty, u)|^2 \rightrightarrows 0 &&\quad\Leftrightarrow\quad \lim_{\mathcal{B} (z)} \sup_u |F (f, z \to \infty, u)|^2 \to 0 &&\quad\Rightarrow\quad \Updownarrow                                            \\
>               &                                                         &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} F (f, z' \to z'', u) \rightrightarrows         && \lim_{\mathcal{B} (z)} F (f, \infty \to z'', u)                                                                                                                         \\
> \fbox{5}\quad & \lim_{\mathcal{B} (z)} F (f, z' \to z'', u) \to 0       &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} F (f, z' \to z'', u) \rightrightarrows 0       &&\quad\Leftrightarrow\quad \Updownarrow                                                   &&\quad\Rightarrow\quad \lim_{\mathcal{B} (z)} F (f, z' \to z'', u) \to 0       \\
> \fbox{6}\quad & \lim_{\mathcal{B} (z)} |F (f, z' \to z'', u)| \to 0     &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} |F (f, z' \to z'', u)| \rightrightarrows 0     &&\quad\Leftrightarrow\quad \lim_{\mathcal{B} (z)} \sup_u |F (f, z' \to z'', u)| \to 0     &&\quad\Rightarrow\quad \Updownarrow                                            \\
> \fbox{7}\quad & \lim_{\mathcal{B} (z)} |F (f, z' \to z'', u)|^2 \to 0   &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} |F (f, z' \to z'', u)|^2 \rightrightarrows0    &&\quad\Leftrightarrow\quad \lim_{\mathcal{B} (z)} \sup_u |F (f, z' \to z'', u)|^2 \to 0   &&\quad\Rightarrow\quad \Updownarrow                                            \\
> \end{alignedat}
> $$
>

> ### 优函数审敛法

> $$
> \begin{alignedat}{9}
> \Uparrow\;  & F (f, z, u) \le F (|f|, z, u) \le F (g, z, u) \quad\Leftarrow\quad f \le |f| \le g \\
<<<<<<< HEAD
> \Downarrow\;& \lim_{\mathcal{B} (z)} F (f, z, u) \rightrightarrows F (f, \infty) \quad\Leftarrow\quad \lim_{\mathcal{B} (z)} F (| f |, z, u) \rightrightarrows F (| f |, \infty) \quad\Leftarrow\quad \lim_{\mathcal{B} (z)} F (g, z, u) \rightrightarrows F (g, \infty) \\
=======
> \Downarrow\;& \lim_{\mathcal{B} (z)} F (f, z, u) \rightrightarrows F (f, \infty, u) \quad\Leftarrow\quad \lim_{\mathcal{B} (z)} F (| f |, z, u) \rightrightarrows F (| f |, \infty, u) \quad\Leftarrow\quad \lim_{\mathcal{B} (z)} F (g, z, u) \rightrightarrows F (g, \infty, u) \\
>>>>>>> ab3aeabde487c66a6ccb7a30bea371d7df83f57f
> \end{alignedat}
> $$
>

> ### 分部审敛法

> $$
> \begin{alignedat}{9}
> \fbox{1}\Uparrow\; & \lim_{\mathcal{B} (z)} f (z, u) \rightrightarrows 0 \quad\land \quad \lim_{\mathcal{B} (z)} F (|g|, z, u) \le M \\
> \Downarrow\;       & \lim_{\mathcal{B} (z)} \sup_u |F (f \cdot g, z \to \infty, u)| \le \lim_{\mathcal{B} (z)} \sup_u F (|f| \cdot |g|, z \to \infty, u) \le \lim_{\mathcal{B} (z)} \sup_u [|f (z, u)| \cdot F (|g|, z \to \infty, u)] \to 0 \\
> \fbox{2}\Uparrow\; & \lim_{\mathcal{B} (z)} f^\updownarrow (z, u) \rightrightarrows 0 \quad\land\quad \lim_{\mathcal{B} (z)} |F (g, z, u)| \le M \\
> \Downarrow\;       & \lim_{\mathcal{B} (z)} \sup_u |F (f \cdot g, z \to \infty, u)| \le \lim_{\mathcal{B} (z)} \sup_u |f (z, u) \cdot F (g, z \to \infty, u)| = \lim_{\mathcal{B} (z)} \sup_u [|f (z, u)| \cdot |F (g, z \to \infty, u)|] \to 0 \\
<<<<<<< HEAD
> \fbox{3}\Uparrow\; & \lim_{\mathcal{B} (z)} |f^\updownarrow (z, u)| \le M \quad\land\quad \lim_{\mathcal{B} (z)} F (g, z, u) \rightrightarrows F (g, \infty) \\
> \Downarrow\;       & \lim_{\mathcal{B} (z)} \sup_u |F (f \cdot g, z \to \infty, u)| \le \lim_{\mathcal{B} (z)} \sup_u |f^\updownarrow (z, u) \cdot F (g, z \to \infty, u)| = \lim_{\mathcal{B} (z)} \sup_u [|f^\updownarrow (z, u)| \cdot |F (g, z \to \infty, u)|] \to 0 \\
> \Downarrow\;       & \lim_{\mathcal{B} (z)} F (f \cdot g, z, u) \rightrightarrows F (f \cdot g, \infty) \\
> \end{alignedat}
> $$
>

> ### 一致收敛可交换运算次序

> $$
> \begin{alignedat}{3}
> \Uparrow\; & \lim_{\mathcal{B} (z)} \sup_u |F (f, z \to \infty, u)| \rightrightarrows 0 \\
> \Downarrow\; & \lim_{\mathcal{B} (u)} L \left( \lim_{\mathcal{B} (z)} F (f, z, u), u \right) \\
> \end{alignedat}
> $$
>

$$
\begin{alignedat}{3}
&& \lim_{\mathcal{B} (u)} L \left( \lim_{\mathcal{B} (z)} F (f, z, u), u \right) &\iff \left\lbrace\begin{alignedat}{3}
& \lim_{\mathcal{B} (u)} \lim_{\mathcal{B} (x)} f (x, u) \\
& \lim_{\mathcal{B} (x)} \lim_{n \to +\infty} \left\langle S_n (x) =  \sum_1^n s_n (x) \right\rangle \\
& \int_\alpha^\beta \mathrm{d} x \cdot \lim_{n \to +\infty} \left\langle S_n (x) = \sum_1^n s_n (x) \right\rangle \\
& \int_\alpha^{+\infty} \mathrm{d} x \cdot \lim_{n \to +\infty} \left\langle S_n (x) = \sum_1^n s_n (x) \right\rangle \\
& \int_{\alpha^+}^\beta \mathrm{d} x \cdot \lim_{n \to +\infty} \left\langle S_n (x) = \sum_1^n s_n (x) \right\rangle \\
& \dfrac{\mathrm{d}}{\mathrm{d} x} \lim_{n \to +\infty} \left\langle S_n (x) = \sum_1^n s_n (x) \right\rangle \\
\end{alignedat}\right. \\
\end{alignedat}
$$
=======
> \fbox{3}\Uparrow\; & \lim_{\mathcal{B} (z)} |f^\updownarrow (z, u)| \le M \quad\land\quad \lim_{\mathcal{B} (z)} F (g, z, u) \rightrightarrows F (g, \infty, u) \\
> \Downarrow\;       & \lim_{\mathcal{B} (z)} \sup_u |F (f \cdot g, z \to \infty, u)| \le \lim_{\mathcal{B} (z)} \sup_u |f^\updownarrow (z, u) \cdot F (g, z \to \infty, u)| = \lim_{\mathcal{B} (z)} \sup_u [|f^\updownarrow (z, u)| \cdot |F (g, z \to \infty, u)|] \to 0 \\
> \Downarrow\;       & \lim_{\mathcal{B} (z)} F (f \cdot g, z, u) \rightrightarrows F (f \cdot g, \infty, u) \\
> \end{alignedat}
> $$
>
>>>>>>> ab3aeabde487c66a6ccb7a30bea371d7df83f57f
