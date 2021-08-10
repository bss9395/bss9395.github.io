---
layout:  zh_post
Topic :  收敛极限
Title :  广义积分
Update:  2021-08-09T10:52:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 广义积分

若函数$f(x)$在区间$[x_l,x_u]$上的定积分存在，但其积分界限端点$x_u$趋于无穷大，则称$\int\limits_{x_l}^{∞^{+}} f(x) · \mathrm{d} x ≡ \lim\limits_{x_u⇝∞^{+}} \int\limits_{x_l}^{x_u} f(x) · \mathrm{d}x$为无穷限积分。

$\int\limits_{-∞}^{+∞} f(x) · \mathrm{d}x = \lim\limits_{x_l⇝∞^{-}} \int\limits_{x_l}^{x_θ} f(x) · \mathrm{d}x + \lim\limits_{x_u⇝∞^{+}} \int\limits_{x_θ}^{x_u} f(x) · \mathrm{d}x = \lim\limits_{x_l⇝∞^{-}} \left[ F(x_θ) - F(x_l) \right] + \lim\limits_{x_u⇝∞^{+}} [F(x_u) - F(x_θ)] = [F(x_θ) - F(∞^{-})] + [F(∞^{+}) - F(x_θ)]$

若函数$f(x)$在区间$[x_l,x_u]$上的定积分存在，但其函数值在端点$x_l$处趋于无穷大，则称$\int\limits_{x_l}^{x_u} f(x) · \mathrm{d} x ≡ \lim\limits_{x_t⇝x_l} \int\limits_{x_t}^{x_u} f(x)· \mathrm{d}x$为无穷界积分。

$\int\limits_{x_l}^{x_u} f(x) · \mathrm{d} x = \lim\limits_{x_t⇝x_l^{+}} \int\limits_{x_t}^{x_θ} f(x) · \mathrm{d}x + \lim\limits_{x_t⇝x_u^-} \int\limits_{x_θ}^{x_t} f(x) · \mathrm{d} x = \lim\limits_{x_t⇝x_l^+} [F(x_θ) - F(x_t)] + \lim\limits_{x_t⇝x_u^-} [F(x_t) - F(x_θ)] = [F(x_θ) - F(x_l^+)] + [F(x_u^-) - F(x_θ)]$

与常义积分相对应，无穷限积分与无穷界积分统称为广义积分。若函数$f(x)$的广义积分存在，则同样也适用于微积分基本定理。

任意常义积分均可通过换元法变换成无穷限积分。

$\int\limits_{x_α}^{x_β} f(x) · \mathrm{d} x \mathop{====}\limits^{t=\frac{1}{x-x_α}} \int\limits_{\frac{1}{x_β-x_α}}^{∞^{+}} f \left( x_α + \dfrac{1}{t} \right) · \dfrac{1}{t^2} · \mathrm{d} t$

$\int\limits_{x_α}^{x_β} f(x) · \mathrm{d} x \mathop{====}\limits^{t=\frac{x_β-x_α}{x-x_α}} \int\limits_{1}^{∞^{+}} f \left( x_α+\dfrac{x_β-x_α}{t} \right) · \dfrac{1}{t^2} · \mathrm{d} t$

### 无穷限积分

无穷限积分收敛的柯西审敛法。

$\left[ \int\limits_{x_α}^{∞^{+}} f(x) · \mathrm{d}x = I_{f} \right] ⇔ \left[ ∀ε>0;∃x_N;∀x_l,x_u≥x_N; \left| \int\limits_{x_α}^{x_u} f(x) · \mathrm{d} x - \int\limits_{x_α}^{x_l} f(x) · \mathrm{d} x \right| = \left| \int\limits_{x_l}^{x_u} f(x) · \mathrm{d} x \right| ≤ ε \right]$

若无穷限积分绝对收敛，则必条件收敛，反之不对。

$\left[ \int\limits_{x_{α}}^{∞^{+}} |f(x)| · \mathrm{d} x = I_{|f|} \right] ⇒ \left[ \int\limits_{x_α}^{∞^{+}} f(x) · \mathrm{d} x = I_{f} \right]$

