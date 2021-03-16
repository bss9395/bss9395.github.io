---
layout:  zh_post
Topic :  收敛极限
Title :  微积分
Update:  2021-03-17T01:30:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 极值点

任意实数的绝对值，为其与实数轴上原点之间的距离。

| $|x - x_0| ≤ +y$  | $x - x_0 ∈ [-y, 0⁻] ∪ [0⁺, +y]$ | $[-y ≤ x - x_0 ≤ 0⁻] ∨ [ 0⁺ ≤ x - x_0 ≤ +y]$ | $[-y ≤ x - x_0] ∧ [x - x_0 ≤ +y]$ |
| :---------------- | :------------------------------ | :------------------------------------------- | :-------------------------------- |
| $|x - x_0 | ≥ +y$ | $x - x_0 ∈ [∞⁻, -y] ∪ [+y, ∞⁺]$ | $[∞⁻ ≤ x - x_0 ≤ -y] ∨ [+y ≤ x - x_0 ≤ ∞⁺]$  | $[x - x_0 ≤ -y] ∨ [x - x_0 ≥ +y]$ |

无穷大可视为扩充的实数轴上向其两端无穷远处延伸出的一点，扩充的实数轴在其两端的无穷大点处重合因此形成封闭的圆环。

无穷大的绝对值为正无穷大，负无穷大与正无穷大互为相反数。但在通常意义中，不考虑扩充的实数轴以及其两端的无穷大点。

|   无穷大 | $∞$  |            | $\dfrac{1}{0} = ∞$   | $\dfrac{1}{∞} = 0$   | $\lim\limits_{n⇝∞⁺} (-1)^n · n ⇝ ∞$ | $x_0 + ∞ \mathop{=}\limits_{x_0≠∞} ∞$    | $x_0 - ∞ \mathop{=}\limits_{x_0≠∞} ∞$    | $(+|x_0|) · ∞ \mathop{=}\limits_{x_0≠0} ∞$   | $(-|x_0|) · ∞ \mathop{=}\limits_{x_0≠0} ∞$   |
| -------: | :--- | :--------- | :------------------- | :------------------- | :---------------------------------- | :--------------------------------------- | :--------------------------------------- | :------------------------------------------- | :------------------------------------------- |
| 正无穷大 | $∞⁺$ | $|∞| = ∞⁺$ | $\dfrac{1}{0⁺} = ∞⁺$ | $\dfrac{1}{∞⁺} = 0⁺$ | $\lim\limits_{n⇝∞⁺} (+1) · n ⇝ ∞⁺$  | $x_0 + ∞⁺ \mathop{=}\limits_{x_0≠∞⁻} ∞⁺$ | $x_0 - ∞⁺ \mathop{=}\limits_{x_0≠∞⁻} ∞⁻$ | $(+|x_0|) · ∞⁺ \mathop{=}\limits_{x_0≠0} ∞⁺$ | $(-|x_0|) · ∞⁺ \mathop{=}\limits_{x_0≠0} ∞⁻$ |
| 负无穷大 | $∞⁻$ | $∞⁻ = -∞⁺$ | $\dfrac{1}{0⁻} = ∞⁻$ | $\dfrac{1}{∞⁻} = 0⁻$ | $\lim\limits_{n⇝∞⁺} (-1) · n ⇝ ∞⁻$  | $x_0 + ∞⁻ \mathop{=}\limits_{x_0≠∞⁺} ∞⁻$ | $x_0 - ∞⁻ \mathop{=}\limits_{x_0≠∞⁺} ∞⁺$ | $(+|x_0|) · ∞⁻ \mathop{=}\limits_{x_0≠0} ∞⁻$ | $(-|x_0|) · ∞⁻ \mathop{=}\limits_{x_0≠0} ∞⁺$ |

极大值与极小值是局部性质，最大值与最小值是全局性质，上确界与下确界是极限性质。最大值与最小值是离散性质，上确界与下确界是连续性质。

上确界与下确界始终存在且唯一确定，上极限与下极限始终存在且唯一确定。

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


|       最大值 | $f (x_0) ≡ \max\limits_{x∈X} f (x)$                          | $[ ∃x_0∈X;∀x∈X; f (x_0) ≥ f (x) ] ⇔ [ ∃x_0∈X;∀x∈X; f (x_0) ≤ f (x) ⇒ f (x_0) = f (x) ]$ |
| -----------: | :----------------------------------------------------------- | :----------------------------------------------------------- |
|       最小值 | $f (x_0) ≡ \min\limits_{x∈X} f (x)$                          | $[ ∃x_0∈X;∀x∈X; f (x_0) ≤ f (x) ] ⇔ [ ∃x_0∈X;∀x∈X; f (x_0) ≥ f (x) ⇒ f (x_0) = f (x) ]$ |
|       极大值 | $f (x_0) ≡ \max\limits_{x∈X⊆Y} f (x)$                        | $[ ∃x_0∈X;∀x∈X⊆Y; f (x_0) ≥ f (x) ] ⇔ [ ∃x_0∈X;∀x∈X⊆Y; f (x_0) ≤ f (x) ⇒ f (x_0) = f (x) ]$ |
|       极小值 | $f (x_0) ≡ \min\limits_{x∈X⊆Y} f (x)$                        | $[ ∃x_0∈X;∀x∈X⊆Y; f (x_0) ≤ f (x) ] ⇔ [ ∃x_0∈X;∀x∈X⊆Y; f (x_0) ≥ f (x) ⇒ f (x_0) = f (x) ]$ |
|       上确界 | $s ≡ \sup\limits_{x∈X} f (x)$                                | $[ ∃s∈\fbox{f(x)}; ∀x∈X; f (x) ≤ s ] ⇔ [ ∃s;∀a;∀x∈X; f (x) ≤ s ∧ [ f (x) ≤ a ⇒ s ≤ a ] ]$ |
|       上确界 | $s ≡ \sup\limits_{x∈X} f (x)$                                | $[ ∃s;∀x∈X;∃y∈X; f (x) ≤ s ∧ [ f (x) < s ⇒ f (x) < f (y) ] ] ⇔ [ ∃s;∀x∈X;∀ε>0;∃y∈X; f (x) ≤ s ∧ s - ε < f (y) ]$ |
|       下确界 | $s ≡ \inf\limits_{x∈X} f (x)$                                | $[ ∃s∈\fbox{f(x)};∀x∈X; f (x) ≥ s ] ⇔ [ ∃s;∀a;∀x∈X; f (x) ≥ s ∧ [ f (x) ≥ a ⇒ s ≥ a ] ]$ |
|       下确界 | $s ≡ \inf\limits_{x∈X} f (x)$                                | $[ ∃s;∀x∈X;∃y∈X; f (x) ≥ s ∧ [ f (x) > s ⇒ f (x) > f (y) ] ] ⇔ [ ∃s;∀x∈X;∀ε>0;∃y∈X; f (x) ≥ s ∧ s + ε > f (y) ]$ |
|   严格最大值 | $f (x_0) ≡ \max\limits_{x∈X} f (x)$                          | $[ ∃x_0∈X;∀x∈X \backslash x_0; f (x_0) > f (x) ]$            |
|   严格最小值 | $f (x_0) ≡ \min\limits_{x∈X} f (x)$                          | $[ ∃x_0∈X;∀x∈X \backslash x_0; f (x_0) < f (x) ]$            |
|   严格极大值 | $f (x_0) ≡ \max\limits_{x∈X⊆Y} f (x)$                        | $[ ∃x_0∈X;∀x∈X \backslash x_0; f (x_0) > f (x) ]$            |
|   严格极小值 | $f (x_0) ≡ \min\limits_{x∈X⊆Y} f (x)$                        | $[ ∃x_0∈X;∀x∈X \backslash x_0; f (x_0) < f (x) ]$            |
|              |                                                              |                                                              |
|       上极限 | $s ≡ \varlimsup\limits_{x⇝x_0} f (x) ≡ \lim\limits_{x⇝x_0} \sup\limits_{t∈(x_0^{±},x^{±})} f (t)$ |                                                              |
|       下极限 | $s ≡ \varliminf\limits_{x⇝x_0} f (x) ≡ \lim\limits_{x⇝x_0} \inf\limits_{t∈(x_0^{±},x^{±})} f (t)$ |                                                              |
|              |                                                              |                                                              |
|     单调递增 | $f^{↗} (x)$                                                  | $[∀x_1,x_2∈X; [ x_1 < x_2 ] ⇒ [ f^{↗} (x_1) ≤ f^{↗} (x_2)]]$ |
|     单调递减 | $f^{↘} (x)$                                                  | $[∀x_1,x_2∈X; [ x_1 < x_2 ] ⇒ [ f^{↘} (x_1) ≥ f^{↘} (x_2)]]$ |
| 严格单调递增 | $f^{↑} (x)$                                                  | $[∀x_1,x_2∈X; [ x_1 < x_2 ] ⇒ [ f^{↑} (x_1) < f^{↑} (x_2)]]$ |
| 严格单调递减 | $f^{↓} (x)$                                                  | $[∀x_1,x_2∈X; [ x_1 < x_2 ] ⇒ [ f^{↓} (x_1) > f^{↓} (x_2)]]$ |

典例：函数$f (x) = \sin x$在区间$\left( 0, \dfrac{π}{2} \right)$上的取值范围为$0 < f (x) < 1$，其下确界为$0$，其上确界为$1$。

典例：函数$f (x) = \dfrac{1}{x}$在区间$(0, ∞⁺)$上的取值范围为$0 < f (x)$，其下确界为$0$，其上确界为$∞⁺$。

| $∀x∈[X_0, X_1]; | f (x) | ≤ ε$ | $⇔$  | $\sup\limits_{x∈[X_0,X_1]} | f (x) | ≤ ε$ |                                                     | $∃x∈[X_0,X_1]; | f (x) | > ε$ | $⇔$  | $\sup\limits_{x∈[X_0,X_1]} | f (x) | > ε$ |
| -----------------------------: | :--: | :---------------------------------------- | :-------------------------------------------------: | ----------------------------: | :--: | :---------------------------------------- |
|  $∀x∈[X_0,X_1]; | f (x) | < ε$ | $⇔$  | $\sup\limits_{x∈[X_0,X_1]} | f (x) | < ε$ |                                                     | $∃x∈[X_0,X_1]; | f (x) | ≥ ε$ | $⇔$  | $\sup\limits_{x∈[X_0,X_1]} | f (x) | ≥ ε$ |
|  $∀x∈(X_0,X_1); | f (x) | ≤ ε$ | $⇔$  | $\sup\limits_{x∈(X_0,X_1)} | f (x) | ≤ ε$ |                                                     | $∃x∈(X_0,X_1); | f (x) | > ε$ | $⇔$  | $\sup\limits_{x∈(X_0,X_1)} | f (x) | > ε$ |
|  $∀x∈(X_0,X_1); | f (x) | < ε$ | $⇒$  | $\sup\limits_{x∈(X_0,X_1)} | f (x) | ≤ ε$ | $\rlap{≡≡≡≡≡≡≡≡≡}\sup\limits_{x⇝X_0} | f (x) | = ε$ | $∃x∈(X_0,X_1); | f (x) | ≥ ε$ | $⇒$  | $\sup\limits_{x∈(X_0,X_1)} | f (x) | ≥ ε$ |

函数$f (x)$在点$x_0$处可导，若点$x_0$为$f (x)$的极值点，则$f' (x_0) = 0$，反之不对。

函数$f (x)$在点$x_0$处可导，若$f' (x_0) = 0$，则点$x_0$为$f (x)$的停驻点，反之亦然。

反例：函数$f (x) = | x |$在点$x_0 = 0$处不可导。

若函数$f (x)$在区间$X$上严格单调，则反函数$f^{-1} (y)$在区间$Y$上的单调性相同。

$∀x_1,x_2∈X; [ f^{-1} (y_1) = x_1 < x_2 = f^{-1} (y_2) ] ⇔ [ f^{↑} (x_1) = y_1 < y_2 = f^{↑} (x_2) ]$

$∀x_1,x_2∈X; [ f^{-1} (y_1) = x_1 < x_2 = f^{-1} (y_2) ] ⇔ [ f^{↓} (x_1) = y_1 > y_2 = f^{↓} (x_2) ]$

| $⇓$  | $∀x_1,x_2∈X; [ x_1 < x_2 ] ⇒ [ f^{↑} (x_1) = y_1 < y_2 = f^{↑} (x_2) ]$ | $P ⇒ Q$                |
| :--: | :----------------------------------------------------------- | :--------------------- |
| $⇓$  | $∀x_1,x_2∈X; [ x_1 = x_2 ] ⇒ [ f^{↑} (x_1) = y_1 = y_2 = f^{↑} (x_2) ]$ | $R ⇒ S$                |
| $⇓$  | $∀x_1,x_2∈X; [ x_1 ≤ x_2 ] ⇒ [ f^{↑} (x_1) = y_1 ≤ y_2 = f^{↑} (x_2) ]$ | $[P ∨ R] ⇒ [ Q ∨ S]$   |
| $⇓$  | $∀y_1,y_2∈X; [ y_1 > y_2 ] ⇒ [ f^{-1} (y_1) = x_1 > x_2 = f^{-1} (y_2) ]$ | $¬[ Q ∨ S] ⇒ ¬[P ∨ R]$ |
| $⇓$  | $∀y_1,y_2∈X; [ y_1 < y_2 ] ⇒ [ f^{-1} (y_1) = x_1 < x_2 = f^{-1} (y_2) ]$ |                        |
| $⇓$  | $∀x_1,x_2∈X; [ f^{-1} (y_1) = x_1 < x_2 = f^{-1} (y_2) ] ⇔ [ f^{↑} (x_1) = y_1 < y_2 = f^{↑} (x_2) ]$ |                        |
|      |                                                              |                        |
| $⇓$  | $∀x_1,x_2∈X; [ f^{-1} (y_1) = x_1 < x_2 = f^{-1} (y_2) ] ⇔ [ f^{↓} (x_1) = y_1 > y_2 = f^{↓} (x_2) ]$ |                        |

若函数$f^{↕} (x)$在单区间$X$上严格单调，且其函数值域为单区间，则函数$f^{↕} (x)$在单区间$X$上单调连续。

