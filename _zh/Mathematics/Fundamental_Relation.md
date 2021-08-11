---
layout:  zh_post
Topic :  收敛极限
Title :  基本关系式
Update:  2021-08-10T18:44:00+08@中国-广东-湛江+08
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

$(y + x)^{n} = \sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · y^{n-i} · x^{i}$

|               $(y + x)^{0}$ | $1$                                                          |
| --------------------------: | ------------------------------------------------------------ |
|               $(y + x)^{1}$ | $y^{1} · x^{0} + y^{0} · x^{1}$                              |
|               $(y + x)^{n}$ | $\sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · y^{n - i} · x^{i}$ |
| $(y + x)^{1} · (y + x)^{n}$ | $\sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · \left[ y^{n-i+1} · x^{i} + y^{n-i} · x^{i+1} \right]$ |
|                             | $y^{n+1} · x^{0} + \left[ \sum\limits_{i=1}^{n} \dfrac{n!}{i! · (n - i)!} y^{n-i+1} · x^{i}  +  \sum\limits_{i=1}^{n} \dfrac{n!}{(i - 1)! · (n - i + 1)!} · y^{n-(i-1)} · x^{i} \right] + y^{0} · x^{n+1}$ |
|                             | $y^{n+1} · x^{0} + \left[ \sum\limits_{i=1}^{n} \dfrac{(n + 1)!}{i! · (n + 1 - i)!} · y^{n+1-i} · x^{i} \right] + y^{0} · x^{n+1}$ |
|             $(y + x)^{n+1}$ | $\sum\limits_{i=0}^{n+1} \dfrac{(n + 1)!}{i! · (n + 1 - i)!} · y^{n-i+1} · x^{i}$ |

### 等比恒等式

$y^{n+1} - x^{n+1} = (y - x) · \sum\limits_{i=0}^{n} y^{n-i} · x^{i}$

$\dfrac{1 - x^{n+1}}{1 - x} = \sum\limits_{i=0}^{n} x^{i}$

|          $y^{n+1} - x^{n+1}$ | $(y - x) · \sum\limits_{i=0}^{n} y^{n-i} · x^{i} = \sum\limits_{i=0}^{n} y^{n-i+1} · x^{i} - \sum\limits_{i=0}^{n} y^{n-i} · x^{i+1} = y^{n+1} + \left[ \sum\limits_{i=1}^{n} y^{n-i+1} · x^{i} - \sum\limits_{i=1}^{n} y^{n-(i-1)} · x^{i} \right] - x^{n+1} = y^{n+1} - x^{n+1}$ |
| ---------------------------: | :----------------------------------------------------------- |
|                $1 - x^{n+1}$ | $(1 - x) · \sum\limits_{i=0}^{n} x^{i}$                      |
| $\dfrac{1 - x^{n+1}}{1 - x}$ | $\sum\limits_{i=0}^{n} x^{i}$                                |

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

### 复数恒等式

$ә^{x} = \cosh x + \sinh x$

$ә^{τ·x} = \cos x + τ · \sin x$

$ә^{+τ·k·π} = (-1)^k$

$ә^{+τ·(k·π+\frac{π}{2})} = (-1)^{k} · τ$

| $\cosh x = \sum\limits_{i=0}^{∞^{+}} \dfrac{1}{(2 · i)!} · x^{2 · i}$ | $\sinh x = \sum\limits_{i=0}^{∞^{+}} \dfrac{1}{(2 · i + 1)!} · x^{2 · i + 1}$ |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| $ә^{x} = \cosh x + \sinh x$                                  | $ә^{x} = \sum\limits_{i=0}^{∞^{+}} \dfrac{1}{i!} · x^i = \sum\limits_{i=0}^{∞^{+}} \dfrac{1}{(2 · i)!} · x^{2 · i} + \sum\limits_{i=0}^{∞^{+}} \dfrac{1}{(2 · i + 1)!} · x^{2 · i + 1}$ |
|                                                              |                                                              |
| $\cos x = \sum\limits_{i=0}^{∞^{+}} \dfrac{(-1)^i}{(2 · i)!} · x^{2 · i}$ | $\sin x = \sum\limits_{i=0}^{∞^{+}} \dfrac{(-1)^{i}}{(2 · i + 1)!} · x^{2 · i + 1}$ |
| $ә^{τ·x} = \cos x + τ · \sin x$                              | $ә^{τ·x} = \sum\limits_{i=0}^{∞^{+}} \dfrac{τ^{i}}{i!} · x^i = \sum\limits_{i=0}^{∞^{+}} \dfrac{(-1)^i}{(2 · i)!} · x^{2 · i} + τ · \sum\limits_{i=0}^{∞^{+}} \dfrac{(-1)^{i}}{(2 · i + 1)!} · x^{2 · i + 1}$ |
| $ә^{+τ·k·π} = (-1)^k$                                        | $ә^{+τ·(k·π+\frac{π}{2})} = (-1)^{k} · τ$                    |

------

### 阶乘方不等式

