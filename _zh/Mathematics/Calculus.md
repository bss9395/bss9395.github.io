---
layout:  zh_post
Topic :  收敛极限
Title :  微积分
Update:  2021-01-31T18:46:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 极值点

极大值与极小值是局部性质，最大值与最小值是全局性质，上确界与下确界是极限性质。

|     最大值 | $m ≡ \max\limits_{m∈S} S$   | $[ ∃m∈S;∀a∈S; m ≥ a ] ⇔ [ ∃m∈S;∀a∈S; m ≤ a ⇒ m = a ]$        |
| ---------: | :-------------------------- | ------------------------------------------------------------ |
|     最小值 | $m ≡ \min\limits_{m∈S} S$   | $[ ∃m∈S;∀a∈S; m ≤ a ] ⇔ [ ∃m∈S;∀a∈S; m ≥ a ⇒ m = a ]$        |
|     极大值 | $m ≡ \max\limits_{m∈S⊆T} S$ | $[ ∃m∈S;∀a∈S; m ≥ a ] ⇔ [ ∃m∈S;∀a∈S; m ≤ a ⇒ m = a ]$        |
|     极小值 | $m ≡ \min\limits_{m∈S⊆T} S$ | $[ ∃m∈S;∀a∈S; m ≤ a ] ⇔ [ ∃m∈S;∀a∈S; m ≥ a ⇒ m = a ]$        |
|     上确界 | $s ≡ \sup S$                | $[ ∃s∈\fbox{S};∀a∈S; a ≤ s ] ⇔ [∃s;∀o;∀a∈S; a ≤ s ∧ [a ≤ o ⇒ s ≤ o]]$ |
|     上确界 | $s ≡ \sup S$                | $[ ∃s;∀a∈S;∃e∈S; a ≤ s ∧ [ a < s ⇒ a < e ] ] ⇔ [ ∃s;∀a∈S;∀ε>0;∃e∈S; a ≤ s ∧ s - ε < e]$ |
|     下确界 | $s ≡ \inf S$                | $[ ∃s∈\fbox{S};∀a∈S; a ≥ s ] ⇔[∃s;∀o;∀a∈S; a ≥ s ∧ [a ≥ o ⇒ s ≥ o]]$ |
|     下确界 | $s ≡ \inf S$                | $[ ∃s;∀a∈S;∃e∈S; a ≥ s ∧ [ a > s ⇒ a > e ] ] ⇔ [ ∃s;∀a∈S;∀ε>0;∃e∈S; a ≥ s ∧ s + ε > e]$ |
| 严格最大值 | $m ≡ \max\limits_{m∈S} S$   | $[ ∃m∈S;∀a∈S \backslash m; m > a ]$                          |
| 严格最小值 | $m ≡ \min\limits_{m∈S} S$   | $[ ∃m∈S;∀a∈S \backslash m; m < a ]$                          |
| 严格极大值 | $m ≡ \max\limits_{m∈S⊆T} S$ | $[ ∃m∈S;∀a∈S \backslash m; m > a ]$                          |
| 严格极小值 | $m ≡ \min\limits_{m∈S⊆T} S$ | $[ ∃m∈S;∀a∈S \backslash m; m < a ]$                          |


