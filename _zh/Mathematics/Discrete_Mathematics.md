---
layout:  zh_post
Topic :  收敛极限
Title :  离散数学
Update:  2021-04-20T18:00:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 约定

全称量词$∀$表示对于每个/对于所有，存在量词$∃$表示存在某个/存在一些，特称量词$Ⅎ$表示对于特定/唯一存在/实际存在。

集合$S$中元素的总个数为$\mathrm{ord} S$，区域$I$中元素的总大小为$\mathrm{fld}I$。

### 关系

$n + 1$元有序集合族$\left\lbrace \mathop{S_i}\limits_{0≤i≤n} \right\rbrace$按先后次序从其各个集合中选取元素$s_i∈S_i$，可排列成$n + 1$元序偶$〈s_0, s_1, ..., s_n 〉$。

$n + 1$元有序集合族$\left\lbrace \mathop{S_i}\limits_{0≤i≤n} \right\rbrace$所有可能的$n + 1$元序偶，组成其全乘积$〈S_0 × S_1 × ... × S_n〉≡ \left\lbrace ∀s_i;〈s_0, s_1, ..., s_n〉\middle| s_i∈S_i∈\left\lbrace \mathop{S_i}\limits_{0≤i≤n} \right\rbrace \right\rbrace$，其元素的个数为$\prod\limits_{i=0}^{n} \mathrm{ord} S_i$。

$n + 1$元有序集合族$\left\lbrace \mathop{S_i}\limits_{0≤i≤n} \right\rbrace$所有的集合若为同一集合$S$，则其全乘积即为集合$S$的$n + 1$次幂方，可简记作$S^{n+1} ≡ \left\lbrace ∀s_i;〈s_0, s_1, ..., s_n 〉\middle| s_i∈S \right\rbrace$。

$n + 1$元有序集合族$\left\lbrace \mathop{S_i}\limits_{0≤i≤n} \right\rbrace$所有存在的$n + 1$元序偶，组成其$n + 1$元关系$\mathcal{F}〈S_0 × S_1 × ... × S_n〉≡ \left\lbrace ∀s_i;〈s_0, s_1, ..., s_n 〉\middle| Ⅎ〈s_0, s_1, ..., s_n 〉∈〈S_0 × S_1 × ... × S_n〉\right\rbrace$。

全乘积具有的典型运算性质。

| 零元性 | $𝟘 =〈S × 𝟘〉$                                  | $𝟘 =〈𝟘 × S〉$                                  |
| :----: | :----------------------------------------------------------- | :----------------------------------------------------------- |
| 不称性 | $〈S × T〉\not≡〈T × S〉$          |                                                              |
| 限定性 | $R = T ∧ S = U ⇒〈R × S〉=〈T × U〉$ | $R ⊆ T ∧ S ⊆ U ⇒〈R × S〉⊆〈T × U〉$ |
| 结合性 | $〈R × S × T〉=〈(R × S) × T〉$    | $〈R × S × T〉=〈R × (S × T)〉$    |
| 结合性 | $〈R × S × T〉≠〈〈R × S〉× T〉$    | $〈R × S × T〉≠〈R ×〈S × T〉〉$    |
| 分配性 | $〈(R ⋃ S) × T〉=〈R × T〉⋃〈S × T〉$ | $〈R × (S ⋃ T)〉=〈R × S〉⋃〈R × T〉$ |
| 分配性 | $〈(R ⋂ S) × T〉=〈R × T〉⋂〈S × T〉$ | $〈R × (S ⋂ T)〉=〈R × S〉⋂〈R × T〉$ |

| $∀rs;∀t;$ | $〈rs, t〉∈〈(R ⋃ S) × T〉$                      |      |                                                              |
| :-------: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
|    $⇕$    | $[rs∈R⋃S] ∧ [t∈T]$                                           | $⇔$  | $[rs∈R ∨ rs∈S] ∧ [t∈T]$                                      |
|    $⇕$    | $[rs∈R ∧ t∈T] ∨ [rs∈S ∧ t∈T]$                                | $⇔$  | $〈rs, t〉∈〈R×T〉∨〈〈rs, t〉∈S×T〉$ |
|    $⇕$    | $〈rs, t〉∈〈R × T〉⋃〈S × T〉$    |      |                                                              |
|    $⇓$    | $〈(R ⋃ S) × T〉=〈R × T〉⋃〈S × T〉$ |      |                                                              |
|           |                                                              |      |                                                              |
| $∀rs;∀t;$ | $〈rs, t〉∈〈(R ⋂ S) × T〉$                      |      |                                                              |
|    $⇕$    | $[rs∈R⋂S] ∧ [t∈T]$                                           | $⇔$  | $[rs∈R ∧ rs∈S] ∧ [t∈T]$                                      |
|    $⇕$    | $[rs∈R ∧ t∈T] ∧ [rs∈S ∧ t∈T]$                                | $⇔$  | $〈rs, t〉∈〈R × T〉∧〈〈rs, t〉∈S × T〉$ |
|    $⇕$    | $〈rs, t〉∈〈R × T〉⋂〈S × T〉$    |      |                                                              |
|    $⇓$    | $〈(R ⋂ S) × T〉=〈R × T〉⋂〈S × T〉$ |      |                                                              |

