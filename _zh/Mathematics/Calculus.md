---
layout:  zh_post
Topic :  收敛极限
Title :  微积分
Update:  2021-05-02T21:20:00+08@中国-广东-湛江+08
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
| 正无穷大 | $∞⁺$ | $|∞| = ∞⁺$ | $\dfrac{1}{0⁺} = ∞⁺$ | $\dfrac{1}{∞⁺} = 0⁺$ | $\lim\limits_{n⇝∞⁺} (+1) · n ⇝ ∞⁺$  | $x_0 + ∞⁺ \mathop{=}\limits_{x_0≠∞⁻} ∞⁺$ | $x_0 - ∞⁺ \mathop{=}\limits_{x_0≠∞⁺} ∞⁻$ | $(+|x_0|) · ∞⁺ \mathop{=}\limits_{x_0≠0} ∞⁺$ | $(-|x_0|) · ∞⁺ \mathop{=}\limits_{x_0≠0} ∞⁻$ |
| 负无穷大 | $∞⁻$ | $∞⁻ = -∞⁺$ | $\dfrac{1}{0⁻} = ∞⁻$ | $\dfrac{1}{∞⁻} = 0⁻$ | $\lim\limits_{n⇝∞⁺} (-1) · n ⇝ ∞⁻$  | $x_0 + ∞⁻ \mathop{=}\limits_{x_0≠∞⁺} ∞⁻$ | $x_0 - ∞⁻ \mathop{=}\limits_{x_0≠∞⁻} ∞⁺$ | $(+|x_0|) · ∞⁻ \mathop{=}\limits_{x_0≠0} ∞⁻$ | $(-|x_0|) · ∞⁻ \mathop{=}\limits_{x_0≠0} ∞⁺$ |

点$x_0$的闭邻域$\mathrm{U}_{X}(x_0, δ)$由属于区域$X$中的点构成，点$x_0$未必属于区域$X$。点$x_0$的任意闭邻域$\mathrm{U}_{X}(x_0)$与其任意补邻域$¬\mathrm{U}_{X}(x_0)$之间没有交集。

聚敛点是极限性质，孤立点是离散性质。边界点要么为孤立点，要么为聚敛点。区域$X$的闭包集$\fbox{X}$由区域$X$本身以及其所有边界点共同构成。

极大值与极小值是局部性质，最大值与最小值是全局性质，上确界与下确界是极限性质。最大值与最小值是离散性质，上确界与下确界是连续性质。

上确界是所有上界的最小值，下确界是所有下界的最大值。上确界与下确界始终存在且唯一确定，因此上极限与下极限始终存在且唯一确定。

|   右闭领域 | $\mathrm{U}_{X}(x_0^{+},δ)$ | $∀x∈X; [x∈\mathrm{U}_{X}(x_0^{+}, δ)] ⇔ [0≤x-x_0≤+δ]$        |                                                  |
| ---------: | :-------------------------- | ------------------------------------------------------------ | :----------------------------------------------- |
|   左闭邻域 | $\mathrm{U}_{X}(x_0^{-},δ)$ | $∀x∈X; [x∈\mathrm{U}_{X}(x_0^{-}, δ)] ⇔ [-δ≤x-x_0≤0]$        |                                                  |
|     闭邻域 | $\mathrm{U}_{X}(x_0, δ)$    | $∀x∈X; [ | x - x_0 | ≤ δ ] ⇔ [ x∈\mathrm{U}(x_0, δ) ]$       | $\mathrm{U}_{X}(x_0) ⋂ ¬\mathrm{U}_{X}(x_0) = 𝟘$ |
|     补邻域 | $¬\mathrm{U}_{X}(x_0, δ)$   | $∀x∉X;[ | x - x_0 | ≤ δ ] ⇔ [ x∈¬\mathrm{U}(x_0, δ) ]$       | $\mathrm{U}_{X}(x_0) ⋃ ¬\mathrm{U}_{X}(x_0) = 𝟙$ |
|     闭包集 | $\fbox{X}$                  | $∀x_0; [ ∀δ>0; \mathrm{U}(x_0, δ) ≠ 𝟘 ] ⇔ \left[ x_0∈\fbox{X} \right]$ | $\fbox{X}⊇X$                                     |
|     聚敛点 | $x_0∈\fbox{X}$              | $∀δ>0; \mathrm{U}(x_0, δ) ≠ 𝟘$                               |                                                  |
|     孤立点 | $x_0∈X$                     | $∃δ>0; \mathrm{U}(x_0, δ) = \lbrace x_0 \rbrace$             |                                                  |
|     边界点 | $x_0∈\fbox{X}$              | $∀δ>0; [ \mathrm{U}(x_0,δ) ≠ 𝟘 ] ∧ [ ¬\mathrm{U}(x_0,δ) ≠ 𝟘 ]$ |                                                  |
|     内敛点 | $x_0∈X$                     | $∃δ>0; \mathrm{U}(x_0, δ) ⊆ X$                               |                                                  |
|   全闭区域 | $[X_0, X_1]$                | $∀δ>0; \mathrm{U}(X_0, δ) ≠ 𝟘$                               | $X = \fbox{X}$                                   |
|   全开区域 | $(X_0, X_1)$                | $∀δ>0; \mathrm{U}(X_0, δ) ≠ 𝟘$                               | $X ≠ \fbox{X}$                                   |
|   半闭区域 | $[X_0, X_1); (X_0, X_1]$    | $∀δ>0; \mathrm{U}(X_0, δ) ≠ 𝟘$                               | $X ≠ \fbox{X}$                                   |
|            |                             |                                                              |                                                  |
|     最大值 | $m ≡ \max\limits_{m∈S} S$   | $[ ∃m∈S;∀a∈S; m ≥ a ] ⇔ [ ∃m∈S;∀a∈S; m ≤ a ⇒ m = a ]$        |                                                  |
|     最小值 | $m ≡ \min\limits_{m∈S} S$   | $[ ∃m∈S;∀a∈S; m ≤ a ] ⇔ [ ∃m∈S;∀a∈S; m ≥ a ⇒ m = a ]$        |                                                  |
|     极大值 | $m ≡ \max\limits_{m∈S⊆T} S$ | $[ ∃m∈S;∀a∈S; m ≥ a ] ⇔ [ ∃m∈S;∀a∈S; m ≤ a ⇒ m = a ]$        |                                                  |
|     极小值 | $m ≡ \min\limits_{m∈S⊆T} S$ | $[ ∃m∈S;∀a∈S; m ≤ a ] ⇔ [ ∃m∈S;∀a∈S; m ≥ a ⇒ m = a ]$        |                                                  |
|     上确界 | $s ≡ \sup S$                | $[ ∃s∈\fbox{S};∀a∈S; a ≤ s ] ⇔ [∃s;∀o;∀a∈S; a ≤ s ∧ [a ≤ o ⇒ s ≤ o]]$ |                                                  |
|     上确界 | $s ≡ \sup S$                | $[ ∃s;∀a∈S;∃e∈S; a ≤ s ∧ [ a < s ⇒ a < e ] ] ⇔ [ ∃s;∀a∈S;∀ε>0;∃e∈S; a ≤ s ∧ s - ε < e]$ |                                                  |
|     下确界 | $s ≡ \inf S$                | $[ ∃s∈\fbox{S};∀a∈S; a ≥ s ] ⇔[∃s;∀o;∀a∈S; a ≥ s ∧ [a ≥ o ⇒ s ≥ o]]$ |                                                  |
|     下确界 | $s ≡ \inf S$                | $[ ∃s;∀a∈S;∃e∈S; a ≥ s ∧ [ a > s ⇒ a > e ] ] ⇔ [ ∃s;∀a∈S;∀ε>0;∃e∈S; a ≥ s ∧ s + ε > e]$ |                                                  |
| 严格最大值 | $m ≡ \max\limits_{m∈S} S$   | $[ ∃m∈S;∀a∈S \backslash m; m > a ]$                          |                                                  |
| 严格最小值 | $m ≡ \min\limits_{m∈S} S$   | $[ ∃m∈S;∀a∈S \backslash m; m < a ]$                          |                                                  |
| 严格极大值 | $m ≡ \max\limits_{m∈S⊆T} S$ | $[ ∃m∈S;∀a∈S \backslash m; m > a ]$                          |                                                  |
| 严格极小值 | $m ≡ \min\limits_{m∈S⊆T} S$ | $[ ∃m∈S;∀a∈S \backslash m; m < a ]$                          |                                                  |


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
|       右极限 | $\lim\limits_{x⇝x_0^+} f(x) ⇝ f_{x_0^+}$                     | $Ⅎx_0∈\fbox{X};∀ε>0;∃δ>0;∀x∈X; 0 ≤ x - x_0 ≤ +δ ⇒ |f(x) - f_{x_0^+}| ≤ ε$ |
|       左极限 | $\lim\limits_{x⇝x_0^-} f(x) ⇝ f_{x_0^-}$                     | $Ⅎx_0∈\fbox{X};∀ε>0;∃δ>0;∀x∈X; -δ ≤ x - x_0 ≤ 0 ⇒ |f(x) - f_{x_0^-}| ≤ ε$ |
|       极限值 | $\lim\limits_{x⇝x_0} f(x) ⇝ f_{x_0}$                         | $Ⅎx_0∈\fbox{X};∀ε>0;∃δ>0;∀x∈\mathrm{U}_{X}(x_0,δ); |f(x) - f_{x_0}| ≤ ε$ |
|       极限值 | $\lim\limits_{x⇝x_0} f(x) ⇝ f_{x_0}$                         | $\lim\limits_{x⇝x_0^-} f(x) ⇝ f_{x_0^-} = f_{x_0} = f_{x_0^+} ⇜ \lim\limits_{x⇝x_0^+} f(x)$ |
|       极限值 | $\lim\limits_{x⇝x_0} f(x) ⇝ ∞^{±},∞$                         | $\lim\limits_{x⇝x_0} \dfrac{1}{f(x)} ⇝ 0^{±},0$              |
|       极限值 | $\lim\limits_{x⇝∞^{±},∞} f(x) ⇝ f_{∞^{±}}$                   | $\lim\limits_{\frac{1}{x}⇝0^{±},0} f(x) ⇝ f_{∞^{±}}$         |
|       上极限 | $f_{x_0} ≡ \varlimsup\limits_{x⇝x_0} f (x)$                  | $f_{x_0} ≡ \lim\limits_{δ⇝0} \sup\limits_{x∈\mathrm{U}(x_0,δ)} f(x)$ |
|       下极限 | $f_{x_0} ≡ \varliminf\limits_{x⇝x_0} f (x)$                  | $f_{x_0} ≡ \lim\limits_{δ⇝0} \inf\limits_{x∈\mathrm{U}(x_0,δ)} f(x)$ |
|   唯一极限值 | $f_{x_0} = \varliminf\limits_{x⇝x_0} f(x) = \varlimsup\limits_{x⇝x_0} f(x)$ | $f_{x_0} = \lim\limits_{δ⇝0} \inf\limits_{x∈\mathrm{U}(x_0,δ)} f(x) = \lim\limits_{δ⇝0} \sup\limits_{x∈\mathrm{U}(x_0,δ)} f(x)$ |
|              |                                                              |                                                              |
|     单调递增 | $f^{↗} (x)$                                                  | $[∀x_1,x_2∈X; [ x_1 < x_2 ] ⇒ [ f^{↗} (x_1) ≤ f^{↗} (x_2)]]$ |
|     单调递减 | $f^{↘} (x)$                                                  | $[∀x_1,x_2∈X; [ x_1 < x_2 ] ⇒ [ f^{↘} (x_1) ≥ f^{↘} (x_2)]]$ |
| 严格单调递增 | $f^{↑} (x)$                                                  | $[∀x_1,x_2∈X; [ x_1 < x_2 ] ⇒ [ f^{↑} (x_1) < f^{↑} (x_2)]]$ |
| 严格单调递减 | $f^{↓} (x)$                                                  | $[∀x_1,x_2∈X; [ x_1 < x_2 ] ⇒ [ f^{↓} (x_1) > f^{↓} (x_2)]]$ |

