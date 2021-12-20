---
layout:  zh_post
Topic :  收敛极限
Title :  线性代数
Update:  2021-12-20T11:05:00+08@中国-广东-深圳+08
Author:  璀璨星辰
Link  :
---

### 特别注意

```
本书中矩阵的定义与教科书不同。
本书中矩阵以左下右上为对角线。
本书中对矩阵的反置为Reverse，而非转置Transpose，其符号为´A而非Aᵀ。
本书中对矩阵的倒逆为Inverse，其符号为ᶥA而非A⁻¹。
本书中坐标系的基向量符号为η。
本书中坐标系均为右手旋坐标系。
本书中共有2种加运算5种乘运算。
本书中矩阵的行列式为Determinant，其符号为║A║。
本书中矩阵的度量值为Measurement，其符号为│A│。
度量值Measurement是拓扑值Topologee的二次方情形。约定Topologee表示拓扑距或者拓扑值。
本书中向量由标量与矢量共同构成，向量的第0位表示其标量分量，矢量的第0位表示其ηₓ分量。本书暂未做修订。
```

$n$元线性代数方程组的最典型定义。
$$
\left[\begin{matrix}
y_1 \\
y_2 \\
⋮ \\
y_n \\
\end{matrix}\right] = \mathop{\left[\begin{matrix}
a_{1,1} & a_{1,2} & ⋯ & a_{1,n} \\
a_{2,1} & a_{2,2} & ⋯ & a_{2,n} \\
⋮ & ⋮ & ⋱ & ⋮ \\
a_{m,1} & a_{m,2} & ⋯ & a_{m,n}
\end{matrix}\right]}\limits_{m×n} \rlap{×}{+} \left[\begin{matrix}
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
\end{matrix}\right] = \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} \rlap{×}{+} \left[\begin{matrix}
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

矩阵的坐标遵循的原则：行优先于列，行数向上递增，列数向右递增。从左往右，从下往上。

$(m+1)×(n+1)$元矩阵的坐标，行数为$m+1$，列数为$n+1$。

$$
\mathop{\left[\begin{matrix}
(m, 0) & (m, 1) & → & (m, n) \\
↑ & ↑ & ↗ & ↑ \\
(1, 0) & (1, 1) & → & (1, n) \\
(0, 0) & (0, 1) & → & (0, n) \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)}
$$

$(n+1)×(n+1)$元方矩阵的单位方矩阵，对角线为左下右上。

$$
\mathop{\left[\begin{matrix}
0 & 0 & ⋯ & 1 \\
⋮ & ⋮ & ⋰ & ⋮ \\
0 & 1 & ⋯ & 0 \\
1 & 0 & ⋯ & 0 \\
\end{matrix}\right]}\limits_{(n+1)×(n+1)}
$$

### 矩阵的运算

矩阵的运算遵循的原则：行优先于列，单行从左往右，单列从下往上。向左复合，向右运算。

矩阵$\mathcal{F}[(m+1)×(n+1)]$的反置矩阵为${'}\mathcal{F}[(m+1)×(n+1)] ≡ \mathrm{rev} \mathcal{F}[(m+1)×(n+1)]$。

$\mathcal{H}[(n+1)×(m+1)] = {'}\mathcal{F}[(m+1)×(n+1)]$。

$$
\mathop{\left[\begin{matrix}
h_{n,0} & h_{n,1} & ⋯ & h_{n,m} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$h_{1,0}$} & h_{1,1} & ⋯ & h_{1,m} \\
h_{0,0} & \fbox{$h_{0,1}$} & ⋯ & h_{0,m} \\
\end{matrix}\right]}\limits_{(n+1)×(m+1)} \mathop{====}\limits^{h_{i,j}=f_{j,i} } \mathrm{rev} \mathop{\left[\begin{matrix}
f_{m,0} & f_{m,1} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{1,0}$} & f_{1,1} & ⋯ & f_{1,n} \\
f_{0,0} & \fbox{$f_{0,1}$} & ⋯ & f_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} = \mathop{\left[\begin{matrix}
f_{0,n} & f_{1,n} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{0,1}$} & f_{1,1} & ⋯ & f_{m,1} \\
f_{0,0} & \fbox{$f_{1,0}$} & ⋯ & f_{m,0} \\
\end{matrix}\right]}\limits_{(n+1)×(m+1)}
$$

矩阵$\mathcal{G}[(m+1)×(n+1)]$与矩阵$\mathcal{F}[(m+1)×(n+1)]$的位加运算。

$\mathcal{H}[(m+1)×(n+1)] = \mathcal{G}[(m+1)×(n+1)] + \mathcal{F}[(m+1)×(n+1)]$。

$$
\mathop{\left[\begin{matrix}
h_{m,0} & h_{m,1} & ⋯ & h_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$h_{1,0}$} & \fbox{$h_{1,1}$} & ⋯ & \fbox{$h_{1,n}$} \\
h_{0,0} & h_{0,1} & ⋯ & h_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} \mathop{======}\limits^{h_{i,j}=f_{i,j}+g_{i,j} } \mathop{\left[\begin{matrix}
g_{m,0} & g_{m,1} & ⋯ & g_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$g_{1,0}$} & \fbox{$g_{1,1}$} & ⋯ & \fbox{$g_{1,n}$} \\
g_{0,0} & g_{0,1} & ⋯ & g_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} + \mathop{\left[\begin{matrix}
f_{m,0} & f_{m,1} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{1,0}$} & \fbox{$f_{1,1}$} & ⋯ & \fbox{$f_{1,n}$} \\
f_{0,0} & f_{0,1} & ⋯ & f_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} = \mathop{\left[\begin{matrix}
g_{m,0}+f_{m,0} & g_{m,1}+f_{m,1} & ⋯ & g_{m,n}+f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$g_{1,0}+f_{1,0}$} & \fbox{$g_{1,1}+f_{1,1}$} & ⋯ & \fbox{$g_{1,n}+f_{1,n}$} \\
g_{0,0}+f_{0,0} & g_{0,1}+f_{0,1} & ⋯ & g_{0,n}+f_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)}
$$

