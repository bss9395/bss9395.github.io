---
layout:  zh_post
Topic :  收敛极限
Title :  四元数
Update:  2021-12-16T01:15:00+08@中国-广东-深圳+08
Author:  璀璨星辰
Credit:
---

### 复数的运算性质

虚数的运算性质。虚数的虚乘运算必满足交换律。

$$
\begin{aligned}
c \circledast τ &= c · τ \\
τ \circledast τ &= -1 \\
\end{aligned}
$$

复数的辐角表示法。辐角的旋转轴为$+τ$轴。

$$
\begin{aligned}
z = |z| · ә^{+τ · \arg z} &≡ |z| · [+τ · \sin(\arg z) + \cos(\arg z)] \\
z &= τ · \mathrm{Im}(z) + \mathrm{Re}(z) \\
\end{aligned}
$$

复数的辐角。

$$
\begin{aligned}
\sin(\arg z) &= \dfrac{\mathrm{Im}(z)}{|z|} \\
\cos(\arg z) &= \dfrac{\mathrm{Re}(z)}{|z|} \\
\tan(\arg z) &= \dfrac{\mathrm{Im}(z)}{\mathrm{Re}(z)} \\
\end{aligned}
$$

共轭复数。

$$
\begin{aligned}
\overline{z} = |z| · ә^{-τ · \arg z} &= |z| · [- τ · \sin(\arg z) + \cos(\arg z)] \\
|z|^2 = z \circledast \overline{z} &≡ |z|^2 · [+τ · \sin(\arg z) + \cos(\arg z)] \circledast [-τ · \sin(\arg z) + \cos(\arg z)] = |z|^2 · \left[ -τ^2 · \sin^2(\arg z) + \cos^2(\arg z) \right] \\
z^2 = z \circledast z &≡ |z|^2 · \left[ +τ · \sin(\arg z) + \cos(\arg z) \right] \circledast \left[ +τ · \sin(\arg z) + \cos(\arg z) \right] = |z|^2 · [ τ · \cos(2 · \arg z) + \sin(2 · \arg z) ] \\
\end{aligned}
$$

倒逆复数。

$$
{'}z = \dfrac{1}{z} = \dfrac{\overline{z}}{|z|^2} = \dfrac{\overline{z}}{|z^2|} ≠ \dfrac{\overline{z}}{z^2}
$$

单位复数。

$$
1 = τ · 0 + 1 = ә^{τ · 0} = τ · \sin 0 + \cos 0
$$

规范复数。

$$
\dfrac{z}{|z|} = ә^{τ · \arg z} = τ · \sin(\arg z) + \cos(\arg z)
$$

规范复数的位加运算。复数的位加运算必满足交换律。

$$
\begin{aligned}
ә^{τ · \arg p} + ә^{τ · \arg q} ≡ [τ · \sin(\arg p) + \cos(\arg p)] + [τ · \sin(\arg q) + \cos(\arg q)] \\
ә^{τ · (\arg p + \arg q)} ≠ ә^{τ · \arg p} + ә^{τ · \arg q} = τ · [\sin(\arg p) + \sin(\arg p)] + [\cos(\arg p) + \cos(\arg q)] \\
\end{aligned}
$$

规范复数的虚乘运算。复数的虚乘运算必满足交换律。

$$
\begin{aligned}
ә^{τ · \arg p} \circledast ә^{τ · \arg q} &≡ [τ · \sin(\arg p) + \cos(\arg p)] \circledast [τ · \sin(\arg q) + \cos(\arg q)] \\
ә^{τ · (\arg p + \arg q)} = ә^{τ · \arg p} \circledast ә^{τ · \arg q} &= τ · \sin(\arg p + \arg q) + \cos(\arg p + \arg q)] \\
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

