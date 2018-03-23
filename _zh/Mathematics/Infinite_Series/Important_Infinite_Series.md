---
layout:    zh_post
Topic:     无穷级数
Title:     重要无穷级数
Revised:   2018-03-23 21:03:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 初等函数级数

> | **f (x)** | **$$\sum\limits^{+\infty}  \dfrac{f^{(n)} (x)}{n !} x^n$$** | **$$f^{(n)} (x)$$** |
> | :------------------- | :--------------------------------------- | :--------------------------------------- |
> | $(1 + x)^P$          | $$1 + \sum\limits_1^{+ \infty} \dfrac{P (P - 1) \cdots (P - n + 1)}{n !} x^n + O (x^{n + 1})$$ | $$P (P - 1) \cdots (P - n + 1) (1 + x)^{P - n}$$ |
> | $$\dfrac{1}{1 + x}$$ | $$1 + \sum\limits_1^{+ \infty} (- 1)^n x^n + O (x^{n + 1})$$ | $$(- 1)^n n ! (1 + x)^{- n - 1}$$        |
> | $$E^x$$              | $$1 + \sum\limits_1^{+ \infty} \dfrac{\ln^n E}{n !} x^n + O (x^{n + 1})$$ | $$E^x \ln^n E$$                          |
> | $$e^x$$              | $$1 + \sum\limits_1^{+ \infty} \dfrac{1}{n !} x^n + O (x^{n + 1})$$ | $$e^x$$                                  |
> | $$\log_L (1 + x)$$   | $$0 + \sum\limits_1^{+ \infty} \dfrac{(- 1)^{n - 1}}{n \ln L} x^n + O (x^{n + 1})$$ | $$\dfrac{(- 1)^{n - 1} (n - 1) !}{(1 + x)^n \ln L}$$ |
> | $$\ln (1 + x)$$      | $$0 + \sum\limits_1^{+ \infty} \dfrac{(- 1)^{n - 1}}{n} x^n + O (x^{n + 1})$$ | $$\dfrac{(- 1)^{n - 1} (n - 1) !}{(1 + x)^n}$$ |
> | $\sin x$             | $$0 + \sum\limits_1^{+ \infty} \dfrac{(- 1)^{n - 1}}{(2 n - 1) !} x^{2 n - 1} + O (x^{2 n + 1})$$ | $$\sin \left( x + n \dfrac{\pi}{2} \right)$$ |
> | $$\cos x$$           | $$1 + \sum\limits_1^{+ \infty} \dfrac{(- 1)^n}{(2 n) !} x^{2 n} + O (x^{2 n + 2})$$ | $$\cos \left( x + n \dfrac{\pi}{2} \right)$$ |
> | $$\arcsin x$$        | $$0 + \sum\limits_1^{+ \infty} \dfrac{[(2 n - 3) !!]^2}{(2 n - 1) !} x^{2 n - 1} + O (x^{2 n + 1})$$ |                                          |
> | $$\arctan x$$        | $$0 + \sum\limits_1^{+ \infty} \dfrac{(- 1)^{n - 1}}{2 n - 1} x^{2 n - 1} + O (x^{2 n + 1})$$ |                                          |
> | $$\sinh x$$          | $$0 + \sum\limits_1^{+ \infty} \dfrac{1}{(2 n - 1) !} x^{2 n - 1} + O (x^{2 n + 1})$$ | $$\dfrac{e^x + (-1)^{n - 1} e^{- x}}{2}$$ |
> | $$\cosh x$$          | $$1 + \sum\limits_1^{+ \infty} \dfrac{1}{(2 n) !} x^{2 n} + O (x^{2 n + 2})$$ | $$\dfrac{e^x + (- 1)^n e^{- x}}{2}$$     |

> ### 等比级数

