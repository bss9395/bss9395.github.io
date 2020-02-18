---
layout:    zh_post
Topic:     基础数学
Title:     自然基数
Revised:   2018-04-08 20:32:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 自然数列 $\lbrace s_n = (1 + \frac{\alpha \gt 0}{n})^n \rbrace$

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&       s_n &= \left( 1 + \dfrac{\alpha}{n} \right)^n \\
>              &&           &= \left[ \sqrt[n + 1]{1 \cdot \left( 1 + \dfrac{\alpha}{n} \right)^n} \right]^{n + 1} \\
>              &&           &< \left[ \dfrac{1 + n \cdot \left( 1 + \dfrac{\alpha}{n}\right)}{n + 1} \right]^{n + 1} \\
>              && s_{n + 1} &= \left( 1 + \dfrac{\alpha}{n + 1} \right)^{n + 1} \\
> \Downarrow\; &&       s_n &< s_{n + 1} \\
> \end{alignedat}
> $$
>

> ### 自然函数 $y = (1 + \frac{\alpha \in \mathbb{R}}{x})^x$

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&                                  y &= \left(1 + \dfrac{\alpha}{x}\right)^x = e^{x \ln \left(1 + \frac{\alpha}{x}\right)} \\
> \Downarrow\; && \dfrac{\mathrm{d} y}{\mathrm{d} x} &=  e^{x \ln \left(1 + \frac{\alpha}{x}\right)} \left[\ln \left(1 + \dfrac{\alpha}{x}\right) - \dfrac{\alpha}{x + \alpha} \right] &&\;\Leftarrow\; e^{x \ln \left(1 + \frac{\alpha}{x}\right)} > 0 \\
> \Uparrow\;   &&                              z (x) &\equiv \ln \left(1 + \dfrac{\alpha}{x}\right) - \dfrac{\alpha}{x + \alpha} \\
> \Downarrow\; && \dfrac{\mathrm{d} z}{\mathrm{d} x} &= - \dfrac{\alpha^2}{x (x + \alpha)^2}                                                                                           &&\;\Rightarrow\; \lim_{\pm\infty} \dfrac{\mathrm{d} z}{\mathrm{d} x} \to 0 \\
> \Downarrow\; &&                             \inf z &= \lim_{x \to \pm \infty} \left[\ln \left(1 + \dfrac{\alpha}{x}\right) - \dfrac{\alpha}{x + \alpha}\right] \to 0                 &&\;\Rightarrow\; z > 0 \\
> \Downarrow\; && \dfrac{\mathrm{d} y}{\mathrm{d} x} &\gt 0
> \end{alignedat}
> $$
>

> ### 自然基数 $e := \lim\limits_{x \to \pm \infty} \left(1 + \frac{1}{x}\right)^x$

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&                         \left(1 + \dfrac{1}{n + 1}\right)^n \le & \left(1 + \dfrac{1}{x}\right)^x \le \left(1 + \dfrac{1}{n}\right)^{n + 1}                         &\;&\Leftarrow\; n \le x \le n + 1 \\
> \Downarrow\; && \lim_{n \to + \infty} \left(1 + \dfrac{1}{n + 1}\right)^{n + 1} & \left(1 + \dfrac{1}{n + 1}\right)^{- 1} \le \lim_{x \to + \infty} \left(1 + \dfrac{1}{x}\right)^x &&\le \lim_{n \to + \infty} \left(1 + \dfrac{1}{n}\right)^n \left(1 + \dfrac{1}{n}\right) \\
> \Downarrow\; &&         \lim_{n \to + \infty} \left( 1 + \dfrac{1}{n} \right)^n &= \lim_{x \to + \infty} \left( 1 + \dfrac{1}{x} \right)^x \\
> \Uparrow\;   &&           \lim_{x \to + \infty} \left(1 + \dfrac{1}{x}\right)^x &= \lim_{x \to + \infty} \left( 1 - \dfrac{1}{x + 1} \right)^{- x} \\
>              &&                                                                 &= \lim_{t \to - \infty} \left( 1 + \dfrac{1}{t} \right)^{t + 1}                                    &\;&\Leftarrow\; t \equiv - (x + 1) \\
>              &&           \lim_{x \to + \infty} \left(1 + \dfrac{1}{x}\right)^x &= \lim_{t \to - \infty} \left( 1 + \dfrac{1}{t} \right)^t \\
> \Downarrow\; &&                                                               e &:= \lim_{x \to \pm \infty} \left( 1 + \dfrac{1}{x} \right)^x \\
> \end{alignedat}
> $$
>

> ### 自然超越数 $e^\alpha = \lim\limits_{x \to \pm \infty} \left( 1 + \frac{\alpha \in \mathbb{R}}{x} \right)^x  $

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\; &&       \lim_{x \to \pm \infty} \left( 1 + \dfrac{\alpha \ne 0}{x} \right)^x &= \lim_{x \to \pm \infty}  \left( 1 + \dfrac{1}{\frac{x}{\alpha}} \right)^{\frac{x}{\alpha} \cdot \alpha} \\
>                    &&                                                                           &= \left[ \lim_{x \to \pm \infty} \left( 1 + \dfrac{1}{\frac{x}{\alpha}} \right)^{\frac{x}{\alpha}} \right]^\alpha \\
>                    &&                                                                           &= e^\alpha \\
> \fbox{2}\Uparrow\; &&         \lim_{x \to \pm \infty} \left( 1 + \dfrac{\alpha = 0}{x} \right)^x &= \lim_{x \to \pm \infty} 1^x \\
>                    &&                                                                           &= 1 \\
>                    &&                                                                           &= e^\alpha \\
> \Downarrow\;       && e^\alpha = \lim_{n \to \pm \infty} \left( 1 + \dfrac{\alpha}{x} \right)^x & \\
> \end{alignedat}
> $$
>

