---
layout: zh_post
Topic : 收敛极限
Title : 经典案例
Update: 2022-01-31T23:45:00+08@中国-广东-湛江+08
Author: 璀璨星辰
Credit: 《线性代数（数学专业用）》李尚志
Notice: 本书限于本人能力范围，如果有疏漏之处请联系，brilliantstarrysky9395@gmail.com
---

### 幻方游戏

$$
\begin{aligned}
\lbrace 1, 2, ⋯, 25 \rbrace &= 5 · \lbrace 0, 1, 2, 3, 4 \rbrace + \lbrace 1, 2, 3, 4, 5 \rbrace \\
\begin{array}{|c|c|c|c|c|}
\hline
0 & 5 & 10 & 15 & 20 \\
\hline
10 & 15 & 20 & 0 & 5 \\
\hline
20 & 0 & 5 & 10 & 15 \\
\hline
5 & 10 & 15 & 20 & 0 \\
\hline
15 & 20 & 0 & 5 & 10 \\
\hline
\end{array} &= 5 · \begin{array}{|c|c|c|c|}
\hline
0 & 1 & 2 & 3 & 4 \\
\hline
2 & 3 & 4 & 0 & 1 \\
\hline
4 & 0 & 1 & 2 & 3 \\
\hline
1 & 2 & 3 & 4 & 0 \\
\hline
3 & 4 & 0 & 1 & 2 \\
\hline
\end{array} \\
\begin{array}{|c|c|c|c|c|} 
\hline
0 & 6 & 12 & 18 & 24 \\
\hline
13 & 19 & 20 & 1 & 7 \\
\hline
21 & 2 & 8 & 14 & 15 \\
\hline
9 & 10 & 16 & 22 & 3 \\
\hline
17 & 23 & 4 & 5 & 11 \\
\hline
\end{array} &= 5 · \begin{array}{|c|c|c|c|}
\hline
0 & 1 & 2 & 3 & 4 \\
\hline
2 & 3 & 4 & 0 & 1 \\
\hline
4 & 0 & 1 & 2 & 3 \\
\hline
1 & 2 & 3 & 4 & 0 \\
\hline
3 & 4 & 0 & 1 & 2 \\
\hline
\end{array} + \begin{array}{|c|c|c|c|c|}
\hline
0 & 1 & 2 & 3 & 4 \\
\hline
3 & 4 & 0 & 1 & 2  \\
\hline
1 & 2 & 3 & 4 & 0 \\
\hline
4 & 0 & 1 & 2 & 3 \\
\hline
2 & 3 & 4 & 0 & 1 \\
\hline
\end{array} \\
\begin{array}{|c|c|c|c|c|}
\hline
1 & 7 & 13 & 19 & 25 \\
\hline
14 & 20 & 21 & 2 & 8  \\
\hline
22 & 23 & 9 & 15 & 16 \\
\hline
10 & 11 & 17 & 23 & 4 \\
\hline
18 & 24 & 5 & 6 & 12 \\
\hline
\end{array} &= 5 · \begin{array}{|c|c|c|c|}
\hline
0 & 1 & 2 & 3 & 4 \\
\hline
2 & 3 & 4 & 0 & 1 \\
\hline
4 & 0 & 1 & 2 & 3 \\
\hline
1 & 2 & 3 & 4 & 0 \\
\hline
3 & 4 & 0 & 1 & 2 \\
\hline
\end{array} + \begin{array}{|c|c|c|c|c|}
\hline
0 & 1 & 2 & 3 & 4 \\
\hline
3 & 4 & 0 & 1 & 2  \\
\hline
1 & 2 & 3 & 4 & 0 \\
\hline
4 & 0 & 1 & 2 & 3 \\
\hline
2 & 3 & 4 & 0 & 1 \\
\hline
\end{array} + \begin{array}{|c|c|c|c|c|}
\hline
1 & 1 & 1 & 1 & 1 \\
\hline
1 & 1 & 1 & 1 & 1  \\
\hline
1 & 1 & 1 & 1 & 1 \\
\hline
1 & 1 & 1 & 1 & 1 \\
\hline
1 & 1 & 1 & 1 & 1 \\
\hline
\end{array} \\
\end{aligned}
$$

