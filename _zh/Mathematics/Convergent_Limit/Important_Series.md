---
layout:    zh_post
Topic:     收敛极限
Title:     重要级数
Revised:   2018-04-09 20:33:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 初等级数

> | **$$f (x)$$** | **(-R, +R)** | **$$f (0) + \sum\limits_1^{+\infty}  \dfrac{f^{(n)} (x)}{n !} x^n + O (x^{n + 1})$$** | **$$f^{(n)} (x)$$** |
> | :------------------- | :--------------------------------------- | :--------------------------------------- | :--------------------------------------- |
> | $(1 + x)^P$          | $$(-1, +1); P \le -1$$ $$(-1, +1]; -1 \lt P \lt 0$$ $$[-1, +1]; P \gt 0$$ | $$1 + \sum\limits_1^{+ \infty} \dfrac{P (P - 1) \cdots (P - n + 1)}{n !} x^n + O (x^{n + 1})$$ | $$P (P - 1) \cdots (P - n + 1) (1 + x)^{P - n}$$ |
> | $$\dfrac{1}{1 - x}$$ | $$(-1, +1)$$ | $$1 + \sum\limits_1^{+ \infty} x^n + O (x^{n + 1})$$ | $$n ! (1 + x)^{- n - 1}$$       |
> | $$E^x$$              | $$(-\infty, +\infty)$$ | $$1 + \sum\limits_1^{+ \infty} \dfrac{\ln^n E}{n !} x^n + O (x^{n + 1})$$ | $$E^x \ln^n E$$                          |
> | $$e^x$$              | $$(-\infty, +\infty)$$ | $$1 + \sum\limits_1^{+ \infty} \dfrac{1}{n !} x^n + O (x^{n + 1})$$ | $$e^x$$                                  |
> | $$\log_L (1 + x)$$   |    | $$0 + \sum\limits_1^{+ \infty} \dfrac{(- 1)^{n - 1}}{n \ln L} x^n + O (x^{n + 1})$$ | $$\dfrac{(- 1)^{n - 1} (n - 1) !}{(1 + x)^n \ln L}$$ |
> | $$\ln (1 + x)$$      | $$(-1, +1]$$ | $$0 + \sum\limits_1^{+ \infty} \dfrac{(- 1)^{n - 1}}{n} x^n + O (x^{n + 1})$$ | $$\dfrac{(- 1)^{n - 1} (n - 1) !}{(1 + x)^n}$$ |
> | $\sin x$             | $$(-\infty, +\infty)$$ | $$0 + \sum\limits_1^{+ \infty} \dfrac{(- 1)^n}{(2 n + 1) !} x^{2 n + 1} + O (x^{2 n + 3})$$ | $$\sin \left( x + n \dfrac{\pi}{2} \right)$$ |
> | $$\cos x$$           | $$(-\infty, +\infty)$$ | $$1 + \sum\limits_1^{+ \infty} \dfrac{(- 1)^n}{(2 n) !} x^{2 n} + O (x^{2 n + 2})$$ | $$\cos \left( x + n \dfrac{\pi}{2} \right)$$ |
> | $$\arcsin x$$        | $$[-1, -1]$$ | $$0 + \sum\limits_1^{+ \infty} \dfrac{(2 n) !}{4^n (n !)^2 (2 n + 1)} x^{2 n + 1} + O (x^{2 n + 3})$$ |                                          |
> | $$\arctan x$$        | $$[-1, +1]$$ | $$0 + \sum\limits_1^{+ \infty} \dfrac{(- 1)^n}{2 n + 1} x^{2 n + 1} + O (x^{2 n + 3})$$ |                                          |
> | $$\sinh x$$          | $$(-\infty, +\infty)$$ | $$0 + \sum\limits_1^{+ \infty} \dfrac{1}{(2 n + 1) !} x^{2 n + 1} + O (x^{2 n + 3})$$ | $$\dfrac{e^x + (-1)^{n - 1} e^{- x}}{2}$$ |
> | $$\cosh x$$          | $$(-\infty, +\infty)$$ | $$1 + \sum\limits_1^{+ \infty} \dfrac{1}{(2 n) !} x^{2 n} + O (x^{2 n + 2})$$ | $$\dfrac{e^x + (- 1)^n e^{- x}}{2}$$     |
> 

