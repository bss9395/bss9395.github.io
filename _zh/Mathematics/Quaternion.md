---
layout:  zh_post
Topic :  收敛极限
Title :  四元数
Update:  2021-12-26T10:35:00+08@中国-广东-深圳+08
Author:  璀璨星辰
Credit:
---

### 特别注意

```
本书中对复数共有3种度量运算：复数的长度值与度量值，或者高次方拓扑值。
本书中复数的长度值为Le(z)，而非|z|。
本书中复数的度量值定为Measurement，而非绝对值Absolute，其符号为|z|。
本书中长度值对复数才有意义，实数的长度值与其度量值相等，但意义不同。
本书中对四元数共有2种倒逆运算：四元数的合乘倒逆运算与虚乘倒逆运算。
本书中对复数共轭运算以及对四元数的共轭运算均为Conjugate，其符号为Ā。
```

### 复数的运算性质

虚数的虚乘运算。虚数的虚乘运算必满足交换律。

$$
\begin{aligned}
c \circledast d &= c · d \\
c \circledast τ &= c · τ \\
τ \circledast τ &= -1 \\
\end{aligned}
$$

复数的长度值。注意：复数的长度值是非负实数。

$$
\mathrm{Le}(z) = \sqrt{\mathrm{Re}^2(z) + \mathrm{Im}^2(z)}
$$

复数的度量值。注意：复数的度量值是复数，但未必都是非负实数。

$$
|z| = \sqrt{z \circledast z}
$$

复数的辐角表示法。复数的旋转轴为$+τ$轴。

$$
\begin{aligned}
z = \mathrm{Le}(z) · ә^{+τ · \arg z} &≡ \mathrm{Le}(z) · [\cos(\arg z) + τ · \sin(\arg z)] \\
z = \mathrm{Re}(z) + τ · \mathrm{Im}(z) &= z_x + τ · z_y \\
\end{aligned}
$$

复数的辐角。

$$
\begin{aligned}
\sin(\arg z) &= \dfrac{\mathrm{Im}(z)}{\mathrm{Le}(z)} \\
\cos(\arg z) &= \dfrac{\mathrm{Re}(z)}{\mathrm{Le}(z)} \\
\tan(\arg z) &= \dfrac{\mathrm{Im}(z)}{\mathrm{Re}(z)} \\
\end{aligned}
$$

单位复数。

$$
1 = 1 + τ · 0 = ә^{τ · 0} = \cos 0 + τ · \sin 0
$$

规范复数。

$$
\begin{aligned}
\dfrac{z}{\mathrm{Le}(z)} &= ә^{τ · \arg z} = \cos(\arg z) + τ · \sin(\arg z) \\
\dfrac{z}{\mathrm{Le}(z)} &= \dfrac{\mathrm{Re}(z) + τ · \mathrm{Im}(z)}{\mathrm{Le}(z)} = \dfrac{z_x + τ · z_y}{\sqrt{z_x^2 + z_y^2}} \\
\end{aligned}
$$

共轭复数。

$$
\begin{aligned}
\overline{z} = \mathrm{Le}(z) · ә^{-τ · \arg z} &= \mathrm{Le}(z) · [\cos(\arg z) - τ · \sin(\arg z)] \\
\mathrm{Le}^2(z) = z \circledast \overline{z} &≡ \mathrm{Le}^2(z) · [\cos(\arg z) + τ · \sin(\arg z)] \circledast [\cos(\arg z) - τ · \sin(\arg z)] = \mathrm{Le}^2(z) · \left[ \cos^2(\arg z) - τ^{2} · \sin^2(\arg z) \right] \\
z^2 ≡ z \circledast z &≡ \mathrm{Le}^2(z) · \left[ \cos(\arg z) + τ · \sin(\arg z) \right] \circledast \left[ \cos(\arg z) + τ · \sin(\arg z) \right] = \mathrm{Le}^2(z) · [ \cos(2 · \arg z) + τ · \sin(2 · \arg z) ] \\
\end{aligned}
$$

倒逆复数。若无特别的规定，复数的倒逆运算指虚乘倒逆运算，而非合乘倒逆运算，复数的两种倒逆运算其值相等但意义不同。

$$
\dfrac{\rlap{1}{≡}}{\rlap{z}{≡}} ⇔ {^\imath}z ≡ \circledast^{-1} {z} = \dfrac{\overline{z}}{\mathrm{Le}^2(z)} = \dfrac{\overline{z}}{\mathrm{Le}(z^2)} ≠ \dfrac{\overline{z}}{z^2}
$$

任意规范复数的位加运算。复数的位加运算必满足交换律。复数的位加运算必满足结合律。
$$
\begin{aligned}
\mathrm{Le}(q) · ә^{τ · \arg q} + \mathrm{Le}(z) · ә^{τ · \arg z} &≡ \mathrm{Le}(q) · [\cos(\arg q) + τ · \sin(\arg q)] + \mathrm{Le}(z) · [\cos(\arg z) + τ · \sin(\arg z)] \\
\mathrm{Le}(q) · ә^{τ · \arg q} + \mathrm{Le}(z) · ә^{τ · \arg z} &= [\mathrm{Le}(q) · \cos(\arg z) + \mathrm{Le}(z) · \cos(\arg z)] + τ · [\mathrm{Le}(q) · \sin(\arg q) + \mathrm{Le}(z) · \sin(\arg z)] \\
\end{aligned}
$$

任意规范复数的虚乘运算。复数的虚乘运算必满足交换律。复数的虚乘运算必满足结合律。

$$
\begin{aligned}
\left[ \mathrm{Le}(q) · ә^{τ · \arg q} \right] \circledast \left[ \mathrm{Le}(z) · ә^{τ · \arg z} \right] &≡ \mathrm{Le}(q) · \mathrm{Le}(z) · [\cos(\arg q) + τ · \sin(\arg q)] \circledast [\cos(\arg z) + τ · \sin(\arg z)] \\
\mathrm{Le}(q) · \mathrm{Le}(z) · ә^{τ · (\arg q + \arg z)} = \left[ \mathrm{Le}(q) · ә^{τ · \arg q} \right] \circledast \left[ \mathrm{Le}(z) · ә^{τ · \arg z} \right] &= \mathrm{Le}(q) · \mathrm{Le}(z) · [\cos(\arg q + \arg z) + τ · \sin(\arg q + \arg z)] \\
\end{aligned}
$$

### 矢量的运算性质

$3$维空间基矢量。

$$
\begin{aligned}
\vec{η}_x &= \left[\begin{matrix}
0 \\
0 \\
1 \\
\end{matrix}\right] & \vec{η}_y &= \left[\begin{matrix}
0 \\
1 \\
0 \\
\end{matrix}\right] & \vec{η}_z &= \left[\begin{matrix}
1 \\
0 \\
0 \\
\end{matrix}\right] \\
\end{aligned}
$$

$3$维空间基矢量的点乘运算。矢量的点乘运算必满足交换律。

