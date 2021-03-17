---
layout:  zh_post
Topic :  收敛极限
Title :  基本关系式
Update:  2021-03-18T01:50:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 取整恒等式

$x = ⌊x⌋ + [x]$

$⌈x⌉ = ⌊x⌋ + \mathrm{sgn} [x]$

典例：$2.71828 = ⌊2.71828⌋ + [2.71828] = 2 + 0.71828$，$-2.71828 = ⌊-2.71828⌋ + [-2.71828] = -2 + -0.71828$

典例：$3 = ⌈2.71828⌉ = ⌊2.71828⌋ + \mathrm{sgn} [2.71828] = 2 + 1$，$-3 = ⌈-2.71828⌉ = ⌊-2.71828⌋ + \mathrm{sgn} [-2.71828] = -2 + -1$

### 最值恒等式

$\max\limits_{x∈X}\lbrace f (x), g (x) \rbrace = \dfrac{f (x) + g (x) + | f (x) - g (x) |}{2} = \dfrac{f (x) + g (x) + \sqrt{[ f (x) - g (x) ]^2}}{2}$

$\min\limits_{x∈X}\lbrace f (x), g (x) \rbrace = \dfrac{f (x) + g (x) - | f (x) - g (x) |}{2} = \dfrac{f (x) + g (x) - \sqrt{[ f (x) - g (x) ]^2}}{2}$

$\min\limits_{x∈X} \lbrace f (x), g (x) \rbrace = -\max\limits_{x∈X} \lbrace -f (x), -g (x) \rbrace$

### 组合恒等式

$\mathrm{C} (n, i) = \dfrac{n!}{i! · (n - i)!} = \dfrac{n!}{(n - i)! · i!} = \mathrm{C} (n, n - i)$

$\mathrm{C} (n + 1, i) = \dfrac{(n + 1)!}{i! · (n + 1 - i)!} = \dfrac{n!}{i! · (n - i)!} + \dfrac{n!}{(i - 1)! · (n - i + 1)!} = \mathrm{C} (n, i) + \mathrm{C} (n, i - 1)$

$(x + y)^{n} = \sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · x^{i} · y^{n-i}$

| $⇓$  |                               $(x + y)^{0}$ | $= 1$                                                        |
| :--: | ------------------------------------------: | ------------------------------------------------------------ |
| $⇓$  |                               $(x + y)^{1}$ | $= \dfrac{1!}{0! · 1!} x^{0} · y^{1} + \dfrac{1!}{1! · 0!} x^{1} · y^{0}$ |
| $⇓$  |                               $(x + y)^{n}$ | $= \sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · x^{i} · y^{n-i}$ |
| $⇓$  | $(x + y)^{n} · (x + y)^{1} = (x + y)^{n+1}$ | $= \sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · x^{i+1} · y^{n-i} + \sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · x^{i} · y^{n+1-i}$ |
|      |                                             | $= x^{n+1} · y^{0} + \left[ \sum\limits_{i=1}^{n} \dfrac{n!}{(i - 1)! · (n - i + 1)!} · x^{i} · y^{n-(i-1)} + \sum\limits_{i=1}^{n} \dfrac{n!}{i! · (n - i)!} · x^{i} · y^{n+1-i} \right] + x^{0} · y^{n+1}$ |
|      |                                             | $= x^{n+1} · y^{0} + \sum\limits_{i=1}^{n} \dfrac{(n + 1)!}{i! · (n + 1 - i)!} · x^{i} · y^{n+1-i} + x^{0} · y^{n+1}$ |
| $⇓$  |                             $(x + y)^{n+1}$ | $= \sum\limits_{i=0}^{n+1} \dfrac{(n + 1)!}{i! · (n + 1 - i)!} · x^{i} · y^{n+1-i}$ |

### 等比恒等式

$x^{n+1} - y^{n+1} = (x - y) · \sum\limits_{i=0}^{n} x^{i} · y^{n - i}$

$\dfrac{x^{n+1} - 1}{x - 1} = \sum\limits_{i=0}^{n} x^{i}$

