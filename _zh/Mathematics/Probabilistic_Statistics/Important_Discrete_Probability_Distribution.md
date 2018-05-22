---
layout:    zh_post
Topic:     概率统计
Title:     重要离散概率分布
Revised:   2018-05-22 09:03:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 离散均匀分布 $X \mapsto \mathrm{D_{iscrete} U_{niform}} (\alpha, \beta)$ 

> $$
> \begin{alignedat}{3}
>                                         P (X = k) &= \dfrac{1}{\beta - \alpha + 1} \quad\Leftarrow\quad k \in \lbrace \alpha, \cdots, \beta \rbrace \\
>                      \mathrm{Exp} [e^{t \cdot X}] &= \sum_{k = \alpha}^\beta e^{t \cdot k} \dfrac{1}{\beta - \alpha + 1} \\
>                                                   &= \dfrac{e^{(\beta + 1) t} - e^{\alpha t}}{(\beta - \alpha + 1) \cdot (e^t - 1)} \\
> \mathrm{Exp} [e^{t \cdot (X - \mathrm{Exp} [X])}] &= \dfrac{e^{(\beta + 1) t} - e^{\alpha t}}{(\beta - \alpha + 1) \cdot (e^t - 1)} \cdot e^{- \frac{\beta + \alpha}{2} t} \\
>      \mathrm{Exp} [\mathrm{DU} (\alpha, \beta)]^h &= \sum_\alpha^\beta k^h \dfrac{1}{\beta - \alpha + 1} \\
>                                                   &= \dfrac{1}{\beta - \alpha + 1} \sum_\alpha^\beta k^h \\
> \end{alignedat}
> $$
>

> $$
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \dfrac{1}{2} \sqrt{\dfrac{(\beta - \alpha + 1)^2 - 1}{3}}                  & \mathrm{Exp} [X]^1 = \dfrac{\beta + \alpha}{2} \\
> \mathrm{Coe} [X] = \dfrac{1}{\beta - \alpha} \sqrt{\dfrac{(\beta - \alpha + 1)^2 - 1}{3}}    & \mathrm{Exp} [X]^2 = \dfrac{(\beta + \alpha)^2 + \beta^2 + \alpha^2 + \beta - \alpha}{6} \\
> \mathrm{Var} [X] = \dfrac{(\beta - \alpha + 1)^2 - 1}{12}                                    & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = \dfrac{(\beta - \alpha + 1)^2 - 1}{12} \\
> \mathrm{Skew} [X] = 0                                                                        & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = 0 \\
> \mathrm{Kurt} [X] = - \dfrac{6 [(\beta - \alpha + 1)^2 + 1]}{5 [(\beta - \alpha + 1)^2 - 1]} & \mathrm{Exp} [X - \mathrm{Exp} [X]]^4 = \dfrac{[(\beta - \alpha + 1)^2 - 1] [3 (\beta - \alpha + 1)^2 - 7]}{240} \\
> \hline
> \end{array}
> $$
>

> ### 二项分布 $X \mapsto \mathrm{B_{i} n_{omial}} (n, p)$

> $$
> \begin{alignedat}{3}
>                                         P (X = k) &= {n \choose k} p^k (1 - p)^{n - k} \quad\Leftarrow\quad k \in \lbrace 0, \cdots, n \rbrace \\
>                      \mathrm{Exp} [e^{t \cdot X}] &= \sum_{k = 0}^n e^{t \cdot k} {n \choose k} p^k (1 - p)^{n - k} \\
>                                                   &= \sum_{k = 0}^n {n \choose k} (p e^t)^k (1 - p)^{n - k} \\
>                                                   &= (p e^t + 1 - p)^n \\
> \mathrm{Exp} [e^{t \cdot (X - \mathrm{Exp} [X])}] &= (p e^t + 1 - p)^n \cdot e^{- n p \cdot t} \\
>               \mathrm{Exp} [\mathrm{Bn} (n, p)]^h &= \sum_{k = 0}^n k^h {n \choose k} p^k (1 - p)^{n - k} \\
>                                                   &= n p \sum_{ k = 1}^n k^{h - 1} {n - 1 \choose k - 1} p^{k - 1} (1- p)^{(n - 1) - (k - 1)} \\
>                                                   &\xlongequal{l = k - 1} n p \sum_{l = 0}^{n - 1} (l + 1)^{h - 1} {n - 1 \choose l} p^l (1 - p)^{(n - 1) - l} \\
>                                                   &= n p \cdot \mathrm{Exp} [\mathrm{Bn} (n - 1, p) + 1]^{h - 1} \\
> \end{alignedat}
> $$
>

