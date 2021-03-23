---
layout:  zh_post
Topic :  收敛极限
Title :  自然基数
Update:  2021-03-21T19:44:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 自然数列

$ә_{n} \mathop{≡≡≡}\limits_{ә_{1}=2}^{ә_{0}=1} \left( 1 + \dfrac{1}{n} \right)^{n} < \left( 1 + \dfrac{1}{n + 1} \right)^{n+1} = ә_{n+1}$

$e_{n} \mathop{≡≡≡}\limits_{e_{1}=\frac{1}{4}}^{e_{0}=0} \left( 1 - \dfrac{1}{n + 1} \right)^{n+1} < \left( 1 - \dfrac{1}{n + 2} \right)^{n+2} = e_{n+1}$

$ә_{n} = \left( 1 + \dfrac{1}{n} \right)^{n} < \left( 1 + \dfrac{1}{n + 1} \right)^{n+1} = ә_{n+1} < \dfrac{1}{e_{n+1}} = \left( 1 + \dfrac{1}{n + 1} \right)^{n+2} < \left( 1 + \dfrac{1}{n} \right)^{n+1} = \dfrac{1}{e_{n}}$

| $⇓$  | $ә_{n} = \left( 1 + \dfrac{1}{n} \right)^{n} = \left[ 1 · \left( 1 + \dfrac{1}{n} \right)^{n} \right]^{\frac{n+1}{n+1}} < \left[ \dfrac{1 + n · \left( 1 + \dfrac{1}{n} \right)}{n + 1} \right]^{n+1} = \left( 1 + \dfrac{1}{n + 1} \right)^{n+1} = ә_{n+1}$ | $⇐$  | $\left[ \prod\limits_{i=0}^{n} x_i \right]^{\frac{1}{n+1}} \mathop{<}\limits_{0<x_i} \left[ \dfrac{1}{n + 1} · \sum\limits_{i=0}^{n} x_i^{+1} \right]^{+1}$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $e_{n} = \left( 1 - \dfrac{1}{n + 1} \right)^{n+1} = \left[ 1 · \left( 1 - \dfrac{1}{n + 1} \right)^{n+1} \right]^{\frac{n+1}{n+2}} < \left[ \dfrac{1 + (n + 1) · \left( 1 - \dfrac{1}{n + 1} \right)}{n + 2} \right]^{n+2} = \left( 1 - \dfrac{1}{n + 2} \right)^{n+2} = e_{n+1}$ | $⇒$  | $\dfrac{1}{e_{n+1}} = \left( \dfrac{n + 2}{n + 1} \right)^{n+2} < \left( \dfrac{n + 1}{n} \right)^{n+1} = \dfrac{1}{e_{n}}$ |

### 自然基数

$ә ≡ \lim\limits_{n⇝∞⁺} \left( 1 + \dfrac{1}{n} \right)^{n} = \lim\limits_{x⇝∞^{±}} \left( 1 + \dfrac{1}{x} \right)^{x}$

| $⇓$  | $ә ≡ \lim\limits_{n⇝∞⁺} \left( 1 + \dfrac{1}{n} \right)^{n}$ | $\left( 1 + \dfrac{1}{n + 1} \right)^{n} < \left( 1 + \dfrac{1}{⌈x⌉} \right)^{⌊x⌋} ≤ \left( 1 + \dfrac{1}{x} \right)^{x} ≤ \left( 1 + \dfrac{1}{⌊x⌋} \right)^{⌈x⌉} < \left( 1 + \dfrac{1}{n} \right)^{n+1}$ |
| :--: | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $⇓$  | $ә = \lim\limits_{x⇝∞⁺} \left( 1 + \dfrac{1}{x} \right)^{x}$ | $\lim\limits_{n⇝∞⁺} \left( 1 + \dfrac{1}{n + 1} \right)^{n+1} · \left( 1 + \dfrac{1}{n + 1} \right)^{-1} \lim\limits_{n⇝∞⁺} \left( 1 + \dfrac{1}{n + 1} \right)^{n} ≤ \lim\limits_{x⇝∞⁺} \left( 1 + \dfrac{1}{x} \right)^{x} ≤ \lim\limits_{n⇝∞⁺} \left( 1 + \dfrac{1}{n} \right)^{n+1} ≤ \lim\limits_{n⇝∞⁺} \left( 1 + \dfrac{1}{n} \right)^{n} · \left( 1 + \dfrac{1}{n} \right)^{+1}$ |
| $⇓$  | $ә = \lim\limits_{x⇝∞⁻} \left( 1 + \dfrac{1}{x} \right)^{x}$ | $\lim\limits_{x⇝∞⁺} \left( 1 + \dfrac{1}{x} \right)^{x} = \lim\limits_{x⇝∞⁺} \left( 1 - \dfrac{1}{x + 1} \right)^{-x} \mathop{====}\limits_{-x=t+1}^{-t=x+1} \lim\limits_{t⇝∞⁻} \left( 1 + \dfrac{1}{t} \right)^{t+1} = \lim\limits_{t⇝∞⁻} \left( 1 + \dfrac{1}{t} \right)^{t} · \left( 1 + \dfrac{1}{t} \right)^{+1}$ |
| $⇓$  | $ә = \lim\limits_{x⇝∞^{±}} \left( 1 + \dfrac{1}{x} \right)^{x}$ |                                                              |