| $⇓$  |          $x^{n+1} - y^{n+1}$ | $= (x - y) · \sum\limits_{i=0}^{n} x^{i} · y^{n - i} = \sum\limits_{i=0}^{n} x^{i+1} · y^{n-i} - \sum\limits_{i=0}^{n} x^{i} · y^{n-(i-1)} = x^{n+1} + \left[ \sum\limits_{i=0}^{n-1} x^{i+1} · y^{n-i} - \sum\limits_{i=0}^{n-1} x^{i+1} · y^{n-i} \right] - y^{n+1}$ |
| :--: | ---------------------------: | :----------------------------------------------------------- |
| $⇓$  |                $x^{n+1} - 1$ | $= (x - 1) · \sum\limits_{i=0}^{n} x^{i}$                    |
| $⇓$  | $\dfrac{x^{n+1} - 1}{x - 1}$ | $= \sum\limits_{i=0}^{n} x^{i}$                              |

### 等幂恒等式

$I(m, n) = \dfrac{(m + 1)^{n+1}}{n + 1} - \sum\limits_{i=0}^{n-1} \dfrac{n!}{i! · (n + 1 - i)!} · I(m,i)$

$\sum\limits_{j=0}^{m} j^{0} = \dfrac{(m + 1)^{1}}{1}$

$\sum\limits_{j=0}^{m} j^{1} = \dfrac{(m + 1)^{2}}{2} - \dfrac{(m + 1)^{1}}{2}$

$\sum\limits_{j=0}^{m} j^{2} = \dfrac{(m + 1)^3}{3} - \dfrac{(m + 1)^{2}}{2} + \dfrac{(m + 1)^{1}}{6}$

$\sum\limits_{j=0}^{m} j^{3} = \dfrac{(m + 1)^{4}}{4} - \dfrac{(m + 1)^3}{2} + \dfrac{(m + 1)^{2}}{4}$

| $⇓$  |             |                                              $(x + 1)^{n+1}$ | $= \sum\limits_{i=0}^{n+1} \dfrac{(n + 1)!}{i! · (n + 1 - i)!} · x^{i} = \sum\limits_{i=0}^{n} \dfrac{(n + 1)!}{i! · (n + 1 - i)!} · x^{i} + x^{n+1}$ |
| :--: | :---------: | -----------------------------------------------------------: | :----------------------------------------------------------- |
| $⇓$  |             | $(m + 1)^{n+1} - 0^{n+1} = \sum\limits_{j=0}^{m} [(j + 1)^{n+1} - j^{n+1}]$ | $= \sum\limits_{j=0}^{m} \sum\limits_{i=0}^{n} \dfrac{(n + 1)!}{i! · (n + 1 - i)!} · j^{i} = \sum\limits_{i=0}^{n} \dfrac{(n + 1)!}{i! · (n + 1 - i)!} · \sum\limits_{j=0}^{m} j^{i} = (n + 1) · \sum\limits_{j=0}^{m} j^{n} + \sum\limits_{i=0}^{n-1} \dfrac{(n + 1)!}{i! · (n + 1 - i)!} · \sum\limits_{j=0}^{m} j^{i}$ |
| $⇓$  |             |                                $\sum\limits_{j=0}^{m} j^{n}$ | $= \dfrac{(m + 1)^{n + 1}}{n + 1} - \sum\limits_{i=0}^{n-1} \dfrac{n!}{i! · (n + 1 - i)!} · \sum\limits_{j=0}^{m} j^{i}$ |
| $⇓$  |             |                                                    $I(m, n)$ | $= \dfrac{(m + 1)^{n+1}}{n + 1} - \sum\limits_{i=0}^{n-1} \dfrac{n!}{i! · (n + 1 - i)!} · I(m,i)$ |
|      |             |                                                              |                                                              |
| $⇓$  | $0^{0} ≡ 1$ |                      $\sum\limits_{j=0}^{m} j^{0} = I(m, 0)$ | $= \dfrac{(m + 1)^{1}}{1} - \dfrac{1}{1} · \mathop{I(m, -1)}\limits_{≡0}$ |
| $⇓$  |             |                     $\sum\limits_{j=0}^{m} j^{1} = I (m, 1)$ | $= \dfrac{(m + 1)^{2}}{2} - \dfrac{1}{2} · I(m, 0) = \dfrac{(m + 1)^{2}}{2} - \dfrac{(m + 1)^{1}}{2}$ |
| $⇓$  |             |                      $\sum\limits_{j=0}^{m} j^{2} = I(m, 2)$ | $= \dfrac{(m + 1)^{3}}{3} - \dfrac{1}{3} · I(m, 0) - \dfrac{1}{1} · I(m, 1) = \dfrac{(m + 1)^3}{3} - \dfrac{(m + 1)^{2}}{2} + \dfrac{(m + 1)^{1}}{6}$ |
| $⇓$  |             |                      $\sum\limits_{j=0}^{m} j^{3} = I(m, 3)$ | $= \dfrac{(m + 1)^{4}}{4} - \dfrac{1}{4} · I(m, 0) - \dfrac{1}{1} · I(m, 1) - \dfrac{3}{2} · I(m, 2) = \dfrac{(m + 1)^{4}}{4} - \dfrac{(m + 1)^3}{2} + \dfrac{(m + 1)^{2}}{4}$ |

