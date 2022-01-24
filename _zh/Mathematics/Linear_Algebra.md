---
layout:  zh_post
Topic :  收敛极限
Title :  线性代数
Update:  2022-01-24T20:52:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 特别注意

```
本书中矩阵的定义与教科书不同。
本书中矩阵以左下右上为对角线。
本书中对矩阵的反置为Reverse，而非转置Transpose，其符号为'A而非Aᵀ。
本书中对矩阵的倒逆为Inverse，其符号为ᶥA而非A⁻¹。
本书中坐标系均为右手旋坐标系。
本书中共有2种加运算5种乘运算。
本书中矩阵的行列式为Determinant，其符号为║A║。
本书中矩阵的度量值为Measurement，其符号为│A│。
度量值Measurement是拓扑值Topologee的二次方情形。约定Topologee表示拓扑距或者拓扑值。
本书中向量由标量与矢量共同构成，向量的第0位表示其标量分量，矢量的第0位表示其ηₓ分量。约定向量的英文单词为Vector，矢量的英文单词为vector。
本书中基向量的符号为𝛈，基矢量的符号为ῆ，基矢量下标移位1为其对应的基向量下标，𝛈₁≡ῆ₀。
约定向量的书写体为粗体无箭头𝐯，矢量的书写体为细体有箭头ṽ。约定矩阵的书写体为大写英文字母，向量的书写体为小写英文字母。
本书中向量与矢量最明显的不同之处在于，向量未定义叉乘运算，矢量有定义叉乘运算，向量与矢量的其它常规的运算性质基本相通。
本书中认为3维矢量内嵌于4维向量，因此3维矢量空间内嵌于4维向量空间，且第0维向量较特殊。
```

$n$元$m$量线性代数方程组的最典型定义。
$$
\left[\begin{matrix}
y_1 \\
y_2 \\
⋮ \\
y_m \\
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

$(1 + n)$元$(1 + m)$量线性代数方程组的现定义。

$$
\left[\begin{matrix}
y_m \\
⋮ \\
y_1 \\
y_0 \\
\end{matrix}\right] = \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} \rlap{×}{+} \left[\begin{matrix}
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

$(1+m)×(1+n)$元矩阵的坐标，行数为$1+m$，列数为$1+n$。

$$
\mathop{\left[\begin{matrix}
\langle m, 0 \rangle & \langle m, 1 \rangle & → & \langle m, n \rangle \\
↑ & ↑ & ↗ & ↑ \\
\langle 1, 0 \rangle & \langle 1, 1 \rangle & → & \langle 1, n \rangle \\
\langle 0, 0 \rangle & \langle 0, 1 \rangle & → & \langle 0, n \rangle \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)}
$$

$(1+n)×(1+n)$元方矩阵的单位方矩阵，对角线为左下右上。

$$
\mathop{\left[\begin{matrix}
0 & 0 & ⋯ & 1 \\
⋮ & ⋮ & ⋰ & ⋮ \\
0 & 1 & ⋯ & 0 \\
1 & 0 & ⋯ & 0 \\
\end{matrix}\right]}\limits_{(1+n)×(1+n)}
$$

### 矩阵的运算

矩阵的运算遵循的原则：行优先于列，单行从左往右，单列从下往上。向左复合，向右运算。

矩阵$\mathcal{F}[(1+m)×(1+n)]$的反置矩阵为${'}\mathcal{F}[(1+m)×(1+n)] ≡ \mathrm{rev} \mathcal{F}[(1+m)×(1+n)]$。

$\mathcal{H}[(1+n)×(1+m)] = {'}\mathcal{F}[(1+m)×(1+n)]$。

$$
\mathop{\left[\begin{matrix}
h_{n,0} & h_{n,1} & ⋯ & h_{n,m} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$h_{1,0}$} & h_{1,1} & ⋯ & h_{1,m} \\
h_{0,0} & \fbox{$h_{0,1}$} & ⋯ & h_{0,m} \\
\end{matrix}\right]}\limits_{(1+n)×(1+m)} \mathop{====}\limits^{h_{i,j}=f_{j,i} } \mathrm{rev} \mathop{\left[\begin{matrix}
f_{m,0} & f_{m,1} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{1,0}$} & f_{1,1} & ⋯ & f_{1,n} \\
f_{0,0} & \fbox{$f_{0,1}$} & ⋯ & f_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} = \mathop{\left[\begin{matrix}
f_{0,n} & f_{1,n} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{0,1}$} & f_{1,1} & ⋯ & f_{m,1} \\
f_{0,0} & \fbox{$f_{1,0}$} & ⋯ & f_{m,0} \\
\end{matrix}\right]}\limits_{(1+n)×(1+m)}
$$

矩阵$\mathcal{G}[(1+m)×(1+n)]$与矩阵$\mathcal{F}[(1+m)×(1+n)]$的位加运算。

$\mathcal{H}[(1+m)×(1+n)] = \mathcal{G}[(1+m)×(1+n)] + \mathcal{F}[(1+m)×(1+n)]$。

$$
\mathop{\left[\begin{matrix}
h_{m,0} & h_{m,1} & ⋯ & h_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$h_{1,0}$} & \fbox{$h_{1,1}$} & ⋯ & \fbox{$h_{1,n}$} \\
h_{0,0} & h_{0,1} & ⋯ & h_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} \mathop{======}\limits^{h_{i,j}=f_{i,j}+g_{i,j} } \mathop{\left[\begin{matrix}
g_{m,0} & g_{m,1} & ⋯ & g_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$g_{1,0}$} & \fbox{$g_{1,1}$} & ⋯ & \fbox{$g_{1,n}$} \\
g_{0,0} & g_{0,1} & ⋯ & g_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} + \mathop{\left[\begin{matrix}
f_{m,0} & f_{m,1} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{1,0}$} & \fbox{$f_{1,1}$} & ⋯ & \fbox{$f_{1,n}$} \\
f_{0,0} & f_{0,1} & ⋯ & f_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} = \mathop{\left[\begin{matrix}
g_{m,0}+f_{m,0} & g_{m,1}+f_{m,1} & ⋯ & g_{m,n}+f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$g_{1,0}+f_{1,0}$} & \fbox{$g_{1,1}+f_{1,1}$} & ⋯ & \fbox{$g_{1,n}+f_{1,n}$} \\
g_{0,0}+f_{0,0} & g_{0,1}+f_{0,1} & ⋯ & g_{0,n}+f_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)}
$$