### 自然幂数

$ә^{α} = \lim\limits_{x⇝∞^{±}} \left( 1 + \dfrac{α}{x} \right)^{x}$

| $⇓$  | $α ≠ 0$ | $\lim\limits_{x⇝∞^{±}} \left( 1 + \dfrac{α}{x} \right)^{x} \mathop{==}\limits^{α≠0} \left[ \lim\limits_{x⇝∞^{±}} \left( 1 + \dfrac{1}{\frac{x}{α}} \right)^{\frac{x}{α}} \right]^{α} = ә^{α}$ |
| :--: | :------ | :----------------------------------------------------------- |
| $⇓$  | $α = 0$ | $\lim\limits_{x⇝∞^{±}} \left( 1 + \dfrac{α}{x} \right)^{x} \mathop{==}\limits^{α=0} \lim\limits_{x⇝∞^{±}} \left( 1 + \dfrac{0}{x} \right)^{x} = ә^{α}$ |
| $⇓$  | $α∈ℝ$   | $\lim\limits_{x⇝∞^{±}} \left( 1 + \dfrac{α}{x} \right)^{x} = ә^{α}$ |

### 自然函数

$f(x) ≡ \left( 1 + \dfrac{α}{x} \right)^{x} \left[ \mathop{==}\limits_{α<0} \mathop{ә^{α}}\limits_{∞⁻};\mathop{1}\limits_{0⁻};\mathop{0}\limits_{(-α)⁺};\mathop{ә^{α}}\limits_{∞⁺} \right] \left[ \mathop{==}\limits_{α=0} 1 \right] \left[ \mathop{==}\limits_{α>0} \mathop{ә^{α}}\limits_{∞⁻};\mathop{∞⁺}\limits_{(-α)⁻};\mathop{1}\limits_{0⁺};\mathop{ә^{α}}\limits_{∞⁺} \right]$

$\dfrac{\mathrm{d}^{1} f(x)}{\mathrm{d}^{1} x} = \left(1+\dfrac{α}{x}\right)^{x} · \left[ \ln\left(1+\dfrac{α}{x}\right) - \dfrac{α}{x + α} \right] = \mathop{0}\limits_{∞};\mathop{+0}\limits_{∞⁻<x<∞⁺}$

$\dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x} = \left(1+\dfrac{α}{x}\right)^{x} · \left[ \left[ \ln\left(1+\dfrac{α}{x}\right) - \dfrac{α}{x + α} \right]^{2} - \dfrac{α^{2}}{x · (x + α)^{2}} \right] = \mathop{+0}\limits_{x<0};\mathop{-0}\limits_{\left[\ln\left(1+\frac{α}{x}\right)^{1+\frac{α}{x}}-1\right]^2<\frac{1}{x}};\mathop{0}\limits_{\left[\ln\left(1+\frac{α}{x}\right)^{1+\frac{α}{x}}-1\right]^2=\frac{1}{x}};\mathop{+0}\limits_{\left[\ln\left(1+\frac{α}{x}\right)^{1+\frac{α}{x}}-1\right]^2≥\frac{1}{x}}$