矩阵$\mathcal{G}[(l+1)×(m+1)]$与矩阵$\mathcal{F}[(m+1)×(n+1)]$的合乘运算。

$\mathcal{H}[(l+1)×(n+1)] = \mathcal{G}[(l+1)×(m+1)] \rlap{×}{+} \mathcal{F}[(m+1)×(n+1)]$

$$
\mathop{\left[\begin{matrix}
h_{l,0} & h_{l,1} & ⋯ & h_{l,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$h_{1,0}$} & h_{1,1} & ⋯ & h_{1,n} \\
h_{0,0} & h_{0,1} & ⋯ & h_{0,n} \\
\end{matrix}\right]}\limits_{(l+1)×(n+1)} \mathop{========}\limits^{h_{i,j}=\sum\limits_{k=0}^{m} g_{i,k}·f_{k,j} } \mathop{\left[\begin{matrix}
g_{l,0} & g_{l,1} & ⋯ & g_{l,m} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$g_{1,0}$} & \fbox{$g_{1,1}$} & ⋯ & \fbox{$g_{1,m}$} \\
g_{0,0} & g_{0,1} & ⋯ & g_{0,m} \\
\end{matrix}\right]}\limits_{(l+1)×(m+1)} \rlap{×}{+} \mathop{\left[\begin{matrix}
\fbox{$f_{m,0}$} & f_{m,1} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{1,0}$} & f_{1,1} & ⋯ & f_{1,n} \\
\fbox{$f_{0,0}$} & f_{0,1} & ⋯ & f_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} = \mathop{\left[\begin{matrix}
\sum\limits_{k=0}^{m} g_{l,k} · f_{k,0} & \sum\limits_{k=0}^{m} g_{l,k} · f_{k,1} & ⋯ & \sum\limits_{k=0}^{m} g_{l,k} · f_{k,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$\sum\limits_{k=0}^{m} g_{1,k} · f_{k,0}$} & \sum\limits_{k=0}^{m} g_{1,k} · f_{k,1} & ⋯ & \sum\limits_{k=0}^{m} g_{1,k} · f_{k,n} \\
\sum\limits_{k=0}^{m} g_{0,k} · f_{k,0} & \sum\limits_{k=0}^{m} g_{0,k} · f_{k,1} & ⋯ & \sum\limits_{k=0}^{m} g_{0,k} · f_{k,n} \\
\end{matrix}\right]}\limits_{(l+1)×(n+1)}
$$

二元关系$\mathcal{G}[Z×Y]$与二元关系$\mathcal{F}[Y×X]$的复合关系$\mathcal{H}[Z×X]$。

$\mathcal{H}[Z×X] = \mathcal{G}[Z×Y] ∘ \mathcal{F}[Y×X]$

### 多项式分解

$$
9·x^3 + 30·x^2 + 42·x^1 + 26 = 9·(x+1)^3 + 3·(x+1)^2 + 9·(x+1)^1 + 5 \\

\begin{array}{l|l|l|l}
\hline
÷ (x+1) & 9·x^3 + 30·x^2 + 42·x^1 + 26                                            & = 9·x^2 + 21·x^1 + 21                                             & = 9·x^1 + 12 & = 9 \\
        & 9·x^3 + \ \ 9·x^2                                                       & \ \ \ \ 9·x^2 + \ \ 9·x^1                                         & \ \ \ \ 9·x^1 + \ \ 9 \\
