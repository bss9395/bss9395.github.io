---
layout:  zh_post
Topic :  收敛极限
Title :  拟合插值
Update:  2021-12-26T12:07:00+08@中国-广东-深圳+08
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

### 平面线性插值

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

### 球面线性插值

$$
\begin{aligned}
\bold{v}\langle \varphi_t \rangle &= \dfrac{\sin(\varphi_1 - \varphi_t)}{\sin(\varphi_1 - \varphi_0)} · \bold{v}_0 + \dfrac{\sin(\varphi_t - \varphi_0)}{\sin(\varphi_1 - \varphi_0)} · \bold{v}_1 \\


\end{aligned}
$$

$$

$$



