---
layout:  zh_post
Topic :  收敛极限
Title :  无穷级数
Update:  2021-02-09T01:21:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---



### 数列极限的性质

若$\lim\limits_{n⇝+∞} S_n ⇝ S$，且 $\lim\limits_{n⇝+∞} T_n ⇝ T$。

$\lim\limits_{n⇝+∞} [ S_n + T_n ] = \lim\limits_{n⇝+∞} S_n + \lim\limits_{n⇝+∞} T_n = S + T$

$\lim\limits_{n⇝+∞} [ S_n - T_n ] = \lim\limits_{n⇝+∞} S_n - \lim\limits_{n⇝+∞} T_n = S - T$

$\lim\limits_{n⇝+∞} [ S_n · T_n ] = \lim\limits_{n⇝∞} S_n · \lim\limits_{n⇝∞} T_n = S · T$

$\lim\limits_{n⇝+∞} \dfrac{S_n}{T_n} = \dfrac{\lim\limits_{n⇝∞} S_n}{\lim\limits_{n⇝∞} T_n} = \dfrac{S}{T}$

$\lim\limits_{n⇝+∞} [ \mathrm{Con.} · S_n ] = \mathrm{Con.} · \lim\limits_{n⇝+∞} S_n$

| $⇓$  | $[ ∀ε_1>0;∃N∈ℕ;∀n≥N; | S_n - S | < ε_1 ] ∧ [∀ε_2>0;∃N∈ℕ;∀n≥N; | T_n - T | < ε_2]$ |
| :--: | ------------------------------------------------------------ |
| $⇓$  | $∀ε>0;∃N∈ℕ;∀n≥N; | (S_n + T_n) - (S + T) | < | S_n - S | + | T_n - T | < ε_1 + ε_2 = ε$ |
| $⇓$  | $∀ε>0;∃N∈ℕ;∀n≥N; | (S_n - T_n) - (S - T) | < | S_n - S | + | T_n - T | < ε_1 + ε_2 = ε$ |
| $⇓$  | $∀ε>0;∃N∈ℕ;∀n≥N; | S_n · T_n - S · T | = | (S_n · T_n - S_n · T) + (S_n · T - S · T) | ≤ | S_n | · | T_n - T | + | S_n - S | · | T | ≤ \mathrm{Sup.} · ε_2 + ε_1 · | T | = ε$ |
| $⇓$  | $∀ε>0;∃N∈ℕ;∀n≥N; \left| \dfrac{S_n}{T_n} - \dfrac{S}{T} \right| = \dfrac{| S_n · T - S · T_n |}{| T_n | · | T |} = \dfrac{| (S_n · T - S · T) + (S · T - S · T_n) |}{| T_n | · | T |} = \dfrac{| S_n - S | · | T | + | S | · | T - T_n |}{| T_n | · | T |} ≤ \dfrac{ε_1 · | T | + | S | · ε_2}{\mathrm{Inf.} · | T |} = ε$ |

典例：数列$\lim\limits_{n⇝+∞} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i \right] = \lim\limits_{n⇝+∞} s_n \mathop{⇝}\limits^{s≠∞} s$

| $⇓$  |  $\lim\limits_{n⇝+∞} s_n ⇝ 0$ | $⇒$  | $∀ε>0;∃N∈ℕ;∀n≥N; \left| \dfrac{s_0 + ··· + s_n}{n + 1} \right| ≤ \left| \dfrac{s_0 + ··· + s_{N-1}}{n + 1} \right| + \left| \dfrac{s_N + ··· + s_n}{n + 1} \right| ≤ \dfrac{\mathrm{Sup.}}{n + 1} + \dfrac{n - N + 1}{n + 1} · ε_1 = ε$ |
| :--: | ----------------------------: | :--: | :----------------------------------------------------------- |
| $⇓$  |  $\lim\limits_{n⇝+∞} s_n ⇝ s$ | $⇔$  | $\lim\limits_{n⇝+∞} (s_n - s) ⇝ 0$                           |
| $⇓$  | $\lim\limits_{n⇝+∞} s_n ⇝ +∞$ | $⇒$  | $∃ε>0;∀N∈ℕ;∃n≥N; \dfrac{s_0 + ··· + s_n}{n + 1} = \dfrac{s_0 + ··· + s_{N-1}}{n + 1} + \dfrac{s_N + ··· + s_n}{n + 1} > \dfrac{\mathrm{Inf.}}{n + 1} + \dfrac{n - N + 1}{n+1} · ε_2 = ε$ |
| $⇓$  | $\lim\limits_{n⇝+∞} s_n ⇝ -∞$ | $⇔$  | $\lim\limits_{n⇝+∞} -s_n ⇝ +∞$                               |
| $⇓$  |                               |      | $\lim\limits_{n⇝+∞} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i \right] = \lim\limits_{n⇝+∞} s_n \mathop{⇝}\limits^{s≠∞} s$ |

反例：数列$\lim\limits_{n⇝+∞} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n (-1)^i · i \right]$

$\lim\limits_{n⇝+∞} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n (-1)^i · i \right] ≈ \lim\limits_{2 · n⇝+∞} \dfrac{0 + (-1 + 2) + (-3 + 4) + ··· + [-(2 · n + 1) + 2 · n]}{2 · n + 1} = \lim\limits_{n⇝+∞} \dfrac{n}{2 · n + 1} ⇝ \dfrac{1}{2} ≠ ∞ ⇜ \lim\limits_{n⇝+∞} (-i)^i · i$

典例：数列$\lim\limits_{n⇝+∞} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i · t_{n - i} \right] = \lim\limits_{n⇝+∞} s_n · t_n = \lim\limits_{n⇝+∞} s_n · \lim\limits_{n⇝+∞} t_n \mathop{⇝}\limits_{t≠∞}^{s≠∞} s·t$

| $⇓$  | $\left[ \lim\limits_{n⇝+∞} s_n ⇝ 0 \right] ∧ \left[ \lim\limits_{n⇝+∞} t_n ⇝ t \right]$ | $⇒$  | $\lim\limits_{n⇝+∞} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i · t_{n-i} \right] ≤ \lim\limits_{n⇝+∞} \left[ \dfrac{\mathrm{Sup.}\lbrace t_i \rbrace}{n + 1} · \sum\limits_{i=0}^n s_i \right] = \mathrm{Sup.}\lbrace t_i \rbrace \lim\limits_{n⇝+∞} · s_n ⇝ 0$ |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇓$  | $\left[ \lim\limits_{n⇝+∞} s_n ⇝ s \right] ⇔ \left[ \lim\limits_{n⇝+∞} (s_n - s) ⇝ 0 \right]$ | $⇒$  | $\lim\limits_{n⇝+∞} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i · t_{n-i} \right] = \lim\limits_{n⇝+∞} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n (s_i - s) · t_{n-i} + \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s · t_{n-i} \right] ⇝ s · t$ |
| $⇓$  |                                                              |      | $\lim\limits_{n⇝+∞} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i · t_{n-i} \right] = \lim\limits_{n⇝+∞} s_n · t_n = \lim\limits_{n⇝+∞} s_n · \lim\limits_{n⇝+∞} t_n \mathop{⇝}\limits_{t≠∞}^{s≠∞} s · t$ |

### 无穷级数

无穷级数的部分和

$S_n ≡ \sum\limits_{i=0}^n s_i$

无穷级数的极限

$\lim\limits_{n ⇝ +∞} S_n ≡ \lim\limits_{n ⇝ +∞} \sum\limits_{i=0}^{n} s_i ≡ \sum\limits_{i=0}^{+∞} s_i$

无穷级数的下极限与上极限

$\varliminf\limits_{n ⇝ +∞} S_n ≡ \mathop{\lim\inf}\limits_{n ⇝ +∞} S_n ≡ \lim\limits_{n ⇝ +∞}\inf\limits_{m ≥ n} S_m ≡ \lim\limits_{n ⇝ +∞}\inf\limits_{m ≥ n} \sum\limits_{i = 0}^m s_i$

$\varlimsup\limits_{n⇝+∞} S_n ≡ \mathop{\lim\sup}\limits_{n⇝+∞} S_n ≡ \lim\limits_{n⇝+∞}\sup\limits_{m≥n} S_m ≡ \lim\limits_{n⇝+∞}\sup\limits_{m≥n} \sum\limits_{i=0}^m s_i$

$\dfrac{1}{\varlimsup\limits_{n⇝+∞} T_n} = \varliminf\limits_{n⇝+∞} \dfrac{1}{T_n} = \varliminf\limits_{n⇝+∞}  S_n ≤ \varlimsup\limits_{n⇝+∞} S_n = \varlimsup\limits_{n⇝+∞} \dfrac{1}{T_n} = \dfrac{1}{\varliminf\limits_{n⇝+∞} T_n}$

典例：无穷级数的下极限与上极限

$\varliminf\limits_{n ⇝ +∞} \dfrac{1}{n} ⇝ 0, \varlimsup\limits_{n ⇝ +∞} \dfrac{1}{n} ⇝ 0$

$\varliminf\limits_{n ⇝ +∞} \sin\dfrac{n · \pi}{4} ⇝ -1, \varlimsup\limits_{n ⇝ +∞} \sin\dfrac{n · \pi}{4} ⇝ +1$

无穷级数的极限之等价表述形式

$∀ε>0;∃N∈ℕ;∀n≥N; |S_n - S| < ε$

$∀ε>0;∃N∈ℕ;∀n≥N; \left| \sum\limits_{i=0}^{n} s_i - S \right| < ε$

无穷级数收敛

$\lim\limits_{n ⇝ +∞} S_n ⇝ S$ 也即 $\lim\limits_{n ⇝ +∞} |S_n - S| ⇝ 0$

$\sum\limits_{i=0}^{+∞} s_i ⇝ S$ 也即 $\lim\limits_{n⇝+∞} \left| \sum\limits_{i=0}^n s_i - S \right| ⇝ 0$

$\varliminf\limits_{n ⇝ +∞} S_n = \lim\limits_{n ⇝ +∞} S_n = \varlimsup\limits_{n ⇝ +∞} S_n$

无穷级数发散

$\lim\limits_{n ⇝ +∞} S_n \not⇝ S$ 也即 $\lim\limits_{n ⇝ +∞} |S_n - S| \not⇝ 0$

$\sum\limits_{i=0}^{+∞} s_i \not⇝ S$ 也即 $\lim\limits_{n⇝+∞} \left| \sum\limits_{i=0}^n s_i - S \right| \not⇝ 0$

$\varliminf\limits_{n ⇝ +∞} S_n ≠ \varlimsup\limits_{n ⇝ +∞} S_n$

### 无穷级数收敛的性质

若无穷级数收敛，则其部分和的绝对值收敛。

$\lim\limits_{n⇝+∞} S_n ⇝ S ⇒ \lim\limits_{n⇝+∞} | S_n | ⇝ | S |$

$[ ∀ε>0;∃N∈ℕ;∀n≥N; | S_n - S | < ε ] ⇒ [  ∀ε>0;∃N∈ℕ;∀n≥N; || S_n | - | S || ≤ | S_n - S | < ε]$

若无穷级数收敛，则其通项收敛于零。

$\lim\limits_{n ⇝ +∞} S_n ⇝ S ⇒ \lim\limits_{i ⇝ +∞} s_i ⇝ 0$

若通项不收敛于零，则无穷级数发散。

$\lim\limits_{i ⇝ +∞} s_i \not⇝ 0 ⇒ \lim\limits_{n ⇝ +∞} S_n \not⇝ S$

将无穷级数的有限多项改变，其敛散性不变。

$\sum\limits_{i = n}^{+∞} s_i ⇝ S ⇔ \sum\limits_{i = m}^{+∞} s_i ⇝ T$

若无穷级数收敛，再将通项保序归组，则其收敛性不变。

$\sum\limits_{i=0}^{+∞} s_i ⇝ S ⇒ \sum\limits_{i=0}^{+∞} (s_{i_0} + ⋯ + s_{i_j}) ⇝ S$

若无穷级数各组内的通项正负性相同，则其敛散性不变。

$\sum\limits_{i=0}^{+∞} s_i ⇝ S ⇔ \sum\limits_{i=0}^{+∞} (s_{i_0} + ⋯ + s_{i_j}) ⇝ S$

特例：无穷级数$\sum\limits_{i=0}^{+∞} (-1)^i \not⇝ S$。

$\lim\limits_{i ⇝ +∞} S_{2 · i - 1} ⇝ -1, \lim\limits_{i ⇝ +∞} S_{2 · i} ⇝ 0$

### 无穷级数的数列审敛法

若无穷级数收敛，则其部分和的极限之差为无穷小。

$[∀ε>0;∃N∈ℕ;∀n≥N; |S_n - S| < ε] ⇔ [∀ε>0;∃N∈ℕ;∀n≥N;∀m>N;|S_m - S_n| < ε]$

$[∀ε>0;∃N∈ℕ;∀n≥N; \left| \sum\limits_{i=0}^n s_i - S \right| < ε] ⇔ [∀ε>0;∃N∈ℕ;∀n≥N;∀m>n; \left| \sum\limits_{i=n}^m s_i \right| < ε]$

$[∀ε>0;∃N∈ℕ; n ≥ N ⇒ | S_n - S | < ε] ⇔ [∀ε>0;∃N∈ℕ; n ≥ N ∧ m > N ⇒ |S_m - S_n| < ε]$

$[∀ε>0;∃N∈ℕ; n ≥ N ⇒ \left| \sum\limits_{i=0}^n s_i - S \right| < ε] ⇔ [∀ε>0;∃N∈ℕ; n ≥ N ∧ m > n ⇒ \left| \sum\limits_{i=n}^m s_i \right| < ε]$

若无穷级数发散，则其部分和的极限之差非无穷小。

$[∃ε>0;∀N∈ℕ;∃n≥N; |S_n - S| ≥ ε] ⇔ [∃ε>0;∀N∈ℕ;∃n≥N;∃m>N; |S_m - S_n| ≥ ε]$

