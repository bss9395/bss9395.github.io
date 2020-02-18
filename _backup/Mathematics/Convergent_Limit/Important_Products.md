---
layout:    zh_post
Topic:     收敛极限
Title:     重要乘积
Revised:   2018-04-17 20:39:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 组合乘积

> $$
> \begin{alignedat}{3}
> \Uparrow\;         &&         \mathcal{C}_\alpha^n &= \dfrac{\alpha (\alpha - 1) \cdots (\alpha - n + 1)}{n !} \\
> \Downarrow\;       &&  (-1)^n \mathcal{C}_\alpha^n &= \left( 1 - \dfrac{\alpha + 1}{1} \right) \left( 1 - \dfrac{\alpha +1}{2} \right) \cdots \left( 1 - \dfrac{\alpha + 1}{n} \right) \\
>                    &&                              &= \prod_1^n \left( 1 - \dfrac{\alpha + 1}{n} \right) \\
> \fbox{1}\Uparrow\; &&             \alpha > -1 \quad&\Rightarrow\quad \sum_1^{+\infty} \dfrac{\alpha + 1}{n} \to +\infty \\
> \Downarrow\;       && \mathcal{C}_\alpha^{+\infty} &= \lim_{+\infty} (-1)^n \prod_1^n \left( 1 - \dfrac{\alpha + 1}{n} \right) \to 0 \\
> \fbox{2}\Uparrow\; &&             \alpha < -1 \quad&\Rightarrow\quad \sum_1^{+\infty} \dfrac{\alpha + 1}{n} \to -\infty \\
> \Downarrow\;       && \mathcal{C}_\alpha^{+\infty} &= \lim_{+\infty} (-1)^n \prod_1^n \left( 1 - \dfrac{\alpha + 1}{n} \right) \to \infty \\
> \fbox{3}\Uparrow\; &&             \alpha = -1 \quad&\Rightarrow\quad \sum_1^{+\infty} \dfrac{\alpha + 1}{n} = 0 \\
> \Downarrow\;       && \mathcal{C}_\alpha^{+\infty} &= (-1)^n \\
> \end{alignedat}
> $$
>

> ### 圆周乘积

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\;   & \int_0^\frac{\pi}{2} \sin^{2 n + 1} x \mathrm{d} x < \int_0^\frac{\pi}{2} \sin^{2 n} x \mathrm{d} x < \int_0^\frac{\pi}{2} \sin^{2 n - 1} x \mathrm{d} x \\
> \Downarrow\; & \dfrac{(2 n) !!}{(2 n + 2) !!} < \dfrac{(2 n -1) !!}{(2 n) !!} \cdot  \dfrac{\pi}{2} < \dfrac{(2 n - 1) !!}{(2 n - 1) !!} \\
> \Downarrow\; & \dfrac{1}{2 n + 1} \left[ \dfrac{(2 n) !!}{(2 n - 1) !!} \right]^2 < \dfrac{\pi}{2} < \dfrac{1}{2 n} \left[ \dfrac{(2 n) !!}{(2 n - 1) !!} \right]^2 \\
> \Downarrow\; & \dfrac{2 n}{2 n + 1} \cdot \dfrac{\pi}{2} < \dfrac{1}{2 n + 1} \left[ \dfrac{(2 n) !!}{(2 n - 1) !!} \right]^2 < \dfrac{\pi}{2} \\
> \Downarrow\; & \dfrac{\pi}{2} = \lim_{+\infty} \dfrac{1}{2 n + 1} \left[ \dfrac{(2 n) !!}{(2 n - 1) !!} \right]^2 = \lim_{+\infty} \dfrac{1}{2 n + 1} \prod_1^n \left[ \dfrac{2 n}{2 n - 1} \right]^2 = \prod_1^{+\infty} \left( \dfrac{2 n}{2 n - 1} \cdot \dfrac{2 n}{2 n + 1} \right) \\
> \fbox{2}\Uparrow\; &  \sin x = x \cdot \prod_1^{+\infty} \left[ 1 - \dfrac{x^2}{(n \pi)^2} \right] \\
> \Downarrow\; & \sin \dfrac{\pi}{2} = \dfrac{\pi}{2} \cdot \prod_1^{+\infty} \left( 1 - \dfrac{1}{4 n^2} \right) \quad\Leftarrow\quad x = \dfrac{\pi}{2} \\
> \Downarrow\; & \dfrac{\pi}{2} = \prod_1^{+\infty} \left( \dfrac{2 n}{2 n - 1} \cdot \dfrac{2 n}{2 n + 1} \right)
> \end{alignedat}
> $$
>

