---
layout:  zh_post
Topic :  收敛极限
Title :  重要级数
Update:  2021-02-04T20:57:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 初等幂级数

| $f (x)$                                                      | ${^h}f (x)$                                                  | $\sum\limits_{i=0}^n \dfrac{{^i}f (x_0)}{i!} · (x - x_0)^i$  | $+ \dfrac{{^{n+1}f (θ)}}{(n + 1)!} · (x - x_0)^{n + 1}$      | $(-R, +R)$ |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ---------- |
| $b^x$                                                        | $b^x · \ln^h b$                                              | $\sum\limits_{i=0}^n \dfrac{\ln^i b}{i!} · x^i$              | $+ \dfrac{b^θ · \ln^i b}{(n + 1)!} · x^{n + 1}$              |            |
| $e^x$                                                        | $e^x$                                                        | $\sum\limits_{i=0}^n \dfrac{1}{i!} · x^i$                    | $+ \dfrac{e^θ}{(n + 1)!} · x^{n + 1}$                        | $(-∞, +∞)$ |
| $\log_l (1 + x)$                                             | $\dfrac{(-1)^{h-1} · (h - 1)!}{(1 + x)^h · \ln l}$           | $\sum\limits_{i=0}^n \dfrac{(-1)^{i - 1}}{i · \ln l} · x^i$  | $+ \dfrac{(-1)^n}{(n + 1) · (1 + θ)^{n + 1} · \ln l} · x^{n + 1}$ |            |
| $\ln (1 + x)$                                                | $\dfrac{(-1)^{h-1} · (h - 1)!}{(1 + x)^h}$                   | $\sum\limits_{i=0}^n \dfrac{(-1)^{i-1}}{i} · x^i$            | $+ \dfrac{(-1)^n}{(n + 1) · (1 + θ)^{n + 1}} · x^{n + 1}$    |            |
| $(1 + x)^p$                                                  | $(1 + x)^{p - h} · \prod\limits_{j=1}^h (p - j + 1)$         | $\sum\limits_{i=0}^n \dfrac{\prod\limits_{j = 1}^i (p - j + 1)}{i!} · x^i$ | $+ \dfrac{(1 + θ)^{p - n - 1} · \prod\limits_{j=1}^{n+1} (p - j + 1)}{(n + 1)!} · x^{n + 1}$ | $(-1, +1)$ |
| $\dfrac{1}{1 + x}$                                           | $\dfrac{(-1)^h · h!}{(1 + x)^{h + 1}}$                       | $\sum\limits_{i=0}^n (-1)^i · x^i$                           | $+ \dfrac{(-1)^{n+1}}{(1 + θ)^{n + 2}} · x^{n + 1}$          |            |
| $\dfrac{1}{1 - x}$                                           | $\dfrac{h!}{(1 - x)^{h + 1}}$                                | $\sum\limits_{i=0}^n x^i$                                    | $+ \dfrac{1}{(1 - θ)^{n + 2}} · x^{n + 1}$                   |            |
| $\sin x = \dfrac{e^{\imath · x} - e^{-\imath · x}}{2 · \imath}$ | $\sin \left( x + h · \dfrac{π}{2} \right) = \imath^h · \dfrac{e^{\imath · x} - (-1)^h · e^{-\imath · x}}{2 · \imath}$ | $\sum\limits_{i=0}^n \dfrac{(-1)^{i}}{(2 · i + 1)!} · x^{2 · i + 1}$ | $+ \dfrac{(-1)^{n + 1} · \sin θ}{(2 · n + 3)!} · x^{2 · n + 3}$ | $(-∞, +∞)$ |
| $\cos x = \dfrac{e^{\imath · x} + e^{-\imath · x}}{2}$       | $\cos \left( x + h · \dfrac{π}{2} \right) = \imath^h · \dfrac{e^{\imath · x} + (-1)^h · e^{-\imath · x}}{2}$ | $\sum\limits_{i=0}^n \dfrac{(-1)^i}{(2 · i)!} · x^{2 · i}$   | $+ \dfrac{(-1)^{n + 1} · \cos θ}{(2 · n + 2)!} · x^{2 · n + 2}$ | $(-∞, +∞)$ |
| $\sinh x = \dfrac{e^x - e^{-x}}{2}$                          | $\dfrac{e^x - (-1)^h · e^{-x}}{2}$                           | $\sum\limits_{i=0}^n \dfrac{1}{(2 · i + 1)!} · x^{2 · i + 1}$ | $+ \dfrac{e^θ + e^{-θ}}{2 · (2 · n + 3)!} · x^{2 · n + 3}$   | $(-∞, +∞)$ |
| $\cosh x = \dfrac{e^x + e^{-x}}{2}$                          | $\dfrac{e^x + (-1)^h · e^{-x}}{2}$                           | $\sum\limits_{i=0}^n \dfrac{1}{(2 · i)!} · x^{2 · i}$        | $+ \dfrac{e^θ + e^{-θ}}{2 · (2 · n + 2)!} · x^{2 · n + 2}$   | $(-∞, +∞)$ |
|                                                              |                                                              |                                                              |                                                              |            |
|                                                              |                                                              |                                                              |                                                              |            |
