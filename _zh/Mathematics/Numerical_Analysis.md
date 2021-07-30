---
layout:  zh_post
Topic :  收敛极限
Title :  数值分析
Update:  2021-07-30T08:34:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 特别注意

```
本书中误差算符与教科书不同。
本书中误差算符等同距离算符。
```

教科书中，绝对误差算符为$Δ$，相对误差算符为$δ$。

在本书中，绝对误差算符为$\mathrm{D}$，相对误差算符为$\mathrm{d}$。

### 渐进量

若$\lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} ⇝ 0$，则称当$x⇝x_0$时，函数$f(x)$对于函数$g(x)$为渐进小量，可记作$f(x) = \mathrm{o}[g(x)]_{x_0}$。

若$\lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} ⇝ q$，则称当$x⇝x_0$时，函数$f(x)$对于函数$g(x)$为渐进同量，可记作$f(x) = \mathrm{O}[g(x)]_{x_0}$。

若$\lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} ⇝ 1$，则称当$x⇝x_0$时，函数$f(x)$对于函数$g(x)$为渐进等量，可记作$f(x) = \mathrm{Θ}[g(x)]_{x_0}$。

若$f(x) = \mathrm{Θ}[g(x)]_{x_0}$，则当$x⇝x_0$时，函数$f(x)$与函数$g(x)$可在乘运算中，但非加运算中相互替换。

| $f(x) = \mathrm{o}[g(x)]_{x_0}$                              | $⇒$  | $f(x) = \mathrm{O}[g(x)]_{x_0}$                              |
| :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $f(x) = \mathrm{Θ}[g(x)]_{x_0}$                              | $⇔$  | $g(x) = \mathrm{Θ}[f(x)]_{x_0}$                              |
| $f(x) = \mathrm{Θ}[g(x)]_{x_0}$                              | $⇔$  | $f(x) = g(x) + \mathrm{o}[g(x)]_{x_0}$                       |
| $f(x) · \mathrm{o}[g(x)] = \mathrm{o}[f(x) · g(x)]_{x_0}$    | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{f(x) · \mathrm{o}[g(x)]}{f(x) · g(x)} = \lim\limits_{x⇝x_0} \dfrac{\mathrm{o}[g(x)]}{g(x)} ⇝ 0$ |
| $f(x) · \mathrm{O}[g(x)] = \mathrm{O}[f(x) · g(x)]_{x_0}$    | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{f(x) · \mathrm{O}[g(x)]}{f(x) · g(x)} = \lim\limits_{x⇝x_0} \dfrac{\mathrm{O}[g(x)]}{g(x)} ⇝ q$ |
| $α · \mathrm{o}[g(x)] = \mathrm{o}[g(x)]_{x_0}$              | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{α · \mathrm{o}[g(x)]}{g(x)} ⇝ 0$ |
| $α · \mathrm{O}[g(x)] = \mathrm{O}[g(x)]_{x_0}$              | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{α · \mathrm{O}[g(x)]}{g(x)} ⇝ α · q$ |
| $\mathrm{o}^{α}[g(x)] \mathop{=}\limits^{0<α} \mathrm{o}[g^{α}(x)]_{x_0}$ | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{\mathrm{o}^{α}[g(x)]}{g^{α}(x)} \mathop{=}\limits^{0<α} \left[ \lim\limits_{x⇝x_0} \dfrac{\mathrm{o}[g(x)]}{g(x)} \right]^{α} ⇝ 0$ |
| $\mathrm{O}^{α}[g(x)] \mathop{=}\limits^{0<α} \mathrm{O}[g^{α}(x)]_{x_0}$ | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{\mathrm{O^{α}}[g(x)]}{g^{α}(x)} \mathop{=}\limits^{0<α} \left[ \lim\limits_{x⇝x_0} \dfrac{\mathrm{O}[g(x)]}{g(x)} \right]^{α} ⇝ q^{α}$ |
| $\lim\limits_{x⇝x_0} f(x) · u(x) \mathop{=======}\limits_{u(x)=\mathrm{Θ}[v(x)]_{x_0}}^{f(x)=\mathrm{Θ}[g(x)]_{x_0}} \lim\limits_{x⇝x_0} g(x) · v(x)$ | $⇐$  | $\lim\limits_{x⇝x_0} f(x) · u(x) = \lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} · [g(x) · v(x)] · \dfrac{u(x)}{v(x)} = \lim\limits_{x⇝x_0} g(x) · v(x)$ |
| $\lim\limits_{x⇝x_0} \dfrac{f(x)}{u(x)} \mathop{=======}\limits_{u(x)=\mathrm{Θ}[v(x)]_{x_0}}^{f(x)=\mathrm{Θ}[g(x)]_{x_0}} \lim\limits_{x⇝x_0} \dfrac{g(x)}{v(x)}$ | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{f(x)}{u(x)} = \lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} · \dfrac{g(x)}{v(x)} · \dfrac{v(x)}{u(x)} = \lim\limits_{x⇝x_0} \dfrac{g(x)}{v(x)}$ |
| $f(x) \mathop{======}\limits_{g(x)=\mathrm{o}[h(x)]_{x_0}}^{f(x)=\mathrm{o}[g(x)]_{x_0}} \mathrm{o}[h(x)]_{x_0}$ | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{f(x)}{h(x)} = \lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} · \dfrac{g(x)}{h(x)} ⇝ 0 · 0 = 0$ |
| $f(x) \mathop{=======}\limits_{g(x)=\mathrm{O}[h(x)]_{x_0}}^{f(x)=\mathrm{O}[g(x)]_{x_0}} \mathrm{O}[h(x)]_{x_0}$ | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{f(x)}{h(x)} = \lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} · \dfrac{g(x)}{h(x)} ⇝ q_0 · q_1 = q$ |
| $f(x) \mathop{=======}\limits_{g(x) = \mathrm{Θ}[h(x)]_{x_0}}^{f(x) = \mathrm{Θ}[g(x)]_{x_0}} \mathrm{Θ}[h(x)]_{x_0}$ | $⇐$  | $\lim\limits_{x⇝x_0} \dfrac{f(x)}{h(x)} = \lim\limits_{x⇝x_0} \dfrac{f(x)}{g(x)} · \dfrac{g(x)}{h(x)} ⇝ 1 · 1 = 1$ |
| $f(x) \mathop{======}\limits_{g(x)=\mathrm{O}[f(x)]}^{f(x)=\mathrm{O}[g(x)]} \mathrm{Θ}[g(x)]_{x_0}$ | $⇔$  | $f(x) = \mathrm{O}[g(x)] $                                   |