\hline
        & \ \ \ \ \ \ \ \ \ \ \ \ \ \ 21·x^2 + 42·x^1                             & \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ 12·x^1 + 21                   & \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ 3 \\
        & \ \ \ \ \ \ \ \ \ \ \ \ \ \ 21·x^2 + 21·x^1                             & \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \  12·x^1 + 12 \\
\hline
        & \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ 21·x^1 + 26 & \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ 9 \\
        & \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ 21·x^1 + 21 \\
\hline
        & \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ 5 \\
\hline
\end{array}
$$

### 基向量的运算性质

若无特别的规定，约定基向量指单位基向量而非规范基向量。示例：$3$维空间单位基向量之一$\vec{η}_{1} ≡ \left[\begin{matrix} 0 \\ 1 \\ 0 \end{matrix}\right]$，$4$维空间规范基向量之一$\vec{n} = \dfrac{1}{\sqrt{3}} · \left[\begin{matrix} 1 \\ 1 \\ 1 \end{matrix}\right]$。

若无特别的规定，约定全基向量指所有单位基向量之位加运算的和。示例：$3$维空间全基向量$\vec{η}_{+} ≡ \left[\begin{matrix} 1 \\ 1 \\ 1 \end{matrix}\right]$。

$n+1$元基向量的点乘运算。
$$
\begin{aligned}
\vec{η}_{i} \odot_{n+1} \vec{η}_{j} &\mathop{==}\limits^{i≡j} 1 & \vec{η}_{i} &∥ \vec{η}_{i} \\
\vec{η}_{i} \odot_{n+1} \vec{η}_{j} &\mathop{==}\limits^{i<j} 0 & \vec{η}_{i} &⊥ \vec{η}_{j} \\
\vec{η}_{j} \odot_{n+1} \vec{η}_{i} &\mathop{==}\limits^{j>i} 0 & \vec{η}_{j} &⊥ \vec{η}_{i} \\
\end{aligned}
$$

$$
\begin{aligned}
\vec{η}_{0} \odot_{2} \vec{η}_{1} &= 0 & \vec{η}_{1} \odot_{2} \vec{η}_{0} &= 0 \\
\vec{η}_{0} \odot_{3} \vec{η}_{1} &= 0 & \vec{η}_{1} \odot_{3} \vec{η}_{0} &= 0 \\
\vec{η}_{0} \odot_{4} \vec{η}_{1} &= 0 & \vec{η}_{1} \odot_{4} \vec{η}_{0} &= 0 \\
\end{aligned}
$$

$n+1$元基向量的叉乘运算。约定$\dfrac{\vec{0}}{|\vec{0}|} = \vec{0}$。

$$
\begin{aligned}
\vec{η}_{i} \otimes_{n+1} \vec{η}_{j} &\mathop{==}\limits^{i≡j} \vec{0} & \left| \vec{η}_{i} \otimes \vec{η}_{j} \right| &= 1 \\
\vec{η}_{i} \otimes_{n+1} \vec{η}_{j} &\mathop{==}\limits^{i<j} +\dfrac{\vec{η}_{+} - (\vec{η}_{i} + \vec{η}_{j})}{\left| \vec{η}_{+} - (\vec{η}_{i} + \vec{η}_{j}) \right|} & \left( \vec{η}_{i} \otimes \vec{η}_{j} \right) &⊥ \vec{η}_{i} \\
\vec{η}_{j} \otimes_{n+1} \vec{η}_{i} &\mathop{==}\limits^{j>i} -\dfrac{\vec{η}_{+} - (\vec{η}_{i} + \vec{η}_{j})}{\left| \vec{η}_{+} - (\vec{η}_{i} + \vec{η}_{j}) \right|} & \left( \vec{η}_{i} \otimes \vec{η}_{j} \right) &⊥ \vec{η}_{j} \\
\end{aligned}
$$

$$
\begin{aligned}
\vec{η}_{0} \otimes_{2} \vec{η}_{1} &= +\dfrac{\vec{0}}{|\vec{0}|} = +\vec{0} & \vec{η}_{1} \otimes_{2} \vec{η}_{0} &= -\dfrac{\vec{0}}{|\vec{0}|} = -\vec{0} \\
\vec{η}_{0} \otimes_{3} \vec{η}_{1} &= +\dfrac{\vec{η}_{2}}{|\vec{η}_{2}|} = +\vec{η}_{2} & \vec{η}_{1} \otimes_{3} \vec{η}_{0} &= -\dfrac{\vec{η}_{2}}{|\vec{η}_{2}|} = -\vec{η}_{2} \\
\vec{η}_{0} \otimes_{4} \vec{η}_{1} &= +\dfrac{\vec{η}_{2} + \vec{η}_{3}}{|\vec{η}_{2} + \vec{η}_{3}|} = +\dfrac{\vec{η}_{2} + \vec{η}_{3}}{\sqrt{2}} & \vec{η}_{1} \otimes_{4} \vec{η}_{0} &= -\dfrac{\vec{η}_{2} + \vec{η}_{3}}{|\vec{η}_{2} + \vec{η}_{3}|} = -\dfrac{\vec{η}_{2} + \vec{η}_{3}}{\sqrt{2}} \\
\end{aligned}
$$

