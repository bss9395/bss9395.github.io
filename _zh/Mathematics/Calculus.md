---
layout:  zh_post
Topic :  收敛极限
Title :  微积分
Update:  2021-02-19T22:42:00+08@中国-广东-湛江+08
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
| $⇓$  | $\left.f (x)\right|_{∃θ∈[α, β]} = θ$   |      |                                                |

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

### 幂级数公式

若多项式函数$\mathrm{Poly}_n (x)$在点$x_0$处连续且有$n$阶导数，则在点$x_0$处可唯一展开成$n$阶幂级数。

$P_n (x) = \sum\limits_{i=0}^n p_i · (x - x_0)^i = p_0 · (x - x_0)^0 + p_1 · (x - x_0)^1 + p_2 · (x - x_0)^2 + ··· + p_n · (x - x_0)^n$

$P_n (x) = \sum\limits_{i=0}^n \dfrac{{^i}P_n (x_0)}{i!} · (x - x_0)^i = \sum\limits_{i=0}^n \left.\dfrac{\mathrm{d}^i P_n (x)}{i! · \mathrm{d}^i x}\right|_{x_0} · (x - x_0)^i = \sum\limits_{i=0}^n \left.\dfrac{\mathrm{d}^i P_n (x)}{\mathrm{d} x^i}\right|_{x_0} · (x - x_0)^i$

| ${^n}P_n (x_0) = n! · p_n$                                   | ${^0}P_n (x_0) = 0! · p_0$                                   | ${^1}P_n (x_0) = 1! · p_1$                                   | ${^2}P_n (x_0) = 2! · p_2$                                   |
| ------------------------------------------------------------ | :----------------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| $\left.\dfrac{\mathrm{d}^n P_n (x)}{\mathrm{d}^n x}\right|_{x_0} ≡ \left.\underbrace{\dfrac{\mathrm{d}}{\mathrm{d} x} ··· \dfrac{\mathrm{d}}{\mathrm{d} x} }_n P_n (x) \right|_{x_0} ≡ n! · p_n$ | $\left.\dfrac{\mathrm{d}^0 P_n (x)}{\mathrm{d}^0 x}\right|_{x_0} ≡ \left.P_n (x)\right|_{x_0} ≡ 0! · p_0$ | $\left.\dfrac{\mathrm{d}^1 P_n (x)}{\mathrm{d}^1 x}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}}{\mathrm{d} x} P_n (x)\right|_{x_0} ≡ 1! · p_1$ | $\left.\dfrac{\mathrm{d}^2 P_n (x)}{\mathrm{d}^2 x}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d}}{\mathrm{d} x} P_n (x)\right|_{x_0} ≡ 2! · p_2$ |
| $\left.\dfrac{\mathrm{d}^n P_n (x)}{\mathrm{d} x^n}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}^n P_n (x)}{n! · \mathrm{d}^n x}\right|_{x_0} ≡ p_n$ | $\left.\dfrac{\mathrm{d}^0 P_n (x)}{\mathrm{d} x^0}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}^0 P_n (x)}{0! · \mathrm{d}^0 x}\right|_{x_0} ≡ p_0$ | $\left.\dfrac{\mathrm{d}^1 P_n (x)}{\mathrm{d} x^1}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}^1 P_n (x)}{1! · \mathrm{d}^1 x}\right|_{x_0} ≡ p_1$ | $\left.\dfrac{\mathrm{d}^2 P_n (x)}{\mathrm{d} x^2}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}^2 P_n (x)}{2! · \mathrm{d}^2 x}\right|_{x_0} ≡ p_2$ |
| $\dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d}^n P_n (x)}{\mathrm{d} x^n} = \dfrac{(n + 1) · \mathrm{d}^{n+1} P_n (x)}{\mathrm{d} x^{n+1}}$ | $\dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d}^0 P_n (x)}{\mathrm{d} x^0} = \dfrac{1 · \mathrm{d}^1 P_n (x)}{\mathrm{d} x^1}$ | $\dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d}^1 P (x)}{\mathrm{d} x^1} = \dfrac{2 · \mathrm{d}^2 P_n (x)}{\mathrm{d} x^2}$ | $\dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d}^2 P_n (x)}{\mathrm{d} x^2} = \dfrac{3 · \mathrm{d}^3 P_n (x)}{\mathrm{d} x^3}$ |

若任意形式的函数$f (x)$在点$x_0$处连续且有$n$阶导数，则在点$x_0$处可唯一展开成$n$阶幂级数。

