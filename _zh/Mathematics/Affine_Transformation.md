---
layout:  zh_post
Topic :  收敛极限
Title :  仿射变换
Update:  2021-12-21T00:51:00+08@中国-广东-深圳+08
Author:  璀璨星辰
Link  :
---

### 齐次变换 Homogen

$$
\left[\begin{matrix}
v_z · v_w^{-1} \\
v_y · v_w^{-1} \\
v_x · v_w^{-1} \\
1 \\
\end{matrix}\right] \mathop{===}\limits_{v_w≠0} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
v_w \\
\end{matrix}\right] \\
$$

### 恒等变换 Identity

$$
\left[\begin{matrix}
v_z \\
v_y \\
v_x \\
1 \\
\end{matrix}\right] = \left[\begin{matrix}
0 & 0 & 0 & 1 \\
0 & 0 & 1 & 0 \\
0 & 1 & 0 & 0 \\
1 & 0 & 0 & 0 \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
1 \\
\end{matrix}\right] \\
$$

### 缩放变换 Scaling

$$
\left[\begin{matrix}
s_z · v_z \\
s_y · v_y \\
s_x · v_x \\
1 \\
\end{matrix}\right] = \left[\begin{matrix}
0 & 0 & 0 & s_z \\
0 & 0 & s_y & 0 \\
0 & s_x & 0 & 0 \\
1 & 0 & 0 & 0 \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
1 \\
\end{matrix}\right] \\
$$

### 平移变换 Translation

$$
\left[\begin{matrix}
v_z + t_z \\
v_y + t_y \\
v_x + t_x \\
1 \\
\end{matrix}\right] = \left[\begin{matrix}
t_z & 0 & 0 & 1 \\
t_y & 0 & 1 & 0 \\
t_x & 1 & 0 & 0 \\
1 & 0 & 0 & 0 \\
\end{matrix}\right] \rlap{×}{+} \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
1
\end{matrix}\right] \\
$$

### 旋转变换 Rotation

$$
\begin{aligned}
&\left[\begin{matrix}
v_z · \cos\varphi + (v_y · n_x - v_x · n_y) · \sin\varphi + (v_x · n_z · n_x + v_y · n_y · n_z + v_z · n_z^2) · (1 - \cos\varphi) \\
v_y · \cos\varphi + (v_x · n_z - v_z · n_x) · \sin\varphi + (v_x · n_x · n_y + v_y · n_y^2 + v_z · n_y · n_z) · (1 - \cos\varphi) \\
v_x · \cos\varphi + (v_z · n_y - v_y · n_z) · \sin\varphi + (v_x · n_x^2 + v_y · n_x · n_y + v_z · n_z · n_x) · (1 - \cos\varphi) \\
1 \\
\end{matrix}\right] \\
&= \mathop{\left[\begin{matrix}
0 & -n_y · \sin\varphi + n_z · n_x · (1 - \cos\varphi) & +n_x · \sin\varphi + n_y · n_z · (1 - \cos\varphi) & \cos\varphi + n_z^2 · (1 - \cos\varphi) \\
0 & +n_z · \sin\varphi + n_x · n_y · (1 - \cos\varphi) & \cos\varphi + n_y^2 · (1 - \cos\varphi) & -n_x · \sin\varphi + n_y · n_z · (1 - \cos\varphi) \\
0 & \cos\varphi + n_x^2 · (1 - \cos\varphi) & -n_z · \sin\varphi + n_x · n_y · (1 - \cos\varphi) & +n_y · \sin\varphi + n_z · n_x · (1 - \cos\varphi) \\
1 & 0 & 0 & 0 \\
\end{matrix}\right]}\limits_{4×4} \rlap{×}{+} \mathop{\left[\begin{matrix}
v_z \\
v_y \\
v_x \\
1 \\
\end{matrix}\right]}\limits_{1+3} \\
\end{aligned}
$$

### 推移变换 Shear Transformation

$$
\mathop{\left[\begin{matrix}
v_z + s_{z:x} · v_x + s_{z:y} · v_y \\
v_y + s_{y:z} · v_z + s_{y:x} · v_x \\
v_x + s_{x:y} · v_y + s_{x:z} · v_z \\
1 \\
\end{matrix}\right]}\limits_{1+3} = \mathop{\left[\begin{matrix}
0 & s_{z:x} & s_{z:y} & 1 \\
0 & s_{y:x} & 1 & s_{y:z} \\
0 & 1 & s_{x:y} & s_{x:z} \\
1 & 0 & 0 & 0 \\
\end{matrix}\right]}\limits_{4×4} \rlap{×}{+} \mathop{\left[\begin{matrix}
v_z \\
v_y \\
v_x \\
0 \\
\end{matrix}\right]}\limits_{1+3} \\
$$

### 反射 Reflection

$$

$$

### 折射 Refraction

$$

$$

