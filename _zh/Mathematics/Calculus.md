---
layout:  zh_post
Topic :  收敛极限
Title :  微积分
Update:  2021-08-05T10:48:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 约定

$\lim\limits_{x⇝x_0 \\ y⇝y_0}$表示$x⇝x_0$与$y⇝y_0$各自独立发生，极限符号同侧的两个极限过程同时发生。

$\lim\limits_{n⇝∞^{+} }^{Δx⇝0}$表示因为$Δx⇝0$而导致$n⇝∞^{+}$，极限符号上下的两个极限过程同时发生。

$\lim\limits_{y⇝y_0} \lim\limits_{x⇝x_0}$表示$x⇝x_0$领先于$y⇝y_0$发生，两个极限符号的极限过程并非同时发生。

### 极值点

任意实数的绝对值，为其与实数轴上原点之间的距离。

| $|x - x_0| ≤ δ$  | $x - x_0 ∈ [-δ, 0⁻] ∪ [0⁺, +δ]$ | $[-δ ≤ x - x_0 ≤ 0⁻] ∨ [ 0⁺ ≤ x - x_0 ≤ +δ]$ | $[-δ ≤ x - x_0] ∧ [x - x_0 ≤ +δ]$ |
| :--------------- | :------------------------------ | :------------------------------------------- | :-------------------------------- |
| $|x - x_0 | ≥ δ$ | $x - x_0 ∈ [∞⁻, -δ] ∪ [+δ, ∞⁺]$ | $[∞⁻ ≤ x - x_0 ≤ -δ] ∨ [+δ ≤ x - x_0 ≤ ∞⁺]$  | $[x - x_0 ≤ -δ] ∨ [x - x_0 ≥ +δ]$ |

无穷大可视为扩充的实数轴上向其两端无穷远处延伸出的一点，扩充的实数轴在其两端的无穷大点处形成封闭的圆环，实数轴上除无穷大点外均按线性序排列。

无穷大的绝对值为正无穷大，负无穷大与正无穷大互为相反数。但在通常意义中，不考虑扩充的实数轴以及无穷大点，而视实数轴为以原点为中点的直线数轴。

无穷大点与原点连线将实数轴划分为负半实数轴与正半实数轴，负无穷大可视为从负半实数轴趋近于无穷大点，正无穷大可视为从正半实数轴趋近于无穷大点。

|   无穷大 | $∞$  |            | $\dfrac{1}{0} = ∞$   | $\dfrac{1}{∞} = 0$   | $\lim\limits_{n⇝∞⁺} (-1)^n · n ⇝ ∞$ | $x_0 + ∞ \mathop{=}\limits_{x_0≠∞} ∞$    | $x_0 - ∞ \mathop{=}\limits_{x_0≠∞} ∞$    | $(+|x_0|) · ∞ \mathop{=}\limits_{x_0≠0} ∞$   | $(-|x_0|) · ∞ \mathop{=}\limits_{x_0≠0} ∞$   |
| -------: | :--- | :--------- | :------------------- | :------------------- | :---------------------------------- | :--------------------------------------- | :--------------------------------------- | :------------------------------------------- | :------------------------------------------- |
| 正无穷大 | $∞⁺$ | $|∞| = ∞⁺$ | $\dfrac{1}{0⁺} = ∞⁺$ | $\dfrac{1}{∞⁺} = 0⁺$ | $\lim\limits_{n⇝∞⁺} (+1) · n ⇝ ∞⁺$  | $x_0 + ∞⁺ \mathop{=}\limits_{x_0≠∞⁻} ∞⁺$ | $x_0 - ∞⁺ \mathop{=}\limits_{x_0≠∞⁺} ∞⁻$ | $(+|x_0|) · ∞⁺ \mathop{=}\limits_{x_0≠0} ∞⁺$ | $(-|x_0|) · ∞⁺ \mathop{=}\limits_{x_0≠0} ∞⁻$ |
| 负无穷大 | $∞⁻$ | $∞⁻ = -∞⁺$ | $\dfrac{1}{0⁻} = ∞⁻$ | $\dfrac{1}{∞⁻} = 0⁻$ | $\lim\limits_{n⇝∞⁺} (-1) · n ⇝ ∞⁻$  | $x_0 + ∞⁻ \mathop{=}\limits_{x_0≠∞⁺} ∞⁻$ | $x_0 - ∞⁻ \mathop{=}\limits_{x_0≠∞⁻} ∞⁺$ | $(+|x_0|) · ∞⁻ \mathop{=}\limits_{x_0≠0} ∞⁻$ | $(-|x_0|) · ∞⁻ \mathop{=}\limits_{x_0≠0} ∞⁺$ |

点$x_0$的闭邻域$\mathrm{B}_{X}(x_0, δ)$由属于区域$X$中的点构成，点$x_0$未必属于区域$X$。点$x_0$的任意闭邻域$\mathrm{B}_{X}(x_0,δ)$与其对应的补邻域$\mathrm{B}_{X}^{¬}(x_0,δ)$之间没有交集。

孤立点是离散性质，聚敛点是极限性质。边界点要么为孤立点，要么为聚敛点。区域$X$的闭包集$\fbox{X}$由区域$X$本身以及其所有边界点共同构成。

最大值与最小值是全局性质与离散性质，极大值与极小值是局部性质与离散性质，上确界与下确界是极限性质与连续性质以及线性序性质。

上确界是所有上界的最小值，下确界是所有下界的最大值。上确界与下确界始终存在且唯一确定，因此上极限与下极限始终存在且唯一确定。

|   左闭邻域 | $\mathrm{B}_{X}(x_0^{-},δ)$           | $∀x∈X; [x∈\mathrm{B}_{X}(x_0^{-}, δ)] ⇔ [-δ ≤ x-x_0 ≤ 0]$    |                                                              |
| ---------: | :------------------------------------ | ------------------------------------------------------------ | :----------------------------------------------------------- |
|   右闭领域 | $\mathrm{B}_{X}(x_0^{+},δ)$           | $∀x∈X; [x∈\mathrm{B}_{X}(x_0^{+}, δ)] ⇔ [0 ≤ x-x_0 ≤ +δ]$    |                                                              |
|     闭邻域 | $\mathrm{B}_{X}(x_0, δ)$              | $∀x∈X; [ x∈\mathrm{B}_{X}(x_0, δ) ] ⇔ [ | x - x_0 | ≤ δ ]$   | $\mathrm{B}_{X}(x_0,δ) ⋂ \mathrm{B}_{X}^{¬}(x_0,δ) = 𝟘$      |
|     补邻域 | $\mathrm{B}_{X}^{¬}(x_0,δ)$           | $∀x∉X; [x∈\mathrm{B}_{X}^{¬}(x_0, δ)] ⇔ [|x-x_0|≤δ]$         | $\mathrm{B}_{X}(x_0,δ) ⋃ \mathrm{B}_{X}^{¬}(x_0,δ) = \mathrm{B}_{𝟙}(x_0,δ)$ |
| 去心闭邻域 | $\mathrm{\mathop{B} }_{X}^{∘}(x_0, δ)$ | $∀x∈X; [x∈\mathrm{\mathop{B} }_{X}^{∘}(x_0, δ) ] ⇔ [0 < |x - x_0| ≤ δ]$ |                                                              |
|     闭包集 | $\fbox{X}$                            | $∀x_0; \left[ x_0∈\fbox{X} \right] ⇔ [ ∀δ>0; \mathrm{B}_{X}(x_0, δ) ≠ 𝟘 ]$ | $\fbox{X}⊇X$                                                 |
|     聚敛点 | $x_0∈\fbox{X}$                        | $∀δ>0; \mathrm{B}_{X}(x_0, δ) ≠ 𝟘$                           |                                                              |
|     孤立点 | $x_0∈X$                               | $∃δ>0; \mathrm{B}_{X}(x_0, δ) = \lbrace x_0 \rbrace$         |                                                              |
|     边界点 | $x_0∈\fbox{X}$                        | $∀δ>0; [ \mathrm{B}_{X}(x_0,δ) ≠ 𝟘 ] ∧ [ \mathrm{B}_{X}^{¬}(x_0,δ) ≠ 𝟘 ]$ |                                                              |
|     内敛点 | $x_0∈X$                               | $∃δ>0; \mathrm{B}_{X}(x_0, δ) ⊆ X$                           |                                                              |
|   全闭区域 | $[x_α, x_β]$                          | $[∀δ>0; \mathrm{B}(x_α, δ) ≠ 𝟘] ∧ [∀δ>0; \mathrm{B}(x_β, δ) ≠ 𝟘]$ | $X = \fbox{X}$                                               |
|   全开区域 | $(x_α, x_β)$                          | $[∀δ>0; \mathrm{B}(x_α, δ) ≠ 𝟘] ∧ [∀δ>0; \mathrm{B}(x_β, δ) ≠ 𝟘]$ | $X ≠ \fbox{X}$                                               |
|   半闭区域 | $[x_α, x_β)$                          | $x_α∈[x_α,x_β) ∧ x_β∉[x_α,x_β)$                              | $X ≠ \fbox{X}$                                               |
|   半闭区域 | $(x_α, x_β]$                          | $x_α∉(x_α,x_β] ∧ x_β∈(x_α,x_β]$                              | $X ≠ \fbox{X}$                                               |
|            |                                       |                                                              |                                                              |
|     最大值 | $m ≡ \max\limits_{m∈S} S$             | $[ ∃m∈S;∀a∈S; m ≥ a ] ⇔ [ ∃m∈S;∀a∈S; m ≤ a ⇒ m = a ]$        | 集合$S$为离散集                                              |
|     最小值 | $m ≡ \min\limits_{m∈S} S$             | $[ ∃m∈S;∀a∈S; m ≤ a ] ⇔ [ ∃m∈S;∀a∈S; m ≥ a ⇒ m = a ]$        | 集合$S$为离散集                                              |
|     极大值 | $m ≡ \max\limits_{m∈S⊆T} S$           | $[ ∃m∈S;∀a∈S; m ≥ a ] ⇔ [ ∃m∈S;∀a∈S; m ≤ a ⇒ m = a ]$        | 集合$S$为集合$T$的子集                                       |
|     极小值 | $m ≡ \min\limits_{m∈S⊆T} S$           | $[ ∃m∈S;∀a∈S; m ≤ a ] ⇔ [ ∃m∈S;∀a∈S; m ≥ a ⇒ m = a ]$        | 集合$S$为集合$T$的子集                                       |
|     上确界 | $s ≡ \sup S$                          | $[ ∃s∈\fbox{S};∀a∈S; a ≤ s ] ⇔ [∃s;∀o;∀a∈S; a ≤ s ∧ [a ≤ o ⇒ s ≤ o]]$ | 集合$S$可为紧致集                                            |
|     上确界 | $s ≡ \sup S$                          | $[ ∃s;∀a∈S;∃e∈S; a ≤ s ∧ [ a < s ⇒ a < e ] ] ⇔ [ ∃s;∀a∈S;∀ε>0;∃e∈S; a ≤ s ∧ s - ε < e]$ | 集合$S$可为紧致集                                            |
|     下确界 | $s ≡ \inf S$                          | $[ ∃s∈\fbox{S};∀a∈S; a ≥ s ] ⇔ [∃s;∀o;∀a∈S; a ≥ s ∧ [a ≥ o ⇒ s ≥ o]]$ | 集合$S$可为紧致集                                            |
|     下确界 | $s ≡ \inf S$                          | $[ ∃s;∀a∈S;∃e∈S; a ≥ s ∧ [ a > s ⇒ a > e ] ] ⇔ [ ∃s;∀a∈S;∀ε>0;∃e∈S; a ≥ s ∧ s + ε > e]$ | 集合$S$可为紧致集                                            |
| 严格最大值 | $m ≡ \max\limits_{m∈S} S$             | $[ ∃m∈S;∀a∈S \backslash m; m > a ]$                          |                                                              |
| 严格最小值 | $m ≡ \min\limits_{m∈S} S$             | $[ ∃m∈S;∀a∈S \backslash m; m < a ]$                          |                                                              |
| 严格极大值 | $m ≡ \max\limits_{m∈S⊆T} S$           | $[ ∃m∈S;∀a∈S \backslash m; m > a ]$                          |                                                              |
| 严格极小值 | $m ≡ \min\limits_{m∈S⊆T} S$           | $[ ∃m∈S;∀a∈S \backslash m; m < a ]$                          |                                                              |


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
|   左侧函数值 | $f(x_0-Δ)$                                                   |                                                              |
|   右侧函数值 | $f(x_0+Δ)$                                                   |                                                              |
|   函数左极限 | $f(x)|_{x_0^{-} } ≡ \lim\limits_{x⇝x_0^-} f(x) ⇝ f_{x_0^-}$   | $Ⅎx_0∈\fbox{X};∀ε>0;∃δ>0;∀x∈X; -δ ≤ x - x_0 < 0 ⇒ |f(x) - f_{x_0^-}| ≤ ε$ |
|   函数右极限 | $f(x)|_{x_0^{+} } ≡ \lim\limits_{x⇝x_0^+} f(x) ⇝ f_{x_0^+}$   | $Ⅎx_0∈\fbox{X};∀ε>0;∃δ>0;∀x∈X; 0 < x - x_0 ≤ +δ ⇒ |f(x) - f_{x_0^+}| ≤ ε$ |
|   函数极限值 | $f(x)|_{x_0} ≡ \lim\limits_{x⇝x_0} f(x) ⇝ f_{x_0}$           | $Ⅎx_0∈\fbox{X};∀ε>0;∃δ>0;∀x∈\mathrm{\mathop{B} }^{∘}(x_0,δ); |f(x) - f_{x_0}| ≤ ε$ |
|   函数极限值 | $f(x)|_{x_0} ≡ \lim\limits_{x⇝x_0} f(x) ⇝ f_{x_0}$           | $\lim\limits_{x⇝x_0^-} f(x) ⇝ f_{x_0^-} = f_{x_0} = f_{x_0^+} ⇜ \lim\limits_{x⇝x_0^+} f(x)$ |
|       极限值 | $\lim\limits_{x⇝x_0} f(x) ⇝ ∞^{±},∞$                         | $\lim\limits_{x⇝x_0} \dfrac{1}{f(x)} ⇝ 0^{±},0$              |
|       极限值 | $\lim\limits_{x⇝∞^{±},∞} f(x) ⇝ f_{∞^{±} }$                   | $\lim\limits_{\frac{1}{x}⇝0^{±},0} f(x) ⇝ f_{∞^{±} }$         |
|       上极限 | $\varlimsup\limits_{x⇝x_0} f (x)$                            | $\lim\limits_{δ⇝0} \sup\limits_{x∈\mathrm{\mathop{B} }^{∘}(x_0,δ)} f(x)$ |
|       下极限 | $\varliminf\limits_{x⇝x_0} f (x)$                            | $\lim\limits_{δ⇝0} \inf\limits_{x∈\mathrm{B}^{∘}(x_0,δ)} f(x)$ |
|   唯一极限值 | $\varliminf\limits_{x⇝x_0} f(x) = \varlimsup\limits_{x⇝x_0} f(x)$ | $\lim\limits_{δ⇝0} \inf\limits_{x∈\mathrm{B}^{∘}(x_0,δ)} f(x) = \lim\limits_{δ⇝0} \sup\limits_{x∈\mathrm{B}^{∘}(x_0,δ)} f(x)$ |
|              |                                                              |                                                              |
|     单调递增 | $f^{↗} (x)$                                                  | $[∀x_1,x_2∈X; [ x_1 < x_2 ] ⇒ [ f^{↗} (x_1) ≤ f^{↗} (x_2)]]$ |
|     单调递减 | $f^{↘} (x)$                                                  | $[∀x_1,x_2∈X; [ x_1 < x_2 ] ⇒ [ f^{↘} (x_1) ≥ f^{↘} (x_2)]]$ |
| 严格单调递增 | $f^{↑} (x)$                                                  | $[∀x_1,x_2∈X; [ x_1 < x_2 ] ⇒ [ f^{↑} (x_1) < f^{↑} (x_2)]]$ |
| 严格单调递减 | $f^{↓} (x)$                                                  | $[∀x_1,x_2∈X; [ x_1 < x_2 ] ⇒ [ f^{↓} (x_1) > f^{↓} (x_2)]]$ |

|           $∀x∈[x_α, x_β]; | f (x) | ≤ ε$ | $⇔$  | $\sup\limits_{x∈[x_α,x_β]} | f (x) | ≤ ε$ |                                                   |         $∃x∈[x_α, x_β]; | f (x) | > ε$ | $⇔$  | $\sup\limits_{x∈[x_α,x_β]} | f (x) | > ε$ |
| --------------------------------------------: | :--: | :-------------------------------------------- | :-----------------------------------------------: | --------------------------------------------: | :--: | :-------------------------------------------- |
|         $∀x∈[x_α,x_β]; | f (x) | < ε$ | $⇔$  | $\sup\limits_{x∈[x_α,x_β]} | f (x) | < ε$ |                                                   |          $∃x∈[x_α,x_β]; | f (x) | ≥ ε$ | $⇔$  | $\sup\limits_{x∈[x_α,x_β]} | f (x) | ≥ ε$ |
|          $∀x∈(x_α,x_β); | f (x) | ≤ ε$ | $⇔$  | $\sup\limits_{x∈(x_α,x_β)} | f (x) | ≤ ε$ |                                                   |          $∃x∈(x_α,x_β); | f (x) | > ε$ | $⇔$  | $\sup\limits_{x∈(x_α,x_β)} | f (x) | > ε$ |
|          $∀x∈(x_α,x_β); | f (x) | < ε$ | $⇒$  | $\sup\limits_{x∈(x_α,x_β)} | f (x) | ≤ ε$ | $\rlap{≡≡≡≡≡≡≡≡≡}\sup\limits_{x⇝x_α} |f (x)| = ε$ |          $∃x∈(x_α,x_β); |f(x)| ≥ ε$ | $⇒$  | $\sup\limits_{x∈(x_α,x_β)} | f (x) | ≥ ε$ |
|                                               |      |                                               |                                                   |                                               |      |                                               |
|                                             $∀x∈[x_α,x_β]; |f(x)| ≥ ε$ |  $⇔$    |  $\inf\limits_{x∈[x_α,x_β]} |f(x)| ≥ ε$                                             |                                                   | $∃x∈[x_α,x_β]; |f(x)| < ε$ |  $⇔$    |  $\inf\limits_{x∈[x_α,x_β]} |f(x)| < ε$                                             |
| $∀x∈[x_α,x_β]; |f(x)| > ε$ |  $⇔$    |   $\inf\limits_{x∈[x_α,x_β]} |f(x)| > ε$                                            |                                                   | $∃x∈[x_α,x_β]; |f(x)| ≤ ε$ |   $⇔$   |   $\inf\limits_{x∈[x_α,x_β]} |f(x)| ≤ ε$                                            |
| $∀x∈(x_α,x_β); |f(x)| ≥ ε$ |   $⇔$   | $\inf\limits_{x∈(x_α,x_β)} |f(x)| ≥ ε$                                              |                                                   | $∃x∈(x_α,x_β); |f(x)| < ε$ |  $⇔$    |     $\inf\limits_{x∈(x_α,x_β)} |f(x)| < ε$                                          |
| $∀x∈(x_α,x_β); |f(x)| > ε$ |$⇒$ |$\inf\limits_{x∈(x_α,x_β)} |f(x)| ≥ ε$ | $\rlap{≡≡≡≡≡≡≡≡}{\inf\limits_{x⇝x_α} |f(x)| = ε}$| $∃x∈(x_α,x_β); |f(x)| ≤ ε$ |$⇒$ | $\inf\limits_{x∈(x_α,x_β)} |f(x)| ≤ ε$|
| | | | | | | |
| $\sup\limits_{|x-x_t|≤δ} |f(x) - f(x_t)| ≤ ε$ | $⇔$  | $\sup\limits_{|f(x)-f(x_t)|≤ε} |x - x_t| > δ$ |                                                   | $\sup\limits_{|x-x_t|≤δ} |f(x) - f(x_t)| > ε$ | $⇔$  | $\sup\limits_{|f(x)-f(x_t)|≤ε} |x - x_t| ≤ δ$ |

上确界与下确界的运算性质。

$\inf\limits_{x∈Y⊇X} f(x) ≤ \inf\limits_{x∈X} f(x) ≤ \sup\limits_{x∈X} f(x) ≤ \sup\limits_{x∈Y⊇X} f(x)$

$\sup\limits_{x∈X} f(x) = -\inf\limits_{x∈X} [-f(x)]$

$\inf\limits_{x∈X} f(x) = -\sup\limits_{x∈X} [-f(x)]$

$\sup\limits_{x∈X} [f(x) + g(x)] ≤ \sup\limits_{x∈X} f(x) + \sup\limits_{x∈X} g(x)$

$\inf\limits_{x∈X} [f(x) + g(x)] ≥ \inf\limits_{x∈X} f(x) + \inf\limits_{x∈X} g(x)$

$\varlimsup\limits_{x⇝x_0} [f(x) + g(x)] ≤ \varlimsup\limits_{x⇝x_0} f(x) + \varlimsup\limits_{x⇝x_0} g(x)$

$\varliminf\limits_{x⇝x_0} [f(x) + g(x)] ≥ \varliminf\limits_{x⇝x_0} f(x) + \varliminf\limits_{x⇝x_0} g(x)$

| $∀x∈X; f(x) ≤ \sup\limits_{x∈X} f(x)$ | $∀x∈X; -f(x) ≥ -\sup\limits_{x∈X} f(x)$                      | $\inf\limits_{x∈X} [-f(x)] = -\sup\limits_{x∈X} f(x)$        | $\sup\limits_{x∈X} f(x) = -\inf\limits_{x∈X} [-f(x)]$        |
| :------------------------------------ | :----------------------------------------------------------- | :----------------------------------------------------------- | ------------------------------------------------------------ |
| $∀x∈X; f(x) ≥ \inf\limits_{x∈X} f(x)$ | $∀x∈X; -f(x) ≤ -\inf\limits_{x∈X} f(x)$                      | $\sup\limits_{x∈X} [-f(x)] = -\inf\limits_{x∈X} f(x)$        | $\inf\limits_{x∈X} f(x) = -\sup\limits_{x∈X} [-f(x)]$        |
| $∀x∈X; f(x) ≤ \sup\limits_{x∈X} f(x)$ | $∀x∈X; [f(x) + g(x)] ≤ \sup\limits_{x∈X} f(x) + \sup\limits_{x∈X} g(x)$ | $\sup\limits_{x∈X} [f(x) + g(x)] ≤ \sup\limits_{x∈X} f(x) + \sup\limits_{x∈X} g(x)$ | $\varlimsup\limits_{x⇝x_0} [f(x) + g(x)] ≤ \varlimsup\limits_{x⇝x_0} f(x) + \varlimsup\limits_{x⇝x_0} g(x)$ |
| $∀x∈X; f(x) ≥ \inf\limits_{x∈X} f(x)$ | $∀x∈X; [f(x) + g(x)] ≥ \inf\limits_{x∈X} f(x) + \inf\limits_{x∈X} g(x)$ | $\inf\limits_{x∈X} [f(x) + g(x)] ≥ \inf\limits_{x∈X} f(x) + \inf\limits_{x∈X} g(x)$ | $\varliminf\limits_{x⇝x_0} [f(x) + g(x)] ≥ \varliminf\limits_{x⇝x_0} f(x) + \varliminf\limits_{x⇝x_0} g(x)$ |

典例：函数$f (x) = \sin x$在区间$\left( 0, \dfrac{π}{2} \right)$上的取值范围为$0 < f (x) < 1$，其下确界为$0$，其上确界为$1$。

典例：函数$f (x) = \dfrac{1}{x}$在区间$(0, ∞⁺)$上的取值范围为$0 < f (x)$，其下确界为$0$，其上确界为$∞⁺$。

典例：函数$f(x) = \sin x$在区间$(0, π)$上的下确界为$-1$且上确界为$+1$，函数$g(x) = -\sin x$在区间$(0, π)$上的下确界为$-1$且上确界为$+1$，函数$f(x) + g(x)$在区间$(0, π)$上为$0$。

函数极限的运算性质，若$\lim\limits_{x⇝x_0} f(x) ⇝ f_{x_0}$，且$\lim\limits_{x⇝x_0} g(x) ⇝ g_{x_0}$。

$\lim\limits_{x⇝x_0} [f(x) + g(x)] = \lim\limits_{x⇝x_0} f(x) + \lim\limits_{x⇝x_0} g(x) ⇝ f_{x_0} + g_{x_0}$

$\lim\limits_{x⇝x_0} [f(x) - g(x)] = \lim\limits_{x⇝x_0} f(x) - \lim\limits_{x⇝x_0} g(x) ⇝ f_{x_0} - g_{x_0}$

$\lim\limits_{x⇝x_0} [f(x) · g(x)] = \lim\limits_{x⇝x_0} f(x) · \lim\limits_{x⇝x_0} g(x) ⇝ f_{x_0} · g_{x_0}$

$\lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} = \dfrac{\lim\limits_{x⇝x_0} f(x)}{\lim\limits_{x⇝x_0} g(x)} \mathop{⇝}\limits_{g_{x_0}≠0} \dfrac{f_{x_0} }{g_{x_0} }$

$\lim\limits_{x⇝x_0} \mathrm{Con} · f(x) = \mathrm{Con} · \lim\limits_{x⇝x_0} f(x) ⇝ \mathrm{Con} · f_{x_0}$