> ### 等幂级数

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \sum_1^n n^1 &= \dfrac{1}{2} n^2 + \dfrac{1}{2} n \\
> \fbox{2}\; && \sum_1^n n^2 &= \dfrac{1}{3} n^3 + \dfrac{1}{2} n^2 + \dfrac{1}{6} n \\
> \fbox{3}\; && \sum_1^n n^3 &= \dfrac{1}{4} n^4 + \dfrac{1}{2} n^3 + \dfrac{1}{4} n^2 \\
> \end{alignedat}
> $$
>

> ### 三角级数

> $$
> \begin{alignedat}{3}
> \fbox{1}\; \sum_m^n \cos n x &= \dfrac{1}{2\sin \dfrac{x}{2}} \cdot \sum_m^n 2 \sin \dfrac{x}{2} \cdot \cos n x \\
>                              &= \dfrac{1}{2 \sin \dfrac{x}{2}} \cdot \sum_m^n \left[ \sin \left( n + \dfrac{1}{2} \right) x - \sin \left( n - \dfrac{1}{2} \right) x \right] \\
>                              &= \dfrac{1}{2 \sin \dfrac{x}{2}} \cdot \left[ \sin \left( n + \dfrac{1}{2} \right) x - \sin \left( m - \dfrac{1}{2} \right) x \right] \\
> \fbox{2}\; \sum_m^n \sin n x &= \dfrac{1}{2 \sin \dfrac{x}{2}} \cdot \sum_m^n 2 \sin \dfrac{x}{2} \cdot \sin n x \\
>                              &= \dfrac{1}{\sin \dfrac{x}{2}} \cdot \sum_m^n \left[ \cos \left( n - \dfrac{1}{2} \right) x - \cos \left( n + \dfrac{1}{2} \right) x \right] \\
>                              &= \dfrac{1}{2 \sin \dfrac{x}{2}} \cdot \left[ \cos \left( m - \dfrac{1}{2} \right) x - \cos \left( n + \dfrac{1}{2} \right) x \right] \\
> \end{alignedat}
> $$
>

> ### 等比级数

> $$
> \begin{alignedat}{3}
> \Uparrow\;           &&  1 + \sum^{+\infty}_1 q^n &= \lim_{+\infty} \dfrac{1 - q^{n + 1}}{1 - q} \\
> \fbox{1}\Downarrow\; &&               q < -1 \quad&\Rightarrow\quad 1 + \sum^{+\infty}_1 q^n \to \infty \\
> \fbox{2}\Downarrow\; &&               q = -1 \quad&\Rightarrow\quad 1 + \sum^{+\infty}_1 q^n \not\to \mathcal{Conv.} \\
> \fbox{3}\Downarrow\; && \lvert q \rvert < +1 \quad&\Rightarrow\quad 1 + \sum^{+\infty}_1 q^n = \dfrac{1}{1 - q} \\
> \fbox{4}\Downarrow\; &&               q = +1 \quad&\Rightarrow\quad 1 + \sum^{+\infty}_1 q^n \to +\infty \\
> \fbox{5}\Downarrow\; &&               q > +1 \quad&\Rightarrow\quad 1 + \sum^{+\infty}_1 q^n \to +\infty \\
> \end{alignedat}
> $$
>

> ### 对数级数

