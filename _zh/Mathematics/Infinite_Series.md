---
layout:  zh_post
Topic :  收敛极限
Title :  无穷级数
Update:  2021-01-23T00:04:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 无穷级数

无穷级数的部分和

$S_n ≡ \sum\limits_{i = 1}^n s_i$

无穷级数的极限

$\lim\limits_{n ⇝ +∞} S_n ≡ \lim\limits_{n ⇝ +∞} \sum\limits_{i = 1}^{n} s_i ≡ \sum\limits_{i = 1}^{+∞} s_i$

无穷级数的下极限与上极限

$\varliminf\limits_{n ⇝ +∞} S_n ≡ \mathop{\lim\inf}\limits_{n ⇝ +∞} S_n ≡ \lim\limits_{n ⇝ +∞}\inf\limits_{m ≥ n} S_m ≡ \lim\limits_{n ⇝ +∞}\inf\limits_{m ≥ n} \sum\limits_{i = 1}^m s_i$

$\varlimsup\limits_{n ⇝ +∞} S_n ≡ \mathop{\lim\sup}\limits_{n ⇝ +∞} S_n ≡ \lim\limits_{n ⇝ +∞}\sup\limits_{m ≥ n} S_m ≡ \lim\limits_{n ⇝ +∞}\sup\limits_{m ≥ n} \sum\limits_{i = 1}^m s_i$

$\varliminf\limits_{n ⇝ +∞} S_n ≤ \varlimsup\limits_{n ⇝ +∞} S_n$

典例：无穷级数下极限与上极限

$\varliminf\limits_{n ⇝ +∞} \dfrac{1}{n} ⇝ 0, \varlimsup\limits_{n ⇝ +∞} \dfrac{1}{n} ⇝ 0$

$\varliminf\limits_{n ⇝ +∞} \sin\dfrac{n · \pi}{4} ⇝ -1, \varlimsup\limits_{n ⇝ +∞} \sin\dfrac{n · \pi}{4} ⇝ +1$

无穷级数的极限之等价表述形式

$∀ε>0;∃N∈ℕ;∀n>N; |S_n - S| < ε$

$∀ε>0;∃N∈ℕ;∀n>N; \left| \sum\limits_{i = 1}^{n} s_i - S \right| < ε$

无穷级数的极限收敛

$\lim\limits_{n ⇝ +∞} S_n ⇝ S$ 也即 $\lim\limits_{n → +∞} |S_n - S| ⇝ 0$

$\sum\limits_{i = 1}^{+∞} s_i ⇝ S$ 也即 $\left| \sum\limits_{i = 1}^{+∞} s_i - S \right| ⇝ 0$

$\varliminf\limits_{n ⇝ +∞} S_n = \lim\limits_{n ⇝ +∞} S_n = \varlimsup\limits_{n ⇝ +∞} S_n$

无穷级数的极限发散

$\lim\limits_{n ⇝ +∞} S_n \not⇝ S$ 也即 $\lim\limits_{n ⇝ +∞} |S_n - S| \not⇝ 0$

$\sum\limits_{i = 1}^{+∞} s_i \not⇝ S$ 也即 $\left| \sum\limits_{i = 1}^{+∞} s_i - S \right| \not⇝ 0$

$\varliminf\limits_{n ⇝ +∞} S_n ≠ \varlimsup\limits_{n ⇝ +∞} S_n$

### 无穷级数收敛的性质

若无穷级数收敛，则其通项的极限为零。

$\lim\limits_{n ⇝ +∞} S_n ⇝ S ⇒ \lim\limits_{i ⇝ +∞} s_i ⇝ 0$

若通项的极限不为零，则无穷级数发散。

$\lim\limits_{i ⇝ +∞} s_i \not⇝ 0 ⇒ \lim\limits_{n ⇝ +∞} S_n \not⇝ S$

无穷级数满足加运算。

$c · \sum\limits_{i = 1}^{n} s_i = \sum\limits_{i = 1}^{n} (c · s_i)$

$\sum\limits_{i = 1}^{n} (s_i ± t_i) = \sum\limits_{i = 1}^{n} s_i ± \sum\limits_{i = 1}^{n} t_i$

将无穷级数的有限多项改变，其敛散性不变。

$\sum\limits_{i = n}^{+∞} s_i ⇝ S ⇔ \sum\limits_{i = m}^{+∞} s_i ⇝ T$

若无穷级数收敛，再将通项保序归组，则其收敛性不变。

$\sum\limits_{i = 1}^{+∞} s_i ⇝ S ⇒ \sum\limits_{i = 1}^{+∞} (s_{i_1} + ⋯ + s_{i_j}) ⇝ S$

若无穷级数各组内的通项正负性相同，则其敛散性不变。

$\sum\limits_{i = 1}^{+∞} s_i ⇝ S ⇔ \sum\limits_{i = 1}^{+∞} (s_{i_1} + ⋯ + s_{i_j}) ⇝ S$

特例：无穷级数$\sum\limits_{i=1}^{+∞} (-1)^i \not⇝ S$。

$\lim\limits_{i ⇝ +∞} S_{2 · i - 1} ⇝ -1, \lim\limits_{i ⇝ +∞} S_{2 · i} ⇝ 0$

### 无穷级数的数列审敛法

若无穷级数收敛，则其部分和的极限之差为无穷小。

$[∀ε>0;∃N∈ℕ;∀n>N; |S_n - S| < ε] ⇔ [∀ε>0;∃N∈ℕ;∀n>N;∀m>N;|S_m - S_n| < ε]$

$[∀ε>0;∃N∈ℕ;∀n>N; \left| \sum\limits_{i=1}^n s_i - S \right| < ε] ⇔ [∀ε>0;∃N∈ℕ;∀n>N;∀m>n; \left| \sum\limits_{i=n+1}^m s_i \right| < ε]$

另根据谓词逻辑，也可完全等价地表达成下述形式。

$[∀ε>0;∃N∈ℕ; n ≥ N ⇒ S_n ⇝ S] ⇔ [∀ε>0;∃N∈ℕ; n ≥ N ∧ m ≥ N ⇒ |S_m - S_n| < ε]$

$[∀ε>0;∃N∈ℕ; n ≥ N ⇒ \sum\limits_{i=1}^n s_i ⇝ S] ⇔ [∀ε>0;∃N∈ℕ; n ≥ N ∧ m ≥ n ⇒ \left| \sum\limits_{i=n + 1}^m s_i \right| < ε]$

必要性证明，根据三角不等关系式。

