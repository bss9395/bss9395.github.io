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
> \overline{\chi} &\xlongequal{\mathcal{Ungrouped}} \dfrac{\chi_1 + \cdots + \chi_n}{n} = \dfrac{1}{n} \sum_{i = 1}^n \chi_i \\
> \overline{\chi} &\xlongequal{\mathcal{Grouped}} \dfrac{\overline{\chi_1} \cdot f_1 + \cdots + \overline{\chi_n} \cdot f_n}{n} = \dfrac{1}{n} \sum_{i = 1}^n \overline{\chi_i} \cdot f_i \\
> \end{alignedat}
> $$
>

> ### 样本方差

> $$
> \begin{alignedat}{3}
>             & \sum_{i = 1}^n (\chi_i - \overline{\chi})^2 = \sum_{i = 1}^n \chi_i^2 - n \cdot \overline{\chi}^2 \\
>         s^2 &\xlongequal{\mathcal{Ungrouped}} \dfrac{1}{n} \sum_{i = 1}^n (\chi_i - \overline{\chi})^2 = \dfrac{1}{n} \sum_{i = 1}^n \chi_i^2 - \overline{\chi}^2 \\
>         s^2 &\xlongequal{\mathcal{Grouped}} \dfrac{1}{n} \sum_{i = 1}^n (\overline{\chi_i} - \overline{\chi})^2 \cdot f_i = \dfrac{1}{n} \sum_{i = 1}^n \overline{\chi_i}^2 \cdot f_i - \overline{\chi}^2 \\
> \tilde{s}^2 &\xlongequal{\mathcal{Ungrouped}} \dfrac{1}{n - 1} \sum_{i = 1}^n (\chi_i - \overline{\chi})^2 = \dfrac{1}{n - 1} \left[ \sum_{ i = 1}^n \chi_i^2 - n \cdot \overline{\chi}^2 \right] \\
> \tilde{s}^2 &\xlongequal{\mathcal{Grouped}} \dfrac{1}{n - 1} \sum_{i = 1}^n (\overline{\chi_i} - \overline{\chi})^2 \cdot f_i = \dfrac{1}{n - 1} \left[ \sum_{i = 1}^n \overline{\chi_i}^2 \cdot f_i - n \cdot \overline{\chi}^2 \right] \\
> \end{alignedat}
> $$
>

> ### 样本期望

> $$
> \begin{alignedat}{3}
>                 \mathrm{Exp} [X] &= \mu \\
>                 \mathrm{Var} [X] &= \sigma^2 \\
>   \mathrm{Exp} [\overline{\chi}] &= \mathrm{Exp} \left[ \dfrac{1}{n} \sum_{i = 1}^n \chi_i \right] \\
>                                  &= \mu \\
>   \mathrm{Var} [\overline{\chi}] &= \mathrm{Var} \left[ \dfrac{1}{n} \sum_{i = 1}^n \chi_i \right] \\
>                                  &= \dfrac{\sigma^2}{n} \\
>                  \overline{\chi} &\sim \mathrm{No} \left( \mu, \dfrac{\sigma^2}{n} \right) \\
>          \mathrm{Exp} [\chi_i]^2 &= \mathrm{Var} [\chi_i] + \mathrm{Exp}^2 [\chi_i] \\
>                                  &= \sigma^2 + \mu^2 \\
> \mathrm{Exp} [\overline{\chi}]^2 &= \mathrm{Var} [\overline{\chi}] + \mathrm{Exp}^2 [\overline{\chi}] \\
>                                  &= \dfrac{\sigma^2}{n} + \mu^2 \\
>       \mathrm{Exp} [\tilde{s}^2] &= \mathrm{Exp} \left[ \dfrac{\sum_1^n (\chi_n - \overline{\chi})^2}{n - 1} \right] \\
>                                  &= \dfrac{1}{n - 1} \mathrm{Exp} \left[ \sum_{i = 1}^n \chi_i^2 - n \cdot \overline{\chi}^2 \right] \\
>                                  &= \dfrac{1}{n - 1} \left[ \sum_{i = 1}^n \mathrm{Exp} [\chi_i]^2 - n \cdot \mathrm{Exp} [\overline{\chi}]^2 \right] \\
>                                  &= \dfrac{1}{n - 1} \left[ n \cdot (\sigma^2 + \mu^2) - n \cdot \left( \dfrac{\sigma^2}{n} + \mu^2 \right) \right] \\
>                                  &= \sigma^2 \\
> \end{alignedat}
> $$
>

> ### 样本偏度 $\mathrm{Skew_{ness}}$

> $$
> \begin{alignedat}{3}
> \mathrm{Skew} &\xlongequal{\mathcal{Ungrouped}} \dfrac{\dfrac{1}{n} \sum\limits_{i = 1}^n (\chi_i - \overline{\chi})^3}{\left[ \dfrac{1}{n} \sum\limits_{i = 1}^n (\chi_i - \overline{\chi})^2 \right]^\frac{3}{2}} \\
> \mathrm{Skew} &\xlongequal{\mathcal{Grouped}} \dfrac{\dfrac{1}{n} \sum\limits_{i = 1}^n (\overline{\chi_i} - \overline{\chi})^3 \cdot f_i}{\left[ \dfrac{1}{n} \sum\limits_{i = 1}^n (\overline{\chi_i} - \overline{\chi})^2 \cdot f_i \right]^\frac{3}{2}}
> \end{alignedat}
> $$
>

> ### 样本峰度 $\mathrm{Kurt_{osis}}$

> $$
> \begin{alignedat}{3}
> \mathrm{Kurt} &\xlongequal{\mathcal{Ungrouped}} \dfrac{\dfrac{1}{n} \sum\limits_{i = 1}^n (\chi_i - \overline{\chi})^4}{\left[ \dfrac{1}{n} \sum\limits_{i = 1}^n (\chi_i - \overline{\chi})^2 \right]^2} - 3 \\
> \mathrm{Kurt} &\xlongequal{\mathcal{Grouped}} \dfrac{\dfrac{1}{n} \sum\limits_{i = 1}^n (\overline{\chi_i} - \overline{\chi})^4 \cdot f_i}{\left[ \dfrac{1}{n} \sum\limits_{i = 1}^n (\overline{\chi_i} - \overline{\chi})^2 \cdot f_i \right]^2} - 3 \\
> \end{alignedat}
> $$
>