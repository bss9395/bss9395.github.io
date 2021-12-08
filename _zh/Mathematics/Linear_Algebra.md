---
layout:  zh_post
Topic :  收敛极限
Title :  线性代数
Update:  2021-12-08T23:06:00+08@中国-广东-深圳+08
Author:  璀璨星辰
Link  :
---

### 特别注意

```
本书中矩阵的定义与教科书不同。
本书中矩阵以左下右上为对角线。
```

$n$元线性代数方程组的最典型定义。

$$
\left[\begin{matrix}
y_1 \\
y_2 \\
⋮ \\
y_n \\
\end{matrix}\right] = \left[\begin{matrix}
a_{1,1} & a_{1,2} & ⋯ & a_{1,n} \\
a_{2,1} & a_{2,2} & ⋯ & a_{2,n} \\
⋮ & ⋮ & ⋱ & ⋮ \\
a_{m,1} & a_{m,2} & ⋯ & a_{m,n}
\end{matrix}\right]_{m×n} \rlap{×}{+} \left[\begin{matrix}
x_1 \\
x_2 \\
⋮ \\
x_n \\
\end{matrix}\right] = \left[\begin{matrix}
a_{1,1} · x_1 + a_{1,2} · x_2 + ⋯ + a_{1,n} · x_n \\
a_{2,1} · x_1 + a_{2,2} · x_2 + ⋯ + a_{2,n} · x_n \\
⋮ \\
a_{m,1} · x_1 + a_{m,2} · x_2 + ⋯ + a_{m,n} · x_n \\
\end{matrix}\right]
$$

$n + 1$元线性代数方程组的现定义。

$$
\left[\begin{matrix}
y_n \\
⋮ \\
y_1 \\
y_0 \\
\end{matrix}\right] = \left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)} \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] = \left[\begin{matrix}
a_{m,0} · x_0 + a_{m,1} · x_1 + ⋯ + a_{m,n} · x_n \\
⋮ \\
a_{1,0} · x_0 + a_{1,1} · x_1 + ⋯ + a_{1,n} · x_n \\
a_{0,0} · x_0 + a_{0,1} · x_1 + ⋯ + a_{0,n} · x_n \\
\end{matrix}\right]
$$

### 矩阵的坐标

矩阵的坐标遵循的原则：行优先于列，行数向上递增，列数向右递增。

$(m+1)×(n+1)$矩阵的坐标，行数为$m+1$，列数为$n+1$。

$$
\left[\begin{matrix}
(m, 0) & (m, 1) & → & (m, n) \\
↑ & ↑ & ↗ & ↑ \\
(1, 0) & (1, 1) & → & (1, n) \\
(0, 0) & (0, 1) & → & (0, n) \\
\end{matrix}\right]_{(m+1)×(n+1)}
$$

$(n+1)×(n+1)$方阵的单位矩阵，对角线为左下右上。

$$
\left[\begin{matrix}
0 & 0 & ⋯ & 1 \\
⋮ & ⋮ & ⋰ & ⋮ \\
0 & 1 & ⋯ & 0 \\
1 & 0 & ⋯ & 0 \\
\end{matrix}\right]_{(n+1)×(n+1)}
$$

### 矩阵的运算

矩阵的运算遵循的原则：行优先于列，单行从左往右，单列从下往上。

矩阵$\mathcal{F}[(m+1)×(n+1)]$的转置矩阵为${^t}\mathcal{F}[(m+1)×(n+1)] ≡ \mathrm{rev} \mathcal{F}[(m+1)×(n+1)]$。

$\mathcal{H}[(n+1)×(m+1)] = {^t}\mathcal{F}[(m+1)×(n+1)]$。

$$
\left[\begin{matrix}
h_{n,0} & h_{n,1} & ⋯ & h_{n,m} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$h_{1,0}$} & h_{1,1} & ⋯ & h_{1,m} \\
h_{0,0} & \fbox{$h_{0,1}$} & ⋯ & h_{0,m} \\
\end{matrix}\right]_{(n+1)×(m+1)} \mathop{====}\limits^{h_{i,j}=f_{j,i} } \mathrm{rev} \left[\begin{matrix}
f_{m,0} & f_{m,1} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{1,0}$} & f_{1,1} & ⋯ & f_{1,n} \\
f_{0,0} & \fbox{$f_{0,1}$} & ⋯ & f_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)} ≡ \left[\begin{matrix}
f_{0,n} & f_{1,n} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{0,1}$} & f_{1,1} & ⋯ & f_{m,1} \\
f_{0,0} & \fbox{$f_{1,0}$} & ⋯ & f_{m,0} \\
\end{matrix}\right]_{(n+1)×(m+1)}
$$

矩阵$\mathcal{G}[(m+1)×(n+1)]$与矩阵$\mathcal{F}[(m+1)×(n+1)]$的位加运算。

