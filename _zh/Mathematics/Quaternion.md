---
layout:  zh_post
Topic :  收敛极限
Title :  四元数
Update:  2021-12-19T18:20:00+08@中国-广东-深圳+08
Author:  璀璨星辰
Credit:
---

### 特别注意

```
本书中对复数的取值共有2种度量运算。
本书中复数的长度值为Le(z)，而非|z|。
本书中复数的度量值定为Measurement，而非绝对值Absolute，其符号为|z|。
本书中长度值对复数才有意义，实数的长度值与其度量值相等，但意义不同。
本书中对四元数的倒逆运算有2种，四元数的合乘倒逆运算与虚乘倒逆运算。
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

复数的长度值。注意，复数的长度值是非负实数。

$$
\mathrm{Le}(z) = \sqrt{\mathrm{Im}^2(z) + \mathrm{Re}^2(z)}
$$

复数的度量值。注意，复数的度量值是复数，但未必都是非负实数。

$$
|z| = \sqrt{z \circledast z}
$$

复数的辐角表示法。辐角的旋转轴为$+τ$轴。

$$
\begin{aligned}
z = \mathrm{Le}(z) · ә^{+τ · \arg z} &≡ \mathrm{Le}(z) · [+τ · \sin(\arg z) + \cos(\arg z)] \\
z = τ · \mathrm{Im}(z) + \mathrm{Re}(z) &= τ · z_y + z_x \\
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
1 = τ · 0 + 1 = ә^{τ · 0} = τ · \sin 0 + \cos 0
$$

规范复数。

$$
\begin{aligned}
\dfrac{z}{\mathrm{Le}(z)} &= ә^{τ · \arg z} = τ · \sin(\arg z) + \cos(\arg z) \\
\dfrac{z}{\mathrm{Le}(z)} &= \dfrac{τ · \mathrm{Im}(z) + \mathrm{Re}(z)}{\mathrm{Le}(z)} = \dfrac{τ · z_y + z_x}{\sqrt{z_y^2 + z_x^2}} \\
\end{aligned}
$$

共轭复数。

$$
\begin{aligned}
\overline{z} = \mathrm{Le}(z) · ә^{-τ · \arg z} &= \mathrm{Le}(z) · [- τ · \sin(\arg z) + \cos(\arg z)] \\
\mathrm{Le}^2(z) = z \circledast \overline{z} &≡ \mathrm{Le}^2(z) · [+τ · \sin(\arg z) + \cos(\arg z)] \circledast [-τ · \sin(\arg z) + \cos(\arg z)] = \mathrm{Le}^2(z) · \left[ -τ^{2} · \sin^2(\arg z) + \cos^2(\arg z) \right] \\
z^2 ≡ z \circledast z &≡ \mathrm{Le}^2(z) · \left[ +τ · \sin(\arg z) + \cos(\arg z) \right] \circledast \left[ +τ · \sin(\arg z) + \cos(\arg z) \right] = \mathrm{Le}^2(z) · [ τ · \cos(2 · \arg z) + \sin(2 · \arg z) ] \\
\end{aligned}
$$

倒逆复数。若无特别的规定，复数的倒逆运算指虚乘倒逆运算，而非合乘倒逆运算，复数的两种倒逆运算其值相等但意义不同。

$$
{'}z ≡ \circledast^{-1} {z} = \dfrac{\overline{z}}{\mathrm{Le}^2(z)} = \dfrac{\overline{z}}{\mathrm{Le}(z^2)} ≠ \dfrac{\overline{z}}{z^2}
$$

任意规范复数的位加运算。复数的位加运算必满足交换律。复数的位加运算必满足结合律。
$$
\begin{aligned}
\mathrm{Le}(q) · ә^{τ · \arg q} + \mathrm{Le}(z) · ә^{τ · \arg z} &≡ \mathrm{Le}(q) · [τ · \sin(\arg q) + \cos(\arg q)] + \mathrm{Le}(z) · [τ · \sin(\arg z) + \cos(\arg z)] \\
\mathrm{Le}(q) · ә^{τ · \arg q} + \mathrm{Le}(z) · ә^{τ · \arg z} &= τ · [\mathrm{Le}(q) · \sin(\arg q) + \mathrm{Le}(z) · \sin(\arg z)] + [\mathrm{Le}(q) · \cos(\arg z) + \mathrm{Le}(z) · \cos(\arg z)] \\
\end{aligned}
$$

任意规范复数的虚乘运算。复数的虚乘运算必满足交换律。复数的虚乘运算必满足结合律。

$$
\begin{aligned}
\left[ \mathrm{Le}(q) · ә^{τ · \arg q} \right] \circledast \left[ \mathrm{Le}(z) · ә^{τ · \arg z} \right] &≡ \mathrm{Le}(q) · \mathrm{Le}(z) · [τ · \sin(\arg q) + \cos(\arg q)] \circledast [τ · \sin(\arg z) + \cos(\arg z)] \\
\mathrm{Le}(q) · \mathrm{Le}(z) · ә^{τ · (\arg q + \arg z)} = \left[ \mathrm{Le}(q) · ә^{τ · \arg q} \right] \circledast \left[ \mathrm{Le}(z) · ә^{τ · \arg z} \right] &= \mathrm{Le}(q) · \mathrm{Le}(z) · [τ · \sin(\arg q + \arg z) + \cos(\arg q + \arg z)] \\
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
\left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] \otimes_3 \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] -_4 \left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] \odot_3 \left[\begin{matrix}
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
-u_x & -u_y & -u_z \\
-u_y & +u_x & 0 \\
+u_z & 0 & -u_x \\
0 & -u_z & +u_y \\
\end{matrix}\right]}\limits_{4×3} \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] = \left[\begin{matrix} 
-u_x · v_x - u_y · v_y - u_z · v_z \\
-u_y · v_x + u_z · v_z \\
+u_z · v_x - u_x · v_z \\
-u_z · v_y + u_y · v_z \\
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
\vec{u} \circledast \vec{v} &= +\vec{u} \otimes \vec{v} - \vec{u} \odot \vec{v} \\
\vec{v} \circledast \vec{v} &= -\vec{u} \otimes \vec{v} - \vec{u} \odot \vec{v} \\
\vec{u} \otimes \vec{v} &= +\dfrac{1}{2} · [\vec{u} \circledast \vec{v} - \vec{v} \circledast \vec{u}] \\
\vec{u} \odot \vec{v} &= -\dfrac{1}{2} · [\vec{u} \circledast \vec{v} + \vec{v} \circledast \vec{u}] \\
\end{aligned}
$$

$3$维空间矢量的平行分量。

$$
\begin{aligned}
\vec{v}_{∥\vec{n}} &= \vec{n} \odot \vec{v} · \vec{n} \\
&= -\dfrac{1}{2} · [\vec{n} \circledast \vec{v} + \vec{v} \circledast \vec{n}] \circledast \vec{n} \\
&= -\dfrac{1}{2} · [\vec{n} \circledast \vec{v} \circledast \vec{n} + \vec{v} \circledast \vec{n} \circledast \vec{n}] \\
&= \dfrac{1}{2} · [-\vec{n} \circledast \vec{v} \circledast \vec{n} + \vec{v}] \\
\end{aligned}
$$

$3$维空间矢量的垂直分量。

$$
\begin{aligned}
\vec{v}_{⊥\vec{n}} &= \vec{n} \otimes \vec{v} \otimes \vec{n} \\
&= +\dfrac{1}{2} · [\vec{n} \circledast \vec{v} - \vec{v} \circledast \vec{n}] \otimes \vec{n} \\
&= +\dfrac{1}{4} · [(\vec{n} \circledast \vec{v} - \vec{v} \circledast \vec{n}) \circledast \vec{n} - \vec{n} \circledast (\vec{n} \circledast \vec{v} - \vec{v} \circledast \vec{n})] \\
&= \dfrac{1}{2} · [+\vec{n} \circledast \vec{v} \circledast \vec{n} + \vec{v}] \\
\end{aligned}
$$

### 四元数的运算性质

若无特别的规定，约定四元数的四个分量均为实数而非复数。注意：四元数其指数的矢量部分为其矢量部分的规范矢量。

四元数的度量值。四元数的度量值是非负实数。

$$
|\bold{q}| = \sqrt{q_x^2 + q_y^2 + q_z^2 + q_w^2}
$$

四元数的辐角表示法。辐角的旋转轴为$+\vec{n}_{\vec{q}}$轴。

$$
\begin{aligned}
\bold{q} = |\bold{q}| · ә^{+\vec{n}_{\vec{q}} · \arg \bold{q}} &≡ |\bold{q}| · \left[ +\vec{n}_{\vec{q}} · \sin(\arg \bold{q}) + \cos(\arg \bold{q}) \right] \\
\bold{q} = +\vec{q} + q &= +\vec{η}_x · q_x + \vec{η}_y · q_y + \vec{η}_z · q_z + q_w \\
\
\end{aligned}
$$

四元数的辐角。

$$
\begin{aligned}
\sin(\arg\bold{q}) &= \dfrac{{'}\vec{n}_{\vec{q}} \rlap{×}{+} \vec{q}}{|\bold{q}|} \\
\cos(\arg\bold{q}) &= \dfrac{q}{|\bold{q}|} \\
\tan(\arg\bold{q}) &= \dfrac{{'}\vec{n}_{\vec{q}} \rlap{×}{+} \vec{q}}{q} \\
|\tan(\arg\bold{q})| &≠ \dfrac{|\vec{q}|}{|q|} \\
\left[ \tan\dfrac{θ_p}{2} = \tan\dfrac{θ_q}{2} \right] &⇔ \left[ θ_p = θ_q \mathrm{\ mod\ } 360° \right] \\
\end{aligned}
$$

单位四元数。

$$
\vec{0} + 1 = ә^{\vec{n} · 0} = \vec{n}_{\vec{q}} · \sin 0 + \cos 0
$$

规范四元数。

$$
\begin{aligned}
\dfrac{\bold{q}}{|\bold{q}|} &= ә^{\vec{n}_{\vec{q}} · \arg \bold{q}} = \vec{n}_{\vec{q}} · \sin(\arg \bold{q}) + \cos(\arg \bold{q}) \\
\dfrac{\bold{q}}{|\bold{q}|} &= \dfrac{\vec{q} + q}{|\bold{q}|} = \dfrac{\vec{η}_x · q_x + \vec{η}_y · q_y + \vec{η}_z · q_z + q_w }{\sqrt{q_x^2 + q_y^2 + q_z^2 + q_w^2}} \\
\end{aligned}
$$

矢量四元数。

$$
\rlap{ә^{\rlap{\vec{v} · \frac{π}{2}}{≡≡}}}{≡≡} ⇔ |\vec{v}| · ә^{\vec{n}_{\vec{v}} · \frac{π}{2}} = \vec{v} = |\vec{v}| · \left[ \vec{n}_{\vec{v}} · \sin \dfrac{π}{2} + \cos \dfrac{π}{2} \right]
$$

共轭四元数。

$$
\begin{aligned}
\overline{\bold{q}} &= |\bold{q}| · ә^{-\vec{n}_{\vec{q}}·\arg \bold{q}} = |\bold{q}| · [-\vec{n}_{\vec{q}} · \sin(\arg \bold{q}) + \cos(\arg \bold{q})] \\
\overline{\bold{q}} &= -\vec{q} + q = - \vec{η}_x · q_x - \vec{η}_y · q_y - \vec{η}_z · q_z + q_w \\
|\bold{q}|^2 = \bold{q} \circledast \overline{\bold{q}} &≡ |\bold{q}|^2 · \left[ +\vec{n}_{\vec{q}} · \sin(\arg\bold{q}) + \cos(\arg\bold{q}) \right] \circledast \left[ -\vec{n}_{\vec{q}} · \sin(\arg\bold{q}) + \cos(\arg\bold{q}) \right] = |\bold{q}|^2 · \left[ -\vec{n}_{\vec{q}}^{2} · \sin^2(\arg\bold{q}) + \cos^2(\arg\bold{q}) \right] \\
\bold{q}^2 = \bold{q} \circledast \bold{q} &≡ |\bold{q}|^2 · \left[ +\vec{n}_{\vec{q}} · \sin(\arg\bold{q}) + \cos(\arg\bold{q}) \right] \circledast \left[ +\vec{n}_{\vec{q}} · \sin(\arg\bold{q}) + \cos(\arg\bold{q}) \right] = |\bold{q}|^2 · \left[ \vec{n}_{\vec{q}} · \sin(2 · \arg\bold{q}) + \cos(2 · \arg\bold{q}) \right] \\
\end{aligned}
$$

倒逆四元数。若无特别的规定，约定四元数的倒逆运算指虚乘倒逆运算，而非合乘倒逆运算，四元数的两种倒逆运算其值不等且意义不同。

$$
{'}\bold{q} ≡ \circledast^{-1}\bold{q} = \dfrac{\overline{\bold{q}}}{|\bold{q}|^2} = \dfrac{\overline{\bold{q}}}{|\bold{q}^2|} ≠ \dfrac{\overline{\bold{q}}}{\bold{q}^2}
$$

同向四元数的位加运算。四元数的位加运算必满足交换律。同向四元数的位加运算必满足结合律。

$$
\begin{aligned}
\left[ |\bold{q}| · ә^{\vec{n}·\arg\bold{q}} \right] + \left[ |\bold{v}| · ә^{\vec{n}·\arg\bold{v}} \right] &≡ |\bold{q}| · \left[ \vec{n} · \sin(\arg\bold{q}) + \cos(\arg\bold{q}) \right] + |\bold{v}| · \left[ \vec{n} · \sin(\arg\bold{v}) + \cos(\arg\bold{v}) \right] \\
\left[ |\bold{q}| · ә^{\vec{n}·\arg\bold{q}} \right] + \left[ |\bold{v}| · ә^{\vec{n}·\arg\bold{v}} \right] &= \vec{n} · [|\bold{q}| · \sin(\arg\bold{q}) + |\bold{v}| · \sin(\arg\bold{v})] + [|\bold{q}| · \cos(\arg\bold{q}) + |\bold{v}| · \cos(\arg\bold{v})] \\
\end{aligned}
$$

同向四元数的虚乘运算。四元数的虚乘运算不满足交换律。同向四元数的虚乘运算必满足结合律。

$$
\begin{aligned}
\left[ |\bold{q}| · ә^{\vec{n}·\arg\bold{q}} \right] \circledast \left[ |\bold{v}| · ә^{\vec{n}·\arg\bold{v}} \right] &≡ |\bold{q}| · |\bold{v}| · \left[ \vec{n} · \sin(\arg\bold{q}) + \cos(\arg\bold{q}) \right] \circledast \left[ \vec{n} · \sin(\arg\bold{v}) + \cos(\arg\bold{v}) \right] \\
|\bold{q}| · |\bold{v}| · ә^{\vec{n}·(\arg\bold{q}+\arg\bold{v})} = \left[ |\bold{q}| · ә^{\vec{n}·\arg\bold{q}} \right] \circledast \left[ |\bold{v}| · ә^{\vec{n}·\arg\bold{v}} \right] &= |\bold{q}| · |\bold{v}| · [ \vec{n} · \sin(\arg\bold{q} + \arg\bold{v}) + \cos(\arg\bold{q} + \arg\bold{v})] \\
\end{aligned}
$$

任意四元数的位加运算。四元数的位加运算必满足交换律。四元数的位加运算必满足结合律。

$$
\begin{aligned}
\left[\begin{matrix}
u_w \\
u_z \\
u_y \\
u_x \\
\end{matrix}\right] + \left[\begin{matrix}
v_w \\
v_z \\
v_y \\
v_x \\
\end{matrix}\right] &≡ (\vec{η}_x · u_x + \vec{η}_y · u_y + \vec{η}_z · u_z + u_w) + (\vec{η}_x · v_x + \vec{η}_y · v_y + \vec{η}_z · v_z + v_w) \\
&= \vec{η}_x · (u_x + v_x) + \vec{η}_y · (u_y + v_y) + \vec{η}_z · (u_z + v_z) \\
\left[\begin{matrix}
u_w \\
u_z \\
u_y \\
u_x \\
\end{matrix}\right] + \left[\begin{matrix}
v_w \\
v_z \\
v_y \\
v_x \\
\end{matrix}\right] &= \left[\begin{matrix}
u_w + v_w \\
u_z + v_z \\
u_y + v_y \\
u_x + v_x \\
\end{matrix}\right] \\
\end{aligned}
$$

任意四元数的虚乘运算。四元数的虚乘运算不满足交换律。四元数的虚乘运算?满足结合律。

$$
\begin{aligned}
\left[\begin{matrix}
q_w \\
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \circledast \left[\begin{matrix}
v_w \\
v_z \\
v_y \\
v_x \\
\end{matrix}\right] &≡ (\vec{η}_x · q_x + \vec{η}_y · q_y + \vec{η}_z · q_z + q_w) \circledast (\vec{η}_x · v_x + \vec{η}_y · v_y + \vec{η}_z · v_z + v_w) \\
&= (\vec{η}_x · q_x + \vec{η}_y · q_y + \vec{η}_z · q_z) \circledast (\vec{η}_x · v_x + \vec{η}_y · v_y + \vec{η}_z · v_z) + q_w · (\vec{η}_x · v_x + \vec{η}_y · v_y + \vec{η}_z · v_z) + v_w · (\vec{η}_x · q_x + \vec{η}_y · q_y + \vec{η}_z · q_z) + q_w · v_w \\
\left[\begin{matrix}
q_w \\
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \circledast \left[\begin{matrix}
v_w \\
v_z \\
v_y \\
v_x \\
\end{matrix}\right] &= \left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] -_4 \left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \odot \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] +_4 q_w · \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] +_4 v_w · \left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] +_4 q_w · v_w = \mathop{\left[\begin{matrix}
-q_x & -q_y & -q_z \\
-q_y & +q_x & +q_w \\
+q_z & +q_w & -q_x \\
+q_w & -q_z & +q_y \\
\end{matrix}\right]}\limits_{4×3} \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] +_4 \left[\begin{matrix}
q_w \\
q_z \\
q_y \\
q_x \\
\end{matrix}\right] · v_w \\
&= \mathop{\left[\begin{matrix}
-q_x & -q_y & -q_z & +q_w \\
-q_y & +q_x & +q_w & +q_z \\
+q_z & +q_w & -q_x & +q_y \\
+q_w & -q_z & +q_y & +q_x \\
\end{matrix}\right]}\limits_{4×4} \rlap{×}{+} \left[\begin{matrix}
v_w \\
v_z \\
v_y \\
v_x \\
\end{matrix}\right] = \left[\begin{matrix}
-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w \\
-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w \\
+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w \\
+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w \\
\end{matrix}\right] \\
\end{aligned}
$$

### 四元数的旋转运算

$3$维空间矢量的旋转运算。以$3$维空间矢量$\vec{n}_{⊥\vec{v}}$为旋转轴，将$3$维空间矢量$\vec{v}$右旋转角度$\varphi$变成$3$维空间矢量$\vec{u}$。

$$
\begin{aligned}
\vec{u} \odot \vec{v} &= +|\vec{v}|^2 · \cos\varphi \\
\vec{u} \otimes \vec{v} &= -|\vec{v}|^2 · \vec{n}_{⊥} · \sin\varphi \\
\vec{u} \circledast \vec{v} &= \vec{u} \otimes \vec{v} - \vec{u} \odot \vec{v} = |\vec{v}|^2 · [-\vec{n}_{⊥} · \sin\varphi - \cos\varphi] = |\vec{u}|^2 · [-\vec{n}_{⊥} · \sin\varphi - \cos\varphi] \\
\vec{u} &= \vec{u} \circledast \vec{v} \circledast {'}\vec{v} = |\vec{v}|^2 · [-\vec{n}_{⊥} · \sin\varphi - \cos\varphi] \circledast \left( -\dfrac{\vec{v}}{|\vec{v}|^2} \right) \\
\vec{u} &=  ә^{+\vec{n}_{⊥}·\varphi} \circledast \vec{v} \\
\vec{v} &= {'}\vec{u} \circledast \vec{u} \circledast \vec{v} = |\vec{u}|^2 · \left( -\dfrac{\vec{u}}{|\vec{u}|^2} \right) \circledast [-\vec{n}_{⊥} · \sin\varphi - \cos\varphi] \\
\vec{v} &= \vec{u} \circledast ә^{+\vec{n}_{⊥}·\varphi} \\
ә^{+\vec{n}_{⊥}·(2·\varphi)} \circledast \vec{v} &= ә^{+\vec{n}_{⊥}·\varphi} \circledast \vec{v} \circledast ә^{-\vec{n}_{⊥}·\varphi} \\
\end{aligned}
$$

四元数对$3$维空间矢量常规旋转运算的几何意义。注意：四元数对$3$维空间矢量常规运算的值是四元数。

$$
\begin{aligned}
ә^{\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast \vec{v} &= ә^{\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast (\vec{v}_{⊥\vec{q}} + \vec{v}_{∥\vec{q}}) \\
&= ә^{\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast \vec{v}_{⊥\vec{q}} + ә^{\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast \left(\vec{v}_{∥\vec{q}} · \sin\dfrac{π}{2} + \cos\dfrac{π}{2} \right) \\
ә^{\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast \vec{v} &= ә^{\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast \vec{v}_{⊥\vec{q}} + \left| \vec{v}_{∥\vec{q}} \right| · ә^{\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast ә^{\vec{n}_{\vec{q}}·\frac{π}{2}} \\
\end{aligned}
$$

四元数对$3$维空间矢量倒逆旋转运算的几何意义。注意：四元数的逆称虚虚乘运算的值是$3$维空间矢量。

$$
\begin{aligned}
ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \circledast \vec{v} \circledast ә^{-\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} &= \left[ ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \circledast \vec{v}_{⊥\vec{q}} + \left| \vec{v}_{∥\vec{q}} \right| · ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \circledast ә^{\vec{n}_{\vec{q}}·\frac{π}{2}} \right] \circledast ә^{-\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \\
&= ә^{+\vec{n}_{\vec{q}}·\arg\bold{q}} \circledast \vec{v}_{⊥\vec{q}} + \vec{v}_{∥\vec{q}} \\
&= \vec{u}_{⊥\vec{q}} + \vec{u}_{∥\vec{q}} \\
\end{aligned}
$$

四元数的任意叉叉乘运算。

$$
\left[\begin{matrix}
q_w \\
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \circledast \left[\begin{matrix}
v_w \\
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \circledast \left[\begin{matrix}
p_w \\
p_z \\
p_y \\
p_x \\
\end{matrix}\right] \\
=  \\
$$

四元数的对称虚虚乘运算。
$$
\begin{aligned}
&\left[ |\bold{q}| · ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \right] \circledast \left[ |\bold{v}| · ә^{+\vec{n}_{\vec{v}}·\arg\bold{v}}  \right] \circledast \left[ |\bold{q}| · ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \right] \\
&= \left[\begin{matrix}
q_w \\
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \circledast \left[\begin{matrix}
v_w \\
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \circledast \left[\begin{matrix}
q_w \\
q_z \\
q_y \\
q_x \\
\end{matrix}\right] = \left[\begin{matrix}
-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w \\
-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w \\
+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w \\
+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w \\
\end{matrix}\right] \circledast \left[\begin{matrix}
q_w \\
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
-(+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_x - (+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_y - (-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_z + (-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_w \\
-(+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_x + (+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_y + (-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_z + (-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_w \\
+(-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_x + (-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_y - (+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_z + (+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_w \\
+(-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_x - (-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_y + (+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_z + (+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_w \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
(- q_w · q_x - q_z · q_y + q_y · q_z - q_x · q_w) · v_x + (+ q_z · q_x - q_w · q_y - q_x · q_z - q_y · q_w) · v_y + (- q_y · q_x + q_x · q_y - q_w · q_z - q_z · q_w) · v_z + (- q_x^2 - q_y^2 - q_z^2 + q_w^2) · v_w \\
(- q_z · q_x + q_w · q_y - q_x · q_z - q_y · q_w) · v_x + (- q_w · q_x - q_z · q_y - q_y · q_z + q_x · q_w) · v_y + (+ q_x^2 + q_y^2 - q_z^2 + q_w^2) · v_z + (- q_y · q_x + q_x · q_y + q_w · q_z + q_z · q_w) · v_w \\
(- q_y · q_x - q_x · q_y - q_w · q_z + q_z · q_w) · v_x + (+ q_x^2 - q_y^2 + q_z^2 + q_w^2) · v_y + (+ q_w · q_x - q_z · q_y - q_y · q_z - q_x · q_w) · v_z + (+ q_z · q_x + q_w · q_y - q_x · q_z + q_y · q_w) · v_w \\
(- q_x^2 + q_y^2 + q_z^2 + q_w^2) · v_x + (- q_y · q_x - q_x · q_y + q_w · q_z - q_z · q_w) · v_y + (- q_z · q_x - q_w · q_y - q_x · q_z + q_y · q_w) · v_z + (+ q_w · q_x - q_z · q_y + q_y · q_z + q_x · q_w) · v_w \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
-2 · q_x · q_w & -2 · q_y · q_w & -2 · q_z · q_w & -q_x^2 - q_y^2 - q_z^2 + q_w^2 \\
-2 · q_z · q_x & -2 · q_y · q_z & +q_x^2 + q_y^2 - q_z^2 + q_w^2 & +2 · q_z · q_w \\
-2 · q_x · q_y & +q_x^2 - q_y^2 + q_z^2 + q_w^2 & -2 · q_y · q_z & +2 · q_y · q_w \\
-q_x^2 + q_y^2 + q_z^2 + q_w^2 & -2 · q_x · q_y & -2 · q_z · q_x & +2 · q_x · q_w \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_w \\
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\end{aligned}
$$

四元数的逆称虚虚乘运算。

$$
\begin{aligned}
&\left[ |\bold{q}| · ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \right] \circledast \left[ |\bold{v}| · ә^{+\vec{n}_{\vec{v}}·\arg\bold{v}}  \right] \circledast \left[ |\bold{q}| · ә^{-\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \right] \\
&= \left[\begin{matrix}
+q_w \\
+q_z \\
+q_y \\
+q_x \\
\end{matrix}\right] \circledast \left[\begin{matrix}
v_w \\
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \circledast \left[\begin{matrix}
+q_w \\
-q_z \\
-q_y \\
-q_x \\
\end{matrix}\right] = \left[\begin{matrix}
-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w \\
-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w \\
+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w \\
+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w \\
\end{matrix}\right] \circledast \left[\begin{matrix}
+q_w \\
-q_z \\
-q_y \\
-q_x \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
+(+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_x + (+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_y + (-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_z + (-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_w \\
+(+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_x - (+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_y - (-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_z + (-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_w \\
-(-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_x - (-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_y + (+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_z + (+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_w \\
-(-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_x + (-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_y - (+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_z + (+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_w \\
\end{matrix}\right] \\
&= \left[\begin{matrix}
0 & 0 & 0 & +q_x^2 + q_y^2 + q_z^2 + q_w^2 \\
2 · (q_z · q_x - q_y · q_w) & 2 · (q_y · q_z + q_x · q_w) & -q_x^2 - q_y^2 + q_z^2 + q_w^2 & 0 \\
2 · (q_x · q_y + q_z · q_w) & -q_x^2 + q_y^2 - q_z^2 + q_w^2 & 2 · (q_y · q_z - q_x · q_w) & 0 \\
+q_x^2 - q_y^2 - q_z^2 + q_w^2 & 2 · (q_x · q_y - q_z · q_w) & 2 · (q_z · q_x + q_y · q_w) & 0 \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_w \\
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\end{aligned}
$$

四元数对应的旋转矩阵。注意：四元数对应的旋转矩阵必唯一。

$$
\begin{aligned}
&\left[ |\bold{q}| · ә^{+\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \right] \circledast \vec{v} \circledast \left[ |\bold{q}| · ә^{-\vec{n}_{\vec{q}}·\frac{\arg\bold{q}}{2}} \right] \\
&= \left[ + \vec{η}_x · q_x + \vec{η}_y · q_y + \vec{η}_z · q_z + q_w \right] \circledast \vec{v} \circledast \left[ - \vec{η}_x · q_x - \vec{η}_y · q_y - \vec{η}_z · q_z + q_w \right] \\
&= \left[\begin{matrix}
0 & 0 & 0 & 1 \\
2 · (q_z · q_x - q_y · q_w) & 2 · (q_y · q_z + q_x · q_w) & 1 - 2 · (q_x^2 + q_y^2) & 0 \\
2 · (q_x · q_y + q_z · q_w) & 1 - 2 · (q_x^2 + q_z^2) & 2 · (q_y · q_z - q_x · q_w) & 0 \\
1 - 2 · (q_y^2 + q_z^2) & 2 · (q_x · q_y - q_z · q_w) & 2 · (q_z · q_x + q_y · q_w) & 0 \\
\end{matrix}\right] \mathop{\rlap{×}{+}}\limits_{0=v_w}^{1=q_x^2+q_y^2+q_z^2+q_w^2} \left[\begin{matrix}
0 \\
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\end{aligned}
$$

旋转矩阵对应的四元数。注意：旋转矩阵对应的四元数不唯一。

$$
\begin{aligned}
|q_w| &= \dfrac{\sqrt{1 + A[0][0] + A[1][1] + A[2][2]}}{2} \\
|q_x| &= \dfrac{\sqrt{1 + A[0][0] - A[1][1] - A[2][2]}}{2} \\
|q_y| &= \dfrac{\sqrt{1 + A[1][1] - A[2][2] - A[0][0]}}{2} \\
|q_z| &= \dfrac{\sqrt{1 + A[2][2] - A[0][0] - A[1][1]}}{2} \\
q_w &≡ |q_w| \\
q_x &≡ \mathrm{sgn}(A[2][1] - A[1][2]) · |q_x| \\
q_y &≡ \mathrm{sgn}(A[0][2] - A[2][0]) · |q_y| \\
q_z &≡ \mathrm{sgn}(A[1][0] - A[0][1]) · |q_z| \\
\end{aligned}
$$