### 渐近过程

任意型渐近线 $0 = p · y + q · x + r$

水平型渐近线 $0 = p · y + r$

垂直型渐近线 $0 = q · x + r$

点到直线距离 $\mathrm{D} = \dfrac{|p·y_0+q·x_0+r|}{\sqrt{p^2 + q^2}}$

线性渐进过程 $\left\lbrace\begin{aligned}
& 0 ⇜ \lim\limits_{x⇝\mathop{x_0}\limits^{∞}} |p · f(x) + q · x + r| \\
& 0 ⇜ \lim\limits_{x⇝\mathop{x_0}\limits^{∞}} \dfrac{|p·f(x) + q·x + r|}{\sqrt{p^2 + q^2}} \\
\end{aligned}\right.$

典例：函数$f(x) = \dfrac{1}{x}$，有垂直渐近线$0 = x$，与水平渐近线$0 = y$。

$\left[ 0 ⇜ \lim\limits_{x⇝0^{+}} \left| p·f(x)+q·x+r \right| = \lim\limits_{x⇝0^{+}} \left| p·\dfrac{1}{x}+q·x+r \right| \right] \mathop{⇒}\limits_{r=0}^{p=0} \left[ 0 = x \right]$

$\left[ 0 ⇜ \lim\limits_{x⇝∞^{+}} \left| p·f(x)+q·x+r \right| = \lim\limits_{x⇝∞^{+}} \left| p·\dfrac{1}{x}+q·x+r \right| \right] \mathop{⇒}\limits_{r = 0}^{q=0} \left[ 0=y \right]$