| $⇓$  | $[∀ε_1>0;∃δ_1>0; ∀x∈\mathrm{B}^{∘}(x_0,δ_1); |f(x) - f_{x_0}| ≤ ε_1] ∧ [∀ε_2>0;∃δ_2>0; ∀x∈\mathrm{B}^{∘}(x_0,δ_2); |g(x) - g_{x_0}| ≤ ε_2]$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε>0;∃δ=\min\lbrace δ_1,δ_2 \rbrace;∀x∈\mathrm{B}^{∘}(x_0,δ); |[f(x) + g(x)] - [f_{x_0} + g_{x_0}]| ≤ |f(x) - f_{x_0}| + |g(x) - g_{x_0}| = ε_1 + ε_2 = ε$ |
| $⇓$  | $∀ε>0;∃δ=\min\lbrace δ_1,δ_2 \rbrace;∀x∈\mathrm{B}^{∘}(x_0,δ); |[f(x) - g(x)] - [f_{x_0} - g_{x_0}]| ≤ |f(x) - f_{x_0}| + |g(x) - g_{x_0}| = ε_1 + ε_2 = ε$ |
| $⇓$  | $∀ε>0;∃δ=\min\lbrace δ_1,δ_2 \rbrace;∀x∈\mathrm{B}^{∘}(x_0,δ); |f(x) · g(x) - f_{x_0} · g_{x_0}] ≤ |f(x)| · |g(x) - g_{x_0}| + |g_{x_0}| · |f(x) - f_{x_0}| ≤ |\sup f(x)| · ε_2 + |g_{x_0}| · ε_1 = ε$ |
| $⇓$  | $∀ε>0;∃δ=\min\lbrace δ_1,δ_2 \rbrace;∀x∈\mathrm{B}^{∘}(x_0,δ); \left| \dfrac{f(x)}{g(x)} - \dfrac{f_{x_0} }{g_{x_0} } \right| = \left| \dfrac{f(x) · g_{x_0} - f_{x_0} · g(x)}{g(x) · g_{x_0} } \right| ≤ \dfrac{\left| f(x) \right| · |g(x) - g_{x_0}| + |g_{x_0}| · |f(x) - f_{x_0}|}{\left| g(x) · g_{x_0} \right|} ≤ \dfrac{|\sup f(x)| · ε_2 + |g_{x_0}| · ε_1}{|\inf g(x)| · |g_{x_0}|} = ε$ |

若函数$f(x)$在点$x_0$处有极限$\lim\limits_{x⇝x_0} f(x) ⇝ f_{x_0} = y_0$，且函数$g(y)$在点$y_0$处有极限$\lim\limits_{y⇝y_0} g(y) ⇝ g_{y_0}$，前提条件$f(x)≠f_{x_0}$不可忽略。

$\lim\limits_{x⇝x_0} g(f(x)) \mathop{====}\limits_{f_{x_0}=y_0}^{f(x)≠f_{x_0} } \lim\limits_{y⇝y_0} g(y) ⇝ g_{y_0}$

| $⇓$  | $∀ζ>0;∃ε>0;∀y; y∈\mathrm{B}^{∘}(y_0,ε) ⇒ g(y)∈\mathrm{B}^{∘}(g_{y_0},ζ)$ |                  |
| :--: | :----------------------------------------------------------- | :--------------- |
| $⇓$  | $∀ε>0;∃δ>0;∀x; x∈\mathrm{B}^{∘}(x_0,δ) ⇒ f(x)∈\mathrm{B}^{∘}(y_0,ε)$ | $f_{x_0} = y_0$  |
| $⇓$  | $∀ζ>0;∃ε>0;∃δ>0;∀x; x∈\mathrm{B}^{∘}(x_0,δ) ⇒ f(x)∈\mathrm{B}^{∘}(y_0,ε) ⇒ g(f(x))∈\mathrm{B}^{∘}(g_{y_0},ζ)$ | $f(x) ≠ f_{x_0}$ |
| $⇓$  | $∀ζ>0;∃ε>0;∀y=f(x); y∈\mathrm{B}^{∘}(y_0,ε) ⇒ g(y)∈\mathrm{B}^{∘}(g_{y_0},ζ)$ |                  |

反例：函数$g(y) = \mathop{0}\limits_{y=0};\mathop{1}\limits_{y≠0}$，且函数$f(x) ≡ 0$。

$\lim\limits_{x⇝x_0} g(f(x)) = g(0) = 0 ≠ 1 ⇜ \lim\limits_{y⇝0} g(y)$

函数$f (x)$在点$x_0$处可导，若点$x_0$为$f (x)$的极值点，则${^1}f (x_0) = 0$，反之不对。

函数$f (x)$在点$x_0$处可导，若${^1}f (x_0) = 0$，则点$x_0$为$f (x)$的停驻点，反之亦然。

反例：函数$f (x) = | x |$在点$x_0 = 0$处不可导。

若函数$f (x)$在区间$X$上严格单调，则反函数$'f (y)$在区间$Y$上的单调性相同。

$∀x_1,x_2∈X; [ {'}f (y_1) = x_1 < x_2 = {'}f (y_2) ] ⇔ [ f^{↑} (x_1) = y_1 < y_2 = f^{↑} (x_2) ]$

$∀x_1,x_2∈X; [ {'}f (y_1) = x_1 < x_2 = {'}f (y_2) ] ⇔ [ f^{↓} (x_1) = y_1 > y_2 = f^{↓} (x_2) ]$

| $⇓$  | $∀x_1,x_2∈X; [ x_1 < x_2 ] ⇒ [ f^{↑} (x_1) = y_1 < y_2 = f^{↑} (x_2) ]$ | $P ⇒ Q$                |
| :--: | :----------------------------------------------------------- | :--------------------- |
| $⇓$  | $∀x_1,x_2∈X; [ x_1 = x_2 ] ⇒ [ f^{↑} (x_1) = y_1 = y_2 = f^{↑} (x_2) ]$ | $R ⇒ S$                |
| $⇓$  | $∀x_1,x_2∈X; [ x_1 ≤ x_2 ] ⇒ [ f^{↑} (x_1) = y_1 ≤ y_2 = f^{↑} (x_2) ]$ | $[P ∨ R] ⇒ [ Q ∨ S]$   |
| $⇓$  | $∀y_1,y_2∈X; [ y_1 > y_2 ] ⇒ [ {'}f (y_1) = x_1 > x_2 = {'}f (y_2) ]$ | $¬[ Q ∨ S] ⇒ ¬[P ∨ R]$ |
| $⇓$  | $∀y_1,y_2∈X; [ y_1 < y_2 ] ⇒ [ {'}f (y_1) = x_1 < x_2 = {'}f (y_2) ]$ |                        |
|      |                                                              |                        |
| $⇓$  | $∀x_1,x_2∈X; [ {'}f (y_1) = x_1 < x_2 = {'}f (y_2) ] ⇔ [ f^{↑} (x_1) = y_1 < y_2 = f^{↑} (x_2) ]$ |                        |

若函数$f^{↕} (x)$在单区间$X$上严格单调，且其函数值域为单区间，则函数$f^{↕} (x)$在单区间$X$上单调连续。

| $⇓$  | $∀x_1,x_2∈X; [ f^{-1} (y_1) = x_1 < x_2 = f^{-1} (y_2) ] ⇔ [ f^{↑} (x_1) = y_1 < y_2 = f^{↑} (x_2) ]$ |      |                                               |
| :--: | :----------------------------------------------------------- | :--: | :-------------------------------------------- |
| $⇓$  | $∀y_1,y_0,y,y_2∈Y; [ y_1 < y_0, y < y_2 ] ⇔ [ x_1 < x_0, x < x_2 ]$ |      |                                               |
| $⇓$  | $∀ε=|y_2-y_1|>0;∃δ=|x_2-x_1|>0; [ | x - x_0 | < δ ] ⇒ [ | y - y_0 | < ε]$ |      |                                               |
| $⇓$  | $∀ε>0;∃δ>0; [ | x - x_0 | < δ ] ⇒ [ | f^{↑} (x) - f^{↑} (x_0) | < ε ]$ | $⇒$  | $\lim\limits_{x⇝x_0} f^{↑} (x) ⇝ f^{↑} (x_0)$ |
| $⇓$  |                                                              |      | $\lim\limits_{x⇝x_0} f^{↕} (x) ⇝ f^{↕} (x_0)$ |

### 连续性

函数$f(x)$在区间$X$上点$x_0$处振幅$w_{X}^{f}(x_0)$。若函数$f(x)$在区间$X$上点$x_0$处未定义，则其在该点处振幅$w_{X}^{f}(x_0)$可视为无穷大。

$w_{X}^{f}(x_0,δ) ≡ \sup\limits_{u,v∈\mathrm{B}_{X}(x_0,δ)} |f(u) - f(v)| = \left[ \sup\limits_{u∈\mathrm{B}_{X}(x_0,δ)} f(u) - \inf\limits_{v∈\mathrm{B}_{X}(x_0,δ)} f(v) \right]$

$w_{X}^{f}(x_0) ≡ \lim\limits_{δ⇝0} w_{X}^{f}(x_0,δ) ≡ \lim\limits_{δ⇝0} \sup\limits_{|u,v-x_0|≤δ}^{u,v∈X} |f(u) - f(v)| = \lim\limits_{δ⇝0} \left[ \sup\limits_{|u-x_0|≤δ}^{u∈X} f(u) - \inf\limits_{|v-x_0|≤δ}^{v∈X} f(v) \right]$

| $w^{f}(x_0) ≠ 0$   | $∃ε>0;∀δ>0; \sup\limits_{u,v∈\mathrm{B}_{X}(x_0,δ)} |f(u) - f(v)|>ε$ | $∃ε>0;∀δ>0;∃u,v∈\mathrm{B}_{X}(x_0,δ); |f(u) - f(v)|>ε$   | $∃ε>0;∀δ>0;∃u,v∈X; |u,v-x_0|≤δ ∧ |f(u) - f(v)|>ε$   |
| :----------------- | :----------------------------------------------------------- | :-------------------------------------------------------- | :-------------------------------------------------- |
| $$w^{f}(x_0) = 0$$ | $∀ε>0;∃δ>0; \sup\limits_{u,v∈\mathrm{B}_{X}(x_0,δ)} |f(u) - f(v)| ≤ ε$ | $∀ε>0;∃δ>0;∀u,v∈\mathrm{B}_{X}(x_0,δ); |f(u) - f(v)| ≤ ε$ | $∀ε>0;∃δ>0;∀u,v∈X; |u,v-x_0|≤δ ⇒ |f(u) - f(v)| ≤ ε$ |

连续性是局部点域性质。若函数$f(x)$在点$x_0∈X$处连续，则函数在点$x_0∈X$处既左连续也右连续，反之亦然。

$\left[ \lim\limits_{x⇝x_0} f (x) ⇝ f (x_0) \right] ⇔ \left[ \lim\limits_{x⇝x_0^{-} } f (x) ⇝ f (x_0) \right] ∧ \left[ \lim\limits_{x⇝x_0^{+} } f (x) ⇝ f (x_0) \right]$

| $\lim\limits_{x⇝x_0^{+} } f(x) ⇝ f(x_0) ≠ ∞$ | $Ⅎx_0∈X;∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{B}(x_0^{+},δ)} |f(x) - f(x_0)|≤ε$ | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x∈\mathrm{B}(x_0^{+},δ); f(x)∈\mathrm{B}(f(x_0),ε)$ |
| :------------------------------------------ | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\lim\limits_{x⇝x_0^-} f(x) ⇝ f(x_0) ≠ ∞$   | $Ⅎx_0∈X;∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{B}(x_0^{-},δ)} |f(x) - f(x_0)|≤ε$ | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x∈\mathrm{B}(x_0^{-},δ); f(x)∈\mathrm{B}(f(x_0),ε)$ |
| $\lim\limits_{x⇝x_0} f (x) ⇝ f (x_0) ≠ ∞$   | $Ⅎx_0∈X;∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{B}(x_0,δ)} |f(x) - f(x_0)| ≤ ε$ | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x∈\mathrm{B}(x_0,δ); f(x)∈\mathrm{B}(f(x_0),ε)$ |
| $\lim\limits_{x⇝x_0} f (x) ⇝ f (x_0) ≠ ∞$   | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x∈\mathrm{B}(x_0,δ); |f(x) - f(x_0)|≤ε$   | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x∈X; |x - x_0|≤δ ⇒ |f(x) - f(x_0)|≤ε$     |
|                                             |                                                              |                                                              |
| $\lim\limits_{x⇝x_0} f(x) \not⇝ f(x_0)$     | $Ⅎx_0∈X;∃ε>0;∀δ>0;∃x∈\mathrm{B}(x_0,δ); |f(x) - f(x_0)| > ε$ | $Ⅎx_0∈X;∃ε>0;∀δ>0;∃x∈X; |x - x_0| ≤ δ ∧ |f(x) - f(x_0)| > ε$ |

一致连续性是全局区域性质。若函数$f(x)$在区间$X$上一致连续，则函数必在任意点$x∈X$处连续，反之不对。$[∃x;∀y; Q(x, y)] ⇒ [∀y;∃x; Q(x, y)]$

$\left[ \lim\limits_{x↭x_t} f (x) ↭ f (x_t) \right] ⇒ \left[ \lim\limits_{x⇝x_0} f(x) ⇝ f(x_0) \right]$

| $\lim\limits_{x↭x_t} f (x) ↭ f (x_t) ≠ ∞$ | $∀ε>0;∃δ>0;∀x,x_t∈X; |x - x_t|≤δ ⇒ |f(x) - f(x_t)|≤ε$     | $∀ε>0;∃δ>0; \sup\limits_{|x-x_t|≤δ} |f(x) - f(x_t)|≤ε$   |
| :---------------------------------------- | --------------------------------------------------------- | -------------------------------------------------------- |
|                                           |                                                           |                                                          |
| $\lim\limits_{x↭x_t} f(x) \not↭ f(x_t)$   | $∃ε>0;∀δ>0;∃x,x_t∈X; |x - x_t| ≤ δ ∧ |f(x) - f(x_t)| > ε$ | $∃ε>0;∀δ>0; \sup\limits_{|x-x_t|≤δ} |f(x) - f(x_t)| > ε$ |

若函数$f (x)$在区间$X$上点$x_0$处连续，则在该点处振幅必为零，反之亦然。若函数$f(x)$在区间$X$上点$x_0$处间断，则在该点处振幅非为零，反之亦然。

$\left[ \lim\limits_{x⇝x_0} f (x) ⇝ f (x_0) \right] ⇔ \left[ \lim\limits_{δ⇝0} w^{f} (x_0,δ) ⇝ 0 \right]$

$\left[ \lim\limits_{x⇝x_0} f(x) \not⇝ f(x_0) \right] ⇔ \left[ \lim\limits_{δ⇝0} w^{f}(x_0,δ) \not⇝ 0 \right]$

| $⇓$  | $∀ε_u>0;∃δ_u>0;∀u∈\mathrm{B}(x_0,δ_u); |f(u) - f(x_0)| ≤ ε_u $ | $\lim\limits_{x⇝x_0} f(x) ⇝ f(x_0)$   |
| :--: | ------------------------------------------------------------ | ------------------------------------- |
| $⇓$  | $∀ε_u>0;∃δ_u>0;∀ε_v>0;∃δ_v>0;∀ε>0;∃δ>0;∀u,v∈\mathrm{B}(x_0,δ=\min\lbrace δ_u,δ_v \rbrace); |f(u) - f(v)| ≤ |f(u) - f(x_0)| + |f(v) - f(x_0)| ≤ ε_u + ε_v = ε$ |                                       |
| $⇓$  | $∀ε>0;∃δ>0;∀u,v∈\mathrm{B}(x_0,δ); |f(u) - f(v)| ≤ ε$        |                                       |
| $⇓$  | $∀ε>0;∃δ>0;∀x∈\mathrm{B}(x_0,δ); |f(x) - f(x_0)| ≤ ε$        | $\lim\limits_{δ⇝0} w^{f} (x_0,δ) ⇝ 0$ |

若函数$f(x)$在区间$X$上点$x_0$处左极限与右极限全都存在，但不均等于该点处函数值，则称点$x_0$为函数$f(x)$的跳跃间断点。若极限值为无穷大，则可视为极限存在。

$\left[ f(x)|_{x_0^{-} } ≠ f(x_0) \right] ∨ \left[ f(x_0) ≠ f(x)|_{x_0^{+} } \right]$

若函数$f(x)$在区间$X$上点$x_0$处左极限与右极限不都存在，但不均等于该点处函数值，则称点$x_0$为函数$f(x)$的振荡间断点。其极限值无限振荡，不趋于任何固定值。

$\left[ \lim\limits_{x⇝x_0^{-} } f(x) \not⇝ f(x_0) \right] ∨ \left[ f(x_0) \not⇜ \lim\limits_{x⇝x_0^{+} } f(x) \right]$

若函数$f (x)$在点$x_0$处连续$\lim\limits_{x⇝x_0} f (x) ⇝ f (x_0)$，且函数$g (x)$在点$x_0$处连续$\lim\limits_{x⇝x_0} g (x) ⇝ g (x_0)$。

$\lim\limits_{x⇝x_0} [ f (x) + g (x) ] = \lim\limits_{x⇝x_0} f (x) + \lim\limits_{x⇝x_0} g (x) ⇝ f (x_0) + g (x_0)$

$\lim\limits_{x⇝x_0} [ f (x) - g (x) ] = \lim\limits_{x⇝x_0} f (x) - \lim\limits_{x⇝x_0} g (x) ⇝ f (x_0) - g (x_0)$

$\lim\limits_{x⇝x_0} [ f (x) · g (x) ] = \lim\limits_{x⇝x_0} f (x) · \lim\limits_{x⇝x_0} g (x) ⇝ f (x_0) · g (x_0)$

$\lim\limits_{x⇝x_0} \dfrac{f (x)}{g (x)} = \dfrac{\lim\limits_{x⇝x_0} f (x)}{\lim\limits_{x⇝x_0} g (x)} \mathop{⇝}\limits_{g(x_0)≠0} \dfrac{f (x_0)}{g (x_0)}$

$\lim\limits_{x⇝x_0} \mathrm{Con} · f (x) = \mathrm{Con} · \lim\limits_{x⇝x_0} f (x) ⇝ \mathrm{Con} · f (x_0)$

若函数$f(x)$在点$x_0$处连续$\lim\limits_{x⇝x_0} f(x) ⇝ f(x_0) = y_0$，且函数$g(y)$在点$y_0$处连续$\lim\limits_{y⇝y_0} g(y) ⇝ g(y_0)$，则复合函数$g(f(x))$在点$x_0$处连续。

$\lim\limits_{x⇝x_0} g(f(x)) = g\left( \lim\limits_{x⇝x_0} f(x) \right) ⇝ g(f(x_0))$

| $⇓$  | $∀ζ>0;∃ε>0;∀y; y∈\mathrm{B}(y_0,ε) ⇒ g(y)∈\mathrm{B}(g(y_0),ζ)$ |      |
| :--: | :----------------------------------------------------------- | :--- |
| $⇓$  | $∀ε>0;∃δ>0;∀x; x∈\mathrm{B}(x_0,δ) ⇒ f(x)∈\mathrm{B}(y_0,ε)$ |      |
| $⇓$  | $∀ζ>0;∃ε>0;∃δ>0;∀x; x∈\mathrm{B}(x_0,δ) ⇒ f(x)∈\mathrm{B}(y_0,ε) ⇒ g(f(x))∈\mathrm{B}(g(y_0),ζ)$ |      |
| $⇓$  | $∀ζ>0;∃ε>0;∀y=f(x); y∈\mathrm{B}(x_0,ε) ⇒ g(y)∈\mathrm{B}(g(f(x_0)),ζ)$ |      |
|      |                                                              |      |
| $⇓$  | $\lim\limits_{x⇝x_0} g(f(x)) = \lim\limits_{y⇝y_0} g(y) = g(y_0) = g\left( \lim\limits_{x⇝x_0} f(x) \right) ⇝ g(f(x_0))$ |      |

### 一致连续性

若函数$f (x)$在区间$\fbox{X}$上连续，则函数$f (x)$在区间$\fbox{X}$上一致连续，反之亦然。

$\left[ \lim\limits_{x⇝x_0} f (x) \mathop{⇝}\limits_{x,x_0∈\fbox{X} } f (x_0) \right] ⇔ \left[ \lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈\fbox{X} } f (x_t) \right]$

| $⇓$  | $∀x_0∈\fbox{X};∀ε>0;∃δ_0>0; w^{f}(x_0,δ_0) ≤ ε$              | $⇔$  | $∀x_0∈X;∀ε>0;∃δ_0>0;∀x∈X; |x - x_0| ≤ δ_0 ⇒ |f(x) - f(x_0)| ≤ ε$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε>0;∀x_0∈\fbox{X};∃δ_0>0; w^{f}(x_0,δ_0) ≤ ε$              |      |                                                              |
| $⇓$  | $∀ε>0;∃δ>0;∀x_0∈\fbox{X};∃δ_0>0; w^{f}\left(x_0,δ=\inf\limits_{x_0∈\fbox{X} }δ_0 \right) ≤ w^{f}(x_0,δ_0) ≤ ε$ |      |                                                              |
| $⇓$  | $∀ε>0;∃δ>0;∀x∈\fbox{X}; w^{f}(x,δ) ≤ ε$                      | $⇔$  | $∀ε>0;∃δ>0;∀x,x_t∈X; |x - x_t| ≤ δ ⇒ |f(x) - f(x_t)| ≤ ε$    |

若函数$f (x)$在区间$\fbox{X}$上导函数有确界，则函数$f (x)$在区间$X$上必一致连续，反之不对。$P ⇒ Q$

若函数$f(x)$在区间$X$上非一致连续，则函数$f(x)$在区间$\fbox{X}$上导函数无确界，反之不对。$¬Q ⇒ ¬P$

$\left[ ∀x_t∈\fbox{X};∃\mathrm{Sup}_{x}; \left| \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right| ≤ \mathrm{Sup_{x} } \right] ⇒ \left[ ∃\mathrm{Sup}^{f};∀x,x_t∈X; | f (x) - f (x_t) | ≤ \mathrm{Sup}^{f} · | x - x_t | \right] ⇒ \left[ \lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈X} f (x_t) \right]$

| $⇓$  | $∀x∈\fbox{X};∃\mathrm{Sup}_{x}; \left| \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right| ≤ \mathrm{Sup}_{x} ≠ ∞^{+}$ |      |                                                              |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $∃\mathrm{Sup};∀x∈\fbox{X};∃\mathrm{Sup}_{x}; \left| \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right| ≤ \mathrm{Sup}_{x} ≤ \mathrm{Sup} = \sup\limits_{x∈\fbox{X} } \left\lbrace \mathrm{Sup}_{x} \right\rbrace$ |      |                                                              |
| $⇓$  | $∃\mathrm{Sup};∀x∈\fbox{X}; |\mathrm{d} f(x)| ≤ \mathrm{Sup} · |\mathrm{d} x|$ | $⇔$  | $∃\mathrm{Sup}^{f};∀x,x_t∈X; |f(x) - f(x_t)| ≤ \mathrm{Sup}^{f} · |x - x_t|$ |
| $⇓$  | $∃\mathrm{Sup};∀ε>0;∃δ>0;∀x,x_t∈X; [ |x - x_t| ≤ δ ] ⇒ [ |f(x) - f(x_t)| ≤ \mathrm{Sup} · |x - x_t| ≤ \mathrm{Sup} · δ = ε ]$ |      |                                                              |
| $⇓$  | $\lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈X} f (x_t)$ |      |                                                              |

若函数$f (x)$在区间$(x_{α}, x_{β})$上一致连续，则可将函数$f(x)$延拓为区间$[x_{α}, x_{β}]$上的一致连续函数$\tilde{f}(x) = \mathop{f(x_α^+)}\limits_{x=x_α}; \mathop{f (x)}\limits_{x∈(x_α,x_β)};\mathop{f(x_β^{-})}\limits_{x=x_β}$。

若函数$f (x)$在区间$(x_α,x_β]$上一致连续，且在区间$[x_β, x_γ)$上一致连续，则函数$f (x)$在区间$(x_α, x_γ)$上一致连续。

若函数$f (x)$在区间$(∞^{-},∞^{+})$上连续，且以区间$T = [t_α, t_β]$为周期，则函数$f (x)$在区间$(∞^{-},∞^{+})$上一致连续。

$\left[ \lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x,x_t∈(x_α,x_β]} f(x_t) \right] ∧ \left[ \lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x,x_t∈[x_β,x_γ)} f(x_t) \right] ⇒ \left[ \lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x,x_t∈(x_α,x_γ)} f (x_t) \right]$

| $⇓$  | $∀ε_1>0;∃δ_1>0;∀x,x_t∈(x_α,x_β]; \left[ | x - x_t | ≤ δ_1 \right] ⇒ \left[ | f (x) - f (x_t) | ≤ ε_1 \right]$ | $\lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈(x_α,x_β]} f (x_t)$ |
| :--: | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $⇓$  | $∀ε_2>0;∃δ_2>0;∀x,x_t∈[x_β,x_γ); \left[ | x - x_t | ≤ δ_2 \right] ⇒ \left[ | f (x) - f (x_t) | ≤ ε_2 \right]$ | $\lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x,x_t∈[x_α,x_β)} f(x_t)$ |
| $⇓$  | $∀ε_3>0;∃δ_3=\min\lbrace δ_1, δ_2 \rbrace;∀x∈(x_α,x_β];∀x_t∈[x_β,x_γ); [ |x - x_t| ≤ δ_3 ] ⇒ [ |f(x) - f(x_t)| ≤ |f(x) - f(x_β)| + |f(x_β) - f(x_t)| ≤ ε_1 + ε_2 = ε_3 ]$ |                                                              |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈(x_α,x_γ); \left[ | x - x_t | ≤ δ \right] ⇒ \left[ | f (x) - f (x_t) | ≤ ε \right]$ | $\lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x,x_t∈(x_α,x_β)} f(x_t)$ |

若函数$f (x)$在区间$[x_α^{±}, ∞^{±})$上连续，且 $\lim\limits_{x⇝∞^{±} } f (x) ⇝ f_{∞^{±} }$极限存在，则函数$f (x)$在区间$[x_α^{±}, ∞^{±})$上一致连续。

$\left[ \lim\limits_{x⇝x_0} f (x) \mathop{⇝}\limits_{x,x_0∈[x_α^{±},∞^{±})} f (x_0) \right] ∧ \left[ \lim\limits_{x⇝∞^{±} } f (x) ⇝ f_{∞^{±} } \right] ⇔ \left[ \lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈[x_α^{±},∞^{±})} f (x_t) \right]$

