---
layout:  zh_post
Topic :  收敛极限
Title :  仿射变换
Update:  2021-12-22T00:15:00+08@中国-广东-深圳+08
Author:  璀璨星辰
Link  :
---

### 仿射变换的运算性质

线性变换前后原点保持重合，线性变换前后直线保持直线。

$$
\begin{aligned}
&\lbrack相似性\rbrack & f(c · \vec{v}) &= c · f(\vec{v}) \\
&\lbrack叠加性\rbrack & f(\vec{u} + \vec{v}) &= f(\vec{u}) + f(\vec{v}) \\
\end{aligned}
$$

仿射变换前后原点不必重合，仿射变换前后直线保持直线。仿射变换 = 线性变换 + 平移变换。

$$
\begin{aligned}
\vec{u} &= \mathrm{L_{inear}} \mathop{\rlap{×}{+}} \vec{v} + \mathrm{\vec{t}_{ranslation}} \\
\left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\end{matrix}\right] &= \left[\begin{matrix}
l_{3,1} & l_{3,2} & l_{3,3} \\
l_{2,1} & l_{2,2} & l_{2,3} \\
l_{1,1} & l_{1,2} & l_{1,3} \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] + \left[\begin{matrix}
t_z \\
t_y \\
t_x \\
\end{matrix}\right] \\
\left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\hline
1 \\
\end{matrix}\right] &= \left[\begin{array}{c|ccc}
t_z & l_{3,1} & l_{3,2} & l_{3,3} \\
t_y & l_{2,1} & l_{2,2} & l_{2,3} \\
t_x & l_{1,1} & l_{1,2} & l_{1,3} \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
\end{aligned}
$$

### 齐次变换 Homogen

若无特别的规定，约定齐次坐标为向量而非矢量，约定齐次坐标的各个分量均为实数而非复数。

对于齐次坐标，当其标量非零时表示矢量空间中的点，当其标量为零时表示矢量空间中的矢量。注意：矢量空间中的矢量为两点之差值。
$$
\begin{aligned}
\left[\begin{matrix}
v_z · v_w^{-1} \\
v_y · v_w^{-1} \\
v_x · v_w^{-1} \\
\hline
1 \\
\end{matrix}\right] &\mathop{===}\limits_{0≠v_w} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
v_w \\
\end{matrix}\right] \\
\left[\begin{matrix}
u_z - v_z \\
u_y - v_y \\
u_x - v_x \\
\hline
0 \\
\end{matrix}\right] &\mathop{===}\limits_{1=v_w}^{1=u_w} \left[\begin{matrix}
u_z \\
u_y \\
u_x \\
\hline
1 \\
\end{matrix}\right] - \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
\end{aligned}
$$

### 恒等变换 Identity

