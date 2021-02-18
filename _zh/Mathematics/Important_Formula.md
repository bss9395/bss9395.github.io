---
layout:  zh_post
Topic :  收敛极限
Title :  重要公式
Update:  2021-02-18T16:30:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 初等幂级数

| $f (x)$                                                      | ${^h}f (x)$                                                  | $\sum\limits_{i=0}^n \dfrac{{^i}f (x_0)}{i!} · (x - x_0)^i$  | $+ \dfrac{{^{n+1}f (θ)}}{(n + 1)!} · (x - x_0)^{n + 1}$      | $(-R, +R)$                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| $b^x$                                                        | $b^x · \ln^h b$                                              | $\sum\limits_{i=0}^n \dfrac{\ln^i b}{i!} · x^i$              | $+ \dfrac{b^θ · \ln^{n + 1} b}{(n + 1)!} · x^{n + 1}$        | $(-∞, +∞)$                                                   |
| $ә^x$                                                        | $ә^x$                                                        | $\sum\limits_{i=0}^n \dfrac{1}{i!} · x^i$                    | $+ \dfrac{ә^θ}{(n + 1)!} · x^{n + 1}$                        | $(-∞, +∞)$                                                   |
| $\log_l (1 + x)$                                             | $\dfrac{(-1)^{h-1} · (h - 1)!}{(1 + x)^h · \ln l}$           | $\sum\limits_{i=0}^n \dfrac{(-1)^{i - 1}}{i · \ln l} · x^i$  | $+ \dfrac{(-1)^n}{(n + 1) · (1 + θ)^{n + 1} · \ln l} · x^{n + 1}$ | $(-1, +1)$                                                   |
| $\ln (1 + x)$                                                | $\dfrac{(-1)^{h-1} · (h - 1)!}{(1 + x)^h}$                   | $\sum\limits_{i=0}^n \dfrac{(-1)^{i-1}}{i} · x^i$            | $+ \dfrac{(-1)^n}{(n + 1) · (1 + θ)^{n + 1}} · x^{n + 1}$    | $(-1, +1]$                                                   |
| $\mathop{(1 + x)^p}\limits_{p≠0}$                            | $\dfrac{(1 + x)^p}{(1 + x)^h} · \prod\limits_{j=0}^{h-1} (p - j)$ | $\sum\limits_{i=0}^n \prod\limits_{j=0}^{i-1} \dfrac{p - j}{j + 1} · x^i$ | $+ \dfrac{(1 + θ)^p}{(1 + θ)^{n + 1}} · \prod\limits_{j=0}^n \dfrac{p - j}{j + 1} · x^{n + 1}$ | $\mathop{(-1, +1)}\limits_{p≤-1}; \mathop{(-1, +1]}\limits_{-1<p<0}; \mathop{[-1, +1]}\limits_{0<p}$ |
| $(1 + x)^{\frac{1}{2}}$                                      | $\dfrac{(1 + x)^{\frac{1}{2}}}{(1 + x)^h} · \prod\limits_{j=0}^{h-1} \dfrac{1 - 2 · j}{2}$ | $\sum\limits_{i=0}^n \prod\limits_{j=0}^{i-1} \dfrac{1 - 2 · j}{2 · (j + 1)} · x^i$ | $+ \dfrac{(1 + θ)^{\frac{1}{2}}}{(1 + θ)^{n+1}} · \prod\limits_{j=0}^n \dfrac{1 - 2 · j}{2 · (j + 1)} · x^{n + 1}$ | $[-1, +1]$                                                   |
| $(1 + x)^{-\frac{1}{2}}$                                     | $\dfrac{1}{(1 + x)^{\frac{1}{2} + h}} · \prod\limits_{j=0}^{h-1} \dfrac{1 - 2 · j}{2}$ | $\sum\limits_{i=0}^n \prod\limits_{j=0}^{j-i} \dfrac{1 - 2 · j}{2 · (j + 1)} · x^i$ | $+ \dfrac{1}{(1 + θ)^{\frac{1}{2} + n + 1}} · \prod\limits_{j=0}^n \dfrac{1 - 2 · j}{2 · (j + 1)} · x^{n + 1}$ | $(-1, +1]$                                                   |
| $\dfrac{1}{1 + x}$                                           | $\dfrac{(-1)^h · h!}{(1 + x)^{h + 1}}$                       | $\sum\limits_{i=0}^n (-1)^i · x^i$                           | $+ \dfrac{(-1)^{n+1}}{(1 + θ)^{n + 2}} · x^{n + 1}$          | $(-1, +1)$                                                   |
| $\dfrac{1}{1 - x}$                                           | $\dfrac{h!}{(1 - x)^{h + 1}}$                                | $\sum\limits_{i=0}^n x^i$                                    | $+ \dfrac{1}{(1 - θ)^{n + 2}} · x^{n + 1}$                   | $(-1, +1)$                                                   |
| $\sin x = \dfrac{ә^{\imath · x} - ә^{-\imath · x}}{2 · \imath}$ | $\sin \left( x + h · \dfrac{π}{2} \right) = \imath^h · \dfrac{ә^{\imath · x} - (-1)^h · ә^{-\imath · x}}{2 · \imath}$ | $\sum\limits_{i=0}^n \dfrac{(-1)^{i}}{(2 · i + 1)!} · x^{2 · i + 1}$ | $+ \dfrac{(-1)^{n + 1} · \sin θ}{(2 · n + 3)!} · x^{2 · n + 3}$ | $(-∞, +∞)$                                                   |
| $\cos x = \dfrac{ә^{\imath · x} + ә^{-\imath · x}}{2}$       | $\cos \left( x + h · \dfrac{π}{2} \right) = \imath^h · \dfrac{ә^{\imath · x} + (-1)^h · ә^{-\imath · x}}{2}$ | $\sum\limits_{i=0}^n \dfrac{(-1)^i}{(2 · i)!} · x^{2 · i}$   | $+ \dfrac{(-1)^{n + 1} · \cos θ}{(2 · n + 2)!} · x^{2 · n + 2}$ | $(-∞, +∞)$                                                   |
| $\sinh x = \dfrac{ә^x - ә^{-x}}{2}$                          | $\dfrac{ә^x - (-1)^h · ә^{-x}}{2}$                           | $\sum\limits_{i=0}^n \dfrac{1}{(2 · i + 1)!} · x^{2 · i + 1}$ | $+ \dfrac{ә^θ + ә^{-θ}}{2 · (2 · n + 3)!} · x^{2 · n + 3}$   | $(-∞, +∞)$                                                   |
| $\cosh x = \dfrac{ә^x + ә^{-x}}{2}$                          | $\dfrac{ә^x + (-1)^h · ә^{-x}}{2}$                           | $\sum\limits_{i=0}^n \dfrac{1}{(2 · i)!} · x^{2 · i}$        | $+ \dfrac{ә^θ + ә^{-θ}}{2 · (2 · n + 2)!} · x^{2 · n + 2}$   | $(-∞, +∞)$                                                   |
|                                                              |                                                              |                                                              |                                                              |                                                              |
| $\arctan x = \int\limits_0^x \dfrac{1}{1 + x^2} \mathrm{d} x$ | $\dfrac{1}{1 + x^2} = \sum\limits_{i=0}^{+∞} (-x^2)^i$       | $\sum\limits_{i=0}^{+∞} \dfrac{(-1)^i}{2 · i + 1} · x^{2 · i + 1}$ |                                                              | $[-1, +1]$                                                   |