$n! \mathop{≡≡}\limits^{0!≡1} n · (n - 1)!$

$[n!]^2 ≥ n^{n}$

$\left( \dfrac{n + 1}{ә} \right)^{n} < n! < (n + 1) · \left( \dfrac{n + 1}{ә} \right)^{n}$

| $n ≥ i+ 1$                                                   | $n ≥ i + 1$                                                  | $n = 1,2$                                                    |
| :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $(n - i) · (i + 1) - n = i · [n - (i + 1)] ≥ 0$              | $[n!]^{2} = [(n - 0) · 1] · [(n - 1) · 2] ··· [2 · (n - 1)] · [1 · (n - 0)]$ |                                                              |
| $(n - i) · (i + 1) ≥ n$                                      | $[n!]^2 ≥ n^{n}$                                             | $[n!]^2 = n^n$                                               |
|                                                              |                                                              |                                                              |
| $\dfrac{(n + 1)^{n}}{n^{n}} = \left( 1 + \dfrac{1}{n} \right)^{n} < ә < \left( 1 + \dfrac{1}{n} \right)^{n+1} = \dfrac{(n + 1)^{n+1}}{n^{n+1}}$ | $\dfrac{(n + 1)^{n}}{n!} = \prod\limits_{i=1}^{n} \dfrac{(n + 1)^{n}}{n^{n}} < ә^{n} < \prod\limits_{i=1}^{n} \dfrac{(n + 1)^{n+1}}{n^{n+1}} = \dfrac{(n + 1)^{n+1}}{n!}$ | $\left( \dfrac{n + 1}{ә} \right)^{n} < n! < (n + 1) · \left( \dfrac{n + 1}{ә} \right)^{n}$ |

### 凹函数不等式

函数$f(x)$在点$(x_0,f(x_0))$与点$(x_1,f(x_1))$此两点处的切割线函数。

$g(x) = \dfrac{x_1 - x}{x_1 - x_0} · f (x_0) + \dfrac{x - x_0}{x_1 - x_0} · f (x_1)$

$g[(1 - t) · x_0 + t · x_1] = (1 - t) · f(x_0) + t · f(x_1)$

| $⇓$  | $0 = T(t) ≡ \left|\begin{matrix} 1 & 1 & 1 \\ 0 & t & 1 \\ x_0 & x & x_1 \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ 0 & t & 1 \\ x_0 & x - x_0 & x_1 - x_0 \end{matrix}\right|$ | $⇒$  | $0 = T(t) ≡ t · (x_1 - x_0) - (x - x_0)$                     |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $x = (1 - t) · x_0 + t · x_1$                                | $⇒$  | $(t, x(t)) = (0,x_0);(1,x_1)$                                |
| $⇓$  | $t = \dfrac{x - x_0}{x_1 - x_0}$                             | $⇒$  | $1 - t = \dfrac{x_1 - x}{x_1 - x_0}$                         |
|      |                                                              |      |                                                              |
| $⇓$  | $0 = F(x) ≡ \left|\begin{matrix} 1 & 1 & 1 \\ x_0 & x & x_1 \\ f(x_0) & g(x) & f(x_1) \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ x_0 & x - x_0 & x_1 - x_0 \\ f(x_0) & g(x) - f(x_0) & f(x_1) - f (x_0) \end{matrix}\right|$ | $⇒$  | $0 = F(x) ≡ (x - x_0) · [f(x_1) - f(x_0)] - (x_1 - x_0)·[g(x) - f(x_0)]$ |
| $⇓$  | $g(x) = \dfrac{x_1 - x}{x_1 - x_0} · f (x_0) + \dfrac{x - x_0}{x_1 - x_0} · f (x_1)$ | $⇒$  | $(x, f (x)) = (x_0, f(x_0));(x_1,f(x_1))$                    |
| $⇓$  | $g[(1 - t) · x_0 + t · x_1] = (1 - t) · f(x_0) + t · f(x_1)$ |      |                                                              |

凹函数的运算性质。凸函数的运算性质完全类似。

$f(x) \mathop{≤}\limits^{x_0≤x≤x_1} \dfrac{x_1 - x}{x_1 - x_0} · f(x_0) + \dfrac{x - x_0}{x_1 - x_0} · f(x_1)$

$\dfrac{f(x) - f (x_0)}{x - x_0} ≤ \dfrac{f(x_1) - f(x_0)}{x_1 - x_0} ≤ \dfrac{f(x_1) - f(x)}{x_1 - x}$

$\left.\dfrac{\mathrm{d} f(x)}{\mathrm{d} x}\right|_{x_0^{+}} ≤ \dfrac{f(x_1) - f(x_0)}{x_1 - x_0} ≤ \left.\dfrac{\mathrm{d} f(x)}{\mathrm{d} x}\right|_{x_1^{-}}$

$\dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = \dfrac{\mathrm{d^2 f(x)}}{\mathrm{d}^2 x} ≥ 0$