### 矩阵的运算性质

若无特别的规定，约定矩阵指行矩阵而非列矩阵，行矩阵与列矩阵互为反置。

$$
\begin{aligned}
\mathrm{A}_{(m+1)×(n+1)} &= \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} \\
{'}\mathrm{A}_{(m+1)×(n+1)} &= \mathop{\left[\begin{matrix}
a_{0,n} & a_{1,n} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{0,1} & a_{1,1} & ⋯ & a_{m,1} \\
a_{0,0} & a_{1,0} & ⋯ & a_{m,0} \\
\end{matrix}\right]}\limits_{(n+1)×(m+1)} \\
\end{aligned}
$$

单位$(n+1)×(n+1)$元矩阵。

$$
\mathrm{I}_{(n+1)×(n+1)} = \mathop{\left[\begin{matrix}
0 & 0 & ⋯ & 1 \\
⋮ & ⋮ & ⋰ & ⋮ \\
0 & 1 & ⋯ & 0 \\
1 & 0 & ⋯ & 0 \\
\end{matrix}\right]}\limits_{(n+1)×(n+1)}
$$

标量与$(m+1)×(n+1)$元矩阵的量加运算。矩阵的量加运算必满足交换律。

$$
\mathop{\left[\begin{matrix}
c + a_{m,0} & c + a_{m,1} & ⋯ & c + a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
c + a_{1,0} & c + a_{1,1} & ⋯ & c + a_{1,n} \\
c + a_{0,0} & c + a_{0,1} & ⋯ & c + a_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} = c \oplus \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)}
$$

$(m+1)×(n+1)$元矩阵与$(m+1)×(n+1)$元矩阵的位加运算。矩阵的位加运算必满足交换律。矩阵的位加运算必满足结合律。

$$
\mathop{\left[\begin{matrix}
b_{m,0} + a_{m,0} & b_{m,1} + a_{m,1} & ⋯ & b_{m,n} + a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} + a_{1,0} & b_{1,1} + a_{1,1} & ⋯ & b_{1,n} + a_{1,n} \\
b_{0,0} + a_{0,0} & b_{0,1} + a_{0,1} & ⋯ & b_{0,n} + a_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} = \mathop{\left[\begin{matrix}
b_{m,0} & b_{m,1} & ⋯ & b_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} & b_{1,1} & ⋯ & b_{1,n} \\
b_{0,0} & b_{0,1} & ⋯ & b_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} + \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)}
$$

标量与$(m+1)×(n+1)$元矩阵的量乘运算。矩阵的量乘运算必满足交换律。

$$
\mathop{\left[\begin{matrix}
c · a_{m,0} & c · a_{m,1} & ⋯ & c · a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
c · a_{1,0} & c · a_{1,1} & ⋯ & c · a_{1,n} \\
c · a_{0,0} & c · a_{0,1} & ⋯ & c · a_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} = c · \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)}
$$

$(m+1)×(n+1)$元矩阵与$(m+1)×(n+1)$元矩阵的点乘运算。矩阵的点乘运算满足必交换律。

$$
\sum\limits_{i=0}^{m} \sum\limits_{j=0}^{n} b_{i,j} · a_{i,j} = \mathop{\left[\begin{matrix}
b_{m,0} & b_{m,1} & ⋯ & b_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} & b_{1,1} & ⋯ & b_{1,n} \\
b_{0,0} & b_{0,1} & ⋯ & b_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} \odot \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)}
$$

$(m+1)×(n+1)$元矩阵与$(m+1)×(n+1)$元矩阵的位乘运算。矩阵的位乘运算必满足交换律。矩阵的位乘运算必满结合律。

$$
\mathop{\left[\begin{matrix}
b_{m,0} · a_{m,0} & b_{m,1} · a_{m,1} & ⋯ & b_{m,n} · a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} · a_{1,0} & b_{1,1} · a_{1,1} & ⋯ & b_{1,n} · a_{1,n} \\
b_{0,0} · a_{0,0} & b_{0,1} · a_{0,1} & ⋯ & b_{0,n} · a_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} = \mathop{\left[\begin{matrix}
b_{m,0} & b_{m,1} & ⋯ & b_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} & b_{1,1} & ⋯ & b_{1,n} \\
b_{0,0} & b_{0,1} & ⋯ & b_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} × \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)}
$$