$$
\begin{aligned}
\vec{η}_x \odot \vec{η}_x &= 1 & \vec{η}_y \odot \vec{η}_y &= 1 & \vec{η}_z \odot \vec{η}_z &= 1 \\
\vec{η}_x \odot \vec{η}_y &= 0 & \vec{η}_y \odot \vec{η}_z &= 0 & \vec{η}_z \odot \vec{η}_x &= 0 \\
\vec{η}_y \odot \vec{η}_x &= 0 & \vec{η}_z \odot \vec{η}_y &= 0 & \vec{η}_x \odot \vec{η}_z &= 0 \\
\end{aligned}
$$

$3$维空间基矢量的叉乘运算。矢量的叉乘运算不满足交换律。矢量的叉乘运算不满足结合律。

$$
\begin{aligned}
\vec{η}_x \otimes \vec{η}_x &= \vec{0} & \vec{η}_y \otimes \vec{η}_y &= \vec{0} & \vec{η}_z \otimes \vec{η}_z &= \vec{0} \\
\vec{η}_x \otimes \vec{η}_y &= +\vec{η}_z & \vec{η}_y \otimes \vec{η}_z &= +\vec{η}_x & \vec{η}_z \otimes \vec{η}_x &= +\vec{η}_y \\
\vec{η}_y \otimes \vec{η}_x &= -\vec{η}_z & \vec{η}_z \otimes \vec{η}_y &= -\vec{η}_x & \vec{η}_x \otimes \vec{η}_{z} &= -\vec{η}_y \\
\end{aligned}
$$

$3$维空间基矢量的虚乘运算。矢量的虚乘运算不满足交换律。

$$
\begin{aligned}
c \circledast \vec{η}_x &≡ c · \vec{η}_x & c \circledast \vec{η}_y &≡ c · \vec{η}_y & c \circledast \vec{η}_z &≡ c · \vec{η}_z \\
\vec{η}_x \circledast \vec{η}_x &≡ \vec{η}_x \odot \vec{η}_x = -1 & \vec{η}_y \circledast \vec{η}_y &≡ \vec{η}_y \odot \vec{η}_y = -1 & \vec{η}_z \circledast \vec{η}_z &≡ \vec{η}_z \odot \vec{η}_z = -1 \\
\vec{η}_x \circledast \vec{η}_y &≡ \vec{η}_x \otimes \vec{η}_y = +\vec{η}_z & \vec{η}_y \circledast \vec{η}_z &≡ \vec{η}_y \otimes \vec{η}_z = +\vec{η}_x & \vec{η}_z \circledast \vec{η}_x &≡ \vec{η}_z \otimes \vec{η}_x = +\vec{η}_y \\
\vec{η}_y \circledast \vec{η}_x &≡ \vec{η}_y \otimes \vec{η}_x = -\vec{η}_z & \vec{η}_z \circledast \vec{η}_y &≡ \vec{η}_z \otimes \vec{η}_y = -\vec{η}_x & \vec{η}_x \circledast \vec{η}_{z} &≡ \vec{η}_x \otimes \vec{η}_z = -\vec{η}_y \\
\end{aligned}
$$

$3$维空间矢量与$3$维空间矢量的虚乘运算。

$$
\begin{aligned}
\left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] \circledast_3 \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] &≡ (\vec{η}_x · u_x + \vec{η}_y · u_y + \vec{η}_z · u_z) \circledast_3 (\vec{η}_x · v_x + \vec{η}_y · v_y + \vec{η}_z · v_z) \\
- \left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] \odot_3 \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] +_4 \left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] \otimes_3 \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] = \left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] \circledast_3 \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] &= \mathop{\left[\begin{matrix}
-u_y & +u_x & 0 \\
+u_z & 0 & -u_x \\
0 & -u_z & +u_y \\
-u_x & -u_y & -u_z \\
\end{matrix}\right]}\limits_{4×3} \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] = \left[\begin{matrix}
+u_x · v_y - u_y · v_x \\
+u_z · v_x - u_x · v_z \\
+u_y · v_z - u_z · v_y \\
-u_x · v_x - u_y · v_y - u_z · v_z \\
\end{matrix}\right] \\
\end{aligned}
$$

$3$维空间矢量的规范化。

$$
\begin{aligned}
\vec{n}_{\vec{v}} = \dfrac{\vec{v}}{|\vec{v}|} &≡ \dfrac{\vec{η}_x · v_{x} + \vec{η}_y · v_{y} + \vec{η}_z · v_{z}}{\sqrt{v_x^2 + v_y^2 + v_z^2}} \\
\vec{n}_{\vec{v}} = \dfrac{\vec{v}}{|\vec{v}|} &= \vec{η}_x · n_{v_x} + \vec{η}_y · n_{v_y} + \vec{η}_z · n_{v_z} \\
\end{aligned}
$$

### 矢量的分解运算

$3$维空间矢量的等值替换。

$$
\begin{aligned}
\vec{u} \circledast \vec{v} &= - \vec{u} \odot \vec{v} + \vec{u} \otimes \vec{v} \\
\vec{v} \circledast \vec{u} &= - \vec{u} \odot \vec{v} - \vec{u} \otimes \vec{v} \\
\vec{u} \otimes \vec{v} &= +\dfrac{1}{2} · [\vec{u} \circledast \vec{v} - \vec{v} \circledast \vec{u}] \\
\vec{u} \odot \vec{v} &= -\dfrac{1}{2} · [\vec{u} \circledast \vec{v} + \vec{v} \circledast \vec{u}] \\
\end{aligned}
$$

$3$维空间矢量的虚乘分解。

$$
\begin{aligned}
\vec{v}_{∥\vec{n}} &= \vec{n} \odot \vec{v} · \vec{n} \\
&= -\dfrac{1}{2} · [\vec{n} \circledast \vec{v} + \vec{v} \circledast \vec{n}] \circledast \vec{n} \\
&= -\dfrac{1}{2} · [\vec{n} \circledast \vec{v} \circledast \vec{n} + \vec{v} \circledast \vec{n} \circledast \vec{n}] \\
&= \dfrac{1}{2} · [-\vec{n} \circledast \vec{v} \circledast \vec{n} + \vec{v}] \\
\vec{v}_{⊥\vec{n}} &= \vec{n} \otimes \vec{v} \otimes \vec{n} \\
&= +\dfrac{1}{2} · [\vec{n} \circledast \vec{v} - \vec{v} \circledast \vec{n}] \otimes \vec{n} \\
&= +\dfrac{1}{4} · [(\vec{n} \circledast \vec{v} - \vec{v} \circledast \vec{n}) \circledast \vec{n} - \vec{n} \circledast (\vec{n} \circledast \vec{v} - \vec{v} \circledast \vec{n})] \\
&= \dfrac{1}{2} · [+\vec{n} \circledast \vec{v} \circledast \vec{n} + \vec{v}] \\
\end{aligned}
$$

$3$维空间矢量的正交分解。