| $⇓$  | $\left| \int\limits_{x_α}^{∞^{+}} f(x) · \mathrm{d}x \right| ≤ \int\limits_{x_α}^{∞^{+}} |f(x)| · \mathrm{d} x$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε>0;∃x_N;∀x_u,x_v≥x_N; \left| \int\limits_{x_v}^{x_u} f(x) · \mathrm{d} x \right| ≤ \int\limits_{x_v}^{x_u} |f(x)| · \mathrm{d} x ≤ ε$ |
| $⇓$  | $\left[ \int\limits_{x_{α}}^{∞^{+}} |f(x)| · \mathrm{d} x = I_{|f|} \right] ⇒ \left[ \int\limits_{x_α}^{∞^{+}} f(x) · \mathrm{d} x = I_{f} \right]$ |

无穷限积分的比较审敛法。

| $⇓$ | $∀ε>0;∃x_N;∀x>x_N;|f(x)| ≤ g(x)$ |
| :--: | :--- |
| $⇓$ | $\left[ \int\limits_{x_α}^{∞^{+}} f(x) · \mathrm{d}x = I_{f} \right] ⇐ \left[ \int\limits_{x_α}^{∞^{+}} |f(x)| · \mathrm{d}x = I_{|f|} \right] ⇐ \left[ \int\limits_{x_α}^{∞^{+}} g(x) · \mathrm{d} x = I_{g} \right]$ |
| $⇓$ | $\left[ \int\limits_{x_α}^{∞^{+}} f(x) · \mathrm{d}x \not= I_{f} \right] ⇒ \left[ \int\limits_{x_α}^{∞^{+}} |f(x)| · \mathrm{d}x \not= I_{|f|} \right] ⇒ \left[ \int\limits_{x_α}^{∞^{+}} g(x) · \mathrm{d} x \not= I_{g} \right]$ |

无穷限积分的比较审敛法极限形式。

| $⇓$  |                                                              |      | $\lim\limits_{x⇝∞^{+}} \dfrac{|f(x)|}{g(x)} ⇝ q$       |
| :--: | ------------------------------------------------------------ | :--: | :----------------------------------------------------- |
| $⇓$  | $\left[ \int\limits_{x_α}^{∞^{+}} |f(x)| · \mathrm{d}x = I_{|f|} \right] \mathop{⇔}\limits^{q≠0} \left[ \int\limits_{x_α}^{∞^{+}} g(x) · \mathrm{d}x = I_{g} \right]$ | $⇐$  | $∀ε>0;∃x_N;∀x>x_N; (q-ε)·g(x) ≤ |f(x)| ≤ (q+ε) · g(x)$ |
| $⇓$  | $\left[ \int\limits_{x_α}^{∞^{+}} |f(x)| · \mathrm{d}x = I_{|f|} \right] \mathop{⇔}\limits^{q=0^+} \left[ \int\limits_{x_α}^{∞^{+}} g(x) · \mathrm{d}x = I_{g} \right]$ | $⇐$  | $∀ε>0;∃x_N;∀x>x_N; |f(x)| ≤ g(x)$                      |
| $⇓$  | $\left[ \int\limits_{x_α}^{∞^{+}} |f(x)| · \mathrm{d}x = I_{|f|} \right] \mathop{⇔}\limits^{q=∞^+} \left[ \int\limits_{x_α}^{∞^{+}} g(x) · \mathrm{d}x = I_{g} \right]$ | $⇐$  | $∀ε>0;∃x_N;∀x>x_N; g(x) ≤ |f(x)|$                      |

无穷限积分的比值审敛法。

|                                                              |      | $\int\limits_{1}^{∞^{+}} \dfrac{1}{x^{a}} · \mathrm{d} x = \mathop{∞^{+}}\limits_{0<a≤1};\mathop{\dfrac{1}{a-1}}\limits_{1<a<∞^{+}}$ |
| -----------------------------------------------------------: | :--: | ------------------------------------------------------------ |
| $\left[ 1 < a \right] ∧ \left[ |f(x)| ≤ \dfrac{1}{x^a} \right]$ | $⇒$  | $\int\limits_{x_α}^{∞^{+}} |f(x)| · \mathrm{d} x = I_{|f|}$  |
|           $[a ≤ 1] ∧ \left[ |f(x)| ≥ \dfrac{1}{x^a} \right]$ | $⇒$  | $\int\limits_{x_α}^{∞^{+}} |f(x)| · \mathrm{d} x = ∞^{+}$    |