$[∃ε>0;∀N∈ℕ;∃n≥N; \left| \sum\limits_{i=0}^n s_i - S \right| ≥ ε] ⇔ [∃ε>0;∀N∈ℕ;∃n≥N;∃m>n; \left| \sum\limits_{i=n}^m s_i \right| ≥ ε$

$[∃ε>0;∀N∈ℕ; n ≥ N ∧ | S_n - S | ≥ ε] ⇔ [∃ε>0;∀N∈ℕ; n ≥ N ∧ m > N ∧ |S_m - S_n| ≥ ε]$

$[∃ε>0;∀N∈ℕ; n ≥ N ∧ \left| \sum\limits_{i=0}^n s_i - S \right| ≥ ε] ⇔ [∃ε>0;∀N∈ℕ; n ≥ N ∧ m > n ∧ \left| \sum\limits_{i=n}^m s_i \right| ≥ ε]$

必要性证明，根据三角不等关系式。

| $⇓$  | $∀ε_1>0;∃N∈ℕ;∀n≥N; \lvert S_n - S \rvert < ε_1] ∧ [∀ε_2>0;∃N∈ℕ;∀m>N; \lvert S_m - S \rvert < ε_2$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε=ε_1 + ε_2;∃N∈ℕ;∀n≥N;∀m>N; \lvert S_m - S_n \rvert ≤ \lvert S_m - S \rvert + \lvert S_n - S \rvert < ε_1 + ε_2 = ε$ |
| $⇓$  | $∀ε>0;∃N∈ℕ;∀n≥N;∀m>N; \lvert S_m - S_n \rvert < ε$           |

充分性证明，根据上下确界关系式。

| $⇓$  | $∀ε>0;∃N∈ℕ;∀n≥N;∀m>N; \lvert S_m - S_n \rvert < ε$           |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∃S;∀ε=ε_1+ε_2;∃N∈ℕ;∀n≥N;∀m>N; S - ε_1 < S_m, S_n < S + ε_2$ |
| $⇓$  | $∀ε>0;∃N∈ℕ;∀n≥N;\lvert S_n - S \rvert < ε$                   |

### 无穷级数的分部审敛法

无穷级数的分部求和公式

$\sum\limits_{i=n}^m s_i · t_i \mathop{===}\limits^{S_{-1}≡0} \sum\limits_{i=n}^m (S_i - S_{i-1}) · t_i = S_m · t_m + \sum\limits_{i=n}^{m-1} S_i · t_i - \sum\limits_{i=n}^{m-1} S_i · t_{i+1} - S_{n-1} · t_n = (S_m · t_m - S_{n-1} · t_n) + \sum\limits_{i=n}^{m-1} S_i · (t_i - t_{i+1}) $

$\left| \sum\limits_{i=n}^m s_i · t_i \right| ≤ | S_m · t_m | + | S_{n-1} · t_n | + \left| \sum\limits_{i=n}^{m-1} S_i · (t_i - t_{i+1}) \right| ≤ | S_m | · | t_m | + | S_{n-1} | · | t_n | + \sum\limits_{i=n}^{m-1} | S_i | · | t_i - t_{i+1} |$

| $⇓$  |                                                              |                                                        | $[ ∃N∈ℕ;∀i>N; | S_i | ≤ \mathrm{Sup.} ∧ t_i ≥ t_{i+1} ] ⊕ [ ∃N∈ℕ;∀i>N; | S_i | ≤ \mathrm{Sup.} ∧ t_i ≤ t_{i+1} ]$ |
| :--: | -----------------------------------------------------------: | :----------------------------------------------------: | :----------------------------------------------------------- |
| $⇓$  |                                                              |                                                        | $\left| \sum\limits_{i=n}^m s_i · t_i \right| ≤ \mathrm{Sup.} · \left[ |t_m| + |t_n| + \left| \sum\limits_{i=n}^{m-1} (t_i - t_{i+1}) \right| \right] ≤ \mathrm{Sup.} · 2 · \left[ |t_m| + |t_n| \right]$ |
| $⇓$  | $\varlimsup\limits_{i ⇝ +∞} |S_i| ≤ \mathrm{Sup.} ∧ t_i ⪌ t_{i+1} ∧ \lim\limits_{i ⇝ +∞} t_i ⇝ 0$ |                          $⇒$                           | $∀ε>0;∃N∈ℕ;∀n≥N;∀m≥n; \left| \sum\limits_{i=n}^m s_i · t_i \right| < \mathrm{Sup.} · 2 · (ε_1 + ε_2) = ε$ |
| $⇓$  | $\varlimsup\limits_{i ⇝ +∞} |S_i| ≤ \mathrm{Sup.} ∧ t_i ⪌ t_{i+1} ∧ \lim\limits_{i ⇝ +∞} t_i ⇝ 0$ |                          $⇒$                           | $\sum\limits_{i=0}^{+∞} s_i · t_i ⇝ ST$                      |
| $⇓$  | $\lim\limits_{i ⇝ +∞} S_i ⇝ S ∧ t_i ⪌ t_{i+1} ∧ \lim\limits_{i ⇝ +∞} t_i ⇝ t$ | $\mathop{⇒}\limits_{\lim\limits_{i⇝+∞} (t_i - t) ⇝ 0}$ | $\sum\limits_{i=0}^{+∞} s_i · t_i = t · \sum\limits_{i=0}^{+∞} s_i + \sum\limits_{i=0}^{+∞} [ s_i · (t_i - t) ] ⇝ ST$ |
| $⇓$  | $\lim\limits_{i ⇝ +∞} S_i ⇝ S ∧ t_i ⪌ t_{i+1} ∧ \varlimsup\limits_{i⇝+∞} | t_i | ≤ \mathrm{Sup.}$ |    $\mathop{⇒}\limits_{\lim\limits_{i⇝+∞} t_i ⇝ t}$    | $\sum\limits_{i=0}^{+∞} s_i · t_i ⇝ ST$                      |

若部分和$\sum\limits_{i=0}^n s_i$有确界，且$t_i$单调趋于零，则无穷级数$\sum\limits_{i=0}^{+∞} s_i · t_i$收敛。

若无穷级数$\sum\limits_{i=0}^{+∞} s_i$收敛，且$t_i$单调有确界，则无穷级数$\sum\limits_{i=0}^{+∞} s_i · t_i$收敛。

特例：若$t_i$单调趋于零，则交错级数$\sum\limits_{i=0}^{+∞} (-1)^i · t_i$收敛。

### 无穷级数的绝对收敛与条件收敛

若无穷级数绝对收敛，则其本身必定收敛。

$\sum\limits_{i=0}^{+∞} |s_i| ⇝ S_{||} ⇒ \sum\limits_{i=0}^{+∞} s_i ⇝ S$

$\left[ ∀ε>0;∃N∈ℕ;∀n≥N;∀m>n; \left| \sum\limits_{i=n}^m |s_i| \right| < ε \right] ⇒ \left[ ∀ε>0;∃N∈ℕ;∀n≥N;∀m>n; \left| \sum\limits_{i=n}^m s_i \right| ≤ \left| \sum\limits_{i=n}^{m} |s_i| \right| < ε \right]$

若无穷级数本身收敛，则其未必绝对收敛。

$\sum\limits_{i=0}^{+∞} s_i ⇝ S \not⇒ \sum\limits_{i=0}^{+∞} |s_i| ⇝ S_{||}$

$\left[ ∀ε>0;∃N∈ℕ;∀n≥N;∀m>n; \left| \sum\limits_{i=n}^m s_i \right| < ε \right] \not⇒ \left[ ∀ε>0;∃N∈ℕ;∀n≥N;∀m>n; \left| \sum\limits_{i=n}^m |s_i| \right| < ε \right]$

### 无穷级数绝对收敛与条件收敛的性质

无穷级数的正数项$+s_i^+ ≡ +\dfrac{1}{2} · (|s_i| + s_i)$，无穷级数的负数项$-s_i^- ≡ -\dfrac{1}{2} · (|s_i| - s_i)$。

无穷级数的一般项$s_i = s_i^+ - s_i^-$，无穷级数的绝对项$|s_i| = s_i^+ + s_i^-$。

若无穷级数绝对收敛，则其正数项级数与负数项级数均收敛，反之亦然。

$\sum\limits_{i=0}^{+∞} |s_i| = \sum\limits_{i=0}^{+∞} (s_i^+ + s_i^-) ⇝ S_{||} ⇔ \left[ \sum\limits_{i=0}^{+∞} s_i^+ ⇝ S_{+} \right] ∧ \left[ \sum\limits_{i=0}^{+∞} s^- ⇝ S_- \right]$

若无穷级数条件收敛，则其正数项级数与负数项级数均发散，反之不对。

$\sum\limits_{i=0}^{+∞} s_i = \sum\limits_{i=0}^{+∞} (s_i^+ - s_i^-) ⇝ S ⇒ \left[ \sum\limits_{i=0}^{+∞} s_i^+ \not⇝ S_+ \right] ∧ \left[ \sum\limits_{i=0}^{+∞} s_i^- \not⇝ S_- \right] ⇒ \left[ \sum\limits_{i=0}^{+∞} s_i^+ ⇝ +∞ \right] ∧ \left[ \sum\limits_{i=0}^{+∞} s_i^- ⇝ +∞ \right]$

| $⇓$  | $\sum\limits_{i=0}^{+∞} | s_i | ⇝ S_{||} ⇒ \sum\limits_{i=0}^{+∞} s_i^+ ⇝ S_+$ | $⇐$  | $0 ≤ s_i^+ ≤ | s_i |$                                        |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇓$  | $\sum\limits_{i=0}^{+∞} | s_i | ⇝ S_{||} ⇒ \sum\limits_{i=0}^{+∞} s^- ⇝ S_-$ | $⇐$  | $0 ≤ s_i^- ≤ | s_i |$                                        |
| $⇓$  | $\sum\limits_{i=0}^{+∞} | s_i | ⇝ S_{||} ⇐ \sum\limits_{i=0}^{+∞} s_i^+ ⇝ S_+ ∧ \sum\limits_{i=0}^{+∞} s_i^- ⇝ S_-$ | $⇐$  | $\sum\limits_{i=0}^{+∞} | s_i | = \sum\limits_{i=0}^{+∞} s_i^+ + \sum\limits_{i=0}^{+∞} s_i^-$ |
| $⇓$  | $\sum\limits_{i=0}^{+∞} | s_i | ⇝ S_{||} ⇔ \sum\limits_{i=0}^{+∞} s_i^+ ⇝ S_+ ∧ \sum\limits_{i=0}^{+∞} s_i^- ⇝ S_-$ | $⇒$  | $\sum\limits_{i=0}^{+∞} | s_i | \not⇝ S_{||} ⇒ \left[ \sum\limits_{i=0}^{+∞} s_i^+ \not⇝ S_+ ∨ \sum\limits_{i=0}^{+∞} s_i^- \not⇝ S_- \right]$ |
| $⇓$  | $\sum\limits_{i=0}^{+∞} s_i ⇝ S ⇒ \left[ \sum\limits_{i=0}^{+∞} s_i^+ ⇝ S_+ ∧ \sum\limits_{i=0}^{+∞} s_i^- ⇝ S_- \right] ⊕ \left[ \sum\limits_{i=0}^{+∞} s_i^+ \not⇝ S_+ ∧ \sum\limits_{i=0}^{+∞} s_i^- \not⇝ S_- \right]$ | $⇐$  | $\sum\limits_{i=0}^{+∞} s_i = \sum\limits_{i=0}^{+∞} s_i^+ - \sum\limits_{i=0}^{+∞} s_i^-$ |
| $⇓$  | $\sum\limits_{i=0}^{+∞} s_i ⇝ S ∧ \sum\limits_{i=0}^{+∞} | s_i | \not⇝ S_{||} ⇒ \left[ \sum\limits_{i=0}^{+∞} s_i^+ \not⇝ S_+ ∧ \sum\limits_{i=0}^{+∞} s_i^- \not⇝ S_- \right]$ |      |                                                              |
| $⇓$  | $\sum\limits_{i=0}^{+∞} s_i ⇝ S ∧ \sum\limits_{i=0}^{+∞} | s_i | \not⇝ S_{||} ⇒ \left[ \sum\limits_{i=0}^{+∞} s_i^+ ⇝ +∞ ∧ \sum\limits_{i=0}^{+∞} s_i^- ⇝ +∞ \right]$ | $⇐$  | $0 ≤ s_i^+ ∧ 0 ≤ s_i^-$                                      |

若无穷级数绝对收敛，则交换任意多项的次序，其极限不变并且保持绝对收敛。

若无穷级数条件收敛，则交换任意多项的次序，可使其趋近于任意给定的极限。

| $⇓$  |                                              | $\sum\limits_{i=0}^{+∞} s_i ⇝ S ⇒ \lim\limits_{i⇝+∞} s_i ⇝ 0$ |
| :--: | -------------------------------------------: | :----------------------------------------------------------- |
| $⇓$  |                                              | $\sum\limits_{i=0}^{+∞} s_i ⇝ S ∧ \sum\limits_{i=0}^{+∞} | s_i | \not⇝ S_{||} ⇒ \sum\limits_{i=0}^{+∞} s_i^+ ⇝ +∞ ∧ \sum\limits_{i=0}^{+∞} s_i^- ⇝ +∞$ |
| $⇓$  | $∃n_0^+∈ℕ;∃n_0^-∈ℕ;∃n_0≤\max(n_0^+, n_0^-);$ | $\left| \left( \sum\limits_{j=0}^{n_0^+} s_j^+ - \sum\limits_{j=0}^{n_0^-} s_j^- \right) - T \right| < | s_{n_0} |$ |
| $⇓$  | $∃n_1^+∈ℕ;∃n_1^-∈ℕ;∃n_1≤\max(n_1^+, n_1^-);$ | $\left| \left( \sum\limits_{j=0}^{n_0^+} s_j^+ - \sum\limits_{j=0}^{n_0^-} s_j^- \right) + \left( \sum\limits_{j=n_0^+ + 1}^{n_1^+} s_j^+ - \sum\limits_{j=n_0^- + 1}^{n_1^-} s_j^- \right) - T \right| < | s_{n_1} | < | s_{n_0} |$ |
| $⇓$  |                                        $···$ | $···$                                                        |
| $⇓$  |                                              | $\left| \left( \sum\limits_{j=0}^{n_0^+} s_j^+ - \sum\limits_{j=0}^{n_0^-} s_j^- \right) + \left( \sum\limits_{j=n_0^+ + 1}^{n_1^+} s_j^+ - \sum\limits_{j=n_0^- + 1}^{n_1^-} s_j^- \right) + ··· + \left( \sum\limits_{j=n_{m-1}^+ + 1}^{n_m^+} s_j^+ - \sum\limits_{j=n_{m-1}^- + 1}^{n_m^-} s_j^- \right) - T \right| < ε = | s_{n_m} | < ··· < | s_{n_1} | < | s_{n_0} |$ |
| $⇓$  |                                              | $\left( \sum\limits_{j=0}^{+∞} s_j^+ - \sum\limits_{j=0}^{+∞} s_j^- \right) = \sum\limits_{j=0}^{+∞} s_j ⇝ T$ |

特例：无穷级数$\sum\limits_{i=\rlap{≡}{0,}1}^{+∞} \dfrac{(-1)^i}{i} ⇝ S$条件收敛非绝对收敛，交换无穷多项的次序可使其值发生改变。

$\sum\limits_{i=\rlap{≡}{0,}1}^{+∞} s_i^+ = \sum\limits_{i=\rlap{≡}{0,}1}^{+∞} \dfrac{1}{2 · i} ⇝ +∞, \sum\limits_{i=0}^{+∞} s_i^- = \sum\limits_{i=0}^{+∞}  = \dfrac{1}{2 · i + 1} ⇝ +∞$

新无穷级数$- \dfrac{1}{1} + \sum\limits_{i=1}^{+∞} \left( - \dfrac{1}{4 · i - 1} + \dfrac{1}{2 · i} - \dfrac{1}{4 · i + 1} \right) ⇝ \dfrac{3}{2} · S$，由原无穷级数$\sum\limits_{i=\rlap{≡}{0,}1}^{+∞} \dfrac{(-1)^i}{i} ⇝ S$，交换无穷多项的次序得到，两者并非等值。

|                   $S = $ | $- \dfrac{1}{1}$ | $+ \dfrac{1}{2}$ | $- \dfrac{1}{3}$ | $+ \dfrac{1}{4}$ | $- \dfrac{1}{5}$ | $+ \dfrac{1}{6}$ | $- \dfrac{1}{7}$ | $+ \dfrac{1}{8}$ | $- \dfrac{1}{9}$ | $+ \dfrac{1}{10}$ | $- \dfrac{1}{11}$ | $+ \dfrac{1}{12}$ | $- \dfrac{1}{13}$ | $+ \dfrac{1}{14}$ | $- \dfrac{1}{15}$ | $+ \dfrac{1}{16}$ | $- \dfrac{1}{17}$ | $+ \dfrac{1}{18}$ | $- \dfrac{1}{19}$ | $+ \dfrac{1}{20}$ | $-\dfrac{1}{21}$ | $+ \dfrac{1}{22}$ |
| -----------------------: | :--------------: | :--------------: | :--------------: | :--------------: | :--------------: | :--------------: | :--------------: | :--------------: | :--------------: | :---------------: | :---------------: | :---------------: | :---------------: | :---------------: | :---------------: | :---------------: | :---------------: | :---------------: | :---------------: | :---------------: | :--------------: | :---------------: |
| $+) \dfrac{1}{2} · S = $ |                  | $- \dfrac{1}{2}$ |                  | $+ \dfrac{1}{4}$ |                  | $- \dfrac{1}{6}$ |                  | $+ \dfrac{1}{8}$ |                  | $- \dfrac{1}{10}$ |                   | $+ \dfrac{1}{12}$ |                   | $- \dfrac{1}{14}$ |                   | $+ \dfrac{1}{16}$ |                   | $- \dfrac{1}{18}$ |                   | $+ \dfrac{1}{20}$ |                  | $- \dfrac{1}{22}$ |
|    $\dfrac{3}{2} · S = $ | $- \dfrac{1}{1}$ |                  | $- \dfrac{1}{3}$ | $+ \dfrac{1}{2}$ | $- \dfrac{1}{5}$ |                  | $- \dfrac{1}{7}$ | $+ \dfrac{1}{4}$ | $- \dfrac{1}{9}$ |                   | $- \dfrac{1}{11}$ | $+ \dfrac{1}{6}$  | $- \dfrac{1}{13}$ |                   | $- \dfrac{1}{15}$ | $+ \dfrac{1}{8}$  | $- \dfrac{1}{17}$ |                   | $- \dfrac{1}{19}$ | $+ \dfrac{1}{10}$ | $-\dfrac{1}{21}$ |                   |