$f (x) = \sum\limits_{i=0}^n \dfrac{{^i}f (x_0)}{i!} · (x - x_0)^i + R_n (x) = f (x_0) + \dfrac{{^1}f (x_0)}{1!} · (x - x_0)^1 + \dfrac{{^2}f (x)}{2!} · (x - x_0)^2 + ··· + \dfrac{{^n}f (x)}{n!} · (x - x_0)^n + R_n (x)$

$f (x) = \sum\limits_{i=0}^n \left.\dfrac{\mathrm{d}^i f (x)}{i! · \mathrm{d}^i x}\right|_{x_0} · (x - x_0)^i + R_n (x) = f (x_0) + \left.\dfrac{\mathrm{d}^1 f (x)}{1! · \mathrm{d}^1 x}\right|_{x_0} · (x - x_0)^1 + \left.\dfrac{\mathrm{d}^2 f (x)}{2! · \mathrm{d}^2 x}\right|_{x_0} · (x - x_0)^2 + ··· + \left.\dfrac{\mathrm{d}^n f (x)}{n! · \mathrm{d}^n x}\right|_{x_0} · (x - x_0)^n + R_n (x)$

$f (x) = \sum\limits_{i=0}^n \left.\dfrac{\mathrm{d}^i f (x)}{\mathrm{d} x^i}\right|_{x_0} · (x - x_0)^i + R_n (x) = f (x_0) + \left.\dfrac{\mathrm{d}^1 f (x)}{\mathrm{d} x^1}\right|_{x_0} · (x - x_0)^1 + \left.\dfrac{\mathrm{d}^2 f (x)}{\mathrm{d} x^2}\right|_{x_0} · (x - x_0)^2 + ··· + \left.\dfrac{\mathrm{d}^n f (x)}{\mathrm{d} x^n}\right|_{x_0} · (x - x_0)^n + R_n (x)$

$R_n (x) = o (x - x_0)^n = f (x) - f (x_0) - \sum\limits_{i=1}^n \dfrac{{^i}f (x_0)}{i!} · (x - x_0)^i  \mathop{====}\limits_{∃θ∈[x_0, x]} \dfrac{{^{n+1}}f (θ)}{(n + 1)!} · (x - x_0)^{n + 1} \mathop{====}\limits_{∃θ∈[x_0, x]} \dfrac{{^{n+1}f (θ)}}{n!} · (x - θ)^n · (x - x_0)^1 \mathop{====}\limits_{∃θ∈[x_0, x]} \int\limits_{x_0}^x \dfrac{{^{n+1}}f (t)}{n!} · (x - t)^n \mathrm{d} t$

$[ R_n (x_0) = 0 ] ⇒ [ f (x) |_{x_0} = f (x_0) ]$

| $⇓$  | ${^m} R_n (x) = {^m} f (x) - {^m} f (x_0) - \sum\limits_{i=m+1}^n \dfrac{{^{i-m}}f (x_0)}{i!} · \dfrac{i!}{(i - m)!} · (x - x_0)^{i-m}$ | $⇒$  | $\lim\limits_{x ⇝ x_0} {^m} R_n (x) \mathop{⇝}\limits_{0 ≤ m ≤ n} 0$ |
| :--: | ------------------------------------------------------------ | :--: | :----------------------------------------------------------- |
| $⇓$  | $\lim\limits_{x⇝x_0} \dfrac{R_n (x)}{(x - x_0)^n} = \lim\limits_{x⇝x_0} \dfrac{1}{n} · \dfrac{{^1}R_n (x)}{(x - x_0)^{n - 1}} = \lim\limits_{x⇝x_0} \dfrac{(n - m)!}{n!} · \dfrac{{^m} R_n (x)}{(x - x_0)^{n - m}} = ··· = \lim\limits_{x⇝x_0} \dfrac{0!}{n!} · \dfrac{{^n}R_n (x)}{(x - x_0)^0} ⇝ 0$ |      |                                                              |
| $⇓$  | $R_n (x) = o (x - x_0)^{n}$                                  |      |                                                              |