$(l+1)*(m+1)$元矩阵与$(m+1)×(n+1)$元矩阵的合乘运算。矩阵的合乘运算不满足交换律。矩阵的合乘运算必满足结合律。

$$
\mathop{\left[\begin{matrix}
\sum\limits_{k=0}^{m} b_{l,k} · a_{k,0} & \sum\limits_{k=0}^{m} b_{l,k} · a_{k,1} & ⋯ & \sum\limits_{k=0}^{m} b_{l,k} · a_{k,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\sum\limits_{k=0}^{m} b_{1,k} · a_{k,0} & \sum\limits_{k=0}^{m} b_{1,k} · a_{k,1} & ⋯ & \sum\limits_{k=0}^{m} b_{1,k} · a_{k,n} \\
\sum\limits_{k=0}^{m} b_{0,k} · a_{k,0} & \sum\limits_{k=0}^{m} b_{0,k} · a_{k,1} & ⋯ & \sum\limits_{k=0}^{m} b_{0,k} · a_{k,n} \\
\end{matrix}\right]}\limits_{(l+1)×(n+1)} = \mathop{\left[\begin{matrix}
b_{l,0} & b_{l,1} & ⋯ & b_{l,m} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} & b_{1,1} & ⋯ & b_{1,m} \\
b_{0,0} & b_{0,1} & ⋯ & b_{0,m} \\
\end{matrix}\right]}\limits_{(l+1)×(m+1)} \rlap{×}{+} \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)}
$$

$$
\begin{aligned}
\mathrm{D}_{(k+1)×(n+1)} &= \mathrm{C}_{(k+1)×(l+1)} \rlap{×}{+} \left[ \mathrm{B}_{(l+1)×(m+1)} \rlap{×}{+} \mathrm{A}_{(m+1)×(n+1)} \right] \\
\mathrm{D}_{(k+1)×(n+1)} &= \left[ \mathrm{C}_{(k+1)×(l+1)} \rlap{×}{+} \mathrm{B}_{(l+1)×(m+1)} \right] \rlap{×}{+} \mathrm{A}_{(m+1)×(n+1)} \\
c(ba)_{q,t} &= \sum\limits_{r=0}^{l} c_{q,r} · \left[ \sum\limits_{s=0}^{m} b_{r,s} · a_{s,t} \right] = \sum\limits_{r=0}^{l} \sum\limits_{s=0}^{m} c_{q,r} · b_{r,s} · a_{s,t} \\
(cb)a_{q,t}&= \sum\limits_{s=0}^{m} \left[ \sum\limits_{r=0}^{l} c_{q,r} · b_{r,s} \right] · a_{s,t} = \sum\limits_{r=0}^{l} \sum\limits_{s=0}^{m} c_{q,r} · b_{r,s} · a_{s,t} \\
\end{aligned}
$$

$$
\begin{aligned}
\mathrm{C}_{(l+1)×(n+1)} &= \mathrm{B}_{(l+1)×(m+1)} \rlap{×}{+} \mathrm{A}_{(m+1)×(n+1)} \\
{'}\mathrm{C}_{(l+1)×(n+1)} &= {'}\mathrm{a}_{(m+1)×(n+1)} \rlap{×}{+} {'}\mathrm{B}_{(l+1)×(m+1)} \\
ba_{r,t} &= \sum\limits_{s=0}^{m} b_{r,s} · a_{s,t} \\
ab_{t,r} &= \sum\limits_{s=0}^{m} a_{t,s} · b_{s,r} \\
\end{aligned}
$$

$$
\begin{aligned}
\mathrm{C}_{(l+1)×(n+1)} &= \mathrm{B}_{(l+1)×(m+1)} \rlap{×}{+} \mathrm{A}_{(m+1)×(n+1)} \\
{^\imath}\mathrm{C}_{(l+1)×(n+1)} &= {^\imath}\mathrm{A}_{(m+1)×(n+1)} \rlap{×}{+} {^\imath}\mathrm{B}_{(l+1)×(m+1)} \\
\mathrm{I}_{(l+1)×(l+1)} &= \mathrm{B}_{(l+1)×(m+1)} \rlap{×}{+} \mathrm{A}_{(m+1)×(n+1)} \rlap{×}{+} {^\imath}\mathrm{A}_{(m+1)×(n+1)} \rlap{×}{+} {^\imath}\mathrm{B}_{(l+1)×(m+1)} \\
\end{aligned}
$$

$(m+1)×(n+1)$元矩阵的度量值。矩阵的度量值值为其自身之点乘运算的方根值。

$$
\left[ \sum\limits_{i=0}^{m} \sum\limits_{j=0}^{n} a_{i,j}^2 \right]^{\frac{1}{2}} = \mathop{\left|\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right|}\limits_{(m+1)×(n+1)} ≡ \mathrm{sqrt} \left( \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} \odot \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(m+1)×(n+1)} \right)
$$

