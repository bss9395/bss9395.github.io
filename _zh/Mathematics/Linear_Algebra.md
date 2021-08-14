---
layout:  zh_post
Topic :  收敛极限
Title :  线性代数
Update:  2021-05-11T22:10:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 特别注意

```
本书中矩阵的定义与教科书不同。
本书中矩阵以左下右上为对角线。
```

$n$元线性代数方程组的最典型定义。

$\left[\begin{matrix}
y_1 \\
y_2 \\
⋮ \\
y_n \\
\end{matrix}\right] = \left[\begin{matrix}
a_{1,1} & a_{1,2} & ⋯ & a_{1,n} \\
a_{2,1} & a_{2,2} & ⋯ & a_{2,n} \\
⋮ & ⋮ & ⋱ & ⋮ \\
a_{m,1} & a_{m,2} & ⋯ & a_{m,n}
\end{matrix}\right] × \left[\begin{matrix}
x_1 \\
x_2 \\
⋮ \\
x_n \\
\end{matrix}\right] = \left[\begin{matrix}
a_{1,1} · x_1 + a_{1,2} · x_2 + ⋯ + a_{1,n} · x_n \\
a_{2,1} · x_1 + a_{2,2} · x_2 + ⋯ + a_{2,n} · x_n \\
⋮ \\
a_{m,1} · x_1 + a_{m,2} · x_2 + ⋯ + a_{m,n} · x_n \\
\end{matrix}\right]$

$n + 1$元线性代数方程组的现定义。

$\left[\begin{matrix}
y_n \\
⋮ \\
y_1 \\
y_0 \\
\end{matrix}\right] = \left[\begin{matrix}
f_{m,0} & f_{m,1} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
f_{1,0} & f_{1,1} & ⋯ & f_{1,n} \\
f_{0,0} & f_{0,1} & ⋯ & f_{0,n} \\
\end{matrix}\right] × \left[\begin{matrix}
x_n \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] = \left[\begin{matrix}
f_{m,0} · x_0 + f_{m,1} · x_1 + ⋯ + f_{m,n} · x_n \\
⋮ \\
f_{1,0} · x_0 + f_{1,1} · x_1 + ⋯ + f_{1,n} · x_n \\
f_{0,0} · x_0 + f_{0,1} · x_1 + ⋯ + f_{0,n} · x_n \\
\end{matrix}\right]$

### 矩阵的坐标

矩阵的坐标遵循的原则：行优先于列，行数向上递增，列数向右递增。

$(m + 1) × (n + 1)$矩阵的坐标，行数为$m$，列数为$n$。

$\left[\begin{matrix}
(m, 0) & (m, 1) & → & (m, n) \\
↑ & ↑ & ↗ & ↑ \\
(1, 0) & (1, 1) & → & (1, n) \\
(0, 0) & (0, 1) & → & (0, n) \\
\end{matrix}\right]$

$(n + 1) × (n + 1)$方阵的单位矩阵，对角线为左下右上。

$\left[\begin{matrix}
0 & 0 & ⋯ & 1 \\
⋮ & ⋮ & ⋰ & ⋮ \\
0 & 1 & ⋯ & 0 \\
1 & 0 & ⋯ & 0 \\
\end{matrix}\right]$

### 矩阵的运算

矩阵的运算遵循的原则：行优先于列，单行从左往右，单列从下往上。

矩阵$\mathcal{F}[(m + 1) × (n + 1)]$的反置矩阵${'}\mathcal{F}[(m + 1) × (n + 1)]$。

${^{'} }\mathcal{F}[(m + 1) × (n + 1)] = \mathrm{rev} \mathcal{F}[(m + 1) × (n + 1)]$

$\left[\begin{matrix}
h_{n,0} & h_{n,1} & ⋯ & h_{n,m} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$h_{1,0}$} & h_{1,1} & ⋯ & h_{1,m} \\
h_{0,0} & \fbox{$h_{0,1}$} & ⋯ & h_{0,m} \\
\end{matrix}\right] \mathop{====}\limits^{h_{i,j}=f_{j,i} } \mathrm{rev} \left[\begin{matrix}
f_{m,0} & f_{m,1} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{1,0}$} & f_{1,1} & ⋯ & f_{1,n} \\
f_{0,0} & \fbox{$f_{0,1}$} & ⋯ & f_{0,n} \\
\end{matrix}\right] = \left[\begin{matrix}
f_{0,n} & f_{1,n} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{0,1}$} & f_{1,1} & ⋯ & f_{m,1} \\
f_{0,0} & \fbox{$f_{1,0}$} & ⋯ & f_{m,0} \\
\end{matrix}\right]$

矩阵$\mathcal{G}[(m + 1) × (n + 1)]$与矩阵$\mathcal{F}[(m + 1) × (n + 1)]$的加运算。