------

### 阶乘方不等式

$n! \mathop{≡≡}\limits^{0!≡1} n · (n - 1)!$

$[n!]^2 ≥ n^{n}$

| $n ≥ i+ 1$                                      | $n ≥ i + 1$                                                  | $n = 1,2$      |
| :---------------------------------------------- | :----------------------------------------------------------- | :------------- |
| $(n - i) · (i + 1) - n = i · [n - (i + 1)] ≥ 0$ | $[n!]^{2} = [(n - 0) · 1] · [(n - 1) · 2] ··· [2 · (n - 1)] · [1 · (n - 0)]$ |                |
| $(n - i) · (i + 1) ≥ n$                         | $[n!]^2 ≥ n^{n}$                                             | $[n!]^2 = n^n$ |

### 凸函数不等式

函数$f(x)$在点$(x_0,f(x_0))$与点$(x_1,f(x_1))$此两点处的切割线函数。

$t(x) = \dfrac{x_1 - x}{x_1 - x_0} · f (x_0) + \dfrac{x - x_0}{x_1 - x_0} · f (x_1)$

| $⇓$  | $0 = T(t) ≡ \left|\begin{matrix} 1 & 1 & 1 \\ 0 & t & 1 \\ x_0 & x & x_1 \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ 0 & t & 1 \\ x_0 & x - x_0 & x_1 - x_0 \end{matrix}\right|$ | $⇒$  | $0 = T(t) ≡ t · (x_1 - x_0) - (x - x_0)$                     |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $x = (1 - t) · x_0 + t · x_1$                                | $⇒$  | $(0,x_0);(1,x_1)$                                            |
| $⇓$  | $t ≡ \dfrac{x - x_0}{x_1 - x_0}$                             |      |                                                              |
|      |                                                              |      |                                                              |
| $⇓$  | $0 = F(x) ≡ \left|\begin{matrix} 1 & 1 & 1 \\ x_0 & x & x_1 \\ f(x_0) & g(x) & f(x_1) \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ x_0 & x - x_0 & x_1 - x_0 \\ f(x_0) & g(x) - f(x_0) & f(x_1) - f (x_0) \end{matrix}\right|$ | $⇒$  | $0 = F(x) ≡ (x - x_0) · [f(x_1) - f(x_0)] - (x_1 - x_0)·[g(x) - f(x_0)]$ |
| $⇓$  | $g(x) = \dfrac{x_1 - x}{x_1 - x_0} · f (x_0) + \dfrac{x - x_0}{x_1 - x_0} · f (x_1)$ | $⇒$  | $(x_0, f(x_0));(x_1,f(x_1))$                                 |
| $⇓$  | $g\left( \dfrac{x_1 - x_0}{x_1 - x_0} · x_0 + \dfrac{x - x_0}{x_1 - x_0} · x_1 \right) = \dfrac{x_1 - x_0}{x_1 - x_0} · f(x_0) + \dfrac{x - x_0}{x_1 - x_0} · f(x_1)$ | $⇐$  | $t ≡ \dfrac{x - x_0}{x_1 - x_0}$                             |


下凸函数与上凸函数

$f[(1 - t) · x_0 + t · x_1] ≤ (1 - t) · f(x_0) + t · f(x_1)$

$f[(1 - t) · x_0 + t · x_1] ≥ (1 - t) · f(x_0) + t · f(x_1)$

### 对函数不等式

$\dfrac{x}{1 + x} \mathop{≤}\limits_{-1<x} \ln (1 + x) \mathop{≤}\limits_{-1<x} x$

$\dfrac{1}{1 + x} \mathop{≤}\limits_{0<x} \ln \left( 1 + \dfrac{1}{x} \right) \mathop{≤}\limits_{0<x} \dfrac{1}{x}$