$f(x) ≥ f(x_0) + \left.\dfrac{\mathrm{d} f(x)}{\mathrm{d} x}\right|_{x_0} · (x - x_0)$

| $⇓$  |                                                $f(x) ≤ g(x)$ | $⇒$  | $f(x) ≤ \dfrac{x_1 - x}{x_1 - x_0} · f(x_0) + \dfrac{x - x_0}{x_1 - x_0} · f(x_1)$ |      |                                                 |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- | :--: | ----------------------------------------------- |
| $⇓$  | $\dfrac{f(x) - f (x_0)}{x - x_0} ≤ \dfrac{f(x_1) - f(x_0)}{x_1 - x_0}$ | $⇐$  | $f(x) - f(x_0) ≤ \left[\dfrac{x_1 - x}{x_1 - x_0} · f(x_0) - f(x_0)\right] + \dfrac{x - x_0}{x_1 - x_0} · f(x_1) = \dfrac{x - x_0}{x_1 - x_0} · [f(x_1) - f(x_0)]$ |      |                                                 |
| $⇓$  | $\dfrac{f(x_1) - f(x_0)}{x_1 - x_0} ≤ \dfrac{f(x_1) - f(x)}{x_1 - x}$ | $⇐$  | $f(x_1) - f(x) ≥ -\dfrac{x_1 - x}{x_1 - x_0} · f(x_0) + \left[ f(x_1) - \dfrac{x - x_0}{x_1 - x_0} · f(x_1) \right] = \dfrac{x_1 - x}{x_1 - x_0} · [f(x_1) - f(x_0)]$ |      |                                                 |
| $⇓$  |                                                              |      | $\lim\limits_{x⇝x_0^+} \dfrac{f (x) - f (x_0)}{x - x_0} = \left.\dfrac{\mathrm{d} f(x)}{\mathrm{d} x}\right|_{x_0^{+}} ≤ \dfrac{f(x_1) - f(x_0)}{x_1 - x_0} ≤ \left.\dfrac{\mathrm{d} f(x)}{\mathrm{d} x}\right|_{x_1^{-}} = \lim\limits_{x⇝x_0^-} \dfrac{f (x_1) - f (x)}{x_1 - x}$ | $⇔$  | $\dfrac{\mathrm{d^2 f(x)}}{\mathrm{d}^2 x} ≥ 0$ |
| $⇓$  | $f(x) ≥ f(x_0) + \left.\dfrac{\mathrm{d} f(x)}{\mathrm{d} x}\right|_{x_0} · (x - x_0)$ | $⇐$  | $\left[ f(x) - f(x_0) ≥ \left.\dfrac{\mathrm{d} f(x)}{\mathrm{d} x}\right|_{x_0^+} · (x - x_0) \right] ∧ \left[ f(x_1) - f(x) ≤ \left.\dfrac{\mathrm{d} f(x)}{\mathrm{d} x}\right|_{x_1^-} · (x_1 - x) \right]$ |      |                                                 |
|      |                                                              |      |                                                              |      |                                                 |
| $⇓$  | $f(x) ≤ \dfrac{x_1 - x}{x_1 - x_0} · f(x_0) + \dfrac{x - x_0}{x_1 - x_0} · f(x_1)$ | $⇐$  | $f(x) = \dfrac{x_1 - x}{x_1 - x_0} · \left[ f(x) + \left.\dfrac{\mathrm{d} f(x)}{\mathrm{d} x}\right|_{x} · (x_0 - x) \right] + \dfrac{x - x_0}{x_1 - x_0} · \left[ f(x) + \left.\dfrac{\mathrm{d} f(x)}{\mathrm{d} x}\right|_{x} · (x_1 - x) \right]$ |      |                                                 |

凹区间满足$\dfrac{\mathrm{d}^2 f(x)}{\mathrm{d}^2 x} ≥ 0$，凸区间满足$\dfrac{\mathrm{d}^2 f(x)}{\mathrm{d}^2 x} ≤ 0$。凹区间与凸区间的分界点称为拐点，此点处满足$\dfrac{\mathrm{d}^2 f(x)}{\mathrm{d}^2 x} = 0$，反之不对。

典例：函数$f(x) = x^{3}$的二阶导函数为$\dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x} = 6 · x$，凹区间为$[0⁺, ∞⁺)$，凸区间为$(∞⁻, 0⁻]$，拐点为$x = 0$。

典例：函数$f(x) = x^{4}$的二阶导函数为$\dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x} = 12 · x^{2}$，凹区间为$(∞⁻, ∞⁺)$，无凸区间，无拐点，但$\left.\dfrac{\mathrm{d}^2 f(x)}{\mathrm{d}^2 x}\right|_{x=0} = 0$。

凹函数不等式。凸函数不等式完全类似。

$f\left[ \sum\limits_{i=0}^{n} t_i · x_i \right] \mathop{≤}\limits_{\sum\limits_{i=0}^{n} t_i =1}^{0≤t_i≤1} \sum\limits_{i=0}^{n} t_i · f(x_i)$