--------------------------------------------------------------------------------

### 正项级数收敛的性质

若正项级数收敛，则正项级数有上确界，反之亦然。

$\sum\limits_{i=0}^{+∞} s_i ⇝ S ⇔ \sum\limits_{i=0}^{+∞} s_i ≤ \mathrm{Sup.}$

若正项级数发散，则正项级数无上确界，反之亦然。

$\sum\limits_{i=0}^{+∞} s_i \not⇝ S ⇔ \sum\limits_{i=0}^{+∞} s_i \not≤ \mathrm{Sup.}$

### 正项级数的比较审敛法

| $⇑$  |                                       $∃N∈ℕ;∀i≥N; s_i ≤ t_i$ | $⇒$  | $\sum\limits_{i=0}^{+∞} t_i ⇝ T ⇒  \sum\limits_{i=0}^{+∞} s_i ⇝ S$ |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇑$  |                            $∃N∈ℕ;∀i≥N; \dfrac{s_i}{t_i} ≤ 1$ | $⇒$  | $\dfrac{s_i}{t_i} ≤ 1 + o (1)$                               |
| $⇑$  |                          $∃N∈ℕ;∀i≥N; \dfrac{s_i}{t_i} = γ_i$ | $⇒$  | $γ_i = \dfrac{s_i}{t_i} + o (1)$                             |
| $⇑$  |                                 $\dfrac{s_i}{t_i} = γ_i ≤ 1$ | $⇒$  | $\sum\limits_{i=0}^{+∞} t_i ⇝ T ⇒  \sum\limits_{i=0}^{+∞} s_i ⇝ S$ |
| $⇑$  |                                  $\dfrac{s_i}{t_i} =γ_i > 1$ | $⇒$  | $\sum\limits_{i=0}^{+∞} s_i \not⇝ S ⇒  \sum\limits_{i=0}^{+∞} t_i \not⇝ T$ |
| $⇑$  | $\varlimsup\limits_{i ⇝ +∞} \dfrac{s_i}{t_i} = \varlimsup\limits_{i ⇝ +∞} γ_i ⇝ γ < 1$ | $⇒$  | $\sum\limits_{i=0}^{+∞} t_i ⇝ T ⇒  \sum\limits_{i=0}^{+∞} s_i ⇝ S$ |
| $⇑$  | $\varlimsup\limits_{i ⇝ +∞} \dfrac{s_i}{t_i} = \varlimsup\limits_{i ⇝ +∞} γ_i ⇝ γ > 1$ | $⇒$  | $\sum\limits_{i=0}^{+∞} s_i \not⇝ S ⇒  \sum\limits_{i=0}^{+∞} t_i \not⇝ T$ |

特例：正项级数$\sum\limits_{i=0}^{+∞} f(α + i)$与广义积分$\int_α^{+∞} f(x) \mathrm{d}x$的敛散性相同，$f(x)$为区间$[α, +∞)$上非负单调递减的连续函数。

$\left[ \sum\limits_{i=0}^{+∞} f(α + i) ⇝ S \right] ⇔ \left[ \int_α^{+∞} f(x) \mathrm{d}x ⇝ I \right]$

| $⇓$  | $\sum\limits_{i = 0}^{+∞} f(α + i + 1) = \sum\limits_{i = 0}^{+∞} \int\limits_{α + i}^{α + i + 1} f(α + i + 1) \mathrm{d}x ≤ \sum\limits_{i = 0}^{+∞} \int\limits_{α + i}^{α + i + 1} f(x) \mathrm{d}x ≤ \sum\limits_{i = 0}^{+∞} \int\limits_{α + i}^{α + i + 1} f(α + i) \mathrm{d}x = \sum\limits_{i = 0}^{+∞} f(α + i)$ |
| :--: | :----------------------------------------------------------: |
| $⇓$  | $\sum\limits_{i=1}^{+∞} f(α + i) = \sum\limits_{i = 0}^{+∞} f(α + i + 1) ≤ \int\limits_α^{+∞} f(x) \mathrm{d}x ≤ \sum\limits_{i = 0}^{+∞} f(α + i)$ |

特例：正项级数$\sum\limits_{i=\rlap{≡≡}{0,1,}2}^{+∞} \dfrac{1}{i^α · \ln^β i · \ln^γ \ln i}$收敛，仅当$α > 1$，以及$α = 1, β > 1$，以及$α = 1, β = 1, γ > $1。

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

### 正项级数的比值审敛法

| $⇑$  |                $∃N∈ℕ;∀i≥N; s_i ≤ \dfrac{\mathrm{Sup.}}{γ^i}$ | $⇒$  | $γ > 1 ⇒ \sum\limits_{i=1}^{+∞} s_i ⇝ S$ |
| :--: | -----------------------------------------------------------: | :--: | :--------------------------------------- |
| $⇑$  | $∃N∈ℕ;∀i≥N; s_{i+1} · γ^{i + 1} ≤ s_i · γ^i ≤ \mathrm{Sup.}$ | $⇒$  | $\dfrac{s_i}{s_{i+1}} ≥ γ + o (1)$       |
| $⇑$  |              $∃N∈ℕ;∀i≥N; \dfrac{s_i}{s_{i+1}} = γ_i + o (1)$ | $⇒$  | $γ_i = \dfrac{s_i}{s_{i+1}} + o (1)$     |
| $⇑$  |                         $\dfrac{s_i}{s_{i+1}} = γ_i ≥ γ > 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S$         |
| $⇑$  |                             $\dfrac{s_i}{s_{i+1}} = γ_i ≤ 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i \not⇝ S$     |
| $⇑$  | $\varliminf\limits_{i ⇝ +∞} \dfrac{s_i}{s_{i+1}} = \varliminf\limits_{i ⇝ +∞} γ_i ⇝ γ > 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S$         |
| $⇑$  | $\varlimsup\limits_{i ⇝ +∞} \dfrac{s_i}{s_{i+1}} = \varlimsup\limits_{i ⇝ +∞} γ_i ⇝ γ < 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i \not⇝ S$     |

特例：正项级数$\sum\limits_{i=\rlap{≡}{0,}1}^{+∞} \dfrac{1}{i} \not⇝ S$，正项级数$\sum\limits_{i=\rlap{≡}{0,}1}^{+∞} \dfrac{1}{i^2} ⇝ S$。

$\lim\limits_{i ⇝ +∞} γ_i = \lim\limits_{i ⇝ +∞} \dfrac{i + 1}{i} ⇝ 1$

$\lim\limits_{i ⇝ +∞} γ_i = \lim\limits_{i ⇝ +∞} \dfrac{i^2}{(i + 1)^2} = \left[ \lim\limits_{i ⇝ +∞} \dfrac{i}{i + 1} \right]^2 ⇝ 1$

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

### 正项级数的幂值审敛法

| $⇑$  |                $∃N∈ℕ;∀i≥N; s_i ≤ \dfrac{\mathrm{Sup.}}{i^α}$ | $⇒$  | $α > 1 ⇒ \sum\limits_{i=1}^{+∞} s_i ⇝ S$                     |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇑$  | $∃N∈ℕ;∀i≥N; s_{i+1} · (i + 1)^α ≤ s_i · i^α ≤ \mathrm{Sup.}$ | $⇒$  | $\dfrac{s_i}{s_{i+1}} ≥ \dfrac{(i + 1)^α}{i^α} = 1 + \dfrac{α}{i} + o \left( \dfrac{1}{i} \right)$ |
| $⇑$  | $∃N∈ℕ;∀i≥N; \dfrac{s_i}{s_{i + 1}} = 1 + \dfrac{α_i}{i} + o \left( \dfrac{1}{i} \right)$ | $⇒$  | $α_i = i · \left( \dfrac{s_i}{s_{i+1}} - 1 \right) + o (1)$  |
| $⇑$  |  $i · \left( \dfrac{s_i}{s_{i+1}} - 1 \right) = α_i ≥ α > 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S$                             |
| $⇑$  |      $i · \left( \dfrac{s_i}{s_{i+1}} - 1 \right) = α_i ≤ 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i \not⇝ S$                         |
| $⇑$  | $\varliminf\limits_{i ⇝ +∞} i · \left( \dfrac{s_i}{s_{i+1}} - 1 \right) = \varliminf\limits_{i ⇝ +∞} α_i ⇝ α > 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i ⇝ S$                             |
| $⇑$  | $\varlimsup\limits_{i ⇝ +∞} i · \left( \dfrac{s_i}{s_{i+1}} - 1 \right) = \varlimsup\limits_{i ⇝ +∞} α_i ⇝ α < 1$ | $⇒$  | $\sum\limits_{i=1}^{+∞} s_i \not⇝ S$                         |

特例：正项级数$\sum\limits_{i=\rlap{≡≡}{0,1,}2}^{+∞} \dfrac{1}{i} \not⇝ S$，正项级数$\sum\limits_{i=\rlap{≡≡}{0,1,}2}^{+∞} \dfrac{1}{i · \ln^2 i} ⇝ S$。

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

特例：正项级数$\sum\limits_{i=\rlap{≡≡}{0,1,}2}^{+∞} \dfrac{1}{i} \not⇝ S$，正项级数$\sum\limits_{i=\rlap{≡≡}{0,1,}2}^{+∞} \dfrac{1}{i · \ln^2 i} ⇝ S$。

$\lim\limits_{i ⇝ +∞} α_i = \lim\limits_{i ⇝ +∞} \dfrac{\ln i}{\ln i} = \lim\limits_{i ⇝ +∞} 1 ⇝ 1$

$\lim\limits_{i ⇝ +∞} α_i = \lim\limits_{i ⇝ +∞} \dfrac{\ln \left( i · \ln^2 i \right)}{\ln i} = \lim\limits_{i ⇝ +∞} \dfrac{\frac{1}{i · \ln i} · \left( \ln^2 i + i · 2 · \ln i · \frac{1}{i} \right)}{\frac{1}{i}} = \lim\limits_{i ⇝ +∞} \left( 1 + \dfrac{2}{\ln i} \right) ⇝ 1$

$\lim\limits_{i ⇝ +∞} s_i · i^1 = \lim\limits_{i ⇝ +∞} \dfrac{1}{i} · i = \lim\limits_{i ⇝ +∞} 1 ⇝ 1$

### 正项级数的对数审敛法

