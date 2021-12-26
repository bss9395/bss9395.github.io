---
layout:  zh_post
Topic :  收敛极限
Title :  拟合插值
Update:  2021-12-27T00:07:00+08@中国-广东-深圳+08
Author:  璀璨星辰
Link  :
---

### 特别注意

```
本书中约定圆括号()强调运算优先级，运算本身具有优先级，示例：(u + v) × w。
本书中约定方括号[]表示矩阵与向量，方括号也用于逻辑学，示例：[w, x, y, z]。
本书中约定花括号{}表示无序的集合，集合中的元素不重复，示例：{η₀, η₁, η₂, η₃}。
本书中约定尖括号<>表示有序的序列，序列中的元素可重复，示例：<out, in, in, extra>。
```

### 线性插值法

$$
\begin{aligned}
\bold{0} &= \left\lVert\begin{matrix}
\bold{v}_0 & \bold{l}\langle t \rangle & \bold{v}_1 \\
t_0 & t & t_1 \\
1 & 1 & 1 \\
\end{matrix}\right\rVert = \left\lVert\begin{matrix}
\bold{v}_0 & \bold{l}\langle t \rangle - \bold{v}_0 & \bold{v_1} - \bold{v_0} \\
t_0 & t - t_0 & t_1 - t_0 \\
1 & 0 & 0 \\
\end{matrix}\right\rVert \\
\bold{l}\langle t \rangle &= \dfrac{t_1 - t}{t_1 - t_0} · \bold{v}_0 + \dfrac{t - t_0}{t_1 - t_0} · \bold{v_1} = \bold{v}_0 + \dfrac{t - t_0}{t_1 - t_0} · (\bold{v}_1 - \bold{v}_0) \\
l \langle x \rangle &= \dfrac{x_1 - x}{x_1 - x_0} · f\langle x_0 \rangle + \dfrac{x - x_0}{x_1 - x_0} · f\langle x_1 \rangle = f\langle x_0 \rangle + \dfrac{x - x_0}{x_1 - x_0} · (f\langle x_1 \rangle - f\langle x_0 \rangle) \\
\end{aligned}
$$

### 球面线性插值法

$$
\begin{aligned}
\bold{v}\langle \varphi_t \rangle &= \dfrac{\sin(\varphi_1 - \varphi_t)}{\sin(\varphi_1 - \varphi_0)} · \bold{v}_0 + \dfrac{\sin(\varphi_t - \varphi_0)}{\sin(\varphi_1 - \varphi_0)} · \bold{v}_1 \\


\end{aligned}
$$



### 四元数插值法

四元数插值法分别对旋转角度与度量值进行线性插值。

$$
\left\lbrace\begin{aligned}
\vec{v} \odot \vec{u} &= |\vec{v}| · |\vec{u}| · \cos∠(\vec{v},\vec{u}) \\
\vec{v} \otimes \vec{u} &= \vec{n}_{⊥} · |\vec{v}| · |\vec{u}| · \sin∠(\vec{v},\vec{u}) \\
\end{aligned}\right. \\
$$