| $⇓$  | $∃x_β;[x_α^{±}, ∞^{±}) = [x_α^{±}, x_β] ∪ [x_β, ∞^{±})$      |      |                                                              |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε>0;∃x_β∈[x_α^{±},∞^{±}];∀x,x_t∈[x_β,∞^{±}); [ |f(x) - f(x_t)| ≤ ε ]$ | $⇔$  | $\left[ \lim\limits_{x⇝∞^{±} } f (x) \mathop{⇝}\limits_{x∈[x_β,∞^{±})} f_{∞^{±} } \right]$ |
| $⇓$  | $∀ε>0;∃x_β∈[x_α^{±},∞^{±}];∃δ>0;∀x,x_t∈[x_β,∞^{±}); ¬[ |x - x_t| ≤ δ ] ∨ [ |f(x) - f (x_t)| ≤ ε ]$ |      |                                                              |
| $⇓$  | $∀ε>0;∃x_β∈[x_α^{±},∞^{±}];∃δ>0;∀x,x_t∈[x_β,∞^{±}); [ |x - x_t| ≤ δ ] ⇒ [ |f(x) - f(x_t)| ≤ ε ]$ | $⇒$  | $\left[ \lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x∈[x_β,∞^{±})} f (x_t) \right]$ |
| $⇓$  | $∀ε>0;∃x_β∈[x_α^{±},∞^{±}];∃δ>0;∀x,x_t∈[x_α^{±},x_β]; [ |x - x_t| ≤ δ ] ⇒ [ |f(x) - f(x_t)| ≤ ε ]$ | $⇔$  | $\left[ \lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x,x_t∈[x_α^{±},x_β]} f(x_t) \right]$ |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈[x_α^{±},∞^{±}); [ |x - x_t| ≤ δ ] ⇒ [ |f(x) - f(x_t)| ≤ ε ]$ | $⇒$  | $\left[ \lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x,x_t∈[x_α^{±},∞^{±})} f(x_t) \right]$ |

若函数$y = f(x)$在区间$X$上非一致连续，则其反函数$x = {'}f(y)$在区间$Y$上一致连续，反之不对。

$\left[ ∃ε>0;∀δ>0; \sup\limits_{|x-x_t|≤δ} |f(x) - f(x_t)| > ε \right] ⇒ \left[ ∀δ>0;∃ε>0; \sup\limits_{|f(x)-f(x_t)|≤ε} |x - x_t| ≤ δ \right]$

| $⇓$  | $∃ε>0;∀δ>0; \sup\limits_{|x-x_t|≤δ} |f(x) - f(x_t)| > ε$  | $⇔$  | $∃ε>0;∀δ>0;∃x,x_t∈X; |x - x_t| ≤ δ ∧ |f(x) - f(x_t)| > ε$    |
| :--: | :-------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $∀δ>0; ∃ε>0; \sup\limits_{|x-x_t|≤δ} |f(x) - f(x_t)| > ε$ |      | $∃x;∀y;P(x,y) ⇒ ∀y;∃x;P(x,y)$                                |
| $⇓$  | $∀δ>0;∃ε>0; \sup\limits_{|f(x)-f(x_t)|≤ε} |x - x_t| ≤ δ$  | $⇔$  | $∀δ>0;∃ε>0;∀f(x),f(x_t)∈Y; |f(x) - f(x_t)| ≤ ε ⇒ |x - x_t| ≤ δ$ |
|      |                                                           |      |                                                              |
| $⇓$  | $∃ε>0;∀δ>0; \sup\limits_{|x-x_t|≤δ} |f(x) - f(x_t)| > ε$  | $⇒$  | $∀δ>0;∃ε>0; \sup\limits_{|f(x)-f(x_t)|≤ε} |x - x_t| ≤ δ$     |
| $⇓$  | $∀ε>0;∃δ>0; \sup\limits_{|x-x_t|≤δ} |f(x) - f(x_t)| ≤ ε$  | $⇐$  | $∃δ>0;∀ε>0; \sup\limits_{|f(x)-f(x_t)|≤ε} |x - x_t| > δ$     |

典例：函数$f (x) = \dfrac{1}{x}$在区间$(0, x_β)$上非一致连续，但在区间$\mathop{[x_α, x_β)}\limits_{0<x_α}$上一致连续。

典例：函数$f (x) = α · x + β$在区间$(∞^{-}, ∞^{+})$上一致连续。函数$f (x) = \sin x^2$在区间$(∞^{-}, ∞^{+})$上非一致连续。

典例：函数$f (x) = | x |$在区间$(∞^{-}, ∞^{+})$上一致连续。函数$\mathrm{sgn} (x) = \mathop{-1}\limits_{x<0};\mathop{0}\limits_{x=0};\mathop{+1}\limits_{x>0}$在区间$[-1, +1]$上非一致连续。

典例：函数$f (x) = \sqrt{x}$在区间$[0, ∞^{+})$上一致连续，但在点$x_0=0^+$处导函数右极限为$\left.\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{0^+} = \lim\limits_{x⇝0^+} \dfrac{1}{2 · \sqrt{x} } = ∞^{+}$。

典例：函数$f(x) = x^2$在区间$[0,∞^{+})$上非一致连续，函数$f(x) = x^2$与${'}f(y) = \sqrt{y}$在区间$[0,∞^{+})$上互为反函数。

| $⇓$  | $∃ε>0;∀δ>0;∃x=\dfrac{1}{n},x_t=\dfrac{1}{n + 1}∈(0,x_β); \left[ | x - x_t | = \left| \dfrac{1}{n · (n + 1)} \right| ≤ δ \right] ∧ \left[ | f (x) - f (x_t) | = \left| \dfrac{1}{x} - \dfrac{1}{x_t} \right| = \left| \dfrac{1}{\frac{1}{n} } - \dfrac{1}{\frac{1}{n + 1} } \right| = 1 > ε \right]$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈[x_α,x_β); \left[ | x - x_t | ≤ δ \right] ⇒ \left[ | f (x) - f (x_t) | = \left| \dfrac{1}{x} - \dfrac{1}{x_t} \right| = \dfrac{| x - x_t |}{| x · x_t |} ≤ \dfrac{δ}{x_α^2} = ε \right]$ |
|      |                                                              |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈(∞^{-},∞^{+}); \left[ | x - x_t | ≤ δ \right] ⇒ \left[ | f (x) - f (x_t) | = \left| (α · x + β) - (α · x_t + β) \right| = | α | · | x - x_t | ≤ | α | · δ = ε \right]$ |
|      |                                                              |
| $⇓$  | $∃ε>0;∀δ>0;∃x=\sqrt{n·π+\frac{π}{2} },x_t=\sqrt{n·π}∈(∞^{-},∞^{+}); \left[ | x - x_t | = \dfrac{\frac{π}{2} }{\sqrt{n·π+\frac{π}{2} } + \sqrt{n·π} } ≤ δ \right] ∧ \left[ | f (x) - f (x_t) | = \left| \sin x^2 - \sin x_t^2 \right| = \left| \sin \left( n·π+\frac{π}{2} \right) - \sin (n·π) \right| = 1 > ε \right]$ |
|      |                                                              |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈(∞^{-},∞^{+}); [ | x - x_t | ≤ δ ] ⇒ [ | f (x) - f (x_t) | = || x | - | x_t || ≤ | x - x_t | ≤ δ = ε ]$ |
|      |                                                              |
| $⇓$  | $∃ε>0;∀δ>0;∃x=\dfrac{1}{n},x_t=0∈[-1,+1]; \left[ | x - x_t | = \left| \dfrac{1}{n} \right| ≤ δ \right] ∧ [ | f (x) - f (x_t) | = | 1 - 0 | = 1 > ε ]$ |
|      |                                                              |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈[0, ∞^{+}); [ | x - x_t | ≤ δ ] ⇒ \left[ | f (x) - f (x_t) | = | \sqrt{x} - \sqrt{x_t} | \mathop{≤}\limits^{\sqrt{u+v}≤\sqrt{u}+\sqrt{v} } \sqrt{|x - x_t|} ≤ \sqrt{δ} = ε \right]$ |
|      |                                                              |
| $⇓$  | $∃ε>0;∀δ>0;∃x=\sqrt{2·n·π+\frac{π}{2} },x_t=\sqrt{2·n·π}∈[0,∞^{+}); \left[ |x - x_t| = \dfrac{\frac{π}{2} }{\sqrt{2·n·π+\frac{π}{2} } + \sqrt{2·n·π} } ≤ δ \right] ∧ \left[ |f(x) - f(x_t)| = |x^{2} - x_t^{2}| = \dfrac{π}{2} > ε \right]$ |

### 导函数

若函数$f(x)$在点$x_0$处去心闭邻域的右导数${^1}f(x_0^{+})$与左导数${^1}f(x_0^{-})$存在且相等，则其导数值${^1}f(x_0)$存在。函数$f(x)$在区间$X$上所有点$x_0$处导数值${^1}f(x_0)$组成其导函数${^1}f(x)$。

若函数$f(x)$在点$x_0$处导函数${^1}f(x)$的右极限${^1}f_{x_0^{+} }$与左极限${^1}f_{x_0^{-} }$存在且相等，则其导函数极限值${^1}f_{x_0}$存在。函数$f(x)$在点$x_0$处导数值${^1}f(x_0)$与其导函数极限值${^1}f_{x_0}$未必等同。

若函数$f(x)$在区间$(x_α,x_β)$上任意点处导数值存在，且在点$x_α$处右导数${^1}f(x_α^{+})$与在点$x_β$处左导数${^1}f(x_β^{-})$均存在，则可认为函数$f(x)$在区间$[x_α,x_β]$上任意点处导数值存在。

|       右导数 | ${^1}f(x_0^+) ≡ \dfrac{\mathrm{d}^1 f(x_0^+)}{\mathrm{d}^1 x_0^{+} }$ | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x_t∈X; 0<x_t-x_0≤+δ ⇒ \left| \dfrac{f(x_t) - f(x_0)}{x_t - x_0} - {^1}f(x_0) \right| ≤ ε$ |                                                              |
| -----------: | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
|       左导数 | ${^1}f(x_0^-) ≡ \dfrac{\mathrm{d}^1 f(x_0^-)}{\mathrm{d}^1 x_0^{-} }$ | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x_t∈X; -δ≤x_t-x_0<0 ⇒ \left| \dfrac{f(x_t) - f(x_0)}{x_t - x_0} - {^1}f(x_0) \right| ≤ ε$ |                                                              |
|       导数值 | ${^1}f(x_0) ≡ \dfrac{\mathrm{d}^1 f(x_0)}{\mathrm{d}^1 x_0}$ | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x_t∈X; 0<|x_t-x_0|≤δ ⇒ \left| \dfrac{f(x_t) - f(x_0)}{x_t - x_0} - {^1}f(x_0) \right| ≤ ε$ |                                                              |
|       右导数 | ${^1}f(x_0^+) ≡ \dfrac{\mathrm{d}^1 f(x_0^+)}{\mathrm{d}^1 x_0^{+} }$ | $\lim\limits_{x_t⇝x_0^+} \dfrac{f(x_t) - f(x_0)}{x_t - x_0} \mathop{=====}\limits^{x_t=x_0+Δx_0} \lim\limits_{Δx_0⇝0^+} \dfrac{f(x_0+Δx_0) - f(x_0)}{Δx_0} = \lim\limits_{Δx_0⇝0^+} \dfrac{Δf(x_0)}{Δx_0}$ |                                                              |
|       左导数 | ${^1}f(x_0^-) ≡ \dfrac{\mathrm{d}^1 f(x_0^-)}{\mathrm{d}^1 x_0^{-} }$ | $\lim\limits_{x_t⇝x_0^-} \dfrac{f(x_t) - f(x_0)}{x_t - x_0} \mathop{=====}\limits^{x_t=x_0+Δx_0} \lim\limits_{Δx_0⇝0^-} \dfrac{f(x_0+Δx_0) - f(x_0)}{Δx_0} = \lim\limits_{Δx_0⇝0^-} \dfrac{Δf(x_0)}{Δx_0}$ |                                                              |
|       导数值 | ${^1}f(x_0) ≡ \dfrac{\mathrm{d}^1 f(x_0)}{\mathrm{d}^1 x_0}$ | $\lim\limits_{x_t⇝x_0} \dfrac{f(x_t) - f(x_0)}{x_t - x_0} \mathop{=====}\limits^{x_t=x_0+Δx_0} \lim\limits_{Δx_0⇝0} \dfrac{f(x_0 + Δx_0) - f(x_0)}{Δx_0} = \lim\limits_{Δx⇝0} \dfrac{Δf(x_0)}{Δx_0}$ | ${^1}f(x_0^{-}) = {^1}f(x_0) = {^1}f(x_0^{+})$               |
|              |                                                              |                                                              |                                                              |
|       导函数 | ${^1}f(x) ≡ \dfrac{\mathrm{d}^1 f(x)}{\mathrm{d}^1 x}$       | $∀x∈X;∀ε>0;∃δ>0;∀x_t∈X; 0<|x_t - x| ≤ δ ⇒ \left| \dfrac{f(x_t) - f(x)}{x_t - x} - {^1}f(x) \right| ≤ ε$ |                                                              |
|       导函数 | ${^1}f(x) ≡ \dfrac{\mathrm{d}^1 f(x)}{\mathrm{d}^1 x}$       | $\lim\limits_{x_t⇝x} \dfrac{f(x_t) - f(x)}{x_t - x} \mathop{=====}\limits^{x_t=x+Δx} \lim\limits_{Δx⇝0} \dfrac{f(x + Δx) - f(x)}{Δx} = \lim\limits_{Δx⇝0} \dfrac{Δf(x)}{Δx}$ |                                                              |
| 导函数右极限 | ${^1}f_{x_0^{+} } ≡ \left.\dfrac{\mathrm{d}^{1}f(x)}{\mathrm{d}^{1}x}\right|_{x_0^{+} }$ | $\lim\limits_{x⇝x_0^{+} } {^1}f(x) = \lim\limits_{x⇝x_0^{+} } \dfrac{\mathrm{d}^{1}f(x)}{\mathrm{d}^{1}x}$ |                                                              |
| 导函数左极限 | ${^1}f_{x_0^{-} } ≡ \left.\dfrac{\mathrm{d}^{1}f(x)}{\mathrm{d}^{1}x}\right|_{x_0^{-} }$ | $\lim\limits_{x⇝x_0^{-} } {^1}f(x) = \lim\limits_{x⇝x_0^{-} } \dfrac{\mathrm{d}^{1}f(x)}{\mathrm{d}^{1}x}$ |                                                              |
| 导函数极限值 | ${^1}f_{x_0} ≡ \left.\dfrac{\mathrm{d}^{1}f(x)}{\mathrm{d}^{1}x}\right|_{x_0}$ | $\lim\limits_{x⇝x_0} {^1}f(x) = \lim\limits_{x⇝x_0} \dfrac{\mathrm{d}^{1}f(x)}{\mathrm{d}^{1}x}$ | ${^1}f_{x_0^{-} } = {^1}f_{x_0} = {^1}f_{x_0^{+} }$            |
|              |                                                              |                                                              |                                                              |
|   二阶导数值 | ${^2}f(x_0) ≡ \dfrac{\mathrm{d}^{2} f(x_0)}{\mathrm{d}^{2} x_0}$ | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x_t∈X; 0<|x_t - x_0| ≤ δ ⇒ \left| \dfrac{{^1}f(x_t) - {^1}f(x_0)}{x_t - x_0} - {^2}f(x_0) \right| ≤ ε$ |                                                              |
|   二阶导数值 | ${^2}f(x_0) ≡ \dfrac{\mathrm{d}^{2} f(x_0)}{\mathrm{d}^{2} x_0}$ | $\lim\limits_{x_t⇝x_0} \dfrac{{^1}f(x_t) - {^1}f(x_0)}{x_t - x_0} = \lim\limits_{Δx_0⇝0} \dfrac{{^1}f(x_0 + Δx_0) - {^1}f(x_0)}{Δx_0} = \lim\limits_{Δx_0⇝0} \dfrac{Δ{^1}f(x_0)}{Δx_0}$ | $\dfrac{\mathrm{d}^{2} f(x_0)}{\mathrm{d}^{2} x_0} ≡ \dfrac{\mathrm{d} }{\mathrm{d} x_0} \dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x_0}$ |
|   二阶导函数 | ${^2}f(x) ≡ \dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x}$   | $∀x∈X;∀ε>0;∃δ>0;∀x_t∈X; 0<|x_t - x| ≤ δ ⇒ \left| \dfrac{{^1}f(x_t) - {^1}f(x)}{x_t - x} - {^2}f(x) \right| ≤ ε$ |                                                              |
|   二阶导函数 | ${^2}f(x) ≡ \dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x}$   | $\lim\limits_{x_t⇝x} \dfrac{{^1}f(x_t) - {^1}f(x)}{x_t - x} = \lim\limits_{Δx⇝0} \dfrac{{^1}f(x + Δx) - {^1}f(x)}{Δx} = \lim\limits_{Δx⇝0} \dfrac{Δ{^1}f(x)}{Δx}$ | $\dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x} ≡ \dfrac{\mathrm{d} }{\mathrm{d} x} \dfrac{\mathrm{d} f(x)}{\mathrm{d} x}$ |
|              |                                                              |                                                              |                                                              |
|   高阶导数值 | ${^n}f(x_0) ≡ \dfrac{\mathrm{d}^{n} f(x_0)}{\mathrm{d}^{n} x_0}$ | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x_t∈X; 0<|x_t - x_0| ≤ δ ⇒ \left| \dfrac{{^{n-1} }f(x_t) - {^{n-1} }f(x_0)}{x_t - x_0} - {^{n} }f(x_0) \right| ≤ ε$ |                                                              |
|   高阶导数值 | ${^n}f(x_0) ≡ \dfrac{\mathrm{d}^{n} f(x_0)}{\mathrm{d}^{n} x_0}$ | $\lim\limits_{x_t⇝x_0} \dfrac{{^{n-1} }f(x_t) - {^{n-1} }f(x_0)}{x_t - x_0} = \lim\limits_{Δx_0⇝0} \dfrac{{^{n-1} }f(x_0 + Δx_0) - {^{n-1} }f(x_0)}{Δx_0} = \lim\limits_{Δx_0⇝0} \dfrac{Δ{^1}f(x_0)}{Δx_0}$ | $\dfrac{\mathrm{d}^{n} f(x_0)}{\mathrm{d}^{n} x_0} ≡ \dfrac{\mathrm{d} }{\mathrm{d} x_0} \dfrac{\mathrm{d}^{n-1} f(x_0)}{\mathrm{d}^{n-1} x_0}$ |
|   高阶导函数 | ${^n}f(x) ≡ \dfrac{\mathrm{d}^{n} f(x)}{\mathrm{d}^{n} x}$   | $∀x∈X;∀ε>0;∃δ>0;∀x_t∈X; 0<|x_t - x| ≤ δ ⇒ \left| \dfrac{{^{n-1} }f(x_t) - {^{n-1} }f(x)}{x_t - x} - {^{n} }f(x) \right| ≤ ε$ |                                                              |
|   高阶导函数 | ${^n}f(x) ≡ \dfrac{\mathrm{d}^{n} f(x)}{\mathrm{d}^{n} x}$   | $\lim\limits_{x_t⇝x} \dfrac{{^{n-1} }f(x_t) - {^{n-1} }f(x)}{x_t - x} = \lim\limits_{Δx⇝0} \dfrac{{^{n-1} }f(x + Δx) - {^{n-1} }f(x)}{Δx} = \lim\limits_{Δx⇝0} \dfrac{Δ{^1}f(x)}{Δx}$ | $\dfrac{\mathrm{d}^{n} f(x)}{\mathrm{d}^{n} x} ≡ \dfrac{\mathrm{d} }{\mathrm{d} x} \dfrac{\mathrm{d}^{n-1} f(x)}{\mathrm{d}^{n-1} x}$ |

典例：函数$f(x) = x^2$。

${^1}f(x) = \dfrac{\mathrm{d}^{1} f(x)}{\mathrm{d}^{1} x} = \lim\limits_{x_t⇝x} \dfrac{x_t^2 - x^2}{x_t - x} = \lim\limits_{x_t⇝x} (x_t + x) ⇝ 2 · x$

${^2}f(x) = \dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x} = \lim\limits_{x_t⇝x} \dfrac{2 · x_t - 2 · x}{x_t - x} = \lim\limits_{x_t⇝x} 2 ⇝ 2$

$\lim\limits_{x_t⇝x} \dfrac{f(x_t) - f(x)}{(x_t - x)^2} = \lim\limits_{x_t⇝x} \dfrac{x_t^2 - x^2}{(x_t - x)^2} = \lim\limits_{x_t⇝x} \dfrac{x_t + x}{x_t - x} ⇝ ∞$

若函数$f(x)$在点$x_0$处一阶导数值${^1}f(x_0)$存在，则函数$f(x)$必定在点$x_0$处连续，反之不对。

若函数$f(x)$在点$x_0$处二阶导数值$^{2}f(x_0)$存在，则其一阶导函数在点$x_0$处连续，反之不对。

$\lim\limits_{x⇝x_0} f(x) = \lim\limits_{x⇝x_0} \left[ \dfrac{f(x) - f(x_0)}{x - x_0} · (x - x_0) + f(x_0) \right] = {^1}f(x_0) · \lim\limits_{x⇝x_0} (x - x_0) + f(x_0) ⇝ f(x_0)$

反例：函数$f(x) = |x|$在点$x_0 = 0$处连续，但其在点$x_0 = 0$处导数值不存在。

$\lim\limits_{x⇝0^{+} } \dfrac{f(x) - f(0)}{x - 0} = \lim\limits_{x⇝0^{+} } \dfrac{x}{x} ⇝ +1 ≠ -1 ⇜ \lim\limits_{x⇝0^{-} } \dfrac{-x}{x} = \lim\limits_{x⇝0^{-} } \dfrac{f(x) - f(0)}{x - 0}$

一阶导函数的运算性质。若函数$g(x)$与函数$f(x)$的一阶导函数存在。

| $\dfrac{\mathrm{d} }{\mathrm{d} x}[g(x) + f(x)]$       | $\dfrac{\mathrm{d} g(x)}{\mathrm{d} x} + \dfrac{\mathrm{d} f(x)}{\mathrm{d} x}$ | $\lim\limits_{x_t⇝x} \dfrac{[g(x_t) + f(x_t)] - [g(x) + f(x)]}{x_t - x} = \lim\limits_{x⇝x} \dfrac{[g(x_t) - g(x)] + [f(x_t) - f(x)]}{x_t - x}$ |
| :---------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\dfrac{\mathrm{d} }{\mathrm{d} x}[g(x) - f(x)]$       | $\dfrac{\mathrm{d}g(x)}{\mathrm{d}x} - \dfrac{\mathrm{d}f(x)}{\mathrm{d}x}$ | $\lim\limits_{x_t⇝x} \dfrac{[g(x_t) - f(x_t)] - [g(x) - f(x)]}{x_t - x} = \lim\limits_{x_t⇝x} \dfrac{[g(x_t) - g(x)] - [f(x_t) - f(x)]}{x_t - x}$ |
| $\dfrac{\mathrm{d} }{\mathrm{d}x}[g(x) · f(x)]$        | $\dfrac{\mathrm{d} g(x)}{\mathrm{d} x} · f(x) + g(x) · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x}$ | $\lim\limits_{x_t⇝x} \dfrac{g(x_t) · f(x_t) - g(x) · f(x)}{x_t - x} = \lim\limits_{x_t⇝x} \dfrac{[g(x_t) - g(x)] · f(x_t) + g(x) · [f(x_t) - f(x)]}{x_t - x}$ |
| $\dfrac{\mathrm{d} }{\mathrm{d} x} \dfrac{g(x)}{f(x)}$ | $\dfrac{\dfrac{\mathrm{d} g(x)}{\mathrm{d} x} · f(x) - g(x) · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} }{f^2(x)}$ | $\lim\limits_{x_t⇝x} \dfrac{\dfrac{g(x_t)}{f(x_t)} - \dfrac{g(x)}{f(x)} }{x_t - x} \mathop{===}\limits^{f(x)≠0} \lim\limits_{x_t⇝x} \dfrac{\dfrac{[g(x_t) - g(x)] · f(x)}{x_t - x} - \dfrac{g(x) · [f(x_t) - f(x)]}{x_t - x} }{f(x_t) · f(x)}$ |
| $\dfrac{\mathrm{d} }{\mathrm{d} x} g(f(x))$            | $\dfrac{\mathrm{d} g(f(x))}{\mathrm{d} f(x)} · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \mathop{===}\limits^{y=f(x)} \dfrac{\mathrm{d} g(y)}{\mathrm{d} y} · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x}$ | $\lim\limits_{x_t⇝x} \dfrac{g(f(x_t)) - g(f(x))}{x_t - x} = \lim\limits_{x_t⇝x} \dfrac{g(f(x_t)) - g(f(x))}{f(x_t) - f(x)} · \dfrac{f(x_t) - f(x)}{x_t - x}$ |
| $\dfrac{\mathrm{d} }{\mathrm{d} x} {'}f^{⇵}(x)$        | $\left[ \dfrac{\mathrm{d} x}{\mathrm{d} {'}f^{⇵}(x)} \right]^{-1} \mathop{====}\limits_{y={'}f^{⇵}(x)}^{x=f^{⇵}(y)} \left[ \dfrac{\mathrm{d} f^{⇵}(y)}{\mathrm{d} y} \right]^{-1}$ | $\lim\limits_{x_t⇝x} \dfrac{{'}f^{⇵}(x_t) - {'}f^{⇵}(x)}{x_t - x} = \left[ \lim\limits_{x_t⇝x} \dfrac{x_t - x}{{'}f^{⇵}(x_t) - {'}f^{⇵}(x)} \right]^{-1} \mathop{====}\limits_{y={'}f^{⇵}(x)}^{x=f^{⇵}(y)} \left[ \lim\limits_{x_t⇝x} \dfrac{f^{⇵}(y_t) - f^{⇵}(y)}{y_t - y} \right]^{-1}$ |
|                                                       |                                                              |                                                              |
| $\dfrac{\mathrm{d} }{\mathrm{d} x} |x|$                | $\dfrac{|x|}{x}$                                             | $\lim\limits_{x_t⇝x>0} \dfrac{(+x_t) - (+x)}{x_t - x} ⇝ +1;\lim\limits_{x_t⇝x<0} \dfrac{(-x_t) - (-x)}{x_t - x} ⇝ -1$ |
| $\dfrac{\mathrm{d} }{\mathrm{d} x} f(x)^{g(x)}$        | $f(x)^{g(x)} · \left[ \dfrac{\mathrm{d} g(x)}{\mathrm{d} x} · \ln |f(x)| + \dfrac{g(x)}{f(x)} · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right]$ | $\dfrac{\mathrm{d} f(x)^{g(x)} }{\mathrm{d} |f(x)^{g(x)}|} · \dfrac{\mathrm{d} ә^{g(x) · \ln |f(x)|} }{\mathrm{d} x} = \dfrac{f(x)^{g(x)} }{|f(x)^{g(x)}|} · ә^{g(x) · \ln |f(x)|} · \left[ \dfrac{\mathrm{d} g(x)}{\mathrm{d} x} · \ln |f(x)| + \dfrac{g(x)}{|f(x)|} · \dfrac{|f(x)|}{f(x)} · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right]$ |