> $$
> \begin{alignedat}{3}
>                    &&        \sum_2^{+\infty} \dfrac{1}{n^\alpha \cdot \ln^\beta n \cdot \ln^\gamma \ln n \cdots} \\
> \fbox{1}\Uparrow\; &&                                                     1 \gt \alpha = 1 - 2 \varepsilon &\quad\Rightarrow\quad  \lim_{+\infty} \dfrac{x^{1 - \varepsilon}}{x^\alpha \cdot \ln^\beta x} \to +\infty \\
> \Downarrow\;       && \sum_2^{+\infty} \dfrac{1}{n^{\alpha < 1} \cdot \ln^\beta n} \not\to \mathcal{Conv.} &\quad\Leftarrow\quad \int_2^{+\infty} \dfrac{1}{x^{1 - \varepsilon}} \mathrm{d} x \not\to \mathcal{Conv.} \\
> \fbox{2}\Uparrow\; &&                                                     1 \lt \alpha = 1 + 2 \varepsilon &\quad\Rightarrow\quad \lim_{+\infty} \dfrac{x^{1 + \varepsilon}}{x^\alpha \cdot \ln^\beta x} \to 0 \\
> \Downarrow\;       &&     \sum_2^{+\infty} \dfrac{1}{n^{\alpha > 1} \cdot \ln^\beta n} \to \mathcal{Conv.} &\quad\Leftarrow\quad \int_2^{+\infty} \dfrac{1}{x^{1 + \varepsilon}} \mathrm{d} x \to \mathcal{Conv.} \\
> \fbox{2}\Uparrow\; &&                                                              1 = \alpha; 1 \gt \beta \\
> \Downarrow\;       &&      \sum_2^{+\infty} \dfrac{1}{n \cdot \ln^{\beta \lt 1} n} \not\to \mathcal{Conv.} &\quad\Leftarrow\quad \int_{\ln 2}^{+\infty} \dfrac{1}{t^\beta \cdot \ln^\gamma t} \mathrm{d} \langle t = \ln x \rangle \not\to \mathcal{Conv.} \\
> \fbox{4}\Uparrow\; &&                                                                1 = \alpha; 1 < \beta \\
> \Downarrow\;       &&          \sum_2^{+\infty} \dfrac{1}{n \cdot \ln^{\beta \gt 1} n} \to \mathcal{Conv.} &\quad\Leftarrow\quad \int_{\ln 2}^{+\infty} \dfrac{1}{t^\beta \cdot \ln^\gamma t} \mathrm{d} \langle t = \ln x \rangle \to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 超几何级数