$f\left[ \sum\limits_{i=0}^{n} \dfrac{t_i · x_i}{\sum\limits_{i=0}^{n} t_i} \right] \mathop{≤}\limits^{0≤t_i} \sum\limits_{i=0}^{n} \dfrac{t_i · f(x_i)}{\sum\limits_{i=0}^{n} t_i}$

| $⇓$  |                                                    $t_0 = 1$ | $f (t_0 · x_0) ≤ t_0 · f(x_0)$                               |
| :--: | -----------------------------------------------------------: | :----------------------------------------------------------- |
| $⇓$  |                                              $t_0 + t_1 = 1$ | $f(t_0 · x_0 + t_1 · x_1) ≤ t_0 · f(x_0) + t_1 · f(x_1) = g(t_0 · x_0 + t_1 · x_1)$ |
| $⇓$  |                              $\sum\limits_{i=0}^{n} t_i = 1$ | $f\left[ \sum\limits_{i=0}^{n} t_i · x_i \right] ≤ \sum\limits_{i=0}^{n} t_i · f(x_i)$ |
| $⇓$  |                            $\sum\limits_{i=0}^{n+1} t_i = 1$ | $f\left[ \sum\limits_{i=0}^{n+1} t_i · x_i \right] = f\left[ (1 - t_{n+1}) · \sum\limits_{i=0}^{n} \dfrac{t_i}{1 - t_{n+1}} · x_i + t_{n+1} · x_{n+1} \right]$ |
| $⇓$  | $\dfrac{1 - t_{n+1}}{1 - t_{n+1}} = \sum\limits_{i=0}^{n} \dfrac{t_i}{1 - t_{n+1}} = 1$ | $f\left[ \sum\limits_{i=0}^{n+1} t_i · x_i \right] ≤ (1 - t_{n+1}) · f\left[ \sum\limits_{i=0}^{n} \dfrac{t_i}{1 - t_{n+1}} · x_i \right] + t_{n+1} · f(x_{n+1}) ≤ (1 - t_{n+1}) · \sum\limits_{i=0}^{n} \dfrac{t_i}{1 - t_{n+1}} · f(x_i) + t_{n+1} · f(x_{n+1}) = \sum\limits_{i=0}^{n+1} t_i · f(x_i)$ |
|      |                                                              |                                                              |
| $⇓$  | $\sum\limits_{i=0}^{n} \dfrac{t_i}{\sum\limits_{i=0}^{n} t_i} = 1$ | $f\left[ \sum\limits_{i=0}^{n} \dfrac{t_i · x_i}{\sum\limits_{i=0}^{n} t_i} \right] \mathop{≤}\limits^{0≤t_i} \sum\limits_{i=0}^{n} \dfrac{t_i · f(x_i)}{\sum\limits_{i=0}^{n} t_i}$ |
|      | $\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \mathop{=====}\limits^{f(x_i)≡g(x_i)} \mathrm{Con}$ | $f\left[ \sum\limits_{i=0}^{n} \dfrac{t_i · x_i}{\sum\limits_{i=0}^{n} t_i} \right] \mathop{==}\limits^{0≤t_i} \sum\limits_{i=0}^{n} \dfrac{t_i · f(x_i)}{\sum\limits_{i=0}^{n} t_i}$ |

### 权均值不等式

$\prod\limits_{i=0}^{n} x_i^{t_i} \mathop{≤}\limits_{0<x_i}^{0<p} \left[ \sum\limits_{i=0}^{n} t_i · x_i^{\frac{1}{p}} \right]^{p}$

$\prod\limits_{i=0}^{n} x_i^{t_i} \mathop{≥}\limits_{0<x_i}^{p<0} \left[ \sum\limits_{i=0}^{n} t_i · x_i^{\frac{1}{p}} \right]^{p}$

$\sum\limits_{i=0}^{n} t_i · x_i \mathop{≤}\limits_{0≤x_i}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} \left[ \sum\limits_{i=0}^{n} t_i · x_i^{\frac{1}{p}} \right]^{p}$

$\sum\limits_{i=0}^{n} t_i · x_i \mathop{≥}\limits_{0≤x_i}^{\left|p-\frac{1}{2}\right|>\frac{1}{2}} \left[ \sum\limits_{i=0}^{n} t_i · x_i^{\frac{1}{p}} \right]^{p}$

$x_n^{↘} = \inf\limits_{i} x_i \mathop{≤}\limits_{0<x_i} \mathop{\left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} x_i^{-1} \right]^{-1}}\limits^{\mathrm{Harmonic\underline{}Mean}} \mathop{≤}\limits_{0<x_i} \mathop{\left[ \prod\limits_{i=0}^{n} x_i \right]^{\frac{1}{n+1}}}\limits^{\mathrm{Geometric\underline{}Mean}} \mathop{≤}\limits_{0<x_i} \mathop{\left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} x_i^{+1} \right]^{+1}}\limits^{\mathrm{Arithmetic\underline{}Mean}} \mathop{≤}\limits_{0≤x_i} \mathop{\left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} x_i^{2} \right]^{\frac{1}{2}}}\limits^{\mathrm{Quadratic\underline{}Mean}} \mathop{≤}\limits_{0≤x_i} \sup\limits_{i} x_i = x_n^{↗}$