$$
\begin{aligned}
\vec{v}_{∥\vec{u}} &= \dfrac{\vec{u}}{|\vec{u}|} \odot \vec{v} · \dfrac{\vec{u}}{|\vec{u}|} = \dfrac{\vec{u} \odot \vec{v} · \vec{u}}{|\vec{u}|^2} \\
\vec{v}_{⊥\vec{u}} &= \dfrac{\vec{u}}{|\vec{u}|} \otimes \vec{v} \otimes \dfrac{\vec{u}}{|\vec{u}|} = \dfrac{\vec{u} \otimes \vec{v} \otimes \vec{u}}{|\vec{u}|^2} \\
\vec{v}_{⊥\vec{u}} &= \vec{v} - \vec{v}_{∥\vec{u}} = \vec{v} - \dfrac{\vec{u} \odot \vec{v} · \vec{u}}{|\vec{u}|^2} \\
\vec{v} &= \vec{v}_{∥\vec{u}} + \vec{v}_{⊥\vec{u}} = \dfrac{\vec{u} \odot \vec{v} · \vec{u}}{|\vec{u}|^2} + \dfrac{\vec{u} \otimes \vec{v} \otimes \vec{u}}{|\vec{u}|^2} \\
\end{aligned}
$$

### 四元数的运算性质

若无特别的规定，约定四元数为$4$维的向量，约定四元数的四个分量均为实数而非复数。注意：四元数其指数的向量部分为其向量部分的规范向量。

四元数的度量值。四元数的度量值是非负实数。

$$
|\bold{q}| = \sqrt{q_w^2 + q_x^2 + q_y^2 + q_z^2}
$$

四元数的辐角表示法。四元数的旋转轴为$+\vec{n}_{\vec{q}}$轴。

$$
\begin{aligned}
\bold{q} = |\bold{q}| · ә^{+\vec{n}_{\vec{q}} · \arg \bold{q}} &≡ |\bold{q}| · \left[ \cos(\arg \bold{q}) + \vec{n}_{\vec{q}} · \sin(\arg \bold{q}) \right] \\
\bold{q} = q + \vec{q} &= q_w + \vec{η}_x · q_x + \vec{η}_y · q_y + \vec{η}_z · q_z \\
\
\end{aligned}
$$

四元数的辐角。

$$
\begin{aligned}
\sin(\arg\bold{q}) &= \dfrac{{^\imath}\vec{n}_{\vec{q}} \rlap{×}{+} \vec{q}}{|\bold{q}|} \\
\cos(\arg\bold{q}) &= \dfrac{q}{|\bold{q}|} \\
\tan(\arg\bold{q}) &= \dfrac{{^\imath}\vec{n}_{\vec{q}} \rlap{×}{+} \vec{q}}{q} \\
|\tan(\arg\bold{q})| &≠ \dfrac{|\vec{q}|}{|q|} \\
\left[ \tan\dfrac{\arg\bold{p}}{2} = \tan\dfrac{\arg\bold{q}}{2} \right] &⇔ \left[ \arg\bold{p} = \arg\bold{q} \mod 360° \right] \\
\end{aligned}
$$

单位四元数。

$$
1 + \vec{0} = ә^{\vec{n} · 0} = \cos 0 + \vec{n}_{\vec{q}} · \sin 0
$$

规范四元数。

$$
\begin{aligned}
\dfrac{\bold{q}}{|\bold{q}|} &= ә^{\vec{n}_{\vec{q}} · \arg \bold{q}} = \cos(\arg \bold{q}) + \vec{n}_{\vec{q}} · \sin(\arg \bold{q}) \\
\dfrac{\bold{q}}{|\bold{q}|} &= \dfrac{q + \vec{q}}{|\bold{q}|} = \dfrac{q_w + \vec{η}_x · q_x + \vec{η}_y · q_y + \vec{η}_z · q_z}{\sqrt{q_w^2 + q_x^2 + q_y^2 + q_z^2}} \\
\end{aligned}
$$

向量四元数。

$$
\rlap{ә^{\rlap{\vec{v} · \frac{π}{2}}{≡≡}}}{≡≡} ⇔ |\vec{v}| · ә^{\vec{n}_{\vec{v}} · \frac{π}{2}} = \vec{v} = |\vec{v}| · \left[ \cos\dfrac{π}{2} + \vec{n}_{\vec{v}} · \sin\dfrac{π}{2} \right]
$$

共轭四元数。

$$
\begin{aligned}
\overline{\bold{q}} &= |\bold{q}| · ә^{-\vec{n}_{\vec{q}}·\arg \bold{q}} = |\bold{q}| · [\cos(\arg \bold{q}) - \vec{n}_{\vec{q}} · \sin(\arg \bold{q})] \\
\overline{\bold{q}} &= q - \vec{q} = q_w - \vec{η}_x · q_x - \vec{η}_y · q_y - \vec{η}_z · q_z \\
|\bold{q}|^2 = \bold{q} \circledast \overline{\bold{q}} &≡ |\bold{q}|^2 · \left[ \cos(\arg\bold{q}) + \vec{n}_{\vec{q}} · \sin(\arg\bold{q}) \right] \circledast \left[ \cos(\arg\bold{q}) - \vec{n}_{\vec{q}} · \sin(\arg\bold{q}) \right] = |\bold{q}|^2 · \left[ \cos^2(\arg\bold{q}) - \vec{n}_{\vec{q}}^{2} · \sin^2(\arg\bold{q}) \right] \\
\bold{q}^2 = \bold{q} \circledast \bold{q} &≡ |\bold{q}|^2 · \left[ \cos(\arg\bold{q}) + \vec{n}_{\vec{q}} · \sin(\arg\bold{q}) \right] \circledast \left[ \cos(\arg\bold{q}) + \vec{n}_{\vec{q}} · \sin(\arg\bold{q}) \right] = |\bold{q}|^2 · \left[ \cos(2 · \arg\bold{q}) + \vec{n}_{\vec{q}} · \sin(2 · \arg\bold{q}) \right] \\
\overline{\bold{q} + \bold{v}} &= \overline{\bold{q}} + \overline{\bold{v}} \\
\end{aligned}
$$

倒逆四元数。若无特别的规定，约定四元数的倒逆运算指虚乘倒逆运算，而非合乘倒逆运算，四元数的两种倒逆运算其值不等且意义不同。

$$
\dfrac{\rlap{1}{≡}}{\rlap{\bold{q}}{≡}} ⇔ {^\imath}\bold{q} ≡ \circledast^{-1}\bold{q} = \dfrac{\overline{\bold{q}}}{|\bold{q}|^2} = \dfrac{\overline{\bold{q}}}{|\bold{q}^2|} ≠ \dfrac{\overline{\bold{q}}}{\bold{q}^2}
$$

同向四元数的位加运算。四元数的位加运算必满足交换律。四元数的位加运算必满足结合律。