$\mathcal{H}[(m +1) × (n + 1)] = \mathcal{G}[(m + 1) × (n + 1)] + \mathcal{F}[(m + 1) × (n + 1)]$

$\left[\begin{matrix}
h_{m,0} & h_{m,1} & ⋯ & h_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$h_{1,0}$} & \fbox{$h_{1,1}$} & ⋯ & \fbox{$h_{1,n}$} \\
h_{0,0} & h_{0,1} & ⋯ & h_{0,n} \\
\end{matrix}\right] \mathop{======}\limits^{h_{i,j}=f_{i,j}+g_{i,j} } \left[\begin{matrix}
g_{m,0} & g_{m,1} & ⋯ & g_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$g_{1,0}$} & \fbox{$g_{1,1}$} & ⋯ & \fbox{$g_{1,n}$} \\
g_{0,0} & g_{0,1} & ⋯ & g_{0,n} \\
\end{matrix}\right] + \left[\begin{matrix}
f_{m,0} & f_{m,1} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{1,0}$} & \fbox{$f_{1,1}$} & ⋯ & \fbox{$f_{1,n}$} \\
f_{0,0} & f_{0,1} & ⋯ & f_{0,n} \\
\end{matrix}\right] = \left[\begin{matrix}
g_{m,0}+f_{m,0} & g_{m,1}+f_{m,1} & ⋯ & g_{m,n}+f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$g_{1,0}+f_{1,0}$} & \fbox{$g_{1,1}+f_{1,1}$} & ⋯ & \fbox{$g_{1,n}+f_{1,n}$} \\
g_{0,0}+f_{0,0} & g_{0,1}+f_{0,1} & ⋯ & g_{0,n}+f_{0,n} \\
\end{matrix}\right]$

矩阵$\mathcal{G}[(l + 1) × (m + 1)]$与矩阵$\mathcal{F}[(m + 1) × (n + 1)]$的乘运算。

$\mathcal{H}[(l +1) × (n + 1)] = \mathcal{G}[(l + 1) × (m + 1)] × \mathcal{F}[(m + 1) × (n + 1)]$

$\left[\begin{matrix}
h_{l,0} & h_{l,1} & ⋯ & h_{l,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$h_{1,0}$} & h_{1,1} & ⋯ & h_{1,n} \\
h_{0,0} & h_{0,1} & ⋯ & h_{0,n} \\
\end{matrix}\right] \mathop{========}\limits^{h_{i,j}=\sum\limits_{k=0}^{m} g_{i,k}·f_{k,j} } \left[\begin{matrix}
g_{l,0} & g_{l,1} & ⋯ & g_{l,m} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$g_{1,0}$} & \fbox{$g_{1,1}$} & ⋯ & \fbox{$g_{1,m}$} \\
g_{0,0} & g_{0,1} & ⋯ & g_{0,m} \\
\end{matrix}\right] × \left[\begin{matrix}
\fbox{$f_{m,0}$} & f_{m,1} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{1,0}$} & f_{1,1} & ⋯ & f_{1,n} \\
\fbox{$f_{0,0}$} & f_{0,1} & ⋯ & f_{0,n} \\
\end{matrix}\right]$

二元关系$\mathcal{G}[Z × Y]$与二元关系$\mathcal{F}[Y × X]$的复合关系$\mathcal{H}[Z × X]$。

$\mathcal{H}[Z × X] = \mathcal{G}[Z × Y] ∘ \mathcal{F}[Y × X]$

### 多项式分解

$9·x^3 + 30·x^2 + 42·x^1 + 26 = 9·(x+1)^3 + 3·(x+1)^2 + 9·(x+1)^1 + 5 \\
\begin{array}{l|l|l|l}
\hline
x+1 & 9·x^3 + 30·x^2 + 42·x^1 + 26                                            & 9·x^2 + 21·x^1 + 21                                               & 9·x^1 + 12 & 9 \\
    & 9·x^3 + \ \ 9·x^2                                                       & 9·x^2 + \ \ 9·x^1 & 9·x^1 + \ \ 9 \\
\hline
    & \ \ \ \ \ \ \ \ \ \ \ \ \ \ 21·x^2 + 42·x^1                             & \ \ \ \ \ \ \ \ \ \ \ \ \ \ 12·x^1 + 21                           & \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ 3 \\
    & \ \ \ \ \ \ \ \ \ \ \ \ \ \ 21·x^2 + 21·x^1                             & \ \ \ \ \ \ \ \ \ \ \ \ \ \  12·x^1 + 12 \\
\hline
    & \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ 21·x^1 + 26 & \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ 9 \\
    & \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ 21·x^1 + 21 \\
\hline
    & \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ 5 \\
\hline
\end{array}$