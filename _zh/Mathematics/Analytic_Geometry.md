---
layout:  zh_post
Topic :  收敛极限
Title :  解析几何学
Update:  2021-04-29T05:17:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 单变元参数方程

$\left\lbrace\begin{align}
y &= y(t) \\
x &= x(t) \\
\end{align}\right.$

$y(x) = y[{'}x(t)]$

| $\dfrac{\mathrm{d} y(x)}{\mathrm{d} x} = \dfrac{\mathrm{d} y(t)}{\mathrm{d} t} · \left[ \dfrac{\mathrm{d} x(t)}{\mathrm{d} t} \right]^{-1}$ | $\dfrac{\mathrm{d} y(t)}{\mathrm{d} t} · \dfrac{\mathrm{d} t}{\mathrm{d} x(t)}$ |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\dfrac{\mathrm{d}^{2} y(x)}{\mathrm{d}^{2} x} = \left[ \dfrac{\mathrm{d}^{2} y}{\mathrm{d}^2 t} · \dfrac{\mathrm{d} x}{\mathrm{d} t} - \dfrac{\mathrm{d} y}{\mathrm{d} t} · \dfrac{\mathrm{d}^{2} x}{\mathrm{d}^{2} t} \right] · \left[\dfrac{\mathrm{d} x}{\mathrm{d} t}\right]^{-3}$ | $\dfrac{\mathrm{d}}{\mathrm{d} t} \left[ \dfrac{\mathrm{d} y(t)}{\mathrm{d} t} · \dfrac{\mathrm{d} t}{\mathrm{d} x(t)} \right] · \dfrac{\mathrm{d} t}{\mathrm{d} x} = \left[ \dfrac{\mathrm{d}^{2} y}{\mathrm{d}^{2} t} · \dfrac{\mathrm{d} t}{\mathrm{d} x} + \dfrac{\mathrm{d} y}{\mathrm{d} t} · (-1) · \left[ \dfrac{\mathrm{d} x}{\mathrm{d} t} \right]^{-2} · \dfrac{\mathrm{d}^{2} x}{\mathrm{d}^2 t} \right] · \dfrac{\mathrm{d} t}{\mathrm{d} x}$ |

### 抛物体参数方程

$\left\lbrace\begin{align}
y(t) &= v_y · t - \dfrac{1}{2} · g · t^2 \\
x(t) &= v_x · t \\
\end{align}\right.$

$y(x) = \dfrac{v_{y}}{v_x} · x - \dfrac{1}{2} · \dfrac{g}{v_x^2} · x^2$

|      |      |      |
| ---- | ---- | ---- |
|      |      |      |
|      |      |      |
|      |      |      |

### 椭圆参数方程

$\left\lbrace\begin{align}
y(t) &= r_y · \sin t \\
x(t) &= r_x · \cos t \\
\end{align}\right.$

$\dfrac{x^2}{r_x^2} + \dfrac{y^2}{r_y^2} = 1$

### 摆线参数方程

$\left\lbrace\begin{align}
y(t) &= r · (1 - \cos t) \\
x(t) &= r · (t - \sin t) \\
\end{align}\right.$

$x(y) = r · {'}\cos \left( 1 - \dfrac{y}{r} \right) - \sqrt{y · (2 · r - y)}$

|      |      |      |
| ---- | ---- | ---- |
|      |      |      |
|      |      |      |
|      |      |      |