| $⇑$  |        $∃N∈ℕ;∀i≥N; s_i ≤ \dfrac{\mathrm{Sup.}}{i · \ln^β i}$ | $⇒$  | $β > 1 ⇒ \sum\limits_{i=0}^{+∞} s_i ⇝ S$                     |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇑$  | $∃N∈ℕ;∀i>N; s_{i+1} · (i+1) · \ln^β (i+1) ≤ s_i · i · \ln^β i ≤ \mathrm{Sup.}$ | $⇒$  | $\dfrac{s_i}{s_{i+1}} ≥ \dfrac{i + 1}{i} · \dfrac{\ln^β (i + 1)}{\ln^β i} = 1 + \dfrac{1}{i} + \dfrac{β}{i · \ln i} + o \left( \dfrac{1}{i · \ln i} \right)$ |
| $⇑$  | $∃N∈ℕ;∀i>N; \dfrac{s_i}{s_{i+1}} = 1 + \dfrac{1}{i} + \dfrac{β_i}{i · \ln i} + o \left( \dfrac{1}{i · \ln i} \right)$ | $⇒$  | $β_i = i · \ln i · \left( \dfrac{s_i}{s_{i+1}} - \dfrac{i + 1}{i} \right) + o (1)$ |
| $⇑$  | $i · \ln i · \left( \dfrac{s_i}{s_{i+1}} - \dfrac{i + 1}{i} \right) = β_i ≥ β > 1$ | $⇒$  | $\sum\limits_{i=0}^{+∞} s_i ⇝ S$                             |
| $⇑$  | $i · \ln i · \left( \dfrac{s_i}{s_{i+1}} - \dfrac{i + 1}{i} \right) = β_i ≤ 1$ | $⇒$  | $\sum\limits_{i=0}^{+∞} s_i \not⇝ S$                         |
| $⇑$  | $\varliminf\limits_{i ⇝ +∞} i · \ln i · \left( \dfrac{s_i}{s_{i+1}} - \dfrac{i + 1}{i} \right) = \varliminf\limits_{i ⇝ +∞}β_i ⇝ β > 1$ | $⇒$  | $\sum\limits_{i=0}^{+∞} s_i ⇝ S$                             |
| $⇑$  | $\varlimsup\limits_{i ⇝ +∞} i · \ln i · \left( \dfrac{s_i}{s_{i+1}} - \dfrac{i + 1}{i} \right) = \varlimsup\limits_{i ⇝ +∞} β_i ⇝ β < 1$ | $⇒$  | $\sum\limits_{i=0}^{+∞} s_i \not⇝ S$                         |

附加证明：

$\dfrac{i + 1}{i} · \dfrac{\ln^β (i + 1)}{\ln^β i} = \left( 1 + \dfrac{1}{i} \right) · \left[ \dfrac{\ln i + \ln \left( 1 + \dfrac{1}{i} \right)}{\ln i} \right]^β = \left( 1 + \dfrac{1}{i} \right) · \left[ 1 + \dfrac{1}{i · \ln i} + o \left( \dfrac{1}{i · \ln i} \right) \right]^β = \left( 1 + \dfrac{1}{i} \right) · \left[ 1 + \dfrac{β}{i · \ln i} + o \left( \dfrac{1}{i · \ln i} \right) \right] = 1 + \dfrac{1}{i} + \dfrac{β}{i · \ln i} + o \left( \dfrac{1}{i · \ln i} \right)$

特例：正项级数$\sum\limits_{i=\rlap{≡≡}{0,1,}2}^{+∞} \dfrac{1}{i · \ln i} \not⇝ S$，正项级数$\sum\limits_{i=\rlap{≡≡}{0,1,}{2}}^{+∞} \dfrac{1}{i · \ln i · \ln^2 \ln i} ⇝ S$。

$\lim\limits_{i ⇝ +∞} β_i = \lim\limits_{i ⇝ +∞} i · \ln i · \left[ \dfrac{(i + 1) · \ln (i + 1)}{i · \ln i} -  \dfrac{i + 1}{i} \right] = \lim\limits_{i ⇝ +∞} \left[ (i + 1) · \ln (i + 1) - (i + 1) · \ln i \right] = \lim\limits_{i ⇝ +∞} \left[ \ln \left( 1 + \dfrac{1}{i} \right)^i + \ln \left( 1 + \dfrac{1}{i} \right) \right] ⇝ 1$

$\lim\limits_{i ⇝ +∞} β_i = \lim\limits_{i ⇝ +∞} i · \ln i · \left[ \dfrac{(i + 1) · \ln (i + 1) · \ln^2 \ln (i + 1)}{i · \ln i · \ln^2 \ln i} - \dfrac{i + 1}{i} \right] = \lim\limits_{i ⇝ +∞} \left[ (i + 1) · \ln (i + 1) · \left[ \lim\limits_{i ⇝ +∞} \dfrac{\ln \ln (i + 1)}{\ln \ln i} \right]^2 - (i + 1) · \ln i \right] = \lim\limits_{i ⇝ +∞} \left[ \ln \left( 1 + \dfrac{1}{i} \right)^i + \ln \left( 1 + \dfrac{1}{i} \right) \right] ⇝ 1$

### 正项级数的审敛法对比

收敛速度：比值审敛法 > 根值审敛法 > 幂值审敛法 > 指数审敛法 > 对数审敛法 > 比较审敛法

强效程度：比值审敛法 < 根值审敛法 < 幂值审敛法 < 指数审敛法 < 对数审敛法 < 比较审敛法

由于$1 < \varliminf\limits_{i ⇝ +∞} \dfrac{s_i}{s_{i+1}} ≤ \varliminf\limits_{i ⇝ +∞} {\dfrac{1}{\sqrt[i]{s_i}}} ≤ \varlimsup\limits_{i ⇝ +∞} \dfrac{1}{\sqrt[i]{s_i}} ≤ \varlimsup\limits_{i ⇝ +∞} \dfrac{s_i}{s_{i+1}}$

也即$\varliminf\limits_{i ⇝ +∞} \dfrac{s_{i+1}}{s_i} ≤ \varliminf\limits_{i ⇝ +∞} \sqrt[i]{s_i} ≤ \varlimsup\limits_{i ⇝ +∞} \sqrt[i]{s_i} ≤ \varlimsup\limits_{i ⇝ +∞} \dfrac{s_{i+1}}{s_i} < 1$​

证明$\varliminf\limits_{i ⇝ +∞} \dfrac{s_i}{s_{i+1}} ≤ \varliminf\limits_{i ⇝ +∞} {\dfrac{1}{\sqrt[i]{s_i}}}$，也即$\varlimsup\limits_{i ⇝ +∞} \sqrt[i]{s_i} ≤ \varlimsup\limits_{i ⇝ +∞} \dfrac{s_{i+1}}{s_i}$

| $⇓$  |        $\varlimsup\limits_{i ⇝ +∞} \dfrac{s_{i+1}}{s_i} ⇝ ρ$ | $⇒$  | $∀ε>0;∃N∈ℕ;∀n≥N; \dfrac{s_{i+1}}{s_i} < ρ + ε$               |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇓$  | $\dfrac{s_i}{s_N} = \dfrac{s_i}{s_{i-1}} ··· \dfrac{s_{N-1}}{s_N} < (ρ + ε)^{i - N}$ | $⇒$  | $s_i < s_N · (ρ + ε)^{-N} · (ρ + ε)^i$                       |
| $⇓$  |     $\sqrt[i]{s_i} < \sqrt[i]{s_N · (ρ + ε)^{-N}} · (ρ + ε)$ | $⇒$  | $\varlimsup\limits_{i ⇝ +∞} \sqrt[i]{s_i} ≤ \varlimsup\limits_{i ⇝ +∞} \left[ \sqrt[i]{s_N · (q + ε)^{-N}} · (ρ + ε) \right] ⇝ ρ + ε$ |
| $⇓$  |                                                     $ε ⇝ 0⁺$ | $⇒$  | $\varlimsup\limits_{i ⇝ +∞} \sqrt[i]{s_i} ≤ \varlimsup\limits_{i ⇝ +∞} \dfrac{s_{i+1}}{s_i} ⇝ ρ$ |

特例：正项级数$\sum\limits_{i=0}^{+∞} \left( \dfrac{1}{2^i} + \dfrac{1}{3^i} \right) = \sum\limits_{i=0}^{+∞} \dfrac{1}{2^i} + \sum\limits_{i=0}^{+∞} \dfrac{1}{3^i} = \dfrac{1}{1 - \frac{1}{2}} + \dfrac{1}{1 - \frac{1}{3}} ⇝ \dfrac{1}{2}$

$\varliminf\limits_{i ⇝ +∞} \dfrac{s_i}{s_{i+1}} = \lim\limits_{i ⇝ +∞} \dfrac{1/3^i}{1/2^{i + 1}} = \lim\limits_{i ⇝ +∞} \dfrac{2^{i + 1}}{3^i} ⇝ 0 < 1$

$\varlimsup\limits_{i ⇝ +∞} \dfrac{s_i}{s_{i+1}} = \lim\limits_{i ⇝ +∞} \dfrac{1/2^i}{1/3^i} = \lim\limits_{i ⇝ +∞} \dfrac{3^i}{2^i} ⇝ +∞ > 1$

$\varliminf\limits_{i ⇝ +∞} \dfrac{1}{\sqrt[i]{s_i}} = \lim\limits_{i ⇝ +∞} \sqrt[2 · i - 1]{2^i} = \lim\limits_{i ⇝ +∞} 2^{\frac{i}{2 · i - 1}} ⇝ \sqrt{2} > 1$

$\varlimsup\limits_{i ⇝ +∞} \dfrac{1}{\sqrt[i]{s_i}} = \lim\limits_{i ⇝ +∞} \sqrt[2 · i]{3^i} = \lim\limits_{i ⇝ +∞} 3^{\frac{1}{2}} ⇝ \sqrt{3} > 1$

### 构造性收敛正项级数

不存在收敛最慢的正项级数。

假设存在正项级数$\sum\limits_{i=0}^{+∞} s_i ⇝ S$，则可构造收敛更慢的正项级数$t_i ≡ \sqrt{S - S_{i-1}} - \sqrt{S - S_i}$，使得$\sum\limits_{i=0}^{+∞} t_i ⇝ \sqrt{S}$。

| $⇓$  |                             $\sum\limits_{i=0}^{+∞} s_i ⇝ S$ | $\mathop{⇒}\limits^{S_{-1}≡0}$ | $s_i = S_i - S_{i-1} = (S - S_{i-1}) - (S - S_i)$            |
| :--: | -----------------------------------------------------------: | :----------------------------: | :----------------------------------------------------------- |
| $⇓$  | $1 = \dfrac{s_i}{(S - S_{i-1}) - (S - S_i)} = \dfrac{s_i}{(\sqrt{S - S_{i-1}} + \sqrt{S - S_i}) · (\sqrt{S - S_{i-1}} - \sqrt{S - S_i})}$ |              $⇒$               | $t_i ≡ \sqrt{S - S_{i-1}} - \sqrt{S - S_i}, \sum\limits_{i=1}^{+∞} t_i ⇝ \sqrt{S - S_{-1}} = \sqrt{S}$ |
| $⇓$  |     $\dfrac{s_i}{t_i} = \sqrt{S - S_{i-1}} + \sqrt{S - S_i}$ |              $⇒$               | $\lim\limits_{i ⇝ +∞} \dfrac{s_i}{t_i} ⇝ 0$                  |

### 无穷级数的乘积

级数的乘积可类比于矩阵的乘法运算。

$\sum\limits_{i=0}^n s_i · \sum\limits_{j=0}^m t_j =
\sum\limits_{i=0,j=0}^{n,m}\left[\begin{matrix}
s_0 \\ s_1 \\ \vdots \\ s_n
\end{matrix}\right] ·
\left[\begin{matrix}
t_0 & t_1 & \cdots & t_m
\end{matrix}\right] =
\sum\limits_{i=0,j=0}^{n,m}\left[\begin{matrix}
s_0 · t_0 & s_0 · t_1 & \cdots & s_0 · t_m \\
s_1 · t_0 & s_1 · t_1 & \cdots & s_1 · t_m \\
\vdots & \vdots & \ddots & \vdots \\
s_n · t_0 & s_n · t_1 & \cdots & s_n · t_m \\
\end{matrix}\right]$

级数的乘积沿左上正方形对角线相加。

$\sum\limits_{i=0}^{+∞} s_i · \sum\limits_{j=0}^{+∞} t_j = \sum\limits_{l=0}^{+∞} \left[ \sum\limits_{k=0}^l s_k · t_{l-k} \right] = \sum\limits_{l=0}^{+∞} \left[ \sum\limits_{i+j=l} s_i · t_j \right] = (s_0 · t_0) + (s_0 · t_1 + s_1 · t_0) + \cdots + (s_0 · t_l + s_1 · t_{l-1} + \cdots + s_{l-1} · t_1 + s_l · t_0) + \cdots$

级数的乘积按左上三角形体横向相加。

$\sum\limits_{i=0}^{+∞} s_i · \sum\limits_{j=0}^{+∞} t_j = \lim\limits_{l⇝+∞} \sum\limits_{i=0}^l \left[ s_i · \sum\limits_{j=0}^{l-i} t_j \right] = \lim\limits_{l⇝+∞} \sum\limits_{i=0}^l s_i · T_{l-i} = \lim\limits_{l⇝+∞} [ s_0 · (t_0 + t_1 + ··· + t_l) + s_1 · (t_0 + t_1 + ··· + t_{l-1}) + ··· + s_{l-1} · (t_0 + t_1) + s_l · (t_0) ]$

级数的乘积按左上三角形体竖向相加。

$\sum\limits_{i=0}^{+∞} s_i · \sum\limits_{j=0}^{+∞} t_j = \lim\limits_{l⇝+∞} \sum\limits_{j=0}^l \left[ t_j · \sum\limits_{i=0}^{l-j} s_i \right] = \lim\limits_{l⇝+∞} \sum\limits_{j=0}^l t_j · S_{l-j} = \lim\limits_{l⇝+∞} [ t_0 · (s_0 + s_1 + ··· s_l) + t_1 · (s_0 + s_1 + ··· + s_{l-1}) + ··· + t_{l-1} · (s_0 + s_1) + t_l · (s_0) ]$

级数的乘积沿左上正方形外边缘相加。

$\sum\limits_{i=0}^{+∞} s_i · \sum\limits_{j=0}^{+∞} t_j = \sum\limits_{l=0}^{+∞} \left[ - s_l · t_l + \sum\limits_{k=0}^l (s_k · t_l + s_l · t_k) \right] = (s_0 · t_0) + (s_0 · t_1 + s_1 · t_1 + s_1 · t_0) + \cdots + (s_0 · t_l + s_1 · t_l + \cdots + s_l · t_l + \cdots + s_l · t_1 + s_l · t_0) + \cdots$

级数的乘积按左上正方形体横向相加。

$\sum\limits_{i=0}^{+∞} s_i · \sum\limits_{j=0}^{+∞} t_j = \lim\limits_{l⇝+∞} \sum\limits_{i=0}^l \left[ s_i · \sum\limits_{j=0}^l t_j \right] = \lim\limits_{l⇝+∞} \sum\limits_{i=0}^l s_i · T_l = \lim\limits_{l⇝+∞} \left[ s_0 · (t_0 + t_1 + ··· + t_l) + s_1 · (t_0 + t_1 + ··· + t_l) + ··· + s_{l-1} · (t_0 + t_1 + ··· + t_l) + s_l · (t_0 + t_1 + ··· + t_l) \right]$

