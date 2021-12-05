---
layout:  zh_post
Topic :  收敛极限
Title :  复变分析
Update:  2021-09-26T16:12:00+08@中国-广东-深圳+08
Author:  璀璨星辰
Link  :
---

### 复数的表示

虚数。

$τ ≡ \sqrt{-1}, τ^2 = -1$

$τ^{4 · n + 0} = +1, τ^{4 · n + 1} = +τ, τ^{4 · n + 2} = -1, τ^{4 · n + 3} = -τ$

直角坐标表示法。

$z = x + τ · y$

$\mathrm{Re\ } z = x, \mathrm{Im\ } z = y$

$[z_1 = z_2] ⇔ [\mathrm{Re\ } z_1 = \mathrm{Re\ } z_2 ∧ \mathrm{Im\ } z_1 = \mathrm{Im\ } z_2]$

极坐标表示法。

$z = r · ә^{+ τ · \phi} = r · \cos \phi + τ · r · \sin \phi$

$\arg z = \phi + 2 · m · π$

$[z_1 = z_2] ⇔ [r_1 = r_2 ∧ \phi_1 = \phi_2 + 2 · m · π]$

辐角表示法。

$z = |z| · ә^{τ · \arg z}$

共轭复数。

$\overline{z} = x - τ · y$

$\overline{z} = r · ә^{- τ · \phi} = r · \cos \phi - τ · r · \sin \phi$

$x = \dfrac{z + \overline{z}}{2}, y = \dfrac{z - \overline{z}}{2 · τ}$

### 复数的运算

复数的模。

$|z| = |x + τ · y| = \sqrt{x^2 + y^2}$

$|\overline{z}| = |x - τ · y| = \sqrt{x^2 + y^2}$

$|z| = |\overline{z}|$

复数的辐角。

