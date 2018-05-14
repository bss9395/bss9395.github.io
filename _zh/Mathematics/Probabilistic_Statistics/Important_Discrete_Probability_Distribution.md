---
layout:    zh_post
Topic:     概率统计
Title:     重要离散概率分布
Revised:   2018-05-14 23:16:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 均匀分布 $X \mapsto \mathrm{Un_{iform}} (\alpha, \beta)$ 

> $$
> \begin{alignedat}{3}
>                                                       P (X = k) &= \dfrac{1}{\beta - \alpha + 1} \quad\Leftarrow\quad k \in \lbrace \alpha, \cdots, \beta \rbrace \\
>                    \mathrm{Exp} [\mathrm{Un} (\alpha, \beta)]^h &= \sum_\alpha^\beta k^h \dfrac{1}{\beta - \alpha + 1} \\
>                                                                 &= \dfrac{1}{\beta - \alpha + 1} \sum_\alpha^\beta k^h \\
> \mathrm{Exp} [\mathrm{Un} (\alpha, \beta) - \mathrm{Exp} [X]]^h &= \sum_\alpha^\beta \left( k - \dfrac{\beta + \alpha}{2} \right)^h \dfrac{1}{\beta - \alpha + 1} \\
>                                                                 &= \dfrac{1}{2^h} \sum_\alpha^\beta [2 k - (\beta + \alpha)]^h \dfrac{1}{(\beta - \alpha + 1)} \\
>                                                                 &= \dfrac{1}{2^h} \mathrm{Exp} [2 \cdot \mathrm{Un} (\alpha, \beta) - (\beta + \alpha)]^h \\
> \end{alignedat} \\
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \dfrac{1}{2} \sqrt{\dfrac{(\beta - \alpha + 1)^2 - 1}{3}}                 & \mathrm{Exp} [X]^1 = \dfrac{\beta + \alpha}{2}                                                                                                                                                     & \mathrm{Exp} [X - \mathrm{Exp} [X]]^1 = 0 \\
> \mathrm{Var} [X] = \dfrac{(\beta - \alpha + 1)^2 - 1}{12}                                   & \mathrm{Exp} [X]^2 = \dfrac{(\beta + \alpha)^2 + \beta^2 + \alpha^2 + \beta - \alpha}{6}                                                                                                           & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = \dfrac{(\beta - \alpha + 1)^2 - 1}{12} \\
> \mathrm{Ske} [X] = 0                                                                        & \mathrm{Exp} [X]^3 = \dfrac{(\beta^2 + \alpha^2 + \beta - \alpha) (\beta + \alpha)}{4}                                                                                                             & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = 0 \\
> \mathrm{Kur} [X] = - \dfrac{6 [(\beta - \alpha + 1)^2 + 1]}{5 [(\beta - \alpha + 1)^2 - 1]} & \mathrm{Exp} [X]^4 = \dfrac{6 (\beta^4 + \beta^3 \alpha + \beta^2 \alpha^2 + \beta \alpha^3 + \alpha^4) + 9 (\beta^3 - \alpha^3) + (\beta - \alpha)^2 + (\beta - \alpha) (3 \beta \alpha - 1)}{30} & \mathrm{Exp} [X - \mathrm{Exp} [X]]^4 = \dfrac{[(\beta - \alpha + 1)^2 - 1] [3 (\beta - \alpha + 1)^2 - 7]}{240} \\
> \hline
> \end{array}
> $$
>

> ### 二项分布 $X \mapsto \mathrm{B_{i} n_{omial}} (n, p)$

> $$
> \begin{alignedat}{3}
>                           P (X = k) &= {n \choose k} p^k (1 - p)^{n - k} \quad\Leftarrow\quad k \in \lbrace 0, \cdots, n \rbrace \\
> \mathrm{Exp} [\mathrm{Bn} (n, p)]^h &= \sum_{k = 0}^n k^h {n \choose k} p^k (1 - p)^{n - k} \\
>                                     &= n p \sum_{ k = 1}^n k^{h - 1} {n - 1 \choose k - 1} p^{k - 1} (1- p)^{(n - 1) - (k - 1)} \\
>                                     &\xlongequal{l = k - 1} n p \sum_{l = 0}^{n - 1} (l + 1)^{h - 1} {n - 1 \choose l} p^l (1 - p)^{(n - 1) - l} \\
>                                     &= n p \cdot \mathrm{Exp} [\mathrm{Bn} (n - 1, p) + 1]^{h - 1} \\
>                  \mathrm{Exp} [X]^1 &= np \\
>                  \mathrm{Exp} [X]^2 &= n (n - 1) p^2 + n p \\
>                    \mathrm{Var} [X] &= n p (1 - p) \\
> \end{alignedat}
> $$
>

> ### 二点分布 $X \mapsto \mathrm{Tw_{o}} (p) = \mathrm{Bn} (1, p)$