| $∀x∈[X_0, X_1]; | f (x) | ≤ ε$ | $⇔$  | $\sup\limits_{x∈[X_0,X_1]} | f (x) | ≤ ε$ |                                                     | $∃x∈[X_0,X_1]; | f (x) | > ε$ | $⇔$  | $\sup\limits_{x∈[X_0,X_1]} | f (x) | > ε$ |
| -----------------------------: | :--: | :---------------------------------------- | :-------------------------------------------------: | ----------------------------: | :--: | :---------------------------------------- |
|  $∀x∈[X_0,X_1]; | f (x) | < ε$ | $⇔$  | $\sup\limits_{x∈[X_0,X_1]} | f (x) | < ε$ |                                                     | $∃x∈[X_0,X_1]; | f (x) | ≥ ε$ | $⇔$  | $\sup\limits_{x∈[X_0,X_1]} | f (x) | ≥ ε$ |
|  $∀x∈(X_0,X_1); | f (x) | ≤ ε$ | $⇔$  | $\sup\limits_{x∈(X_0,X_1)} | f (x) | ≤ ε$ |                                                     | $∃x∈(X_0,X_1); | f (x) | > ε$ | $⇔$  | $\sup\limits_{x∈(X_0,X_1)} | f (x) | > ε$ |
|  $∀x∈(X_0,X_1); | f (x) | < ε$ | $⇒$  | $\sup\limits_{x∈(X_0,X_1)} | f (x) | ≤ ε$ | $\rlap{≡≡≡≡≡≡≡≡≡}\sup\limits_{x⇝X_0} | f (x) | = ε$ | $∃x∈(X_0,X_1); | f (x) | ≥ ε$ | $⇒$  | $\sup\limits_{x∈(X_0,X_1)} | f (x) | ≥ ε$ |

| $⇕$  | $\lim\limits_{x⇝x_0} f(x) ⇝ f_{x_0}$                         |                                                     |                                                              |
| :--: | :----------------------------------------------------------- | :-------------------------------------------------: | :----------------------------------------------------------- |
| $⇓$  | $∀ε>0;∃δ>0;∀x∈\mathrm{U}(x_0,δ); |f(x) - f_{x_0}| ≤ ε$       |                                                     |                                                              |
| $⇓$  | $∀ε>0;∃δ>0;∀x_1,x_2∈\mathrm{U}(x_0, δ); |f(x_1) - f(x_2)| ≤ |f(x_1) - f_{x_0}| + |f(x_2) - f_{x_0}| ≤ 2·ε_0 = ε$ | $\mathop{⇋}\limits_{δ≥\frac{1}{N}}^{δ≤\frac{1}{N}}$ | $∀ε>0;∃N∈ℕ;∀n,m≥N; x_n,x_m∈\mathrm{U}\left(x_0,\frac{1}{N}\right) ⇒ |f(x_n) - f(x_m)| ≤ ε$ |
| $⇓$  | $∀ε>0;∃δ>0;∀x_1,x_2∈\mathrm{U}(x_0,δ); |f(x_1) - f(x_2)| ≤ ε$ |                         $⇔$                         | $∀ε>0;∃δ>0; \sup\limits_{x_1,x_2∈\mathrm{U}(x_0,δ)} |f(x_1) - f(x_2)| ≤ ε$ |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_1∈\mathrm{U}(x_0,δ); f(x_1) - ε ≤ f(x) ≤ f(x_1) + ε$ |                                                     |                                                              |
| $⇓$  | $f_{x_0} ⇜ \lim\limits_{δ⇝0} \inf\limits_{x∈\mathrm{U}(x_0,δ)} f(x) = \lim\limits_{δ⇝0} \sup\limits_{x∈\mathrm{U}(x_0,δ)} f(x)$ |                                                     |                                                              |
| $⇓$  | $∀ε>0;∃δ>0;∀x∈\mathrm{U}(x_0,δ); |f(x) - f_{x_0}| ≤ ε$       | $\mathop{⇋}\limits_{δ≥\frac{1}{N}}^{δ≤\frac{1}{N}}$ | $∀ε>0;∃N∈ℕ;∀n≥N; x_n∈\mathrm{U}\left(x_0,\frac{1}{N}\right) ⇒ |f(x_n) - f_{x_0}| ≤ ε$ |

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

$\lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} = \dfrac{\lim\limits_{x⇝x_0} f(x)}{\lim\limits_{x⇝x_0} g(x)} \mathop{⇝}\limits_{g_{x_0}≠0} \dfrac{f_{x_0}}{g_{x_0}}$

$\lim\limits_{x⇝x_0} \mathrm{Con} · f(x) = \mathrm{Con} · \lim\limits_{x⇝x_0} f(x) ⇝ \mathrm{Con} · f_{x_0}$

| $⇓$  | $[∀ε_1>0;∃δ_1>0; ∀x∈\mathrm{U}(x_0,δ_1); |f(x) - f_{x_0}| ≤ ε_1] ∧ [∀ε_2>0;∃δ_2>0; ∀x∈\mathrm{U}(x_0,δ_2); |g(x) - g_{x_0}| ≤ ε_2]$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε>0;∃δ=\min\lbrace δ_1,δ_2 \rbrace;∀x∈\mathrm{U}(x_0,δ); |[f(x) + g(x)] - [f_{x_0} + g_{x_0}]| ≤ |f(x) - f_{x_0}| + |g(x) - g_{x_0}| = ε_1 + ε_2 = ε$ |
| $⇓$  | $∀ε>0;∃δ=\min\lbrace δ_1,δ_2 \rbrace;∀x∈\mathrm{U}(x_0,δ); |[f(x) - g(x)] - [f_{x_0} - g_{x_0}]| ≤ |f(x) - f_{x_0}| + |g(x) - g_{x_0}| = ε_1 + ε_2 = ε$ |
| $⇓$  | $∀ε>0;∃δ=\min\lbrace δ_1,δ_2 \rbrace;∀x∈\mathrm{U}(x_0,δ); |f(x) · g(x) - f_{x_0} · g_{x_0}] ≤ |f(x)| · |g(x) - g_{x_0}| + |g_{x_0}| · |f(x) - f_{x_0}| ≤ |\sup f(x)| · ε_2 + |g_{x_0}| · ε_1 = ε$ |
| $⇓$  | $∀ε>0;∃δ=\min\lbrace δ_1,δ_2 \rbrace;∀x∈\mathrm{U}(x_0,δ); \left| \dfrac{f(x)}{g(x)} - \dfrac{f_{x_0}}{g_{x_0}} \right| = \left| \dfrac{f(x) · g_{x_0} - f_{x_0} · g(x)}{g(x) · g_{x_0}} \right| ≤ \dfrac{\left| f(x) \right| · |g(x) - g_{x_0}| + |g_{x_0}| · |f(x) - f_{x_0}|}{\left| g(x) · g_{x_0} \right|} ≤ \dfrac{|\sup f(x)| · ε_2 + |g_{x_0}| · ε_1}{|\inf g(x)| · |g_{x_0}|} = ε$ |

若函数$f(y)$在点$y_0$处有极限$\lim\limits_{y⇝y_0} f(y) ⇝ f_{y_0}$，且函数$g(x)$在点$x_0$处有极限$\lim\limits_{x⇝x_0} g(x) ⇝ g_{x_0} = y_0$。

$\lim\limits_{x⇝x_0} f(g(x)) \mathop{====}\limits_{g_{x_0}=y_0}^{g(x)≠g_{x_0}} \lim\limits_{y⇝y_0} f\left(y\right) ⇝ f_{y_0}$

| $⇓$  | $∀ζ>0;∃ε>0;∀y; y∈\mathrm{U}(y_0,ε) ⇒ f(y)∈\mathrm{U}(f_{y_0},ζ)$ |                  |
| :--: | :----------------------------------------------------------- | :--------------- |
| $⇓$  | $∀ε>0;∃δ>0;∀x; x∈\mathrm{U}(x_0,δ) ⇒ g(x)∈\mathrm{U}(y_0,ε)$ | $g_{x_0} = y_0$  |
| $⇓$  | $∀ζ>0;∃ε>0;∃δ>0;∀x; x∈\mathrm{U}(x_0,δ) ⇒ g(x)∈\mathrm{U}(y_0,ε) ⇒ f(g(x))∈\mathrm{U}(f_{y_0},ζ)$ | $g(x) ≠ g_{x_0}$ |
| $⇓$  | $∀ζ>0;∃δ>0;∀x∈\mathrm{U}(x_0,δ); f(g(x))∈\mathrm{U}(f_{y_0},ζ)$ |                  |

反例：函数$f(y) = \mathop{0}\limits_{y=0};\mathop{1}\limits_{y≠0}$，且函数$g(x) ≡ 0$。

$\lim\limits_{x⇝x_0} f(g(x)) = f(0) = 0 ≠ 1 ⇜ \lim\limits_{y⇝0} f(y)$

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

### 渐进量

若$\lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} ⇝ 0$，则称当$x⇝x_0$时，函数$f(x)$对于函数$g(x)$为渐进小量，可记作$f(x) ≈ \mathrm{o}[g(x)]_{x_0}$。

若$\lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} ⇝ q$，则称当$x⇝x_0$时，函数$f(x)$对于函数$g(x)$为渐进同量，可记作$f(x) ≈ \mathrm{O}[g(x)]_{x_0}$。

若$\lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} ⇝ 1$，则称当$x⇝x_0$时，函数$f(x)$对于函数$g(x)$为渐进等量，可记作$f(x) ≈ \mathrm{Θ}[g(x)]_{x_0}$。

若$f(x) ≈ \mathrm{Θ}[g(x)]_{x_0}$，则当$x⇝x_0$时，函数$f(x)$与函数$g(x)$可在乘运算中，但非加运算中相互替换。

| $f(x) ≈ \mathrm{o}[g(x)]_{x_0}$                              | $⇒$  | $f(x) ≈ \mathrm{O}[g(x)]_{x_0}$                              |
| :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $f(x) ≈ \mathrm{Θ}[g(x)]_{x_0}$                              | $⇔$  | $g(x) ≈ \mathrm{Θ}[f(x)]_{x_0}$                              |
| $f(x) ≈ \mathrm{Θ}[g(x)]_{x_0}$                              | $⇔$  | $f(x) ≈ g(x) + \mathrm{o}[g(x)]_{x_0}$                       |
| $f(x) · \mathrm{o}[g(x)] ≈ \mathrm{o}[f(x) · g(x)]_{x_0}$    | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{f(x) · \mathrm{o}[g(x)]}{f(x) · g(x)} = \lim\limits_{x⇝x_0} \dfrac{\mathrm{o}[g(x)]}{g(x)} ⇝ 0$ |
| $f(x) · \mathrm{O}[g(x)] ≈ \mathrm{O}[f(x) · g(x)]_{x_0}$    | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{f(x) · \mathrm{O}[g(x)]}{f(x) · g(x)} = \lim\limits_{x⇝x_0} \dfrac{\mathrm{O}[g(x)]}{g(x)} ⇝ q$ |
| $α · \mathrm{o}[g(x)] ≈ \mathrm{o}[g(x)]_{x_0}$              | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{α · \mathrm{o}[g(x)]}{g(x)} ⇝ 0$ |
| $α · \mathrm{O}[g(x)] ≈ \mathrm{O}[g(x)]_{x_0}$              | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{α · \mathrm{O}[g(x)]}{g(x)} ⇝ α · q$ |
| $\mathrm{o}^{α}[g(x)] \mathop{≈}\limits^{0<α} \mathrm{o}[g^{α}(x)]_{x_0}$ | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{\mathrm{o}^{α}[g(x)]}{g^{α}(x)} \mathop{=}\limits^{0<α} \left[ \lim\limits_{x⇝x_0} \dfrac{\mathrm{o}[g(x)]}{g(x)} \right]^{α} ⇝ 0$ |
| $\mathrm{O}^{α}[g(x)] \mathop{≈}\limits^{0<α} \mathrm{O}[g^{α}(x)]_{x_0}$ | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{\mathrm{O^{α}}[g(x)]}{g^{α}(x)} \mathop{=}\limits^{0<α} \left[ \lim\limits_{x⇝x_0} \dfrac{\mathrm{O}[g(x)]}{g(x)} \right]^{α} ⇝ q^{α}$ |
| $\lim\limits_{x⇝x_0} f(x) · u(x) \mathop{=======}\limits_{u(x)≈\mathrm{Θ}[v(x)]_{x_0}}^{f(x)≈\mathrm{Θ}[g(x)]_{x_0}} \lim\limits_{x⇝x_0} g(x) · v(x)$ | $⇐$  | $\lim\limits_{x⇝x_0} f(x) · u(x) = \lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} · [g(x) · v(x)] · \dfrac{u(x)}{v(x)} = \lim\limits_{x⇝x_0} g(x) · v(x)$ |
| $\lim\limits_{x⇝x_0} \dfrac{f(x)}{u(x)} \mathop{=======}\limits_{u(x)≈\mathrm{Θ}[v(x)]_{x_0}}^{f(x)≈\mathrm{Θ}[g(x)]_{x_0}} \lim\limits_{x⇝x_0} \dfrac{g(x)}{v(x)}$ | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{f(x)}{u(x)} = \lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} · \dfrac{g(x)}{v(x)} · \dfrac{v(x)}{u(x)} = \lim\limits_{x⇝x_0} \dfrac{g(x)}{v(x)}$ |
| $f(x) \mathop{≈≈≈≈≈≈}\limits_{g(x)≈\mathrm{o}[h(x)]_{x_0}}^{f(x)≈\mathrm{o}[g(x)]_{x_0}} \mathrm{o}[h(x)]_{x_0}$ | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{f(x)}{h(x)} = \lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} · \dfrac{g(x)}{h(x)} ⇝ 0 · 0 = 0$ |
| $f(x) \mathop{≈≈≈≈≈≈≈}\limits_{g(x)≈\mathrm{O}[h(x)]_{x_0}}^{f(x)≈\mathrm{O}[g(x)]_{x_0}} \mathrm{O}[h(x)]_{x_0}$ | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{f(x)}{h(x)} = \lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} · \dfrac{g(x)}{h(x)} ⇝ q_0 · q_1 = q$ |
| $f(x) \mathop{≈≈≈≈≈≈≈}\limits_{g(x) ≈ \mathrm{Θ}[h(x)]_{x_0}}^{f(x) ≈ \mathrm{Θ}[g(x)]_{x_0}} \mathrm{Θ}[h(x)]_{x_0}$ | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{f(x)}{h(x)} = \lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} · \dfrac{g(x)}{h(x)} ⇝ 1 · 1 = 1$ |
| $f(x) \mathop{≈≈≈≈≈≈}\limits_{g(x)≈\mathrm{O}[f(x)]}^{f(x)≈\mathrm{O}[g(x)]} \mathrm{Θ}[g(x)]_{x_0}$ | $⇔$  | $f(x) ≈ \mathrm{O}[g(x)] $                                   |