|     最大值 | $f (x_0) ≡ \max\limits_{x∈X} f (x)$   | $[ ∃x_0∈X;∀x∈X; f (x_0) ≥ f (x) ] ⇔ [ ∃x_0∈X;∀x∈X; f (x_0) ≤ f (x) ⇒ f (x_0) = f (x) ]$ |
| ---------: | :------------------------------------ | :----------------------------------------------------------- |
|     最小值 | $f (x_0) ≡ \min\limits_{x∈X} f (x)$   | $[ ∃x_0∈X;∀x∈X; f (x_0) ≤ f (x) ] ⇔ [ ∃x_0∈X;∀x∈X; f (x_0) ≥ f (x) ⇒ f (x_0) = f (x) ]$ |
|     极大值 | $f (x_0) ≡ \max\limits_{x∈X⊆Y} f (x)$ | $[ ∃x_0∈X;∀x∈X⊆Y; f (x_0) ≥ f (x) ] ⇔ [ ∃x_0∈X;∀x∈X⊆Y; f (x_0) ≤ f (x) ⇒ f (x_0) = f (x) ]$ |
|     极小值 | $f (x_0) ≡ \min\limits_{x∈X⊆Y} f (x)$ | $[ ∃x_0∈X;∀x∈X⊆Y; f (x_0) ≤ f (x) ] ⇔ [ ∃x_0∈X;∀x∈X⊆Y; f (x_0) ≥ f (x) ⇒ f (x_0) = f (x) ]$ |
|     上确界 | $s ≡ \sup\limits_{x∈X} f (x)$         | $[ ∃s∈\fbox{f(x)}; ∀x∈X; f (x) ≤ s ] ⇔ [ ∃s;∀a;∀x∈X; f (x) ≤ s ∧ [ f (x) ≤ a ⇒ s ≤ a ] ]$ |
|     上确界 | $s ≡ \sup\limits_{x∈X} f (x)$         | $[ ∃s;∀x∈X;∃y∈X; f (x) ≤ s ∧ [ f (x) < s ⇒ f (x) < f (y) ] ] ⇔ [ ∃s;∀x∈X;∀ε>0;∃y∈X; f (x) ≤ s ∧ s - ε < f (y) ]$ |
|     下确界 | $s ≡ \inf\limits_{x∈X} f (x)$         | $[ ∃s∈\fbox{f(x)};∀x∈X; f (x) ≥ s ] ⇔ [ ∃s;∀a;∀x∈X; f (x) ≥ s ∧ [ f (x) ≥ a ⇒ s ≥ a ] ]$ |
|     下确界 | $s ≡ \inf\limits_{x∈X} f (x)$         | $[ ∃s;∀x∈X;∃y∈X; f (x) ≥ s ∧ [ f (x) > s ⇒ f (x) > f (y) ] ] ⇔ [ ∃s;∀x∈X;∀ε>0;∃y∈X; f (x) ≥ s ∧ s + ε > f (y) ]$ |
| 严格最大值 | $f (x_0) ≡ \max\limits_{x∈X} f (x)$   | $[ ∃x_0∈X;∀x∈X \backslash x_0; f (x_0) > f (x) ]$            |
| 严格最小值 | $f (x_0) ≡ \min\limits_{x∈X} f (x)$   | $[ ∃x_0∈X;∀x∈X \backslash x_0; f (x_0) < f (x) ]$            |
| 严格极大值 | $f (x_0) ≡ \max\limits_{x∈X⊆Y} f (x)$ | $[ ∃x_0∈X;∀x∈X \backslash x_0; f (x_0) > f (x) ]$            |
| 严格极小值 | $f (x_0) ≡ \min\limits_{x∈X⊆Y} f (x)$ | $[ ∃x_0∈X;∀x∈X \backslash x_0; f (x_0) < f (x) ]$            |

函数$f (x)$在点$x_0$处可导，若点$x_0$为$f (x)$的极值点，则$f' (x_0) = 0$，反之不对。

函数$f (x)$在点$x_0$处可导，若$f' (x_0) = 0$，则点$x_0$为$f (x)$的停驻点，反之亦然。

反例：函数$f (x) = | x |$在点$x_0 = 0$处不可导。

### 连续介值定理

函数$f (x)$在区间$X$上连续，对于函数值域内任意的函数值$f (t)$，必定至少存在一点$θ∈X$使得$f (t) = f (θ)$。

$f(x)|_{∀t∈X} = \left.f (x)\right|_{∃θ∈X}$