恒等变换矩阵为单位矩阵。
$$
\left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] = \left[\begin{array}{c|ccc}
0 & 0 & 0 & 1 \\
0 & 0 & 1 & 0 \\
0 & 1 & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
$$

### 缩放变换 Scaling

$$
\left[\begin{matrix}
s_z · v_z \\
s_y · v_y \\
s_x · v_x \\
\hline
1 \\
\end{matrix}\right] = \left[\begin{array}{c|ccc}
0 & 0 & 0 & s_z \\
0 & 0 & s_y & 0 \\
0 & s_x & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
$$

### 切变变换 Shearing

$$
\left[\begin{matrix}
v_z + s_{z:x} · v_x + s_{z:y} · v_y \\
v_y + s_{y:z} · v_z + s_{y:x} · v_x \\
v_x + s_{x:y} · v_y + s_{x:z} · v_z \\
\hline
1 \\
\end{matrix}\right] = \left[\begin{array}{c|ccc}
0 & s_{z:x} & s_{z:y} & 1 \\
0 & s_{y:x} & 1 & s_{y:z} \\
0 & 1 & s_{x:y} & s_{x:z} \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
$$

### 平移变换 Translation

$$
\left[\begin{matrix}
v_z + t_z \\
v_y + t_y \\
v_x + t_x \\
\hline
1 \\
\end{matrix}\right] = \left[\begin{array}{c|ccc}
t_z & 0 & 0 & 1 \\
t_y & 0 & 1 & 0 \\
t_x & 1 & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
$$

### 旋转变换 Rotation

以$3$维空间矢量$\vec{η}_x · n_x + \vec{η}_y · n_y + \vec{η}_z · n_z$为旋转轴，将$3$维空间矢量$\vec{v}$按右手旋转角度$\varphi$。

$$
\begin{aligned}
&\left[\begin{matrix}
v_z · \cos\varphi + (v_y · n_x - v_x · n_y) · \sin\varphi + (v_x · n_z · n_x + v_y · n_y · n_z + v_z · n_z^2) · (1 - \cos\varphi) \\
v_y · \cos\varphi + (v_x · n_z - v_z · n_x) · \sin\varphi + (v_x · n_x · n_y + v_y · n_y^2 + v_z · n_y · n_z) · (1 - \cos\varphi) \\
v_x · \cos\varphi + (v_z · n_y - v_y · n_z) · \sin\varphi + (v_x · n_x^2 + v_y · n_x · n_y + v_z · n_z · n_x) · (1 - \cos\varphi) \\
\hline
1 \\
\end{matrix}\right] \\
&= \left[\begin{array}{c|ccc}
0 & -n_y · \sin\varphi + n_z · n_x · (1 - \cos\varphi) & +n_x · \sin\varphi + n_y · n_z · (1 - \cos\varphi) & \cos\varphi + n_z^2 · (1 - \cos\varphi) \\
0 & +n_z · \sin\varphi + n_x · n_y · (1 - \cos\varphi) & \cos\varphi + n_y^2 · (1 - \cos\varphi) & -n_x · \sin\varphi + n_y · n_z · (1 - \cos\varphi) \\
0 & \cos\varphi + n_x^2 · (1 - \cos\varphi) & -n_z · \sin\varphi + n_x · n_y · (1 - \cos\varphi) & +n_y · \sin\varphi + n_z · n_x · (1 - \cos\varphi) \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
\end{aligned}
$$

以$3$维空间矢量$\vec{η}_x$为旋转轴，将$3$维空间矢量$\vec{v}$按右手旋转角度$\varphi$。

$$
\left[\begin{matrix}
+ v_y · \sin\varphi + v_z · \cos\varphi \\
+ v_y · \cos\varphi - v_z · \sin\varphi \\
+ v_x \\
\hline
1 \\
\end{matrix}\right] = \left[\begin{array}{c|ccc}
0 & 0 & +\sin\varphi & +\cos\varphi \\
0 & 0 & +\cos\varphi & -\sin\varphi \\
0 & 1 & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right]
$$

以$3$维空间矢量$\vec{η}_y$为旋转轴，将$3$维空间矢量$\vec{v}$按右手旋转角度$\varphi$。

$$
\left[\begin{matrix}
- v_x · \sin\varphi + v_z · \cos\varphi \\
+ v_y \\
+ v_x · \cos\varphi + v_z · \sin\varphi \\
\hline
1 \\
\end{matrix}\right] = \left[\begin{array}{c|ccc}
0 & -\sin\varphi & 0 & +\cos\varphi \\
0 & 0 & 1 & 0 \\
0 & +\cos\varphi & 0 & +\sin\varphi \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
$$

以$3$维空间矢量$\vec{η}_z$为旋转轴，将$3$维空间矢量$\vec{v}$按右手旋转角度$\varphi$。

$$
\left[\begin{matrix}
+ v_z \\
+ v_x · \sin\varphi + v_y · \cos\varphi \\
+ v_x · \cos\varphi - v_y · \sin\varphi \\
\hline
1 \\
\end{matrix}\right] = \left[\begin{array}{c|ccc}
0 & 0 & 0 & 1 \\
0 & +\sin\varphi & +\cos\varphi & 0 \\
0 & +\cos\varphi & -\sin\varphi & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
$$

### 镜像变换 Mirroring

以$3$维空间原点$O$为镜像点，将$3$为空间矢量$\vec{v}$镜像化。

$$
\left[\begin{matrix}
- v_z \\
- v_y \\
- v_x \\
\hline
1 \\
\end{matrix}\right] = \left[\begin{array}{c|ccc}
0 & 0 & 0 & -1 \\
0 & 0 & -1 & 0 \\
0 & -1 & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
$$

以$3$维空间直线$Ox$为镜像轴，将$3$为空间矢量$\vec{v}$镜像化。以直线为镜像轴相当于绕直线旋转$180°$。

$$
\left[\begin{matrix}
- v_z \\
- v_y \\
+ v_x \\
\hline
1 \\
\end{matrix}\right] = \left[\begin{array}{c|ccc}
0 & 0 & 0 & -1 \\
0 & 0 & -1 & 0 \\
0 & +1 & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
$$

以$3$维空间直线$Oy$为镜像轴，将$3$为空间矢量$\vec{v}$镜像化。以直线为镜像轴相当于绕直线旋转$180°$。

$$
\left[\begin{matrix}
- v_z \\
+ v_y \\
- v_x \\
\hline
1 \\
\end{matrix}\right] = \left[\begin{array}{c|ccc}
0 & 0 & 0 & -1 \\
0 & 0 & +1 & 0 \\
0 & -1 & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
$$

以$3$维空间直线$Oz$为镜像轴，将$3$为空间矢量$\vec{v}$镜像化。以直线为镜像轴相当于绕直线旋转$180°$。

$$
\left[\begin{matrix}
+ v_z \\
- v_y \\
- v_x \\
\hline
1 \\
\end{matrix}\right] = \left[\begin{array}{c|ccc}
0 & 0 & 0 & +1 \\
0 & 0 & -1 & 0 \\
0 & -1 & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
$$

以$3$维空间平面$yOz$为镜像面，将$3$维空间矢量$\vec{v}$镜像化。

$$
\left[\begin{matrix}
+ v_z \\
+ v_y \\
- v_x \\
\hline
1 \\
\end{matrix}\right] = \left[\begin{array}{c|ccc}
0 & 0 & 0 & +1 \\
0 & 0 & +1 & 0 \\
0 & -1 & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
$$

以$3$维空间平面$zOx$为镜像面，将$3$维空间矢量$\vec{v}$镜像化。

$$
\left[\begin{matrix}
+ v_z \\
- v_y \\
+ v_x \\
\hline
1 \\
\end{matrix}\right] = \left[\begin{array}{c|ccc}
0 & 0 & 0 & +1 \\
0 & 0 & -1 & 0 \\
0 & +1 & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
$$

以$3$维空间平面$xOy$为镜像轴，将$3$维空间矢量$\vec{v}$镜像化。

$$
\left[\begin{matrix}
- v_z \\
+ v_y \\
+ v_x \\
\hline
1 \\
\end{matrix}\right] = \left[\begin{array}{c|ccc}
0 & 0 & 0 & -1 \\
0 & 0 & +1 & 0 \\
0 & +1 & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\hline
1 \\
\end{matrix}\right] \\
$$

### 反射变换 Reflection

$$

$$

### 折射变换 Refraction

$$

$$

### 右手坐标系与左手坐标系

$$
\begin{aligned}
\left[\begin{matrix}
-1,+1 \\
-1,+1 \\
-1,+1 \\
\hline
1 \\
\end{matrix}\right] &\mathop{======}\limits_{[+1;+1;+1]}^{\mathrm{right-handed}} \mathrm{P}_{\mathrm{rojection}} \rlap{×}{+} \left[\begin{matrix}
+z_{\mathrm{near}},+z_{\mathrm{far}} \\
+y_{\mathrm{bottom}},+y_{\mathrm{top}} \\
+x_{\mathrm{left}},+x_{\mathrm{right}} \\
\hline
1 \\
\end{matrix}\right] \\
\left[\begin{matrix}
-1,+1 \\
-1,+1 \\
-1,+1 \\
\hline
1 \\
\end{matrix}\right] &\mathop{======}\limits_{[+1;+1;-1]}^{\mathrm{left-handed}} \mathrm{P}_{\mathrm{rojection}} \rlap{×}{+} \left[\begin{matrix}
-z_{\mathrm{near}},-z_{\mathrm{far}} \\
+y_{\mathrm{bottom}},+y_{\mathrm{top}} \\
+x_{\mathrm{left}},+x_{\mathrm{right}} \\
\hline
1 \\
\end{matrix}\right] \\
\end{aligned}
$$

### 正交投影变换 Orthographic Projection

```
正交投影变换的步骤，共计2步：
[平移变换] 将长方体的中心平移与原点重合；
[缩放变换] 将长方体的三围缩放到[-1, +1]；
```

$$
\begin{aligned}
\mathrm{T_{ranslate}} &= \left[\begin{array}{c|ccc}
-\frac{z_{\mathrm{far}} + z_{\mathrm{hear}}}{2} & 0 & 0 & 1 \\
-\frac{y_{\mathrm{top}} + y_{\mathrm{bottom}}}{2} & 0 & 1 & 0 \\
-\frac{x_{\mathrm{left}} + x_{\mathrm{right}}}{2} & 1 & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \\
\mathrm{S_{cale}} &= \left[\begin{array}{c|ccc}
0 & 0 & 0 & \frac{-2}{z_{\mathrm{far}} - z_{\mathrm{near}}} \\
0 & 0 & \frac{+2}{y_{\mathrm{top}} - y_{\mathrm{bottom}}} & 0 \\
0 & \frac{+2}{x_{\mathrm{right}} - x_{\mathrm{left}}} & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \\
\mathrm{O_{rthogonalize}} &= \mathrm{S_{cale}} \rlap{×}{+} \mathrm{T_{ranslate}} \\
&= \left[\begin{array}{c|ccc}
0 & 0 & 0 & \frac{-2}{z_{\mathrm{far}} - z_{\mathrm{near}}} \\
0 & 0 & \frac{+2}{y_{\mathrm{top}} - y_{\mathrm{bottom}}} & 0 \\
0 & \frac{+2}{x_{\mathrm{right}} - x_{\mathrm{left}}} & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \rlap{×}{+} \left[\begin{array}{c|ccc}
-\frac{z_{\mathrm{far}} + z_{\mathrm{hear}}}{2} & 0 & 0 & 1 \\
-\frac{y_{\mathrm{top}} + y_{\mathrm{bottom}}}{2} & 0 & 1 & 0 \\
-\frac{x_{\mathrm{left}} + x_{\mathrm{right}}}{2} & 1 & 0 & 0 \\
\hline
1 & 0 & 0 & 0 \\
\end{array}\right] \\
\mathrm{O_{rthogonalize}} &= \left[\begin{matrix}
+\frac{z_{\mathrm{far}} + z_{\mathrm{hear}}}{z_{\mathrm{far}} - z_{\mathrm{near}}} & 0 & 0 & \frac{-2}{z_{\mathrm{far}} - z_{\mathrm{near}}} \\
-\frac{y_{\mathrm{top}} + y_{\mathrm{bottom}}}{y_{\mathrm{top}} - y_{\mathrm{bottom}}} & 0 & \frac{+2}{y_{\mathrm{top}} - y_{\mathrm{bottom}}} & 0 \\
-\frac{x_{\mathrm{right}} + x_{\mathrm{left}}}{x_{\mathrm{right}} - x_{\mathrm{left}}} & \frac{+2}{x_{\mathrm{right}} - x_{\mathrm{left}}} & 0 & 0 \\
1 & 0 & 0 & 0 \\
\end{matrix}\right] \\
\end{aligned}
$$

### 透视投影变换 Perspective Projection