典例：函数$f(x) = \dfrac{(x + 9)^{\frac{1}{2} } · (3 - x)^{\frac{2}{3} } }{(x + 4)^{\frac{3}{4} } · (5 - x)^{\frac{4}{5} } }$，因此$\ln |f(x)| = \dfrac{1}{2} · \ln |x + 9| + \dfrac{2}{3} · \ln |3 - x| - \dfrac{3}{4} · \ln |x + 4| - \dfrac{4}{5} · \ln |5 - x|$。

$\dfrac{1}{f(x)} · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = \dfrac{+1}{2 · (x + 9)} + \dfrac{-2}{3 · (3 - x)} - \dfrac{3}{4 · (x + 4)} - \dfrac{-4}{5 · (5 - x)} $

$\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = \dfrac{(x + 9)^{\frac{1}{2} } · (3 - x)^{\frac{2}{3} } }{(x + 4)^{\frac{3}{4} } · (5 - x)^{\frac{4}{5} } } · \left[ \dfrac{+1}{2 · (x + 9)} + \dfrac{-2}{3 · (3 - x)} - \dfrac{3}{4 · (x + 4)} - \dfrac{-4}{5 · (5 - x)} \right]$

周期函数$f(x) = f(x + T)$，其导函数$\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = \dfrac{\mathrm{d} [f(x + T)]}{\mathrm{d} (x + T)} · \dfrac{\mathrm{d} (x + T)}{\mathrm{d} x} = \dfrac{\mathrm{d} f(x + T)}{\mathrm{d} (x + T)}$以$T$为周期。

奇函数$f(x) = -f(-x)$，其导函数$\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = \dfrac{\mathrm{d} [-f(-x)]}{\mathrm{d} (-x)} · \dfrac{\mathrm{d} (-x)}{\mathrm{d} x} = +\dfrac{\mathrm{d} f(-x)}{\mathrm{d} (-x)}$为偶函数。

偶函数$f(x) = +f(-x)$，其导函数$\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = \dfrac{\mathrm{d} [+f(-x)]}{\mathrm{d} (-x)} · \dfrac{\mathrm{d} (-x)}{\mathrm{d} x} = -\dfrac{\mathrm{d} f(-x)}{\mathrm{d} (-x)}$为奇函数。

高阶导函数的运算性质。若函数$g(x)$与函数$f(x)$的高阶导函数均存在。

|     $\dfrac{\mathrm{d}^{n} }{\mathrm{d}^{n} x} [g(x) + f(x)]$ | $\dfrac{\mathrm{d}^{n} g(x)}{\mathrm{d}^{n} x} + \dfrac{\mathrm{d}^{n} f(x)}{\mathrm{d}^{n} x}$ | $\dfrac{\mathrm{d}^{0} f(x)}{\mathrm{d}^{0} x} ≡ f(x)$ |
| -----------------------------------------------------------: | :----------------------------------------------------------- | :----------------------------------------------------- |
|     $\dfrac{\mathrm{d}^{n} }{\mathrm{d}^{n} x} [g(x) · f(x)]$ | $\sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · \dfrac{\mathrm{d}^{n-i} g(x)}{\mathrm{d}^{n-i} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x}$ |                                                        |
| $\dfrac{\mathrm{d}^{n} }{\mathrm{d}^{n} x} [\mathrm{Con} · f(x)]$ | $= \mathrm{Con} · \dfrac{\mathrm{d}^{n} f(x)}{\mathrm{d}^{n} x}$ |                                                        |

|     $\dfrac{\mathrm{d}^{0} }{\mathrm{d}^{0} x} [g(x) + f(x)]$ | $g(x) + f(x)$                                                | $\dfrac{\mathrm{d}^{0} f(x)}{\mathrm{d}^{0} x} ≡ f(x)$ |
| -----------------------------------------------------------: | :----------------------------------------------------------- | :----------------------------------------------------- |
|     $\dfrac{\mathrm{d}^{1} }{\mathrm{d}^{1} x} [g(x) + f(x)]$ | $\dfrac{\mathrm{d}^{1} g(x)}{\mathrm{d}^{1} x} + \dfrac{\mathrm{d}^{1} f(x)}{\mathrm{d}^{1} x}$ |                                                        |
|     $\dfrac{\mathrm{d}^{n} }{\mathrm{d}^{n} x} [g(x) + f(x)]$ | $\dfrac{\mathrm{d}^{n} g(x)}{\mathrm{d}^{n} x} + \dfrac{\mathrm{d}^{n} f(x)}{\mathrm{d}^{n} x}$ |                                                        |
| $\dfrac{\mathrm{d} }{\mathrm{d} x} \dfrac{\mathrm{d}^{n} }{\mathrm{d}^{n} x} [g(x) + f(x)]$ | $\dfrac{\mathrm{d} }{\mathrm{d} x} \left[ \dfrac{\mathrm{d}^{n} g(x)}{\mathrm{d}^{n} x} + \dfrac{\mathrm{d}^{n} f(x)}{\mathrm{d}^{n} x} \right]$ |                                                        |
| $\dfrac{\mathrm{d}^{n+1} }{\mathrm{d}^{n+1} x} [g(x) + f(x)]$ | $\dfrac{\mathrm{d}^{n+1} g(x)}{\mathrm{d}^{n+1} x} + \dfrac{\mathrm{d}^{n+1} f(x)}{\mathrm{d}^{n+1} x}$ |                                                        |
|                                                              |                                                              |                                                        |
|     $\dfrac{\mathrm{d}^{0} }{\mathrm{d}^{0} x} [g(x) · f(x)]$ | $g(x) · f(x)$                                                | $\dfrac{\mathrm{d}^{0} f(x)}{\mathrm{d}^{0} x} ≡ f(x)$ |
|     $\dfrac{\mathrm{d}^{1} }{\mathrm{d}^{1} x} [g(x) · f(x)]$ | $\dfrac{\mathrm{d}^{1} g(x)}{\mathrm{d}^{1} x} · f(x) + g(x) · \dfrac{\mathrm{d}^{1} f(x)}{\mathrm{d}^{1} x}$ |                                                        |
|     $\dfrac{\mathrm{d}^{n} }{\mathrm{d}^{n} x} [g(x) · f(x)]$ | $\sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · \dfrac{\mathrm{d}^{n-i} g(x)}{\mathrm{d}^{n-i} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x}$ |                                                        |
| $\dfrac{\mathrm{d} }{\mathrm{d} x} \dfrac{\mathrm{d}^{n} }{\mathrm{d}^{n} x} [g(x) · f(x)]$ | $\sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · \dfrac{\mathrm{d} }{\mathrm{d} x} \left[ \dfrac{\mathrm{d}^{n-i} g(x)}{\mathrm{d}^{n-i} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x} \right]$ |                                                        |
|                                                              | $\sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · \left[ \dfrac{\mathrm{d}^{n-i+1} g(x)}{\mathrm{d}^{n-i+1} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x} + \dfrac{\mathrm{d}^{n-i} g(x)}{\mathrm{d}^{n-i} x} · \dfrac{\mathrm{d}^{i+1} f(x)}{\mathrm{d}^{i+1} x} \right]$ |                                                        |
|                                                              | $\dfrac{\mathrm{d}^{n+1} g(x)}{\mathrm{d}^{n+1} x} · \dfrac{\mathrm{d}^{0} f(x)}{\mathrm{d}^{0} x} + \left[ \sum\limits_{i=1}^{n} \dfrac{n!}{i! · (n - i)!} · \dfrac{\mathrm{d}^{n-i+1} g(x)}{\mathrm{d}^{n-i+1} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x} + \sum\limits_{i=1}^{n} \dfrac{n!}{(i - 1)! · (n - i + 1)!} · \dfrac{\mathrm{d}^{n-(i-1)} g(x)}{\mathrm{d}^{n-(i-1)} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x} \right] + \dfrac{\mathrm{d}^{0} g(x)}{\mathrm{d}^{0} x} · \dfrac{\mathrm{d}^{n+1} f(x)}{\mathrm{d}^{n+1} x}$ |                                                        |
|                                                              | $\dfrac{\mathrm{d}^{n+i} g(x)}{\mathrm{d}^{n+1} x} · \dfrac{\mathrm{d}^{0} f(x)}{\mathrm{d}^{0} x} + \left[ \sum\limits_{i=1}^{n} \dfrac{(n + 1)!}{i! · (n + 1 - i)!} · \dfrac{\mathrm{d}^{n+1-i} g(x)}{\mathrm{d}^{n+1-i} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x}\right] + \dfrac{\mathrm{d}^{0} g(x)}{\mathrm{d}^{0} x} · \dfrac{\mathrm{d}^{n+1} f(x)}{\mathrm{d}^{n+1} x}$ |                                                        |
| $\dfrac{\mathrm{d}^{n+1} }{\mathrm{d}^{n+1} x} [g(x) · f(x)]$ | $\sum\limits_{i=0}^{n+1} \dfrac{(n + 1)!}{i! · (n + 1 - i)!} · \dfrac{\mathrm{d}^{n+1-i} g(x)}{\mathrm{d}^{n+1-i} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x}$ |                                                        |

若函数$f(x)$在区间$X$上连续且导函数$\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} ≶ 0$，则函数$f^{⇵}(x)$在区间$X$上严格单调，反之不对。

若函数$f(x)$在区间$X$上连续且导函数$\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} ⪋ 0$，则函数$f^{⇵}(x)$在区间$X$上单调递进，反之亦然。

若函数$f(x)$在区间$X$上连续且严格单调，则其导函数$\dfrac{\mathrm{d} f(x)}{\mathrm{d} x}$仅有可能在单点处为零。

$\left[ \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} ≶ 0 \right] ⇒ \left[ f^{⇵}(x) \right] ⇔ \left[ ∀x_1,x_2∈L≡\left\lbrace ∀x : \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = 0 \right\rbrace; [x_1,x_2]⊈L \right]$

$\left[ \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} ⪋ 0 \right] ⇔ \left[ f^{⤨}(x) \right]$

| $\lim\limits_{x_2⇝x_1} \dfrac{f(x_2) - f(x_1)}{x_2 - x_1} = \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \mathop{≤}\limits_{x_1=x_2} 0$ | $⇐$  | $\dfrac{f(x_2) - f(x_1)}{x_2 - x_1} = \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ∈(x_1,x_2)} < 0$ | $⇒$  | $[x_1 < x_2] ⇒ [f(x_1) < f(x_2)]$ | $⇔$  | $f^{↑}(x)$ |
| :----------------------------------------------------------- | :--: | :----------------------------------------------------------- | :--: | :-------------------------------- | :--: | :--------- |
| $\lim\limits_{x_2⇝x_1} \dfrac{f(x_2) - f(x_1)}{x_2 - x_1} = \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} ≤ 0$ | $⇔$  | $\dfrac{f(x_2) - f(x_1)}{x_2 - x_1} = \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ∈(x_1,x_2)} ≤ 0$ | $⇔$  | $[x_1 < x_2] ⇒ [f(x_1) ≤ f(x_2)]$ | $⇔$  | $f^{↗}(x)$ |

典例：函数$f^{↑}(x) = x^3$，在$ℝ$上严格单调递增，但仅仅在点$x_0 = 0$处导数值${^1}f^{↑}(0) = 0$。

若函数$f(x)$在点$x_0$处的两侧导数值异号，则点$x_0$为极小值点异或者极大值点，反之不对。

若函数$f(x)$在点$x_0$处导数值为零，二阶导数值存在不为零，则点$x_0$为极值点，反之不对。

$\left[ {^1}f(x_0) = 0 \right] ∧ \left[ {^2}f(x_0) ≶ 0 \right] ⇒ \left[ {^1}f(x_0 - Δ) · {^1}f(x_0 + Δ) < 0 \right] ⇒ \left[ f(x_0) = \inf\limits_{x∈\mathrm{B}(x_0,Δ)} f(x) \right] ∨ \left[ f(x_0) = \sup\limits_{x∈\mathrm{B}(x_0,Δ)} f(x) \right]$

| $⇓$  | ${^1}f(x_0-Δ) · {^1}f(x_0+Δ) < 0$                            | $⇔$  | $\dfrac{f(x_0-Δ) - f(x_0)}{-Δ} · \dfrac{f(x_0+Δ)-f(x_0)}{+Δ} < 0$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\left[ f(x_0) = \inf\limits_{x∈\mathrm{B}(x_0,Δ)} f(x) \right] ∨ \left[ f(x_0) = \sup\limits_{x∈\mathrm{B}(x_0,Δ)} f(x) \right]$ | $⇔$  | $[f(x_0-Δx_0) - f(x_0)] · [f(x_0) - f(x_0+Δx_0)] < 0$        |
|      |                                                              |      |                                                              |
| $⇓$  | $\left[ {^1}f(x_0) = 0 \right] ∧ \left[ {^2}f(x_0) < 0 \right] ⇒ \left[ {^1}f(x_0 - Δ) · {^1}f(x_0 + Δ) < 0 \right]$ |      | $f(x_0) = \sup\limits_{x∈\mathrm{B}(x_0,Δ)} f(x)$            |
| $⇓$  | $\left[ {^1}f(x_0) = 0 \right] ∧ \left[ {^2}f(x_0) > 0 \right] ⇒ \left[ {^1}f(x_0 - Δ) · {^1}f(x_0 + Δ) < 0 \right]$ |      | $f(x_0) = \inf\limits_{x∈\mathrm{B}(x_0,Δ)} f(x)$            |
| $⇓$  | $\left[ {^1}f(x_0) = 0 \right] ∧ \left[ {^2}f(x_0) ≶ 0 \right] ⇒ \left[ {^1}f(x_0 - Δ) · {^1}f(x_0 + Δ) < 0 \right]$ |      | $\left[ f(x_0) = \inf\limits_{x∈\mathrm{B}(x_0,Δ)} f(x) \right] ∨ \left[ f(x_0) = \sup\limits_{x∈\mathrm{B}(x_0,Δ)} f(x) \right]$ |

若函数$f(x)$在区间$[x_α,x_β]$上连续，则函数$f(x)$在区间$[x_α,x_β]$上停驻点与曲折点处取得最小值与最大值。

$\inf\limits_{x∈[x_α,x_β]} f(x) = \inf \left\lbrace ∀x; f(x): x∈\left\lbrace ∀x_0∈[x_α,x_β]; x_0: \dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x} = 0 \right\rbrace \bigcup \left\lbrace ∀x_0∈[x_α,x_β]; x_0: \dfrac{\mathrm{d} f(x_0^{-})}{\mathrm{d} x} ≠ \dfrac{\mathrm{d} f(x_0^{+})}{\mathrm{d} x} \right\rbrace \right\rbrace$

$\sup\limits_{x∈[x_α,x_β]} f(x) = \sup \left\lbrace ∀x; f(x): x∈\left\lbrace ∀x_0∈[x_α,x_β]; x_0: \dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x} = 0 \right\rbrace \bigcup \left\lbrace ∀x_0∈[x_α,x_β]; x_0: \dfrac{\mathrm{d} f(x_0^{-})}{\mathrm{d} x} ≠ \dfrac{\mathrm{d} f(x_0^{+})}{\mathrm{d} x} \right\rbrace \right\rbrace$

典例：数列$n^{\frac{1}{n} }$在$3^{\frac{1}{3} }$处取得最大值。

| $f(x) = x^{\frac{1}{x} }$                                     | $\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = x^{\frac{1}{x} } · \left[ -\dfrac{1}{x^2} · \ln|x| + \dfrac{1}{x^2} · 1 \right] = x^{\frac{1}{x}-2} · (1 - \ln|x|) = \mathop{+0}\limits_{x<ә};\mathop{0}\limits_{x=ә};\mathop{-0}\limits_{x>ә}$ | $x^{\frac{1}{x}-2} > 0$ |
| :----------------------------------------------------------- | :----------------------------------------------------------- | :---------------------- |
| $\lim\limits_{x⇝0^{+} } x^{\frac{1}{x} } = \lim\limits_{x⇝0^{+} } ә^{\frac{1}{x}·\ln x} ⇝ ә^{∞^{-} } = 0$ | $\lim\limits_{x⇝∞^{+} } x^{\frac{1}{x} } = \lim\limits_{x⇝∞^{+} } ә^{\frac{1}{x}·\ln x} ⇝ ә^{0^{+} } = 1$ |                         |
| $\max\limits_{0≤n<∞^{+} } \left\lbrace n^{\frac{1}{n} } \right\rbrace = \max\limits_{2≤ә≤3} \left\lbrace 2^{\frac{1}{2} }, 3^{\frac{1}{3} } \right\rbrace = 3^{\frac{1}{3} }$ |                                                              |                         |

### 连续介值定理

若函数$f (x)$在单区间$X$上连续，则其值域$Y$为单区间，反之不对。单区间内任意一点均为聚点，任意两点均可连通成线。

若函数$f(x)$在单区间$X=[x_{α},x_{β}]$上连续，则对于任意函数值$f(x)$，必定存在某一点$θ∈X$其函数值相等。

$f(x)|_{∀x∈X} = \left.f (x)\right|_{∃θ∈X}$

| $⇓$  | $∀x∈X;∃θ∈X; f (x) = f (θ)$                                   | $⇔$  | $\left. f(x) \right|_{∀x∈X} = \left. f(x) \right|_{∃θ∈X}$    |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $∀y∈f(X);∃θ∈X; y = f(θ)$                                     | $⇐$  | $y ≡ f(x)$                                                   |
| $⇓$  | $∀y∈[\min\lbrace f(x_α),f(x_β) \rbrace,\max\lbrace f(x_α),f(x_β) \rbrace] ⊆ f([x_α,x_β]);∃θ∈X; y = f(θ)$ |      |                                                              |
| $⇓$  | $[f(x_α) · f(x_β) ≤ 0] ⇒ \left[ 0 = \left. f(x) \right|_{∃θ∈[x_α,x_β]} \right]$ |      | $[f(x_α) · f(x_β) < 0] ⇒ \left[ 0 = \left. f(x) \right|_{∃θ∈(x_α,x_β)} \right]$ |

若函数$f(x)$在单区间$X = [x_α, x_β]$上连续，对于权均值$\sum\limits_{i=0}^{n} t_i · f(x_i)$，则必定存在某一点$θ∈X$其函数值相等。

$\sum\limits_{i=0}^{n} t_i · f(x_i) \mathop{=====}\limits_{x_i∈[x_α,x_β]}^{\sum\limits_{i=0}^{n} t_i \mathop{==}\limits^{0≤t_i} 1} \left. f(θ) \right|_{∃θ∈[x_α,x_β]}$

| $⇓$  | $\sum\limits_{i=0}^{n} t_i · f(x_i) ∈ [\min\lbrace f(x_i) \rbrace, \max\lbrace f(x_i) \rbrace] ⊆ f([x_α,x_β])$ | $\sum\limits_{i=0}^{n} t_i \mathop{==}\limits^{0≤t_i} 1$ |
| :--: | :----------------------------------------------------------- | :------------------------------------------------------- |
| $⇓$  | $\sum\limits_{i=0}^{n} t_i · f(x_i) = \left. f(θ) \right|_{∃θ∈[x_α,x_β]}$ |                                                          |

若函数$f (x)$在单区间$X = [x_α, x_β]$上连续，且其值域内含于定义域，则必定存在某一个不动点$θ∈[x_α, x_β]$。

$f([x_α,x_β]) ⊆ [x_α,x_β] ⇒ \left. f(x) \right|_{∃θ∈[x_α,x_β]} = θ$

| $⇓$  | $F (x) ≡ f (x) - x$                        |      |                                                        |
| :--: | :----------------------------------------- | :--: | :----------------------------------------------------- |
| $⇓$  | $F(x_α) · F(x_β) ≤ 0$                      | $⇐$  | $F(x_α) = f(x_α) - x_α ≥ 0, F(x_β) = f(x_β) - x_β ≤ 0$ |
| $⇓$  | $0 = \left. F (x) \right|_{∃θ∈[x_α, x_β]}$ |      |                                                        |
| $⇓$  | $\left.f (x)\right|_{∃θ∈[x_α, x_β]} = θ$   |      |                                                        |

对于实数域奇数次多项式$P_{2·n+1}(x) ≡ \sum\limits_{i=0}^{2·n+1} p_i · (x - x_0)^{i}$，必定存在某一个实数解$θ∈ℝ$。

| $⇓$  | $P_{2·n+1}(x) ≡ \sum\limits_{i=0}^{2·n+1} p_i · (x - x_0)^{i} = p_{2·n+1} · (x - x_0)^{2·n+1} · \left[ 1 + \sum\limits_{i=1}^{2·n} \dfrac{p_{i} · (x - x_0)^{i} }{p_{2·n+1} · (x - x_0)^{2·n+1} } + \dfrac{p_0}{p_{2·n+1}·(x - x_0)^{2·n+1} } \right]$ |      |                    |
| :--: | :----------------------------------------------------------- | :--: | :----------------- |
| $⇓$  | $\lim\limits_{x⇝∞^{+} } P_{2·n+1}(x) = \lim\limits_{x⇝∞^{+} } p_{2·n+1} · (x - x_0)^{2·n+1} ⇝ p_{2·n+1} · ∞^{+}$ |      |                    |
| $⇓$  | $\lim\limits_{x⇝∞^{-} } P_{2·n+1}(x) = \lim\limits_{x⇝∞^{+} } p_{2·n+1} · (x - x_0)^{2·n+1} ⇝ p_{2·n+1} · ∞^{-}$ |      |                    |
| $⇓$  | $P_{2·n+1}(ℝ) = ℝ$                                           | $⇒$  | $0 ∈ P_{2·n+1}(ℝ)$ |
| $⇓$  | $0 = \left. P_{2·n+1}(x) \right|_{∃θ∈ℝ}$                     |      |                    |

若函数$f (x)$在单区间$(x_α, x_β)$上连续，且$\lim\limits_{x⇝x_α^{+} } f (x)$与$\lim\limits_{x⇝x_β^{-} } f (x)$均有确界，则函数$f (x)$在区间$(x_α, x_β)$上有确界。

若函数$f (x)$在区间$(∞⁻, ∞⁺)$上连续，且$\lim\limits_{x⇝∞⁻} f (x)$与$\lim\limits_{x⇝∞⁺} f (x)$均有确界，则函数$f (x)$在区间$(∞⁻, ∞⁺)$上有确界。

$|f(x)| ≤ \max\left\lbrace \left| \inf\limits_{x∈X} f(x) \right|, \left| \sup\limits_{x∈X} f(x) \right| \right\rbrace$

### 微分中值定理

若函数$f(x)$在点$x_0$处连续且导数值$\dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x_0} = 0$，则称点$x_0$为函数$f(x)$的停驻点。

若函数$f(x)$在点$x_0$处连续但其导数值并不存在，则称点$x_0$为函数$f(x)$的曲折点。

若函数$f(x)$在点$x_0$处达到极小值极大值且导数值存在，则其在点$x_0$处导数$\dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x} = 0$。

若函数$f(x)$在闭区间$[x_α,x_β]$上连续且导函数存在，当两端点处函数值相等，或者两端点处单调性相反，则存在某一点$θ∈(x_α,x_β)$其导数值为零。

$[f(x_α) = f(x_β)] ⇒ \left[ \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ∈(x_α,x_β)} = 0 \right]$

$[[f(x_α) - f(x_α+Δ)] · [f(x_β-Δ) - f(x_β)] ≤ 0] ⇒ \left[ \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ∈(x_α,x_β)} = 0 \right]$

| $⇓$  | $f(θ) = \inf\limits_{x∈(x_α,x_β)} f(x)$                      | $⇔$  | $\lim\limits_{x⇝θ^{-} } \dfrac{f(x) - f(θ)}{x - θ} ≤ 0 ≤ \lim\limits_{x⇝θ^{+} } \dfrac{f(x) - f(θ)}{x - θ}$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $f(θ) = \sup\limits_{x∈(x_α,x_β)} f(x)$                      | $⇔$  | $\lim\limits_{x⇝θ^{-} } \dfrac{f(x) - f(θ)}{x - θ} ≥ 0 ≥ \lim\limits_{x⇝θ^{+} } \dfrac{f(x) - f(θ)}{x - θ}$ |
| $⇓$  | $[f(θ-Δ) - f(θ)] · [f(θ) - f(θ+Δ)] ≤ 0$                      | $⇔$  | $\dfrac{f(θ-Δ) - f(θ)}{-Δ} · \dfrac{f(θ+Δ) - f(θ)}{+Δ} ≤ 0$  |
| $⇓$  | $f(x_γ) = f(x_δ)$                                            | $⇒$  | $\left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ∈(x_γ,x_δ)} = \lim\limits_{x⇝θ} \dfrac{f(x) - f(θ)}{x - θ} = 0$ |
|      |                                                              |      |                                                              |
| $⇓$  | $[[f(x_α) - f(x_α+Δ)] · [f(x_β-Δ) - f(x_β)] ≤ 0] ⇒ \left[ f(x_γ) \mathop{======}\limits_{x_α≤x_γ<x_δ≤x_β}^{∃x_γ,x_δ;} f(x_δ) \right]$ | $⇒$  | $\left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ∈(x_γ,x_δ)⊆(x_α,x_β)} = \lim\limits_{x⇝θ} \dfrac{f(x) - f(θ)}{x - θ} = 0$ |

