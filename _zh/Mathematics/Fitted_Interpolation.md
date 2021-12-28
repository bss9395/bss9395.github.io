---
layout:  zh_post
Topic :  收敛极限
Title :  拟合插值
Update:  2021-12-28T00:30:00+08@中国-广东-深圳+08
Author:  璀璨星辰
Link  :
---

### 特别注意

```
本书中约定圆括号()强调运算优先级，运算本身具有优先级，示例：(u + v) × w。
本书中约定方括号[]表示矩阵与向量，方括号也用于逻辑学，示例：[w, x, y, z]。
本书中约定花括号{}表示无序的集合，集合中的元素不重复，示例：{η₀, η₁, η₂, η₃}。
本书中约定尖括号<>表示有序的序列，序列中的元素可重复，示例：<out₀, out₁, in₀, in₁, in₂, extra>。
本书中约定自变量t的典型定义域为[0,+1], 约定自变量x的典型定义域为[x₀, x₁]。
```

### 直弦线性插值法

直弦线性插值法在两点间的直弦上等间距进行线性插值。注意：圆弧线性插值法适用于任意维度的向量。

$$
\begin{aligned}
\bold{0} &= \left\lVert\begin{matrix}
\bold{v}_0 & \bold{v}_t & \bold{v}_1 \\
0 & t & 1 \\
1 & 1 & 1 \\
\end{matrix}\right\rVert = \left\lVert\begin{matrix}
\bold{v}_0 & \bold{v}_t - \bold{v}_0 & \bold{v}_1 - \bold{v}_0 \\
0 & t & 1 \\
1 & 0 & 0 \\
\end{matrix}\right\rVert \\
\bold{v}_t &= (1 - t) · \bold{v}_0 + t · \bold{v}_1 = \bold{v}_0 + t · (\bold{v}_1 - \bold{v}_0) \\
l \langle t \rangle &= (1 - t) · f\langle 0 \rangle + t · f\langle 1 \rangle = f\langle 0 \rangle + t · (f\langle 1 \rangle - f\langle 0 \rangle) \\
\end{aligned}
$$

$$
\begin{aligned}
\bold{0} &= \left\lVert\begin{matrix}
\bold{v}_0 & \bold{v}_x & \bold{v}_1 \\
x_0 & x & x_1 \\
1 & 1 & 1 \\
\end{matrix}\right\rVert = \left\lVert\begin{matrix}
\bold{v}_0 & \bold{v}_x - \bold{v}_0 & \bold{v}_1 - \bold{v}_0 \\
x_0 & x - x_0 & x_1 - x_0 \\
1 & 0 & 0 \\
\end{matrix}\right\rVert \\
\bold{v}_t &= \dfrac{x_1 - x}{x_1 - x_0} · \bold{v}_0 + \dfrac{x - x_0}{x_1 - x_0} · \bold{v}_1 = \bold{v}_0 + \dfrac{x - x_0}{x_1 - x_0} · (\bold{v}_1 - \bold{v}_0) \\
l \langle x \rangle &= \dfrac{x_1 - x}{x_1 - x_0} · f\langle x_0 \rangle + \dfrac{x - x_0}{x_1 - x_0} · f\langle x_1 \rangle = f\langle x_0 \rangle + \dfrac{x - x_0}{x_1 - x_0} · (f\langle x_1 \rangle - f\langle x_0 \rangle) \\
\end{aligned}
$$

### 圆弧线性插值法

圆弧线性插值法同时对旋转角度与度量值进行线性插值。注意：圆弧线性插值法适用于任意维度的向量，圆弧线性插值法优于四元数线性插值法。

$$
\begin{aligned}
\left\lbrace\begin{aligned}
\bold{v}_t &= α · \bold{v}_0 + β · \bold{v}_1 \\
|\bold{v}_0| · |\bold{v}_t| · \cos(t · \varphi) = \bold{v}_0 \odot \bold{v}_t &= \bold{v}_0 \odot (α · \bold{v}_0 + β · \bold{v}_1) = α · |\bold{v}_0|^2 + β · |\bold{v}_0| · |\bold{v}_1| · \cos\varphi \\
|\bold{v}_t| · |\bold{v}_1| · \cos((1 - t) · \varphi) = \bold{v}_t \odot \bold{v}_1 &= (α · \bold{v}_0 + β · \bold{v}_1) \odot \bold{v}_1 = α · |\bold{v}_0| · |\bold{v}_1| · \cos\varphi + β · |\bold{v}_1|^2 \\
\end{aligned}\right. &&⇒\left\lbrace\begin{aligned}
α &= \dfrac{|\bold{v}_t|}{|\bold{v}_0|} · \dfrac{\sin((1 - t) · \varphi)}{\sin\varphi} \\
β &= \dfrac{|\bold{v}_t|}{|\bold{v}_1|} · \dfrac{\sin(t · \varphi)}{\sin\varphi} \\
\end{aligned}\right. \\
\end{aligned}
$$

