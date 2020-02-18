---
layout:    zh_post
Topic:     收敛极限
Title:     常用积分表
Revised:   2017-02-14 18:15:00 +08 @ 中国-广东-湛江 +08
Authors:   璀璨星辰
Resources:
---

> ### 1 含有$a x + b$的积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \int \frac{\mathrm{d} x}{a x + b} = \frac{1}{a} \ln \vert a x + b \vert +C \\
> \fbox{02}\quad & \int (a x + b)^\mu \mathrm{d} x = \frac{1}{a (\mu + 1)} (a x + b)^{\mu + 1} + C \; (\mu \ne - 1) \\
> \fbox{03}\quad & \int \frac{x}{a x + b} \mathrm{d} x = \frac{1}{a^2} (a x + b - b \ln \vert a x + b \vert) + C \\
> \fbox{04}\quad & \int \frac{x^2}{a x + b} \mathrm{d} x = \frac{1}{a^3} \left[\frac{1}{2} (a x + b)^2 - 2 b (a x + b) + b^2 \ln \vert a x + b \vert\right] + C \\
> \fbox{05}\quad & \int \frac{\mathrm{d} x}{x (a x + b)} = - \frac{1}{b} \ln \left\lvert \frac{a x + b}{x} \right\rvert + C \\
> \fbox{06}\quad & \int \frac{\mathrm{d} x}{x^2 (a x + b)} = - \frac{1}{b x} + \frac{a}{b^2} \ln \left\lvert \frac{a x + b}{x} \right\rvert + C \\
> \fbox{07}\quad & \int \frac{x}{(a x + b)^2} \mathrm{d} x = \frac{1}{a^2} \left(\ln \vert a x + b \vert + \frac{b}{a x + b}\right) + C \\
> \fbox{08}\quad & \int \frac{x^2}{(a x + b)^2} \mathrm{d} x = \frac{1}{a^3} \left(a x + b - 2 b \ln \vert a x + b \lvert - \frac{b^2}{a x + b}\right) + C \\
> \fbox{09}\quad & \int \frac{\mathrm{d} x}{x (a x + b)^2} = \frac{1}{b (a x + b)} - \frac{1}{b^2} \ln \left\lvert \frac{a x + b}{x} \right\rvert + C \\
> \end{aligned}
> $$
>

> ### 2 含有$\sqrt{a x + b}$的积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \int \sqrt{a x + b} \mathrm{d} x = \frac{2}{3 a} \sqrt{(a x + b)^3} + C \\
> \fbox{02}\quad & \int x \sqrt{a x + b} \mathrm{d} x = \frac{2}{15 a^2} (3 a x - 2 b) \sqrt{(a x + b)^3} + C \\
> \fbox{03}\quad & \int x^2 \sqrt{a x + b} \mathrm{d} x = \frac{2}{105 a^3} (15 a^2 x^2 - 12 a b x + 8 b^2) \sqrt{(a x + b)^3} + C \\
> \fbox{04}\quad & \int \frac{x}{\sqrt{a x + b}} \mathrm{d} x = \frac{2}{3 a^2} (a x - 2 b) \sqrt{a x + b} + C \\
> \fbox{05}\quad & \int \frac{x^2}{\sqrt{a x + b}} \mathrm{d} x = \frac{2}{15 a^3} (3 a^2 x^2 - 4 a b x + 8 b^2) \sqrt{a x + b} + C \\
> \fbox{06}\quad & \int \frac{\mathrm{d} x}{x \sqrt{a x + b}} = \left\lbrace\begin{aligned}
>                                                               & \frac{1}{\sqrt{b}} \ln \left\lvert \frac{\sqrt{a x + b} - \sqrt{b}}{\sqrt{a x + b} + \sqrt{b}} \right\rvert + C \; (b > 0) \\
>                                                               & \frac{2}{\sqrt{- b}} \arctan \sqrt{\frac{a x + b}{- b}} + C \; (b < 0)
>                                                               \end{aligned}\right. \\
> \fbox{07}\quad & \int \frac{\mathrm{d} x}{x^2 \sqrt{a x + b}} = - \frac{\sqrt{a x + b}}{b x} - \frac{a}{2 b} \int \frac{\mathrm{d} x}{x \sqrt{a x + b}} \\
> \fbox{08}\quad & \int \frac{a x + b}{x} \mathrm{d} x = 2 \sqrt{a x + b} + b \int \frac{\mathrm{d} x}{x \sqrt{a x + b}} \\
> \fbox{09}\quad & \int \frac{a x + b}{x^2} \mathrm{d} x = - \frac{\sqrt{a x + b}}{x} + \frac{a}{2} \int \frac{\mathrm{d} x}{x \sqrt{a x + b}}
> \end{aligned}
> $$
>

