---
layout:  zh_post
Topic :  收敛极限
Title :  解析几何学
Update:  2021-05-09T02:12:00+08@中国-广东-湛江+08
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

$\dfrac{\Lambda^{2} f(x,y)}{\lambda^{1} x · \lambda^{1} y} = f_{y,x} = \dfrac{\Lambda^{2} f(x,y)}{\lambda^{1} y · \lambda^{1} x}$

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
y &= r(θ) · \sin θ \\
x &= r(θ) · \cos θ \\
\end{aligned}\right.$

$y(x) = y[{'}x(θ)]$

$\tan α = \dfrac{\Lambda y(x)}{\lambda x} = \left[ \dfrac{\Lambda r(θ)}{\lambda θ} · \tan θ + r(θ) \right] · \left[ \dfrac{\Lambda r(θ)}{\lambda θ} - r(θ) · \tan θ \right]^{-1}$

$\tan ν = \tan (α - θ) = r(θ) · \left[ \dfrac{\Lambda r(θ)}{\lambda θ} \right]^{-1}$

| $\tan α = \dfrac{\Lambda y(x)}{\lambda x}$ | $\dfrac{\Lambda y(θ)}{\lambda θ} · \left[ \dfrac{\Lambda x(θ)}{\lambda θ} \right]^{-1} = \left[ \dfrac{\Lambda r(θ)}{\lambda θ} · \sin θ + r(θ) · \cos θ \right] · \left[ \dfrac{\Lambda r(θ)}{\lambda θ} · \cos θ - r(θ) · \sin θ \right]^{-1} = \left[ \dfrac{\Lambda r(θ)}{\lambda θ} · \tan θ + r(θ) \right] · \left[ \dfrac{\Lambda r(θ)}{\lambda θ} - r(θ) · \tan θ \right]^{-1}$ |
| :----------------------------------------- | :----------------------------------------------------------- |
| $\tan ν = \tan (α - θ)$                    | $\dfrac{\tan α - \tan θ}{1 + \tan α · \tan θ} = \dfrac{\left[ \dfrac{\Lambda r(θ)}{\lambda θ} · \tan θ + r(θ) \right] · \left[ \dfrac{\Lambda r(θ)}{\lambda θ} - r(θ) · \tan θ \right]^{-1} - \tan θ}{1 + \left[ \dfrac{\Lambda r(θ)}{\lambda θ} · \tan θ + r(θ) \right] · \left[ \dfrac{\Lambda r(θ)}{\lambda θ} - r(θ) · \tan θ \right]^{-1} · \tan θ} = \dfrac{\dfrac{\Lambda r(θ)}{\lambda θ} · \tan θ + r(θ) - \dfrac{\Lambda r(θ)}{\lambda θ} · \tan θ + r(θ) · \tan^{2} θ}{\dfrac{\Lambda r(θ)}{\lambda θ} - r(θ) · \tan θ + \dfrac{\Lambda r(θ)}{\lambda θ} · \tan^{2} θ + r(θ) · \tan θ} = r(θ) · \left[ \dfrac{\Lambda r(θ)}{\lambda θ} \right]^{-1}$ |

------

### 抛物体参数方程

$\left\lbrace\begin{aligned}
y(t) &= v_y · t - \dfrac{1}{2} · g · t^2 \\
x(t) &= v_x · t \\
\end{aligned}\right.$

$y(x) = \dfrac{v_{y}}{v_x} · x - \dfrac{1}{2} · \dfrac{g}{v_x^2} · x^2$

$v(t) = \sqrt{\left[ \dfrac{\Lambda y(t)}{\lambda t} \right]^{2} + \left[ \dfrac{\Lambda x(t)}{\lambda t} \right]^{2}} = \sqrt{v_{x}^{2} + (v_{y} - g · t)^{2}}$

$\tan α = \dfrac{\Lambda y(x)}{\lambda x} = \dfrac{v_{y} - g · t}{v_{x}}$

| $\dfrac{\Lambda y(t)}{\lambda t}$                            | $v_{y} - g · t$                                              |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\dfrac{\Lambda x(t)}{\lambda t}$                            | $v_{x}$                                                      |
| $v(t) = \sqrt{\left[ \dfrac{\Lambda y(t)}{\lambda t} \right]^{2} + \left[ \dfrac{\Lambda x(t)}{\lambda t} \right]^{2}}$ | $\sqrt{v_{x}^{2} + (v_{y} - g · t)^{2}}$                     |
| $\tan α = \dfrac{\Lambda y(x)}{\lambda x}$                   | $\dfrac{\Lambda y(t)}{\lambda t} · \left[ \dfrac{\Lambda x(t)}{\lambda t} \right]^{-1} = \dfrac{v_{y} - g · t}{v_{x}}$ |

### 椭圆线参数方程

$\left\lbrace\begin{aligned}
y(θ) &= r_y · \sin θ \\
x(θ) &= r_x · \cos θ \\
\end{aligned}\right.$

$\dfrac{x^2}{r_x^2} + \dfrac{y^2}{r_y^2} = 1$

$\dfrac{\Lambda y(x)}{\lambda x} = \dfrac{-r_{y}}{r_{x} · \tan θ}$

$\dfrac{\Lambda^{2} y(x)}{\lambda^{2} x} = \dfrac{-r_{y}}{r_{x} · \sin^{3} θ}$

| $\dfrac{\Lambda y(x)}{\lambda x}$         | $\dfrac{\Lambda y(θ)}{\lambda θ} · \left[ \dfrac{\Lambda x(θ)}{\lambda θ} \right]^{-1} = \dfrac{+r_{y} · \cos θ} {-r_{x} · \sin θ} = \dfrac{-r_{y}}{r_{x} · \tan θ}$ |
| :---------------------------------------- | :----------------------------------------------------------- |
| $\dfrac{\Lambda^{2} y(x)}{\lambda^{2} x}$ | $\left[ \dfrac{\Lambda^{2} y}{\lambda^{2} t} · \dfrac{\Lambda x}{\lambda t} - \dfrac{\Lambda y}{\lambda t} · \dfrac{\Lambda^{2} x}{\lambda^{2} t} \right] · \left[ \dfrac{\Lambda x}{\lambda t} \right]^{-3} = \left[ (-r_{y} · \sin θ) · (-r_{x} · \sin θ) - (+r_{y} · \cos θ) · (-r_{x} · \cos θ) \right] · [-r_{x} · \sin θ]^{-3} = \dfrac{-r_{y}}{r_{x} · \sin^{3} θ}$ |

### 旋轮线参数方程

$\left\lbrace\begin{aligned}
y(t) &= r · (1 - \cos t) \\
x(t) &= r · (t - \sin t) \\
\end{aligned}\right.$

$x(y) = r · {'}\cos \left( 1 - \dfrac{y}{r} \right) - \sqrt{y · (2 · r - y)}$

$\dfrac{\Lambda y(x)}{\lambda x} = \dfrac{1}{\tan \frac{t}{2}}$

$\dfrac{\Lambda^{2} y(x)}{\lambda^{2} x} = \dfrac{-1}{r · (1 - \cos t)^{2}}$

|                                           |                                                              |
| :---------------------------------------- | :----------------------------------------------------------- |
| $\dfrac{\Lambda y(x)}{\lambda x}$         | $\dfrac{\Lambda y(t)}{\lambda t} · \left[ \dfrac{\Lambda x(t)}{\lambda t} \right]^{-1} = \dfrac{r · \sin t}{r · (1 - \cos t)} = \dfrac{2 · \sin \frac{t}{2} · \cos \frac{t}{2}}{2 · \sin^{2} \frac{t}{2}} = \dfrac{1}{\tan \frac{t}{2}}$ |
| $\dfrac{\Lambda^{2} y(x)}{\lambda^{2} x}$ | $\left[ \dfrac{\Lambda^{2} y}{\lambda^{2} t} · \dfrac{\Lambda x}{\lambda t} - \dfrac{\Lambda y}{\lambda t} · \dfrac{\Lambda^{2} x}{\lambda^{2} t} \right] · \left[ \dfrac{\Lambda x}{\lambda t} \right]^{-3} = \dfrac{[r · \cos t] · [r · (1 - \cos t)] - [r · \sin t] · [r · \sin t]}{[r · (1 - \cos t)]^{3}} = \dfrac{-1}{r · (1 - \cos t)^{2}}$ |

### 螺旋线参数方程

$r(θ) = β^{α · θ}$

$\tan ν = \dfrac{1}{α · \ln β}$

| $\tan κ$ | $r(θ) · \left[ \dfrac{\Lambda r(θ)}{\lambda θ} \right]^{-1} = β^{α·θ} · [ β^{α·θ} · \ln β · α ]^{-1} = \dfrac{1}{α · \ln β}$ |
| :------- | :----------------------------------------------------------- |
|          |                                                              |

------

### 抛物线坐标方程

$y^2 = 2 · p · x$

$\tan α = \dfrac{\Lambda y(x)}{\lambda x} = \dfrac{p}{y}$

$\dfrac{\Lambda^2 y(x)}{\lambda^2 x} = -\dfrac{p^2}{y^3}$

| $\dfrac{\Lambda y(x)}{\lambda x}$     | $-\dfrac{\Lambda F(y,x)}{\lambda x} · \left[ \dfrac{\Lambda F(y,x)}{\lambda y} \right]^{-1} = -(-2 · p) · [2 · y]^{-1} = \dfrac{p}{y}$ |
| :------------------------------------ | :----------------------------------------------------------- |
| $\dfrac{\Lambda^2 y(x)}{\lambda^2 x}$ | $-\left[ \dfrac{\Lambda^2 F(y,x)}{\lambda^2 y} · \left[ \dfrac{\Lambda y}{\lambda x} \right]^{2} + \dfrac{\Lambda^2 F(y,x)}{\lambda y · \lambda x} · \dfrac{\Lambda y}{\lambda x} + \dfrac{\Lambda^2 F(y,x)}{\lambda x · \lambda y} · \dfrac{\Lambda y}{\lambda x} + \dfrac{\Lambda^2 F(y,x)}{\lambda^2 x} \right] · \left[ \dfrac{\Lambda F(y,x)}{\lambda y} \right]^{-1} = -\left[ 2 · \dfrac{p^2}{y^2} + 0 + 0 + 0 \right] · [2 · y]^{-1} = -\dfrac{p^2}{y^3}$ |

### 平直线坐标方程

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
& \dfrac{y - y_{κ}}{x_1 - x_0} = -\dfrac{x - x_{κ}}{y_1 - y_0} \\
\end{aligned}\right.
\left\lbrace\begin{aligned}
& y - y_0 = +t · (x - x_0) \\
& \tan α = +t \\
& \tan κ = -\dfrac{1}{t} \\
& y - y_{κ} = -\dfrac{1}{t} · (x - x_{κ}) \\
\end{aligned}\right.$

$\left\lbrace\begin{aligned}
& r_{κ} = q · y_0 - p · x_0 \\
& y_{κ} = \dfrac{-r · p + r_{κ} · q}{p^2 + q^2} = \dfrac{-r·p + q^2·y_0 -p·q·x_0}{p^2 + q^2} \\
& x_{κ} = \dfrac{-r · q - r_{κ} · p}{p^2 + q^2} = \dfrac{-r·q-p·q·y_0+p^2·x_0}{p^2 + q^2} \\
& \mathrm{D}[\langle x_0,y_0 \rangle; 0=p·y+q·x+r] = \sqrt{(y_{κ}-y_0)^2+(x_{κ}-x_0)^2} = \dfrac{|p·y_0+q·x_0+r|}{\sqrt{p^2 + q^2}} \\
\end{aligned}\right.$