> $$
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \sqrt{n p (1 - p)}                     & \mathrm{Exp} [X]^1 = n p \\
> \mathrm{Coe} [X] = \sqrt{\dfrac{1 - p}{n p}}             & \mathrm{Exp} [X]^2 = n (n - 1) p^2 + n p \\
> \mathrm{Var} [X] = n p (1 - p)                           & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = n p ( 1 - p) \\    
> \mathrm{Skew} [x] = \dfrac{1 - 2 p}{\sqrt{n p (1 - p)}}  & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = n p (1 - p) (1 - 2 p) \\
> \mathrm{Kurt} [X] = \dfrac{1 - 6 p (1 - p)}{n p (1 - p)} & \mathrm{Exp} [X - \mathrm{Exp} [X]]^4 = n p ( 1- p) [1 - 3 (2 + n) p (1 - p)] \\
> \hline
> \end{array}
> $$
>

> ### 独立二项分布的可加性

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           &&                                     X_1 &\mapsto \mathrm{Bn} (n, p) \quad\land\quad X_2 \mapsto \mathrm{Bn} (m, p) \\
> \Uparrow\quad           &&                               P (X = k) &= \sum_{\max (0, k - m)}^{\min (n, k)} P (X_1 = i) \cdot P (X_2 = k - i) \\
>                         &&                                         &= \sum_{\max (0, k - m)}^{\min (n, k)} {n \choose i} p^i (1 - p)^{n - i} \cdot {m \choose k - i} p^{k - i} (1 - p)^{m - (k - i)} \\
>                         &&                                         &= p^k (1 - p)^{n + m - k} \sum_{\max (0, k - m)}^{\min (n, k)} {n \choose i} {m \choose k - i} \\
>                         &&                                         &= {n + m \choose k} p^k (1 - p)^{n + m - k} \\
> \fbox{1}\Downarrow\quad && \mathrm{Bn} (n, p) * \mathrm{Bn} (m, p) &= \mathrm{Bn} (n + m, p) \\
> \fbox{2}\Downarrow\quad &&                  [\mathrm{Bn} (n, p)]^h &= \mathrm{Bn} (h n, p) \\
> \end{alignedat}
> $$
>

> ### 二点分布 $X \mapsto \mathrm{Tw_{o}} (p) = \mathrm{Bn} (1, p)$

> $$
> \begin{alignedat}{3}
>                                         P (X = k) &= p^k (1 - p)^{1 - k} \quad\Leftarrow\quad k \in \lbrace 0, 1 \rbrace \\
>                      \mathrm{Exp} [e^{t \cdot X}] &= p e^t + 1 - p \\
> \mathrm{Exp} [e^{t \cdot (X - \mathrm{Exp} [X])}] &= (p e^t + 1 - p) \cdot e^{- p \cdot t} \\
>                  \mathrm{Exp} [\mathrm{Tw} (p)]^h &= \mathrm{Exp} [\mathrm{Bn}  (1, p)]^h \\
> \end{alignedat}
> $$
>

> $$
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \sqrt{p (1 - p)}                     & \mathrm{Exp} [X]^1 = p \\
> \mathrm{Coe} [X] = \sqrt{\dfrac{1 - p}{p}}             & \mathrm{Exp} [X]^2 = p \\
> \mathrm{Var} [X] = p (1 - p)                           & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = p (1 - p)  \\      
> \mathrm{Skew} [X] = \sqrt{\dfrac{1 - 2 p}{p (1 - p)}}  & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = p (1 - p) (1 - 2 p) \\
> \mathrm{Kurt} [X] = \dfrac{1 - 6 p (1 - p)}{p (1 - p)} & \mathrm{Exp} [X - \mathrm{Exp} [X]]^4 = p (1 - p) [1 - 9 p (1 - p)] \\
> \hline
> \end{array}
> $$
>