> ### 3 含有$x^2 \pm a^2$的积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \int \frac{\mathrm{d} x}{x^2 + a^2} = \frac{1}{a} \arctan \frac{x}{a} + C \\
> \fbox{02}\quad & \int \frac{\mathrm{d} x}{(x^2 + a^2)^n} = \frac{x}{2 (n - 1) a^2 (x^2 + a^2)^{n - 1}} + \frac{2 n - 3}{2 (n - 1) a^2} \int \frac{\mathrm{d} x}{(x^2 + a^2)^{n - 1}} \\
> \fbox{03}\quad & \int \frac{\mathrm{d} x}{x^2 - a^2} = \frac{1}{2 a} \ln \left\lvert \frac{x - a}{x + a} \right\rvert + C 
> \end{aligned}
> $$
>

> ### 4 含有$a x^2 + b \; (a > 0)$的积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \int \frac{\mathrm{d} x}{a x^2 + b} = \left\lbrace\begin{aligned}
>                                                        & \frac{1}{\sqrt{a b}} \arctan \sqrt{\frac{a}{b}} x + C \\
>                                                        & \frac{1}{2 \sqrt{- a b}} \ln \left\lvert \frac{\sqrt{a} x - \sqrt{- b}}{\sqrt{a} x + \sqrt{- b}} \right\rvert + C
>                                                        \end{aligned}\right. \\
> \fbox{02}\quad & \int \frac{x}{a x^2 + b} \mathrm{d} x = \frac{1}{2 a} \ln \lvert a x^2 + b \rvert + C \\
> \fbox{03}\quad & \int \frac{x^2}{a x^2 + b} \mathrm{d} x = \frac{x}{a} - \frac{b}{a} \int \frac{\mathrm{d} x}{a x^2 + b} \\
> \fbox{04}\quad & \int \frac{\mathrm{d} x}{x (a x^2 + b)} = \frac{1}{2 b} \ln \frac{x^2}{\lvert a x^2 + b \rvert} + C \\
> \fbox{05}\quad & \int \frac{\mathrm{d} x}{x^2 (a x^2 + b)} = - \frac{1}{b x} - \frac{a}{b} \int \frac{\mathrm{d} x}{a x^2 + b} \\
> \fbox{06}\quad & \int \frac{\mathrm{d} x}{x^3 (a x^2 + b)} = \frac{a}{2 b^2} \ln \frac{\lvert a x^2 + b \rvert}{x^2} - \frac{1}{2 b x^2} + C \\
> \fbox{07}\quad & \int \frac{\mathrm{d} x}{(a x^2 + b)^2} = \frac{x}{2 b (a x^2 + b)} + \frac{1}{2 b} \int \frac{\mathrm{d} x}{a x^2 + b}
> \end{aligned}
> $$
>

> ### 5 含有$a x^2 + b x + c \; (a > 0)$的积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \int \frac{\mathrm{d} x}{a x^2 + b x + c} = \left\lbrace\begin{aligned}
>                                                              & \frac{2}{\sqrt{4 a c - b^2}} \arctan \frac{2 a x + b}{\sqrt{4 a c - b^2}} + C \; (b^2 < 4 a c)\\
>                                                              & \frac{1}{\sqrt{b^2 - 4 a c}} \ln \left\lvert \frac{2 a x + b - \sqrt{b^2 - 4 a c}}{2 a x + b + \sqrt{b^2 - 4 a c}} \right\rvert + C \; (b^2 > 4 a c)
>                                                              \end{aligned}\right. \\
> \fbox{02}\quad & \int \frac{x}{a x^2 + b x + c} \mathrm{d} x = \frac{1}{2 a} \ln \left\lvert a x^2 + b x + c \right\rvert - \frac{b}{2 a} \int \frac{\mathrm{d} x}{a x^2 + b x + c}
> \end{aligned}
> $$
>