### 近似误差

变量精确值 $\bar{x}$

变量近似值 $x = \bar{x} ± \mathrm{D}(x)$

绝对误差值 $\mathrm{D}(x) ≡ |x - \bar{x}|$

相对误差值 $\mathrm{d}(x) ≡ \dfrac{|x - \bar{x}|}{|x|} ≡ \dfrac{\mathrm{D}(x)}{|x|}$

近似误差值的运算性质。

| $\mathrm{D}(y + x) ≤ \mathrm{D}(y) + \mathrm{D}(x)$          | $\mathrm{d}(y + x) ≤ \dfrac{\mathrm{D}(y) + \mathrm{D}(x)}{|y + x|}$ |      |                                                              | $\mathrm{d}(y+x) \mathop{≤}\limits_{|x|≤|y+x|}^{|y|≤|y+x|} \mathrm{d}(y) + \mathrm{d}(x)$ |
| :----------------------------------------------------------- | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\mathrm{D}(y - x) ≤ \mathrm{D}(y) + \mathrm{D}(x)$          | $\mathrm{d}(y - x) ≤ \dfrac{\mathrm{D}(y) + \mathrm{D}(x)}{|y - x|}$ |      |                                                              | $\mathrm{d}(y - x) \mathop{≤}\limits_{|x|≤|y-x|}^{|y|≤|y-x|} \mathrm{d}(y)+\mathrm{d}(x)$ |
| $\mathrm{D}(y · x) ≤ |y| · \mathrm{D}(x) + \mathrm{D}(y) · |x| + \mathrm{D}(y) · \mathrm{D}(x)$ | $\mathrm{d}(y · x) ≤ \mathrm{d}(y) + \mathrm{d}(x) + \mathrm{d}(y) · \mathrm{d}(x)$ |      | $\mathrm{D}(y·x) \mathop{≤}\limits^{\mathrm{D}(y)·\mathrm{D}(x)≈0} |y| · \mathrm{D}(x) + \mathrm{D}(y) · |x|$ | $\mathrm{d}(y·x) \mathop{≤}\limits^{\mathrm{d}(y)·\mathrm{d}(x)≈0} \mathrm{d}(y) + \mathrm{d}(x)$ |
| $\mathrm{D}\left( \dfrac{y}{x} \right) ≤ \dfrac{|y| · \mathrm{D}(x) + \mathrm{D}(y) · |x|}{x^2 · [1 - \mathrm{d}(x)]}$ | $\mathrm{d}\left( \dfrac{y}{x} \right) ≤ \dfrac{\mathrm{d}(y) + \mathrm{d}(x)}{1 - \mathrm{d}(x)}$ |      | $\mathrm{D}\left(\dfrac{y}{x}\right) \mathop{≤}\limits^{1-\mathrm{d}(x)≈0} \dfrac{|y|·\mathrm{D}(x)+\mathrm{D}(y)·|x|}{x^2}$ | $\mathrm{d}\left(\dfrac{y}{x}\right) \mathop{≤}\limits^{1-\mathrm{d}(x)≈0} \mathrm{d}(y) + \mathrm{d}(x)$ |


