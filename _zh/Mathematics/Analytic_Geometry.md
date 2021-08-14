---
layout:  zh_post
Topic :  收敛极限
Title :  解析几何学
Update:  2021-08-10T16:31:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 特别注意

```
本书中微分算符与教科书不同。
```

在本书中，全微分算符为$\Lambda$，偏微分算符为$\lambda$，一阶求导算符为$\dfrac{\Lambda}{\lambda} ≡ \dfrac{\Lambda^{1} }{\lambda^{1} }$，高阶求导算符为$\dfrac{\Lambda^{n} }{\lambda^{n} } ≡ \dfrac{\Lambda}{\lambda} \dfrac{\Lambda^{n-1} }{\lambda^{n-1} }$。

一阶微分同等定理。

$\Lambda f(x) = \lambda f(x)$

$\dfrac{\Lambda f^{⇵}(x)}{\lambda x} \mathop{====}\limits_{x={'}f^{⇵}(y)}^{y=f^{⇵}(x)} \left[ \dfrac{\Lambda {'}f^{⇵}(y)}{\lambda y} \right]^{-1}$

$\dfrac{\Lambda g(f(x))}{\lambda x} = \dfrac{\Lambda g(f(x))}{\lambda f(x)} · \dfrac{\Lambda f(x)}{\lambda x} \mathop{===}\limits^{y=f(x)} \dfrac{\Lambda g(y)}{\lambda y} · \dfrac{\Lambda f(x)}{\lambda x}$

二变元全微分定理。

$\dfrac{\Lambda^{2} f(x,y)}{\lambda^{1} x · \lambda^{1} y} = f_{y,x} = \dfrac{\Lambda^{2} f(x,y)}{\lambda^{1} y · \lambda^{1} x}$

$\Lambda^{1} f(x,y) = f_{x} · \lambda x + f_{y} · \lambda y$

$\Lambda^{2} f(x,y) = \Lambda [f_{x} · \lambda x + f_{y} · \lambda y] = f_{x,x} · \lambda^{2} x + f_{x,y} · \lambda^{1} x · \lambda^{1} y + f_{y,x} · \lambda^{1} y · \lambda^{1} x + f_{y,y} · \lambda^{2} y$

典例：函数$f(x) = x^{3}$。

|                                                              | $\int \Lambda f(x) = f(x)$                                   | $\Lambda^{0} f(x) ≡ f(x)$                                    | $\lambda^{0} x ≡ 1$                                          | $\lambda h(x) = \dfrac{\Lambda h(x)}{\lambda x} · \lambda x$ |                                                      |
| :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :--------------------------------------------------- |
| $\dfrac{\Lambda^{-2} f(x)}{\lambda^{-2} x} = \dfrac{x^{5} }{20}$ | $\dfrac{\Lambda^{-1} f(x)}{\lambda^{-1} x} = \dfrac{x^{4} }{4}$ | $\dfrac{\Lambda^{0} f(x)}{\lambda^{0} x} = x^{3}$            | $\dfrac{\Lambda^{1} f(x)}{\lambda^{1} x} = 3 · x^{2}$        | $\dfrac{\Lambda^{2} f(x)}{\lambda^{2} x} = 6 · x^{1}$        | $\dfrac{\Lambda^{3} f(x)}{\lambda^{3} x} = 6$        |
| $\Lambda^{-2} f(x) = \dfrac{x^{5} }{20} · \lambda^{-2} x$     | $\Lambda^{-1} f(x) = \dfrac{x^{4} }{4} · \lambda^{-1} x$      | $\Lambda^{0} f(x) = x^{3} · \lambda^{0} x$                   | $\Lambda^{1} f(x) = 3 · x^{2} · \lambda^{1} x$               | $\Lambda^{2} f(x) = 6 · x^{1} · \lambda^{2} x$               | $\Lambda^{3} f(x) = 6 · \lambda^{3} x$               |
|                                                              | $\int \Lambda^{-1} f(x) = \Lambda^{-2} f(x)$                 | $\int \Lambda^{0} f(x) = \Lambda^{-1} f(x)$                  | $\int \Lambda^{1} f(x) = \Lambda^{0} f(x)$                   | $\int \Lambda^{2} f(x) = \Lambda^{1} f(x)$                   | $\int \Lambda^{3} f(x) = \Lambda^{2} f(x)$           |
|                                                              | $\int \dfrac{x^{4} }{x} · \lambda^{-1} x = \dfrac{x^{5} }{20} · \lambda^{-2} x$ | $\int x^{3} · \lambda^{0} x = \dfrac{x^{4} }{4} · \lambda^{-1} x$ | $\int 3 · x^{2} · \lambda^{1} x = x^{3} · \lambda^{0} x = x^{3}$ | $\int 6 · x^{1} · \lambda^{2} x = 3 · x^{2} · \lambda^{1} x = \lambda^{1} x^{3}$ | $\int 6 · \lambda^{3} x = 6 · x^{1} · \lambda^{2} x$ |