| $⇓$  | $∀ε_1>0;∃N∈ℕ;∀n>N; \lvert S_n - S \rvert < ε_1] ∧ [∀ε_2>0;∃N∈ℕ;∀m>N; \lvert S_m - S \rvert < ε_2$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε=ε_1 + ε_2;∃N∈ℕ;∀n>N;∀m>N; \lvert S_m - S_n \rvert ≤ \lvert S_m - S \rvert + \lvert S_n - S \rvert < ε_1 + ε_2 = ε$ |
| $⇓$  | $∀ε>0;∃N∈ℕ;∀n>N;∀m>N; \lvert S_m - S_n \rvert < ε$           |

充分性证明，根据上下确界关系式。

| $⇓$  | $∀ε>0;∃N∈ℕ;∀n>N;∀m>N; \lvert S_m - S_n \rvert < ε$           |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∃S;∀ε=ε_1+ε_2;∃N∈ℕ;∀n>N;∀m>N; S - ε_1 < S_m, S_n < S + ε_2$ |
| $⇓$  | $∀ε>0;∃N∈ℕ;∀n>N;\lvert S_n - S \rvert < ε$                   |

### 无穷级数的分部审敛法

无穷级数的分部求和公式

$\sum\limits_{i=n+1}^m s_i · t_i = \sum\limits_{i=n+1}^m (S_i - S_{i-1}) · t_i = S_m · t_m + \sum\limits_{i=n+1}^{m-1} S_i · t_i - \sum\limits_{i=n+1}^{m-1} S_i · t_{i+1} - S_n · t_{n+1} = (S_m · t_m - S_n · t_{n+1}) + \sum\limits_{i=n+1}^{m-1} S_i · (t_i - t_{i+1})$

$\left| \sum\limits_{i=n+1}^m s_i · t_i \right| ≤ |S_m · t_m| + |S_n · t_{n+1}| + \left| \sum\limits_{i=n+1}^{m-1} S_i · (t_i - t_{i+1}) \right| ≤ |S_m| · |t_m| + |S_n| · |t_{n+1}| + \sum\limits_{i=n+1}^{m-1} |S_i| · |t_i - t_{i+1}|$

| $⇓$  |                                                              |      | $\left| \sum\limits_{i=n+1}^m s_i · t_i \right| ≤ |S_m| · |t_m| + |S_n| · |t_{n+1}| + \sum\limits_{i=n+1}^{m-1} |S_i| · |t_i - t_{i+1}|$ |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇓$  | $∀i∈[n, m]; |S_i| < \mathrm{Sup.} ∧ [t_i > t_{i+1} ⊕ t_i < t_{i+1}]$ | $⇒$  | $\left| \sum\limits_{i=n+1}^m s_i · t_i \right| ≤ \mathrm{Sup.} · \left[ |t_m| + |t_{n+1}| + \left| \sum\limits_{i=n+1}^{m-1} (t_i - t_{i+1}) \right| \right] ≤ \mathrm{Sup.} · 2 · \left[ |t_m| + |t_{n+1}| \right]$ |
| $⇓$  | $\varlimsup\limits_{i ⇝ +∞} |S_i| < \mathrm{Sup.} ∧ [t_i > t_{i+1} ⊕ t_i < t_{i+1}] ∧ \lim\limits_{i ⇝ +∞} t_i ⇝ 0$ | $⇒$  | $∀ε>0;∃N∈ℕ;∀n≥N;∀m≥n; \left| \sum\limits_{i=n+1}^m s_i · t_i \right| < \mathrm{Sup.} · 2 · (ε_1 + ε_2) = ε$ |
| $⇓$  | $\varlimsup\limits_{i ⇝ +∞} |S_i| < \mathrm{Sup.} ∧ [t_i > t_{i+1} ⊕ t_i < t_{i+1}] ∧ \lim\limits_{i ⇝ +∞} t_i ⇝ 0$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i · t_i ⇝ ST$                      |
| $⇓$  | $\lim\limits_{i ⇝ +∞} S_i ⇝ S ∧ [t_i > t_{i+1} ⊕ t_i < t_{i+1}] ∧ \lim\limits_{i ⇝ +∞} t_i ⇝ t$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i · t_i = t · \sum\limits_{i=1}^{+∞} s_i + \sum\limits_{i=1}^{+∞} [ s_i · (t_i - t) ] ⇝ ST$ |

特例：若$s_i > s_{i+1} ∧ \lim\limits_{i ⇝ +∞} s_i ⇝ 0$，则交错级数$\sum\limits_{i=1}^{+∞} (-1)^i · s_i ⇝ S$。

### 无穷级数的绝对收敛与条件收敛

若无穷级数绝对收敛，则其本身必定收敛。

$\sum\limits_{i=1}^{+∞} |s_i| ⇝ S_{||} ⇒ \sum\limits_{i=1}^{+∞} s_i ⇝ S$

$\left[ ∀ε>0;∃N∈ℕ;∀n>N; \left| \sum\limits_{i=n+1}^m |s_i| \right| < ε \right] ⇒ \left[ ∀ε>0;∃N∈ℕ;∀n>N;∀m>n; \left| \sum\limits_{i=n+1}^m s_i \right| ≤ \left| \sum\limits_{i=n+1}^{m} |s_i| \right| < ε \right]$

若无穷级数本身收敛，则其未必绝对收敛。

$\sum\limits_{i=1}^{+∞} s_i ⇝ S \not⇒ \sum\limits_{i=1}^{+∞} |s_i| ⇝ S_{||}$

$\left[ ∀ε>0;∃N∈ℕ;∀n>N;∀m>n; \left| \sum\limits_{i=n+1}^m s_i \right| < ε \right] \not⇒ \left[ ∀ε>0;∃N∈ℕ;∀n>N; \left| \sum\limits_{i=n+1}^m |s_i| \right| < ε \right]$

### 无穷级数绝对收敛与条件收敛的性质

无穷级数的正数项$+s_i^+ ≡ +\dfrac{1}{2} · (|s_i| + s_i)$，无穷级数的负数项$-s_i^- ≡ -\dfrac{1}{2} · (|s_i| - s_i)$。

无穷级数的一般项$s_i = s_i^+ - s_i^-$，无穷级数的绝对项$|s_i| = s_i^+ + s_i^-$。

若无穷级数绝对收敛，则其正数项级数与负数项级数均收敛，反之亦然。

$\sum\limits_{i=1}^{+∞} |s_i| = \sum\limits_{i=1}^{+∞} (s_i^+ + s_i^-) ⇝ S_{||} ⇔ \sum\limits_{i=1}^{+∞} s_i^+ ⇝ S_{+} ∧ \sum\limits_{i=1}^{+∞} s^- ⇝ S_-$

若无穷级数条件收敛，则其正数项级数与负数项级数均发散，反之不对。

$\sum\limits_{i=1}^{+∞} s_i = \sum\limits_{i=1}^{+∞} (s_i^+ - s_i^-) ⇝ S ⇒ \sum\limits_{i=1}^{+∞} s_i^+ \not⇝ S_+ ∧ \sum\limits_{i=1}^{+∞} s_i^- \not⇝ S_- ⇒ \sum\limits_{i=1}^{+∞} s_i^+ ⇝ +∞ ∧ \sum\limits_{i=1}^{+∞} s_i^- ⇝ +∞$

| $⇓$  | $\sum\limits_{i=1}^{+∞} | s_i | ⇝ S_{||} ⇒ \sum\limits_{i=1}^{+∞} s_i^+ ⇝ S_+$ | $⇐$  | $0 ≤ s_i^+ ≤ | s_i |$                                        |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇓$  | $\sum\limits_{i=1}^{+∞} | s_i | ⇝ S_{||} ⇒ \sum\limits_{i=1}^{+∞} s^- ⇝ S_-$ | $⇐$  | $0 ≤ s_i^- ≤ | s_i |$                                        |
| $⇓$  | $\sum\limits_{i=1}^{+∞} | s_i | ⇝ S_{||} ⇐ \sum\limits_{i=1}^{+∞} s_i^+ ⇝ S_+ ∧ \sum\limits_{i=1}^{+∞} s_i^- ⇝ S_-$ | $⇐$  | $\sum\limits_{i=1}^{+∞} | s_i | = \sum\limits_{i = 1}^{+∞} s_i^+ + \sum\limits_{i=1}^{+∞} s_i^-$ |
| $⇓$  | $\sum\limits_{i=1}^{+∞} | s_i | ⇝ S_{||} ⇔ \sum\limits_{i=1}^{+∞} s_i^+ ⇝ S_+ ∧ \sum\limits_{i=1}^{+∞} s_i^- ⇝ S_-$ | $⇒$  | $\sum\limits_{i=1}^{+∞} | s_i | \not⇝ S_{||} ⇒ \left[ \sum\limits_{i=1}^{+∞} s_i^+ \not⇝ S_+ ∨ \sum\limits_{i=1}^{+∞} s_i^- \not⇝ S_- \right]$ |
| $⇓$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S ⇒ \left[ \sum\limits_{i=1}^{+∞} s_i^+ ⇝ S_+ ∧ \sum\limits_{i=1}^{+∞} s_i^- ⇝ S_- \right] ⊕ \left[ \sum\limits_{i=1}^{+∞} s_i^+ \not⇝ S_+ ∧ \sum\limits_{i=1}^{+∞} s_i^- \not⇝ S_- \right]$ | $⇐$  | $\sum\limits_{i=1}^{+∞} s_i = \sum\limits_{i=1}^{+∞} s_i^+ - \sum\limits_{i=1}^{+∞} s_i^-$ |
| $⇓$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S ∧ \sum\limits_{i=1}^{+∞} | s_i | \not⇝ S_{||} ⇒ \left[ \sum\limits_{i=1}^{+∞} s_i^+ \not⇝ S_+ ∧ \sum\limits_{i=1}^{+∞} s_i^- \not⇝ S_- \right]$ |      |                                                              |
| $⇓$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S ∧ \sum\limits_{i=1}^{+∞} | s_i | \not⇝ S_{||} ⇒ \left[ \sum\limits_{i=1}^{+∞} s_i^+ ⇝ +∞ ∧ \sum\limits_{i=1}^{+∞} s_i^- ⇝ +∞ \right]$ | $⇐$  | $0 ≤ s_i^+ ∧ 0 ≤ s_i^-$                                      |

若无穷级数绝对收敛，则交换任意多项的次序，其极限不变并且保持绝对收敛。

若无穷级数条件收敛，则交换任意多项的次序，可使其趋近于任意给定的极限。

| $⇓$  |                                              | $\sum\limits_{i=1}^{+∞} s_i ⇝ S ⇒ \lim\limits_{i=1}^{+∞} s_i ⇝ 0$ |
| :--: | -------------------------------------------: | :----------------------------------------------------------- |
| $⇓$  |                                              | $\sum\limits_{i=1}^{+∞} s_i ⇝ S ∧ \sum\limits_{i=1}^{+∞} | s_i | \not⇝ S_{||} ⇒ \sum\limits_{i=1}^{+∞} s_i^+ ⇝ +∞ ∧ \sum\limits_{i=1}^{+∞} s_i^- ⇝ +∞$ |
| $⇓$  | $∃n_1^+∈ℕ;∃n_1^-∈ℕ;∃n_1≤\max(n_1^+, n_1^-);$ | $\left| \left( \sum\limits_{j=1}^{n_1^+} s_j^+ - \sum\limits_{j=1}^{n_1^-} s_j^- \right) - T \right| < | s_{n_1} |$ |
| $⇓$  | $∃n_2^+∈ℕ;∃n_2^-∈ℕ;∃n_2≤\max(n_2^+, n_2^-);$ | $\left| \left( \sum\limits_{j=1}^{n_1^+} s_j^+ - \sum\limits_{j=1}^{n_1^-} s_j^- \right) + \left( \sum\limits_{j=n_1^+ + 1}^{n_2^+} s_j^+ - \sum\limits_{j=n_2^- + 1}^{n_2^-} s_j^- \right) - T \right| < | s_{n_2} | < | s_{n_1} |$ |
| $⇓$  |                                        $···$ | $···$                                                        |
| $⇓$  |                                              | $\left| \left( \sum\limits_{j=1}^{n_1^+} s_j^+ - \sum\limits_{j=1}^{n_1^-} s_j^- \right) + \left( \sum\limits_{j=n_1^+ + 1}^{n_2^+} s_j^+ - \sum\limits_{j=n_1^- + 1}^{n_2^-} s_j^- \right) + ··· + \left( \sum\limits_{j=n_{m-1}^+ + 1}^{n_m^+} s_j^+ - \sum\limits_{j=n_{m-1}^- + 1}^{n_m^-} s_j^- \right) - T \right| < ε = | s_{n_m} | < ··· < | s_{n_2} | < | s_{n_1} |$ |
| $⇓$  |                                              | $\left( \sum\limits_{j=1}^{+∞} s_j^+ - \sum\limits_{j=1}^{+∞} s_j^- \right) = \sum\limits_{j=1}^{+∞} s_j ⇝ T$ |

特例：无穷级数$\sum\limits_{i=1}^{+∞} \dfrac{(-1)^n}{n} ⇝ S$条件收敛非绝对收敛，交换无穷多项的次序可使其值发生改变。

$\sum\limits_{i=1}^{+∞} s_i^+ = \sum\limits_{i=1}^{+∞} \dfrac{1}{2 · i} ⇝ +∞, \sum\limits_{i=1}^{+∞} s_i^- = \sum\limits_{i=1}^{+∞}  = \dfrac{1}{2 · i - 1} ⇝ +∞$

新无穷级数$- \dfrac{1}{1} + \sum\limits_{i=1}^{+∞} \left( - \dfrac{1}{4 · i - 1} + \dfrac{1}{2 · i} - \dfrac{1}{4 · i + 1} \right) ⇝ \dfrac{3}{2} · S$，由原无穷级数$\sum\limits_{i=1}^{+∞} \dfrac{(-1)^n}{n} ⇝ S$，交换无穷多项的次序得到，两者并非等值。

|                   $S = $ | $- \dfrac{1}{1}$ | $+ \dfrac{1}{2}$ | $- \dfrac{1}{3}$ | $+ \dfrac{1}{4}$ | $- \dfrac{1}{5}$ | $+ \dfrac{1}{6}$ | $- \dfrac{1}{7}$ | $+ \dfrac{1}{8}$ | $- \dfrac{1}{9}$ | $+ \dfrac{1}{10}$ | $- \dfrac{1}{11}$ | $+ \dfrac{1}{12}$ | $- \dfrac{1}{13}$ | $+ \dfrac{1}{14}$ | $- \dfrac{1}{15}$ | $+ \dfrac{1}{16}$ | $- \dfrac{1}{17}$ | $+ \dfrac{1}{18}$ | $- \dfrac{1}{19}$ | $+ \dfrac{1}{20}$ | $-\dfrac{1}{21}$ | $+ \dfrac{1}{22}$ |
| -----------------------: | :--------------: | :--------------: | :--------------: | :--------------: | :--------------: | :--------------: | :--------------: | :--------------: | :--------------: | :---------------: | :---------------: | :---------------: | :---------------: | :---------------: | :---------------: | :---------------: | :---------------: | :---------------: | :---------------: | :---------------: | :--------------: | :---------------: |
| $+) \dfrac{1}{2} · S = $ |                  | $- \dfrac{1}{2}$ |                  | $+ \dfrac{1}{4}$ |                  | $- \dfrac{1}{6}$ |                  | $+ \dfrac{1}{8}$ |                  | $- \dfrac{1}{10}$ |                   | $+ \dfrac{1}{12}$ |                   | $- \dfrac{1}{14}$ |                   | $+ \dfrac{1}{16}$ |                   | $- \dfrac{1}{18}$ |                   | $+ \dfrac{1}{20}$ |                  | $- \dfrac{1}{22}$ |
|    $\dfrac{3}{2} · S = $ | $- \dfrac{1}{1}$ |                  | $- \dfrac{1}{3}$ | $+ \dfrac{1}{2}$ | $- \dfrac{1}{5}$ |                  | $- \dfrac{1}{7}$ | $+ \dfrac{1}{4}$ | $- \dfrac{1}{9}$ |                   | $- \dfrac{1}{11}$ | $+ \dfrac{1}{6}$  | $- \dfrac{1}{13}$ |                   | $- \dfrac{1}{15}$ | $+ \dfrac{1}{8}$  | $- \dfrac{1}{17}$ |                   | $- \dfrac{1}{19}$ | $+ \dfrac{1}{10}$ | $-\dfrac{1}{21}$ |                   |

