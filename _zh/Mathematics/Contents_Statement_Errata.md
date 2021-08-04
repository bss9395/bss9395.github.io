---
layout:  zh_post
Topic :  收敛极限
Title :  内容-声明-勘误
Update:  2021-08-01T07:46:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 内容

本书由下列多个文件组成。图像与资源文件尚未包含。文件名称根据字典序排列。

```
Analytic_Geometry.md
Calculus.md
Contents_Statement_Errata.md
Discrete_Mathematics.md
Fundamental_Relation.md
Important_Formula.md
Infinite_Series.md
Linear_Algebra.md
Numerical_Analysis.md
Special_Function.md
The_Natural_Base.md
Trigonometry.md
```

------

### 声明

```
本书中内容未必正确，
你觉得正确那就正确，
你觉得错误那就错误。

欢迎研习并指正错误，
如有疑问可以发邮件，
拷贝副本前先联系我。
```

```
本书如果能付梓出版发行，
不打算出版到新加坡地区。
```

电子邮箱：brilliantstarrysky9395@gmail.com
贵姓大名：璀璨星辰

------

### 勘误

```
本书中内容未必正确，
病毒内容会放在此处，
需要大量思考与讨论。
```

### 一致连续性

若函数$f(x)$在区间$X$上点$x_0$处导数值有确界，则函数$f(x)$在点$x_0$处连续，反之不对。$P ⇒ Q$

若函数$f(x)$在区间$X$上点$x_0$处间断，则函数$f(x)$在该点处导数值无确界，反之不对。$¬Q ⇒ ¬P$

$\left[ Ⅎx_0∈X;∃\mathrm{Sup}_{x_0}; \left| \dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x} \right| ≤ \mathrm{Sup}_{x_0} \right] ⇒ \left[ \lim\limits_{x⇝x_0} f(x) \mathop{⇝}\limits_{x_0∈X} f(x_0) \right]$

| $⇓$  | $Ⅎx_0∈X;∃ε>0;∀δ>0;∃x∈X; |x - x_0| ≤ δ ∧ |f(x) - f(x_0)| > ε$ | $⇔$  | $\lim\limits_{x⇝x_0} f(x) \not⇝ f(x_0)$                      |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $Ⅎx_0∈X;∃ε>0;∀δ>0;∃x∈X;Ⅎ\mathrm{Sup}_{x_0}; \left| \dfrac{f(x) - f(x_0)}{x - x_0} \right| \mathop{>}\limits_{δ⇝0^{+}} \dfrac{ε}{δ} ≥ \mathrm{Sup}_{x_0} = \dfrac{ε}{\sup δ}$ |      |                                                              |
| $⇓$  | $Ⅎx_0∈X;∀\mathrm{Sup}_{x_0}; \left| \dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x_0} \right| > \mathrm{Sup}_{x_0}$ | $⇔$  | $\left| \dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x_0} \right| = \lim\limits_{x⇝x_0} \left| \dfrac{f(x) - f(x_0)}{x - x_0} \right| ⇝ ∞^{+}$ |
|      |                                                              |      |                                                              |
| $⇓$  | $\left[ \lim\limits_{x⇝x_0} f(x) \not⇝ f(x_0) \right] ⇒ \left[ Ⅎx_0∈X;∀\mathrm{Sup}_{x_0}; \left| \dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x_0} \right| > \mathrm{Sup}_{x_0} \right]$ |      |                                                              |
| $⇓$  | $\left[ Ⅎx_0∈X;∃\mathrm{Sup}_{x_0}; \left| \dfrac{\mathrm{d} f(x_0)}{\mathrm{d} x_0} \right| ≤ \mathrm{Sup}_{x_0} \right] ⇒ \left[ \lim\limits_{x⇝x_0} f(x) ⇝ f(x_0) \right]$ |      |                                                              |

若函数$f (x)$在区间$X$上满足切割线极限过程，则函数$f (x)$在区间$X$上一致连续，反之亦然。原点是固定点，闭区间上的连续函数必一致连续。

本定理根据经验得到，原点与无穷大点均是特殊点。当$x$趋近于无穷大时，$Δx_t$趋近于零，两个过程通过取特定值可关联成同一个极限过程。

对于无穷大点处，可取$\lim\limits_{Δx_t ⇝ 0 \\ x⇝∞} x^{α} · Δx_t \mathop{⇝}\limits^{α>0} 1$，$\lim\limits_{Δx_t ⇝ 0 \\ x⇝∞} x^{α} · Δx_t \mathop{⇝}\limits^{α≤0} 0$。对于原点处，可取$\lim\limits_{Δx_t⇝0 \\ x⇝0} \dfrac{Δx_t}{x^{α}} \mathop{⇝}\limits^{α>1} 1$，$\lim\limits_{Δx_t⇝0 \\ x⇝0} \dfrac{Δx_t}{x^{α}} \mathop{⇝}\limits^{α≤1} 0$。

$\left[ 0 ↭ \lim\limits_{x↭x_t} \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} · Δx \right]  ⇔ \left[ \lim\limits_{x↭x_t} f(x) ↭ f(x_t) \right]$