> ### 6 含有$\sqrt{x^2 + a^2} \; (a > 0)$的积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \int \frac{\mathrm{d} x}{\sqrt{x^2 + a^2}} = \operatorname{arsh} \frac{x}{a} + C_1 = \ln (x + \sqrt{x^2 + a^2}) + C \\
> \fbox{02}\quad & \int \frac{\mathrm{d} x}{\sqrt{(x^2 + a^2)^3}} = \frac{x}{a^2 \sqrt{x^2 + a^2}} + C \\
> \fbox{03}\quad & \int \frac{x}{\sqrt{x^2 + a^2}} \mathrm{d} x  = \sqrt{x^2 + a^2} + C \\
> \fbox{04}\quad & \int \frac{x}{\sqrt{(x^2 + a^2)^3}} \mathrm{d} x = - \frac{1}{\sqrt{x^2 + a^2}} + C \\
> \fbox{05}\quad & \int \frac{x^2}{\sqrt{x^2 + a^2}} \mathrm{d} x = \frac{x}{2} \sqrt{x^2 + a^2} - \frac{a^2}{2} \ln (x + \sqrt{x^2 + a^2}) + C \\
> \fbox{06}\quad & \int \frac{x^2}{\sqrt{(x^2 + a^2)^3}} \mathrm{d} x = - \frac{x}{\sqrt{x^2 + a^2}} + \ln (x + \sqrt{x^2 + a^2}) + C \\
> \fbox{07}\quad & \int \frac{\mathrm{d} x}{x \sqrt{x^2 + a^2}} = \frac{1}{a} \ln \frac{\sqrt{x^2 + a^2} - a}{\lvert x \rvert} + C \\
> \fbox{08}\quad & \int \frac{\mathrm{d} x}{x^2 \sqrt{x^2 + a^2}} = - \frac{\sqrt{x^2 + a^2}}{a^2 x} + C \\
> \fbox{09}\quad & \int \sqrt{x^2 + a^2} \mathrm{d} x = \frac{x}{2} \sqrt{x^2 + a^2} + \frac{a^2}{2} \ln (x + \sqrt{x^2 + a^2}) + C \\
> \fbox{10}\quad & \int \sqrt{(x^2 + a^2)^3} \mathrm{d} x = \frac{x}{8} (2 x^2 + 5 a^2) \sqrt{x^2 + a^2} + \frac{3}{8} a^4 \ln (x + \sqrt{x^2 + a^2}) + C \\
> \fbox{11}\quad & \int x \sqrt{(x^2+ a^2} \mathrm{d} x = \frac{1}{3} \sqrt{(x^2 + a^2)^3} + C \\
> \fbox{12}\quad & \int x^2 \sqrt{x^2 + a^2} \mathrm{d} x = \frac{x}{8} (2 x^2 + a^2) \sqrt{x^2 + a^2} - \frac{a^4}{8} \ln (x + \sqrt{x^2 + a^2}) + C \\
> \fbox{13}\quad & \int \frac{\sqrt{x^2 + a^2}}{x} \mathrm{d} x = \sqrt{x^2 + a^2} + a \ln \frac{\sqrt{x^2 + a^2} - a}{\lvert x \rvert} + C \\
> \fbox{14}\quad & \int \frac{\sqrt{x^2 + a^2}}{x^2} \mathrm{d} x = - \frac{\sqrt{x^2 + a^2}}{x} + \ln (x + \sqrt{x^2 + a^2}) + C
> \end{aligned}
> $$
>

> ### 7 含有$\sqrt{x^2 - a^2} \; (a > 0)$的积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \frac{\mathrm{d} x}{\sqrt{x^2 - a^2}} = \frac{x}{\lvert x \rvert} \operatorname{arch} \frac{\lvert x \rvert}{a} + C_1 = \ln \lvert x + \sqrt{x^2 - a^2} \rvert + C \\
> \fbox{02}\quad & \int \frac{\mathrm{d} x}{\sqrt{(x^2 - a^2)^3}} = - \frac{x}{a^2 \sqrt{x^2 - a^2}} + C \\
> \fbox{03}\quad & \int \frac{x}{\sqrt{x^2 - a^2}} \mathrm{d} x = \sqrt{x^2 - a^2} + C \\
> \fbox{04}\quad & \int \frac{x}{\sqrt{(x^2 - a^2)^3}} \mathrm{d} x = - \frac{1}{\sqrt{x^2 - a^2}} + C \\
> \fbox{05}\quad & \int \frac{x^2}{\sqrt{x^2 - a^2}} \mathrm{d} x = \frac{x}{2} \sqrt{x^2 - a^2} + \frac{a^2}{2} \ln \lvert x + \sqrt{x^2 - a^2} \rvert + C \\
> \fbox{06}\quad & \int \frac{x^2}{\sqrt{(x^2 - a^2)^3}} \mathrm{d} x = - \frac{x}{\sqrt{x^2 - a^2}} + \ln \lvert x + \sqrt{x^2 - a^2} \rvert + C \\
> \fbox{07}\quad & \int \frac{\mathrm{d} x}{x \sqrt{x^2 - a^2}} = \frac{1}{a} \arccos \frac{a}{\lvert x \rvert} + C \\
> \fbox{08}\quad & \int \frac{\mathrm{d} x}{x^2 \sqrt{x^2 - a^2}} = \frac{\sqrt{x^2 - a^2}}{a^2 x} + C \\
> \fbox{09}\quad & \int \sqrt{x^2 - a^2} \mathrm{d} x = \frac{x}{2} \sqrt{x^2 - a^2} - \frac{a^2}{2} \ln \lvert x + \sqrt{x^2 - a^2} \rvert + C \\
> \fbox{10}\quad & \int \sqrt{(x^2 - a^2)^3} \mathrm{d} x = \frac{x}{8} (2x^2 - 5 a^2) \sqrt{x^2 - a^2} + \frac{3}{8} a^4 \ln \lvert x + \sqrt{x^2 - a^2} \rvert + C \\
> \fbox{11}\quad & \int x \sqrt{x^2 - a^2} \mathrm{d} x = \frac{1}{3} \sqrt{(x^2 - a^2)^3} + C \\
> \fbox{12}\quad & \int x^2 \sqrt{x^2 - a^2} \mathrm{d} x = \frac{x}{8} (2 x^2 - a^2) \sqrt{x^2 - a^2} - \frac{a^4}{8} \ln \lvert x + \sqrt{x^2 - a^2} \rvert + C \\
> \fbox{13}\quad & \int \frac{\sqrt{x^2 - a^2}}{x} \mathrm{d} x = \sqrt{x^2 - a^2} - a \arccos \frac{a}{\lvert x \rvert} + C \\
> \fbox{14}\quad & \int \frac{\sqrt{x^2 - a^2}}{x^2} \mathrm{d} x = - \frac{\sqrt{x^2 - a^2}}{x} + \ln \lvert x + \sqrt{x^2 - a^2}\rvert + C
> \end{aligned}
> $$
>

> ### 8 含有$\sqrt{a^2 - x^2} \; (a > 0)$的积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \int \frac{\mathrm{d} x}{\sqrt{a^2 - x^2}} = \arcsin \frac{x}{a} + C \\
> \fbox{02}\quad & \int \frac{\mathrm{d} x}{\sqrt{(a^2 - x^2)^3}} = \frac{x}{a^2 \sqrt{a^2 - x^2}} + C \\
> \fbox{03}\quad & \int \frac{x}{\sqrt{a^2 - x^2}} \mathrm{d} x = - \sqrt{a^2 - x^2} + C \\
> \fbox{04}\quad & \int \frac{x}{\sqrt{(a^2 - x^2)^3}} \mathrm{d} x = \frac{1}{\sqrt{a^2 - x^2}} + C \\
> \fbox{05}\quad & \int \frac{x^2}{\sqrt{a^2 - x^2}} \mathrm{d} x = - \frac{x}{2} \sqrt{a^2 - x^2} + \frac{a^2}{2} \arcsin \frac{x}{a} + C \\
> \fbox{06}\quad & \int \frac{x^3}{\sqrt{(a^2 - x^2)^3}} \mathrm{d} x = \frac{x}{\sqrt{a^2 - x^2}} - \arcsin \frac{x}{a} + C \\
> \fbox{07}\quad & \int \frac{\mathrm{d} x}{x \sqrt{a^2 - x^2}} = \frac{1}{a} \ln \frac{a - \sqrt{a^2 - x^2}}{\lvert x \rvert} + C \\
> \fbox{08}\quad & \int \frac{\mathrm{d} x}{x^2 \sqrt{a^2 - x^2}} = - \frac{\sqrt{a^2 - x^2}}{a^2 x^2} + C \\
> \fbox{09}\quad & \int \sqrt{a^2 - x^2} \mathrm{d} x = \frac{x}{2} \sqrt{a^2 - x^2} + \frac{a^2}{2} \arcsin \frac{x}{a} + C \\
> \fbox{10}\quad & \int \sqrt{(a^2 - x^2)^3} \mathrm{d} x = \frac{x}{8} (5 a^2 - 2 x^2) \sqrt{a^2 - x^2} + \frac{3}{8} a^4 \arcsin \frac{x}{a} + C \\
> \fbox{11}\quad & \int x \sqrt{a^2 - x^2} \mathrm{d} x = - \frac{1}{3} \sqrt{(a^2 - x^2)^3} + C \\
> \fbox{12}\quad & \int x^2 \sqrt{a^2 - x^2} \mathrm{d} x = \frac{x}{8} (2 x^2 - a^2) \sqrt{a^2 - x^2} + \frac{a^4}{8} \arcsin \frac{x}{a} + C \\
> \fbox{13}\quad & \int \frac{\sqrt{a^2 - x^2}}{x} \mathrm{d} x = \sqrt{a^2 - x^2} + a \ln \frac{a -  \sqrt{a^2 - x^2}}{\lvert x \rvert} + C \\
> \fbox{14}\quad & \int \frac{\sqrt{a^2 - x^2}}{x^2} \mathrm{d} x = - \frac{\sqrt{a^2 - x^2}}{x} - \arcsin \frac{x}{a} + C 
> \end{aligned}
> $$
>

> ### 9 含有$\sqrt{\pm a x^2 + b x + c} \; (a > 0)$的积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \int \frac{\mathrm{d} x}{\sqrt{a x^2 + b x + c}} = \frac{1}{\sqrt{a}} \ln \lvert 2 a x + b + 2 \sqrt{a \vphantom{x^2}} \sqrt{a x^2 + b x + c} \rvert + C \\
> \fbox{02}\quad & \int \sqrt{a x^2 + b x + c} \mathrm{d} x = \frac{2 a x + b}{4 a} \sqrt{a x^2 + b x + c} + \frac{4 a c - b^2}{8 \sqrt{a^3}} \ln \lvert 2 a x + b + 2\sqrt{a \vphantom{x^2}} \sqrt{a x^2 + b x + c} \rvert + C \\
> \fbox{03}\quad & \int \frac{x}{\sqrt{a x^2 + b x + c}} \mathrm{d} x = \frac{1}{a} \sqrt{a x^2 + b x + c} - \frac{b}{2 \sqrt{a^3}} \ln \lvert2 a x + b + 2 \sqrt{a \vphantom{x^2}}  \sqrt{a x^2 + b x + c}\rvert + C \\
> \fbox{04}\quad & \int \frac{\mathrm{d} x}{\sqrt{c + b x - a x^2}} = \frac{1}{\sqrt{a}} \arcsin \frac{2 a x - b}{\sqrt{b^2 + 4 a c}} + C \\
> \fbox{05}\quad & \int \sqrt{c + bx - a x^2} \mathrm{d} x = \frac{2 a x - b}{4 a} \sqrt{c + b x - a x^2} + \frac{b^2 + 4 a c}{8 \sqrt{a^3}} \arcsin \frac{2 a x - b}{\sqrt{b^2 + 4 a c}} + C \\
> \fbox{06}\quad & \int \frac{x}{\sqrt{c + b x - a x^2}} \mathrm{d} x = - \frac{1}{a} \sqrt{c + b x - a x^2} + \frac{b}{2 \sqrt{a^3}} \arcsin \frac{2 a x - b}{\sqrt{b^2 + 4 a c}} + C 
> \end{aligned}
> $$
>

> ### 10 含有$\sqrt{\pm\dfrac{x - a}{x - b}}$或$\sqrt{(x - a)(b - x)}$的积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \int \frac{x - a}{x - b} \mathrm{d} x = (x - b) \sqrt{\frac{x - a}{x - b}} + (b - a) \ln (\sqrt{\lvert x - a \rvert} + \sqrt{\lvert x - b \rvert}) + C \\
> \fbox{02}\quad & \int \sqrt{\frac{x - a}{b -x}} \mathrm{d} x = (x - b) \sqrt{\frac{x - a}{b - x}} + (b - a) \arcsin \sqrt{\frac{x - a}{b - a}} + C \\
> \fbox{03}\quad & \int \frac{\mathrm{d} x}{\sqrt{(x - a)(b - x)}} = 2 \arcsin \sqrt{\frac{x - a}{b - a}} + C \; (a < b) \\
> \fbox{04}\quad & \int \sqrt{(x - a)(b - x)} \mathrm{d} x = \frac{2 x - a -b}{4} \sqrt{(x - a)(b - x)} + \frac{(b - a)^2}{4} \arcsin \sqrt{\frac{x - a}{b - a}} + C \; (a < b)
> \end{aligned}
> $$
>

> ### 11 含有三角函数的积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \int \sin x \mathrm{d} x = - \cos x + C \\
> \fbox{02}\quad & \int \cos x \mathrm{d} x = \sin x + C \\
> \fbox{03}\quad & \int \tan x \mathrm{d} x = - \ln \lvert \cos x \rvert + C \\
> \fbox{04}\quad & \int \cot x \mathrm{d} x = \ln \lvert \sin x \rvert + C \\
> \fbox{05}\quad & \int \sec x \mathrm{d} x = \ln \left\lvert \tan \left(\frac{\pi}{4} + \frac{x}{2}\right) \right\rvert + C = \ln \lvert \sec x + \tan x\rvert + C \\
> \fbox{06}\quad & \int \csc x \mathrm{d} x = \ln \left\lvert \tan \frac{x}{2} \right\rvert + C = \ln \lvert \csc x - \cot x \rvert + C \\
> \fbox{07}\quad & \int \sec^2 x \mathrm{d} x = \tan x + C \\
> \fbox{08}\quad & \int \csc^2 x \mathrm{d} x = - \cot x + C \\
> \fbox{09}\quad & \int \sec x \tan x \mathrm{d} x = \sec x + C \\
> \fbox{10}\quad & \int \csc x \cot x \mathrm{d} x = - \csc x + C \\
> \fbox{11}\quad & \int \sin^2 x \mathrm{d} x = \frac{x}{2} - \frac{1}{4} \sin 2 x + C \\
> \fbox{12}\quad & \int \cos^2 x \mathrm{d} x = \frac{x}{2} + \frac{1}{4} \sin 2 x + C \\
> \fbox{13}\quad & \int \sin^n x \mathrm{d} x = - \frac{1}{n} \sin^{n - 1} x \cos x + \frac{n - 1}{n} \int \sin^{n - 2} \mathrm{d} x \\
> \fbox{14}\quad & \int \cos^n \mathrm{d} x = \frac{1}{n} \cos^{n - 1} x \sin x + \frac{n - 1}{n} \int \cos^{n - 2} \mathrm{d} x \\
> \fbox{15}\quad & \int \frac{\mathrm{d} x}{\sin^n x} = - \frac{1}{n - 1} \cdot \frac{\cos x}{\sin^{n - 1} x} + \frac{n - 2}{n - 1} \int \frac{\mathrm{d} x}{\sin^{n - 2} x} \\
> \fbox{16}\quad & \int \frac{\mathrm{d} x}{\cos^n x} = \frac{1}{n - 1} \cdot \frac{\sin x}{\cos^{n - 1} x} + \frac{n - 2}{n - 1} \int \frac{\mathrm{d} x}{\cos^{n - 2} x} \\
> \fbox{17}\quad & \int \cos^m x \sin^n x \mathrm{d} x = \frac{1}{m + n} \cos^{m - 1} x \sin^{n + 1} x + \frac{m - 1}{m + n} \int \cos^{m - 2} x \sin^n x \mathrm{d} x \\
>                & \phantom{\, \int \cos^m x \sin^n x \mathrm{d} x} = - \frac{1}{m + n} \cos^{m + 1} x \sin^{n - 1} x + \frac{n - 1}{m + n} \int \cos^m x \sin^{n - 2} x \mathrm{d} x \\
> \fbox{18}\quad & \int \sin ax \cos bx \mathrm{d} x  = - \frac{1}{2 (a + b)} \cos (a + b) x - \frac{1}{2 (a - b)} \cos (a - b) x + C \\
> \fbox{19}\quad & \int \sin ax \sin bx \mathrm{d} x =  - \frac{1}{2 (a + b)} \sin (a + b) x + \frac{1}{2 (a - b)} \sin (a - b) x + C \\
> \fbox{20}\quad & \int \cos a x \cos b x  \mathrm{d} x = \frac{1}{2 (a + b)} \sin (a + b) x + \frac{1}{2 (a - b)} \sin (a - b) x + C \\
> \fbox{21}\quad & \int \frac{\mathrm{d} x}{a + b \sin x} = \frac{2}{\sqrt{a^2 - b^2}} \arctan \frac{a \tan \frac{x}{2} + b}{\sqrt{a^2 - b^2}} + C \; (a^2 > b^2) \\
> \fbox{22}\quad & \int \frac{\mathrm{d} x}{a + b \sin x} = \frac{1}{\sqrt{b^2 - a^2}} \ln \left\lvert \frac{a \tan \frac{x}{2} + b - \sqrt{b^2 - a^2}}{a \tan \frac{x}{2} + b + \sqrt{b^2 - a^2}} \right\rvert + C \; (a^2 < b^2) \\
> \fbox{23}\quad & \int \frac{\mathrm{d} x}{a + b \cos x} = \frac{2}{a + b} \sqrt{\frac{a + b}{a - b}} \arctan \left(\sqrt{\frac{a - b}{a + b}} \tan \frac{x}{2} \right) + C \; (a^2 > b^2) \\
> \fbox{24}\quad & \int \frac{\mathrm{d} x}{a + b \cos x} = \frac{1}{a + b} \sqrt{\frac{a + b}{b - a}} \ln \left\lvert \frac{\tan \frac{x}{2} + \sqrt{\frac{a + b}{b - a}}}{\tan \frac{x}{2} - \sqrt{\frac{a + b}{b - a}}} \right\rvert + C \; (a^2 < b^2) \\
> \fbox{25}\quad & \int \frac{\mathrm{d} x}{a^2 \cos^2 x + b^2 \sin^2 x} = \frac{1}{a b} \arctan \left(\frac{b}{a} \tan x\right) + C \\
> \fbox{26}\quad & \int \frac{\mathrm{d} x}{a^2 \cos^2 x - b^2 \sin^2 x} =  \frac{1}{2 a b} \ln \left\lvert \frac{b \tan x + a}{b \tan x - a} \right\rvert + C \\
> \fbox{27}\quad & \int x \sin a x \mathrm{d} x = \frac{1}{a^2} \sin a x - \frac{1}{a} x \cos a x + C \\
> \fbox{28}\quad & \int x^2 \sin a x \mathrm{d} x = - \frac{1}{a} x^2 \cos a x +\frac{2}{a^2} x \sin a x + \frac{2}{a^3} \cos a x + C \\
> \fbox{29}\quad & \int x \cos a x \mathrm{d} x = \frac{1}{a^2} \cos a x + \frac{1}{a} x \sin a x + C \\
> \fbox{30}\quad & \int x^2 \cos a x \mathrm{d} x = \frac{1}{a} x^2 \sin a x + \frac{2}{a^2} x \cos a x - \frac{2}{a^3} \sin a x + C 
> \end{aligned}
> $$
>

> ### 12 含有反三角函数的积分(其中$a > 0$)

> $$
> \begin{aligned}
> \fbox{01}\quad & \int \arcsin \frac{x}{a} \mathrm{d} x = x \arcsin \frac{x}{a} + \sqrt{a^2 - x^2} + C \\
> \fbox{02}\quad & \int x \arcsin \frac{x}{a} \mathrm{d} x = \left(\frac{x^2}{x} - \frac{a^2}{4}\right) \arcsin \frac{x}{a} + \frac{x}{4} \sqrt{a^2 - x^2} + C \\
> \fbox{03}\quad & \int x^2 \arcsin \frac{x}{a} \mathrm{d} x = \frac{x^3}{3} \arcsin \frac{x}{a} + \frac{1}{9} (x^2 + 2 a^2) \sqrt{a^2 - x^2} + C \\
> \fbox{04}\quad & \int \arccos \frac{x}{a} \mathrm{d} x = x \arccos \frac{x}{a} - \sqrt{a^2 - x^2} + C \\
> \fbox{05}\quad & \int x \arccos \frac{x}{a} \mathrm{d} x = \left(\frac{x^2}{2} - \frac{a^2}{4}\right) \arccos \frac{x}{a} - \frac{x}{4} \sqrt{a^2 - x^2} + C \\
> \fbox{06}\quad & \int x^2 \arccos \frac{x}{a} \mathrm{d} x = \frac{x^3}{3} \arccos \frac{x}{a} - \frac{1}{9} (x^2 + 2 a^2) \sqrt{a^2 - x^2} + C \\
> \fbox{07}\quad & \int \arctan \frac{x}{a} \mathrm{d} x = x \arctan \frac{x}{a} - \frac{a}{2} \ln (a^2 + x^2) + C \\
> \fbox{08}\quad & \int x \arctan \frac{x}{a} \mathrm{d} x = \frac{1}{2} (a^2 + x^2) \arctan \frac{x}{a} - \frac{a}{2} x + C \\
> \fbox{09}\quad & \int x^2 \arctan \frac{x}{a} \mathrm{d} x = \frac{x^3}{3} \arctan \frac{x}{a} - \frac{a}{6} x^2 + \frac{a^3}{6} \ln (a^2 + x^2) + C
> \end{aligned}
> $$
>

> ### 13 含有指数函数的积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \int a^x \mathrm{d} x = \frac{1}{\ln a} a^x + C \\
> \fbox{02}\quad & \int e^{a x} \mathrm{d} x = \frac{1}{a} e^{a x} + C \\
> \fbox{03}\quad & \int x e^{a x} \mathrm{d} x = \frac{1}{a^2} (a x - 1) e^{a x} + C \\
> \fbox{04}\quad & \int x^n e^{a x} \mathrm{d} x = \frac{1}{a} x^n e^{a x} - \frac{n}{a} \int x^{n - 1} e^{a x} \mathrm{d} x \\
> \fbox{05}\quad & \int x a^x \mathrm{d} x = \frac{x}{\ln a} a^x - \frac{1}{\ln^2 a} a^x + C \\
> \fbox{06}\quad & \int x^n a^x \mathrm{d} x = \frac{1}{\ln a} x^n a^x - \frac{n}{\ln a} \int x^{n - 1} a^x \mathrm{d} x \\
> \fbox{07}\quad & \int e^{a x} \sin b x \mathrm{d} x = \frac{1}{a^2 + b^2} e^{a x} (a \sin b x - b \cos b x) + C \\
> \fbox{08}\quad & \int e^{a x} \cos b x \mathrm{d} x = \frac{1}{a^2 + b^2} e^{a x} (b \sin b x + a \cos b x) + C \\
> \fbox{09}\quad & \int e^{a x} \sin^n b x \mathrm{d} x = \frac{1}{a^2 + b^2 n^2} e^{a x} \sin^{n - 1} b x (a \sin b x - n b \cos b x) + \frac{n (n - 1) b^2}{a^2 + b^2 n^2} \int e^{a x} \sin^{n - 2} b x \mathrm{d} x \\
> \fbox{10}\quad & \int e^{a x} \cos^n b x \mathrm{d} x = \frac{1}{a^2 + b^2 n^2} e^{a x} \cos^{n - 1} b x (a \cos bx + n b \sin b x) + \frac{n (n - 1) b^2}{a^2 + b^2 n^2} \int e^{a x} \cos^{n - 2} b x \mathrm{d} x
> \end{aligned}
> $$
>

> ### 14 含有对数函数的积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \int \ln x \mathrm{d} x = x \ln x - x + C \\
> \fbox{02}\quad & \int \frac{\mathrm{d} x}{x \ln x} = \ln \lvert \ln x \rvert + C \\
> \fbox{03}\quad & \int x^n \ln x \mathrm{d} x = \frac{1}{n + 1} x^{n + 1} \left(\ln x - \frac{1}{n + 1}\right) + C \\
> \fbox{04}\quad & \int \ln^n x \mathrm{d} x = x \ln^n x - n \int \ln^{n - 1} \mathrm{d} x \\
> \fbox{05}\quad & \int x^m \ln^n x \mathrm{d} x = \frac{1}{m + 1} x^{m + 1} \ln^n x - \frac{n}{m + 1} \int x^m \ln^{n - 1} x  \mathrm{d} x
> \end{aligned}
> $$
>

> ### 15 含有双曲函数的积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \int \operatorname{sh} x \mathrm{d} x = \operatorname{ch} x + C \\
> \fbox{02}\quad & \int \operatorname{ch} x \mathrm{d} x = \operatorname{sh} x + C \\
> \fbox{03}\quad & \int \operatorname{th} x \mathrm{d} x = \ln \operatorname{ch} x + C \\
> \fbox{04}\quad & \int \operatorname{sh}^2 x \mathrm{d} x = - \frac{x}{2} + \frac{1}{4} \operatorname{sh} 2 x + C \\
> \fbox{05}\quad & \int \operatorname{ch}^2 x \mathrm{d} x = \frac{x}{2} + \frac{1}{4} \operatorname{sh} 2 x + C
> \end{aligned}
> $$
>

> ### 16 定积分

> $$
> \begin{aligned}
> \fbox{01}\quad & \int_{- \pi}^\pi \cos n x \mathrm{d} x = \int_{- \pi}^\pi \sin n x \mathrm{d} x = 0 \\
> \fbox{02}\quad & \int_{- \pi}^{\pi} \cos m x \sin n x \mathrm{d} x = 0 \\
> \fbox{03}\quad & \int_{- \pi}^{\pi} \cos m x \cos n x \mathrm{d} x = \left\lbrace\begin{aligned}
>                                                                      & 0, m \ne n \\
>                                                                      & \pi, m = n
>                                                                      \end{aligned}\right. \\
> \fbox{04}\quad & \int_{- \pi}^{\pi} \sin m x \sin n x \mathrm{d} x = \left\lbrace\begin{aligned}
>                                                                      & 0, m \ne n \\
>                                                                      & \pi, m = n
>                                                                      \end{aligned}\right. \\
> \fbox{05}\quad & \int_{0}^{\pi} \sin m x \sin n x \mathrm{d} x = \int_{0}^{\pi} \cos m x \cos n x \mathrm{d} x = \left\lbrace\begin{aligned}
>                                                                                                                  & 0, m \ne n \\
>                                                                                                                  & \frac{\pi}{2}, m = n
>                                                                                                                  \end{aligned}\right. \\
> \fbox{06}\quad & I_n = \int_{0}^{\frac{\pi}{2}} \sin^n x \mathrm{d} x = \int_{0}^{\frac{\pi}{2}} \cos^n x \mathrm{d} x \\
>                & \phantom{I_n} = \frac{n - 1}{n} I_{n - 2} \\
>                & \phantom{I_n} = \left\lbrace\begin{alignedat}{3}
>                                  & \frac{n - 1}{n} \cdot \frac{n - 3}{n - 2} \cdot \ldots \cdot \frac{3}{4} \cdot \frac{1}{2} \cdot \left( I_0 = \dfrac{\pi}{2} \right) &\quad\Leftarrow\quad n &= 2 k \\
>                                  & \frac{n - 1}{n} \cdot \frac{n - 3}{n - 2} \cdot \ldots \cdot \frac{4}{5} \cdot \frac{2}{3} \cdot \left( I_1 = 1 \right)              &\quad\Leftarrow\quad n &= 2 k + 1 \\
>                                  \end{alignedat}\right.
> \end{aligned}
> $$
>