--------------------------------------------------------------------------------

### 正项级数收敛的性质

若正项级数收敛，则正项级数有上确界，反之亦然。

$\sum\limits_{i = 1}^{+∞} s_i ⇝ S ⇔ \sum\limits_{i = 1}^{+∞} s_i ≤ \mathrm{Sup.}$

若正项级数发散，则正项级数无上确界，反之亦然。

$\sum\limits_{i = 1}^{+∞} s_i \not⇝ S ⇔ \sum\limits_{i = 1}^{+∞} s_i \not≤ \mathrm{Sup.}$

### 正项级数的比较审敛法

| $⇑$  |                                       $∃N∈ℕ;∀i≥N; s_i ≤ t_i$ | $⇒$  | $\sum\limits_{i = 1}^{+∞} t_i ⇝ T ⇒  \sum\limits_{i = 1}^{+∞} s_i ⇝ S$ |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇑$  |                            $∃N∈ℕ;∀i≥N; \dfrac{s_i}{t_i} ≤ 1$ | $⇒$  | $\dfrac{s_i}{t_i} ≤ 1 + o (1)$                               |
| $⇑$  |                          $∃N∈ℕ;∀i≥N; \dfrac{s_i}{t_i} = γ_i$ | $⇒$  | $γ_i = \dfrac{s_i}{t_i} + o (1)$                             |
| $⇑$  |                                 $\dfrac{s_i}{t_i} = γ_i ≤ 1$ | $⇒$  | $\sum\limits_{i = 1}^{+∞} t_i ⇝ T ⇒  \sum\limits_{i = 1}^{+∞} s_i ⇝ S$ |
| $⇑$  |                                  $\dfrac{s_i}{t_i} =γ_i > 1$ | $⇒$  | $\sum\limits_{i = 1}^{+∞} s_i \not⇝ S ⇒  \sum\limits_{i = 1}^{+∞} t_i \not⇝ T$ |
| $⇑$  | $\varlimsup\limits_{i ⇝ +∞} \dfrac{s_i}{t_i} = \varlimsup\limits_{i ⇝ +∞} γ_i ⇝ γ < 1$ | $⇒$  | $\sum\limits_{i = 1}^{+∞} t_i ⇝ T ⇒  \sum\limits_{i = 1}^{+∞} s_i ⇝ S$ |
| $⇑$  | $\varlimsup\limits_{i ⇝ +∞} \dfrac{s_i}{t_i} = \varlimsup\limits_{i ⇝ +∞} γ_i ⇝ γ > 1$ | $⇒$  | $\sum\limits_{i = 1}^{+∞} s_i \not⇝ S ⇒  \sum\limits_{i = 1}^{+∞} t_i \not⇝ T$ |