$3$维空间基矢量的叉乘运算。矢量的叉乘运算不满足交换律。

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
-\left[\begin{matrix}
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
\end{matrix}\right] &= \left[\begin{matrix}
-u_x & -u_y & -u_z \\
-u_y & +u_x & 0 \\
+u_z & 0 & -u_x \\
0 & -u_z & +u_y \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
\end{aligned}
$$

$3$维空间矢量的规范化。

$$
\begin{aligned}
\dfrac{\vec{v}}{|\vec{v}|} &= \dfrac{\vec{η}_x · v_x + \vec{η}_y · v_y + \vec{η}_z · v_z}{\sqrt{v_x^2 + v_y^2 + v_z^2}} \\
\vec{n}_{\vec{v}} &= \vec{η}_x · n_x + \vec{η}_y · n_y + \vec{η}_z · n_z \\
\end{aligned}
$$

### 四元数的运算性质

四元数的辐角表示法。辐角的旋转轴为$+\vec{n}$轴。

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
\sin(\arg\bold{q}) &= {'}\vec{n}_{\vec{q}} \rlap{×}{+} \dfrac{\vec{q}}{|\bold{q}|} \\
\cos(\arg\bold{q}) &= \dfrac{q}{|\bold{q}|} \\
\tan(\arg\bold{q}) &= \dfrac{{'}\vec{n}_{\vec{q}} \rlap{×}{+} \vec{q}}{q} \\
|\tan(\arg\bold{q})| &≠ \dfrac{|\vec{q}|}{|q|} \\
\left[ \tan\dfrac{θ_p}{2} = \tan\dfrac{θ_q}{2} \right] &⇔ \left[ θ_p = θ_q \mathrm{\ mod\ } 360° \right] \\
\end{aligned}
$$

共轭四元数。

$$
\begin{aligned}
\overline{\bold{q}} &= |\bold{q}| · ә^{-\vec{n}·\arg \bold{q}} = |\bold{q}| · [-\vec{n} · \sin(\arg \bold{q}) + \cos(\arg \bold{q})] \\
\overline{\bold{q}} &= -\vec{q} + q = - \vec{η}_x · q_x - \vec{η}_y · q_y - \vec{η}_z · q_z + q_w \\
\bold{q}^2 &= |\bold{q}|^2 = \bold{q} \circledast \overline{\bold{q}} = |\bold{q}|^2 · \left[ -\vec{n}^2 · \sin^2(\arg\bold{q}) + \cos^2(\arg\bold{q}) \right] \\
\end{aligned}
$$

倒逆四元数。

$$
{'}\bold{q} = \dfrac{1}{\bold{q}} = \dfrac{\overline{\bold{q}}}{|\bold{q}|^2}
$$

单位四元数。

$$
\vec{0} + 1 = ә^{\vec{n} · 0} = \vec{n} · \sin 0 + \cos 0
$$

规范四元数。

$$
\begin{aligned}
\dfrac{\bold{q}}{|\bold{q}|} &= ә^{\vec{n} · \arg \bold{q}} = \vec{n} · \sin(\arg \bold{q}) + \cos(\arg \bold{q}) \\
\dfrac{\bold{q}}{|\bold{q}|} &= \vec{q} + q = \vec{η}_x · q_x + \vec{η}_y · q_y + \vec{η}_z · q_z + q_w \\
\end{aligned}
$$

矢量四元数。

$$
ә^{\vec{v} · \frac{π}{2}} = \vec{v} = \vec{v} · \sin \dfrac{π}{2} + \cos \dfrac{π}{2}
$$

四元数的虚乘运算。

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
\end{matrix}\right] &=-\left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \odot \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] + \left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] \otimes \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] + q_w · \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] + v_w · \left[\begin{matrix}
q_z \\
q_y \\
q_x \\
\end{matrix}\right] + q_w · v_w = \left[\begin{matrix}
-q_x & -q_y & -q_z \\
-q_y & +q_x & +q_w \\
+q_z & +q_w & -q_x \\
+q_w & -q_z & +q_y \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] + \left[\begin{matrix}
q_w \\
q_z \\
q_y \\
q_x \\
\end{matrix}\right] · v_w \\
&= \left[\begin{matrix}
-q_x & -q_y & -q_z & +q_w \\
-q_y & +q_x & +q_w & +q_z \\
+q_z & +q_w & -q_x & +q_y \\
+q_w & -q_z & +q_y & +q_x \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
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

四元数的对称虚虚乘运算。

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
\end{matrix}\right] \circledast \left[\begin{matrix}
q_w \\
q_z \\
q_y \\
q_x \\
\end{matrix}\right] &= \left[\begin{matrix}
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

\end{matrix}\right] \\
\end{aligned}
$$