附加证明：$f (x) = \mathop{(1 + x)^p}\limits_{p≠0}$的收敛点集为$\mathop{(-1, +1)}\limits_{p≤-1}; \mathop{(-1, +1]}\limits_{-1<p<0}; \mathop{[-1, +1]}\limits_{0<p}$。

| $⇓$  | $f (x) = \sum\limits_{i=0}^n \prod\limits_{j=0}^{i-1} \dfrac{p - j}{j + 1} · x^i = \sum\limits_{i=0}^n \prod\limits_{j=0}^{i-1} \dfrac{j - p}{j + 1} · (-x)^i$ |      |                                                              |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $R_n (x) = \dfrac{(1 + θ)^p}{(1 + θ)^{n + 1}} · \prod\limits_{j=0}^n \dfrac{p - j}{j + 1} · x^{n + 1} = \dfrac{(1 + θ)^p}{(1 + θ)^{n + 1}} · \prod\limits_{j=0}^n \dfrac{j - p}{j + 1} · (-x)^{n + 1}$ |      |                                                              |
| $⇓$  | $\left[ 0 ≠ 1 \mathop{≤}\limits^{p≤-1} \lim\limits_{i⇝+∞} \prod\limits_{j=0}^{i-1} \left| \dfrac{j - p}{j + 1} \right| = \lim\limits_{i⇝+∞} | s_{i} (+1) | \right] ∧ \left[ \lim\limits_{n⇝+∞} \mathop{| R_n (+1) |}\limits_{1≤1+θ≤2}^{0≤θ≤1} ≤ \lim\limits_{n⇝+∞} \dfrac{2^p}{1^{n + 1}} · \prod\limits_{j=0}^n \left| \dfrac{j - p}{j + 1} \right| \mathop{⇝}\limits^{-1 < p} 0 \right]$ | $⇒$  | $\mathop{[+0, +1)}\limits_{p≤-1}; \mathop{[+0, +1]}\limits_{-1<p}$ |
| $⇓$  | $\lim\limits_{i⇝+∞} i · \left[ \dfrac{s_i^+ (-1)}{s_{i+1}^+ (-1)} - 1 \right] \mathop{==}\limits^{j≥p} \lim\limits_{i⇝+∞} i · \left[ \prod\limits_{j=0}^{i-1} \dfrac{j - p}{j + 1} · \prod\limits_{j=0}^{i} \dfrac{j + 1}{j - p} - 1 \right] = \lim\limits_{i⇝+∞} i · \left[ \dfrac{i + 1}{i - p} - 1 \right] = 1 + p$ | $⇒$  | $\mathop{(-1, -0]}\limits_{p<0}; \mathop{[-1, -0]}\limits_{0<p}$ |
| $⇓$  |                                                              |      | $\mathop{(-1, +1)}\limits_{p≤-1}; \mathop{(-1, +1]}\limits_{-1<p<0}; \mathop{[-1, +1]}\limits_{0<p}$ |