矩阵$\mathcal{G}[(l+1)×(1+m)]$与矩阵$\mathcal{F}[(1+m)×(1+n)]$的合乘运算。

$\mathcal{H}[(l+1)×(1+n)] = \mathcal{G}[(l+1)×(1+m)] \rlap{×}{+} \mathcal{F}[(1+m)×(1+n)]$

$$
\mathop{\left[\begin{matrix}
h_{l,0} & h_{l,1} & ⋯ & h_{l,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$h_{1,0}$} & h_{1,1} & ⋯ & h_{1,n} \\
h_{0,0} & h_{0,1} & ⋯ & h_{0,n} \\
\end{matrix}\right]}\limits_{(l+1)×(1+n)} \mathop{========}\limits^{h_{i,j}=\sum\limits_{k=0}^{m} g_{i,k}·f_{k,j} } \mathop{\left[\begin{matrix}
g_{l,0} & g_{l,1} & ⋯ & g_{l,m} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$g_{1,0}$} & \fbox{$g_{1,1}$} & ⋯ & \fbox{$g_{1,m}$} \\
g_{0,0} & g_{0,1} & ⋯ & g_{0,m} \\
\end{matrix}\right]}\limits_{(l+1)×(1+m)} \rlap{×}{+} \mathop{\left[\begin{matrix}
\fbox{$f_{m,0}$} & f_{m,1} & ⋯ & f_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$f_{1,0}$} & f_{1,1} & ⋯ & f_{1,n} \\
\fbox{$f_{0,0}$} & f_{0,1} & ⋯ & f_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} = \mathop{\left[\begin{matrix}
\sum\limits_{k=0}^{m} g_{l,k} · f_{k,0} & \sum\limits_{k=0}^{m} g_{l,k} · f_{k,1} & ⋯ & \sum\limits_{k=0}^{m} g_{l,k} · f_{k,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\fbox{$\sum\limits_{k=0}^{m} g_{1,k} · f_{k,0}$} & \sum\limits_{k=0}^{m} g_{1,k} · f_{k,1} & ⋯ & \sum\limits_{k=0}^{m} g_{1,k} · f_{k,n} \\
\sum\limits_{k=0}^{m} g_{0,k} · f_{k,0} & \sum\limits_{k=0}^{m} g_{0,k} · f_{k,1} & ⋯ & \sum\limits_{k=0}^{m} g_{0,k} · f_{k,n} \\
\end{matrix}\right]}\limits_{(l+1)×(1+n)}
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

------

### 线性代数方程组

$(1 + n)$元$(1 + m)$量线性代数方程组。当$y ≡ 0$时为齐次线性代数方程组，当$y \not≡ 0$时为非齐次线性方程组。

注意：线性代数方程组未必有解，零解$\bold{x} = \left[\begin{matrix} 0 \\ ⋮ \\ 0 \\ \end{matrix}\right]$必定是齐次线性方程组的解，并且必定不是非齐次线性方程组的解。

$$
\left[\begin{matrix}
y_m \\
⋮ \\
y_1 \\
y_0 \\
\end{matrix}\right] = \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} \rlap{×}{+} \left[\begin{matrix}
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

$(1 + n)$元$(1 + m)$量线性代数方程组的线性组合。注意：$κ = 0$并非特殊情形，$(1 + n)$元$(1 + m)$量线性代数方程组的解必定是其线性组合的解，反之不对。

$$
\begin{aligned}
\left[\begin{matrix}
κ_0 & κ_1 & ⋯ & κ_m \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
y_m \\
⋮ \\
y_1 \\
y_0 \\
\end{matrix}\right] &= \left[\begin{matrix}
κ_0 & κ_1 & ⋯ & κ_m \\
\end{matrix}\right] \rlap{×}{+} \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] \\
β = \left[\begin{matrix}
α_0 & α_1 & ⋯ & α_n \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] &= \left[\begin{matrix}
\sum\limits_{i=0}^{m} κ_i · a_{i,0} & \sum\limits_{i=0}^{m} κ_i · a_{i,1} & ⋯ & \sum\limits_{i=0}^{m} κ_i · a_{i,n} \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] \\
\end{aligned} \\
$$