$(n+1)×(n+1)$元矩阵的行列式。

$$
\mathop{\left\Vert\begin{matrix}
a_{n,0} & a_{n,1} & ⋯ & a_{n,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right\Vert}\limits_{(n+1)×(n+1)} = \sum\limits_{k_0,k_1,⋯,k_n} \mathrm{sgn}(k_0, k_1, ⋯, k_n) · a_{0,k_0} · a_{1,k_1} ⋯ a_{n,k_n} \\
$$

### 向量的运算性质

若无特别的规定，约定向量指列向量而非行向量，列向量与行向量互为反置。

$$
\begin{aligned}
\vec{v} &= \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] \\
{^r}\vec{v} &= \left[\begin{matrix}
v_0, v_1, ⋯, v_n \\
\end{matrix}\right]
\end{aligned}
$$

标量与$n+1$元向量的量加运算。向量的量加运算必满足交换律。

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

$n+1$元向量与$n+1$元向量的位加运算。向量的位加运算必满足交换律。向量的位加运算必满足结合律。

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

标量与$n+1$元向量的量乘运算。向量的量乘运算必满足交换律。

$$
\left[\begin{matrix}
c · v_n \\
⋮ \\
c · v_1 \\
c · v_0 \\
\end{matrix}\right] = c · \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] = \mathop{\left[\begin{matrix}
0 & 0 & ⋯ & c \\
⋮ & ⋮ & ⋰ & ⋮ \\
0 & c & ⋯ & 0 \\
c & 0 & ⋯ & 0 \\
\end{matrix}\right]}\limits_{(n+1)×(n+1)} \rlap{×}{+} \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right]
$$

$n+1$元向量与$n+1$元向量的点乘运算。向量的点乘运算必满足交换律。

$$
\begin{aligned}
|\vec{u}| · |\vec{v}| · \cos \ang(\vec{u},\vec{v}) &= \left[\begin{matrix}
u_n \\
⋮ \\
u_1 \\
u_0 \\
\end{matrix}\right] \odot \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] ≡ (\vec{η}_0 · u_0 + \vec{η}_1 · u_1 + ⋯ + \vec{η}_n · u_n) \odot (\vec{η}_0 · v_0 + \vec{η}_1 · v_1 + ⋯ + \vec{η}_n · v_n) \\
\sum\limits_{k=0}^{n} u_k · v_k  &= \left[\begin{matrix}
u_n \\
⋮ \\
u_1 \\
u_0 \\
\end{matrix}\right] \odot \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] = \left[\begin{matrix}
u_0 & u_1 & ⋯ & u_n \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] \\
\end{aligned}
$$

$n+1$元向量与$n+1$元向量的位乘运算。向量的位乘运算必满足交换律。向量的位乘运算必满足结合律。

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
\end{matrix}\right] = \mathop{\left[\begin{matrix}
0 & 0 & ⋯ & u_n \\
⋮ & ⋮ & ⋰ & ⋮ \\
0 & u_1 & ⋯ & 0 \\
u_0 & 0 & ⋯ & 0 \\
\end{matrix}\right]}\limits_{(n+1)×(n+1)} \rlap{×}{+} \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right]
$$

$n+1$元向量与$n+1$元向量的叉乘运算。向量的叉乘运算不满足交换律。向量的叉乘运算不满足结合律。

