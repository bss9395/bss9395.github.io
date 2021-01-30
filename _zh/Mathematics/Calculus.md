---
layout:  zh_post
Topic :  收敛极限
Title :  微积分
Update:  2021-01-30T18:35:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 极值点

极小值与极大值是局部性质，最小值与最大值是全局性质。

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