特例：正项级数$\sum\limits_{i = 1}^{+∞} f(α + i)$与广义积分$\int_α^{+∞} f(x) \mathrm{d}x$的敛散性相同，$f(x)$为区间$[α, +∞)$上非负单调递减的连续函数。

$\left[ \sum\limits_{i = 1}^{+∞} f(α + i) ⇝ S \right] ⇔ \left[ \int_α^{+∞} f(x) \mathrm{d}x ⇝ I \right]$

| $⇓$  | $\sum\limits_{i = 0}^{+∞} \int\limits_{α + i}^{α + i + 1} f(α + i + 1) \mathrm{d}x = \int\limits_α^{+∞} f(α + i + 1) \mathrm{d}x ≤ \int\limits_α^{+∞} f(x) \mathrm{d}x ≤ \int\limits_α^{+∞} f(α + i) \mathrm{d}x = \sum\limits_{i = 0}^{+∞} \int\limits_{α + i}^{α + i + 1} f(α + i) \mathrm{d}x$ |
| :--: | :----------------------------------------------------------: |
| $⇓$  | $\sum\limits_{i = 0}^{+∞} f(α + i + 1) = \sum\limits_{i = 0}^{+∞} \int\limits_{α + i}^{α + i + 1} f(α + i + 1) \mathrm{d}x ≤ \sum\limits_{i = 0}^{+∞} \int\limits_{α + i}^{α + i + 1} f(x) \mathrm{d}x ≤ \sum\limits_{i = 0}^{+∞} \int\limits_{α + i}^{α + i + 1} f(α + i) \mathrm{d}x = \sum\limits_{i = 0}^{+∞} f(α + i)$ |
| $⇓$  | $\sum\limits_{i=1}^{+∞} f(α + i) = \sum\limits_{i = 0}^{+∞} f(α + i + 1) ≤ \int\limits_α^{+∞} f(x) \mathrm{d}x ≤ \sum\limits_{i = 0}^{+∞} f(α + i)$ |

特例：正项级数$\sum\limits_{i=2}^{+∞} \dfrac{1}{i^α · \ln^β i · \ln^γ \ln i}$收敛，仅当$α > 1$，以及$α = 1, β > 1$，以及$α = 1, β = 1, γ > 1。

| $⇓$  |              $f(x) ≡ \dfrac{1}{x^α · \ln^β x · \ln^γ \ln x}$ | $⇒$  | $x_1 > x_2 ⇒ f(x_1) > f(x_2)$                                |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇓$  | $s_i = \dfrac{1}{i^α · \ln^β i · \ln^γ \ln i} = \dfrac{1}{i^{1 + ε_1}} · \dfrac{1}{i^{ε_2} · \ln^β i · \ln^γ \ln i}$ | $⇐$  | $α > 1 ⇒ α ≡ 1 + ε_1 + ε_2$                                  |
| $⇓$  |                       $α > 1 ⇒ s_i < \dfrac{1}{i^{1 + ε_1}}$ | $⇐$  | $\lim\limits_{i ⇝ +∞} \dfrac{1}{i^{ε_2} · \ln^β i · \ln^γ \ln i} ⇝ 0$ |
| $⇓$  |                     $α > 1 ⇒ \sum\limits_{i=2}^{+∞} s_i ⇝ S$ | $⇐$  | $\int\limits_{i=2}^{+∞} \dfrac{1}{i^{1 + ε_1}} \mathrm{d}i ⇝ I$ |
| $⇓$  | $s_i = \dfrac{1}{i^α · \ln^β i · \ln^γ \ln i} = \dfrac{1}{i^{1 - ε_1}} · \dfrac{i^{ ε_2}}{\ln^β i · \ln^γ \ln i}$ | $⇐$  | $α < 1 ⇒ α ≡ 1 - ε_1 - ε_2$                                  |
| $⇓$  |                       $α < 1 ⇒ s_i > \dfrac{1}{i^{1 - ε_1}}$ | $⇐$  | $\lim\limits_{i ⇝ +∞} \dfrac{i^{ε_2}}{\ln^β i · \ln^γ \ln i} ⇝ +∞$ |
| $⇓$  |                 $α < 1 ⇒ \sum\limits_{i=2}^{+∞} s_i \not⇝ S$ | $⇐$  | $\int\limits_{i=2}^{+∞} \dfrac{1}{i^{1 - ε_1}} \mathrm{d}i \not⇝ I$ |
| $⇓$  | $α = 1 ⇒ \int\limits_{2}^{+∞} s_i \mathrm{d}i = \int\limits_{\ln 2}^{+∞} \dfrac{\mathrm{d}u}{u^β · \ln^γ u}$ | $⇐$  | $u ≡ \ln i ⇒ \dfrac{\mathrm{d}i}{i} = \mathrm{d}u$           |
| $⇓$  |              $α = 1, β > 1 ⇒ \sum\limits_{i=2}^{+∞} s_i ⇝ S$ | $⇐$  | $β > 1 ⇒ \int\limits_{\ln 2}^{+∞} \dfrac{\mathrm{d}u}{u^β · \ln^γ u} ⇝ I$ |
| $⇓$  |          $α = 1, β < 1 ⇒ \sum\limits_{i=2}^{+∞} s_i \not⇝ S$ | $⇐$  | $β < 1 ⇒ \int\limits_{\ln 2}^{+∞} \dfrac{\mathrm{d}u}{u^β · \ln^γ u} \not⇝ I$ |

附加证明：$\lim\limits_{i ⇝ +∞} \dfrac{i^{ε_2}}{\ln^β i · \ln^γ \ln i} ⇝ +∞$

$\lim\limits_{i ⇝ +∞} \dfrac{i^{ε_2}}{\ln^β i · \ln^γ \ln i} = \lim\limits_{i ⇝ +∞} \left[ \left[ \lim\limits_{i ⇝ +∞} \dfrac{i^{\frac{ε_2}{β}}}{\ln i} \right]^β· \dfrac{1}{\ln^γ \ln i} \right] = \lim\limits_{i ⇝ +∞} \left[ \left( \dfrac{ε_2}{β} \right)^β · \left[ \lim\limits_{i ⇝ +∞} \dfrac{i^{\frac{ε_2}{γ}}}{\ln \ln i} \right]^γ \right] = \lim\limits_{i ⇝ +∞} \left[ \left( \dfrac{ε_2}{β} \right)^β · \left( \dfrac{ε_2}{γ} · \ln i \right)^γ · i^{ε_2} \right] ⇝ +∞$

