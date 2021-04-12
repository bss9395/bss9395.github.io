---
layout:  zh_post
Topic :  收敛极限
Title :  特殊函数
Update:  2021-04-12T20:17:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 特征函数$\mathcal{X}_{I} (x)$

$\mathcal{X}_{I} (x) = \mathop{1}\limits_{x∈I};\mathop{0}\limits_{x∉I}$

### 有理函数$\mathcal{Q} (x)$

$\mathcal{Q} (x) = \mathop{1}\limits_{x∈ℚ}; \mathop{0}\limits_{x∉ℚ}$

函数$\mathcal{Q} (x)$在区间$[X_0, X_1]⊆ℝ$内，处处不连续，也处处不可导。

### 实数函数$\mathcal{R} (x)$

$\mathcal{R} (x) \mathop{======}\limits_{m∈ℤ;n∈ℤ^+}^{1 = \gcd (|m|, |n|)} \mathop{\dfrac{1}{n}}\limits_{x=\frac{m}{n}}; \mathop{0}\limits_{x≠\frac{m}{n}}$

函数$\mathcal{R} (x)$在区间$[X_0,X_1]⊆ℝ$内，任何无理点处连续，任何有理点处不连续。

| $⇓$  | $∀x_0∈X;∀ε>0;∃δ>0;∀x∈X; \left[ \dfrac{1}{n} = \left| \mathop{\mathcal{R} (x)}\limits_{x=\frac{m}{n}} - \mathop{\mathcal{R} (x_0)}\limits_{x_0≠\frac{p}{q}} \right| > ε \right] ⇒ \left[ \left| \mathop{x}\limits_{x=\frac{m}{n}} - \mathop{x_0}\limits_{x_0≠\frac{p}{q}} \right| ∈\left\lbrace \left| \mathop{\dfrac{m_j}{n_i}}\limits_{n_i<\frac{1}{ε}} - \mathop{x_0}\limits_{x_0≠\frac{p}{q}} \right| \right\rbrace \right]$ | $¬Q ⇒ ¬P$               |
| :--: | :----------------------------------------------------------- | :---------------------- |
| $⇓$  | $∀x_0∈X;∀ε>0;∃δ<\min\left\lbrace \left| \mathop{\dfrac{m_j}{n_i}}\limits_{n_i<\frac{1}{ε}} - \mathop{x_0}\limits_{x_0≠\frac{p}{q}} \right| \right\rbrace;∀x∈X; \left[ | x - \mathop{x_0}\limits_{x_0≠\frac{p}{q}} | ≤ δ \right] ⇒ \left[ \sup \left| \mathcal{R} (x) - \mathop{\mathcal{R} (x_0)}\limits_{x_0≠\frac{p}{q}} \right| = \sup \left| \mathop{\dfrac{1}{n}}\limits_{x=\frac{m}{n}};\mathop{0}\limits_{x≠\frac{m}{n}} \right| = \dfrac{1}{n} ≤ ε \right]$ | $P ⇒ Q$                 |
| $⇓$  | $\lim\limits_{x⇝x_0≠\frac{m}{n}} \mathcal{R} (x) ⇝ \mathcal{R} (x_0)$ |                         |
|      |                                                              |                         |
| $⇓$  | $∃x_0∈X;∃ε>0;∀δ>0;∀x∈X; \left[ \left| x - \mathop{x_0}\limits_{x_0=\frac{p}{q}} \right| ≤ δ \right] ∧ \left[ \sup \left| \mathcal{R} (x) - \mathop{\mathcal{R} (x_0)}\limits_{x_0=\frac{p}{q}} \right| = \sup \left| \left[ \mathop{\dfrac{1}{n}}\limits_{x=\frac{m}{n}};\mathop{0}\limits_{x≠\frac{m}{n}} \right] - \dfrac{1}{q} \right| ≥ \dfrac{1}{q} > ε \right]$ | $¬[ P ⇒ Q ] ⇔ [P ∧ ¬Q]$ |
| $⇓$  | $\lim\limits_{x⇝x_0=\frac{m}{n}} \mathcal{R} (x) \not⇝ \mathcal{R} (x_0)$ |                         |