| $⇓$  | $∀x_1,x_2∈X; [ f^{-1} (y_1) = x_1 < x_2 = f^{-1} (y_2) ] ⇔ [ f^{↑} (x_1) = y_1 < y_2 = f^{↑} (x_2) ]$ |      |                                               |
| :--: | :----------------------------------------------------------- | :--: | :-------------------------------------------- |
| $⇓$  | $∀y_1,y_0,y,y_2∈Y; [ y_1 < y_0, y < y_2 ] ⇔ [ x_1 < x_0, x < x_2 ]$ |      |                                               |
| $⇓$  | $∀ε=|y_2-y_1|>0;∃δ=|x_2-x_1|>0; [ | x - x_0 | < δ ] ⇒ [ | y - y_0 | < ε]$ |      |                                               |
| $⇓$  | $∀ε>0;∃δ>0; [ | x - x_0 | < δ ] ⇒ [ | f^{↑} (x) - f^{↑} (x_0) | < ε ]$ | $⇒$  | $\lim\limits_{x⇝x_0} f^{↑} (x) ⇝ f^{↑} (x_0)$ |
| $⇓$  |                                                              |      | $\lim\limits_{x⇝x_0} f^{↕} (x) ⇝ f^{↕} (x_0)$ |

### 数列极限

若数列$S_n$的极限值收敛于$S$，则对于任意的正实数$ε$，必有任意多项落在区间$[S - ε, S + ε]$内，且至多有限项落在区间$[S - ε, S + ε]$外。

| $\lim\limits_{n⇝∞⁺} S_n ⇝ S ≠ ∞$      | $\lim\limits_{n⇝∞⁺} S_n ⇝ S⁺ ≠ ∞⁺$     | $\lim\limits_{n⇝∞⁺} S_n ⇝ S⁻ ≠ ∞⁻$     |
| :------------------------------------ | :------------------------------------- | :------------------------------------- |
| $\lim\limits_{n⇝∞⁺} | S_n - S | ⇝ 0⁺$ | $\lim\limits_{n⇝∞⁺} S_n - S⁺ ⇝ 0⁺$     | $\lim\limits_{n⇝∞⁺} S_n - S⁻ ⇝ 0⁻$     |
| $∀ε>0;∃N∈ℕ;∀n≥N; | S_n - S | ≤ ε$     | $∀ε>0;∃N∈ℕ;∀n≥N; 0⁺ ≤ S_n - S ≤ ε$     | $∀ε>0;∃N∈ℕ;∀n≥N; ε ≤ S_n - S ≤ 0⁻$     |
| $∀ε>0;∃N∈ℕ;∀n≥N; S - ε ≤ S_n ≤ S + ε$ | $∀ε>0;∃N∈ℕ;∀n≥N; S + 0⁺ ≤ S_n ≤ S + ε$ | $∀ε>0;∃N∈ℕ;∀n≥N; S + ε ≤ S_n ≤ S + 0⁻$ |

若数列$S_n$的极限值发散于$∞$，则对于任意的正实数$ε$，必有任意多项落在区间$[-ε, +ε]$外，且至多有限项落在区间$[-ε, +ε]$内。

| $\lim\limits_{n⇝∞⁺} S_n ⇝ ∞$              | $\lim\limits_{n⇝∞⁺} S_n ⇝ ∞⁺$ | $\lim\limits_{n⇝∞⁺} S_n ⇝ ∞⁻$ |
| :---------------------------------------- | :---------------------------- | :---------------------------- |
| $\lim\limits_{n⇝∞⁺} | S_n | ⇝ ∞⁺$         |                               |                               |
| $∀ε>0;∃N∈ℕ;∀n≥N; | S_n | ≥ ε$             | $∀ε>0;∃N∈ℕ;∀n≥N; S_n ≥ +ε$    | $∀ε>0;∃N∈ℕ;∀n≥N; S_n ≤ -ε$    |
| $∀ε>0;∃N∈ℕ;∀n≥N; [S_n ≤ -ε] ∨ [S_n ≥ +ε]$ |                               |                               |

数列$S_n$的下极限与上极限。

$\varliminf\limits_{n⇝∞⁺} S_n ≡ \mathop{\lim\inf}\limits_{n⇝∞⁺} S_n ≡ \lim\limits_{n⇝∞⁺} \inf\limits_{m≥n} S_m$

$\varlimsup\limits_{n⇝∞⁺} S_n ≡ \mathop{\lim\sup}\limits_{n⇝∞⁺} S_n ≡ \lim\limits_{n⇝∞⁺} \sup\limits_{m≥n} S_m$

数列$S_n$中的有限多项发生改变，数列的敛散性不改变。

若数列$S_n$的极限值收敛于$S$，则其任何子数列$S_{n_m}$的极限值均收敛于S，反之亦然。

$\left[ \lim\limits_{n⇝∞⁺} S_n ⇝ S \right] ⇔ \left[ \lim\limits_{m⇝∞⁺} S_{n_m} ⇝ S \right]$

若数列$S_n$的极限值收敛于$S$，则其上极限与其下极限相等，反之亦然。因此若数列$S_n$的极限值存在，则此极限值唯一确定。

$\left[ \lim\limits_{n⇝∞⁺} S_n ⇝ S \right] ⇔ \left[ \varliminf\limits_{n⇝∞⁺} S_n ⇝ S ⇜ \varlimsup\limits_{n⇝∞⁺} S_n \right]$

典例：数列$S_n = (-1)^n$的极限值不存在。

$\lim\limits_{m⇝∞⁺} S_{2·m} = \lim\limits_{m⇝∞⁺} (-1)^{2·m} ⇝ (+1) ≠ (-1) ⇜ \lim\limits_{m⇝∞⁺} (-1)^{2·m+1} = \lim\limits_{m⇝∞⁺} S_{2·m+1}$

$\varliminf\limits_{n⇝∞⁺} S_n ⇝ (-1) ≠ (+1) ⇜ \varlimsup\limits_{n⇝∞⁺} S_n$

典例：数列$S_n = \sin n$的极限值不存在。

$\varliminf\limits_{n⇝∞⁺} S_n = \varliminf\limits_{n_m⇝∞⁺}^{n_m∈\left(2·m·π-\frac{3}{4}·π,2·m·π-\frac{1}{4}·π\right)} \sin n_m < 0 < \varlimsup\limits_{n_m⇝∞⁺}^{n_m∈\left(2·m·π+\frac{1}{4}·π,2·m·π+\frac{3}{4}·π\right)}  \sin n_m = \varlimsup\limits_{n⇝∞⁺} S_n$

若数列$S_n$的极限值收敛，则数列$S_n$有确界，反之不对。

$\left[ \lim\limits_{n⇝∞⁺} S_n ⇝ S ≠ ∞ \right] ⇒ \left[ ∀n∈ℕ; |S_n| ≤ \max\left\lbrace \left|\inf S_n\right|, \left| \sup S_n \right| \right\rbrace \right]$

### 数列极限的运算性质

$\left[ \lim\limits_{n⇝∞⁺} S_n ⇝ S < T ⇜ \lim\limits_{n⇝∞⁺} T_n \right] ⇒ \left[ ∃N∈ℕ;∀n≥N; S_n < \dfrac{S + T}{2} < T_n \right]$

$\left[ ∃N∈ℕ;∀n≥N; S_n ≤ R_n ≤ T_n \right] ⇒ \left[ \lim\limits_{n⇝∞⁺} S_n ≤ \lim\limits_{n⇝∞⁺} R_n ≤ \lim\limits_{n⇝∞⁺} T_n  \right]$

| $⇓$  | $\lim\limits_{n⇝∞⁺} S_n ⇝ S < T ⇜ \lim\limits_{n⇝∞⁺} T_n$    |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε=\dfrac{T - S}{2};∃N∈ℕ;∀n≥N; S_n < S + ε = S + \dfrac{T - S}{2} = \dfrac{S + T}{2} = T - \dfrac{T - S}{2} = T - ε < T_n$ |
| $⇓$  | $∃N∈ℕ;∀n≥N; S_n < \dfrac{S + T}{2} < T_n$                    |

若$\lim\limits_{n⇝∞⁺} S_n ⇝ S$，且 $\lim\limits_{n⇝∞⁺} T_n ⇝ T$。

$\lim\limits_{n⇝∞⁺} [ S_n + T_n ] = \lim\limits_{n⇝∞⁺} S_n + \lim\limits_{n⇝∞⁺} T_n ⇝ S + T$

$\lim\limits_{n⇝∞⁺} [ S_n - T_n ] = \lim\limits_{n⇝∞⁺} S_n - \lim\limits_{n⇝∞⁺} T_n ⇝ S - T$

$\lim\limits_{n⇝∞⁺} [ S_n · T_n ] = \lim\limits_{n⇝∞⁺} S_n · \lim\limits_{n⇝∞⁺} T_n ⇝ S · T$

$\lim\limits_{n⇝∞⁺} \dfrac{S_n}{T_n} = \dfrac{\lim\limits_{n⇝∞⁺} S_n}{\lim\limits_{n⇝∞⁺} T_n} \mathop{⇝}\limits_{T≠0} \dfrac{S}{T}$

$\lim\limits_{n⇝∞⁺} [ \mathrm{Con} · S_n ] = \mathrm{Con} · \lim\limits_{n⇝∞⁺} S_n ⇝ \mathrm{Con} · S$

| $⇓$  | $[ ∀ε_1>0;∃N∈ℕ;∀n≥N; | S_n - S | < ε_1 ] ∧ [∀ε_2>0;∃N∈ℕ;∀n≥N; | T_n - T | < ε_2]$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε>0;∃N∈ℕ;∀n≥N; | (S_n + T_n) - (S + T) | < | S_n - S | + | T_n - T | < ε_1 + ε_2 = ε$ |
| $⇓$  | $∀ε>0;∃N∈ℕ;∀n≥N; | (S_n - T_n) - (S - T) | < | S_n - S | + | T_n - T | < ε_1 + ε_2 = ε$ |
| $⇓$  | $∀ε>0;∃N∈ℕ;∀n≥N; | S_n · T_n - S · T | = | (S_n · T_n - S_n · T) + (S_n · T - S · T) | ≤ | S_n | · | T_n - T | + | S_n - S | · | T | ≤ \mathrm{Sup} · ε_2 + ε_1 · | T | = ε$ |
| $⇓$  | $∀ε>0;∃N∈ℕ;∀n≥N; \left| \dfrac{S_n}{T_n} - \dfrac{S}{T} \right| = \dfrac{| S_n · T - S · T_n |}{| T_n | · | T |} = \dfrac{| (S_n · T - S · T) + (S · T - S · T_n) |}{| T_n | · | T |} = \dfrac{| S_n - S | · | T | + | S | · | T - T_n |}{| T_n | · | T |} ≤ \dfrac{ε_1 · | T | + | S | · ε_2}{\mathrm{Inf} · | T |} = ε$ |

典例：数列$\lim\limits_{n⇝∞⁺} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i \right] = \lim\limits_{n⇝∞⁺} s_n \mathop{⇝}\limits^{s≠∞} s$

| $⇓$  | $\lim\limits_{n⇝∞⁺} s_n ⇝ s$  | $∀ε>0;∃N∈ℕ;∀n≥N; \left| \dfrac{s_0 + ··· + s_n}{n + 1} - s_n \right| ≤ \left| \dfrac{(s_0 - s_n) + ··· + (s_{N-1} - s_n)}{n + 1} \right| + \left| \dfrac{(s_N - s_n) + ··· + (s_n - s_n)}{n + 1} \right| ≤ \dfrac{\mathrm{Sum}}{n + 1} + \dfrac{n - N + 1}{n + 1} · ε_1 = ε$ |
| :--: | ----------------------------- | :----------------------------------------------------------- |
| $⇓$  | $\lim\limits_{n⇝∞⁺} s_n ⇝ ∞⁺$ | $∀ε>0;∃N∈ℕ;∀n≥N; \dfrac{s_0 + ··· + s_n}{n + 1} = \dfrac{s_0 + ··· + s_{N-1}}{n + 1} + \dfrac{s_N + ··· + s_n}{n + 1} ≥ \dfrac{\mathrm{Sum}}{n + 1} + \dfrac{n - N + 1}{n + 1} · \min\limits_{N≤m≤n} s_m = s_{m⇝∞⁺} = +ε$ |
| $⇓$  | $\lim\limits_{n⇝∞⁺} s_n ⇝ ∞⁻$ | $∀ε>0;∃N∈ℕ;∀n≥N; \dfrac{s_0 + ··· + s_n}{n + 1} = \dfrac{s_0 + ··· + s_{N-1}}{n + 1} + \dfrac{s_N + ··· + s_n}{n + 1} ≤ \dfrac{\mathrm{Sum}}{n + 1} + \dfrac{n - N + 1}{n + 1} · \max\limits_{N≤m≤n} s_m = s_{m⇝∞⁺} = -ε$ |
| $⇓$  |                               | $\lim\limits_{n⇝∞⁺} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i \right] = \lim\limits_{n⇝∞⁺} s_n \mathop{⇝}\limits^{s≠∞} s$ |

反例：数列$\lim\limits_{n⇝∞⁺} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n (-1)^i · i \right]$

$\lim\limits_{n⇝∞⁺} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n (-1)^i · i \right] ≈ \lim\limits_{2 · n⇝∞⁺} \dfrac{0 + (-1 + 2) + (-3 + 4) + ··· + [-(2 · n + 1) + 2 · n]}{2 · n + 1} = \lim\limits_{n⇝∞⁺} \dfrac{n}{2 · n + 1} ⇝ \dfrac{1}{2} ≠ ∞ ⇜ \lim\limits_{n⇝∞⁺} (-i)^i · i$

典例：数列$\lim\limits_{n⇝∞⁺} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i · t_{n - i} \right] = \lim\limits_{n⇝∞⁺} s_n · t_n = \lim\limits_{n⇝∞⁺} s_n · \lim\limits_{n⇝∞⁺} t_n \mathop{⇝}\limits_{t≠∞}^{s≠∞} s·t$

| $⇓$  | $\left[ \lim\limits_{n⇝∞⁺} s_n ⇝ 0 \right] ∧ \left[ \lim\limits_{n⇝∞⁺} t_n ⇝ t \right]$ | $⇒$  | $\lim\limits_{n⇝∞⁺} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i · t_{n-i} \right] ≤ \lim\limits_{n⇝∞⁺} \left[ \dfrac{\mathrm{Sup.}\lbrace t_i \rbrace}{n + 1} · \sum\limits_{i=0}^n s_i \right] = \mathrm{Sup.}\lbrace t_i \rbrace \lim\limits_{n⇝∞⁺} · s_n ⇝ 0$ |
| :--: | -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
| $⇓$  | $\left[ \lim\limits_{n⇝∞⁺} s_n ⇝ s \right] ⇔ \left[ \lim\limits_{n⇝∞⁺} (s_n - s) ⇝ 0 \right]$ | $⇒$  | $\lim\limits_{n⇝∞⁺} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i · t_{n-i} \right] = \lim\limits_{n⇝∞⁺} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n (s_i - s) · t_{n-i} + \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s · t_{n-i} \right] ⇝ s · t$ |
| $⇓$  |                                                              |      | $\lim\limits_{n⇝∞⁺} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i · t_{n-i} \right] = \lim\limits_{n⇝∞⁺} s_n · t_n = \lim\limits_{n⇝∞⁺} s_n · \lim\limits_{n⇝∞⁺} t_n \mathop{⇝}\limits_{t≠∞}^{s≠∞} s · t$ |