$$
\begin{aligned}
\left[ |\bold{q}| · ә^{\vec{n}·\arg\bold{q}} \right] + \left[ |\bold{v}| · ә^{\vec{n}·\arg\bold{v}} \right] &≡ |\bold{q}| · \left[ \cos(\arg\bold{q}) + \vec{n} · \sin(\arg\bold{q}) \right] + |\bold{v}| · \left[ \cos(\arg\bold{v}) + \vec{n} · \sin(\arg\bold{v}) \right] \\
\left[ |\bold{q}| · ә^{\vec{n}·\arg\bold{q}} \right] + \left[ |\bold{v}| · ә^{\vec{n}·\arg\bold{v}} \right] &= [|\bold{q}| · \cos(\arg\bold{q}) + |\bold{v}| · \cos(\arg\bold{v})] + \vec{n} · [|\bold{q}| · \sin(\arg\bold{q}) + |\bold{v}| · \sin(\arg\bold{v})] \\
\end{aligned}
$$

同向四元数的虚乘运算。四元数的虚乘运算不满足交换律。四元数的虚乘运算必满足结合律。注意：向量的叉乘运算不满足结合律。

$$
\begin{aligned}
\left[ |\bold{q}| · ә^{\vec{n}·\arg\bold{q}} \right] \circledast \left[ |\bold{v}| · ә^{\vec{n}·\arg\bold{v}} \right] &≡ |\bold{q}| · |\bold{v}| · \left[ \cos(\arg\bold{q}) + \vec{n} · \sin(\arg\bold{q}) \right] \circledast \left[ \cos(\arg\bold{v}) + \vec{n} · \sin(\arg\bold{v}) \right] \\
|\bold{q}| · |\bold{v}| · ә^{\vec{n}·(\arg\bold{q}+\arg\bold{v})} = \left[ |\bold{q}| · ә^{\vec{n}·\arg\bold{q}} \right] \circledast \left[ |\bold{v}| · ә^{\vec{n}·\arg\bold{v}} \right] &= |\bold{q}| · |\bold{v}| · \left[ \cos(\arg\bold{q} + \arg\bold{v}) + \vec{n} · \sin(\arg\bold{q} + \arg\bold{v}) \right] \\
\end{aligned}
$$

任意四元数的位加运算。四元数的位加运算必满足交换律。四元数的位加运算必满足结合律。

$$
\begin{aligned}
\left[\begin{matrix}
u_z \\
u_y \\
u_x \\
u_w \\
\end{matrix}\right] + \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
v_w \\
\end{matrix}\right] &≡ (u_w + \vec{η}_x · u_x + \vec{η}_y · u_y + \vec{η}_z · u_z) + (v_w + \vec{η}_x · v_x + \vec{η}_y · v_y + \vec{η}_z · v_z) \\
&= (u_w + v_w) + \vec{η}_x · (u_x + v_x) + \vec{η}_y · (u_y + v_y) + \vec{η}_z · (u_z + v_z) \\
\left[\begin{matrix}
u_z \\
u_y \\
u_x \\
u_w \\
\end{matrix}\right] + \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
v_w \\
\end{matrix}\right] &= \left[\begin{matrix}
u_z + v_z \\
u_y + v_y \\
u_x + v_x \\
u_w + v_w \\
\end{matrix}\right] \\
\end{aligned}
$$

任意四元数的虚乘运算。四元数的虚乘运算不满足交换律。四元数的虚乘运算必满足结合律。注意：向量的叉乘运算不满足结合律。

$$
\begin{aligned}
\left[\begin{matrix}
q_z \\
q_y \\
q_x \\
q_w \\
\end{matrix}\right] \circledast \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
v_w \\
\end{matrix}\right] &≡ (q_w + \vec{η}_x · q_x + \vec{η}_y · q_y + \vec{η}_z · q_z) \circledast (v_w + \vec{η}_x · v_x + \vec{η}_y · v_y + \vec{η}_z · v_z) \\
&= q_w · v_w + q_w · (\vec{η}_x · v_x + \vec{η}_y · v_y + \vec{η}_z · v_z) + v_w · (\vec{η}_x · q_x + \vec{η}_y · q_y + \vec{η}_z · q_z) + (\vec{η}_x · q_x + \vec{η}_y · q_y + \vec{η}_z · q_z) \circledast (\vec{η}_x · v_x + \vec{η}_y · v_y + \vec{η}_z · v_z) \\
\left[\begin{matrix}
q_z \\
q_y \\
q_x \\
q_w \\
\end{matrix}\right] \circledast \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
v_w \\
\end{matrix}\right] &= q_w · v_w +_4 q_w · \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] +_4 v_w · \left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] -_4 \left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \odot \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] +_4 \left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] = \mathop{\left[\begin{matrix}
q_z \\
q_y \\
q_x \\
q_w \\
\end{matrix}\right]}_{1+3} · v_w +_4 \mathop{\left[\begin{matrix}
-q_y & +q_x & +q_w \\
+q_z & +q_w & -q_x \\
+q_w & -q_z & +q_y \\
-q_x & -q_y & -q_z \\
\end{matrix}\right]}\limits_{4×3} \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
&= \mathop{\left[\begin{matrix}
+q_z & -q_y & +q_x & +q_w \\
+q_y & +q_z & +q_w & -q_x \\
+q_x & +q_w & -q_z & +q_y \\
+q_w & -q_x & -q_y & -q_z \\
\end{matrix}\right]}\limits_{4×4} \rlap{×}{+} \mathop{\left[\begin{matrix}
v_z \\
v_y \\
v_x \\
v_w \\
\end{matrix}\right]}\limits_{1+3} = \left[\begin{matrix}
q_z · v_w - q_y · v_x + q_x · v_y + q_w · v_z \\
q_y · v_w + q_z · v_x + q_w · v_y - q_x · v_z \\
q_x · v_w + q_w · v_x - q_z · v_y + q_y · v_z \\
q_w · v_w -q_x · v_x - q_y · v_y - q_z · v_z \\
\end{matrix}\right] \\
\end{aligned}
$$

$$
\begin{aligned}
\overline{\bold{q} \circledast \bold{v}} &= \overline{\bold{v}} \circledast \overline{\bold{q}} \\
\left[\begin{matrix}
-v_z \\
-v_y \\
-v_x \\
+v_w \\
\end{matrix}\right] \circledast \left[\begin{matrix}
-q_z \\
-q_y \\
-q_x \\
+q_w \\
\end{matrix}\right] &= v_w · q_w +_4 v_w · \left[\begin{matrix}
-q_z \\
-q_y \\
-q_x \\
\end{matrix}\right] +_4 q_w · \left[\begin{matrix}
-v_z \\
-v_y \\
-v_x \\
\end{matrix}\right] -_4 \left[\begin{matrix}
-v_z \\
-v_y \\
-v_x \\
\end{matrix}\right] \odot \left[\begin{matrix}
-q_z \\
-q_y \\
-q_x \\
\end{matrix}\right] +_4 \left[\begin{matrix}
-v_z \\
-v_y \\
-v_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
-q_z \\
-q_y \\
-q_x \\
\end{matrix}\right] \\
&= q_w · v_w -_4 q_w · \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] -_4 v_w · \left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] -_4 \left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \odot \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] -_4 \left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\end{aligned}
$$