### 连续性

函数$f(x)$在任意点$x_0$处的振幅。

$w^{f}(x_0,δ) ≡ \sup\limits_{u,v∈\mathrm{U}(x_0,δ)} |f(u) - f(v)| = \left[ \sup\limits_{u∈\mathrm{U}(x_0,δ)} f(u) - \inf\limits_{v∈\mathrm{U}(x_0,δ)} f(v) \right]$

对于任意间断点$x_0$，其所在任意区间内的振幅均不为零。

| $\lim\limits_{δ⇝0} w^f (x_0,δ) \not⇝ 0$ | $∃ε>0;∀δ>0; \sup\limits_{u,v∈\mathrm{U}(x_0,δ)} |f(u) - f(v)|>ε$ | $∃ε>0;∀δ>0;∃u,v∈\mathrm{U}(x_0,δ); |f(u) - f(v)|>ε$ |
| :-------------------------------------- | :----------------------------------------------------------- | :-------------------------------------------------- |
|                                         |                                                              |                                                     |

连续性是局部性质。若函数$f(x)$在点$x_0∈X$处连续，则函数在点$x_0∈X$处既左连续也右连续，反之亦然。

$\left[ \lim\limits_{x⇝x_0} f (x) ⇝ f (x_0) \right] ⇔ \left[ \lim\limits_{x⇝x_0^{-}} f (x) ⇝ f (x_0) \right] ∧ \left[ \lim\limits_{x⇝x_0^{+}} f (x) ⇝ f (x_0) \right]$

| $\lim\limits_{x⇝x_0^{+}} f(x) ⇝ f(x_0) ≠ ∞$ | $∀x_0∈X;∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{U}^{+}(x_0,δ)} |f(x) - f(x_0)|≤ε$ | $∀x_0∈X;∀ε>0;∃δ>0;∀x∈\mathrm{U}^{+}(x_0,δ); f(x)∈\mathrm{U}(f(x_0),ε)$ |
| :------------------------------------------ | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\lim\limits_{x⇝x_0^-} f(x) ⇝ f(x_0) ≠ ∞$   | $∀x_0∈X;∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{U}^{-}(x_0,δ)} |f(x) - f(x_0)|≤ε$ | $∀x_0∈X;∀ε>0;∃δ>0;∀x∈\mathrm{U}^{-}(x_0,δ); f(x)∈\mathrm{U}(f(x_0),ε)$ |
| $\lim\limits_{x⇝x_0} f (x) ⇝ f (x_0) ≠ ∞$   | $∀x_0∈X;∀ε>0;∃δ>0; \sup\limits_{x∈\mathrm{U}(x_0,δ)} |f(x) - f(x_0)| ≤ ε$ | $∀x_0∈X;∀ε>0;∃δ>0;∀x∈\mathrm{U}(x_0,δ); f(x)∈\mathrm{U}(f(x_0),ε)$ |
| $\lim\limits_{x⇝x_0} f (x) ⇝ f (x_0) ≠ ∞$   | $∀x_0∈X;∀ε>0;∃δ>0;∀x∈\mathrm{U}(x_0,δ); |f(x) - f(x_0)|≤ε$   | $∀x_0∈X;∀ε>0;∃δ>0;∀x∈X; |x - x_0|≤δ ⇒ |f(x) - f(x_0)|≤ε$     |

一致连续性是全局性质。若函数$f(x)$在区间$X$上一致连续，则函数必在任意点$x∈X$处连续，反之不对。$[∃x;∀y; Q(x, y)] ⇒ [∀y;∃x; Q(x, y)]$

$\left[ \lim\limits_{x↭x_t} f (x) ↭ f (x_t) \right] ⇒ \left[ \lim\limits_{x⇝x_0} f(x) ⇝ f(x_0) \right]$

| $\lim\limits_{x↭x_t} f (x) ↭ f (x_t) ≠ ∞$ | $∀ε>0;∃δ>0;∀x,x_t∈X; |x - x_t|≤δ ⇒ |f(x) - f(x_t)|≤ε$ | $∀ε>0;∃δ>0; \sup\limits_{|x-x_t|≤δ} |f(x) - f(x_t)|≤ε$ |
| :---------------------------------------- | ----------------------------------------------------- | ------------------------------------------------------ |
|                                           |                                                       |                                                        |

若函数$f (x)$在区间$X$上点$x_0$处连续，则在该点处的振幅为零，反之亦然。

$\left[ \lim\limits_{x⇝x_0} f (x) ⇝ f (x_0) \right] ⇔ \left[ \lim\limits_{δ⇝0} w^{f} (x_0,δ) ⇝ 0 \right]$

| $⇓$  | $∀ε_1>0;∃δ>0;∀u∈\mathrm{U}(x_0,δ); |f(u) - f(x_0)|≤ε_1$      | $\lim\limits_{x⇝x_0} f (x) ⇝ f (x_0)$ |
| :--: | :----------------------------------------------------------- | :------------------------------------ |
| $⇓$  | $∀ε>0;∃δ>0;∀u,v∈\mathrm{U}(x_0,δ); |f(u) - f(v)| ≤ |f(u) - f(x_0)| + |f(v) - f(x_0)| ≤ ε_1 + ε_2 = ε$ |                                       |
| $⇓$  | $∀ε>0;∃δ>0;∀u,v∈\mathrm{U}(x_0,δ); |f(u) - f(v)| ≤ ε$        | $\lim\limits_{δ⇝0} w^{f} (x_0,δ) ⇝ 0$ |
| $⇓$  | $∀ε>0;∃δ>0;∀x∈\mathrm{U}(x_0,δ); |f(x) - f(x_0)| ≤ ε$        |                                       |

若函数$f (x)$在点$x_0$处连续$\lim\limits_{x⇝x_0} f (x) ⇝ f (x_0)$，且函数$g (x)$在点$x_0$处连续$\lim\limits_{x⇝x_0} g (x) ⇝ g (x_0)$。

$\lim\limits_{x⇝x_0} [ f (x) + g (x) ] = \lim\limits_{x⇝x_0} f (x) + \lim\limits_{x⇝x_0} g (x) ⇝ f (x_0) + g (x_0)$

$\lim\limits_{x⇝x_0} [ f (x) - g (x) ] = \lim\limits_{x⇝x_0} f (x) - \lim\limits_{x⇝x_0} g (x) ⇝ f (x_0) - g (x_0)$

$\lim\limits_{x⇝x_0} [ f (x) · g (x) ] = \lim\limits_{x⇝x_0} f (x) · \lim\limits_{x⇝x_0} g (x) ⇝ f (x_0) · g (x_0)$

$\lim\limits_{x⇝x_0} \dfrac{f (x)}{g (x)} = \dfrac{\lim\limits_{x⇝x_0} f (x)}{\lim\limits_{x⇝x_0} g (x)} \mathop{⇝}\limits_{g(x_0)≠0} \dfrac{f (x_0)}{g (x_0)}$

$\lim\limits_{x⇝x_0} \mathrm{Con} · f (x) = \mathrm{Con} \lim\limits_{x⇝x_0} f (x) ⇝ \mathrm{Con} · f (x_0)$

若函数$f (y)$在点$y_0$处连续$\lim\limits_{y⇝y_0} f (y) ⇝ f (y_0)$，且函数$g (x)$在点$x_0$处连续$\lim\limits_{x⇝x_0} g (x) ⇝ g (x_0) = y_0$。

$\lim\limits_{x⇝x_0} f (g (x)) \mathop{====}\limits_{g(x_0)=y_0} f \left( \lim\limits_{x⇝x_0} g (x) \right) ⇝ f (g (x_0))$

| $⇓$  | $∀ζ>0;∃ε>0;∀y; y∈\mathrm{U}(y_0,ε) ⇒ f(y)∈\mathrm{U}(f(y_0),ζ)$ |                |
| :--: | :----------------------------------------------------------- | :------------- |
| $⇓$  | $∀ε>0;∃δ>0;∀x; x∈\mathrm{U}(x_0,δ) ⇒ g(x)∈\mathrm{U}(y_0,ε)$ | $g(x_0) = y_0$ |
| $⇓$  | $∀ζ>0;∃ε>0;∃δ>0;∀x; x∈\mathrm{U}(x_0,δ) ⇒ g(x)∈\mathrm{U}(y_0,ε) ⇒ f(g(x))∈\mathrm{U}(f(y_0),ζ)$ |                |
| $⇓$  | $∀ζ>0;∃δ>0;∀x∈\mathrm{U}(x_0,δ); f(g(x))∈\mathrm{U}(f(y_0),ζ)$ |                |

### 导函数

若函数$f(x)$在点$x_0$处去心邻域内的右导数${^1}f(x_0^{+})$与左导数${^1}f(x_0^{-})$存在且相等，则其导数值${^1}f(x_0)$存在。

若函数$f(x)$在点$x_0$处导函数${^1}f(x)$的右极限${^1}f_{x_0}^{+}$与左极限${^1}f_{x_0}^{-}$存在且相等，则其导函数极限值${^1}f_{x_0}$存在。

若函数$f(x)$在区间$(X_0,X_1)$内任意点处导数值存在，且在点$X_0$处右导数存在与在点$X_1$处左导数存在，则其在区间$[X_0,X_1]$内任意点处导数值存在。

