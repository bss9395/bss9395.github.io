---
layout:    zh_post
Topic:     收敛极限
Title:     统一收敛极限理论
Revised:   2018-04-22 03:35:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 收敛极限理论

> $$
> \begin{alignedat}{9}
> \fbox{1}\quad & \lim_{\mathcal{B} (z)} F (f, z) \to F (f, \infty)          &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} F (f, z, u) \rightrightarrows F (f, \infty, u)         &&\quad\Leftrightarrow\quad \Updownarrow                                                           &&\quad\Rightarrow\quad \lim_{\mathcal{B} (z)} F (f, z, u) \to F (f, \infty, u)       \\
> \fbox{2}\quad & \lim_{\mathcal{B} (z)} [F (f, z) - F (f, \infty)] \to 0    &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} [F (f, z, u) - F (f, \infty, u)] \rightrightarrows 0   &&\quad\Leftrightarrow\quad \Updownarrow                                                           &&\quad\Rightarrow\quad \lim_{\mathcal{B} (z)} [F (f, z, u) - F (f, \infty, u)] \to 0 \\
> \fbox{3}\quad & \lim_{\mathcal{B} (z)} |F (f, z) - F (f, \infty)| \to 0    &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} |F (f, z, u) - F (f, \infty, u)| \rightrightarrows 0   &&\quad\Leftrightarrow\quad \lim_{\mathcal{B} (z)} \sup_u |F (f, z, u) - F (f, \infty, u)| \to 0   &&\quad\Rightarrow\quad \Updownarrow                                                  \\
> \fbox{4}\quad & \lim_{\mathcal{B} (z)} | F (f, z) - F (f, \infty)|^2 \to 0 &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} |F (f, z, u) - F (f, \infty, u)|^2 \rightrightarrows 0 &&\quad\Leftrightarrow\quad \lim_{\mathcal{B} (z)} \sup_u |F (f, z, u) - F (f, \infty, u)|^2 \to 0 &&\quad\Rightarrow\quad \Updownarrow                                                  \\
>               &                                                            &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} [F (f, z', u) - F (f, z'', u)] \rightrightarrows       && \lim_{\mathcal{B} (z)} [F (f, \infty, u) - F (f, z'', u)]                                                                                                                             \\
> \fbox{5}\quad & \lim_{\mathcal{B} (z)} [F (f, z') - F (f, z'')] \to 0      &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} [F (f, z', u) - F (f, z'', u)] \rightrightarrows 0     &&\quad\Leftrightarrow\quad \Updownarrow                                                           &&\quad\Rightarrow\quad \lim_{\mathcal{B} (z)} [F (f, z', u) - F (f, z'', u)] \to 0   \\
> \fbox{6}\quad & \lim_{\mathcal{B} (z)} |F (f, z') - F (f, z'')| \to 0      &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} |F (f, z', u) - F (f, z'', u)| \rightrightarrows 0     &&\quad\Leftrightarrow\quad \lim_{\mathcal{B} (z)} \sup_u |F (f, z', u) - F (f, z'', u)| \to 0     &&\quad\Rightarrow\quad \Updownarrow                                                  \\
> \fbox{7}\quad & \lim_{\mathcal{B} (z)} |F (f, z') - F (f, z'')|^2 \to 0    &&\quad\Updownarrow\quad \lim_{\mathcal{B} (z)} |F (f, z', u) - F (f, z'', u)|^2 \rightrightarrows0    &&\quad\Leftrightarrow\quad \lim_{\mathcal{B} (z)} \sup_u |F (f, z', u) - F (f, z'', u)|^2 \to 0   &&\quad\Rightarrow\quad \Updownarrow                                                  \\
> \end{alignedat}
> $$
>

> ### 优函数审敛法

> $$
> \begin{alignedat}{3}
>\Uparrow\; & F (f, z, u) \le F (|f|, z, u) \le F (g, z, u) \quad\Leftarrow\quad f \le |f| \le g \\
> \Downarrow\;& \lim_{\mathcal{B} (z)} F (f, z, u) \rightrightarrows F (f, \infty, u) \quad\Leftarrow\quad \lim_{\mathcal{B} (z)} F (| f |, z, u) \rightrightarrows F (| f |, \infty, u) \quad\Leftarrow\quad \lim_{\mathcal{B} (z)} F (g, z, u) \rightrightarrows F (g, \infty, u) \\
>
> \end{alignedat}
> $$
>