### 连续性

对于任意间断点$x_0$，其所在任意区间内的振幅均不为零。

$∃ε>0; ε ≤ \lim\limits_{Δx⇝0} w^f (x_0) = \lim\limits_{Δx⇝0} \sup\limits_{|u,v-x_0|≤Δx} | f (u) - f (v) | = \lim\limits_{Δx⇝0} \left[ \sup\limits_{|u-x_0|≤Δx} f (u) - \inf\limits_{|v-x_0|≤Δx} f (v) \right]$

$∃ε>0;∀Δx>0;∃u,v∈X; [ | u,v - x_0 | ≤ Δx ] ∧ [ |f (u) - f (v) | > ε ]$

连续性是局部性质。若函数$f (x)$在区间$X$上连续，则函数在区间$X$上任意点处有局部的确界。

$\lim\limits_{x⇝x_0} f (x) ⇝ f (x_0) ≠ ±∞$

$∀x_0∈X;∀ε>0;∃δ>0;∀x∈X; \left[ | x - x_0 | ≤ δ \right] ⇒ \left[ | f (x) - f (x_0) | ≤ ε \right]$

$\left[ ∀x_0∈X;∀ε>0;∃δ>0; \sup\limits_{|x-x_0|≤δ} | f (x) - f (x_0) | ≤ ε \right] ⇔ \left[ ∀x_0∈X;∀ε>0;∃δ>0;∀x∈\left\lbrace\mathop{x∈X}\limits_{|x-x_0|≤δ}\right\rbrace; | f (x) - f (x_0) | ≤ ε \right]$

$∀x_0∈X;∃\mathrm{Sup_{x_0}}; | f (x_0) | ≤ \mathrm{Sup_{x_0}}$

一致连续性是全局性质。若函数$f (x)$在区间X上一致连续，则函数在区间$X$上所有点处有全局的确界。

$\lim\limits_{x↭x_t} f (x) ↭ f (x_t) ≠ ±∞$

$∀ε>0;∃δ>0;∀x,x_t∈X; \left[ | x - x_t | ≤ δ \right] ⇒ \left[ | f (x) - f (x_t) | ≤ ε \right]$

$\left[ ∀ε>0;∃δ>0; \sup\limits_{|x-x_t|≤δ} | f (x) - f (x_t) | ≤ ε \right] ⇔ \left[ ∀x_0∈X;∀ε>0;∃δ>0;∀x,x_t∈\left\lbrace\mathop{x,x_t∈X}\limits_{|x-x_t|≤δ}\right\rbrace; | f (x) - f (x_t) | ≤ ε \right]$

$∃\mathrm{Sup};∀x_t∈X; | f (x_t) | ≤ \sup\limits_{x_t∈X} | f (x_t) | =\mathrm{Sup}$

若函数$f (x)$在区间$X$上点$x_0$处连续，则在该点处的振幅为零，反之亦然。

$\left[ \lim\limits_{x⇝x_0} f (x) ⇝ f (x_0) \right] ⇔ \left[ \lim\limits_{Δx⇝0} w^{f} (x_0) ⇝ 0 \right]$

若函数$f (x)$在区间$X$上点$x_0$处连续，则在该点处的左极限与右极限相等，反之亦然。

$f (x_0^-) = \lim\limits_{x⇝x_0^-} f (x) ⇝ f (x_0) ⇜ \lim\limits_{x⇝x_0^+} f (x) = f (x_0^+)$

若函数$f (x)$在点$x_0$处连续$\lim\limits_{x⇝x_0} f (x) ⇝ f (x_0)$，且函数$g (x)$在点$x_0$处连续$\lim\limits_{x⇝x_0} g (x) ⇝ g (x_0)$。

$\lim\limits_{x⇝x_0} [ f (x) + g (x) ] = \lim\limits_{x⇝x_0} f (x) + \lim\limits_{x⇝x_0} g (x) ⇝ f (x_0) + g (x_0)$

$\lim\limits_{x⇝x_0} [ f (x) - g (x) ] = \lim\limits_{x⇝x_0} f (x) - \lim\limits_{x⇝x_0} g (x) ⇝ f (x_0) - g (x_0)$

$\lim\limits_{x⇝x_0} [ f (x) · g (x) ] = \lim\limits_{x⇝x_0} f (x) · \lim\limits_{x⇝x_0} g (x) ⇝ f (x_0) · g (x_0)$

$\lim\limits_{x⇝x_0} \dfrac{f (x)}{g (x)} = \dfrac{\lim\limits_{x⇝x_0} f (x)}{\lim\limits_{x⇝x_0} g (x)} \mathop{⇝}\limits_{g(x_0)≠0} \dfrac{f (x_0)}{g (x_0)}$

$\lim\limits_{x⇝x_0} \mathrm{Con.} · f (x) = \mathrm{Con.} \lim\limits_{x⇝x_0} f (x) ⇝ \mathrm{Con.} · f (x_0)$

若函数$f (y)$在点$y_0$处连续$\lim\limits_{y⇝y_0} f (y) ⇝ f (y_0)$，且函数$y = g (x)$在点$x_0$处连续$\lim\limits_{x⇝x_0} g (x) ⇝ g (x_0) = y_0$。

$\lim\limits_{x⇝x_0} f (g (x)) = f \left( \lim\limits_{x⇝x_0} g (x) \right) ⇝ f (g (x_0))$

| $⇓$  | $∀ζ>0;∃ε>0;∀y∈Y; \left[ | g (x) - g (x_0) | = | y - y_0 | ≤ ε \right] ⇒ \left[ | f (g (x)) - f (g (x_0)) | = | f (y) - f (y_0) | ≤ ζ \right]$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε>0;∃δ>0;∀x∈X; \left[ | x - x_0 | ≤ δ \right] ⇒ \left[ | g (x) - g (x_0) | ≤ ε \right]$ |
| $⇓$  | $∀ζ>0;∃ε>0;∃δ>0;∀y∈Y;∀x∈X; [ | x - x_0 | ≤ δ ] ⇒ [ | g (x) - g (x_0) | ≤ ε ] ⇒ [ | f (g (x)) - f (g (x_0)) | ≤ ζ ]$ |
| $⇓$  | $∀ζ>0;∃δ>0;∀x∈X; [ | x - x_0 | ≤ δ ] ⇒ [ | f (g (x)) - f (g (x_0)) | ≤ ζ ]$ |

若函数$f (x)$在区间$X$上任意切割线的斜率有全局的确界，则函数$f (x)$在区间$X$上一致连续，反之不对。

$\left[ ∀x,x_t∈X; | f (x) - f (x_t) | ≤ \mathrm{Sup.} · | x - x_t | \right] ⇒ \left[ \lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈X} f (x_t) \right]$

$\left[ ∀x_t∈\fbox{X}; \left| \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{x_t} ≤ \mathrm{Sup_{x_t}} ≠ ∞⁺ \right] ⇒ \left[ ∀x,x_t∈\fbox{X}; | f (x) - f (x_t) | ≤ \mathrm{Sup.} · | x - x_t | \right] ⇒ \left[ \lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈\fbox{X}} f (x_t) \right]$

| $⇓$  | $∀x_t∈\fbox{X}; \left| \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{x_t} ≤ \mathrm{Sup_{x_t}} ≠ ∞⁺$ | $⇒$  | $\lim\limits_{x⇝x_t} \left| \dfrac{f (x) - f (x_t)}{x - x_t} \right| = \left| \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{x_t} ≤ \mathrm{Sup_{x_t}} ≤ \mathrm{Sup} = \sup\limits_{x_t∈\fbox{X}}\lbrace \mathrm{Sup_{x_t}} \rbrace ≠ ∞⁺$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $∀x,x_t∈X; | f (x) - f (x_t) | ≤ \mathrm{Sup.} · | x - x_t | $ |      |                                                              |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈X; [ | x - x_t | ≤ δ ] ⇒ [ | f (x) - f (x_t) | ≤ \mathrm{Sup.} · | x - x_t | ≤ ε ]$ |      |                                                              |
| $⇓$  | $\lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈X} f (x_t)$ |      |                                                              |

若函数$f (x)$在区间$X$上满足切割线过程，则函数$f (x)$在区间$X$上一致连续，反之亦然。

$0 ↭ \lim\limits_{x↭x_t} | f (x) - f (x_t) | \mathop{===}\limits_{x_t∈X}^{x∈X} \lim\limits_{x↭x_t} \left[ \left| \dfrac{f (x) - f (x_t)}{x - x_t} \right| · | x - x_t | \right] \mathop{===}\limits_{x_t∈X}^{x∈X} \left[ \lim\limits_{x↭x_t} \left| \dfrac{f (x) - f (x_t)}{x - x_t} \right| · \lim\limits_{x↭x_t} | x - x_t | \right] \mathop{===}\limits_{x_t∈\fbox{X}}^{x∈X} \lim\limits_{x⇝x_t} \left[ \left| \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{x_t=x} · | x - x_t | \right]$

若函数$f (x)$在区间$X$上一致连续，则函数$f (x)$在区间$X$上连续，反之不对。

$\left[ \lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈X} f (x_t) \right] ⇒ \left[ \lim\limits_{x⇝x_0} f (x) \mathop{⇝}\limits_{x,x_0∈X} f (x_0) \right]$

若函数$f (x)$在区间$[X_0, X_1]$上连续，则函数$f (x)$在区间$[X_0, X_1]$上一致连续，反之亦然。

$\left[ \lim\limits_{x⇝x_0} f (x) \mathop{⇝}\limits_{x,x_0∈[X_0,X_1]} f (x_0) \right] ⇔ \left[ \lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈[X_0,X_1]} f (x_t) \right]$

若函数$f (x)$在区间$(X_0, X_1)$上一致连续，则可将函数$f (x)$延拓为区间$[X_0,X_1]$上的一致连续函数$\tilde{f} (x) = \mathop{\lim\limits^{x⇝X_0^+} f (x)}\limits_{x=X_0}; \mathop{f (x)}\limits_{x∈(X_0,X_1)}; \mathop{\lim\limits^{x⇝X_1^-} f (x)}\limits_{x=X_1}$。

若函数$f (x)$在区间$(X_0,X_1]$上一致连续，且在区间$[X_1, X_2)$上一致连续，则函数$f (x)$在区间$(X_0, X_2)$上一致连续。

$\left[ \lim\limits_{x↭x_0} f (x) \mathop{↭}\limits_{x,x_0∈(X_0,X_1]} f (x_0) \right] ∧ \left[ \lim\limits_{x↭x_0} f (x) \mathop{↭}\limits_{x,x_0∈[X_1,X_2)} f (x_0) \right] ⇒ \left[ \lim\limits_{x↭x_0} f (x) \mathop{↭}\limits_{x,x_0∈(X_0,X_2)} f (x_0) \right]$

| $⇓$  | $∀ε_1>0;∃δ>0;∀x,x_t∈(X_0,X_1]; \left[ | x - x_t | ≤ δ \right] ⇒ \left[ | f (x) - f (x_t) | ≤ ε_1 \right]$ | $\lim\limits_{x↭x_0} f (x) \mathop{↭}\limits_{x,x_0∈(X_0,X_1]} f (x_0)$ |
| :--: | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $⇓$  | $∀ε_2>0;∃δ>0;∀x,x_t∈[X_1,X_2); \left[ | x - x_t | ≤ δ \right] ⇒ \left[ | f (x) - f (x_t) | ≤ ε_2 \right]$ | $\lim\limits_{x↭x_0} f (x) \mathop{↭}\limits_{x,x_0∈[X_1,X_2)} f (x_0)$ |
| $⇓$  | $∀ε_3>0;∃δ>0;∀x∈(X_0,X_1];∀x_t∈[X_1,X_2); [ | x - x_t | ≤ δ ] ⇒ [ | f (x) - f (x_t) | ≤ | f (x) - f (X_1) | + | f (X_1) - f (x_t) | ≤ ε_1 + ε_2 = ε_3 ]$ |                                                              |
| $⇓$  | $∀ε_3>0;∃δ>0;∀x,x_t∈(X_0,X_1); \left[ | x - x_t | ≤ δ \right] ⇒ \left[ | f (x) - f (x_t) | ≤ ε_3 \right]$ | $\lim\limits_{x↭x_0} f (x) \mathop{↭}\limits_{x,x_0∈(X_0,X_2)} f (x_0)$ |

若函数$f (x)$在区间$(∞⁻,∞⁺)$上连续，且以区间$[T_0, T_1]$为周期，则函数$f (x)$在区间$(∞⁻,∞⁺)$上一致连续。

若函数$f (x)$在区间$[X_0^{±}, ±∞)$上连续，且 $\lim\limits_{x⇝±∞} f (x) ⇝ f_{±∞}$的极限存在，则函数$f (x)$在$[X_0^{±}, ±∞)$上一致连续。

$\left[ \lim\limits_{x⇝x_0} f (x) \mathop{⇝}\limits_{x,x_0∈[X_0^{±},±∞)} f (x_0) \right] ∧ \left[ \lim\limits_{x⇝±∞} f (x) ⇝ f_{±∞} \right] ⇔ \left[ \lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_0∈[X_0^{±},±∞)} f (x_t) \right]$