> $$
> \begin{alignedat}{3}
>                        P (X = k) &= p^k (1 - p)^{1 - k} \quad\Leftarrow\quad k \in \lbrace 0, 1 \rbrace \\
> \mathrm{Exp} [\mathrm{Tw} (p)]^h &= \mathrm{Exp} [\mathrm{Bn}  (1, p)]^h \\
>               \mathrm{Exp} [X]^1 &= p \\
>               \mathrm{Exp} [X]^2 &= p \\
>                 \mathrm{Var} [X] &= p (1 - p) \\
> \end{alignedat}
> $$
>

> ### 随机分布 $X \mapsto \mathrm{St_{ochastic}} (\lambda)$

> $$
> \begin{alignedat}{3}
>                              P (X = k) &= \dfrac{\lambda^k}{k !} e^{- \lambda} \quad\Leftarrow\quad k \in \mathbb{N} \\
> \mathrm{Exp} [\mathrm{St} (\lambda)]^h &= \sum_{k = 0}^{+\infty} k^h \dfrac{\lambda^k}{k !} e^{- \lambda} \\
>                                        &= \lambda \sum_{k = 1}^{+\infty} k^{h - 1} \dfrac{\lambda^{k - 1}}{(k - 1) !}  e^{- \lambda} \\
>                                        &\xlongequal{l = k - 1} \lambda \sum_{l = 0}^{+\infty} (l + 1)^{h - 1} \dfrac{\lambda^l}{l !}  e^{- \lambda} \\
>                                        &= \lambda \cdot \mathrm{Exp} [\mathrm{St} (\lambda) + 1]^{h - 1} \\
>                     \mathrm{Exp} [X]^1 &= \lambda \\
>                     \mathrm{Exp} [X]^2 &= \lambda^2 + \lambda \\
>                       \mathrm{Var} [X] &= \lambda \\
> \end{alignedat}
> $$
>

> ### 二项分布的随机分布近似

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   &&                           \lim_{+\infty} n \cdot p_n &= \lambda \\
> \Downarrow\quad && \lim_{+\infty} {n \choose k} p_n^k (1 - p_n)^{n - k} &= \lim_{+\infty} \dfrac{n !}{k ! (n - k) !} \left( \dfrac{\lambda}{n} \right)^k \left( 1 - \dfrac{\lambda}{n} \right)^{n - k} \\
>                 &&                                                      &= \lim_{+\infty} \dfrac{\prod\limits_1^{k} (n - k + 1)}{n^k} \dfrac{\lambda^k}{k !} \left( 1 - \dfrac{\lambda}{n} \right)^n \left( 1 - \dfrac{\lambda}{n} \right)^{- k} \\
>                 &&                                                      &= \dfrac{\lambda^k}{k !} \cdot \lim_{+\infty} \prod_1^k \left( 1 - \dfrac{k + 1}{n} \right) \cdot \lim_{+\infty} \left( 1 - \dfrac{\lambda}{n} \right)^n \cdot \lim_{+\infty} \left( 1 - \dfrac{\lambda}{n} \right)^{- k} \\
>                 &&                                                      &= \dfrac{\lambda^k}{k !} e^{- \lambda} \\
> \Downarrow\quad &&                    {n \choose k} p^k (1 - p)^{n - k} &\approx \dfrac{(n \cdot p)^k}{k !} e^{- (n \cdot p)}
> \end{alignedat}
> $$
>

> ### 负二项分布 $X \mapsto \mathrm{N_{egative} B_{inomial} (n, p)}$

> $$
> \begin{alignedat}{3}
>                           P (X = k) &= {k - 1 \choose n - 1} p^n (1 - p)^{k - n} \quad\Leftarrow\quad k \in [n, +\infty) \\
>                       P (X - n = l) &\xlongequal{l = k - n} {n + l - 1 \choose l} p^n (1 - p)^l \quad\Leftarrow\quad l \in \mathbb{N} \\
> \mathrm{Exp} [\mathrm{NB} (n, p)]^h &= \sum_{k = n}^{+\infty} k^h {k - 1 \choose n - 1} p^n (1 - p)^{k - n} \\
>                                     &= \dfrac{n}{p} \sum_{k = n}^{+\infty} k^{h - 1} {k \choose n} p^{n + 1} (1 - p)^{k - n} \\
>                                     &\xlongequal{k = l - 1} \dfrac{n}{p} \sum_{l = n + 1}^{+\infty} (l - 1)^{h - 1} {l - 1 \choose n} p^{n + 1} (1 - p)^{l - (n + 1)} \\
>                                     &= \dfrac{n}{p} \cdot \mathrm{Exp} [\mathrm{NB} (n + 1, p) - 1]^{h - 1} \\
>                  \mathrm{Exp} [X]^1 &= \dfrac{n}{p} \\
>                  \mathrm{Exp} [X]^2 &= \dfrac{n (n + 1)}{p^2} - \dfrac{n}{p} \\
>                    \mathrm{Var} [X] &= \dfrac{n (1 - p)}{p^2} \\
> \end{alignedat}
> $$
>

> ### 几何分布 $X \mapsto \mathrm{Ge_{ometric}} (p) = \mathrm{NB} (1, p)$