| $\mathrm{D}(y + x)$                     | $\mathrm{D}(y + x) = |(y + x) - (\bar{y} + \bar{x})| ≤ |y - \bar{y}| + |x - \bar{x}| = \mathrm{D}(y) + \mathrm{D}(x)$ |
| :-------------------------------------- | :----------------------------------------------------------- |
| $\mathrm{D}(y - x)$                     | $ \mathrm{D}(y - x) = |(y - x) - (\bar{y} - \bar{x})| ≤ |y - \bar{y}| + |x - \bar{x}| = \mathrm{D}(y) + \mathrm{D}(x)$ |
| $\mathrm{D}(y · x)$                     | $\mathrm{D}(y · x) = |y · x - \bar{y} · \bar{x}| = |y · x - (y + Δy) · (x + Δx)| ≤ |y · Δx| + |Δy · x| + |Δy · Δx| = |y| · \mathrm{D}(x) + \mathrm{D}(y) · |x| + \mathrm{D}(y) · \mathrm{D}(x)$ |
| $\mathrm{D}\left( \dfrac{y}{x} \right)$ | $\mathrm{D}\left( \dfrac{y}{x} \right) = \left| \dfrac{y}{x} - \dfrac{\bar{y}}{\bar{x}} \right| = \left| \dfrac{y·\bar{x}-\bar{y}·x}{x·\bar{x}} \right| = \left| \dfrac{y · (x + Δx) - (y + Δy) · x}{x · (x + Δx)} \right| ≤ \dfrac{|y · Δx| + |Δy · x|}{x^2 · \left| 1 + \dfrac{Δx}{x} \right|} ≤ \dfrac{|y| · \mathrm{D}(x) + \mathrm{D}(y) · |x|}{x^2 · [1 - \mathrm{d}(x)]}$ |
|                                         |                                                              |
| $\mathrm{d}(y + x)$                     | $\mathrm{d}(y + x) = \dfrac{\mathrm{D}(y + x)}{|y + x|} ≤ \dfrac{\mathrm{D}(y) + \mathrm{D}(x)}{|y + x|}$ |
| $\mathrm{d}(y - x)$                     | $\mathrm{d}(y - x) = \dfrac{\mathrm{D}(y - x)}{|y - x|} ≤ \dfrac{\mathrm{D}(y) + \mathrm{D}(x)}{|y - x|}$ |
| $\mathrm{d}(y · x)$                     | $\mathrm{d}(y · x) = \dfrac{\mathrm{D}(y · x)}{|y · x|} ≤ \dfrac{|y| · \mathrm{D}(x) + \mathrm{D}(y) · |x| + \mathrm{D}(y) · \mathrm{D}(x)}{|y · x|} = \mathrm{d}(y) + \mathrm{d}(x) + \mathrm{d}(y) · \mathrm{d}(x)$ |
| $\mathrm{d}\left( \dfrac{y}{x} \right)$ | $\mathrm{d}\left( \dfrac{y}{x} \right) = \mathrm{D}\left( \dfrac{y}{x} \right) · \left| \dfrac{y}{x} \right|^{-1} ≤ \dfrac{|y| · \mathrm{D}(x) + \mathrm{D}(y) · |x|}{x^2 · [1 - \mathrm{d}(x)]} · \left| \dfrac{x}{y} \right| = \dfrac{\mathrm{d}(y) + \mathrm{d}(x)}{1 - \mathrm{d}(x)}$ |

### 线性插值

函数$f(x)$在区间$[x_α,x_β]$上线性插值的误差。

$l(x) - f(x) \mathop{=====}\limits^{∃θ∈(x_α,x_β)} \dfrac{(x_β - x) · (x - x_α)}{2} · {^2}f(θ)$

| $⇓$  | $l(x) = \dfrac{x_β - x}{x_β - x_α} · f(x_α) + \dfrac{x - x_α}{x_β - x_α} · f(x_β)$ | $⇐$  | $$0 = \left|\begin{matrix} 1 & 1 & 1 \\ x_α & x & x_β \\ f(x_α) & l(x) & f(x_β) \\ \end{matrix}\right| = \left|\begin{matrix} 1 & 0 & 0 \\ x_α & x - x_α & x_β - x_α \\ f(x_α) & l(x) - f(x_α) & f(x_β) - f(x_α) \\ \end{matrix}\right|$$ |
| :--: | :----------------------------------------------------------- | :--: | ------------------------------------------------------------ |
| $⇓$  | $l(x) - f(x) = \dfrac{x_β - x}{x_β - x_α} · [f(x_α) - f(x)] + \dfrac{x - x_α}{x_β - x_α} · [f(x_β) - f(x)]$ | $⇐$  | $f(x_α) - f(x) = {^1}f(x) · (x_α - x) + \dfrac{{^2}f(θ_α)}{2} · (x_α - x)^2$ |
| $⇓$  | $l(x) - f(x) = \dfrac{(x_β - x) · (x - x_α)}{2} · \left[ \dfrac{x - x_α}{x_β - x_α} · {^2}f(θ_α) + \dfrac{x_β - x}{x_β - x_α} · {^2}f(θ_β) \right]$ | $⇐$  | $f(x_β) - f(x) = {^1}f(x) · (x_β - x) + \dfrac{{^2}f(θ_β)}{2} · (x_β - x)^2$ |
| $⇓$  | $l(x) - f(x) \mathop{========}\limits^{∃θ∈(θ_α,θ_β)⊆(x_α,x_β)} \dfrac{(x_β - x) · (x - x_α)}{2} · {^2}f(θ)$ | $⇐$  | $\min\lbrace {^2}f(θ_α),{^2}f(θ_β) \rbrace ≤ \dfrac{x - x_α}{x_β - x_α} · {^2}f(θ_α) + \dfrac{x_β - x}{x_β - x_α} · {^2}f(θ_β) ≤ \max\lbrace {^2}f(θ_α),{^2}f(θ_β) \rbrace$ |