| $⇓$  | $∃X_1;[X_0^{±}, ±∞) = [X_0^{±}, X_1] ∪ [X_1, ±∞)$            |      |                                                              |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε>0;∃X_1∈[X_0^{±},±∞];∀x,x_t∈[X_1,±∞); [ | f (x) - f (x_t) | ≤ ε ]$ | $⇔$  | $\left[ \lim\limits_{x⇝±∞} f (x) \mathop{⇝}\limits_{x∈[X_1,±∞)} f_{±∞} \right]$ |
| $⇓$  | $∀ε>0;∃X_1∈[X_0^{±},±∞]; ¬[ ∀δ=|x-x_t|; | x - x_t | ≤ δ ] ∨ [ ∀x,x_t∈[X_1,±∞);  | f (x) - f (x_t) | ≤ ε ]$ |      |                                                              |
| $⇓$  | $∀ε>0;∃X_1∈[X_0^{±},±∞];∃δ=|x-x_t|;∀x,x_t∈[X_1,±∞); ¬[ | x - x_t | ≤ δ ] ∨ [   | f (x) - f (x_t) | ≤ ε ]$ |      |                                                              |
| $⇓$  | $∀ε>0;∃X_1∈[X_0^{±},±∞];∃δ>0;∀x,x_t∈[X_1,±∞); [ | x - x_t | ≤ δ ] ⇒ [   | f (x) - f (x_t) | ≤ ε ]$ | $⇒$  | $\left[ \lim\limits_{x⇝x_t} f (x) \mathop{↭}\limits_{x∈[X_1,±∞)} f (x_t) \right]$ |
| $⇓$  | $∀ε>0;∃X_1∈[X_0^{±},±∞];∃δ>0;∀x,x_t∈[X_0^{±},X_1]; [ | x - x_t | ≤ δ ] ⇒ [ | f (x) - f (x_t) | ≤ ε ]$ | $⇔$  | $\left[ \lim\limits_{x⇝x_t} f (x) \mathop{↭}\limits_{x,x_t∈[X_0^{±},X_1]} f (x_t) \right]$ |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈[X_0^{±},±∞); [ | x - x_t | ≤ δ ] ⇒ [ | f (x) - f (x_t) | ≤ ε ]$ | $⇒$  | $\left[ \lim\limits_{x⇝x_t} f (x) \mathop{↭}\limits_{x,x_0∈[X_0^{±},±∞)} f (x_t) \right]$ |

典例：函数$f (x) = \dfrac{1}{x}$在区间$(0, 1)$上非一致连续，但在区间$\mathop{[X_0, X_1)}\limits_{0<X_0}$上一致连续。

典例：函数$f (x) = \sin x^2$在区间$(∞⁻, ∞⁺)$上非一致连续。函数$f (x) = α · x + β$在区间$(∞⁻, ∞⁺)$上一致连续。

典例：函数$f (x) = | x |$在区间$(∞⁻, ∞⁺)$上一致连续。函数$\mathrm{sgn} (x) = \mathop{-1}\limits_{x<0};\mathop{0}\limits_{x=0};\mathop{+1}\limits_{x>0}$在区间$[-1, +1]$上非一致连续。

典例：函数$f (x) = \sqrt{x}$在区间$(+0, ∞⁺)$上一致连续，但其在点$x_0=0^+$处导函数的极限为$\left.\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{x_0=0^+} = \lim\limits_{x⇝0^+} \dfrac{1}{2 · \sqrt{x}} = ∞⁺$。

| $⇓$  | $∃ε>0;∀δ>0;∃x≡\dfrac{1}{n},x_t≡\dfrac{1}{n + 1}; \left[ | x - x_t | = \left| \dfrac{1}{n · (n + 1)} \right| < δ \right] ∧ \left[ | f (x) - f (x_t) | = \left| \dfrac{1}{x} - \dfrac{1}{x_t} \right| = \left| \dfrac{1}{\frac{1}{n}} - \dfrac{1}{\frac{1}{n + 1}} \right| = 1 ≥ ε \right]$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈[X_0,X_1); \left[ | x - x_t | < δ \right] ⇒ \left[ | f (x) - f (x_t) | = \left| \dfrac{1}{x} - \dfrac{1}{x_t} \right| = \dfrac{| x - x_t |}{| x · x_t |} < \dfrac{δ}{X_0^2} = ε \right]$ |
|      |                                                              |
| $⇓$  | $∃ε>0;∀δ>0;∃x≡\sqrt{n·π+\frac{π}{2}},x_t≡\sqrt{n·π}; \left[ | x - x_t | = \dfrac{\frac{π}{2}}{\sqrt{n·π+\frac{π}{2}} + \sqrt{n·π}} < δ \right] ∧ \left[ | f (x) - f (x_t) | = \left| \sin x^2 - \sin x_t^2 \right| = \left| \sin \left( n·π+\frac{π}{2} \right) - \sin (n·π) \right| = 1 ≥ ε \right]$ |
|      |                                                              |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈(∞⁻,∞⁺); \left[ | x - x_t | < δ \right] ⇒ \left[ | f (x) - f (x_t) | = \left| (α · x + β) - (α · x_t + β) \right| = | α | · | x - x_t | < | α | · δ = ε \right]$ |
|      |                                                              |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈(∞⁻,∞⁺); [ | x - x_t | < δ ] ⇒ [ | f (x) - f (x_t) | = || x | - | x_t || < | x - x_t | < δ = ε ]$ |
|      |                                                              |
| $⇓$  | $∃ε>0;∀δ>0;∃x≡\dfrac{1}{n},x_t≡0; \left[ | x - x_t | = \left| \dfrac{1}{n} \right| < δ \right] ∧ [ | f (x) - f (x_t) | = | 1 - 0 | = 1 ≥ ε ]$ |
|      |                                                              |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈(0, ∞⁺); [ | x - x_t | < δ ] ⇒ \left[ | f (x) - f (x_t) | = | \sqrt{x} - \sqrt{x_t} | < \left| \dfrac{x - x_t}{\sqrt{x} + \sqrt{x_t}} \right| \mathop{<}\limits^{x-x_t=δ} \left| \dfrac{δ}{\sqrt{x_t+δ}+\sqrt{x_t}} \right| < \left| \dfrac{δ}{\sqrt{δ}} \right| = ε \right]$ |

### 连续介值定理

函数$f (x)$在区间$X$上连续，对于函数值域内任意的函数值$f (t)$，必定至少存在一点$θ∈X$使得成立。

$f(x)|_{∀t∈X} = \left.f (x)\right|_{∃θ∈X}$

| $⇓$  | $∀t∈X;∃θ∈X; f (t) = f (θ)$                                   | $⇔$  | $f(x)|_{∀t∈X} = \left.f (x)\right|_{∃θ∈X}$                   |
| :--: | :----------------------------------------------------------- | :--: | ------------------------------------------------------------ |
| $⇓$  | $∀y∈\left( \inf\limits_{x∈X} f(x), \sup\limits_{x∈X} f(x) \right) ⊊ (∞⁻, ∞⁺);∃θ∈X; y = f (θ)$ | $⇐$  | $y ≡ f (x)$                                                  |
| $⇓$  | $∀y∈\left[\min \lbrace f (X_0), f (X_1) \rbrace, \max \lbrace f (X_0), f (X_1) \rbrace \right];∃θ∈[X_0, X_1]; y = f (θ)$ | $⇐$  | $[ \min\lbrace f (X_0), f (X_1) \rbrace, \max\lbrace f (X_0), f (X_1) \rbrace ] ⊆ \left( \inf\limits_{x∈[X_0,X_1]} f (x), \sup\limits_{x∈[X_0,X_1]} f (x) \right)$ |
| $⇓$  | $\left[ f (X_0) · f (X_1) ≤ 0 \right] ⇒ \left[ 0 = \left. f (θ) \right|_{∃θ∈[X_0, X_1]} \right]$ | $⇐$  | $0 ∈ [ \min\lbrace f (X_0), f (X_1) \rbrace, \max\lbrace f (X_0), f (X_1) \rbrace ]$ |

若函数$f (x)$在单区间$X$上连续，则其值域$Y$为单区间，反之不对。

若函数$f (x)$在区间$[X_0, X_1]$上连续，且其值域内含于定义域，则必存在不动点$θ∈[X_0, X_1]$使得成立。

$∀x∈[X_0, X_1]; f(x)∈[X_0, X_1] ⇒ \left.f (x)\right|_{∃θ∈[X_0, X_1]} = θ$

| $⇓$  | $F (x) ≡ f (x) - x$                    |      |                                                |
| :--: | :------------------------------------- | :--: | :--------------------------------------------- |
| $⇓$  | $F (X_0) · F (X_1) ≤ 0$                    | $⇐$  | $F (X_0) = f (X_0) - X_0 ≥ 0, F (X_1) = f (X_1) - X_1 ≤ 0$ |
| $⇓$  | $0 = \left. F (x) \right|_{∃θ∈[X_0, X_1]}$ |      |                                                |
| $⇓$  | $\left.f (x)\right|_{∃θ∈[X_0, X_1]} = θ$   |      |                                                |

若函数$f (x)$在区间$[X_0, X_1]$上连续，则对于任意$λ_i>0$必存在点$θ$使得成立。

$∀x_i∈[X_0,X_1];∃θ∈[\min\lbrace x_i \rbrace, \max\lbrace x_i \rbrace];∀λ_i>0; \left[ \sum\limits_{i=0}^{n} λ_i = 1 \right] ⇒ \left[ f (θ) = \sum\limits_{i=0}^{n} λ_i · f (x_i) \right]$

| $⇓$  | $\min\lbrace f (x_i) \rbrace ≤ \sum\limits_{i=0}^{n} λ_i · f (x_i) ≤ \max\lbrace f (x_i) \rbrace$ | $⇐$  | $∀λ_i>0; \sum\limits_{i=0}^{n} λ_i = 1$                      |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $∃θ∈[\min\lbrace x_i \rbrace, \max\lbrace x_i \rbrace]; f (θ) = \sum\limits_{i=0}^{n} λ_i · f (x_i)$ | $⇐$  | $[\min\lbrace f (x_i) \rbrace, \max\lbrace f (x_i) \rbrace ] ⊆ \left( \inf\limits_{x∈[\min\lbrace x_i \rbrace, \max\lbrace x_i \rbrace]} f (x), \sup\limits_{x∈[\min\lbrace x_i \rbrace, \max\lbrace x_i \rbrace]} f (x) \right)$ |

对于实数域的奇数次多项式$0 = P_{2·m+1} (x) = \sum\limits_{i=0}^{2 · m + 1} p_i · (x - x_0)^{i}$，必定存在至少一个实数解$θ$。

| $⇓$  | $P_{2·m+1} (x) = \sum\limits_{i=0}^{2·m+1} p_i · (x - x_0)^{i} = p_{2·m+1} · (x - x_0)^{2·m+1} + \sum\limits_{i=0}^{2·m} \dfrac{p_i}{(x - x_0)^{2 · m + 1 - i}}$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $\lim\limits_{x⇝∞⁺} P_{2·m+1} (x) = \lim\limits_{m⇝∞⁺} p_{2·m+1} · (x - x_0)^{2 · m + 1} ⇝ ∞⁺ · p_{2·m+1}$ |
| $⇓$  | $\lim\limits_{x⇝∞⁻} P_{2·m+1} (x) = \lim\limits_{m⇝∞⁺} p_{2·m+1} · (x - x_0)^{2 · m + 1} ⇝ ∞⁻ · p_{2·m+1}$ |
| $⇓$  | $0∈\left( \inf\limits_{x∈ℝ} P_{2·m+1} (x), \sup\limits_{x∈ℝ} P_{2·m+1} (x) \right) = (∞⁻, ∞⁺)$ |
| $⇓$  | $∃θ∈ℝ; 0 = P_{2·m+1} (θ) = \sum\limits_{i=0}^{2 · m + 1} p_i · (θ - x_0)^{i}$ |

若函数$f (x)$在区间$(X_0, X_1)$上连续，且$\lim\limits_{x⇝X_0^{+}} f (x)$与$\lim\limits_{x⇝X_1^{-}} f (x)$均有确界，则函数$f (x)$在区间$(X_0, X_1)$上有确界。

若函数$f (x)$在区间$(∞⁻, ∞⁺)$上连续，且$\lim\limits_{x⇝∞⁻} f (x)$与$\lim\limits_{x⇝∞⁺} f (x)$均有确界，则函数$f (x)$在区间$(∞⁻, ∞⁺)$上有确界。

$∀x∈(X_0,X_1); | f (x) | ≤ \max\left\lbrace \left| \sup\limits_{x∈X} f (x) \right|, \left| \inf\limits_{x∈X} f (x) \right| \right\rbrace ≠ ∞⁺$

### 微分中值定理

函数$f (x)$在闭区间$[X_0, X_1]$上连续且可导，若两个端点的函数值相等，则必至少存在一点$θ∈(X_0, X_1)$使得成立。

$[ f (X_0) = f (X_1) ] ⇒ \left[ \left. \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{∃θ∈(X_0, X_1)}  = 0 \right]$

| $⇓$  | $\lim\limits_{x⇝θ^-} \dfrac{f (x) - f (θ)}{x - θ} ≤ 0 ≤ \lim\limits_{x⇝θ^+} \dfrac{f (x) - f (θ)}{x - θ}$ | $⇐$  | $f (θ) ≡ \min\limits_{x∈(X_0, X_1)} f (x)$ |
| :--: | :----------------------------------------------------------- | :--: | :------------------------------------- |
| $⇓$  | $\lim\limits_{x⇝θ^-} \dfrac{f (x) - f (θ)}{x - θ} ≥ 0 ≥ \lim\limits_{x⇝θ^+} \dfrac{f (x) - f (θ)}{x - θ}$ | $⇐$  | $f (θ) ≡ \max\limits_{x∈(X_0, X_1)} f (x)$ |
| $⇓$  | $\left.\dfrac{\mathrm{d} f (x)}{\mathrm{d} x}\right|_{∃θ∈(X_0, X_1)} = \lim\limits_{x⇝θ} \dfrac{f (x) - f (θ)}{x - θ} = 0$ | $⇐$  | $f (X_0) = f (X_1)$                        |

函数$f (x)$在闭区间$[X_0, X_1]$上连续且可导，则必至少存在一点$θ∈(X_0, X_1)$使得成立。

$\left. \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{∃θ∈(X_0, X_1)} = \dfrac{f (X_1) - f (X_0)}{X_1 - X_0}$

| $⇓$  | $F (x) = \left|\begin{matrix} 1 & 1 & 1 \\ X_0 & x & X_1 \\ f (X_0) & f (x) & f (X_1) \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ X_0 & x - X_0 & X_1 - X_0 \\ f (X_0) & f (x) - f (X_0) & f (X_1) - f (X_0) \end{matrix}\right|$ | $⇒$  | $F (X_0) = 0 = F (X_1)$                                      |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $$\dfrac{\mathrm{d} F (x)}{\mathrm{d} x} = \dfrac{\mathrm{d}}{\mathrm{d} x} \left|\begin{matrix} 1 & 0 & 0 \\ X_0 & x - X_0 & X_1 - X_0 \\ f (X_0) & f (x) - f (X_0) & f (X_1) - f (X_0) \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ X_0 & 1 & X_1 - X_0 \\ f (X_0) & \dfrac{\mathrm{d} f (x)}{\mathrm{d}x} & f (X_1) - f (X_0) \end{matrix}\right|$$ | $⇒$  | $\dfrac{\mathrm{d} F (x)}{\mathrm{d} x} = [ f (X_1) - f (X_0) ] - (X_1 - X_0) · \dfrac{\mathrm{d} f (x)}{\mathrm{d} x}$ |
| $⇓$  | $\left. \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{∃θ∈(X_0, X_1)} = \dfrac{f (X_1) - f (X_0)}{X_1 - X_0}$ | $⇐$  | $\left.\dfrac{\mathrm{d} F (x)}{\mathrm{d} x} \right|_{∃θ∈(X_0, X_1)} = 0$ |