|       右导数 | ${^1}f(x_0^+) ≡ \dfrac{\mathrm{d}^1 f(x_0^+)}{\mathrm{d}^1 x}$ | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x_t∈X; 0<x_t-x_0≤+δ ⇒ \left| \dfrac{f(x_t) - f(x_0) - {^1}f(x_0) · [x_t - x_0]}{x_t - x_0} \right| ≤ ε$ |                                                              |
| -----------: | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
|       左导数 | ${^1}f(x_0^-) ≡ \dfrac{\mathrm{d}^1 f(x_0^-)}{\mathrm{d}^1 x}$ | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x_t∈X; -δ≤x_t-x_0<0 ⇒ \left| \dfrac{f(x_t) - f(x_0) - {^1}f(x_0) · [x_t - x_0]}{x_t - x_0} \right| ≤ ε$ |                                                              |
|       导数值 | ${^1}f(x_0) ≡ \dfrac{\mathrm{d}^1 f(x_0)}{\mathrm{d}^1 x}$   | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x_t∈X; 0<|x_t-x_0|≤δ ⇒ \left| \dfrac{f(x_t) - f(x_0) - {^1}f(x_0) · [x_t - x_0]}{x_t - x_0} \right| ≤ ε$ |                                                              |
|       右导数 | ${^1}f(x_0^+) ≡ \dfrac{\mathrm{d}^1 f(x_0^+)}{\mathrm{d}^1 x}$ | $\lim\limits_{x_t⇝x_0^+} \dfrac{f(x_t) - f(x_0)}{x_t - x_0} \mathop{=====}\limits^{x_t=x_0+Δx_0} \lim\limits_{Δx_0⇝0^+} \dfrac{f(x_0+Δx_0) - f(x_0)}{Δx_0} = \lim\limits_{Δx_0⇝0^+} \dfrac{Δf(x_0)}{Δx_0}$ |                                                              |
|       左导数 | ${^1}f(x_0^-) ≡ \dfrac{\mathrm{d}^1 f(x_0^-)}{\mathrm{d}^1 x}$ | $\lim\limits_{x_t⇝x_0^-} \dfrac{f(x_t) - f(x_0)}{x_t - x_0} \mathop{=====}\limits^{x_t=x_0+Δx_0} \lim\limits_{Δx_0⇝0^-} \dfrac{f(x_0+Δx_0) - f(x_0)}{Δx_0} = \lim\limits_{Δx_0⇝0^-} \dfrac{Δf(x_0)}{Δx_0}$ |                                                              |
|       导数值 | ${^1}f(x_0) ≡ \dfrac{\mathrm{d}^1 f(x_0)}{\mathrm{d}^1 x}$   | $\lim\limits_{x_t⇝x_0} \dfrac{f(x_t) - f(x_0)}{x_t - x_0} \mathop{=====}\limits^{x_t=x_0+Δx_0} \lim\limits_{Δx_0⇝0} \dfrac{f(x_0 + Δx_0) - f(x_0)}{Δx_0} = \lim\limits_{Δx⇝0} \dfrac{Δf(x_0)}{Δx_0}$ | ${^1}f(x_0^{-}) = {^1}f(x_0) = {^1}f(x_0^{+})$               |
|              |                                                              |                                                              |                                                              |
|       导函数 | ${^1}f(x) ≡ \dfrac{\mathrm{d}^1 f(x)}{\mathrm{d}^1 x}$       | $∀x∈X;∀ε>0;∃δ>0;∀x_t∈X; 0<|x_t - x| ≤ δ ⇒ \left| \dfrac{f(x_t) - f(x) - {^1}f(x) · [x_t - x]}{x_t - x} \right| ≤ ε$ |                                                              |
|       导函数 | ${^1}f(x) ≡ \dfrac{\mathrm{d}^1 f(x)}{\mathrm{d}^1 x}$       | $\lim\limits_{x_t⇝x} \dfrac{f(x_t) - f(x)}{x_t - x} \mathop{=====}\limits^{x_t=x+Δx} \lim\limits_{Δx⇝0} \dfrac{f(x + Δx) - f(x)}{Δx} = \lim\limits_{Δx⇝0} \dfrac{Δf(x)}{Δx}$ |                                                              |
| 导函数右极限 | ${^1}f_{x_0^{+}} ≡ \left.\dfrac{\mathrm{d}^{1}f(x)}{\mathrm{d}^{1}x}\right|_{x_0^{+}}$ | $\lim\limits_{x⇝x_0^{+}} {^1}f(x) = \lim\limits_{x⇝x_0^{+}} \dfrac{\mathrm{d}^{1}f(x)}{\mathrm{d}^{1}x}$ |                                                              |
| 导函数左极限 | ${^1}f_{x_0^{-}} ≡ \left.\dfrac{\mathrm{d}^{1}f(x)}{\mathrm{d}^{1}x}\right|_{x_0^{-}}$ | $\lim\limits_{x⇝x_0^{-}} {^1}f(x) = \lim\limits_{x⇝x_0^{-}} \dfrac{\mathrm{d}^{1}f(x)}{\mathrm{d}^{1}x}$ |                                                              |
| 导函数极限值 | ${^1}f_{x_0} ≡ \left.\dfrac{\mathrm{d}^{1}f(x)}{\mathrm{d}^{1}x}\right|_{x_0}$ | $\lim\limits_{x⇝x_0} {^1}f(x) = \lim\limits_{x⇝x_0} \dfrac{\mathrm{d}^{1}f(x)}{\mathrm{d}^{1}x}$ | ${^1}f_{x_0^{-}} = {^1}f_{x_0} = {^1}f_{x_0^{+}}$            |
|              |                                                              |                                                              |                                                              |
|   二阶导数值 | ${^2}f(x_0) ≡ \dfrac{\mathrm{d}^{2} f(x_0)}{\mathrm{d}^{2} x}$ | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x_t∈X; 0<|x_t - x_0| ≤ δ ⇒ \left| \dfrac{{^1}f(x_t) - {^1}f(x_0) - {^2}f(x_0) · [x_t - x_0]}{x_t - x_0} \right| ≤ ε$ |                                                              |
|   二阶导数值 | ${^2}f(x_0) ≡ \dfrac{\mathrm{d}^{2} f(x_0)}{\mathrm{d}^{2} x}$ | $\lim\limits_{x_t⇝x_0} \dfrac{{^1}f(x_t) - {^1}f(x_0)}{x_t - x_0} = \lim\limits_{Δx_0⇝0} \dfrac{{^1}f(x_0 + Δx_0) - {^1}f(x_0)}{Δx_0} = \lim\limits_{Δx_0⇝0} \dfrac{Δ{^1}f(x_0)}{Δx_0}$ |                                                              |
|   二阶导函数 | ${^2}f(x) ≡ \dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x}$   | $∀x∈X;∀ε>0;∃δ>0;∀x_t∈X; 0<|x_t - x| ≤ δ ⇒ \left| \dfrac{{^1}f(x_t) - {^1}f(x) - {^2}f(x) · [x_t - x]}{x_t - x} \right| ≤ ε$ |                                                              |
|   二阶导函数 | ${^2}f(x) ≡ \dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x}$   | $\lim\limits_{x_t⇝x} \dfrac{{^1}f(x_t) - {^1}f(x)}{x_t - x} = \lim\limits_{Δx⇝0} \dfrac{{^1}f(x + Δx) - {^1}f(x)}{Δx} = \lim\limits_{Δx⇝0} \dfrac{Δ{^1}f(x)}{Δx}$ | $\dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x} ≡ \dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d} f(x)}{\mathrm{d} x}$ |
|              |                                                              |                                                              |                                                              |
|   高阶导数值 | ${^n}f(x_0) ≡ \dfrac{\mathrm{d}^{n} f(x_0)}{\mathrm{d}^{n} x}$ | $Ⅎx_0∈X;∀ε>0;∃δ>0;∀x_t∈X; 0<|x_t - x_0| ≤ δ ⇒ \left| \dfrac{{^{n-1}}f(x_t) - {^{n-1}}f(x_0) - {^{n}}f(x_0) · [x_t - x_0]}{x_t - x_0} \right| ≤ ε$ |                                                              |
|   高阶导数值 | ${^n}f(x_0) ≡ \dfrac{\mathrm{d}^{n} f(x_0)}{\mathrm{d}^{n} x}$ | $\lim\limits_{x_t⇝x_0} \dfrac{{^{n-1}}f(x_t) - {^{n-1}}f(x_0)}{x_t - x_0} = \lim\limits_{Δx_0⇝0} \dfrac{{^{n-1}}f(x_0 + Δx_0) - {^{n-1}}f(x_0)}{Δx_0} = \lim\limits_{Δx_0⇝0} \dfrac{Δ{^1}f(x_0)}{Δx_0}$ |                                                              |
|   高阶导函数 | ${^n}f(x) ≡ \dfrac{\mathrm{d}^{n} f(x)}{\mathrm{d}^{n} x}$   | $∀x∈X;∀ε>0;∃δ>0;∀x_t∈X; 0<|x_t - x| ≤ δ ⇒ \left| \dfrac{{^{n-1}}f(x_t) - {^{n-1}}f(x) - {^{n}}f(x) · [x_t - x]}{x_t - x} \right| ≤ ε$ |                                                              |
|   高阶导函数 | ${^n}f(x) ≡ \dfrac{\mathrm{d}^{n} f(x)}{\mathrm{d}^{n} x}$   | $\lim\limits_{x_t⇝x} \dfrac{{^{n-1}}f(x_t) - {^{n-1}}f(x)}{x_t - x} = \lim\limits_{Δx⇝0} \dfrac{{^{n-1}}f(x + Δx) - {^{n-1}}f(x)}{Δx} = \lim\limits_{Δx⇝0} \dfrac{Δ{^1}f(x)}{Δx}$ | $\dfrac{\mathrm{d}^{n} f(x)}{\mathrm{d}^{n} x} ≡ \dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d}^{n-1} f(x)}{\mathrm{d}^{n-1} x}$ |

典例：函数$f(x) = x^2$。

${^1}f(x) = \dfrac{\mathrm{d}^{1} f(x)}{\mathrm{d}^{1} x} = \lim\limits_{x_t⇝x} \dfrac{x_t^2 - x^2}{x_t - x} = \lim\limits_{x_t⇝x} (x_t + x) ⇝ 2 · x$

${^2}f(x) = \dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x} = \lim\limits_{x_t⇝x} \dfrac{2 · x_t - 2 · x}{x_t - x} = \lim\limits_{x_t⇝x} 2 ⇝ 2$

$\lim\limits_{x_t⇝x} \dfrac{f(x_t) - f(x)}{(x_t - x)^2} = \lim\limits_{x_t⇝x} \dfrac{x_t^2 - x^2}{(x_t - x)^2} = \lim\limits_{x_t⇝x} \dfrac{x_t + x}{x_t - x} ⇝ ∞$

若函数$f(x)$在点$x_0$处的导数值${^1}f(x_0)$存在，则其在点$x_0$处连续，反之不对。

$\lim\limits_{x⇝x_0} f(x) = \lim\limits_{x⇝x_0} \left[ \dfrac{f(x) - f(x_0)}{x - x_0} · (x - x_0) + f(x_0) \right] = {^1}f(x_0) · \lim\limits_{x⇝x_0} (x - x_0) + f(x_0) ⇝ f(x_0)$

反例：函数$f(x) = |x|$在点$x_0 = 0$处连续，但其在点$x_0 = 0$处导数值不存在。

$\lim\limits_{x⇝0^{+}} \dfrac{f(x) - f(0)}{x - 0} = \lim\limits_{x⇝0^{+}} \dfrac{x}{x} ⇝ +1 ≠ -1 ⇜ \lim\limits_{x⇝0^{-}} \dfrac{-x}{x} = \lim\limits_{x⇝0^{-}} \dfrac{f(x) - f(0)}{x - 0}$

一阶导函数的运算性质。若函数$g(x)$与函数$f(x)$的一阶导函数存在。

