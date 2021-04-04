---
layout:  zh_post
Topic :  收敛极限
Title :  微积分
Update:  2021-04-05T05:30:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 矩阵的坐标

矩阵的坐标遵循的原则：列优先于行，列数向右递增，行数向上递增。

$(m + 1) × (n + 1)$矩阵的坐标，列数为$m$，行数为$n$。

$\left[\begin{matrix}
(0, n) & (1, n) & ⋯ & (m, n) \\
⋮ & ⋮ & ⋰ & ⋮ \\
(0, 1) & (1, 1) & ⋯ & (m, 1) \\
(0, 0) & (1, 0) & ⋯ & (m, 0) \\
\end{matrix}\right]$

$(n + 1) × (n + 1)$方阵的单位矩阵，对角线方向为左下右上。

$\left[\begin{matrix}
0 & 0 & ⋯ & 1 \\
⋮ & ⋮ & ⋰ & ⋮ \\
0 & 1 & ⋯ & 0 \\
1 & 0 & ⋯ & 0 \\
\end{matrix}\right]$

### 矩阵的运算

矩阵的运算遵循的原则：列优先于行，单列从下往上，单行从左往右。

矩阵$\mathcal{F}[(m + 1) × (n + 1)]$的反置矩阵${'}\mathcal{F}[(m + 1) × (n + 1)]$。

$\mathrm{rev} \mathcal{F}[(m + 1) × (n + 1)] = {^{'}}\mathcal{F}[(m + 1) × (n + 1)]$

$\mathrm{rev}\left[\begin{matrix}
f_{0,n} & f_{1,n} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
f_{0,1} & f_{1,1} & ⋯ & f_{m,1} \\
f_{0,0} & f_{1,0} & ⋯ & f_{m,0} \\
\end{matrix}\right] \mathop{====}\limits^{h_{i,j}=f_{j,i}} \left[\begin{matrix}
h_{0,n} & h_{1,n} & ⋯ & h_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
h_{0,1} & h_{1,1} & ⋯ & h_{m,1} \\
h_{0,0} & h_{1,0} & ⋯ & h_{m,0} \\
\end{matrix}\right]$

矩阵$\mathcal{F}[(m + 1) × (n + 1)]$与矩阵$\mathcal{G}[(m + 1) × (n + 1)]$的加运算。

$\mathcal{F}[(m + 1) × (n + 1)] + \mathcal{G}[(m + 1) × (n + 1)] = \mathcal{H}[(m +1) × (n + 1)]$

$\left[\begin{matrix}
f_{0,n} & f_{1,n} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
f_{0,1} & f_{1,1} & ⋯ & f_{m,1} \\
\rlap{≡≡}{f_{0,0}} & f_{1,0} & ⋯ & f_{m,0} \\
\end{matrix}\right] + \left[\begin{matrix}
g_{0,n} & g_{1,n} & ⋯ & g_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
g_{0,1} & g_{1,1} & ⋯ & g_{m,1} \\
\rlap{≡≡}{g_{0,0}} & g_{1,0} & ⋯ & g_{m,0} \\
\end{matrix}\right] \mathop{======}\limits^{h_{i,j}=f_{i,j}+g_{i,j}} \left[\begin{matrix}
h_{0,n} & h_{1,n} & ⋯ & h_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
h_{0,1} & h_{1,1} & ⋯ & h_{m,1} \\
\rlap{≡≡}{h_{0,0}} & h_{1,0} & ⋯ & h_{m,0} \\
\end{matrix}\right]$

矩阵$\mathcal{F}[(l + 1) × (m + 1)]$与矩阵$\mathcal{G}[(m + 1) × (n + 1)]$的乘运算。

$\mathcal{F}[(l + 1) × (m + 1)] × \mathcal{G}[(m + 1) × (n + 1)] = \mathcal{H}[(l +1) × (n + 1)]$

$\left[\begin{matrix}
\rlap{≡≡}{f_{0,m}} & f_{1,m} & ⋯ & f_{l,m} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\rlap{≡≡}{f_{0,1}} & f_{1,1} & ⋯ & f_{l,1} \\
\rlap{≡≡}{f_{0,0}} & f_{1,0} & ⋯ & f_{l,0} \\
\end{matrix}\right] × \left[\begin{matrix}
g_{0,n} & g_{1,n} & ⋯ & g_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
g_{0,1} & g_{1,1} & ⋯ & g_{m,1} \\
\rlap{≡≡}{g_{0,0}} & \rlap{≡≡}{g_{1,0}} & ⋯ & \rlap{≡≡}{g_{m,0}} \\
\end{matrix}\right] \mathop{=======}\limits^{h_{i,j}=\sum\limits_{k=0}^{m} f_{i,k}·g_{k,j}} \left[\begin{matrix}
h_{0,n} & h_{1,n} & ⋯ & h_{l,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
h_{0,1} & h_{1,1} & ⋯ & h_{l,1} \\
h_{0,0} & h_{1,0} & ⋯ & h_{l,0} \\
\end{matrix}\right]$

