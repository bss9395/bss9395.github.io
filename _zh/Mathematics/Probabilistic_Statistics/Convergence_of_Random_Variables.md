---
layout:    zh_post
Topic:     概率统计
Title:     随机变量的收敛性
Revised:   2018-05-29 16:45:00 +08 @ 中国-新疆-乌鲁木齐 +06
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
> \Uparrow\quad           & \lbrace |X_n - X| \lt \varepsilon_X \rbrace \;\land\; \lbrace |Y_n - Y| \lt \varepsilon_Y \rbrace \mathop{\implies}^{f \in \mathcal{Conti.}} \lbrace |f (X_n, Y_n) - f (X, Y)| \lt \varepsilon \rbrace \\
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
> \Uparrow\quad           & \lbrace X \le x \rbrace \iff \lbrace X \le x, X_n \le x_n \rbrace \;\lor\; \lbrace X \le x, X_n \ge x_n \rbrace \\
> \Downarrow\quad         & \lbrace X \le x \rbrace \implies \lbrace X_n \le x_n \rbrace \;\lor\; \lbrace X_n - X \ge x_n - x \rbrace \\
> \fbox{1}\Downarrow\quad & \mathcal{True} \equiv \neg \lbrace X \le x \rbrace \;\lor\; \lbrace X_n \le x_{n+} \rbrace \;\lor\; \lbrace X_n - X \ge x_{n+} - x \rbrace &\;&\Leftarrow\; x_{n+} - x \ge \varepsilon \\
> \Downarrow\quad         & P [X \le x] \le P [X_n \le x_{n+}] + P [|X_n - X| \ge \varepsilon] \\
> \Downarrow\quad         & P [X \le x] \le \liminf P [X \le x_{n+}] \\
> \fbox{2}\Downarrow\quad & \mathcal{True} \equiv \neg \lbrace X_n \le x_{n-} \rbrace \;\lor\; \lbrace X \le x \rbrace \;\lor\; \lbrace X - X_n \ge x - x_{n-} \rbrace &\;&\Leftarrow\; x - x_{n-} \ge \varepsilon \\
> \Downarrow\quad         & P [X_n \le x_{n-}] - P [|X - X_n| \ge \varepsilon] \le P [X \le x] \\
> \Downarrow\quad         & \limsup P [X_n \le x_{n-}] \le P [X \le x] \\
> \fbox{3}\Downarrow\quad & \limsup P [X_n \le x_{n-}] \le P [X \le x] \le \liminf P [X_n \le x_{n+}]                                                                  &\;&\Leftarrow\; \lim P [|X - X_n| \lt \varepsilon] = 1 \\
> \Downarrow\quad         & \forall x \in \mathcal{Conti.}; \lim_{n \to +\infty} P [X_n \le x] = P [X \le x] \\
> \Downarrow\quad         & \lim_{n \to +\infty} C_n (x) \mathop{\longrightarrow}^{\mathcal{Weak}} C (x) \\
> \end{alignedat}
> $$
>

> ### 依概率收敛与依分布收敛的等效性

> $$
> \begin{alignedat}{3}
> \lim_{n \to +\infty} X_n \mathop{\longrightarrow}^{\mathcal{Prob.}} \alpha \iff \lim_{n \to +\infty} C_n (x) \mathop{\longrightarrow}_{P [X = \alpha] = 1}^{\mathcal{Weak}} C (x) \\
> \end{alignedat}
> $$
>