级数的乘积按左上正方形体竖向相加。

$\sum\limits_{i=0}^{+∞} s_i · \sum\limits_{j=0}^{+∞} t_j = \lim\limits_{l⇝+∞} \sum\limits_{j=0}^l \left[ t_j · \sum\limits_{i=0}^l s_i \right] = \lim\limits_{l⇝+∞} \sum\limits_{j=0}^l t_j · S_l = \lim\limits_{l⇝+∞} [ t_0 · (s_0 + s_1 + ··· + s_l) + t_1 · (s_0 + s_1 + ··· + s_l) + ··· + t_{l-1} · (s_0 + s_1 + ··· + s_l) + t_l · (s_0 + s_1 + ··· + s_l) ]$

### 无穷级数的乘积收敛

若无穷级数之一绝对收敛，且其余无穷级数条件收敛，则无穷级数的乘积必定绝对收敛。

$\left[ \sum\limits_{i=0}^{+∞} | s_i | ⇝ S_{||} \right] ∧ \left[ \sum\limits_{j=0}^{+∞} t_j ⇝ T \right] ⇒ \left[ \lim\limits_{l⇝+∞} \sum\limits_{i=0}^l \left| s_i · \sum\limits_{j=0}^l t_j \right| ⇝ ST_{||} \right]$

| $⇓$  | $\sum\limits_{i=1}^{+∞} s_i · \sum\limits_{j=1}^{+∞} t_j = \lim\limits_{l⇝+∞} \sum\limits_{i=1}^l \left[ s_i · \sum\limits_{j=1}^l t_j \right] = \lim\limits_{l⇝+∞} \sum\limits_{i=1}^l s_i · T_l$ | $⇒$  | $\lim\limits_{l⇝+∞} \sum\limits_{i=1}^l \left| s_i · \sum\limits_{j=1}^l t_j \right| = \lim\limits_{l⇝+∞} \sum\limits_{i=1}^l | s_i · T_l |$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\lim\limits_{l⇝+∞} \sum\limits_{i=1}^l | s_i · T_l | = \lim\limits_{l⇝+∞} \left[ | T | · \sum\limits_{i=1}^l | s_i | + \sum\limits_{i=1}^l | s_i | · (|T_l| - |T|) \right]$ |      |                                                              |
| $⇓$  | $\lim\limits_{l⇝+∞} \sum\limits_{i=1}^l | s_i · T_l | ≤ \lim\limits_{l⇝+∞} \left[ | T | · \sum\limits_{i=1}^l | s_i | + \sum\limits_{i=1}^L | s_i | · (|| T_l | - | T ||) + \sum\limits_{i=L+1}^l | s_i | · (|| T_l | - | T ||) \right]$ |      |                                                              |
| $⇓$  | $\lim\limits_{l⇝+∞} \sum\limits_{i=1}^l | s_i · T_l | ≤ | T | · \sum\limits_{i=1}^{+∞} | s_i | + ε_1 · \sum\limits_{i=1}^L | s_i | + \mathrm{Sup.} · \sum\limits_{i=L+1}^l | s_i |$ | $⇐$  | $∃L∈ℕ;[ l>L ⇒ || T_l | - | T || < ε_1 ] ∧ [ l≤L ⇒ || T_l | - | T || ≤ \mathrm{Sup.}]$ |
| $⇓$  | $\lim\limits_{l⇝+∞} \sum\limits_{i=1}^l | s_i · T_l | ≤ | T | · \sum\limits_{i=1}^{+∞} | s_i | + ε_1 · S_{||} + \mathrm{Sup.} · ε_2$ |      |                                                              |
| $⇓$  | $\lim\limits_{l⇝+∞} \sum\limits_{i=1}^l | s_i · T_l | ≤ | T | · S_{||} + ε$ | $⇐$  | $ε = ε_1 · S_{||} + \mathrm{Sup.} · ε_2$                     |
| $⇓$  | $\lim\limits_{l⇝+∞} \sum\limits_{i=1}^l \left| s_i · \sum\limits_{j=1}^l t_j \right| ⇝ ST_{||}$ |      |                                                              |

若无穷级数全都条件收敛，则无穷级数的乘积未必条件收敛。

若无穷级数全都条件收敛，且无穷级数的乘积条件收敛，则该乘积等于无穷级数的极限相乘。根据幂级数的性质。

$\left[ \sum\limits_{i=0}^{+∞} s_i ⇝ S \right] ∧ \left[ \sum\limits_{j=0}^{+∞} t_j ⇝ T \right] ∧ \left[ \lim\limits_{l⇝+∞} \sum\limits_{i=0}^l s_i · \sum\limits_{j=0}^l t_j ⇝ ST \right] ⇒ \left[ S · T = ST \right]$

典例：无穷级数$\sum\limits_{i=\rlap{≡}{0,}1}^{+∞} s_i = \sum\limits_{i=\rlap{≡}{0,}1}^{+∞} \dfrac{(-1)^{i}}{\sqrt{i}} ⇝ S$条件收敛，无穷级数$\sum\limits_{j=\rlap{≡}{0,}1}^{+∞} t_i = \sum\limits_{j=\rlap{≡}{0,}1}^{+∞} \dfrac{(-1)^j}{\sqrt{j}} ⇝ T$条件收敛, 两者的乘积沿对角线相加$\sum\limits_{i=\rlap{≡}{0,}1}^{+∞} s_i · \sum\limits_{j=\rlap{≡}{0,}1}^{+∞} t_j \not⇝ ST$。

$\lim\limits_{l⇝+∞} \left| \sum\limits_{k=1}^l s_k · t_{l-k+1} \right| = \lim\limits_{l⇝+∞} \left| \sum\limits_{k=1}^l \dfrac{(-1)^k}{\sqrt{k}} · \dfrac{(-1)^{l-k+1}}{\sqrt{l-k+1}} \right| = \lim\limits_{l⇝+∞} \sum\limits_{k=1}^l \dfrac{1}{\sqrt{k · (l - k + 1)}} ≥ \lim\limits_{l⇝+∞} \dfrac{l}{\frac{k + (l - k + 1)}{2}} ⇝ 2 ≠ 0$

### 无穷乘积

无穷乘积的部分积

$P_l ≡ \prod\limits_{n=0}^l p_n ≡ \prod\limits_{n=0}^l (1 + s_n)$

无穷乘积的极限

$\lim\limits_{l⇝+∞} P_l ≡ \lim\limits_{l⇝+∞} \prod\limits_{n=0}^l p_n ≡ \prod\limits_{n=0}^{+∞} p_n ≡ \prod\limits_{n=0}^{+∞} (1 + s_n)$

无穷乘积收敛

$\lim\limits_{l⇝+∞} P_l ⇝ P ≠ 0$，也即$\lim\limits_{l⇝+∞} | P_l - P | ⇝ 0$

$\prod\limits_{n=0}^{+∞} p_n ⇝ P ≠ 0$，也即$\lim\limits_{n⇝+∞} \left| \prod\limits_{n=0}^n p_n - P \right| ⇝ 0$

无穷乘积发散

$\lim\limits_{l⇝+∞} P_l \not⇝ P ≠ 0$，也即$\lim\limits_{l⇝+∞} | P_l - P | \not⇝ 0$

$\prod\limits_{n=0}^{+∞} p_n \not⇝ P ≠ 0$，也即$\lim\limits_{n⇝+∞} \left| \prod\limits_{n=0}^n p_n - P \right| \not⇝ 0$

### 无穷乘积收敛的性质

若无穷乘积收敛，则其通项的极限为一。

$\lim\limits_{l⇝+∞} P_l ⇝ P ≠ 0 ⇒ \lim\limits_{n⇝+∞} p_n ⇝ 1 ⇒ \lim\limits_{n⇝+∞} s_n ⇝ 0$

$\lim\limits_{n⇝+∞} p_n = \lim\limits_{n⇝+∞} \dfrac{P_n}{P_{n-1}} = \dfrac{\lim\limits_{n⇝+∞} P_n}{\lim\limits_{n⇝+∞} P_{n-1}} = \dfrac{P}{P} ⇝ 1$

若通项的极限不为一，则无穷乘积发散。

$\lim\limits_{n⇝+∞} p_n \not⇝ 1 ⇒ \lim\limits_{l⇝+∞} P_l \not⇝ P ≠ 0$

### 无穷乘积的对偶原理

若无穷乘积收敛，则其对应的无穷级数也收敛，反之亦然。

$\left[ \prod\limits_{n=0}^{+∞} p_n ⇝ P \right] ⇔ \left[ \ln \prod\limits_{n=0}^{+∞} p_n ⇝ \ln P \right] ⇔ \left[ \sum\limits_{n=0}^{+∞} \ln p_n ⇝ \ln P \right]$

$\left[ \prod\limits_{n=0}^{+∞} (1 + | s_n |) ⇝ P_{||} \right] ⇔ \left[ \sum\limits_{n=0}^{+∞} \ln (1 + | s_n |) ⇝ \ln P_{||} \right] ⇔ \left[ \sum\limits_{n=0}^{+∞} | s_n | ⇝ S_{||} \right]$

$\left[ \prod\limits_{n=0}^{+∞} (1 + s_n) ⇝ P \right] ⇔ \left[ \sum\limits_{n=0}^{+∞} \ln (1 + s_n) ⇝ \ln P \right] \mathop{⇒}\limits_{-1 < s_n ≤ 0} \left[ \sum\limits_{n=0}^{+∞} s_n ⇝ S \right]$

若无穷乘积发散于零，则其对应的无穷级数发散于负无穷。

$\left[ \prod\limits_{n=0}^{+∞} p_n ⇝ 0 \right] ⇔ \left[ \sum\limits_{n=0}^{+∞} \ln p_n ⇝ -∞ \right]$

$\left[ \prod\limits_{n=0}^{+∞} (1 + s_n) ⇝ 0 \right] ⇔ \left[ \sum\limits_{n=0}^{+∞} \ln (1 + s_n) ⇝ -∞ \right] \mathop{⇐}\limits_{-1 < s_n ≤ 0} \left[ \sum\limits_{n=0}^{+∞} s_n ⇝ -∞ \right]$

| $⇓$  | $(1 + | x |) · (1 + | y |) = 1 + | x | + | y | + | x | · | y | ≥ 1 + | x | + | y | > | x | + | y |$ |      |                                                              |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\prod\limits_{n=0}^{+∞} (1 + | s_n |) > \sum\limits_{n=0}^{+∞} | s_n | ≥ \sum\limits_{n=0}^{+∞} \ln (1 + | s_n |) ≥ 0$ | $⇐$  | $| s_n | ≥ \ln (1 + | s_n |) ≥ 0$                            |
| $⇓$  | $\prod\limits_{n=0}^{+∞} (1 + | s_n |) ⇝ P_{||} ⇒ \sum\limits_{n=0}^{+∞} | s_n | ⇝ S_{||} ⇒ \sum\limits_{n=0}^{+∞} \ln (1 + | s_n |) ⇝ \ln P_{||}$ |      |                                                              |
| $⇓$  | $\prod\limits_{n=0}^{+∞} (1 + | s_n |) ⇝ P_{||} ⇔ \sum\limits_{n=0}^{+∞} | s_n | ⇝ S_{||} ⇔ \sum\limits_{n=0}^{+∞} \ln (1 + | s_n |) ⇝ \ln P_{||}$ |      |                                                              |
| $⇓$  | $-1 < s_n ≤ 0 ⇒ \prod\limits_{n=0}^{+∞} (1 + s_n) > 0 ≥ \sum\limits_{n=0}^{+∞} s_n ≥ \sum\limits_{n=0}^{+∞} \ln (1 + s_n)$ | $⇐$  | $| \ln (1 + s_n) | ≥ | s_n | ≥ \ln (1 + | s_n |) ≥ s_n ≥ \ln (1 + s_n) \mathop{=}\limits_{-1 < s_n} \ln | 1 + s_n |$ |
| $⇓$  | $\prod\limits_{n=0}^{+∞} (1 + s_n) ⇝ P ⇔ \sum\limits_{n=0}^{+∞} \ln (1 + s_n) ⇝ \ln P ⇒ \sum\limits_{n=0}^{+∞} s_n ⇝ S$ |      |                                                              |

特例：若$\sum\limits_{n=0}^{+∞} s_n^2 ⇝ \mathrm{Con.}$，则$\left[ \sum\limits_{n=0}^{+∞} s_n ⇝ S \right] ⇔ \left[ \sum\limits_{n=0}^{+∞} \ln (1 + s_n) ⇝ \ln P \right] ⇔ \left[ \prod\limits_{n=0}^{+∞} (1 + s_n) ⇝ P \right]$

| $⇓$  | $\sum\limits_{n=1}^{+∞} s_n^2 ⇝ \mathrm{Con.}$               |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $\lim\limits_{n⇝+∞} s_n^2 ⇝ 0 ⇒ \lim\limits_{n⇝+∞} s_n ⇝ 0 ⇒ \lim\limits_{n⇝+∞} \ln (1 + s_n) ⇝ 0$ |
| $⇓$  | $\lim\limits_{n⇝+∞} \dfrac{s_n - \ln (1 + s_n)}{s_n^2} = \lim\limits_{n⇝+∞} \dfrac{1}{2 · (1 + s_n)} ⇝ \dfrac{1}{2}$ |
| $⇓$  | $\sum\limits_{n=1}^{+∞} s_n^2 ⇝ \mathrm{Con.} ⇒ \left[ \sum\limits_{n=1}^{+∞} s_n - \sum\limits_{n=1}^{+∞} \ln (1 + s_n) ⇝ \mathrm{Con.} \right]$ |
| $⇓$  | $\sum\limits_{n=1}^{+∞} s_n^2 ⇝ \mathrm{Con.} ⇒ \left[ \sum\limits_{n=1}^{+∞} s_n ⇝ S ⇔ \sum\limits_{n=1}^{+∞} \ln (1 + s_n) ⇝ \ln P ⇔ \prod\limits_{n=1}^{+∞} (1 + s_n) ⇝ P \right]$ |
| $⇓$  | $\sum\limits_{n=1}^{+∞} s_n^2 ⇝ +∞ ⇒ \left[ \sum\limits_{n=1}^{+∞} s_n - \sum\limits_{n=1}^{+∞} \ln (1 + s_n) ⇝ +∞ \right]$ |
| $⇓$  | $\sum\limits_{n=1}^{+∞} s_n^2 ⇝ +∞ ⇒ \left[ \sum\limits_{n=1}^{+∞} s_n ⇝ S ⇔ \sum\limits_{n=1}^{+∞} \ln (1 + s_n) ⇝ -∞ ⇔ \prod\limits_{n=1}^{+∞} (1 + s_n) ⇝ 0 \right]$ |