必存在函数$f (x)$在区间$[X_0, X_1]⊆ℝ$内，任何无理点处连续，任何有理点处连续。例如$f (x) ≡ x$。

必存在函数$f (x)$在区间$[X_0, X_1]⊆ℝ$内，任何无理点处不连续，任何有理点处不连续。例如$f (x) ≡ \mathcal{Q} (x)$。

必存在函数$f (x)$在区间$[X_0,X_1]⊆ℝ$内，任何无理点处连续，任何有理点处不连续。例如$f (x) ≡ \mathcal{R} (x)$。

$∀x_n,r_0,q_0∈[X_0,X_1];∃f(x); \left[ \lim\limits_{n⇝+∞}^{Δx⇝0} \sup | f (x_n) - \mathop{f (r_0)}\limits_{r_0∉ℚ} | ⇝ 0 \right] ∧ \left[ \lim\limits_{n⇝+∞}^{Δx⇝0} \sup | f (x_n) - \mathop{f (q_0)}\limits_{q_0∈ℚ} | > 0 \right]$

不存在函数$f (x)$在区间$[X_0,X_1]⊆ℝ$内，任何无理点处不连续，任何有理点处连续。

$∀x_n,r_0,q_0∈[X_0,X_1];¬∃f(x); \left[ \lim\limits_{n⇝+∞}^{Δx⇝0} \sup | f (x_n) - \mathop{f (r_0)}\limits_{r_0∉ℚ} | > 0 \right] ∧ \left[ \lim\limits_{n⇝+∞}^{Δx⇝0} \sup | f (x_n) - \mathop{f (q_0)}\limits_{q_0∈ℚ} | ⇝ 0 \right]$

| $⇓$  | $∀r∈[X_0,X_1]\backslashℚ;∃ε>0;∀δ>0; [ | x - r_0 | < δ ] ∧ [ \sup | f (x) - f (r) | ≥ ε ]$ |      |                                                              |                  |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- | :--------------- |
| $⇓$  | $∀r∈[X_0,X_1]\backslashℚ;∃m∈ℕ;∃ε>0; \lim\limits_{n⇝+∞}^{Δx⇝0} \sup | f (x_n) - f (r) | ≥ ε ≥ \dfrac{1}{m+1}$ |      |                                                              |                  |
| $⇓$  | $∀r; [ r ∈ [X_0,X_1]\backslashℚ ] ⇒ \left[ r ∈ \bigcup\limits_{m=0}^{ℕ} \mathop{r_m}\limits_{w^f (r_m)≥\frac{1}{m+1}} \right]$ | $⇒$  | $r_m ∈ \left( r_m - \dfrac{ζ}{2^{m+1}}, r_m + \dfrac{ζ}{2^{m+1}} \right)$ |                  |
| $⇓$  | $[X_0,X_1] \backslash ℚ ⊆ \bigcup\limits_{m=0}^{ℕ} \mathop{r_0}\limits_{w^f(r_0)≥\frac{1}{m+1}} ⊆ \mathcal{O}$ | $⇒$  | $[X_0,X_1] \backslash ℚ ⊆ \mathcal{O}$                       | $\mathrm{False}$ |

### 分形函数$\mathcal{F} (x)$

$\lbrace (X_{i,j} - I_{i}, X_{i,j} + I_{i}) \rbrace \mathop{≡≡≡≡≡}\limits_{I_{i}=\frac{1}{2^{2·i+3}}}^{X_{i,j}=\frac{2·j+1}{2^{i+1}}} \bigcup\limits_{i=0}^{+∞} \bigcup\limits_{j=0}^{2^i-1} \left( \dfrac{2 · j + 1}{2^{i + 1}} - \dfrac{1}{2^{2 · i + 3}}, \dfrac{2 · j + 1}{2^{i + 1}} + \dfrac{1}{2^{2 · i + 3}} \right) = \bigcup\limits_{i=1}^{+∞} \bigcup\limits_{j=1}^{2^{i-1}} \left( \dfrac{2·j-1}{2^i} - \dfrac{1}{2^{2·i+1}}, \dfrac{2·j-1}{2^i} + \dfrac{1}{2^{2·i+1}} \right)$