| $0 ↭ \lim\limits_{x↭x_t} [ f(x) - f(x_t) ] = \lim\limits_{x↭x_t} \dfrac{f(x) - f(x_t)}{x - x_t} · (x - x_t) = \lim\limits_{x↭x_t} \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} · Δx$ |                                                              |                                                              |
| :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\lim\limits_{x↭x_t⇝∞} \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} · Δx = \lim\limits_{Δx⇝0 \\ x⇝∞} \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} · Δx$ | $\lim\limits_{Δx_t ⇝ 0 \\ x⇝∞} x^{α} · Δx_t \mathop{⇝}\limits^{α>0} 1$ | $\lim\limits_{Δx_t ⇝ 0 \\ x⇝∞} x^{α} · Δx_t \mathop{⇝}\limits^{α≤0} 0$ |
| $\lim\limits_{x↭x_t⇝0} \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} · Δx = \lim\limits_{Δx⇝0 \\ x⇝0} \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} · Δx$ | $\lim\limits_{Δx_t⇝0 \\ x⇝0} \dfrac{Δx_t}{x^{α}} \mathop{⇝}\limits^{α>1} 1$ | $\lim\limits_{Δx_t⇝0 \\ x⇝0} \dfrac{Δx_t}{x^{α}} \mathop{⇝}\limits^{α≤1} 0$ |

典例：函数$\sin x$在无穷大点处一致连续，函数$\sin x^2$在无穷大点处非一致连续。

典例：函数$\ln x$在原点处一致连续，函数$\dfrac{1}{x}$在原点处非一致连续，函数$\sin \dfrac{1}{x}$在原点处非一致连续，函数$x · \sin \dfrac{1}{x}$在原点处一致连续，函数$x^2 · \sin \dfrac{1}{x}$在原点处一致连续。

| $\dfrac{\mathrm{d}}{\mathrm{d} x} \sin x = \cos x$           | $\lim\limits_{Δx⇝0 \\ x⇝∞} \cos x · Δx ⇝ 0$               |      | $\dfrac{\mathrm{d}}{\mathrm{d} x} \ln x = \dfrac{1}{x}$      | $\lim\limits_{Δx⇝0 \\x⇝0} \dfrac{1}{x} · Δx ⇝ 0$             |
| :----------------------------------------------------------- | :-------------------------------------------------------- | :--: | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\dfrac{\mathrm{d}}{\mathrm{d} x} \sin x^2 = 2 · x · \cos x^2$ | $\lim\limits_{Δx⇝0 \\ x⇝∞} 2 · x · \cos x^2 · Δx \not⇝ 0$ |      | $\dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{1}{x} = -\dfrac{1}{x^2}$ | $\lim\limits_{Δx⇝0 \\ x⇝0} -\dfrac{1}{x^2} · Δx \not⇝ 0$     |
|                                                              |                                                           |      | $\dfrac{\mathrm{d}}{\mathrm{d} x} \sin \dfrac{1}{x} = - \dfrac{1}{x^2} · \cos \dfrac{1}{x}$ | $\lim\limits_{Δx⇝0 \\ x⇝0} -\dfrac{1}{x^2} · \cos \dfrac{1}{x} · Δx \not⇝ 0$ |
|                                                              |                                                           |      | $\dfrac{\mathrm{d}}{\mathrm{d} x} \left[ x · \sin \dfrac{1}{x} \right] = \sin \dfrac{1}{x} - \dfrac{1}{x} · \cos \dfrac{1}{x}$ | $\lim\limits_{Δx⇝0 \\ x⇝0} \left[ \sin \dfrac{1}{x} - \dfrac{1}{x} · \cos \dfrac{1}{x} \right] · Δx ⇝ 0$ |
|                                                              |                                                           |      | $\dfrac{\mathrm{d}}{\mathrm{d} x} \left[ x^2 · \sin \dfrac{1}{x} \right] = 2 · x · \sin \dfrac{1}{x} - \cos \dfrac{1}{x}$ | $\lim\limits_{Δx⇝0 \\ x⇝0} \left[ 2 · x · \sin \dfrac{1}{x} - \cos \dfrac{1}{x} \right] · Δx ⇝ 0$ |

### 零测集 

离散集与零测集彼此等价，离散集强调集合中元素的数量，零测集强调集合中元素的度量。

任意零测集$\mathcal{O}$，必存在可数个区间$X_{i}$覆盖之，使得其可测度大小为零。

$∀\mathcal{O};∀ε_1>0;∃\lbrace X_{i} \rbrace; \left[ \mathcal{O} ⊆ \bigcup X_i \right] ∧ \left[ \mathrm{ord} \mathcal{O} ≤ \sum\limits_{i=0}^{∞^{+}} \mathrm{ord} X_i < \sum\limits_{i=0}^{∞^{+}} \dfrac{ε_0}{2^{i}} = 2 · ε_0 = ε_1 \right]$

可数个零测集$\mathcal{O}_i$的合集$\lbrace \mathcal{O}_{i} \rbrace$为零测集。

$∀\lbrace\mathcal{O}_{i}\rbrace;∀ε_2>0;∃\lbrace X_{i,j} \rbrace; \left[ \lbrace \mathcal{O}_{i} \rbrace ⊆ \bigcup \bigcup X_{i,j} \right] ∧ \left[ \mathrm{ord} \lbrace \mathcal{O}_{i} \rbrace = \sum\mathrm{ord} \mathcal{O}_i = \sum \sum \mathrm{ord} X_{i,j} ≤ \sum\limits_{i=0}^{∞⁺} \dfrac{1}{2^{i} } · \sum\limits_{j=0}^{∞⁺} \dfrac{ε_0}{2^{j}} ≤ \sum\limits_{i=0}^{∞⁺} \dfrac{ε_1}{2^i} = 2 · ε_1 = ε_2 \right]$