线性代数方程组的同解变形。若$(1 + n)$元$(1 + r)$量线性代数方程组中的每个方程，全都是$(1 + n)$元$(1 + m)$量线性代数方程组的线性组合，并且反之亦然。

注意：线性代数方程组的同解变形满足加运算与乘运算封闭性，因此线性代数方程组的解对于其系数所在的数域封闭。

$$
\left[\begin{matrix}
β_r \\
⋮ \\
β_1 \\
β_0 \\
\end{matrix}\right] = \mathop{\left[\begin{matrix}
α_{r,0} & α_{r,1} & ⋯ & α_{r,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
α_{1,0} & α_{1,1} & ⋯ & α_{1,n} \\
α_{0,0} & α_{0,1} & ⋯ & α_{0,n} \\
\end{matrix}\right]}\limits_{(1+r)×(1+n)} \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] \\
$$

```
线性代数方程组同解变形的初等行变换，共计4个。注意：原方程组与现方程组中方程的个数未必相同。
[规整阶梯形] 对于线性代数方程组，交换任意两个方程的位置，其余方程不变，方程的个数不变。〈j〉⇆〈i〉
[系数化为一] 对于线性代数方程组，将非零常数乘以任一方程，其余方程不变，方程的个数不变。〈i〉·κ
[消去相同元] 对于线性代数方程组，将任一方程加到另一方程，其余方程不变，方程的个数不变。〈j〉⩲〈i〉·κ
[消去恒等式] 对于线性代数方程组，将所有恒等式方程都剔除，其余方程不变，方程的个数改变。
线性代数方程组同解变形的初等列变换，共计1个。
[规整对角形] 对于线性代数方程组，交换任意两个变元的位置，其余变元不变，方程的个数不变。
```

线性代数方程组经过初等行变换的同解变形，最终形成阶梯形矩阵，然后经过初等列变换的同解变形，最终形成对角形矩阵。

