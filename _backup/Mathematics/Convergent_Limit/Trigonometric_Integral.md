---
layout:    zh_post
Topic:     收敛极限
Title:     三角积分
Revised:   2018-05-31 21:17:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 三角积分

> $$
> \begin{alignedat}{3}
> f (\langle -\infty < x < +\infty \rangle) &= \int_0^{+\infty} [a (u) \cdot \cos u x + b (u) \cdot \sin u x] \mathrm{d} u 
> &&\;\Leftarrow\; \left\lbrace\begin{alignedat}{3}
>                  a (u) &= \dfrac{1}{\pi} \int_{-\infty}^{+\infty} f (x) \cdot \cos u x \mathrm{d} x \\
>                  b (u) &= \dfrac{1}{\pi} \int_{-\infty}^{+\infty} f (x) \cdot \sin u x \mathrm{d} x \\
>                  \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### 三角积分的延拓性

> $$
> \begin{alignedat}{3}
> f (\langle -\infty < x < +\infty) &\xlongequal{f (x) = f (- x)} \int_0^{+\infty} a (u) \cdot \cos u x \mathrm{d} u 
> &&\;\Leftarrow\; \left\lbrace\begin{alignedat}{3}
>                      a (u) &= \dfrac{2}{\pi} \int_0^{+\infty} f (x) \cdot \cos u x \mathrm{d} x \\
>                  0 = b (u) &= \dfrac{1}{\pi} \int_{-\infty}^{+\infty} f (x) \cdot \sin u x \mathrm{d} x \\
>                  \end{alignedat}\right. \\
> f (\langle -\infty < x < +\infty) &\xlongequal{f (x) = - f (- x)} \int_0^{+\infty} b (u) \cdot \sin u x \mathrm{d} u 
> &&\;\Leftarrow\; \left\lbrace\begin{alignedat}{3}
>                  0 = a (u) &= \dfrac{1}{\pi} \int_{-\infty}^{+\infty} f (x) \cdot \cos u x \mathrm{d} x \\
>                      b (u) &= \dfrac{2}{\pi} \int_0^{+\infty} f (x) \cdot \sin u x \mathrm{d} x \\
>                  \end{alignedat}\right. \\
> \end{alignedat}
> $$
>

> ### 三角积分的收敛性

> $$
> \begin{alignedat}{3}
> \Uparrow\;           &&           S (\lambda, x_0) &= \int_0^\lambda [a (u) \cdot \cos u x_0 + b (u) \cdot \sin u x_0] \mathrm{d} u \\
>                      &&                            &= \dfrac{1}{\pi} \int_0^\lambda \int_{-\infty}^{+\infty} f (x) \cdot [\cos u x \cdot \cos u x_0 + \sin u x \cdot \sin u x_0] \mathrm{d} x \mathrm{d} u \\
>                      &&                            &= \dfrac{1}{\pi} \int_{-\infty}^{+\infty} f (x) \int_0^\lambda \cos u (x_0 - x) \mathrm{d} u \mathrm{d} x \\
>                      &&                            &= \dfrac{1}{\pi} \int_{-\infty}^{+\infty} f (x) \cdot \dfrac{\sin \lambda (x_0 - x)}{x_0 - x} \mathrm{d} x \\
>                      &&                            &\xlongequal{t = x_0 - x} \dfrac{1}{\pi} \int_{-\infty}^{+\infty} f (x_0 + t) \cdot \dfrac{\sin \lambda t}{t} \mathrm{d} t \\
>                      &&                            &\xlongequal{t = - u} \dfrac{1}{\pi} \int_0^{+\infty} [f (x_0 + t) + f (x_0 - t)] \cdot \dfrac{\sin \lambda t}{t} \mathrm{d} t \\
> \Uparrow\;           &&                            & \int_\delta^{+\infty} \dfrac{f (x_0 + t) + f (x_0 - t)}{t} \to \mathcal{Conv.} \\
> \fbox{1}\Downarrow\; && \lim_{\lambda \to +\infty} & \dfrac{1}{\pi} \int_\delta^{+\infty} \dfrac{f (x_0 + t) + f (x_0 - t)}{t} \cdot \sin \lambda t \mathrm{d} t \to 0 \\
> \fbox{2}\Downarrow\; &&                    f (x_0) &= \lim_{\lambda \to +\infty} \dfrac{1}{\pi} \int_0^\delta \dfrac{f (x_0 + t) + f (x_0 - t)}{t} \cdot \sin \lambda t \mathrm{d} t \\
> \Downarrow\;         &&                          1 &= \lim_{\lambda \to +\infty} \dfrac{2}{\pi} \int_0^\delta \dfrac{\sin \lambda t}{t} \mathrm{d} t \\
> \fbox{3}\Downarrow\; &&                f (x_0) - l &= \lim_{\lambda \to +\infty} \dfrac{1}{\pi} \int_0^\delta \dfrac{f (x_0 + t) + f (x_0 - t) - 2 l}{t} \cdot \sin \lambda t \mathrm{d} t \\
>                      &&                            &= \lim_{\lambda \to +\infty} \dfrac{1}{\pi} \int_0^\delta \left[ \dfrac{f (x_0 + t) - l}{t} + \dfrac{f (x_0 - t) - l}{t} \right] \cdot \sin \lambda t \mathrm{d} t \\
>                      &&                            &\to 0 \quad\Leftarrow\quad \int_0^\delta \left[ \dfrac{f (x_0 + t) - l}{t} + \dfrac{f (x_0 - t) - l}{t} \right] \mathrm{d} t \to \mathcal{Conv.} \\
> \fbox{4}\Downarrow\; &&                    f (x_0) &\xlongequal{2 l = f (x_0^+) + f (x_0^-)} \dfrac{f (x_0^+) + f (x_0^-)}{t} \quad\Leftarrow\quad f' (x_0^+) + f' (x_0^-) \\
> \end{alignedat}
> $$
>