------

### 单变元隐式方程

$0 = F(y(x),x)$

$\dfrac{\Lambda y(x)}{\lambda x} = -\dfrac{\Lambda F(y,x)}{\lambda x} · \left[ \dfrac{\Lambda F(y,x)}{\lambda y} \right]^{-1}$

$\dfrac{\Lambda^2 y(x)}{\lambda^2 x} = -\left[ \dfrac{\Lambda^2 F(y,x)}{\lambda^2 y} · \left[ \dfrac{\Lambda y}{\lambda x} \right]^{2} + \dfrac{\Lambda^2 F(y,x)}{\lambda y · \lambda x} · \dfrac{\Lambda y}{\lambda x} + \dfrac{\Lambda^2 F(y,x)}{\lambda x · \lambda y} · \dfrac{\Lambda y}{\lambda x} + \dfrac{\Lambda^2 F(y,x)}{\lambda^2 x} \right] · \left[ \dfrac{\Lambda F(y,x)}{\lambda y} \right]^{-1}$

|                                       |                                                              |
| :------------------------------------ | :----------------------------------------------------------- |
| $\dfrac{\Lambda 0}{\lambda x}$        | $\dfrac{\Lambda F(y,x)}{\lambda y} · \dfrac{\Lambda y}{\lambda x} + \dfrac{\Lambda F(y,x)}{\lambda x}$ |
| $\dfrac{\Lambda^2 0}{\lambda^2 x}$    | $\left[ \dfrac{\Lambda^2 F(y,x)}{\lambda^2 y} · \dfrac{\Lambda y}{\lambda x} + \dfrac{\Lambda^2 F(y,x)}{\lambda y · \lambda x} \right] · \dfrac{\Lambda y}{\lambda x} + \dfrac{\Lambda F(y,x)}{\lambda y} · \dfrac{\Lambda^2 y}{\lambda^2 x} + \dfrac{\Lambda^2 F(y,x)}{\lambda x · \lambda y} · \dfrac{\Lambda y}{\lambda x} + \dfrac{\Lambda^2 F(y,x)}{\lambda^2 x}$ |
|                                       |                                                              |
| $\dfrac{\Lambda y(x)}{\lambda x}$     | $-\dfrac{\Lambda F(y,x)}{\lambda x} · \left[ \dfrac{\Lambda F(y,x)}{\lambda y} \right]^{-1}$ |
| $\dfrac{\Lambda^2 y(x)}{\lambda^2 x}$ | $-\left[ \dfrac{\Lambda^2 F(y,x)}{\lambda^2 y} · \left[ \dfrac{\Lambda y}{\lambda x} \right]^{2} + \dfrac{\Lambda^2 F(y,x)}{\lambda y · \lambda x} · \dfrac{\Lambda y}{\lambda x} + \dfrac{\Lambda^2 F(y,x)}{\lambda x · \lambda y} · \dfrac{\Lambda y}{\lambda x} + \dfrac{\Lambda^2 F(y,x)}{\lambda^2 x} \right] · \left[ \dfrac{\Lambda F(y,x)}{\lambda y} \right]^{-1}$ |

### 单变元参数方程

$\left\lbrace\begin{aligned}
y &= y(t) \\
x &= x(t) \\
\end{aligned}\right.$