$$
\begin{aligned}
\left[\begin{matrix}
0 \\
⋮ \\
β_{r+1} \\
β_r \\
⋮ \\
β_1 \\
β_0 \\
\end{matrix}\right] &\mathop{===}\limits^{α_{k,k}=1} \mathop{\left[\begin{matrix}
0 & 0 & ⋯ & 0 & 0 & ⋯ & 0 \\
⋮ & ⋮ & ⋰ & ⋮ & ⋮ & ⋰ & ⋮ \\
0 & 0 & ⋯ & 0 & 0 & ⋯ & 0 \\
0 & 0 & ⋯ & α_{r,r} & α_{r,r+1} & ⋯ & α_{r,n} \\
⋮ & ⋮ & ⋰ & ⋮ & ⋮ & ⋰ & ⋮ \\
0 & α_{1,1} & ⋯ & 0 & α_{1,r+1} & ⋯ & α_{1,n} \\
α_{0,0} & 0 & ⋯ & 0 & α_{0,r+1} & ⋯ & α_{0,n} \\
\end{matrix}\right]}\limits_{(1 + m)×(1 + n)} \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_{r+1} \\
x_r \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] \\
\left[\begin{matrix}
x_r \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] &\mathop{===}\limits^{β_{r+1}=0} \mathop{\left[\begin{matrix}
β_r & -α_{r,r+1} & ⋯ & -α_{r,n} \\
⋮ & ⋮ & & ⋮ \\
β_1 & -α_{1,r+1} & ⋯ & -α_{1,n} \\
β_0 & -α_{0,r+1} & ⋯ & -α_{0,n} \\
\end{matrix}\right]}\limits_{(1+r)×(1+n-r)} \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_{r+1} \\
+1 \\
\end{matrix}\right] = \left[\begin{matrix}
β_r - α_{r,r+1} · x_{r+1} ⋯ - α_{r,n} · x_{n} \\
⋮ \\
β_1 - α_{1,r+1} · x_{r+1} ⋯ - α_{1,n} · x_{n} \\
β_0 - α_{0,r+1} · x_{r+1} ⋯ - α_{0,n} · x_{n} \\
\end{matrix}\right] \\
\end{aligned}
$$

```
非齐次线性代数方程组解的结构，共计3种。
[不存在解] 若βᵣ₊₁ ≠ 0，则线性代数方程组无解。
[有唯一解] 若βᵣ₊₁ = 0，且r = n，则线性代数方程组有唯一解。
[有无数解] 若βᵣ₊₁ = 0，且r < n，则线性代数方程组有无数解，且通解中有n - r个自由变元。
齐次线性方程组解的结构，共计1种。
[有无数解] 若m < n，则r(≤m)< n，且线性代数方程组有无数解。
```

### 基矢量的运算性质

若无特别的规定，约定基矢量指单位基矢量而非规范基矢量。示例：$3$维空间单位基矢量之一$\vec{η}_{1} ≡ \left[\begin{matrix} 0 \\ 1 \\ 0 \end{matrix}\right]$，$4$维空间规范基矢量之一$\vec{n} = \dfrac{1}{\sqrt{3}} · \left[\begin{matrix} 1 \\ 1 \\ 1 \end{matrix}\right]$。

若无特别的规定，约定全基矢量指所有单位基矢量之位加运算的和。示例：$3$维空间全基矢量$\vec{η}_{+} ≡ \left[\begin{matrix} 1 \\ 1 \\ 1 \end{matrix}\right]$。

$n+1$元基矢量的点乘运算。
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

$n+1$元基矢量量的叉乘运算。约定$\dfrac{\vec{0}}{|\vec{0}|} = \vec{0}$。

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
\mathrm{A}_{(1+m)×(1+n)} &= \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} \\
{'}\mathrm{A}_{(1+m)×(1+n)} &= \mathop{\left[\begin{matrix}
a_{0,n} & a_{1,n} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{0,1} & a_{1,1} & ⋯ & a_{m,1} \\
a_{0,0} & a_{1,0} & ⋯ & a_{m,0} \\
\end{matrix}\right]}\limits_{(1+n)×(1+m)} \\
\end{aligned}
$$

单位$(1+n)×(1+n)$元矩阵。