> $$
> \begin{alignedat}{3}
>                    && 1 + \sum_1^{+\infty} \dfrac{\alpha \cdots (\alpha + n - 1) \cdot \beta \cdots (\beta +n - 1)}{\gamma \cdots (\gamma + n - 1)} \dfrac{x^n}{n !} & \\
> \Uparrow\;         &&                                                   \dfrac{s_{n + 1}}{s_n} = \dfrac{(n + \alpha) (n + \beta)}{(n + \gamma) (n + 1)} \cdot x \quad&\Rightarrow\quad \lim_{+\infty} \dfrac{s_{n + 1}}{s_n} = x \\
> \fbox{1}\Uparrow\; &&                                                                                                                             0 \le x \lt 1 \quad&\Leftarrow\quad \lim_{+\infty} \dfrac{s_{n + 1}}{s_n} < 1 \\
> \Downarrow\;       && 1 + \sum_1^{+\infty} \dfrac{\alpha \cdots (\alpha + n - 1) \cdot \beta \cdots (\beta +n - 1)}{\gamma \cdots (\gamma + n - 1)} \dfrac{x^n}{n !} &\to \mathcal{Conv.} \\
> \fbox{2}\Uparrow\; &&                                                                                                                                     x > 1 \quad&\Leftarrow\quad \lim_{+\infty} \dfrac{s_{n + 1}}{s_n} > 1 \\
> \Downarrow\;       && 1 + \sum_1^{+\infty} \dfrac{\alpha \cdots (\alpha + n - 1) \cdot \beta \cdots (\beta +n - 1)}{\gamma \cdots (\gamma + n - 1)} \dfrac{x^n}{n !} &\not\to \mathcal{Conv.} \\
> \Uparrow\;         &&                                            \lim_{+\infty} n \cdot \left( \dfrac{s_n}{s_{n + 1}} - 1 \right) = \gamma + 1 - \alpha - \beta \quad&\Leftarrow\quad n \cdot \left( \dfrac{s_n}{s_{n + 1}} - 1 \right) = \dfrac{(\gamma + 1 - \alpha - \beta) n^2 + (\gamma - \alpha \beta) n}{n^2 + (\alpha + \beta) n + \alpha \beta} \\
> \fbox{3}\Uparrow\; &&                                                                                                            x = 1, \gamma > \alpha + \beta \quad&\Leftarrow\quad \gamma + 1 - \alpha - \beta > 1 \\
> \Downarrow\;       && 1 + \sum_1^{+\infty} \dfrac{\alpha \cdots (\alpha + n - 1) \cdot \beta \cdots (\beta +n - 1)}{\gamma \cdots (\gamma + n - 1)} \dfrac{x^n}{n !} &\to \mathcal{Conv.} \\
> \fbox{4}\Uparrow\; &&                                                                                                            x = 1, \gamma < \alpha + \beta \quad&\Leftarrow\quad \gamma + 1 - \alpha - \beta < 1 \\
> \Downarrow\;       && 1 + \sum_1^{+\infty} \dfrac{\alpha \cdots (\alpha + n - 1) \cdot \beta \cdots (\beta +n - 1)}{\gamma \cdots (\gamma + n - 1)} \dfrac{x^n}{n !} &\not\to \mathcal{Conv.} \\
> \Uparrow\;         &&                                                                                              n \cdot \left( \dfrac{s_n}{s_{n + 1}} - 1 \right) &= \dfrac{n^2}{n^2 + \langle \gamma = \alpha + \beta \rangle n + \alpha \beta} < 1 \\
> \fbox{5}\Uparrow\; &&                                                                                                            x = 1, \gamma = \alpha + \beta \quad&\Leftarrow\quad \gamma + 1 - \alpha - \beta = 1 \\
> \Downarrow\;       && 1 + \sum_1^{+\infty} \dfrac{\alpha \cdots (\alpha + n - 1) \cdot \beta \cdots (\beta +n - 1)}{\gamma \cdots (\gamma + n - 1)} \dfrac{x^n}{n !} &\not\to \mathcal{Conv.} \\
> \end{alignedat}
> $$
>

> ### 调和级数

> $$
> \begin{alignedat}{3}
> \Uparrow\;           &&                            f^\downarrow (x - 1) &\ge f^\downarrow (\lfloor x \rfloor) \ge \left\lvert \alpha - \left[ \sum_m^{\lfloor x \rfloor} f^\downarrow (x) - \int_m^x f^\downarrow (x) \mathrm{d} x \right] \right\rvert \quad\Leftarrow\quad \lim_{+\infty} f^\downarrow (x) \to 0 \\
> \Uparrow\;           &&                                           f (x) &= \dfrac{1}{x^{\langle h \ne 1 \rangle}}; \int_m^n f (x) \mathrm{d} x = \dfrac{n^{1- h} - m^{1 - h}}{1 - h}; f (x - 1) = O \left( \dfrac{1}{x^h} \right); \\
> \fbox{1}\Downarrow\; && \sum_m^n \dfrac{1}{n^{\langle h \ne 1 \rangle}} &= \dfrac{n^{1- h} - m^{1 - h}}{1 - h} + \mathcal{Const.} + O \left( \dfrac{1}{n^h} \right) \\
> \Uparrow\;           &&                                           f (x) &= \dfrac{1}{x}; \int_m^n f (x) \mathrm{d} x = \ln \dfrac{n}{m}; f (x - 1) = O \left( \dfrac{1}{x} \right); \\
> \fbox{2}\Downarrow\; &&                           \sum_m^n \dfrac{1}{n} &= \ln \dfrac{n}{m} + \mathcal{Const.} + O \left( \dfrac{1}{n} \right) \\
> \end{alignedat}
> $$
>