无穷限积分的比值审敛法极限形式。

| $\left[ \lim\limits_{x⇝∞^+} \dfrac{|f(x)|}{\dfrac{1}{x^a}} ⇝ q > 0 \right] ⇒ \left[ \lim\limits_{x⇝∞^{+}} |f(x)| = \lim\limits_{x⇝∞^{+}} \dfrac{q}{x^a} \right]$ |      | $\int\limits_{1}^{∞} \dfrac{1}{x^{a}} · \mathrm{d} x = \mathop{∞^{+}}\limits_{0<a≤1};\mathop{\dfrac{1}{a-1}}\limits_{1<a<∞^{+}}$ |
| -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
|                                      $[1 < a] ∧ [0≤q<∞^{+}]$ | $⇒$  | $\int\limits_{x_α}^{∞^{+}} |f(x)| · \mathrm{d} x = I_{|f|}$  |
|                                        $[a≤1] ∧ [0<q≤∞^{+}]$ | $⇒$  | $\int\limits_{x_α}^{∞^{+}} |f(x)| · \mathrm{d} x = ∞^{+}$    |

典例：无穷限积分$\int\limits_{1}^{∞^+} x^{a} · ә^{-x} · \mathrm{d}x$收敛，其中$a=2$以及$q = 0$。

$\lim\limits_{x⇝∞^{+}} \dfrac{x^a · ә^{-x}}{\dfrac{1}{x^2}} = \lim\limits_{x⇝∞^{+}} \dfrac{x^{a+2}}{ә^x} ⇝ 0$

无穷限积分的分部审敛法。

若函数$g(x)$与函数$f(x)$均连续，且$|g^{⤨}(x)|≤ \mathrm{Sup}$，以及$\int\limits_{x_α}^{∞^{+}} f(x) · \mathrm{d}x = I_{f}$，则无穷限积分$\int\limits_{x_α}^{∞^+} g(x) · f(x) · \mathrm{d}x = I_{gf}$收敛。

若函数$g(x)$与函数$f(x)$均连续，且$\lim\limits_{x⇝∞} g^{⤨}(x) ⇝ 0$，以及$\left| \int\limits_{x_α}^{x} f(x) · \mathrm{d} x \right| ≤ \mathrm{Sup}$，则无穷限积分$\int\limits_{x_α}^{∞^+} g(x) · f(x) · \mathrm{d}x = I_{gf}$收敛。

|      | $∀ε>0;∃x_N;∀x_l,x_u≥x_N;$                                    |      |                                                              |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\left| \int\limits_{x_l}^{x_u} f (x) · g^{⤨} (x) \mathrm{d} x \right| = \left| g^{⤨} (x_l) · \int\limits_{x_l}^{θ} f (x) \mathrm{d} x + g^{⤨} (x_u) · \int\limits_{θ}^{x_u} f (x) \mathrm{d} x \right| ≤ \left| g^{⤨}(x_l) \right| · \left| \int\limits_{x_l}^{θ} f(x) · \mathrm{d}x \right| + \left| g^{⤨}(x_u) \right| · \left| \int\limits_{θ}^{x_u} f(x) · \mathrm{d}x \right| $ |      |                                                              |
| $⇓$  | $\left| \int\limits_{x_l}^{x_u} f (x) · g^{⤨} (x) \mathrm{d} x \right| ≤ \mathrm{Sup} · ε_1 + \mathrm{Sup} · ε_2 = ε$ | $⇐$  | $|g^{⤨}(x) ≤ \mathrm{Sup}| ∧ \left[ \int\limits_{x_α}^{∞^{+}} f(x) · \mathrm{d}x = I_{f} \right]$ |
|      |                                                              |      |                                                              |
| $⇓$  | $\left| \int\limits_{x_l}^{x_u} f (x) · g^{⤨} (x) \mathrm{d} x \right| = \left| g^{⤨}(x_l) \right| · \left| \int\limits_{x_α}^{θ} f(x) · \mathrm{d}x - \int\limits_{x_α}^{x_l} f(x)·\mathrm{d}x \right| + |g^{⤨}(x_u)| · \left| \int\limits_{x_α}^{x_u} f(x) · \mathrm{d}x - \int\limits_{x_α}^{θ} f(x) · \mathrm{d}x \right|$ |      |                                                              |
| $⇓$  | $\left| \int\limits_{x_l}^{x_u} f (x) · g^{⤨} (x) \mathrm{d} x \right| ≤ ε_1·2·\mathrm{Sup} + ε_2·2·\mathrm{Sup} = ε$ | $⇐$  | $\left[ \lim\limits_{x⇝∞} g^{⤨}(x) ⇝ 0 \right] ∧ \left[ \left| \int\limits_{x_α}^{x} f(x) · \mathrm{d} x \right| ≤ \mathrm{Sup} \right]$ |