若函数$f(x)$在闭区间$[x_α,x_β]$上连续且导函数存在，则存在某一点$θ∈(x_α,x_β)$其导数值，等同于两端点处直线的斜率。

$\dfrac{f(x_β) - f(x_α)}{x_β - x_α} = \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ∈(x_α,x_β)}$

| $⇓$  | $F(x) ≡ \left|\begin{matrix} 1 & 1 & 1 \\ x_α & x & x_β \\ f(x_α) & f(x) & f(x_β) \\ \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ x_α & x - x_α & x_β - x_α \\ f(x_α) & f(x) - f(x_α) & f(x_β) - f(x_α) \end{matrix}\right|$ | $F(x_α) = 0 = F(x_β)$                                        |
| :--: | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $⇓$  | $\dfrac{\mathrm{d} F(x)}{\mathrm{d} x} = \dfrac{\mathrm{d} }{\mathrm{d} x} \left|\begin{matrix} 1 & 0 & 0 \\ x_α & x - x_α & x_β - x_α \\ f(x_α) & f(x) - f(x_α) & f(x_β) - f(x_α) \\ \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ x_α & 1 & x_β - x_α \\ f(x_α) & \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} & f(x_β) - f(x_α) \end{matrix}\right|$ | $\dfrac{\mathrm{d} F(x)}{\mathrm{d} x} = [f(x_β) - f(x_α)] - (x_β - x_α) · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x}$ |
| $⇓$  | $\dfrac{f(x_β) - f(x_α)}{x_β - x_α} = \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ∈(x_α,x_β)}$ | $\left. \dfrac{\mathrm{d} F(x)}{\mathrm{d} x} \right|_{∃θ∈(x_α,x_β)} = 0$ |

若函数$f(x)$与函数$g(x)$在闭区间$[x_α,x_β]$上连续且导函数存在，则存在某一点$θ∈(x_α,x_β)$其导数值，等同于两端点处函数值的比值。

$\dfrac{g(x_β) - g(x_α)}{f(x_β) - f(x_α)} = \left.\dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)}\right|_{∃θ∈(x_α, x_β)}$

| $⇓$  | $F(x) ≡ \left|\begin{matrix} 1 & 1 & 1 \\ g(x_α) & g(x) & g(x_β) \\ f(x_α) & f(x) & f(x_β) \\ \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ g(x_α) & g(x) - g(x_α) & g(x_β) - g(x_α) \\ f(x_α) & f(x) - f(x_α) & f(x_β) - f(x_α) \\ \end{matrix}\right|$ | $F(x_α) = 0 = F(x_β)$                                        |
| :--: | ------------------------------------------------------------ | ------------------------------------------------------------ |
| $⇓$  | $\dfrac{\mathrm{d} F(x)}{\mathrm{d} x} = \dfrac{\mathrm{d} }{\mathrm{d} x} \left|\begin{matrix} 1 & 0 & 0 \\ g(x_α) & g(x) - g(x_α) & g(x_β) - g(x_α) \\ f(x_α) & f(x) - f(x_α) & f(x_β) - f(x_α) \\ \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ g(x_α) & \dfrac{\mathrm{d} g(x)}{\mathrm{d} x} & g(x_β) - g(x_α) \\ f(x_α) & \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} & f(x_β) - f(x_α) \end{matrix}\right|$ | $\dfrac{\mathrm{d} F(x)}{\mathrm{d} x} = [f(x_β) - f(x_α)]  · \dfrac{\mathrm{d} g(x)}{\mathrm{d} x} - [g(x_β) - g(x_α)] · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x}$ |
| $⇓$  | $\dfrac{g(x_β) - g(x_α)}{f(x_β) - f(x_α)} = \left.\dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{∃θ∈(x_α,x_β)} = \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} x} · \dfrac{\mathrm{d} x}{\mathrm{d} f(x)} \right|_{∃θ∈(x_α,x_β)}$ | $\left. \dfrac{\mathrm{d} F(x)}{\mathrm{d} x} \right|_{∃θ∈(x_α,x_β)} = 0$ |

### 导数介值定理

若函数$f(x)$在点$x_0$处连续，且其导函数的极限值$\left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{x_0}$存在，则在该点处其导数值$\dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x_0}$等于该极限值，反之不对。若函数在无穷点处的函数值固定，则同样适用。

$\left[ \lim\limits_{x⇝x_0} \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} ⇝ \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{x_0} \right] ⇒ \left[ \lim\limits_{x⇝x_0} \dfrac{f(x) - f(x_0)}{x - x_0} = \dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x_0} = \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{x_0} \right]$

| $⇓$  | $\dfrac{f(x) - f(x_0)}{x - x_0} = \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ∈(x_0,x)}$ | $⇐$  | $\lim\limits_{x⇝x_0} f(x) ⇝ f(x_0)$                          |
| :--: | :----------------------------------------------------------- | :--: | ------------------------------------------------------------ |
| $⇓$  | $\dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x_0} = \lim\limits_{x⇝x_0} \dfrac{f(x) - f(x_0)}{x - x_0} = \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{x_0}$ | $⇐$  | $\left[ \lim\limits_{x⇝x_0} \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∀x} ⇝ \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{x_0} \right] ⇒ \left[ \lim\limits_{θ⇝x_0} \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ} ⇝ \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{x_0} \right]$ |

反例：函数$\mathcal{W}_{2}(x) = \mathop{0}\limits_{x=0};\mathop{x^{2} · \sin \dfrac{1}{x} }\limits_{x≠0}$，在点$x_0 = 0$处连续，但其导函数在点$x_0=0$处的极限值不存在。

$\dfrac{\mathrm{d} \mathcal{W}_{2}(x)}{\mathrm{d} x} = \mathop{\left[ x · \sin \dfrac{1}{x} \right]}\limits_{x=0};\mathop{\left[ 2 · x · \sin \dfrac{1}{x} - \cos \dfrac{1}{x} \right]}\limits_{x≠0}$

$\dfrac{\mathrm{d} \mathcal{W}_{2}(0)}{\mathrm{d} 0} = \lim\limits_{x⇝0} x · \sin \dfrac{1}{x} ⇝ 0 \not⇜ \lim\limits_{x⇝0} \dfrac{\mathrm{d} \mathcal{W}_{2}(x)}{\mathrm{d} x}$

若函数$g(x)$与函数$f(x)$在点$x_0$处的极限值均存在，且其导函数比值的极限值$\left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{x_0}$存在，则在该点处其导函数比值的极限值$\dfrac{\mathrm{d} g(x_0)}{\mathrm{d} f(x_0)}$等于该极限值，反之不对。

$\left[ \lim\limits_{x⇝x_0} \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} ⇝ \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{x_0} \right] ⇒ \left[ \lim\limits_{x⇝x_0} \dfrac{g(x) - g(x)|_{x_0} }{f(x) - f(x)|_{x_0} } = \dfrac{\mathrm{d} g(x_0)}{\mathrm{d} f(x_0)} = \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{x_0} \right]$

$\left[ \lim\limits_{x⇝x_0} \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} ⇝ \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{x_0} \right] ⇒ \left[ \lim\limits_{x⇝x_0} \dfrac{g(x)}{f(x)} \mathop{=====}\limits_{f(x)|_{x_0} = 0}^{g(x)|_{x_0} = 0} \dfrac{\mathrm{d} g(x_0)}{\mathrm{d} f(x_0)} = \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{x_0} \right] ⇒ \left[ \lim\limits_{x⇝x_0} \dfrac{g(x)}{f(x)} \mathop{=====}\limits_{f(x)|_{x_0} = ∞}^{g(x)|_{x_0} = ∞} \dfrac{\mathrm{d} g(x_0)}{\mathrm{d} f(x_0)} = \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{x_0} \right]$

| $⇓$  | $\dfrac{g(x) - g(x)|_{x_0} }{f(x) - f(x)|_{x_0} } = \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{∃θ∈(x_0,x)}$ | $⇐$  | $\lim\limits_{x⇝x_0} g(x) ⇝ g(x)|_{x_0}$                     |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\lim\limits_{x⇝x_0} \dfrac{g(x) - g(x)|_{x_0} }{f(x) - f(x)|_{x_0} } = \dfrac{\mathrm{d} g(x_0)}{\mathrm{d} f(x_0)} = \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{x_0}$ | $⇐$  | $\left[ \lim\limits_{x⇝x_0} \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{∀x} ⇝ \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{x_0} \right] ⇒ \left[ \lim\limits_{x⇝x_0} \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{∃θ} ⇝ \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{x_0} \right]$ |
|      |                                                              |      |                                                              |
| $⇓$  | $\lim\limits_{x⇝x_0} \dfrac{g(x)}{f(x)} \mathop{=====}\limits_{f(x)|_{x_0} = 0}^{g(x)|_{x_0} = 0} \dfrac{\mathrm{d} g(x_0)}{\mathrm{d} f(x_0)} = \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{x_0}$ |      |                                                              |
| $⇓$  | $\lim\limits_{x⇝x_0} \dfrac{g^{-1}(x)}{f^{-1}(x)} \mathop{=====}\limits_{f(x)|_{x_0}=∞}^{g(x)|_{x_0}=∞} \left[ \lim\limits_{x⇝x_0} \dfrac{(-1) · g^{-2}(x)}{(-1) · f^{-2}(x)} \right] · \dfrac{\mathrm{d} g(x_0)}{\mathrm{d} f(x_0)}$ |      |                                                              |
| $⇓$  | $\lim\limits_{x⇝x_0} \dfrac{g(x)}{f(x)} = \lim\limits_{x⇝x_0} \dfrac{g^{-1}(x)}{f^{-1}(x)} · \lim\limits_{x⇝x_0} \dfrac{g^{2}(x)}{f^{2}(x)} = \dfrac{\mathrm{d} g(x_0)}{\mathrm{d} f(x_0)} = \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{x_0}$ |      |                                                              |

反例：导数介值定理的前提条件不可忽略。

$\left[ \lim\limits_{x⇝∞^{+} } \dfrac{2 · x - \sin x}{2 · x + \cos x} = \lim\limits_{x⇝∞^{+} } \dfrac{2 - \dfrac{\sin x}{x} }{2 + \dfrac{\cos x}{x} } \right] ⇝ 1 \not⇜ \left[ \lim\limits_{x⇝∞^{+} } \dfrac{2 - \cos x}{2 - \sin x} = \lim\limits_{x⇝∞^{+} } \dfrac{2 · x - \sin x}{2 · x + \cos x} \right]$

典例：若函数$f(x)$在区间$X$上二阶导函数存在。

$\dfrac{\mathrm{d}^2 f(x)}{\mathrm{d}^2 x} = \lim\limits_{h⇝0} \dfrac{f(x+h) + f(x-h) - 2 · f(x)}{h^2}$

| $⇓$  | $\lim\limits_{h⇝0} \dfrac{f(x+h) + f(x-h) - 2 · f(x)}{h^2}$  |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $= \lim\limits_{h⇝0} \dfrac{\dfrac{\mathrm{d} [f(x+h) + f(x-h) - 2 · f(x)]}{\mathrm{d} h} }{2 · h} = \lim\limits_{h⇝0} \dfrac{\dfrac{\mathrm{d} f(x+h)}{\mathrm{d} (x+h)} · \dfrac{\mathrm{d} (x+h)}{\mathrm{d} h} + \dfrac{\mathrm{d} f(x-h)}{\mathrm{d}(x-h)} · \dfrac{\mathrm{d} (x-h)}{\mathrm{d} h} }{2 · h}$ |
| $⇓$  | $= \lim\limits_{h⇝0} \dfrac{\dfrac{\mathrm{d} f(x+h)}{\mathrm{d} (x+h)} - \dfrac{\mathrm{d} f(x-h)}{\mathrm{d} (x-h)} }{2·h} = \lim\limits_{h⇝0} \dfrac{\dfrac{\mathrm{d} f(x+h)}{\mathrm{d}(x+h)} - \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} }{+2 · h} + \lim\limits_{h⇝0} \dfrac{\dfrac{\mathrm{d} f(x-h)}{\mathrm{d} (x-h)} - \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} }{-2 · h}$ |
| $⇓$  | $= \dfrac{\mathrm{d}^2 f(x)}{2 · \mathrm{d}^2 x} + \dfrac{\mathrm{d}^2 f(x)}{2 · \mathrm{d}^2 x} = \dfrac{\mathrm{d}^2 f(x)}{\mathrm{d}^2 x}$ |

若函数$f(x)$在区间$[x_α,x_β]$上连续且导数值存在，则对于两端点处导数值之间任意取值$t$，存在某点$θ∈(x_α,x_β)$其导数值相等。

$∀t∈\left[\min\left\lbrace \dfrac{\mathrm{d} f(x_α^{+})}{\mathrm{d} x_α^{+} }, \dfrac{\mathrm{d} f(x_β^{-})}{\mathrm{d} x_{β}^{-} } \right\rbrace, \max\left\lbrace \dfrac{\mathrm{d} f(x_α^{+})}{\mathrm{d} x_α^{+} }, \dfrac{\mathrm{d} f(x_β^{-})}{\mathrm{d} x_β^{-} } \right\rbrace\right];∃θ∈(x_α,x_β); \dfrac{\mathrm{d} f(θ)}{\mathrm{d} x} = t$

| $⇓$  | $F(x) ≡ f(x) - t · x$                                        |      | $\dfrac{\mathrm{d} F(x)}{\mathrm{d} x} = \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} - t$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\dfrac{\mathrm{d} F(x_α^{+})}{\mathrm{d} x_α^{+} } · \dfrac{\mathrm{d} F(x_β^{-})}{\mathrm{d} x_{β^{-} } } = \left[ \dfrac{\mathrm{d} f(x_α^{+})}{\mathrm{d} x_{α}^{+} } - t \right] · \left[ \dfrac{\mathrm{d} f(x_β^{-})}{\mathrm{d} x_β^{-} } - t \right] ≤ 0$ | $⇐$  | $∀t∈\left[\min\left\lbrace \dfrac{\mathrm{d} f(x_α^{+})}{\mathrm{d} x_α^{+} }, \dfrac{\mathrm{d} f(x_β^{-})}{\mathrm{d} x_β^{-} } \right\rbrace, \max\left\lbrace \dfrac{\mathrm{d} f(x_α^{+})}{\mathrm{d} x_α^{+} }, \dfrac{\mathrm{d} f(x_β^{-})}{\mathrm{d} x_β^{-} } \right\rbrace\right];$ |
| $⇓$  | $\dfrac{\mathrm{d} F(x_α^{+})}{\mathrm{d} x_α^{+} } = \lim\limits_{x⇝x_α^{+} } \dfrac{F(x) - F(x_α)}{x - x_α}$ |      | $\dfrac{\mathrm{d} F(x_β^{-})}{\mathrm{d} x_β^{-} } = \lim\limits_{x⇝x_β^{-} } \dfrac{F(x) - F(x_β)}{x - x_β}$ |
| $⇓$  | $[F(x_α) - F(x_α+Δ)] · [F(x_β-Δ) - F(x_β)] ≤ 0$              |      | $\lim\limits_{x⇝x_0}^{x_0∈[x_α,x_β]} F(x) ⇝ F(x_0)$          |
| $⇓$  | $∃θ∈(x_α,x_β); [F(θ-Δ) - F(θ)] · [F(θ) - F(θ+Δ)] ≤ 0$        | $⇔$  | $\left[ F(θ) = \inf\limits_{x∈\mathrm{B}(θ,Δ)} F(x) \right] ∨ \left[ F(θ) = \sup\limits_{x∈\mathrm{B}(θ,Δ)} F(x) \right]$ |
| $⇓$  | $\left. \dfrac{\mathrm{d} F(x)}{\mathrm{d} x} \right|_{∃θ∈(x_α,x_β)} = \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ∈(x_α,x_β)} - t = 0$ | $⇒$  | $\left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ∈(x_α,x_β)} = t$ |

典例：不定式$\lim\limits_{x⇝∞^{+} } \left[ \sqrt[9]{x^9 + x^5} - \sqrt[9]{x^9 - x^5} \right]$的极限值。

$\lim\limits_{x⇝∞^{+} } x · \left[ (1 + \dfrac{1}{x^4})^{\frac{1}{9} } - (1-\dfrac{1}{x^{4} })^{\frac{1}{9} } \right] = \lim\limits_{t⇝0^{+} } \dfrac{(1+t^4)^{\frac{1}{9} } - (1-t^4)^{\frac{1}{9} } }{t} = \lim\limits_{t⇝0^{+} } \left[ \dfrac{1}{9} · (1+t^4)^{-\frac{8}{9} } · 4 · t^{3} + \dfrac{1}{9} · (1 - t^4)^{-\frac{8}{9} } · 4 · t^3 \right] ⇝ 0$

### 幂级数

多项式函数$\mathrm{Poly}_{n}(x)$在点$x_0$处连续，且有$n$导数值，在点$x_0$处必可唯一展开成$n$阶幂级数。

$\mathrm{P}_{n}(x) = \sum\limits_{i=0}^n p_i · (x - x_0)^i = p_0 · (x - x_0)^0 + p_1 · (x - x_0)^1 + p_2 · (x - x_0)^2 + ··· + p_n · (x - x_0)^n$

$\mathrm{P}_{n}(x) = \sum\limits_{i=0}^{n} \dfrac{{^i}\mathrm{P}_{n}(x_0)}{i!} · (x - x_0)^{i} = \sum\limits_{i=0}^{n} \dfrac{\mathrm{d}^{i} \mathrm{P}_{n}(x_0)}{i! · \mathrm{d}^{i} x_0} · (x - x_0)^{i}$

|                                                              | ${^i}\mathrm{P}_{n} (x_0) = \left. {^i}\mathrm{P}_{n}(x) \right|_{x_0}$ | $\left. {^i}\mathrm{P}_{n}(x) \right|_{x_0} = i! · p_{i}$    | $\left. {^0}\mathrm{P}_{n}(x) \right|_{x_0} = 0! · p_0$      | $\left. {^1}\mathrm{P}_{n}(x) \right|_{x_0} = 1! · p_1$      | $\left. {^2}\mathrm{P}_{n}(x_0) \right|_{x_0} = 2! · p_2$    |
| :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\dfrac{\mathrm{d}^{i+1} \mathrm{P}_n(x)}{\mathrm{d}^{i+1} x} = \dfrac{\mathrm{d} }{\mathrm{d} x} \dfrac{\mathrm{d}^{i}\mathrm{P}_n(x)}{\mathrm{d}^{i} x}$ | $\dfrac{\mathrm{d}^i \mathrm{P}_{n}(x_0)}{\mathrm{d}^{i} x_0} = \left. \dfrac{\mathrm{d}^{i}\mathrm{P}_{n}(x)}{\mathrm{d}^{i} x} \right|_{x_0}$ | $\left. \dfrac{\mathrm{d}^{i} \mathrm{P}_n (x)}{\mathrm{d}^{i} x} \right|_{x_0} = i! · p_i$ | $\left. \dfrac{\mathrm{d}^{0} \mathrm{P}_{n}(x)}{\mathrm{d}^{0} x} \right|_{x_0} = 0! · p_0$ | $\left. \dfrac{\mathrm{d}^{1} \mathrm{P}_{n}(x)}{\mathrm{d}^{1} x} \right|_{x_0} = 1! · p_1$ | $\left. \dfrac{\mathrm{d}^{2} \mathrm{P}_{n}(x)}{\mathrm{d}^2 x} \right|_{x_0} = 2! · p_2$ |

任意的函数$f(x)$在点$x_0$处连续，若有$n+1$阶导数值则在点$x_0$处可唯一展开成$n$阶幂级数。

$f(x) = \sum\limits_{i=0}^{n} \dfrac{{^i}f(x_0)}{i!} · (x - x_0)^{i} + R_{n}(x) = f(x_0) + \dfrac{{^1}f(x_0)}{1!} · (x - x_0)^{1} + \dfrac{{^2}f(x_0)}{2!} · (x - x_0)^2 + ... + \dfrac{{^n}f(x_0)}{n!} · (x - x_0)^n + \mathrm{R}_{n}(x)$

$f(x) = \sum\limits_{i=0}^{n} \dfrac{\mathrm{d}^{i} f(x_0)}{1! · \mathrm{d}^{i} x_0} · (x - x_0)^{i} + R_{n}(x) = f(x_0) + \dfrac{\mathrm{d}^{1} f(x_0)}{1! · \mathrm{d}^1 x_0} · (x - x_0)^{1} + \dfrac{\mathrm{d}^{2} f(x_0)}{2! · \mathrm{d}^2 x_0} · (x - x_0)^{2} + ... + \dfrac{\mathrm{d}^{n} f(x_0)}{n! · \mathrm{d}^{n} x_0} · (x - x_0)^{n} + \mathrm{R}_{n}(x)$

$\mathrm{R}_{n}(x) = o(x - x_0)^{n} = f(x) - f(x_0) - \sum\limits_{i=1}^{n} \dfrac{{^i}f(x_0)}{i!} · (x - x_0)^{i} \mathop{====}\limits^{∃θ∈(x_0, x)} \dfrac{{^{n+1} } f(θ)}{(n + 1)!} · (x - x_0)^{n+1} \mathop{====}\limits^{∃θ∈(x_0, x)} \dfrac{{^{n+1} } f(θ)}{n!} · (x - θ)^{n} · (x - x_0)^{1} \mathop{====}\limits^{∃θ∈(x_0, x)} \int_{x_0}^{x} \dfrac{{^{n+1} } f(t)}{n!} · (x - t)^{n} \mathrm{d} t$

| $⇓$  | ${^m}\mathrm{R}_n(x) \mathop{====}\limits_{0≤m≤n} {^m}f(x) - {^m}f(x_0) - \sum\limits_{i=m+1}^{n} \dfrac{{^i}f(x_0)}{i!} · (x - x_0)^{i-m} · \dfrac{i!}{(i-m)!} = {^m}f(x) - {^m}f(x_0) - \sum\limits_{i=m+1}^{n} \dfrac{{^i}f(x_0)}{(i - m)!} · (x - x_0)^{i-m}$ | $⇒$  | $\lim\limits_{x⇝x_0} {^m}\mathrm{R}_n(x) ⇝ 0$ |
| :--: | :----------------------------------------------------------- | :--: | :-------------------------------------------- |
| $⇓$  | $\lim\limits_{x⇝x_0} \dfrac{\mathrm{R}_{n}(x)}{(x - x_0)^{n} } = \lim\limits_{x⇝x_0} \dfrac{(n - m)!}{n!} · \dfrac{{^m}\mathrm{R}_n(x)}{(x - x_0)^{n-m} } = \ldots = \lim\limits_{x⇝x_0}\dfrac{1!}{n!} · \dfrac{^{n-1}\mathrm{R}_n(x)}{(x - x_0)^1} = \lim\limits_{x⇝x_0} \dfrac{0!}{n!} · \dfrac{{^n}\mathrm{R}_n(x)}{(x - x_0)^{0} } ⇝ 0$ | $⇒$  | $\mathrm{R}_n(x) = o(x - x_0)^n$              |

| $⇓$  | $F (t) ≡ \sum\limits_{i=0}^n \dfrac{ {^i} f (t)}{i!} · (x - t)^i$ | $⇒$  | $\mathrm{R}_n (x) = F (x) - F (x_0)$                         |                                                       |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- | :---------------------------------------------------- |
| $⇓$  | ${^1} F (t) = \sum\limits_{i=0}^n \left[ \dfrac{ {^{i+1} } f (t)}{i!} · (x - t)^i - \dfrac{ {^i} f (t)}{i!} · i · (x - t)^{i-1} \right]$ |      |                                                              |                                                       |
| $⇓$  | $^{1}F(t) = \sum\limits_{i=1}^{n+1} \dfrac{{^i}f(t)}{(i - 1)!} · (x - t)^{i-1} - \sum\limits_{i=1}^{n} \dfrac{{^i}f(t)}{(i-1)!} · (x - t)^{i-1} = \dfrac{{^{n+1} }f(t)}{n!} · (x - t)^{n}$ |      |                                                              |                                                       |
| $⇓$  | $\dfrac{R_n (x)}{G (x) - G (x_0)} = \dfrac{F (x) - F (x_0)}{G (x) - G (x_0)} = \left.\dfrac{ {^1} F (t)}{ {^1} G (t)}\right|_{∃θ∈(x_0, x)} = \dfrac{ {^{n+1} } f (θ)}{n!} · \dfrac{(x - θ)^n}{ {^1} G (θ)} $ |      |                                                              |                                                       |
| $⇓$  | $\mathrm{R}_n (x) \mathop{====}\limits^{∃θ∈(x_0, x)} \dfrac{ {^{n+1} } f (θ)}{n!} · \dfrac{(x - θ)^n}{ {^1} G (θ)} · [G (x) - G (x_0)]$ |      |                                                              |                                                       |
| $⇓$  | $\mathrm{R}_n (x) \mathop{====}\limits^{∃θ∈(x_0, x)} \dfrac{ {^{n+1}f (θ)} }{(n + 1)!} · (x - x_0)^{n + 1}$ | $⇐$  | $G (t) ≡ (x - t)^{n + 1}$                                    | ${^1}G (t) = -(n + 1) · (x - t)^n$                    |
| $⇓$  | $\mathrm{R}_n (x) \mathop{====}\limits^{∃θ∈(x_0, x)} \dfrac{ {^{n+1}f (θ)} }{n!} · (x - θ)^n · (x - x_0)^1$ | $⇐$  | $G (t) ≡ (x - t)^1$                                          | ${^1}G (t) = -1$                                      |
| $⇓$  | $\mathrm{R}_n (x) \mathop{====}\limits^{∃θ∈(x_0, x)} \int\limits_{x_0}^x \dfrac{ {^{n+1} }f (t)}{n!} · (x - t)^n \mathrm{d} t$ | $⇐$  | $G (t) ≡ \int\limits_{x_0}^t \dfrac{ {^{n+1} }f (t)}{n!} · (x - t)^n \mathrm{d} t$ | ${^1}G (t) = \dfrac{ {^{n+1} }f (t)}{n!} · (x - t)^n$ |