$\dfrac{s_n^{↘}}{\mathop{\mathrm{ave}}\limits_{i} t_i} = \dfrac{\inf\limits_{i} s_i}{\mathop{\mathrm{ave}}\limits_{i} t_i} ≤ \dfrac{\mathop{\mathrm{ave}}\limits_{i} s_i}{\mathop{\mathrm{ave}}\limits_{i} t_i} ≤ \dfrac{\mathop{\mathrm{ave}}\limits_{i} s_i}{\inf\limits_{i} t_i} = \dfrac{\mathop{\mathrm{ave}}\limits_{i} s_i}{t_n^{↘}}$

$\dfrac{\mathop{\mathrm{ave}}\limits_{i} s_i}{t_n^{↗}} = \dfrac{\mathop{\mathrm{ave}}\limits_{i} s_i}{\sup\limits_{i} t_i} ≤ \dfrac{\mathop{\mathrm{ave}}\limits_{i} s_i}{\mathop{\mathrm{ave}}\limits_{i} t_i} ≤ \dfrac{\sup\limits_{i} s_i}{\mathop{\mathrm{ave}}\limits_{i} t_i} = \dfrac{s_n^{↗}}{\mathop{\mathrm{ave}}\limits_{i} t_i}$

| $f(x) \mathop{≡≡}\limits_{0<x} \ln x$            | $\dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x} = -\dfrac{1}{x^{2}} < 0$ | $\dfrac{\mathrm{d}^{1} f(x)}{\mathrm{d}^{1} x} = +\dfrac{1}{x^{1}} > 0$ | $x_i ≡ x$                                                    | $\sum\limits_{i=0}^{n} t_i \mathop{===}\limits_{0≤t_i≤1} 1$  |
| :----------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $0 < p$                                          | $\ln \left[ \sum\limits_{i=0}^{n} t_i · x_i^{\frac{1}{p}} \right]^{p} = p · \ln \left[ \sum\limits_{i=0}^{n} t_i · x_i^{\frac{1}{p}} \right] ≥ p · \sum\limits_{i=0}^{n} t_i · \ln x_i^{\frac{1}{p}} = \ln \prod\limits_{i=0}^{n} x_i^{t_i}$ | $\prod\limits_{i=0}^{n} x_i^{t_i} \mathop{≤}\limits_{0<x_i}^{0<p} \left[ \sum\limits_{i=0}^{n} t_i · x_i^{\frac{1}{p}} \right]^{p}$ | $\prod\limits_{i=0}^{n} x_i^{t_i} \mathop{=}\limits_{0<x}^{0<p} \left[ \sum\limits_{i=0}^{n} t_i · x_i^{\frac{1}{p}} \right]^{p}$ | $\left[ \prod\limits_{i=0}^{n} x_i \right]^{\frac{1}{n + 1}} \mathop{≤}\limits_{0<x_i}^{0<p} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p}$ |
| $p < 0$                                          | $\ln \left[ \sum\limits_{i=0}^{n} t_i · x_i^{\frac{1}{p}} \right]^{p} = p · \ln \left[ \sum\limits_{i=0}^{n} t_i · x_i^{\frac{1}{p}} \right] ≤ p · \sum\limits_{i=0}^{n} t_i · \ln x_i^{\frac{1}{p}} = \ln \prod\limits_{i=0}^{n} x_i^{t_i}$ | $\prod\limits_{i=0}^{n} x_i^{t_i} \mathop{≥}\limits_{0<x_i}^{p<0} \left[ \sum\limits_{i=0}^{n} t_i · x_i^{\frac{1}{p}} \right]^{p}$ |                                                              | $\left[ \prod\limits_{i=0}^{n} x_i \right]^{\frac{1}{n + 1}} \mathop{≥}\limits_{0<x_i}^{p<0} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p}$ |
|                                                  |                                                              |                                                              |                                                              |                                                              |
| $f(x) \mathop{≡≡}\limits_{0≤x} x^{p}$            | $\dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x} = p · (p - 1) · x^{p-2} = \mathop{-0}\limits_{\left|p-\frac{1}{2}\right|<\frac{1}{2}};\mathop{+0}\limits_{\left|p-\frac{1}{2}\right|>\frac{1}{2}}$ | $x_i ≡ u_i^{p}$                                              | $x_i ≡ x$                                                    | $\sum\limits_{i=0}^{n} t_i \mathop{===}\limits_{0≤t_i≤1} 1$  |
| $\left| p - \dfrac{1}{2} \right| < \dfrac{1}{2}$ | $\left[ \sum\limits_{i=0}^{n} t_i · u_i \right]^{p} ≥ \sum\limits_{i=0}^{n} t_i · u_i^{p}$ | $\sum\limits_{i=0}^{n} t_i · x_i \mathop{≤}\limits_{0≤x_i}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} \left[ \sum\limits_{i=0}^{n} t_i · x_i^{\frac{1}{p}} \right]^{p}$ | $\sum\limits_{i=0}^{n} t_i · x_i \mathop{=}\limits_{0≤x}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} \left[ \sum\limits_{i=0}^{n} t_i · x_i^{\frac{1}{p}} \right]^{p}$ | $\dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} x_i \mathop{≤}\limits_{0≤x_i}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p}$ |
| $\left| p - \dfrac{1}{2} \right| > \dfrac{1}{2}$ | $\left[ \sum\limits_{i=0}^{n} t_i · u_i \right]^{p} ≤ \sum\limits_{i=0}^{n} t_i · u_i^{p}$ | $\sum\limits_{i=0}^{n} t_i · x_i \mathop{≥}\limits_{0≤x_i}^{\left|p-\frac{1}{2}\right|>\frac{1}{2}} \left[ \sum\limits_{i=0}^{n} t_i · x_i^{\frac{1}{p}} \right]^{p}$ | $[p < 0] ⇒ [ 0 < x_i ]$                                      | $\dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} x_i \mathop{≥}\limits_{0≤x_i}^{\left|p-\frac{1}{2}\right|>\frac{1}{2}} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p}$ |