$\mathcal{H}[(m+1)×(n+1)] = \mathcal{G}[(m+1)×(n+1)] + \mathcal{F}[(m+1)×(n+1)]$。

$$
\left[\begin{matrix}
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
\end{matrix}\right]
$$

矩阵$\mathcal{G}[(l+1)×(m+1)]$与矩阵$\mathcal{F}[(m+1)×(n+1)]$的乘和运算。

$\mathcal{H}[(l+1)×(n+1)] = \mathcal{G}[(l+1)×(m+1)] \rlap{×}{+} \mathcal{F}[(m+1)×(n+1)]$

$$
\left[\begin{matrix}
h_{l,0} & h_{l,1} & ⋯ & h_{l,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$h_{1,0}$} & h_{1,1} & ⋯ & h_{1,n} \\
h_{0,0} & h_{0,1} & ⋯ & h_{0,n} \\
\end{matrix}\right]_{(l+1)×(n+1)} \mathop{========}\limits^{h_{i,j}=\sum\limits_{k=0}^{m} g_{i,k}·f_{k,j} } \left[\begin{matrix}
g_{l,0} & g_{l,1} & ⋯ & g_{l,m} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$g_{1,0}$} & \fbox{$g_{1,1}$} & ⋯ & \fbox{$g_{1,m}$} \\
g_{0,0} & g_{0,1} & ⋯ & g_{0,m} \\
\end{matrix}\right]_{(l+1)×(m+1)} \rlap{×}{+} \left[\begin{matrix}
\fbox{$f_{m,0}$} & f_{m,1} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{1,0}$} & f_{1,1} & ⋯ & f_{1,n} \\
\fbox{$f_{0,0}$} & f_{0,1} & ⋯ & f_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)}
$$

二元关系$\mathcal{G}[Z×Y]$与二元关系$\mathcal{F}[Y×X]$的复合关系$\mathcal{H}[Z×X]$。

$\mathcal{H}[Z×X] = \mathcal{G}[Z×Y] ∘ \mathcal{F}[Y×X]$

### 多项式分解

$$
9·x^3 + 30·x^2 + 42·x^1 + 26 = 9·(x+1)^3 + 3·(x+1)^2 + 9·(x+1)^1 + 5 \\
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
\end{array}
$$

### 矩阵的运算性质

若无特别的规定，约定矩阵指行矩阵而非列矩阵，行矩阵与列矩阵互为转置。

$$
\begin{aligned}
\mathrm{A}_{(m+1)×(n+1)} &= \left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)} \\
{^t}\mathrm{A}_{(n+1)×(m+1)} &= \left[\begin{matrix}
a_{0,n} & a_{1,n} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{0,1} & a_{1,1} & ⋯ & a_{m,1} \\
a_{0,0} & a_{1,0} & ⋯ & a_{m,0} \\
\end{matrix}\right]_{(n+1)×(m+1)} \\
\end{aligned}
$$

单位$(n+1)×(n+1)$元矩阵。

$$
\mathrm{I}_{(n+1)×(n+1)} = \left[\begin{matrix}
0 & 0 & ⋯ & 1 \\
⋮ & ⋮ & ⋰ & ⋮ \\
0 & 1 & ⋯ & 0 \\
1 & 0 & ⋯ & 0 \\
\end{matrix}\right]_{(n+1)×(n+1)}
$$

标量与$(m+1)×(n+1)$元矩阵的量加运算。

$$
\left[\begin{matrix}
c + a_{m,0} & c + a_{m,1} & ⋯ & c + a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
c + a_{1,0} & c + a_{1,1} & ⋯ & c + a_{1,n} \\
c + a_{0,0} & c + a_{0,1} & ⋯ & c + a_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)} = c \oplus \left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)}
$$

$(m+1)×(n+1)$元矩阵与$(m+1)×(n+1)$元矩阵的位加运算。

$$
\left[\begin{matrix}
b_{m,0} + a_{m,0} & b_{m,1} + a_{m,1} & ⋯ & b_{m,n} + a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} + a_{1,0} & b_{1,1} + a_{1,1} & ⋯ & b_{1,n} + a_{1,n} \\
b_{0,0} + a_{0,0} & b_{0,1} + a_{0,1} & ⋯ & b_{0,n} + a_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)} = \left[\begin{matrix}
b_{m,0} & b_{m,1} & ⋯ & b_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} & b_{1,1} & ⋯ & b_{1,n} \\
b_{0,0} & b_{0,1} & ⋯ & b_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)} + \left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)}
$$

标量与$(m+1)×(n+1)$元矩阵的量乘运算。

$$
\left[\begin{matrix}
c · a_{m,0} & c · a_{m,1} & ⋯ & c · a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
c · a_{1,0} & c · a_{1,1} & ⋯ & c · a_{1,n} \\
c · a_{0,0} & c · a_{0,1} & ⋯ & c · a_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)} = c \odot \left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)}
$$