### 无穷乘积的绝对收敛与条件收敛

若无穷乘积绝对收敛，则必定条件收敛。

$\left[ \prod\limits_{n=0}^{+∞} (1 + | s_n |) ⇝ P_{||} \right] ⇔ \left[ \sum\limits_{n=0}^{+∞} \ln (1 + | s_n |) ⇝ \ln P_{||} \right] ⇒ \left[ \sum\limits_{n=0}^{+∞} \ln (1 + s_n) ⇝ \ln P \right] ⇔ \left[ \prod\limits_{n=0}^{+∞} (1 + s_n) ⇝ P \right]$

若无穷乘积条件收敛，则未必绝对收敛。

$\left[ \prod\limits_{n=0}^{+∞} (1 + s_n) ⇝ P \right] ⇔ \left[ \sum\limits_{n=0}^{+∞} \ln (1 + s_n) ⇝ \ln P \right] \not⇒ \left[ \sum\limits_{n=0}^{+∞} \ln (1 + | s_n |) ⇝ \ln P_{||} \right] ⇔ \left[ \prod\limits_{n=0}^{+∞} (1 + | s_n |) ⇝ P_{||} \right]$

### 无穷乘积绝对收敛与条件收敛的性质

若无穷乘积绝对收敛，则交换任意多项的次序，其极限不变并且保持绝对收敛。

若无穷乘积条件收敛，则交换任意多项的次序，可使其趋近于任意给定的正数。

### 函数项级数

函数项级数的部分和

$F_n (x) ≡ \sum\limits_{i=0}^n f_i (x)$

函数项级数的极限

$\lim\limits_{n⇝+∞} F_n (x) ≡ \lim\limits_{n⇝+∞} \sum\limits_{i=0}^n f_i (x) ≡ \sum\limits_{i=0}^{+∞} f_i (x)$

函数项级数收敛

$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} F_n (x) ⇝ F(x_0)$也即$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} | F_n (x) - F (x_0) | ⇝ 0$

$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} \sum\limits_{i=0}^n f_i (x) ⇝ F (x_0)$也即$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} \left| \sum\limits_{i=0}^n f_i (x) - F (x_0) \right| ⇝ 0$

函数项级数发散

$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} F_n (x) \not⇝ F(x_0)$也即$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} | F_n (x) - F (x_0) | \not⇝ 0$

$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} \sum\limits_{i=0}^n f_i (x) \not⇝ F (x_0)$也即$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} \left| \sum\limits_{i=0}^n f_i (x) - F (x_0) \right| \not⇝ 0$

典例：函数项级数$F_n (x) = x^0 + \sum\limits_{i=1}^n (x^i - x^{i-1}) = x^n$

$F (x) = \lim\limits_{n⇝+∞} F_n (x) = \lim\limits_{n⇝+∞} x^n$

函数项级数$F_n (x)$在收敛区间$(-1, 1]$内都连续且可导，在点$x = 1$处不连续也不可导。

|     $x < -1$ | $⇒$  | $\lim\limits_{n⇝+∞} x^n ⇝ ∞$                 |
| -----------: | :--: | :------------------------------------------- |
|     $x = -1$ | $⇒$  | $\lim\limits_{n⇝+∞} x^n \not⇝ \mathrm{Lim.}$ |
| $| x | < +1$ | $⇒$  | $\lim\limits_{n⇝+∞} x^n ⇝ 0$                 |
|     $x = +1$ | $⇒$  | $\lim\limits_{n⇝+∞} x^n ⇝ 1$                 |
|     $x > +1$ | $⇒$  | $\lim\limits_{n⇝+∞} x^n ⇝ +∞$                |

### 函数项级数的一致收敛

函数项级数一致收敛

$[∀ε>0;∃N∈ℕ;∀n≥N; \sup\limits_{x∈X} | F_n (x) - F (x) | ≤ ε] ⇔ [∀ε>0;∃N∈ℕ;∀n≥N;∀x∈X; | F_n (x) - F (x) | < ε]$

$[∀ε>0;∃N∈ℕ;∀n≥N;∀m>N; \sup\limits_{x∈X} | F_m (x) - F_n (x) | ≤ ε] ⇔ [∀ε>0;∃N∈ℕ;∀n≥N;∀m>N;∀x∈X; | F_m (x) - F_n (x) | < ε]$

$[∀ε>0;∃N∈ℕ;∀n≥N;∀m>n; \sup\limits_{x∈X} \left| \sum\limits_{i=n}^m f_i (x) \right| ≤ ε] ⇔ [∀ε>0;∃N∈ℕ;∀n≥N;∀m>n;∀x∈X; \left| \sum\limits_{i=n}^m f_i (x) \right| < ε]$

$\left[ \lim\limits_{n⇝+∞} F_n (x) \mathop{↭}\limits_{x∈X} F (x) \right] ⇔ \left[ \lim\limits_{n⇝+∞} | F_n (x) - F (x) | \mathop{↭}\limits_{x∈X} 0 \right] ⇔ \left[ \lim\limits_{n⇝+∞} \sup\limits_{x∈X} | F_n (x) - F (x) | ⇝ 0 \right]$

$\left[ \sum\limits_{i=0}^{+∞} f_i (x) \mathop{↭}\limits_{x∈X} F (x) \right] ⇔ \left[ \lim\limits_{n⇝+∞} \left| \sum\limits_{i=0}^n f_i (x) - F (x) \right| \mathop{↭}\limits_{x∈X} 0 \right] ⇔ \left[ \lim\limits_{n⇝+∞} \sup\limits_{x∈X} \left| \sum\limits_{i=0}^n f_i (x) - F (x) \right| ⇝ 0 \right]$

若函数项级数一致收敛，则其通项一致收敛于零。

$\lim\limits_{n⇝+∞} F_n (x) \mathop{↭}\limits_{x∈X} F (x) ⇒ \lim\limits_{i⇝+∞} f_i (x) \mathop{↭}\limits_{x∈X} 0 ⇔ \lim\limits_{i⇝+∞} \sup\limits_{x∈X} | f_i (x) | ⇝ 0 $

函数项级数非一致收敛

$[∃ε>0;∀N∈ℕ;∃n≥N; \sup\limits_{x∈X} | F_n (x) - F (x) | > ε] ⇔ [∃ε>0;∀N∈ℕ;∃n≥N;∃x∈X; | F_n (x) - F (x) | ≥ ε]$

$[∃ε>0;∀N∈ℕ;∃n≥N;∃m>N; \sup\limits_{x∈X} | F_m (x) - F_n (x) | > ε] ⇔ [∃ε>0;∀N∈ℕ;∃n≥N;∃m>N;∃x∈X; | F_m (x) - F_n (x) | ≥ ε]$

$[∃ε>0;∀N∈ℕ;∃n≥N;∃m>n; \sup\limits_{x∈X} \left| \sum\limits_{i=n}^m f_i (x) \right| > ε] ⇔ [∃ε>0;∀N∈ℕ;∃n≥N;∃m>n;∃x∈X; \left| \sum\limits_{i=n}^m f_i (x) \right| ≥ ε]$

$\left[ \lim\limits_{n⇝+∞} F_n (x) \mathop{\not↭}\limits_{x∈X} F (x) \right] ⇔ \left[ \lim\limits_{n⇝+∞} | F_n (x) - F (x) | \mathop{\not↭}\limits_{x∈X} 0 \right] ⇔ \left[ \lim\limits_{n⇝+∞} \sup\limits_{x∈X} | F_n (x) - F (x) | \not⇝ 0 \right]$

$\left[ \sum\limits_{i=1}^{+∞} f_i (x) \mathop{\not↭}\limits_{x∈X} F (x) \right] ⇔ \left[ \lim\limits_{n⇝+∞} \left| \sum\limits_{i=1}^n f_i (x) - F (x) \right| \mathop{\not↭}\limits_{x∈X} 0 \right] ⇔ \left[ \lim\limits_{n⇝+∞} \sup\limits_{x∈X} \left| \sum\limits_{i=1}^n f_i (x) - F (x) \right| \not⇝ 0 \right]$

若通项不一致收敛于零，则函数项级数非一致收敛。

$\lim\limits_{n⇝+∞} F_n (x) \mathop{\not↭}\limits_{x∈X} F (x) ⇐ \lim\limits_{i⇝+∞} f_i (x) \mathop{\not↭}\limits_{x∈X} 0 ⇔ \lim\limits_{i⇝+∞} \sup\limits_{x∈X} | f_i (x) | \not⇝ 0 $

典例：函数项级数$F_n (x) = x^0 + \sum\limits_{i=1}^n (x^i - x^{i-1}) = x^n$在区间$(0, 1)$上非一致收敛。

$F (x) = \lim\limits_{n⇝+∞} F_n (x) = \lim\limits_{n⇝+∞} x^n \mathop{⇝}\limits_{x∈(0, 1)} 0$

$\lim\limits_{n⇝+∞} \sup\limits_{x∈(0, 1)} | F_n (x) - F(x) | = \lim\limits_{n⇝+∞} \sup\limits_{x∈(0, 1)} | x^n | ⇝ 1 ≠ 0$

若函数项级数有优正项级数，则必定绝对一致收敛。

若函数项级数绝对一致收敛，则必定条件一致收敛。

$\left[ ∃N∈ℕ;∀i≥N; \sup\limits_{x∈X} | f_i (x) | ≤ | s_i | \right] ⇔ \left[ ∃N∈ℕ;∀i≥N;∀x∈X; | f_i (x) | ≤ | s_i | \right] ⇒ \left[ \sum\limits_{i=1}^{+∞} | s_i | ⇝ S ⇒ \sum\limits_{i=1}^{+∞} | f_i (x) | \mathop{↭}\limits_{x∈X} F_{||} (x) ⇒ \sum\limits_{i=1}^{+∞} f_i (x) \mathop{↭}\limits_{x∈X} F (x) \right]$

$\left[ ∃N∈ℕ;∀n≥N;∀m>n; \sup\limits_{x∈X} \left| \sum\limits_{i=n}^m f_i (x) \right| ≤ \sup\limits_{x∈X} \left| \sum\limits_{i=n}^m | f_i (x) | \right| ≤ \left| \sum\limits_{i=n}^m | s_i | \right| < ε \right] ⇔ \left[ ∃N∈ℕ;∀n≥N;∀m>n;∀x∈X; \left| \sum\limits_{i=n}^m f_i (x) \right| ≤ \left| \sum\limits_{i=n}^m | f_i (x) | \right| ≤ \left| \sum\limits_{i=n}^m | s_i | \right| < ε \right]$

### 函数项级数一致收敛的性质

若函数项级数收敛，且函数项为连续函数，则其和函数未必为连续函数。

典例：函数项级数$\sum\limits_{i=\rlap{≡}{0,}1}^{+∞} \dfrac{\sin i · x}{i} = \dfrac{\pi - x}{2}$，以$T = 2 · \pi$为周期，在点$x = 2 · i · \pi$处不连续。

若函数项级数一致收敛，且函数项为连续函数，则其和函数必定为连续函数。$P ∧ Q ⇒ R$

若函数项为连续函数，但和函数非连续函数，则函数项级数必定非一致收敛。$Q ∧ ¬R ⇒ ¬P$

| $\fbox{1}$ | $∀ε_1>0;∃δ>0;∃N∈ℕ;∀x∈X;∀n≥N; x_0∈X ∧ | x - x_0 | < δ ⇒ | F_n (x) - F_n (x_0) | < ε_1$ |
| :--------: | ------------------------------------------------------------ |
| $\fbox{2}$ | $∀ε_3>0;∃N∈ℕ;∀n≥N;∀x∈X; | F_n (x) - F (x) | < ε_3$           |
|    $⇓$     | $∀ε_2>0;∃N∈ℕ;∀n≥N; x_0∈X ⇒ | F_n (x_0) - F (x_0) | < ε_2$    |
|    $⇓$     | $∀ε_1>0;∀ε_2>0;∀ε_4=ε_1+ε_2;∃δ>0;∃N∈ℕ;∀x∈X;∀n≥N; x_0∈X ∧ | x - x_0 | < δ ⇒ | F_n (x) - F (x_0) | < | F_n (x) - F_n (x_0) | + | F_n (x_0) - F (x_0) | < ε_4$ |
|    $⇓$     | $∀ε_4>0;∃δ>0;∃N∈ℕ;∀x∈X;∀n≥N; x_0∈X ∧ | x - x_0 | < δ ⇒ | F_n (x) - F (x_0) | < ε_4$ |
|    $⇕$     | $∀ε_4>0;∃δ>0;∃N∈ℕ;∀n≥N;∀x∈X; x_0∈X ∧ | x - x_0 | < δ ⇒ | F_n (x) - F (x_0) | < ε_4$ |
|    $⇓$     | $\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} F_n (x) \mathop{≡}\limits_{\fbox{1}} \lim\limits_{n⇝+∞ \\ x⇝x_0} F_n (x) \mathop{≡}\limits_{\fbox{2}} \lim\limits_{n⇝+∞} \lim\limits_{x⇝x_0} F_n (x)$ |
|    $⇓$     | $∀ε_3>0;∀ε_4>0;∀ε_5=ε_3+ε_4;∃δ>0;∃N∈ℕ;∀n≥N;∀x∈X; x_0∈X ∧ | x - x_0 | < δ ⇒ | F (x) - F (x_0) | ≤ | F (x) - F_n (x) | + | F_n (x) - F (x_0) | < ε_5$ |
|    $⇓$     | $∀ε_5>0;∃δ>0;∀x∈X; x_0∈X ∧ | x - x_0 | < δ ⇒ | F (x) - F (x_0) | < ε_5$ |
|    $⇓$     | $\lim\limits_{x⇝x_0} F (x) ⇝ F (x_0)$                        |

若函数项级数$F_n (x)$在区间$X$上一致收敛，则多重极限可以随意交换极限运算的次序。

$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} F_n (x) ≡ \lim\limits_{n⇝+∞ \\ x⇝x_0} F_n (x) ≡ \lim\limits_{n⇝+∞} \lim\limits_{x⇝x_0} F_n (x)$

若函数项级数$F_n (x)$在区间$X$上非一致收敛，则多重极限不可随意交换极限运算的次序。

$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} F_n (x) \not≡ \lim\limits_{n⇝+∞ \\ x⇝x_0} F_n (x) \not≡ \lim\limits_{n⇝+∞} \lim\limits_{x⇝x_0} F_n (x)$