$y(x) = y[{'}x(t)]$

$\dfrac{\Lambda y(x)}{\lambda x} = \dfrac{\Lambda y(t)}{\lambda t} · \left[ \dfrac{\Lambda x(t)}{\lambda t} \right]^{-1}$

$\dfrac{\Lambda^{2} y(x)}{\lambda^{2} x} = \left[ \dfrac{\Lambda^{2} y}{\lambda^{2} t} · \dfrac{\Lambda x}{\lambda t} - \dfrac{\Lambda y}{\lambda t} · \dfrac{\Lambda^{2} x}{\lambda^{2} t} \right] · \left[ \dfrac{\Lambda x}{\lambda t} \right]^{-3}$

| $\dfrac{\Lambda y(x)}{\lambda x}$         | $\dfrac{Λ y(t)}{λ t} · \dfrac{Λ t}{λ x(t)} = \left[ \dfrac{\Lambda y(t)}{\lambda t} \right] · \left[ \dfrac{\Lambda x(t)}{\lambda t} \right]^{-1}$ |
| :---------------------------------------- | :----------------------------------------------------------- |
| $\dfrac{\Lambda^{2} y(x)}{\lambda^{2} x}$ | $\dfrac{\Lambda}{\lambda x} \dfrac{\Lambda y(x)}{\lambda x} = \dfrac{\Lambda}{\lambda t} \left[ \dfrac{\Lambda y}{\lambda t} · \left[ \dfrac{\Lambda x}{\lambda t} \right]^{-1} \right] · \dfrac{\Lambda t}{\lambda x} = \left[ \dfrac{\Lambda^{2} y}{\lambda^{2} t} · \left[ \dfrac{\Lambda x}{\lambda t} \right]^{-1} + \dfrac{\Lambda y}{\lambda t} · (-1) · \left[ \dfrac{\Lambda x}{\lambda t} \right]^{-2} · \dfrac{\Lambda^{2} x}{\lambda^{2} t} \right] · \dfrac{\Lambda t}{\lambda x} = \left[ \dfrac{\Lambda^{2} y}{\lambda^{2} t} · \dfrac{\Lambda x}{\lambda t} - \dfrac{\Lambda y}{\lambda t} · \dfrac{\Lambda^{2} x}{\lambda^{2} t} \right] · \left[ \dfrac{\Lambda x}{\lambda t} \right]^{-3}$ |

### 平面极角坐标系

$\left\lbrace\begin{aligned}
y &= r(\phi) · \sin \phi \\
x &= r(\phi) · \cos \phi \\
\end{aligned}\right.$

$y(x) = y[{'}x(\phi)]$

$\tan α = \dfrac{\Lambda y(x)}{\lambda x} = \left[ \dfrac{\Lambda r(\phi)}{\lambda \phi} · \tan \phi + r(\phi) \right] · \left[ \dfrac{\Lambda r(\phi)}{\lambda \phi} - r(\phi) · \tan \phi \right]^{-1}$

$\tan ν = \tan (α - \phi) = r(\phi) · \left[ \dfrac{\Lambda r(\phi)}{\lambda \phi} \right]^{-1}$

| $\tan α = \dfrac{\Lambda y(x)}{\lambda x}$ | $\dfrac{\Lambda y(\phi)}{\lambda \phi} · \left[ \dfrac{\Lambda x(\phi)}{\lambda \phi} \right]^{-1} = \left[ \dfrac{\Lambda r(\phi)}{\lambda \phi} · \sin \phi + r(\phi) · \cos \phi \right] · \left[ \dfrac{\Lambda r(\phi)}{\lambda \phi} · \cos \phi - r(\phi) · \sin \phi \right]^{-1} = \left[ \dfrac{\Lambda r(\phi)}{\lambda \phi} · \tan \phi + r(\phi) \right] · \left[ \dfrac{\Lambda r(\phi)}{\lambda \phi} - r(\phi) · \tan \phi \right]^{-1}$ |
| :----------------------------------------- | :----------------------------------------------------------- |
| $\tan ν = \tan (α - \phi)$                    | $\dfrac{\tan α - \tan \phi}{1 + \tan α · \tan \phi} = \dfrac{\left[ \dfrac{\Lambda r(\phi)}{\lambda \phi} · \tan \phi + r(\phi) \right] · \left[ \dfrac{\Lambda r(\phi)}{\lambda \phi} - r(\phi) · \tan \phi \right]^{-1} - \tan \phi}{1 + \left[ \dfrac{\Lambda r(\phi)}{\lambda \phi} · \tan \phi + r(\phi) \right] · \left[ \dfrac{\Lambda r(\phi)}{\lambda \phi} - r(\phi) · \tan \phi \right]^{-1} · \tan \phi} = \dfrac{\dfrac{\Lambda r(\phi)}{\lambda \phi} · \tan \phi + r(\phi) - \dfrac{\Lambda r(\phi)}{\lambda \phi} · \tan \phi + r(\phi) · \tan^{2} \phi}{\dfrac{\Lambda r(\phi)}{\lambda \phi} - r(\phi) · \tan \phi + \dfrac{\Lambda r(\phi)}{\lambda \phi} · \tan^{2} \phi + r(\phi) · \tan \phi} = r(\phi) · \left[ \dfrac{\Lambda r(\phi)}{\lambda \phi} \right]^{-1}$ |

### 平面图形的面积

平面曲线所包围图形的面积。注意：当$\left\lbrace\begin{aligned}
y(α) &= y(β) \\
x(α) &= x(β) \\
\end{aligned}\right.$时平面曲线形成闭环。

$\left\lbrace\begin{aligned}
A &= \left| \int\limits_{x_α}^{x_β} y(x) · \lambda x \right| = \left| \int\limits_{t_α}^{t_β} y(x(t)) · {^1}x(t) · \lambda t \right| \\
A &= \left| \int_{y_α}^{y_β} x(y) · \lambda y \right| = \left| \int\limits_{t_α}^{t_β} x(y(t)) · {^1}y(t) · \lambda t \right| \\
A &= \left| \dfrac{1}{2} · \int\limits_{α}^{β} r^{2}(\phi) · \lambda\phi \right| \\
\end{aligned}\right.$

旋转体截面的面积，旋转体的体积。

$A = π·f^2(x)$

$V = \int\limits_{x_α}^{x_β} π·f^2(x)·\lambda x$

### 空间曲线的长度

$L_3 = \int\limits_{t_α}^{t_β} \sqrt{[{^1}x(t)]^2 + [{^1}y(t)]^2 + [{^1}z(t)]^2} · \lambda t$

$L_3 = \int\limits_{x_α}^{x_β} \sqrt{1 + [{^1}y(x)]^2 + [{^1}z(x)]^2} · \lambda x$

$L_2 \mathop{=======}\limits_{x(\phi)=r(\phi)·\cos \phi}^{y(\phi)=r(\phi)·\sin \phi} \int\limits_{\phi_{α} }^{\phi_β} \sqrt{[^{1}r(\phi)]^2 + [r(\phi)]^2} · \lambda \phi$

| $L_3 = \int\limits_{t_α}^{t_β} \sqrt{[\lambda x(t)]^2 + [\lambda y(t)]^2 + [\lambda z(t)]^2}$ |      |                                                              |
| :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $L_3 = \int\limits_{t_α}^{t_β} \sqrt{\left[ \dfrac{\Lambda x(t)}{\lambda t} \right]^2 + \left[ \dfrac{\Lambda y(t)}{\Lambda t} \right]^2 + \left[ \dfrac{\Lambda z(t)}{\lambda t} \right]^2} · \lambda t = \int\limits_{t_α}^{t_β} \sqrt{[{^1}x(t)]^2 + [{^1}y(t)]^2 + [{^1}z(t)]^2} · \lambda t$ |      |                                                              |
| $L_3 = \int\limits_{x_α}^{x_β} \sqrt{\left[ \dfrac{\Lambda x}{\lambda x} \right]^2+\left[ \dfrac{\Lambda y(x)}{\lambda x} \right]^2+\left[ \dfrac{\Lambda z(x)}{\lambda x} \right]^2} · \lambda x = \int\limits_{x_α}^{x_β} \sqrt{1 + [{^1}y(x)]^2 + [{^1}z(x)]^2} · \lambda x$ |      |                                                              |
| $L_2 \mathop{=======}\limits_{x(\phi)=r(\phi)·\cos \phi}^{y(\phi)=r(\phi)·\sin \phi} \int\limits_{\phi_α}^{\phi_β} \sqrt{[{^1}x(\phi)]^2 + [{^1}y(\phi)]^2} · \lambda \phi = \int\limits_{\phi_{α} }^{\phi_β} \sqrt{[^{1}r(\phi)]^2 + [r(\phi)]^2} · \lambda \phi$ | $⇐$  | $[{^1}x(\phi)]^2 + [{^1}y(\phi)]^2 \mathop{============}\limits_{{^1}x(\phi) = {^1}r(\phi) · \cos \phi - r(\phi) · \sin \phi}^{{^1}y(\phi) = {^1}r(\phi) · \sin \phi + r(\phi)·\cos \phi} [{^1}r(\phi)]^2 + [r(\phi)]^2$ |

### 旋转曲面的面积

平面光滑正则曲线$\left\lbrace\begin{aligned}
y &= y(t) \\
x &= x(t) \\
\end{aligned}\right.$绕$x$轴旋转所得曲面的面积。

$A \mathop{=}\limits_{}^{} \int\limits_{t_α}^{t_β} 2·π·y(t) · \sqrt{[{^1}x(t)]^2 + [{^1}y(t)]^2} · \lambda t$

$A = \int\limits_{x_α}^{x_β} 2 ·π·y(x) ·\sqrt{1 + [{^1}y(x)]^2} · \lambda x$

------

### 抛物体

$\left\lbrace\begin{aligned}
y(t) &= v_y · t - \dfrac{1}{2} · g · t^2 \\
x(t) &= v_x · t \\
\end{aligned}\right.$

$y(x) = \dfrac{v_{y} }{v_x} · x - \dfrac{1}{2} · \dfrac{g}{v_x^2} · x^2$

$v(t) = \sqrt{\left[ \dfrac{\Lambda y(t)}{\lambda t} \right]^{2} + \left[ \dfrac{\Lambda x(t)}{\lambda t} \right]^{2} } = \sqrt{v_{x}^{2} + (v_{y} - g · t)^{2} }$

$\tan α = \dfrac{\Lambda y(x)}{\lambda x} = \dfrac{v_{y} - g · t}{v_{x} }$

| $\dfrac{\Lambda y(t)}{\lambda t}$                            | $v_{y} - g · t$                                              |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\dfrac{\Lambda x(t)}{\lambda t}$                            | $v_{x}$                                                      |
| $v(t) = \sqrt{\left[ \dfrac{\Lambda y(t)}{\lambda t} \right]^{2} + \left[ \dfrac{\Lambda x(t)}{\lambda t} \right]^{2} }$ | $\sqrt{v_{x}^{2} + (v_{y} - g · t)^{2} }$                     |
| $\tan α = \dfrac{\Lambda y(x)}{\lambda x}$                   | $\dfrac{\Lambda y(t)}{\lambda t} · \left[ \dfrac{\Lambda x(t)}{\lambda t} \right]^{-1} = \dfrac{v_{y} - g · t}{v_{x} }$ |

### 椭圆形

$\left\lbrace\begin{aligned}
y(\phi) &= r_y · \sin \phi \\
x(\phi) &= r_x · \cos \phi \\
\end{aligned}\right.$

$\dfrac{x^2}{r_x^2} + \dfrac{y^2}{r_y^2} = 1$

$\dfrac{\Lambda y(x)}{\lambda x} = \dfrac{-r_{y} }{r_{x} · \tan \phi}$

$\dfrac{\Lambda^{2} y(x)}{\lambda^{2} x} = \dfrac{-r_{y} }{r_{x} · \sin^{3} \phi}$

| $\dfrac{\Lambda y(x)}{\lambda x}$         | $\dfrac{\Lambda y(\phi)}{\lambda \phi} · \left[ \dfrac{\Lambda x(\phi)}{\lambda \phi} \right]^{-1} = \dfrac{+r_{y} · \cos \phi} {-r_{x} · \sin \phi} = \dfrac{-r_{y} }{r_{x} · \tan \phi}$ |
| :---------------------------------------- | :----------------------------------------------------------- |
| $\dfrac{\Lambda^{2} y(x)}{\lambda^{2} x}$ | $\left[ \dfrac{\Lambda^{2} y}{\lambda^{2} t} · \dfrac{\Lambda x}{\lambda t} - \dfrac{\Lambda y}{\lambda t} · \dfrac{\Lambda^{2} x}{\lambda^{2} t} \right] · \left[ \dfrac{\Lambda x}{\lambda t} \right]^{-3} = \left[ (-r_{y} · \sin \phi) · (-r_{x} · \sin \phi) - (+r_{y} · \cos \phi) · (-r_{x} · \cos \phi) \right] · [-r_{x} · \sin \phi]^{-3} = \dfrac{-r_{y} }{r_{x} · \sin^{3} \phi}$ |

椭圆的面积。

$A = π·r_x·r_y$

| $A = \int\limits_{0}^{2·π} y(x(\phi)) · {^1}x(\phi) · \mathrm{d} \phi = \int\limits_{0}^{2·π} r_{y} ·\sin \phi · \dfrac{\Lambda}{\lambda \phi} [r_x · \cos \phi] · \lambda \phi$ |
| :----------------------------------------------------------- |
| $A = r_x·r_{y}·\int\limits_{0}^{2·π} \sin^2 \phi · \lambda \phi = r_x·r_y · \int_{0}^{2·π} \dfrac{1 - \cos 2 ·t}{2} · \lambda t = r_x·r_y·\left[ \dfrac{1}{2} · t - \dfrac{\sin 2 ·t}{4} \right]_{0}^{2·π} = π·r_x·r_y$ |

### 旋轮线

$\left\lbrace\begin{aligned}
y(t) &= r · (1 - \cos t) \\
x(t) &= r · (t - \sin t) \\
\end{aligned}\right.$

$x(y) = r · {'}\cos \left( 1 - \dfrac{y}{r} \right) - \sqrt{y · (2 · r - y)}$

$\dfrac{\Lambda y(x)}{\lambda x} = \dfrac{1}{\tan \frac{t}{2} }$

$\dfrac{\Lambda^{2} y(x)}{\lambda^{2} x} = \dfrac{-1}{r · (1 - \cos t)^{2} }$

|                                           |                                                              |
| :---------------------------------------- | :----------------------------------------------------------- |
| $\dfrac{\Lambda y(x)}{\lambda x}$         | $\dfrac{\Lambda y(t)}{\lambda t} · \left[ \dfrac{\Lambda x(t)}{\lambda t} \right]^{-1} = \dfrac{r · \sin t}{r · (1 - \cos t)} = \dfrac{2 · \sin \frac{t}{2} · \cos \frac{t}{2} }{2 · \sin^{2} \frac{t}{2} } = \dfrac{1}{\tan \frac{t}{2} }$ |
| $\dfrac{\Lambda^{2} y(x)}{\lambda^{2} x}$ | $\left[ \dfrac{\Lambda^{2} y}{\lambda^{2} t} · \dfrac{\Lambda x}{\lambda t} - \dfrac{\Lambda y}{\lambda t} · \dfrac{\Lambda^{2} x}{\lambda^{2} t} \right] · \left[ \dfrac{\Lambda x}{\lambda t} \right]^{-3} = \dfrac{[r · \cos t] · [r · (1 - \cos t)] - [r · \sin t] · [r · \sin t]}{[r · (1 - \cos t)]^{3} } = \dfrac{-1}{r · (1 - \cos t)^{2} }$ |

旋轮线单拱的面积。

$A = 3·π·r^2$

| $A = \int\limits_{0}^{2·π·r} y(x) · \lambda x = \int\limits_{0}^{2·π} y(t) · {^1}x(t) · \lambda t = \int\limits_{0}^{2·π} r·(1 - \cos t) · r · (1 - \cos t) · \lambda t $ |
| ------------------------------------------------------------ |
| $A = r^2 · \int\limits_{0}^{2·π} \left( 1 - 2·\cos t + \dfrac{1 + \cos 2 · t}{2} \right) · \lambda t = r^2 · \left[ \dfrac{3}{2} · t - 2 · \sin t + \dfrac{\sin 2 · t}{4} \right]_{0}^{2·π} = 3·π·r^2$ |

旋轮线单拱的长度。

$L = 8 · r$

| $L = \int\limits_{0}^{2·π} \sqrt{[{^1}x(t)]^2 + [^{1}y(t)]^2} · \lambda t = \int\limits_{0}^{2·π} \sqrt{r^2 · (1-\cos t)^2 + r^2 · \sin^2 t} · \lambda t = \int\limits_{0}^{2·π} \sqrt{2·r^2·(1-\cos t)} · \lambda t = 2 · r · \int\limits_{0}^{2·π} \sin \dfrac{t}{2} · \lambda t = -4 · r · \left[ \cos \dfrac{t}{2} \right]_{0}^{2·π} = 8 · r$ |
| :----------------------------------------------------------- |
|                                                              |

### 螺旋线

$r(\phi) = β^{α · \phi}$

$\tan ν = \dfrac{1}{α · \ln β}$

| $\tan κ$ | $r(\phi) · \left[ \dfrac{\Lambda r(\phi)}{\lambda \phi} \right]^{-1} = β^{α·\phi} · [ β^{α·\phi} · \ln β · α ]^{-1} = \dfrac{1}{α · \ln β}$ |
| :------- | :----------------------------------------------------------- |
|          |                                                              |

------

### 抛物线

$y^2 = 2 · p · x$

$\tan α = \dfrac{\Lambda y(x)}{\lambda x} = \dfrac{p}{y}$

$\dfrac{\Lambda^2 y(x)}{\lambda^2 x} = -\dfrac{p^2}{y^3}$

| $\dfrac{\Lambda y(x)}{\lambda x}$     | $-\dfrac{\Lambda F(y,x)}{\lambda x} · \left[ \dfrac{\Lambda F(y,x)}{\lambda y} \right]^{-1} = -(-2 · p) · [2 · y]^{-1} = \dfrac{p}{y}$ |
| :------------------------------------ | :----------------------------------------------------------- |
| $\dfrac{\Lambda^2 y(x)}{\lambda^2 x}$ | $-\left[ \dfrac{\Lambda^2 F(y,x)}{\lambda^2 y} · \left[ \dfrac{\Lambda y}{\lambda x} \right]^{2} + \dfrac{\Lambda^2 F(y,x)}{\lambda y · \lambda x} · \dfrac{\Lambda y}{\lambda x} + \dfrac{\Lambda^2 F(y,x)}{\lambda x · \lambda y} · \dfrac{\Lambda y}{\lambda x} + \dfrac{\Lambda^2 F(y,x)}{\lambda^2 x} \right] · \left[ \dfrac{\Lambda F(y,x)}{\lambda y} \right]^{-1} = -\left[ 2 · \dfrac{p^2}{y^2} + 0 + 0 + 0 \right] · [2 · y]^{-1} = -\dfrac{p^2}{y^3}$ |

### 平直线

$\left\lbrace\begin{aligned}
& 0 = +p · y + q · x + r \\
& \tan α = -\dfrac{q}{p} \\
& \tan κ = +\dfrac{p}{q} \\
& 0 = -q · y + p · x + r_{κ} \\
\end{aligned}\right.
\left\lbrace\begin{aligned}
& y = +k · x + c \\
& \tan α = +k \\
& \tan κ = -\dfrac{1}{k} \\
& y = -\dfrac{1}{k} · x + c_{κ} \\
\end{aligned}\right.
\left\lbrace\begin{aligned}
& \dfrac{y - y_0}{y_1 - y_0} = +\dfrac{x - x_0}{x_1 - x_0} \\
& \tan α = +\dfrac{y_1 - y_0}{x_1 - x_0} \\
& \tan κ = -\dfrac{x_1 - x_0}{y_1 - y_0} \\
& \dfrac{y - y_{κ} }{x_1 - x_0} = -\dfrac{x - x_{κ} }{y_1 - y_0} \\
\end{aligned}\right.
\left\lbrace\begin{aligned}
& y - y_0 = +t · (x - x_0) \\
& \tan α = +t \\
& \tan κ = -\dfrac{1}{t} \\
& y - y_{κ} = -\dfrac{1}{t} · (x - x_{κ}) \\
\end{aligned}\right.$

$\left\lbrace\begin{aligned}
& r_{κ} = +q · y_0 - p · x_0 \\
& y_{κ} = \dfrac{-p · r + q · r_{κ} }{p^2 + q^2} = \dfrac{-p·r + q^2·y_0 -p·q·x_0}{p^2 + q^2} \\
& x_{κ} = \dfrac{-q · r - p · r_{κ} }{p^2 + q^2} = \dfrac{-q·r-p·q·y_0+p^2·x_0}{p^2 + q^2} \\
& \mathrm{D}[\langle x_0,y_0 \rangle; 0=p·y+q·x+r] = \sqrt{(y_{κ}-y_0)^2+(x_{κ}-x_0)^2} = \dfrac{|p·y_0+q·x_0+r|}{\sqrt{p^2 + q^2} } \\
& \mathrm{D}[0=p·y+q·x+r_1;0=p·y+q·x+r_2] = \dfrac{|p·y_1+q·x_1+r_2|}{\sqrt{p^2+q^2} } = \dfrac{|r_1-r_2|}{\sqrt{p^2 + q^2} } \\
\end{aligned}\right.$

### 双扭线

$(x^2 + y^2)^2 = a^2 · (x^2 - y^2)$

$r^2 = a^2 · \cos (2 · \phi)$

| $r^4 = (x^2+y^2)^2 = a^2 · (x^2 - y^2) = a^2 · (r^2·\cos^2 \phi - r^2 ·\sin^2 \phi) = a^2 · r^2 · \cos (2 · \phi)$ | $⇒$  | $r^2 = a^2 · \cos (2 · \phi)$ |
| :----------------------------------------------------------- | :--: | ----------------------------- |
|                                                              |      |                               |

双扭线的面积。

$A = a^2$

| $A = 4 · \dfrac{1}{2} · \int\limits_{0}^{\frac{π}{4} } r^{2} (\phi) · \lambda \phi$ |
| :----------------------------------------------------------- |
| $A = 2 · \int\limits_{0}^{\frac{π}{4} } a^2 · \cos (2·\phi) · \lambda \phi = a^2 · [\sin (2·\phi)]_{0}^{\frac{π}{4} } = a^2$ |

### 椭球体

$\dfrac{x^2}{r_x^2} + \dfrac{y^2}{r_y^2} + \dfrac{z^2}{r_z^2} = 1$

$A_x = π·r_y·r_z·\left( 1 - \dfrac{x^2}{r_x^2} \right)$

$V = \dfrac{4}{3}·π·r_x·r_y·r_z$

| $A_x = π·r_y·\sqrt{1 - \dfrac{x^2}{r_x^2} }·r_z·\sqrt{1-\dfrac{x^2}{r_x^2} } = π·r_y·r_z·\left( 1 - \dfrac{x^2}{r_x^2} \right)$ | $⇐$  | $\dfrac{y^2}{r_y^2 · \left( 1 - \dfrac{x^2}{r_x^2} \right)} + \dfrac{z^2}{r_z^2 · \left( 1 - \dfrac{x^2}{r_x^2} \right)} = 1$ |
| :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $V = \int\limits_{-r_x}^{+r_x} A_x · \lambda x = \int\limits_{-r_x}^{+r_x} π·r_y·r_z·\left( 1 - \dfrac{x^2}{r_x^2} \right) \lambda x = π·r_y·r_z·\left[ x - \dfrac{x^3}{3·r_x^2} \right]_{-r_x}^{+r_x} = \dfrac{4}{3} ·π·r_x·r_y·r_z$ |      |                                                              |

### 圆球体

$x^2 + y^2 = r^2$

圆球体表面积。

$A=4·π·r^2$

| $A = \int\limits_{x_α}^{x_β} 2 ·π·y(x) ·\sqrt{1 + [{^1}y(x)]^2} · \lambda x$ | $⇐$  | $y(x) = \sqrt{r^2 - x^2}$                 |
| :----------------------------------------------------------- | :--: | :---------------------------------------- |
| $A = \int\limits_{-r}^{+r} 2·π·\sqrt{r^2-x^2} ·\sqrt{1+\dfrac{x^2}{r^2 - x^2} } ·\lambda x = \int\limits_{-r}^{+r} 2·π·r · \lambda x = 2·π·r·\left[ x \right]_{-r}^{+r} = 4·π·r^2$ | $⇐$  | ${^1}y(x) = \dfrac{-x}{\sqrt{r^2 - x^2} }$ |

### 圆锥体

$A_x = π·\dfrac{r^2}{h^2} ·x^2$

$V = \dfrac{1}{3} · π ·r^2 · h$

| $A_x = π·\left( \dfrac{r}{h} ·x \right)^2 = π·\dfrac{r^2}{h^2} ·x^2$ |
| :----------------------------------------------------------- |
| $V = \int\limits_{0}^{h} A_x · \lambda x = \int\limits_{0}^{h} π·\dfrac{r^2}{h^2} ·x^2 · \lambda x = π·\dfrac{r^2}{h^2} ·\left. \dfrac{x^3}{3} \right|_{0}^{h} = \dfrac{1}{3} · π·r^2 ·h$ |

### 圆环体

圆环体截面方程，其中$r_{O}$为圆心到原点的距离，$r_{A}$为圆的半径。

$x^2 + (y-r_O)^2 = r_A^2$

$A_l = π·r_A^2$

$V = 2·π^2·r_{A}^2·r_{O}$

| $V = \int\limits_{0}^{2·π·r_{O} } A_l · \lambda l = \int\limits_{0}^{2·π·r_{O} } π·r_A^2 · \lambda l = 2·π^2·r_A^2·r_O$ |
| ------------------------------------------------------------ |
|                                                              |

### 悬链线

$y = \dfrac{ә^{x} + ә^{-x} }{2}$

悬链线从$x=0$到$x=x_0$的弧长。

$L = \dfrac{ә^{x_0} - ә^{-x_0} }{2}$

| $L = \int\limits_{0}^{x_0} \sqrt{1 + [{^1}y(x)]^2} · \lambda x = \int\limits_{0}^{x_0} \sqrt{1 + \left[ \dfrac{ә^{x} - ә^{-x} }{2} \right]^2} · \lambda x = \int\limits_{0}^{x_0} \dfrac{ә^{x}+ә^{-x} }{2} · \lambda x = \left[ \dfrac{ә^x - ә^{-x} }{2} \right]_{0}^{x_0} = \dfrac{ә^{x_0} - ә^{-x_0} }{2}$ |
| :----------------------------------------------------------- |
|                                                              |

### 心形线

$r = a · (1 + \cos \phi)$

心形线的周长。

$L = 8 · a$

| $L = \int\limits_{0}^{2·π} \sqrt{[{^1}r(\phi)]^2 + [r(\phi)]^2} · \lambda \phi = \int\limits_{0}^{2·π} \sqrt{a^2·(-\sin \phi)^2 + a^2 · (1 + \cos \phi)^2} · \lambda \phi$ |
| :----------------------------------------------------------- |
| $L = a · \int\limits_{0}^{2·π} \sqrt{2·(1 + \cos \phi)} · \lambda \phi = 2 ·a · \int\limits_{0}^{2·π} \left| \cos \dfrac{\phi}{2} \right| · \lambda \phi = 2·a·\int\limits_{0}^{π} \cos \dfrac{\phi}{2}·\lambda \phi - 2·a·\int\limits_{π}^{2·π} \cos \dfrac{\phi}{2} · \lambda \phi = 4·a·\left[\sin\dfrac{\phi}{2}\right]_0^{π} - 4·a·\left[ \sin \dfrac{\phi}{2} \right]_{π}^{2·π} = 8·a$ |

### 圆柱螺线

$\left\lbrace\begin{aligned}
z(t) &= h· t \\
y(t) &= r · \sin t \\
x(t) &= r · \cos t \\
\end{aligned}\right.$

圆柱螺线单螺距的弧长。

$L = 2·π·\sqrt{r^2+h^2}$

| $L = \int\limits_{0}^{2·π} \sqrt{[{^1}x(t)]^2 + [{^1}y(t)]^2 + [{^1}z(t)]^2} · \lambda t = \int\limits_{0}^{2·π} \sqrt{(-r·\sin t)^2 + (r·\cos t)^2 + h^2} · \lambda t = \sqrt{r^2+h^2} · \int\limits_{0}^{2·π} \lambda t = 2·π·\sqrt{r^2+h^2}$ |
| :----------------------------------------------------------- |
|                                                              |



