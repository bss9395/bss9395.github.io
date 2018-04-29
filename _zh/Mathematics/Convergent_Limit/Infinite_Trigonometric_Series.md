---
layout:    zh_post
Topic:     收敛极限
Title:     无穷三角级数
Revised:   2018-04-28 01:58:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 正交三角系

> $$
> \begin{alignedat}{3}
> && \lbrace \varphi_k \rbrace &= \lbrace 1, \cos x, \sin x, \cdots, \cos k x, \sin k x, \cdots \rbrace \\
> && 0 < m, 0 < n &\implies
> \left\lbrace\begin{alignedat}{3}
> \fbox{1}\; & \int_{- \pi}^\pi e^{\imath m x} \cdot e^{- \imath n x} \mathrm{d} x = 2 \pi \cdot \delta^{m n} \\
> \fbox{2}\; & \int_{- \pi}^\pi \sin m x \cdot \sin n x \mathrm{d} x = \int_{- \pi}^\pi \cos m x \cdot \cos n x \mathrm{d} x = \pi \cdot \delta^{m n} \\
> \fbox{3}\; & \int_{- \pi}^\pi \sin m x \cdot \cos n x \mathrm{d} x = \int_{- \pi}^\pi \cos m x \cdot \sin n x \mathrm{d} x = 0 \\
> \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### 三角级数

> $$
> \begin{alignedat}{3}
> && f (x + 2 \pi) &= f (\langle - \pi \le x \le \pi \rangle) = \dfrac{a_0}{2} + \sum_1^{+\infty} (a_n \cos n x + b_n \sin n x)
> &&\;\Leftarrow\; \left\lbrace\begin{alignedat}{3}
>                  a_n &= \dfrac{1}{\pi} \int_{- \pi}^\pi f (x) \cos n x \mathrm{d} x \\
>                  b_n &= \dfrac{1}{\pi} \int_{- \pi}^\pi f (x) \sin n x \mathrm{d} x \\
>                  \end{alignedat}\right. \\
> && f (x + 2 \pi) &= f (\langle - \pi \le x \le \pi \rangle) \xlongequal{f (x) = f (- x)} \dfrac{a_0}{2} + \sum_1^{+\infty} a_n \cos n x 
> &&\;\Leftarrow\; \left\lbrace\begin{alignedat}{3}
>                  a_n &= \dfrac{2}{\pi} \int_0^{\pi} f (x) \cos n x \mathrm{d} x \\
>                  0 = b_n &= \dfrac{1}{\pi} \int_{- \pi}^{\pi} f (x) \sin n x \mathrm{d} x \\
>                  \end{alignedat}\right. \\
> && f (x + 2 \pi) &= f (\langle - \pi \le x \le \pi \rangle) \xlongequal{f (x) = - f (- x)} \sum_1^{+\infty} b_n \sin n x 
> &&\;\Leftarrow\; \left\lbrace\begin{alignedat}{3}
>                  0 = a_n &= \dfrac{1}{\pi} \int_{- \pi}^{\pi} f (x) \cos n x \mathrm{d} x  \\
>                  b_n &= \dfrac{2}{\pi} \int_0^{\pi} f (x) \sin n x \mathrm{d} x \\
>                  \end{alignedat}\right. \\
> &&    g (t+ 2 T) &= g (\langle - T \le t \le T \rangle) \xlongequal[f (x) = f (x + 2 \pi)]{g \left( \left\langle t = \frac{T}{\pi} x \right\rangle \right)} \dfrac{a_0}{2} + \sum_1^{+\infty} \left( a_n \cos \dfrac{n}{T} \pi t + b_n \sin \dfrac{n}{T} \pi t \right)
> &&\;\Leftarrow\; \left\lbrace\begin{alignedat}{3}
>                  a_n &= \dfrac{1}{T} \int_{- T}^T g (t) \cos \dfrac{n}{T} \pi t \mathrm{d} t = \dfrac{1}{\pi} \int_{- \pi}^\pi g \left( \dfrac{T}{\pi} x \right) \cos n x \mathrm{d} x \\
>                  b_n &= \dfrac{1}{T} \int_{- T}^T g (t) \sin \dfrac{n}{T} \pi t \mathrm{d} t = \dfrac{1}{\pi} \int_{- \pi}^\pi g \left( \dfrac{T}{\pi} \right) x \sin n x \mathrm{d} x \\
>                  \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### 三角级数的系数

