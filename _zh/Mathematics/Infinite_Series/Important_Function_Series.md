---
layout:    zh_post
Topic:     无穷级数
Title:     重要函数级数
Revised:   2018-03-30 01:27:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 积分和级数

> $$
> \begin{alignedat}{3}
>         \Uparrow\;   &&                                                                g (m, x) &= \sum_m^{\lfloor x \rfloor} f^\downarrow (n) - \int_m^x f^\downarrow (x) \mathrm{d} x \quad&&\Leftarrow\quad m \le x; 0 \le f^\downarrow (x) \\
>                      &&                                                              \fbox{1}\; &= \sum_m^{\lfloor x \rfloor} f (n) - \int_m^{\lfloor x \rfloor} f (x) \mathrm{d} x - \int_{\lfloor x \rfloor}^x f (x) \mathrm{d} x \quad&&\Rightarrow\quad g (m, x) = g (m, \lfloor x \rfloor) - \int_{\lfloor x \rfloor}^x f (x) \mathrm{d} x \\
>                      &&                                                              \fbox{2}\; &= \sum_m^{\lfloor x \rfloor} \int_n^{n + 1} [f (n) - f(x)] \mathrm{d} x + \int_x^{\lfloor x \rfloor + 1} f (x) \mathrm{d} x \quad&&\Rightarrow\quad g (m, x) \ge 0 \\
>                      &&                                                              \fbox{3}\; &= f (m) +  \sum_{m + 1}^{\lfloor x \rfloor} \int_{n - 1}^{n} [f (n) - f (x)] \mathrm{d} x - \int_{\lfloor x \rfloor}^x f (x) \mathrm{d} x \quad&&\Rightarrow\quad g (m, x) \le f (m) \\
>         \Downarrow\; &&                                                                g (m, m) &= f (m) \\
>         \Downarrow\; &&                                                      g(m, x) - g (m, y) &= \left[ \sum_m^{\lfloor x \rfloor} f^\downarrow (n) - \int_m^x f^\downarrow (x) \mathrm{d} x \right] - \left[ \sum_m^{\lfloor y \rfloor} f^\downarrow (n) - \int_m^{\lfloor y \rfloor} f^\downarrow (x) \mathrm{d} x - \int_{\lfloor y \rfloor}^y f^\downarrow \mathrm{d} x \right] \quad&&\Leftarrow\quad m \le y \le x \\
>                      &&                                                                         &= - f (\lfloor y \rfloor) + \left[ \sum_{\lfloor y \rfloor}^{\lfloor x \rfloor} f (n) - \int_{\lfloor y \rfloor}^x f (x) \mathrm{d} x \right] + \int_{\lfloor y \rfloor}^y f (x) \mathrm{d} x \\
>                      &&                                                              \fbox{1}\; &= g (\lfloor y \rfloor, x) - f (\lfloor y \rfloor) + \int_{\lfloor y \rfloor}^y f (x) \mathrm{d} x \\
>                      &&                                                                         &= \left[ \sum_{\lfloor y \rfloor + 1}^{\lfloor x \rfloor} f (n) - \int_{\lfloor y \rfloor + 1}^x f (x) \mathrm{d} x \right] - \int_{\lfloor y \rfloor}^{\lfloor y \rfloor + 1} f (x) \mathrm{d} x + \int_{\lfloor y \rfloor}^y f (x) \mathrm{d} x \\
>                      &&                                                              \fbox{2}\; &= g (\lfloor y \rfloor + 1, x) - \int_y^{\lfloor y \rfloor + 1} f (x) \mathrm{d} x \\
>         \Downarrow\; &&                                                 g (m, n + 1) - g (m, n) &= g (n + 1, n + 1) - \int_n^{n  + 1} f (x) \mathrm{d} x \\
>                      &&                                                                         &\le f (n + 1) - f (n + 1) = 0 \\
>         \Downarrow\; && - f (\lfloor y \rfloor) + \int_{\lfloor y \rfloor}^y f (x) \mathrm{d} x &\le g (m, x) - g (m, y) \le \int_{\lfloor y \rfloor}^y f (x) \mathrm{d} x \quad&&\Leftarrow\quad 0 \le g (m, x) \le f (m) \\
> \fbox{1}\Downarrow\; &&                                       \lvert g (m, x) - g (m, y) \rvert &\le f^\downarrow (\lfloor y \rfloor) \le f^\downarrow (y - 1) \\
> \fbox{2}\Downarrow\; &&                              \lim_{+\infty} f^\downarrow (x) \to 0 \quad&\Rightarrow\quad \alpha \gets \lim_{+\infty} \left[ \sum_m^{\lfloor x \rfloor} f^\downarrow (x) - \int_m^x f^\downarrow (x) \mathrm{d} x \right] \\
> \fbox{3}\Downarrow\; &&               f^\downarrow (x - 1) \ge f^\downarrow (\lfloor x \rfloor) &\ge \left\lvert \alpha - \left[ \sum_m^{\lfloor x \rfloor} f^\downarrow (x) - \int_m^x f^\downarrow (x) \mathrm{d} x \right] \right\rvert \quad\Leftarrow\quad \lim_{+\infty} f^\downarrow (x) \to 0 \\
> \end{alignedat}
> $$
>

