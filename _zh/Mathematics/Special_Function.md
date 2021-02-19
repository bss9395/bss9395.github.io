---
layout:  zh_post
Topic :  收敛极限
Title :  特殊函数
Update:  2021-02-20T01:43:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 函数$\mathcal{D} (x)$

$\mathcal{D} (x) = \mathop{1}\limits_{x∈Q}; \mathop{0}\limits_{x∉Q}$

函数$\mathrm{D} (x)$在区间$[0, 1]$内处处不连续。

### 函数$\mathcal{R} (x)$

$\mathcal{R} (x) = \mathop{\dfrac{1}{\min | n |}}\limits_{x=\frac{m}{n}}; \mathop{0}\limits_{x≠\frac{m}{n}}$

函数$\mathcal{R} (x)$在区间$[0, 1]$内，任何无理点处连续，任何有理点处不连续。

| $⇓$  | $∀x∈[0, 1];∀ε>0; \left[ ε ≤ \dfrac{1}{N} = \mathcal{R} (x) ≤ 1 \right] ⇒ \left[ x ∈ \mathop{\left\lbrace \dfrac{m_i}{n_j}  \right\rbrace}\limits_{1≤m_i≤n_j≤N≤\frac{1}{ε}} \right]$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∀x∈[0, 1];∀ε>0;∃δ>0; \left[ | x - x_0 | < δ = \min \left\lbrace \dfrac{m_i}{n_j} \right\rbrace \right] ⇒ \left[ \left| \mathop{\mathcal{R} (x)} - \mathop{\mathcal{R} (x_0)}\limits_{x_0≠\frac{m}{n}} \right| \mathop{==}\limits_{N<n} \left| \mathop{\dfrac{1}{n}}\limits_{x=\frac{m}{n}}; \mathop{0}\limits_{x≠\frac{m}{n}} \right| < ε \right]$ |
| $⇓$  | $\lim\limits_{x⇝x_0≠\frac{m}{n}} R (x) ⇝ 0$                  |