| $⇓$  | $f(x) ≡ \left( 1 + \dfrac{α}{x} \right)^{x} = ә^{x·\ln\left(1+\frac{α}{x}\right)}$ | $⇒$  | $u[t(x)] \mathop{≡≡≡≡≡}\limits_{x·(x + α)>0}^{t=\frac{α}{x}>-1} \ln\left( 1 + \dfrac{α}{x} \right) + x · \dfrac{1}{1 + \dfrac{α}{x}} · \dfrac{-α}{x^2} = \ln(1 + t) + \dfrac{-t}{1 + t} ≥ \mathop{0}\limits_{u[0]}$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\dfrac{\mathrm{d}^{1} f(x)}{\mathrm{d}^{1} x} = \left(1+\dfrac{α}{x}\right)^{x} · \left[ \ln\left(1+\dfrac{α}{x}\right) + \dfrac{-α}{x + α} \right] = ә^{x·\ln\left(1+\frac{α}{x}\right)} · u[t(x)]$ | $⇒$  | $\dfrac{\mathrm{d} u[t]}{\mathrm{d} t} = \dfrac{1}{1 + t} + \dfrac{-1}{1 + t} + \dfrac{t}{(1 + t)^2} = \dfrac{t}{(1 + t)^2} = \mathop{-0}\limits_{-1<t<0};\mathop{0}\limits_{t=0};\mathop{+0}\limits_{t>0}$ |
| $⇓$  | $\dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x} = \left(1+\dfrac{α}{x}\right)^{x} · \left[ \left[ \ln\left(1+\dfrac{α}{x}\right) + \dfrac{-α}{x + α} \right]^{2} + \dfrac{-α^{2}}{x · (x + α)^{2}} \right] = ә^{x·\ln\left(1+\frac{α}{x}\right)} · \left[ u^2[t(x)] + \dfrac{\mathrm{d} u[t]}{\mathrm{d} t} · \dfrac{\mathrm{d} t(x)}{\mathrm{d} x} \right]$ | $⇒$  | $\dfrac{\mathrm{d} u[t]}{\mathrm{d} t} · \dfrac{\mathrm{d} t(x)}{\mathrm{d} x} = \dfrac{t}{(1 + t)^2} · \dfrac{-α}{x^2} = \dfrac{t^2}{(1 + t)^2} · \dfrac{-1}{x} = \mathop{+0}\limits_{x<0};\mathop{∞⁺}\limits_{x=0⁻};\mathop{∞⁻}\limits_{x=0⁺};\mathop{-0}\limits_{x>0}$ |
|      |                                                              |      |                                                              |
| $⇓$  | $f(x)$                                                       | $⇐$  |                                                              |
|      |                                                              |      |                                                              |
| $⇓$  | $\dfrac{\mathrm{d}^{1} f(x)}{\mathrm{d}^{1} x} = \mathop{0}\limits_{∞};\mathop{+0}\limits_{∞⁻<x<∞⁺}$ | $⇐$  | $u[0] \mathop{==}\limits_{x=∞}^{t=0} 0$                      |
|      |                                                              |      |                                                              |
| $⇓$  | $\left[ \ln\left( 1 + \dfrac{α}{x} \right)^{1+\frac{α}{x}} - 1 \right]^2 = \dfrac{(x + α)^2}{α^2} · \left[ \ln\left( 1 + \dfrac{α}{x} \right) + \dfrac{-α}{x + α} \right]^2 = \left[ \dfrac{1}{x} · \dfrac{α^2}{(x + α)^2} \right] · \dfrac{(x + α)^2}{α^2} = \dfrac{1}{x}$ | $⇐$  | $\dfrac{\mathrm{d}^2 f(x)}{\mathrm{d}^2 x} \mathop{==}\limits_{x>0} 0$ |
| $⇓$  | $\dfrac{\mathrm{d}^{2} f(x)}{\mathrm{d}^{2} x} = \mathop{+0}\limits_{x<0};\mathop{-0}\limits_{\left[\ln\left(1+\frac{α}{x}\right)^{1+\frac{α}{x}}-1\right]^2<\frac{1}{x}};\mathop{0}\limits_{\left[\ln\left(1+\frac{α}{x}\right)^{1+\frac{α}{x}}-1\right]^2=\frac{1}{x}};\mathop{+0}\limits_{\left[\ln\left(1+\frac{α}{x}\right)^{1+\frac{α}{x}}-1\right]^2≥\frac{1}{x}}$ |      |                                                              |

