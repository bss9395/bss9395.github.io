---
layout:  zh_post
Topic :  收敛极限
Title :  重要公式
Update:  2021-08-07T10:19:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 注意

```
本书中避免使用阶乘算符，
特别是双叹号的阶乘算符，
两者均可替代为连乘算符,
连乘算符的下标从一开始。
```

$(2·n-1)!! = \prod\limits_{i=1}^{n} (2·i-1)$

$(2·n)!! = \prod\limits_{i=1}^{n} (2·i)$

$(2·n+1)!! = \prod\limits_{i=1}^{n} (2·i+1)$

### 基本数学常数

| $π$  | $3.1415926535,8979323846,...$ | $\lim\limits_{m⇝∞^{+}} \dfrac{1}{m} · \left[ \prod\limits_{i=1}^{m} (2·i) \right]^{+2} · \left[ \prod\limits_{i=1}^{m} (2·i-1) \right]^{-2}$ |
| :--- | :---------------------------- | :----------------------------------------------------------- |
| $ә$  | $2.7182818284,5904553488,...$ |                                                              |
|      |                               |                                                              |

### 特殊数学常数

| $Γ \left( \dfrac{1}{2} \right)$ | $π^{\frac{1}{2}}$ |
| :------------------------------ | :---------------- |
|                                 |                   |

### 重要极限

| $\dfrac{0}{0}$                                               | $\dfrac{∞}{∞}$                                               | $1^0$                                             | $0^{\frac{1}{0}}$                         | $∞^{\frac{1}{∞}}$                                            | $1^{∞}$                                                      | $1^{\frac{1}{∞}}$                                            | $0 · ∞$                                                      |
| :----------------------------------------------------------- | :----------------------------------------------------------- | ------------------------------------------------- | ----------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| $\lim\limits_{x⇝0} \dfrac{\sin x}{x} \mathop{⇝}\limits_{x∈\left(-\frac{π}{2},+\frac{π}{2}\right)}^{\sin |x| ≤ |x| ≤ \tan |x|} 1$ | $\lim\limits_{n⇝∞⁺} \dfrac{n^α}{β^n} \mathop{⇝}\limits_{1<β}^{0<α} 0$ | $\lim\limits_{x⇝0} \mathop{β^x}\limits_{0<β} = 1$ | $\lim\limits_{x⇝0^+} x^{\frac{1}{x}} ⇝ 0$ | $\lim\limits_{n⇝∞⁺} \sqrt[n]{n} \mathop{⇝}\limits^{\sqrt[n]{n} = 1 + α_n} 1$ | $\lim\limits_{x⇝±∞} \left( 1 + \dfrac{1}{x} \right)^{x} ⇝ ә$ | $\lim\limits_{n⇝∞⁺} \mathop{\sqrt[n]{β}}\limits_{0<β} \mathop{⇝}\limits^{\sqrt[n]{β} = 1 + α_n} 1$ | $\lim\limits_{x⇝0^+} x^α · \ln^{γ} x \mathop{⇝}\limits_{0<γ}^{0<α} 0$ |
| $\lim\limits_{x⇝0} \dfrac{\log_{β} (1 + x)}{x} ⇝ \dfrac{1}{\ln β}$ | $\lim\limits_{n⇝∞⁺} \dfrac{β^n}{n!} \mathop{⇝}\limits^{1<β} 0$ |                                                   |                                           | $\lim\limits_{n⇝∞⁺} \sqrt[n]{n!} \mathop{⇝}\limits^{1^n} ∞⁺$ | $\lim\limits_{x⇝∞⁺} \mathop{β^{x}}\limits_{0<β} = \mathop{0}\limits_{0<β<1};\mathop{1}\limits_{β=1};\mathop{∞⁺}\limits_{1<β}$ |                                                              |                                                              |
| $\lim\limits_{x⇝0} \dfrac{β^x - 1}{x} ⇝ \ln β$               | $\lim\limits_{x⇝∞⁺} \dfrac{\ln^{γ} x}{x^α} \mathop{⇝}\limits_{0<α}^{0<γ} 0$ |                                                   |                                           | $\lim\limits_{x⇝∞⁺} x^{\frac{1}{x}} ⇝ 1$                     |                                                              |                                                              |                                                              |
| $\lim\limits_{x⇝0} \dfrac{(1 + x)^{α} - 1}{x} ⇝ α$           | $\lim\limits_{x⇝∞⁺} \dfrac{x^α}{β^x} \mathop{⇝}\limits_{1<β}^{0<α} 0$ |                                                   |                                           |                                                              |                                                              |                                                              |                                                              |
|                                                              | $\lim\limits_{x⇝∞⁺} \dfrac{β^x}{x^x} \mathop{⇝}\limits^{1<β} 0$ |                                                   |                                           |                                                              |                                                              |                                                              |                                                              |

### 等值极限

| $\sin x ≈ x + \mathrm{o}[x]_{x=0}$                        |      |
| --------------------------------------------------------- | ---- |
| $\tan x ≈ x + \mathrm{o}[x]_{x=0}$                        |      |
| $1 - \cos x ≈ \dfrac{1}{2} · x^2 + \mathrm{o}[x^2]_{x=0}$ |      |
| ${'}\sin x ≈ x + \mathrm{o}[x]_{x=0}$                     |      |
| $\ln(1 + x) ≈ x + \mathrm{o}[x]_{x=0}$                    |      |
| $(1 + x)^{α} ≈ 1 + α · x + \mathrm{o}[x]_{x=0}$           |      |

### 阶乘数列极限

$\lim\limits_{n⇝∞^{+}} \dfrac{n}{\sqrt[n]{n!}} ⇝ ә$

| $\left( \dfrac{n + 1}{ә} \right)^{n} < n! < (n + 1) · \left( \dfrac{n + 1}{ә} \right)^{n}$ |
| ------------------------------------------------------------ |
| $\dfrac{n + 1}{n} · \dfrac{n}{\sqrt[n]{n!}} = \dfrac{n + 1}{\sqrt[n]{n!}} < ә < \sqrt[n]{n + 1} · \dfrac{n + 1}{\sqrt[n]{n!}} = \sqrt[n]{n + 1} · \dfrac{n + 1}{n} · \dfrac{n}{\sqrt[n]{n!}}$ |
| $\lim\limits_{n⇝∞^{+}} \dfrac{n}{\sqrt[n]{n!}} = \lim\limits_{n⇝∞^{+}} \dfrac{n + 1}{n} · \lim\limits_{n⇝∞^{+}} \dfrac{n}{\sqrt[n]{n!}} ⇝ ә ⇜ \lim\limits_{n⇝∞^{+}} \sqrt[n]{n + 1} · \lim\limits_{n⇝∞^{+}} \dfrac{n + 1}{n} · \lim\limits_{n⇝∞^{+}} \dfrac{n}{\sqrt[n]{n!}} = \lim\limits_{n⇝∞^{+}} \dfrac{n}{\sqrt[n]{n!}}$ |

### 等比数列极限

$\lim\limits_{n⇝∞⁺} β^n = \mathop{∞}\limits_{β<-1};\mathop{※}\limits_{β=-1};\mathop{0}\limits_{-1<β<+1};\mathop{1}\limits_{β=+1};\mathop{∞⁺}\limits_{+1<β}$

$\lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^{n} β^n = \lim\limits_{n⇝∞⁺} \dfrac{β^n - 1}{β - 1} = \mathop{∞}\limits_{β<-1};\mathop{※}\limits_{β=-1};\mathop{\dfrac{1}{1 - β}}\limits_{-1<β<+1};\mathop{∞⁺}\limits_{β=+1};\mathop{∞⁺}\limits_{+1<β}$

$\lim\limits_{x⇝∞^{±}} \dfrac{\sum\limits_{i=0}^{n} s_i · x^{i}}{\sum\limits_{j=0}^{m} t_j · x^{j}} = \lim\limits_{x⇝∞^{±}} \dfrac{s_n · x^n + s_{n-1} · x^{n-1} + ··· + s_1 · x^{1} + s_0 · x^{0}}{t_m · x^{m} + t_{m-1} · x^{m-1} + ··· + t_1 · x^{1} + t_0 · x^{0}} = \mathop{0}\limits_{n<m};\mathop{\dfrac{s_n}{t_n}}\limits_{n=m};\mathop{\dfrac{s_n}{t_m}·∞^{±}}\limits_{n>m}$

### 均值数列极限

$\left[ \lim\limits_{n⇝∞⁺} s_n ⇝ s,∞^{±} \right] ⇔ \left[ \lim\limits_{n⇝∞⁺} \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i ⇝ s,∞^{±} \right]$

$\left[ \lim\limits_{n⇝∞⁺} s_n \mathop{⇝}\limits_{0<s_n} s,∞^{+} \right] ⇒ \left[ \lim\limits_{n⇝∞^{+}} \left[ \prod\limits_{i=0}^{n} s_i \right]^{\frac{1}{n+1}} ⇝ s,∞^{+} \right]$

$\lim\limits_{n⇝∞^{+}} \left[ \sum\limits_{i=0}^{n} s_i^{n+1} \right]^{\frac{1}{n+1}} \mathop{⇝}\limits_{0≤s_i} \sup\limits_{i} s_i$

$\left[ \lim\limits_{n⇝∞^{+}} \dfrac{s_n}{t_n} ⇝ r,∞^{±} \right] ⇔ \left[ \lim\limits_{n⇝∞^{+}} \left[ \sum\limits_{i=0}^{n} s_n \right]^{+1} · \left[ \sum\limits_{i=0}^{n} t_n \right]^{-1} ⇝r,∞^{±} \right]$

$\left[ \lim\limits_{n⇝∞^{+}} s_n · t_n \mathop{⇝}\limits_{\lim\limits_{n⇝∞^{+}} t_n ⇝ t,∞^{±}}^{\lim\limits_{n⇝∞^{+}} s_n ⇝ s,∞^{±}} r,∞^{±} \right] ⇒ \left[ \lim\limits_{n⇝∞^{+}} \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} s_i · t_{n-i} ⇝ r,∞^{±} \right]$