典例：若函数$f(x)$在区间$X$上二阶导函数存在。

$\dfrac{\mathrm{d}^2 f(x)}{\mathrm{d}^2 x} = \lim\limits_{h⇝0} \dfrac{f(x+h) + f(x-h) - 2 · f(x)}{h^2}$

| $⇓$  | $f(x+h) = f(x) + \dfrac{\mathrm{d} f(x)}{1! · \mathrm{d} x} · h + \dfrac{\mathrm{d}^2 f(x)}{2! · \mathrm{d}^2 x} · h^2 + o_{+}(h^2)$ | $f(x-h) = f(x) - \dfrac{\mathrm{d} f(x)}{1! · \mathrm{d} x} · h + \dfrac{\mathrm{d}^2 f(x)}{2! · \mathrm{d}^2 x} · h^2 + o_{-}(h^2)$ |
| :--: | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $⇓$  | $\dfrac{\mathrm{d}^2 f(x)}{\mathrm{d}^2 x} = \dfrac{f(x+h) + f(x-h) - 2 · f(x)}{h^2} + \left[ o_{+}(h^2) +o_{-}(h^2) \right]$ |                                                              |
| $⇓$  | $\dfrac{\mathrm{d}^2 f(x)}{\mathrm{d}^2 x} = \lim\limits_{h⇝0} \dfrac{f(x+h) + f(x-h) - 2 · f(x)}{h^2}$ |                                                              |

典例：函数$g(x)$与函数$f(x)$之比的极限值。

$\lim\limits_{x⇝x_0} \dfrac{g(x)}{f(x)} \mathop{======}\limits_{{^h}f(x_0)\mathop{==}\limits^{h<n}0}^{{^h}g(x_0)\mathop{==}\limits^{h<m}0} \lim\limits_{x⇝x_0} \dfrac{\dfrac{{^m}g(x_0)}{m!}·(x - x_0)^{m} + o(x-x_0)^{m} }{\dfrac{{^n}f(x_0)}{n!}·(x - x_0)^{n} + o(x-x_0)^{n} } = \lim\limits_{x⇝x_0} (x - x_0)^{m-n} · \dfrac{\dfrac{{^m}g(x_0)}{m!} + \dfrac{o(x - x_0)^m}{(x - x_0)^m} }{\dfrac{{^n}f(x_0)}{n!} + \dfrac{o(x - x_0)^n}{(x - x_0)^n} } ⇝ \mathop{0}\limits_{m>n};\mathop{\dfrac{{^n}g(x_0)}{{^n}f(x_0)} }\limits_{m=n};\mathop{∞}\limits_{m<n}$

典例：函数$f(x) = x^{n+1} · \mathcal{Q}(x)$在点$x_0=0$处连续但仅有一阶导数值，因此在点$x_0=0$处可唯一展开成$1$阶幂级数。

${^1}f(0) = \lim\limits_{x⇝0} \dfrac{f(x) - f(0)}{x - 0} = \lim\limits_{x⇝0} \dfrac{x^{n+1}·\mathcal{Q}(x)}{x} ⇝ 0$

$f(x) = f(0) + \dfrac{{^1}f(0)}{1!} · (x - 0)^1 + R_{1}(x)= o(x^1)$

典例：函数$f(x) = \tan x$在点$x_0 = 0$处展开成$5$阶幂级数。

$\tan x = 1·x^1 + \dfrac{1}{3}·x^3 + \dfrac{2}{15}·x^5 + o(x^5)$

| $f(x)$     | $\dfrac{{^0}f(0)}{0!}·x^0 + \dfrac{{^1}f(0)}{1!}·x^1 + \dfrac{{^2}f(0)}{2!}·x^2 + \dfrac{{^3}f(0)}{3!}·x^3 + \dfrac{{^4}f(0)}{4!}·x^4 + \dfrac{{^5}f(0)}{5!}·x^5 + o(x^5)$ |
| :--------- | :----------------------------------------------------------- |
| ${^0}f(0)$ | $\left[ \tan x \right]_{x=0} = 0$                            |
| ${^1}f(0)$ | $\left[ \cos^{-2} x \right]_{x=0} = 1$                       |
| ${^2}f(0)$ | $\left[ 2·\cos^{-3} x · \sin^{1} x \right]_{x=0} = 0$        |
| ${^3}f(0)$ | $\left[ 6·\cos^{-4} x · \sin^{2} x + 2·\cos^{-2} x \right]_{x=0} = 2$ |
| ${^4}f(0)$ | $\left[ 24·\cos^{-5} x · \sin^{3} x + 16·\cos^{-3} x · \sin^{1} x \right]_{x=0} = 0$ |
| ${^5}f(0)$ | $\left[ 120·\cos^{-6} x · \sin^{4} x + 120·\cos^{-4} x · \sin^{2} x + 16·\cos^{-2} x \right]_{x=0} = 16$ |

典例：数列$s_n = \left(1 + \dfrac{0}{n^2}\right) · \left(1 + \dfrac{1}{n^2}\right) ··· \left(1 + \dfrac{n}{n^2}\right)$的极限值。

$\lim\limits_{n⇝∞^{+} } s_n = \lim\limits_{n⇝∞^{+} } \left(1 + \dfrac{0}{n^2}\right) · \left(1 + \dfrac{1}{n^2}\right) ··· \left(1 + \dfrac{n}{n^2}\right) ⇝ ә^{\frac{1}{2} }$

| $⇓$  | $x - \dfrac{x^2}{2} < \ln(1 + x) < x$                        | $⇐$  | $\ln(1+x) = \sum\limits_{i=\rlap{≡}{0,}1}^{∞^{+} } \dfrac{(-1)^{i-1} }{i} · x^i$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\sum\limits_{i=0}^{n} \dfrac{i}{n^2} - \sum\limits_{i=0}^{n} \dfrac{i^2}{2·n^{4} } < \sum\limits_{i=0}^{n} \ln\left(1 + \dfrac{i}{n^2}\right) < \sum\limits_{i=0}^{n} \dfrac{i}{n^2}$ | $⇐$  | $x = \dfrac{i}{n^2}$                                         |
| $⇓$  | $\dfrac{1}{n^2} · \left[ \dfrac{(n+1)^2}{2} - \dfrac{(n+1)^1}{2} \right] - \dfrac{1}{2·n^4} · \left[ \dfrac{(n+1)^3}{3} - \dfrac{(n+1)^2}{2} + \dfrac{(n+1)^1}{6} \right] < \ln s_n < \dfrac{1}{n^2} · \left[ \dfrac{(n+1)^2}{2} - \dfrac{(n+1)^1}{2} \right]$ | $⇐$  | $\sum\limits_{j=0}^{m} j^{1} = \dfrac{(m + 1)^{2} }{2} - \dfrac{(m + 1)^{1} }{2}$ |
| $⇓$  | $\lim\limits_{n⇝∞^{+} } s_n = \lim\limits_{n⇝∞^{+} } \left(1 + \dfrac{0}{n^2}\right) · \left(1 + \dfrac{1}{n^2}\right) ··· \left(1 + \dfrac{n}{n^2}\right) ⇝ ә^{\frac{1}{2} }$ | $⇐$  | $\sum\limits_{j=0}^{m} j^{2} = \dfrac{(m + 1)^3}{3} - \dfrac{(m + 1)^{2} }{2} + \dfrac{(m + 1)^{1} }{6}$ |

### 原函数

若存在函数$F(x)$，其导函数为$f(x)$，则称函数$F(x)$为函数$f(x)$的原函数。函数$f(x)$的全部原函数$F(x)$组成原函数族$\lbrace \tilde{F}(x) \rbrace = \left\lbrace ∀F; F(x) : \dfrac{\mathrm{d} F(x)}{\mathrm{d} x} = f(x) \right\rbrace$。

若函数$f(x)$存在原函数$F(x)$，则对函数$f(x)$作不定积分可得到函数$F(x)$的函数族$\lbrace \tilde{F}(x) \rbrace$。函数族$\lbrace \tilde{F}(x) \rbrace$中任意两个原函数$F_1(x)$与$F_2(x)$仅相差一个常数。

从几何上来看，函数$f(x)$的原函数族$\lbrace \tilde{F}(x) \rbrace$形成一系列沿纵坐标轴平移的曲线族，且曲线族在横坐标相同点处切线的斜率$\dfrac{\mathrm{d} }{\mathrm{d} x} [F(x) + \mathrm{Con}]$即为函数$f(x)$。

$\left[ f(x) = \dfrac{\mathrm{d} F(x)}{\mathrm{d} x} = \dfrac{\mathrm{d} }{\mathrm{d} x} [F(x) + \mathrm{Con}] \right] ⇔ \left[ \int f(x) \mathrm{d}x = \int \dfrac{\mathrm{d} F(x)}{\mathrm{d} x} \mathrm{d} x = F(x) + \mathrm{Con} \right]$

若函数$f(x)$的原函数$F(x)$满足特定的初始条件，则可唯一确定此原函数$F(x)$。

$\left[ y_0 = F(x_0) + \mathrm{Con} \right] ⇒ \left[ \mathrm{Con} = y_0 - F(x_0) \right]$

典例：质点作匀加速直线运动，加速度为$a = \dfrac{\mathrm{d} v(t)}{\mathrm{d} t} = \dfrac{\mathrm{d}^2 x(t)}{\mathrm{d}^2 t}$，初始速度为$v_0 = v(t_0)$，初始位移为$x_0 = x(t_0)$。

$v(t) = a·(t-t_0) + v_0$

$x(t) = \dfrac{a}{2} · (t - t_0)^2 + v_0 · (t - t_0) + x_0$

| $v(t) = \int \dfrac{\mathrm{d} v(t)}{\mathrm{d} t} \mathrm{d} t = \int a \mathrm{d}t = a·t + \mathrm{Con} = a·(t-t_0) + v_0$ | $⇐$  | $v_0 = v(t_0) = a·t_0+\mathrm{Con}$                          |
| :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $x(t) = \int \dfrac{\mathrm{d} x(t)}{\mathrm{d}t} \mathrm{d}t = \int v(t) \mathrm{d}t = \int [a · (t - t_0) + v_0] \mathrm{d} x = \dfrac{a}{2}·(t-t_0)^2 + v_0·t + \mathrm{Con} = \dfrac{a}{2} · (t - t_0)^2 + v_0 · (t - t_0) + x_0$ | $⇐$  | $x_0 = x(t_0) = \dfrac{a}{2}·(t - t_0)^2 + v_0·t+\mathrm{Con}$ |

不定积分的运算性质。

$\int \mathrm{Con} · f(x) \mathrm{d}x = \mathrm{Con} · \int f(x) \mathrm{d} x$

$\int [f(x) + g(x)] \mathrm{d}x = \int f(x) \mathrm{d} x + \int g(x) \mathrm{d} x$

$\int [f(x) - g(x)] \mathrm{d}x = \int f(x) \mathrm{d} x - \int g(x) \mathrm{d} x$

|                                                              |      |                                                              |
| :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $\dfrac{\mathrm{d} }{\mathrm{d} x} [\int \mathrm{Con} · f(x) \mathrm{d} x] = \mathrm{Con} · f(x)$ | $=$  | $\dfrac{\mathrm{d} }{\mathrm{d} x} [\mathrm{Con} · \int f(x) \mathrm{d} x] = \mathrm{Con} · \dfrac{\mathrm{d} }{\mathrm{d}x} [\int f(x) \mathrm{d} x] = \mathrm{Con} · f(x)$ |
| $\dfrac{\mathrm{d} }{\mathrm{d} x} \int [f(x) + g(x)]\mathrm{d}x = f(x) + g(x)$ | $=$  | $\dfrac{\mathrm{d} }{\mathrm{d} x} \left[ \int f(x) \mathrm{d} x + \int g(x) \mathrm{d} x \right] = \dfrac{\mathrm{d} }{\mathrm{d} x} \int f(x) \mathrm{d}x + \dfrac{\mathrm{d} }{\mathrm{d} x} \int g(x) \mathrm{d} x = f(x) + g(x)$ |
| $\dfrac{\mathrm{d} }{\mathrm{d} x} \int [f(x) - g(x)]\mathrm{d}x = f(x) - g(x)$ | $=$  | $\dfrac{\mathrm{d} }{\mathrm{d} x} \left[ \int f(x) \mathrm{d} x - \int g(x) \mathrm{d} x \right] = \dfrac{\mathrm{d} }{\mathrm{d} x} \int f(x) \mathrm{d}x - \dfrac{\mathrm{d} }{\mathrm{d} x} \int g(x) \mathrm{d} x = f(x) - g(x)$ |

对于任意函数$f(x)$，未必都存在原函数$F(x)$，使得$\dfrac{\mathrm{d} F(x)}{\mathrm{d} x} = f(x)$。

典例：有理函数$\mathcal{Q} (x) = \mathop{1}\limits_{x∈ℚ}; \mathop{0}\limits_{x∉ℚ}$不存在原函数$F(x)$，使得$\dfrac{\mathrm{d} F(x)}{\mathrm{d}x} = \mathcal{Q}(x)$。

若函数$f(x)$在区间$X$上的导函数存在，则函数$f(x)$的导函数$\dfrac{\mathrm{d} f(x)}{\mathrm{d} x}$在区间$X$上不存在跳跃间断点。$P⇒Q$

若函数$f(x)$在区间$X$上含有跳跃间断点，则函数$f(x)$不存在原函数$F(x)$，使得$\dfrac{\mathrm{d}F(x)}{\mathrm{d}x} = f(x)$。$¬Q⇒¬P$

| $⇓$  | $\dfrac{\mathrm{d} f(x_0^{-})}{\mathrm{d} x_0^{-} } = \dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x_0} = \dfrac{\mathrm{d} f(x_0^{+})}{\mathrm{d} x_0^{+} }$ | 假设在点$x_0$处导数值存在 |
| :--: | :----------------------------------------------------------- | :------------------------ |
| $⇓$  | $\dfrac{\mathrm{d} f(x_0^{-})}{\mathrm{d} x_0^{-} } = \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{x_0^{-} } ≠ \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{x_0^{+} } = \dfrac{\mathrm{d} f(x_0^{+})}{\mathrm{d} x_0^{+} }$ | $\mathrm{False}$          |

### 定积分

将区间$[x_α,x_β]$划分成$n+1$个子区间$[x_i,x_{i+1}]$，每个子区间长度为$Δx_i = x_{i+1} - x_i$，任取子区间内点$θ_i∈[x_i,x_{i+1}]$，有函数$f(x)$在区间$[x_α,x_β]$上的定积分和。

$\sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i,x_{i+1}]} f(x) · Δx_i ≤ \sum\limits_{i=0}^{n} f(θ_i) · Δx_i ≤ \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_{i},x_{i+1}]} f(x) · Δx_i$

对于函数$f(x)$，在将区间$[x_α,x_β]$划分成$n+1$个子区间$[x_i,x_{i+1}]$的基础上，多添加$m$个点再形成$m$个子区间，则其下积分和不减，且其上积分和不增。

对于函数$f(x)$，有任意多种将区间$[x_α,x_β]$划分成子区间的情形，但其下积分和始终小于等于其上积分和。此可理解为将任意两种划分情形互相叠加。

对于函数$f(x)$，无论在区间$[x_α,x_β]$上有任意多种划分情形，若其下积分和的极限等于上积分和的极限，则其积分和的极限存在且唯一，此即定积分。

$\sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i,x_{i+1}]} f(x) · Δx_i ≤ \sum\limits_{j=0}^{n+m} \inf\limits_{x∈[x_j,x_{j+1}]} f(x) · Δx_j ≤ \sum\limits_{j=0}^{n+m} f(θ_j) ·Δx_j ≤ \sum\limits_{j=0}^{n+m} \sup\limits_{x∈[x_{j},x_{j+1}]} f(x) · Δx_j ≤ \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_i,x_{i+1}]} f(x) · Δx_i$

$\sum\limits_{i=0}^{n} \inf\limits_{x∈[x_{i},x_{i+1}]} f (x) · Δx_i ≤ \rlap{≡≡≡≡≡≡≡≡≡≡≡≡≡}{\sum\limits_{j=0}^{n+m} \inf\limits_{x∈[x_{j},x_{j+1}]} f (x) · Δx_j} ≤ \sum\limits_{j=0}^{n+m} f (θ_j) · Δx_j ≤ \rlap{≡≡≡≡≡≡≡≡≡≡≡≡≡}{\sum\limits_{j=0}^{n+m} \sup\limits_{x∈[x_{j},x_{j+1}]} f (x) · Δx_j} ≤ \sum\limits_{k=0}^{m} \sup\limits_{x∈[x_{k},x_{k+1}]} f (x) · Δx_k$

$\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_{i},x_{i+1}]} f (x) · Δx_i ≤ \rlap{≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡}\varlimsup\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_{i},x_{i+1}]} f (x) · Δx_i ≤ \lim\limits_{n+m⇝∞⁺}^{Δx_j⇝0} \sum\limits_{j=0}^{n+m} f (θ_j) · Δx_j ≤ \rlap{≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡}\varliminf\limits_{m⇝∞⁺}^{Δx_k⇝0} \sum\limits_{k=0}^{m} \sup\limits_{x∈[x_{k},x_{k+1}]} f (x) · Δx_k ≤ \lim\limits_{m⇝∞⁺}^{Δx_k⇝0} \sum\limits_{k=0}^{m} \sup\limits_{x∈[x_{k},x_{k+1}]} f (x) · Δx_k$

| $⇓$  | $[x_{i}, x_{i+1}] = [x_{j}, x_{j+1}] ∪ [x_{j+1}, x_{j+2}]$   | $Δx_i = Δx_{j} + Δ_{j+1}$ |
| :--: | :----------------------------------------------------------- | ------------------------- |
| $⇓$  | $\inf\limits_{x∈[x_{i}, x_{i+1}]} f (x) ≤ \inf\limits_{x∈[x_{j}, x_{j+1}]} f (x), \inf\limits_{x∈[x_{j+1}, x_{j+2}]} f (x) ≤ f (x_{j+1}) ≤ \sup\limits_{x∈[x_{j}, x_{j+1}]} f (x), \sup\limits_{x∈[x_{j+1}, x_{j+2}]} f (x) ≤ \sup\limits_{x∈[x_i, x_{i+1}]} f (x)$ |                           |
| $⇓$  | $\inf\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_i ≤ \inf\limits_{x∈[x_j, x_{j+1}]} f (x) · Δx_{j} + \inf\limits_{x∈[x_{j+1}, x_{j+2}]} f (x) · Δx_{j+1}$ |                           |
| $⇓$  | $\sup\limits_{x∈[x_j, x_{j+1}]} f (x) · Δx_{j} + \sup\limits_{x∈[x_{j+1}, x_{j+2}]} f (x) · Δx_{j+1} ≤ \sup\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_{i}$ |                           |

对于函数$f (x)$，在将区间$[x_α,x_β]$划分成$n + 1$个子区间$[x_{i}, x_{i+1}]$的基础上，多添加$m$个点再形成$m$个子区间，则其振幅积和不增，且其振幅加和不减。

$0 ≤ \sum\limits_{j=0}^{n+m} \left[ \sup\limits_{x∈[x_j,x_{j+1}]} f(x) - \inf\limits_{x∈[x_j,x_{j+1}]} f(x) \right] · Δx_{j} ≤ \sum\limits_{i=0}^{n} \left[ \sup\limits_{x∈[x_i,x_{i+1}]} f(x) - \inf\limits_{x∈[x_i,x_{i+1}]} f(x) \right] · Δx_i = \sum\limits_{i=0}^{n} w_i · Δx_i$

$\sum\limits_{j=0}^{n+m} \left[ \sup\limits_{x∈[x_j,x_{j+1}]} f(x) - \inf\limits_{x∈[x_j,x_{j+1}]} f(x) \right] ≥ \sum\limits_{i=0}^{n} \left[ \sup\limits_{x∈[x_i,x_{i+1}]} f(x) - \inf\limits_{x∈[x_i,x_{i+1}]} f(x) \right] = \sum\limits_{i=0}^{n} w_i ≥ 0$

| $⇓$  | $[x_{i}, x_{i+1}] = [x_{j}, x_{j+1}] ∪ [x_{j+1}, x_{j+2}]$   |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $\inf\limits_{x∈[x_{i}, x_{i+1}]} f (x) ≤ \inf\limits_{x∈[x_{j}, x_{j+1}]} f (x), \inf\limits_{x∈[x_{j+1}, x_{j+2}]} f (x) ≤ f (x_{j+1}) ≤ \sup\limits_{x∈[x_{j}, x_{j+1}]} f (x), \sup\limits_{x∈[x_{j+1}, x_{j+2}]} f (x) ≤ \sup\limits_{x∈[x_i, x_{i+1}]} f (x)$ |
| $⇓$  | $\left[ \sup\limits_{x∈[x_{j},x_{j+1}]} f (x) - \inf\limits_{x∈[x_{j},x_{j+1}]} f (x) \right] + \left[ \sup\limits_{x∈[x_{j+1},x_{j+2}]} f (x) - \inf\limits_{x∈[x_{j+1},x_{j+2}]} f (x) \right] = \left[ \sup\limits_{x∈[x_{j},x_{j+1}]} f (x) - \inf\limits_{x∈[x_{j+1},x_{j+2}]} f (x) \right] + \left[ \sup\limits_{x∈[x_{j+1},x_{j+2}]} f (x) - \inf\limits_{x∈[x_{j},x_{j+1}]} f (x) \right] ≥ 0 + 0$ |
| $⇓$  | $\left[ \sup\limits_{x∈[x_{j},x_{j+1}]} f (x) - \inf\limits_{x∈[x_{j},x_{j+1}]} f (x) \right] + \left[ \sup\limits_{x∈[x_{j+1},x_{j+2}]} f (x) - \inf\limits_{x∈[x_{j+1},x_{j+2}]} f (x) \right] ≥ \left[ \sup\limits_{x∈[x_{i},x_{i+1}]} f (x) - \inf\limits_{x∈[x_{i},x_{i+1}]} f (x) \right]$ |

若函数$f(x)$在区间$[x_α,x_β]$上的定积分存在，则其下积分和的极限等于上积分和的极限，反之亦然。

若函数$f(x)$在区间$[x_α,x_β]$上的定积分存在，则其振幅积和的极限为零，反之亦然。

$\int\limits_{x_α}^{x_β} f(x) · \mathrm{d}x \mathop{≡≡≡≡}\limits_{x_{α}=x_0}^{x_{β}=x_{n+1} } \lim\limits_{n⇝∞^{+} }^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i,x_{i+1}]} f(x) · Δx_i = \lim\limits_{n⇝∞^+}^{Δx_i⇝0} \sum\limits_{i=0}^{n} f(θ_i) · Δx_i = \lim\limits_{n⇝∞^{+} }^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_i,x_{i+1}]} f(x) · Δx_i$

$0 ⇜ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n w_i · Δx_i ≡ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n \sup\limits_{u,v∈[x_{i}, x_{i+1}]} | f (u) - f (v) | · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \left[ \sup\limits_{x∈[x_{i},x_{i+1}]} f (x) - \inf\limits_{x∈[x_i,x_{i+1}]} f (x) \right] · Δx_i$

若函数$f(x)$在区间$[x_α,x_β]$上的定积分存在，则可任取子区间内点$θ_i$处函数值$f(θ_i)$为该子区间的平均值。

若函数$f(x)$在区间$[x_α,x_β]$上的定积分存在，则可将区间$[x_α,x_β]$按等间距$\dfrac{x_β-x_α}{n + 1}$划分成$n+1$个子区间。

若函数$f (x)$在区间$[x_α,x_β]$上的定积分存在，则当子区间的间距趋于零时，定积分与子区间的取值无关，定积分与子区间的划分无关。

$\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n f (θ_i) · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n f (x_i) · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n f (x_{i+1}) · Δx_i = \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^n f \left[ i · \dfrac{x_β - x_α}{n + 1} \right] · \dfrac{x_β - x_α}{n + 1} = \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} f \left[ (i + 1) · \dfrac{x_β - x_α}{n + 1} \right] · \dfrac{x_β - x_α}{n + 1}$

$\left[ 0 ⇜ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n w_i · Δx_i \right] ⇒ \left[ 0 ⇜ \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^n w_i · \dfrac{x_β - x_α}{n + 1} \right] ⇒\left[ 0 ⇜ \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^n \sup\limits_{u,v∈[x_i, x_{i+1}]} | f (u) - f (v) | · \dfrac{x_β - x_α}{n + 1} \right] ⇒ \left[ 0 ⇜ \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} | f (x_{i+1}) - f (x_{i}) | · \dfrac{x_β - x_α}{n + 1} \right]$

若函数$f(X)$在区间$[x_α,x_β]$上连续因此一致连续，则其振幅积和的极限为零。连续函数$f(x)$在区间$[x_α,x_β]$上的定积分必存在。

| $⇓$  | $∀ε>0;∃δ>0;∀u,v∈[x_α,x_β]; |u-v|≤δ ⇒ |f(u) - f(v)| ≤ ε$      | $⇔$  | $\lim\limits_{x⇝x_t} f (x) \mathop{↭}\limits_{x,x_t∈[x_α,x_β]} f (x_t)$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε>0;∃δ=\max \lbraceΔx_i\rbrace;\sup\limits_{u,v∈[x_i,x_{i+1}]} |f(u)-f(v)| ≤ ε$ |      |                                                              |
| $⇓$  | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_i,x_{i+1}]} | f (u) - f (v) | · Δx_i < ε · \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} Δx_i = ε · (x_β-x_α) ⇝ 0$ |      |                                                              |

若函数$f (x)$在区间$[x_α,x_β]$上的定积分存在，则函数$f (x)$在区间$[x_α,x_β]$上有确界，反之不对。

$\left[ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i ⇝ 0 \right] ⇒ \left[ f (x) ≤ \mathrm{Sup} \right]$