函数$f (x)$与函数$g (x)$在闭区间$[X_0, X_1]$上连续且可导，则必至少存在一点$θ∈(X_0, X_1)$使得成立。

$\left.\dfrac{\mathrm{d} f (x)}{\mathrm{d} g (x)}\right|_{∃θ∈(X_0, X_1)} = \dfrac{f (X_1) - f (X_0)}{g (X_1) - g (X_0)}$

| $⇓$  | $F (x) = \left|\begin{matrix} 1 & 1 & 1 \\ g (X_0) & g (x) & g (X_1) \\ f (X_0) & f (x) & f (X_1) \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ g (X_0) & g (x) - g (X_0) & g (X_1) - g (X_0) \\ f (X_0) & f (x) - f (X_0) & f (X_1) - f (X_0) \end{matrix}\right|$ | $⇒$  | $F (X_0) = 0 = F (X_1)$                                      |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\dfrac{\mathrm{d} F (x)}{\mathrm{d} x} = \dfrac{\mathrm{d}}{\mathrm{d} x} \left|\begin{matrix} 1 & 0 & 0 \\ g (X_0) & g (x) - g (X_0) & g (X_1) - g (X_0) \\ f (X_0) & f (x) - f (X_0) & f (X_1) - f (X_0) \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ g (X_0) & \dfrac{\mathrm{d} g (x)}{\mathrm{d} x} & g (X_1) - g (X_0) \\ f (X_0) & \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} & f (X_1) - f (X_0) \end{matrix}\right|$ | $⇒$  | $\dfrac{\mathrm{d} F (x)}{\mathrm{d} x} = [ f (X_1) - f (X_0) ]  · \dfrac{\mathrm{d} g (x)}{\mathrm{d} x} - [ g (X_1) - g (X_0) ] · \dfrac{\mathrm{d} f (x)}{\mathrm{d} x}$ |
| $⇓$  | $\left.\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} · \dfrac{\mathrm{d} x}{\mathrm{d} g (x)}\right|_{∃θ∈(X_0, X_1)} = \left.\dfrac{\mathrm{d} f (x)}{\mathrm{d} g (x)}\right|_{∃θ∈(X_0, X_1)} = \dfrac{f (X_1) - f (X_0)}{g (X_1) - g (X_0)}$ | $⇐$  | $\left.\dfrac{\mathrm{d} F (x)}{\mathrm{d} x} \right|_{∃θ∈(X_0, X_1)} = 0$ |





### 幂级数公式

若多项式函数$\mathrm{Poly}_n (x)$在点$x_0$处连续且有$n + 1$阶导数，则在点$x_0$处可唯一展开成$n$阶幂级数。

$P_n (x) = \sum\limits_{i=0}^n p_i · (x - x_0)^i = p_0 · (x - x_0)^0 + p_1 · (x - x_0)^1 + p_2 · (x - x_0)^2 + ··· + p_n · (x - x_0)^n$

$P_n (x) = \sum\limits_{i=0}^n \dfrac{{^i}P_n (x_0)}{i!} · (x - x_0)^i = \sum\limits_{i=0}^n \left.\dfrac{\mathrm{d}^i P_n (x)}{i! · \mathrm{d}^i x}\right|_{x_0} · (x - x_0)^i = \sum\limits_{i=0}^n \left.\dfrac{\mathrm{d}^i P_n (x)}{\mathrm{d} x^i}\right|_{x_0} · (x - x_0)^i$

| ${^n}P_n (x_0) = n! · p_n$                                   | ${^0}P_n (x_0) = 0! · p_0$                                   | ${^1}P_n (x_0) = 1! · p_1$                                   | ${^2}P_n (x_0) = 2! · p_2$                                   |
| ------------------------------------------------------------ | :----------------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| $\left.\dfrac{\mathrm{d}^n P_n (x)}{\mathrm{d}^n x}\right|_{x_0} ≡ \left.\underbrace{\dfrac{\mathrm{d}}{\mathrm{d} x} ··· \dfrac{\mathrm{d}}{\mathrm{d} x} }_n P_n (x) \right|_{x_0} ≡ n! · p_n$ | $\left.\dfrac{\mathrm{d}^0 P_n (x)}{\mathrm{d}^0 x}\right|_{x_0} ≡ \left.P_n (x)\right|_{x_0} ≡ 0! · p_0$ | $\left.\dfrac{\mathrm{d}^1 P_n (x)}{\mathrm{d}^1 x}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}}{\mathrm{d} x} P_n (x)\right|_{x_0} ≡ 1! · p_1$ | $\left.\dfrac{\mathrm{d}^2 P_n (x)}{\mathrm{d}^2 x}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d}}{\mathrm{d} x} P_n (x)\right|_{x_0} ≡ 2! · p_2$ |
| $\left.\dfrac{\mathrm{d}^n P_n (x)}{\mathrm{d} x^n}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}^n P_n (x)}{n! · \mathrm{d}^n x}\right|_{x_0} ≡ p_n$ | $\left.\dfrac{\mathrm{d}^0 P_n (x)}{\mathrm{d} x^0}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}^0 P_n (x)}{0! · \mathrm{d}^0 x}\right|_{x_0} ≡ p_0$ | $\left.\dfrac{\mathrm{d}^1 P_n (x)}{\mathrm{d} x^1}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}^1 P_n (x)}{1! · \mathrm{d}^1 x}\right|_{x_0} ≡ p_1$ | $\left.\dfrac{\mathrm{d}^2 P_n (x)}{\mathrm{d} x^2}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}^2 P_n (x)}{2! · \mathrm{d}^2 x}\right|_{x_0} ≡ p_2$ |
| $\dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d}^n P_n (x)}{\mathrm{d} x^n} = \dfrac{(n + 1) · \mathrm{d}^{n+1} P_n (x)}{\mathrm{d} x^{n+1}}$ | $\dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d}^0 P_n (x)}{\mathrm{d} x^0} = \dfrac{1 · \mathrm{d}^1 P_n (x)}{\mathrm{d} x^1}$ | $\dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d}^1 P (x)}{\mathrm{d} x^1} = \dfrac{2 · \mathrm{d}^2 P_n (x)}{\mathrm{d} x^2}$ | $\dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d}^2 P_n (x)}{\mathrm{d} x^2} = \dfrac{3 · \mathrm{d}^3 P_n (x)}{\mathrm{d} x^3}$ |

若任意形式的函数$f (x)$在点$x_0$处连续且有$n + 1$阶导数，则在点$x_0$处可唯一展开成$n$阶幂级数。

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

对于任意零测集$\mathcal{O}$，均存在可列可数个区间$X_{i∈ℕ}$覆盖之，使得其可测度长度为零。

$∀\mathcal{O};∃\lbrace X_{i∈ℕ} \rbrace;∀ζ>0; \left[ \mathcal{O} ⊆ \bigcup\limits_{i=0}^{ℕ} X_i \right] ∧ \left[ | \mathcal{O} | ≤ \sum\limits_{i=0}^{ℕ} | X_i | < ζ \right]$

可列可数集$\lbrace {s_{i∈ℕ}} \rbrace$为零测集。此外有限集为可列可数集，零测集的子集为零测集。

$∀\lbrace\mathcal{s_{i∈ℕ}}\rbrace;∃\lbrace X_{i∈ℕ} \rbrace;∀ζ_2>0; \left[ \lbrace s_{i∈ℕ} \rbrace ⊆ \bigcup\limits_{i=0}^{ℕ} \left( s_i - \dfrac{ζ_1}{2^{i+1}}, s_i + \dfrac{ζ_1}{2^{i+1}} \right) \right] ∧ \left[ \left| \lbrace s_{i∈ℕ} \rbrace \right| = \sum\limits_{i=0}^{ℕ} | s_i | ≤ \sum\limits_{i=0}^{ℕ} \dfrac{ζ_1}{2^{i}} ≤ \sum\limits_{i=0}^{∞⁺} \dfrac{ζ_1}{2^i} =  2 · ζ_1 = ζ_2 \right]$

可列可数个零测集$𝒪_i$的合集$\lbrace 𝒪_{i∈ℕ} \rbrace$为零测集。

$∀\lbrace\mathcal{O}_{i∈ℕ}\rbrace;∃\lbrace X_{{i∈ℕ},{j∈ℕ}} \rbrace;∀ζ_3>0; \left[ \lbrace \mathcal{O}_{i∈ℕ} \rbrace ⊆ \bigcup\limits_{i=0}^{ℕ} \bigcup\limits_{j=0}^{ℕ} X_{i,j} \right] ∧ \left[ \left| \lbrace \mathcal{O}_{i∈ℕ} \rbrace \right| = \sum\limits_{i=0}^{ℕ} | \mathcal{O}_i | = \sum\limits_{i=0}^{ℕ} \sum\limits_{j=0}^{ℕ} | X_{i,j} | ≤ \sum\limits_{i=0}^{∞⁺} \dfrac{1}{2^{i}} · \sum\limits_{j=0}^{∞⁺} \dfrac{ζ_1}{2^{j}} ≤ \sum\limits_{i=0}^{∞⁺} \dfrac{ζ_2}{2^i} = 2 · ζ_2 = ζ_3 \right]$

### 定积分

对于函数$f (x)$，在将区间$[X_0, X_1]$划分成$n + 1$个子区间$[x_i, x_{i+1}]$的基础上，多添加$m$个点再形成$m$个子区间，其下积分和不减，其上积分和不增。

对于函数$f (x)$，有任意多种将区间$[X_0, X_1]$划分成子区间的情形，其下积分和始终小于等于上积分和。可理解为将任意两种划分情形互相叠加。

对于函数$f (x)$，在区间$[X_0, X_1]$上的任意多种划分情形，若下积分和的极限等于上积分和的极限，则其积分和的极限存在且唯一，此即定积分。

$\sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_i ≤ \sum\limits_{j=0}^{n+m} \inf\limits_{x∈[x_j, x_{j+1}]} f (x) · Δx_j ≤ \sum\limits_{j=0}^{n+m} f (θ_j) · Δx_j ≤ \sum\limits_{j=0}^{n+m} \sup\limits_{x∈[x_j, x_{j+1}]} f (x) · Δx_j ≤ \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_i$

$\sum\limits_{i=0}^{n} \inf\limits_{x∈[x_{i},x_{i+1}]} f (x) · Δx_i ≤ \rlap{≡≡≡≡≡≡≡≡≡≡≡≡≡}{\sum\limits_{j=0}^{n+m} \inf\limits_{x∈[x_{j},x_{j+1}]} f (x) · Δx_j} ≤ \sum\limits_{j=0}^{n+m} f (θ_j) · Δx_j ≤ \rlap{≡≡≡≡≡≡≡≡≡≡≡≡≡}{\sum\limits_{j=0}^{n+m} \sup\limits_{x∈[x_{j},x_{j+1}]} f (x) · Δx_j} ≤ \sum\limits_{k=0}^{m} \sup\limits_{x∈[x_{k},x_{k+1}]} f (x) · Δx_k$

$\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_{i},x_{i+1}]} f (x) · Δx_i ≤ \varlimsup\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_{i},x_{i+1}]} f (x) · Δx_i ≤ \lim\limits_{n+m⇝∞⁺}^{Δx_j⇝0} \sum\limits_{j=0}^{n+m} f (θ_j) · Δx_j ≤ \varliminf\limits_{m⇝∞⁺}^{Δx_k⇝0} \sum\limits_{k=0}^{m} \sup\limits_{x∈[x_{k},x_{k+1}]} f (x) · Δx_k ≤ \lim\limits_{m⇝∞⁺}^{Δx_k⇝0} \sum\limits_{k=0}^{m} \sup\limits_{x∈[x_{k},x_{k+1}]} f (x) · Δx_k$

| $⇓$  | $[x_{j}, x_{j+1}] ∪ [x_{j+1}, x_{j+2}] = [x_{i}, x_{i+1}]$   |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $\inf\limits_{x∈[x_{i}, x_{i+1}]} f (x) ≤ \inf\limits_{x∈[x_{j}, x_{j+1}]} f (x), \inf\limits_{x∈[x_{j+1}, x_{j+2}]} f (x) ≤ f (x_{j+1}) ≤ \sup\limits_{x∈[x_{j}, x_{j+1}]} f (x), \sup\limits_{x∈[x_{j+1}, x_{j+2}]} f (x) ≤ \sup\limits_{x∈[x_i, x_{i+1}]} f (x)$ |
| $⇓$  | $\inf\limits_{x∈[x_i, x_{i+1}]} f (x) · [(x_{j+1} - x_{j}) + (x_{j+2} - x_{j+1})] ≤ \inf\limits_{x∈[x_j, x_{j+1}]} f (x) · (x_{j+1} - x_{j}) + \inf\limits_{x∈[x_{j+1}, x_{j+2}]} f (x) · (x_{j+2} - x_{j+1})$ |
| $⇓$  | $\sup\limits_{x∈[x_j, x_{j+1}]} f (x) · (x_{j+1} - x_{j}) + \sup\limits_{x∈[x_{j+1}, x_{j+2}]} f (x) · (x_{j+2} - x_{j+1}) ≤ \sup\limits_{x∈[x_i, x_{i+1}]} f (x) · [(x_{j+1} - x_{j}) + (x_{j+2} - x_{j+1})]$ |

对于函数$f (x)$，在将区间$[X_0, X_1]$划分成$n + 1$个子区间$[x_{i}, x_{i+1}]$的基础上，多添加$m$个点再形成$m$个子区间，其振幅积和不增，其振幅加和不减。

$0 ≤ \sum\limits_{j=0}^{n+m} \left[ \sup\limits_{x∈[x_{j},x_{j+1}]} f (x) - \inf\limits_{x∈[x_{j},x_{j+1}]} f (x) \right] · Δx_j ≤ \sum\limits_{i=0}^{n} \left[ \sup\limits_{x∈[x_{i},x_{i+1}]} f (x) - \inf\limits_{x∈[x_{i},x_{i+1}]} f (x) \right] · Δx_i$

$(m + 1) · \sum\limits_{i=0}^{n} \left[ \sup\limits_{x∈[x_{i},x_{i+1}]} f (x) - \inf\limits_{x∈[x_{i},x_{i+1}]} f (x) \right] ≥ \sum\limits_{j=0}^{n+m} \left[ \sup\limits_{x∈[x_{j},x_{j+1}]} f (x) - \inf\limits_{x∈[x_{j},x_{j+1}]} f (x) \right] ≥ \sum\limits_{i=0}^{n} \left[ \sup\limits_{x∈[x_{i},x_{i+1}]} f (x) - \inf\limits_{x∈[x_{i},x_{i+1}]} f (x) \right] ≥ 0$

