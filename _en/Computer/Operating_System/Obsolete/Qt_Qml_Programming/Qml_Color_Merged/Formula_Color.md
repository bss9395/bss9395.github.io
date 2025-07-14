### 颜色融合
### 采用方法：前本背补。前景色为本色，背景色为补色，前景色叠加背景色

$$
\begin{aligned}
A_{ba} & 可调换顺序 \\
A_{ba} &= A_b + A_a * (1 - A_b) \\
       &= A_b + A_a - A_b * A_a \\
\\
C_{ba} & 不可调换顺序 \\
C_{ba} &= C_b * A_b + C_a * A_a * (1 - A_b) \\
       &= C_b * A_b + C_a * A_a - C_a * A_b * A_a \\
\end{aligned}
$$

$$
\begin{aligned}
A_{cba} & 可调换顺序 \\
A_{cba} &= A_c + A_{ba} * (1 - A_c) \\
        &= A_c + [A_b + A_a - A_b * A_a] * (1 - A_c) \\
        &= A_c + [A_b + A_a - A_b * A_a] - [A_c * A_b + A_c * A_a - A_c * A_b * A_a] \\
        &= A_c + A_b + A_a - A_c * A_b - A_c * A_a - A_b * A_a + A_c * A_b * A_a \\
\\
C_{cba} & 不可调换顺序 \\
C_{cba} &= C_c * A_c + C_{ba} * (1 - A_c) \\
        &= C_c * A_c + [C_b * A_b + C_a * A_a - C_a * A_b * A_a] * (1 - A_c) \\
        &= C_c * A_c + [C_b * A_b + C_a * A_a - C_a * A_b * A_a] - [C_b * A_c * A_b + C_a * A_c * A_a - C_a * A_c * A_b * A_a] \\
        &= C_c * A_c + C_b * A_b + C_a * A_a - C_b * A_c * A_b - C_a * A_c * A_a - C_a * A_b * A_a + C_a * A_c * A_b * A_a \\
\end{aligned}
$$

