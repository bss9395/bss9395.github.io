---
layout:  zh_post
Topic :  收敛极限
Title :  解析几何学
Update:  2021-04-30T02:21:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 特别注意

```
本书中微分算符与教科书不同。
本书中微分算符必定成对出现。
```

在本书中，全微分算符为$\Lambda$，偏微分算符为$\lambda$，一阶求导算符为$\dfrac{\Lambda}{\lambda} ≡ \dfrac{\Lambda^{1}}{\lambda^{1}}$，高阶求导算符为$\dfrac{\Lambda^{n}}{\lambda^{n}} ≡ \dfrac{\Lambda}{\lambda} \dfrac{\Lambda^{n-1}}{\lambda^{n-1}}$。

一阶微分同等定理。

$\Lambda f(x) = \lambda f(x)$

$\dfrac{\Lambda f^{⇵}(x)}{\lambda x} \mathop{====}\limits_{x={'}f^{⇵}(y)}^{y=f^{⇵}(x)} \left[ \dfrac{\Lambda {'}f^{⇵}(y)}{\lambda y} \right]^{-1}$

$\dfrac{\Lambda g(f(x))}{\lambda x} = \dfrac{\Lambda g(f(x))}{\lambda f(x)} · \dfrac{\Lambda f(x)}{\lambda x} \mathop{===}\limits^{y=f(x)} \dfrac{\Lambda g(y)}{\lambda y} · \dfrac{\Lambda f(x)}{\lambda x}$

二变元全微分定理。

$\dfrac{\Lambda^{2} f(x,y)}{\lambda^{1} y · \lambda^{1} x} = f_{y,x}$

$\Lambda^{1} f(x,y) = f_{x} · \lambda x + f_{y} · \lambda y$

$\Lambda^{2} f(x,y) = \Lambda [f_{x} · \lambda x + f_{y} · \lambda y] = f_{x,x} · \lambda^{2} x + f_{x,y} · \lambda^{1} x · \lambda^{1} y + f_{y,x} · \lambda^{1} y · \lambda^{1} x + f_{y,y} · \lambda^{2} y$

典例：函数$f(x) = x^{3}$。

|                                                              | $\int \Lambda f(x) = f(x)$                                   | $\Lambda^{0} f(x) ≡ f(x)$                                    | $\lambda^{0} x ≡ 1$                                          | $\lambda h(x) = \dfrac{\Lambda h(x)}{\lambda x} · \lambda x$ |                                                      |
| :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :--------------------------------------------------- |
| $\dfrac{\Lambda^{-2} f(x)}{\lambda^{-2} x} = \dfrac{x^{5}}{20}$ | $\dfrac{\Lambda^{-1} f(x)}{\lambda^{-1} x} = \dfrac{x^{4}}{4}$ | $\dfrac{\Lambda^{0} f(x)}{\lambda^{0} x} = x^{3}$            | $\dfrac{\Lambda^{1} f(x)}{\lambda^{1} x} = 3 · x^{2}$        | $\dfrac{\Lambda^{2} f(x)}{\lambda^{2} x} = 6 · x^{1}$        | $\dfrac{\Lambda^{3} f(x)}{\lambda^{3} x} = 6$        |
| $\Lambda^{-2} f(x) = \dfrac{x^{5}}{20} · \lambda^{-2} x$     | $\Lambda^{-1} f(x) = \dfrac{x^{4}}{4} · \lambda^{-1} x$      | $\Lambda^{0} f(x) = x^{3} · \lambda^{0} x$                   | $\Lambda^{1} f(x) = 3 · x^{2} · \lambda^{1} x$               | $\Lambda^{2} f(x) = 6 · x^{1} · \lambda^{2} x$               | $\Lambda^{3} f(x) = 6 · \lambda^{3} x$               |
|                                                              | $\int \Lambda^{-1} f(x) = \Lambda^{-2} f(x)$                 | $\int \Lambda^{0} f(x) = \Lambda^{-1} f(x)$                  | $\int \Lambda^{1} f(x) = \Lambda^{0} f(x)$                   | $\int \Lambda^{2} f(x) = \Lambda^{1} f(x)$                   | $\int \Lambda^{3} f(x) = \Lambda^{2} f(x)$           |
|                                                              | $\int \dfrac{x^{4}}{x} · \lambda^{-1} x = \dfrac{x^{5}}{20} · \lambda^{-2} x$ | $\int x^{3} · \lambda^{0} x = \dfrac{x^{4}}{4} · \lambda^{-1} x$ | $\int 3 · x^{2} · \lambda^{1} x = x^{3} · \lambda^{0} x = x^{3}$ | $\int 6 · x^{1} · \lambda^{2} x = 3 · x^{2} · \lambda^{1} x = \lambda^{1} x^{3}$ | $\int 6 · \lambda^{3} x = 6 · x^{1} · \lambda^{2} x$ |

------

### 平面极坐标系



------

### 单变元参数方程

$\left\lbrace\begin{align}
y &= y(t) \\
x &= x(t) \\
\end{align}\right.$

$y(x) = y[{'}x(t)]$

| $\dfrac{\Lambda y(x)}{\lambda x} = \dfrac{\Lambda y(t)}{\lambda t} · \left[ \dfrac{\Lambda x(t)}{\lambda t} \right]^{-1}$ | $\dfrac{\Lambda y(x)}{\lambda x} = \dfrac{Λ y(t)}{λ t} · \dfrac{Λ t}{λ x(t)}$ |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\dfrac{\Lambda^{2} y(x)}{\lambda^{2} x} = \left[ \dfrac{\Lambda^{2} y}{\lambda^{2} t} · \dfrac{\Lambda x}{\lambda t} - \dfrac{\Lambda y}{\lambda t} · \dfrac{\Lambda^{2} x}{\lambda^{2} t} \right] · \left[ \dfrac{\Lambda x}{\lambda t} \right]^{-3}$ | $\dfrac{\Lambda}{\lambda x} \dfrac{\Lambda y(x)}{\lambda x} = \dfrac{\Lambda}{\lambda t} \left[ \dfrac{\Lambda y}{\lambda t} · \left[ \dfrac{\Lambda x}{\lambda t} \right]^{-1} \right] · \dfrac{\Lambda t}{\lambda x} = \left[ \dfrac{\Lambda^{2} y}{\lambda^{2} t} · \left[ \dfrac{\Lambda x}{\lambda t} \right]^{-1} + \dfrac{\Lambda y}{\lambda t} · (-1) · \left[ \dfrac{\Lambda x}{\lambda t} \right]^{-2} · \dfrac{\Lambda^{2} x}{\lambda^{2} t} \right] · \dfrac{\Lambda t}{\lambda x}$ |
|                                                              |                                                              |

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

