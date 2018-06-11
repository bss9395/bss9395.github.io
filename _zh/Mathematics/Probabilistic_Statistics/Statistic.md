---
layout:    zh_post
Topic:     概率统计
Title:     统计量
Revised:   2018-06-11 19:33:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 样本

> $$
> \begin{alignedat}{3}
>              X &\mapsto C (x) \\
>                &\Downarrow\; \text{Choose} \\
> \chi_1, \cdots &, \chi_i, \cdots, \chi_n \\
> \end{alignedat}
> $$
>

> ### 统计量 $S_{tatistic}$

> $$
> \begin{alignedat}{3}
> S &= S [\chi_1, \cdots, \chi_n] \quad\Leftarrow\quad p (\chi_1, \cdots, \chi_n) = p_X (\chi_1) \cdots p_X (\chi_n) \\
> \end{alignedat}
> $$
>

> ### 样本均值

> $$
> \begin{alignedat}{3}
> \mu &\xlongequal{\mathcal{Ungrouped}} \dfrac{\chi_1 + \cdots + \chi_n}{n} = \dfrac{1}{n} \sum_{i = 1}^n \chi_i \\
> \mu &\xlongequal{\mathcal{Grouped}} \dfrac{\overline{\chi_1} \cdot f_1 + \cdots + \overline{\chi_n} \cdot f_n}{n} = \dfrac{1}{n} \sum_{i = 1}^n \overline{\chi_i} \cdot f_i \\
>   E &\mathop{\implies}^{\text{Choose}} \mu \\
> \end{alignedat}
> $$
>

> ### 样本方差

> $$
> \begin{alignedat}{3}
>         \sigma^2 &\xlongequal{\mathcal{Ungrouped}} \dfrac{1}{n} \sum_{i = 1}^n (\chi_i - \mu)^2 = \dfrac{1}{n} \sum_{i = 1}^n \chi_i^2 - \mu^2 \\
>         \sigma^2 &\xlongequal{\mathcal{Grouped}} \dfrac{1}{n} \sum_{i = 1}^n (\overline{\chi_i} - \mu)^2 \cdot f_i = \dfrac{1}{n} \sum_{i = 1}^n \overline{\chi_i}^2 \cdot f_i - \mu^2 \\
> \tilde{\sigma}^2 &\xlongequal{\mathcal{Ungrouped}} \dfrac{1}{n - 1} \sum_{i = 1}^n (\chi_i - \mu)^2 = \dfrac{1}{n - 1} \left[ \sum_{ i = 1}^n \chi_i^2 - n \cdot \mu^2 \right] \\
> \tilde{\sigma}^2 &\xlongequal{\mathcal{Grouped}} \dfrac{1}{n - 1} \sum_{i = 1}^n (\overline{\chi_i} - \mu)^2 \cdot f_i = \dfrac{1}{n - 1} \left[ \sum_{i = 1}^n \overline{\chi_i}^2 \cdot f_i - n \cdot \mu^2 \right] \\
>              V^2 &\mathop{\implies}^{\text{Choose}} \sigma^2 \\
>      \tilde{V}^2 &\mathop{\implies}^{\text{Choose}} \tilde{\sigma}^2 \\
> \end{alignedat}
> $$
>

> ### 样本期望

> $$
> \begin{alignedat}{3}
>   \mathrm{Exp} [E] &= \mathrm{Exp} \left[ \dfrac{1}{n} \sum_{i = 1}^n \chi_i \right] = \mu \\
>   \mathrm{Var} [E] &= \mathrm{Var} \left[ \dfrac{1}{n} \sum_{i = 1}^n \chi_i \right] = \dfrac{\sigma^2}{n} = \dfrac{n - 1}{n^2} \tilde{\sigma}^2 \\
>                  E &\sim  \mathrm{No} \left( \mu, \dfrac{\sigma^2}{n} \right) \\
> \end{alignedat}
> $$
>

> ### 样本偏度 $\mathrm{Skew_{ness}}$

> $$
> \begin{alignedat}{3}
> \mathrm{Skew} [X] &\xlongequal{\mathcal{Ungrouped}} \dfrac{\dfrac{1}{n} \sum\limits_{i = 1}^n (\chi_i - \overline{\chi})^3}{\left[ \dfrac{1}{n} \sum\limits_{i = 1}^n (\chi_i - \overline{\chi})^2 \right]^\frac{3}{2}} \\
> \mathrm{Skew} [X] &\xlongequal{\mathcal{Grouped}} \dfrac{\dfrac{1}{n} \sum\limits_{i = 1}^n (\overline{\chi_i} - \overline{\chi})^3 \cdot f_i}{\left[ \dfrac{1}{n} \sum\limits_{i = 1}^n (\overline{\chi_i} - \overline{\chi})^2 \cdot f_i \right]^\frac{3}{2}}
> \end{alignedat}
> $$
>

> ### 样本峰度 $\mathrm{Kurt_{osis}}$

> $$
> \begin{alignedat}{3}
> \mathrm{Kurt} [X] &\xlongequal{\mathcal{Ungrouped}} \dfrac{\dfrac{1}{n} \sum\limits_{i = 1}^n (\chi_i - \overline{\chi})^4}{\left[ \dfrac{1}{n} \sum\limits_{i = 1}^n (\chi_i - \overline{\chi})^2 \right]^2} - 3 \\
> \mathrm{Kurt} [X] &\xlongequal{\mathcal{Grouped}} \dfrac{\dfrac{1}{n} \sum\limits_{i = 1}^n (\overline{\chi_i} - \overline{\chi})^4 \cdot f_i}{\left[ \dfrac{1}{n} \sum\limits_{i = 1}^n (\overline{\chi_i} - \overline{\chi})^2 \cdot f_i \right]^2} - 3 \\
> \end{alignedat}
> $$
>