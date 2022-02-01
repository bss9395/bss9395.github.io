---
layout: zh_post
Topic : 收敛极限
Title : 经典案例
Update: 2022-02-01T23:26:00+08@中国-广东-湛江+08
Author: 璀璨星辰
Credit: 《线性代数（数学专业用）》李尚志
Notice: 本书限于本人能力范围，如果有疏漏之处请联系，brilliantstarrysky9395@gmail.com
---

### 幻方游戏

将正整数$1, 2, ⋯, 25$填入$5 × 5$阶幻方，使每行每列以及每条对角线上$5$个数之和相等。注意：循环数列之和必相等。

$$
\begin{aligned}
\lbrace 1, 2, ⋯, 25 \rbrace &= 5 · \lbrace 0, 1, 2, 3, 4 \rbrace + \lbrace 1, 2, 3, 4, 5 \rbrace \\
\begin{array}{|c|c|c|c|c|}
\hline
15 & 20 & 0 & 5 & \fbox{10} \\
\hline
5 & 10 & 15 & \fbox{20} & 0 \\
\hline
20 & 0 & \fbox{5} & 10 & 15 \\
\hline
10 & \fbox{15} & 20 & 0 & 5 \\
\hline
\fbox{0} & \fbox{5} & \fbox{10} & \fbox{15} & \fbox{20} \\
\hline
\end{array} &= 5 · \begin{array}{|c|c|c|c|c|}
\hline
3 & 4 & 0 & 1 & \fbox{2} \\
\hline
1 & 2 & 3 & \fbox{4} & 0 \\
\hline
4 & 0 & \fbox{1} & 2 & 3 \\
\hline
2 & \fbox{3} & 4 & 0 & 1 \\
\hline
\fbox{0} & \fbox{1} & \fbox{2} & \fbox{3} & \fbox{4} \\
\hline
\end{array} \\
\begin{array}{|c|c|c|c|c|}
\hline
17 & 23 & 4 & 5 & \fbox{11} \\
\hline
9 & 10 & 16 & \fbox{22} & 3 \\
\hline
21 & 2 & \fbox{8} & 14 & 15 \\
\hline
13 & \fbox{19} & 20 & 1 & 7 \\
\hline
\fbox{0} & \fbox{6} & \fbox{12} & \fbox{18} & \fbox{24} \\
\hline
\end{array} &= 5 · \begin{array}{|c|c|c|c|c|}
\hline
3 & 4 & 0 & 1 & \fbox{2} \\
\hline
1 & 2 & 3 & \fbox{4} & 0 \\
\hline
4 & 0 & \fbox{1} & 2 & 3 \\
\hline
2 & \fbox{3} & 4 & 0 & 1 \\
\hline
\fbox{0} & \fbox{1} & \fbox{2} & \fbox{3} & \fbox{4} \\
\hline
\end{array} + \begin{array}{|c|c|c|c|c|}
\hline
2 & 3 & 4 & 0 & \fbox{1} \\
\hline
4 & 0 & 1 & \fbox{2} & 3 \\
\hline
1 & 2 & \fbox{3} & 4 & 0 \\
\hline
3 & \fbox{4} & 0 & 1 & 2 \\
\hline
\fbox{0} & \fbox{1} & \fbox{2} & \fbox{3} & \fbox{4} \\
\hline
\end{array} \\
\begin{array}{|c|c|c|c|c|}
\hline
18 & 24 & 5 & 6 & \fbox{12} \\
\hline
10 & 11 & 17 & \fbox{23} & 4 \\
\hline
22 & 3 & \fbox{9} & 15 & 16 \\
\hline
14 & \fbox{20} & 21 & 2 & 8 \\
\hline
\fbox{1} & \fbox{7} & \fbox{13} & \fbox{19} & \fbox{25} \\
\hline
\end{array} &= 5 · \begin{array}{|c|c|c|c|c|}
\hline
3 & 4 & 0 & 1 & \fbox{2} \\
\hline
1 & 2 & 3 & \fbox{4} & 0 \\
\hline
4 & 0 & \fbox{1} & 2 & 3 \\
\hline
2 & \fbox{3} & 4 & 0 & 1 \\
\hline
\fbox{0} & \fbox{1} & \fbox{2} & \fbox{3} & \fbox{4} \\
\hline
\end{array} + \begin{array}{|c|c|c|c|c|}
\hline
2 & 3 & 4 & 0 & \fbox{1} \\
\hline
4 & 0 & 1 & \fbox{2} & 3 \\
\hline
1 & 2 & \fbox{3} & 4 & 0 \\
\hline
3 & \fbox{4} & 0 & 1 & 2 \\
\hline
\fbox{0} & \fbox{1} & \fbox{2} & \fbox{3} & \fbox{4} \\
\hline
\end{array} + \begin{array}{|c|c|c|c|c|}
\hline
1 & 1 & 1 & 1 & \fbox{1} \\
\hline
1 & 1 & 1 & \fbox{1} & 1 \\
\hline
1 & 1 & \fbox{1} & 1 & 1 \\
\hline
1 & \fbox{1} & 1 & 1 & 1 \\
\hline
\fbox{1} & \fbox{1} & \fbox{1} & \fbox{1} & \fbox{1} \\
\hline
\end{array} \\
\end{aligned}
$$

