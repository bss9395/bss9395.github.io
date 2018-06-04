---
layout:    zh_post
Topic:     概率统计
Title:     概率的收敛性
Revised:   2018-06-01 18:56:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 依随机变量收敛

> $$
> \begin{alignedat}{3}
> P \left[ \lim_{n \to +\infty} |X_n - X| \ge \varepsilon \right] &= 0 \\
> P \left[ \lim_{n \to +\infty} |X_n - X| \lt \varepsilon \right] &= 1 \\
> \end{alignedat}
> $$
>

> ### 依概率收敛

> $$
> \begin{alignedat}{3}
> \lim_{n \to +\infty} P [|X_n - X| \ge \varepsilon] &= 0 \\
> \lim_{n \to +\infty} P [|X_n - X| \lt \varepsilon] &= 1 \\
> \end{alignedat}
> $$
>

> ### 依概率收敛的性质

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           & \lbrace |X_n - X| \lt \varepsilon_X \rbrace \;\land\; \lbrace |Y_n - Y| \lt \varepsilon_Y \rbrace \mathop{\implies}^{f \in \mathcal{Conti.}} \lbrace |f (X_n, Y_n) - f (X, Y)| \lt \varepsilon \rbrace \\
> \Downarrow\quad         & \mathcal{True} \equiv \lbrace |X_n - X| \ge \varepsilon_X \rbrace \;\lor\; \lbrace |Y_n - Y| \ge \varepsilon_Y \rbrace \;\lor\; \lbrace |f (X_n, Y_n) - f (X, Y)| \lt \varepsilon \rbrace \\
> \Downarrow\quad         & 1 \le P [|X_n - X| \ge \varepsilon_X] + P [|Y_n - Y| \ge \varepsilon_Y] + P [|f (X_n, Y_n) - f (X, Y)| \lt \varepsilon] \\
> \Uparrow\quad           & \lim_{n \to +\infty} P [|X_n - X| \ge \varepsilon_X] = 0 \;\land\; \lim_{n \to +\infty} P [|Y_n - Y| \ge \varepsilon_Y] = 0 \\
> \fbox{1}\Downarrow\quad & \lim_{n \to +\infty} P [|f (X_n, Y_n) - f (X, Y)| \lt \varepsilon] = 1 \\
> \fbox{2}\Downarrow\quad & \lim_{n \to +\infty} P [|(X_n \pm Y_n) - (X \pm Y)| \lt \varepsilon] = 1 \\
> \fbox{3}\Downarrow\quad & \lim_{n \to +\infty} P [|(X_n \divideontimes Y_n) - (X \divideontimes Y)| \lt \varepsilon] = 1 \\
> \end{alignedat}
> $$
>

> ### 依分布收敛

> $$
> \begin{alignedat}{3}
> \lim_{n \to +\infty} P [X_n \le x] \xlongequal{\forall x \in \mathcal{Conti.}} P [X \le x] \\
> \end{alignedat}
> $$
>

> ### 依多方收敛

> $$
> \begin{alignedat}{3}
> \lim_{n \to +\infty} \mathrm{Exp} [|X_n - X|]^h = 0 \\
> \end{alignedat}
> $$
>

> ### 依随机变量收敛强于依概率收敛

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   && P \left[ \lim_{n \to +\infty} |X_n - X| \ge \varepsilon \right] &= P \left[ \lim_{N \to +\infty} \bigcup_{n = N}^{+\infty} (|X_n - X| \ge \varepsilon) \right] \\
>                 &&                                                                 &\ge \lim_{n \to +\infty} P \left[ |X_n - X| \ge \varepsilon \right] \\
> \Downarrow\quad && P \left[ \lim_{n \to +\infty} |X_n - X| \ge \varepsilon \right] &= 0 \implies \lim_{n \to +\infty} P [|X_n - X| \ge \varepsilon] = 0 \\
> \end{alignedat}
> $$
>

