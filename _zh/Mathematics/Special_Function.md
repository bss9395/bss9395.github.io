---
layout:  zh_post
Topic :  收敛极限
Title :  特殊函数
Update:  2021-08-02T18:58:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 绝对函数$\mathrm{abs}(x)$

$\mathrm{abs}(x) = |x| = \mathop{-x}\limits_{x<0};\mathop{0}\limits_{x=0};\mathop{+x}\limits_{x>0}$

$\dfrac{\Lambda \mathrm{abs}(0)}{\lambda x} = \lim\limits_{x⇝0} \dfrac{\mathrm{abs}(x) - \mathrm{abs}(0)}{x - 0} = \lim\limits_{x⇝0} \dfrac{|x|}{x}$

$\dfrac{\Lambda \mathrm{abs}(x)}{\lambda x} = \mathop{-1}\limits_{x<0};\mathop{|x|·x^{-1}}\limits_{x=0};\mathop{+1}\limits_{x>0} = \dfrac{|x|}{x}$

### 特征函数$\mathcal{X}_{I} (x)$

$\mathcal{X}_{I} (x) = \mathop{1}\limits_{x∈I};\mathop{0}\limits_{x∉I}$

### 有理函数$\mathcal{Q} (x)$

$\mathcal{Q} (x) = \mathop{1}\limits_{x∈ℚ}; \mathop{0}\limits_{x∉ℚ}$

函数$\mathcal{Q} (x)$在区间$ℝ$内，处处不连续，处处不可导。

| $⇓$  | $∀x_0∈ℝ;∃ε=1;∀δ>0; \sup\limits_{u,v∈\mathrm{U}(x_0,δ)} \mathop{|f(u) - f(v)|}\limits_{u∈ℚ,v∉ℚ} = ε$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $\lim\limits_{δ⇝0} w^f (x_0,δ) \not⇝ 0$                      |

函数$\mathcal{Q} (x)$在区间$[0, 1]$上有确界，但其定积分不存在。

$\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i, x_i+1]} \mathcal{Q} (x) · Δx_i = \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} 0 · Δx_i ⇝ 0 ≠ 1 ⇜ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n}  1 · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_i, x_{i+1}]} \mathcal{Q} (x) · Δx_i$

函数$\mathcal{Q}(x)$不存在原函数$F(x)$，使得$\dfrac{\mathrm{d} F(x)}{\mathrm{d}x} = \mathcal{Q}(x)$。

| $Ⅎ\dfrac{1}{2}∈[0,1]=[{^1}F(\sqrt{2}),{^1}F(0)];∃θ∈[0,\sqrt{2}]; {^1}F(θ) = \mathcal{Q}(θ) = \dfrac{1}{2}$ | $\mathrm{False}$ |
| :----------------------------------------------------------- | :--------------- |
|                                                              |                  |

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

$∃f(x); \left[ ∀q_0∈ℚ;∃ε>0;∀δ>0; w^{f}(q_0,δ) > ε \right] ∧ \left[ ∀r_0∉ℚ;∀ε>0;∃δ>0; w^{f}(r_0,δ) ≤ ε \right]$

$∃f(x);∀r∈ℝ; [r∉ℚ] ⇔ \left[ ∀ε>0;∃δ>0; w^{f}(r,δ) ≤ ε \right]$

不存在函数$f (x)$在区间$ℝ$内，任何有理点处连续，任何无理点处不连续。注意：有理数的间隙由无理数填充，反之不对。

$¬∃f(x); \left[ ∀q_0∈ℚ;∀ε>0;∃q_1>0; w^{f}(q_0,q_1) ≤ ε \right] ∧ \left[ ∀r_0∉ℚ;∃ε>0;∀δ>0; w^{f}(r_0,δ) > ε \right]$

$¬∃f(x);∀q∈ℝ; [q∈ℚ] ⇔ \left[ ∀ε>0;∃δ>0; w^{f}(q,δ) ≤ ε \right]$

