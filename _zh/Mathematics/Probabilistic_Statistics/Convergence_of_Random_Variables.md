---
layout:    zh_post
Topic:     概率统计
Title:     随机变量的收敛性
Revised:   2018-05-29 01:35:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 依概率收敛

> $$
> \begin{alignedat}{3}
> \lim_{n \to +\infty} X_n \mathop{\longrightarrow}^{\mathcal{Prob.}} X \iff \lim_{n \to +\infty} P [|X_n - X| \lt \varepsilon] = 1 \\
> \end{alignedat}
> $$
>

> ### 依概率收敛的性质

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           & \lbrace |X_n - X| \lt \varepsilon_X \rbrace \;\land\; \lbrace |Y_n - Y| \lt \varepsilon_Y \rbrace \implies \lbrace |f (X_n, Y_n) - f (X, Y)| \lt \varepsilon \rbrace \\
> \Downarrow\quad         & \mathcal{True} \equiv \lbrace |X_n - X| \ge \varepsilon_X \rbrace \;\lor\; \lbrace |Y_n - Y| \ge \varepsilon_Y \rbrace \;\lor\; \lbrace |f (X_n, Y_n) - f (X, Y)| \lt \varepsilon \rbrace \\
> \Downarrow\quad         & 1 \le P [|X_n - X| \ge \varepsilon_X] + P [|Y_n - Y| \ge \varepsilon_Y] + P [|f (X_n, Y_n) - f (X, Y)| \lt \varepsilon] \\
> \Uparrow\quad           & \lim_{n \to +\infty} P [|X_n - X| \lt \varepsilon_X] = 1 \;\land\; \lim_{n \to +\infty} P [|Y_n - Y| \lt \varepsilon_Y] = 1 \\
> \Downarrow\quad         & \lim_{n \to +\infty} P [|f (X_n, Y_n) - f (X, Y)| \lt \varepsilon] = 1 \\
> \fbox{1}\Downarrow\quad & \lim_{n \to +\infty} f (X_n, Y_n) \mathop{\longrightarrow}^{\mathcal{Prob.}} f (X, Y) \\
> \fbox{2}\Downarrow\quad & \lim_{n \to +\infty} (X_n \pm Y_n) \mathop{\longrightarrow}^{\mathcal{Prob.}} X \pm Y \\
> \fbox{3}\Downarrow\quad & \lim_{n \to +\infty} (X_n \divideontimes Y_n) \mathop{\longrightarrow}^{\mathcal{Prob.}} X \divideontimes Y \\
> \end{alignedat}
> $$
>

> ### 依分布收敛

> $$
> \begin{alignedat}{3}
> \lim_{n \to +\infty} C_n (x) \mathop{\longrightarrow}^{\mathcal{Weak}} C (x) \iff \forall x \in \mathcal{Conti.}; \lim_{n \to +\infty} P [X_n \le x] = P [X \le x] \\
> \end{alignedat}
> $$
>

> ### 依概率收敛强于依分布收敛

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           & \lbrace X \le x \rbrace \iff \lbrace X \le x, Y \le y \rbrace \;\lor\; \lbrace X \le x, Y \ge y \rbrace \\
> \Downarrow\quad         & \lbrace X \le x \rbrace \implies \lbrace Y \le y \rbrace \;\lor\; \lbrace Y - X \ge y - x \rbrace \\
> \fbox{1}\Downarrow\quad & \mathcal{True} \equiv \neg \lbrace X \le x \rbrace \;\lor\; \lbrace Y \le y_+ \rbrace \;\lor\; \lbrace Y - X \ge y_+ - x \rbrace &\;&\Leftarrow\; y_+ - x \ge \varepsilon \\
> \Downarrow\quad         & P [X \le x] \le P [Y \le y_+] + P [|Y - X| \ge \varepsilon] \\
> \Downarrow\quad         & P [X \le x] \le \liminf P [Y \le y_+] \\
> \fbox{2}\Downarrow\quad & \mathcal{True} \equiv \neg \lbrace Y \le y_- \rbrace \;\lor\; \lbrace X \le x \rbrace \;\lor\; \lbrace X - Y \ge x - y_- \rbrace &\;&\Leftarrow\; x - y_- \ge \varepsilon \\
> \Downarrow\quad         & P [Y \le y_-] - P [|X - Y| \ge \varepsilon] \le P [X \le x] \\
> \Downarrow\quad         & \limsup P [Y \le y_-] \le P [X \le x] \\
> \fbox{3}\Downarrow\quad & \limsup P [Y \le y_-] \le P [X \le x] \le \liminf P [Y \le y_+]                                                                  &\;&\Leftarrow\; \lim P [|X - Y| \lt \varepsilon] = 1 \\
> \Downarrow\quad         & \lim_{n \to +\infty} C_n (x) \mathop{\longrightarrow}^{\mathcal{Weak}} C (x)
> \end{alignedat}
> $$
>