### 对函数不等式

$\dfrac{x}{1 + x} \mathop{≤}\limits_{x>-1} \ln (1 + x) \mathop{≤}\limits_{x>-1} x$

$\dfrac{α}{x + α} \mathop{≤}\limits_{x·(x+α)>0} \ln\left( 1 + \dfrac{α}{x} \right) \mathop{≤}\limits_{x·(x+α)>0} \dfrac{α}{x}$

$\dfrac{α}{1 + \dfrac{α}{x}} \mathop{≤}\limits_{x>0}^{x>-α} \ln\left( 1 + \dfrac{α}{x} \right)^{x} \mathop{≤}\limits_{x>0}^{x>-α} α$

$\dfrac{α}{1 + \dfrac{α}{x}} \mathop{≥}\limits_{x<0}^{x<-α} \ln\left( 1 + \dfrac{α}{x} \right)^{x} \mathop{≥}\limits_{x<0}^{x<-α} α$

$\dfrac{α}{x} \mathop{≤}\limits_{x·(x+α)>0} \ln\left( 1 + \dfrac{α}{x} \right)^{1+\frac{α}{x}} \mathop{≤}\limits_{x·(x+α)>0} \dfrac{α}{x} · \left( 1 + \dfrac{α}{x} \right)$

|                                                              | $x∈(-1,+∞)$                                                  | $x∈(-1,+∞)$                                                  | $x=0$                                                        |
| :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $f (x) \mathop{≡≡≡}\limits_{-1<x} \ln (1 + x)$               | $1+θ∈(1,1+x)⊆(0, +∞)$                                        | $\dfrac{x}{1+θ}∈\left(\dfrac{x}{1+x},\dfrac{x}{1}\right)$    |                                                              |
| $\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} = \dfrac{1}{1 + x} > 0$ | $\dfrac{f (x) - f (0)}{x - 0} = \dfrac{\ln (1 + x)}{x} = \left. \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{∃θ∈(0,x)} = \dfrac{1}{1 + θ} > 0$ | $\dfrac{1}{1 + \dfrac{1}{x}} = \dfrac{x}{1 + x} \mathop{≤}\limits_{x>-1} \ln (1 + x) \mathop{≤}\limits_{x>-1} x$ | $\dfrac{1}{1 + \dfrac{1}{x}} = \dfrac{x}{1 + x} \mathop{=}\limits_{x=0} \ln (1 + x) \mathop{=}\limits_{x=0} x$ |
|                                                              |                                                              |                                                              |                                                              |
| $t \mathop{≡≡≡≡≡}\limits_{x·(x+α)>0}^{\frac{α}{x}>-1} \dfrac{α}{x}$ | $\dfrac{α}{x} · \dfrac{1}{1 + \dfrac{α}{x}} = \dfrac{α}{x + α} \mathop{≤}\limits_{x·(x+α)>0} \ln\left( 1 + \dfrac{α}{x} \right) \mathop{≤}\limits_{x·(x+α)>0} \dfrac{α}{x}$ | $\dfrac{α}{x} \mathop{≤}\limits_{x·(x+α)>0} \ln\left( 1 + \dfrac{α}{x} \right)^{1+\frac{α}{x}} \mathop{≤}\limits_{x·(x+α)>0} \dfrac{α}{x} · \left( 1 + \dfrac{α}{x} \right)$ | $α = 0$                                                      |
| $x > 0$                                                      | $\dfrac{α}{1 + \dfrac{α}{x}} \mathop{≤}\limits_{x>0}^{x>-α} \ln\left( 1 + \dfrac{α}{x} \right)^{x} \mathop{≤}\limits_{x>0}^{x>-α} α$ |                                                              | $\dfrac{α}{1 + \dfrac{α}{x}} \mathop{=}\limits_{x>0}^{α=0} \ln\left( 1 + \dfrac{α}{x} \right)^{x} \mathop{=}\limits_{x>0}^{α=0} α$ |
| $x < 0$                                                      | $\dfrac{α}{1 + \dfrac{α}{x}} \mathop{≥}\limits_{x<0}^{x<-α} \ln\left( 1 + \dfrac{α}{x} \right)^{x} \mathop{≥}\limits_{x<0}^{x<-α} α$ |                                                              | $\dfrac{α}{1 + \dfrac{α}{x}} \mathop{=}\limits_{x<0}^{α=0} \ln\left( 1 + \dfrac{α}{x} \right)^{x} \mathop{=}\limits_{x<0}^{α=0} α$ |