| $⇓$  | $[x_{j}, x_{j+1}] ∪ [x_{j+1}, x_{j+2}] = [x_{i}, x_{i+1}]$   |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $\inf\limits_{x∈[x_{i}, x_{i+1}]} f (x) ≤ \inf\limits_{x∈[x_{j}, x_{j+1}]} f (x), \inf\limits_{x∈[x_{j+1}, x_{j+2}]} f (x) ≤ f (x_{j+1}) ≤ \sup\limits_{x∈[x_{j}, x_{j+1}]} f (x), \sup\limits_{x∈[x_{j+1}, x_{j+2}]} f (x) ≤ \sup\limits_{x∈[x_i, x_{i+1}]} f (x)$ |
| $⇓$  | $(1 + 1) · \inf\limits_{x∈[x_{i},x_{i+1}]} f (x) ≤ \inf\limits_{x∈[x_{j},x_{j+1}]} f (x) + \inf\limits_{x∈[x_{j+1},x_{j+2}]} f (x) ≤ \sup\limits_{x∈[x_{j},x_{j+1}]} f (x) + \sup\limits_{x∈[x_{j+1},x_{j+2}]} f (x) ≤ (1 + 1) · \sup\limits_{x∈[x_{i},x_{i+1}]} f (x)$ |
| $⇓$  | $\left[ \sup\limits_{x∈[x_{j},x_{j+1}]} f (x) - \inf\limits_{x∈[x_{j},x_{j+1}]} f (x) \right] + \left[ \sup\limits_{x∈[x_{j+1},x_{j+2}]} f (x) - \inf\limits_{x∈[x_{j+1},x_{j+2}]} f (x) \right] = \left[ \sup\limits_{x∈[x_{j},x_{j+1}]} f (x) - \inf\limits_{x∈[x_{j+1},x_{i+2}]} f (x) \right] + \left[ \sup\limits_{x∈[x_{j+1},x_{j+2}]} f (x) - \inf\limits_{x∈[x_{j},x_{i+1}]} f (x) \right] ≥ 0 + 0$ |
| $⇓$  | $(1 + 1) · \left[ \sup\limits_{x∈[x_{i},x_{i+1}]} f (x) - \inf\limits_{x∈[x_{i},x_{i+1}]} f (x) \right] ≥ \left[ \sup\limits_{x∈[x_{j},x_{j+1}]} f (x) - \inf\limits_{x∈[x_{j},x_{j+1}]} f (x) \right] + \left[ \sup\limits_{x∈[x_{j+1},x_{j+2}]} f (x) - \inf\limits_{x∈[x_{j+1},x_{j+2}]} f (x) \right] ≥ \left[ \sup\limits_{x∈[x_{i},x_{i+1}]} f (x) - \inf\limits_{x∈[x_{i},x_{i+1}]} f (x) \right] + 0$ |

若函数$f (x)$在区间$[X_0, X_1]$上的定积分存在，则其下积分和的极限等于上积分和的极限，反之亦然。

若函数$f (x)$在区间$[X_0, X_1]$上的定积分存在，则其振幅积和的极限为零，反之亦然。

$\int\limits_{X_0}^{X_1} f (x) \mathrm{d} x \mathop{≡≡≡≡}\limits_{X_0=x_0}^{X_1=x_{n+1}} \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i, x_i+1]} f (x) · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} f (θ_i) · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_i$

$0 ⇜ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n w_i · Δx_i ≡ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n \sup\limits_{u,v∈[x_{i}, x_{i+1}]} | f (u) - f (v) | · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \left[ \sup\limits_{x∈[x_{i},x_{i+1}]} f (x) - \inf\limits_{x∈[x_i,x_{i+1}]} f (x) \right] · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_i - \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i, x_i+1]} f (x) · Δx_i$

若函数$f (x)$在区间$[X_0, X_1]$上的定积分存在，则可任取点$θ_i$处的函数值$f (θ_i)$视为该子区间的平均值，反之不对。

若函数$f (x)$在区间$[X_0, X_1]$上的定积分存在，则可将区间$[X_0, X_1]$按等间距划分成子区间，反之不对。

若函数$f (x)$在区间$[X_0, X_1]$上的定积分存在，则当子区间的间距趋于零时，定积分与子区间的取值无关，定积分与子区间的划分无关。

$\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n f (θ_i) · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n f (x_i) · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n f (x_{i+1}) · Δx_i = \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^n f \left[ i · \dfrac{X_1 - X_0}{n + 1} \right] · \dfrac{X_1 - X_0}{n + 1} = \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} f \left[ (i + 1) · \dfrac{X_1 - X_0}{n + 1} \right] · \dfrac{X_1 - X_0}{n + 1}$

$\left[ 0 ⇜ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n w_i · Δx_i \right] ⇒ \left[ 0 ⇜ \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^n w_i · \dfrac{X_1 - X_0}{n + 1} \right] ⇒\left[ 0 ⇜ \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^n \sup\limits_{u,v∈[x_i, x_{i+1}]} | f (u) - f (v) | · \dfrac{X_1 - X_0}{n + 1} \right] ⇒ \left[ 0 ⇜ \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} | f (x_{i+1}) - f (x_{i}) | · \dfrac{X_1 - X_0}{n + 1} \right]$

若函数$f (x)$在区间$[X_0, X_1]$上连续因此一致连续，则其振幅积和的极限为零，反之不对。连续函数$f (x)$在区间$[X_0, X_1]$上的定积分存在。

| $⇓$  | $∀ε>0; \sup\limits_{u,v∈[x_{i},x_{i+1}]} | f (u) - f (v) | ≤ ε$ | $⇔$  | $\lim\limits_{x⇝x_t} f (x) \mathop{↭}\limits_{x,x_t∈[X_0,X_1]} f (x_t)$ |
| :--: | :----------------------------------------------------------- | :--: | ------------------------------------------------------------ |
| $⇓$  | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_i,x_{i+1}]} | f (u) - f (v) | · Δx_i < ε · \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} Δx_i = ε · (X_1 - X_0) ⇝ 0$ |      |                                                              |

若函数$f (x)$在区间$[X_0, X_1]$上的定积分存在，则函数$f (x)$在区间$[X_0, X_1]$上有确界，反之不对。

$\left[ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i ⇝ 0 \right] ⇒ \left[ f (x) ≤ \mathrm{Sup.} \right]$

| $⇓$  | $0 ⇜ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i$ | $⇒$  | $0 ⇜ \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} w_i · \dfrac{X_1 - X_0}{n + 1}$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $0 ⇜ (X_1 - X_0) · \lim\limits_{n⇝∞⁺} \dfrac{\sup\limits_{x∈[X_0,X_1]} f (x) - \inf\limits_{x∈[X_0,X_1]} f (x)}{n + 1}$ | $⇐$  | $\sum\limits_{i=0}^n w_i = \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} | f (u) - f (v) | ≥ \sup\limits_{x∈[X_0,X_1]} f (x) - \inf\limits_{x∈[X_0,X_1]} f (x) ≥ 0$ |
| $⇓$  | $\sup\limits_{x∈[X_0,X_1]} f (x) - \inf\limits_{x∈[X_0,X_1]} f (x) ≠ ∞⁺$ |      |                                                              |
| $⇓$  | $\left[ \sup\limits_{x∈[X_0,X_1]} f (x) ≠ ∞⁺ \right] ∧ \left[ \inf\limits_{x∈[X_0,X_1]} f (x) ≠ ∞⁻ \right]$ | $⇐$  | $\left[ \sup\limits_{x∈[X_0, X_1]} f (x) = ∞⁺ \right] ∨ \left[ \inf\limits_{x∈[X_0,X_1]} f (x) = ∞⁻ \right] ⇒ \left[ \sup f (x) - \inf f (x) = ∞⁺ \right]$ |
| $⇓$  | $| f (x) | ≤ \mathrm{Sup.} = \max \lbrace | \inf f (x) |, | \sup f (x) | \rbrace$ | $⇐$  | $\inf f (x) ≤ f (x) ≤ \sup f (x)$                            |

反例：函数$\mathcal{Q} (x) = \mathop{1}\limits_{x∈ℚ}; \mathop{0}\limits_{x∉ℚ}$在区间$[0, 1]$上有确界，但其定积分不存在。

$\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i, x_i+1]} \mathcal{Q} (x) · Δx_i = \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} 0 · Δx_i ⇝ 0 ≠ 1 ⇜ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n}  1 · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_i, x_{i+1}]} \mathcal{Q} (x) · Δx_i$

若函数$f (x)$在区间$[X_0, X_1]$上的定积分存在，则函数$f (x)$在区间$[X_0, X_1]$上的断点集为零测集，反之亦然。函数$f (x)$在区间$[X_0, X_1]$上几乎处处连续。

若函数$f (x)$在区间$[X_0, X_1]$上的定积分存在，则函数$f (x)$在区间$[X_0, X_1]$内的任何子区间上的断点集为零测集，因此其定积分存在。

$\left[ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i ⇝ 0 \right] ⇔ \left[  ∀ε,𝜁>0; \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i≥ε} < 𝜁 \right]$

| $⇓$  | $∀ε,𝜁>0;$ | $ε · 𝜁 > \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n w_i · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{w_i · Δx_i}\limits_{w_i<ε} + \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n \mathop{w_i · Δx_i}\limits_{w_i≥ε} ≥ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{w_i · Δx_i}\limits_{w_i≥ε} ≥ ε · \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i≥ε}$ |
| :--: | --------: | :----------------------------------------------------------- |
| $⇓$  | $∀ε,𝜁>0;$ | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i≥ε} < 𝜁 ⇝ 0$ |
| $⇓$  | $∀ε,𝜁>0;$ | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{w_i · Δx_i}\limits_{w_i<ε} + \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{w_i · Δx_i}\limits_{w_i≥ε} ≤ ε · \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i<ε} + \sup\limits f (x) · \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i≥ε} ≤ ε · (X_1 - X_0) + \sup\limits f (x) · 𝜁$ |
| $⇓$  | $∀ε,𝜁>0;$ | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i ⇝ 0$ |

特例：函数$\mathcal{R} (x) \mathop{======}\limits_{m∈ℤ;n∈ℤ^+}^{1 = \gcd (|m|, |n|)} \mathop{\dfrac{1}{n}}\limits_{x=\frac{m}{n}}; \mathop{0}\limits_{x≠\frac{m}{n}}$在区间$[0, 1]$上，任何无理点处连续，任何有理点处不连续，其断点集为零测集，因此其定积分存在。

$\int\limits_{0}^{1} \mathcal{R} (x) \mathrm{d} x = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i,x_{i+1}]} \mathcal{R} (x) · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} 0 · Δx_i ⇝ 0$

若函数$f^{⤨} (x)$在区间$[X_0, X_1]$上单调有确界，则其断点集为零测集，因此其定积分存在。

| $⇓$  | $0 ≤ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i ≤ ε · \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} w_i = ε · \left[ \sup\limits_{x∈[X_0,X_1]} f^{⤨} (x) - \inf\limits_{x∈[X_0,X_1]} f^{⤨} (x) \right]$ |
| :--: | ------------------------------------------------------------ |
| $⇓$  | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i ⇝ 0$ |
| $⇓$  | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i≥ε} ⇝ 0$ |

若函数$f (x)$在区间$[X_0, X_1]$上的定积分存在，则函数$| f (x) |$在区间$[X_0, X_1]$上的定积分存在，其断点集为零测集，反之不对。

若函数$f (x)$以及函数$g (x)$在区间$[X_0, X_1]$上的定积分存在，则函数$f (x) + g (x)$在区间$[X_0, X_1]$上的定积分存在，其断点集为零测集，反之不对。

若函数$f (x)$以及函数$g (x)$在区间$[X_0, X_1]$上的定积分存在，则函数$f (x) - g (x)$在区间$[X_0, X_1]$上的定积分存在，其断点集为零测集，反之不对。

若函数$f (x)$以及函数$g (x)$在区间$[X_0, X_1]$上的定积分存在，则函数$f (x) · g (x)$在区间$[X_0, X_1]$上的定积分存在，其断点集为零测集，反之不对。

若函数$f (x)$以及函数$g (x) ≠ 0$在区间$[X_0, X_1]$上的定积分存在，则函数$\dfrac{f (x)}{g (x)}$在区间$[X_0, X_1]$上的定积分存在，其断点集为零测集，反之不对。