> ### 三角积分变换

> $$
> \begin{alignedat}{3}
> \Uparrow\;           &&       f (x) &= \int_0^{+\infty} [a (u) \cdot \cos u x + b (u) \cdot \sin u x] \mathrm{d} u \\
>                      &&             &= \int_0^{+\infty} \left[ a (u) \dfrac{e^{\imath u x} + e^{- \imath u x}}{2} + b (u) \dfrac{e^{\imath u x} - e^{- \imath ux}}{2 \imath} \right] \mathrm{d} u \\
>                      &&             &= \int_0^{+\infty} \left[ \dfrac{a (u) - \imath b (u)}{2} e^{\imath u x} + \dfrac{a (u) + \imath b (u)}{2} e^{- \imath u x} \right] \mathrm{d} u \\
>                      &&             &= \int_{-\infty}^{+\infty} \dfrac{a (u) - \imath b (u)}{2} e^{\imath u x} \mathrm{d} u + \int_{-\infty}^0 \dfrac{a (- u) + \imath b (- u)}{2} e^{\imath u x} \mathrm{d} u \\
>                      &&             &= \dfrac{1}{\sqrt{2 \pi}} \int_{-\infty}^{+\infty} e^{\imath u x} \mathrm{d} u \dfrac{1}{\sqrt{2 \pi}} \int_{-\infty}^{+\infty} f (x) e^{- \imath u x} \mathrm{d} x \\
> \fbox{1}\Downarrow\; && \hat{f} (u) &= \dfrac{1}{\sqrt{2 \pi}} \int_{-\infty}^{+\infty} f (x) e^{- \imath u x} \mathrm{d} x \\
> \fbox{2}\Downarrow\; &&       f (x) &= \dfrac{1}{\sqrt{2 \pi}} \int_{-\infty}^{+\infty} \hat{f} (u) e^{\imath u x} \mathrm{d} u \\
> \end{alignedat}
> $$
>

> ### 卷积运算

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&           (f * g) (t) &= \dfrac{1}{\sqrt{2 \pi}} \int_{-\infty}^{+\infty} f (\tau) \cdot g (t - \tau) \mathrm{d} \tau \\
> \Downarrow\; && \widehat{(f * g)} (x) &= \dfrac{1}{2 \pi} \int_{-\infty}^{+\infty} \left( \int_{-\infty}^{+\infty} f (\tau) \cdot g (t - \tau) \mathrm{d} \tau \right) e^{- \imath x t} \mathrm{d} t \\
>              &&                       &\xlongequal{u = t - \tau} \dfrac{1}{2 \pi} \int_{-\infty}^{+\infty} f (\tau) e^{- \imath x \tau} \mathrm{d} \tau \int_{-\infty}^{+\infty} g (u) e^{- \imath x u} \mathrm{d} u \\
>              &&                       &= \hat{f} (x) \cdot \hat{g} (x) \\
> \end{alignedat}
> $$
>