| $⇓$  | $F (t) ≡ \sum\limits_{i=0}^n \dfrac{{^i} f (t)}{i!} · (x - t)^i$ | $⇒$  | $R_n (x) = F (x) - F (x_0)$                                  |                                                     |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- | :-------------------------------------------------- |
| $⇓$  | ${^1} F (t) = \sum\limits_{i=0}^n \left[ \dfrac{{^{i+1}} f (t)}{i!} · (x - t)^i - \dfrac{{^i} f (t)}{i!} · i · (x - t)^{i-1} \right]$ |      |                                                              |                                                     |
| $⇓$  | ${^1}F (t) = \sum\limits_{i=0}^n \dfrac{{^{i+1}} f (t)}{i!} · (x - t)^i - \sum\limits_{i=0}^{n-1} \dfrac{{^{i+1}} f (t)}{i!} · (x - t)^i = \dfrac{{^{n+1}} f (t)}{n!} · (x - t)^n$ |      |                                                              |                                                     |
| $⇓$  | $\dfrac{R_n (x)}{G (x) - G (x_0)} = \dfrac{F (x) - F (x_0)}{G (x) - G (x_0)} = \left.\dfrac{{^1} F (t)}{{^1} G (t)}\right|_{∃θ∈[x_0, x]} = \dfrac{{^{n+1}} f (θ)}{n!} · \dfrac{(x - θ)^n}{{^1} G (θ)} $ |      |                                                              |                                                     |
| $⇓$  | $R_n (x) \mathop{====}\limits_{∃θ∈[x_0, x]} \dfrac{{^{n+1}} f (θ)}{n!} · \dfrac{(x - θ)^n}{{^1} G (θ)} · [G (x) - G (x_0)]$ |      |                                                              |                                                     |
| $⇓$  | $R_n (x) \mathop{====}\limits_{∃θ∈[x_0, x]} \dfrac{{^{n+1}f (θ)}}{(n + 1)!} · (x - x_0)^{n + 1}$ | $⇐$  | $G (t) ≡ (x - t)^{n + 1}$                                    | ${^1}G (t) = -(n + 1) · (x - t)^n$                  |
| $⇓$  | $R_n (x) \mathop{====}\limits_{∃θ∈[x_0, x]} \dfrac{{^{n+1}f (θ)}}{n!} · (x - θ)^n · (x - x_0)^1$ | $⇐$  | $G (t) ≡ (x - t)^1$                                          | ${^1}G (t) = -1$                                    |
| $⇓$  | $R_n (x) \mathop{====}\limits_{∃θ∈[x_0, x]} \int\limits_{x_0}^x \dfrac{{^{n+1}}f (t)}{n!} · (x - t)^n \mathrm{d} t$ | $⇐$  | $G (t) ≡ \int\limits_{x_0}^t \dfrac{{^{n+1}}f (t)}{n!} · (x - t)^n \mathrm{d} t$ | ${^1}G (t) = \dfrac{{^{n+1}}f (t)}{n!} · (x - t)^n$ |
| $⇓$  | $R_n (x) = O (x - x_0)^{n + 1}$                              | $⇐$  | $\varlimsup\limits_{x⇝x_0} \dfrac{R_n (x)}{(x - x_0)^{n + 1}} = \dfrac{{^{n+1}}f (θ)}{(n + 1)!} ≤ \mathrm{Sup.}$ |                                                     |

### 零测集

对于任意零测集$𝒪$，均存在至多可数个区间$X_i$覆盖之，使得其可测度长度为零。

$∀ε>0; \left[ 𝒪 ⊆ \bigcup\limits_{i=0}^{n⇝+∞} X_i \right] ∧ \left[ | 𝒪 | ≤ \sum\limits_{i=0}^{n⇝+∞} | X_i | < ε \right]$

至多可数集$\mathop{\lbrace s_i \rbrace}\limits_{n⇝+∞}$为零测集。此外有限集为至多可数集，零测集的子集为零测集。

$∀ε_2>0; \left[ \mathop{\lbrace s_i \rbrace}\limits_{n⇝+∞} ⊆ \bigcup\limits_{i=0}^{n⇝+∞} \left( s_i - \dfrac{ε_1}{2^{i+1}}, s_i + \dfrac{ε_1}{2^{i+1}} \right) \right] ⇒ \left[ \left| \mathop{\lbrace s_i \rbrace}\limits_{n⇝+∞} \right| = \sum\limits_{i=0}^{n⇝+∞} | s_i | ≤ \sum\limits_{i=0}^{n} \dfrac{ε_1}{2^{i}} ≤ \sum\limits_{i=0}^{+∞} \dfrac{ε_1}{2^i} =  2 · ε_1 = ε_2 \right]$

至多可数个零测集$𝒪_i$的合集$\mathop{\lbrace 𝒪_i \rbrace}\limits_{n⇝+∞}$为零测集。