典例：分段函数项级数$F_n (x) = \mathop{2 · n · x}\limits_{0 ≤ x ≤ \frac{1}{2 · n}}; \mathop{2 · (1 - n · x)}\limits_{\frac{1}{2 · n} < x ≤ \frac{1}{n}}; \mathop{0}\limits_{\frac{1}{n} < x ≤ 1}$在区间$[0, 1]$内非一致收敛。

$\lim\limits_{x⇝0} \lim\limits_{n⇝+∞} F_n (x) = \lim\limits_{x⇝0} 0 ⇝ 0$

$\lim\limits_{n⇝+∞ \\ x≡\frac{1}{2 · n}⇝0} F_n (x) = \lim\limits_{n⇝+∞} 2 · n · \dfrac{1}{2 · n} ⇝ 1 $

$\lim\limits_{n⇝+∞} \lim\limits_{x⇝0} F_n (x) = \lim\limits_{n⇝+∞} 0 ⇝ 0 $

函数项级数不可随意交换极限运算与求和运算的次序，除非函数项级数$F_n (x)$在区间$X$上一致收敛。

$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} F_n (x) ≡ \lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} \sum\limits_{i=0}^{n} f_i (x) ≡ \lim\limits_{x⇝x_0} \sum\limits_{i=0}^{+∞} f_i (x) \not≡ \sum\limits_{i=0}^{+∞} \lim\limits_{x⇝x_0} f_i (x) ≡ \lim\limits_{n⇝+∞} \sum\limits_{i=0}^n \lim\limits_{x⇝x_0} f_i (x) ≡ \lim\limits_{n⇝+∞} \lim\limits_{x⇝x_0} \sum\limits_{i=0}^n f_i (x) ≡ \lim\limits_{n⇝+∞} \lim\limits_{x⇝x_0} F_n (x)$

函数项级数不可随意交换极限运算与积分运算的次序，除非函数项级数$F_n (x)$在区间$[α, β]$上一致收敛。？

$\int\limits_α^β \left[ \lim\limits_{n⇝+∞} F_n (x) \right] \mathrm{d}x ≡ \int\limits_α^β \left[ \lim\limits_{n⇝+∞} \sum\limits_{i=0}^n f_i (x) \right] \mathrm{d}x ≡ \int\limits_α^β \left[ \sum\limits_{i=0}^{+∞} f_i (x) \right] \mathrm{d}x \not≡ \sum\limits_{i=0}^{+∞} \left[ \int\limits_α^β f_i (x) \mathrm{d}x \right] ≡ \lim\limits_{n⇝+∞} \sum\limits_{i=0}^n \left[ \int\limits_α^β f_i (x) \mathrm{d}x \right] ≡ \lim\limits_{n⇝+∞} \int\limits_α^β \left[ \sum\limits_{i=0}^n f_i (x) \right] \mathrm{d}x ≡ \lim\limits_{n⇝+∞} \int\limits_α^β F_n (x) \mathrm{d}x$

函数项级数不可随意交换极限运算与求导运算的次序，除非函数项级数$F_n (x)$在区间$X$上一致收敛。？

$\lim\limits_{x⇝x_0} \dfrac{\mathrm{d}}{\mathrm{d}x} \left[ \lim\limits_{n⇝+∞} F_n (x) \right] ≡ \lim\limits_{x⇝x_0} \dfrac{\mathrm{d}}{\mathrm{d}x} \left[ \lim\limits_{n⇝+∞} \sum\limits_{i=0}^n f_i (x) \right] ≡ \lim\limits_{x⇝x_0} \dfrac{\mathrm{d}}{\mathrm{d}x} \left[ \sum\limits_{i=0}^{+∞} f_i (x) \right] \not≡ \sum\limits_{i=0}^{+∞} \lim\limits_{x⇝x_0} \dfrac{\mathrm{d} f_i (x)}{\mathrm{d}x} ≡ \lim\limits_{n⇝+∞} \sum\limits_{i=0}^n \lim\limits_{x⇝x_0} \dfrac{\mathrm{d} f_i (x)}{\mathrm{d}x} ≡ \lim\limits_{n⇝+∞} \lim\limits_{x⇝x_0} \dfrac{\mathrm{d}}{\mathrm{d}x} \left[ \sum\limits_{i=0}^n f_i (x) \right] ≡ \lim\limits_{n⇝+∞} \lim\limits_{x⇝x_0} \dfrac{\mathrm{d} F_n (x)}{\mathrm{d}x}$

典例：函数项级数$F_n (x) = \sum\limits_{i=\rlap{≡}{0,}1}^n \left[ i · x · (1 - x^2)^i - (i - 1) · x · (1 - x^2)^{i-1} \right] $在区间$[0, 1]$上非一致收敛。

$\int\limits_0^1 \left[ \lim\limits_{n⇝+∞} F_n (x) \right] \mathrm{d}x = \int_0^1 \lim\limits_{n⇝+∞} \left[ n · x · (1 - x^2)^n \right] \mathrm{d}x = \int\limits_0^1 \lim\limits_{n⇝+∞} \left[ \mathop{0}\limits_{x=0,1}; \mathop{n · x · (1 - x^2)^n}\limits_{x∈(0, 1)} \right] \mathrm{d}x = \int\limits_0^1 0 \mathrm{d}x = 0 ≠ \dfrac{1}{2}$

$\lim\limits_{n⇝+∞} \int\limits_0^1 F_n (x) \mathrm{d}x = \lim\limits_{n⇝+∞} \int\limits_0^1 [ n · x · (1 - x^2)^n ] \mathrm{d}x = \lim\limits_{n⇝+∞} \left. \dfrac{- n · (1 - x^2)^{n + 1}}{2 · (n + 1)} \right|_0^1 = \lim\limits_{n⇝+∞} \dfrac{n}{2 · (n + 1)} ⇝ \dfrac{1}{2}$

典例：函数项级数$F_n (x) = \sum\limits_{i=\rlap{≡}{0,}1}^n f_i (x) = \sum\limits_{i=\rlap{≡}{0,}1}^n \left[ ә^{-i · x^2} - ә^{-(i - 1) · x^2} \right] = ә^{-n · x^2} - 1$

$\lim\limits_{x⇝0} \dfrac{\mathrm{d}}{\mathrm{d}x} \left[ \lim\limits_{n⇝+∞} F_n (x) \right] = \lim\limits_{x⇝0} \dfrac{\mathrm{d}}{\mathrm{d}x} \left[ \lim\limits_{n⇝+∞} \left( ә^{-n·x^2} - 1 \right) \right] = \lim\limits_{x⇝0} \dfrac{\mathrm{d}}{\mathrm{d}x} \left[ \mathop{0}\limits_{x=0}, \mathop{-1}\limits_{x≠0} \right] \not≡ 0$

$\lim\limits_{n⇝+∞} \lim\limits_{x⇝0} \dfrac{\mathrm{d} F_n (x)}{\mathrm{d}x} = \lim\limits_{n⇝+∞} \lim\limits_{x⇝0} \dfrac{\mathrm{d} (ә^{-n · x^2} - 1)}{\mathrm{d}x} = \lim\limits_{n⇝+∞} \lim\limits_{x⇝0} -2 · n · x · ә^{-n · x^2} ≡ 0$

### 幂级数

幂级数的部分和

$F_n (x) ≡ \sum\limits_{i=0}^n p_i · (x - x_0)^i$

幂级数的极限

$\lim\limits_{n⇝+∞} F_n (x) ≡ \lim\limits_{n⇝+∞} \sum\limits_{i=0}^n p_i · (x - x_0)^i ≡ \sum\limits_{i=0}^{+∞} p_i · (x - x_0)^i$

幂级数收敛

$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} F_n (x) ⇝ F (x_0) ⇔ \lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} | F_n (x) - F (x_0) | ⇝ 0$

$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} \sum\limits_{i=0}^n p_i · (x - x_0)^i ⇝ F (x_0) ⇔ \lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} \left| \sum\limits_{i=0}^n p_i · (x - x_0)^i - F (x_0) \right| ⇝ 0$

幂级数发散

$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} F_n (x) \not⇝ F (x_0) ⇔ \lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} | F_n (x) - F (x_0) | \not⇝ 0$

$\lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} \sum\limits_{i=0}^n p_i · (x - x_0)^i \not⇝ F (x_0) ⇔ \lim\limits_{x⇝x_0} \lim\limits_{n⇝+∞} \left| \sum\limits_{i=0}^n p_i · (x - x_0)^i - F (x_0) \right| \not⇝ 0$

### 幂级数收敛的性质

若幂级数在点$x_1 - x_0$处条件收敛，则在区间$[±0, x_1 - x_0]$上条件一致收敛。

$\left[ \sum\limits_{i=0}^{+∞} p_i · (x_1 - x_0)^i ⇝ F (x_1) \right] ⇒ \left[ \sum\limits_{i=0}^{+∞} p_i · (x - x_0) \mathop{↭}\limits_{[±0, x - x_0]⊆[±0, x_1 - x_0]} F (x) \right]$

若幂级数在点$x_1 - x_0$处条件收敛，则在区间$[±0, x_1 - x_0)$上绝对收敛，且在区间$[±0, x_1 - x_0]$上条件收敛。

若幂级数在点$x_1 - x_0$处绝对收敛，则在区间$[±0, x_1 - x_0]$上绝对收敛，且在区间$[±0, x_1 - x_0]$上条件收敛。

若幂级数在点$x_2 - x_0$处绝对发散，则在区间$(x_2 - x_0, ±∞)$上条件发散，且在区间$[x_2 - x_0, ±∞)$上绝对发散。

若幂级数在点$x_2 - x_0$处条件发散，则在区间$[x_2 - x_0, ±∞)$上条件发散，且在区间$[x_2 - x_0, ±∞)$上绝对发散。

$\left[ \sum\limits_{i=0}^{+∞} | p_i · (x_1 - x_0)^i | ⇝ F_{||} (x_1) \right] ⇒ \left[ \sum\limits_{i=0}^{+∞} p_i · (x_1 - x_0)^i ⇝ F (x_1) \right] ⇒ \left[ \sum\limits_{i=0}^{+∞} | p_i · (x_2 - x_0)^i | \mathop{⇝}\limits_{| x_2 - x_0 | < | x_1 - x_0 |} F_{||} (x_2) \right] ⇒ \left[ \sum\limits_{i=0}^{+∞} p_i · (x - x_0)^i \mathop{⇝}\limits_{| x - x_0 | ≤ | x_2 - x_0 | < | x_1 - x_0 |} F (x) \right]$   

$\left[ \sum\limits_{i=0}^{+∞} p_i · (x_2 - x_0)^i \not⇝ F (x_2) \right] ⇒ \left[ \sum\limits_{i=0}^{+∞} | p_i · (x_2 - x_0)^i | \not⇝ F_{||} (x_2) \right] ⇒ \left[ \sum\limits_{i=0}^{+∞} p_i · (x_1 - x_0)^i \mathop{\not⇝}\limits_{| x_1 - x_0 | > | x_2 - x_0 |} F (x_1) \right] ⇒ \left[ \sum\limits_{i=0}^{+∞} | p_i · (x - x_0)^i | \mathop{\not⇝}\limits_{| x - x_0 | ≥ | x_1 - x_0 | > | x_2 - x_0 |} F_{||} (x) \right]$  

| $⇓$  | $\sum\limits_{i=1}^{+∞} p_i · (x - x_0)^i = \sum\limits_{i=1}^{+∞} p_i · (x_1 - x_0)^i · \dfrac{(x - x_0 )^i}{(x_1 - x_0)^i}$ |      |                                                              |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇓$  | $\left[ \sum\limits_{i=1}^{+∞} p_i · (x_1 - x_0)^i ⇝ F (x_1) \right] ⇒ \left[ \sum\limits_{i=1}^{+∞} p_i · (x - x_0) \mathop{↭}\limits_{[±0, x - x_0] ⊆ [±0, x_1 - x_0]} F (x) \right]$ | $⇐$  | $\left[ \sum\limits_{i=1}^{+∞} p_i · (x_1 - x_0)^i ⇝ F (x_1) \right] ∧ \left[ \left| \dfrac{(x - x_0)^i}{(x_1 - x_0)^i} \right| ≤ 1 \right]$ |
| $⇓$  | $\left[ \sum\limits_{i=1}^{+∞} p_i · (x_1 - x_0)^i ⇝ F (x_1) \right] ⇒ \left[ \sum\limits_{i=1}^{+∞} | p_i · (x - x_0)^i | \mathop{⇝}\limits_{| x - x_0 | < | x_1 - x_0 |} F_{||} (x) \right]$ | $⇐$  | $[ | p_i · (x_1 - x_0)^i | ≤ \mathrm{Sup.} ] ∧ \left[ \sum\limits_{i=1}^{+∞} \dfrac{(x - x_0)^i}{(x_1 - x_0)^i} ⇝ \mathrm{Con.} \right]$ |
| $⇓$  | $\left[ \sum\limits_{i=1}^{+∞} | p_i · (x - x_0)^i | \not⇝ F_{||} (x) \right] ⇒ \left[ \sum\limits_{i=1}^{+∞} p_i · (x_1 - x_0)^i \mathop{\not⇝}\limits_{| x - x_0 | < | x_1 - x_0 |} F (x_1) \right]$ |      |                                                              |

幂级数的绝对收敛半径$R$与绝对发散半径$\overline{R}$。

$R ≡ \dfrac{1}{\varlimsup\limits_{i⇝+∞} \sqrt[i]{| p_i |}} ≡ \varliminf\limits_{i⇝+∞} \dfrac{1}{\sqrt[i]{| p_i |}} < \varlimsup\limits_{i⇝+∞} \dfrac{1}{\sqrt[i]{| p_i |}} ≡ \dfrac{1}{\varliminf\limits_{i⇝+∞} \sqrt[i]{| p_i |}} ≡ \overline{R}$

幂级数在绝对收敛半径内区间$| x - x_0 | ≤ R_γ < R$上绝对一致收敛。

幂级数在绝对收敛半径内绝对收敛且条件收敛，幂级数在绝对发散半径外条件发散且绝对发散。

$\left[ \sum\limits_{i=0}^{+∞} | p_i · (x - x_0 )^i | \mathop{↭}\limits_{| x - x_0 | ≤ R_γ < R} F_{||} (x) \right] ⇒ \left[ \sum\limits_{i=0}^{+∞} p_i · (x - x_0 )^i \mathop{↭}\limits_{| x - x_0 | ≤ R_γ < R} F (x) \right]$

$\left[ \sum\limits_{i=0}^{+∞} | p_i · (x - x_0)^i | \mathop{⇝}\limits_{| x - x_0 | < R} F_{||} (x) \right] ⇒ \left[ \sum\limits_{i=0}^{+∞} p_i · (x - x_0)^i \mathop{⇝}\limits_{| x - x_0 | < R} F (x) \right]$