> $$
> \begin{alignedat}{3}
> \Uparrow\;           & \int_\alpha^\beta f^{(k)} (x) \mathrm{d} x \to \mathcal{Conv.} \quad\Rightarrow\quad \dfrac{1}{\lambda} \cdot \int_\alpha^\beta f^{(k)} \left( \dfrac{\lambda x}{\lambda} \right) \mathrm{d} (\lambda x) \to \mathcal{Conv.} \\
> \fbox{1}\Downarrow\; & \lim_{+ \infty} \int_\alpha^\beta f (x) \cos \lambda x \mathrm{d} x \xlongequal[g (t) = f \left( \frac{t}{\lambda} \right)]{t = \lambda x} \lim_{+\infty} \dfrac{1}{\lambda} \int_{\lambda \alpha}^{\lambda \beta} g (t) \cos t \mathrm{d} t \to 0 \\
> \Downarrow\;         & \lim_{+\infty} a_n \to 0 \\
> \fbox{2}\Downarrow\; & \lim_{+\infty} \int_\alpha^\beta f (x) \sin \lambda x \mathrm{d} x \xlongequal[g (t) = f \left( \frac{t}{\lambda} \right)]{t = \lambda x} \lim_{+\infty} \int_{\lambda \alpha}^{\lambda \beta} g (t) \sin t \mathrm{d} t \to 0 \\
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
> \Uparrow\;           &&            S_n (x_0) &= \dfrac{a_0}{2} + \sum_1^{+\infty} (a_n \cos n x_0 + b_n \sin n x_0) \\
>                      &&                      &= \dfrac{1}{2 \pi} \int_{- \pi}^\pi f (x) \mathrm{d} x + \dfrac{1}{\pi} \sum_1^{+\infty} \int_{- \pi}^\pi f (x) \cdot  (\cos n x \cos n x_0 + \sin n x \sin n x_0) \mathrm{d} x \\
>                      &&                      &= \dfrac{1}{\pi} \int_{- \pi}^\pi f (x) \cdot \left[ \dfrac{1}{2} + \sum_1^{+\infty} \cos n (x - x_0) \right] \mathrm{d} x \\
>                      &&                      &= \dfrac{1}{\pi} \int_{- \pi}^\pi f (x) \cdot \dfrac{\sin \left( n + \dfrac{1}{2} \right) (x - x_0)}{2 \sin \dfrac{1}{2} (x - x_0)} \mathrm{d} x \\
>                      &&                      &\xlongequal{t = x - x_0} \dfrac{1}{\pi} \left\langle \int_{- \pi - x_0}^{\pi - x_0} = \int_{- \pi}^\pi \right\rangle f (x_0 + t) \cdot \dfrac{\sin \left( n + \dfrac{1}{2} \right) t}{2 \sin \dfrac{t}{2}} \mathrm{d} t \\
>                      &&                      &\xlongequal{t = - u} \dfrac{1}{\pi} \int_0^\pi [f (x_0 + t) + f (x_0 - t)] \cdot \dfrac{\sin \left( n + \dfrac{1}{2} \right) t}{2 \sin \dfrac{t}{2}} \mathrm{d} t \\
> \Uparrow\;           &&                      & \int_0^\pi \dfrac{f (x_0 + t) + f (x_0 - t)}{t} \cdot \mathrm{d} t \to \mathcal{Conv.} \\
> \Downarrow\;         && \lim_{n \to +\infty} & \int_\delta^\pi \dfrac{f (x_0 + t) + f (x_0 - t)}{2 \sin \dfrac{t}{2}} \cdot \sin \left( n + \dfrac{1}{2} \right) t \mathrm{d} t \to 0 \quad\Leftarrow\quad \lim_{\lambda \to +\infty} \int_0^\pi \varphi (t) \sin \lambda t \mathrm{d} t \to 0 \\
> \fbox{1}\Downarrow\; &&              f (x_0) &= \lim_{n \to +\infty} \dfrac{1}{\pi} \int_0^\delta [f (x_0 + t) + f (x_0 - t)] \cdot \dfrac{\sin \left( n + \dfrac{1}{2} \right)}{2 \sin \dfrac{t}{2}} \mathrm{d} t \\
> \Downarrow\;         &&                    1 &\xlongequal{f (x) \equiv 1} \lim_{n \to +\infty} \dfrac{1}{\pi} \int_0^\delta \dfrac{\sin \left( n + \dfrac{1}{2} \right)}{2 \sin \dfrac{t}{2}} \mathrm{d}  t \\
> \fbox{2}\Downarrow\; &&          f (x_0) - l &= \lim_{n \to +\infty} \dfrac{1}{\pi} \int_0^\delta [f (x_0 + t) + f (x_0 - t) - 2 l] \cdot \dfrac{\sin \left( n + \dfrac{1}{2} \right)}{2 \sin \dfrac{t}{2}} \mathrm{d} t \\
>                      &&                      &\le \lim_{n \to +\infty} \dfrac{1}{\pi} \int_0^\delta \dfrac{f (x_0 + t) + f (x_0 - t) - 2 l}{t} \cdot \sin \left( n + \dfrac{1}{2} \right) \mathrm{d} t \\
>                      &&                      &\to 0 \quad\Leftarrow\quad \left| \dfrac{f (x_0 + t) + f (x_0 - t) - 2 l}{t} \right| \le \dfrac{M}{t^{\langle \alpha < 1 \rangle}} \\
> \fbox{3}\Downarrow\; &&              f (x_0) &\xlongequal{2 l = f (x_0^+) + f (x_0^-)} \dfrac{f (x_0^+) + f (x_0^-)}{2} \\
>                      &&                      &= \lim_{n \to +\infty} \dfrac{1}{\pi} \int_0^\delta \left[ \left\langle \dfrac{f (x_0 + t) - f (x_0^+)}{t} \to f' (x_0^+) \right\rangle + \left\langle \dfrac{f (x_0 - t) - f (x_0^-)}{t} \to f' (x_0^-) \right\rangle \right] \cdot \sin \left( n + \dfrac{1}{2} \right) \mathrm{d} t \\
> \end{alignedat}
> $$
>