$$
\left[\begin{matrix}
-(+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_x - (+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_y - (-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_z + (-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_w \\
-(+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_x + (+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_y + (-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_z + (-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_w \\
+(-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_x + (-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_y - (+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_z + (+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_w \\
+(-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_x - (-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_y + (+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_z + (+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_w \\
\end{matrix}\right]
$$

$$
\left[\begin{matrix}
(- q_w · q_x - q_z · q_y + q_y · q_z - q_x · q_w) · v_x + (+ q_z · q_x - q_w · q_y - q_x · q_z - q_y · q_w) · v_y + (- q_y · q_x + q_x · q_y - q_w · q_z - q_z · q_w) · v_y + (- q_x^2 - q_y^2 - q_z^2 + q_w^2) · v_w \\
(- q_z · q_x + q_w · q_y - q_x · q_z - q_y · q_w) · v_x + (- q_w · q_x - q_z · q_y - q_y · q_z + q_x · q_w) · v_y + (+ q_x^2 + q_y^2 - q_z^2 + q_w^2) · v_z + (- q_y · q_x + q_x · q_y + q_w · q_z + q_z · q_w) · v_w \\
(- q_y · q_x - q_x · q_y - q_w · q_z + q_z · q_w) · v_x + (+ q_x^2 - q_y^2 + q_z^2 + q_w^2) · v_y + (+ q_w · q_x - q_z · q_y - q_y · q_z - q_x · q_w) · v_z + (+ q_z · q_x + q_w · q_y - q_x · q_z + q_y · q_w) · v_w \\
(- q_x^2 + q_y^2 + q_z^2 + q_w^2) · v_x + (- q_y · q_x - q_x · q_y + q_w · q_z - q_z · q_w) · v_y + (- q_z · q_x - q_w · q_y - q_x · q_z + q_y · q_w) · v_z + (+ q_w · q_x - q_z · q_y + q_y · q_z + q_x · q_w) · v_w \\
\end{matrix}\right]
$$

$$
\left[\begin{matrix}
-2 · q_w · q_x & -2 · q_y · q_w & -2 · q_z · q_w & -q_x^2 - q_y^2 - q_z^2 + q_w^2 \\
-2 · q_z · q_x & -2 · q_y · q_z & +q_x^2 + q_y^2 - q_z^2 + q_w^2 & +2 · q_z · q_w \\
-2 · q_x · q_y & +q_x^2 - q_y^2 + q_z^2 + q_w^2 & -2 · q_y · q_z & +2 · q_y · q_w \\
-q_x^2 + q_y^2 + q_z^2 + q_w^2 & -2 · q_x · q_y & -2 · q_z · q_x & +2 · q_w · q_x \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_w \\
v_z \\
v_y \\
v_x \\
\end{matrix}\right] \\
$$

四元数的逆称虚虚乘运算。

$$
\begin{aligned}
\left[\begin{matrix}
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
\end{matrix}\right] &= \left[\begin{matrix}
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

\end{matrix}\right] \\
\end{aligned}
$$

$$
\left[\begin{matrix}
+(+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_x + (+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_y + (-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_z + (-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_w \\
+(+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_x - (+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_y - (-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_z + (-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_w \\
-(-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_x - (-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_y + (+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_z + (+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_w \\
-(-q_x · v_x - q_y · v_y - q_z · v_z + q_w · v_w) · q_x + (-q_y · v_x + q_x · v_y + q_w · v_z + q_z · v_w) · q_y - (+q_z · v_x + q_w · v_y - q_x · v_z + q_y · v_w) · q_z + (+q_w · v_x - q_z · v_y + q_y · v_z + q_x · v_w) · q_w \\
\end{matrix}\right]
$$

$$
\left[\begin{matrix}
(+ q_w · q_x + q_z · q_y - q_y · q_z - q_x · q_w) · v_x + (- q_z · q_x + q_w · q_y + q_x · q_z - q_y · q_w) · v_y + (+ q_y · q_x - q_x · q_y + q_w · q_z - q_z · q_w) · v_y + (+ q_x^2 + q_y^2 + q_z^2 + q_w^2) · v_w \\
(+ q_z · q_x - q_w · q_y + q_x · q_z - q_y · q_w) · v_x + (+ q_w · q_x + q_z · q_y + q_y · q_z + q_x · q_w) · v_y + (- q_x^2 - q_y^2 + q_z^2 + q_w^2) · v_z + (+ q_y · q_x - q_x · q_y - q_w · q_z + q_z · q_w) · v_w \\
(+ q_y · q_x + q_x · q_y + q_w · q_z + q_z · q_w) · v_x + (- q_x^2 + q_y^2 - q_z^2 + q_w^2) · v_y + (- q_w · q_x + q_z · q_y + q_y · q_z - q_x · q_w) · v_z + (- q_z · q_x - q_w · q_y + q_x · q_z + q_y · q_w) · v_w \\
(+ q_x^2 - q_y^2 - q_z^2 + q_w^2) · v_x + (+ q_y · q_x + q_x · q_y - q_w · q_z - q_z · q_w) · v_y + (+ q_z · q_x + q_w · q_y + q_x · q_z + q_y · q_w) · v_z + (- q_w · q_x + q_z · q_y - q_y · q_z + q_x · q_w) · v_w \\
\end{matrix}\right]
$$

$$
\left[\begin{matrix}
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
$$

$$
\left[\begin{matrix}
0 & 0 & 0 & 1 \\
2 · (q_z · q_x - q_y · q_w) & 2 · (q_y · q_z + q_x · q_w) & 1 - 2 · (q_x^2 - q_y^2) & 0 \\
2 · (q_x · q_y + q_z · q_w) & 1 - 2 · (q_x^2 - q_z^2) & 2 · (q_y · q_z - q_x · q_w) & 0 \\
1 - 2 · (q_y^2 + q_z^2) & 2 · (q_x · q_y - q_z · q_w) & 2 · (q_z · q_x + q_y · q_w) & 0 \\
\end{matrix}\right] \mathop{\rlap{×}{+}}\limits_{0=v_w}^{1=q_x^2+q_y^2+q_z^2+q_w^2} \left[\begin{matrix}
0 \\
v_z \\
v_y \\
v_x \\
\end{matrix}\right]
$$

