---
layout:  zh_post
Topic :  收敛极限
Title :  特殊函数
Update:  2021-04-18T21:21:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 特征函数$\mathcal{X}_{I} (x)$

$\mathcal{X}_{I} (x) = \mathop{1}\limits_{x∈I};\mathop{0}\limits_{x∉I}$

### 有理函数$\mathcal{Q} (x)$

$\mathcal{Q} (x) = \mathop{1}\limits_{x∈ℚ}; \mathop{0}\limits_{x∉ℚ}$

函数$\mathcal{Q} (x)$在区间$ℝ$内，处处不连续，处处不可导。

| $⇓$  | $∀x_0∈ℝ;∃ε=1;∀δ>0; \sup\limits_{u,v∈\mathrm{U}(x_0,δ)} \mathop{|f(u) - f(v)|}\limits_{u∈ℚ,v∉ℚ} = ε$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $\lim\limits_{δ⇝0} w^f (x_0,δ) \not⇝ 0$                      |

### 实数函数$\mathcal{R} (x)$

$\mathcal{R} (x) \mathop{======}\limits_{m∈ℤ;n∈ℤ^+}^{1 = \gcd (|m|, |n|)} \mathop{\dfrac{1}{n}}\limits_{x=\frac{m}{n}}; \mathop{0}\limits_{x≠\frac{m}{n}}$

函数$\mathcal{R} (x)$在区间$ℝ$内，任何有理点处不连续，任何无理点处连续。
| $⇓$  | $∀x_0∉ℚ;∀ε>0;∃δ>0;∀x∈ℝ; \left[\left| \mathcal{R}(x) - \mathcal{R}(x_0) \right| > ε\right] ⇒ \left[ x ∈ \left\lbrace ∀m_j∈ℤ;∀n_i∈ℕ; \dfrac{m_j}{n_i} : \dfrac{1}{n_i} > ε \right\rbrace \right]$ | $¬Q ⇒ ¬P$ |
| :--: | :----------------------------------------------------------- | :-------- |
| $⇓$  | $∀x_0∉ℚ;∀ε>0;∃δ>0;∀x∈ℝ; \left[ |x - x_0| < \min\left\lbrace ∀m_j∈ℤ;∀n_i∈ℕ; \left| \dfrac{m_j}{n_i} - x_0 \right|: \dfrac{1}{n_i} > ε \right\rbrace = δ \right] ⇒ \left[ \left| \mathcal{R}(x) - \mathcal{R}(x_0) \right| = \left| \mathop{\dfrac{1}{n}}\limits_{x=\frac{m}{n}};\mathop{0}\limits_{x≠\frac{m}{n}} \right| ≤ ε \right]$ | $P ⇒ Q$   |
| $⇓$  | $\lim\limits_{x⇝x_0≠\frac{p}{q}} \mathcal{R} (x) ⇝ \mathcal{R} (x_0)$ |           |
|      |                                                              |           |
| $⇓$  | $∃x_0=\dfrac{p}{q}∈ℚ;∃ε>0;∀δ>0; \sup\limits_{x∈\mathrm{U}(x_0,δ)} \left| \mathcal{R}(x) - \mathcal{R}(x_0) \right| = \sup\limits_{x∈\mathrm{U}(x_0,δ)} \left| \mathop{\dfrac{1}{n}}\limits_{x=\frac{m}{n}};\mathop{0}\limits_{x≠\frac{m}{n}} - \dfrac{1}{q} \right| ≥ \dfrac{1}{q}$ |           |
| $⇓$  | $\lim\limits_{x⇝x_0=\frac{p}{q}} \mathcal{R} (x) \not⇝ \mathcal{R} (x_0)$ |           |

必存在函数$f (x)$在区间$ℝ$内，任何有理点处连续，任何无理点处连续。例如$f (x) ≡ x$。

必存在函数$f (x)$在区间$ℝ$内，任何有理点处不连续，任何无理点处不连续。例如$f (x) ≡ \mathcal{Q}(x)$。

必存在函数$f (x)$在区间$ℝ$内，任何有理点处不连续，任何无理点处连续。例如$f (x) ≡ \mathcal{R}(x)$。