### 正项级数的根值审敛法

| $⇑$  |                $∃N∈ℕ;∀i≥N; s_i ≤ \dfrac{\mathrm{Sup.}}{γ^i}$ | $⇒$  | $γ > 1 ⇒ \sum\limits_{i=1}^{+∞} s_i ⇝ S$                     |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇑$  | $∃N∈ℕ;∀i≥N; \sqrt[i + 1]{s_{i+1}} · γ ≤ \sqrt[i]{s_i} · γ ≤ \sqrt[N]{\mathrm{Sup.}} ⇝ 1$ | $⇒$  | $\sqrt[i]{s_i} ≤ \dfrac{1}{γ} + o \left( \dfrac{1}{γ} \right)$ |
| $⇑$  | $∃N∈ℕ;∀i≥N; \sqrt[i]{s_i} = \dfrac{1}{γ_i} + o \left( \dfrac{1}{γ_i} \right)$ | $⇒$  | $γ_i = \dfrac{1}{\sqrt[i]{s_i}} + o (1)$                     |
| $⇑$  |                     $\dfrac{1}{\sqrt[i]{s_i}} = γ_i ≥ γ > 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S$                             |
| $⇑$  |                         $\dfrac{1}{\sqrt[i]{s_i}} = γ_i ≤ 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i \not⇝ S$                         |
| $⇑$  | $\varliminf\limits_{i ⇝ +∞} \dfrac{1}{\sqrt[i]{s_i}} = \varliminf\limits_{i ⇝ +∞} γ_i ⇝ γ > 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S$                             |
| $⇑$  | $\varlimsup\limits_{i ⇝ +∞} \dfrac{1}{\sqrt[i]{s_i}} = \varlimsup\limits_{i ⇝ +∞} γ_i ⇝ γ < 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i \not⇝ S$                         |

特例：正项级数$\sum\limits_{i = 1}^{+∞} \dfrac{1}{i} \not⇝ S$，正项级数$\sum\limits_{i = 1}^{+∞} \dfrac{1}{i^2} ⇝ S$。

$\lim\limits_{i ⇝ +∞} γ_i = \lim\limits_{i ⇝ +∞} \sqrt[i]{i} ⇝ 1$

$\lim\limits_{i ⇝ +∞} γ_i = \lim\limits_{i ⇝ +∞} \sqrt[i]{i^2} = \left[ \lim\limits_{i ⇝ +∞} \sqrt[i]{i} \right]^2 ⇝ 1$

### 正项级数的比值审敛法

| $⇑$  |                $∃N∈ℕ;∀i≥N; s_i ≤ \dfrac{\mathrm{Sup.}}{γ^i}$ | $⇒$  | $γ > 1 ⇒ \sum\limits_{i=1}^{+∞} s_i ⇝ S$ |
| :--: | -----------------------------------------------------------: | :--: | :--------------------------------------- |
| $⇑$  | $∃N∈ℕ;∀i≥N; s_{i+1} · γ^{i + 1} ≤ s_i · γ^i ≤ \mathrm{Sup.}$ | $⇒$  | $\dfrac{s_i}{s_{i+1}} ≥ γ + o (1)$       |
| $⇑$  |              $∃N∈ℕ;∀i≥N; \dfrac{s_i}{s_{i+1}} = γ_i + o (1)$ | $⇒$  | $γ_i = \dfrac{s_i}{s_{i+1}} + o (1)$     |
| $⇑$  |                         $\dfrac{s_i}{s_{i+1}} = γ_i ≥ γ > 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S$         |
| $⇑$  |                             $\dfrac{s_i}{s_{i+1}} = γ_i ≤ 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i \not⇝ S$     |
| $⇑$  | $\varliminf\limits_{i ⇝ +∞} \dfrac{s_i}{s_{i+1}} = \varliminf\limits_{i ⇝ +∞} γ_i ⇝ γ > 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S$         |
| $⇑$  | $\varlimsup\limits_{i ⇝ +∞} \dfrac{s_i}{s_{i+1}} = \varlimsup\limits_{i ⇝ +∞} γ_i ⇝ γ < 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i \not⇝ S$     |

特例：正项级数$\sum\limits_{i = 1}^{+∞} \dfrac{1}{i} \not⇝ S$，正项级数$\sum\limits_{i = 1}^{+∞} \dfrac{1}{i^2} ⇝ S$。

$\lim\limits_{i ⇝ +∞} γ_i = \lim\limits_{i ⇝ +∞} \dfrac{i + 1}{i} ⇝ 1$

$\lim\limits_{i ⇝ +∞} γ_i = \lim\limits_{i ⇝ +∞} \dfrac{i^2}{(i + 1)^2} = \left[ \lim\limits_{i ⇝ +∞} \dfrac{i}{i + 1} \right]^2 ⇝ 1$

### 正项级数的幂值审敛法

| $⇑$  |                $∃N∈ℕ;∀i≥N; s_i ≤ \dfrac{\mathrm{Sup.}}{i^α}$ | $⇒$  | $α > 1 ⇒ \sum\limits_{i=1}^{+∞} s_i ⇝ S$                     |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇑$  | $∃N∈ℕ;∀i≥N; s_{i+1} · (i + 1)^α ≤ s_i · i^α ≤ \mathrm{Sup.}$ | $⇒$  | $\dfrac{s_i}{s_{i+1}} ≥ \dfrac{(i + 1)^α}{i^α} = 1 + \dfrac{α}{i} + o \left( \dfrac{1}{i} \right)$ |
| $⇑$  | $∃N∈ℕ;∀i≥N; \dfrac{s_i}{s_{i + 1}} = 1 + \dfrac{α_i}{i} + o \left( \dfrac{1}{i} \right)$ | $⇒$  | $α_i = i · \left( \dfrac{s_i}{s_{i+1}} - 1 \right) + o (1)$  |
| $⇑$  |  $i · \left( \dfrac{s_i}{s_{i+1}} - 1 \right) = α_i ≥ α > 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S$                             |
| $⇑$  |      $i · \left( \dfrac{s_i}{s_{i+1}} - 1 \right) = α_i ≤ 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i \not⇝ S$                         |
| $⇑$  | $\varliminf\limits_{i ⇝ +∞} i · \left( \dfrac{s_i}{s_{i+1}} - 1 \right) = \varliminf\limits_{i ⇝ +∞} α_i ⇝ α > 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S$                             |
| $⇑$  | $\varlimsup\limits_{i ⇝ +∞} i · \left( \dfrac{s_i}{s_{i+1}} - 1 \right) = \varlimsup\limits_{i ⇝ +∞} α_i ⇝ α < 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i \not⇝ S$                         |

特例：正项级数$\sum\limits_{i = 2}^{+∞} \dfrac{1}{i} \not⇝ S$，正项级数$\sum\limits_{i = 2}^{+∞} \dfrac{1}{i · \ln^2 i} ⇝ S$。

$\lim\limits_{i ⇝ +∞} α_i = \lim\limits_{i ⇝ +∞} i · \left( \dfrac{i + 1}{i} - 1 \right) = \lim\limits_{i ⇝ +∞} 1 ⇝ 1$

$\lim\limits_{i ⇝ +∞} α_i = \lim\limits_{i ⇝ +∞} i · \left[ \dfrac{(i + 1) · \ln^2 (i + 1)}{i · \ln^2 i} - 1 \right] = \lim\limits_{i ⇝ +∞} \left[ (i + 1) · \left[ \lim\limits_{i ⇝ +∞} \dfrac{\ln (i + 1)}{\ln i} \right]^2 - i \right] = \lim\limits_{i ⇝ +∞} 1 ⇝ 1$