典例：根据分部审敛法，考察无穷限积分$\int\limits_{1}^{∞^{+}} \dfrac{\sin x}{x^{a}} · \mathrm{d} x$的敛散性。

| $a>1$   | $\left| \dfrac{\sin x}{x^a} \right| ≤ \dfrac{1}{x^a}$        | $⇒$  | $\int\limits_{1}^{∞^{+}} \dfrac{\sin x}{x^a} · \mathrm{d} x ⇝ I$ |
| :------ | ------------------------------------------------------------ | :--: | :----------------------------------------------------------- |
| $0<a≤1$ | $\left[ \lim\limits_{x⇝∞^{+}} \dfrac{1}{x^{a}} ⇝ 0 \right] ∧ \left[ \left| \int\limits_{1}^{x} \sin x · \mathrm{d} x \right| = | -\cos x + \cos 1 | ≤ 2 \right]$ | $⇒$  | $\int\limits_{1}^{∞^{+}} \dfrac{\sin x}{x^a} · \mathrm{d} x ⇝ I$ |
| $0<a≤1$ | $\left[ \left| \dfrac{\sin x}{x^a} \right| ≥ \dfrac{\sin^2 x}{x} = \dfrac{1 - \cos 2 · x}{2·x} = \dfrac{1}{2·x} - \dfrac{\cos 2 · x}{2·x} \right] ∧ \left[ \int\limits_{1}^{∞^{+}} \dfrac{1}{x} · \mathrm{d} x = \ln x |_{1}^{∞^{+}} = ∞^{+} \right]$ | $⇒$  | $\int\limits_{1}^{∞^{+}} \left| \dfrac{\sin x}{x^a} \right| · \mathrm{d} x \not⇝ I$ |
| $a≤0$   | $\left| \int\limits_{2·n·π}^{2·n·π+π} \dfrac{\sin x}{x^a} · \mathrm{d}x \right| ≥ \left| \int\limits_{2·n·π}^{2·n·π+π} \sin x · \mathrm{d}x \right| = \left| \int\limits_{0}^{π} \sin x · \mathrm{d}x \right| = 2 > ε$ | $⇒$  | $\int\limits_{1}^{∞^{+}} \dfrac{\sin x}{x^a} · \mathrm{d} x \not⇝ I$ |

若无穷限积分$\int\limits_{x_α}^{∞^{+}} f(x) · \mathrm{d}x ⇝ I$，且$f(x) ≥ 0$，但未必有$\lim\limits_{x⇝∞^{+}} f(x) ⇝ 0$。

反例：脉冲函数$\mathcal{P}(x) = \mathop{0}\limits_{};\mathop{+n^2·2^{n} · \left[ x - \left( n-\dfrac{1}{2^n · n} \right) \right]}\limits_{x∈\left[n-\frac{1}{2^{n}·n},n\right]};\mathop{-n^2·2^{n} · \left[ x - \left( n+\dfrac{1}{2^{n}·n} \right) \right]}\limits_{x∈\left[n,n+\frac{1}{2^{n}·n}\right]};0$

脉冲函数$\mathcal{P}(x)$的无穷限积分$\int\limits_{0}^{∞^{+}} \mathcal{P}(x) · \mathrm{d}x = \sum\limits_{i=1}^{∞} \dfrac{1}{2^i} = 1$收敛，且$\mathcal{P}(x) ≥ 0$，但$\lim\limits_{x⇝∞^{+}} \mathcal{P}(x) \not⇝ 0$。

### 无穷界积分

无穷界积分的柯西审敛法。