$\arg z = +{'}\tan \dfrac{y}{x}$

$\arg \overline{z} = -{'}\tan \dfrac{y}{x}$

$\arg z = -\arg \overline{z}$

复数的加法

$z_1 + z_2 = (x_1 + τ · y_1) + (x_2 + τ · y_2) = (x_1 + x_2) + τ · (y_1 + y_2)$

$z_1 + z_2 = r_1 · ә^{τ · \phi_1} + r_2 · ә^{τ · \phi_2}$

复数的减法

$z_1 - z_2 = (x_1 + τ · y_1) - (x_2 + τ · y_2) = (x_1 - x_2) + τ · (y_1 - y_2)$

$z_1 - z_2 = r_1 · ә^{τ · \phi_1} - r_2 · ә^{τ · \phi_2}$

复数的乘法

$z_1 · z_2 = (x_1 + τ · y_1) · (x_2 + τ · y_2) = (x_1 · x_2 - y_1 · y_2) + τ · (x_1 · y_2 + x_2 · y_1)$

$z_1 · z_2 = (r_1 · ә^{τ · \phi_1}) · (r_2 · ә^{τ · \phi_2}) = (r_1 · r_2) · ә^{τ · (\phi_1 + \phi_2)}$

复数的除法

$\dfrac{z_1}{z_2} = \dfrac{x_1 + τ · y_1}{x_2 + τ · y_2} = \dfrac{(x_1 + τ · y_1) · (x_2 - τ · y_2)}{(x_2 + τ · y_2) · (x_2 - τ · y_2)} = \dfrac{x_1 · x_2 + y_1 · y_2}{x_2^2 + y_2^2} + τ · \dfrac{x_2 · y_1 - x_1 · y_2}{x_2^2 + y_2^2}$

$\dfrac{z_1}{z_2} = \dfrac{r_1 · ә^{τ · \phi_1}}{r_2 · ә^{τ · \phi_2}} = \dfrac{r_1}{r_2} · ә^{τ · (\phi_1 - \phi_2)}$

复数的乘方

$|z|^2 = |r · ә^{τ · \phi}|^2 = r^2 = |r^2 · ә^{τ · 2 · \phi}| = |z^2|$

$z^n = (r · ә^{τ · \phi})^n = r^n · (\cos \phi + τ · \sin \phi)^n = r^n · [\cos (n · \phi) + τ · \sin (n · \phi)] = r^n · ә^{τ · n · \phi}$

$(x + τ · y)^2 = (x^2 - y^2) + τ · (2 · x · y)$

$(x + τ · y)^3 = (x^3 - 3 · x · y^2) + τ · (3 · x^2 · y - y^3)$

复数的开方

$z^{\frac{1}{n}} = [r · ә^{τ · (\phi + 2 · m · π)}]^{\frac{1}{n}} = r^{\frac{1}{n}} · ә^{τ · \frac{\phi + 2 · m · π}{n}}$

$[(x + τ · y)^2 = a + τ · b] ⇒ 
\left\lbrace\begin{aligned}
x^2 - y^2 &= a \\
2 · x · y &= b \\
\end{aligned}\right. ⇒ 
\left\lbrace\begin{aligned}
x_1 &= +\sqrt{\dfrac{\sqrt{a^2 + b^2} + a}{2}} \\
y_1 &= +b · \sqrt{\dfrac{\sqrt{a^2 + b^2} - a}{2 · b^2}} \\
\end{aligned}\right. 
\left\lbrace\begin{aligned}
x_2 &= -\sqrt{\dfrac{\sqrt{a^2 + b^2} + a}{2}} \\
y_2 &= -b · \sqrt{\dfrac{\sqrt{a^2 + b^2} - a}{2 · b^2}} \\
\end{aligned}\right.$

### 共轭复数的运算

$z + \overline{z} = (x + τ · y) + (x - τ · y) = 2 · x = 2 · \mathrm{Re\ } z$

$z - \overline{z} = (x + τ · y) - (x - τ · y) = τ · 2 · y = τ · 2 · \mathrm{Im\ } z$

$z · \overline{z} = (x + τ · y) · (x - τ · y) = x^2 + y^2 = |z|^2 = |z^2|$

$\dfrac{1}{\overline{z}} = \dfrac{z}{z · \overline{z}} = \dfrac{z}{|z|^2}$

$\dfrac{1}{z} = \dfrac{\overline{z}}{z · \overline{z}} = \dfrac{\overline{z}}{|z|^2}$

$\overline{z_1} + \overline{z_2} = (x_1 - τ · y_1) + (x_2 - τ · y_2) = (x_1 + x_2) - τ · (y_1 + y_2) = \overline{z_1 + z_2}$

$\overline{z_1} - \overline{z_2} = (x_1 - τ · y_1) - (x_2 - τ · y_2) = (x_1 - x_2) - τ · (y_1 - y_2) = \overline{z_1 - z_2}$

$\overline{z_1} · \overline{z_2} = (x_1 - τ · y_1) · (x_2 - τ · y_2) = (x_1 · x_2 - y_1 · y_2) - τ · (x_1 · y_2 + x_2 · y_1) = \overline{z_1 · z_2}$

$\dfrac{\overline{z_1}}{\overline{z_2}} = \dfrac{x_1 - τ · y_1}{x_2 - τ · y_2} = \dfrac{(x_1 - τ · y_1) · (x_2 + τ · y_2)}{(x_2 - τ · y_2) · (x_2 + τ · y_2)} = \dfrac{x_1 · x_2 + y_1 · y_2}{x_2^2 + y_2^2} - τ · \dfrac{x_2 · y_1 - x_1 · y_2}{x_2^2 + y_2^2} = \overline{\left(\dfrac{z_1}{z_2}\right)}$

$\overline{z}^n = (r· ә^{- τ · \phi})^n = r^n · ә^{- τ · n · \phi} = \overline{z^n}$

### 复数的运算性质

复数不满足线性序性质，复数不能直接比较大小。

加法有零元: $0 = 0 + τ · 0$

加法有负元: $-z = -(x + τ · y) = -x - τ · y$

加法结合律: $(z_1 + z_2) + z_3 = z_1 + (z_2 + z_3)$

加法交换律: $z_1 + z_2 = z_2 + z_1$

乘法有幺元: $1 = 1 + τ · 0$

乘法有逆元: $z^{-1} = (x + τ · y)^{-1} = \dfrac{x}{x^2 + y^2} - τ · \dfrac{y}{x^2 + y^2}$

乘法结合律: $(z_1 · z_2) · z_3 = z_1 · (z_2 · z_3)$

乘法交换律: $z_1 · z_2 = z_2 · z_1$

乘法分配律: $z_1 · (z_2 + z_3) = z_1 · z_2 + z_1 · z_3$

指数加运算: $z_1^{z_2 + z_3} = z_1^{z_2} · z_1^{z_3}$

指数乘运算: $z_1^{z_2 · z_3} = (z_1^{z_2})^{z_3}$

拓扑距关系: $|z_1 + z_2| ≤ |z_1| + |z_2|$

拓扑距关系: $|z_1 - z_2| ≥ ||z_1| - |z_2||$