$(m+1)×(n+1)$元矩阵与$(m+1)×(n+1)$元矩阵的点乘运算。

$$
\sum\limits_{i=0}^{m} \sum\limits_{j=0}^{n} b_{i,j} · a_{i,j} = \left[\begin{matrix}
b_{m,0} & b_{m,1} & ⋯ & b_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} & b_{1,1} & ⋯ & b_{1,n} \\
b_{0,0} & b_{0,1} & ⋯ & b_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)} · \left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)}
$$

$(m+1)×(n+1)$元矩阵与$(m+1)×(n+1)$元矩阵的位乘运算。

$$
\left[\begin{matrix}
b_{m,0} · a_{m,0} & b_{m,1} · a_{m,1} & ⋯ & b_{m,n} · a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} · a_{1,0} & b_{1,1} · a_{1,1} & ⋯ & b_{1,n} · a_{1,n} \\
b_{0,0} · a_{0,0} & b_{0,1} · a_{0,1} & ⋯ & b_{0,n} · a_{0,n} \\
\end{matrix}\right] = \left[\begin{matrix}
b_{m,0} & b_{m,1} & ⋯ & b_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} & b_{1,1} & ⋯ & b_{1,n} \\
b_{0,0} & b_{0,1} & ⋯ & b_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)} × \left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)}
$$

$(l+1)*(m+1)$元矩阵与$(m+1)×(n+1)$元矩阵的乘和运算。

$$
\left[\begin{matrix}
\sum\limits_{k=0}^{m} b_{l,k} · a_{k,0} & \sum\limits_{k=0}^{m} b_{l,k} · a_{k,1} & ⋯ & \sum\limits_{k=0}^{m} b_{l,k} · a_{k,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\sum\limits_{k=0}^{m} b_{1,k} · a_{k,0} & \sum\limits_{k=0}^{m} b_{1,k} · a_{k,1} & ⋯ & \sum\limits_{k=0}^{m} b_{1,k} · a_{k,n} \\
\sum\limits_{k=0}^{m} b_{0,k} · a_{k,0} & \sum\limits_{k=0}^{m} b_{0,k} · a_{k,1} & ⋯ & \sum\limits_{k=0}^{m} b_{0,k} · a_{k,n} \\
\end{matrix}\right]_{(l+1)×(n+1)} = \left[\begin{matrix}
b_{l,0} & b_{l,1} & ⋯ & b_{l,m} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} & b_{1,1} & ⋯ & b_{1,m} \\
b_{0,0} & b_{0,1} & ⋯ & b_{0,m} \\
\end{matrix}\right]_{(l+1)×(m+1)} \rlap{×}{+} \left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]_{(m+1)×(n+1)}
$$

### 矢量的运算性质

若无特别的规定，约定矢量指列矢量而非行矢量，列矢量与行矢量互为转置。

$$
\begin{aligned}
\vec{v} &= \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] \\
{^t}\vec{v} &= \left[\begin{matrix}
v_0, v_1, ⋯, v_n \\
\end{matrix}\right]
\end{aligned}
$$

标量与$n+1$元矢量的量加运算。

$$
\left[\begin{matrix}
c + v_n \\
⋮ \\
c + v_1 \\
c + v_0 \\
\end{matrix}\right] = c \oplus \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right]
$$

$n+1$元矢量与$n+1$元矢量的位加运算。

$$
\left[\begin{matrix}
u_n + v_n \\
⋮ \\
u_1 + v_1 \\
u_0 + v_0 \\
\end{matrix}\right] = \left[\begin{matrix}
u_n \\
⋮ \\
u_1 \\
u_0 \\
\end{matrix}\right] + \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right]
$$

标量与$n+1$元矢量的量乘运算。

$$
\left[\begin{matrix}
c · v_n \\
⋮ \\
c · v_1 \\
c · v_0 \\
\end{matrix}\right] = c \odot \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] \\
\left[\begin{matrix}
0 & 0 & ⋯ & c \\
⋮ & ⋮ & ⋰ & ⋮ \\
0 & c & ⋯ & 0 \\
c & 0 & ⋯ & 0 \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right]
$$

$n+1$元矢量与$n+1$元矢量的点乘运算。

$$
|\vec{u}| · |\vec{v}| · \cos \ang(\vec{u},\vec{v}) = \sum\limits_{k=0}^{n} v_k · w_k  = \left[\begin{matrix}
u_n \\
⋮ \\
u_1 \\
u_0 \\
\end{matrix}\right] · \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] \\
\left[\begin{matrix}
u_0 & u_1 & ⋯ & u_n \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right]
$$

$n+1$元矢量与$n+1$元矢量的位乘运算。

