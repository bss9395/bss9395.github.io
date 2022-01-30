---
layout: zh_post
Topic : 收敛极限
Title : 线性代数
Update: 2022-01-30T23:33:00+08@中国-广东-湛江+08
Author: 璀璨星辰
Credit: 《线性代数（数学专业用）》李尚志
Notice: 本书限于本人能力范围，如果有疏漏之处请联系，brilliantstarrysky9395@gmail.com
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

$(1 + n)$元$(1 + m)$量线性代数方程组，其系数矩阵记作$A_{(1+m)×(1+n)}$，其增广矩阵记作$\tilde{A}_{(1+m)×(2+n)}$。当$\bold{b} ≡ \bold{0}$时为齐次线性代数方程组，当$\bold{b} ≠ \bold{0}$时为非齐次线性方程组。

注意：线性代数方程组未必有解，零解$\bold{x} = \left[\begin{matrix} 0 \\ ⋮ \\ 0 \\ \end{matrix}\right]$必定是齐次线性方程组的解，并且必定不是非齐次线性方程组的解。

$$
\begin{aligned}
A_{(1+m)×(1+n)} \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] = \left[\begin{matrix}
b_m \\
⋮ \\
b_1 \\
b_0 \\
\end{matrix}\right] &= \mathop{\left[\begin{matrix}
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
\end{matrix}\right] \\
\left[\begin{array}{c|c}
\bold{b} & A_{(1+m)×(1+n)}
\end{array}\right] = \tilde{A}_{(1+m)×(2+n)} &= \left[\begin{array}{c|ccc}
b_m & a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋮ & ⋰ & ⋮ \\
b_1 & a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
b_0 & a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{array}\right] \\
\end{aligned}
$$

$(1 + n)$元$(1 + m)$量线性代数方程组的线性组合。注意：$κ = 0$并非特殊情形，$(1 + n)$元$(1 + m)$量线性代数方程组的解必定是其线性组合的解，反之不对。

$$
\begin{aligned}
β = \left[\begin{matrix}
κ_0 & κ_1 & ⋯ & κ_m \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
b_m \\
⋮ \\
b_1 \\
b_0 \\
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
\hline
β_r \\
⋮ \\
β_1 \\
β_0 \\
\end{matrix}\right] &\mathop{===}\limits^{α_{k,k}=1} \mathop{\left[\begin{array}{cccc|ccc}
0 & 0 & ⋯ & 0 & 0 & ⋯ & 0 \\
⋮ & ⋮ & ⋰ & ⋮ & ⋮ & ⋰ & ⋮ \\
0 & 0 & ⋯ & 0 & 0 & ⋯ & 0 \\
\hline
0 & 0 & ⋯ & α_{r,r} & α_{r,r+1} & ⋯ & α_{r,n} \\
⋮ & ⋮ & ⋰ & ⋮ & ⋮ & ⋰ & ⋮ \\
0 & α_{1,1} & ⋯ & 0 & α_{1,r+1} & ⋯ & α_{1,n} \\
α_{0,0} & 0 & ⋯ & 0 & α_{0,r+1} & ⋯ & α_{0,n} \\
\end{array}\right]}\limits_{(1 + m)×(1 + n)} \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_{r+1} \\
\hline
x_r \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] \\
\left[\begin{matrix}
x_n \\
⋮ \\
x_{r+1} \\
\hline
x_r \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] &\mathop{===}\limits^{β_{r+1}=0} \mathop{\left[\begin{array}{c|ccc}
0 & 0 & ⋯ & 1 \\
⋮ & ⋮ & ⋰ & ⋮ \\
0 & 1 & ⋯ & 0 \\
\hline
β_r & -α_{r,r+1} & ⋯ & -α_{r,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
β_1 & -α_{1,r+1} & ⋯ & -α_{1,n} \\
β_0 & -α_{0,r+1} & ⋯ & -α_{0,n} \\
\end{array}\right]}\limits_{(1+r)×(1+n-r)} \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_{r+1} \\
\hline
+1 \\
\end{matrix}\right] = \left[\begin{matrix}
x_n \\
⋮ \\
x_{r+1} \\
\hline
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
[有无数解] 若βᵣ₊₁ = 0，且r < n，则线性代数方程组有无数解，且通解中有(1 + n) - (1 + r)个自由变元。
齐次线性代数方程组解的结构，共计1种。
[有无数解] 若m < n，则r(≤m)< n，且线性代数方程组有无数解。
```

若线性代数方程组中有某个方程是其余方程的线性组合，则该线性代数方程组满足线性相关性，否则该线性代数方程组满足线性无关性。注意：方程的变元变量即为向量的分量。

若线性代数方程组的反置齐次线性代数方程组有非零解，则该线性代数方程组满足线性相关性，否则该线性代数方程组满足线性无关性。注意：方程组的反置即为向量组的反置。

注意：含零向量方程的线性代数方程组必满足线性相关性，若线性代数方程组仅含有一个非零向量方程，则该线性代数方程组满足线性无关性。约定：空向量集满足线性无关性。

推论：线性代数方程组满足线性相关性，当且仅当其子集线性代数方程组满足线性相关性，当且仅当有某个方程是其前面所有方程的线性组合。

$$
\begin{aligned}
\left[\begin{matrix}
0 \\
⋮ \\
0 \\
\hline
0 \\
\end{matrix}\right] &\mathop{===} \mathop{\left[\begin{matrix}
a_{0,n} · x_n & a_{1,n} · x_n & ⋯ & a_{m,n} · x_n \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{0,1} · x_1 & a_{1,1} · x_1 & ⋯ & a_{m,1} · x_1 \\
a_{0,0} · x_0 & a_{1,0} · x_0 & ⋯ & a_{m,0} · x_0 \\
\hline
y_0 & y_1 & ⋯ & y_m \\
\end{matrix}\right]}\limits_{(2+n)×(1+m)} \rlap{×}{+} \left[\begin{matrix}
χ_m \\
⋮ \\
χ_1 \\
χ_0 \\
\end{matrix}\right] \\
\left[\begin{matrix}
0 \\
⋮ \\
0 \\
\hline
0 \\
\end{matrix}\right] &\mathop{===}\limits^{\langle \rlap{×}{+},× \rangle} \left[\begin{matrix}
x_n \\
⋮ \\
x_1 \\
x_0 \\
\hline
+1
\end{matrix}\right] × \mathop{\left[\begin{matrix}
a_{0,n} & a_{1,n} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{0,1} & a_{1,1} & ⋯ & a_{m,1} \\
a_{0,0} & a_{1,0} & ⋯ & a_{m,0} \\
\hline
y_0 & y_1 & ⋯ & y_m \\
\end{matrix}\right]}\limits_{(2+n)×(1+m)} \rlap{×}{+} \left[\begin{matrix}
χ_m \\
⋮ \\
χ_1 \\
χ_0 \\
\end{matrix}\right] = \mathop{\left[\begin{matrix}
a_{0,n} & a_{1,n} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{0,1} & a_{1,1} & ⋯ & a_{m,1} \\
a_{0,0} & a_{1,0} & ⋯ & a_{m,0} \\
\hline
y_0 & y_1 & ⋯ & y_m \\
\end{matrix}\right]}\limits_{(2+n)×(1+m)} \rlap{×}{+} \left[\begin{matrix}
χ_m \\
⋮ \\
χ_1 \\
χ_0 \\
\end{matrix}\right] \\
\left[\begin{matrix}
0 \\
⋮ \\
0 \\
\hline
0 \\
\end{matrix}\right] &\mathop{===} \left[\begin{matrix}
\bold{η}_0 & \bold{η}_1 & ⋯ & \bold{η}_n \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
χ_n \\
⋮ \\
χ_1 \\
χ_0 \\
\end{matrix}\right] = \mathop{\left[\begin{matrix}
0 & 0 & ⋯ & 1 \\
⋮ & ⋮ & ⋰ & ⋮ \\
0 & 1 & ⋯ & 0 \\
\hline
1 & 0 & ⋯ & 0 \\
\end{matrix}\right]}\limits_{(1+n)×(1+n)} \rlap{×}{+} \left[\begin{matrix}
χ_n \\
⋮ \\
χ_1 \\
χ_0 \\
\end{matrix}\right] = \left[\begin{matrix}
χ_n \\
⋮ \\
χ_1 \\
χ_0 \\
\end{matrix}\right] \\
\end{aligned}
$$

在线性代数方程组中添加任意数量的分量，新线性代数方程组的反置齐次线性代数方程组的解，必定是原线性代数方程组的反置齐次线性代数方程组的解，反之不对。

推论：若线性代数方程组满足线性无关性，则该线性代数方程组仅有非零解，因此在该线性代数方程组中添加任意数量的分量，新线性代数方程组必满足线性无关性。

若$m > n$，则$(1 + n)$元$(1 + m)$量线性代数方程组的$(1+m)$元$(1+n)$量反置齐次线性代数方程组必有无数解因而有非零解，因此该线性代数方程组满足线性相关性。

推论：在$(1 + n)$元向量空间中，至多存在$(1 + n)$个线性无关的向量，且至少存在$(1 + n)$个线性无关的基向量$\bold{η}_i$，因此$(1 + n)$元向量空间也称作$(1 + n)$维向量空间。

推论：在$(1+n)$维向量空间中，任意一个向量与其$(1+n)$个基向量$\bold{η}_i$的向量组都满足线性相关性，因此任意一个向量都可以表示成其$(1 + n)$个基向量$\bold{η}_i$的线性组合。

约定：对于$(1+n)$元$(1+m)$量向量组$\bold{S}_{(1+n)×(1+m)} = \lbrace ∀i; \bold{v}_i \rbrace$，$(1+n)$指示该向量组中向量的维数是$(1+n)$维，$(1+m)$指示该向量组中向量的个数是$(1+m)$个。

推论：对于向量组$\lbrace ∀i; \bold{v}_i \rbrace_{(1+n)×(1+m)}$，若其任意一个向量$\bold{v}_i$都是其子集向量组$\lbrace ∀j; \bold{v}_j \rbrace_{(1+n)×(1+r)}$的线性组合，当且仅当此子集向量组是其极大线性无关向量组之一。

若向量组$\lbrace ∀i; \bold{u}_i \rbrace_{(1+n)×(1+q)}$中每一个向量都是向量组$\lbrace ∀j; \bold{v}_j \rbrace_{(1+n)×(1+p)}$的线性组合且反之亦然，则此两个向量组互为等价$\lbrace ∀i; \bold{u}_i \rbrace_{(1+n)×(1+q)} ⇆ \lbrace ∀j; \bold{v}_j \rbrace_{(1+n)×(1+p)}$。

注意：互为线性组合等价的向量组$\bold{Q}_{(1+n)×(1+q)} ⇆ \bold{P}_{(1+n)×(1+p)}$两者的个数未必相等$q \not≡ p$。向量组的线性组合等价关系具有传递性，$\bold{Q}_{(1+n)×(1+q)} \mathop{⇆}\limits_{\bold{Q} ⇆ \bold{P}}^{\bold{P} ⇆ \bold{O}} \bold{O}_{(1+n)×(1+o)}$。

$$
\begin{aligned}
\left[\begin{matrix}
\bold{v}_0 & \bold{v}_1 & ⋯ & \bold{v}_p \\
\end{matrix}\right] &= \left[\begin{matrix}
\bold{u}_0 & \bold{u}_1 & ⋯ & \bold{u}_o \\
\end{matrix}\right] \rlap{×}{+} \mathop{\left[\begin{matrix}
κ_{0,o} & κ_{1,o} & ⋯ & κ_{p,o} \\
⋮ & ⋮ & ⋰ & ⋮ \\
κ_{0,1} & κ_{1,1} & ⋯ & κ_{p,1} \\
κ_{0,0} & κ_{1,0} & ⋯ & κ_{p,0} \\
\end{matrix}\right]}\limits_{(1+o)×(1+p)} \\
\left[\begin{matrix}
\bold{w}_0 & \bold{w}_1 & ⋯ & \bold{w}_q \\
\end{matrix}\right] &= \left[\begin{matrix}
\bold{v}_0 & \bold{v}_1 & ⋯ & \bold{v}_p \\
\end{matrix}\right] \rlap{×}{+} \mathop{\left[\begin{matrix}
ι_{0,p} & ι_{1,p} & ⋯ & ι_{q,p} \\
⋮ & ⋮ & ⋰ & ⋮ \\
ι_{0,1} & ι_{1,1} & ⋯ & ι_{q,1} \\
ι_{0,0} & ι_{1,0} & ⋯ & ι_{q,0} \\
\end{matrix}\right]}\limits_{(1+p)×(1+q)} \\
\left[\begin{matrix}
\bold{w}_0 & \bold{w}_1 & ⋯ & \bold{w}_q \\
\end{matrix}\right] &= \left[\begin{matrix}
\bold{u}_0 & \bold{u}_1 & ⋯ & \bold{u}_o \\
\end{matrix}\right] \rlap{×}{+} \mathop{\left[\begin{matrix}
κ_{0,o} & κ_{1,o} & ⋯ & κ_{p,o} \\
⋮ & ⋮ & ⋰ & ⋮ \\
κ_{0,1} & κ_{1,1} & ⋯ & κ_{p,1} \\
κ_{0,0} & κ_{1,0} & ⋯ & κ_{p,0} \\
\end{matrix}\right]}\limits_{(1+o)×(1+p)} \rlap{×}{+} \mathop{\left[\begin{matrix}
ι_{0,p} & ι_{1,p} & ⋯ & ι_{q,p} \\
⋮ & ⋮ & ⋰ & ⋮ \\
ι_{0,1} & ι_{1,1} & ⋯ & ι_{q,1} \\
ι_{0,0} & ι_{1,0} & ⋯ & ι_{q,0} \\
\end{matrix}\right]}\limits_{(1+p)×(1+q)} \\
\left[\begin{matrix}
\bold{w}_0 & \bold{w}_1 & ⋯ & \bold{w}_q \\
\end{matrix}\right] &= \left[\begin{matrix}
\bold{u}_0 & \bold{u}_1 & ⋯ & \bold{u}_o \\
\end{matrix}\right] \rlap{×}{+} \mathop{\left[\begin{matrix}
\sum\limits_{i=0}^{p} κ_{i,o} · ι_{0,i} & \sum\limits_{i=0}^{p} κ_{i,o} · ι_{1,p} & ⋯ & \sum\limits_{i=0}^{p} κ_{i,o} · ι_{q,i} \\
⋮ & ⋮ & ⋰ & ⋮ \\
\sum\limits_{i=0}^{p} κ_{i,1} · ι_{0,i} & \sum\limits_{i=0}^{p} κ_{i,1} · ι_{1,i} & ⋯ & \sum\limits_{i=0}^{p} κ_{i,1} · ι_{q,i} \\
\sum\limits_{i=0}^{p} κ_{i,0} · ι_{0,i} & \sum\limits_{i=0}^{p} κ_{i,0} · ι_{1,i} & ⋯ & \sum\limits_{i=0}^{p} κ_{i,0} · ι_{q,i} \\
\end{matrix}\right]}\limits_{(1+o)×(1+q)} \\
\end{aligned}
$$

对于向量组$\lbrace ∀k; \bold{w}_k \rbrace_{(1+n)×(1+q)}$，若其任意一个向量$\bold{w}_k$都是向量组$\lbrace ∀j; \bold{v}_j \rbrace_{(1+n)×(1+p)}$的线性组合，且$q > p$，则前者必满足线性相关性。注意：后者可满足线性无关性。

对于向量组$\lbrace ∀j; \bold{v}_j \rbrace_{(1+n)×(1+p)}$，从其任意一个向量开始，都能扩充成一个极大线性无关向量组，其所有极大线性无关向量组互为线性组合等价，并且向量的个数都相等。

$$
\begin{aligned}
\left[\begin{matrix}
0 \\
⋮ \\
0 \\
0 \\
\end{matrix}\right] &= \left[\begin{matrix}
\bold{w}_0 & \bold{w}_1 & ⋯ & \bold{w}_q \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
χ_q \\
⋮ \\
χ_1 \\
χ_0 \\
\end{matrix}\right] \\
\left[\begin{matrix}
0 \\
⋮ \\
0 \\
0 \\
\end{matrix}\right] &= \left[\begin{matrix}
\bold{v}_0 & \bold{v}_1 & ⋯ & \bold{v}_p \\
\end{matrix}\right] \rlap{×}{+} \mathop{\left[\begin{matrix}
ι_{0,p} & ι_{1,p} & ⋯ & ι_{q,p} \\
⋮ & ⋮ & ⋰ & ⋮ \\
ι_{0,1} & ι_{1,1} & ⋯ & ι_{q,1} \\
ι_{0,0} & ι_{1,0} & ⋯ & ι_{q,0} \\
\end{matrix}\right]}\limits_{(1+p)×(1+q)} \rlap{×}{+} \left[\begin{matrix}
χ_q \\
⋮ \\
χ_1 \\
χ_0 \\
\end{matrix}\right] \mathop{===}\limits^{q>p} \mathop{\left[\begin{matrix}
ι_{0,p} & ι_{1,p} & ⋯ & ι_{q,p} \\
⋮ & ⋮ & ⋰ & ⋮ \\
ι_{0,1} & ι_{1,1} & ⋯ & ι_{q,1} \\
ι_{0,0} & ι_{1,0} & ⋯ & ι_{q,0} \\
\end{matrix}\right]}\limits_{(1+p)×(1+q)} \rlap{×}{+} \left[\begin{matrix}
χ_q \\
⋮ \\
χ_1 \\
χ_0 \\
\end{matrix}\right] \\
\end{aligned}
$$

约定：对于向量组$\lbrace ∀i; \bold{v}_i \rbrace_{(1+n)×(1+m)}$，其向量组的秩rank，指其任意一个极大线性无关向量组$\lbrace ∀j; \bold{v}_j \rbrace_{(1+n)×(1+r)}$的向量个数$(1 + r)$，记作$\mathrm{Rank}\langle \lbrace ∀j; \bold{v}_j \rbrace_{(1+n)×(1+r)} \rangle$。

约定：向量组指列向量组而非行向量组，向量组的秩指列秩而非行秩。因任意向量组经过初等行变换与初等列变换将形成对角形矩阵，向量组的列秩与其行秩必定相等。

推论：根据向量组线性组合的传递性，若向量组$\lbrace ∀i; \bold{u}_i \rbrace_{(1+n)×(1+q)}$是向量组$\lbrace ∀j; \bold{v}_j \rbrace_{(1+n)×(1+p)}$的线性组合，则$\mathrm{Rank}\langle \lbrace ∀i; \bold{u}_i \rbrace_{(1+n)×(1+q)} \rangle ≤ \mathrm{Rank}\langle \lbrace ∀j; \bold{v}_j \rbrace_{(1+n)×(1+p)} \rangle$。

### 线性空间

线性代数方程组的解集对于其增广矩阵所在的数域封闭。

$$
\begin{aligned}
&线性空间\lbrace ∀i; \bold{x}_i \rbrace的运算性质，共计2个。注意：线性空间\lbrace ∀i; \bold{x}_i \rbrace也可以是空集Ø。 \\
&\begin{array}{lllll}
[满足位加性] && [\bold{x} ∈ \lbrace ∀i; \bold{x}_i \rbrace] ∧ [\bold{y} ∈ \lbrace ∀i; \bold{x}_i \rbrace] &⇒& [(\bold{x} + \bold{y}) ∈ \lbrace ∀i; \bold{x}_i \rbrace] \\
[满足量乘性] && [\bold{x} ∈ \lbrace ∀i; \bold{x}_i \rbrace] ∧ [k ∈ \mathrm{Field}\langle \bold{x} \rangle] &⇒& [(k · \bold{x}) ∈ \lbrace ∀i; \bold{x}_i \rbrace] \\
\end{array} \\
\\
&线性空间\lbrace ∀i; \bold{x}_i \rbrace的典型性质，共计8个。注意：此处线性空间\lbrace ∀i; \bold{x}_i \rbrace不是空集Ø。 \\
&\begin{array}{lllll}
[位加有零元] && \bold{0} ∈ \lbrace ∀i; \bold{x}_i \rbrace \\
[位加有负元] && -\bold{x} ∈ \lbrace ∀i; \bold{x}_i \rbrace \\
[位加结合律] && (\bold{x} + \bold{y}) + \bold{z} = \bold{x} + (\bold{y} + \bold{z}) \\
[位加交换律] && \bold{x} + \bold{y} = \bold{y} + \bold{x} \\
[量乘有幺元] && 1 · \bold{x} = \bold{x} \\
[量乘结合律] && (ι · κ) · \bold{x} = ι · (κ · \bold{x}) \\
[量乘分配律] && κ · (\bold{x} + \bold{y}) = κ · \bold{x} + κ · \bold{y} \\
[量乘分配律] && (ι + κ) · \bold{x} = ι · \bold{x} + κ · \bold{x} \\
\end{array} \\
\end{aligned}
$$

线性空间对于位加运算与量乘运算封闭，齐次线性代数方程的解集是线性空间，非齐次线性代数方程的解集不是线性空间而是仿射空间。

$$
\begin{aligned}
\left[\begin{matrix}
0 \\
⋮ \\
0 \\
0 \\
\end{matrix}\right] &= \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] = \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} \rlap{×}{+} \left[\begin{matrix}
y_n \\
⋮ \\
y_1 \\
y_0 \\
\end{matrix}\right] \\
\left[\begin{matrix}
0 \\
⋮ \\
0 \\
0 \\
\end{matrix}\right] &= \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} \rlap{×}{+} \left[\begin{matrix}
x_n + y_n \\
⋮ \\
x_1 + y_1 \\
x_0 + y_0 \\
\end{matrix}\right] \\
\left[\begin{matrix}
0 \\
⋮ \\
0 \\
0 \\
\end{matrix}\right] &= \mathop{\left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} \rlap{×}{+} \left[\begin{matrix}
k · x_n \\
⋮ \\
k · x_1 \\
k · x_0 \\
\end{matrix}\right] \\
\end{aligned}
$$

线性空间中任意一个极大线性无关向量组构成其基向量组，线性空间中任意一个向量都是此基向量组的线性组合，线性组合的系数必唯一确定，也称作基向量组的坐标。

仅由零向量构成的线性空间称为零空间，零空间$\lbrace \bold{0} \rbrace_{(1+n)×(1)}$中极大线性无关向量组为空集$Ø$，因此空集$Ø$是零空间的基向量组，零空间的维数是$\mathrm{Rank}\langle \lbrace \bold{0} \rbrace_{(1+n)×(1)} \rangle = 0$。

$$
\begin{aligned}
\bold{x} = \left[\begin{matrix}
\bold{e}_0 & \bold{e}_1 & ⋯ & \bold{e}_r \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
x_r \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] = x_0 · \bold{e}_0 + x_1 · \bold{e}_1 ⋯ + x_r · \bold{e}_r \\
\end{aligned}
$$

约定：对于线性空间$\lbrace ∀i;𝐱ᵢ \rbrace$，其维数dimension，指其任意一个基向量组的向量个数，记作$\mathrm{Dime}\langle \lbrace ∀i;𝐱ᵢ \rbrace \rangle$。注意：线性空间的维数不等同于线性空间中向量的维数。

齐次线性代数方程组的解集$\lbrace ∀i;𝐱ᵢ \rbrace_{(1+n)}$有$(1 + n) - \mathrm{Rank}\langle A_{(1+m)×(1+n)} \rangle$个自由变元，因此该线性空间的维数满足$\mathrm{Dime}\langle \lbrace ∀i;𝐱ᵢ \rbrace \rangle = (1 + n) - \mathrm{Rank}\langle A_{(1+m)×(1+n)} \rangle$。

约定：向量集$\lbrace ∀j; \bold{x}_j \rbrace_{(1+n)}$的全体线性组合构成包含该向量集的最小线性空间$\mathrm{Linear}\langle \lbrace ∀j; \bold{x}_j \rbrace_{(1+n)} \rangle$。齐次线性代数方程组的解集$\lbrace ∀j; \bold{x}_j \rbrace_{(1+n)} ≡ \mathrm{L_{inear}}\langle \lbrace ∀j; \bold{x}_j \rbrace_{(1+n)} \rangle$。

推论：向量集$\lbrace ∀j; \bold{x}_j \rbrace_{(1+n)}$的极大线性无关向量组，构成包含该向量集的最小线性空间的基向量组，因此必满足$\mathrm{Rank}\langle \lbrace ∀j; \bold{x}_j \rbrace_{(1+n)} \rangle = \mathrm{Dime}\langle \mathrm{Linear}\langle \lbrace ∀j; \bold{x}_j \rbrace_{(1+n)} \rangle \rangle$。

注意：齐次线性代数方程组的解集$\lbrace ∀i;𝐱ᵢ \rbrace_{(1+n)}$的任意子集$\lbrace ∀j; \bold{x}_j \rbrace_{(1+n)}$未必是线性空间，其最小线性空间满足$\lbrace ∀i;𝐱ᵢ \rbrace_{(1+n)} ⊇ \mathrm{Linear}\langle \lbrace ∀j; \bold{x}_j \rbrace_{(1+n)} \rangle ⊇ \lbrace ∀j; \bold{x}_j \rbrace_{(1+n)}$。

若向量集$\lbrace ∀j; \bold{x}_j \rbrace_{(1+n)}$是向量集$\lbrace ∀k; \bold{v}_k \rbrace_{(1+n)}$的线性组合，当且仅当$\lbrace ∀j; \bold{x}_j \rbrace_{(1+n)} ⊆ \mathrm{Linear}\langle \lbrace ∀k; \bold{v}_k \rbrace_{(1+n)} \rangle$，当且仅当$\mathrm{Linear}\lbrace ∀j; \bold{x}_j \rbrace_{(1+n)} ⊆ \mathrm{Linear}\langle \lbrace ∀k; \bold{v}_k \rbrace_{(1+n)} \rangle$。

非齐次线性代数方程组存在解，当且仅当其系数矩阵的秩等同于其增广矩阵的秩$\mathrm{Rank}\langle A_{(1+m)×(1+n)} \rangle = \mathrm{Rank}\langle \tilde{A}_{(1+m)×(2+n)} \rangle$，当且仅当$\bold{y} ∈ \mathrm{Linear}\langle \lbrace \bold{a}_0, \bold{a}_1, ⋯, \bold{a}_n \rbrace \rangle$。

约定：非齐次线性代数方程组的任意一个特解，记作$\bold{ρ} = \left[\begin{matrix} ρ_n \\ ⋮ \\ ρ_0 \end{matrix}\right]$。非齐次线性代数方程组的任意两个特解之差，必是其对应齐次线性代数方程组的解，记作$\bold{u} = \left[\begin{matrix} u_n \\ ⋮ \\ u_0 \end{matrix}\right]$。

推论：非齐次线性代数方程组的通解满足$\bold{x} = \bold{ρ} + \bold{u}$。齐次线性代数方程组的解必经过原点$\bold{0}$，非齐次线性方程组的通解必不经过原点$\bold{0}$，且不满足线性空间的运算性质。

$$
\begin{aligned}
\left[\begin{matrix}
b_m \\
⋮ \\
b_1 \\
b_0 \\
\end{matrix}\right] &= \left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
ρ_n \\
⋮ \\
ρ_1 \\
ρ_0 \\
\end{matrix}\right] = ρ_0 · \left[\begin{matrix}
a_{m,0} \\
⋮ \\
a_{1,0} \\
a_{0,0} \\
\end{matrix}\right] + ρ_1 · \left[\begin{matrix}
a_{m,1} \\
⋮ \\
a_{m,1} \\
a_{m,0} \\
\end{matrix}\right] + ⋯ + ρ_n · \left[\begin{matrix}
a_{m,n} \\
⋮ \\
a_{1,n} \\
a_{0,n} \\
\end{matrix}\right] \\
\left[\begin{matrix}
0 \\
⋮ \\
0 \\
0 \\
\end{matrix}\right] &= \left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
ϱ_n - ρ_n \\
⋮ \\
ϱ_1 - ρ_1 \\
ϱ_0 - ρ_0 \\
\end{matrix}\right] \\
\left[\begin{matrix}
b_m \\
⋮ \\
b_1 \\
b_0 \\
\end{matrix}\right] &= \left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
ρ_n + u_n \\
⋮ \\
ρ_1 + u_1 \\
ρ_0 + u_0 \\
\end{matrix}\right] = \left[\begin{matrix}
a_{m,0} & a_{m,1} & ⋯ & a_{m,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
a_{1,0} & a_{1,1} & ⋯ & a_{1,n} \\
a_{0,0} & a_{0,1} & ⋯ & a_{0,n} \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] \\
\end{aligned}
$$

典例：求非齐次线性代数方程组的通解。

$$
\begin{aligned}
\left[\begin{matrix}
-3 \\
1 \\
6 \\
7 \\
\end{matrix}\right] &= \left[\begin{matrix}
1 & 2 & 3 & 4 \\
1 & 2 & 0 & -5 \\
2 & 4 & -3 & -19 \\
3 & 6 & -3 & -24 \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
x_3 \\
x_2 \\
x_1 \\
x_0 \\
\end{matrix}\right] = \left[\begin{matrix}
1 · x_0 + 2 · x_1 + 3 · x_2 + 4 · x_3 \\
1 · x_0 + 2 · x_1 + 0 · x_2 - 5 · x_3 \\
2 · x_0 + 4 · x_1 - 3 · x_2 - 19 · x_3 \\
3 · x_0 + 6 · x_1 - 3 · x_2 - 24 · x_3 \\
\end{matrix}\right] \\
\tilde{A}_{(1+3)×(2+3)} &= \left[\begin{array}{c|ccc}
-3 & 1 & 2 & 3 & 4 \\
1 & 1 & 2 & 0 & -5 \\
6 & 2 & 4 & -3 & -19 \\
7 & 3 & 6 & -3 & -24 \\
\end{array}\right] ≈ \left[\begin{array}{c|ccc}
-\frac{4}{3} & 0 & 0 & 1 & 3 \\
1 & 1 & 2 & 0 & -5 \\
\end{array}\right] \mathop{≈≈≈≈≈≈≈}\limits^{\langle +1,x_0,x_2,x_1,x_3 \rangle} \left[\begin{array}{c|ccc}
-\frac{4}{3} & 0 & 1 & 0 & 3 \\
1 & 1 & 0 & 2 & -5 \\
\end{array}\right] \\
\left[\begin{matrix}
x_3 \\
x_1 \\
x_2 \\
x_0 \\
\end{matrix}\right] &= \left[\begin{array}{c|cc}
0 & 0 & 1 \\
0 & 1 & 0 \\
\hline
-\frac{4}{3} & 0 & -3 \\
1 & -2 & 5 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
x_3 \\
x_1 \\
+1 \\
\end{matrix}\right] = \left[\begin{matrix}
0 \\
0 \\
\frac{4}{3} \\
1 \\
\end{matrix}\right] + x_1 · \left[\begin{matrix}
0 \\
1 \\
0 \\
-2 \\
\end{matrix}\right] + x_2 · \left[\begin{matrix}
1 \\
0 \\
-3 \\
5 \\
\end{matrix}\right] \\
\end{aligned}
$$

典例：$1$元$n$方多项式集$\lbrace ∀a_i∈F; f\langle x \rangle = a_0 · x^0 + a_1 · x^1 + ⋯ + a_n · x^n \rbrace$也即$\lbrace ∀f; f\langle x \rangle \rbrace$是线性空间，其基向量组是$\lbrace x^0, x^1, ⋯, x^n \rbrace_{(1)×(1+n)}$。注意：$x^n$是变化的量。

典例：复数集$ℤ ≡ \lbrace ∀z∈ℤ; z \rbrace ≡ \lbrace ∀a∈ℝ;∀b∈ℝ; τ · a + b \rbrace$，在数域$ℤ$上的基向量组是$\lbrace 1 \rbrace_{(1)×(1)}$，其维数是$1$，在数域$ℝ$上的基向量组是$\lbrace 1, τ \rbrace_{(1+1)×(1+1)}$，其维数是$2$。

### 线性变换

两个线性空间的同态敛射$\mathrm{Homomorphism}\langle \lbrace ∀\bold{w}; \bold{w} \rbrace_{(1+m)} ↢ \lbrace ∀\bold{v}; \bold{v} \rbrace_{(1+n)} \rangle$，向量$\bold{w}$与向量$\bold{v}$的维数未必相等$(1 + m) \not≡ (1 + n)$。同构映射的运算性质更强于同态敛射。

$$
\begin{aligned}
&两个线性空间的同态敛射\mathrm{Homomorphism}\langle \lbrace ∀\bold{w}; \bold{w} \rbrace_{(1+m)} ↢ \lbrace ∀\bold{v}; \bold{v} \rbrace_{(1+n)} \rangle的运算性质，共计3个。 \\
&\begin{array}{ll}
[满足位加性] & \mathrm{H}\langle \bold{v}_i + \bold{v}_j \rangle = \mathrm{H}\langle \bold{v}_i \rangle + \mathrm{H}\langle \bold{v}_j \rangle \\
[满足量乘性] & \mathrm{H}\langle k · \bold{v}_i \rangle = k · \mathrm{H}\langle \bold{v}_i \rangle \\
[满足敛射性] & ∀\bold{v} ∈ \lbrace ∀\bold{v}; \bold{v} \rbrace; Ⅎ\bold{w} ∈ \lbrace ∀\bold{w}; \bold{w} \rbrace; \langle \bold{w}, \bold{v} \rangle ∈ \mathrm{I} \\
[不足双射性] & [\bold{w} = \mathrm{H}\langle \lbrace ∀\bold{u};\bold{u} \rbrace \rangle] ⇔ [{^\imath}\mathrm{H}\langle \bold{w} \rangle = \lbrace ∀\bold{u}; \bold{u} \rbrace] \\
\end{array} \\
\\
&两个线性空间的同构映射\mathrm{Isomorphism}\langle \lbrace ∀\bold{w}; \bold{w} \rbrace_{(1+m)} ⇼ \lbrace ∀\bold{v}; \bold{v} \rbrace_{(1+n)} \rangle的运算性质，共计4个。 \\
&\begin{array}{ll}
[满足位加性] & \mathrm{H}\langle \bold{v}_i + \bold{v}_j \rangle = \mathrm{H}\langle \bold{v}_i \rangle + \mathrm{H}\langle \bold{v}_j \rangle \\
[满足量乘性] & \mathrm{H}\langle k · \bold{v}_i \rangle = k · \mathrm{H}\langle \bold{v}_i \rangle \\
[满足映射性] & [∀\bold{v} ∈ \lbrace ∀\bold{v}; \bold{v} \rbrace; Ⅎ\bold{w} ∈ \lbrace ∀\bold{w}; \bold{w} \rbrace; \langle \bold{w}, \bold{v} \rangle ∈ \mathrm{I}] ∧ [∀\bold{w} ∈ \lbrace ∀\bold{w}; \bold{w} \rbrace; Ⅎ\bold{v} ∈ \lbrace ∀\bold{v}; \bold{v} \rbrace; \langle \bold{w}, \bold{v} \rangle ∈ \mathrm{I}] \\
[满足双射性] & [\bold{w} = \mathrm{H}\langle \bold{v} \rangle] ⇔ [{^\imath}\mathrm{H}\langle \bold{w} \rangle = \bold{v}] \\
\end{array} \\
\end{aligned}
$$

两个线性空间的同态敛射，将零向量$\bold{0}$敛射到零向量$\bold{0} = \mathrm{H}\langle \bold{0} \rangle$。注意：每个线性空间中的零向量都唯一确定。

$$
\begin{aligned}
\mathrm{H}\langle \bold{0} \rangle &= \mathrm{H}\langle \bold{0} + \bold{0} \rangle = \mathrm{H}\langle \bold{0} \rangle + \mathrm{H}\langle \bold{0} \rangle \\
\bold{0} &= \mathrm{H}\langle \bold{0} \rangle \\
\end{aligned}
$$

两个线性空间的同构映射，将线性无关向量集$\lbrace ∀i; \bold{v}_i \rbrace$映射到线性无关向量集$\mathrm{I}\langle \lbrace ∀i; \bold{v}_i \rbrace \rangle$，将基向量组$\lbrace ∀i; \bold{e}_i \rbrace$映射到基向量组$\mathrm{I}\langle ∀i; \bold{e}_i \rangle$。注意：同态敛射并不满足双射性。

两个线性空间的同构映射，此两个线性空间的维数必相等$\mathrm{Dime}\langle \lbrace ∀\bold{v};\bold{v} \rbrace \rangle = \mathrm{Rank}\langle \lbrace ∀i; \bold{e}_i \rbrace \rangle = \mathrm{Rank}\langle \mathrm{I}\langle \lbrace ∀i; \bold{e}_i \rbrace \rangle \rangle = \mathrm{Dime}\langle \lbrace ∀\bold{w};\bold{w} \rbrace \rangle$。注意：同态敛射并不满足双射性。

$$
\begin{aligned}
\left[\begin{matrix}
0 \\
⋮ \\
0 \\
0 \\
\end{matrix}\right] &= \left[\begin{matrix}
\bold{v}_0 & \bold{v}_1 & ⋯ & \bold{v}_n \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
χ_n \\
⋮ \\
χ_1 \\
χ_0 \\
\end{matrix}\right] = \bold{v}_0 · χ_0 + \bold{v}_1 · χ_1 + ⋯ + \bold{v}_n · χ_n \\
\left[\begin{matrix}
0 \\
⋮ \\
0 \\
0 \\
\end{matrix}\right] &= \left[\begin{matrix}
\mathrm{I}\langle \bold{v}_0 \rangle & \mathrm{I}\langle \bold{v}_1 \rangle & ⋯ & \mathrm{I}\langle \bold{v}_n \rangle \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
χ_n \\
⋮ \\
χ_1 \\
χ_0 \\
\end{matrix}\right] = \mathrm{I}\langle \bold{v}_0 · χ_0 \rangle + \mathrm{I}\langle \bold{v}_1 · χ_1 \rangle + ⋯ + \mathrm{I}\langle \bold{v}_n · χ_n \rangle = \mathrm{I}\langle \bold{v}_0 · χ_0 + \bold{v}_1 · χ_1 + ⋯ + \bold{v}_n · χ_n \rangle \\
\end{aligned}
$$

两个线性空间的同构映射，由基向量组$\lbrace ∀i; \bold{e}_i \rbrace_{(1+n)×(1+n)}$过渡到基向量组$\lbrace ∀i; \bold{r}_i \rbrace_{(1+n)×(1+n)}$的坐标转换，其中基向量$\bold{r}_i$对于基向量组$\lbrace ∀i; \bold{e}_i \rbrace$的映射坐标为$\bold{r}_i = \left[\begin{matrix} r_{i,n} \\ ⋮ \\ r_{i,0} \\ \end{matrix}\right]$。

$$
\begin{aligned}
\mathrm{I}\left\langle\left[\begin{matrix}
v_n \\
⋮ \\
v_1 \\
v_0 \\
\end{matrix}\right]\right\rangle &= \mathrm{I}\left\langle\left[\begin{matrix}
\bold{e}_0 & \bold{e}_1 & ⋯ & \bold{e}_n \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right]\right\rangle \\
\left[\begin{matrix}
y_n \\
⋮ \\
y_1 \\
y_0 \\
\end{matrix}\right] &= \left[\begin{matrix}
\mathrm{I}\langle \bold{e}_0 \rangle & \mathrm{I}\langle \bold{e}_1 \rangle & ⋯ & \mathrm{I}\langle \bold{e}_n \rangle \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] = \left[\begin{matrix}
\bold{r}_0 & \bold{r}_1 & ⋯ & \bold{r}_n \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] \\
\left[\begin{matrix}
y_n \\
⋮ \\
y_1 \\
y_0 \\
\end{matrix}\right] &= \left[\begin{matrix}
r_{0,n} & r_{1,n} & ⋯ & r_{n,n} \\
⋮ & ⋮ & ⋰ & ⋮ \\
r_{0,1} & r_{1,1} & ⋯ & r_{n,1} \\
r_{0,0} & r_{1,0} & ⋯ & r_{n,0} \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
x_n \\
⋮ \\
x_1 \\
x_0 \\
\end{matrix}\right] = \left[\begin{matrix}
r_{0,n} · x_0 + r_{1,n} · x_1 + ⋯ + r_{n,n} · x_n \\
⋮ \\
r_{0,1} · x_0 + r_{1,1} · x_1 + ⋯ + r_{n,1} · x_n \\
r_{0,0} · x_0 + r_{1,0} · x_1 + ⋯ + r_{n,0} · x_n \\
\end{matrix}\right] \\
\end{aligned}
$$

典例：实数域$ℝ$上的线性空间，若向量集$\lbrace \bold{v}_0, \bold{v}_1, \bold{v}_2 \rbrace$线性无关，则向量集$\lbrace \bold{v}_0 + \bold{v}_1, \bold{v}_1 + \bold{v}_2, \bold{v}_2 + \bold{v}_0 \rbrace$线性无关。注意：线性无关向量组都可以同构映射到单位基向量组。

$$
\begin{aligned}
\left[\begin{array}{c|c|c}
0 & 0 & 1 \\
0 & 1 & 0 \\
1 & 0 & 0 \\
\end{array}\right] &= \mathrm{I}\langle [\bold{v}_0, \bold{v}_1, \bold{v}_2] \rangle \\
\left[\begin{matrix}
0 & 0 & 1 \\
0 & 1 & 0 \\
1 & 0 & 0 \\
\end{matrix}\right] ≈ \left[\begin{array}{c|c|c}
0 & 1 & 1 \\
1 & 1 & 0 \\
1 & 0 & 1 \\
\end{array}\right] &= \mathrm{I}\langle [\bold{v}_0 + \bold{v}_1, \bold{v}_1 + \bold{v}_2, \bold{v}_2 + \bold{v}_0] \rangle \\
\end{aligned}
$$

### 线性空间的运算性质

线性空间$V$与线性空间$W$的交集$V \cap W$，必定是线性空间。线性空间$U$的子集线性空间$V$与子集线性空间$W$的交集$V \cap W$，是线性空间$U$的子集线性空间。

注意：线性空间$V$与线性空间$W$的合集$V \cup W$，未必是线性空间。

$$
\begin{aligned}
&\begin{array}{|cl}
⇓ & [\lbrace \bold{v}, \bold{w} \rbrace ∈ V \cap W] \\
⇒ & [\bold{v} ∈ V] ∧ [\bold{w} ∈ V] ∧ [\bold{v} ∈ W] ∧ [\bold{w} ∈ W] \\
⇒ & [(\bold{v} + \bold{w}) ∈ V] ∧ [(\bold{v} + \bold{w}) ∈ W] \\
⇒ & [(\bold{v} + \bold{w}) ∈ V \cap W] \\
\end{array} \\
\hline
&\begin{array}{|cl}
⇓ & [\bold{v} ∈ V \cap W] \\
⇒ & [\bold{v} ∈ V] ∧ [\bold{v} ∈ W] \\
⇒ & [k · \bold{v} ∈ V] ∧ [k · \bold{v} ∈ W] \\
⇒ & [k · \bold{v} ∈ V] \\
\end{array} \\
\end{aligned}
$$

约定：线性空间$V$与线性空间$W$的位加集$V + W$，是包含$V \cup W$的最小线性空间，也即$V + W ≡ \mathrm{Linear}\langle V \cup W \rangle$。

若线性空间$V$的基向量组$\lbrace ∀\bold{e}_{V}; \bold{e}_V \rbrace$与线性空间$W$的基向量组$\lbrace ∀\bold{e}_{W}; \bold{e}_W \rbrace$满足线性无关性，当且仅当其交集的基向量组$\lbrace ∀\bold{e}_{V \cap W}; \bold{e}_{V \cap W} \rbrace = Ø$，当且仅当其交集$V \cap W = \lbrace 0 \rbrace$。

线性空间$V$与线性空间$W$的位加集$V + W$，必满足$\mathrm{Dime}\langle V + W \rangle = \mathrm{Dime}\langle V \rangle + \mathrm{Dime}\langle W \rangle - \mathrm{Dime}\langle V \cap W \rangle ≤ \mathrm{Dime}\langle V \rangle + \mathrm{Dime}\langle W \rangle$，等号成立当且仅当$V \cap W = \lbrace \bold{0} \rbrace$。

推论：线性空间$U$的子集线性空间$V$与子集线性空间$W$的交集$V \cap W$，必满足$\mathrm{Dime}\langle V \cap W \rangle ≥ \mathrm{Dime}\langle V \rangle + \mathrm{Dime}\langle W \rangle - \mathrm{Dime}\langle U \rangle$，等号成立当且仅当$V + W = U$。

约定：若线性空间$U$的子集线性空间$V$与子集线性空间$W$，满足互斥性$V \cap W = \lbrace 0 \rbrace$，且满足互补性$V + W = U$，则子集线性空间$V$与子集线性空间$W$关于线性空间$U$互补。

推论：子集线性空间$V$与子集线性空间$W$关于线性空间$U$互补，当且仅当$\mathrm{Dime}\langle \lbrace ∀\bold{e}_{V \cap W}; \bold{e}_{V \cap W} \rbrace \rangle = 0$，并且$\mathrm{Dime}\langle \lbrace ∀\bold{e}_{V \cup W}; \bold{e}_{V \cup W} \rbrace \rangle = \mathrm{Dime}\langle \lbrace ∀\bold{e}_U; \bold{e}_U \rbrace \rangle$。

$$
\begin{aligned}
V + W &≡ \mathrm{Linear}\langle V \cup W \rangle \mathop{================}\limits^{\lbrace ∀\bold{e}_{V\cup W}; \bold{e}_{V\cup W} \rbrace ≈ \lbrace ∀\bold{e}_{V}; \bold{e}_V \rbrace \cup \lbrace ∀\bold{e}_W; \bold{e}_W \rbrace} \mathrm{Linear}\langle \lbrace ∀\bold{e}_{V}; \bold{e}_V \rbrace \cup \lbrace ∀\bold{e}_W; \bold{e}_W \rbrace \rangle \\
\mathrm{Dime}\langle V + W \rangle &= \mathrm{Rank}\langle \lbrace ∀\bold{e}_{V}; \bold{e}_V \rbrace \cup \lbrace ∀\bold{e}_W; \bold{e}_W \rbrace \rangle = \mathrm{Rank}\langle \lbrace ∀\bold{e}_{V}; \bold{e}_V \rbrace \rangle + \mathrm{Rank}\langle \lbrace ∀\bold{e}_{W}; \bold{e}_W \rbrace \rangle - \mathrm{Rank}\langle \lbrace ∀\bold{e}_{V \cap W}; \bold{e}_{V \cap W} \rbrace \rangle \\
\mathrm{Dime}\langle V + W \rangle &= \mathrm{Dime}\langle V \rangle + \mathrm{Dime}\langle W \rangle - \mathrm{Dime}\langle V \cap W \rangle ≤ \mathrm{Dime}\langle V \rangle + \mathrm{Dime}\langle W \rangle \\
\mathrm{Dime}\langle V \cap W \rangle &= \mathrm{Dime}\langle V \rangle + \mathrm{Dime}\langle W \rangle - \mathrm{Dime}\langle V + W \rangle ≥ \mathrm{Dime}\langle V \rangle + \mathrm{Dime}\langle W \rangle - \mathrm{Dime}\langle U \rangle \\
\end{aligned}
$$

典例：两个线性代数方程组的解集的交集。

$$
\begin{aligned}
&\left\lbrace\begin{aligned}
5 &= 1 · x_0 + 2 · x_1 + 7 · x_2 + 5 · x_3 - 4 · x_4 \\
2 &= 0 · x_0 + 1 · x_1 + 4 · x_2 + 3 · x_3 - 1 · x_4 \\
\end{aligned}\right. \\
&\left\lbrace\begin{aligned}
1 &= 1 · x_0 + 1 · x_1 + 1 · x_2 - 1 · x_3 - 1 · x_4 \\
0 &= 0 · x_0 + 1 · x_1 + 2 · x_2 + 0 · x_3 + 1 · x_4 \\
\end{aligned}\right. \\
&\left[\begin{matrix}
\tilde{A}_1 \\
\hline
\tilde{A}_0 \\
\end{matrix}\right] = \left[\begin{array}{c|ccccc}
5 & 1 & 2 & 7 & 5 & -4 \\
2 & 0 & 1 & 4 & 3 & -1 \\
\hline
1 & 1 & 1 & 1 & -1 & -1 \\
0 & 0 & 1 & 2 & 0 & 1 \\
\end{array}\right] ≈ \left[\begin{array}{c|ccccc}
1 & 0 & 0 & 1 & \frac{3}{2} & -1 \\
-2 & 0 & 1 & 0 & -3 & 3 \\
2 & 1 & 0 & 0 & \frac{1}{2} & -3 \\
\end{array}\right] \\
&\left[\begin{matrix}
x_4 \\
x_3 \\
x_2 \\
x_1 \\
x_0 \\
\end{matrix}\right] = \left[\begin{array}{c|cc}
0 & 0 & 1 \\
0 & 1 & 0 \\
\hline
1 & -\frac{3}{2} & 1 \\
-2 & 3 & -3 \\
2 & -\frac{1}{2} & 3 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
x_4 \\
x_3 \\
+1 \\
\end{matrix}\right] = \left[\begin{matrix}
0 \\
0 \\
1 \\
-2 \\
2 \\
\end{matrix}\right] + x_3 · \left[\begin{matrix}
0 \\
1 \\
-\frac{3}{2} \\
3 \\
-\frac{1}{2} \\
\end{matrix}\right] + x_4 · \left[\begin{matrix}
1 \\
0 \\
1 \\
-3 \\
3 \\
\end{matrix}\right] \\
\end{aligned}
$$

典例：


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
\end{matrix}\right]}\limits_{(1+m)×(1+n)} = c \boxplus \mathop{\left[\begin{matrix}
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

$(1+m)×(1+n)$元矩阵与$(1+m)×(1+n)$元矩阵的点乘运算。矩阵的点乘运算必满足交换律。

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
{'}\mathrm{C}_{(l+1)×(1+n)} &= {'}\mathrm{A}_{(1+m)×(1+n)} \rlap{×}{+} {'}\mathrm{B}_{(l+1)×(1+m)} \\
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
\end{matrix}\right] = c \boxplus \left[\begin{matrix}
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