$\left[ \int\limits_{\phi}^{x_β} f(x) · \mathrm{d}x ⇝ I_{f} \right] ⇔ \left[ ∀ε>0;∃δ>0;∀x_l,x_u∈\mathrm{B}(\phi,δ); \left| \int\limits_{x_α}^{x_u} f(x) · \mathrm{d} x - \int\limits_{x_α}^{x_l} f(x) · \mathrm{d} x  \right| = \left| \int\limits_{x_l}^{x_u} f(x) · \mathrm{d} x \right| < ε \right]$

若无穷界积分绝对收敛，则必条件收敛，反之不对。

$\left[ \int\limits_{\phi}^{x_β} |f(x)| · \mathrm{d} x = I_{|f|} \right] ⇒ \left[ \int\limits_{\phi}^{x_β} f(x) · \mathrm{d} x = I_{f} \right]$

| $⇓$  | $\left| \int\limits_{\phi}^{x_β} f(x) · \mathrm{d}x \right| ≤ \int\limits_{\phi}^{x_β} |f(x)| · \mathrm{d} x$ |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $∀ε>0;∃δ>0;∀x_l,x_u∈\mathrm{B}(\phi,δ); \left| \int\limits_{x_l}^{x_u} f(x) · \mathrm{d} x \right| ≤ \int\limits_{x_l}^{x_u} |f(x)| · \mathrm{d} x ≤ ε$ |
| $⇓$  | $\left[ \int\limits_{\phi}^{x_β} |f(x)| · \mathrm{d} x = I_{|f|} \right] ⇒ \left[ \int\limits_{\phi}^{x_β} f(x) · \mathrm{d} x = I_{f} \right]$ |

无穷界积分的比较审敛法。

| $⇓$  | $∀ε>0;∃δ>0;∀x∈\mathrm{B}(\phi,δ);|f(x)| ≤ g(x)$              |
| :--: | :----------------------------------------------------------- |
| $⇓$  | $\left[ \int\limits_{\phi}^{x_β} f(x) · \mathrm{d}x = I_{f} \right] ⇐ \left[ \int\limits_{\phi}^{x_β} |f(x)| · \mathrm{d}x = I_{|f|} \right] ⇐ \left[ \int\limits_{\phi}^{x_β} g(x) · \mathrm{d} x = I_{g} \right]$ |
| $⇓$  | $\left[ \int\limits_{\phi}^{x_β} f(x) · \mathrm{d}x \not= I_{f} \right] ⇒ \left[ \int\limits_{\phi}^{x_β} |f(x)| · \mathrm{d}x \not= I_{|f|} \right] ⇒ \left[ \int\limits_{\phi}^{x_β} g(x) · \mathrm{d} x \not= I_{g} \right]$ |

无穷界积分的比较审敛法极限形式。

| $⇓$  |                                                              |      | $\lim\limits_{x⇝∞^{+}} \dfrac{|f(x)|}{g(x)} ⇝ q$             |
| :--: | ------------------------------------------------------------ | :--: | :----------------------------------------------------------- |
| $⇓$  | $\left[ \int\limits_{\phi}^{x_β} |f(x)| · \mathrm{d}x = I_{|f|} \right] \mathop{⇔}\limits^{q≠0} \left[ \int\limits_{\phi}^{x_β} g(x) · \mathrm{d}x = I_{g} \right]$ | $⇐$  | $∀ε>0;∃δ>0;∀x∈\mathrm{B}(\phi,δ); (q-ε)·g(x) ≤ |f(x)| ≤ (q+ε) · g(x)$ |
| $⇓$  | $\left[ \int\limits_{\phi}^{x_β} |f(x)| · \mathrm{d} x = I_{|f|} \right] \mathop{⇐}\limits^{q=0^+} \left[ \int\limits_{\phi}^{x_β} g(x) · \mathrm{d}x = I_g \right]$ | $⇐$  | $∀ε>0;∃δ>0;∀x∈\mathrm{B}(\phi,δ); |f(x)| ≤ g(x)$             |
| $⇓$  | $\left[ \int\limits_{\phi}^{x_β} |f(x)| · \mathrm{d}x \not= I_{|f|} \right] \mathop{⇐}\limits^{q=∞^{+}} \left[ \int\limits_{\phi}^{x_β} g(x) · \mathrm{d} x \not= I_{g} \right]$ | $⇐$  | $∀ε>0;∃δ>0;∀x∈\mathrm{B}(\phi,δ); g(x) ≤ |f(x)|$             |