$$
\begin{aligned}
ә^{\vec{n}_{⊥} · \varphi · t} &\mathop{==} \cos(\varphi · t) + \vec{n}_{⊥} · \sin(\varphi · t) \\
&\mathop{==} \cos(\varphi · t) + \dfrac{\vec{v} \otimes \vec{u}}{|\vec{v}| · |\vec{u}|} · \dfrac{\sin(\varphi · t)}{\sin\varphi} = \dfrac{\sin(\varphi · t)}{|\vec{v}| · |\vec{u}| · \sin\varphi} · \left( \dfrac{|\vec{v}| · |\vec{u}| · \sin\varphi}{\tan(\varphi · t)} + \vec{v} \otimes \vec{u} \right) \\
&\mathop{==} \frac{\sin(\varphi · t)}{|\vec{v}| · |\vec{u}| · \sin\varphi} · \left[\begin{matrix}
v_x · u_y - v_y · u_x \\
v_z · u_x - v_x · u_z \\
v_y · u_z - v_z · u_y \\
\hline
\frac{|\vec{v}|·|\vec{u}|·\sin\varphi}{\tan(\varphi · t)} \\
\end{matrix}\right] \mathop{≈≈} \frac{\sin(\varphi · t)}{|\vec{v}| · |\vec{u}| · \sin\varphi} · \left[\begin{array}{c|ccc}
\rlap{+q_z}{≡≡} & -q_y & +q_x & +q_w \\
\rlap{+q_y}{≡≡} & +q_z & +q_w & -q_x \\
\rlap{+q_x}{≡≡} & +q_w & -q_z & +q_y \\
\hline
+q_w & \rlap{-q_x}{≡≡} & \rlap{-q_y}{≡≡} & \rlap{-q_z}{≡≡} \\
\end{array}\right] \\
&\mathop{≈≈} \frac{\sin(\varphi · t)}{|\vec{v}| · |\vec{u}| · \sin\varphi} · \left[\begin{array}{c|ccc}
+(v_x · u_y - v_y · u_x) & -(v_z · u_x - v_x · u_z) & +(v_y · u_z - v_z · u_y) & \frac{|\vec{v}|·|\vec{u}|·\sin\varphi}{\tan(\varphi · t)} \\
+(v_z · u_x - v_x · u_z) & +(v_x · u_y - v_y · u_x) & \frac{|\vec{v}|·|\vec{u}|·\sin\varphi}{\tan(\varphi · t)} & -(v_y · u_z - v_z · u_y) \\
+(v_y · u_z - v_z · u_y) & \frac{|\vec{v}|·|\vec{u}|·\sin\varphi}{\tan(\varphi · t)} & -(v_x · u_y - v_y · u_x) & +(v_z · u_x - v_x · u_z) \\
\hline
\frac{|\vec{v}|·|\vec{u}|·\sin\varphi}{\tan(\varphi · t)} & -(v_y · u_z - v_z · u_y) & -(v_z · u_x - v_x · u_z) & +(v_x · u_y - v_y · u_x) \\
\end{array}\right] \\
\left(\dfrac{1 - t}{1 - 0} · 1 + \dfrac{t - 0}{1 - 0} · \dfrac{|\vec{u}|}{|\vec{v}|}\right) · ә^{\vec{n}_{⊥} · \varphi · t} &\mathop{==} \left(1 - t + t · \dfrac{|\vec{u}|}{|\vec{v}|}\right) · \dfrac{\sin(\varphi · t)}{|\vec{v}| · |\vec{u}| · \sin\varphi} · \left[\begin{matrix}
v_x · u_y - v_y · u_x \\
v_z · u_x - v_x · u_z \\
v_y · u_z - v_z · u_y \\
\hline
\frac{|\vec{v}|·|\vec{u}|·\sin\varphi}{\tan(\varphi · t)} \\
\end{matrix}\right] \\
&\mathop{≈≈} \left(1 - t + t · \dfrac{|\vec{u}|}{|\vec{v}|}\right) · \frac{\sin(\varphi · t)}{|\vec{v}| · |\vec{u}| · \sin\varphi} · \left[\begin{array}{c|ccc}
+(v_x · u_y - v_y · u_x) & -(v_z · u_x - v_x · u_z) & +(v_y · u_z - v_z · u_y) & \frac{|\vec{v}|·|\vec{u}|·\sin\varphi}{\tan(\varphi · t)} \\
+(v_z · u_x - v_x · u_z) & +(v_x · u_y - v_y · u_x) & \frac{|\vec{v}|·|\vec{u}|·\sin\varphi}{\tan(\varphi · t)} & -(v_y · u_z - v_z · u_y) \\
+(v_y · u_z - v_z · u_y) & \frac{|\vec{v}|·|\vec{u}|·\sin\varphi}{\tan(\varphi · t)} & -(v_x · u_y - v_y · u_x) & +(v_z · u_x - v_x · u_z) \\
\hline
\frac{|\vec{v}|·|\vec{u}|·\sin\varphi}{\tan(\varphi · t)} & -(v_y · u_z - v_z · u_y) & -(v_z · u_x - v_x · u_z) & +(v_x · u_y - v_y · u_x) \\
\end{array}\right] \\
\end{aligned}
$$