| $⇓$  | $0 ⇜ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i$ | $⇒$  | $0 ⇜ \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} w_i · \dfrac{x_β - x_α}{n + 1}$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $0 ⇜ \lim\limits_{n⇝∞⁺} \dfrac{\sup\limits_{x∈[x_α,x_β]} f (x) - \inf\limits_{x∈[x_α,x_β]} f (x)}{n + 1} · (x_β - x_α)$ | $⇐$  | $\sum\limits_{i=0}^n w_i = \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} | f (u) - f (v) | ≥ \sup\limits_{x∈[x_α,x_β]} f (x) - \inf\limits_{x∈[x_α,x_β]} f (x) ≥ 0$ |
| $⇓$  | $\sup\limits_{x∈[x_α,x_β]} f (x) - \inf\limits_{x∈[x_α,x_β]} f (x) ≠ ∞⁺$ |      |                                                              |
| $⇓$  | $\left[ \sup\limits_{x∈[x_α,x_β]} f (x) ≠ ∞⁺ \right] ∧ \left[ \inf\limits_{x∈[x_α,x_β]} f (x) ≠ ∞⁻ \right]$ | $⇒$  | $|f(x)| ≤ \mathrm{Sup} = \max\lbrace |\inf f(x)|,|\sup f(x)| \rbrace$ |

反例：函数$\mathcal{Q} (x) = \mathop{1}\limits_{x∈ℚ}; \mathop{0}\limits_{x∉ℚ}$在区间$[0, 1]$上有确界，但其定积分不存在。

$\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i, x_i+1]} \mathcal{Q} (x) · Δx_i = \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} 0 · Δx_i ⇝ 0 ≠ 1 ⇜ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n}  1 · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_i, x_{i+1}]} \mathcal{Q} (x) · Δx_i$

若函数$f(x)$在区间$[x_α,x_β]$上的定积分存在，则函数$f(x)$在区间$[x_α,x_β]$上的断点集为零测集，反之亦然。函数$f (x)$在区间$[x_α, x_β]$上几乎处处连续。

$\left[ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i ⇝ 0 \right] ⇔ \left[  ∀ε>0,𝜁>0; \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i≥ε} < 𝜁 \right]$

| $⇓$  | $∀ε>0,𝜁>0;$ | $ε · 𝜁 > \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n w_i · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{w_i · Δx_i}\limits_{w_i<ε} + \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^n \mathop{w_i · Δx_i}\limits_{w_i≥ε} ≥ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{w_i · Δx_i}\limits_{w_i≥ε} ≥ ε · \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i≥ε}$ |
| :--: | ----------: | ------------------------------------------------------------ |
| $⇓$  | $∀ε>0,𝜁>0;$ | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i≥ε} < 𝜁$ |
| $⇓$  | $∀ε>0,𝜁>0;$ | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{w_i · Δx_i}\limits_{w_i<ε} + \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{w_i · Δx_i}\limits_{w_i≥ε} ≤ ε · \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i<ε} + \sup\limits w_i · \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i≥ε} ≤ ε · (x_β - x_α) + \sup\limits w_i · 𝜁$ |
| $⇓$  | $∀ε>0,𝜁>0;$ | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i ⇝ 0$ |

特例：函数$\mathcal{R} (x) \mathop{======}\limits_{m∈ℤ;n∈ℤ^+}^{1 = \gcd (|m|, |n|)} \mathop{\dfrac{1}{n} }\limits_{x=\frac{m}{n} }; \mathop{0}\limits_{x≠\frac{m}{n} }$在区间$[0, 1]$上，任何无理点处连续，任何有理点处不连续，其断点集为零测集，因此其定积分存在。

$\int\limits_{0}^{1} \mathcal{R} (x) \mathrm{d} x = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i,x_{i+1}]} \mathcal{R} (x) · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} 0 · Δx_i ⇝ 0$

若函数$f^{⤨} (x)$在区间$[x_α, x_β]$上单调有确界，则其断点集为零测集，因此其定积分存在。

| $⇓$  | $0 ≤ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i ≤ ε · \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} w_i = ε · \left[ \sup\limits_{x∈[x_α,x_β]} f^{⤨} (x) - \inf\limits_{x∈[x_α,x_β]} f^{⤨} (x) \right]$ |
| :--: | ------------------------------------------------------------ |
| $⇓$  | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i · Δx_i ⇝ 0$ |
| $⇓$  | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i≥ε} ⇝ 0$ |

若函数$f (x)$在区间$[x_α, x_β]$上的定积分存在，则函数$| f (x) |$在区间$[x_α, x_β]$上的定积分存在，其断点集为零测集，反之不对。

若函数$f (x)$以及函数$g (x)$在区间$[x_α, x_β]$上的定积分存在，则函数$f (x) + g (x)$在区间$[x_α, x_β]$上的定积分存在，其断点集为零测集，反之不对。

若函数$f (x)$以及函数$g (x)$在区间$[x_α, x_β]$上的定积分存在，则函数$f (x) - g (x)$在区间$[x_α, x_β]$上的定积分存在，其断点集为零测集，反之不对。

若函数$f (x)$以及函数$g (x)$在区间$[x_α, x_β]$上的定积分存在，则函数$f (x) · g (x)$在区间$[x_α, x_β]$上的定积分存在，其断点集为零测集，反之不对。

若函数$f (x)$以及函数$g (x) ≠ 0$在区间$[x_α, x_β]$上的定积分存在，则函数$\dfrac{f (x)}{g (x)}$在区间$[x_α, x_β]$上的定积分存在，其断点集为零测集，反之不对。

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
| $⇓$  | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i^{\frac{f}{g} } · Δx_i ⇝ 0$ |
| $⇓$  | $∃ε>0;∃ε^f,ε^g>0; \left[ w_i^f < ε^f \right] ∧ \left[ w_i^g < ε^g \right] ⇒ \left[ w_i^{\frac{f}{g} } ≤ \left[ \dfrac{1}{\inf | g (x) |} · w_i^f + \dfrac{\sup | f (x) |}{\inf | g^2 (x) |} · w_i^g \right] < \dfrac{1}{\inf | g (x) |} · ε^f + \dfrac{\sup | f (x) |}{\inf | g^2 (x) |} · ε^g = ε \right]$ |
| $⇓$  | $∃ε>0;∃ε^f,ε^g>0; \left[ ε ≤ w_i^{\frac{f}{g} } \right] ⇒ \left[ ε^f ≤ w_i^f \right] ∨ \left[ ε^g ≤ w_i^g \right]$ |
| $⇓$  | $\mathcal{O}^{\frac{f}{g} } ⊆ \mathcal{\mathcal{O}^{f} } ∪ \mathcal{O}^{g}$ |

特例：函数$f (x) = \mathop{1}\limits_{x∈ℚ};\mathop{-1}\limits_{x∉ℚ}$在区间$[0, 1]$上的定积分不存在，其断点集非为零测集。但函数$| f (x) | = 1$在区间$[0, 1]$上的定积分存在。

若函数$g(y)$在区间$[y_α, y_β]$上连续，且函数$y = f(x)$在区间$[x_α, x_β]$上的定积分存在，则复合函数$g(f(x))$在区间$[x_α, x_β]$上的定积分存在，其断点集为零测集。

若函数$g(y)$在区间$[y_α, y_β]$上的定积分存在，且函数$y = f(x)$在区间$[x_α, x_β]$上连续因此定积分存在，则复合函数$g(f(x))$在区间$[x_α, x_β]$上的定积分未必存在。

若函数$g(y)$在区间$[ y_α, y_β ]$上的定积分存在，且函数$y = f(x)$在区间$[x_α, x_β]$上的定积分存在，则复合函数$g(f(x))$在区间$[x_α, x_β]$上的定积分未必存在。

| $⇓$  |                | $\left[ \lim\limits_{y⇝y_0} g(y) \mathop{⇝}\limits_{y,y_0∈[x_α,x_β]} g(y_0) \right] ⇔ \left[ \lim\limits_{y↭y_t} g(y)\mathop{↭}\limits_{y,y_0∈[x_α,x_β]}g(y_t) \right]$ |
| :--: | -------------: | :----------------------------------------------------------- |
| $⇓$  |   $∀ε>0;∃δ>0;$ | $\sup\limits_{|y-y_t|≤δ} | g(y) - g(y_t) | ≤ ε $             |
| $⇓$  |   $∀ε>0;∃δ>0;$ | $\sup\limits_{|f(x)-f(x_t)|≤δ} | g(f(x)) - g(f(x_t)) | ≤ ε $ |
| $⇓$  |   $∀𝜁>0;∀δ>0;$ | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i^{f}>δ} < 𝜁$ |
| $⇓$  | $∀ε,𝜁>0;∃δ>0;$ | $0 ≤ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} | g (f (u)) - g (f (v)) | · Δx_i = \lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} \mathop{| g (f (u)) - g (f (v)) | · Δx_i}\limits_{|f(u)-f(v)|≤w_i^{f}≤δ} + \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} \mathop{| g(f(u)) - g(f(v)) | · Δx_i}\limits_{w_i^f>δ}$ |
| $⇓$  | $∀ε,𝜁>0;∃δ>0;$ | $0 ≤ \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{u,v∈[x_{i},x_{i+1}]} | g (f(u)) - g(f(v)) | · Δx_i < ε · \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i^{f}≤δ} + \mathrm{Sup} · \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \mathop{Δx_i}\limits_{w_i^{f}>δ} < ε · (x_β - x_α) + \mathrm{Sup} · 𝜁 ⇝ 0$ |
| $⇓$  |                | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_{i}^{g∘f} · Δx_i ⇝ 0$ |
|      |                |                                                              |
| $⇓$  |   $∀ε>0;∃δ>0;$ | $\sup\limits_{|f(x)-f(x_t)|≤δ} | g (f (x)) - g (f (x_t)) | ≤ ε $ |
| $⇓$  |   $∃ε>0;∃δ>0;$ | $[ w_i^{f} ≤ δ ] ⇒ [ w_i^{g∘f} ≤ ε ]$                        |
| $⇓$  |   $∃ε>0;∃δ>0;$ | $[ w_i^{g∘f} > ε ] ⇒ [ w_i^{f} > δ ]$                        |
| $⇓$  |                | $\mathcal{O}^{g∘f} ⊆ \mathcal{O}^{f}$                        |

反例：函数$\mathrm{sgn} (y) = \mathop{-1}\limits_{y<0};\mathop{0}\limits_{y=0};\mathop{+1}\limits_{y>0}$在区间$[0, 1]$上的定积分存在，函数$\mathcal{F} (x) ≡ \mathop{I_i - \left| x - X_{i,j} \right|}\limits_{| x - X_{i,j} | < I_{i} }; \mathop{0}\limits_{| x - X_{i,j} | ≥ I_{i} }$在区间$[0, 1]$上连续因此定积分存在。

但复合函数$\mathrm{sgn} (\mathcal{F} (x)) = \mathop{1}\limits_{|x-X_{i,j}|<I_i};\mathop{0}\limits_{|x-X_{i,j}|≥I_i}$在区间$[0, 1]$上的断点集非为零测集，其定积分不存在。

反例：函数$\mathrm{sgn} (y) = \mathop{-1}\limits_{y<0};\mathop{0}\limits_{y=0};\mathop{+1}\limits_{y>0}$在区间$[0, 1]$上的定积分存在，函数$\mathcal{R} (x) \mathop{======}\limits_{m∈ℤ;n∈ℤ^+}^{1 = \gcd (|m|, |n|)} \mathop{\dfrac{1}{n} }\limits_{x=\frac{m}{n} }; \mathop{0}\limits_{x≠\frac{m}{n} }$在区间$[0, 1]$上的定积分存在。

但复合函数$\mathrm{sgn} (\mathcal{R} (x)) = \mathcal{Q} (x) = \mathop{1}\limits_{x∈Q}; \mathop{0}\limits_{x∉Q}$在区间$[0, 1]$上的断点集非为零测集，其定积分不存在。

### 定积分的运算性质

定积分的积分区间下限与积分区间上限对换时，约定定积分的正负性对换。

| $\int\limits_{x_α}^{x_β} f (x) \mathrm{d} x = - \int\limits_{x_β}^{x_α} f (x) \mathrm{d} x$ |      |                                                              |
| :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $\int\limits_{x_α}^{x_α} f (x) \mathrm{d} x = 0$             | $⇐$  | $\int\limits_{x_α}^{x_α} f (x) \mathrm{d} x = - \int\limits_{x_α}^{x_α} f (x) \mathrm{d} x$ |
| $\int\limits_{x_α}^{x_β} f (x) \mathrm{d} x = \int\limits_{x_α}^{x_γ} f (x) \mathrm{d} x + \int\limits_{x_γ}^{x_β} f (x) \mathrm{d} x$ |      |                                                              |
| $\int\limits_{x_α}^{x_β} \mathrm{Con} · f (x) \mathrm{d} x = \mathrm{Con} · \int\limits_{x_α}^{x_β} f (x) \mathrm{d} x$ |      |                                                              |
| $\int\limits_{x_α}^{x_β} [ f (x) + g (x) ] \mathrm{d} x = \int\limits_{x_α}^{x_β} f (x) \mathrm{d} x + \int\limits_{x_α}^{x_β} g (x) \mathrm{d} x$ |      |                                                              |
| $\int\limits_{x_α}^{x_β} [ f (x) - g (x) ] \mathrm{d} x = \int\limits_{x_α}^{x_β} f (x) \mathrm{d} x - \int\limits_{x_α}^{x_β} g (x) \mathrm{d} x$ |      |                                                              |
| $[ f (x) ≤ g (x) ] ⇒ \left[ \int\limits_{x_α}^{x_β} f (x) \mathrm{d} x ≤ \int\limits_{x_α}^{x_β} g (x) \mathrm{d} x \right]$ |      |                                                              |
| $[ 0 ≤ g (x) ] ⇒ \left[ 0 ≤ \int\limits_{x_α}^{x_β} g (x) \mathrm{d} x \right]$ | $⇐$  | $f (x) = 0$                                                  |
| $[ f (x) ≤ g (x) ] ∧ \left[ \lim\limits_{x⇝x_0} f (x) ⇝ f (x_0) < g (x_0) ⇜ \lim\limits_{x⇝x_0} g (x) \right] ⇒ \left[ \int\limits_{x_α}^{x_β} f (x) \mathrm{d} x < \int\limits_{x_α}^{x_β} g (x) \mathrm{d} x \right]$ | $⇐$  | $\left[ \int\limits_{x_α}^{x_0-δ} + \int\limits_{x_0-δ}^{x_0+δ} + \int\limits_{x_0+δ}^{x_β} \right] [ f (x) - g (x) ] \mathrm{d} x < 0$ |
| $[ 0 ≤ g (x) ] ∧ \left[ 0 < g (x_0) ⇜ \lim\limits_{x⇝x_0} g (x) \right] ⇒ \left[ 0 < \int\limits_{x_α}^{x_β} g (x) \mathrm{d} x \right]$ | $⇐$  | $f (x) = 0$                                                  |
| $[ 0 ≤ g (x) ] ∧ \left[ 0 = \int\limits_{x_α}^{x_β} g (x) \mathrm{d} x \right] ⇒ \left[ 0 = g (x_0) ⇜ \lim\limits_{x⇝x_0} g (x) \right]$ | $⇐$  | $[ P ∧ Q ⇒ R ] ⇔ [ P ∧ ¬R ⇒ ¬Q ]$                            |
| $\left| \int\limits_{x_α}^{x_β} f (x) \mathrm{d} x \right| ≤ \int\limits_{x_α}^{x_β} | f (x) | \mathrm{d} x$ | $⇐$  | $- \int\limits_{x_α}^{x_β} | f (x) | \mathrm{d} x ≤ \int\limits_{x_α}^{x_β} f (x) \mathrm{d} x ≤ + \int\limits_{x_α}^{x_β} | f (x) | \mathrm{d} x$ |

### 微积分基本定理

若函数$f(x)$在区间$[x_α,x_β]$上的定积分存在，则其变上限积分与其变下限积分存在，其变上限积分与其变下限积分可互相转换。

$\mathrm{U}_{x_α}^{f}(x) = \int\limits_{x_α}^{x} f(x) · \mathrm{d} x$

$\mathrm{L}_{x_β}^{f}(x) = \int\limits_{x}^{x_β} f(x) · \mathrm{d} x$

$\mathrm{U}_{x_γ}^{f}(x) = \int\limits_{x_γ}^{x} f(x)·\mathrm{d}x = -\int\limits_{x}^{x_γ} f(x)·\mathrm{d}x = -\mathrm{L}_{x_γ}^{f}(x)$

若函数$f(x)$在区间$[x_α,x_β]$上的定积分存在，因此函数$f(x)$在区间$[x_α,x_β]$上有确界，则其变上限积分$\mathrm{U}(x)$在区间$[x_α,x_β]$上连续。

$\left[ \int\limits_{x_α}^{x_β} f(x) · \mathrm{d} x = \lim\limits_{n⇝∞^+}^{Δx_i⇝0} \sum\limits_{i=0}^{n} f(θ_i) · Δx_i \right] ⇒ \left[ \lim\limits_{x⇝x_0} \mathrm{U}(x) ⇝ \mathrm{U}(x_0) \right]$

| $⇓$  | $\left[ \int\limits_{x_α}^{x_β} f(x) · \mathrm{d} x = \lim\limits_{n⇝∞^+}^{Δx_i⇝0} \sum\limits_{i=0}^{n} f(θ_i) · Δx_i \right] ⇒ \left[ f(x) ≤ \mathrm{Sup} \right]$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∀x_0∈[x_α,x_β];∀ε>0;∃δ>0;∀x∈[x_α,x_β]; |\mathrm{U}(x) - \mathrm{U}(x_0)| = \left| \int\limits_{x_α}^{x} f(x) · \mathrm{d}x - \int\limits_{x_α}^{x_0} f(x) · \mathrm{d} x \right| = \left| \int\limits_{x_0}^{x} f(x) · \mathrm{d}x \right| ≤ \mathrm{Sup} · \left| \int\limits_{x_0}^{x} \mathrm{d}x \right| = \mathrm{Sup}· (x - x_α) = \mathrm{Sup} · δ = ε$ |
| $⇓$  | $\lim\limits_{x⇝x_0} \mathrm{U}(x) ⇝ \mathrm{U}(x_0)$        |

若函数$f(x)$在区间$[x_α,x_β]$上连续，则其变上限积分$\mathrm{U}(x)$为函数$f(x)$的原函数，且同理其变下限积分$\mathrm{L}(x)$为函数$f(x)$的原函数。

$\dfrac{\mathrm{d} }{\mathrm{d} x} \int\limits_{x_α}^{x} f(x) · \mathrm{d} x = \dfrac{\mathrm{d} \mathrm{U}(x)}{\mathrm{d}x} = f(x)$

$\dfrac{\mathrm{d} }{\mathrm{d}x} \int\limits_{v(x)}^{u(x)} f(x) ·\mathrm{d}x = \dfrac{\mathrm{d} \mathrm{U}(u(x))}{\mathrm{d} x} - \dfrac{\mathrm{d}\mathrm{U}(v(x))}{\mathrm{d}x} = f(u(x)) · {^1}u(x) - f(v(x)) · {^1} v(x)$

| $⇓$  | $∀x_0∈[x_α,x_β];∀ε>0;∃δ>0;∀x_t∈[x_α,x_β]; |x_t - x_0| ≤ δ ⇒ |f(x_t) - f(x_0)| ≤ε$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $\left| \dfrac{\mathrm{U}(x_t) - \mathrm{U}(x_0)}{x_t - x_0} - f(x_0) \right| = \left| \dfrac{\int\limits_{x_α}^{x_t} f(x) · \mathrm{d}x - \int\limits_{x_α}^{x_0} f(x)·\mathrm{d}x}{x_t - x_0} - f(x_0) \right| = \left| \dfrac{\int\limits_{x_0}^{x_t} f(x)·\mathrm{d}x - \int\limits_{x_0}^{x_t} f(x_0)·\mathrm{d}x}{x_t - x_0} \right| ≤ \left| \dfrac{\int\limits_{x_0}^{x_t} |f(x)-f(x_0)|·\mathrm{d}x}{x_t - x_0} \right| ≤ \dfrac{ε·\left|\int\limits_{x_0}^{x_t} \mathrm{d}x \right|}{|x_t - x_0|} = ε$ |
| $⇓$  | $\dfrac{\mathrm{d} }{\mathrm{d} x} \int\limits_{x_α}^{x} f(x) · \mathrm{d} x = \dfrac{\mathrm{d} \mathrm{U}(x)}{\mathrm{d}x} = f(x)$ |
|      |                                                              |
| $⇓$  | $\int\limits_{v(x)}^{u(x)} f(x) ·\mathrm{d}x = \int\limits_{x_γ}^{u(x)} f(x) · \mathrm{d}x + \int\limits_{v(x)}^{x_γ} f(x) · \mathrm{d}x = \int\limits_{x_γ}^{u(x)} f(x) · \mathrm{d} x - \int\limits_{x_γ}^{v(x)} f(x) · \mathrm{d} x = \mathrm{U}(u(x)) - \mathrm{U}(v(x))$ |
| $⇓$  | $\dfrac{\mathrm{d} }{\mathrm{d}x} \int\limits_{v(x)}^{u(x)} f(x) ·\mathrm{d}x = \dfrac{\mathrm{d} \mathrm{U}(u(x))}{\mathrm{d} x} - \dfrac{\mathrm{d}\mathrm{U}(v(x))}{\mathrm{d}x} = \dfrac{\mathrm{d}\mathrm{U}(u)}{\mathrm{d}u} · \dfrac{\mathrm{d}u(x)}{\mathrm{d}x} - \dfrac{\mathrm{d}\mathrm{U}(v)}{\mathrm{d}v} ·\dfrac{\mathrm{d}v(x)}{\mathrm{d}x} = f(u(x)) · {^1}u(x) - f(v(x)) · {^1} v(x)$ |

若函数$f(x)$在区间$[x_α,x_β]$上连续，则其在区间$[x_α,x_β]$上的定积分为其任意原函数在该两端点处的差值。【微积分基本定理】

$\int\limits_{x_α}^{x_β} f(x) · \mathrm{d}x = F(x_β) - F(x_α) = \left. F(x) \right|_{x_α}^{x_β}$

| $⇓$  | $\int\limits_{x_α}^{x_β} f(x) · \mathrm{d}x \mathop{====}\limits_{\mathrm{U}(x_α) = 0} \mathrm{U}(x_β) - \mathrm{U}(x_α) = [\mathrm{U}(x_β) + \mathrm{Con}] - [\mathrm{U}(x_α)+\mathrm{Con}] = F(x_β) - F(x_α) = \left. F(x) \right|_{x_α}^{x_β}$ |
| :--: | :----------------------------------------------------------- |
|      |                                                              |

典例：计算定积分$\int\limits_{0}^{π} \sin x · \mathrm{d}x$。

$\left[ \int\limits_{x_α}^{x_β} \sin x · \mathrm{d} x = [-\cos x]_{x_α}^{x_β} \right] ⇒ \left[ \int\limits_{0}^{π} \sin x · \mathrm{d}x = [-\cos x]_{0}^{π} = 2 \right]$

典例：计算极限值$\lim\limits_{n⇝∞^{+} } \dfrac{1^{p}+2^{p}+···+n^{p} }{n^{p+1} }$。

$\lim\limits_{n⇝∞^{+} } \dfrac{1^{p}+2^{p}+···+n^{p} }{n^{p+1} } = \lim\limits_{n⇝∞^{+} } \left[ \left(\dfrac{1}{n}\right)^{p} + \left( \dfrac{2}{n} \right)^{p} + ··· + \left( \dfrac{n}{n} \right)^{p} \right] · \dfrac{1}{n} \mathop{===}\limits^{p>-1} \int\limits_{0}^{1} x^{p} · \mathrm{d} x = \left[ \dfrac{x^{p+1} }{p+1} \right]_{0}^{1} = \dfrac{1}{p + 1}$

换元积分法。

$\int\limits_{x_α}^{x_β} g(f(x))·{^1}f(x) · \mathrm{d}x = \int\limits_{x_α}^{x_β} g(f(x)) · \mathrm{d} f(x) \mathop{====}\limits_{t_α=f(x_α)}^{t_β = f(x_β)} \int\limits_{t_α}^{t_β} g(t) · \mathrm{d}t$

分部积分法。

$\int\limits_{x_α}^{x_β} u(x) · \mathrm{d}v(x) = [u(x)·v(x)]_{x_α}^{x_β} - \int\limits_{x_α}^{x_β} v(x) ·\mathrm{d} u(x)$

$\int\limits_{x_α}^{x_β} u(x) ·{^1}v(x) · \mathrm{d}x = [u(x)·v(x)]_{x_α}^{x_β} - \int\limits_{x_α}^{x_β} {^1}u(x) · v(x) · \mathrm{d} x$

| $⇓$  | $\int\limits_{x_α}^{x_β} g(f(x)) · {^1}f(x) · \mathrm{d} x = \int\limits_{x_α}^{x_β} g(f(x)) · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} · \mathrm{d}x = \int\limits_{x_α}^{x_β} g(f(x)) · \mathrm{d} f(x) \mathop{====}\limits_{t_α=f(x_α)}^{t_β=f(x_β)} \int\limits_{t_α}^{t_β} g(t) · \mathrm{d} t$ |      |                                                              |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
|      |                                                              |      |                                                              |
| $⇓$  | $\mathrm{d}[u(x) · v(x)] = u(x) · \mathrm{d} v(x) + v(x) · \mathrm{d} u(x)$ | $⇔$  | $\dfrac{\mathrm{d} }{\mathrm{d} x} [u(x) · v(x)] = \dfrac{\mathrm{d} u(x)}{\mathrm{d} x} · v(x) + u(x) · \dfrac{\mathrm{d} v(x)}{\mathrm{d} x}$ |
| $⇓$  | $[u(x) · v(x)]_{x_α}^{x_β} = \int\limits_{x_α}^{x_β} \mathrm{d}[u(x) · v(x)] = \int\limits_{x_α}^{x_β} u(x) · \mathrm{d} v(x) + \int\limits_{x_α}^{x_β} v(x) · \mathrm{d} u(x)$ |      |                                                              |
| $⇓$  | $\int\limits_{x_α}^{x_β} u(x) · \mathrm{d}v(x) = [u(x)·v(x)]_{x_α}^{x_β} - \int\limits_{x_α}^{x_β} v(x) ·\mathrm{d} u(x)$ |      |                                                              |
| $⇓$  | $\int\limits_{x_α}^{x_β} u(x) ·{^1}v(x) · \mathrm{d}x = [u(x)·v(x)]_{x_α}^{x_β} - \int\limits_{x_α}^{x_β} {^1}u(x) · v(x) · \mathrm{d} x$ |      |                                                              |