$| \lbrace (X_{i,j} - I_{i}, X_{i,j} + I_{i}) \rbrace | = \sum\limits_{i=0}^{+∞} \sum\limits_{j=0}^{2^i - 1} 2 · I_i = \sum\limits_{i=0}^{+∞} \sum\limits_{j=0}^{2^i-1} \dfrac{2}{2^{2·i+3}} = \sum\limits_{i=0}^{+∞} 2^i · \dfrac{2}{2^{2·i+3}} = \sum\limits_{i=0}^{+∞} \dfrac{1}{2^{i+2}} = \dfrac{\frac{1}{4}}{1 - \frac{1}{2}} = \dfrac{1}{2}$

| $I_0 = \dfrac{1}{2^3}$ | $\left( \dfrac{1}{2^1} - \dfrac{1}{2^3}, \dfrac{1}{2^1} + \dfrac{1}{2^3} \right)$ |
| :--------------------: | :----------------------------------------------------------: |
| $I_1 = \dfrac{1}{2^5}$ | $\left( \dfrac{1}{2^2} - \dfrac{1}{2^5}, \dfrac{1}{2^2} + \dfrac{1}{2^5} \right) ∪ \left( \dfrac{3}{2^2} - \dfrac{1}{2^5}, \dfrac{3}{2^2} + \dfrac{1}{2^5} \right)$ |
| $I_2 = \dfrac{1}{2^7}$ | $\left( \dfrac{1}{2^3} - \dfrac{1}{2^7}, \dfrac{1}{2^3} + \dfrac{1}{2^7} \right) ∪ \left( \dfrac{3}{2^3} - \dfrac{1}{2^7}, \dfrac{3}{2^3} + \dfrac{1}{2^7} \right) ∪ \left( \dfrac{5}{2^3} - \dfrac{1}{2^7}, \dfrac{5}{2^3} + \dfrac{1}{2^7} \right) ∪ \left( \dfrac{7}{2^3} - \dfrac{1}{2^7}, \dfrac{7}{2^3} - \dfrac{1}{2^7} \right)$ |

$\mathcal{F} (x) ≡ \mathop{I_i - \left| x - X_{i,j} \right|}\limits_{| x - X_{i,j} | < I_{i}}; \mathop{0}\limits_{| x - X_{i,j} | ≥ I_{i}}$

函数$\mathcal{F} (x)$在区间$[0, 1]$内连续，在以点$X_{i,j}$为中点且以$I_i$为半径的区间内呈三角形状，其三角形状区间的可测度长度为$\dfrac{1}{2}$。

### 符号函数$\mathrm{sgn} (x)$

$\mathrm{sgn} (x) = \mathop{-1}\limits_{x<0};\mathop{0}\limits_{x=0};\mathop{+1}\limits_{x>0}$

$\mathrm{sgn} (\mathcal{R} (x)) = \mathcal{Q} (x)$

### 振荡函数$\sin \dfrac{1}{x}$

$f(x) = \mathop{0}\limits_{x≤0};\mathop{x^{0} · \sin \dfrac{1}{x}}\limits_{x>0}$，在点$x = 0$处振荡。

$f(x) = \mathop{0}\limits_{x≤0};\mathop{x^{1} · \sin \dfrac{1}{x}}\limits_{x>0}$，在点$x = 0$处连续。

| $f(x) = \mathop{0}\limits_{x≤0};\mathop{x^{0} · \sin \dfrac{1}{x}}\limits_{x>0}$ | $\lim\limits_{\mathop{x⇝0}\limits_{x=\frac{1}{2·n·π}}} x^{0} · \sin \dfrac{1}{x} ⇝ 0$ | $\lim\limits_{\mathop{x⇝0}\limits_{x=\frac{1}{2·n·π}+\frac{π}{2}}} x^{0} · \sin \dfrac{1}{x} ⇝ 1$ |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| $f(x) = \mathop{0}\limits_{x≤0};\mathop{x^{1} · \sin \dfrac{1}{x}}\limits_{x>0}$ | $\lim\limits_{x⇝0} x^{1} · \sin \dfrac{1}{x} ⇝ 0$            |                                                              |
|                                                              |                                                              |                                                              |