|                                                             | $x∈(-1,+∞)$                                                  | $x∈(-1,+∞)$                                               | $x=0$                                | $x∈(+0,+∞)$                                                  |
| :---------------------------------------------------------- | :----------------------------------------------------------- | :-------------------------------------------------------- | :----------------------------------- | :----------------------------------------------------------- |
| $f (x) \mathop{≡≡≡}\limits_{-1<x} \ln (1 + x)$              | $1+θ∈(1,1+x)⊆(0, +∞)$                                        | $\dfrac{x}{1+θ}∈\left(\dfrac{x}{1+x},\dfrac{x}{1}\right)$ |                                      | $t ≡ \dfrac{1}{x}$                                           |
| $\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} = \dfrac{1}{1 + x}$ | $\dfrac{f (x) - f (0)}{x - 0} = \dfrac{\ln (1 + x)}{x} = \left. \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{∃θ∈(0,x)} = \dfrac{1}{1 + θ}$ | $\dfrac{x}{1 + x} ≤ \ln (1 + x) ≤ x$                      | $\dfrac{x}{1 + x} = \ln (1 + x) = x$ | $\dfrac{1}{1 + x} ≤ \ln \left( 1 + \dfrac{1}{x} \right) ≤ \dfrac{1}{x}$ |

### 幂函数不等式

$x^p \mathop{≤}\limits_{0≤x}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} p · x + q$

$x^p \mathop{≥}\limits_{0≤x}^{\left|p-\frac{1}{2}\right|>\frac{1}{2}} p · x + q$

| $p + q = 1$                                      | $\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} = p · (x^{p-1} - 1)$ | $f (x) = x^{p} - p · x + p - 1$                              | $0 ≤ x$               |                     | $x=1$                 |
| :----------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :-------------------- | :------------------ | :-------------------- |
| $\left| p - \dfrac{1}{2} \right| < \dfrac{1}{2}$ | $\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} = \mathop{0^+}\limits_{0<x<1};\mathop{0}\limits_{x=1};\mathop{0^-}\limits_{1<x}$ | $f (x) = \mathop{0^-}\limits_{0<x<1};\mathop{0}\limits_{x=1};\mathop{0^-}\limits_{1<x}$ | $x^p ≤ p · x + 1 - p$ | $x^{p} ≤ p · x + q$ | $x^{p} = p · x + q$   |
| $\left| p - \dfrac{1}{2} \right| > \dfrac{1}{2}$ | $\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} = \mathop{0^-}\limits_{0<x<1};\mathop{0}\limits_{x=1};\mathop{0^+}\limits_{1<x}$ | $f (x) = \mathop{0^+}\limits_{0<x<1};\mathop{0}\limits_{x=1};\mathop{0^+}\limits_{1<x}$ | $x^p ≥ p · x + 1 - p$ | $x^{p} ≥ p · x + q$ | $[p < 0] ⇒ [ 0 < x ]$ |

### 互补项不等式

$x · y \mathop{≤}\limits_{0≤x,0≤y}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} p · x^{\frac{1}{p}} + q · y^{\frac{1}{q}}$

$x · y \mathop{≥}\limits_{0≤x,0≤y}^{\left|p-\frac{1}{2}\right|>\frac{1}{2}} p · x^{\frac{1}{p}} + q · y^{\frac{1}{q}}$

| $p + q = 1$                                      | $t ≡ \dfrac{u}{v}$                                       | $0 ≤ u, 0 ≤ v$                  | $x ≡ u^{p}, y ≡v^q$                                 | $u = x^{\frac{1}{p}} ≡ y^{\frac{1}{q}} = v$         |
| :----------------------------------------------- | :------------------------------------------------------- | :------------------------------ | --------------------------------------------------- | :-------------------------------------------------- |
| $\left| p - \dfrac{1}{2} \right| < \dfrac{1}{2}$ | $\left[ \dfrac{u}{v} \right]^{p} ≤ p · \dfrac{u}{v} + q$ | $u^{p} · v^{q} ≤ p · u + q · v$ | $x · y ≤ p · x^{\frac{1}{p}} + q · y^{\frac{1}{q}}$ | $x · y = p · x^{\frac{1}{p}} + q · y^{\frac{1}{q}}$ |
| $\left| p - \dfrac{1}{2} \right| > \dfrac{1}{2}$ | $\left[ \dfrac{u}{v} \right]^p ≥ p · \dfrac{u}{v} + q$   | $u^{p} · v^{q} ≥ p · u + q · v$ | $x · y ≥ p · x^{\frac{1}{p}} + q · y^{\frac{1}{q}}$ | $[p < 0] ⇒ [ 0 < x · y ]$                           |