分部积分法的升降幂型式。

$\int\limits_{x_α}^{x_β} {^0}u(x) · {^{n+1} }v(x) · \mathrm{d}x = \left[ \sum\limits_{i=0}^{n} (-1)^{n} ·{^i}u(x) ·{^{n-i} }v(x) \right]_{x_α}^{x_β} + (-1)^{n+1} \int\limits_{x_α}^{x_β} {^{n+1} }u(x) · {^0}v(x) ·\mathrm{d}x$

| $\int\limits_{x_α}^{x_β} {^0}u(x) · {^{n+1} }v(x) · \mathrm{d}x$ | $= \left[ {^0}u(x)·{^n}v(x) \right]_{x_α}^{x_β} - \int_{x_α}^{x_β} {^1}u(x) ·{^n}v(x) · \mathrm{d} x$ |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
|                                                              | $= \left[ ^{0}u(x)·{^n}v(x) - {^1}u(x) · {^{n-1} }v(x) \right]_{x_α}^{x_β} + \int\limits_{x_α}^{x_β} {^2}u(x) ·{^{n-1} }v(x) ·\mathrm{d} x$ |
|                                                              | $= \left[ \sum\limits_{i=0}^{n} (-1)^{n} ·{^i}u(x) ·{^{n-i} }v(x) \right]_{x_α}^{x_β} + (-1)^{n+1} \int\limits_{x_α}^{x_β} {^{n+1} }u(x) · {^0}v(x) ·\mathrm{d}x$ |

典例：应用换元积分法，计算$\int \tan x · \mathrm{d}x$。

$\int_x \tan x · \mathrm{d}x = \int_x \dfrac{\sin x}{\cos x} · \mathrm{d}x = \int_x \dfrac{-1}{\cos x} · \mathrm{d} \cos x \mathop{====}\limits^{t=\cos x} \int_t \dfrac{-1}{t} · \mathrm{d} t = -\ln|t| + \mathrm{Con} = -\ln |\cos x| + \mathrm{Con}$

典例：应用换元积分法，计算$\int \dfrac{1}{x^2 - a^2} · \mathrm{d}x$。

$\int_x \dfrac{1}{x^2 - a^2} · \mathrm{d}x = \dfrac{1}{2 · a} · \int_x \left[ \dfrac{1}{x - a} - \dfrac{1}{x + a} \right] \mathrm{d} x = \dfrac{1}{2·a} · \left[ \int_x \dfrac{\mathrm{d}(x-a)}{x-a} - \int_x \dfrac{\mathrm{d}(x+a)}{x + a} \right] \mathop{===}\limits_{s=x+a}^{t=x-a} \dfrac{1}{2·a} · \int_t \dfrac{\mathrm{d}t}{t} - \dfrac{1}{2·a} · \int_s \dfrac{\mathrm{d}s}{s} = \dfrac{1}{2·a} · \left[ \ln |t| - \ln|s| \right] + \mathrm{Con}= \dfrac{1}{2·a}· \ln \left| \dfrac{x-a}{x+a} \right| + \mathrm{Con}$

典例：应用换元积分法，计算$\int \dfrac{1}{\sqrt{x^2 - a^2} } · \mathrm{d}x$。已知$\int \dfrac{1}{\sqrt{x^2 - 1} } · \mathrm{d}x = {'}\cosh x + \mathrm{Con}$。

$\int \dfrac{1}{\sqrt{x^2 - a^2} } · \mathrm{d}x = \int \dfrac{1}{\sqrt{\frac{x^2}{a^2} - 1^2} } · \mathrm{d} \dfrac{x}{a} \mathop{==}\limits^{t=\frac{x}{a} } {'}\cosh t + \mathrm{Con}_0 = {'}\cosh \dfrac{x}{a} + \mathrm{Con}_0 = \ln\left( \dfrac{x}{a} + \sqrt{\dfrac{x^2}{a^2} - 1} \right) + \mathrm{Con}_0 = \ln \left( x + \sqrt{x^2 + a^2} \right) + \mathrm{Con}$

典例：应用分部积分法$x$降幂型式，计算$\int x· ә^{-x} · \mathrm{d}x$。

$\int x· ә^{-x} · \mathrm{d}x = -\int x · \mathrm{d} ә^{-x} = -x · ә^{-x} + \intә^{-x} · \mathrm{d} x = -x·ә^{-x} + \int \mathrm{d}ә^{-x} = -x·ә^{-x} + ә^{-x} + \mathrm{Con}$

典例：应用分部积分法$x$升幂型式，计算$\int x · \ln x · \mathrm{d}x$。

$\int x · \ln x · \mathrm{d}x = \dfrac{1}{2} · \int \ln x · \mathrm{d} x^2 = \dfrac{1}{2} · \left[ x^2 · \ln x - \int x^2 · \mathrm{d}\ln x \right] \mathop{=====}\limits^{\mathrm{d}\ln x = \frac{1}{x}·\mathrm{d}x} \dfrac{1}{2} · x^2 · \ln x - \dfrac{1}{2} · \int x · \mathrm{d} x = \dfrac{1}{2} · x^2 · \ln x - \dfrac{1}{4} ·x^2 + \mathrm{Con}$

典例：应用分部积分法循环型式，计算$\int \sqrt{x^2 - a^2}·\mathrm{d}x$。已知$\int \dfrac{1}{\sqrt{x^2 - a^2} } · \mathrm{d}x = {'}\cosh \dfrac{x}{a} + \mathrm{Con}$。

$\int \sqrt{x^2 - a^2}·\mathrm{d}x = x · \sqrt{x^2 - a^2} - \int x · \mathrm{d} \sqrt{x^2 - a^2} = x · \sqrt{x^2 + a^2} - \int x · \dfrac{2·x}{2\sqrt{x^2-a^2} } \mathrm{d}x = x· \sqrt{x^2 - a^2} - \int \dfrac{(x^2 - a^2)+a^2}{\sqrt{x^2 - a^2} } · \mathrm{d}x = x·\sqrt{x^2-a^2} - \int \sqrt{x^2-a^2} · \mathrm{d}x - a^2 · \int \dfrac{1}{\sqrt{x^2 - a^2} } · \mathrm{d}x$

$\int \sqrt{x^2-a^2} = \dfrac{x·\sqrt{x^2-a^2} }{2} - \dfrac{a^2}{2} · {'}\cosh \dfrac{x}{a} + \mathrm{Con}$

典例：应用分部积分法递推型式，计算$\int \cos^n x · \mathrm{d}x$。

$\int \cos^n x · \mathrm{d}x = \int \cos^{n-1} x · \mathrm{d} \sin x = \cos^{n-1} x · \sin x - \int \sin x · \mathrm{d} \cos^{n-1} x = \cos^{n-1} x · \sin x + (n - 1) · \int \cos^{n-2}x · \sin^2 x ·\mathrm{d} x \mathop{=======}\limits^{\sin^2 x = 1 - \cos^2 x} \cos^{n-1} x · \sin x +(n-1) · \int [\cos^{n-2} x - \cos^n x]·\mathrm{d}x$

$\int \cos^{n} x · \mathrm{d} x = \dfrac{1}{n} · \cos^{n-1}x· \sin x + \dfrac{n - 1}{n} · \int \cos^{n-2}x·\mathrm{d}x$

若函数$f(x)$为奇函数且定积分存在，则$\int\limits_{-x_γ}^{+x_γ} f(x) · \mathrm{d}x = 0$。

若函数$f(x)$为偶函数且定积分存在，则$\int\limits_{-x_γ}^{+x_γ} f(x) · \mathrm{d} x = 2 · \int\limits_{0}^{+x_γ} f(x) · \mathrm{d}x$。

若函数$f(x)$为周期函数且定积分存在，则$\int\limits_{x_γ}^{x_γ+T} f(x) · \mathrm{d} x = \int\limits_{0}^{T} f(x) · \mathrm{d} x$。

| $⇓$  | $\int\limits_{-x_γ}^{+x_γ} f(x) · \mathrm{d} x = \int\limits_{-x_γ}^{0} f(x) · \mathrm{d} x + \int\limits_{0}^{+x_γ} f(x) · \mathrm{d} x \mathop{===}\limits^{x=-t} \int\limits_{x_γ}^{0} f(-t) · \mathrm{d}(-t) + \int\limits_{0}^{x_γ} f(x) · \mathrm{d} x \mathop{======}\limits^{f(-t)=-f(t)} \int\limits_{0}^{x_γ} -f(t) · \mathrm{d}t + \int\limits_{0}^{x_γ} f(x)·\mathrm{d}x$ |
| :--: | :----------------------------------------------------------- |
|      |                                                              |
| $⇓$  | $\int\limits_{-x_γ}^{+x_γ} f(x) · \mathrm{d} x = \int\limits_{-x_γ}^{0} f(x)· \mathrm{d}x + \int\limits_{0}^{+x_γ} f(x) · \mathrm{d} x \mathop{===}\limits^{x=-t} \int\limits_{x_γ}^{0} f(-t)·\mathrm{d}(-t) + \int\limits_{0}^{x_γ} f(x) · \mathrm{d} x \mathop{======}\limits^{f(-t)=+f(t)} \int\limits_{0}^{x_γ} +f(t) · \mathrm{d}t + \int\limits_{0}^{x_γ} f(x)·\mathrm{d}x$ |
|      |                                                              |
| $⇓$  | $\int\limits_{T}^{x_γ+T} f(x) · \mathrm{d} x \mathop{====}\limits^{x=t+T} \int\limits_{0}^{x_γ} f(t+T) · \mathrm{d}(t+T) \mathop{======}\limits^{f(t+T)=f(t)} \int\limits_{0}^{x_γ} f(t) · \mathrm{d}t$ |
| $⇓$  | $\int\limits_{x_γ}^{x_γ+T} f(x) · \mathrm{d} x = \int\limits_{x_γ}^{0} f(x) · \mathrm{d}x + \int\limits_{0}^{T} f(x) · \mathrm{d}x + \int\limits_{T}^{x_γ+T} f(x) · \mathrm{d}x = -\int\limits_{0}^{x_γ} f(x) · \mathrm{d}x + \int\limits_{0}^{T} f(x) · \mathrm{d}x + \int\limits_{0}^{x_γ} f(x) · \mathrm{d}x = \int\limits_{0}^{T} f(x) · \mathrm{d}x$ |

### 积分中值定理

错位积和公式。

$\inf F (x) · g^{↘_0} (x_α) ≤ \int\limits_{x_α}^{x} f (θ_{i}) · g^{↘_0} (θ_{i}) · Δx_i ≤ \sup F (x) · g^{↘_0} (x_α)$

$\inf F (x) · g^{↗^0} (x_α) ≥ \int\limits_{x_α}^{x} f (θ_{i}) · g^{↗^0} (θ_{i}) · Δx_i ≥ \sup F (x) · g^{↗^0} (x_α)$

$\inf F (x) · g^{↗_0} (x_β) ≤ \int\limits_{x}^{x_β} f (θ_{i}) · g^{↗_0} (θ_{i}) · Δx_i ≤ \sup F (x) · g^{↗_0} (x_β)$

$\inf F (x) · g^{↘^0} (x_β) ≥ \int\limits_{x}^{x_β} f (θ_{i}) · g^{↘^0} (θ_{i}) · Δx_i ≥ \sup F (x) · g^{↘^0} (x_β)$

| $⇓$  | $F(x_{n+1}) \mathop{≡≡≡≡≡≡}\limits_{x_i≤θ_i≤x_{i+1} }^{x_α≤θ_i≤x} \sum\limits_{i=0}^{n} f(θ_i) · Δx_i$ |      | $\int\limits_{x_α}^{x} f (x) \mathrm{d} x = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} F(x_{n+1})$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\sum\limits_{i=n}^{m} f (θ_{i}) · g (θ_{i}) · Δx_i = \sum\limits_{i=n}^{m} [ F (x_{i+1}) - F (x_{i}) ] · g (θ_{i}) = F (x_{m+1}) · g (θ_{m}) + \sum\limits_{i=n}^{m-1} F (x_{i+1}) · g (θ_{i}) - \sum\limits_{i=n}^{m-1} F (x_{i+1}) · g (θ_{i+1}) - F (x_{n}) · g (θ_{n})$ |      |                                                              |
| $⇓$  | $\sum\limits_{i=0}^{m} f (θ_{i}) · g (θ_{i}) · Δx_i = [ F (x_{m+1}) · g (θ_{m}) - \rlap{≡≡≡≡≡≡≡}{F (x_{0}) · g (θ_{0})} ] + \sum\limits_{i=0}^{m-1} F (x_{i+1}) · [ g (θ_{i}) - g (θ_{i+1}) ]$ | $⇐$  | $F (x_{0}) ≡ 0$                                              |
| $⇓$  | $\sum\limits_{i=0}^{m} f (θ_i) · g^{↘_0} (θ_i) · Δx_i ≤ \sup F (x) · g^{↘_0} (θ_{m}) + \sup F (x) · \sum\limits_{i=0}^{m-1} [ g^{↘_0} (θ_{i}) - g^{↘_0} (θ_{i+1}) ] = \sup F (x) · g^{↘_0} (θ_0)$ | $⇐$  | $g^{↘_0} (θ_{i}) ≥ g^{↘_0} (θ_{i+1}) ≥ 0$                    |
| $⇓$  | $\sum\limits_{i=0}^{m} f (θ_i) · g^{↘_0} (θ_i) · Δx_i ≥ \inf F (x) · g^{↘_0} (θ_{m}) + \inf F (x) · \sum\limits_{i=0}^{m-1} [ g^{↘_0} (θ_{i}) - g^{↘_0} (θ_{i+1}) ] = \inf F (x) · g^{↘_0} (θ_{0})$ | $⇐$  | $g^{↘_0} (θ_{i}) ≥ g^{↘_0} (θ_{i+1}) ≥ 0$                    |
| $⇓$  | $\inf F (x) · g^{↘_0} (x_α) ≤ \int\limits_{x_α}^{x} f (θ_{i}) · g^{↘_0} (θ_{i}) · Δx_i ≡ \lim\limits_{m⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{m} f (θ_{i}) · g^{↘_0} (θ_{i}) · Δx_i ≤ \sup F (x) · g^{↘_0} (x_α)$ | $⇐$  | $x_0 = x_α$                                                  |
| $⇓$  | $\inf F (x) · g^{↗^0} (x_α) ≥ \int\limits_{x_α}^{x} f (θ_{i}) · g^{↗^0} (θ_{i}) · Δx_i ≡ \lim\limits_{m⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{m} f (θ_{i}) · g^{↗^0} (θ_{i}) · Δx_i ≥ \sup F (x) · g^{↗^0} (x_α)$ | $⇐$  | $g^{↗^0} (x) ≡ (-1) · h^{↘_0} (x)$                           |
|      |                                                              |      |                                                              |
| $⇓$  | $F(x_{n+1}) \mathop{≡≡≡≡≡≡}\limits_{x_i≤θ_i≤x_{i+1} }^{x≤θ_i≤x_β} \sum\limits_{i=0}^{n} f(θ_i) · Δx_i$ |      | $\int\limits_{x}^{x_β} f (x) \mathrm{d} x = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} F(x_{n+1})$ |
| $⇓$  | $\sum\limits_{i=n}^{m} f (θ_{i}) · g (θ_{i}) · Δx_i = \sum\limits_{i=n}^{m} [ F (x_{i+1}) - F (x_{i}) ] · g (θ_{i}) = F (x_{m+1}) · g (θ_{m}) + \sum\limits_{i=n}^{m-1} F (x_{i+1}) · g (θ_{i}) - \sum\limits_{i=n}^{m-1} F (x_{i+1}) · g (θ_{i+1}) - F (x_{n}) · g (θ_{n})$ |      |                                                              |
| $⇓$  | $\sum\limits_{i=0}^{m} f (θ_{i}) · g (θ_{i}) · Δx_i = [ F (x_{m+1}) · g (θ_{m}) - \rlap{≡≡≡≡≡≡≡}{F (x_{0}) · g (θ_{0})} ] + \sum\limits_{i=0}^{m-1} F (x_{i+1}) · [ g (θ_{i}) - g (θ_{i+1}) ]$ | $⇐$  | $F (x_{0}) ≡ 0$                                              |
| $⇓$  | $\sum\limits_{i=0}^{m} f (θ_i) · g^{↗_0} (θ_i) · Δx_i ≤ \sup F (x) · g^{↗_0} (θ_{m}) + \sup F (x) · \sum\limits_{i=0}^{m-1} [ g^{↗_0} (θ_{i}) - g^{↗_0} (θ_{i+1}) ] = \sup F (x) · g^{↗_0} (θ_0)$ | $⇐$  | $0 ≤ g^{↗_0} (θ_{i+1}) ≤ g^{↗_0} (θ_{i})$                    |
| $⇓$  | $\sum\limits_{i=0}^{m} f (θ_i) · g^{↗_0} (θ_i) · Δx_i ≥ \inf F (x) · g^{↗_0} (θ_{m}) + \inf F (x) · \sum\limits_{i=0}^{m-1} [ g^{↗_0} (θ_{i}) - g^{↗_0} (θ_{i+1}) ] = \inf F (x) · g^{↗_0} (θ_0)$ | $⇐$  | $0 ≤ g^{↗_0} (θ_{i+1}) ≤ g^{↗_0} (θ_{i})$                    |
| $⇓$  | $\inf F (x) · g^{↗_0} (X_1) ≤ \int\limits_{x}^{x_β} f (θ_{i}) · g^{↗_0} (θ_{i}) · Δx_i ≡ \lim\limits_{m⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{m} f (θ_i) · g^{↗_0} (θ_i) · Δx_i ≤ \sup F (x) · g^{↗_0} (X_1)$ | $⇐$  | $x_0 = x_β$                                                  |
| $⇓$  | $\inf F (x) · g^{↘^0} (X_1) ≥ \int\limits_{x}^{x_β} f (θ_{i}) · g^{↘^0} (θ_{i}) · Δx_i ≡ \lim\limits_{m⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{m} f (θ_i) · g^{↘^0} (θ_i) · Δx_i ≥ \sup F (x) · g^{↘^0} (X_1)$ | $⇐$  | $g^{↘^0} (x) ≡ (-1) · h^{↗_0} (x)$                           |

若函数$f (x)$在区间$[x_α,x_β]$上连续，函数$g (x)$在区间$[x_α,x_β]$上连续，则必至少存在一点$θ∈(x_α, x_β)$使得成立。[积分第一中值定理]

$\int\limits_{x_α}^{x_β} f (x) · g (x) \mathrm{d} x = \left. f (x) \right|_{∃θ∈(x_α, x_β)} · \int\limits_{x_α}^{x_β} g (x) \mathrm{d} x$

$\int\limits_{x_α}^{x_β} f (x) \mathrm{d} x = \left. f (x) \right|_{∃θ∈[x_α,x_β]} · (x_β-x_α)$

| $⇓$  | $F (x) ≡ \int\limits_{x_α}^{x} f (x) · g (x) \mathrm{d} x$   | $⇒$  | $F (x_α) = 0; F (x_β) = \int\limits_{x_α}^{x_β} f (x) · g (x) \mathrm{d} x$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $G (x) ≡ \int\limits_{x_α}^{x} g (x) \mathrm{d} x$           | $⇒$  | $G (x_α) = 0; G (x_β) = \int\limits_{x_α}^{x_β} g (x) \mathrm{d} x$ |
| $⇓$  | $\dfrac{\int\limits_{x_α}^{x_β} f (x) · g (x) \mathrm{d} x}{\int\limits_{x_α}^{x_β} g (x) \mathrm{d} x} = \dfrac{F (x_β) - F (x_α)}{G (x_β) - G (x_α)} = \left. \dfrac{\mathrm{d} F (x)}{\mathrm{d} G (x)} \right|_{∃θ∈[x_α, x_β]} = \left. \dfrac{f (x) · g (x)}{g (x)} \right|_{∃θ∈[x_α, x_β]} = \left. f (x) \right|_{∃θ∈[x_α, x_β]}$ |      |                                                              |
| $⇓$  | $\int\limits_{x_α}^{x_β} f (x) · g (x) \mathrm{d} x = \left. f (x) \right|_{∃θ∈[x_α, x_β]} · \int\limits_{x_α}^{x_β} g (x) \mathrm{d} x$ |      |                                                              |
| $⇓$  | $\int\limits_{x_α}^{x_β} f (x) \mathrm{d} x = \left. f (x) \right|_{∃θ∈[x_α, x_β]} · (x_β - x_α)$ | $⇐$  | $g (x) ≡ 1$                                                  |

若函数$f^{⤨} (x)$在区间$[x_α, x_β]$上连续且单调，函数$g (x)$在区间$[x_α, x_β]$上连续，则必至少存在一点$θ∈[x_α,x_β]$使得成立。[积分第二中值定理]

$\int\limits_{x_α}^{x_β} f (x) · g^{↘_0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[x_α,x_β]} g^{↘_0} (x_α) · \int\limits_{x_α}^{θ} f (x) \mathrm{d} x$

$\int\limits_{x_α}^{x_β} f (x) · g^{↗^0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[x_α,x_β]} g^{↗^0} (x_α) · \int\limits_{x_α}^{θ} f (x) \mathrm{d} x$

$\int\limits_{x_α}^{x_β} f (x) · g^{↗_0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[x_α,x_β]} g^{↗_0} (x_β) · \int\limits_{θ}^{x_β} f (x) \mathrm{d} x$

$\int\limits_{x_α}^{x_β} f (x) · g^{↘^0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[x_α,x_β]} g^{↘^0} (x_β) · \int\limits_{θ}^{x_β} f (x) \mathrm{d} x$

$\int\limits_{x_α}^{x_β} f (x) · g^{⤨} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[x_α,x_β]} g^{⤨} (x_α) · \int\limits_{x_α}^{θ} f (x) \mathrm{d} x + g^{⤨} (x_β) · \int\limits_{θ}^{x_β} f (x) \mathrm{d} x$

| $⇓$  |                                                              |      | $∀F (x)∈[\inf F (x), \sup F (x)];∃θ∈[x_α,x_β]; F (x) = F (θ)$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\int\limits_{x_α}^{x_β} f (x) · g^{↘_0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[x_α,x_β]} g^{↘_0} (x_α) · \int\limits_{x_α}^{θ} f (x) \mathrm{d} x$ | $⇐$  | $\inf F (x) · g^{↘_0} (x_α) ≤ \int\limits_{x_α}^{x} f (θ_{i}) · g^{↘_0} (θ_{i}) · Δx_i ≤ \sup F (x) · g^{↘_0} (x_α)$ |
| $⇓$  | $\int\limits_{x_α}^{x_β} f (x) · g^{↗^0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[x_α,x_β]} g^{↗^0} (x_α) · \int\limits_{x_α}^{θ} f (x) \mathrm{d} x$ | $⇐$  | $\inf F (x) · g^{↗^0} (x_α) ≥ \int\limits_{x_α}^{x} f (θ_{i}) · g^{↗^0} (θ_{i}) · Δx_i ≥ \sup F (x) · g^{↗^0} (x_α)$ |
| $⇓$  | $\int\limits_{x_α}^{x_β} f (x) · g^{↗_0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[x_α,x_β]} g^{↗_0} (x_β) · \int\limits_{θ}^{x_β} f (x) \mathrm{d} x$ | $⇐$  | $\inf F (x) · g^{↗_0} (x_β) ≤ \int\limits_{x}^{x_β} f (θ_{i}) · g^{↗_0} (θ_{i}) · Δx_i ≤ \sup F (x) · g^{↗_0} (x_β)$ |
| $⇓$  | $\int\limits_{x_α}^{x_β} f (x) · g^{↘^0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[x_α,x_β]} g^{↘^0} (x_β) · \int\limits_{θ}^{x_β} f (x) \mathrm{d} x$ | $⇐$  | $\inf F (x) · g^{↘^0} (x_β) ≥ \int\limits_{x}^{x_β} f (θ_{i}) · g^{↘^0} (θ_{i}) · Δx_i ≥ \sup F (x) · g^{↘^0} (x_β)$ |
|      |                                                              |      |                                                              |
| $⇓$  | $h^{↘_0} (x) ≡ \dfrac{g^{⤨} (x) - g^{⤨} (x_β)}{g^{⤨} (x_α) - g^{⤨} (x_β)}$ | $⇒$  | $\int\limits_{x_α}^{x_β} h^{↘_0} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[x_α,x_β]} h^{↘_0} (x_α) · \int\limits_{x_α}^{θ} f (x) \mathrm{d} x$ |
| $⇓$  | $\int\limits_{x_α}^{x_β} f (x) · \dfrac{g^{⤨} (x) - g^{⤨} (x_β)}{g^{⤨} (x_α) - g^{⤨} (x_β)} \mathrm{d} x \mathop{=====}\limits^{∃θ∈[x_α,x_β]} 1 ·  \int\limits_{X_0}^{θ} f (x) \mathrm{d} x$ | $⇐$  | $h^{↘_0} (x_α) = 1$                                          |
| $⇓$  | $\int\limits_{x_α}^{x_β} f (x) · g^{⤨} (x) \mathrm{d} x \mathop{=====}\limits^{∃θ∈[x_α,x_β]} g^{⤨} (x_α) · \int\limits_{x_α}^{θ} f (x) \mathrm{d} x + g^{⤨} (x_β) · \int\limits_{θ}^{x_β} f (x) \mathrm{d} x$ |      |                                                              |