### 剩余定理

取余代数方程$\left\lbrace\begin{aligned}
r_3 &= x \mathop{\%} 7 \\
r_2 &= x \mathop{\%} 5 \\
r_1 &= x \mathop{\%} 3 \\
\end{aligned}\right.$的解集$\lbrace ∀x; x \rbrace$。注意：解集$\lbrace ∀x; x \rbrace$不是线性空间而是模余空间，其同态敛射不是线性空间而是模余空间。

$$
\begin{aligned}
\mathrm{Homo}\langle x \rangle &≡ \left[\begin{matrix}
x \mathop{\%} 7 \\
x \mathop{\%} 5 \\
x \mathop{\%} 3 \\
\end{matrix}\right] \\
\mathrm{Homo}\langle x + y \rangle &≡ \left[\begin{matrix}
(x + y) \mathop{\%} 7 \\
(x + y) \mathop{\%} 5 \\
(x + y) \mathop{\%} 3 \\
\end{matrix}\right] ≡ \left[\begin{matrix}
x \mathop{\%} 7 \\
x \mathop{\%} 5 \\
x \mathop{\%} 3 \\
\end{matrix}\right] \oplus \left[\begin{matrix}
y \mathop{\%} 7 \\
y \mathop{\%} 5 \\
y \mathop{\%} 3 \\
\end{matrix}\right] \\
\mathrm{Homo}\langle k · x \rangle &≡ \left[\begin{matrix}
(k · x) \mathop{\%} 7 \\
(k · x) \mathop{\%} 5 \\
(k · x) \mathop{\%} 3 \\
\end{matrix}\right] ≡ k \odot \left[\begin{matrix}
x \mathop{\%} 7 \\
x \mathop{\%} 5 \\
x \mathop{\%} 3 \\
\end{matrix}\right] \\
\hline
\mathrm{Homo}\langle e_1 \rangle &\mathop{===}\limits^{e_1=70} \left[\begin{matrix}
0 \\
0 \\
1 \\
\end{matrix}\right] \\
\mathrm{Homo}\langle e_2 \rangle &\mathop{===}\limits^{e_1=21} \left[\begin{matrix}
0 \\
1 \\
0 \\
\end{matrix}\right] \\
\mathrm{Homo}\langle e_3 \rangle &\mathop{===}\limits^{e_1=15} \left[\begin{matrix}
1 \\
0 \\
0 \\
\end{matrix}\right] \\
\mathrm{Homo}\left\langle e_1 · r_1 + e_2 · r_2 + e_3 · r_3 \right\rangle &= r_1 \odot \left[\begin{matrix}
0 \\
0 \\
1 \\
\end{matrix}\right] \oplus r_2 \odot \left[\begin{matrix}
0 \\
1 \\
0 \\
\end{matrix}\right] \oplus r_3 \odot \left[\begin{matrix}
1 \\
0 \\
0 \\
\end{matrix}\right] = \left[\begin{matrix}
r_3 \mathop{\%} 7 \\
r_2 \mathop{\%} 5 \\
r_1 \mathop{\%} 3 \\
\end{matrix}\right] \\
x &= e_1 · r_1 + e_2 · r_2 + e_3 · r_3 = 70 · r_1 + 21 · r_2 + 15 · r_3 \\
\end{aligned}
$$

### 迭代数列