### 正项级数的指数审敛法

| $⇑$  |                $∃N∈ℕ;∀i≥N; s_i ≤ \dfrac{\mathrm{Sup.}}{i^α}$ | $⇒$  | $α > 1 ⇒ \sum\limits_{i=1}^{+∞} s_i ⇝ S$                     |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇑$  | $∃N∈ℕ;∀i≥N; s_{i+1} · (i + 1)^α ≤ s_i · i^α ≤ \mathrm{Sup.}$ | $⇒$  | $α ≤ \dfrac{\ln \mathrm{Sup.} - \ln s_i}{\ln i} = \dfrac{\ln s_i^{-1}}{\ln i} + o (1)$ |
| $⇑$  |       $∃N∈ℕ;∀i≥N; α_i = \dfrac{\ln s_i^{-1}}{\ln i} + o (1)$ | $⇒$  | $s_i · i^{α + o (1)} ≤ 1$                                    |
| $⇑$  |                  $\dfrac{\ln s_i^{-1}}{\ln i} = α_i ≥ α > 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S$                             |
| $⇑$  |                      $\dfrac{\ln s_i^{-1}}{\ln i} = α_i ≤ 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i \not⇝ S$                         |
| $⇑$  | $\varliminf\limits_{i ⇝ +∞} \dfrac{\ln s_i^{-1}}{\ln i} = \varliminf\limits_{i ⇝ +∞} α_i ⇝ α > 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S$                             |
| $⇑$  | $\varlimsup\limits_{i ⇝ +∞} \dfrac{\ln s_i^{-1}}{\ln i} = \varlimsup\limits_{i ⇝ +∞} α_i ⇝ α < 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i \not⇝ S$                         |
| $⇑$  |  $\varlimsup\limits_{i ⇝ +∞} s_i · i^α ⇝ \mathrm{Sup.} < +∞$ | $⇒$  | $α > 1 ⇒ \sum\limits_{i=1}^{+∞} s_i ⇝ S$                     |
| $⇑$  |   $\varliminf\limits_{i ⇝ +∞} s_i · i^α ⇝ \mathrm{Inf.} > 0$ | $⇒$  | $α ≤ 1 ⇒ \sum\limits_{i=1}^{+∞} s_i \not⇝ S$                 |

特例：正项级数$\sum\limits_{i = 1}^{+∞} \dfrac{1}{i} \not⇝ S$，正项级数$\sum\limits_{i = 2}^{+∞} \dfrac{1}{i · \ln^2 i} ⇝ S$。

$\lim\limits_{i ⇝ +∞} α_i = \lim\limits_{i ⇝ +∞} \dfrac{\ln i}{\ln i} = \lim\limits_{i ⇝ +∞} 1 ⇝ 1$

$\lim\limits_{i ⇝ +∞} α_i = \lim\limits_{i ⇝ +∞} \dfrac{\ln \left( i · \ln^2 i \right)}{\ln i} = \lim\limits_{i ⇝ +∞} \dfrac{\frac{1}{i · \ln i} · \left( \ln^2 i + i · 2 · \ln i · \frac{1}{i} \right)}{\frac{1}{i}} = \lim\limits_{i ⇝ +∞} \left( 1 + \dfrac{2}{\ln i} \right) ⇝ 1$

$\lim\limits_{i ⇝ +∞} s_i · i^1 = \lim\limits_{i ⇝ +∞} \dfrac{1}{i} · i = \lim\limits_{i ⇝ +∞} 1 ⇝ 1$

### 正项级数的对数审敛法

| $⇑$  |        $∃N∈ℕ;∀i≥N; s_i ≤ \dfrac{\mathrm{Sup.}}{i · \ln^β i}$ | $⇒$  | $β > 1 ⇒ \sum\limits_{i = 1}^{+∞} s_i ⇝ S$                   |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇑$  | $∃N∈ℕ;∀i>N; s_{i+1} · (i+1) · \ln^β (i+1) ≤ s_i · i · \ln^β i ≤ \mathrm{Sup.}$ | $⇒$  | $\dfrac{s_i}{s_{i+1}} ≥ \dfrac{i + 1}{i} · \dfrac{\ln^β (i + 1)}{\ln^β i} = 1 + \dfrac{1}{i} + \dfrac{β}{i · \ln i} + o \left( \dfrac{1}{i · \ln i} \right)$ |
| $⇑$  | $∃N∈ℕ;∀i>N; \dfrac{s_i}{s_{i+1}} = 1 + \dfrac{1}{i} + \dfrac{β_i}{i · \ln i} + o \left( \dfrac{1}{i · \ln i} \right)$ | $⇒$  | $β_i = i · \ln i · \left( \dfrac{s_i}{s_{i+1}} - \dfrac{i + 1}{i} \right) + o (1)$ |
| $⇑$  | $i · \ln i · \left( \dfrac{s_i}{s_{i+1}} - \dfrac{i + 1}{i} \right) = β_i ≥ β > 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S$                             |
| $⇑$  | $i · \ln i · \left( \dfrac{s_i}{s_{i+1}} - \dfrac{i + 1}{i} \right) = β_i ≤ 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i \not⇝ S$                         |
| $⇑$  | $\varliminf\limits_{i ⇝ +∞} i · \ln i · \left( \dfrac{s_i}{s_{i+1}} - \dfrac{i + 1}{i} \right) = \varliminf\limits_{i ⇝ +∞}β_i ⇝ β > 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S$                             |
| $⇑$  | $\varlimsup\limits_{i ⇝ +∞} i · \ln i · \left( \dfrac{s_i}{s_{i+1}} - \dfrac{i + 1}{i} \right) = \varlimsup\limits_{i ⇝ +∞} β_i ⇝ β < 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i \not⇝ S$                         |

附加证明：

$\dfrac{i + 1}{i} · \dfrac{\ln^β (i + 1)}{\ln^β i} = \left( 1 + \dfrac{1}{i} \right) · \left[ \dfrac{\ln i + \ln \left( 1 + \dfrac{1}{i} \right)}{\ln i} \right]^β = \left( 1 + \dfrac{1}{i} \right) · \left[ 1 + \dfrac{1}{i · \ln i} + o \left( \dfrac{1}{i · \ln i} \right) \right]^β = \left( 1 + \dfrac{1}{i} \right) · \left[ 1 + \dfrac{β}{i · \ln i} + o \left( \dfrac{1}{i · \ln i} \right) \right] = 1 + \dfrac{1}{i} + \dfrac{β}{i · \ln i} + o \left( \dfrac{1}{i · \ln i} \right)$

特例：正项级数$\sum\limits_{i=1}^{+∞} \dfrac{1}{i · \ln i} \not⇝ S$，正项级数$\sum\limits_{i=1}^{+∞} \dfrac{1}{i · \ln i · \ln^2 \ln i} ⇝ S$。

$\lim\limits_{i ⇝ +∞} β_i = \lim\limits_{i ⇝ +∞} i · \ln i · \left[ \dfrac{(i + 1) · \ln (i + 1)}{i · \ln i} -  \dfrac{i + 1}{i} \right] = \lim\limits_{i ⇝ +∞} \left[ (i + 1) · \ln (i + 1) - (i + 1) · \ln i \right] = \lim\limits_{i ⇝ +∞} \left[ \ln \left( 1 + \dfrac{1}{i} \right)^i + \ln \left( 1 + \dfrac{1}{i} \right) \right] ⇝ 1$

$\lim\limits_{i ⇝ +∞} β_i = \lim\limits_{i ⇝ +∞} i · \ln i · \left[ \dfrac{(i + 1) · \ln (i + 1) · \ln^2 \ln (i + 1)}{i · \ln i · \ln^2 \ln i} - \dfrac{i + 1}{i} \right] = \lim\limits_{i ⇝ +∞} \left[ (i + 1) · \ln (i + 1) · \left[ \lim\limits_{i ⇝ +∞} \dfrac{\ln \ln (i + 1)}{\ln \ln i} \right]^2 - (i + 1) · \ln i \right] = \lim\limits_{i ⇝ +∞} \left[ \ln \left( 1 + \dfrac{1}{i} \right)^i + \ln \left( 1 + \dfrac{1}{i} \right) \right] ⇝ 1$