| $⇓$  | $∃f(x); \left[ ∀q_0∈ℚ;∀ε_q>0;∃q_1>0; w^{f}(q_0,q_1) ≤ ε_q \right] ∧ \left[ ∀r_0∉ℚ;∃ε_r>0;∀δ>0; w^{f}(r_0,δ) > ε_r \right]$ | $P$                  |
| :--: | :----------------------------------------------------------- | :------------------- |
| $⇓$  | $∃f(x); ∀q_0∈ℚ;∀q_1∈ℚ; ∃r_0∉ℚ,r_0∈[q_0,q_1];∃ε_r=\mathrm{Con}>0;∀δ>0; w^{f}(r_0,δ) > ε_r = \mathrm{Con} > 0$ |                      |
| $⇓$  | $∃f(x); ∀q_0∈ℚ;∀ε_q>0;∃q_1>0; ∃r_0∉ℚ,r_0∈[q_0,q_1];∃ε_r=\mathrm{Con}>0;∀δ=\min\lbrace |q_0-r_0|,|q_1-r_0| \rbrace; 0 < \mathrm{Con} = ε_r < w^{f}(r_0,δ) ≤ w^{f}(q_0,q_1) ≤ ε_q$ |                      |
| $⇓$  | $∃f(x); ∀q_0∈ℚ;∀ε_q>0;∃q_1>0; \mathrm{Con} ≤ w^{f}(q_0,q_1) ≤ ε_q$ | $Q = \mathrm{False}$ |
| $⇓$  | $¬∃f(x); \left[ ∀q_0∈ℚ;∀ε>0;∃q_1>0; w^{f}(q_0,q_1) ≤ ε \right] ∧ \left[ ∀r_0∉ℚ;∃ε>0;∀δ>0; w^{f}(r_0,δ) > ε \right]$ | $¬Q ∧ (P → Q) ⇒ ¬P$  |
| $⇓$  | $¬∃f(x); \left[ ∀q∈ℝ; [q∈ℚ] ⇒ [∀ε>0;∃δ>0; w^{f}(q,δ) ≤ ε] \right] ∧ \left[ ∀q∈ℝ; [q∉ℚ] ⇒ [∃ε>0;∀δ>0; w^{f}(q,δ) > ε] \right]$ |                      |
| $⇓$  | $¬∃f(x);∀q∈ℝ; [q∈ℚ] ⇔ \left[ ∀ε>0;∃δ>0; w^{f}(q,δ) ≤ ε \right]$ |                      |

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

$\mathrm{sgn} (x) = \mathop{-1}\limits_{x<0};\mathop{0}\limits_{x=0};\mathop{+1}\limits_{x>0} = \mathop{0}\limits_{x=0};\mathop{x·|x|^{-1}}\limits_{x≠0}$

$\mathrm{sgn} (\mathcal{R} (x)) = \mathcal{Q} (x)$

$\dfrac{\mathrm{d} \mathrm{sgn}(0)}{\mathrm{d} x} = \lim\limits_{x⇝0} \dfrac{\mathrm{sgn}(x) - \mathrm{sgn}(0)}{x - 0} = \lim\limits_{x⇝0} \dfrac{1}{|x|}$

$\dfrac{\mathrm{d} \mathrm{sgn}(x)}{\mathrm{d} x} = \mathop{\dfrac{0}{x}}\limits_{x<0};\mathop{\dfrac{-1}{x}}\limits_{x=0^{-}};\mathop{\dfrac{+1}{x}}\limits_{x=0^{+}};\mathop{\dfrac{0}{x}}\limits_{x>0} = \mathop{\dfrac{1}{|x|}}\limits_{x=0};\mathop{\dfrac{0}{x}}\limits_{x≠0}$

$\lim\limits_{x⇝0} \dfrac{\mathrm{d} \mathrm{sgn}(x)}{\mathrm{d} x} ⇝ 0 ≠ \dfrac{\mathrm{d} \mathrm{sgn}(0)}{\mathrm{d} x}$

### 振荡函数$\mathcal{W}_{α}(x)$

$\mathcal{W}_{α}(x) = \mathop{0}\limits_{x=0};\mathop{x^{α} · \sin \dfrac{1}{x}}\limits_{x≠0}$

$\dfrac{\mathrm{d} \mathcal{W}_{α}(0)}{\mathrm{d} x} = \lim\limits_{x⇝0} \dfrac{\mathcal{W}_{α}(x) - \mathcal{W}_{α}(0)}{x - 0} = \lim\limits_{x⇝0} x^{α-1} · \sin \dfrac{1}{x}$

$\dfrac{\mathrm{d} \mathcal{W}_{α}(x)}{\mathrm{d} x} = \mathop{\left[ x^{α-1} · \sin \dfrac{1}{x} \right]}\limits_{x=0};\mathop{\left[ α · x^{α-1} · \sin \dfrac{1}{x} - x^{α-2} · \cos \dfrac{1}{x} \right]}\limits_{x≠0}$

当$α ≤ 0$时，$\mathcal{W}_{α}(x)$在点$x = 0$处振荡，因此其导数振荡，其导函数振荡，非一致连续。

当$0 < α ≤ 1$时，$\mathcal{W}_{α} (x)$在点$x = 0$处连续，其导数振荡，其导函数振荡，也一致连续。