### 复数积分

$\int\limits_{0}^{+∞} e^{-α · x} · e^{\imath · β · x} \mathrm{d} x = \dfrac{α + \imath · β}{α^2 + β^2}$

$\int\limits_0^{+∞} e^{- α · x} · \cos (β · x) \mathrm{d} x = \dfrac{α}{α^2 + β^2}$

$\int\limits_0^{+∞} e^{- α · x} · \sin (β · x) \mathrm{d} x = \dfrac{β}{α^2 + β^2}$

| $⇓$  | $\int\limits_{X_0}^{X_1} e^{-α · x} · e^{\imath · β · x} \mathrm{d} x = \left[ \dfrac{e^{-α · x + \imath · β · x}}{-α + \imath · β} \right]_{I_0}^{I_1} = \left[ \dfrac{e^{-α · x}}{-α + \imath · β} · \dfrac{-α - \imath · \beta}{-α - \imath · \beta} · [\cos (β · x) + \imath · \sin (β · x)] \right]_{X_0}^{X_1}$ |      |                                                              |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\int\limits_{X_0}^{X_1} e^{-α · x} · e^{\imath · β · x} \mathrm{d} x = \left[ \dfrac{e^{-α · x}}{α^2 + β^2} · [[ -α · \cos (β · x) + β · \sin (β · x) ] + \imath · [ -α · \sin (β · x) - β · \cos (β · x) ]] \right]_{X_0}^{X_1}$ | $⇔$  | $\int\limits_{X_0}^{X_1} e^{-α · x} · [ \cos (β · x) + \imath · \sin (β · x)] \mathrm{d} x$ |
| $⇓$  | $\int\limits_{X_0}^{X_1} e^{-α · x} · \cos (β · x) \mathrm{d} x = \left[ \dfrac{e^{-α · x}}{α^2 + β^2} · [ -α · \cos (β · x) + β · \sin (β · x)] \right]_{X_0}^{X_1}$ | $⇒$  | $\int\limits_0^{+∞} e^{- α · x} · \cos (β · x) \mathrm{d} x = \dfrac{α}{α^2 + β^2}$ |
| $⇓$  | $\int\limits_{X_0}^{X_1} e^{-α · x} · \sin (β · x) \mathrm{d} x = \left[ \dfrac{e^{-α · x}}{α^2 + β^2} · [-α · \sin (β · x) - β · \cos (β · x)] \right]_{X_0}^{X_1}$ | $⇒$  | $\int\limits_0^{+∞} e^{- α · x} · \sin (β · x) \mathrm{d} x = \dfrac{β}{α^2 + β^2}$ |
| $⇓$  |                                                              | $⇒$  | $\int\limits_{0}^{+∞} e^{-α · x} · e^{\imath · β · x} \mathrm{d} x = \dfrac{α + \imath · β}{α^2 + β^2}$ |