| $⇓$  |                              $\lim\limits_{n⇝∞^{+}} s_n ⇝ s$ |                             $⇒$                              | $∀ε>0;∃N∈ℕ;∀n≥N; \left| \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} s_i - s \right| ≤ \left| \dfrac{1}{n + 1} · \sum\limits_{i=0}^{N-1} (s_i - s) \right| + \left| \dfrac{1}{n + 1} · \sum\limits_{i=N}^{n} (s_i - s) \right| ≤ \dfrac{\mathrm{Sum}}{n + 1} + \dfrac{n - N + 1}{n + 1} · ε_0 ≤ ε$ |
| :--: | -----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------- |
| $⇓$  |                          $\lim\limits_{n⇝∞^{+}} s_n ⇝ ∞^{+}$ | $\mathop{⇒}\limits_{\sum\limits_{i=0}^{n} t_i = \sum\limits_{i=0}^{N} \mathrm{Inf} + \sum\limits_{i=0}^{n} s_i}^{t_N=s_N+\mathrm{Inf}>0}$ | $\left[ \lim\limits_{n⇝∞^{+}} \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} \dfrac{1}{t_i} ⇝ 0^{+} \right] ⇒ \left[ \lim\limits_{n⇝∞^{+}} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} t_i^{-1} \right]^{-1} ⇝ ∞^{+} \right] ⇒ \left[ \lim\limits_{n⇝∞^{+}} \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} t_i ⇝ ∞^{+} \right] ⇒ \left[ \lim\limits_{n⇝∞^{+}} \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} s_i ⇝ ∞^{+} \right]$ |
| $⇓$  |                          $\lim\limits_{n⇝∞^{+}} s_n ⇝ ∞^{-}$ |                             $⇒$                              | $\left[ \lim\limits_{n⇝∞^{+}} \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} (-s_i) ⇝ ∞^{+} \right] ⇒ \left[ \lim\limits_{n⇝∞^{+}} \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} s_i ⇝ ∞^{-} \right]$ |
| $⇓$  |                        $\lim\limits_{n⇝∞^{+}} s_n ⇝ s,∞^{±}$ |                             $⇒$                              | $\lim\limits_{n⇝∞⁺} \dfrac{1}{n} · \sum\limits_{i=0}^n s_i = \lim\limits_{n⇝∞⁺} \dfrac{n}{n + 1} · \dfrac{1}{n} · \sum\limits_{i=0}^{n} s_i = \lim\limits_{n⇝∞⁺} \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i ⇝ s,∞^{±}$ |
|      |                                                              |                                                              |                                                              |
| $⇓$  | $\lim\limits_{n⇝∞⁺} \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i ⇝ s$ |                             $⇒$                              | $\left[ \lim\limits_{n⇝∞^{+}} \sum\limits_{i=0}^{n} s_i = \lim\limits_{n⇝∞^{+}} (n + 1) · s \right] ⇒ \left[ \lim\limits_{n⇝∞^{+}} s_{n} = \lim\limits_{n⇝∞^{+}} \left[ \sum\limits_{i=0}^{n} s_i - \sum\limits_{i=0}^{n-1} s_i \right] = \lim\limits_{n⇝∞^{+}} \left[ (n + 1) · s - n · s \right] ⇝ s \right]$ |
| $⇓$  | $\lim\limits_{n⇝∞⁺} \dfrac{1}{n + 1} · \sum\limits_{i=0}^n s_i ⇝ s,∞^{±}$ |                             $⇒$                              | $\lim\limits_{n⇝∞^{+}} s_{n} ⇝ s,∞^{±}$                      |
|      |                                                              |                                                              |                                                              |
| $⇓$  | $\lim\limits_{n⇝∞^{+}} s_n^{-1} \mathop{⇝}\limits_{0<s_n} s^{-1},0^{+}$ |                                                              | $\left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} s_i^{-1} \right]^{-1} \mathop{≤}\limits_{0<s_i} \left[ \prod\limits_{i=0}^{n} s_i \right]^{\frac{1}{n+1}} \mathop{≤}\limits_{0≤s_i} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} s_i^{+1} \right]^{+1}$ |
| $⇓$  | $\lim\limits_{n⇝∞⁺} s_n^{+1} \mathop{⇝}\limits_{0<s_n} s^{+1},∞^{+}$ |                             $⇒$                              | $\lim\limits_{n⇝∞^{+}} \left[ \prod\limits_{i=0}^{n} s_i \right]^{\frac{1}{n}} = \lim\limits_{n⇝∞^{+}} \left[ \prod\limits_{i=0}^{n} s_i \right]^{\frac{1}{n} · \frac{n}{n+1}} = \lim\limits_{n⇝∞^{+}} \left[ \prod\limits_{i=0}^{n} s_i \right]^{\frac{1}{n+1}} ⇝ s$ |
|      |                                                              |                                                              |                                                              |
| $⇓$  |                                                              |                                                              | $\sup\limits_{i≤n} s_i \mathop{=}\limits_{0≤s_i} \left[\sup\limits_{i≤n} s_i\right]^{\frac{n+1}{n+1}} \mathop{≤}\limits_{0≤s_i} \left[\sum\limits_{i=0}^{n} s_i^{n+1}\right]^{\frac{1}{n+1}} \mathop{≤}\limits_{0≤s_i} \left[(n + 1) · \sup\limits_{i≤n} s_i\right]^{\frac{1}{n+1}} \mathop{=}\limits_{0≤s_i} \sqrt[n+1]{n+1} · \sup\limits_{i≤n} s_i$ |
| $⇓$  |                                                              |                                                              | $\lim\limits_{n⇝∞^{+}} \left[ \sum\limits_{i=0}^{n} s_i^{n+1} \right]^{\frac{1}{n+1}} \mathop{⇝}\limits_{0≤s_i} \sup\limits_{i} s_i$ |
|      |                                                              |                                                              |                                                              |
| $⇓$  |                 $\lim\limits_{n⇝∞^{+}} \dfrac{s_n}{t_n} ⇝ r$ |                             $⇔$                              | $\left[ \lim\limits_{n⇝∞^{+}} s_n = \lim\limits_{n⇝∞^{+}} r · t_n \right] ⇔ \left[ \lim\limits_{n⇝∞^{+}} \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} (s_n - r · t_n) ⇝ 0 \right] ⇔ \left[ \lim\limits_{n⇝∞^{+}} \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} s_n = \lim\limits_{n⇝∞^{+}} \dfrac{r}{n + 1} · \sum\limits_{i=0}^{n} t_n \right]$ |
| $⇓$  |           $\lim\limits_{n⇝∞^{+}} \dfrac{s_n}{t_n} ⇝ r,∞^{±}$ |                             $⇔$                              | $\lim\limits_{n⇝∞^{+}} \left[ \sum\limits_{i=0}^{n} s_n \right]^{+1} · \left[ \sum\limits_{i=0}^{n} t_n \right]^{-1} = \lim\limits_{n⇝∞^{+}} \left[ \dfrac{r}{n + 1} · \sum\limits_{i=0}^{n} t_n \right]^{+1} · \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} t_n \right]^{-1} ⇝ r,∞^{±}$ |
|      |                                                              |                                                              |                                                              |
| $⇓$  | $\lim\limits_{n⇝∞^{+}} s_n · t_n \mathop{⇝}\limits_{\lim\limits_{n⇝∞^{+}} t_n ⇝ t}^{\lim\limits_{n⇝∞^{+}} s_n ⇝ s} r$ |                             $⇒$                              | $r ⇜ \lim\limits_{n⇝∞^{+}} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} s_i \right] · \lim\limits_{m⇝∞^{+}} \left[ \dfrac{1}{m + 1} · \sum\limits_{i=0}^{m} t_i \right] = \lim\limits_{n⇝∞^{+}} \left[ \dfrac{1}{n + 1} · \sum\limits_{m=0}^{n} \dfrac{1}{n + 1} · \sum\limits_{i=0}^{m} s_i · t_{n-i} \right] = \lim\limits_{n⇝∞^{+}} \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} s_i · t_{n-i}$ |
| $⇓$  | $\lim\limits_{n⇝∞^{+}} s_n · t_n \mathop{⇝}\limits_{\lim\limits_{n⇝∞^{+}} t_n ⇝ t,∞^{±}}^{\lim\limits_{n⇝∞^{+}} s_n ⇝ s,∞^{±}} r,∞^{±}$ |                             $⇒$                              | $\lim\limits_{n⇝∞^{+}} \dfrac{1}{n + 1} · \sum\limits_{n⇝∞^{+}}^{n} s_i · t_{n-i} ⇝ r,∞^{±}$ |

反例：数列极限$\lim\limits_{n⇝∞^{+}} \sum\limits_{i=0}^{n} \dfrac{1}{n + 1} ⇝ ∞^{+}$，并且$\lim\limits_{n⇝∞^{+}} \left. \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} \dfrac{1}{n + 1} \right] \middle/ \left[ \dfrac{1}{n + 1} \right] \right. = \lim\limits_{n⇝∞^{+}} \sum\limits_{i=0}^{n} \dfrac{1}{n + 1} ⇝ ∞^{+} ≠ 1$。

$∞^{+} ⇜ \lim\limits_{n⇝∞^{+}} \sum\limits_{i=0}^{n} \dfrac{1}{n + 1} = \lim\limits_{n⇝∞^{+}} (n + 1) · \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} \dfrac{1}{n + 1} \right] \not≡ \lim\limits_{n⇝∞^{+}} (n + 1) · \dfrac{1}{n + 1} = 1$

反例：数列极限$\lim\limits_{n⇝∞⁺} \sum\limits_{i=0}^n (-1)^i · i  ⇝ ∞$。

