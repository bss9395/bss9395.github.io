---
layout:  zh_post
Topic :  收敛极限
Title :  四元数
Update:  2021-12-06T00:06:00+08@中国-广东-深圳+08
Author:  璀璨星辰
Credit:
---



Credit: https://zhuanlan.zhihu.com/p/27471300
Credit: https://www.qiujiawei.com/understanding-quaternions/
Credit: https://zhuanlan.zhihu.com/p/97186723
Credit: https://zhuanlan.zhihu.com/p/78987582

### 复数的运算性质

复数的辐角表示法。
$$
z = |z| · ә^{τ · (+\arg z)} = |z| · \cos (\arg z) + τ · |z| · \sin (\arg z)
$$
共轭复数。
$$
\begin{aligned}
\overline{z} &= |z| · ә^{τ · (-\arg z)} = |z| · \cos (\arg z) - τ · |z| · \sin (\arg z) \\
z · \overline{z} &= |z|^2 = z^2 \\
\end{aligned}
$$
复数的逆。
$$
{'}z = \dfrac{1}{z} = \dfrac{\overline{z}}{z^2}
$$
方向复数。
$$
ә^{τ · \phi} = \cos \phi + τ · \sin \phi
$$

单位复数。
$$
1 = ә^{τ · 0} = \cos 0 + τ · \sin 0
$$

单位虚数的点乘运算。
$$
τ · τ = -1
$$

方向复数的点乘运算。

$$
ә^{τ · \phi} · ә^{τ · \varphi} = ә^{τ · (\phi + \varphi)}
$$

### 矢量的运算性质

$3$维空间单位矢量。

$$
\begin{aligned}
\vec{i} = \left[\begin{matrix}
0 \\
0 \\
1 \\
\end{matrix}\right] && \vec{j} = \left[\begin{matrix}
0 \\
1 \\
0 \\
\end{matrix}\right] && \vec{k} = \left[\begin{matrix}
1 \\
0 \\
0 \\
\end{matrix}\right]
\end{aligned}
$$

$3$维空间单位矢量的点乘运算。

$$
\begin{aligned}
\vec{i} · \vec{i} = 1 && \vec{j} · \vec{j} = 1 && \vec{k} · \vec{k} = 1 \\
\vec{i} · \vec{j} = 0 && \vec{j} · \vec{k} = 0 && \vec{k} · \vec{i} = 0 \\
\vec{j} · \vec{i} = 0 && \vec{k} · \vec{j} = 0 && \vec{i} · \vec{k} = 0 \\
\end{aligned}
$$

$3$维空间单位矢量的叉乘运算。

$$
\begin{aligned}
\vec{i} × \vec{i} = +\vec{0} && \vec{j} × \vec{j} = +\vec{0} && \vec{k} × \vec{k} = +\vec{0} \\
\vec{i} × \vec{j} = +\vec{k} && \vec{j} × \vec{k} = +\vec{i} && \vec{k} × \vec{i} = +\vec{j} \\
\vec{j} × \vec{i} = -\vec{k} && \vec{k} × \vec{j} = -\vec{i} && \vec{i} × \vec{k} = -\vec{j} \\
\end{aligned}
$$

$3$维空间单位矢量的虚乘运算。

$$
\begin{aligned}
c * \vec{i} = c · \vec{i} &&  \\
\vec{i} * \vec{i} = -1 && \vec{j} * \vec{j} = -1 && \vec{k} * \vec{k} = -1 \\
\vec{i} * \vec{j} = +\vec{k} && \vec{j} * \vec{k} = +\vec{i} && \vec{k} * \vec{i} = +\vec{j} \\
\vec{j} * \vec{i} = -\vec{k} && \vec{k} * \vec{j} = -\vec{i} && \vec{i} * \vec{k} = -\vec{j} \\
\end{aligned}
$$

标量与$3$维空间矢量的点乘运算。

$$
\left[\begin{matrix}
c · v_z \\
c · v_y \\
c · v_x \\
\end{matrix}\right] = c · \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right]
$$

$3$维空间矢量与$3$维空间矢量的点乘运算。