| $⇓$  | $∀t∈X;∃θ∈X; f (t) = f (θ)$                                   | $⇔$  | $f(x)|_{∀t∈X} = \left.f (x)\right|_{∃θ∈X}$ |
| :--: | :----------------------------------------------------------- | :--: | ------------------------------------------ |
| $⇓$  | $∀f(t)∈\left( \inf\limits_{x∈X} f(x), \sup\limits_{x∈X} f(x) \right);∃θ∈X; f (t) = f (θ)$ |      |                                            |
| $⇓$  | $∀f(t)∈\left[\min\limits_{α,β∈X} \lbrace f (α), f (β) \rbrace, \max\limits_{α,β∈X} \lbrace f (α), f (β) \rbrace \right];∃θ∈[α, β]; f (t) = f (θ)$ |      |                                            |
| $⇓$  | $f (α) · f (β) ≤ 0 ⇒ 0 = \left. f (θ) \right|_{∃θ∈[α, β]}$   |      |                                            |

函数$f (x)$在闭区间$[α, β]$上连续，若函数的值域内含于定义域，则必定存在不动点$θ∈[α, β]$使得$f (θ) = θ$。

$∀x∈[α, β]; f(x)∈[α, β] ⇒ \left.f (x)\right|_{∃θ∈[α, β]} = θ$

| $⇓$  | $F (x) ≡ f (x) - x$                    |      |                                                |
| :--: | :------------------------------------- | :--: | :--------------------------------------------- |
| $⇓$  | $F (α) · F (β) ≤ 0$                    | $⇐$  | $F (α) = f (α) - α ≥ 0, F (β) = f (β) - β ≤ 0$ |
| $⇓$  | $0 = \left. F (x) \right|_{∃θ∈[α, β]}$ |      |                                                |
| $⇓$  | $\left.f (x)\right|_{∃θ∈[α, β]} = θ$                                     |      |                                                |

### 微分中值定理

函数$f (x)$在闭区间$[α, β]$上连续且可导，若两个端点的函数值相等，则必定至少存在一点$θ∈[α, β]$使得$\left. \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_θ = 0$。

$[ f (α) = f (β) ] ⇒ \left[ \left. \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{∃θ∈[α, β]}  = 0 \right]$

| $⇓$  | $0 ≤ \dfrac{f (θ^-) - f (θ)}{θ^- - θ} ≤ \dfrac{f (θ^+) - f (θ)}{θ^+ - θ} ≤ 0$ | $⇐$  | $f (θ) ≡ \max\limits_{x∈X} f (x)$ |
| :--: | :----------------------------------------------------------- | :--: | :-------------------------------- |
| $⇓$  | $0 ≥ \dfrac{f (θ^-) - f (θ)}{θ^- - θ} ≥ \dfrac{f (θ^+) - f (θ)}{θ^+ - θ} ≥ 0$ | $⇐$  | $f (θ) ≡ \min\limits_{x∈X} f (x)$ |
| $⇓$  | $\left.\dfrac{\mathrm{d} f (x)}{\mathrm{d} x}\right|_{∃θ∈[α, β]} = \lim\limits_{x⇝θ} \dfrac{f (x) - f (θ)}{x - θ} = 0$ | $⇐$  | $f (α) = f (β)$                   |

函数$f (x)$在闭区间$[α, β]$上连续且可导，则必定至少存在一点$θ∈[α, β]$使得$\left. \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_θ = \dfrac{f (β) - f (α)}{β - α}$。

$\left. \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{∃θ∈[α, β]} = \dfrac{f (β) - f (α)}{β - α}$