$∀ε_3>0; \left[ \mathop{\lbrace 𝒪_i \rbrace}\limits_{n⇝+∞} ⊆ \bigcup\limits_{i=0}^{n⇝+∞} \bigcup\limits_{j=0}^{m⇝+∞} X_{i,j} \right] ⇒ \left[ \left| \mathop{\lbrace 𝒪_i \rbrace}\limits_{n⇝+∞} \right| = \sum\limits_{i=0}^{n⇝+∞} | 𝒪_i | = \sum\limits_{i=0}^{n⇝+∞} \sum\limits_{j=0}^{m⇝+∞} | X_{i,j} | ≤ \sum\limits_{i=0}^{n⇝+∞} \dfrac{1}{2^{i}} · \sum\limits_{j=0}^{m⇝+∞} \dfrac{ε_1}{2^{j}} ≤ \sum\limits_{i=0}^{+∞} \dfrac{ε_2}{2^i} = 2 · ε_2 = ε_3 \right]$

### 定积分

在定义域区间$[X_0, X_1]$划分成$n + 1$个子区间$[x_i, x_{i+1}]$的基础上，多添加$m$个点再形成$m$个子区间，其下积分和不减，其上积分和不增。

$\sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_i ≤ \sum\limits_{j=0}^{n+m} \inf\limits_{x∈[x_j, x_{j+1}]} f (x) · Δx_j ≤ \sum\limits_{j=0}^{n+m} f (θ_j) · Δx_j ≤ \sum\limits_{j=0}^{n+m} \sup\limits_{x∈[x_j, x_{j+1}]} f (x) · Δx_j ≤ \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_i$

| $⇓$  | $[x_{j}, x_{j+1}] ⊆ [x_{i}, x_{i+1}]$                      |  ⇒   | $\inf\limits_{x∈[x_i, x_{i+1}]} f (x) ≤ \inf\limits_{x∈[x_j, x_{j+1}]} f (x) ≤ \sup\limits_{x∈[x_j, x_{j+1}]} f (x) ≤ \sup\limits_{x∈[x_i, x_{i+1}]} f (x)$ |
| :--: | :--------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $[x_{j}, x_{j+1}] ∪ [x_{j+1}, x_{j+2}] = [x_{i}, x_{i+1}]$ |  ⇒   | $\inf\limits_{x∈[x_i, x_{i+1}]} f (x) · [(x_{j+1} - x_{j}) + (x_{j+2} - x_{j+1})] ≤ \inf\limits_{x∈[x_j, x_{j+1}]} f (x) · (x_{j+1} - x_{j}) + \inf\limits_{x∈[x_{j+1}, x_{j+2}]} f (x) · (x_{j+2} - x_{j+1})$ |
| $⇓$  | $[x_{j}, x_{j+1}] ∪ [x_{j+1}, x_{j+2}] = [x_{i}, x_{i+1}]$ |  ⇒   | $\sup\limits_{x∈[x_j, x_{j+1}]} f (x) · (x_{j+1} - x_{j}) + \sup\limits_{x∈[x_{j+1}, x_{j+2}]} f (x) · (x_{j+2} - x_{j+1}) ≤ \sup\limits_{x∈[x_i, x_{i+1}]} f (x) · [(x_{j+1} - x_{j}) + (x_{j+2} - x_{j+1})]$ |

若函数$f (x)$在区间$[X_0, X_1]$上的定积分存在，则其下积分和的极限等同于上积分和的极限，反之亦然。可任取点$θ_i$处的函数值$f (θ_i)$视为该子区间的平均值。

$\int\limits_{X_0}^{X_1} f (x) \mathrm{d} x \mathop{≡≡≡≡}\limits_{X_0=x_0}^{X_1=x_{n+1}} \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i, x_i+1]} f (x) · Δx_i = \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} f (θ_i) · Δx_i = \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_i$

$\int\limits_{X_0}^{X_1} f (x) \mathrm{d} x \mathop{≡≡≡≡}\limits_{X_0=x_0}^{X_1=x_{n+1}} \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^n f (x_i) · Δx_i = \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} f (θ_i) · Δx_i = \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^n f (x_{i+1}) · Δx_i$

$\int\limits_{X_0}^{X_1} f (x) \mathrm{d} x ≡≡≡≡ \lim\limits_{n⇝+∞} \sum\limits_{i=0}^n f \left[ i · \dfrac{X_1 - X_0}{n + 1} \right] · \dfrac{X_1 - X_0}{n + 1} = \lim\limits_{n⇝+∞} \sum\limits_{i=0}^{n} f \left[ θ_i · \dfrac{X_1 - X_0}{n + 1} \right] · \dfrac{X_1 - X_0}{n + 1} = \lim\limits_{n⇝+∞} \sum\limits_{i=0}^{n} f \left[ (i + 1) · \dfrac{X_1 - X_0}{n + 1} \right] · \dfrac{X_1 - X_0}{n + 1}$