$$
\mathrm{I}_{(1+n)×(1+n)} = \mathop{\left[\begin{matrix}
0 & 0 & ⋯ & 1 \\
⋮ & ⋮ & ⋰ & ⋮ \\
0 & 1 & ⋯ & 0 \\
1 & 0 & ⋯ & 0 \\
\end{matrix}\right]}\limits_{(1+n)×(1+n)}
$$

标量与$(1+m)×(1+n)$元矩阵的量加运算。矩阵的量加运算必满足交换律。

$$
\mathop{\left[\begin{matrix}
c + a_{m,0} & c + a_{m,1} & ⋯ & c + a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
c + a_{1,0} & c + a_{1,1} & ⋯ & c + a_{1,n} \\
c + a_{0,0} & c + a_{0,1} & ⋯ & c + a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} = c \oplus \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)}
$$

$(1+m)×(1+n)$元矩阵与$(1+m)×(1+n)$元矩阵的位加运算。矩阵的位加运算必满足交换律。矩阵的位加运算必满足结合律。

$$
\mathop{\left[\begin{matrix}
b_{m,0} + a_{m,0} & b_{m,1} + a_{m,1} & ⋯ & b_{m,n} + a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} + a_{1,0} & b_{1,1} + a_{1,1} & ⋯ & b_{1,n} + a_{1,n} \\
b_{0,0} + a_{0,0} & b_{0,1} + a_{0,1} & ⋯ & b_{0,n} + a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} = \mathop{\left[\begin{matrix}
b_{m,0} & b_{m,1} & ⋯ & b_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} & b_{1,1} & ⋯ & b_{1,n} \\
b_{0,0} & b_{0,1} & ⋯ & b_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} + \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)}
$$

标量与$(1+m)×(1+n)$元矩阵的量乘运算。矩阵的量乘运算必满足交换律。

$$
\mathop{\left[\begin{matrix}
c · a_{m,0} & c · a_{m,1} & ⋯ & c · a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
c · a_{1,0} & c · a_{1,1} & ⋯ & c · a_{1,n} \\
c · a_{0,0} & c · a_{0,1} & ⋯ & c · a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} = c · \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)}
$$

$(1+m)×(1+n)$元矩阵与$(1+m)×(1+n)$元矩阵的点乘运算。矩阵的点乘运算满足必交换律。

$$
\sum\limits_{i=0}^{m} \sum\limits_{j=0}^{n} b_{i,j} · a_{i,j} = \mathop{\left[\begin{matrix}
b_{m,0} & b_{m,1} & ⋯ & b_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} & b_{1,1} & ⋯ & b_{1,n} \\
b_{0,0} & b_{0,1} & ⋯ & b_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} \odot \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)}
$$

$(1+m)×(1+n)$元矩阵与$(1+m)×(1+n)$元矩阵的位乘运算。矩阵的位乘运算必满足交换律。矩阵的位乘运算必满结合律。

$$
\mathop{\left[\begin{matrix}
b_{m,0} · a_{m,0} & b_{m,1} · a_{m,1} & ⋯ & b_{m,n} · a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} · a_{1,0} & b_{1,1} · a_{1,1} & ⋯ & b_{1,n} · a_{1,n} \\
b_{0,0} · a_{0,0} & b_{0,1} · a_{0,1} & ⋯ & b_{0,n} · a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} = \mathop{\left[\begin{matrix}
b_{m,0} & b_{m,1} & ⋯ & b_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} & b_{1,1} & ⋯ & b_{1,n} \\
b_{0,0} & b_{0,1} & ⋯ & b_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} × \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)}
$$

$(l+1)*(1+m)$元矩阵与$(1+m)×(1+n)$元矩阵的合乘运算。矩阵的合乘运算不满足交换律。矩阵的合乘运算必满足结合律。