任意四元数的等值替换。

$$
\begin{aligned}
\bold{q} \odot \bold{v} &= \dfrac{\bold{\overline{q}} \circledast \bold{v} + \bold{v} \circledast \bold{\overline{q}}}{2} \\
q · \vec{v} - v · \vec{q} - \vec{q} \otimes \vec{v} &= \dfrac{\bold{\overline{q}} \circledast \bold{v} - \bold{v} \circledast \bold{\overline{q}}}{2} \\
q · v + q · \vec{v} + v · \vec{q} - \vec{q} \odot \vec{v} &= \dfrac{\bold{q} \circledast \bold{v} + \bold{v} \circledast \bold{q}}{2} \\
\vec{q} \otimes \vec{v} &= \dfrac{\bold{q} \circledast \bold{v} - \bold{v} \circledast \bold{q}}{2} \\
\end{aligned}
$$

### 四元数的旋转运算

$3$维空间向量的旋转运算。以$3$维空间矢量$\vec{n}_{⊥\vec{v}}$为旋转轴，将$3$维空间矢量$\vec{v}$按右手旋转角度$\varphi$变成$3$维空间矢量$\vec{u}$。

$$
\begin{aligned}
\vec{u} \odot \vec{v} &= +|\vec{v}|^2 · \cos\varphi \\
\vec{u} \otimes \vec{v} &= -|\vec{v}|^2 · \vec{n}_{⊥} · \sin\varphi \\
\vec{u} \circledast \vec{v} &= \vec{u} \otimes \vec{v} - \vec{u} \odot \vec{v} = |\vec{v}|^2 · [ - \cos\varphi - \vec{n}_{⊥} · \sin\varphi] = |\vec{u}|^2 · [- \cos\varphi - \vec{n}_{⊥} · \sin\varphi] \\
\vec{u} &= \vec{u} \circledast \vec{v} \circledast {^\imath}\vec{v} = |\vec{v}|^2 · [- \cos\varphi - \vec{n}_{⊥} · \sin\varphi] \circledast \left( -\dfrac{\vec{v}}{|\vec{v}|^2} \right) \\
\vec{u} &=  ә^{+\vec{n}_{⊥}·\varphi} \circledast \vec{v} \\
\vec{v} &= {^\imath}\vec{u} \circledast \vec{u} \circledast \vec{v} = |\vec{u}|^2 · \left( -\dfrac{\vec{u}}{|\vec{u}|^2} \right) \circledast [- \cos\varphi - \vec{n}_{⊥} · \sin\varphi] \\
\vec{v} &= \vec{u} \circledast ә^{+\vec{n}_{⊥}·\varphi} \\
ә^{+\vec{n}_{⊥}·(2·\varphi)} \circledast \vec{v} &= ә^{+\vec{n}_{⊥}·\varphi} \circledast \vec{v} \circledast ә^{-\vec{n}_{⊥}·\varphi} \\
\end{aligned}
$$

四元数对$3$维空间矢量常规旋转运算的几何意义。注意：四元数对$3$维空间矢量常规运算之值是四元数。