### 幂函数不等式

$x^p \mathop{≤}\limits_{0≤x}^{\left|p-\frac{1}{2}\right|≤\frac{1}{2}} p · x + q$

$x^p \mathop{≥}\limits_{0≤x}^{\left|p-\frac{1}{2}\right|≥\frac{1}{2}} p · x + q$

$(1 + x)^{p} \mathop{≤}\limits_{-1≤x}^{\left|p-\frac{1}{2}\right|≤\frac{1}{2}} 1 + p · x$

$(1 + x)^{p} \mathop{≥}\limits_{-1≤x}^{\left|p-\frac{1}{2}\right|≥\frac{1}{2}} 1 + p · x$

| $p + q = 1$                                      | $\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} = p · (x^{p-1} - 1)$ | $f (x) = x^{p} - p · x + p - 1$                              | $0 ≤ x$               |                     | $x=1$                 | $t \mathop{≡≡≡}\limits_{-1≤x}^{0≤t} x + 1$ |
| :----------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :-------------------- | :------------------ | :-------------------- | ------------------------------------------ |
| $\left| p - \dfrac{1}{2} \right| ≤ \dfrac{1}{2}$ | $\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} = \mathop{+0}\limits_{0<x<1};\mathop{0}\limits_{x=1};\mathop{-0}\limits_{1<x}$ | $f (x) = \mathop{-0}\limits_{0<x<1};\mathop{0}\limits_{x=1};\mathop{-0}\limits_{1<x}$ | $x^p ≤ p · x + 1 - p$ | $x^{p} ≤ p · x + q$ | $x^{p} = p · x + q$   | $(1 + x)^{p} ≤ 1 + p · x$                  |
| $\left| p - \dfrac{1}{2} \right| ≥ \dfrac{1}{2}$ | $\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} = \mathop{-0}\limits_{0<x<1};\mathop{0}\limits_{x=1};\mathop{+0}\limits_{1<x}$ | $f (x) = \mathop{+0}\limits_{0<x<1};\mathop{0}\limits_{x=1};\mathop{+0}\limits_{1<x}$ | $x^p ≥ p · x + 1 - p$ | $x^{p} ≥ p · x + q$ | $[p < 0] ⇒ [ 0 < x ]$ | $(1 + x)^{p} ≥ 1 + p · x$                  |

### 连乘积不等式

$\prod\limits_{i=0}^{n} (1 + x_i)^{p} \mathop{≥}\limits_{0≤x_i}^{1≤n,p} 1 + p · \sum\limits_{i=0}^{n} x_i + p^{n+1} · \prod\limits_{i=0}^{n} x_i$

|    $(1 + x_i)^{p} \mathop{≥}\limits^{1≤p}$ | $1 + p · x_i$                                                |                                                              |
| -----------------------------------------: | :----------------------------------------------------------- | ------------------------------------------------------------ |
|   $\prod\limits_{i=0}^{0} (1 + x_i)^{p} ≥$ | $1 + p · x_0$                                                | $≥ 1 + p · \sum\limits_{i=0}^{0} x_i$                        |
|   $\prod\limits_{i=0}^{1} (1 + x_i)^{p} ≥$ | $\left[ 1 + p · x_0 \right] · (1 + p · x_1)$                 | $≥ 1 + p · \sum\limits_{i=0}^{1} x_i + p^{2} · \prod\limits_{i=0}^{1} x_i$ |
|   $\prod\limits_{i=0}^{2} (1 + x_i)^{p} ≥$ | $\left[ 1 + p · \sum\limits_{i=0}^{1} x_i + p^{2} · \prod\limits_{i=0}^{1} x_i \right] · (1 + p · x_2)$ | $≥ 1 + p · \sum\limits_{i=0}^{2} x_i + p^{3} · \prod\limits_{i=0}^{2} x_i$ |
|   $\prod\limits_{i=0}^{n} (1 + x_i)^{p} ≥$ |                                                              | $≥ 1 + p · \sum\limits_{i=0}^{n} x_i + p^{n+1} · \prod\limits_{i=0}^{n} x_i$ |
| $\prod\limits_{i=0}^{n+1} (1 + x_i)^{p} ≥$ | $\left[ 1 + p · \sum\limits_{i=0}^{n} x_i + p^{n+1} · \prod\limits_{i=0}^{n} x_i \right] · (1 + p · x_{n+1})$ | $≥ 1 + p · \sum\limits_{i=0}^{n+1} x_i + p^{n+2} · \prod\limits_{i=0}^{n+1} x_i$ |

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