> ### 负二项分布 $X \mapsto \mathrm{N_{egative} B_{inomial} (n, p)}$

> $$
> \begin{alignedat}{3}
>                                          P (X = k) &= {k - 1 \choose n - 1} p^n (1 - p)^{k - n} \quad\Leftarrow\quad k \in [n, +\infty) \\
>                                      P (X - n = l) &\xlongequal{l = k - n} {n + l - 1 \choose l} p^n (1 - p)^l \quad\Leftarrow\quad l \in \mathbb{N} \\
>                                                    &= {- n \choose l} p^n (p - 1)^l \\
>                       \mathrm{Exp} [e^{t \cdot X}] &= \sum_{k = n}^{+\infty} e^{t \cdot k} {k - 1 \choose n - 1} p^n (1 - p)^{k - n} \\
>                                                    &\xlongequal{l = k - n} (e^t p)^n \sum_{l = 0}^{+\infty} {- n \choose l} [e^t (p - 1)]^l \\
>                                                    &= (e^t p)^n \cdot [1 + e^t (p - 1)]^{- n} \\
>                                                    &= \left[ \dfrac{p}{e^{- t} + p - 1} \right]^n \\
> \mathrm{Exp} [e^{t \cdot (X  - \mathrm{Exp} [X])}] &= \left[ \dfrac{p}{e^{- t} + p - 1} \right]^n \cdot e^{- \frac{n}{p} t} \\
>                \mathrm{Exp} [\mathrm{NB} (n, p)]^h &= \sum_{k = n}^{+\infty} k^h {k - 1 \choose n - 1} p^n (1 - p)^{k - n} \\
>                                                    &= \dfrac{n}{p} \sum_{k = n}^{+\infty} k^{h - 1} {k \choose n} p^{n + 1} (1 - p)^{k - n} \\
>                                                    &\xlongequal{k = l - 1} \dfrac{n}{p} \sum_{l = n + 1}^{+\infty} (l - 1)^{h - 1} {l - 1 \choose n} p^{n + 1} (1 - p)^{l - (n + 1)} \\
>                                                    &= \dfrac{n}{p} \cdot \mathrm{Exp} [\mathrm{NB} (n + 1, p) - 1]^{h - 1} \\
> \end{alignedat}
> $$
>

> $$
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \dfrac{\sqrt{n (1 - p)}}{p}          & \mathrm{Exp} [X]^1 = \dfrac{n}{p} \\
> \mathrm{Coe} [X] = \sqrt{\dfrac{1 - p}{n}}             & \mathrm{Exp} [X]^2 = \dfrac{n (n - p + 1)}{p^2} \\
> \mathrm{Var} [X] = \dfrac{n (1 - p)}{p^2}              & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = \dfrac{n (1 - p)}{p^2} \\
> \mathrm{Skew} [X] = \dfrac{2 - p}{\sqrt{n (1 - p)}}    & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = \dfrac{n (1 - p) (2 - p) }{p^3} \\
> \mathrm{Kurt} [X] = \dfrac{p^2 + 6 (1 - p)}{n (1 - p)} & \mathrm{Exp} [X - \mathrm{Exp} [X]]^4 = \dfrac{n (1- p) [p^2 + 3 (n + 2) (1 - p)]}{p^4} \\
> \hline
> \end{array}
> $$
>

> ### 随机分布 $X \mapsto \mathrm{St_{ochastic}} (\lambda)$

