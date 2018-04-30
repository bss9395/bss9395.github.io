---
layout:    zh_post
Topic:     收敛极限
Title:     无穷三角级数
Revised:   2018-04-30 20:16:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 正交三角系

> $$
> \begin{alignedat}{3}
> \lbrace \varphi_k \rbrace &= \lbrace 1, \cos x, \sin x, \cdots, \cos k x, \sin k x, \cdots \rbrace \\
>              0 < m, 0 < n &\implies \left\lbrace\begin{alignedat}{3}
>                                     & \int_{- \pi}^\pi e^{\imath m x} \cdot e^{- \imath n x} \mathrm{d} x = 2 \pi \cdot \delta^{m n} \\
>                                     & \int_{- \pi}^\pi \sin m x \cdot \sin n x \mathrm{d} x = \int_{- \pi}^\pi \cos m x \cdot \cos n x \mathrm{d} x = \pi \cdot \delta^{m n} \\
>                                     & \int_{- \pi}^\pi \sin m x \cdot \cos n x \mathrm{d} x = \int_{- \pi}^\pi \cos m x \cdot \sin n x \mathrm{d} x = 0 \\
>                                     \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### 三角级数

> $$
> \begin{alignedat}{3}
> f (x + 2 \pi) = f (\langle - \pi \le x \le \pi \rangle) &= \dfrac{a_0}{2} + \sum_1^{+\infty} (a_n \cos n x + b_n \sin n x) 
> &&\;\Leftarrow\; \left\lbrace\begin{alignedat}{3}
>                  a_n &= \dfrac{1}{\pi} \int_{- \pi}^\pi f (x) \cos n x \mathrm{d} x \\
>                  b_n &= \dfrac{1}{\pi} \int_{- \pi}^\pi f (x) \sin n x \mathrm{d} x \\
>                  \end{alignedat}\right. \\
> g (t+ 2 T) = g (\langle - T \le t \le T \rangle) &\xlongequal{g \left( \left\langle t = \frac{T}{\pi} x \right\rangle \right)} \dfrac{a_0}{2} + \sum_1^{+\infty} \left( a_n \cos \dfrac{n}{T} \pi t + b_n \sin \dfrac{n}{T} \pi t \right) 
> &&\;\Leftarrow\; \left\lbrace\begin{alignedat}{3}
>                  a_n &= \dfrac{1}{T} \int_{- T}^T g (t) \cos \dfrac{n}{T} \pi t \mathrm{d} t = \dfrac{1}{\pi} \int_{- \pi}^\pi g \left( \dfrac{T}{\pi} x \right) \cos n x \mathrm{d} x \\
>                  b_n &= \dfrac{1}{T} \int_{- T}^T g (t) \sin \dfrac{n}{T} \pi t \mathrm{d} t = \dfrac{1}{\pi} \int_{- \pi}^\pi g \left( \dfrac{T}{\pi} x \right) \sin n x \mathrm{d} x \\
>                  \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### 三角级数的延拓性

> $$
> \begin{alignedat}{3}
> f (x + 2 \pi) = f (\langle - \pi \le x \le \pi \rangle) &\xlongequal{f (x) = f (- x)} \dfrac{a_0}{2} + \sum_1^{+\infty} a_n \cos n x 
> &&\;\Leftarrow\; \left\lbrace\begin{alignedat}{3}
>                      a_n &= \dfrac{2}{\pi} \int_0^{\pi} f (x) \cos n x \mathrm{d} x \\
>                  0 = b_n &= \dfrac{1}{\pi} \int_{- \pi}^{\pi} f (x) \sin n x \mathrm{d} x \\
>                  \end{alignedat}\right. \\
> f (x + 2 \pi) = f (\langle - \pi \le x \le \pi \rangle) &\xlongequal{f (x) = - f (- x)} \sum_1^{+\infty} b_n \sin n x 
> &&\;\Leftarrow\; \left\lbrace\begin{alignedat}{3}
>                  0 = a_n &= \dfrac{1}{\pi} \int_{- \pi}^{\pi} f (x) \cos n x \mathrm{d} x  \\
>                      b_n &= \dfrac{2}{\pi} \int_0^{\pi} f (x) \sin n x \mathrm{d} x \\
>                  \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### 三角级数的系数