| $⇓$  | $$ F (x) = \left|\begin{matrix} 1 & 1 & 1 \\ α & x & β \\ f (α) & f (x) & f (β) \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ α & x - α & β - α \\ f (α) & f (x) - f (α) & f (β) - f (α) \end{matrix}\right| = (x - α) · [ f (β) - f (α) ] - (β - α) · [ f (x) - f (α) ] $$ | $⇒$  | $F (α) = 0 = F (β)$                                          |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $$\dfrac{\mathrm{d} F (x)}{\mathrm{d} x} = \dfrac{\mathrm{d}}{\mathrm{d} x} \left|\begin{matrix} 1 & 0 & 0 \\ α & x - α & β - α \\ f (α) & f (x) - f (α) & f (β) - f (α) \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ α & 1 & β - α \\ f (α) & \dfrac{\mathrm{d} f (x)}{\mathrm{d}x} & f (β) - f (α) \end{matrix}\right| = [ f (β) - f (α) ] - (β - α) · \dfrac{\mathrm{d} f (x)}{\mathrm{d} x}$$ |      |                                                              |
| $⇓$  | $\left. \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{∃θ∈[α, β]} = \dfrac{f (β) - f (α)}{β - α} - \dfrac{1}{β - α} · \left.\dfrac{\mathrm{d} F (x)}{\mathrm{d} x} \right|_{∃θ∈[α, β]} = \dfrac{f (β) - f (α)}{β - α}$ | $⇐$  | $\left.\dfrac{\mathrm{d} F (x)}{\mathrm{d} x} \right|_{∃θ∈[α, β]} = 0$ |

函数$f (x)$与函数$g (x)$在闭区间$[α, β]$上连续且可导，则必定至少存在一点$θ∈[α, β]$使得$\left. \dfrac{\mathrm{d} f (x)}{\mathrm{d} g(x)} \right|_θ = \dfrac{f (β) - f (α)}{g (β) - g (α)}$。

$\left.\dfrac{\mathrm{d} f (x)}{\mathrm{d} g (x)}\right|_{∃θ∈[α, β]} = \dfrac{f (β) - f (α)}{g (β) - g (α)}$

| $⇓$  | $$ F (x) = \left|\begin{matrix} 1 & 1 & 1 \\ g (α) & g (x) & g (β) \\ f (α) & f (x) & f (β) \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ g (α) & g (x) - g (α) & g (β) - g (α) \\ f (α) & f (x) - f (α) & f (β) - f (α) \end{matrix}\right| = (x - α) · [ f (β) - f (α) ] - (β - α) · [ f (x) - f (α) ] $$ | $⇒$  | $F (α) = 0 = F (β)$                                          |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $$\dfrac{\mathrm{d} F (x)}{\mathrm{d} x} = \dfrac{\mathrm{d}}{\mathrm{d} x} \left|\begin{matrix} 1 & 0 & 0 \\ g (α) & g (x) - g (α) & g (β) - g (α) \\ f (α) & f (x) - f (α) & f (β) - f (α) \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ g (α) & \dfrac{\mathrm{d} g (x)}{\mathrm{d} x} & g (β) - g (α) \\ f (α) & \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} & f (β) - f (α) \end{matrix}\right| = [ f (β) - f (α) ]  · \dfrac{\mathrm{d} g (x)}{\mathrm{d} x} - [ g (β) - g (α) ] · \dfrac{\mathrm{d} f (x)}{\mathrm{d} x}$$ |      |                                                              |
| $⇓$  | $$\left.\dfrac{\mathrm{d} f (x)}{\mathrm{d} g (x)}\right|_{∃θ∈[α, β]} = \dfrac{f (β) - f (α)}{g (β) - g (α)} - \dfrac{1}{g (β) - g (α)} · \left.\dfrac{\mathrm{d} F (x)}{\mathrm{d} g (x)}\right|_{∃θ∈[α, β]} = \dfrac{f (β) - f (α)}{g (β) - g (α)}$$ | $⇐$  | $\left.\dfrac{\mathrm{d} F (x)}{\mathrm{d} x} \right|_{∃θ∈[α, β]} = 0$ |

### 导数极限定理

函数$f (x)$在区间$(α, β)$上连续且可导，根据微分中值定理。

$\left. \dfrac{\mathrm{d} f_+ (x)}{\mathrm{d} x} \right|_α = \lim\limits_{x⇝α^+} \dfrac{f (x) - f (α)}{x - α} = \lim\limits_{θ⇝α^+} \left. \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{θ∈[α, x]} = \left. \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{α^+}$