$\left[ \sum\limits_{i=0}^{+∞} | p_i · (x - x_0)^i | \mathop{\not⇝}\limits_{| x - x_0 | > \overline{R}} F_{||} (x) \right] ⇒ \left[ \sum\limits_{i=0}^{+∞} p_i · (x - x_0)^i \mathop{\not⇝}\limits_{| x - x_0 | > \overline{R}} F (x) \right]$

| $⇑$  | $\varlimsup\limits_{i⇝+∞} | p_i · (x - x_0)^i | ⇝ \dfrac{1}{γ_+^i}$ |     $\mathop{⇒}\limits^{γ_+ > 1}$      | $\sum\limits_{i=1}^{+∞} | p_i · (x - x_0 )^i | ↭ F_{||} (x)$ |
| :--: | -----------------------------------------------------------: | :------------------------------------: | :----------------------------------------------------------- |
| $⇑$  | $\varliminf\limits_{i⇝+∞} \dfrac{1}{\sqrt[i]{| p_i · (x - x_0)^i |}} = \varliminf\limits_{i⇝+∞} \dfrac{1}{\sqrt[i]{| p_i |} · | x - x_0 |} ⇝ γ_+ > 1$ |     $\mathop{⇒}\limits^{γ_+ > 1}$      | $\sum\limits_{i=1}^{+∞} | p_i · (x - x_0)^i | ⇝ F_{||} (x)$  |
| $⇑$  | $\varlimsup\limits_{i⇝+∞} \dfrac{1}{\sqrt[i]{| p_i · (x - x_0)^i |}} = \varlimsup\limits_{i⇝+∞} \dfrac{1}{\sqrt[i]{| p_i |} · | x - x_0 |} ⇝ γ_- < 1$ |     $\mathop{⇒}\limits^{γ_- < 1}$      | $\sum\limits_{i=1}^{+∞} | p_i · (x - x_0)^i | \not⇝ F_{||} (x)$ |
| $⇑$  | $R ≡ \dfrac{1}{\varlimsup\limits_{i⇝+∞} \sqrt[i]{| p_i |}} ≡ \varliminf\limits_{i⇝+∞} \dfrac{1}{\sqrt[i]{| p_i |}} ⇝ γ_+ · | x - x_0 | > | x - x_0 |$ |                                        | $\overline{R} ≡ \dfrac{1}{\varliminf\limits_{i⇝+∞} \sqrt[i]{| p_i |}} ≡ \varlimsup\limits_{i⇝+∞} \dfrac{1}{\sqrt[i]{| p_i |}} ⇝ γ_- · | x - x_0 | < | x - x_0 |$ |
| $⇑$  |                         $R_γ ≡ \dfrac{R}{γ_+} ≥ | x - x_0 |$ |     $\mathop{⇒}\limits^{γ_+ > 1}$      | $\sum\limits_{i=1}^{+∞} | p_i · (x - x_0 )^i | \mathop{↭}\limits_{| x - x_0 | ≤ R_{γ} < R} F_{||} (x)$ |
| $⇑$  |                                            $R > | x - x_0 |$ |                  $⇒$                   | $\sum\limits_{i=1}^{+∞} | p_i · (x - x_0)^i | \mathop{⇝}\limits_{| x - x_0 | < R} F_{||} (x)$ |
| $⇑$  |                                 $\overline{R} < | x - x_0 |$ | $\mathop{⇒}\limits^{\overline{R} ≥ R}$ | $\sum\limits_{i=1}^{+∞} | p_i · (x - x_0)^i | \mathop{\not⇝}\limits_{| x - x_0 | > \overline{R}} F_{||} (x)$ |

|      |      |      |
| ---- | ---- | ---- |
|      |      |      |
|      |      |      |
|      |      |      |

幂级数在绝对收敛半径内区间$| x - x_0 | < R$上，连续且有任意阶导数。

幂级数在绝对收敛半径内区间$| x - x_0 | ≤ R_γ < R$上，可逐项积分且积分后绝对收敛半径不变，绝对收敛半径处的敛散性可能由发散变成收敛。

幂级数在绝对收敛半径内区间$| x - x_0 | ≤ R_γ < R$上，可逐项求导且求导后绝对收敛半径不变，绝对收敛半径处的敛散性可能由收敛变成发散。

$\int\limits_{x_0}^{x} \mathrm{d} x · \lim\limits_{n⇝+∞} F_n (x) ≡ \int\limits_{x_0}^{x} \mathrm{d} x · \sum\limits_{i=0}^{+∞} p_i · (x - x_0)^i ≡ \sum\limits_{i=0}^{+∞} \int\limits_{x_0}^{x}\mathrm{d} x · p_i · (x - x_0)^i ≡ \lim\limits_{n⇝+∞} \int\limits_{x_0}^{x} \mathrm{d} x · F_n (x) ≡ \sum\limits_{i=0}^{+∞} \dfrac{p_i}{i + 1} · (x - x_0)^{i + 1}$

$\dfrac{\mathrm{d}}{\mathrm{d} x} \lim\limits_{n⇝+∞} F_n (x) ≡ \dfrac{\mathrm{d}}{\mathrm{d} x} \sum\limits_{i=0}^{+∞} [ p_i · (x - x_0)^i ] ≡ \sum\limits_{i=0}^{+∞} \dfrac{\mathrm{d}}{\mathrm{d} x} [ p_i · (x - x_0)^i] ≡ \lim\limits_{n⇝+∞} \dfrac{\mathrm{d}}{\mathrm{d} x} F_n (x) ≡ \sum\limits_{i=0}^{+∞} [ p_i · i · (x - x_0)^{i - 1} ]$

$\varliminf\limits_{n⇝+∞} \sqrt[i]{\left| \dfrac{p_i}{i + 1} \right|} = \dfrac{\varliminf\limits_{n⇝+∞} \sqrt[i]{| p_i |}}{\varlimsup\limits_{n⇝+∞} \sqrt[i]{i + 1}} = R = \varliminf\limits_{n⇝+∞} \sqrt[i]{| p_i · i |} = \varliminf\limits_{n⇝+∞} \sqrt[i]{| p_i |} · \varliminf\limits_{n⇝+∞} \sqrt[i]{i} $

幂级数在绝对收敛半径$±R$处的敛散性不恒定。

典例：幂级数$\sum\limits_{i=0}^{+∞} (-x)^i = \dfrac{1}{1 + x}$的绝对收敛半径为$R = 1$。

$\lim\limits_{x⇝1^-} \sum\limits_{i=0}^{+∞} (-x)^i = \lim\limits_{x⇝1^-} \dfrac{1}{1 + x} ⇝ \dfrac{1}{2} \not⇜ \sum\limits_{i=0}^{+∞} (-1)^i = \sum\limits_{i=0}^{+∞} \lim\limits_{x⇝1^-} (-x)^i$

若幂级数在点$x_1 - x_0$处的绝对极限将收敛，则在点$x_1 - x_0$处绝对收敛为该极限。

$\left[ \lim\limits_{x⇝x_1} \sum\limits_{i=0}^{+∞} | p_i · (x - x_0) |^i ⇝ F_{x_1} \right] \mathop{⇒}\limits^{| x - x_0 | ≤ | x_1 - x_0 |} \left[ \sum\limits_{i=0}^{+∞} | p_i · (x_1 - x_0) |^i ⇝ F_{x_1} \right]$

$F_{x_1} ⇜ \lim\limits_{x⇝x_1} \sum\limits_{i=0}^{+∞} | p_i | · | x - x_0 |^i ≤ \sum\limits_{i=0}^{+∞} | p_i | · | x_1 - x_0 |^i = \lim\limits_{n⇝+∞} \sum\limits_{i=0}^n \lim\limits_{x⇝x_1} | p_i | · | x - x_0 |^i = \lim\limits_{n⇝+∞} \lim\limits_{x⇝x_1} \sum\limits_{i=0}^n | p_i | · | x - x_0 |^i ≤ \rlap{≡≡≡} \lim\limits_{n⇝+∞} \lim\limits_{x⇝x_1} \sum\limits_{i=0}^{+∞} | p_i | · | x - x_0 |^i ⇝ F_{x_1}$

同起点幂级数可做加运算，其绝对收敛半径至少为共同的绝对收敛半径。

同起点幂级数可做乘运算，其绝对收敛半径至少为各绝对收敛半径之积。

$\left[ \sum\limits_{i=0}^{+∞} p_i · (x - x_0)^i \right] ± \left[ \sum\limits_{j=0}^{+∞} q_j · (x - x_0)^j \right] \mathop{=======}\limits_{| x - x_0 |<R_{pq}}^{R_{pq}≡\min\lbrace R_p, R_q \rbrace} \sum\limits_{l=0}^{+∞} (p_l ± q_l) · (x - x_0)^l$

$\left[ \sum\limits_{i=0}^{+∞} p_i · (x - x_0)^i \right] · \left[ \sum\limits_{j=0}^{+∞} q_j · (x - x_0)^j \right] \mathop{======}\limits_{| x - x_0 | < R_p · R_q} \sum\limits_{l=0}^{+∞} \left[ \sum\limits_{k=0}^l p_k · q_{l-k} \right] · (x - x_0)^l$

| $⇓$  | $\dfrac{1}{R_{pq}} ≡ \dfrac{1}{\min\lbrace R_p, R_q \rbrace} = \max\left\lbrace \dfrac{1}{R_p}, \dfrac{1}{R_q} \right\rbrace = \max\left\lbrace \varlimsup\limits_{l⇝+∞} \sqrt[l]{| p_l |}, \varlimsup\limits_{l⇝+∞} \sqrt[l]{| q_l |} \right\rbrace = \varlimsup\limits_{l⇝+∞} \sqrt[l]{\max\lbrace | p_l |, | q_l |\rbrace}$ |      |                                                              |
| :--: | ------------------------------------------------------------ | :--: | :----------------------------------------------------------- |
| $⇓$  | $\dfrac{1}{R} ≡ \varlimsup\limits_{l⇝+∞} \sqrt[l]{| p_l ± q_l |} ≤ \varlimsup\limits_{l⇝+∞} \sqrt[l]{| p_l | + | q_l |} ≤ \varlimsup\limits_{l⇝+∞} \sqrt[l]{2 · \max\lbrace| p_l |, | q_l |\rbrace} = \varlimsup\limits_{l⇝+∞} \sqrt[l]{\max\lbrace| p_l |, | q_l |\rbrace} = \dfrac{1}{R_{pq}}$ | $⇒$  | $R_{pq} ≤ \dfrac{1}{\varlimsup\limits_{l⇝+∞} \sqrt[l]{| p_l ± q_l |}} ≡ R$ |
| $⇓$  | $\dfrac{1}{R_{pq}} = \varlimsup\limits_{l⇝+∞} \sqrt[l]{\max\lbrace| p_l |, | q_l|\rbrace} ≤ \varlimsup\limits_{l⇝+∞} \sqrt[l]{| p_l | + | q_l |} \mathop{=====}\limits^{0 ≤ ± · p_l · q_l} \varlimsup\limits_{l⇝+∞} \sqrt[l]{| p_l ± q_l |} ≡ \dfrac{1}{R}$ | $⇒$  | $R_{pq} \mathop{=====}\limits^{0 ≤ ± · p_l · q_l} R$         |
| $⇓$  | $\left| \dfrac{1}{R_p} - \dfrac{1}{R_q} \right| = \left| \varlimsup\limits_{l⇝+∞} \sqrt[l]{| p_l |} - \varlimsup\limits_{l⇝+∞} \sqrt[l]{| q_l |} \right| ≤ \varlimsup\limits_{l⇝+∞} \left| \sqrt[l]{| p_l |} - \sqrt[l]{| q_l |} \right| ≤ \varlimsup\limits_{l⇝+∞} \sqrt[l]{|| p_l | - | q_l ||} ≤ \varlimsup\limits_{l⇝+∞} \sqrt[l]{| p_l ± q_l |} ≡ \dfrac{1}{R}$ | $⇒$  | $R_{pq} ≤ R ≤ \dfrac{R_p · R_q}{| R_p - R_q |} \mathop{========}\limits^{\max\lbrace R_p, R_q \rbrace = +∞} R_{pq}$ |

| $⇓$  | $\lim\limits_{n⇝+∞} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i · t_{n-i} \right] = \lim\limits_{n⇝+∞} s_n · t_n$ |      |                                                   |
| :--: | :----------------------------------------------------------- | :--: | ------------------------------------------------- |
| $⇓$  | $\dfrac{1}{R} ≡ \varlimsup\limits_{l⇝+∞} \sqrt[l]{\left| \sum\limits_{k=0}^l p_k · q_{l-k} \right|} ≤ \varlimsup\limits_{l⇝+∞} \sqrt[l]{\sum\limits_{k=0}^l | p_k | · | q_{l-k} |} = \varlimsup\limits_{l⇝+∞} \sqrt[l]{l + 1} · \varlimsup\limits_{l⇝+∞} \sqrt[l]{\dfrac{1}{l + 1} · \sum\limits_{k=0}^l | p_k | · | q_{l-k} |} = \varlimsup\limits_{l⇝+∞} \sqrt[l]{| p_l | · | q_l |} = \dfrac{1}{R_p · R_q}$ | $⇒$  | $R_p · R_q ≤ R$                                   |
| $⇓$  | $\dfrac{1}{R_p · R_q} = \varlimsup\limits_{l⇝+∞} \sqrt[l]{\sum\limits_{k=0}^l | p_k | · | q_{l-k} |} \mathop{===}\limits_{q_j⪌0}^{p_i⪌0} \varlimsup\limits_{l⇝+∞} \sqrt[l]{\left| \sum\limits_{k=0}^l p_k · q_{l-k} \right|} ≡ \dfrac{1}{R}$ | $⇒$  | $R_p · R_q \mathop{===}\limits_{q_j⪌0}^{p_i⪌0} R$ |

附加证明：$|| p_l |^{\frac{1}{l}} - | q_l |^{\frac{1}{l}}| ≤ || p_l | - | q_l ||^\frac{1}{l}$

| $⇓$  | $| x | + | y | ≤ (| x |^\frac{1}{l} + | y |^{\frac{1}{l}})^l$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $(| x | + | y |)^\frac{1}{l} ≤ | x |^\frac{1}{l} + | y |^{\frac{1}{l}}$ |
| $⇓$  | $| x |^{\frac{1}{l}} ≤ || x | - | y ||^{\frac{1}{l}} + | y |^{\frac{1}{l}}$ |
| $⇓$  | $|| x |^{\frac{1}{l}} - | y |^{\frac{1}{l}}| ≤ || x | - | y ||^\frac{1}{l}$ |