函数$f(X)$在点$x_0$处闭邻域内的局部形态。

| $\dfrac{{^n}f(x_0)}{n!} · (x - x_0)^{n} + o(x - x_0)^{n}$ | $\mathop{======}\limits^{{^h}f(x_0) \mathop{===}\limits^{1≤h<n} 0}$ | $f(x) - f(x_0)$                                         |                                                   |
| :-------------------------------------------------------- | :----------------------------------------------------------: | :------------------------------------------------------ | :------------------------------------------------ |
| $[n = 2·l + 0] ∧ [{^n}f(x_0) > 0]$                        |                             $⇔$                              | $[f(x_0^{-}) - f(x_0) > 0] ∧ [f(x_0^{+}) - f(x_0) > 0]$ | $f(x_0) = \inf\limits_{x∈\mathrm{B}(x_0,δ)} f(x)$ |
| $[n = 2·l + 0] ∧ [{^n}f(x_0) < 0]$                        |                             $⇔$                              | $[f(x_0^{-}) - f(x_0) < 0] ∧ [f(x_0^{+}) - f(x_0) < 0]$ | $f(x_0) = \max\limits_{x∈\mathrm{B}(x_0,δ)} f(x)$ |
|                                                           |                                                              |                                                         |                                                   |
| $\dfrac{{^n}f(x_0)}{n!} · (x - x_0)^{n} + o(x - x_0)^{n}$ | $\mathop{======}\limits^{{^h}f(x_0) \mathop{===}\limits^{1<h<n} 0}$ | $f(x) - l(x)$                                           | $l(x) ≡ f(x) - f(x_0) - {^1}f(x_0) · (x - x_0)$   |
| $[n = 2 · l + 0] ∧ [{^n}f(x_0) < 0]$                      |                             $⇔$                              | $[f(x_0-Δ) - l(x_0-Δ) < 0] ∧ [f(x_0+Δ) - l(x_0+Δ) < 0]$ | $x_0$为相切点，$f(x)$在切线$l(x)$下方。           |
| $[n = 2 · l + 0] ∧ [{^n}f(x_0) > 0]$                      |                             $⇔$                              | $[f(x_0-Δ) - l(x_0-Δ) > 0] ∧ [f(x_0+Δ) - l(x_0+Δ) > 0]$ | $x_0$为相切点，$f(x)$在切线$l(x)$上方。           |
| $[n = 2 · l + 1] ∧ [{^n}f(x_0) < 0]$                      |                             $⇔$                              | $[f(x_0-Δ) - l(x_0-Δ) > 0] ∧ [f(x_0+Δ) - l(x_0+Δ) < 0]$ | $x_0$为相交点，$f(x)$于切线$l(x)$向下。           |
| $[n = 2 · l + 1] ∧ [{^n}f(x_0) > 0]$                      |                             $⇔$                              | $[f(x_0-Δ) - l(x_0-Δ) < 0] ∧ [f(x_0+Δ) - l(x_0+Δ) > 0]$ | $x_0$为相交点，$f(x)$于切线$l(x)$向上。           |