| $⇓$  | $0 ≤ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n \sup\limits_{u,v∈[x_i,x_{i+1}]} || f (u) | - f (v) || · Δx_i ≤ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_i,x_{i+1}]} | f (u) - f (v) | · Δx_i ⇝ 0$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_{i}^{|f|} · Δx_i ⇝ 0$ |
| $⇓$  | $∃ε>0; \left[ w_i^f < ε \right] ⇒ \left[ w_i^{|f|} ≤ w_i^f < ε \right]$ |
| $⇓$  | $∃ε>0; \left[ ε ≤ w_i^{|f|} \right] ⇒ \left[ ε ≤ w_i^{f} \right]$ |
| $⇓$  | $\mathcal{O}^{| f |} ⊆ \mathcal{O}^{f}$                      |
|      |                                                              |
| $⇓$  | $0 ≤ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} | [ f (u) + g (u) ] - [ f (v) + g (v) ] | · Δx_i ≤ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} | f (u) - f (v) | · Δx_i + \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} | g (u) - g (v) | · Δx_i ⇝ 0$ |
| $⇓$  | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i^{f+g} ·Δx_i ⇝ 0$ |
| $⇓$  | $∃ε>0;∃ε^f,ε^g>0; \left[ w_i^f < ε^f \right] ∧ \left[ w_i^g < ε^g \right] ⇒ \left[ w_i^{f+g} ≤ (w_i^f + w_i^g) < ε^f + ε^g = ε \right]$ |
| $⇓$  | $∃ε>0;∃ε^f,ε^g>0; \left[ ε^f + ε^g = ε ≤ w_i^{f+g} \right] ⇒ \left[ ε^f ≤ w_i^{f} \right] ∨ \left[ ε^g ≤ w_i^g \right]$ |
| $⇓$  | $\mathcal{O}^{f+g} ⊆ \mathcal{O}^{f} ∪ \mathcal{O}^g$        |
|      |                                                              |
| $⇓$  | $0 ≤ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} | [ f (u) - g (u) ] - [ f (v) - g (v) ] | · Δx_i ≤ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} | f (u) - f (v) | · Δx_i + \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} | g (u) - g (v) | · Δx_i ⇝ 0$ |
| $⇓$  | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i^{f-g} ·Δx_i ⇝ 0$ |
| $⇓$  | $∃ε>0;∃ε^f,ε^g>0; \left[ w_i^f < ε^f \right] ∧ \left[ w_i^g < ε^g \right] ⇒ \left[ w_i^{f-g} ≤ (w_i^f + w_i^g) < ε^f + ε^g = ε \right]$ |
| $⇓$  | $∃ε>0;∃ε^f,ε^g>0; \left[ ε^f + ε^g = ε ≤ w_i^{f-g} \right] ⇒ \left[ ε^f ≤ w_i^{f} \right] ∨ \left[ ε^g ≤ w_i^g \right]$ |
| $⇓$  | $\mathcal{O}^{f-g} ⊆ \mathcal{O}^{f} ∪ \mathcal{O}^g$        |
|      |                                                              |
| $⇓$  | $\sup\limits_{u,v∈[x_i,x_{i+1}]} | f (u) · g (u) - f (v) · g (v) | ≤ \sup\limits_{u,v∈[x_i,x_{i+1}]} [ | f (u) | · |g (u) - g (v) | + | g (v) | · |f (u) - f (v) | ] ≤ \sup f (x) · \sup\limits_{u,v∈[x_i,x_{i+1}]} | g (u) - g (v) | + \sup g (x) · \sup\limits_{u,v∈[x_i,x_{i+1}]} | f (u) - f (v) |$ |
| $⇓$  | $0 ≤ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_i,x_{i+1}]} | f (u) · g (u) - f (v) · g (v) | · Δx_i ≤ \sup | f(x) | · \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_i,x_{i+1}]} |g (u) - g (v) | · Δx_i + \sup | g (x) | · \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_i,x_{i+1}]} | f (u) - f (v) | · Δx_i ⇝ 0$ |
| $⇓$  | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_{i}^{f·g} · Δx_i ⇝ 0$ |
| $⇓$  | $∃ε>0;∃ε^f,ε^g>0; \left[ w_i^f < ε^f \right] ∧ \left[ w_i^g < ε^g \right] ⇒ \left[ w_i^{f·g} ≤ \left[ \sup f (x) · w_i^g + \sup g (x) · w_i^f \right] < \sup f (x) · ε^f + \sup g (x) · ε^g = ε \right]$ |
| $⇓$  | $∃ε>0;∃ε^f,ε^g>0; \left[ ε ≤ w_i^{f·g} \right] ⇒ \left[ ε^f ≤ w_i^f \right] ∨ \left[ ε^g ≤ w_i^g \right]$ |
| $⇓$  | $\mathcal{O}^{f·g} ⊆ \mathcal{O}^{f} ∪ \mathcal{O}^{g}$      |
|      |                                                              |
| $⇓$  | $\sup\limits_{u,v∈[x_{i},x_{i+1}]} \left| \dfrac{f (u)}{g (u)} - \dfrac{f (v)}{g (v)} \right| = \sup\limits_{u,v∈[x_{i},x_{i+1}]} \left| \dfrac{g (v) · [ f (u)  - f (v) ] - f (v) · [ g (u) - g (v) ]}{g (u) · g (v)} \right| ≤ \dfrac{1}{\inf \left| g (x) \right|} · \sup\limits_{u,v∈[x_{i},x_{i+1}]} | f (u) - f (v) | + \dfrac{\sup | f (x) |}{\inf | g^2 (x) |} · \sup\limits_{u,v∈[x_{i},x_{i+1}]} | g (u) - g (v) |$ |
| $⇓$  | $0 ≤ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} \left| \dfrac{f (u)}{g (u)} - \dfrac{f (v)}{g (v)} \right| · Δx_i ≤ \dfrac{1}{\inf | g (x) |} · \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} | f (u) - f (v) | · Δx_i + \dfrac{\sup | f (x) |}{\inf | g^2 (x) |} · \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} | g (u) - g (v) | · Δx_i ⇝ 0$ |
| $⇓$  | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i^{\frac{f}{g}} · Δx_i ⇝ 0$ |
| $⇓$  | $∃ε>0;∃ε^f,ε^g>0; \left[ w_i^f < ε^f \right] ∧ \left[ w_i^g < ε^g \right] ⇒ \left[ w_i^{\frac{f}{g}} ≤ \left[ \dfrac{1}{\inf | g (x) |} · w_i^f + \dfrac{\sup | f (x) |}{\inf | g^2 (x) |} · w_i^g \right] < \dfrac{1}{\inf | g (x) |} · ε^f + \dfrac{\sup | f (x) |}{\inf | g^2 (x) |} · ε^g = ε \right]$ |
| $⇓$  | $∃ε>0;∃ε^f,ε^g>0; \left[ ε ≤ w_i^{\frac{f}{g}} \right] ⇒ \left[ ε^f ≤ w_i^f \right] ∨ \left[ ε^g ≤ w_i^g \right]$ |
| $⇓$  | $\mathcal{O}^{\frac{f}{g}} ⊆ \mathcal{\mathcal{O}^{f}} ∪ \mathcal{O}^{g}$ |

特例：函数$f (x) = \mathop{1}\limits_{x∈ℚ};\mathop{-1}\limits_{x∉ℚ}$在区间$[0, 1]$上的定积分不存在，其断点集非为零测集。但函数$| f (x) | = 1$在区间$[0, 1]$上的定积分存在。

若函数$f (y)$在区间$[Y_0, Y_1]$上连续，且函数$y = g (x)$在区间$[X_0, X_1]$上的定积分存在，则复合函数$f (g (x))$在区间$[X_0, X_1]$上的定积分存在，其断点集为零测集。

若函数$f (y)$在区间$[Y_0, Y_1]$上的定积分存在，且函数$y = g (x)$在区间$[X_0, X_1]$上连续因此定积分存在，则复合函数$f (g (x))$在区间$[X_0, X_1]$上的定积分未必存在。

若函数$f (y)$在区间$[ Y_0, Y_1 ]$上的定积分存在，且函数$y = g (x)$在区间$[X_0, X_1]$上的定积分存在，则复合函数$f (g (x))$在区间$[X_0, X_1]$上的定积分未必存在。

| $⇓$  |   $∀ε>0;∃δ>0;$ | $∀ε>0;∃δ>0; \sup\limits_{|y-y_0|≤δ} | f (y) - f (y_0) | ≤ ε $ |
| :--: | -------------: | :----------------------------------------------------------- |
| $⇓$  |   $∀ε>0;∃δ>0;$ | $\sup\limits_{|g(x)-g(x_0)|≤δ} | f (g (x)) - f (g (x_0)) | ≤ ε $ |
| $⇓$  |   $∀𝜁>0;∀δ>0;$ | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i^{g}>δ} < 𝜁$ |
| $⇓$  | $∀ε,𝜁>0;∃δ>0;$ | $0 ≤ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} | f (g (u)) - f (g (v)) | · Δx_i = \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} \mathop{| f (g (u)) - f (g (v)) | · Δx_i}\limits_{|g(u)-g(v)|≤w_i^{g}≤δ} + \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} \mathop{| f (g (u)) - f (g (v)) | · Δx_i}\limits_{w_i^g>δ}$ |
| $⇓$  | $∀ε,𝜁>0;∃δ>0;$ | $0 ≤ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} | f (g (u)) - f (g (v)) | · Δx_i < ε · \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i^{g}≤δ} + \mathrm{Sup.} · \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i^{g}>δ} < ε · (X_1 - X_0) + \mathrm{Sup.} · 𝜁 ⇝ 0$ |
| $⇓$  |                | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_{i}^{f∘g} · Δx_i ⇝ 0$ |
|      |                |                                                              |
| $⇓$  |   $∀ε>0;∃δ>0;$ | $\sup\limits_{|g(x)-g(x_0)|≤δ} | f (g (x)) - f (g (x_0)) | ≤ ε $ |
| $⇓$  |   $∃ε>0;∃δ>0;$ | $[ w_i^{g} ≤ δ ] ⇒ [ w_i^{f∘g} ≤ ε ]$                        |
| $⇓$  |   $∃ε>0;∃δ>0;$ | $[ w_i^{f∘g} > ε ] ⇒ [ w_i^{g} > δ ]$                        |
| $⇓$  |                | $\mathcal{O}^{f∘g} ⊆ \mathcal{O}^{g}$                        |

反例：函数$\mathrm{sgn} (y) = \mathop{-1}\limits_{y<0};\mathop{0}\limits_{y=0};\mathop{+1}\limits_{y>0}$在区间$[0, 1]$上的定积分存在，函数$\mathcal{F} (x) ≡ \mathop{I_i - \left| x - X_{i,j} \right|}\limits_{| x - X_{i,j} | < I_{i}}; \mathop{0}\limits_{| x - X_{i,j} | ≥ I_{i}}$在区间$[0, 1]$上连续因此定积分存在。

但复合函数$\mathrm{sgn} (\mathcal{F} (x)) = \mathop{1}\limits_{|x-X_{i,j}|<I_i};\mathop{0}\limits_{|x-X_{i,j}|≥I_i}$在区间$[0, 1]$上的断点集非为零测集，其定积分不存在。

反例：函数$\mathrm{sgn} (y) = \mathop{-1}\limits_{y<0};\mathop{0}\limits_{y=0};\mathop{+1}\limits_{y>0}$在区间$[0, 1]$上的定积分存在，函数$\mathcal{R} (x) \mathop{======}\limits_{m∈ℤ;n∈ℤ^+}^{1 = \gcd (|m|, |n|)} \mathop{\dfrac{1}{n}}\limits_{x=\frac{m}{n}}; \mathop{0}\limits_{x≠\frac{m}{n}}$在区间$[0, 1]$上的定积分存在。

但复合函数$\mathrm{sgn} (\mathcal{R} (x)) = \mathcal{Q} (x) = \mathop{1}\limits_{x∈Q}; \mathop{0}\limits_{x∉Q}$在区间$[0, 1]$上的断点集非为零测集，其定积分不存在。

### 定积分的运算性质

定积分的积分区间下限与积分区间上限对换时，约定定积分的正负性对换。

| $\int\limits_{X_0}^{X_1} f (x) \mathrm{d} x = - \int\limits_{X_1}^{X_0} f (x) \mathrm{d} x$ |      |                                                              |
| :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $\int\limits_{X_0}^{X_0} f (x) \mathrm{d} x = 0$             | $⇐$  | $\int\limits_{X_0}^{X_0} f (x) \mathrm{d} x = - \int\limits_{X_0}^{X_0} f (x) \mathrm{d} x$ |
| $\int\limits_{X_0}^{X_1} f (x) \mathrm{d} x = \int\limits_{X_0}^{X_2} f (x) \mathrm{d} x + \int\limits_{X_2}^{X_1} f (x) \mathrm{d} x$ |      |                                                              |
| $\int\limits_{X_0}^{X_1} \mathrm{Con.} · f (x) \mathrm{d} x = \mathrm{Con.} · \int\limits_{X_0}^{X_1} f (x) \mathrm{d} x$ |      |                                                              |
| $\int\limits_{X_0}^{X_1} [ f (x) + g (x) ] \mathrm{d} x = \int\limits_{X_0}^{X_1} f (x) \mathrm{d} x + \int\limits_{X_0}^{X_1} g (x) \mathrm{d} x$ |      |                                                              |
| $\int\limits_{X_0}^{X_1} [ f (x) - g (x) ] \mathrm{d} x = \int\limits_{X_0}^{X_1} f (x) \mathrm{d} x - \int\limits_{X_0}^{X_1} g (x) \mathrm{d} x$ |      |                                                              |
| $[ f (x) ≤ g (x) ] ⇒ \left[ \int\limits_{X_0}^{X_1} f (x) \mathrm{d} x ≤ \int\limits_{X_0}^{X_1} g (x) \mathrm{d} x \right]$ |      |                                                              |
| $[ 0 ≤ g (x) ] ⇒ \left[ 0 ≤ \int\limits_{X_0}^{X_1} g (x) \mathrm{d} x \right]$ | $⇐$  | $f (x) = 0$                                                  |
| $[ f (x) ≤ g (x) ] ∧ \left[ \lim\limits_{x⇝x_0} f (x) ⇝ f (x_0) < g (x_0) ⇜ \lim\limits_{x⇝x_0} g (x) \right] ⇒ \left[ \int\limits_{X_0}^{X_1} f (x) \mathrm{d} x < \int\limits_{X_0}^{X_1} g (x) \mathrm{d} x \right]$ | $⇐$  | $\left[ \int\limits_{X_0}^{x_0-δ} + \int\limits_{x_0-δ}^{x_0+δ} + \int\limits_{x_0+δ}^{X_1} \right] [ f (x) - g (x) ] \mathrm{d} x < 0$ |
| $[ 0 ≤ g (x) ] ∧ \left[ 0 < g (x_0) ⇜ \lim\limits_{x⇝x_0} g (x) \right] ⇒ \left[ 0 < \int\limits_{X_0}^{X_1} g (x) \mathrm{d} x \right]$ | $⇐$  | $f (x) = 0$                                                  |
| $[ 0 ≤ g (x) ] ∧ \left[ 0 = \int\limits_{X_0}^{X_1} g (x) \mathrm{d} x \right] ⇒ \left[ 0 = g (x_0) ⇜ \lim\limits_{x⇝x_0} g (x) \right]$ | $⇐$  | $[ P ∧ Q ⇒ R ] ⇔ [ P ∧ ¬R ⇒ ¬Q ]$                            |
| $\left| \int\limits_{X_0}^{X_1} f (x) \mathrm{d} x \right| ≤ \int\limits_{X_0}^{X_1} | f (x) | \mathrm{d} x$ | $⇐$  | $- \int\limits_{X_0}^{X_1} | f (x) | \mathrm{d} x ≤ \int\limits_{X_0}^{X_1} f (x) \mathrm{d} x ≤ + \int\limits_{X_0}^{X_1} | f (x) | \mathrm{d} x$ |

### 积分中值定理

错位积和公式。

$\inf F (x) · g^{↘_0} (X_0) ≤ \int\limits_{[X_0,X_1]}^{x} f (θ_{i}) · g^{↘_0} (θ_{i}) · Δx_i ≤ \sup F (x) · g^{↘_0} (X_0)$

$\inf F (x) · g^{↗^0} (X_0) ≥ \int\limits_{[X_0,X_1]}^{x} f (θ_{i}) · g^{↗^0} (θ_{i}) · Δx_i ≥ \sup F (x) · g^{↗^0} (X_0)$