$$
\begin{aligned}
|\vec{v}| · |\vec{w}| · \cos \ang(\vec{v},\vec{w}) = v_x · w_x + v_y · w_y + v_z · w_z &= \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] · \left[\begin{matrix}
w_z \\
w_y \\
w_x \\
\end{matrix}\right] = (\vec{i} · v_x + \vec{j} · v_y + \vec{k} · v_z) · (\vec{i} · w_x + \vec{j} · w_y + \vec{k} · w_z) \\
\end{aligned}
$$

$3$维空间矢量与$3$维空间矢量的叉乘运算。

$$
\begin{aligned}
\vec{n}_{\vec{v}×\vec{w}} · |\vec{v}| · |\vec{w}| · \sin \ang(\vec{v}, \vec{w}) = \left[\begin{matrix}
\vec{k} & v_z & w_z \\
\vec{j} & v_y & w_y \\
\vec{i} & v_x & w_x \\
\end{matrix}\right] &= \left[\begin{matrix}
v_x · w_y - v_y · w_x \\
v_z · w_x - v_x · w_z \\
v_y · w_z - v_z · w_y \\
\end{matrix}\right] = \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] × \left[\begin{matrix}
w_z \\
w_y \\
w_x \\
\end{matrix}\right] = (\vec{i} · v_x + \vec{j} · v_y + \vec{k} · v_z) × (\vec{i} · w_x + \vec{j} · w_y + \vec{k} · w_z) \\
&= \left[\begin{matrix}
-v_y & +v_x & 0 \\
+v_z & 0 & -v_x \\
0 & -v_z & +v_y \\
\end{matrix}\right] * \left[\begin{matrix}
w_z \\
w_y \\
w_x \\
\end{matrix}\right] 
\end{aligned}
$$

$3$维空间矢量与$3$维空间矢量的虚乘运算。
$$
\begin{aligned}
-\left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] · \left[\begin{matrix}
w_z \\
w_y \\
w_x \\
\end{matrix}\right] + \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] × \left[\begin{matrix}
w_z \\
w_y \\
w_x \\
\end{matrix}\right] &= \left[\begin{matrix}
v_z \\
v_y \\
v_x \\
\end{matrix}\right] * \left[\begin{matrix}
w_z \\
w_y \\
w_x \\
\end{matrix}\right] = (\vec{i} · v_x + \vec{j} · v_y + \vec{k} · v_z) * (\vec{i} · w_x + \vec{j} · w_y + \vec{k} · w_z) \\

\end{aligned}
$$



$3$维空间矢量的长度。
$$
|\vec{v}| = \left| \vec{i} · v_x + \vec{j} · v_y + \vec{k} · v_z \right| = \sqrt{v_x^2 + v_y^2 + v_z^2}
$$

$3$维空间方向矢量。
$$
\vec{n}_{\vec{v}} = \dfrac{\vec{v}}{|\vec{v}|} = \dfrac{\vec{i} · v_x + \vec{j} · v_y + \vec{k} · v_z}{\sqrt{v_x^2 + v_y^2 + v_z^2}}
$$

### 四元数的运算性质

四元数。

$$
\begin{aligned}
\bold{q} &= ә^{\vec{n}_{\vec{v}} · (+θ)} \\
&= \cos θ + \vec{n}_{\vec{v}} · \sin θ \\
&= \cos θ + (\vec{i} · n_x + \vec{j} · n_y + \vec{k} · n_z) · \sin θ \\
&= \cos θ + \left( \vec{i} · \dfrac{v_x}{|\vec{v}|} + \vec{j} · \dfrac{v_y}{|\vec{v}|} + \vec{k} · \dfrac{v_z}{|\vec{v}|} \right) · \sin θ \\
&= w + \vec{i} · x + \vec{j} · y + \vec{k} · z \\
&= q_w + \vec{q}_{\vec{n}} \\
\end{aligned}
$$

四元数的长度。
$$
1 = |\bold{q}| = |ә^{\vec{n}_{\vec{v}} · θ}| = \sqrt{w^2 + x^2 + y^2 + z^2}
$$