> ### 依概率收敛强于依分布收敛

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           & \lbrace X \le x \rbrace \iff \lbrace X \le x, X_n \le x' \rbrace \;\lor\; \lbrace X \le x, X_n \ge x' \rbrace \\
> \Downarrow\quad         & \lbrace X \le x \rbrace \implies \lbrace X_n \le x' \rbrace \;\lor\; \lbrace X_n - X \ge x' - x \rbrace \\
> \fbox{1}\Downarrow\quad & \mathcal{True} \equiv \neg \lbrace X \le x \rbrace \;\lor\; \lbrace X_n \le x^+ \rbrace \;\lor\; \lbrace X_n - X \ge x^+ - x \rbrace &&\;\Leftarrow\; x^+ - x \ge \varepsilon \\
> \Downarrow\quad         & P [X \le x] \le P [X_n \le x^+] + P [|X_n - X| \ge \varepsilon] \\
> \Downarrow\quad         & P [X \le x] \le \lim_{n \to +\infty} \inf_{x^+} P [X_n \le x^+] \\
> \fbox{2}\Downarrow\quad & \mathcal{True} \equiv \neg \lbrace X_n \le x^- \rbrace \;\lor\; \lbrace X \le x \rbrace \;\lor\; \lbrace X - X_n \ge x - x^- \rbrace &&\;\Leftarrow\; x - x^- \ge \varepsilon \\
> \Downarrow\quad         & P [X_n \le x^-] - P [|X - X_n| \ge \varepsilon] \le P [X \le x] \\
> \Downarrow\quad         & \lim_{n \to +\infty} \sup_{x^-} P [X_n \le x^-] \le P [X \le x] \\
> \fbox{3}\Downarrow\quad & \lim_{n \to +\infty} \sup_{x^-} P [X_n \le x^-] \le P [X \le x] \le \lim_{n \to +\infty} \inf_{x^+} P [X_n \le x^+] \\
> \Downarrow\quad         &\lim_{n \to +\infty} P [|X_n - X| \ge \varepsilon] = 0 \implies \lim_{n \to +\infty} P [X_n \le x] \xlongequal{\forall x \in \mathcal{Conti.}} P [X \le x] \\
> \end{alignedat}
> $$
>

> ### 依概率收敛与依分布收敛的退化等价性

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   &&                      P [|X_n - \alpha| \ge \varepsilon] &= P [X_n \ge \alpha + \varepsilon] + P [ X_n \le \alpha - \varepsilon] \\
>                 &&                                                         &\le P \left[ X_n \gt \alpha + \dfrac{\varepsilon}{2} \right] + P [X_n \le \alpha - \varepsilon] \\
>                 &&                                                         &= 1 - P \left[ X_n \le \alpha + \dfrac{\varepsilon}{2} \right] + P [X_n \le \alpha - \varepsilon] \\
> \Downarrow\quad && \lim_{n \to +\infty} P [|X_n - \alpha| \ge \varepsilon] &= 0 \impliedby \lim_{n \to +\infty} P [X_n \le x] \xlongequal{\forall x \in \mathcal{Conti.}} P [X \le x] \\
> \Downarrow\quad && \lim_{n \to +\infty} P [|X_n - \alpha| \ge \varepsilon] &= 0 \iff \lim_{n \to +\infty} P [X_n \le x] \xlongequal{\forall x \in \mathcal{Conti.}} P [X \le x] \\
> \end{alignedat}
> $$
>

> ### 依概率收敛弱于依多方收敛

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   & P [|X_n - X| \ge \varepsilon] \le \dfrac{\mathrm{Exp} [|X_n - X|]^h}{\varepsilon^h} \\
> \Downarrow\quad & \lim_{n \to +\infty} P [|X_n - X| \ge \varepsilon] = 0 \impliedby \lim_{n \to +\infty} \mathrm{Exp} [|X_n - X|]^h = 0 \\
> \end{alignedat}
> $$
>