无穷界积分的比值审敛法。

|                                                              |      | $\int\limits_{0}^{1} \dfrac{1}{x^a} · \mathrm{d} x = \mathop{\dfrac{1}{1 - a}}\limits_{0<a<1}; \mathop{∞⁺}\limits_{1≤a<∞⁺}$ |
| -----------------------------------------------------------: | :--: | ------------------------------------------------------------ |
| $\left[ a < 1 \right] ∧ \left[ |f(x)| ≤ \dfrac{1}{(x - \phi)^a} \right]$ | $⇒$  | $\int\limits_{\phi}^{x_β} |f(x)| · \mathrm{d} x = I_{|f|}$   |
|  $[1 ≤ a] ∧ \left[ |f(x)| ≥ \dfrac{1}{(x - \phi)^a} \right]$ | $⇒$  | $\int\limits_{\phi}^{x_β} |f(x)| · \mathrm{d} x = ∞^{+}$     |

无穷界积分的比值审敛法极限形式。

| $\left[ \lim\limits_{x⇝\phi^{+}} \dfrac{|f(x)|}{\dfrac{1}{(x-\phi)^a}} ⇝ q > 0 \right] ⇒ \left[ \lim\limits_{x⇝\phi^{+}} |f(x)| = \lim\limits_{x⇝\phi^{+}} \dfrac{q}{(x - \phi)^{a}} \right]$ |      | $\int\limits_{0}^{1} \dfrac{1}{x^a} · \mathrm{d} x = \mathop{\dfrac{1}{1 - a}}\limits_{0<a<1};\mathop{∞^{+}}\limits_{1≤a<∞^{+}}$ |
| -----------------------------------------------------------: | :--: | :----------------------------------------------------------- |
|                                      $[a < 1] ∧ [0≤q<∞^{+}]$ | $⇒$  | $\int\limits_{x_α}^{∞^{+}} |f(x)| · \mathrm{d} x = I_{|f|}$  |
|                                      $[1 ≤ a] ∧ [0<q≤∞^{+}]$ | $⇒$  | $\int\limits_{x_α}^{∞^{+}} |f(x)| · \mathrm{d} x = ∞^{+}$    |

典例：考察广义积分$\int\limits_{0}^{∞^+} \dfrac{\ln(1+x)}{x^p} · \mathrm{d} x = \int\limits_{0}^{1} \dfrac{\ln (1 + x)}{x^p} · \mathrm{d}x + \int\limits_{1}^{∞^{+}} \dfrac{\ln(1+x)}{x^p} · \mathrm{d} x$的敛散性，其在点$0^{+}$处为无穷界积分，在点$∞^{+}$为无穷限积分。

广义积分$\int\limits_{0}^{∞^+} \dfrac{\ln(1+x)}{x^p} · \mathrm{d} x$，在$1<p<2$时收敛，否则发散。

| $\lim\limits_{x⇝0^{+}} f(x) = \lim\limits_{x⇝0^{+}} \dfrac{\ln (1 + x)}{x^p} = \lim\limits_{x⇝0^{+}} \dfrac{1}{(1+x)·p·x^{p-1}} = \lim\limits_{x⇝0^{+}} \dfrac{1}{p·x^{p-1}} ≤ \rlap{≡≡≡≡≡≡}\left[ \lim\limits_{x⇝0^+} \dfrac{q}{x^a} \right]$ | $[p-1<1] ⇒ [p<2]$ | $⇒$  | $\int\limits_{0}^{1} f(x) · \mathrm{d} x = I_0^+$       |
| :----------------------------------------------------------- | :---------------- | :--: | :------------------------------------------------------ |
| $\lim\limits_{x⇝∞^{+}} f(x) = \lim\limits_{x⇝∞^{+}} \dfrac{\ln (1 + x)}{x^p} = \lim\limits_{x⇝∞^{+}} \dfrac{1}{(1 + x) · p · x^{p-1}} = \lim\limits_{x⇝∞^{+}} \dfrac{1}{p·x^{p}} ≤ \rlap{≡≡≡≡≡≡≡}\left[ \lim\limits_{x⇝∞^+} \dfrac{q}{x^a} \right] $ | $[p>1]$           | $⇒$  | $\int\limits_{1}^{∞^{+}} f(x) · \mathrm{d} x = I_{∞^+}$ |