> $$
> \begin{alignedat}{3}
> \Uparrow\;           & \int_\alpha^\beta f^{(k)} (x) \mathrm{d} x \to \mathcal{Conv.} \quad\Rightarrow\quad \dfrac{1}{\lambda} \cdot \int_\alpha^\beta f^{(k)} \left( \dfrac{\lambda x}{\lambda} \right) \mathrm{d} (\lambda x) \to \mathcal{Conv.} \\
> \fbox{1}\Downarrow\; & \lim_{+ \infty} \int_\alpha^\beta f (x) \cos \lambda x \mathrm{d} x = \lim_{+\infty} \dfrac{1}{\lambda} \cdot \int_\alpha^\beta f \left( \dfrac{\lambda x}{\lambda} \right) \cos (\lambda x) \mathrm{d} (\lambda x) \to 0 \\
> \Downarrow\;         & \lim_{+\infty} a_n \to 0 \\
> \fbox{2}\Downarrow\; & \lim_{+\infty} \int_\alpha^\beta f (x) \sin \lambda x \mathrm{d} x = \lim_{+\infty} \dfrac{1}{\lambda} \cdot \int_\alpha^\beta f \left( \dfrac{\lambda x}{\lambda} \right) \sin (\lambda x) \mathrm{d} (\lambda x) \to 0 \\
> \Downarrow\;         & \lim_{+\infty} b_n \to 0 \\
> \fbox{3}\Uparrow\;   & a_n = \dfrac{1}{n} \int_{- \pi}^\pi f (x) \cos n x \mathrm{d} x = - \dfrac{1}{n \pi} \int_{- \pi}^\pi f' (x) \sin n x \mathrm{d} x = - \dfrac{b_n^{(1)}}{n} \\
> \Downarrow\;         & a_n = o \left( \dfrac{1}{n^1} \right) = o \left( \dfrac{1}{n^k} \right) \\
> \fbox{4}\Uparrow\;   & b_n = \dfrac{1}{n} \int_{-\pi}^\pi f (x) \sin n x \mathrm{d} x = + \dfrac{1}{n \pi} \int_{- \pi}^\pi f' (x) \cos n x \mathrm{d} x = \dfrac{a_n^{(1)}}{n} \\
> \Downarrow\;         & b_n = o \left( \dfrac{1}{n^1} \right) = o \left( \dfrac{1}{n^k} \right) \\
> \end{alignedat}
> $$
>

> ### 三角级数的收敛性

> $$
> \begin{alignedat}{3}
> \Uparrow\;           &&            S_n (x_0) &= \dfrac{a_0}{2} + \sum_1^n (a_n \cos n x_0 + b_n \sin n x_0) \\
>                      &&                      &= \dfrac{1}{2 \pi} \int_{- \pi}^\pi f (x) \mathrm{d} x + \dfrac{1}{\pi} \sum_1^n \int_{- \pi}^\pi f (x) \cdot  (\cos n x \cos n x_0 + \sin n x \sin n x_0) \mathrm{d} x \\
>                      &&                      &= \dfrac{1}{\pi} \int_{- \pi}^\pi f (x) \cdot \left[ \dfrac{1}{2} + \sum_1^n \cos n (x_0 - x) \right] \mathrm{d} x \\
>                      &&                      &= \dfrac{1}{\pi} \int_{- \pi}^\pi f (x) \cdot \dfrac{\sin \left( n + \dfrac{1}{2} \right) (x_0 - x)}{2 \sin \dfrac{1}{2} (x_0 - x)} \mathrm{d} x \\
>                      &&                      &\xlongequal{t = x_0 - x} \dfrac{1}{\pi} \left\langle \int_{- \pi - x_0}^{\pi - x_0} = \int_{- \pi}^\pi \right\rangle f (x_0 + t) \cdot \dfrac{\sin \left( n + \dfrac{1}{2} \right) t}{2 \sin \dfrac{t}{2}} \mathrm{d} t \\
>                      &&                      &\xlongequal{t = - u} \dfrac{1}{\pi} \int_0^\pi [f (x_0 + t) + f (x_0 - t)] \cdot \dfrac{\sin \left( n + \dfrac{1}{2} \right) t}{2 \sin \dfrac{t}{2}} \mathrm{d} t \\
> \Uparrow\;           &&                      & \int_\delta^\pi [f (x_0 + t) + f (x_0 - t)] \cdot \mathrm{d} t \to \mathcal{Conv.} \\
> \fbox{1}\Downarrow\; && \lim_{n \to +\infty} & \dfrac{1}{\pi} \int_\delta^\pi [f (x_0 + t) + f (x_0 - t)] \cdot \dfrac{1}{2 \sin \dfrac{t}{2}} \cdot \sin \left( n + \dfrac{1}{2} \right) t \mathrm{d} t \to 0 \\
> \fbox{2}\Downarrow\; &&              f (x_0) &= \lim_{n \to +\infty} \dfrac{1}{\pi} \int_0^\delta [f (x_0 + t) + f (x_0 - t)] \cdot \dfrac{\sin \left( n + \dfrac{1}{2} \right) t}{2 \sin \dfrac{t}{2}} \mathrm{d} t \\
> \Downarrow\;         &&                    1 &\xlongequal{f (x) \equiv 1} \lim_{n \to +\infty} \dfrac{1}{\pi} \int_0^\delta \dfrac{\sin \left( n + \dfrac{1}{2} \right) t}{\sin \dfrac{t}{2}} \mathrm{d}  t \\
> \fbox{3}\Downarrow\; &&          f (x_0) - l &= \lim_{n \to +\infty} \dfrac{1}{\pi} \int_0^\delta [f (x_0 + t) + f (x_0 - t) - 2 l] \cdot \dfrac{\sin \left( n + \dfrac{1}{2} \right) t}{2 \sin \dfrac{t}{2}} \mathrm{d} t \\
>                      &&                      &= \lim_{n \to +\infty} \dfrac{1}{\pi} \int_0^\delta \left[ \dfrac{f (x_0 + t) - l}{t} + \dfrac{f (x_0 - t) - l}{t} \right] \cdot \dfrac{t}{2 \sin \dfrac{t}{2}} \cdot \sin \left( n + \dfrac{1}{2} \right) t \mathrm{d} t \\
>                      &&                      &\to 0 \quad\Leftarrow\quad \int_0^\delta \left[ \dfrac{f (x_0 + t) - l}{t} + \dfrac{f (x_0 - t) - l}{t} \right] \mathrm{d} t \to \mathcal{Conv.} \\
> \fbox{4}\Downarrow\; &&              f (x_0) &\xlongequal{2 l = f (x_0^+) + f (x_0^-)} \dfrac{f (x_0^+) + f (x_0^-)}{2} \quad\Leftarrow\quad f' (x_0^+) \;\land\; f' (x_0^-) \\
> \end{alignedat}
> $$
>