> $$
> \begin{alignedat}{3}
>                        P (X = k) &= (1 - p)^{k - 1} p \quad\Leftarrow\quad k \in \mathbb{N}^+ \\
> \mathrm{Exp} [\mathrm{Ge} (p)]^h &= \mathrm{Exp} [\mathrm{NB} (1, p)]^h \\
>               \mathrm{Exp} [X]^1 &= \dfrac{1}{p} \\
>               \mathrm{Exp} [X]^2 &= \dfrac{2}{p^2} - \dfrac{1}{p} \\
>                 \mathrm{Var} [X] &= \dfrac{1 - p}{p^2} \\
> \end{alignedat}
> $$
>

> ###  几何分布的无记忆性

> $$
> \begin{alignedat}{3}
> \Uparrow\quad   &&                P (X > n) &= \sum_{n + 1}^{+\infty} (1 - p)^{k - 1} p \\
>                 &&                          &= (1 - p)^n \\
> \Downarrow\quad && P (X > n + m \mid X > n) &= (1 - p)^m \\
> \Downarrow\quad && P (X > n + m \mid X > n) &= P (X > m) \\
> \end{alignedat}
> $$
>

> ### 超几何分布 $X \mapsto \mathrm{H_{yper} G_{eometric}} (N, K, n) $

> $$
> \begin{alignedat}{3}
>                              P (X = k) &= \dfrac{{K \choose k} {N - K \choose n - k}}{{N \choose n}} \quad\Leftarrow\quad k \in \lbrace \max (0, n - N + K), \cdots, \min (K, n) \rbrace \\
> \mathrm{Exp} [\mathrm{HG} (N, K, n)]^h &= \sum_{\max (0, n - N + K)}^{\min (K, n)} k^h \dfrac{{K \choose k} {N - K \choose n - k}}{{N \choose n}} \\
>                                        &= \dfrac{n K}{N} \sum_{k = \max (1, n - N + K)}^{\min (K, n)} k^{h - 1} \dfrac{{K - 1 \choose k - 1} {N - K \choose n - k}}{N - 1 \choose n - 1} \\
>                                        &\xlongequal{l = k - 1} \dfrac{n K}{N} \sum_{l = \max (0, n - 1 - N + K)}^{\min (K - 1, n - 1)} (l +1)^{h - 1} \dfrac{{K - 1 \choose l} {N - K \choose n - 1 - l}}{{N - 1 \choose n - 1}} \\
>                                        &= \dfrac{n K}{N} \cdot \mathrm{Exp} [\mathrm{HG} (N - 1, K - 1, n - 1) + 1]^{h - 1} \\
>                     \mathrm{Exp} [X]^1 &= \dfrac{n K}{N} \\\
>                     \mathrm{Exp} [X]^2 &= \dfrac{n (n - 1) K (K - 1)}{N (N - 1)} + \dfrac{n K}{N} \\
>                       \mathrm{Var} [X] &= \dfrac{n K (N - K) (N - n)}{N^2 (N - 1)} \\
> \end{alignedat}
> $$
>

> ### 超几何分布的二项分布近似

> $$
> \begin{alignedat}{3}
> \fbox{1}\Uparrow\quad &&                                                                               p &= \lim_{k \le n \ll N} \dfrac{K}{N} = \lim_{k \le n \ll N} \dfrac{K - k + 1}{N - k + 1} \\
> \fbox{2}\Uparrow\quad &&                                                                           1 - p &= \lim_{k \le n \ll N} \dfrac{N - K}{N} = \lim_{k \le n \ll N} \dfrac{(N - K) - (n - k) + 1}{(N - k) - (n - k) + 1}  \\
> \Downarrow\quad       && \lim_{k \le n \ll N} \dfrac{{K \choose k} {N - K \choose n - k}}{{N \choose n}} &= \lim_{k \le n \ll N} \dfrac{n !}{k ! (n - k) !} \dfrac{\frac{K !}{(K - k) !}}{\frac{N !}{(N - k) !}} \dfrac{\frac{(N - K) !}{[(N - K) - (n - k)] !}}{\frac{(N - k) !}{(N - n) !}} \\
>                       &&                                                                                 &= \lim_{k \le n \ll N} {n \choose k} \dfrac{K (K - 1) \cdots (K - k + 1)}{N (N - 1) \cdots (N - k + 1)} \dfrac{(N - K) [(N - K) - 1] \cdots [(N - K) - (n - k) + 1]}{(N - k) [(N - k) - 1] \cdots [(N - k) - (n - k) + 1]} \\
>                       &&                                                                                 &= \lim_{k \le n \ll N} {n \choose k} \left( \dfrac{K}{N} \right)^k \left( \dfrac{N - K}{N} \right)^{n - k} \\
> \Downarrow\quad       &&                      \dfrac{{K \choose k} {N - K \choose n - k}}{{N \choose n}} &\approx {n \choose k} p^k (1 - p)^{n - k} \\
> \end{alignedat}
> $$
>