$$
\mathop{\left[\begin{matrix}
\sum\limits_{k=0}^{m} b_{l,k} · a_{k,0} & \sum\limits_{k=0}^{m} b_{l,k} · a_{k,1} & ⋯ & \sum\limits_{k=0}^{m} b_{l,k} · a_{k,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\sum\limits_{k=0}^{m} b_{1,k} · a_{k,0} & \sum\limits_{k=0}^{m} b_{1,k} · a_{k,1} & ⋯ & \sum\limits_{k=0}^{m} b_{1,k} · a_{k,n} \\
\sum\limits_{k=0}^{m} b_{0,k} · a_{k,0} & \sum\limits_{k=0}^{m} b_{0,k} · a_{k,1} & ⋯ & \sum\limits_{k=0}^{m} b_{0,k} · a_{k,n} \\
\end{matrix}\right]}\limits_{(l+1)×(1+n)} = \mathop{\left[\begin{matrix}
b_{l,0} & b_{l,1} & ⋯ & b_{l,m} \\
⋮ & ⋮ & ⋰ & ⋮ \\
b_{1,0} & b_{1,1} & ⋯ & b_{1,m} \\
b_{0,0} & b_{0,1} & ⋯ & b_{0,m} \\
\end{matrix}\right]}\limits_{(l+1)×(1+m)} \rlap{×}{+} \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)}
$$

$$
\begin{aligned}
\mathrm{D}_{(k+1)×(1+n)} &= \mathrm{C}_{(k+1)×(l+1)} \rlap{×}{+} \left[ \mathrm{B}_{(l+1)×(1+m)} \rlap{×}{+} \mathrm{A}_{(1+m)×(1+n)} \right] \\
\mathrm{D}_{(k+1)×(1+n)} &= \left[ \mathrm{C}_{(k+1)×(l+1)} \rlap{×}{+} \mathrm{B}_{(l+1)×(1+m)} \right] \rlap{×}{+} \mathrm{A}_{(1+m)×(1+n)} \\
c(ba)_{q,t} &= \sum\limits_{r=0}^{l} c_{q,r} · \left[ \sum\limits_{s=0}^{m} b_{r,s} · a_{s,t} \right] = \sum\limits_{r=0}^{l} \sum\limits_{s=0}^{m} c_{q,r} · b_{r,s} · a_{s,t} \\
(cb)a_{q,t}&= \sum\limits_{s=0}^{m} \left[ \sum\limits_{r=0}^{l} c_{q,r} · b_{r,s} \right] · a_{s,t} = \sum\limits_{r=0}^{l} \sum\limits_{s=0}^{m} c_{q,r} · b_{r,s} · a_{s,t} \\
\end{aligned}
$$

$$
\begin{aligned}
\mathrm{C}_{(l+1)×(1+n)} &= \mathrm{B}_{(l+1)×(1+m)} \rlap{×}{+} \mathrm{A}_{(1+m)×(1+n)} \\
{'}\mathrm{C}_{(l+1)×(1+n)} &= {'}\mathrm{a}_{(1+m)×(1+n)} \rlap{×}{+} {'}\mathrm{B}_{(l+1)×(1+m)} \\
ba_{r,t} &= \sum\limits_{s=0}^{m} b_{r,s} · a_{s,t} \\
ab_{t,r} &= \sum\limits_{s=0}^{m} a_{t,s} · b_{s,r} \\
\end{aligned}
$$

$$
\begin{aligned}
\mathrm{C}_{(l+1)×(1+n)} &= \mathrm{B}_{(l+1)×(1+m)} \rlap{×}{+} \mathrm{A}_{(1+m)×(1+n)} \\
{^\imath}\mathrm{C}_{(l+1)×(1+n)} &= {^\imath}\mathrm{A}_{(1+m)×(1+n)} \rlap{×}{+} {^\imath}\mathrm{B}_{(l+1)×(1+m)} \\
\mathrm{I}_{(l+1)×(l+1)} &= \mathrm{B}_{(l+1)×(1+m)} \rlap{×}{+} \mathrm{A}_{(1+m)×(1+n)} \rlap{×}{+} {^\imath}\mathrm{A}_{(1+m)×(1+n)} \rlap{×}{+} {^\imath}\mathrm{B}_{(l+1)×(1+m)} \\
\end{aligned}
$$

$(1+m)×(1+n)$元矩阵的度量值。矩阵的度量值值为其自身之点乘运算的方根值。

$$
\left[ \sum\limits_{i=0}^{m} \sum\limits_{j=0}^{n} a_{i,j}^2 \right]^{\frac{1}{2}} = \mathop{\left|\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right|}\limits_{(1+m)×(1+n)} ≡ \mathrm{sqrt} \left( \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} \odot \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} \right)
$$