### 正项级数的审敛法对比

收敛速度：根值审敛法 > 比值审敛法 > 幂值审敛法 > 指数审敛法 > 对数审敛法 > 比较审敛法

强效程度：根值审敛法 < 比值审敛法 < 幂值审敛法 < 指数审敛法 < 对数审敛法 < 比较审敛法

由于$1 < \varliminf\limits_{i ⇝ +∞} \dfrac{s_i}{s_{i+1}} ≤ \varliminf\limits_{i ⇝ +∞} {\dfrac{1}{\sqrt[i]{s_i}}} ≤ \varlimsup\limits_{i ⇝ +∞} \dfrac{1}{\sqrt[i]{s_i}} ≤ \varlimsup\limits_{i ⇝ +∞} \dfrac{s_i}{s_{i+1}}$

也即$\varliminf\limits_{i ⇝ +∞} \dfrac{s_{i+1}}{s_i} ≤ \varliminf\limits_{i ⇝ +∞} \sqrt[i]{s_i} ≤ \varlimsup\limits_{i ⇝ +∞} \sqrt[i]{s_i} ≤ \varlimsup\limits_{i ⇝ +∞} \dfrac{s_{i+1}}{s_i} < 1$​

证明$\varliminf\limits_{i ⇝ +∞} \dfrac{s_i}{s_{i+1}} ≤ \varliminf\limits_{i ⇝ +∞} {\dfrac{1}{\sqrt[i]{s_i}}}$，也即$\varlimsup\limits_{i ⇝ +∞} \sqrt[i]{s_i} ≤ \varlimsup\limits_{i ⇝ +∞} \dfrac{s_{i+1}}{s_i}$

| $⇓$  |    $\varlimsup\limits_{i ⇝ +∞} \dfrac{s_{i+1}}{s_i} ⇝ ρ$ | $⇒$  | $∀ε>0;∃N∈ℕ;∀n≥N; \dfrac{s_{i+1}}{s_i} < ρ + ε$               |
| :--: | -------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇓$  |                     $\dfrac{s_i}{s_N} < (ρ + ε)^{i - N}$ | $⇒$  | $s_i < s_N · (ρ + ε)^{-N} · (ρ + ε)^i$                       |
| $⇓$  | $\sqrt[i]{s_i} < \sqrt[i]{s_N · (ρ + ε)^{-N}} · (ρ + ε)$ | $⇒$  | $\varlimsup\limits_{i ⇝ +∞} \sqrt[i]{s_i} ≤ \varlimsup\limits_{i ⇝ +∞} \left[ \sqrt[i]{s_N · (q + ε)^{-N}} · (ρ + ε) \right] ⇝ ρ + ε$ |
| $⇓$  |                                                 $ε ⇝ 0⁺$ | $⇒$  | $\varlimsup\limits_{i ⇝ +∞} \sqrt[i]{s_i} ≤ \varlimsup\limits_{i ⇝ +∞} \dfrac{s_{i+1}}{s_i} ⇝ ρ$ |

特例：正项级数$\sum\limits_{i=1}^{+∞} \left( \dfrac{1}{2^i} + \dfrac{1}{3^i} \right) = \sum\limits_{i=1}^{+∞} \dfrac{1}{2^i} + \sum\limits_{i=1}^{+∞} \dfrac{1}{3^i} = \dfrac{2}{2 - 1} + \dfrac{3}{3 - 1} ⇝ \dfrac{7}{2}$

$\varliminf\limits_{i ⇝ +∞} \dfrac{s_i}{s_{i+1}} = \lim\limits_{i ⇝ +∞} \dfrac{1/3^i}{1/2^{i + 1}} = \lim\limits_{i ⇝ +∞} \dfrac{2^{i + 1}}{3^i} ⇝ 0 < 1$

$\varlimsup\limits_{i ⇝ +∞} \dfrac{s_i}{s_{i+1}} = \lim\limits_{i ⇝ +∞} \dfrac{1/2^i}{1/3^i} = \lim\limits_{i ⇝ +∞} \dfrac{3^i}{2^i} ⇝ +∞ > 1$

$\varliminf\limits_{i ⇝ +∞} \dfrac{1}{\sqrt[i]{s_i}} = \lim\limits_{i ⇝ +∞} \sqrt[2 · i - 1]{2^i} = \lim\limits_{i ⇝ +∞} 2^{\frac{i}{2 · i - 1}} ⇝ \sqrt{2} > 1$

$\varlimsup\limits_{i ⇝ +∞} \dfrac{1}{\sqrt[i]{s_i}} = \lim\limits_{i ⇝ +∞} \sqrt[2 · i]{3^i} = \lim\limits_{i ⇝ +∞} 3^{\frac{1}{2}} ⇝ \sqrt{3} > 1$

### 构造性收敛正项级数

不存在收敛最慢的正项级数。

假设存在正项级数$\sum\limits_{i=1}^{+∞} s_i ⇝ S$，则可构造收敛更慢的正项级数$t_i ≡ \sqrt{S - S_{i-1}} - \sqrt{S - S_i}, \sum\limits_{i=1}^{+∞} t_i ⇝ \sqrt{S - S_0}$。

| $⇓$  |                             $\sum\limits_{i=1}^{+∞} s_i ⇝ S$ | $⇒$  | $S_0 = 0, s_i = S_i - S_{i-1} = (S - S_{i-1}) - (S - S_i)$   |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇓$  | $1 = \dfrac{s_i}{(S - S_{i-1}) - (S - S_i)} = \dfrac{s_i}{(\sqrt{S - S_{i-1}} + \sqrt{S - S_i}) · (\sqrt{S - S_{i-1}} - \sqrt{S - S_i})}$ | $⇒$  | $t_i ≡ \sqrt{S - S_{i-1}} - \sqrt{S - S_i}, \sum\limits_{i=1}^{+∞} t_i ⇝ \sqrt{S - S_0}$ |
| $⇓$  |     $\dfrac{s_i}{t_i} = \sqrt{S - S_{i-1}} + \sqrt{S - S_i}$ | $⇒$  | $\lim\limits_{i ⇝ +∞} \dfrac{s_i}{t_i} ⇝ 0$                  |

### 无穷乘积

级数的乘积可类比于矩阵的乘法运算。

$\sum\limits_{i=1}^n s_i · \sum\limits_{j=1}^m t_j =
\sum\limits_{i=1,j=1}^{n,m}\left[\begin{matrix}
s_1 \\ s_2 \\ \vdots \\ s_n
\end{matrix}\right] ·
\left[\begin{matrix}
t_1 & t_2 & \cdots & t_m
\end{matrix}\right] =
\sum\limits_{i=1,j=1}^{n,m}\left[\begin{matrix}
s_1 · t_1 & s_1 · t_2 & \cdots & s_1 · t_m \\
s_2 · t_1 & s_2 · t_2 & \cdots & s_2 · t_m \\
\vdots & \vdots & \ddots & \vdots \\
s_n · t_1 & s_n · t_2 & \cdots & s_n · t_m \\
\end{matrix}\right]$

级数的乘积沿左上正方形对角线相加。

$\sum\limits_{i=1}^{+∞} s_i · \sum\limits_{j=1}^{+∞} t_j = \sum\limits_{l=1}^{+∞} \left[ \sum\limits_{k=1}^l s_k · t_{l-k+1} \right] = \sum\limits_{l=1}^{+∞} \left[ \sum\limits_{i+j=l+1} s_i · t_j \right] = (s_1 · t_1) + (s_1 · t_2 + s_2 · t_1) + \cdots + (s_1 · t_l + s_2 · t_{l-1} + \cdots + s_{l-1} · t_2 + s_l · t_1) + \cdots$

级数的乘积按左上三角形体横向相加。