> $$
> \begin{alignedat}{3}
>                                         P (X = k) &= \dfrac{\lambda^k}{k !} e^{- \lambda} \quad\Leftarrow\quad k \in \mathbb{N} \\
>                      \mathrm{Exp} [e^{t \cdot X}] &= \sum_{k = 0}^{+\infty} e^{t \cdot k} \dfrac{\lambda^k}{k !} e^{- \lambda} \\
>                                                   &= e^{- \lambda} \sum_{k = 0}^{+\infty} \dfrac{(\lambda e^t)^k}{k !} \\
>                                                   &= e^{- \lambda} e^{\lambda e^t} \\
>                                                   &= e^{\lambda (e^t - 1)} \\
> \mathrm{Exp} [e^{t \cdot (X - \mathrm{Exp} [X])}] &= e^{\lambda (e^t - 1)} \cdot e^{- \lambda t} \\
>            \mathrm{Exp} [\mathrm{St} (\lambda)]^h &= \sum_{k = 0}^{+\infty} k^h \dfrac{\lambda^k}{k !} e^{- \lambda} \\
>                                                   &= \lambda \sum_{k = 1}^{+\infty} k^{h - 1} \dfrac{\lambda^{k - 1}}{(k - 1) !}  e^{- \lambda} \\
>                                                   &\xlongequal{l = k - 1} \lambda \sum_{l = 0}^{+\infty} (l + 1)^{h - 1} \dfrac{\lambda^l}{l !}  e^{- \lambda} \\
>                                                   &= \lambda \cdot \mathrm{Exp} [\mathrm{St} (\lambda) + 1]^{h - 1} \\
> \end{alignedat}
> $$
>

> $$
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \sqrt{\lambda}              & \mathrm{Exp} [X]^1 = \lambda \\
> \mathrm{Coe} [X] = \dfrac{1}{\sqrt{\lambda}}  & \mathrm{Exp} [X]^2 = \lambda (\lambda + 1) \\
> \mathrm{Var} [X] = \lambda                    & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = \lambda \\
> \mathrm{Skew} [X] = \dfrac{1}{\sqrt{\lambda}} & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = \lambda \\
> \mathrm{Kurt} [X] = \dfrac{1}{\lambda}        & \mathrm{Exp} [X - \mathrm{Exp} [X]]^4 = \lambda (3 \lambda + 1) \\
> \hline
> \end{array}
> $$
>

> ### 独立随机分布的可加性

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           &&                                               X_1 &\mapsto \mathrm{St} (\lambda_1) \quad\land\quad X_2 \mapsto \mathrm{St} (\lambda_2)  \\
> \Uparrow\quad           &&                                         P (X = k) &= \sum_{i = 0}^{k} P (X_1 = i) \cdot P (X_2 = k - i) \\
>                         &&                                                   &= \sum_{i = 0}^k \left[ \dfrac{\lambda_1^i}{i !} e^{- \lambda_1} \right] \cdot \left[ \dfrac{\lambda_2^{k - i}}{(k - i) !} e^{- \lambda_2} \right] \\
>                         &&                                                   &= \dfrac{(\lambda_1 + \lambda_2)^k}{k !} e^{- (\lambda_1 + \lambda_2)} \sum_{i = 0}^k \dfrac{k !}{i ! (k - i) !} \left( \dfrac{\lambda_1}{\lambda_1 + \lambda_2} \right)^i \left( \dfrac{\lambda_2}{\lambda_1 + \lambda_2} \right)^{k - i} \\
>                         &&                                                   &= \dfrac{(\lambda_1 + \lambda_2)^k}{k !} e^{- (\lambda_1 + \lambda_2)} \\
> \fbox{1}\Downarrow\quad && \mathrm{St} (\lambda_1) * \mathrm{St} (\lambda_2) &= \mathrm{St} (\lambda_1 + \lambda_2) \\
> \fbox{2}\Downarrow\quad &&                         [\mathrm{St} (\lambda)]^h &= \mathrm{St} (h \lambda) \\
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

> ### 几何分布 $X \mapsto \mathrm{Ge_{ometric}} (p) = \mathrm{NB} (1, p)$

> $$
> \begin{alignedat}{3}
>                                         P (X = k) &= (1 - p)^{k - 1} p \quad\Leftarrow\quad k \in \mathbb{N}^+ \\
>                      \mathrm{Exp} [e^{t \cdot X}] &= \dfrac{p}{e^{- t} + p - 1} \\
> \mathrm{Exp} [e^{t \cdot (X - \mathrm{Exp} [X])}] &= \dfrac{p}{e^{- t} + p - 1} \cdot e^{- \frac{1}{p} t} \\
>                  \mathrm{Exp} [\mathrm{Ge} (p)]^h &= \mathrm{Exp} [\mathrm{NB} (1, p)]^h \\
> \end{alignedat}
> $$
>