$$
\begin{aligned}
\vec{n}_{\vec{u}\otimes\vec{v}} · |\vec{u}| · |\vec{v}| · \sin \ang(\vec{u},\vec{v}) &= \left[\begin{matrix}
u_n \\
⋮ \\
u_1 \\
u_0 \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] ≡ (\vec{η}_0 · u_0 + \vec{η}_1 · u_1 + ⋯ + \vec{η}_n · u_n) \otimes (\vec{η}_0 · v_0 + \vec{η}_1 · v_1 + ⋯ + \vec{η}_n · v_n) \\
\dfrac{1}{\sqrt{n - 1}} · \left[\begin{matrix}
\sum\limits_{i=0;\rlap{≡}{n}}^{n} \sum\limits_{j=0;\rlap{≡}{n}}^{n} [\mathrm{sgn}(j-i) · u_i · v_j] \\
⋮ \\
\sum\limits_{i=0;\rlap{≡}{1}}^{n} \sum\limits_{j=0;\rlap{≡}{1}}^{n} [\mathrm{sgn}(j-i) · u_i · v_j] \\
\sum\limits_{i=0;\rlap{≡}{0}}^{n} \sum\limits_{j=0;\rlap{≡}{0}}^{n} [\mathrm{sgn}(j-i) · u_i · v_j] \\
\end{matrix}\right] &= \left[\begin{matrix}
u_n \\
⋮ \\
u_1 \\
u_0 \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] = \dfrac{1}{\sqrt{n - 1}} · \mathop{\left[\begin{matrix}
\sum\limits_{i=0;\rlap{≡}{n}}^{n} [\mathrm{sgn}(0-i) · u_i] & \sum\limits_{i=0;\rlap{≡}{n}}^{n} [\mathrm{sgn}(1-i) · u_i] & ⋯ & 0 \\
⋮ & ⋮ & ⋰ & ⋮ \\
\sum\limits_{i=0;\rlap{≡}{1}}^{n} [\mathrm{sgn}(0-i) · u_i] & 0 & ⋯ & \sum\limits_{i=0;\rlap{≡}{1}}^{n} [\mathrm{sgn}(n-i) · u_i] \\
0 & \sum\limits_{i=0;\rlap{≡}{0}}^{n} [\mathrm{sgn}(1-i) · u_i] & ⋯ & \sum\limits_{i=0;\rlap{≡}{0}}^{n} [\mathrm{sgn}(n-i) · u_i] \\
\end{matrix}\right]}\limits_{(n+1)×(n+1)} \rlap{×}{+} \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] \\
\end{aligned}
$$

$3$元向量与$3$元向量的叉乘运算。向量的叉乘运算不满足结合律。

$$
\begin{aligned}
\vec{n}_{\vec{u}\otimes\vec{v}} · |\vec{u}| · |\vec{v}| · \sin \ang(\vec{u},\vec{v}) &= \left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] = (\vec{η}_x · u_x + \vec{η}_y · u_y + \vec{η}_z · u_z) \otimes (\vec{η}_x · v_x + \vec{η}_y · v_y + \vec{η}_z · v_z) \\
\left\Vert\begin{matrix}
\vec{η}_z & u_z & v_z \\
\vec{η}_y & u_y & v_y \\
\vec{η}_x & u_x & v_x \\
\end{matrix}\right\Vert = \left[\begin{matrix}
u_x · v_y - u_y · v_x \\
u_z · v_x - u_x · v_z \\
u_y · v_z - u_z · v_y \\
\end{matrix}\right] &= \left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] = \mathop{\left[\begin{matrix}
-u_y & +u_x & 0 \\
+u_z & 0 & -u_x \\
0 & -u_z & +u_y \\
\end{matrix}\right]}\limits_{3×3} \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\end{aligned}
$$

$n+1$元向量的度量值。向量的度量值为其自身之点乘运算的方根值。

$$
\left[ \sum\limits_{i=0}^{n} v_{i}^2 \right]^{\frac{1}{2}} = \left|\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right| ≡ \mathrm{sqrt} \left( \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] \odot \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] \right)
$$

### 向量的二重乘运算

$3$元向量的混合叉点乘运算。