$\sum\limits_{i=1}^{+∞} s_i · \sum\limits_{j=1}^{+∞} t_j = \lim\limits_{l⇝+∞} \sum\limits_{i=1}^l \left[ s_i · \sum\limits_{j=1}^{l-i+1} t_j \right] = \lim\limits_{l⇝+∞} \sum\limits_{i=1}^l s_i · T_{l-i+1} = \lim\limits_{l⇝+∞} [ s_1 · (t_1 + t_2 + ··· + t_l) + s_2 · (t_1 + t_2 + ··· + t_{l-1}) + ··· + s_{l-1} · (t_1 + t_2) + s_l · (t_1) ]$

级数的乘积按左上三角形体竖向相加。

$\sum\limits_{i=1}^{+∞} s_i · \sum\limits_{j=1}^{+∞} t_j = \lim\limits_{l⇝+∞} \sum\limits_{j=1}^l \left[ t_j · \sum\limits_{i=1}^{l-j+1} s_i \right] = \lim\limits_{l⇝+∞} \sum\limits_{j=1}^l t_j · S_{l-j+1} = \lim\limits_{l⇝+∞} [ t_1 · (s_1 + s_2 + ··· s_l) + t_2 · (s_1 + s_2 + ··· + s_{l-1}) + ··· + t_{l-1} · (s_1 + s_2) + t_l · (s_1) ]$

级数的乘积沿左上正方形外边缘相加。

$\sum\limits_{i=1}^{+∞} s_i · \sum\limits_{j=1}^{+∞} t_j = \sum\limits_{l=1}^{+∞} \left[ - s_l · t_l + \sum\limits_{k=1}^l (s_k · t_l + s_l · t_k) \right] = (s_1 · t_1) + (s_1 · t_2 + s_2 · t_2 + s_2 · t_1) + \cdots + (s_1 · t_l + s_2 · t_l + \cdots + s_l · t_l + \cdots + s_l · t_2 + s_l · t_1) + \cdots$

级数的乘积按左上正方形体横向相加。

$\sum\limits_{i=1}^{+∞} s_i · \sum\limits_{j=1}^{+∞} t_j = \lim\limits_{l⇝+∞} \sum\limits_{i=1}^l \left[ s_i · \sum\limits_{j=1}^l t_j \right] = \lim\limits_{l⇝+∞} \sum\limits_{i=1}^l s_i · T_l = \lim\limits_{l⇝+∞} \left[ s_1 · (t_1 + t_2 + ··· + t_l) + s_2 · (t_1 + t_2 + ··· + t_l) + ··· + s_{l-1} · (t_1 + t2 + ··· + t_l) + s_l · (t_1 + t_2 + ··· + t_l) \right]$

级数的乘积按左上正方形体竖向相加。

$\sum\limits_{i=1}^{+∞} s_i · \sum\limits_{j=1}^{+∞} t_j = \lim\limits_{l⇝+∞} \sum\limits_{j=1}^l \left[ t_j · \sum\limits_{i=1}^l s_i \right] = \lim\limits_{l⇝+∞} \sum\limits_{j=1}^l t_j · S_l = \lim\limits_{l⇝+∞} [ t_1 · (s_1 + s_2 + ··· + s_l) + t_2 · (s_1 + s_2 + ··· + s_l) + ··· + t_{l-1} · (s_1 + s_2 + ··· + s_l) + t_l · (s_1 + s_2 + ··· + s_l) ]$

### 无穷乘积的收敛

若无穷级数之一绝对收敛，且其余无穷级数条件收敛，则无穷乘积必定绝对收敛。

$\sum\limits_{i=1}^{+∞} | s_i | ⇝ S_{||} ∧ \sum\limits_{j=1}^{+∞} t_j ⇝ T ⇒ \lim\limits_{l⇝+∞} \sum\limits_{i=1}^l \left| s_i · \sum\limits_{j=1}^l t_j \right| ⇝ ST_{||}$

| $⇓$  | $\sum\limits_{i=1}^{+∞} s_i · \sum\limits_{j=1}^{+∞} t_j = \lim\limits_{l⇝+∞} \sum\limits_{i=1}^l \left[ s_i · \sum\limits_{j=1}^l t_j \right] = \lim\limits_{l⇝+∞} \sum\limits_{i=1}^l s_i · T_l$ | $⇒$  | $\lim\limits_{l⇝+∞} \sum\limits_{i=1}^l \left| s_i · \sum\limits_{j=1}^l t_j \right| = \lim\limits_{l⇝+∞} \sum\limits_{i=1}^l | s_i · T_l |$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\lim\limits_{l⇝+∞} \sum\limits_{i=1}^l | s_i · T_l | = \lim\limits_{l⇝+∞} \left[ | T | · \sum\limits_{i=1}^l | s_i | + \sum\limits_{i=1}^l | s_i | · (|T_l| - |T|) \right]$ |      |                                                              |
| $⇓$  | $\lim\limits_{l⇝+∞} \sum\limits_{i=1}^l | s_i · T_l | ≤ \lim\limits_{l⇝+∞} \left[ | T | · \sum\limits_{i=1}^l | s_i | + \sum\limits_{i=1}^L | s_i | · (|| T_l | - | T ||) + \sum\limits_{i=L+1}^l | s_i | · (|| T_l | - | T ||) \right]$ |      |                                                              |
| $⇓$  | $\lim\limits_{l⇝+∞} \sum\limits_{i=1}^l | s_i · T_l | ≤ | T | · \sum\limits_{i=1}^{+∞} | s_i | + ε_1 · \sum\limits_{i=1}^L | s_i | + \mathrm{Sup.} · \sum\limits_{i=L+1}^l | s_i |$ | $⇐$  | $∃L∈ℕ;[ l>L ⇒ || T_l | - | T || < ε_1 ] ∧ [ l≤L ⇒ || T_l | - | T || ≤ \mathrm{Sup.}]$ |
| $⇓$  | $\lim\limits_{l⇝+∞} \sum\limits_{i=1}^l | s_i · T_l | ≤ | T | · \sum\limits_{i=1}^{+∞} | s_i | + ε_1 · S_{||} + \mathrm{Sup.} · ε_2$ |      |                                                              |
| $⇓$  | $\lim\limits_{l⇝+∞} \sum\limits_{i=1}^l | s_i · T_l | ≤ | T | · S_{||} + ε$ | $⇐$  | $ε = ε_1 · S_{||} + \mathrm{Sup.} · ε_2$                     |
| $⇓$  | $\lim\limits_{l⇝+∞} \sum\limits_{i=1}^l \left| s_i · \sum\limits_{j=1}^l t_j \right| ⇝ ST_{||}$ |      |                                                              |

若无穷级数全都条件收敛，则无穷乘积未必条件收敛。

典例：无穷级数$\sum\limits_{i=1}^{+∞} s_i = \sum\limits_{i=1}^{+∞} \dfrac{(-1)^{i}}{\sqrt{i}} ⇝ S$条件收敛，无穷级数$\sum\limits_{j=1}^{+∞} t_i = \sum\limits_{j=1}^{+∞} \dfrac{(-1)^j}{\sqrt{j}} ⇝ T$条件收敛, 两者的乘积沿对角线相加$\sum\limits_{i=1}^{+∞} s_i · \sum\limits_{j=1}^{+∞} t_j \not⇝ ST$。

$\lim\limits_{l⇝+∞} \left| \sum\limits_{k=1}^l s_k · t_{l-k+1} \right| = \lim\limits_{l⇝+∞} \left| \sum\limits_{k=1}^l \dfrac{(-1)^k}{\sqrt{k}} · \dfrac{(-1)^{l-k+1}}{\sqrt{l-k+1}} \right| = \lim\limits_{l⇝+∞} \sum\limits_{k=1}^l \dfrac{1}{\sqrt{k · (l - k + 1)}} ≥ \lim\limits_{l⇝+∞} \dfrac{l}{\frac{k + (l - k + 1)}{2}} ⇝ 2 ≠ 0$

### 无穷乘积的性质



