$$
\begin{aligned}
\varphi &≡ ∠(\bold{v_0},\bold{v_1}) \\
\bold{v}_t &= α · \bold{v}_0 + β · \bold{v}_1 \\
\bold{v}_t &= |\bold{v}_t| · \left( \dfrac{\bold{v}_0}{|\bold{v}_0|} · \dfrac{\sin\left( (1 - t) · \varphi \right)}{\sin\varphi} + \dfrac{\bold{v}_1}{|\bold{v}_1|} · \dfrac{\sin\left( t · \varphi \right)}{\sin\varphi} \right) \\
\bold{v}_t &= \left( (1 - t) · |\bold{v}_0| + t · |\bold{v}_1| \right) · \left( \dfrac{\bold{v}_0}{|\bold{v}_0|} · \dfrac{\sin\left( (1 - t) · \varphi \right)}{\sin\varphi} + \dfrac{\bold{v}_1}{|\bold{v}_1|} · \dfrac{\sin\left( t · \varphi \right)}{\sin\varphi} \right) \\
\bold{v}_t &= \dfrac{\frac{x_1 - x}{x_1 - x_0} · |\bold{v}_0| + \frac{x - x_0}{x_1 - x_0} · |\bold{v}_1|}{\sin\varphi} · \left( \dfrac{\bold{v}_0}{|\bold{v}_0|} · \sin\left( \dfrac{x_1 - x}{x_1 - x_0} · \varphi \right) + \dfrac{\bold{v}_1}{|\bold{v}_1|} · \sin\left( \dfrac{x - x_0}{x_1 - x_0} · \varphi \right) \right) \\
\bold{v}_t &= \dfrac{\frac{x_1 - x}{x_1 - x_0} · |\bold{v}_0| + \frac{x - x_0}{x_1 - x_0} · |\bold{v}_1|}{\sin\varphi} · \left( \bold{n}_{\bold{v}_0} · \sin\left( \dfrac{x_1 - x}{x_1 - x_0} · \varphi \right) + \bold{n}_{\bold{v}_1} · \sin\left( \dfrac{x - x_0}{x_1 - x_0} · \varphi \right) \right) \\
\end{aligned}
$$

### 四元数线性插值法

四元数插值法同时对旋转角度与度量值进行线性插值。注意：四元数线性插值法仅适用于$3$维空间矢量。

注意：若需要对四元数本身而非$3$维空间矢量进行插值，应当同时对四元数的旋转轴与旋转角进行插值。

$$
\begin{aligned}
\varphi &≡ ∠(\vec{v},\vec{u}) \\
ә^{\vec{n}_{⊥} · t · \varphi} &\mathop{=} \cos(t · \varphi) + \vec{n}_{⊥} · \sin(t · \varphi) \\
&\mathop{=} \cos(t · \varphi) + \dfrac{\vec{v} \otimes \vec{u}}{|\vec{v}| · |\vec{u}|} · \dfrac{\sin(t · \varphi)}{\sin\varphi} \\
ә^{\vec{n}_{⊥} · t · \varphi} \circledast \vec{v} &\mathop{=} \left[ \cos(t · \varphi) + \dfrac{\vec{v} \otimes \vec{u}}{|\vec{v}| · |\vec{u}|} · \dfrac{\sin(t · \varphi)}{\sin\varphi} \right] \circledast \vec{v} \\
&= \cos(t · \varphi) · \vec{v} + \dfrac{\sin(t · \varphi)}{\sin\varphi} · \left[ \dfrac{\vec{v} \otimes \vec{u} \otimes \vec{v}}{|\vec{v}| · |\vec{u}|} - \dfrac{\rlap{\vec{v} \otimes \vec{u} \odot \vec{v}}{≡≡≡≡≡}}{|\vec{v}| · |\vec{u}|} \right] \\
&= \cos(t · \varphi) · \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] + \dfrac{\sin(t · \varphi)}{\sin\varphi · |\vec{v}| · |\vec{u}|} · \left[\begin{array}{ccc}
-v_z · v_x & -v_y · v_z & v_x^2 + v_y^2 \\
-v_x · v_y & v_z^2 + v_x^2 & -v_y · v_z \\
v_y^2 + v_z^2 & -v_x · v_y & -v_z · v_x \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] = \left[\begin{matrix}
- v_z · v_x · u_x - v_y · v_z · u_y + (v_x^2 + v_y^2) · u_z \\
- v_x · v_y · u_x + (v_z^2 + v_x^2) · u_y - v_y · v_z · u_z \\
+ (v_y^2 + v_z^2) · u_x - v_x · v_y · u_y - v_z · v_x · u_z \\
\end{matrix}\right] \\
\left( 1 + t · \left( \dfrac{|\vec{u}|}{|\vec{v}|} - 1 \right) \right) · ә^{\vec{n}_{⊥} · t · \varphi} \circledast \vec{v} &= \left( 1 + t · \left( \dfrac{|\vec{u}|}{|\vec{v}|} - 1 \right) \right) · \left( \cos(t · \varphi) · \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] + \dfrac{\sin(t · \varphi)}{\sin\varphi · |\vec{v}| · |\vec{u}|} · \left[\begin{array}{ccc}
-v_z · v_x & -v_y · v_z & v_x^2 + v_y^2 \\
-v_x · v_y & v_z^2 + v_x^2 & -v_y · v_z \\
v_y^2 + v_z^2 & -v_x · v_y & -v_z · v_x \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] \right) \\
\left( 1 + \dfrac{x - x_0}{x_1 - x_0} · \dfrac{|\vec{u}| - |\vec{v}|}{|\vec{v}|} \right) · ә^{\vec{n}_{⊥} · \frac{x - x_0}{x_1 - x_0} · \varphi} \circledast \vec{v} &= \left( 1 + \dfrac{x - x_0}{x_1 - x_0} · \dfrac{|\vec{u}| - |\vec{v}|}{|\vec{v}|} \right) · \left( \cos\left( \dfrac{x - x_0}{x_1 - x_0} · \varphi \right) · \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] + \dfrac{\sin\left( \frac{x - x_0}{x_1 - x_0} · \varphi \right)}{\sin\varphi · |\vec{v}| · |\vec{u}|} · \left[\begin{array}{ccc}
-v_z · v_x & -v_y · v_z & v_x^2 + v_y^2 \\
-v_x · v_y & v_z^2 + v_x^2 & -v_y · v_z \\
v_y^2 + v_z^2 & -v_x · v_y & -v_z · v_x \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] \right) \\
\end{aligned}
$$