> ### 三角乘积

> $$
> \begin{alignedat}{3}
> \Uparrow\;           && \cos m z + \imath \sin m z &= (cos z + \imath \sin z)^m \\
>                      &&                            &= \mathcal{C}_m^0 \cos^m z \sin^0 z + \mathcal{C}_m^2 \cos^{m - 2} z \sin^2 z + \cdots \\
>                      &&                            &+ \imath \cdot \left[ \mathcal{C}_m^1 \cos^{m - 1} z \sin^1 z + \mathcal{C}_m^3 \cos^{m - 3} z \sin^3 z \right] + \cdots \\
> \fbox{1}\Downarrow\; &&           \sin (2 n + 1) z &= \sin z \cdot P_{\sin} (n, \sin^2 z)                                                                                                         &&\;\Leftarrow\; m = 2 n + 1; \sin^2 z = 1 - \cos^2 z \\
>                      &&                            &= \sin z \cdot P_{\sin}^0 \cdot \prod_{l = 1}^n \left( 1 - \dfrac{\sin^2 z}{\sin^2 z_l} \right)                                               &&\;\Rightarrow\; P_{\sin}^0 = \lim_{z \to 0} \dfrac{\sin (2 n + 1) z}{\sin z} = 2 n + 1 \\
>                      &&                            &= (2 n + 1) \sin z \cdot \prod_{l = 1}^n \left( 1 - \dfrac{\sin^2 z}{\sin^2 \dfrac{l \pi}{2 n + 1}} \right)                                   &&\;\Leftarrow\; \sin \left[ (2 n + 1) \cdot \left\langle z_l = \dfrac{l \pi}{2 n + 1} \right\rangle \right] = 0 \\
> \Downarrow\;         &&                     \sin x &= (2 n + 1) \sin \dfrac{x}{2 n + 1} \cdot \prod_{l = 1}^n \left( 1 - \dfrac{\sin^2 \dfrac{x}{2 n + 1}}{\sin^2 \dfrac{l \pi}{2 n + 1}} \right) &&\;\Leftarrow\; z = \dfrac{x}{2 n + 1} \\
> \Downarrow\;         &&                     \sin x &= x \cdot \prod_1^{+\infty} \left[ 1 - \dfrac{x^2}{(n \pi)^2} \right]                                                                         &&\;\Leftarrow\; n \to +\infty \\
> \fbox{2}\Downarrow\; &&               \cos (2 n) z &= P_{\cos} (n, \sin^2 z)                                                                                                                      &&\;\Leftarrow\; m = 2 n; \sin^2 = 1 - \cos^2 z \\
>                      &&                            &= P_{\cos}^0 \cdot \prod_{l = 1}^n \left( 1 - \dfrac{\sin^2 z}{\sin^2 z_l} \right)                                                            &&\;\Rightarrow\; P_{\cos}^0 = \lim_{z \to 0} \cos (2 n) z = 1 \\
>                      &&                            &= \prod_{l = 1}^n \left( 1 - \dfrac{\sin^2 z}{\sin^2 \dfrac{- \frac{1}{2} \pi + l \pi}{2 n}} \right)                                          &&\;\Leftarrow\; \cos \left[ (2 n) \cdot \left\langle z_l = \dfrac{- \frac{1}{2} \pi + l \pi}{2 n} \right\rangle \right] = 0 \\
> \Downarrow\;         &&                     \cos x &= \prod_{l = 1}^n \left( 1 - \dfrac{\sin^2 \dfrac{x}{2 n}}{\sin^2 \dfrac{- \frac{1}{2} \pi + l \pi}{2 n}} \right)                             &&\;\Leftarrow\; z = \dfrac{x}{2 n} \\
> \Downarrow\;         &&                     \cos x &= \prod_1^n \left[ 1 - \dfrac{x^2}{\left( \dfrac{2 n - 1}{2} \pi \right)^2} \right]                                                           &&\;\Leftarrow\; n \to +\infty \\
> \fbox{3}\Downarrow\; &&                    \sinh x &= x \cdot \prod_1^{+\infty} \left[ 1 + \dfrac{x^2}{(n \pi)^2} \right]                                                                         &&\;\Leftarrow\; \sinh x = - \imath \sin (\imath x) \\
> \fbox{4}\Downarrow\; &&                    \cosh x &= \prod_1^{+\infty} \left[ 1 + \dfrac{x^2}{\left( \dfrac{2 n - 1}{2} \pi \right)^2} \right]                                                   &&\;\Leftarrow\; \cosh x = \cos (\imath x) \\
> \end{alignedat}
> $$
>
