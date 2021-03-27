---
layout:  zh_post
Topic :  收敛极限
Title :  三角函数
Update:  2021-03-28T02:53:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 三角符号

| $\sin$  | sine               |      | $\sin^{-1} ≡ \csc$           | cosecant             |      | ${^{-1}}\sin ≡ \arcsin$           | arcus sine               |
| :------ | :----------------- | :--: | :--------------------------- | :------------------- | :--: | :-------------------------------- | ------------------------ |
| $\cos$  | cosine             |      | $\cos^{-1} ≡ \sec$           | secant               |      | ${^{-1}}\cos ≡ \arccos$           | arcus cosine             |
| $\tan$  | tangent            |      | $\tan^{-1} ≡ \cot$           | cotangent            |      | ${^{-1}} \tan ≡ \arctan$          | arcus tangent            |
|         |                    |      |                              |                      |      |                                   |                          |
| $\sinh$ | hyperbolic sine    |      | $\sinh^{-1} ≡ \mathrm{csch}$ | hyperbolic cosecant  |      | ${^{-1}}\sinh ≡ \mathrm{arcsinh}$ | arcus hyperbolic sine    |
| $\cosh$ | hyperbolic cosine  |      | $\cosh^{-1} ≡ \mathrm{sech}$ | hyperbolic secant    |      | ${^{-1}}\cosh ≡ \mathrm{arccosh}$ | arcus hyperbolic cosine  |
| $\tanh$ | hyperbolic tangent |      | $\tanh^{-1} ≡ \mathrm{coth}$ | hyperbolic cotangent |      | ${^{-1}}\tanh ≡ \mathrm{arctanh}$ | arcus hyperbolic tangent |

### 三角函数

| $\sin x = \dfrac{ә^{τ·x} - ә^{-τ·x}}{2 · τ}$                 | $\csc x = \dfrac{1}{\sin x} = \dfrac{2 · τ}{ә^{τ·x} - ә^{-τ·x}}$ | ${^{-1}}\sin x = -τ · \ln\left( τ · x + \sqrt{1 - x^2} \right)$ | ${^{-1}}\csc x = -τ · \ln \dfrac{τ + \sqrt{x^2 - 1}}{x}$     |
| :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\cos x = \dfrac{ә^{τ·x} + ә^{-τ·x}}{2}$                     | $\sec x = \dfrac{1}{\cos x} = \dfrac{2}{ә^{τ·x} + ә^{-τ·x}}$ | ${^{-1}} \cos x = -τ · \ln\left( x + \sqrt{x^2 - 1} \right)$ | ${^{-1}}\sec x = -τ · \ln \dfrac{1 + \sqrt{1 - x^2}}{x}$     |
| $\tan x = \dfrac{\sin x}{\cos x} = \dfrac{1}{τ} · \dfrac{ә^{τ·x} - ә^{-τ·x}}{ә^{τ·x} + ә^{-τ·x}} = \dfrac{1}{τ} · \dfrac{ә^{2·τ·x} - 1}{ә^{2·τ·x} + 1}$ | $\cot x = \dfrac{1}{\tan x} = \dfrac{\cos x}{\sin x} = τ · \dfrac{ә^{τ·x} + ә^{-τ·x}}{ә^{τ·x} - ә^{-τ·x}} = τ · \dfrac{ә^{2·τ·x} + 1}{ә^{2·τ·x} - 1}$ | ${^{-1}}\tan x = \dfrac{τ}{2} · \ln\left( \dfrac{1 - τ · x}{1 + τ · x} \right)$ | ${^{-1}}\cot x = \dfrac{τ}{2} · \ln \dfrac{x - τ}{x + τ}$    |
|                                                              |                                                              |                                                              |                                                              |
| $\sinh x = \dfrac{ә^{x} - ә^{-x}}{2}$                        | $\mathrm{csch\ } x = \dfrac{1}{\sinh x} = \dfrac{2}{ә^{x} - ә^{-x}}$ | ${^{-1}}\sinh x = \ln\left( x + \sqrt{1 + x^2} \right)$      | ${^{-1}}\mathrm{csch\ } x = \ln \dfrac{1 + \sqrt{x^2 + 1}}{x}$ |
| $\cosh x = \dfrac{ә^{x} + ә^{-x}}{2}$                        | $\mathrm{sech\ } x = \dfrac{1}{\cosh x} = \dfrac{2}{ә^{x} + ә^{-x}}$ | ${^{-1}} \cosh x = \ln\left( x + \sqrt{x^2 - 1} \right)$     | ${^{-1}}\mathrm{sech\ } x = \ln \dfrac{1 + \sqrt{1 - x^2}}{x}$ |
| $\tanh x = \dfrac{\sinh x}{\cosh x} = \dfrac{ә^{x} - ә^{-x}}{ә^{x} + ә^{-x}} = \dfrac{ә^{2·x} - 1}{ә^{2·x} + 1}$ | $\mathrm{coth\ } x = \dfrac{1}{\tanh x} = \dfrac{\cosh x}{\sinh x} = \dfrac{ә^{x} + ә^{-x}}{ә^{x} - ә^{-x}} = \dfrac{ә^{2·x} + 1}{ә^{2·x} - 1}$ | ${^{-1}}\tanh x = \dfrac{1}{2} · \ln \dfrac{1 + x}{1 - x}$   | ${^{-1}}\coth x = \dfrac{1}{2} · \ln \dfrac{x + 1}{x - 1}$   |

### 典型运算性质



|                           |      |      |
| :------------------------ | ---- | ---- |
| $\sin^2 x + \cos^2 x = 1$ |      |      |
|                           |      |      |
|                           |      |      |



| $\cosh 0 = 1$                                           |                                                         |      |
| :------------------------------------------------------ | ------------------------------------------------------- | ---- |
| $\cosh^2 x - \sinh^2 x = 1$                             |                                                         |      |
|                                                         |                                                         |      |
| $\cosh (x + y) = \cosh x · \cosh y + \sinh x · \sinh y$ | $\cosh (x - y) = \cosh x · \cosh y - \sinh x · \sinh y$ |      |
| $\sinh (x + y) = \sinh x · \cosh y + \cosh x · \sinh y$ | $\sinh (x - y) = \sinh x · \cosh y - \cosh x · \sinh y$ |      |
|                                                         |                                                         |      |
|                                                         |                                                         |      |
| $\sinh (2 · x) = 2 · \sinh x · \cosh x$                 |                                                         |      |
| $\cosh^2 x = \cosh^2 x + \sinh^2 x$                     |                                                         |      |