$∃f(x); \left[ ∀r∈ℚ;∃ε>0;∀δ>0; \sup\limits_{x∈\mathrm{U}(r,δ)} |f(x) - f(r)| > ε \right] ∧ \left[ ∀r∉ℚ;∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{U}(r,δ)} |f(x) - f(r)| ≤ ε \right]$

$∃f(x);∀r∈ℝ; [r∉ℚ] ⇔ \left[ ∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{U}(r,δ)} |f(x) - f(r)| ≤ ε \right]$

不存在函数$f (x)$在区间$ℝ$内，任何有理点处连续，任何无理点处不连续。

$¬∃f(x); \left[ ∀r∈ℚ;∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{U}(r,δ)} |f(x) - f(r)| ≤ ε \right] ∧ \left[ ∀r∉ℚ;∃ε>0;∀δ>0; \sup\limits_{x∈\mathrm{U}(r,δ)} |f(x) - f(r)| > ε \right]$

$¬∃f(x);∀r∈ℝ; [r∈ℚ] ⇔ \left[ ∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{U}(r,δ)} |f(x) - f(r)| ≤ ε \right]$

| $⇓$  | $∃f(x);∀r∈ℝ; [r∉ℚ] ⇔ \left[ ∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{U}(r,δ)} |f(x) - f(r)| ≤ ε \right]$ | $¬Q$                |
| :--: | :----------------------------------------------------------- | :------------------ |
| $⇓$  | $∃f(x); \left[ ∀r∈ℚ;∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{U}(r,δ)} |f(x) - f(r)| ≤ ε \right] ∧ \left[ ∀r∉ℚ;∃ε>0;∀δ>0; \sup\limits_{x∈\mathrm{U}(r,δ)} |f(x) - f(r)| > ε \right]$ | $P$                 |
| $⇓$  | $∃f(x); \left[ ∀r∈ℝ; [r∈ℚ] ⇒ \left[ ∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{U}(r,δ)} |f(x) - f(r)| ≤ ε \right] \right] ∧ \left[ ∀∈ℝ; [r∉ℚ] ⇒ \left[ ∃ε>0;∀δ>0; \sup\limits_{x∈\mathrm{U}(r,δ)} |f(x) - f(r)| > ε \right] \right]$ |                     |
| $⇓$  | $∃f(x);∀r∈ℝ; [r∈ℚ] ⇔ \left[ ∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{U}(r,δ)} |f(x) - f(r)| ≤ ε \right]$ | $P → Q$             |
| $⇓$  | $¬∃f(x); \left[ ∀r∈ℚ;∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{U}(r,δ)} |f(x) - f(r)| ≤ ε \right] ∧ \left[ ∀r∉ℚ;∃ε>0;∀δ>0; \sup\limits_{x∈\mathrm{U}(r,δ)} |f(x) - f(r)| > ε \right]$ | $¬Q ∧ (P → Q) ⇒ ¬P$ |

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

### 振荡函数$\mathcal{W}(x)$

$\mathcal{W}(x) = \mathop{0}\limits_{x≤0};\mathop{x^{0} · \sin \dfrac{1}{x}}\limits_{x>0}$，在点$x = 0$处振荡。

$\mathcal{W}(x) = \mathop{0}\limits_{x≤0};\mathop{x^{1} · \sin \dfrac{1}{x}}\limits_{x>0}$，在点$x = 0$处连续。

| $\mathcal{W}(x) = \mathop{0}\limits_{x≤0};\mathop{x^{0} · \sin \dfrac{1}{x}}\limits_{x>0}$ | $\lim\limits_{\mathop{x⇝0}\limits_{x=\frac{1}{2·n·π}}} x^{0} · \sin \dfrac{1}{x} ⇝ 0$ | $\lim\limits_{\mathop{x⇝0}\limits_{x=\frac{1}{2·n·π}+\frac{π}{2}}} x^{0} · \sin \dfrac{1}{x} ⇝ 1$ |
| :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\mathcal{W}(x) = \mathop{0}\limits_{x≤0};\mathop{x^{1} · \sin \dfrac{1}{x}}\limits_{x>0}$ | $\lim\limits_{x⇝0} x^{1} · \sin \dfrac{1}{x} ⇝ 0$            |                                                              |
|                                                              |                                                              |                                                              |