### 向量积不等式

$\sum\limits_{i=0}^{n} x_i · y_i \mathop{≤}\limits_{0≤x_i,0≤y_i}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} · \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}$

$\sum\limits_{i=0}^{n} x_i · y_i \mathop{≥}\limits_{0≤x_i,0≤y_i}^{\left|p-\frac{1}{2}\right|>\frac{1}{2}} \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} · \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}$

| $p + q = 1$                                      | $u_i ≡ \dfrac{x_i}{\left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p}}, v_i ≡ \dfrac{y_i}{\left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}}$ | $0 ≤ x_i, 0 ≤ y_i$                                           | $x_i^{\frac{1}{p}} ≡ λ · y_i^{\frac{1}{q}}$                  |
| :----------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\left| p - \dfrac{1}{2} \right| < \dfrac{1}{2}$ | $\sum\limits_{i=0}^{n} \dfrac{x_i}{\left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p}} · \dfrac{y_i}{\left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}} ≤ p · \sum\limits_{i=0}^{n} \dfrac{x_i^{\frac{1}{p}}}{\sum\limits_{i=0}^{n} x_i^{\frac{1}{p}}} + q · \sum\limits_{i=0}^{n} \dfrac{y_i^{\frac{1}{q}}}{\sum\limits_{i=0}^{n} y_i^{\frac{1}{q}}} = 1$ | $\sum\limits_{i=0}^{n} x_i · y_i ≤ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} · \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}$ | $\sum\limits_{i=0}^{n} x_i · y_i = \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} · \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}$ |
| $\left| p - \dfrac{1}{2} \right| > \dfrac{1}{2}$ | $\sum\limits_{i=0}^{n} \dfrac{x_i}{\left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p}} · \dfrac{y_i}{\left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}} ≥ p · \sum\limits_{i=0}^{n} \dfrac{x_i^{\frac{1}{p}}}{\sum\limits_{i=0}^{n} x_i^{\frac{1}{p}}} + q · \sum\limits_{i=0}^{n} \dfrac{y_i^{\frac{1}{q}}}{\sum\limits_{i=0}^{n} y_i^{\frac{1}{q}}} = 1$ | $\sum\limits_{i=0}^{n} x_i · y_i ≥ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} · \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}$ | $[p < 0] ⇒ [ 0 < x_i · y_i ]$                                |

### 拓扑距不等式

$\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p} \mathop{≤}\limits_{0≤x_i,0≤y_i}^{\left|p- \frac{1}{2}\right|<\frac{1}{2}} \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p}$

$\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p} \mathop{≥}\limits_{0≤x_i,0≤y_i}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p}$

| $p + q = 1$                                      | $\sum\limits_{i=0}^{n} (x_{i} + y_{i})^{\frac{1}{p}} = \sum\limits_{i=0}^{n} x_{i} · (x_{i} + y_{i})^{\frac{1}{p} - 1} + \sum\limits_{i=0}^{n} y_{i} · (x_{i} + y_{i})^{\frac{1}{p} - 1}$ | $\left( \dfrac{1}{p} - 1 \right) · \dfrac{1}{q} = \dfrac{1}{p}$ | $x_i ≡ λ · y_i$                                              |
| :----------------------------------------------- | :----------------------------------------------------------- | ------------------------------------------------------------ | :----------------------------------------------------------- |
| $\left| p - \dfrac{1}{2} \right| < \dfrac{1}{2}$ | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p+q} ≤ \left[ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p} \right] · \left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\left( \frac{1}{p} - 1 \right) · \frac{1}{q}} \right]^{q}$ | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p} ≤ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p}$ | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p} = \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p}$ |
| $\left| p - \dfrac{1}{2} \right| > \dfrac{1}{2}$ | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p+q} ≥ \left[ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p} \right] · \left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\left( \frac{1}{p} - 1 \right) · \frac{1}{q}} \right]^{q}$ | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p} ≥ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p}$ | $[p < 0] ⇒ [ 0 < x_i · y_i ]$                                |