| $\dfrac{\mathrm{d}}{\mathrm{d} x}[g(x) + f(x)]$     | $\dfrac{\mathrm{d} g(x)}{\mathrm{d} x} + \dfrac{\mathrm{d} f(x)}{\mathrm{d} x}$ | $\lim\limits_{x_t⇝x} \dfrac{[g(x_t) + f(x_t)] - [g(x) + f(x)]}{x_t - x} = \lim\limits_{x⇝x} \dfrac{[g(x_t) - g(x)] + [f(x_t) - f(x)]}{x_t - x}$ |
| :-------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\dfrac{\mathrm{d}}{\mathrm{d} x}[g(x) - f(x)]$     | $\dfrac{\mathrm{d}g(x)}{\mathrm{d}x} - \dfrac{\mathrm{d}f(x)}{\mathrm{d}x}$ | $\lim\limits_{x_t⇝x} \dfrac{[g(x_t) - f(x_t)] - [g(x) - f(x)]}{x_t - x} = \lim\limits_{x_t⇝x} \dfrac{[g(x_t) - g(x)] - [f(x_t) - f(x)]}{x_t - x}$ |
| $\dfrac{\mathrm{d}}{\mathrm{d}x}[g(x) · f^{+1}(x)]$ | $\dfrac{\mathrm{d} g(x)}{\mathrm{d} x} · f(x) + g(x) · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x}$ | $\lim\limits_{x_t⇝x} \dfrac{g(x_t) · f(x_t) - g(x) · f(x)}{x_t - x} = \lim\limits_{x_t⇝x} \dfrac{[g(x_t) - g(x)] · f(x_t) + g(x) · [f(x_t) - f(x)]}{x_t - x}$ |
| $\dfrac{\mathrm{d}}{\mathrm{d} x} [g(x)·f^{-1}(x)]$ | $\dfrac{\dfrac{\mathrm{d} g(x)}{\mathrm{d} x} · f(x) - g(x) · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x}}{f^2(x)}$ | $\lim\limits_{x_t⇝x} \dfrac{\dfrac{g(x_t)}{f(x_t)} - \dfrac{g(x)}{f(x)}}{x_t - x} \mathop{===}\limits^{f(x)≠0} \lim\limits_{x_t⇝x} \dfrac{\dfrac{[g(x_t) - g(x)] · f(x)}{x_t - x} - \dfrac{g(x) · [f(x_t) - f(x)]}{x_t - x}}{f(x_t) · f(x)}$ |
| $\dfrac{\mathrm{d}}{\mathrm{d} x} g(f(x))$          | $\dfrac{\mathrm{d} g(f(x))}{\mathrm{d} f(x)} · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \mathop{===}\limits^{y=f(x)} \dfrac{\mathrm{d} g(y)}{\mathrm{d} y} · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x}$ | $\lim\limits_{x_t⇝x} \dfrac{g(f(x_t)) - g(f(x))}{x_t - x} = \lim\limits_{x_t⇝x} \dfrac{g(f(x_t)) - g(f(x))}{f(x_t) - f(x)} · \dfrac{f(x_t) - f(x)}{x_t - x}$ |
| $\dfrac{\mathrm{d}}{\mathrm{d} x} {'}f^{⇵}(x)$      | $\left[ \dfrac{\mathrm{d} x}{\mathrm{d} {'}f^{⇵}(x)} \right]^{-1} \mathop{====}\limits_{y={'}f^{⇵}(x)}^{x=f^{⇵}(y)} \left[ \dfrac{\mathrm{d} f^{⇵}(y)}{\mathrm{d} y} \right]^{-1}$ | $\lim\limits_{x_t⇝x} \dfrac{{'}f^{⇵}(x_t) - {'}f^{⇵}(x)}{x_t - x} = \left[ \lim\limits_{x_t⇝x} \dfrac{x_t - x}{{'}f^{⇵}(x_t) - {'}f^{⇵}(x)} \right]^{-1} \mathop{====}\limits_{y={'}f^{⇵}(x)}^{x=f^{⇵}(y)} \left[ \lim\limits_{x_t⇝x} \dfrac{f^{⇵}(y_t) - f^{⇵}(y)}{y_t - y} \right]^{-1}$ |
|                                                     |                                                              |                                                              |
| $\dfrac{\mathrm{d}}{\mathrm{d} x} |x|$              | $\dfrac{|x|}{x}$                                             | $\lim\limits_{x_t⇝x>0} \dfrac{(+x_t) - (+x)}{x_t - x} ⇝ +1;\lim\limits_{x_t⇝x<0} \dfrac{(-x_t) - (-x)}{x_t - x} ⇝ -1$ |
| $\dfrac{\mathrm{d}}{\mathrm{d} x} f(x)^{g(x)}$      | $f(x)^{g(x)} · \left[ \dfrac{\mathrm{d} g(x)}{\mathrm{d} x} · \ln |f(x)| + \dfrac{g(x)}{f(x)} · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right]$ | $\dfrac{\mathrm{d} f(x)^{g(x)}}{\mathrm{d} |f(x)^{g(x)}|} · \dfrac{\mathrm{d} ә^{g(x) · \ln |f(x)|}}{\mathrm{d} x} = \dfrac{f(x)^{g(x)}}{|f(x)^{g(x)}|} · ә^{g(x) · \ln |f(x)|} · \left[ \dfrac{\mathrm{d} g(x)}{\mathrm{d} x} · \ln |f(x)| + \dfrac{g(x)}{|f(x)|} · \dfrac{|f(x)|}{f(x)} · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right]$ |

典例：函数$f(x) = \dfrac{(x + 9)^{\frac{1}{2}} · (3 - x)^{\frac{2}{3}}}{(x + 4)^{\frac{3}{4}} · (5 - x)^{\frac{4}{5}}}$，因此$\ln |f(x)| = \dfrac{1}{2} · \ln |x + 9| + \dfrac{2}{3} · \ln |3 - x| - \dfrac{3}{4} · \ln |x + 4| - \dfrac{4}{5} · \ln |5 - x|$。

$\dfrac{1}{f(x)} · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = \dfrac{+1}{2 · (x + 9)} + \dfrac{-2}{3 · (3 - x)} - \dfrac{3}{4 · (x + 4)} - \dfrac{-4}{5 · (5 - x)} $

$\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = \dfrac{(x + 9)^{\frac{1}{2}} · (3 - x)^{\frac{2}{3}}}{(x + 4)^{\frac{3}{4}} · (5 - x)^{\frac{4}{5}}} · \left[ \dfrac{+1}{2 · (x + 9)} + \dfrac{-2}{3 · (3 - x)} - \dfrac{3}{4 · (x + 4)} - \dfrac{-4}{5 · (5 - x)} \right]$

周期函数$f(x) = f(x + T)$，其导函数$\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = \dfrac{\mathrm{d} [f(x + T)]}{\mathrm{d} (x + T)} · \dfrac{\mathrm{d} (x + T)}{\mathrm{d} x} = \dfrac{\mathrm{d} f(x + T)}{\mathrm{d} (x + T)}$以$T$为周期，因此$\left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{x} = \left.\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{x+T}$。

奇函数$f(x) = -f(-x)$，其导函数$\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = \dfrac{\mathrm{d} [-f(-x)]}{\mathrm{d} (-x)} · \dfrac{\mathrm{d} (-x)}{\mathrm{d} x} = +\dfrac{\mathrm{d} f(-x)}{\mathrm{d} (-x)}$为偶函数，因此$\left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{x} = +\left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{-x}$。

偶函数$f(x) = +f(-x)$，其导函数$\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = \dfrac{\mathrm{d} [+f(-x)]}{\mathrm{d} (-x)} · \dfrac{\mathrm{d} (-x)}{\mathrm{d} x} = -\dfrac{\mathrm{d} f(-x)}{\mathrm{d} (-x)}$为奇函数，因此$\left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{x} = -\left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{-x}$。

高阶导函数的运算性质。若函数$g(x)$与函数$f(x)$的高阶导函数存在。

|     $\dfrac{\mathrm{d}^{n}}{\mathrm{d}^{n} x} [g(x) + f(x)]$ | $\dfrac{\mathrm{d}^{n} g(x)}{\mathrm{d}^{n} x} + \dfrac{\mathrm{d}^{n} f(x)}{\mathrm{d}^{n} x}$ | $\dfrac{\mathrm{d}^{0} f(x)}{\mathrm{d}^{0} x} ≡ f(x)$ |
| -----------------------------------------------------------: | :----------------------------------------------------------- | :----------------------------------------------------- |
|     $\dfrac{\mathrm{d}^{n}}{\mathrm{d}^{n} x} [g(x) · f(x)]$ | $\sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · \dfrac{\mathrm{d}^{n-i} g(x)}{\mathrm{d}^{n-i} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x}$ |                                                        |
| $\dfrac{\mathrm{d}^{n}}{\mathrm{d}^{n} x} [\mathrm{Con} · f(x)]$ | $= \mathrm{Con} · \dfrac{\mathrm{d}^{n} f(x)}{\mathrm{d}^{n} x}$ |                                                        |

|     $\dfrac{\mathrm{d}^{0}}{\mathrm{d}^{0} x} [g(x) + f(x)]$ | $g(x) + f(x)$                                                | $\dfrac{\mathrm{d}^{0} f(x)}{\mathrm{d}^{0} x} ≡ f(x)$ |
| -----------------------------------------------------------: | :----------------------------------------------------------- | :----------------------------------------------------- |
|     $\dfrac{\mathrm{d}^{1}}{\mathrm{d}^{1} x} [g(x) + f(x)]$ | $\dfrac{\mathrm{d}^{1} g(x)}{\mathrm{d}^{1} x} + \dfrac{\mathrm{d}^{1} f(x)}{\mathrm{d}^{1} x}$ |                                                        |
|     $\dfrac{\mathrm{d}^{n}}{\mathrm{d}^{n} x} [g(x) + f(x)]$ | $\dfrac{\mathrm{d}^{n} g(x)}{\mathrm{d}^{n} x} + \dfrac{\mathrm{d}^{n} f(x)}{\mathrm{d}^{n} x}$ |                                                        |
| $\dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d}^{n}}{\mathrm{d}^{n} x} [g(x) + f(x)]$ | $\dfrac{\mathrm{d}}{\mathrm{d} x} \left[ \dfrac{\mathrm{d}^{n} g(x)}{\mathrm{d}^{n} x} + \dfrac{\mathrm{d}^{n} f(x)}{\mathrm{d}^{n} x} \right]$ |                                                        |
| $\dfrac{\mathrm{d}^{n+1}}{\mathrm{d}^{n+1} x} [g(x) + f(x)]$ | $\dfrac{\mathrm{d}^{n+1} g(x)}{\mathrm{d}^{n+1} x} + \dfrac{\mathrm{d}^{n+1} f(x)}{\mathrm{d}^{n+1} x}$ |                                                        |
|                                                              |                                                              |                                                        |
|     $\dfrac{\mathrm{d}^{0}}{\mathrm{d}^{0} x} [g(x) · f(x)]$ | $g(x) · f(x)$                                                | $\dfrac{\mathrm{d}^{0} f(x)}{\mathrm{d}^{0} x} ≡ f(x)$ |
|     $\dfrac{\mathrm{d}^{1}}{\mathrm{d}^{1} x} [g(x) · f(x)]$ | $\dfrac{\mathrm{d}^{1} g(x)}{\mathrm{d}^{1} x} · f(x) + g(x) · \dfrac{\mathrm{d}^{1} f(x)}{\mathrm{d}^{1} x}$ |                                                        |
|     $\dfrac{\mathrm{d}^{n}}{\mathrm{d}^{n} x} [g(x) · f(x)]$ | $\sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · \dfrac{\mathrm{d}^{n-i} g(x)}{\mathrm{d}^{n-i} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x}$ |                                                        |
| $\dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\mathrm{d}^{n}}{\mathrm{d}^{n} x} [g(x) · f(x)]$ | $\sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · \dfrac{\mathrm{d}}{\mathrm{d} x} \left[ \dfrac{\mathrm{d}^{n-i} g(x)}{\mathrm{d}^{n-i} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x} \right]$ |                                                        |
|                                                              | $\sum\limits_{i=0}^{n} \dfrac{n!}{i! · (n - i)!} · \left[ \dfrac{\mathrm{d}^{n-i+1} g(x)}{\mathrm{d}^{n-i+1} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x} + \dfrac{\mathrm{d}^{n-i} g(x)}{\mathrm{d}^{n-i} x} · \dfrac{\mathrm{d}^{i+1} f(x)}{\mathrm{d}^{i+1} x} \right]$ |                                                        |
|                                                              | $\dfrac{\mathrm{d}^{n+1} g(x)}{\mathrm{d}^{n+1} x} · \dfrac{\mathrm{d}^{0} f(x)}{\mathrm{d}^{0} x} + \left[ \sum\limits_{i=1}^{n} \dfrac{n!}{i! · (n - i)!} · \dfrac{\mathrm{d}^{n-i+1} g(x)}{\mathrm{d}^{n-i+1} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x} + \sum\limits_{i=1}^{n} \dfrac{n!}{(i - 1)! · (n - i + 1)!} · \dfrac{\mathrm{d}^{n-(i-1)} g(x)}{\mathrm{d}^{n-(i-1)} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x} \right] + \dfrac{\mathrm{d}^{0} g(x)}{\mathrm{d}^{0} x} · \dfrac{\mathrm{d}^{n+1} f(x)}{\mathrm{d}^{n+1} x}$ |                                                        |
|                                                              | $\dfrac{\mathrm{d}^{n+i} g(x)}{\mathrm{d}^{n+1} x} · \dfrac{\mathrm{d}^{0} f(x)}{\mathrm{d}^{0} x} + \left[ \sum\limits_{i=1}^{n} \dfrac{(n + 1)!}{i! · (n + 1 - i)!} · \dfrac{\mathrm{d}^{n+1-i} g(x)}{\mathrm{d}^{n+1-i} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x}\right] + \dfrac{\mathrm{d}^{0} g(x)}{\mathrm{d}^{0} x} · \dfrac{\mathrm{d}^{n+1} f(x)}{\mathrm{d}^{n+1} x}$ |                                                        |
| $\dfrac{\mathrm{d}^{n+1}}{\mathrm{d}^{n+1} x} [g(x) · f(x)]$ | $\sum\limits_{i=0}^{n+1} \dfrac{(n + 1)!}{i! · (n + 1 - i)!} · \dfrac{\mathrm{d}^{n+1-i} g(x)}{\mathrm{d}^{n+1-i} x} · \dfrac{\mathrm{d}^{i} f(x)}{\mathrm{d}^{i} x}$ |                                                        |