$$
\left[\begin{matrix}
u_n · v_n \\
⋮ \\
u_1 · v_1 \\
u_0 · v_0 \\
\end{matrix}\right] = \left[\begin{matrix}
u_n \\
⋮ \\
u_1 \\
u_0 \\
\end{matrix}\right] × \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] \\
\left[\begin{matrix}
0 & 0 & ⋯ & u_n \\
⋮ & ⋮ & ⋰ & ⋮ \\
0 & u_1 & ⋯ & 0 \\
u_0 & 0 & ⋯ & 0 \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right]
$$

$3$元矢量与$3$元矢量的叉乘运算。
$$
\vec{n}_{\vec{u}\otimes\vec{v}} · |\vec{u}| · |\vec{v}| · \sin \ang(\vec{u},\vec{v}) = \left|\begin{matrix}
\vec{k} & u_z & v_z \\
\vec{j} & u_y & v_y \\
\vec{i} & u_x & v_x \\
\end{matrix}\right| = \left[\begin{matrix}
u_x · v_y - u_y · v_x \\
u_z · v_x - u_x · v_z \\
u_y · v_z - u_z · v_y \\
\end{matrix}\right] = \left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\left[\begin{matrix}
-u_y & +u_x & 0 \\
+u_z & 0 & -u_x \\
0 & -u_z & +u_y \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right]
$$

### 矢量的三重积

$3$元矢量的混合叉点积。

$$
\left|\begin{matrix}
t_z & u_z & v_z \\
t_y & u_y & v_y \\
t_x & u_x & v_x \\
\end{matrix}\right| = \left[\begin{matrix}
t_z \\
t_y \\
t_x \\
\end{matrix}\right] · \left[\begin{matrix}
u_x · v_y - u_y · v_x \\
u_z · v_x - u_x · v_z \\
u_y · v_z - u_z · v_y \\
\end{matrix}\right] = \left[\begin{matrix}
t_z \\
t_y \\
t_x \\
\end{matrix}\right] · \left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
= (t_y · u_z - t_z · u_y) · v_x + (t_z · u_x - t_x · u_z) · v_y + (t_x · u_y - t_y · u_x) · v_z \\
= \left[\begin{matrix}
(t_y · u_z - t_z · u_y) & (t_z · u_x - t_x · u_z) & (t_x · u_y - t_y · u_x) \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right]
$$

$3$元矢量的对称叉叉积。

$$
\begin{aligned}
\left[\begin{matrix}
r_z \\
r_y \\
r_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
r_z \\
r_y \\
r_x \\
\end{matrix}\right] &= \left[\begin{matrix}
r_x · v_y - r_y · v_x \\
r_z · v_x - r_x · v_z \\
r_y · v_z - r_z · v_y \\
\end{matrix}\right] \otimes \left[\begin{matrix}
r_z \\
r_y \\
r_x \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
(r_y · v_z - r_z · v_y) · r_y - (r_z · v_x - r_x · v_z) · r_x \\
(r_x · v_y - r_y · v_x) · r_x - (r_y · v_z - r_z · v_y) · r_z \\
(r_z · v_x - r_x · v_z) · r_z - (r_x · v_y - r_y · v_x) · r_y \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
-r_z · r_x · v_x - r_y · r_z · v_y + (r_x^2 + r_y^2) · v_z \\
-r_x · r_y · v_x + (r_z^2 + r_x^2) · v_y - r_y · r_z · v_z \\
+(r_y^2 + r_z^2) · v_x - r_x · r_y · v_y - r_z · r_x · v_z \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
-r_z · r_x & -r_y · r_z & (r_x^2 + r_y^2) \\
-r_x · r_y & (r_z^2 + r_x^2) & -r_y · r_z \\
(r_y^2 + r_z^2) & -r_x · r_y & -r_z · r_x \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\end{aligned}
$$

$3$元矢量的对称点量积。
$$
\begin{aligned}
\left(\left[\begin{matrix}
r_z \\
r_y \\
r_x \\
\end{matrix}\right] · \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right]\right) \odot \left[\begin{matrix}
r_z \\
r_y \\
r_x \\
\end{matrix}\right] &= (r_x · v_x + r_y · v_y + r_z · v_z) \odot \left[\begin{matrix}
r_z \\
r_y \\
r_x \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
r_z · r_x · v_x + r_y · r_z · v_y + r_z^2 · v_z \\
r_x · r_y · v_x + r_y^2 · v_y + r_y · r_z · v_z \\
r_x^2 · v_x + r_x · r_y · v_y + r_z · r_x · v_z \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
r_z · r_x & r_y · r_z & r_z^2 \\
r_x · r_y & r_y^2 & r_y · r_z \\
r_x^2 & r_x · r_y & r_z · r_x \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right]
\end{aligned}
$$