### 指数积分

$\int\limits_{0}^{+∞} e^{-x^2} \mathrm{d} x = \dfrac{\sqrt{π}}{2}$

| $⇓$  | $\int\limits_0^{+∞} e^{-x^2} \mathrm{d} x \mathop{===}\limits^{t = x^2} \int\limits_0^{+∞} e^{-t} \dfrac{\mathrm{d} t}{2 · \sqrt{t}} = \dfrac{1}{2} · \int\limits_{0}^{+∞} t^{\frac{1}{2} - 1} · e^{-t} \mathrm{d} t = \dfrac{1}{2} · Γ \left( \dfrac{1}{2} \right) = \dfrac{\sqrt{π}}{2}$ | $⇐$  | $Γ \left( \dfrac{1}{2} \right) = \sqrt{π}$ |
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
| $⇓$  | $I_{2·m} = \dfrac{π}{2} · \dfrac{1}{2} · \dfrac{3}{4} ··· \dfrac{2 · m - 3}{2 · m - 2} · \dfrac{2 · m - 1}{2 · m}$ | $⇐$  | $I_0 = \int\limits_{0}^{\frac{π}{2}} \cos^0 x \mathrm{d} x = \dfrac{π}{2}$ |
| $⇓$  | $I_{2·m+1} = 1 · \dfrac{2}{3} · \dfrac{4}{5} ··· \dfrac{2 · m - 2}{2 · m - 1} · \dfrac{2 · m}{2 · m + 1}$ | $⇐$  | $I_1 = \int\limits_{0}^{\frac{π}{2}} \cos^1 x \mathrm{d} x = [ \sin x ]_{0}^{\frac{π}{2}} = 1$ |
| $⇓$  | $I_n = \left[ \dfrac{π}{2} \right]^{\frac{1 + (-1)^n}{2}} · \left[ \prod\limits_{i=1}^n i^{(-1)^i} \right]^{(-1)^{n+1}}$ |      |                                                              |

| $⇓$  | $\int\limits_{-π}^{+π} \dfrac{1 - r^2}{1 - 2 · r · \cos x + r^2} \mathrm{d} x \mathop{=======}\limits_{\cos x = \frac{1 - \tan^2 \frac{x}{2}}{1 + \tan^2 \frac{x}{2}}}^{t = \tan \frac{x}{2}} \int\limits_{-∞}^{+∞} \dfrac{1 - r^2}{1 - 2 · r · \dfrac{1 - t^2}{1 + t^2} + r^2} \dfrac{2 · \mathrm{d} t}{1 + t^2} = \int\limits_{-∞}^{+∞} \dfrac{2 · (1 - r^2)}{(1 - r)^2 + (1 + r)^2 · t^2} \mathrm{d} t = 2 · \left[ \arctan \left( \dfrac{1 + r}{1 - r} · t \right) \right]_{-∞}^{+∞} = 2 · π$ |
| :--: | ------------------------------------------------------------ |
|      |                                                              |

### 调和积分

$\int\limits_{0}^{1} \dfrac{1}{x^α} \mathrm{d} x = \mathop{\dfrac{1}{1 - α}}\limits_{0<α<1}; \mathop{+∞}\limits_{1≤α<+∞}$

$\int\limits_{1}^{+∞} \dfrac{1}{x^α} \mathrm{d} x = \mathop{+∞}\limits_{0<α≤1}; \mathop{\dfrac{1}{α - 1}}\limits_{1<α<+∞}$

$\int\limits_{0}^{+∞} \dfrac{1}{x^α} \mathrm{d} x = +∞$

$\int\limits_{1}^{2} \dfrac{1}{x · \ln^β x} \mathrm{d} x = \mathop{\dfrac{\ln^{1 - β} 2}{1 - β}}\limits_{0<β<1}; \mathop{+∞}\limits_{1≤β<+∞}$

$\int\limits_{2}^{+∞} \dfrac{1}{x · \ln^β x} \mathrm{d} x = \mathop{+∞}\limits_{0<β≤1}; \mathop{\dfrac{1}{(β - 1) · \ln^{β - 1} 2}}\limits_{1<β<+∞}$

$\int\limits_{2}^{+∞} \dfrac{1}{x · \ln^β x} \mathrm{d} x = +∞$