$∞ ⇜ \lim\limits_{n⇝∞⁺} (-i)^i · i ≠ \lim\limits_{n⇝∞⁺} \dfrac{1}{n + 1} · \sum\limits_{i=0}^n (-1)^i · i = \lim\limits_{2 · n⇝∞⁺} \dfrac{0 + (-1 + 2) + (-3 + 4) + ··· + [-(2 · n + 1) + 2 · n]}{2 · n + 1} = \lim\limits_{n⇝∞⁺} \dfrac{n}{2 · n + 1} ⇝ \dfrac{1}{2}$

典例：级数$\lim\limits_{n⇝∞^{+}} \sum\limits_{i=0}^{n} s_i ⇝ S$，且$\lim\limits_{n⇝∞^{+}} t_n ⇝ t,∞^{±}$。

$\lim\limits_{n⇝∞^{+}} \dfrac{1}{t_n} · \left[ \sum\limits_{i=0}^{n} t_i · s_i \right] \mathop{==}\limits^{S_0=0} \lim\limits_{n⇝∞^{±}} \dfrac{1}{t_n} · \left[ \sum\limits_{i=0}^{n} t_{i} · (S_{i+1} - S_{i}) \right] = \lim\limits_{n⇝∞^{+}} \dfrac{1}{t_n} · \left[ \sum\limits_{i=0}^{n} t_{i} · S_{i+1} - \sum\limits_{i=0}^{n-1} t_{i+1} · S_{i+1} \right] = \lim\limits_{n⇝∞^{+}} \left[ \dfrac{1}{t_n} · \left[ \sum\limits_{i=0}^{n-1} (t_{i+1} - t_{i}) · S_{i+1} \right] + S_{n+1} \right] = \lim\limits_{n⇝∞^{+}} \dfrac{t_{n} - t_{n-1}}{t_{n} - t_{n-1}} · S_{n} + \lim\limits_{n⇝∞^{+}} S_{n+1} ⇝ 0$

### 调和数列极限

$1 ⇜ \lim\limits_{n⇝∞^{+}} \dfrac{1}{\ln(n)} · \sum\limits_{i=1}^{n} \dfrac{1}{i}$

| $⇓$  | $\dfrac{x}{1 + x} \mathop{≤}\limits_{x>-1} \ln(1 + x) \mathop{≤}\limits_{x>-1} x$ | $⇒$  | $\dfrac{1}{n^{m}} = \dfrac{1}{n^{m} - 1} · \dfrac{1}{1 + \dfrac{1}{n^{m} - 1}} ≤ \ln\left( 1 + \dfrac{1}{n^{m} - 1} \right) ≤ \dfrac{1}{n^{m} - 1}$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\dfrac{1}{n^m} ≤ \ln\dfrac{n^m}{n^m - 1} ≤ \dfrac{1}{n^m - 1}$ |      | $\dfrac{α}{x + α} \mathop{≤}\limits_{x·(x+α)>0} \ln\left( 1 + \dfrac{α}{x} \right) \mathop{≤}\limits_{x·(x+α)>0} \dfrac{α}{x}$ |
|      |                                                              |      |                                                              |
| $⇓$  | $\dfrac{1}{n} ≤ \ln\left( \dfrac{n}{n - 1} \right) ≤ \dfrac{1}{n - 1}$ | $⇒$  | $\dfrac{1}{n} ≤ \ln(n) - \ln(n - 1) ≤ \dfrac{1}{n - 1}$      |
| $⇓$  | $\sum\limits_{i=2}^{n} \dfrac{1}{i} ≤ \ln(n) ≤ \sum\limits_{i=2}^{n} \dfrac{1}{i - 1}$ |      | $s_{n} ≡ \ln(n) - \sum\limits_{i=1}^{n} \dfrac{1}{i}$        |
| $⇓$  | $-1 ≤ \ln(n) - \sum\limits_{i=1}^{n} \dfrac{1}{i} ≤ \sum\limits_{i=2}^{n} \dfrac{1}{i - 1} - \sum\limits_{i=2}^{n} \dfrac{1}{i} - 1 = \sum\limits_{i=2}^{n} \dfrac{1}{i - 1} - \sum\limits_{i=2}^{n} \dfrac{1}{i - 1} -\dfrac{1}{n} = -\dfrac{1}{n}$ |      | $s_{n+1} - s_{n} = \ln\left( \dfrac{n + 1}{n} \right) - \dfrac{1}{n + 1} = \ln\left( 1 + \dfrac{1}{n} \right) - \dfrac{1}{n + 1} > 0$ |
| $⇓$  | $0 ⇜ \lim\limits_{n⇝∞^{+}} \dfrac{1}{\ln(n)} · \left[ \ln(n) - \sum\limits_{i=1}^{n} \dfrac{1}{i} \right]$ | $⇒$  | $1 ⇜ \lim\limits_{n⇝∞^{+}} \dfrac{1}{\ln(n)} · \sum\limits_{i=1}^{n} \dfrac{1}{i}$ |
|      |                                                              |      |                                                              |
| $⇓$  | $\dfrac{1}{n^{2}} ≤ \ln\left( \dfrac{n^2}{n^2 - 1} \right) ≤ \dfrac{1}{n^2 - 1}$ | $⇒$  | $\dfrac{1}{n^2} ≤ [\ln(n) - \ln(n - 1)] + [\ln(n) - \ln(n + 1)] ≤ \dfrac{1}{n^2 - 1}$ |
| $⇓$  | $\sum\limits_{i=2}^{n} \dfrac{1}{n^{2}} ≤ \ln(n) + [\ln(2) - \ln(n + 1)] = \ln \dfrac{2 · n}{n + 1} ≤ \sum\limits_{i=2}^{n} \dfrac{1}{n^2 - 1}$ |      | $s_{n} ≡ \ln \dfrac{2 · n}{n + 1} - \sum\limits_{i=1}^{n} \dfrac{1}{i^2}$ |
| $⇓$  | $-1 ≤ \ln \dfrac{2 · n}{n + 1} - \sum\limits_{i=1}^{n} \dfrac{1}{i^2} ≤ \sum\limits_{i=2}^{n} \dfrac{1}{i^2 - 1} - \sum\limits_{i=2}^{n} \dfrac{1}{i^2} - 1 = \sum\limits_{i=2}^{n} \dfrac{1}{i^2 - 1} - \sum\limits_{i=2}^{n} \dfrac{1}{(i - 1)^2} - \dfrac{1}{n^2} < -\dfrac{1}{n^2}$ |      | $s_{n+1} - s_{n} = \ln \dfrac{(n + 1)^2}{n · (n + 1)} - \dfrac{1}{(n + 1)^2} = \ln\left[ 1 + \dfrac{1}{(n + 1)^2 - 1} \right] - \dfrac{1}{(n + 1)^2} > 0$ |
| $⇓$  | $\dfrac{-1}{\ln 2} ⇜ \lim\limits_{n⇝∞^{+}} \dfrac{-1}{\ln \dfrac{2 · n}{n + 1}} ≤ \lim\limits_{n⇝∞^{+}} \dfrac{1}{\ln \dfrac{2 · n}{n + 1}} · \left[ \ln \dfrac{2 · n}{n + 1} - \sum\limits_{i=1}^{n} \dfrac{1}{i^2} \right] ≤ \lim\limits_{n⇝∞^{+}} \dfrac{-1}{n^2 · \ln \dfrac{2 · n}{n + 1}} ⇝ 0$ |      |                                                              |

------

### 初等导函数