当$1 < α ≤ 2$时，$\mathcal{W}_{α}(x)$在点$x = 0$处连续，其导数收敛，其导函数振荡，也一致连续。

当$2 < α$时，$\mathcal{W}_{α}(x)$在点$x = 0$处连续，并且其导数收敛，其导函数收敛，也一致连续。
| $α < 0$     | $\lim\limits_{δ⇝0} \sup\limits_{x∈\mathrm{U}(0,δ)} \left| x^{α} · \sin \dfrac{1}{x} \right| ≥ \lim\limits_{m⇝∞}^{x=[m·π+\frac{π}{2}]^{-1}} |x^{α}| \mathop{⇝}\limits_{n<0} ∞^{+}$ | $\lim\limits_{δ⇝0} \sup\limits_{x∈\mathrm{U}(0,δ)} \left| x^{α} · \cos \dfrac{1}{x} \right| ≥ \lim\limits_{m⇝∞}^{x=[m·π]^{-1}} |x^{α}| \mathop{⇝}\limits_{n<0} ∞^{+}$ | $x = 0$处振荡 |
| :---------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :------------ |
| $α = 0$     | $\lim\limits_{δ⇝0} \sup\limits_{x∈\mathrm{U}(0,δ)} \left|x^{α} · \sin \dfrac{1}{x} \right| ≥ \lim\limits_{m⇝0}^{x=[m·π+\frac{π}{2}]^{-1}} \left|\sin \dfrac{1}{x}\right| = 1$ | $\lim\limits_{δ⇝0} \sup\limits_{x∈\mathrm{U}(0,δ)} \left|x^{α} · \cos \dfrac{1}{x} \right| ≥ \lim\limits_{m⇝0}^{x=[m·π]^{-1}} \left|\cos \dfrac{1}{x}\right| = 1$ | $x = 0$处振荡 |
| $0 < α$     | $\lim\limits_{δ⇝0} \sup\limits_{x∈\mathrm{U}(0,δ)} \left| x^{α} · \sin \dfrac{1}{x} \right| ≤ \lim\limits_{x⇝0}^{δ⇝0} |x^{α}| \mathop{⇝}\limits_{0<α} 0$ | $\lim\limits_{δ⇝0} \sup\limits_{x∈\mathrm{U}(0,δ)} \left| x^{α} · \cos \dfrac{1}{x} \right| ≤ \lim\limits_{x⇝0}^{δ⇝0} |x^{α}| \mathop{⇝}\limits_{0<α} 0$ | $x=0$处收敛   |
|             |                                                              |                                                              |               |
| $1 < α ≤ 2$ | $\lim\limits_{δ⇝0} \sup\limits_{x∈\mathrm{U}(0,δ)} \left|α · x^{α-1} · \sin \dfrac{1}{x} - x^{α-2} · \cos \dfrac{1}{x} \right| ≥ \lim\limits_{m⇝∞}^{x=[m·π+\frac{π}{2}]^{-1}} |α·x^{α-1}| ⇝ \mathop{0}\limits_{1<α≤2}$ | $\lim\limits_{δ⇝0} \sup\limits_{x∈\mathrm{U}(0,δ)} \left|α · x^{α-1} · \sin \dfrac{1}{x} - x^{α-2} · \cos \dfrac{1}{x} \right| ≥ \lim\limits_{m⇝∞}^{x=[m·π]^{-1}} |x^{α-2}| ⇝ \mathop{∞^{+}}\limits_{1<α<2};\mathop{1}\limits_{α=2}$ | $x=0$处振荡   |

函数$f(x) ≡ \dfrac{\mathrm{d} \mathcal{W}_{\frac{3}{2}}(x)}{\mathrm{d} x} = \mathop{0}\limits_{x=0};\mathop{\left[ \dfrac{3}{2} · x^{\frac{1}{2}} · \sin \dfrac{1}{x} - \dfrac{1}{x^{\frac{1}{2}}} · \cos \dfrac{1}{x} \right]}\limits_{x≠0}$在点$x=0$处附近振荡且无界，但有原函数$F(x) ≡ \mathcal{W}_{\frac{3}{2}}(x) = \mathop{0}\limits_{x=0};\mathop{x^{\frac{3}{2}} · \sin \dfrac{1}{x}}$。

### 倒幂函数

$\mathcal{E}(x) ≡ \mathop{0}\limits_{x=0};\mathop{ә^{-\frac{1}{x}}}\limits_{x≠0}$

$\lim\limits_{x⇝0^{-}} ә^{-\frac{1}{x}} ⇝ ∞^{+}$

$\lim\limits_{x⇝0^{+}} ә^{-\frac{1}{x}} ⇝ 0^{+}$