迭代数列$f_{n+2} ≡ f_{n} + f_{n+1}$初始值的解集$\left\lbrace ∀f_0;∀f_1; \left[\begin{matrix}
f_1 \\
f_0 \\
\end{matrix}\right] \right\rbrace$。注意：解集$\left\lbrace ∀f_0;∀f_1; \left[\begin{matrix}
f_1 \\
f_0 \\
\end{matrix}\right] \right\rbrace$是线性空间。

$$
\begin{aligned}
\mathrm{Iso}\left\langle \left[\begin{matrix}
f_1 \\
f_0 \\
\end{matrix}\right] \right\rangle &≡ \langle f_0, f_1, ⋯, f_n \rangle \\
\mathrm{Iso}\left\langle \left[\begin{matrix}
f_1 \\
f_0 \\
\end{matrix}\right] + \left[\begin{matrix}
g_1 \\
g_0 \\
\end{matrix}\right] \right\rangle &≡ \langle f_0 + g_0, f_1 + g_1, ⋯, f_n + g_n \rangle ≡ \langle f_0, f_1, ⋯, f_n \rangle + \langle g_0, g_1, ⋯, g_n \rangle \\
\mathrm{Iso}\left\langle k · \left[\begin{matrix}
f_1 \\
f_0 \\
\end{matrix}\right] \right\rangle &≡ \langle k · f_0, k · f_1, ⋯, k · f_n \rangle ≡ k · \langle f_0, f_1, ⋯, f_n \rangle \\
2 = \mathrm{Dime}\left\langle \left[\begin{matrix}
f_1 \\
f_0 \\
\end{matrix}\right] \right\rangle &= \mathrm{Dime}\langle \langle f_0, f_1, ⋯, f_n \rangle \rangle \\
\hline
\mathrm{Iso}\langle \bold{e}_1 \rangle = \mathrm{Iso}\left\langle \left[\begin{matrix} q_1 \\ 1 \end{matrix}\right] \right\rangle &\mathop{=======}\limits_{q_1 = \frac{1 - \sqrt{5}}{2}}^{q^{n+2} = q^{n} + q^{n+1}} \langle 1, q_1, ⋯, q_1^n \rangle \\
\mathrm{Iso}\langle \bold{e}_2 \rangle = \mathrm{Iso}\left\langle \left[\begin{matrix} q_2 \\ 1 \end{matrix}\right] \right\rangle &\mathop{=======}\limits_{q_2 = \frac{1 + \sqrt{5}}{2}}^{q^{n+2} = q^{n} + q^{n+1}} \langle 1, q_2, ⋯, q_2^n \rangle \\
\mathrm{Iso}\left\langle \bold{e}_1 · x_1 + \bold{e}_2 · x_2 \right\rangle &= \langle x_1 + x_2, q_1 · x_1 + q_2 · x_2, ⋯, q_1^n · x_1 + q_2^n · x_2 \rangle \\
\left[\begin{matrix}
f_1 \\
f_0 \\
\end{matrix}\right] &= \bold{e}_1 · x_1 + \bold{e}_2 · x_2 = \left[\begin{matrix}
q_1 \\
1 \\
\end{matrix}\right] · x_1 + \left[\begin{matrix}
q_2 \\
1 \\
\end{matrix}\right] · x_2 = \left[\begin{matrix}
\frac{1 - \sqrt{5}}{2} \\
1 \\
\end{matrix}\right] · x_1 + \left[\begin{matrix}
\frac{1 + \sqrt{5}}{2} \\
1 \\
\end{matrix}\right] · x_2 \\
\left[\begin{matrix}
x_2 \\
x_1 \\
\end{matrix}\right] &= \left[\begin{matrix}
\frac{f_1 - f_0 · q_1}{q_2 - q_1} \\
\frac{f_0 · q_2 - f_1}{q_2 - q_1} \\
\end{matrix}\right] \\
\hline
f_n &\mathop{===}\limits_{f_0 = 1}^{f_1 = 1} q_1^n · x_1 + q_2^n · x_2 \mathop{=====}\limits_{x_1 = \frac{q_2 - 1}{q_2 - q_1}}^{x_2 = \frac{1 - q_1}{q_2 - q_1}} \dfrac{q_1^n · (q_2 - 1) + q_2^n · (1 - q_1)}{q_2 - q_1} \mathop{=====}\limits_{q_2 - q_1 = \sqrt{5}}^{q_2 + q_1 = 1} \dfrac{q_2^{n+1} - q_1^{n+1}}{q_2 - q_1} = \dfrac{(1 + \sqrt{5})^n + (1 - \sqrt{5})^n}{2^n · \sqrt{5}} \\
\end{aligned}
$$

