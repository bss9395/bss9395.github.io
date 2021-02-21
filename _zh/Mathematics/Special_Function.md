---
layout:  zh_post
Topic :  收敛极限
Title :  特殊函数
Update:  2021-02-21T00:15:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 函数$\mathcal{Q} (x)$

$\mathcal{Q} (x) = \mathop{1}\limits_{x∈Q}; \mathop{0}\limits_{x∉Q}$

函数$\mathrm{Q} (x)$在区间$[0, 1]$内，处处不连续，也处处不可导。

### 函数$\mathcal{R} (x)$

$\mathcal{R} (x) \mathop{======}\limits_{m∈ℤ;n∈ℤ^+}^{1 = \gcd (|m|, |n|)} \mathop{\dfrac{1}{n}}\limits_{x=\frac{m}{n}}; \mathop{0}\limits_{x≠\frac{m}{n}}$

函数$\mathcal{R} (x)$在区间$[0, 1]$内，任何无理点处连续，任何有理点处不连续。

| $⇓$  | $∀x,x_0∈[0, 1];∀ε>0; \left[ ε ≤ \mathop{\mathcal{R} (x)}\limits_{x=\frac{m}{n}} \right] ⇒ \left[ x∈\left\lbrace \mathop{\dfrac{m_i}{n_j}}\limits_{1≤m_i≤n_j≤\frac{1}{ε}} \right\rbrace \right]$ | $P ⇒ Q$   |
| :--: | :----------------------------------------------------------- | :-------- |
| $⇓$  | $∀x,x_0∈[0, 1];∀ε>0;∃δ=\min\left\lbrace \mathop{\dfrac{m_i}{n_j}}\limits_{1≤m_i≤n_j≤\frac{1}{ε}} \right\rbrace=\dfrac{1}{\max\lbrace n_j \rbrace}=\dfrac{1}{⌊\frac{1}{ε}⌋}; \left[ | x - \mathop{x_0}\limits_{x_0≠\frac{m}{n}} | ≤ x < δ \right] ⇒ \left[ \left| \mathcal{R} (x) - \mathop{\mathcal{R} (x_0)}\limits_{x_0≠\frac{m}{n}} \right| = \mathcal{R} (x) = \left[ \mathop{\mathcal{R} (x)}\limits_{x=\frac{m}{n}};\mathop{0}\limits_{x≠\frac{m}{n}} \right] < ε \right]$ | $¬Q ⇒ ¬P$ |
| $⇓$  | $\lim\limits_{x⇝x_0≠\frac{m}{n}} \mathcal{R} (x) ⇝ \mathcal{R} (x_0)$ |           |
|      |                                                              |           |
| $⇓$  | $∀x,x_0∈[0, 1];∃ε_0>0;\left| \mathcal{R} (x) - \mathop{\mathcal{R} (x_0)}\limits_{x_0=\frac{p}{q}} \right| = \left| \left[ \mathop{\dfrac{1}{n}}\limits_{x=\frac{m}{n}};\mathop{0}\limits_{x≠\frac{m}{n}} \right] - \dfrac{1}{q} \right| \mathop{≥}\limits_{x≠\frac{m}{n}} \dfrac{1}{q} = ε_0$ |           |
| $⇓$  | $\lim\limits_{x⇝x_0=\frac{m}{n}} \mathcal{R} (x) ⇝ \mathcal{R} (x_0)$ |           |

### 函数$\mathrm{sgn} (x)$

$\mathrm{sgn} (x) = \mathop{-1}\limits_{x<0};\mathop{0}\limits_{x=0};\mathop{+1}\limits_{x>0}$

$\mathrm{sgn} (\mathcal{R} (x)) = \mathcal{Q} (x)$
