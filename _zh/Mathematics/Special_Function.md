---
layout:  zh_post
Topic :  收敛极限
Title :  特殊函数
Update:  2021-02-22T03:20:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 函数$\mathcal{Q} (x)$

$\mathcal{Q} (x) = \mathop{1}\limits_{x∈Q}; \mathop{0}\limits_{x∉Q}$

函数$\mathrm{Q} (x)$在区间$[0, 1]$内，处处不连续，也处处不可导。

### 函数$\mathcal{R} (x)$

$\mathcal{R} (x) \mathop{======}\limits_{m∈ℤ;n∈ℤ^+}^{1 = \gcd (|m|, |n|)} \mathop{\dfrac{1}{n}}\limits_{x=\frac{m}{n}}; \mathop{0}\limits_{x≠\frac{m}{n}}$

函数$\mathcal{R} (x)$在区间$ℝ$内，任何无理点处连续，任何有理点处不连续。

| $⇓$  | $∀x,x_0∈ℝ;∀ε>0; \left[ ε ≤ \mathop{\mathcal{R} (x)}\limits_{x=\frac{m}{n}} \right] ⇒ \left[ x∈\mathop{\left\lbrace \dfrac{m_i}{n_j} \right\rbrace}\limits_{1≤n_j≤\frac{1}{ε}}^{1≤m_i} \right]$ | $P ⇒ Q$                   |
| :--: | :----------------------------------------------------------- | :------------------------ |
| $⇓$  | $∀x,x_0∈ℝ;∀ε>0;∃δ=\min\mathop{\left\lbrace \dfrac{m_i}{n_j} \right\rbrace}\limits_{1≤n_j≤\frac{1}{ε}}^{1≤m_i}=\dfrac{1}{\max\lbrace n_j \rbrace}=\dfrac{1}{⌊\frac{1}{ε}⌋}; \left[ | x - \mathop{x_0}\limits_{x_0≠\frac{p}{q}} | ≤ x < δ \right] ⇒ \left[ \left| \mathcal{R} (x) - \mathop{\mathcal{R} (x_0)}\limits_{x_0≠\frac{p}{q}} \right| = \mathcal{R} (x) = \left[ \mathop{\mathcal{R} (x)}\limits_{x=\frac{m}{n}};\mathop{0}\limits_{x≠\frac{m}{n}} \right] < ε \right]$ | $¬Q ⇒ ¬P$                 |
| $⇓$  | $\lim\limits_{x⇝x_0≠\frac{m}{n}} \mathcal{R} (x) ⇝ \mathcal{R} (x_0)$ |                           |
|      |                                                              |                           |
| $⇓$  | $∀x,x_0∈ℝ;∃ε_0>0;∀δ>0; \left[ | x - x_0 | < δ \right] ∧ \left| \mathcal{R} (x) - \mathop{\mathcal{R} (x_0)}\limits_{x_0=\frac{p}{q}} \right| = \left| \left[ \mathop{\dfrac{1}{n}}\limits_{x=\frac{m}{n}};\mathop{0}\limits_{x≠\frac{m}{n}} \right] - \dfrac{1}{q} \right| \mathop{≥}\limits_{x≠\frac{m}{n}} \dfrac{1}{q} = ε_0$ | $¬[ P ⇒ Q ] ⇔ [ P ∧ ¬Q ]$ |
| $⇓$  | $\lim\limits_{x⇝x_0=\frac{m}{n}} \mathcal{R} (x) \not⇝ \mathcal{R} (x_0)$ |                           |

### 函数$\mathcal{F} (x)$

$\lbrace (X_{i,j} - I_{i}, X_{i,j} + I_{i}) \rbrace \mathop{≡≡≡≡≡}\limits_{I_{i}=\frac{1}{2^{2·i+3}}}^{X_{i,j}=\frac{2·j+1}{2^{i+1}}} \bigcup\limits_{i=0}^{+∞} \bigcup\limits_{j=0}^{2^i-1} \left( \dfrac{2 · j + 1}{2^{i + 1}} - \dfrac{1}{2^{2 · i + 3}}, \dfrac{2 · j + 1}{2^{i + 1}} + \dfrac{1}{2^{2 · i + 3}} \right) = \bigcup\limits_{i=1}^{+∞} \bigcup\limits_{j=1}^{2^{i-1}} \left( \dfrac{2·j-1}{2^i} - \dfrac{1}{2^{2·i+1}}, \dfrac{2·j-1}{2^i} + \dfrac{1}{2^{2·i+1}} \right)$

$| \lbrace (X_{i,j} - I_{i}, X_{i,j} + I_{i}) \rbrace | = \sum\limits_{i=0}^{+∞} \sum\limits_{j=0}^{2^i - 1} 2 · I_i = \sum\limits_{i=0}^{+∞} 2^i · \dfrac{2}{2^{2·i+3}} = \sum\limits_{i=0}^{+∞} \dfrac{1}{2^{i+2}} = \dfrac{\frac{1}{4}}{1 - \frac{1}{2}} = \dfrac{1}{2}$

| $I_0 = \dfrac{1}{2^3}$ | $\left( \dfrac{1}{2^1} - \dfrac{1}{2^3}, \dfrac{1}{2^1} + \dfrac{1}{2^3} \right)$ |
| :--------------------: | :----------------------------------------------------------: |
| $I_1 = \dfrac{1}{2^5}$ | $\left( \dfrac{1}{2^2} - \dfrac{1}{2^5}, \dfrac{1}{2^2} + \dfrac{1}{2^5} \right) ∪ \left( \dfrac{3}{2^2} - \dfrac{1}{2^5}, \dfrac{3}{2^2} + \dfrac{1}{2^5} \right)$ |
| $I_2 = \dfrac{1}{2^7}$ | $\left( \dfrac{1}{2^3} - \dfrac{1}{2^7}, \dfrac{1}{2^3} + \dfrac{1}{2^7} \right) ∪ \left( \dfrac{3}{2^3} - \dfrac{1}{2^7}, \dfrac{3}{2^3} + \dfrac{1}{2^7} \right) ∪ \left( \dfrac{5}{2^3} - \dfrac{1}{2^7}, \dfrac{5}{2^3} + \dfrac{1}{2^7} \right) ∪ \left( \dfrac{7}{2^3} - \dfrac{1}{2^7}, \dfrac{7}{2^3} - \dfrac{1}{2^7} \right)$ |

$\mathcal{F} (x) ≡ \mathop{I_i - \left| x - X_{i,j} \right|}\limits_{| x - X_{i,j} | < I_{i}}; \mathop{0}\limits_{| x - X_{i,j} | ≥ I_{i}}$

函数$\mathcal{F} (x)$在区间$[0, 1]$内连续，在以点$X_{i,j}$为中点且以$I_i$为半径的区间内呈三角形状，其三角形状区间的可测度长度为$\dfrac{1}{2}$。

### 函数$\mathrm{sgn} (x)$

$\mathrm{sgn} (x) = \mathop{-1}\limits_{x<0};\mathop{0}\limits_{x=0};\mathop{+1}\limits_{x>0}$

$\mathrm{sgn} (\mathcal{R} (x)) = \mathcal{Q} (x)$