> $$
> \begin{alignedat}{3}
> \Uparrow\; && 1 + \sum^{+\infty}_1 q^n &= \lim_{+\infty} \dfrac{1 - q^{n + 1}}{1 - q} \\
> \fbox{1}\Downarrow\; && q \lt -1 \;&\Rightarrow\; 1 + \sum^{+\infty}_1 q^n \to \infty \\
> \fbox{2}\Downarrow\; && q = -1 \;&\Rightarrow\; 1 + \sum^{+\infty}_1 q^n \not\to \mathcal{Conv.} \\
> \fbox{3}\Downarrow\; && \lvert q \rvert \lt +1 \;&\Rightarrow\; 1 + \sum^{+\infty}_1 q^n = \dfrac{1}{1 - q} \\
> \fbox{4}\Downarrow\; && q = +1 \;&\Rightarrow\; 1 + \sum^{+\infty}_1 q^n \to +\infty \\
> \fbox{5}\Downarrow\; && q \gt +1 \;&\Rightarrow\; 1 + \sum^{+\infty}_1 q^n \to +\infty \\
> \end{alignedat}
> $$
>

> ### 调和级数

> $$
> \begin{alignedat}{3}
> \Uparrow\;   &&                   & \ln \left( 1 + \dfrac{1}{n} \right)^n < \ln e < \ln \left( 1 + \dfrac{1}{n} \right)^{n + 1} \\
> \Downarrow\; &&                   & \dfrac{1}{n + 1} < \ln \left(1 + \dfrac{1}{n} \right) < \dfrac{1}{n} \\
> \Downarrow\; &&                   & \dfrac{1}{n} - \ln \left( 1 + \dfrac{1}{n} \right) < \dfrac{1}{n} - \dfrac{1}{n + 1} < \dfrac{1}{n^2} \\
> \Downarrow\; && \mathcal{Conv.} \;&\leftarrow\; \sum^{+\infty}_1 \left[ \dfrac{1}{n} - \ln \left( 1 + \dfrac{1}{n} \right) \right] \\
>              &&                   &= \sum^{+\infty}_1 \left[ \dfrac{1}{n} - \ln (n + 1) + \ln n \right] \\
>              &&                   &= \lim_{+\infty} \left[ \sum^n_1 \dfrac{1}{n} - \ln (n + 1) \right] \\
> \Downarrow\; &&                 1 &= \lim_{+\infty} \dfrac{\sum\limits^{n}_1 \dfrac{1}{n}}{\ln n} \\
> \Downarrow\; &&             \ln n &\mathop{\longleftrightarrow}_{+\infty} \sum^n_1 \dfrac{1}{n} \\
> \end{alignedat}
> $$
>

> ### 三角级数

> $$
> \begin{alignedat}{3}
> \fbox{1}\; \sum^n_1 \cos n x &= \dfrac{1}{2\sin \dfrac{x}{2}} \cdot \sum^n_1 2 \sin \dfrac{x}{2} \cdot \cos n x \\
>                              &= \dfrac{1}{2 \sin \dfrac{x}{2}} \cdot \sum^n_1 \left[ \sin \left( n + \dfrac{1}{2} \right) x - \sin \left( n - \dfrac{1}{2} \right) x \right] \\
>                              &= \dfrac{1}{2 \sin \dfrac{x}{2}} \cdot \left[ \sin \left( n + \dfrac{1}{2} \right) x - \sin \dfrac{x}{2} \right] \\
> \fbox{2}\; \sum^n_1 \sin n x &= \dfrac{1}{2 \sin \dfrac{x}{2}} \cdot \sum^n_1 2 \sin \dfrac{x}{2} \cdot \sin n x \\
>                              &= \dfrac{1}{\sin \dfrac{x}{2}} \cdot \sum^n_1 \left[ \cos \left( n - \dfrac{1}{2} \right) x - \cos \left( n + \dfrac{1}{2} \right) x \right] \\
>                              &= \dfrac{1}{2 \sin \dfrac{x}{2}} \cdot \left[ \cos \dfrac{x}{2} - \cos \left( n + \dfrac{1}{2} \right) x \right] \\
> \end{alignedat}
> $$
>