$\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p} \mathop{≥}\limits_{0≤x_i,0≤y_i}^{\left|p-\frac{1}{2}\right|>\frac{1}{2}} \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p}$

$(x + y)^{p} \mathop{≤}\limits_{0≤x,0≤y}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} x^{p} +y^{p}$

$(x + y)^{p} \mathop{≥}\limits_{0≤x,0≤y}^{\left|p-\frac{1}{2}\right|>\frac{1}{2}} x^{p} +y^{p}$

| $p + q = 1$                                      | $\sum\limits_{i=0}^{n} (x_{i} + y_{i})^{\frac{1}{p}} = \sum\limits_{i=0}^{n} x_{i} · (x_{i} + y_{i})^{\frac{1}{p} - 1} + \sum\limits_{i=0}^{n} y_{i} · (x_{i} + y_{i})^{\frac{1}{p} - 1}$ | $\left( \dfrac{1}{p} - 1 \right) · \dfrac{1}{q} = \dfrac{1}{p}$ | $x_i ≡ λ · y_i$                                              |
| :----------------------------------------------- | :----------------------------------------------------------- | ------------------------------------------------------------ | :----------------------------------------------------------- |
| $\left| p - \dfrac{1}{2} \right| < \dfrac{1}{2}$ | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p+q} ≤ \left[ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p} \right] · \left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\left( \frac{1}{p} - 1 \right) · \frac{1}{q}} \right]^{q}$ | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p} ≤ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p}$ | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p} = \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p}$ |
| $\left| p - \dfrac{1}{2} \right| > \dfrac{1}{2}$ | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p+q} ≥ \left[ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p} \right] · \left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\left( \frac{1}{p} - 1 \right) · \frac{1}{q}} \right]^{q}$ | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p} ≥ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p}$ | $[p < 0] ⇒ [ 0 < x_i · y_i ]$                                |
|                                                  |                                                              |                                                              |                                                              |
| $p + q = 1$                                      | $u_1 = 0, v_0 = 0$                                           | $x ≡ v_0^{\frac{1}{p}}, y ≡ u_1^{\frac{1}{p}}$               | $x ≡ 0, y ≡ 0$                                               |
| $\left| p - \dfrac{1}{2} \right| < \dfrac{1}{2}$ | $\left[ u_0^{\frac{1}{p}} + v_1^{\frac{1}{p}} \right]^{p} ≤ \left[ u_0^{\frac{1}{p}} \right]^{p} + \left[ v_1^{\frac{1}{p}} \right]^{p}$ | $(x + y)^{p} \mathop{≤}\limits_{0≤x,0≤y}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} x^{p} + y^{p}$ | $(x + y)^{p} \mathop{=}\limits_{0≤x,0≤y}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} x^{p} + y^{p}$ |
| $\left| p - \dfrac{1}{2} \right| > \dfrac{1}{2}$ | $\left[ u_0^{\frac{1}{p}} + v_1^{\frac{1}{p}} \right]^{p} ≥ \left[ u_0^{\frac{1}{p}} \right]^{p} + \left[ v_1^{\frac{1}{p}} \right]^{p}$ | $(x + y)^{p} \mathop{≥}\limits_{0≤x,0≤y}^{\left|p-\frac{1}{2}\right|>\frac{1}{2}} x^{p} + y^{p}$ | $[p < 0] ⇒ [ 0 < x_i · y_i ]$                                |

### 全排序不等式

若数列$\lbrace a_i : a_0 ≤ a_1 ≤ ··· ≤ a_n \rbrace$，数列$\lbrace b_i : b_0 ≤ b_1 ≤ ··· ≤ b_n \rbrace$，数列$\lbrace b_i \rbrace$有乱序数列$\lbrace p_i : p_0,p_1,···,p_n \rbrace$，则数列的乘积满足：反序和 ≤ 乱序和 ≤ 顺序和。

$a_0 · b_n + a_1 · b_{n-1} + ··· + a_n · b_0 ≤ a_0 · p_0 + a_1 · p_1 + ··· + a_n · p_n ≤ a_0 · b_0 + a_1 · b_1 + ··· + a_n · b_n$

若数列$\lbrace a_i · p_i \rbrace$中$p_0 ≠ b_0, p_j = b_0$，则将$p_0$与$p_j$对换，记对换前和为$S$，记对换后和为$T$，则$T - S = a_0·p_j + a_j·p_0 - a_0·p_0-a_j·p_j = (a_j - a_0) · (p_0 - p_j) ≥ 0$。

依此类推逐项调整，因此有乱序和 ≤ 顺序和，同理有反序和 ≤ 乱序和。