|                                              |                                                              |                                                              | $\dfrac{\mathrm{d} f(x)^{g(x)}}{\mathrm{d} x} = f(x)^{g(x)} · \left[ \dfrac{\mathrm{d} g(x)}{\mathrm{d} x} · \ln |f(x)| + \dfrac{g(x)}{f(x)} · \dfrac{\mathrm{d} f(x)}{\mathrm{d} x} \right]$ |                                 |
| :------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------: | :----------------------------------------------------------- | :------------------------------ |
|                                              | $\dfrac{\mathrm{d} f(-x)}{\mathrm{d} x} \mathop{===}\limits^{t=-x} -\dfrac{\mathrm{d} f(t)}{\mathrm{d} t}$ |                                                              | $\dfrac{\mathrm{d} f(g(x))}{\mathrm{d} x} \mathop{===}\limits^{y=g(x)} \dfrac{\mathrm{d} f(y)}{\mathrm{d} y} · \dfrac{\mathrm{d} g(x)}{\mathrm{d} x}$ | $t \mathop{==}\limits^{x<0} -x$ |
| $f (x)$                                      | $\dfrac{\mathrm{d}{'}f^{⇵}(x)}{\mathrm{d} x} \mathop{====}\limits_{y={'}f^{⇵}(x)}^{x=f^{⇵}(y)} \left[ \dfrac{\mathrm{d} f^{⇵}(y)}{\mathrm{d} y} \right]^{-1}$ |               $\mathop{==}\limits_{X}^{f(X)}$                | $\lim\limits_{x_t⇝x} \dfrac{f(x_t) - f(x)}{x_t - x} \mathop{====}\limits^{x_t=x+Δx} \lim\limits_{Δx⇝0} \dfrac{f(x + Δx) - f(x)}{Δx}$ |                                 |
|                                              |                                                              |                                                              |                                                              |                                 |
| $\mathrm{Con}$                               | $0$                                                          |    $\mathop{====}\limits_{(∞^{-},∞^{+})}^{\mathrm{Con}}$     | $\lim\limits_{x_t⇝x} \dfrac{\mathrm{Con} - \mathrm{Con}}{x_t - x} ⇝ 0$ |                                 |
| $|x|$                                        | $\dfrac{|x|}{x}$                                             | $\mathop{===}\limits_{(∞^{-},0)}^{(0,∞^{+})};\mathop{=}\limits_{0}^{0};\mathop{===}\limits_{(0,∞^{+})}^{(0,∞^{+})}$ | $\lim\limits_{x_t⇝x>0} \dfrac{x_t - x}{x_t - x} ⇝ +1$        | $-1$                            |
| $\mathop{\log_β | x |}\limits_{0<β≠1}$       | $\dfrac{1}{x · \ln β}$                                       | $\mathop{====}\limits_{(∞^{-},0)}^{(∞^{-},∞^{+})};\mathop{====}\limits_{(0,∞^{+})}^{(∞^{-},∞^{+})}$ | $\lim\limits_{x_t⇝x>0} \dfrac{\log_β x_t - \log_β x}{x_t - x} = \lim\limits_{x_t⇝x} \log_{β} \left( \dfrac{x_t}{x} \right)^{\frac{1}{x_t - x}} = \dfrac{1}{\ln β} · \lim\limits_{x_t⇝x} \ln \left( 1 + \dfrac{x_t - x}{x} \right)^{\frac{x}{x_t-x} · \frac{1}{x}} ⇝ \dfrac{1}{x · \ln β}$ | $\dfrac{-1}{t·\ln β}$           |
| $\ln | x |$                                  | $\dfrac{1}{x}$                                               | $\mathop{====}\limits_{(∞^{-},0)}^{(∞^{-},∞^{+})};\mathop{====}\limits_{(0,∞^{+})}^{(∞^{-},∞^{+})}$ |                                                              |                                 |
| $\mathop{β^x}\limits_{0<β≠1}$                | $β^x · \ln β$                                                |      $\mathop{====}\limits_{(∞^{-},∞^{+})}^{(0,∞^{+})}$      | $\dfrac{\mathrm{d} β^{x}}{\mathrm{d} x} = \left[ \dfrac{\mathrm{d} \log_β y}{\mathrm{d} y} \right]^{-1} = \left[ \dfrac{1}{y · \ln β} \right]^{-1} = β^{x} · \ln β$ |                                 |
| $ә^x$                                        | $ә^x$                                                        |      $\mathop{====}\limits_{(∞^{-},∞^{+})}^{(0,∞^{+})}$      |                                                              |                                 |
| $|x|^{α}$                                    | $α · |x|^{α} · x^{-1}$                                       | $\mathop{===}\limits_{(∞^{-},0)}^{(0,∞^{+})};\mathop{=}\limits_{0}^{0};\mathop{===}\limits_{(0,∞^{+})}^{(0,∞^{+})}$ | $\dfrac{\mathrm{d} |x|^α}{\mathrm{d} x} = |x|^{α} · \left[ \dfrac{\mathrm{d} α}{\mathrm{d} x} · \ln |x| + \dfrac{α}{|x|} · \dfrac{|x|}{x} \right] = α · |x|^{α} · x^{-1}$ |                                 |
| $x^{α}$                                      | $α · x^{α - 1}$                                              | $\mathop{0<α}\limits_{(∞^{-},0)}^{(0,∞^{+})};\mathop{=}\limits_{0}^{0};\mathop{===}\limits_{(0,∞^{+})}^{(0,∞^{+})}$ | $\dfrac{\mathrm{d} x^{α}}{\mathrm{d} x} = x^{α} · \left[ \dfrac{\mathrm{d} α}{\mathrm{d} x} · \ln |x| + \dfrac{α}{x} · \dfrac{\mathrm{d} x}{\mathrm{d} x} \right] = α · x^{α-1}$ |                                 |
| $x^x$                                        | $x^{x} · [\ln |x| + 1]$                                      | $\mathop{===}\limits_{(∞^{-},0)}^{?};\mathop{=}\limits_{0}^{0};\mathop{=====}\limits_{(0,∞^{+})}^{(ә^{-ә^{-1}},∞^{+})}$ | $\dfrac{\mathrm{d} x^x}{\mathrm{d} x} = x^{x} · \left[ \dfrac{\mathrm{d} x}{\mathrm{d} x} · \ln |x| + \dfrac{x}{x} · \dfrac{\mathrm{d} x}{\mathrm{d} x} \right] = x^{x} · [\ln |x| + 1]$ |                                 |
|                                              |                                                              |                                                              |                                                              |                                 |
| $\sin x = \dfrac{ә^{τ·x} - ә^{-τ·x}}{2 · τ}$ | $+\cos x = \sin \left( x + h · \dfrac{π}{2} \right)$         |         $\mathop{2·k·π}\limits_{(-π,+π)}^{[-1,+1]}$          | $\dfrac{\mathrm{d} \sin x}{\mathrm{d} x} = \dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{ә^{τ·x} - ә^{-τ·x}}{2 · τ} = +\dfrac{ә^{τ·x} + ә^{-τ·x}}{2} = +\cos x$ |                                 |
| $\cos x = \dfrac{ә^{τ·x} + ә^{-τ·x}}{2}$     | $-\sin x = \cos \left( x + h · \dfrac{π}{2} \right)$         |         $\mathop{2·k·π}\limits_{(-π,+π)}^{[-1,+1]}$          | $\dfrac{\mathrm{d} \cos x}{\mathrm{d} x} = \dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{ә^{τ·x} + ә^{-τ·x}}{2} = -\dfrac{ә^{τ·x} - ә^{-τ·x}}{2 · τ} = -\sin x$ |                                 |
| $\tan x = \dfrac{\sin x}{\cos x}$            | $+\cos^{-2} x$                                               | $\mathop{k·π}\limits_{(-\frac{π}{2},+\frac{π}{2})}^{(∞^{-},∞^{+})}$ | $\dfrac{\mathrm{d} \tan x}{\mathrm{d} x} = \dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\sin x}{\cos x} = \dfrac{+\cos^2 x + \sin^2 x}{\cos^2 x} = +\cos^{-2} x$ |                                 |
| $\tan^{-1} x$                                | $-\sin^{-2} x$                                               |        $\mathop{k·π}\limits_{(0,+π)}^{(∞^{-},∞^{+})}$        | $\dfrac{\mathrm{d} \tan^{-1} x}{\mathrm{d} x} = (-1) · \tan^{-2} x · \cos^{-2} x = - \sin^{-2} x$ |                                 |
| $\cos^{-1} x$                                | $+\cos^{-2} x · \sin x$                                      | $\mathop{2·k·π}\limits_{(-\frac{π}{2},+\frac{π}{2})}^{[+1,∞^{+})};\mathop{2·k·π}\limits_{(+\frac{π}{2},\frac{3·π}{2})}^{(∞^{-},-1]}$ | $\dfrac{\mathrm{d} \cos^{-1} x}{\mathrm{d} x} = (-1) · \cos^{-2} x · (-\sin x) = +\cos^{-2} x · \sin x$ |                                 |
| $\sin^{-1} x$                                | $-\sin^{-2} x · \cos x$                                      | $\mathop{2·k·π}\limits_{(-π,0)}^{(∞^{-},-1]};\mathop{2·k·π}\limits_{(0,+π)}^{[+1,∞^{+}]}$ | $\dfrac{\mathrm{d} \sin^{-1} x}{\mathrm{d} x} = (-1) · \sin^{-2} x · (+\cos x) = -\sin^{-2} x · \cos x$ |                                 |
|                                              |                                                              |                                                              |                                                              |                                 |
| ${'}\sin x$                                  | $\dfrac{+1}{\sqrt{1 - x^2}}$                                 | $\mathop{=====}\limits_{[-1,+1]}^{[-\frac{π}{2},+\frac{π}{2}]}$ | $\dfrac{\mathrm{d} {'}\sin x}{\mathrm{d} x} = \left[ \dfrac{\mathrm{d} \sin y}{\mathrm{d} y} \right]^{-1} = \dfrac{+1}{\cos y} = \dfrac{+1}{\sqrt{1 - \sin^2 y}} = \dfrac{+1}{\sqrt{1 - x^2}}$ |                                 |
| ${'}\cos x$                                  | $\dfrac{-1}{\sqrt{1 - x^2}}$                                 |    $\mathop{====}\limits_{[-1,+1]}^{\left[+0,+π \right]}$    | $\dfrac{\mathrm{d} {'}\cos x}{\mathrm{d} x} = \left[ \dfrac{\mathrm{d} \cos y}{\mathrm{d} y} \right]^{-1} = \dfrac{-1}{\sin y} = \dfrac{-1}{\sqrt{1 - \cos^2 y}} = \dfrac{-1}{\sqrt{1 - x^2}}$ |                                 |
| ${'}\tan x$                                  | $\dfrac{+1}{1 + x^2}$                                        | $\mathop{=====}\limits_{(∞^{-},∞^{+})}^{(-\frac{π}{2},+\frac{π}{2})}$ | $\dfrac{\mathrm{d} {'}\tan x}{\mathrm{d} x} = \left[ \dfrac{\mathrm{d} \tan y}{\mathrm{d} y} \right]^{-1} = \dfrac{+1}{\cos^{-2} y} = \dfrac{+1}{1 + \tan^2 y} = \dfrac{+1}{1 + x^2}$ |                                 |
| ${'}\tan^{-1} x$                             | $\dfrac{-1}{1 + x^2}$                                        | $\mathop{====}\limits_{(∞^{-},0^{-})}^{(-\frac{π}{2},0^{-})};\mathop{====}\limits_{(0^{+},∞^{+})}^{(0^{+},+\frac{π}{2})}$ | $\dfrac{\mathrm{d} {'}\tan^{-1} x}{\mathrm{d} x} = \left[ \dfrac{\mathrm{d} \tan^{-1} y}{\mathrm{d} y} \right]^{-1} = \dfrac{-1}{\sin^{-2} y} = \dfrac{-1}{1 + \tan^{-2} y} = \dfrac{-1}{1 + x^2}$ |                                 |
| ${'}\cos^{-1} x$                             | $\dfrac{+1}{|x| · \sqrt{x^2 - 1}}$                           | $\mathop{====}\limits_{(∞^{-},-1]}^{(+\frac{π}{2},+π]};\mathop{====}\limits_{[+1,∞^{+})}^{[+0,+\frac{π}{2})}$ | $\dfrac{\mathrm{d} {'}\cos^{-1} x}{\mathrm{d} x} = \left[ \dfrac{\mathrm{d} \cos^{-1} y}{\mathrm{d} y} \right]^{-1} = \dfrac{+1}{\cos^{-2} y · \sin y} = \dfrac{+1}{\cos^{-2} y · \sqrt{1 - \cos^2 y}} = \dfrac{+1}{|x| · \sqrt{x^2 - 1}}$ |                                 |
| ${'}\sin^{-1} x$                             | $\dfrac{-1}{|x| · \sqrt{x^2 - 1}}$                           | $\mathop{====}\limits_{(∞^{-},-1]}^{(0^{-},-\frac{π}{2}]};\mathop{====}\limits_{[+1,∞^{+})}^{[+\frac{π}{2},0^{+})}$ | $\dfrac{\mathrm{d} {'}\sin^{-1} x}{\mathrm{d} x} = \left[ \dfrac{\mathrm{d} \sin^{-1} y}{\mathrm{d} y} \right]^{-1} = \dfrac{-1}{\sin^{-2} y · \cos y} = \dfrac{-1}{\sin^{-2} y · \sqrt{1 - \sin^{2} y}} = \dfrac{-1}{|x| · \sqrt{x^2 - 1}}$ |                                 |
|                                              |                                                              |                                                              |                                                              |                                 |
| $\sinh x = \dfrac{ә^{x} - ә^{-x}}{2}$        | $+\cosh x$                                                   |    $\mathop{====}\limits_{(∞^{-},∞^{+})}^{(∞^{-},∞^{+})}$    | $\dfrac{\mathrm{d} \sinh x}{\mathrm{d} x} = \dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{ә^{x} - ә^{-x}}{2} = \dfrac{ә^{x} + ә^{-x}}{2} = +\cosh x$ |                                 |
| $\cosh x = \dfrac{ә^{x} + ә^{-x}}{2}$        | $+\sinh x$                                                   |     $\mathop{====}\limits_{(∞^{-},∞^{+})}^{[+1,∞^{+})}$      | $\dfrac{\mathrm{d} \cosh x}{\mathrm{d} x} = \dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{ә^{x} + ә^{-x}}{2} = \dfrac{ә^{x} - ә^{-x}}{2} = +\sinh x$ |                                 |
| $\tanh x = \dfrac{\sinh x}{\cosh x}$         | $+\cosh^{-2} x$                                              |       $\mathop{====}\limits_{(∞^{-},∞^{+})}^{(-1,+1)}$       | $\dfrac{\mathrm{d} \tanh x}{\mathrm{d} x} = \dfrac{\mathrm{d}}{\mathrm{d} x} \dfrac{\sinh x}{\cosh x} = \dfrac{\cosh^2 x - \sinh^2 x}{\cosh^2 x} = +\cosh^{-2} x$ |                                 |
| $\tanh^{-1} x$                               | $-\sinh^{-2} x$                                              | $\mathop{====}\limits_{(∞^{-},0^{-})}^{(∞^{-},-1)};\mathop{====}\limits_{(0^{+},∞^{+})}^{(+1,∞^{+})}$ | $\dfrac{\mathrm{d} \tanh^{-1} x}{\mathrm{d} x} = (-1) · \tanh^{-2} x · (+\cosh^{-2} x) = -\sinh^{-2} x$ |                                 |
| $\cosh^{-1} x$                               | $-\cosh^{-2} x · \sinh x$                                    |     $\mathop{====}\limits_{(∞^{-},∞^{+})}^{(0^{+},+1]}$      | $\dfrac{\mathrm{d} \cosh^{-1} x}{\mathrm{d} x} = (-1) · \cosh^{-2} x · (+\sinh x) = -\cosh^{-2} x · \sinh x$ |                                 |
| $\sinh^{-1} x$                               | $-\sinh^{-2} x · \cosh x$                                    | $\mathop{====}\limits_{(∞^{-},0^{-})}^{(∞^{-},0^{-})};\mathop{====}\limits_{(0^{+},∞^{+})}^{(0^{+},∞^{+})}$ | $\dfrac{\mathrm{d} \sinh^{-1} x}{\mathrm{d} x} = (-1) · \sinh^{-2} x · (+\cosh x) = -\sinh^{-2} x · \cosh x$ |                                 |
|                                              |                                                              |                                                              |                                                              |                                 |
| ${'}\sinh x$                                 | $\dfrac{+1}{\sqrt{x^2 + 1}}$                                 |    $\mathop{====}\limits_{(∞^{-},∞^{+})}^{(∞^{-},∞^{+})}$    | $\dfrac{\mathrm{d} {'}\sinh x}{\mathrm{d} x} = \left[ \dfrac{\mathrm{d} \sinh y}{\mathrm{d} y} \right]^{-1} = \dfrac{+1}{\cosh y} = \dfrac{+1}{\sqrt{\sinh^2 x + 1}} = \dfrac{+1}{\sqrt{x^2 + 1}}$ |                                 |
| ${'}\cosh x$                                 | $\dfrac{+1}{\sqrt{x^2 - 1}}$                                 |       $\mathop{====}\limits_{[+1,∞^{+})}^{[+0,∞^{+})}$       | $\dfrac{\mathrm{d} {'}\cosh x}{\mathrm{d} x} = \left[ \dfrac{\mathrm{d}\cosh y}{\mathrm{d} y} \right] = \dfrac{+1}{\sinh y} = \dfrac{+1}{\sqrt{\cosh^2 y - 1}} = \dfrac{+1}{\sqrt{x^2 - 1}}$ |                                 |
| ${'}\tanh x$                                 | $\dfrac{+1}{1 - x^2}$                                        |       $\mathop{====}\limits_{(-1,+1)}^{(∞^{-},∞^{+})}$       | $\dfrac{\mathrm{d} {'}\tanh x}{\mathrm{d} x} = \left[ \dfrac{\mathrm{d} \tanh y}{\mathrm{d} y} \right]^{-1} = \dfrac{+1}{\cosh^{-2} y} = \dfrac{+1}{1 - \tanh^{2} y} = \dfrac{+1}{1 - x^2}$ |                                 |
| ${'}\tanh^{-1} x$                            | $\dfrac{+1}{1 - x^2}$                                        | $\mathop{====}\limits_{(∞^{-},-1)}^{(∞^{-},0^{-})};\mathop{====}\limits_{(+1,∞^{+})}^{(0^{+},∞^{+})}$ | $\dfrac{\mathrm{d} {'}\tanh^{-1} x}{\mathrm{d} x} = \left[ \dfrac{\mathrm{d} \tanh^{-1} y}{\mathrm{d} y} \right]^{-1} = \dfrac{-1}{\sinh^{-2} y} = \dfrac{-1}{\tanh^{-2} y - 1} = \dfrac{+1}{1 - x^{2}}$ |                                 |
| ${'}\cosh^{-1} x$                            | $\dfrac{-1}{|x| · \sqrt{1 - x^2}}$                           |       $\mathop{====}\limits_{(0^{-},+1]}^{[0,∞^{+})}$        | $\dfrac{\mathrm{d} {'}\cosh^{-1} x}{\mathrm{d} x} = \left[ \dfrac{\mathrm{d} \cosh^{-1} y}{\mathrm{d} y} \right]^{-1} = \dfrac{-1}{\cosh^{-2} y · \sinh y} = \dfrac{-1}{\cosh^{-2} y · \sqrt{\cosh^{2} y - 1}} = \dfrac{-1}{|x| · \sqrt{1 - x^2}}$ |                                 |
| ${'}\sinh^{-1} x$                            | $\dfrac{-1}{|x| · \sqrt{1 + x^2}}$                           | $\mathop{====}\limits_{(∞^{-},0^{-})}^{(∞^{-},0^{-})};\mathop{====}\limits_{(0^{+},∞^{+})}^{(0^{+},∞^{+})}$ | $\dfrac{\mathrm{d} {'}\sinh^{-1} x}{\mathrm{d} x} = \left[ \dfrac{\mathrm{d} \sinh^{-1} y}{\mathrm{d} y} \right]^{-1} = \dfrac{-1}{\sinh^{-2} y · \cosh y} = \dfrac{-1}{\sinh^{-2} y · \sqrt{\sinh^{2} y + 1}} = \dfrac{-1}{|x| · \sqrt{1 + x^2}}$ |                                 |

