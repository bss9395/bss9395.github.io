---
layout:    zh_post
Topic:     概率统计
Title:     参数估计
Revised:   2018-06-30 23:32:00 +08 @ 中国-广东-湛江 +08
Authors:   璀璨星辰
Resources:
---

> ### 最大似然估计 $\mathrm{M_{aximum} L_{ikelihood} E_{stimation}}$

> $$
> \begin{alignedat}{3}
>     \mathrm{MLE} [X \mid \Theta] &= P [\chi_1, \cdots, \chi_n \mid \theta] \\
>                                  &= P [\chi_1 \mid \theta] \cdots P [\chi_n \mid \theta] \\
> \mathrm{MLE} [f (X) \mid \Theta] &= \mathrm{MLE} [X \mid \Theta] \\ 
>                 \widehat{\theta} &\impliedby \max_{(\chi_1, \cdots \chi_n)} \mathrm{MLE} [X \mid \Theta] \\
>                                  &\iff \max_{(\chi_1, \cdots, \chi_n)} \ln \mathrm{MLE} [X \mid \Theta] \\
> \end{alignedat}
> $$
>

> ### 正态分布的最大似然估计

> $$
> \begin{alignedat}{3}
> \Uparrow\quad           &&                                                                           X &\mapsto \mathrm{No} (\mu, \sigma^2) \\
> \Downarrow\quad         &&                                         \mathrm{MLE} [X \mid \mu, \sigma^2] &= \prod_1^n \left[ \dfrac{1}{\sqrt{2 \pi} \sigma} e^{- \frac{(\chi_n - \mu)^2}{2 \sigma^2}} \right] \\
>                         &&                                                                             &= (2 \pi \sigma^2)^{- \frac{n}{2}} \cdot e^{- \frac{1}{2 \sigma^2} \sum_1^n (\chi_n - \mu)^2} \\
> \Downarrow\quad         &&                                     \ln \mathrm{MLE} [X \mid \mu, \sigma^2] &= - \dfrac{n}{2} \ln 2 \pi - \dfrac{n}{2} \ln \sigma^2 - \dfrac{1}{2 \sigma^2} \sum_1^n (\chi_n - \mu)^2 \\
> \Downarrow\quad         &&      \dfrac{\partial}{\partial \mu} \ln \mathrm{MLE} [X \mid \mu, \sigma^2] &= 0 = \dfrac{1}{\sigma^2} \sum_1^n (\chi_n - \mu) \\
> \Downarrow\quad         && \dfrac{\partial}{\partial \sigma^2} \ln \mathrm{MLE} [X \mid \mu, \sigma^2] &= 0 = - \dfrac{n}{2 \sigma^2} + \dfrac{1}{2 \sigma^4} \sum_1^n (\chi_n - \mu)^2 \\
> \fbox{1}\Downarrow\quad &&                                                               \widehat{\mu} &= \dfrac{1}{n} \sum_1^n \chi_n = \overline{\chi} \\
> \fbox{2}\Downarrow\quad &&                                                          \widehat{\sigma^2} &= \dfrac{1}{n} \sum_1^n (\chi_n - \overline{\chi})^2 = s^2 \\
> \end{alignedat}
> $$
>

> ### 后验概率估计

> $$
> \begin{alignedat}{3}
>       P [\Theta \mid X] &= \dfrac{P [X \mid \Theta] \cdot P [\Theta]}{P [X]} \\
>                         &= \dfrac{P [X \mid \Theta] \cdot P [\Theta]}{\int_\Theta P [X \mid \Theta] \cdot P [\Theta] \mathrm{d} \Theta} \\
> \widehat{\theta} \mid X &= \mathrm{Exp} [\Theta \mid X] \\
>                         &= \int_\Theta \Theta \cdot P [\Theta \mid X] \mathrm{d} \Theta \\
> \end{alignedat}
> $$
>