> $$
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \dfrac{\sqrt{1 - p}}{p}          & \mathrm{Exp} [X]^1 = \dfrac{1}{p} \\
> \mathrm{Coe} [X] = 1 - p                           & \mathrm{Exp} [X]^2 = \dfrac{1 - p + 1}{p^2} \\
> \mathrm{Var} [X] = \dfrac{1 - p}{p^2}              & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = \dfrac{1 - p}{p^2} \\
> \mathrm{Skew} [X] = \dfrac{2 - p}{\sqrt{1 - p}}    & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = \dfrac{(1 - p) (2 - p)}{p^3} \\
> \mathrm{Kurt} [X] = \dfrac{p^2 + 6 (1 - p)}{1 - p} & \mathrm{Exp} [X - \mathrm{Exp} [X]]^4 = \dfrac{(1- p) [p^2 + 9 (1 - p)]}{p^4} \\
> \hline
> \end{array}
> $$
>

> ### 几何分布的无记忆性

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
>                                                 P (X = k) &= \dfrac{{K \choose k} {N - K \choose n - k}}{{N \choose n}} \quad\Leftarrow\quad k \in \lbrace \max (0, n - N + K), \cdots, \min (K, n) \rbrace \\
>                                                           &= \dfrac{{n \choose k} {N - n \choose K - k}}{{N \choose K}} \\
>                    \mathrm{Exp} [\mathrm{HG} (N, K, n)]^h &= \sum_{k = \max (0, n - N + K)}^{\min (K, n)} k^h \dfrac{{K \choose k} {N - K \choose n - k}}{{N \choose n}} \\
>                                                           &= \dfrac{n K}{N} \sum_{k = \max (1, n - N + K)}^{\min (K, n)} k^{h - 1} \dfrac{{K - 1 \choose k - 1} {N - K \choose n - k}}{N - 1 \choose n - 1} \\
>                                                           &\xlongequal{l = k - 1} \dfrac{n K}{N} \sum_{l = \max (0, n - 1 - N + K)}^{\min (K - 1, n - 1)} (l +1)^{h - 1} \dfrac{{K - 1 \choose l} {N - K \choose n - 1 - l}}{{N - 1 \choose n - 1}} \\
>                                                           &= \dfrac{n K}{N} \cdot \mathrm{Exp} [\mathrm{HG} (N - 1, K - 1, n - 1) + 1]^{h - 1} \\
> \mathrm{Exp} [\mathrm{HG} (N, K, n) - \mathrm{Exp} [X]]^h &= \sum_{k = \max (0, n - N + K)}^{\min (K, n)} \left( k - \dfrac{n K}{N} \right)^h \dfrac{{K \choose k} {N - K \choose n - k}}{{N \choose n}} \\
>                                                           &= \mathrm{Exp} [X] \cdot \left\lbrace \mathrm{Exp} \left[ \mathrm{HG} (N - 1, K - 1, n - 1) + 1 - \mathrm{Exp} [X] \right]^{h - 1} - \mathrm{Exp} \left[ \mathrm{HG} (N, K, n) - \mathrm{Exp} [X] \right]^{h - 1} \right\rbrace \\
> \end{alignedat}
> $$
>

> $$
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \dfrac{1}{N} \sqrt{\dfrac{n K (N - n) (N - K)}{N - 1}}                         & \mathrm{Exp} [X]^1 = \dfrac{n K}{N} \\
> \mathrm{Coe} [X] = \sqrt{\dfrac{(N - n) (N - K)}{n K (N - 1)}}                                   & \mathrm{Exp} [X]^2 = \dfrac{n (n - 1) K (K - 1)}{N (N - 1)} + \dfrac{n K}{N} \\
> \mathrm{Var} [X] = \dfrac{n K (N - n) (N - K)}{N^2 (N - 1)}                                      & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = \dfrac{n K (N - n) (N - K)}{N^2 (N - 1)} \\
> \mathrm{Skew} [X] = \dfrac{(N - 2 n) (N - 2 K)}{N - 2} \sqrt{\dfrac{N - 1}{n K (N - n) (N - K)}} & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = \dfrac{n K (N - n) (N - 2 n) (N - K) (N - 2 K)}{N^3 (N - 1) (N - 2)} \\
> \end{array}
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