### 拟合方程

拟合$1$元$n$方多项式方程。采用线性代数方程组。当$m = n$时才有唯一解。

$$
\begin{aligned}
\left[\begin{matrix}
y_m \\
⋮ \\
y_1 \\
y_0 \\
\end{matrix}\right] &= \mathop{\left[\begin{matrix}
x_m^0 & x_m^1 & ⋯ & x_m^n \\
⋮ & ⋮  & ⋰ & ⋮ \\
x_1^0 & x_1^1 & ⋯ & x_1^n \\
x_0^0 & x_0^1 & ⋯ & x_0^n \\
\end{matrix}\right]}\limits_{(1+m)×(1+n)} \rlap{×}{+} \left[\begin{matrix}
a_n \\
⋮ \\
a_1 \\
a_0 \\
\end{matrix}\right] = \left[\begin{matrix}
a_0 · x_m^0 + a_1 · x_m^1 + ⋯ + a_n · x_m^n \\
⋮ \\
a_0 · x_1^0 + a_1 · x_1^1 + ⋯ + a_n · x_1^n \\
a_0 · x_0^0 + a_1 · x_0^1 + ⋯ + a_n · x_0^n \\
\end{matrix}\right] \\
f\langle x \rangle &≡ a_0 · x^0 + a_1 · x^1 + ⋯ + a_n · x^n \\
\end{aligned}
$$

拟合$1$元$n$方多项式方程。采用同态敛射泛函数。当$m = n$时为同构映射。

$$
\begin{aligned}
\mathrm{Homo}\langle f \rangle &≡ \left[\begin{matrix}
f\langle x_m \rangle \\
⋮ \\
f\langle x_1 \rangle \\
f\langle x_0 \rangle \\
\end{matrix}\right] \\
\mathrm{Homo}\langle f + g \rangle &= \left[\begin{matrix}
f\langle x_m \rangle + g\langle x_m \rangle \\
⋮ \\
f\langle x_1 \rangle + g\langle x_1 \rangle \\
f\langle x_0 \rangle + g\langle x_0 \rangle \\
\end{matrix}\right] = \left[\begin{matrix}
f\langle x_m \rangle \\
⋮ \\
f\langle x_1 \rangle \\
f\langle x_0 \rangle \\
\end{matrix}\right] + \left[\begin{matrix}
g\langle x_m \rangle \\
⋮ \\
g\langle x_1 \rangle \\
g\langle x_0 \rangle \\
\end{matrix}\right] \\
\mathrm{Homo}\langle k · f \rangle &= \left[\begin{matrix}
k · f\langle x_m \rangle \\
⋮ \\
k · f\langle x_1 \rangle \\
k · f\langle x_0 \rangle \\
\end{matrix}\right] = k · \left[\begin{matrix}
f\langle x_m \rangle \\
⋮ \\
f\langle x_1 \rangle \\
f\langle x_0 \rangle \\
\end{matrix}\right] \\
\hline
\mathrm{Homo}\langle e_i \rangle &= \bold{η}_i \\
e_i\langle x \rangle &\mathop{≡≡≡≡≡≡}\limits^{e_i\langle x_j \rangle = \mathop{0}\limits_{i≠j}; \mathop{1}\limits_{i=j}} \prod\limits_{j=0;i≠j}^{n} \dfrac{x - x_j}{x_i - x_j} \\
\mathrm{Homo}\langle e_0 · y_0 + e_1 · y_1 + ⋯ + e_m · y_m \rangle &= \left[\begin{matrix}
y_m \\
⋮ \\
y_1 \\
y_0 \\
\end{matrix}\right] \\
f\langle x \rangle ≡ e_0 · y_0 + e_1 · y_1 + ⋯ + e_m · y_m &= \sum\limits_{i=0}^{m} y_i · \prod\limits_{j=0;i≠j}^{n} \dfrac{x - x_j}{x_i - x_j} \\
\end{aligned}
$$