二元关系$\mathcal{F}〈Y × X〉$，其前域$Y$中所有存在的元素组成其值域$\mathrm{val} \mathcal{F} ≡ \lbrace ∀y;y | ∃x;〈y, x 〉∈\mathcal{F} \rbrace$，其后域$X$中所有存在的元素组成其原域$\mathrm{def} \mathcal{F} ≡ \lbrace ∀x;x | ∃y;〈y, x 〉∈\mathcal{F} \rbrace$。

二元关系$\mathcal{F}〈Y × X〉$，其值域$\mathrm{val}\mathcal{F} ⊆ Y$与其原域$\mathrm{def}\mathcal{F} ⊆ X$对换位置，即为其反关系${'}\mathcal{F}〈Y × X〉≡ \left\lbrace ∀x;∀y;〈x, y 〉\middle|〈y, x 〉∈\mathcal{F} \right\rbrace$。

二元关系$\mathcal{G}〈Z × Y〉$与$\mathcal{F}〈Y × X〉$，前者的原域$\mathrm{def}\mathcal{G} ⊆ Y$与后者的值域$\mathrm{val}\mathcal{F} ⊆ Y$叠加相消，即为复合关系$\mathcal{G} ∘ \mathcal{F}〈Z × X〉≡ \left\lbrace ∀z;∀x;〈z, x 〉\middle| ∃y;〈z, y 〉∈\mathcal{G} ∧〈y, x 〉∈\mathcal{F} \right\rbrace$。

二元关系$\mathcal{F}〈Y × X〉$，其值域$\mathrm{val}\mathcal{F} ⊆ Y$通常视为输出域，其原域$\mathrm{def}\mathcal{F} ⊆ X$通常视为输入域。原域的输入与值域的输出为多对多的关系，因此$\mathrm{ord}(\mathrm{val} \mathcal{F}) \not≡ \mathrm{ord}(\mathrm{def} \mathcal{F})$。

若采用简化的记法，二元关系$∀x∈\mathrm{def}\mathcal{F};∃y∈\mathrm{val}\mathcal{F}; y = \mathcal{F}(x)$，反关系$∀y∈\mathrm{val}\mathcal{F};∃x∈\mathrm{def}\mathcal{F}; x = {'}\mathcal{F}(y)$，复合关系$∀x∈\mathrm{def}\mathcal{G∘F};∃z∈\mathrm{val}\mathcal{G∘F}; z = \mathcal{G}(\mathcal{F}(x))$。

二元关系$\mathcal{F}〈X × X〉$可能具有的特殊性质。

| 相等性 | $∀x∈X;〈x, x 〉∈\mathcal{F}$                               |      | 恒等关系$\mathcal{I}〈X × X〉≡ \left\lbrace ∀x;〈x, x 〉\middle| x∈X \right\rbrace$ | $⇒$  | $\mathcal{I}〈X × X〉⊆ \mathcal{F}〈X × X〉$ |
| :----: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- | :--: | ------------------------------------------------------------ |
| 不等性 | $∀x∈X;〈x, x 〉∉\mathcal{F}$                               |      | 恒等关系$∀x;〈x, x 〉∈\mathcal{I}〈X × X〉⇔ x∈X$ | $⇒$  | $\mathcal{I}〈X × X〉⋂ \mathcal{F}〈X × X〉= 𝟘$ |
| 对称性 | $∀y∈X;∀x∈X;〈y, x 〉∈\mathcal{F} ⇒〈x, y 〉∈\mathcal{F}$ | $⇔$  | $∀y∈X;∀x∈X;〈y, x 〉∈\mathcal{F} ⇔〈x, y 〉∈\mathcal{F}$ | $⇒$  | $\mathcal{F}〈X × X〉= {'}\mathcal{F}〈X × X〉$ |
| 不称性 | $∀y∈X;∀x∈X;〈y, x 〉∈\mathcal{F} ⇒〈x, y 〉∉\mathcal{F}$ | $⇔$  | $∀y∈X;∀x∈X;〈y, x 〉∉\mathcal{F} ∨〈x, y 〉∉\mathcal{F}$ | $⇒$  | $\mathcal{F}〈X × X〉⋂ {'}\mathcal{F}〈X × X〉= 𝟘$ |
| 传递性 | $∀z∈X;∀y∈X;∀x∈X;〈z, y 〉∈\mathcal{F} ∧〈y, x 〉∈\mathcal{F} ⇒〈z, x 〉∈\mathcal{F}$ |      |                                                              | $⇒$  | $\mathcal{F}〈X × X〉∘ \mathcal{F}〈X × X〉⊆ \mathcal{F}〈X × X〉$ |

二元关系$\mathcal{F}〈Y × X〉$具有的典型运算性质。

| $\mathcal{F}〈Y × X〉\mathop{≡≡≡≡≡≡}\limits_{\mathrm{def} \mathcal{F} = \mathrm{def} \mathcal{G}}^{\mathrm{val} \mathcal{F} = \mathrm{val} \mathcal{G}} \mathcal{G}〈V × U〉$ | $\mathcal{F}〈Y × X〉\mathop{≡≡≡}\limits_{\mathcal{F}⊇\mathcal{G}}^{\mathcal{F}⊆\mathcal{G}} \mathcal{G}〈V × U〉$ |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\mathcal{F}〈Y × X〉= {''}\mathcal{F}〈Y × X〉$ | $\mathrm{val} \mathcal{F}〈Y × X〉= \mathrm{def} {'}\mathcal{F}〈Y × X〉$ |
| $\mathcal{F}〈Y × X〉= \mathcal{I}〈Y × Y〉∘ \mathcal{F}〈Y × X〉$ | $\mathcal{F}〈Y × X〉= \mathcal{F}〈Y × X〉∘ \mathcal{I}〈X × X〉$ |
| $\mathcal{I}〈\mathrm{def}F × \mathrm{def}F〉⊆ {'}\mathcal{F}〈Y × X〉∘ \mathcal{F}〈Y × X〉$ | $\mathcal{I}〈\mathrm{val}F × \mathrm{val}F〉⊆ \mathcal{F}〈Y × X〉∘ {'}\mathcal{F}〈Y × X〉$ |
| ${'}(\mathcal{G}〈Z × Y〉∘ \mathcal{F}〈Y × Z〉) = {'}\mathcal{F}〈Y × Z〉∘ {'}\mathcal{G}〈Z × Y〉$ |                                                              |
| $\mathcal{H}〈T × Z〉∘ \mathcal{G}〈Z × Y〉∘ \mathcal{F}〈Y × X〉= \mathcal{H}〈T × Z〉∘ (\mathcal{G}〈Z × Y〉∘ \mathcal{F}〈Y × X〉)$ | $\mathcal{H}〈T × Z〉∘ \mathcal{G}〈Z × Y〉∘ \mathcal{F}〈Y × X〉= (\mathcal{H}〈T × Z〉∘ \mathcal{G}〈Z × Y〉) ∘ \mathcal{F}〈Y × X〉$ |
| $\mathcal{H}〈Z × Y〉∘ (\mathcal{G}〈Y × X〉∪ \mathcal{F}〈Y × X〉) = (\mathcal{H}〈Z × Y〉∘ \mathcal{G}〈Y × X〉) ∪ (\mathcal{H}〈Z × Y〉∘ \mathcal{F}〈Y × X〉)$ | $(\mathcal{H}〈Z × Y〉∪ \mathcal{G}〈Z × Y〉) ∘ \mathcal{F}〈Y × X〉= (\mathcal{H}〈Z × Y〉∘ \mathcal{F}〈Y × X〉) ∪ (\mathcal{G}〈Z × Y〉∘ \mathcal{F}〈Y × X〉)$ |
| $\mathcal{H}〈Z × Y〉∘ (\mathcal{G}〈Y × X〉∩ \mathcal{F}〈Y × X〉) ⊆ (\mathcal{H}〈Z × Y〉∘ \mathcal{G}〈Y × X〉) ∩ (\mathcal{H}〈Z × Y〉∘ \mathcal{F}〈Y × X〉)$ | $(\mathcal{H}〈Z × Y〉∩ \mathcal{G}〈Z × Y〉) ∘ \mathcal{F}〈Y × X〉⊆ (\mathcal{H}〈Z × Y〉∘ \mathcal{F}〈Y × X〉) ∩ (\mathcal{G}〈Z × Y〉∘ \mathcal{F}〈Y × X〉)$ |

| $∀y;∀x;$ | $〈y, x 〉∈\mathcal{F}〈Y × X〉$                |      |                                                              |
| :------: | ------------------------------------------------------------ | :--: | :----------------------------------------------------------- |
|   $⇕$    | $〈x, y 〉∈{'}\mathcal{F}〈Y × X〉$             |      |                                                              |
|   $⇕$    | $〈y, x 〉∈{''}\mathcal{F}〈Y × X〉$            |      |                                                              |
|          |                                                              |      |                                                              |
| $∀y;∀x;$ | $〈y, x 〉∈\mathcal{F}〈Y × X〉$                |      |                                                              |
|   $⇕$    | $〈y, y 〉∈\mathcal{I}〈Y × Y〉∧〈y, x 〉∈\mathcal{F}〈Y × X〉$ |      |                                                              |
|   $⇕$    | $〈y, x 〉∈\mathcal{I}〈Y × Y〉∘ \mathcal{F}〈Y × X〉$ |      |                                                              |
|          |                                                              |      |                                                              |
| $∀y;∀x;$ | $〈x, y 〉∈{'}\mathcal{F}〈Y × X〉∧〈y, x 〉∈\mathcal{F}〈Y × X〉$ |      |                                                              |
|   $⇓$    | $〈x, x 〉∈{'}\mathcal{F}〈Y × X〉∘ \mathcal{F}〈Y × X〉$ |      |                                                              |
|   $⇓$    | $\mathcal{I}〈\mathrm{def}F × \mathrm{def}F〉⊆ {'}\mathcal{F}〈Y × X〉∘ \mathcal{F}〈Y × X〉$ |      |                                                              |
|          |                                                              |      |                                                              |
| $∀z;∀x;$ | $〈x, z 〉∈{'}(\mathcal{G}〈Z × Y〉∘ \mathcal{F}〈Y × Z〉)$ |      |                                                              |
|   $⇕$    | $〈z, x 〉∈\mathcal{G}〈Z × Y〉∘ \mathcal{F}[Y × Z]$ |      |                                                              |
|   $⇕$    | $∃y;〈z, y 〉∈\mathcal{G}〈Z × Y〉∧〈y, x 〉∈\mathcal{F}〈Y × Z〉$ | $⇔$  | $∃y;〈x, y 〉∈{'}\mathcal{F}〈Y × Z〉∧〈y, z 〉∈{'}\mathcal{G}〈Z × Y〉$ |
|   $⇕$    | $〈x, z 〉∈{'}\mathcal{F}〈Y × Z〉∘ {'}\mathcal{G}〈Z × Y〉$ |      |                                                              |
|          |                                                              |      |                                                              |
| $∀t;∀x;$ | $〈t, x 〉∈\mathcal{H}〈T × Z〉∘ (\mathcal{G}〈Z × Y〉∘ \mathcal{F}〈Y × X〉)$ |      |                                                              |
|   $⇕$    | $∃z;〈t, z 〉∈\mathcal{H}〈T × Z〉∧〈z, x 〉∈\mathcal{G}〈Z × Y〉∘ \mathcal{F}〈Y × X〉$ |      |                                                              |
|   $⇕$    | $∃z;∃y;〈t, z 〉∈\mathcal{H}〈T × Z〉∧〈z, y 〉∈\mathcal{G}〈Z × Y〉∧〈y, x 〉∈\mathcal{F}〈Y × X〉$ | $⇔$  | $∃y;〈t, y〉∈\mathcal{H}〈T × Z〉∘ \mathcal{G}〈Z × Y〉∧〈y, x 〉∈\mathcal{F}〈Y × X〉$ |
|   $⇕$    | $〈t, x〉∈(\mathcal{H}〈T × Z〉∘ \mathcal{G}〈Z × Y〉) ∘ \mathcal{F}〈Y × X〉$ |      |                                                              |
|          |                                                              |      |                                                              |
| $∀z;∀x;$ | $〈z, x〉∈\mathcal{H}〈Z × Y〉∘ (\mathcal{G}〈Y × X〉∪ \mathcal{F}〈Y × X〉)$ |      |                                                              |
|   $⇕$    | $∃y;〈z, y〉∈\mathcal{H}〈Z × Y〉∧〈y, x〉∈\mathcal{G}〈Y × X〉∪ \mathcal{F}〈Y × X〉$ | $⇔$  | $∃y;〈z, y〉∈\mathcal{H}〈Z × Y〉∧ [〈y, x〉∈\mathcal{G}〈Y × X〉∨〈y, x〉∈\mathcal{F}〈Y × X〉]$ |
|   $⇕$    | $∃y; [〈z, y〉∈\mathcal{H}〈Z × Y〉∧〈y, x〉∈\mathcal{G}〈Y × X〉] ∨ [〈z, y〉∈\mathcal{H}〈Z × Y〉∧〈y, x〉∈\mathcal{F}〈Y × X〉]$ |      |                                                              |
|   $⇕$    | $[∃y;〈z, y〉∈\mathcal{H}〈Z × Y〉∧〈y, x〉∈\mathcal{G}〈Y × X〉] ∨ [∃y;〈z, y〉∈\mathcal{H}〈Z × Y〉∧〈y, x〉∈\mathcal{F}〈Y × X〉]$ | $⇔$  | $〈z, x〉∈\mathcal{H}〈Z × Y〉∘ \mathcal{G}〈Y × X〉∨〈z, x〉∈\mathcal{H}〈Z × Y〉∘ \mathcal{F}〈Y × X〉$ |
|   $⇕$    | $〈z, x〉∈\mathcal{H}〈Z × Y〉∘ \mathcal{G}〈Y × X〉∪ \mathcal{H}〈Z × Y〉∘ \mathcal{F}〈Y × X〉$ |      |                                                              |
|          |                                                              |      |                                                              |
| $∀z;∀x;$ | $〈z, x〉∈\mathcal{H}〈Z × Y〉∘ (\mathcal{G}〈Y × X〉∩ \mathcal{F}〈Y × X〉)$ |      |                                                              |
|   $⇕$    | $∃y;〈z, y〉∈\mathcal{H}〈Z × Y〉∧〈y, x〉∈\mathcal{G}〈Y × X〉∩ \mathcal{F}〈Y × X〉$ | $⇔$  | $∃y;〈z, y〉∈\mathcal{H}〈Z × Y〉∧ [〈y, x〉∈\mathcal{G}〈Y × X〉∧〈y, x〉∈\mathcal{F}〈Y × X〉]$ |
|   $⇕$    | $∃y; [〈z, y〉∈\mathcal{H}〈Z × Y〉∧〈y, x〉∈\mathcal{G}〈Y × X〉] ∧ [〈z, y〉∈\mathcal{H}〈Z × Y〉∧〈y, x〉∈\mathcal{F}〈Y × X〉]$ |      |                                                              |
|   $⇓$    | $[∃y;〈z, y〉∈\mathcal{H}〈Z × Y〉∧〈y, x〉∈\mathcal{G}〈Y × X〉] ∧ [∃y;〈z, y〉∈\mathcal{H}〈Z × Y〉∧〈y, x〉∈\mathcal{F}〈Y × X〉]$ | $⇔$  | $〈z, x〉∈\mathcal{H}〈Z × Y〉∘ \mathcal{G}〈Y × X〉∨〈z, x〉∈\mathcal{H}〈Z × Y〉∘ \mathcal{F}〈Y × X〉$ |
|   $⇕$    | $〈z, x〉∈\mathcal{H}〈Z × Y〉∘ \mathcal{G}〈Y × X〉⋂ \mathcal{H}〈Z × Y〉∘ \mathcal{F}〈Y × X〉$ |      |                                                              |

二元关系$\mathcal{F}〈Y × X〉$可能具有的类型。

| 满射$\mathcal{F}〈Y ⇹ X〉$ | $[∀y∈Y;∃x∈X;〈y, x〉∈\mathcal{F}] ∧ [∀x∈X;∃y∈Y;〈y, x〉∈\mathcal{F}]$ | $[\mathrm{val}\mathcal{F} = Y] ∧ [\mathrm{def}\mathcal{F} = X]$ | $[\mathrm{ord}(\mathrm{val}\mathcal{F}) = \mathrm{ord}(Y)] ∧ [\mathrm{ord}(\mathrm{def}\mathcal{F}) = \mathrm{ord}(X)]$ |
| :------------------------------------: | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| 敛射$\mathcal{F}〈Y ↢ X〉$ | $∀x∈\mathrm{def}\mathcal{F};Ⅎy∈\mathrm{val}\mathcal{F};〈y, x〉∈\mathcal{F}$ | $∀x;∀y_0,y_1;〈y_0, x〉∈\mathcal{F} ∧〈y_1, x〉∈\mathcal{F} ⇒ [y_0 = y_1]$ | $\mathrm{ord} (\mathrm{val}\mathcal{F}) ≤ \mathrm{ord} (\mathrm{def}\mathcal{F})$ |
| 散射$\mathcal{F}〈Y ↣ X〉$ | $∀y∈\mathrm{val}\mathcal{F};Ⅎx∈\mathrm{def}\mathcal{F};〈y, x〉∈\mathcal{F}$ | $∀y;∀x_0,x_1;〈y, x_0〉∈\mathcal{F} ∧〈y, x_1〉∈\mathcal{F} ⇒ [x_0 = x_1]$ | $\mathrm{ord} (\mathrm{val}\mathcal{F}) ≥ \mathrm{ord} (\mathrm{def}\mathcal{F})$ |
| 映射$\mathcal{F}〈Y ⇼ X〉$ | $[∀x∈\mathrm{def}\mathcal{F};Ⅎy∈\mathrm{val}\mathcal{F};〈y, x〉∈\mathcal{F}] ∧ [∀y∈\mathrm{val}\mathcal{F};Ⅎx∈\mathrm{def}\mathcal{F};〈y, x〉∈\mathcal{F}]$ | $∀x_0,x_1;∀y_0,y_1;〈y_0, x_0〉∈\mathcal{F} ∧〈y_1, x_1〉∈\mathcal{F} ⇒ [y_0 = y_1 ⇔ x_0 = x_1]$ | $\mathrm{ord} (\mathrm{val}\mathcal{F}) = \mathrm{ord} (\mathrm{def}\mathcal{F})$ |
| 置换$\mathcal{F}〈X ⇆ X〉$ | $[∀x∈X;Ⅎy∈X;〈y, x〉∈\mathcal{F}] ∧ [∀y∈X;Ⅎx∈X;〈y, x〉∈\mathcal{F}]$ | $\mathrm{val}\mathcal{F} = \mathrm{def}\mathcal{F} = X$      | $\mathrm{ord}(\mathrm{val}\mathcal{F}) = \mathrm{ord}(\mathrm{def}\mathcal{F}) = \mathrm{ord}(X)$ |

二元关系$\mathcal{F}〈Y × X〉$可视为$\rlap{≡≡≡≡≡≡≡}{单变元单变量多值}$函数，通常记作$Y ⊨ \mathcal{F}(X)$。其敛射关系可视为$\rlap{≡≡≡≡≡≡≡≡≡≡}{单变元单变量单值}$函数，通常记作$Y = \mathcal{F}(X)$。其映射关系同时满足敛射关系与散射关系，通常记作$Y ≡ \mathcal{F}(X)$。

多元关系$\mathcal{F}〈(Y_0 × Y_1 × ... × Y_m) × (X_0 × X_1 × ... × X_n)〉$可视为$n变元m变量多值$函数，通常记作$(Y_0, Y_1, ..., Y_m) ⊨ \mathcal{F}(X_0, X_1, ..., X_n)$。其敛射关系可视为$n变元m变量\rlap{≡≡}{单值}$函数，通常记作$(Y_0, Y_1, ..., Y_m) = \mathcal{F}(X_0, X_1, ..., X_n)$。其映射关系同时满足敛射关系与散射关系，通常记作$(Y_0, Y_1, ..., Y_m) ≡ \mathcal{F}(X_0, X_1, ..., X_m)$。

二元关系 $\mathcal{F}〈Y × X〉$可能有$2^{\mathrm{ord} Y × \mathrm{ord} X}$个，敛射关系$\mathcal{F}: Y ↢ X$可能有$\sum\limits_{i=0}^{\mathrm{ord}X} \dfrac{(\mathrm{ord}X)!}{i! · (\mathrm{ord}X - i)!} · (\mathrm{ord}Y)^{i} = (\mathrm{ord}Y + 1)^{\mathrm{ord}X}$个，散射关系$\mathcal{F}: Y ↣ X$可能有$\sum\limits_{i=0}^{\mathrm{ord}Y} \dfrac{(\mathrm{ord}Y)!}{i! · (\mathrm{ord}Y - i)!} · (\mathrm{ord}X)^{i} = (\mathrm{ord}X + 1)^{\mathrm{ord}Y}$个。映射关系$\mathcal{F}: Y ⇼ X$可能有$\sum\limits_{i=0}^{\min\lbrace \mathrm{ord}X, \mathrm{ord}Y \rbrace} \dfrac{(\mathrm{ord}X)!}{i! · (\mathrm{ord}X - i)!} · \dfrac{(\mathrm{ord}Y)!}{i! · (\mathrm{ord}Y - i)!} · i! = \sum\limits_{i=0}^{\min\lbrace \mathrm{ord}X, \mathrm{ord}Y \rbrace} \dfrac{(\mathrm{ord}X)! · (\mathrm{ord}Y)!}{i! ·(\mathrm{ord}X - i)! · (\mathrm{ord}Y - i)!}$个。

典例：集合$Y = \lbrace y_0 \rbrace$，集合$X = \lbrace x_0, x_1, x_2 \rbrace$。

二元关系可能有$2^{1 × 3} = 8$个，分别为$𝟘, \lbrace〈y_0, x_0〉\rbrace, \lbrace〈y_0, x_1〉\rbrace, \lbrace〈y_0, x_2〉\rbrace, \lbrace〈y_0, x_0〉,〈y_0, x_1〉\rbrace, \lbrace〈y_0, x_0〉,〈y_0, x_2〉\rbrace, \lbrace〈y_0, x_1〉,〈y_0, x_2〉\rbrace, \lbrace〈y_0, x_0〉,〈y_0, x_1〉,〈y_0, x_2〉\rbrace$。

敛射关系可能有$(1 + 1)^3 = 8$个，分别为$𝟘, \lbrace〈y_0, x_0〉\rbrace, \lbrace〈y_0, x_1〉\rbrace, \lbrace〈y_0, x_2〉\rbrace, \lbrace〈y_0, x_0〉,〈y_0, x_1〉\rbrace, \lbrace〈y_0, x_0〉,〈y_0, x_2〉\rbrace, \lbrace〈y_0, x_1〉,〈y_0, x_2〉\rbrace, \lbrace〈y_0, x_0〉,〈y_0, x_1〉,〈y_0, x_2〉\rbrace$。

散射关系可能有$(3 + 1)^1 = 4$个，分别为$𝟘, \lbrace〈y_0, x_0〉\rbrace, \lbrace〈y_0, x_1〉\rbrace, \lbrace〈y_0, x_2〉\rbrace$。

映射关系可能有$\dfrac{1!·3!}{0!·1!·3!} + \dfrac{1!·3!}{1!·0!·2!} = 4$个，分别为$𝟘, \lbrace〈y_0, x_0〉\rbrace, \lbrace〈y_0, x_1〉\rbrace, \lbrace〈y_0, x_2〉\rbrace$。

二元关系$\mathcal{G}〈Z × Y〉$与二元关系$\mathcal{F}〈Y × X〉$的复合关系。

| $\mathcal{G}〈Z ⇹ Y〉∘ \mathcal{F}〈Y ⇹ X〉= \mathcal{G ∘ F}〈Z ⇹ X〉$ |      | $[Z = \mathrm{val}\mathcal{G}] ∧ [\mathrm{def}\mathcal{G} = Y = \mathrm{val}\mathcal{F}] ∧ [\mathrm{def}\mathcal{F} = X]$ |
| :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $\mathcal{G}〈Z ↢ Y〉∘ \mathcal{F}〈Y ↢ X〉= \mathcal{G ∘ F}〈Z ↢ X〉$ | $⇒$  | $\mathcal{G ∘ F}〈Z ⇼ X〉⇒ \mathcal{G}〈Z ⇼ Y〉∧ \mathcal{F}〈Y ⇼ X〉$ |
| $\mathcal{G}〈Z ↣ Y〉∘ \mathcal{F}〈Y ↣ X〉= \mathcal{G ∘ F}〈Z ↣ X〉$ | $⇒$  | $\mathcal{G ∘ F}〈Z ⇼ X〉⇒ \mathcal{G}〈Z ⇼ Y〉∧ \mathcal{F}〈Y ⇼ X〉$ |
| $\mathcal{G}〈Z ⇼ Y〉∘ \mathcal{F}〈Y ⇼ X〉= \mathcal{G ∘ F}〈Z ⇼ X〉$ |      |                                                              |
| $\mathcal{G}〈X ⇆ X〉∘ \mathcal{F}〈X ⇆ X〉= \mathcal{G ∘ F}〈X ⇆ X〉$ |      |                                                              |

| $⇓$  | $∀x∈\mathrm{def}\mathcal{F};Ⅎy∈\mathrm{val}\mathcal{F};〈y, x〉∈\mathcal{F}$ | $⇔$  | $\mathcal{F}〈Y ↢ X〉$     |
| :--: | :----------------------------------------------------------- | :--: | :------------------------------------- |
| $⇓$  | $∀y∈\mathrm{def}\mathcal{G};Ⅎz∈\mathrm{val}\mathcal{G};〈z, y〉∈\mathcal{G}$ | $⇔$  | $\mathcal{G}〈Z ↢ Y〉$     |
| $⇓$  | $∀x∈\mathrm{def}\mathcal{G ∘ F};Ⅎy∈\mathrm{def}\mathcal{G} ∩ \mathrm{val}\mathcal{F};Ⅎz∈\mathrm{val}\mathcal{G ∘ F};〈z, x〉∈\mathcal{G ∘ F}$ | $⇔$  | $\mathcal{G ∘ F}〈Z ↢ X〉$ |
|      |                                                              |      |                                        |
| $⇓$  | $[Z = \mathrm{val}\mathcal{G}] ∧ [\mathrm{def}\mathcal{G} = Y = \mathrm{val}\mathcal{F}] ∧ [\mathrm{def}\mathcal{F} = X]$ |      |                                        |
| $⇓$  | $∀x∈X;Ⅎy∈Y;Ⅎz∈Z;〈z, x〉∈\mathcal{G ∘ F}$                    | $⇔$  | $\mathcal{G ∘ F}〈Z ↢ X〉$ |
| $⇓$  | $∀z∈Z;Ⅎx∈X;〈z, x〉∈\mathcal{G ∘ F}$                         | $⇔$  | $\mathcal{G ∘ F}〈Z ⇼ X〉$ |
| $⇓$  | $∀x∈X;Ⅎy∈Y;〈y, x〉∈\mathcal{F}$                             | $⇔$  | $\mathcal{F}〈Y ↢ X〉$     |
| $⇓$  | $∀z∈Z;Ⅎx∈X;Ⅎy∈Y;〈z, y〉∈\mathcal{G}$                        |      |                                        |
| $⇓$  | $∀y∈Y;Ⅎz∈Z;〈z, y〉∈\mathcal{G}$                             | $⇔$  | $\mathcal{G}〈Z ↢ Y〉$     |
| $⇓$  | $[∀z∈Z;Ⅎy∈Y;〈z, y〉∈\mathcal{G}] ∧ [∀y∈Y;Ⅎz∈Z;〈z, y〉∈\mathcal{G}]$ | $⇔$  | $\mathcal{G}〈Z ⇼ Y〉$     |

### 无限集

有理数集定义在加运算与乘运算上，实数集定义在加运算与乘运算以及幂运算上，因此实数集中元素必远远多于有理数集中元素。

有理数集与实数集本身均具有无限紧致性，有理数集中的元素未能填满直线数轴上的点，实数集中的元素能填满直线数轴上的点。

若集合$S$满足$\mathrm{ord} S ≈ \mathrm{O}[ϰ_0]$，则称集合$S$为离散集，否则称集合$S$为连续集，因此有限集为离散集。

自然数集/整数集/有理数集为离散集，无理数集/实数集/复数集为连续集。

|                  $ℕ$                  | $⊊$  |                 $ℤ = ±ℕ$                  | $⫕$  |            $ℚ = \dfrac{ℕ^{ℕ}}{ℕ^{ℕ}} × ±ℕ$             | $⫕$  |     $𝔼 = \dfrac{ℕ^{\frac{ℕ}{ℕ}}}{ℕ^{\frac{ℕ}{ℕ}}} × ±ℕ$      | $=$  |      $ℝ = [0,1) × ±ℕ$       | $⊊$  |             $ℂ = ℝ ± τ · ℝ$              |
| :-----------------------------------: | :--: | :---------------------------------------: | :--: | :----------------------------------------------------: | :--: | :----------------------------------------------------------: | :--: | :-------------------------: | :--: | :--------------------------------------: |
|               离散/均匀               |      |                 离散/均匀                 |      |                       紧致/均匀                        |      |                       [猜测]紧致/不均                        |      |          紧致/连续          |      |                紧致/连续                 |
|        $\mathrm{ord} ℕ ≡ ϰ_0$         | $<$  |   $\mathrm{ord} ℤ = 2 · \mathrm{ord} ℕ$   | $≪$  |    $\mathrm{ord} ℚ ≤ 2 · \mathrm{ord}〈ℕ^{ℕ} × ℕ〉$    | $≪$  | $\mathrm{ord} 𝔼 ≤ 2 · \mathrm{ord}〈{(ℕ^{ℕ})}^{ℕ} × ℕ^{ℕ} × ℕ〉$ | $=$  | $\mathrm{ord} ℝ ≡ 2 · ϰ_1$  | $<$  | $\mathrm{ord} ℂ = \mathrm{ord}〈ℝ × ℝ〉$ |
|        $\mathrm{Θ}[ϰ_0] ≈ ϰ_0$        | $<$  |        $\mathrm{O}[ϰ_0] ≈ 2 · ϰ_0$        | $≪$  | $\mathrm{O}\left[ϰ_0^{ϰ_0+1}\right] ≈ 2 · ϰ_0^{ϰ_0+1}$ | $≪$  | $\mathrm{O}\left[ϰ_0^{ϰ_0^{ϰ_0+1}}\right] ≈ 2 · ϰ_0^{ϰ_0^2 + ϰ_0 + 1}$ | $=$  | $\mathrm{O}[ϰ_1] ≈ 2 · ϰ_1$ | $<$  |     $\mathrm{O}[ϰ_1^2] ≈ 4 · ϰ_1^2$      |
| $\mathrm{fld} ℕ = \dfrac{ϰ_0^2}{ϰ_1}$ | $<$  | $\mathrm{fld} ℤ = 2 · \dfrac{ϰ_0^2}{ϰ_1}$ | $≪$  |    $\mathrm{fld} ℚ ≤ 2 · \dfrac{ϰ_0^{ϰ_0+2}}{ϰ_1}$     | $≪$  |  $\mathrm{fld} 𝔼 ≤ 2 · \dfrac{ϰ_0^{ϰ_0^2 + ϰ_0 + 2}}{ϰ_1}$   | $=$  | $\mathrm{fld} ℝ = 2 · ϰ_0$  | $<$  |       $\mathrm{fld} ℂ = 4 · ϰ_0^2$       |

| 0维  | $\mathrm{fld} ●  = \left[ \dfrac{\mathrm{fld} ℝ}{\mathrm{ord} ℝ} \right]^0 = э^0 = \left[\dfrac{ϰ_0}{ϰ_1}\right]^{0} = 1$ | $\mathrm{fld} ℝ = 2 · ϰ_0$                | $\mathrm{ord} ℝ = 2 · ϰ_1$                |
| :--: | :----------------------------------------------------------- | :---------------------------------------- | :---------------------------------------- |
| 1维  | $\mathrm{fld} ● = \left[ \dfrac{\mathrm{fld} ℝ}{\mathrm{ord} ℝ} \right]^1 ≡ э^1 ≡ \left[\dfrac{ϰ_0}{ϰ_1}\right]^{1} = \mathrm{o}[1]$ | $\mathrm{fld}([0,1]) = 1$                 | $\mathrm{fld} ((0,1)) = 1$                |
| 2维  | $\mathrm{fld} ● = \left[ \dfrac{\mathrm{fld} ℝ}{\mathrm{ord} ℝ} \right]^2 = э^2 = \left[\dfrac{ϰ_0}{ϰ_1}\right]^2 = \mathrm{o}[1]$ | $\mathrm{fld}([0,1] × [0,1]) = 1$         | $\mathrm{fld}((0,1) × (0,1)) = 1$         |
| 3维  | $\mathrm{fld} ● = \left[ \dfrac{\mathrm{fld} ℝ}{\mathrm{ord} ℝ} \right]^3 = э^3 = \left[ \dfrac{ϰ_0}{ϰ_1} \right]^{3} = \mathrm{o}[1]$ | $\mathrm{fld}([0,1] × [0,1] × [0,1]) = 1$ | $\mathrm{fld}((0,1) × (0,1) × (0,1)) = 1$ |

典例：映射关系$y = f(x) = 2 · x - 1$，并且$\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = 2$，其中$X = \bigcup \lbrace X_i \rbrace = [0,1]$，因此$Y = \bigcup \lbrace Y_i \rbrace = [-1,+1]$，显然$\mathrm{ord} X < \mathrm{ord} Y$。

对于点域$x∈X_i$及其映射点域$y∈Y_i$，必满足$Y_i = f(X_i)$，$\mathrm{fld} Y_i = 2 · \mathrm{fld} X_i$，$\mathrm{ord} \lbrace Y_i \rbrace = \mathrm{ord} \lbrace X_i \rbrace$。

典例：映射关系$y = f(x) = \tan \left( \dfrac{2 · x - 1}{2} · π \right)$，并且$\dfrac{\mathrm{d} f(x)}{\mathrm{d} x} = \dfrac{π}{\cos^2 \left( \frac{2 · x - 1}{2} · π \right)}$，其中$X = \bigcup\lbrace X_i \rbrace = (0,1)$，因此$Y = \bigcup\lbrace Y_i \rbrace = (∞^{-},∞^{+})$，显然$\mathrm{ord} X < \mathrm{ord} Y$。

对于点域$x∈X_i$及其映射点域$y∈Y_i$，必满足$Y_i = f(X_i), \mathrm{fld} Y_i = \dfrac{π}{\cos^2 \left( \frac{2 · x - 1}{2} · π \right)} · \mathrm{fld} X_i, \mathrm{ord} \lbrace Y_i \rbrace = \mathrm{ord} \lbrace X_i \rbrace$。

典例：自然数集$ℕ$，整数集$ℤ$，倒自然数集$\dfrac{1}{ℕ^{+}} ⊊ [0, 1]$，倒整数集$\dfrac{1}{ℤ^{±}} ⊊ [-1, +1]$。

倒自然数集$\dfrac{1}{ℕ^{+}}$与倒整数集$\dfrac{1}{ℤ^{±}}$，满足映射关系$y = f(x) = 2 · x - 1$。

### 零测集

离散集与零测集彼此等价，离散集强调集合中元素的数量，零测集强调集合中元素的度量。

任意零测集$\mathcal{O}$，必存在可数个区间$X_{i}$覆盖之，使得其可测度大小为零。

$∀\mathcal{O};∀ε_1>0;∃\lbrace X_{i} \rbrace; \left[ \mathcal{O} ⊆ \bigcup X_i \right] ∧ \left[ \mathrm{ord} \mathcal{O} ≤ \sum\limits_{i=0}^{∞^{+}} \mathrm{ord} X_i < \sum\limits_{i=0}^{∞^{+}} \dfrac{ε_0}{2^{i}} = 2 · ε_0 = ε_1 \right]$

可数个零测集$\mathcal{O}_i$的合集$\lbrace \mathcal{O}_{i} \rbrace$为零测集。

$∀\lbrace\mathcal{O}_{i}\rbrace;∀ε_2>0;∃\lbrace X_{i,j} \rbrace; \left[ \lbrace \mathcal{O}_{i} \rbrace ⊆ \bigcup \bigcup X_{i,j} \right] ∧ \left[ \mathrm{ord} \lbrace \mathcal{O}_{i} \rbrace = \sum\mathrm{ord} \mathcal{O}_i = \sum \sum \mathrm{ord} X_{i,j} ≤ \sum\limits_{i=0}^{∞⁺} \dfrac{1}{2^{i} } · \sum\limits_{j=0}^{∞⁺} \dfrac{ε_0}{2^{j}} ≤ \sum\limits_{i=0}^{∞⁺} \dfrac{ε_1}{2^i} = 2 · ε_1 = ε_2 \right]$