> ### 负超几何分布 $X \mapsto \mathrm{N_{egative} H_{ypergeometric}} (K, N, n)$

> $$
> \begin{alignedat}{3}
>                                                 P (X = k) &= \dfrac{{N \choose n - 1} {K - N \choose k - n}}{{K \choose k - 1}} \dfrac{N - n + 1}{K - k + 1} \quad\Leftarrow\quad k \in [\max (1, n), \cdots, \min (K, K - N + n)] \\
>                                                           &= \dfrac{{k - 1 \choose n - 1} {K - k \choose N - n}}{{K \choose N}} \\
>                                             p (X - n = l) &= \dfrac{{n + l -1 \choose l} {K - l - n \choose K - l - N}}{K \choose N} \\
>                    \mathrm{Exp} [\mathrm{NH} (N, K, n)]^h &= \sum_{k = \max (1, n)}^{\min (K, K - N + n)} k^h \dfrac{{k - 1 \choose n - 1} {K - k \choose N - n}}{{K \choose N}} \\
>                                                           &= n \sum_{k = \max (1, n)}^{\min (K, K - N + n)} k^{h - 1} \dfrac{{k \choose n} {K - k \choose N - n}}{{K \choose N}} \\
>                                                           &\xlongequal{k = l - 1} \dfrac{n (K + 1)}{N + 1} \sum_{l = \max (1, n + 1)}^{\min (K + 1, K + 1 - N + n)} (l - 1)^{h - 1} \dfrac{{l - 1 \choose n} {K + 1 - l \choose N - n}}{{K + 1 \choose N + 1}} \\
>                                                           &= \dfrac{n (K + 1)}{N + 1} \cdot \mathrm{Exp} [\mathrm{NH} (N + 1, K + 1, n + 1) - 1]^{h - 1} \\
> \mathrm{Exp} [\mathrm{NH} (N, K, n) - \mathrm{Exp} [X]]^h &= \sum_{k = \max (1, n)}^{\min (K, K - N + n)} \left[ k - \dfrac{n (K + 1)}{N + 1} \right]^h \dfrac{{k - 1 \choose n - 1} {K - k \choose N - n}}{{K \choose N}} \\
>                                                           &= \mathrm{Exp} [X] \cdot \left\lbrace \mathrm{Exp} \left[ \mathrm{NH} (N + 1, K + 1, n + 1) - 1 - \mathrm{Exp} [X] \right]^{h - 1} - \mathrm{Exp} [\mathrm{NH} (N, K, n) - \mathrm{Exp} [X]]^{h - 1} \right\rbrace \\
> \end{alignedat}
> $$
>

> $$
> \begin{array}{l|l|l}
> \hline
> \mathrm{SD} [X] = \dfrac{1}{N + 1} \sqrt{\dfrac{n (K + 1) (K - N) (N - n + 1)}{N + 2}}                             & \mathrm{Exp} [X]^1 = \dfrac{n (K + 1)}{N + 1} \\
> \mathrm{Coe} [X] = \sqrt{\dfrac{(K - N) (N - n + 1)}{n (K + 1) (N + 2)}}                                           & \mathrm{Exp} [X]^2 = \dfrac{n (K + 1)}{(N + 1)} \left[ \dfrac{(n + 1) (K + 2)}{N + 2} - 1 \right] \\
> \mathrm{Var} [X] = \dfrac{n (K + 1) (K - N) (N - n + 1)}{(N + 1)^2 (N + 2)}                                        & \mathrm{Exp} [X - \mathrm{Exp} [X]]^2 = \dfrac{n (K + 1) (K - N) (N - n + 1)}{(N + 1)^2 (N + 2)} \\
> \mathrm{Skew} [X] = \dfrac{(2 K - N + 1) (N - 2 n + 1)}{N + 3} \sqrt{\dfrac{N + 2}{n (K + 1) (K - N) (N - n + 1)}} & \mathrm{Exp} [X - \mathrm{Exp} [X]]^3 = \dfrac{n (K + 1) (K - N) (2 K - N + 1) (N - n + 1) (N - 2 n + 1)}{(N + 1)^3 (N + 2) (N + 3)} \\
> \hline
> \end{array}
> $$
>