> ### 三角级数变换

> $$
> \begin{alignedat}{3}
> \Uparrow\;           &&       f (x) &= \dfrac{a_0}{2} + \sum_1^{+\infty} (a_n \cos n x + b_n \sin n x) \\
>                      &&             &= \dfrac{a_0}{2} + \sum_1^{+\infty} \left( a_n \dfrac{e^{\imath n x} + e^{- \imath n x}}{2} + b_n \dfrac{e^{\imath n x} - e^{- \imath n x}}{2 \imath} \right) \\
>                      &&             &= \dfrac{a_0}{2} + \sum_1^{+\infty} \left( \dfrac{a_n - \imath b_n}{2} e^{\imath n x} + \dfrac{a_n + \imath b_n}{2} e^{- \imath n x} \right) \\
>                      &&             &= \sum_{-\infty}^{+\infty} c_n e^{\imath n x} \\
> \Downarrow\;         &&         c_0 &= \dfrac{a_0}{2} = \dfrac{1}{2 \pi} \int_{- \pi}^\pi f (x) \mathrm{d} x = \dfrac{1}{2 \pi} \int_{- \pi}^\pi f (x) e^{\imath 0 x} \mathrm{d} x \\
> \Downarrow\;         &&         c_n &= \dfrac{a_n - \imath b_n}{2} = \dfrac{1}{2 \pi} \left[ \int_{- \pi}^\pi f (x) \cos n x \mathrm{d} x - \imath \int_{- \pi}^\pi f (x) \sin n x \mathrm{d} x \right] = \dfrac{1}{2 \pi} \int_{- \pi}^\pi f (x) e^{- \imath n x} \mathrm{d} x \\
> \Downarrow\;         &&     c_{- n} &= \dfrac{a_n + \imath b_n}{2} = \dfrac{1}{2 \pi} \left[ \int_{- \pi}^\pi f (x) \cos n x \mathrm{d} x + \imath \int_{- \pi}^\pi f (x) \sin n x \mathrm{d} x  \right] = \dfrac{1}{2 \pi} \int_{- \pi}^\pi f (x) e^{+ \imath n x} \mathrm{d} x \\
> \fbox{1}\Downarrow\; && \hat{f} (n) &= \dfrac{1}{2 \pi} \int_{- \pi}^\pi f (x) e^{- \imath n x} \mathrm{d} x \\
> \fbox{2}\Downarrow\; &&       f (x) &= \sum_{-\infty}^{+\infty} \hat{f} (n) e^{\imath n x} \\ 
> \end{alignedat}
> $$
>