$$
\begin{aligned}
ә^{\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast \vec{v} &= ә^{\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast (\vec{v}_{⊥\vec{q}} + \vec{v}_{∥\vec{q}}) \\
&= ә^{\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast \vec{v}_{⊥\vec{q}} + ә^{\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast \left(\vec{v}_{∥\vec{q}} · \sin\dfrac{π}{2} + \cos\dfrac{π}{2} \right) \\
ә^{\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast \vec{v} &= ә^{\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast \vec{v}_{⊥\vec{q}} + \left| \vec{v}_{∥\vec{q}} \right| · ә^{\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast ә^{\vec{n}_{\vec{q}}·\frac{π}{2}} \\
\end{aligned}
$$

四元数对$3$维空间矢量倒逆旋转运算的几何意义。注意：四元数的逆称虚虚乘运算之值是$3$维空间矢量。

$$
\begin{aligned}
ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \circledast \vec{v} \circledast ә^{-\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} &= \left[ ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \circledast \vec{v}_{⊥\vec{q}} + \left| \vec{v}_{∥\vec{q}} \right| · ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \circledast ә^{\vec{n}_{\vec{q}}·\frac{π}{2}} \right] \circledast ә^{-\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \\
&= ә^{+\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast \vec{v}_{⊥\vec{q}} + \vec{v}_{∥\vec{q}} \\
&= \vec{u}_{⊥\vec{q}} + \vec{u}_{∥\vec{q}} \\
\end{aligned}
$$

四元数的任意虚虚乘运算。四元数的虚虚乘运算必满足结合律。

$$
\begin{aligned}
&\left(\left[ |\bold{q}| · ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \right] \circledast \left[ |\bold{v}| · ә^{+\vec{n}_{\vec{v}}·\arg\bold{v}} \right]\right) \circledast \left[ |\bold{p}| · ә^{+\vec{n}_{\vec{p}}·\frac{\arg\bold{p}}{2}} \right] \\
&= \left(\left[\begin{matrix}
q_z \\
q_y \\
q_x \\
q_w \\
\end{matrix}\right] \circledast \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
v_w \\
\end{matrix}\right]\right) \circledast \left[\begin{matrix}
p_z \\
p_y \\
p_x \\
p_w \\
\end{matrix}\right] = \left[\begin{matrix}
q_z · v_w - q_y · v_x + q_x · v_y + q_w · v_z \\
q_y · v_w + q_z · v_x + q_w · v_y - q_x · v_z \\
q_x · v_w + q_w · v_x - q_z · v_y + q_y · v_z \\
q_w · v_w - q_x · v_x - q_y · v_y - q_z · v_z \\
\end{matrix}\right] \circledast \left[\begin{matrix}
p_z \\
p_y \\
p_x \\
p_w \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
(q_z · v_w - q_y · v_x + q_x · v_y + q_w · v_z) · p_w - (q_y · v_w + q_z · v_x + q_w · v_y - q_x · v_z) · p_x + (q_x · v_w + q_w · v_x - q_z · v_y + q_y · v_z) · p_y + (q_w · v_w - q_x · v_x - q_y · v_y - q_z · v_z) · p_z \\
(q_y · v_w + q_z · v_x + q_w · v_y - q_x · v_z) · p_w + (q_z · v_w - q_y · v_x + q_x · v_y + q_w · v_z) · p_x + (q_w · v_w - q_x · v_x - q_y · v_y - q_z · v_z) · p_y - (q_x · v_w + q_w · v_x - q_z · v_y + q_y · v_z) · p_z \\
(q_x · v_w + q_w · v_x - q_z · v_y + q_y · v_z) · p_w + (q_w · v_w - q_x · v_x - q_y · v_y - q_z · v_z) · p_x - (q_z · v_w - q_y · v_x + q_x · v_y + q_w · v_z) · p_y + (q_y · v_w + q_z · v_x + q_w · v_y - q_x · v_z) · p_z \\
(q_w · v_w - q_x · v_x - q_y · v_y - q_z · v_z) · p_w - (q_x · v_w + q_w · v_x - q_z · v_y + q_y · v_z) · p_x - (q_y · v_w + q_z · v_x + q_w · v_y - q_x · v_z) · p_y - (q_z · v_w - q_y · v_x + q_x · v_y + q_w · v_z) · p_z \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
(+ q_z · p_w - q_y · p_x + q_x · p_y + q_w · p_z) · v_w + (- q_y · p_w - q_z · p_x + q_w · p_y - q_x · p_z) · v_x + (+ q_x · p_w - q_w · p_x - q_z · p_y - q_y · p_z) · v_y + (+ q_w · p_w + q_x · p_x + q_y · p_y - q_z · p_z) · v_z \\
(+ q_y · p_w + q_z · p_x + q_w · p_y - q_x · p_z) · v_w + (+ q_z · p_w - q_y · p_x - q_x · p_y - q_w · p_z) · v_x + (+ q_w · p_w + q_x · p_x - q_y · p_y + q_z · p_z) · v_y + (- q_x · p_w + q_w · p_x - q_z · p_y - q_y · p_z) · v_z \\
(+ q_x · p_w + q_w · p_x - q_z · p_y + q_y · p_z) · v_w + (+ q_w · p_w - q_x · p_x + q_y · p_y + q_z · p_z) · v_x + (- q_z · p_w - q_y · p_x - q_x · p_y + q_w · p_z) · v_y + (+ q_y · p_w - q_z · p_x - q_w · p_y - q_x · p_z) · v_z \\
(+ q_w · p_w - q_x · p_x - q_y · p_y - q_z · p_z) · v_w + (- q_x · p_w - q_w · p_x - q_z · p_y + q_y · p_z) · v_x + (- q_y · p_w + q_z · p_x - q_w · p_y - q_x · p_z) · v_y + (- q_z · p_w - q_y · p_x + q_x · p_y - q_w · p_z) · v_z \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
(+ q_w · p_z + q_x · p_y - q_y · p_x + q_z · p_w) & (+ q_w · p_y - q_x · p_z - q_y · p_w - q_z · p_x) & (- q_w · p_x + q_x · p_w - q_y · p_z - q_z · p_y) & (+ q_w · p_w + q_x · p_x + q_y · p_y - q_z · p_z) \\
(+ q_w · p_y - q_x · p_z + q_y · p_w + q_z · p_x) & (- q_w · p_z - q_x · p_y - q_y · p_x + q_z · p_w) & (+ q_w · p_w + q_x · p_x - q_y · p_y + q_z · p_z) & (+ q_w · p_x - q_x · p_w - q_y · p_z - q_z · p_y) \\
(+ q_w · p_x + q_x · p_w + q_y · p_z - q_z · p_y) & (+ q_w · p_w - q_x · p_x + q_y · p_y + q_z · p_z) & (+ q_w · p_z - q_x · p_y - q_y · p_x - q_z · p_w) & (- q_w · p_y - q_x · p_z + q_y · p_w - q_z · p_x) \\
(+ q_w · p_w - q_x · p_x - q_y · p_y - q_z · p_z) & (- q_w · p_x - q_x · p_w + q_y · p_z - q_z · p_y) & (- q_w · p_y - q_x · p_z - q_y · p_w + q_z · p_x) & (- q_w · p_z + q_x · p_y - q_y · p_x - q_z · p_w) \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
v_w \\
\end{matrix}\right] \\
\end{aligned}
$$

$$
\begin{aligned}
&\left[ |\bold{q}| · ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \right] \circledast \left(\left[ |\bold{v}| · ә^{+\vec{n}_{\vec{v}}·\arg\bold{v}} \right] \circledast \left[ |\bold{p}| · ә^{+\vec{n}_{\vec{p}}·\frac{\arg\bold{p}}{2}} \right]\right) \\
&= \left[\begin{matrix}
q_z \\
q_y \\
q_x \\
q_w \\
\end{matrix}\right] \circledast \left(\left[\begin{matrix}
v_z \\
v_y \\
v_x \\
v_w \\
\end{matrix}\right] \circledast \left[\begin{matrix}
p_z \\
p_y \\
p_x \\
p_w \\
\end{matrix}\right]\right) = \left[\begin{matrix}
q_z \\
q_y \\
q_x \\
q_w \\
\end{matrix}\right] \circledast \left[\begin{matrix}
v_z · p_w - v_y · p_x + v_x · p_y + v_w · p_z \\
v_y · p_w + v_z · p_x + v_w · p_y - v_x · p_z \\
v_x · p_w + v_w · p_x - v_z · p_y + v_y · p_z \\
v_w · p_w - v_x · p_x - v_y · p_y - v_z · p_z \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
+ q_z · (v_w · p_w - v_x · p_x - v_y · p_y - v_z · p_z) - q_y · (v_x · p_w + v_w · p_x- v_z · p_y + v_y · p_z) + q_x · (v_y · p_w + v _z · p_x + v_w · p_y - v_x · p_z) + q_w · (v_z · p_w - v_y · p_x + v_x · p_y + v_w · p_z) \\
+ q_y · (v_w · p_w - v_x · p_x - v_y · p_y - v_z · p_z) + q_z · (v_x · p_w + v_w · p_x- v_z · p_y + v_y · p_z) + q_w · (v_y · p_w + v _z · p_x + v_w · p_y - v_x · p_z) - q_x · (v_z · p_w - v_y · p_x + v_x · p_y + v_w · p_z) \\
+ q_x · (v_w · p_w - v_x · p_x - v_y · p_y - v_z · p_z) + q_w · (v_x · p_w + v_w · p_x- v_z · p_y + v_y · p_z) - q_z · (v_y · p_w + v _z · p_x + v_w · p_y - v_x · p_z) + q_y · (v_z · p_w - v_y · p_x + v_x · p_y + v_w · p_z) \\
+ q_w · (v_w · p_w - v_x · p_x - v_y · p_y - v_z · p_z) - q_x · (v_x · p_w + v_w · p_x- v_z · p_y + v_y · p_z) - q_y · (v_y · p_w + v _z · p_x + v_w · p_y - v_x · p_z) - q_z · (v_z · p_w - v_y · p_x + v_x · p_y + v_w · p_z) \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
(+ q_z · p_w - q_y · p_x + q_x · p_y + q_w · p_z) · v_w & (- q_z · p_x - q_y · p_w - q_x · p_z + q_w · p_y) · v_x & (- q_z · p_y - q_y · p_z + q_x · p_w - q_w · p_x) · v_y & (- q_z · p_z + q_y · p_y + q_x · p_x + q_w · p_w) · v_z \\
(+ q_y · p_w + q_z · p_x + q_w · p_y - q_x · p_z) · v_w & (- q_y · p_x + q_z · p_w - q_w · p_z - q_x · p_y) · v_x & (- q_y · p_y + q_z · p_z + q_w · p_w + q_x · p_x) · v_y & (- q_y · p_z - q_z · p_y + q_w · p_x - q_x · p_w) · v_z \\
(+ q_x · p_w + q_w · p_x - q_z · p_y + q_y · p_z) · v_w & (- q_x · p_x + q_w · p_w + q_z · p_z + q_y · p_y) · v_x & (- q_x · p_y + q_w · p_z - q_z · p_w - q_y · p_x) · v_y & (- q_x · p_z - q_w · p_y - q_z · p_x + q_y · p_w) · v_z \\
(+ q_w · p_w - q_x · p_x - q_y · p_y - q_z · p_z) · v_w & (- q_w · p_x - q_x · p_w + q_y · p_z - q_z · p_y) · v_x & (- q_w · p_y - q_x · p_z - q_y · p_w + q_z · p_x) · v_y & (- q_w · p_z + q_x · p_y - q_y · p_x - q_z · p_w) · v_z \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
(+ q_w · p_z + q_x · p_y - q_y · p_x + q_z · p_w) & (+ q_w · p_y - q_x · p_z - q_y · p_w - q_z · p_x) & (- q_w · p_x + q_x · p_w - q_y · p_z - q_z · p_y) & (+ q_w · p_w + q_x · p_x + q_y · p_y - q_z · p_z) \\
(+ q_w · p_y - q_x · p_z + q_y · p_w + q_z · p_x) & (- q_w · p_z - q_x · p_y - q_y · p_x + q_z · p_w) & (+ q_w · p_w + q_x · p_x - q_y · p_y + q_z · p_z) & (+ q_w · p_x - q_x · p_w - q_y · p_z - q_z · p_y) \\
(+ q_w · p_x + q_x · p_w + q_y · p_z - q_z · p_y) & (+ q_w · p_w - q_x · p_x + q_y · p_y + q_z · p_z) & (+ q_w · p_z - q_x · p_y - q_y · p_x - q_z · p_w) & (- q_w · p_y - q_x · p_z + q_y · p_w - q_z · p_x) \\
(+ q_w · p_w - q_x · p_x - q_y · p_y - q_z · p_z) & (- q_w · p_x - q_x · p_w + q_y · p_z - q_z · p_y) & (- q_w · p_y - q_x · p_z - q_y · p_w + q_z · p_x) & (- q_w · p_z + q_x · p_y - q_y · p_x - q_z · p_w) \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
v_w \\
\end{matrix}\right] \\
\end{aligned}
$$

四元数的对称虚虚乘运算。四元数的虚虚乘运算必满足结合律。

$$
\begin{aligned}
&\left[ |\bold{q}| · ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \right] \circledast \left[ |\bold{v}| · ә^{+\vec{n}_{\vec{v}}·\arg\bold{v}}  \right] \circledast \left[ |\bold{q}| · ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \right] \\
&= \left[\begin{matrix}
+q_z \\
+q_y \\
+q_x \\
+q_w \\
\end{matrix}\right] \circledast \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
v_w \\
\end{matrix}\right] \circledast \left[\begin{matrix}
+q_z \\
+q_y \\
+q_x \\
+q_w \\
\end{matrix}\right] = \left[\begin{matrix}
q_z · v_w - q_y · v_x + q_x · v_y + q_w · v_z \\
q_y · v_w + q_z · v_x + q_w · v_y - q_x · v_z \\
q_x · v_w + q_w · v_x - q_z · v_y + q_y · v_z \\
q_w · v_w - q_x · v_x - q_y · v_y - q_z · v_z \\
\end{matrix}\right] \circledast \left[\begin{matrix}
+q_z \\
+q_y \\
+q_x \\
+q_w \\
\end{matrix}\right] \\
&= \mathop{\left[\begin{matrix}
+2 · q_w · q_z & -2 · q_z · q_x & -2 · q_y · q_z & q_w^2 + q_x^2 + q_y^2 - q_z^2 \\
+2 · q_w · q_y & -2 · q_x · q_y & q_w^2 + q_x^2 - q_y^2 + q_z^2 & -2 · q_y · q_z \\
+2 · q_w · q_x & q_w^2 - q_x^2 + q_y^2 + q_z^2 & -2 · q_x · q_y & -2 · q_z · q_x \\
q_w^2 - q_x^2 - q_y^2 - q_z^2 & -2 · q_w · q_x & -2 · q_w · q_y & -2 · q_w · q_z \\
\end{matrix}\right]}\limits_{4×4} \rlap{×}{+} \mathop{\left[\begin{matrix}
v_z \\
v_y \\
v_x \\
v_w \\
\end{matrix}\right]}\limits_{1+3} \\
\end{aligned}
$$

四元数的逆称虚虚乘运算。四元数的虚虚乘运算必满足结合律。

$$
\begin{aligned}
&\left[ |\bold{q}| · ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \right] \circledast \left[ |\bold{v}| · ә^{+\vec{n}_{\vec{v}}·\arg\bold{v}}  \right] \circledast \left[ |\bold{q}| · ә^{-\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \right] \\
&= \left[\begin{matrix}
+q_z \\
+q_y \\
+q_x \\
+q_w \\
\end{matrix}\right] \circledast \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
v_w \\
\end{matrix}\right] \circledast \left[\begin{matrix}
-q_z \\
-q_y \\
-q_x \\
+q_w \\
\end{matrix}\right] = \left[\begin{matrix}
q_z · v_w - q_y · v_x + q_x · v_y + q_w · v_z \\
q_y · v_w + q_z · v_x + q_w · v_y - q_x · v_z \\
q_x · v_w + q_w · v_x - q_z · v_y + q_y · v_z \\
q_w · v_w - q_x · v_x - q_y · v_y - q_z · v_z \\
\end{matrix}\right] \circledast \left[\begin{matrix}
-q_z \\
-q_y \\
-q_x \\
+q_w \\
\end{matrix}\right] \\
&= \mathop{\left[\begin{matrix}
0 & 2 · (- q_w · q_y + q_z · q_x) & 2 · (+ q_w · q_x + q_y · q_z) & q_w^2 - q_x^2 - q_y^2 + q_z^2 \\
0 & 2 · (+ q_w · q_z + q_x · q_y) & q_w^2 - q_x^2 + q_y^2 - q_z^2 & 2 · (- q_w · q_x + q_y · q_z) \\
0 & q_w^2 + q_x^2 - q_y^2 - q_z^2 & 2 · (- q_w · q_z + q_x · q_y) & 2 · (+ q_w · q_y + q_z · q_x) \\
q_w^2 + q_x^2 + q_y^2 + q_z^2 & 0 & 0 & 0 \\
\end{matrix}\right]}\limits_{4×4} \rlap{×}{+} \mathop{\left[\begin{matrix}
v_z \\
v_y \\
v_x \\
v_w \\
\end{matrix}\right]}\limits_{1+3} \\
\end{aligned}
$$

四元数$ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}}$所对应的旋转矩阵。注意：四元数的辐角是$\dfrac{\arg\bold{q}}{2}$，旋转矩阵的旋转角是$\arg\bold{q}$。注意：四元数所对应的旋转矩阵必唯一。

$$
\begin{aligned}
&ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \circledast \vec{v} \circledast ә^{-\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \\
&= \left[ q_w + \vec{η}_x · q_x + \vec{η}_y · q_y + \vec{η}_z · q_z \right] \circledast \vec{v} \circledast \left[ q_w - \vec{η}_x · q_x - \vec{η}_y · q_y - \vec{η}_z · q_z \right] \\
&= \mathop{\left[\begin{matrix}
0 & 2 · (- q_w · q_y + q_z · q_x) & 2 · (+ q_w · q_x + q_y · q_z) & 1 - 2 · (q_x^2 + q_y^2) \\
0 & 2 · (+ q_w · q_z + q_x · q_y) & 1 - 2 · (q_x^2 + q_z^2) & 2 · (- q_w · q_x + q_y · q_z) \\
0 & 1 - 2 · (q_y^2 + q_z^2) & 2 · (- q_w · q_z + q_x · q_y) & 2 · (+ q_w · q_y + q_z · q_x) \\
1 & 0 & 0 & 0 \\
\end{matrix}\right]}\limits_{4×4} \mathop{\rlap{×}{+}}\limits_{0=v_w}^{1=q_x^2+q_y^2+q_z^2+q_w^2} \mathop{\left[\begin{matrix}
v_z \\
v_y \\
v_x \\
0 \\
\end{matrix}\right]}\limits_{1+3} \\
\end{aligned}
$$

$$
\begin{aligned}
&ә^{+\vec{n}_{\vec{q}}·\frac{\varphi}{2}} \circledast \vec{v} \circledast ә^{-\vec{n}_{\vec{q}}·\frac{\varphi}{2}} \\
&= \left[ \cos\dfrac{\varphi}{2} + \sin\dfrac{\varphi}{2} · (\vec{η}_x · n_x + \vec{η}_y · n_y + \vec{η}_z · n_z) \right] \circledast \vec{v} \circledast \left[ \cos\dfrac{\varphi}{2} - \sin\dfrac{\varphi}{2} · (\vec{η}_x · n_x + \vec{η}_y · n_y + \vec{η}_z · n_z) \right] \\
&= \left[\begin{matrix}
0 & 2 · \left( -n_y · \cos\dfrac{\varphi}{2} · \sin\dfrac{\varphi}{2} + n_z · n_x · \sin^{2}\dfrac{\varphi}{2} \right) & 2 · \left( +n_x · \cos\dfrac{\varphi}{2} · \sin\dfrac{\varphi}{2} + n_y · n_z · \sin^{2}\dfrac{\varphi}{2} \right) & \cos^{2}\dfrac{\varphi}{2} + \sin^{2}\dfrac{\varphi}{2} · \left( - n_x^2 - n_y^2 + n_z^2 \right) \\
0 & 2 · \left( +n_z · \cos\dfrac{\varphi}{2} · \sin\dfrac{\varphi}{2} + n_x · n_y · \sin^{2}\dfrac{\varphi}{2} \right) & \cos^{2}\dfrac{\varphi}{2}  + \sin^{2}\dfrac{\varphi}{2} · \left( - n_x^2 + n_y^2 - n_z^2 \right) & 2 · \left( - n_x · \cos\dfrac{\varphi}{2} · \sin\dfrac{\varphi}{2} + n_y · n_z · \sin^{2}\dfrac{\varphi}{2} \right) \\
0 & \cos^{2}\dfrac{\varphi}{2} + \sin^{2}\dfrac{\varphi}{2} · \left( n_x^2 - n_y^2 - n_z^2 \right) & 2 · \left( -n_z · \cos\dfrac{\varphi}{2} · \sin\dfrac{\varphi}{2} + n_x · n_y · \sin^{2}\dfrac{\varphi}{2} \right) & 2 · \left( +n_y · \cos\dfrac{\varphi}{2} · \sin\dfrac{\varphi}{2} + n_z · n_x · \sin^{2}\dfrac{\varphi}{2} \right) \\
1 & 0 & 0 & 0 \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
1 \\
\end{matrix}\right] \\
&= \mathop{\left[\begin{matrix}
0 & -n_y · \sin\varphi + n_z · n_x · (1 - \cos\varphi) & +n_x · \sin\varphi + n_y · n_z · (1 - \cos\varphi) & \cos\varphi + n_z^2 · (1 - \cos\varphi) \\
0 & +n_z · \sin\varphi + n_x · n_y · (1 - \cos\varphi) & \cos\varphi + n_y^2 · (1 - \cos\varphi) & -n_x · \sin\varphi + n_y · n_z · (1 - \cos\varphi) \\
0 & \cos\varphi + n_x^2 · (1 - \cos\varphi) & -n_z · \sin\varphi + n_x · n_y · (1 - \cos\varphi) & +n_y · \sin\varphi + n_z · n_x · (1 - \cos\varphi) \\
1 & 0 & 0 & 0 \\
\end{matrix}\right]}\limits_{4×4} \mathop{\rlap{×}{+}}\limits_{0=v_w}^{1=q_x^2+q_y^2+q_z^2+q_w^2} \mathop{\left[\begin{matrix}
v_z \\
v_y \\
v_x \\
0 \\
\end{matrix}\right]}\limits_{1+3} \\
\end{aligned}
$$

旋转矩阵所对应的四元数$ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}}$。注意：四元数的辐角是$\dfrac{\arg\bold{q}}{2}$，旋转矩阵的旋转角是$\arg\bold{q}$。注意：旋转矩阵所对应的四元数不唯一。

$$
\begin{aligned}
|q_z| &= \dfrac{\sqrt{1 + A[3][3] - A[1][1] - A[2][2]}}{2} \\
|q_y| &= \dfrac{\sqrt{1 + A[2][2] - A[3][3] - A[1][1]}}{2} \\
|q_x| &= \dfrac{\sqrt{1 + A[1][1] - A[2][2] - A[3][3]}}{2} \\
|q_w| &= \dfrac{\sqrt{1 + A[1][1] + A[2][2] + A[3][3]}}{2} \\
q_z &≡ \mathrm{sgn}(A[2][1] - A[1][2]) · |q_z| \\
q_y &≡ \mathrm{sgn}(A[1][3] - A[3][1]) · |q_y| \\
q_x &≡ \mathrm{sgn}(A[3][2] - A[2][3]) · |q_x| \\
q_w &≡ |q_w| \\
\end{aligned}
$$