若函数$f (x)$在区间$[X_0, X_1]$上的定积分存在，则其振幅和的极限为零，反之亦然。

$0 ⇜ \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^n w_i · Δx_i ≡ \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^n \sup\limits_{u,v∈[x_i, x_{i+1}]} | f (u) - f (v) | · Δx_i$

$0 ⇜ \lim\limits_{n⇝+∞} \sum\limits_{i=0}^{n} w_i · \dfrac{X_1 - X_0}{n + 1} ≡ \lim\limits_{n⇝+∞} \sum\limits_{i=0}^n \sup\limits_{u,v∈[x_i, x_{i+1}]} | f (u) - f (v) | · \dfrac{X_1 - X_0}{n + 1}$

| $⇕$  | $\lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_i = \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_i$ |
| :--: | ------------------------------------------------------------ |
| $⇕$  | $0 ≤ \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^n \sup\limits_{u,v∈[x_i, x_{i+1}]} | f (u) - f (v) | · Δx_i = \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \left[ \sup\limits_{x∈[x_i, x_{i+1}]} f (x) - \inf\limits_{x∈[x_i, x_{i+1}]} f (x) \right] · Δx_i = \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_i - \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_i ⇝ 0$ |

若函数$f (x)$在区间$[X_0, X_1]$上的定积分存在，则函数$f (x)$在区间$[X_0, X_1]$上有确界，反之不对。

$\left[ \lim\limits_{n⇝+∞} \sum\limits_{i=0}^{n} w_i · \dfrac{X_1 - X_0}{n + 1} ⇝ 0 \right] ⇒ \left[ f (x) ≤ \mathrm{Sup.} \right]$

| $⇓$  | $0 ⇜ \lim\limits_{n⇝+∞} \sum\limits_{i=0}^{n} w_i · \dfrac{X_1 - X_0}{n + 1} = (X_1 - X_0) · \lim\limits_{n⇝+∞} \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} w_i = (X_1 - X_0) · w_n$ |      |                                                       |
| :--: | :----------------------------------------------------------- | :--: | :---------------------------------------------------- |
| $⇓$  | $0 ⇜ w_n = \sup\limits_{u,v∈[x_n, x_{n+1}]} | f (u) - f (v) | ≥ || f (u) | - | f (v) ||$ |      |                                                       |
| $⇓$  | $| f (x) | ≤ \mathrm{Sup.}$                                  | $⇐$  | $[ | f (u) | ⇝ +∞ ] ⇒ [ | f (u) | - | f (v) | ⇝ +∞ ]$ |

反例：函数$𝓓 (x) = \mathop{1}\limits_{x∈ℚ}; \mathop{0}\limits_{x∉ℚ}$在区间$[0, 1]$上有确界，但其定积分不存在。

$\lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i, x_i+1]} 𝓓 (x) · Δx_i = \lim\limits_{n⇝+∞} \sum\limits_{i=0}^{n} 0 · Δx_i = 0 ≠ 1 = \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n}  1 · Δx_i = \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_i$

若函数$f (x)$在区间$[X_0, X_1]$上的定积分存在，则函数$f (x)$在区间$[X_0, X_1]$上的断点集为零测集，反之亦然。

$\left[ \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i ⇝ 0 \right] ⇔ \left[ \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i≥ε} ⇝ 0 \right]$

| $⇓$  | $ε · 𝜁 > \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^n w_i · Δx_i = \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{w_i · Δx_i}\limits_{w_i<ε} + \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^n \mathop{w_i · Δx_i}\limits_{w_i≥ε} ≥ \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{w_i · Δx_i}\limits_{w_i≥ε} = ε · \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i≥ε}$ |      |                                       |
| :--: | :----------------------------------------------------------- | :--: | :------------------------------------ |
| $⇓$  | $\lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i≥ε} < 𝜁 ⇝ 0$ |      |                                       |
| $⇓$  | $\lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i = \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{w_i · Δx_i}\limits_{w_i<ε} + \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{w_i · Δx_i}\limits_{w_i≥ε} ≤ ε · \lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i<ε} + \mathrm{Sup.} · \lim\limits_{n⇝+∞} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i≥ε} ≤ ε · (X_1 - X_0) + \mathrm{Sup.} · 𝜁$ | $⇐$  | $\mathrm{Sup.} ≡ \sup\limits_{i} w_i$ |
| $⇓$  | $\lim\limits_{n⇝+∞}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i ⇝ 0$ |      |                                       |