### 一致连续性

若函数$f (x)$在区间$\fbox{X}$上导函数有全局的确界，则函数$f (x)$在区间$X$上一致连续，反之不对。

$\left[ ∀x_t∈\fbox{X};Ⅎ\mathrm{Sup}_{x}; \left| \dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{x} ≤ \mathrm{Sup_{x} } \right] ⇔ \left[ Ⅎ\mathrm{Sup}^{f};∀x,x_t∈X; | f (x) - f (x_t) | ≤ \mathrm{Sup}^{f} · | x - x_t | \right] ⇒ \left[ \lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈X} f (x_t) \right]$

| $⇕$  | $∀x∈\fbox{X};Ⅎ\mathrm{Sup}_{x}; \left| \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right| ≤ \mathrm{Sup}_{x} ≠ ∞^{+}$ |      |                                                              |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇕$  | $Ⅎ\mathrm{Sup};∀x∈\fbox{X};Ⅎ\mathrm{Sup}_{x}; \left| \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right| ≤ \mathrm{Sup}_{x} ≤ \sup\limits_{x∈\fbox{X}} \left\lbrace \mathrm{Sup}_{x} \right\rbrace = \mathrm{Sup}$ |      |                                                              |
| $⇕$  | $Ⅎ\mathrm{Sup};∀x∈\fbox{X}; |\mathrm{d} f(x)| ≤ \mathrm{Sup} · |\mathrm{d} x|$ | $⇔$  | $Ⅎ\mathrm{Sup}^{f};∀x,x_t∈X; |f(x) - f(x_t)| ≤ \mathrm{Sup}^{f} · |x - x_t|$ |
| $⇕$  | $Ⅎ\mathrm{Sup};∀ε>0;∃δ>0;∀x,x_t∈X; [ |x - x_t| ≤ δ ] ⇒ [ |f(x) - f(x_t)| ≤ \mathrm{Sup} · |x - x_t| ≤ \mathrm{Sup} · δ = ε ]$ |      |                                                              |
| $⇓$  | $\lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈X} f (x_t)$ |      |                                                              |

若函数$f (x)$在区间$\fbox{X}$上满足切割线极限过程，则函数$f (x)$在区间$X$上一致连续，反之亦然。[有待验证]

$\left[ \lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x_t∈X}^{x∈X} f(x_t) \right] ⇔ \left[ 0 ⇜ \lim\limits_{x⇝x_t} \left| \dfrac{\mathrm{d} f(x_t)}{\mathrm{d} x_t} \right| · |x - x_t| \mathop{===}\limits_{x_t∈\fbox{X}}^{x∈X} \lim\limits_{x⇝x_t} \left| \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right| · |x - x_t| \right]$

若函数$f(x)$在区间$\fbox{X}$上已连续，且满足切割线极限过程，则函数$f(x)$在区间$X$上一致连续，反之亦然。

$\left[ \lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x_t∈X}^{x∈X} f(x_t) \right] ⇔ \left[ 0 \mathop{⇜}\limits_{x_t∈\fbox{X}}^{x∈X} \lim\limits_{x⇝x_t} \left| \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right| · |x - x_t| \right]$

| $⇕$  | $f(x) = f(x_t) + \dfrac{\mathrm{d} f(x_t)}{\mathrm{d} x_t} · (x - x_t) + o_{x_t}(|x - x_t|)$ | $f(x_t) = f(x) + \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} · (x_t - x) + o_{x}(|x_t - x|)$ |
| :--: | ------------------------------------------------------------ | :----------------------------------------------------------- |
| $⇕$  | $|f(x) - f(x_t) - o_{x_t}(|x - x_t|)| = \left| \dfrac{\mathrm{d} f(x_t)}{\mathrm{d} x_t} \right| · |x - x_t|$ | $|f(x_t) - f(x) - o_{x}(|x_t - x|)| = \left| \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right| · |x_t - x|$ |
| $⇕$  | $0 \mathop{↭}\limits_{x_t∈X}^{x∈X} \lim\limits_{x↭x_t} |f(x) - f(x_t) + o(|x - x_t|)| = \lim\limits_{x⇝x_t} \left| \dfrac{\mathrm{d} f(x_t)}{\mathrm{d} x_t} \right| · |x - x_t| \mathop{===}\limits_{x_t∈\fbox{X}}^{x∈X} \lim\limits_{x⇝x_t} \left| \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right| · |x - x_t|$ |                                                              |


若函数$f (x)$在区间$\fbox{X} = [x_{α}, x_{β}]$上连续，则函数$f (x)$在区间$[x_{α}, x_{β}]$上一致连续，反之亦然。

$\left[ \lim\limits_{x⇝x_0} f (x) \mathop{⇝}\limits_{x,x_0∈[x_{α}, x_{β}]} f (x_0) \right] ⇔ \left[ \lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈[x_{α}, x_{β}]} f (x_t) \right]$

若函数$f (x)$在区间$(x_{α}, x_{β})$上一致连续，则可将函数$f(x)$延拓为区间$[x_{α}, x_{β}]$上的一致连续函数$\tilde{f}(x) = \mathop{f(x_α^+)}\limits_{x=x_α}; \mathop{f (x)}\limits_{x∈(x_α,x_β)};\mathop{f(x_β^{-})}\limits_{x=x_β}$。

若函数$f (x)$在区间$(x_α,x_β]$上一致连续，且在区间$[x_β, x_γ)$上一致连续，则函数$f (x)$在区间$(x_α, x_γ)$上一致连续。

$\left[ \lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x,x_t∈(x_α,x_β]} f(x_t) \right] ∧ \left[ \lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x,x_t∈[x_β,x_γ)} f(x_t) \right] ⇒ \left[ \lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x,x_t∈(x_α,x_γ)} f (x_t) \right]$

| $⇓$  | $∀ε_1>0;∃δ_1>0;∀x,x_t∈(x_α,x_β]; \left[ | x - x_t | ≤ δ_1 \right] ⇒ \left[ | f (x) - f (x_t) | ≤ ε_1 \right]$ | $\lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈(x_α,x_β]} f (x_t)$ |
| :--: | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $⇓$  | $∀ε_2>0;∃δ_2>0;∀x,x_t∈[x_β,x_γ); \left[ | x - x_t | ≤ δ_2 \right] ⇒ \left[ | f (x) - f (x_t) | ≤ ε_2 \right]$ | $\lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x,x_t∈[x_α,x_β)} f(x_t)$ |
| $⇓$  | $∀ε_3>0;∃δ_3=\min\lbrace δ_1, δ_2 \rbrace;∀x∈(x_α,x_β];∀x_t∈[x_β,x_γ); [ |x - x_t| ≤ δ_3 ] ⇒ [ |f(x) - f(x_t)| ≤ |f(x) - f(x_β)| + |f(x_β) - f(x_t)| ≤ ε_1 + ε_2 = ε_3 ]$ |                                                              |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈(x_α,x_γ); \left[ | x - x_t | ≤ δ \right] ⇒ \left[ | f (x) - f (x_t) | ≤ ε \right]$ | $\lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x,x_t∈(x_α,x_β)} f(x_t)$ |

若函数$f (x)$在区间$(∞^{-},∞^{+})$上连续，且以区间$T = [t_α, t_β]$为周期，则函数$f (x)$在区间$(∞^{-},∞^{+})$上一致连续。

若函数$f (x)$在区间$[x_α^{±}, ∞^{±})$上连续，且 $\lim\limits_{x⇝∞^{±}} f (x) ⇝ f_{∞^{±}}$极限存在，则函数$f (x)$在区间$[x_α^{±}, ∞^{±})$上一致连续。

$\left[ \lim\limits_{x⇝x_0} f (x) \mathop{⇝}\limits_{x,x_0∈[x_α^{±},∞^{±})} f (x_0) \right] ∧ \left[ \lim\limits_{x⇝∞^{±}} f (x) ⇝ f_{∞^{±}} \right] ⇔ \left[ \lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x,x_t∈[x_α^{±},∞^{±})} f (x_t) \right]$

| $⇓$  | $∃x_β;[x_α^{±}, ∞^{±}) = [x_α^{±}, x_β] ∪ [x_β, ∞^{±})$      |      |                                                              |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε>0;∃x_β∈[x_α^{±},∞^{±}];∀x,x_t∈[x_β,∞^{±}); [ |f(x) - f(x_t)| ≤ ε ]$ | $⇔$  | $\left[ \lim\limits_{x⇝∞^{±}} f (x) \mathop{⇝}\limits_{x∈[x_β,∞^{±})} f_{∞^{±}} \right]$ |
| $⇓$  | $∀ε>0;∃x_β∈[x_α^{±},∞^{±}];∃δ>0;∀x,x_t∈[x_β,∞^{±}); ¬[ |x - x_t| ≤ δ ] ∨ [ |f(x) - f (x_t)| ≤ ε ]$ |      |                                                              |
| $⇓$  | $∀ε>0;∃x_β∈[x_α^{±},∞^{±}];∃δ>0;∀x,x_t∈[x_β,∞^{±}); [ |x - x_t| ≤ δ ] ⇒ [ |f(x) - f(x_t)| ≤ ε ]$ | $⇒$  | $\left[ \lim\limits_{x↭x_t} f (x) \mathop{↭}\limits_{x∈[x_β,∞^{±})} f (x_t) \right]$ |
| $⇓$  | $∀ε>0;∃x_β∈[x_α^{±},∞^{±}];∃δ>0;∀x,x_t∈[x_α^{±},x_β]; [ |x - x_t| ≤ δ ] ⇒ [ |f(x) - f(x_t)| ≤ ε ]$ | $⇔$  | $\left[ \lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x,x_t∈[x_α^{±},x_β]} f(x_t) \right]$ |
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈[x_α^{±},∞^{±}); [ |x - x_t| ≤ δ ] ⇒ [ |f(x) - f(x_t)| ≤ ε ]$ | $⇒$  | $\left[ \lim\limits_{x↭x_t} f(x) \mathop{↭}\limits_{x,x_t∈[x_α^{±},∞^{±})} f(x_t) \right]$ |

典例：函数$f (x) = \dfrac{1}{x}$在区间$(0, x_β)$上非一致连续，但在区间$\mathop{[x_α, x_β)}\limits_{0<x_α}$上一致连续。

典例：函数$f (x) = α · x + β$在区间$(∞^{-}, ∞^{+})$上一致连续。函数$f (x) = \sin x^2$在区间$(∞^{-}, ∞^{+})$上非一致连续。

典例：函数$f (x) = | x |$在区间$(∞^{-}, ∞^{+})$上一致连续。函数$\mathrm{sgn} (x) = \mathop{-1}\limits_{x<0};\mathop{0}\limits_{x=0};\mathop{+1}\limits_{x>0}$在区间$[-1, +1]$上非一致连续。

典例：函数$f (x) = \sqrt{x}$在区间$[0, ∞^{+})$上一致连续，但在点$x_0=0^+$处导函数右极限为$\left.\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} \right|_{0^+} = \lim\limits_{x⇝0^+} \dfrac{1}{2 · \sqrt{x} } = ∞^{+}$。

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
| $⇓$  | $∀ε>0;∃δ>0;∀x,x_t∈[0, ∞^{+}); [ | x - x_t | ≤ δ ] ⇒ \left[ | f (x) - f (x_t) | = | \sqrt{x} - \sqrt{x_t} | \mathop{≤}\limits^{\sqrt{u+v}≤\sqrt{u}+\sqrt{v}} \sqrt{|x - x_t|} ≤ \sqrt{δ} = ε \right]$ |