共轭四元数。
$$
\begin{aligned}
\overline{\bold{q}} &= ә^{\vec{n}_{\vec{v}} · (-θ)} \\
&= \cos θ - \vec{n}_{\vec{v}} · \sin θ \\
&= q_w - \vec{q}_{\vec{n}} \\
\bold{q} · \overline{\bold{q}} &= |\bold{q}|^2 = \left| \bold{q}^2 \right| = 1
\end{aligned}
$$
四元数的逆。
$$
{'}\bold{q} = \dfrac{1}{\bold{q}} = \dfrac{\overline{\bold{q}}}{|\bold{q}|^2} = \overline{\bold{q}}
$$

四元数的加运算。
$$
\begin{aligned}
\bold{p} + \bold{q} &= (w_p + \vec{i} · x_p + \vec{j} · y_p + \vec{k} · z_p) + (w_q + \vec{i} · x_q + \vec{j} · y_q + \vec{k} · z_q) \\
&= (w_p + w_q) + \vec{i} · (x_p + x_q) + \vec{j} · (y_p + y_q) + \vec{k} · (z_p + z_q)
\end{aligned}
$$


四元数的虚乘运算。
$$
\begin{aligned}
\bold{p} * \bold{q} &= (p_w + \vec{p}_{\vec{n}}) * (q_w + \vec{q}_{\vec{n}}) \\
&= p_w · q_w + p_w · \vec{q}_{\vec{n}} + q_w · \vec{p}_{\vec{n}} + \vec{p}_{\vec{n}} * \vec{q}_{\vec{n}} \\
&= (p_w · q_w - \vec{p}_{\vec{n}} · \vec{q}_{\vec{n}}) + p_w · \vec{q}_{\vec{n}} + q_w · \vec{p}_{\vec{n}} + \vec{p}_{\vec{n}} × \vec{q}_{\vec{n}} \\
\bold{p} * \bold{q} &= (w_p + \vec{i} · x_p + \vec{j} · y_p + \vec{k} · z_p) * (w_q + \vec{i} · x_q + \vec{j} · y_q + \vec{k} · z_q) \\
&= (w_p · w_q - x_p · x_q - y_p · y_q - z_p · z_q) \\
&+ \vec{i} · (w_p · x_q + x_p · w_q + y_p · z_q - z_p · y_q) \\
&+ \vec{j} · (w_p · y_q + y_p · w_q + z_p · x_q - x_p · z_q) \\
&+ \vec{k} · (w_p · z_q + z_p · w_q + x_p · y_q - y_p · x_q) \\
\end{aligned}
$$

$$
\begin{aligned}
\bold{p} * \vec{v} &= (p_w + \vec{p}_{\vec{n}}) * \vec{v} \\
&= -\vec{p}_{\vec{n}} · \vec{v} + p_w · \vec{v} + \vec{p}_{\vec{n}} × \vec{v} \\
\vec{v} * \overline{\bold{q}} &= \vec{v} * (q_w - \vec{q}_{\vec{n}}) \\
&= +\vec{q}_{\vec{n}} · \vec{v} + q_w · \vec{v} + \vec{q}_{\vec{n}} × \vec{v} \\
\end{aligned}
$$

四元数的旋转运算。
$$
\begin{aligned}
\bold{q} * \vec{v} * {'}\bold{q} &= \bold{q} * \vec{v} * \overline{\bold{q}} \\
&= (q_w + \vec{q}_{\vec{n}}) * \vec{v} * (q_w - \vec{q}_{\vec{n}}) \\
&= (q_w · \vec{v} + \vec{q}_{\vec{n}} * \vec{v}) * (q_w - \vec{q}_{\vec{n}}) \\
&= q_w^2 · \vec{v} + q_w · \vec{q}_{\vec{n}} * \vec{v} - q_w · \vec{v} * \vec{q}_{\vec{n}} - \vec{q}_{\vec{n}} * \vec{v} * \vec{q}_{\vec{n}} \\
&= q_w^2 · \vec{v} + 2 · q_w · \vec{q}_{\vec{n}} × \vec{v} - (- \vec{q}_{\vec{n}} · \vec{v} + \vec{q}_{\vec{n}} × \vec{v}) * \vec{q}_{\vec{n}} \\
&= q_w^2 · \vec{v} + 2 · q_w · \vec{q}_{\vec{n}} × \vec{v} + \vec{q}_{\vec{n}} · \vec{v} · \vec{q}_{\vec{n}} - \vec{q}_{\vec{n}} × \vec{v} × \vec{q}_\vec{n} \\
&= 
\end{aligned}
$$