$\inf F (x) · g^{↗_0} (X_1) ≤ \int\limits_{x}^{[X_0,X_1]} f (θ_{i}) · g^{↗_0} (θ_{i}) · Δx_i ≤ \sup F (x) · g^{↗_0} (X_1)$

$\inf F (x) · g^{↘^0} (X_1) ≥ \int\limits_{x}^{[X_0,X_1]} f (θ_{i}) · g^{↘^0} (θ_{i}) · Δx_i ≥ \sup F (x) · g^{↘^0} (X_1)$

| $⇓$  | $F (x) ≡ \int\limits_{X_0}^{x} f (x) \mathrm{d} x \mathop{=======}\limits_{θ_0∈[X_0,X_0+Δx_0]}^{θ_{n}∈[x-Δx_n,x]} \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} f (θ_i) · Δx_i$ |      |                                           |
| :--: | :----------------------------------------------------------- | :--: | :---------------------------------------- |
| $⇓$  | $\sum\limits_{i=n}^{m} f (θ_{i}) · g (θ_{i}) · Δx_i = \sum\limits_{i=n}^{m} [ F (x_{i+1}) - F (x_{i}) ] · g (θ_{i}) = F (x_{m+1}) · g (θ_{m}) + \sum\limits_{i=n}^{m-1} F (x_{i+1}) · g (θ_{i}) - \sum\limits_{i=n}^{m-1} F (x_{i+1}) · g (θ_{i+1}) - F (x_{n}) · g (θ_{n})$ |      |                                           |
| $⇓$  | $\sum\limits_{i=0}^{m} f (θ_{i}) · g (θ_{i}) · Δx_i = [ F (x_{m+1}) · g (θ_{m}) - \rlap{≡≡≡≡≡≡≡}{F (x_{0}) · g (θ_{0})} ] + \sum\limits_{i=0}^{m-1} F (x_{i+1}) · [ g (θ_{i}) - g (θ_{i+1}) ]$ | $⇐$  | $F (x_{0}) ≡ 0$                           |
| $⇓$  | $\sum\limits_{i=0}^{m} f (θ_i) · g^{↘_0} (θ_i) · Δx_i ≤ \sup F (x) · g^{↘_0} (θ_{m}) + \sup F (x) · \sum\limits_{i=0}^{m-1} [ g^{↘_0} (θ_{i}) - g^{↘_0} (θ_{i+1}) ] = \sup F (x) · g^{↘_0} (θ_0)$ | $⇐$  | $g^{↘_0} (θ_{i}) ≥ g^{↘_0} (θ_{i+1}) ≥ 0$ |
| $⇓$  | $\sum\limits_{i=0}^{m} f (θ_i) · g^{↘_0} (θ_i) · Δx_i ≥ \inf F (x) · g^{↘_0} (θ_{m}) + \inf F (x) · \sum\limits_{i=0}^{m-1} [ g^{↘_0} (θ_{i}) - g^{↘_0} (θ_{i+1}) ] = \inf F (x) · g^{↘_0} (θ_{0})$ | $⇐$  | $g^{↘_0} (θ_{i}) ≥ g^{↘_0} (θ_{i+1}) ≥ 0$ |
| $⇓$  | $\inf F (x) · g^{↘_0} (X_0) ≤ \int\limits_{[X_0,X_1]}^{x} f (θ_{i}) · g^{↘_0} (θ_{i}) · Δx_i ≡ \lim\limits_{m⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{m} f (θ_{i}) · g^{↘_0} (θ_{i}) · Δx_i ≤ \sup F (x) · g^{↘_0} (X_0)$ | $⇐$  | $x_0 = X_0$                               |
| $⇓$  | $\inf F (x) · g^{↗^0} (X_0) ≥ \int\limits_{[X_0,X_1]}^{x} f (θ_{i}) · g^{↗^0} (θ_{i}) · Δx_i ≡ \lim\limits_{m⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{m} f (θ_{i}) · g^{↗^0} (θ_{i}) · Δx_i ≥ \sup F (x) · g^{↗^0} (X_0)$ | $⇐$  | $g^{↗^0} (x) ≡ (-1) · h^{↘_0} (x)$        |
|      |                                                              |      |                                           |
| $⇓$  | $F (x) ≡ \int\limits_{x}^{X_1} f (x) \mathrm{d} x \mathop{=======}\limits_{θ_{n}∈[x,x+Δx_n]}^{θ_{0}∈[X_1-Δx_0,X_1]} \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} f (θ_i) · Δx_i$ |      |                                           |
| $⇓$  | $\sum\limits_{i=n}^{m} f (θ_{i}) · g (θ_{i}) · Δx_i = \sum\limits_{i=n}^{m} [ F (x_{i+1}) - F (x_{i}) ] · g (θ_{i}) = F (x_{m+1}) · g (θ_{m}) + \sum\limits_{i=n}^{m-1} F (x_{i+1}) · g (θ_{i}) - \sum\limits_{i=n}^{m-1} F (x_{i+1}) · g (θ_{i+1}) - F (x_{n}) · g (θ_{n})$ |      |                                           |
| $⇓$  | $\sum\limits_{i=0}^{m} f (θ_{i}) · g (θ_{i}) · Δx_i = [ F (x_{m+1}) · g (θ_{m}) - \rlap{≡≡≡≡≡≡≡}{F (x_{0}) · g (θ_{0})} ] + \sum\limits_{i=0}^{m-1} F (x_{i+1}) · [ g (θ_{i}) - g (θ_{i+1}) ]$ | $⇐$  | $F (x_{0}) ≡ 0$                           |
| $⇓$  | $\sum\limits_{i=0}^{m} f (θ_i) · g^{↗_0} (θ_i) · Δx_i ≤ \sup F (x) · g^{↗_0} (θ_{m}) + \sup F (x) · \sum\limits_{i=0}^{m-1} [ g^{↗_0} (θ_{i}) - g^{↗_0} (θ_{i+1}) ] = \sup F (x) · g^{↗_0} (θ_0)$ | $⇐$  | $0 ≤ g^{↗_0} (θ_{i+1}) ≤ g^{↗_0} (θ_{i})$ |
| $⇓$  | $\sum\limits_{i=0}^{m} f (θ_i) · g^{↗_0} (θ_i) · Δx_i ≥ \inf F (x) · g^{↗_0} (θ_{m}) + \inf F (x) · \sum\limits_{i=0}^{m-1} [ g^{↗_0} (θ_{i}) - g^{↗_0} (θ_{i+1}) ] = \inf F (x) · g^{↗_0} (θ_0)$ | $⇐$  | $0 ≤ g^{↗_0} (θ_{i+1}) ≤ g^{↗_0} (θ_{i})$ |
| $⇓$  | $\inf F (x) · g^{↗_0} (X_1) ≤ \int\limits_{x}^{[X_0,X_1]} f (θ_{i}) · g^{↗_0} (θ_{i}) · Δx_i ≡ \lim\limits_{m⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{m} f (θ_i) · g^{↗_0} (θ_i) · Δx_i ≤ \sup F (x) · g^{↗_0} (X_1)$ | $⇐$  | $x_0 = X_1$                               |
| $⇓$  | $\inf F (x) · g^{↘^0} (X_1) ≥ \int\limits_{x}^{[X_0,X_1]} f (θ_{i}) · g^{↘^0} (θ_{i}) · Δx_i ≡ \lim\limits_{m⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{m} f (θ_i) · g^{↘^0} (θ_i) · Δx_i ≥ \sup F (x) · g^{↘^0} (X_1)$ | $⇐$  | $g^{↘^0} (x) ≡ (-1) · h^{↗_0} (x)$        |

若函数$f (x)$在区间$[X_0, X_1]$上连续，函数$g (x)$在区间$[X_0, X_1]$上连续，则必至少存在一点$θ∈(X_0, X_1)$使得成立。

$\int\limits_{X_0}^{X_1} f (x) · g (x) \mathrm{d} x = \left. f (x) \right|_{∃θ∈(X_0, X_1)} · \int\limits_{X_0}^{X_1} g (x) \mathrm{d} x$

$\int\limits_{X_0}^{X_1} f (x) \mathrm{d} x = \left. f (x) \right|_{∃θ∈[X_0, X_1]} · (X_1 - X_0)$

| $⇓$  | $F (x) ≡ \int\limits_{X_0}^{x} f (x) · g (x) \mathrm{d} x$   | $⇒$  | $F (X_0) = 0; F (X_1) = \int\limits_{X_0}^{X_1} f (x) · g (x) \mathrm{d} x$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $G (x) ≡ \int\limits_{X_0}^{x} g (x) \mathrm{d} x$           | $⇒$  | $G (X_0) = 0; G (X_1) = \int\limits_{X_0}^{X_1} g (x) \mathrm{d} x$ |
| $⇓$  | $\dfrac{\int\limits_{X_0}^{X_1} f (x) · g (x) \mathrm{d} x}{\int\limits_{X_0}^{X_1} g (x) \mathrm{d} x} = \dfrac{F (X_1) - F (X_0)}{G (X_1) - G (X_0)} = \left. \dfrac{\mathrm{d} F (x)}{\mathrm{d} G (x)} \right|_{∃θ∈[X_0, X_1]} = \left. \dfrac{f (x) · g (x)}{g (x)} \right|_{∃θ∈[X_0, X_1]} = \left. f (x) \right|_{∃θ∈[X_0, X_1]}$ |      |                                                              |
| $⇓$  | $\int\limits_{X_0}^{X_1} f (x) · g (x) \mathrm{d} x = \left. f (x) \right|_{∃θ∈[X_0, X_1]} · \int\limits_{X_0}^{X_1} g (x) \mathrm{d} x$ |      |                                                              |
| $⇓$  | $\int\limits_{X_0}^{X_1} f (x) \mathrm{d} x = \left. f (x) \right|_{∃θ∈[X_0, X_1]} · (X_1 - X_0)$ | $⇐$  | $g (x) ≡ 1$                                                  |

若函数$f^{⤨} (x)$在区间$[X_0, X_1]$上连续且单调，函数$g (x)$在区间$[X_0, X_1]$上连续，则必至少存在一点$θ∈[X_0, X_1]$使得成立。

$\int\limits_{X_0}^{X_1} f (x) · g^{↘_0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[X_0,X_1]} g^{↘_0} (X_0) · \int\limits_{X_0}^{θ} f (x) \mathrm{d} x$

$\int\limits_{X_0}^{X_1} f (x) · g^{↗^0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[X_0,X_1]} g^{↗^0} (X_0) · \int\limits_{X_0}^{θ} f (x) \mathrm{d} x$

$\int\limits_{X_0}^{X_1} f (x) · g^{↗_0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[X_0,X_1]} g^{↗_0} (X_1) · \int\limits_{θ}^{X_1} f (x) \mathrm{d} x$

$\int\limits_{X_0}^{X_1} f (x) · g^{↘^0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[X_0,X_1]} g^{↘^0} (X_1) · \int\limits_{θ}^{X_1} f (x) \mathrm{d} x$

$\int\limits_{X_0}^{X_1} f (x) · g^{⤨} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[X_0,X_1]} g^{⤨} (X_0) · \int\limits_{X_0}^{θ} f (x) \mathrm{d} x + g^{⤨} (X_1) · \int\limits_{θ}^{X_1} f (x) \mathrm{d} x$

| $⇓$  |                                                              |      | $∀F (x)∈[\inf F (x), \sup F (x)];∃θ∈[X_0,X_1]; F (x) = F (θ)$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\int\limits_{X_0}^{X_1} f (x) · g^{↘_0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[X_0,X_1]} g^{↘_0} (X_0) · \int\limits_{X_0}^{θ} f (x) \mathrm{d} x$ | $⇐$  | $\inf F (x) · g^{↘_0} (X_0) ≤ \int\limits_{[X_0,X_1]}^{x} f (θ_{i}) · g^{↘_0} (θ_{i}) · Δx_i ≤ \sup F (x) · g^{↘_0} (X_0)$ |
| $⇓$  | $\int\limits_{X_0}^{X_1} f (x) · g^{↗^0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[X_0,X_1]} g^{↗^0} (X_0) · \int\limits_{X_0}^{θ} f (x) \mathrm{d} x$ | $⇐$  | $\inf F (x) · g^{↗^0} (X_0) ≥ \int\limits_{[X_0,X_1]}^{x} f (θ_{i}) · g^{↗^0} (θ_{i}) · Δx_i ≥ \sup F (x) · g^{↗^0} (X_0)$ |
| $⇓$  | $\int\limits_{X_0}^{X_1} f (x) · g^{↗_0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[X_0,X_1]} g^{↗_0} (X_1) · \int\limits_{θ}^{X_1} f (x) \mathrm{d} x$ | $⇐$  | $\inf F (x) · g^{↗_0} (X_1) ≤ \int\limits_{x}^{[X_0,X_1]} f (θ_{i}) · g^{↗_0} (θ_{i}) · Δx_i ≤ \sup F (x) · g^{↗_0} (X_1)$ |
| $⇓$  | $\int\limits_{X_0}^{X_1} f (x) · g^{↘^0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[X_0,X_1]} g^{↘^0} (X_1) · \int\limits_{θ}^{X_1} f (x) \mathrm{d} x$ | $⇐$  | $\inf F (x) · g^{↘^0} (X_1) ≥ \int\limits_{x}^{[X_0,X_1]} f (θ_{i}) · g^{↘^0} (θ_{i}) · Δx_i ≥ \sup F (x) · g^{↘^0} (X_1)$ |
|      |                                                              |      |                                                              |
| $⇓$  | $h^{↘_0} (x) ≡ \dfrac{g^{⤨} (x) - g^{⤨} (X_1)}{g^{⤨} (X_0) - g^{⤨} (X_1)}$ | $⇒$  | $\int\limits_{X_0}^{X_1} h^{↘_0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[X_0,X_1]} h^{↘_0} (X_0) · \int\limits_{X_0}^{θ} f (x) \mathrm{d} x$ |
| $⇓$  | $\int\limits_{X_0}^{X_1} f (x) · \dfrac{g^{⤨} (x) - g^{⤨} (X_1)}{g^{⤨} (X_0) - g^{⤨} (X_1)} \mathrm{d} x \mathop{=====}\limits^{∃θ∈[X_0,X_1]} 1 ·  \int\limits_{X_0}^{θ} f (x) \mathrm{d} x$ | $⇐$  | $h^{↘_0} (X_0) = 1$                                          |
| $⇓$  | $\int\limits_{X_0}^{X_1} f (x) · g^{⤨} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[X_0,X_1]} g^{⤨} (X_0) · \int\limits_{X_0}^{θ} f (x) \mathrm{d} x + g^{⤨} (X_1) · \int\limits_{θ}^{X_1} f (x) \mathrm{d} x$ |      |                                                              |

###