$(1+n)×(1+n)$元矩阵的行列式。

$$
\mathop{\left\Vert\begin{matrix}
a_{n,0} & a_{n,1} & ⋯ & a_{n,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right\Vert}\limits_{(1+n)×(1+n)} = \sum\limits_{k_0,k_1,⋯,k_n} \mathrm{sgn}(k_0, k_1, ⋯, k_n) · a_{0,k_0} · a_{1,k_1} ⋯ a_{n,k_n} \\
$$

### 向量的运算性质

若无特别的规定，约定向量指列向量而非行向量，列向量与行向量互为反置。

$$
\begin{aligned}
\bold{v} &= \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] \\
{'}\bold{v} &= \left[\begin{matrix}
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
\end{matrix}\right]}\limits_{(1+n)×(1+n)} \rlap{×}{+} \left[\begin{matrix}
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
\end{matrix}\right] ≡ (\bold{η}_0 · u_0 + \bold{η}_1 · u_1 + ⋯ + \bold{η}_n · u_n) \odot (\bold{η}_0 · v_0 + \bold{η}_1 · v_1 + ⋯ + \bold{η}_n · v_n) \\
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
\end{matrix}\right]}\limits_{(1+n)×(1+n)} \rlap{×}{+} \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right]
$$

$n+1$元矢量与$n+1$元矢量的叉乘运算。矢量的叉乘运算不满足交换律。矢量的叉乘运算不满足结合律。

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
\end{matrix}\right]}\limits_{(1+n)×(1+n)} \rlap{×}{+} \left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right] \\
\end{aligned}
$$

$3$元矢量与$3$元矢量的叉乘运算。矢量的叉乘运算不满足结合律。

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

### 矢量的二重乘运算

$3$元矢量的混合叉点乘运算。

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

$3$元矢量的任意叉叉乘运算。矢量的任意叉叉乘运算不满足结合律。

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
&= \mathop{\left[\begin{matrix}
-q_z · p_x & -q_z · p_y & (q_x · p_x + q_y · p_y) \\
-q_y · p_x & (q_z · p_z + q_x · p_x) & -q_y · p_z \\
(q_y · p_y + q_z · p_z) & -q_x · p_y & -q_x · p_z \\
\end{matrix}\right]}\limits_{3×3} \rlap{×}{+} \left[\begin{matrix}
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
&= \mathop{\left[\begin{matrix}
-q_x · p_z & -q_y · p_z & (q_x · p_x + q_y · p_y) \\
-q_x · p_y & (q_z · p_z + q_x · p_x) & -q_z· p_y \\
(q_y · p_y + q_z · p_z) & -q_y · p_x & q_z · p_x \\
\end{matrix}\right]}\limits_{3×3} \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\end{aligned}
$$

$3$元矢量的对称叉叉乘运算。矢量的对称叉叉乘运算必满足结合律。

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
\end{matrix}\right] &= \left[\begin{matrix}
- q_z · q_x · v_x - q_y · q_z · v_y + (q_x^2 + q_y^2) · v_z \\
- q_x · q_y · v_x + (q_z^2 + q_x^2) · v_y - q_y · q_z · v_z \\
+ (q_y^2 + q_z^2) · v_x - q_x · q_y · v_y - q_z · q_x · v_z \\
\end{matrix}\right] \\
&= \mathop{\left[\begin{matrix}
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

$3$元矢量的逆称叉叉乘运算。矢量的逆称叉叉乘运算必满足结合律。

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
\end{matrix}\right] &= \left[\begin{matrix}
+ q_z · q_x · v_x + q_y · q_z · v_y - (q_x^2 + q_y^2) · v_z \\
+ q_x · q_y · v_x - (q_z^2 + q_x^2) · v_y + q_y · q_z · v_z \\
- (q_y^2 + q_z^2) · v_x + q_x · q_y · v_y + q_z · q_x · v_z \\
\end{matrix}\right] \\
&= \mathop{\left[\begin{matrix}
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

$3$元矢量的对称点量乘运算。

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