### 初等原函数

| $f(x)$                          | $\int f(x) \mathrm{d}x$                                      | $\int f(x) \mathrm{d}x$                                      |           $X$            |
| ------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------: |
|                                 |                                                              |                                                              |                          |
| $\mathop{β^{x}}\limits_{0<β≠1}$ | $\mathrm{Con} + \dfrac{β^{x}}{\ln β}$                        |                                                              |                          |
| $ә^x$                           | $\mathrm{Con} + ә^x$                                         |                                                              |                          |
| $\mathop{x^{α}}\limits_{α≠-1}$  | $\mathrm{Con} + \dfrac{x^{α+1}}{α+1}$                        |                                                              |                          |
| $\dfrac{1}{x}$                  | $\mathrm{Con}+\ln |x|$                                       |                                                              |                          |
| $\ln x$                         | $\mathrm{Con} + x·\ln x - x$                                 |                                                              |                          |
|                                 |                                                              |                                                              |                          |
| $\sin x$                        | $\mathrm{Con} - \cos x$                                      |                                                              |                          |
| $\cos x$                        | $\mathrm{Con} + \sin x$                                      |                                                              |                          |
| $\tan x$                        | $\mathrm{Con} - \ln |\cos x|$                                |                                                              |                          |
| $\tan^{-1} x$                   | $\mathrm{Con} + \ln |\sin x|$                                |                                                              |                          |
| $\cos^{-1} x$                   | $\mathrm{Con} + \ln \left| \tan \left( \dfrac{x}{2} + \dfrac{π}{4} \right) \right|$ |                                                              |                          |
| $\sin^{-1}x$                    | $\mathrm{Con} + \ln\left| \tan \dfrac{x}{2}\right|$          |                                                              |                          |
| $\sin^{-2} x$                   | $\mathrm{Con} - \tan^{-1} x$                                 |                                                              |                          |
| $\cos^{-2} x$                   | $\mathrm{Con} + \tan^{+1} x$                                 |                                                              |                          |
|                                 |                                                              |                                                              |                          |
| $\sinh x$                       | $\mathrm{Con} + \cosh x$                                     |                                                              |                          |
| $\cosh x$                       | $\mathrm{Con} + \sinh x$                                     |                                                              |                          |
| $\tanh x$                       | $\mathrm{Con} + \ln |\cosh x|$                               |                                                              |                          |
| $\tanh^{-1} x$                  | $\mathrm{Con} + \ln | \sinh x|$                              |                                                              |                          |
| $\cosh^{-1} x$                  | $\mathrm{Con} + {'}\tan(\sinh x)$                            |                                                              |                          |
| $\sinh^{-1} x$                  | $\mathrm{Con} + \ln \left(\tanh \dfrac{x}{2} \right)$        |                                                              |                          |
| $\sinh^{-2} x$                  | $\mathrm{Con} - \tanh^{-1} x$                                |                                                              |                          |
| $\cosh^{-2} x$                  | $\mathrm{Con} + \tanh^{+1} x$                                |                                                              |                          |
|                                 |                                                              |                                                              |                          |
| $\dfrac{+1}{1 + x^2}$           | $\mathrm{Con} + {'}\tan^{+1} x$                              | $\mathrm{Con} + \dfrac{τ}{2} · \ln \dfrac{1 - τ · x}{1 + τ · x}$ |                          |
| $\dfrac{-1}{1 + x^2}$           | $\mathrm{Con} + {'}\tan^{-1} x$                              | $\mathrm{Con} + \dfrac{τ}{2} · \ln \dfrac{x - τ}{x + τ}$     |                          |
| $\dfrac{+1}{1 - x^2}$           | $\mathrm{Con} + {'}\tanh^{+1} x$                             | $\mathrm{Con} + \dfrac{1}{2} · \ln \dfrac{1 + x}{1 - x}$     |        $(-1,+1)$         |
| $\dfrac{+1}{1 - x^2}$           | $\mathrm{Con} + {'}\tanh^{-1} x$                             | $\mathrm{Con} + \dfrac{1}{2} · \ln \dfrac{x + 1}{x - 1}$     | $(∞^{-},-1];[+1，∞^{+}]$ |
|                                 |                                                              |                                                              |                          |
| $\dfrac{+1}{\sqrt{1 - x^2}}$    | $\mathrm{Con} + {'}\sin x$                                   | $\mathrm{Con} -τ · \ln\left( τ · x + \sqrt{1 - x^2} \right)$ |                          |
| $\dfrac{-1}{\sqrt{1 - x^2}}$    | $\mathrm{Con} + {'}\cos x$                                   | $\mathrm{Con} -τ · \ln\left( x + \sqrt{x^2 - 1} \right)$     |                          |
| $\dfrac{+1}{\sqrt{x^2 + 1}}$    | $\mathrm{Con} + {'}\sinh x$                                  | $\mathrm{Con} + \ln\left( x + \sqrt{1 + x^2} \right)$        |                          |
| $\dfrac{+1}{\sqrt{x^2 - 1}}$    | $\mathrm{Con} + {'}\cosh x$                                  | $\mathrm{Con} + \ln\left( x + \sqrt{x^2 - 1} \right)$        |                          |
|                                 |                                                              |                                                              |                          |

### 初等幂级数

| $f (x)$                                                      | ${^h}f (x)$                                                  | $\sum\limits_{i=0}^n \dfrac{{^i}f (0)}{i!} · x^i$            | $+ \dfrac{{^{n+1}f (θ)}}{(n + 1)!} · x^{n + 1}$              | $(-R, +R)$                                                   |
| :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $β^x$                                                        | $β^x · \ln^h β$                                              | $\sum\limits_{i=0}^n \dfrac{\ln^i β}{i!} · x^i$              | $+ \dfrac{β^θ · \ln^{n + 1} β}{(n + 1)!} · x^{n + 1}$        | $(∞⁻, ∞⁺)$                                                   |
| $ә^x$                                                        | $ә^x$                                                        | $\sum\limits_{i=0}^n \dfrac{1}{i!} · x^i$                    | $+ \dfrac{ә^θ}{(n + 1)!} · x^{n + 1}$                        | $(∞⁻, ∞⁺)$                                                   |
| $\mathop{\log_β (1 + x)}\limits_{0<β≠1}$                     | $\dfrac{(-1)^{h-1} · (h - 1)!}{(1 + x)^h · \ln β}$           | $\sum\limits_{i=\rlap{≡}{0,}1}^n \dfrac{(-1)^{i - 1}}{i · \ln β} · x^i$ | $+ \dfrac{(-1)^n}{(n + 1) · (1 + θ)^{n + 1} · \ln β} · x^{n + 1}$ | $(-1, +1)$                                                   |
| $\ln (1 + x)$                                                | $\dfrac{(-1)^{h-1} · (h - 1)!}{(1 + x)^h}$                   | $\sum\limits_{i=\rlap{≡}{0,}1}^n \dfrac{(-1)^{i-1}}{i} · x^i$ | $+ \dfrac{(-1)^n}{(n + 1) · (1 + θ)^{n + 1}} · x^{n + 1}$    | $(-1, +1]$                                                   |
| $(1 + x)^{α}$                                                | $\dfrac{(1 + x)^{α}}{(1 + x)^h} · \prod\limits_{j=0}^{h-1} (α - j)$ | $\sum\limits_{i=0}^n \prod\limits_{j=0}^{i-1} \dfrac{α - j}{j + 1} · x^i$ | $+ \dfrac{(1 + θ)^{α}}{(1 + θ)^{n + 1}} · \prod\limits_{j=0}^n \dfrac{α - j}{j + 1} · x^{n + 1}$ | $\mathop{(-1, +1)}\limits_{α≤-1}; \mathop{(-1, +1]}\limits_{-1<α<0}; \mathop{[-1, +1]}\limits_{0<α}$ |
| $(1 + x)^{\frac{1}{2}}$                                      | $\dfrac{(1 + x)^{\frac{1}{2}}}{(1 + x)^h} · \prod\limits_{j=0}^{h-1} \dfrac{1 - 2 · j}{2}$ | $\sum\limits_{i=0}^n \prod\limits_{j=0}^{i-1} \dfrac{1 - 2 · j}{2 · (j + 1)} · x^i$ | $+ \dfrac{(1 + θ)^{\frac{1}{2}}}{(1 + θ)^{n+1}} · \prod\limits_{j=0}^n \dfrac{1 - 2 · j}{2 · (j + 1)} · x^{n + 1}$ | $[-1, +1]$                                                   |
| $(1 + x)^{-\frac{1}{2}}$                                     | $\dfrac{1}{(1 + x)^{\frac{1}{2} + h}} · \prod\limits_{j=0}^{h-1} \dfrac{- 1 - 2 · j}{2}$ | $\sum\limits_{i=0}^n \prod\limits_{j=0}^{i-1} \dfrac{- 1 - 2 · j}{2 · (j + 1)} · x^i$ | $+ \dfrac{1}{(1 + θ)^{\frac{1}{2} + n + 1}} · \prod\limits_{j=0}^n \dfrac{- 1 - 2 · j}{2 · (j + 1)} · x^{n + 1}$ | $(-1, +1]$                                                   |
| $\dfrac{1}{1 + x}$                                           | $\dfrac{(-1)^h · h!}{(1 + x)^{h + 1}}$                       | $\sum\limits_{i=0}^n (-1)^i · x^i$                           | $+ \dfrac{(-1)^{n+1}}{(1 + θ)^{n + 2}} · x^{n + 1}$          | $(-1, +1)$                                                   |
| $\dfrac{1}{1 - x}$                                           | $\dfrac{h!}{(1 - x)^{h + 1}}$                                | $\sum\limits_{i=0}^n x^i$                                    | $+ \dfrac{1}{(1 - θ)^{n + 2}} · x^{n + 1}$                   | $(-1, +1)$                                                   |
|                                                              |                                                              |                                                              |                                                              |                                                              |
| $\sin x = \dfrac{ә^{τ · x} - ә^{-τ · x}}{2 · τ}$             | $τ^h · \dfrac{ә^{τ · x} - (-1)^h · ә^{-τ · x}}{2 · τ} = \sin \left( x + h · \dfrac{π}{2} \right)$ | $\sum\limits_{i=0}^n \dfrac{(-1)^{i}}{(2 · i + 1)!} · x^{2 · i + 1}$ | $+ \dfrac{(-1)^{n + 1} · \sin θ}{(2 · n + 3)!} · x^{2 · n + 3}$ | $(∞⁻, ∞⁺)$                                                   |
| $\cos x = \dfrac{ә^{τ · x} + ә^{-τ · x}}{2}$                 | $τ^h · \dfrac{ә^{τ · x} + (-1)^h · ә^{-τ · x}}{2} = \cos \left( x + h · \dfrac{π}{2} \right)$ | $\sum\limits_{i=0}^n \dfrac{(-1)^i}{(2 · i)!} · x^{2 · i}$   | $+ \dfrac{(-1)^{n + 1} · \cos θ}{(2 · n + 2)!} · x^{2 · n + 2}$ | $(∞⁻, ∞⁺)$                                                   |
|                                                              |                                                              |                                                              |                                                              |                                                              |
| $\sinh x = \dfrac{ә^x - ә^{-x}}{2}$                          | $\dfrac{ә^x - (-1)^h · ә^{-x}}{2}$                           | $\sum\limits_{i=0}^n \dfrac{1}{(2 · i + 1)!} · x^{2 · i + 1}$ | $+ \dfrac{ә^θ + ә^{-θ}}{2 · (2 · n + 3)!} · x^{2 · n + 3}$   | $(∞⁻, ∞⁺)$                                                   |
| $\cosh x = \dfrac{ә^x + ә^{-x}}{2}$                          | $\dfrac{ә^x + (-1)^h · ә^{-x}}{2}$                           | $\sum\limits_{i=0}^n \dfrac{1}{(2 · i)!} · x^{2 · i}$        | $+ \dfrac{ә^θ + ә^{-θ}}{2 · (2 · n + 2)!} · x^{2 · n + 2}$   | $(∞⁻, ∞⁺)$                                                   |
|                                                              |                                                              |                                                              |                                                              |                                                              |
|                                                              |                                                              |                                                              |                                                              |                                                              |
| ${'}\tan x = \int\limits_0^x \dfrac{1}{1 + x^2} \mathrm{d} x$ | $\dfrac{1}{1 + x^2} = \sum\limits_{i=0}^{∞⁺} (-x^2)^i$       | $\sum\limits_{i=0}^{∞⁺} \dfrac{(-1)^i}{2 · i + 1} · x^{2 · i + 1}$ |                                                              | $[-1, +1]$                                                   |

附加证明：$f (x) = \mathop{(1 + x)^α}\limits_{α≠0}$的收敛点集为$\mathop{(-1, +1)}\limits_{α≤-1}; \mathop{(-1, +1]}\limits_{-1<α<0}; \mathop{[-1, +1]}\limits_{0<α}$。

| $⇓$  | $f (x) = \sum\limits_{i=0}^n \prod\limits_{j=0}^{i-1} \dfrac{α - j}{j + 1} · x^i = \sum\limits_{i=0}^n \prod\limits_{j=0}^{i-1} \dfrac{j - α}{j + 1} · (-x)^i$ |      |                                                              |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $R_n (x) = \dfrac{(1 + θ)^α}{(1 + θ)^{n + 1}} · \prod\limits_{j=0}^n \dfrac{α - j}{j + 1} · x^{n + 1} = \dfrac{(1 + θ)^α}{(1 + θ)^{n + 1}} · \prod\limits_{j=0}^n \dfrac{j - α}{j + 1} · (-x)^{n + 1}$ |      |                                                              |
| $⇓$  | $\left[ 0 ≠ 1 \mathop{≤}\limits^{α≤-1} \lim\limits_{i⇝∞⁺} \prod\limits_{j=0}^{i-1} \left| \dfrac{j - α}{j + 1} \right| = \lim\limits_{i⇝∞⁺} | s_{i} (+1) | \right] ∧ \left[ \lim\limits_{n⇝∞⁺} \mathop{| R_n (+1) |}\limits_{1≤1+θ≤2}^{0≤θ≤1} ≤ \lim\limits_{n⇝∞⁺} \dfrac{2^α}{1^{n + 1}} · \prod\limits_{j=0}^n \left| \dfrac{j - α}{j + 1} \right| \mathop{⇝}\limits^{-1 < α} 0 \right]$ | $⇒$  | $\mathop{[+0, +1)}\limits_{α≤-1}; \mathop{[+0, +1]}\limits_{-1<α}$ |
| $⇓$  | $\lim\limits_{i⇝∞⁺} i · \left[ \dfrac{s_i^+ (-1)}{s_{i+1}^+ (-1)} - 1 \right] \mathop{==}\limits^{j≥α} \lim\limits_{i⇝∞⁺} i · \left[ \prod\limits_{j=0}^{i-1} \dfrac{j - α}{j + 1} · \prod\limits_{j=0}^{i} \dfrac{j + 1}{j - α} - 1 \right] = \lim\limits_{i⇝∞⁺} i · \left[ \dfrac{i + 1}{i - α} - 1 \right] = 1 + α$ | $⇒$  | $\mathop{(-1, -0]}\limits_{α<0}; \mathop{[-1, -0]}\limits_{0<α}$ |
| $⇓$  |                                                              |      | $\mathop{(-1, +1)}\limits_{α≤-1}; \mathop{(-1, +1]}\limits_{-1<α<0}; \mathop{[-1, +1]}\limits_{0<α}$ |

### 复数积分

$\int\limits_{0}^{∞⁺} e^{-α · x} · e^{τ · β · x} \mathrm{d} x = \dfrac{α + τ · β}{α^2 + β^2}$

$\int\limits_0^{∞⁺} e^{- α · x} · \cos (β · x) \mathrm{d} x = \dfrac{α}{α^2 + β^2}$

$\int\limits_0^{∞⁺} e^{- α · x} · \sin (β · x) \mathrm{d} x = \dfrac{β}{α^2 + β^2}$

| $⇓$  | $\int\limits_{x_α}^{x_β} e^{-α · x} · e^{τ · β · x} \mathrm{d} x = \left[ \dfrac{e^{-α · x + τ · β · x}}{-α + τ · β} \right]_{x_α}^{x_β} = \left[ \dfrac{e^{-α · x}}{-α + τ · β} · \dfrac{-α - τ · \beta}{-α - τ · \beta} · [\cos (β · x) + τ · \sin (β · x)] \right]_{x_α}^{x_β}$ |      |                                                              |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\int\limits_{x_α}^{x_β} e^{-α · x} · e^{τ · β · x} \mathrm{d} x = \left[ \dfrac{e^{-α · x}}{α^2 + β^2} · [[ -α · \cos (β · x) + β · \sin (β · x) ] + τ · [ -α · \sin (β · x) - β · \cos (β · x) ]] \right]_{x_α}^{x_β}$ | $⇔$  | $\int\limits_{x_α}^{x_β} e^{-α · x} · [ \cos (β · x) + τ · \sin (β · x)] \mathrm{d} x$ |
| $⇓$  | $\int\limits_{x_α}^{x_β} e^{-α · x} · \cos (β · x) \mathrm{d} x = \left[ \dfrac{e^{-α · x}}{α^2 + β^2} · [ -α · \cos (β · x) + β · \sin (β · x)] \right]_{x_α}^{x_β}$ | $⇒$  | $\int\limits_0^{∞⁺} e^{- α · x} · \cos (β · x) \mathrm{d} x = \dfrac{α}{α^2 + β^2}$ |
| $⇓$  | $\int\limits_{x_α}^{x_β} e^{-α · x} · \sin (β · x) \mathrm{d} x = \left[ \dfrac{e^{-α · x}}{α^2 + β^2} · [-α · \sin (β · x) - β · \cos (β · x)] \right]_{x_α}^{x_β}$ | $⇒$  | $\int\limits_0^{∞⁺} e^{- α · x} · \sin (β · x) \mathrm{d} x = \dfrac{β}{α^2 + β^2}$ |
| $⇓$  |                                                              | $⇒$  | $\int\limits_{0}^{∞⁺} e^{-α · x} · e^{τ · β · x} \mathrm{d} x = \dfrac{α + τ · β}{α^2 + β^2}$ |

### 指数积分

$\int\limits_{0}^{∞⁺} e^{-x^2} \mathrm{d} x = \dfrac{\sqrt{π}}{2}$

| $⇓$  | $\int\limits_0^{∞⁺} e^{-x^2} \mathrm{d} x \mathop{===}\limits^{t = x^2} \int\limits_0^{∞⁺} e^{-t} \dfrac{\mathrm{d} t}{2 · \sqrt{t}} = \dfrac{1}{2} · \int\limits_{0}^{∞⁺} t^{\frac{1}{2} - 1} · e^{-t} \mathrm{d} t = \dfrac{1}{2} · Γ \left( \dfrac{1}{2} \right) = \dfrac{\sqrt{π}}{2}$ | $⇐$  | $Γ \left( \dfrac{1}{2} \right) = \sqrt{π}$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------- |
|      |                                                              |      |                                            |

### 三角积分

$\int\limits_{0}^{\frac{π}{2}} \cos^n x \mathrm{d}x = \left[ \dfrac{π}{2} \right]^{\frac{1 + (-1)^n}{2}} · \left[ \prod\limits_{i=1}^n i^{(-1)^i} \right]^{(-1)^{n+1}}$

$\int\limits_{0}^{\frac{π}{2}} \sin^n x \mathrm{d} x = \int\limits_{0}^{\frac{π}{2}} \cos^n x \mathrm{d} x$

$\int\limits_{-π}^{+π} \dfrac{1 - r^2}{1 - 2 · r · \cos x + r^2} \mathrm{d} x = 2 · π$

| $⇓$  | $\int\limits_{0}^{\frac{π}{2}} f (\sin x) \mathrm{d} x \mathop{====}\limits^{x=\frac{π}{2}-t} -\int\limits_{\frac{π}{2}}^{0} f (\cos t) \mathrm{d} t = \int\limits_{0}^{\frac{π}{2}} f (\cos t) \mathrm{d} t$ | $⇒$  | $\int\limits_{0}^{\frac{π}{2}} \sin^n x \mathrm{d} x = \int\limits_{0}^{\frac{π}{2}} \cos^n x \mathrm{d} x$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $I_n = \int\limits_{0}^{\frac{π}{2}} \cos^n \mathrm{d} x = \int\limits_{0}^{\frac{π}{2}} \cos^{n-1} x \mathrm{d} \sin x = \left[ \cos^{n - 1} x · \sin x \right]_{0}^{\frac{π}{2}} + (n - 1) · \int\limits_{0}^{\frac{π}{2}} \cos^{n-2} x · \sin^2 x \mathrm{d} x$ |      |                                                              |
| $⇓$  | $I_n = (n - 1) · \int\limits_{0}^{\frac{π}{2}} \cos^{n-2} x · [ 1 - \cos^2 x] \mathrm{d} x = (n - 1) · [ I_{n-2} - I_n ]$ |      |                                                              |
| $⇓$  | $I_n = \dfrac{n - 1}{n} · I_{n-2}$                           |      |                                                              |
| $⇓$  | $I_{2·m} = \dfrac{π}{2} · \dfrac{1}{2} · \dfrac{3}{4} ··· \dfrac{2 · m - 3}{2 · m - 2} · \dfrac{2 · m - 1}{2 · m} = \dfrac{π}{2} · \left[ \prod\limits_{i=1}^{m} (2·i-1) \right]^{+1}  · \left[ \prod\limits_{i=1}^{m}(2·i) \right]^{-1}$ | $⇐$  | $I_0 = \int\limits_{0}^{\frac{π}{2}} \cos^0 x \mathrm{d} x = \dfrac{π}{2}$ |
| $⇓$  | $I_{2·m+1} = 1 · \dfrac{2}{3} · \dfrac{4}{5} ··· \dfrac{2 · m - 2}{2 · m - 1} · \dfrac{2 · m}{2 · m + 1} = \left[ \prod\limits_{i=1}^{m}(2·i) \right]^{+1} · \left[ \prod\limits_{i=1}^{m}(2·i+1) \right]^{-1}$ | $⇐$  | $I_1 = \int\limits_{0}^{\frac{π}{2}} \cos^1 x \mathrm{d} x = [ \sin x ]_{0}^{\frac{π}{2}} = 1$ |
| $⇓$  | $I_n = \left[ \dfrac{π}{2} \right]^{\frac{1 + (-1)^n}{2}} · \left[ \prod\limits_{i=1}^n i^{(-1)^i} \right]^{(-1)^{n+1}}$ |      |                                                              |
|      |                                                              |      |                                                              |
| $⇓$  | $\int\limits_{0}^{\frac{π}{2}} \cos^{2·m+1} x · \mathrm{d} x < \int\limits_{0}^{\frac{π}{2}} \cos^{2·m} x · \mathrm{d}x < \int\limits_{0}^{\frac{π}{2}} \cos^{2·m-1} x · \mathrm{d} x$ |      |                                                              |
| $⇓$  | $I_{2·m+1} < I_{2·m} < I_{2·m-1}$                            |      | $I_{2·m-1} = \left[ \prod\limits_{i=1}^{m-1}(2·i) \right]^{+1} · \left[ \prod\limits_{i=1}^{m-1}(2·i+1) \right]^{-1}$ |
| $⇓$  | $\left[ \prod\limits_{i=1}^{m}(2·i) \right]^{+1} · \left[ \prod\limits_{i=1}^{m}(2·i+1) \right]^{-1} < \dfrac{π}{2} · \left[ \prod\limits_{i=1}^{m} (2·i-1) \right]^{+1}  · \left[ \prod\limits_{i=1}^{m}(2·i) \right]^{-1} < \left[ \prod\limits_{i=1}^{m-1}(2·i) \right]^{+1} · \left[ \prod\limits_{i=1}^{m-1}(2·i+1) \right]^{-1}$ |      |                                                              |
| $⇓$  | $J_{m} = \dfrac{1}{2·m+1} · \left[ \prod\limits_{i=1}^{m} (2·i) \right]^{+2} · \left[ \prod\limits_{i=1}^{m} (2·i-1) \right]^{-2} < \dfrac{π}{2} < \dfrac{1}{2·m} · \left[ \prod\limits_{i=1}^{m} (2·i) \right]^{+2} · \left[ \prod\limits_{i=1}^{m} (2·i-1) \right]^{-2} = K_{m}$ |      |                                                              |
| $⇓$  | $K_{m} - J_{m} = \dfrac{1}{(2·m)·(2·m+1)} · \left[ \prod\limits_{i=1}^{m} (2·i) \right]^{+2} · \left[ \prod\limits_{i=1}^{m} (2·i-1) \right]^{-2} < \dfrac{1}{2·m} · \dfrac{π}{2} \mathop{⇝}\limits_{m⇝∞^{+}} 0$ |      |                                                              |
| $⇓$  | $π = \lim\limits_{m⇝∞^{+}} (2 · K_{m}) = \lim\limits_{m⇝∞^{+}} \dfrac{1}{m} · \left[ \prod\limits_{i=1}^{m} (2·i) \right]^{+2} · \left[ \prod\limits_{i=1}^{m} (2·i-1) \right]^{-2}$ |      |                                                              |

| $⇓$  | $\int\limits \dfrac{1 - r^2}{1 - 2 · r · \cos x + r^2} \mathrm{d} x \mathop{=======}\limits_{\cos x = \frac{1 - \tan^2 \frac{x}{2}}{1 + \tan^2 \frac{x}{2}}}^{t = \tan \frac{x}{2}} \int\limits \dfrac{1 - r^2}{1 - 2 · r · \dfrac{1 - t^2}{1 + t^2} + r^2} \dfrac{2 · \mathrm{d} t}{1 + t^2} = \int\limits \dfrac{2 · (1 - r^2)}{(1 - r)^2 + (1 + r)^2 · t^2} \mathrm{d} t = 2 · \tan^{-1} \left( \dfrac{1 + r}{1 - r} · t \right) = 2 · \tan^{-1} \left( \dfrac{1 + r}{1 - r} · \tan \dfrac{x}{2} \right)$ |
| :--: | ------------------------------------------------------------ |
| $⇓$  | $\int\limits_{-π}^{+π} \dfrac{1 - r^2}{1 - 2 · r · \cos x + r^2} \mathrm{d} x = \left[ 2 · \tan^{-1} \left( \dfrac{1 + r}{1 - r} · \tan \dfrac{x}{2} \right) \right]_{-π}^{+π} = 2 · π$ |

### 调和积分

$\int\limits_{0}^{1} \dfrac{1}{x^a} · \mathrm{d} x = \mathop{\dfrac{1}{1 - a}}\limits_{0<a<1}; \mathop{∞⁺}\limits_{1≤a<∞⁺}$

$\int\limits_{1}^{∞⁺} \dfrac{1}{x^a} · \mathrm{d} x = \mathop{∞⁺}\limits_{0<a≤1}; \mathop{\dfrac{1}{a - 1}}\limits_{1<a<∞⁺}$

$\int\limits_{1}^{ә} \dfrac{1}{x · \ln^b x} · \mathrm{d} x = \mathop{\dfrac{1}{1 - b}}\limits_{0<b<1}; \mathop{∞⁺}\limits_{1≤b<∞⁺}$

$\int\limits_{ә}^{∞⁺} \dfrac{1}{x · \ln^b x} · \mathrm{d} x = \mathop{∞⁺}\limits_{0<b≤1}; \mathop{\dfrac{1}{b - 1}}\limits_{1<b<∞⁺}$

| $⇓$  | $\int\limits_{x_α}^{x_β} \dfrac{1}{x^a} · \mathrm{d}x \mathop{==}\limits^{a≠1} \left. \dfrac{x^{1-a}}{1-a} \right|_{x_α}^{x_β} = \dfrac{x_β^{1-a} - x_α^{1-a}}{1-a}$ | $\int\limits_{x_α}^{x_β} \dfrac{1}{x^1} \mathrm{d} x \mathop{==}\limits^{a=1} \ln x|_{x_α}^{x_β} = \ln \dfrac{x_β}{x_α}$ |      |                                                              |
| :--: | :----------------------------------------------------------- | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\int\limits_{0}^{1} \dfrac{1}{x^a} · \mathrm{d}x \mathop{==}\limits^{a≠1} \mathop{\dfrac{1}{1-a}}\limits_{0<a<1};\mathop{∞^{+}}\limits_{1<a<∞^{+}}$ | $\int\limits_{0}^{1} \dfrac{1}{x^{1}} · \mathrm{d}x \mathop{==}\limits^{a=1} ∞^{+}$ | $⇒$  | $\int\limits_{0}^{1} \dfrac{1}{x^a} · \mathrm{d} x = \mathop{\dfrac{1}{1 - a}}\limits_{0<a<1}; \mathop{∞⁺}\limits_{1≤a<∞⁺}$ |
| $⇓$  | $\int\limits_{1}^{∞^{+}} \dfrac{1}{x^{a}} · \mathrm{d}x \mathop{==}\limits^{a≠1} \mathop{∞^{+}}\limits_{0<a<1};\mathop{\dfrac{1}{a - 1}}\limits_{1<a<∞^{+}}$ | $\int\limits_{1}^{∞⁺} \dfrac{1}{x^1} · \mathrm{d} x \mathop{==}\limits^{a=1} ∞⁺$ | $⇒$  | $\int\limits_{1}^{∞⁺} \dfrac{1}{x^a} · \mathrm{d} x = \mathop{∞⁺}\limits_{0<α≤1}; \mathop{\dfrac{1}{a - 1}}\limits_{1<a<∞⁺}$ |
|      |                                                              |                                                              | $⇒$  | $\int\limits_{0}^{∞⁺} \dfrac{1}{x^a} · \mathrm{d} x = ∞⁺$    |
|      |                                                              |                                                              |      |                                                              |
| $⇓$  | $\int\limits_{x_α}^{x_β} \dfrac{1}{x·\ln^{b}x} · \mathrm{d}x \mathop{===}\limits^{t=\ln x} \int\limits_{\ln x_α}^{\ln x_β} \dfrac{1}{t^{b}} · \mathrm{d}t \mathop{==}\limits^{b≠1} \left[ \dfrac{t^{1-b}}{1-b} \right]_{\ln x_α}^{\ln x_β} = \dfrac{\ln^{1-b} x_β - \ln^{1-b} x_α}{1 - b}$ |                                                              | $⇒$  | $\int\limits_{1}^{ә} \dfrac{1}{x · \ln^b x} · \mathrm{d} x = \mathop{\dfrac{1}{1 - b}}\limits_{0<b<1}; \mathop{∞⁺}\limits_{1≤b<∞⁺}$ |
| $⇓$  | $\int\limits_{x_α}^{x_β} \dfrac{1}{x·\ln^{1} x} · \mathrm{d}x \mathop{===}\limits^{t=\ln x} \int\limits_{\ln x_α}^{\ln x_β} \dfrac{1}{t^1} · \mathrm{d}t \mathop{==}\limits^{b=1} [\ln t]_{\ln x_α}^{\ln x_β} = \ln \dfrac{\ln x_β}{\ln x_α}$ |                                                              | $⇒$  | $\int\limits_{ә}^{∞⁺} \dfrac{1}{x · \ln^b x} · \mathrm{d} x = \mathop{∞⁺}\limits_{0<b≤1}; \mathop{\dfrac{1}{b - 1}}\limits_{1<b<∞⁺}$ |
| $⇓$  |                                                              |                                                              | $⇒$  | $\int\limits_{1}^{∞⁺} \dfrac{1}{x · \ln^b x} · \mathrm{d} x = ∞⁺$ |