$$
\begin{aligned}
\left[\begin{matrix}
t_z \\
t_y \\
t_x \\
\end{matrix}\right] \odot \left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] &= \left[\begin{matrix}
t_z \\
t_y \\
t_x \\
\end{matrix}\right] \odot \left[\begin{matrix}
u_x · v_y - u_y · v_x \\
u_z · v_x - u_x · v_z \\
u_y · v_z - u_z · v_y \\
\end{matrix}\right] = \left\Vert\begin{matrix}
t_z & u_z & v_z \\
t_y & u_y & v_y \\
t_x & u_x & v_x \\
\end{matrix}\right\Vert \\
&= (t_y · u_z - t_z · u_y) · v_x + (t_z · u_x - t_x · u_z) · v_y + (t_x · u_y - t_y · u_x) · v_z \\
&= \left[\begin{matrix}
(t_y · u_z - t_z · u_y) & (t_z · u_x - t_x · u_z) & (t_x · u_y - t_y · u_x) \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\end{aligned}
$$

$3$元向量的任意叉叉乘运算。向量的任意叉叉乘运算不满足结合律。

$$
\begin{aligned}
\left(\left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right]\right) \otimes \left[\begin{matrix}
p_z \\
p_y \\
p_x \\
\end{matrix}\right] &= \left[\begin{matrix}
q_x · v_y - q_y · v_x \\
q_z · v_x - q_x · v_z \\
q_y · v_z - q_z · v_y \\
\end{matrix}\right] \otimes \left[\begin{matrix}
p_z \\
p_y \\
p_x \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
(q_y · v_z - q_z · v_y) · p_y - (q_z · v_x - q_x · v_z) · p_x \\
(q_x · v_y - q_y · v_x) · p_x - (q_y · v_z - q_z · v_y) · p_z \\
(q_z · v_x - q_x · v_z) · p_z - (q_x · v_y - q_y · v_x) · p_y \\
\end{matrix}\right] = \left[\begin{matrix}
-q_z · p_x · v_x - q_z · p_y · v_y + (q_x · p_x + q_y · p_y) · v_z \\
-q_y · p_x · v_x + (q_x · p_x + q_z · p_z) · v_y - q_y · p_z · v_z \\
+(q_z · p_z + q_y · p_y) · v_x - q_x · p_y · v_y - q_x · p_z · v_z \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
-q_z · p_x & -q_z · p_y & (q_x · p_x + q_y · p_y) \\
-q_y · p_x & (q_z · p_z + q_x · p_x) & -q_y · p_z \\
(q_y · p_y + q_z · p_z) & -q_x · p_y & -q_x · p_z \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\end{aligned}
$$

$$
\begin{aligned}
\left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \otimes \left(\left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
p_z \\
p_y \\
p_x \\
\end{matrix}\right]\right) &= \left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_x · p_y - v_y · p_x \\
v_z · p_x - v_x · p_z \\
v_y · p_z - v_z · p_y \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
q_x · (v_z · p_x - v_x · p_z) - q_y · (v_y · p_z - v_z · p_y) \\
q_z · (v_y · p_z - v_z · p_y) - q_x · (v_x · p_y - v_y · p_x) \\
q_y · (v_x · p_y - v_y · p_x) - q_z · (v_z · p_x - v_x · p_z) \\
\end{matrix}\right] = \left[\begin{matrix}
-q_x · p_z · v_x - q_y · p_z · v_y + (q_x · p_x + q_y · p_y) · v_z \\
-q_x · p_y · v_x + (q_x · p_x + q_z · p_z) · v_y - q_z · p_y · v_z \\
+(q_y · p_y + q_z · p_z) · v_x - q_y · p_x · v_y - q_z · p_x · v_z \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
-q_x · p_z & -q_y · p_z & (q_x · p_x + q_y · p_y) \\
-q_x · p_y & (q_z · p_z + q_x · p_x) & -q_z· p_y \\
(q_y · p_y + q_z · p_z) & -q_y · p_x & q_z · p_x \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\end{aligned}
$$

$3$元向量的对称叉叉乘运算。向量的对称叉叉乘运算必满足结合律。

$$
\begin{aligned}
\left[\begin{matrix}
+q_z \\
+q_y \\
+q_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
+q_z \\
+q_y \\
+q_x \\
\end{matrix}\right] &= \mathop{\left[\begin{matrix}
-q_z · q_x & -q_y · q_z & +(q_x^2 + q_y^2) \\
-q_x · q_y & +(q_z^2 + q_x^2) & -q_y · q_z \\
+(q_y^2 + q_z^2) & -q_x · q_y & -q_z · q_x \\
\end{matrix}\right]}\limits_{3×3} \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\end{aligned}
$$

$3$元向量的逆称叉叉乘运算。向量的逆称叉叉乘运算必满足结合律。

$$
\begin{aligned}
\left[\begin{matrix}
+q_z \\
+q_y \\
+q_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
-q_z \\
-q_y \\
-q_x \\
\end{matrix}\right] &= \mathop{\left[\begin{matrix}
+q_z · q_x & +q_y · q_z & -(q_x^2 + q_y^2) \\
+q_x · q_y & -(q_z^2 + q_x^2) & +q_y · q_z \\
-(q_y^2 + q_z^2) & +q_x · q_y & +q_z · q_x \\
\end{matrix}\right]}\limits_{3×3} \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\end{aligned}
$$

$3$元向量的对称点量乘运算。

$$
\begin{aligned}
\left(\left[\begin{matrix}
r_z \\
r_y \\
r_x \\
\end{matrix}\right] \odot \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right]\right) · \left[\begin{matrix}
r_z \\
r_y \\
r_x \\
\end{matrix}\right] &= (r_x · v_x + r_y · v_y + r_z · v_z) · \left[\begin{matrix}
r_z \\
r_y \\
r_x \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
r_z · r_x · v_x + r_y · r_z · v_y + r_z^2 · v_z \\
r_x · r_y · v_x + r_y^2 · v_y + r_y · r_z · v_z \\
r_x^2 · v_x + r_x · r_y · v_y + r_z · r_x · v_z \\
\end{matrix}\right] \\
&= \mathop{\left[\begin{matrix}
r_z · r_x & r_y · r_z & r_z^2 \\
r_x · r_y & r_y^2 & r_y · r_z \\
r_x^2 & r_x · r_y & r_z · r_x \\
\end{matrix}\right]}\limits_{3×3} \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\end{aligned}
$$