### 连续介值定理

若函数$f (x)$在单区间$X$上连续，则其值域$Y$为单区间，反之不对。单区间内任意一点均为聚点，并且任意两点均可连通成线。

若函数$f(x)$在单区间$X=[x_{α},x_{β}]$上连续，则对于任意函数值$f(x)$，必定存在某一点$θ∈X$其函数值相等。

$f(x)|_{∀x∈X} = \left.f (x)\right|_{∃θ∈X}$

| $⇓$  | $∀x∈X;∃θ∈X; f (x) = f (θ)$                                   | $⇔$  | $\left. f(x) \right|_{∀x∈X} = \left. f(x) \right|_{∃θ∈X}$    |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $∀y∈f(X);∃θ∈X; y = f(θ)$                                     | $⇐$  | $y ≡ f(x)$                                                   |
| $⇓$  | $∀y∈[\min\lbrace f(x_α),f(x_β),\max\lbrace f(x_α),f(x_β) \rbrace \rbrace] ⊆ f([x_α,x_β]);∃θ∈X; y = f(θ)$ |      |                                                              |
| $⇓$  | $[f(x_α) · f(x_β) ≤ 0] ⇒ \left[ 0 = \left. f(x) \right|_{∃θ∈[x_α,x_β]} \right]$ |      | $[f(x_α),f(x_β) < 0] ⇒ \left[ 0 = \left. f(x) \right|_{∃θ∈(x_α,x_β)} \right]$ |

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

| $⇓$  | $P_{2·n+1}(x) ≡ \sum\limits_{i=0}^{2·n+1} p_i · (x - x_0)^{i} = p_{2·n+1} · (x - x_0)^{2·n+1} · \left[ 1 + \sum\limits_{i=1}^{2·n} \dfrac{p_{i} · (x - x_0)^{i}}{p_{2·n+1} · (x - x_0)^{2·n+1}} + \dfrac{p_0}{p_{2·n+1}·(x - x_0)^{2·n+1}} \right]$ |      |                    |
| :--: | :----------------------------------------------------------- | :--: | :----------------- |
| $⇓$  | $\lim\limits_{x⇝∞^{+}} P_{2·n+1}(x) = \lim\limits_{x⇝∞^{+}} p_{2·n+1} · (x - x_0)^{2·n+1} ⇝ p_{2·n+1} · ∞^{+}$ |      |                    |
| $⇓$  | $\lim\limits_{x⇝∞^{-}} P_{2·n+1}(x) = \lim\limits_{x⇝∞^{+}} p_{2·n+1} · (x - x_0)^{2·n+1} ⇝ p_{2·n+1} · ∞^{-}$ |      |                    |
| $⇓$  | $P_{2·n+1}(ℝ) = ℝ$                                           | $⇒$  | $0 ∈ P_{2·n+1}(ℝ)$ |
| $⇓$  | $0 = \left. P_{2·n+1}(x) \right|_{∃θ∈ℝ}$                     |      |                    |

若函数$f (x)$在单区间$(x_α, x_β)$上连续，且$\lim\limits_{x⇝x_α^{+} } f (x)$与$\lim\limits_{x⇝x_β^{-} } f (x)$均有确界，则函数$f (x)$在区间$(x_α, x_β)$上有确界。

若函数$f (x)$在区间$(∞⁻, ∞⁺)$上连续，且$\lim\limits_{x⇝∞⁻} f (x)$与$\lim\limits_{x⇝∞⁺} f (x)$均有确界，则函数$f (x)$在区间$(∞⁻, ∞⁺)$上有确界。

$|f(x)| ≤ \max\left\lbrace \left| \inf\limits_{x∈X} f(x) \right|, \left| \sup\limits_{x∈X} f(x) \right| \right\rbrace$

### 微分中值定理

若函数$f(x)$在点$x_0$处导数值$\dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x} = 0$，则称点$x_0$为函数$f(x)$的驻点。

若函数$f(x)$在点$x_0$处导数值存在，且达到极小值极大值，则其在点$x_0$处导数$\dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x} = 0$。

若函数$f(x)$在闭区间$[x_α,x_β]$上连续且可导，当两端点处函数值相等，则存在某一点$θ∈(x_α,x_β)$其导数值为零。

$[f(x_α) = f(x_β)] ⇒ \left[ \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ∈(x_α,x_β)} = 0 \right]$

| $⇓$  | $f(θ) = \min\limits_{x∈(x_α,x_β)} f(x)$ | $\lim\limits_{x⇝θ^{-}} \dfrac{f(x) - f(θ)}{x - θ} ≤ 0 ≤ \lim\limits_{x⇝θ^{+}} \dfrac{f(x) - f(θ)}{x - θ}$ |
| :--: | :-------------------------------------- | :----------------------------------------------------------- |
| $⇓$  | $f(θ) = \max\limits_{x∈(x_α,x_β)} f(x)$ | $\lim\limits_{x⇝θ^{-}} \dfrac{f(x) - f(θ)}{x - θ} ≥ 0 ≥ \lim\limits_{x⇝θ^{+}} \dfrac{f(x) - f(θ)}{x - θ}$ |
| $⇓$  | $f(x_α) = f(x_β)$                       | $\lim\limits_{x⇝θ} \dfrac{f(x) - f(θ)}{x - θ} = \left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right| = 0$ |

若函数$f(x)$在闭区间$[x_α,x_β]$上连续且可导，则存在某一点$θ∈(x_α,x_β)$其导数值，等同于两端点处直线的斜率。

$\left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ∈(x_α,x_β)} = \dfrac{f(x_β) - f(x_α)}{x_β - x_α}$

| $⇓$  | $F(x) ≡ \left|\begin{matrix} 1 & 1 & 1 \\ x_α & x & x_β \\ f(x_α) & f(x) & f(x_β) \\ \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ x_α & x - x_α & x_β - x_α \\ f(x_α) & f(x) - f(x_α) & f(x_β) - f(x_α) \end{matrix}\right|$ | $F(x_α) = 0 = F(x_β)$                                        |
| :--: | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $⇓$  | $\dfrac{\mathrm{d} F(x)}{\mathrm{d} x} = \dfrac{\mathrm{d}}{\mathrm{d} x} \left|\begin{matrix} 1 & 0 & 0 \\ x_α & x - x_α & x_β - x_α \\ f(x_α) & f(x) - f(x_α) & f(x_β) - f(x_α) \\ \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ x_α & 1 & x_β - x_α \\ f(x_α) & \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} & f(x_β) - f(x_α) \end{matrix}\right|$ | $\dfrac{\mathrm{d} F(x)}{\mathrm{d} x} = [f(x_β) - f(x_α)] - (x_β - x_α) · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x}$ |
| $⇓$  | $\left. \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right|_{∃θ∈(x_α,x_β)} = \dfrac{f(x_β) - f(x_α)}{x_β - x_α}$ | $\left. \dfrac{\mathrm{d} F(x)}{\mathrm{d} x} \right|_{∃θ∈(x_α,x_β)} = 0$ |

若函数$f(x)$与函数$g(x)$在闭区间$[x_α,x_β]$上连续且可导，则存在某一点$θ∈(x_α,x_β)$其导数值，等同于两端点处函数值的比值。

$\left.\dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)}\right|_{∃θ∈(x_α, x_β)} = \dfrac{g(x_β) - g(x_α)}{f(x_β) - f(x_α)}$

| $⇓$  | $F(x) ≡ \left|\begin{matrix} 1 & 1 & 1 \\ g(x_α) & g(x) & g(x_β) \\ f(x_α) & f(x) & f(x_β) \\ \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ g(x_α) & g(x) - g(x_α) & g(x_β) - g(x_α) \\ f(x_α) & f(x) - f(x_α) & f(x_β) - f(x_α) \\ \end{matrix}\right|$ | $F(x_α) = 0 = F(x_β)$                                        |
| :--: | ------------------------------------------------------------ | ------------------------------------------------------------ |
| $⇓$  | $\dfrac{\mathrm{d} F(x)}{\mathrm{d} x} = \dfrac{\mathrm{d}}{\mathrm{d} x} \left|\begin{matrix} 1 & 0 & 0 \\ g(x_α) & g(x) - g(x_α) & g(x_β) - g(x_α) \\ f(x_α) & f(x) - f(x_α) & f(x_β) - f(x_α) \\ \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ g(x_α) & \dfrac{\mathrm{d} g(x)}{\mathrm{d} x} & g(x_β) - g(x_α) \\ f(x_α) & \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} & f(x_β) - f(x_α) \end{matrix}\right|$ | $\dfrac{\mathrm{d} F(x)}{\mathrm{d} x} = [f(x_β) - f(x_α)]  · \dfrac{\mathrm{d} g(x)}{\mathrm{d} x} - [g(x_β) - g(x_α)] · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x}$ |
| $⇓$  | $\left.\dfrac{\mathrm{d} g(x)}{\mathrm{d} f(x)} \right|_{∃θ∈(x_α,x_β)} = \left. \dfrac{\mathrm{d} g(x)}{\mathrm{d} x} · \dfrac{\mathrm{d} x}{\mathrm{d} f(x)} \right|_{∃θ∈(x_α,x_β)} = \dfrac{g(x_β) - g(x_α)}{f(x_β) - f(x_α)}$ | $\left. \dfrac{\mathrm{d} F(x)}{\mathrm{d} x} \right|_{∃θ∈(x_α,x_β)} = 0$ |



### 幂级数公式

若多项式函数$\mathrm{Poly}_n (x)$在点$x_0$处连续且有$n + 1$阶导数，则在点$x_0$处可唯一展开成$n$阶幂级数。

$P_n (x) = \sum\limits_{i=0}^n p_i · (x - x_0)^i = p_0 · (x - x_0)^0 + p_1 · (x - x_0)^1 + p_2 · (x - x_0)^2 + ··· + p_n · (x - x_0)^n$

$P_n (x) = \sum\limits_{i=0}^n \dfrac{ {^i}P_n (x_0)}{i!} · (x - x_0)^i = \sum\limits_{i=0}^n \left.\dfrac{\mathrm{d}^i P_n (x)}{i! · \mathrm{d}^i x}\right|_{x_0} · (x - x_0)^i = \sum\limits_{i=0}^n \left.\dfrac{\mathrm{d}^i P_n (x)}{\mathrm{d} x^i}\right|_{x_0} · (x - x_0)^i$

| ${^n}P_n (x_0) = n! · p_n$                                   | ${^0}P_n (x_0) = 0! · p_0$                                   | ${^1}P_n (x_0) = 1! · p_1$                                   | ${^2}P_n (x_0) = 2! · p_2$                                   |
| ------------------------------------------------------------ | :----------------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| $\left.\dfrac{\mathrm{d}^n P_n (x)}{\mathrm{d}^n x}\right|_{x_0} ≡ \left.\underbrace{\dfrac{\mathrm{d} }{\mathrm{d} x} ··· \dfrac{\mathrm{d} }{\mathrm{d} x} }_n P_n (x) \right|_{x_0} ≡ n! · p_n$ | $\left.\dfrac{\mathrm{d}^0 P_n (x)}{\mathrm{d}^0 x}\right|_{x_0} ≡ \left.P_n (x)\right|_{x_0} ≡ 0! · p_0$ | $\left.\dfrac{\mathrm{d}^1 P_n (x)}{\mathrm{d}^1 x}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d} }{\mathrm{d} x} P_n (x)\right|_{x_0} ≡ 1! · p_1$ | $\left.\dfrac{\mathrm{d}^2 P_n (x)}{\mathrm{d}^2 x}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d} }{\mathrm{d} x} \dfrac{\mathrm{d} }{\mathrm{d} x} P_n (x)\right|_{x_0} ≡ 2! · p_2$ |
| $\left.\dfrac{\mathrm{d}^n P_n (x)}{\mathrm{d} x^n}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}^n P_n (x)}{n! · \mathrm{d}^n x}\right|_{x_0} ≡ p_n$ | $\left.\dfrac{\mathrm{d}^0 P_n (x)}{\mathrm{d} x^0}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}^0 P_n (x)}{0! · \mathrm{d}^0 x}\right|_{x_0} ≡ p_0$ | $\left.\dfrac{\mathrm{d}^1 P_n (x)}{\mathrm{d} x^1}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}^1 P_n (x)}{1! · \mathrm{d}^1 x}\right|_{x_0} ≡ p_1$ | $\left.\dfrac{\mathrm{d}^2 P_n (x)}{\mathrm{d} x^2}\right|_{x_0} ≡ \left.\dfrac{\mathrm{d}^2 P_n (x)}{2! · \mathrm{d}^2 x}\right|_{x_0} ≡ p_2$ |
| $\dfrac{\mathrm{d} }{\mathrm{d} x} \dfrac{\mathrm{d}^n P_n (x)}{\mathrm{d} x^n} = \dfrac{(n + 1) · \mathrm{d}^{n+1} P_n (x)}{\mathrm{d} x^{n+1} }$ | $\dfrac{\mathrm{d} }{\mathrm{d} x} \dfrac{\mathrm{d}^0 P_n (x)}{\mathrm{d} x^0} = \dfrac{1 · \mathrm{d}^1 P_n (x)}{\mathrm{d} x^1}$ | $\dfrac{\mathrm{d} }{\mathrm{d} x} \dfrac{\mathrm{d}^1 P (x)}{\mathrm{d} x^1} = \dfrac{2 · \mathrm{d}^2 P_n (x)}{\mathrm{d} x^2}$ | $\dfrac{\mathrm{d} }{\mathrm{d} x} \dfrac{\mathrm{d}^2 P_n (x)}{\mathrm{d} x^2} = \dfrac{3 · \mathrm{d}^3 P_n (x)}{\mathrm{d} x^3}$ |

