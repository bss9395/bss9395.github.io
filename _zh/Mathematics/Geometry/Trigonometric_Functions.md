---
layout:    zh_post
Topic:     几何学
Title:     三角函数
Revised:   2017-09-25 22:16:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 符号表示

> | *$\sin$* | *$\cos$* | *$\tan$*  |  *$\cot$*   | *$\sec$* |  *$\csc$*  |
> | :------: | :------: | :-------: | :---------: | :------: | :--------: |
> |  `sine`  | `cosine` | `tangent` | `cotangent` | `secant` | `cosecant` |

> ### 诱导公式

> $$
> \begin{array}{|l|l|l|} \hline
> \sin (- \theta) = - \sin \theta & \sin \left( \theta + \dfrac{1}{2} \pi \right) = + \cos \theta & \sin (\theta + \pi) = - \sin \theta & \sin (\theta + \dfrac{3}{2} \pi) = - \cos \theta \\ \hline
> \cos (- \theta) = + \cos \theta & \cos \left( \theta + \dfrac{1}{2} \pi \right) = - \sin \theta & \cos (\theta + \pi) = - \cos \theta & \cos (\theta + \dfrac{3}{2} \pi) = + \sin \theta \\ \hline
> \tan (- \theta) = - \tan \theta & \tan \left( \theta + \dfrac{1}{2} \pi \right) = - \cot \theta & \tan (\theta + \pi) = + \tan \theta & \tan (\theta + \dfrac{3}{2} \pi) = - \cot \theta \\ \hline
> \end{array}
> $$
>

> ### 和角公式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \sin (\alpha + \beta) &= \sin \alpha \cos \beta + \cos \alpha \sin \beta \\
> \fbox{2}\; && \cos (\alpha + \beta) &= \cos \alpha \cos \beta - \sin \alpha \sin \beta \\
> \fbox{3}\; && \tan (\alpha + \beta) &= \dfrac{\tan \alpha + \tan \beta}{1 - \tan \alpha \tan \beta} \\
> \end{alignedat}
> $$
>

> ### 统一公式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \sin \theta &= \dfrac{2 \tan \dfrac{\theta}{2}}{1 + \tan^2 \dfrac{\theta}{2}} \\
> \fbox{2}\; && \cos \theta &= \dfrac{1 - \tan^2 \dfrac{\theta}{2}}{1 + \tan^2 \dfrac{\theta}{2}} \\
> \fbox{3}\; && \tan \theta &= \dfrac{2 \tan \dfrac{\theta}{2}}{1 - \tan^2 \dfrac{\theta}{2}} \\
> \end{alignedat}
> $$
>

> ### 分角公式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \sin \alpha &= \sin \dfrac{\alpha + \beta}{2} \cos \dfrac{\alpha - \beta}{2} + \cos \dfrac{\alpha + \beta}{2} \sin \dfrac{\alpha - \beta}{2} \\
> \fbox{2}\; && \cos \alpha &= \cos \dfrac{\alpha + \beta}{2} \cos \dfrac{\alpha - \beta}{2} - \sin \dfrac{\alpha + \beta}{2} \sin \dfrac{\alpha - \beta}{2} \\
> \end{alignedat}
> $$
>

> ### 二倍角公式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \sin 2 \theta &= 2 \sin \theta \cos \theta \\
> \fbox{2}\; && \cos 2 \theta &= \cos^2 \theta - \sin^2 \theta \\
> \fbox{3}\; && \tan 2 \theta &= \dfrac{1}{1 - \tan \theta} - \dfrac{1}{1 + \tan \theta} \\
> \end{alignedat}
> $$
>

> ### 和差化积公式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \sin \alpha + \sin \beta &= 2 \sin \dfrac{\alpha + \beta}{2} \cos \dfrac{\alpha - \beta}{2} \\
> \fbox{2}\; && \cos \alpha + \cos \beta &= 2 \cos \dfrac{\alpha + \beta}{2} \cos \dfrac{\alpha - \beta}{2} \\
> \fbox{3}\; && \tan \alpha + \tan \beta &= \dfrac{\sin (\alpha + \beta)}{\cos \alpha \cos \beta} \\
> \fbox{4}\; && \cot \alpha + \cot \beta &= \dfrac{\sin (\alpha + \beta)}{\sin \alpha \sin \beta} \\
> \fbox{5}\; && \tan \alpha + \cot \beta &= \dfrac{\cos (\alpha - \beta)}{\cos \alpha \sin \beta} \\
> \end{alignedat}
> $$
>

> ### 积化和差公式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \sin \alpha \sin \beta &= \dfrac{1}{2} [\cos (\alpha - \beta) - \cos (\alpha + \beta)] \\
> \fbox{2}\; && \sin \alpha \cos \beta &= \dfrac{1}{2} [\sin (\alpha + \beta) + \sin (\alpha - \beta)]] \\
> \fbox{3}\; && \cos \alpha \sin \beta &= \dfrac{1}{2} [\sin (\alpha + \beta) - \sin (\alpha - \beta)]] \\
> \fbox{4}\; && \cos \alpha \cos \beta &= \dfrac{1}{2} [\cos (\alpha + \beta) + \cos (\alpha - \beta)] \\
> \end{alignedat}
> $$
>

> ### 平方差公式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && \sin (\alpha + \beta) \cdot \sin (\alpha - \beta) = \sin^2 \alpha - \sin^2 \beta \\
> \fbox{2}\; && \cos (\alpha + \beta) \cdot \cos (\alpha - \beta) = \cos^2 \alpha - \sin^2 \beta \\
> \end{alignedat}
> $$
>

> ### 辅助角公式

> $$
> \begin{alignedat}{3}
> \fbox{1}\; && A \sin \theta + B \cos \theta &= \sqrt{A^2 + B^2} \cdot \sin \left( \theta + \arctan \dfrac{B}{A} \right) \\
> \fbox{2}\; && A \sin \theta + B \cos \theta &= \sqrt{A^2 + B^2} \cdot \cos \left( \theta - \arctan \dfrac{A}{B} \right) \\
> \end{alignedat}
> $$
>

> ### 分解公式

> $$
> \begin{alignedat}{3}
> \tan (x + y) = \dfrac{\tan x + \tan y}{1 - \tan x \cdot \tan y} \\
> \end{alignedat}
> $$
>