|      | $\int\limits_{X_0}^{X_1} \dfrac{1}{x^α} \mathrm{d} x \mathop{====}\limits_{0<X_0,X_1}^{α≠1} \left[ \dfrac{x^{1 - α}}{1 - α} \right]_{X_0}^{X_1} = \dfrac{X_1^{1 - α} - X_0^{1 - α}}{1 - α}$ | $\int\limits_{X_0}^{X_1} \dfrac{1}{x^1} \mathrm{d} x \mathop{====}\limits_{0<X_0,X_1}^{α=1} [ \ln x ]_{X_0}^{X_1} = \ln \dfrac{X_1}{X_0}$ |      |                                                              |
| :--: | :----------------------------------------------------------- | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\int\limits_{0}^{X_1} \dfrac{1}{x^α} \mathrm{d} x \mathop{==}\limits^{α≠1} \dfrac{X_1 - (0^+)^{1 - α}}{1 - α} = \mathop{\dfrac{X_1}{1 - α}}\limits_{0<α<1}; \mathop{+∞}\limits_{1<α<+∞}$ | $\int\limits_{0}^{X_1} \dfrac{1}{x^1} \mathrm{d} x = \ln \dfrac{X_1}{0^+} = +∞$ | $⇒$  | $\int\limits_{0}^{1} \dfrac{1}{x^α} \mathrm{d} x = \mathop{\dfrac{1}{1 - α}}\limits_{0<α<1}; \mathop{+∞}\limits_{1≤α<+∞}$ |
| $⇓$  | $\int\limits_{X_0}^{+∞} \dfrac{1}{x^α} \mathrm{d} x \mathop{==}\limits^{α≠1} \dfrac{(+∞)^{1 - α} - X_0}{1 - α} = \mathop{+∞}\limits_{0<α<1}; \mathop{\dfrac{X_0}{α - 1}}\limits_{1<α<+∞}$ | $\int\limits_{X_0}^{+∞} \dfrac{1}{x^1} \mathrm{d} x = \ln \dfrac{+∞}{X_0} = +∞$ | $⇒$  | $\int\limits_{1}^{+∞} \dfrac{1}{x^α} \mathrm{d} x = \mathop{+∞}\limits_{0<α≤1}; \mathop{\dfrac{1}{α - 1}}\limits_{1<α<+∞}$ |
| $⇓$  |                                                              |                                                              | $⇒$  | $\int\limits_{0}^{+∞} \dfrac{1}{x^α} \mathrm{d} x = +∞$      |
| $⇓$  | $\int\limits_{X_0}^{X_1} \dfrac{1}{x · \ln^β x} \mathrm{d} x \mathop{====}\limits^{t=\ln x} \int\limits_{\ln X_0}^{\ln X_1} \dfrac{1}{t^β} \mathrm{d} t \mathop{====}\limits_{1<X_0,X_1}^{β≠1} \left[ \dfrac{t^{1 - β}}{1 - β} \right]_{\ln X_0}^{\ln X_1} = \dfrac{\ln^{1 - β} X_1 - \ln^{1 - β} X_0}{1 - β}$ |                                                              | $⇒$  | $\int\limits_{1}^{2} \dfrac{1}{x · \ln^β x} \mathrm{d} x = \mathop{\dfrac{\ln^{1 - β} 2}{1 - β}}\limits_{0<β<1}; \mathop{+∞}\limits_{1≤β<+∞}$ |
| $⇓$  | $\int\limits_{X_0}^{X_1} \dfrac{1}{x · \ln^1 x} \mathrm{d} x \mathop{===}\limits^{t=\ln x} \int\limits_{X_0}^{X_1} \dfrac{1}{t^1} \mathrm{d} t \mathop{====}\limits_{1<X_0,X_1}^{β=1} [ \ln t ]_{\ln X_0}^{\ln X_1} = \ln \dfrac{\ln X_1}{\ln X_0}$ |                                                              | $⇒$  | $\int\limits_{2}^{+∞} \dfrac{1}{x · \ln^β x} \mathrm{d} x = \mathop{+∞}\limits_{0<β≤1}; \mathop{\dfrac{1}{(β - 1) · \ln^{β - 1} 2}}\limits_{1<β<+∞}$ |
| $⇓$  |                                                              |                                                              | $⇒$  | $\int\limits_{2}^{+∞} \dfrac{1}{x · \ln^β x} \mathrm{d} x = +∞$ |