若任意形式的函数$f (x)$在点$x_0$处连续且有$n + 1$阶导数，则在点$x_0$处可唯一展开成$n$阶幂级数。

$f (x) = \sum\limits_{i=0}^n \dfrac{ {^i}f (x_0)}{i!} · (x - x_0)^i + R_n (x) = f (x_0) + \dfrac{ {^1}f (x_0)}{1!} · (x - x_0)^1 + \dfrac{ {^2}f (x)}{2!} · (x - x_0)^2 + ··· + \dfrac{ {^n}f (x)}{n!} · (x - x_0)^n + R_n (x)$

$f (x) = \sum\limits_{i=0}^n \left.\dfrac{\mathrm{d}^i f (x)}{i! · \mathrm{d}^i x}\right|_{x_0} · (x - x_0)^i + R_n (x) = f (x_0) + \left.\dfrac{\mathrm{d}^1 f (x)}{1! · \mathrm{d}^1 x}\right|_{x_0} · (x - x_0)^1 + \left.\dfrac{\mathrm{d}^2 f (x)}{2! · \mathrm{d}^2 x}\right|_{x_0} · (x - x_0)^2 + ··· + \left.\dfrac{\mathrm{d}^n f (x)}{n! · \mathrm{d}^n x}\right|_{x_0} · (x - x_0)^n + R_n (x)$

$f (x) = \sum\limits_{i=0}^n \left.\dfrac{\mathrm{d}^i f (x)}{\mathrm{d} x^i}\right|_{x_0} · (x - x_0)^i + R_n (x) = f (x_0) + \left.\dfrac{\mathrm{d}^1 f (x)}{\mathrm{d} x^1}\right|_{x_0} · (x - x_0)^1 + \left.\dfrac{\mathrm{d}^2 f (x)}{\mathrm{d} x^2}\right|_{x_0} · (x - x_0)^2 + ··· + \left.\dfrac{\mathrm{d}^n f (x)}{\mathrm{d} x^n}\right|_{x_0} · (x - x_0)^n + R_n (x)$

$R_n (x) = o (x - x_0)^n = f (x) - f (x_0) - \sum\limits_{i=1}^n \dfrac{ {^i}f (x_0)}{i!} · (x - x_0)^i  \mathop{====}\limits_{∃θ∈[x_0, x]} \dfrac{ {^{n+1} }f (θ)}{(n + 1)!} · (x - x_0)^{n + 1} \mathop{====}\limits_{∃θ∈[x_0, x]} \dfrac{ {^{n+1}f (θ)} }{n!} · (x - θ)^n · (x - x_0)^1 \mathop{====}\limits_{∃θ∈[x_0, x]} \int\limits_{x_0}^x \dfrac{ {^{n+1} }f (t)}{n!} · (x - t)^n \mathrm{d} t$

$[ R_n (x_0) = 0 ] ⇒ [ f (x) |_{x_0} = f (x_0) ]$

| $⇓$  | ${^m} R_n (x) = {^m} f (x) - {^m} f (x_0) - \sum\limits_{i=m+1}^n \dfrac{ {^{i-m} }f (x_0)}{i!} · \dfrac{i!}{(i - m)!} · (x - x_0)^{i-m}$ | $⇒$  | $\lim\limits_{x ⇝ x_0} {^m} R_n (x) \mathop{⇝}\limits_{0 ≤ m ≤ n} 0$ |
| :--: | ------------------------------------------------------------ | :--: | :----------------------------------------------------------- |
| $⇓$  | $\lim\limits_{x⇝x_0} \dfrac{R_n (x)}{(x - x_0)^n} = \lim\limits_{x⇝x_0} \dfrac{1}{n} · \dfrac{ {^1}R_n (x)}{(x - x_0)^{n - 1} } = \lim\limits_{x⇝x_0} \dfrac{(n - m)!}{n!} · \dfrac{ {^m} R_n (x)}{(x - x_0)^{n - m} } = ··· = \lim\limits_{x⇝x_0} \dfrac{0!}{n!} · \dfrac{ {^n}R_n (x)}{(x - x_0)^0} ⇝ 0$ |      |                                                              |
| $⇓$  | $R_n (x) = o (x - x_0)^{n}$                                  |      |                                                              |

| $⇓$  | $F (t) ≡ \sum\limits_{i=0}^n \dfrac{ {^i} f (t)}{i!} · (x - t)^i$ | $⇒$  | $R_n (x) = F (x) - F (x_0)$                                  |                                                     |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- | :-------------------------------------------------- |
| $⇓$  | ${^1} F (t) = \sum\limits_{i=0}^n \left[ \dfrac{ {^{i+1} } f (t)}{i!} · (x - t)^i - \dfrac{ {^i} f (t)}{i!} · i · (x - t)^{i-1} \right]$ |      |                                                              |                                                     |
| $⇓$  | ${^1}F (t) = \sum\limits_{i=0}^n \dfrac{ {^{i+1} } f (t)}{i!} · (x - t)^i - \sum\limits_{i=0}^{n-1} \dfrac{ {^{i+1} } f (t)}{i!} · (x - t)^i = \dfrac{ {^{n+1} } f (t)}{n!} · (x - t)^n$ |      |                                                              |                                                     |
| $⇓$  | $\dfrac{R_n (x)}{G (x) - G (x_0)} = \dfrac{F (x) - F (x_0)}{G (x) - G (x_0)} = \left.\dfrac{ {^1} F (t)}{ {^1} G (t)}\right|_{∃θ∈[x_0, x]} = \dfrac{ {^{n+1} } f (θ)}{n!} · \dfrac{(x - θ)^n}{ {^1} G (θ)} $ |      |                                                              |                                                     |
| $⇓$  | $R_n (x) \mathop{====}\limits_{∃θ∈[x_0, x]} \dfrac{ {^{n+1} } f (θ)}{n!} · \dfrac{(x - θ)^n}{ {^1} G (θ)} · [G (x) - G (x_0)]$ |      |                                                              |                                                     |
| $⇓$  | $R_n (x) \mathop{====}\limits_{∃θ∈[x_0, x]} \dfrac{ {^{n+1}f (θ)} }{(n + 1)!} · (x - x_0)^{n + 1}$ | $⇐$  | $G (t) ≡ (x - t)^{n + 1}$                                    | ${^1}G (t) = -(n + 1) · (x - t)^n$                  |
| $⇓$  | $R_n (x) \mathop{====}\limits_{∃θ∈[x_0, x]} \dfrac{ {^{n+1}f (θ)} }{n!} · (x - θ)^n · (x - x_0)^1$ | $⇐$  | $G (t) ≡ (x - t)^1$                                          | ${^1}G (t) = -1$                                    |
| $⇓$  | $R_n (x) \mathop{====}\limits_{∃θ∈[x_0, x]} \int\limits_{x_0}^x \dfrac{ {^{n+1} }f (t)}{n!} · (x - t)^n \mathrm{d} t$ | $⇐$  | $G (t) ≡ \int\limits_{x_0}^t \dfrac{ {^{n+1} }f (t)}{n!} · (x - t)^n \mathrm{d} t$ | ${^1}G (t) = \dfrac{ {^{n+1} }f (t)}{n!} · (x - t)^n$ |
| $⇓$  | $R_n (x) = O (x - x_0)^{n + 1}$                              | $⇐$  | $\varlimsup\limits_{x⇝x_0} \dfrac{R_n (x)}{(x - x_0)^{n + 1} } = \dfrac{ {^{n+1} }f (θ)}{(n + 1)!} ≤ \mathrm{Sup.}$ |                                                     |

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

$\int\limits_{X_0}^{X_1} f (x) \mathrm{d} x \mathop{≡≡≡≡}\limits_{X_0=x_0}^{X_1=x_{n+1} } \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \inf\limits_{x∈[x_i, x_i+1]} f (x) · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} f (θ_i) · Δx_i = \lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} \sup\limits_{x∈[x_i, x_{i+1}]} f (x) · Δx_i$

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

特例：函数$\mathcal{R} (x) \mathop{======}\limits_{m∈ℤ;n∈ℤ^+}^{1 = \gcd (|m|, |n|)} \mathop{\dfrac{1}{n} }\limits_{x=\frac{m}{n} }; \mathop{0}\limits_{x≠\frac{m}{n} }$在区间$[0, 1]$上，任何无理点处连续，任何有理点处不连续，其断点集为零测集，因此其定积分存在。

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
| $⇓$  | $\lim\limits_{n⇝∞⁺}^{Δx_i⇝0} \sum\limits_{i=0}^{n} w_i^{\frac{f}{g} } · Δx_i ⇝ 0$ |
| $⇓$  | $∃ε>0;∃ε^f,ε^g>0; \left[ w_i^f < ε^f \right] ∧ \left[ w_i^g < ε^g \right] ⇒ \left[ w_i^{\frac{f}{g} } ≤ \left[ \dfrac{1}{\inf | g (x) |} · w_i^f + \dfrac{\sup | f (x) |}{\inf | g^2 (x) |} · w_i^g \right] < \dfrac{1}{\inf | g (x) |} · ε^f + \dfrac{\sup | f (x) |}{\inf | g^2 (x) |} · ε^g = ε \right]$ |
| $⇓$  | $∃ε>0;∃ε^f,ε^g>0; \left[ ε ≤ w_i^{\frac{f}{g} } \right] ⇒ \left[ ε^f ≤ w_i^f \right] ∨ \left[ ε^g ≤ w_i^g \right]$ |
| $⇓$  | $\mathcal{O}^{\frac{f}{g} } ⊆ \mathcal{\mathcal{O}^{f} } ∪ \mathcal{O}^{g}$ |

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

反例：函数$\mathrm{sgn} (y) = \mathop{-1}\limits_{y<0};\mathop{0}\limits_{y=0};\mathop{+1}\limits_{y>0}$在区间$[0, 1]$上的定积分存在，函数$\mathcal{F} (x) ≡ \mathop{I_i - \left| x - X_{i,j} \right|}\limits_{| x - X_{i,j} | < I_{i} }; \mathop{0}\limits_{| x - X_{i,j} | ≥ I_{i} }$在区间$[0, 1]$上连续因此定积分存在。

但复合函数$\mathrm{sgn} (\mathcal{F} (x)) = \mathop{1}\limits_{|x-X_{i,j}|<I_i};\mathop{0}\limits_{|x-X_{i,j}|≥I_i}$在区间$[0, 1]$上的断点集非为零测集，其定积分不存在。

反例：函数$\mathrm{sgn} (y) = \mathop{-1}\limits_{y<0};\mathop{0}\limits_{y=0};\mathop{+1}\limits_{y>0}$在区间$[0, 1]$上的定积分存在，函数$\mathcal{R} (x) \mathop{======}\limits_{m∈ℤ;n∈ℤ^+}^{1 = \gcd (|m|, |n|)} \mathop{\dfrac{1}{n} }\limits_{x=\frac{m}{n} }; \mathop{0}\limits_{x≠\frac{m}{n} }$在区间$[0, 1]$上的定积分存在。

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

