---
layout:    zh_post
Topic:     概率统计
Title:     统计量
Revised:   2018-06-08 23:03:00 +08 @ 中国-新疆-乌鲁木齐 +06
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
>         s^2 &\xlongequal{\mathcal{Ungrouped}} \dfrac{1}{n} \sum_{i = 1}^n (\chi_i - \overline{\chi})^2 \\
>         s^2 &\xlongequal{\mathcal{Grouped}} \dfrac{1}{n} \sum_{i = 1}^n (\overline{\chi_i} - \overline{\chi})^2 \cdot f_i \\
> \tilde{s}^2 &\xlongequal{\mathcal{Ungrouped}} \dfrac{1}{n - 1} \sum_{i = 1}^n (\chi_i - \overline{\chi})^2 = \dfrac{1}{n - 1} \left[ \sum_{ i = 1}^n \chi_i^2 - n \cdot \overline{\chi} \right] \\
> \tilde{s}^2 &\xlongequal{\mathcal{Grouped}} \dfrac{1}{n - 1} \sum_{i = 1}^n (\overline{\chi_i} - \overline{\chi})^2 \cdot f_i = \dfrac{1}{n - 1} \left[ \sum_{i = 1}^n \overline{\chi_i}^2 \cdot f_i - n \cdot \overline{\chi} \right] \\
> \end{alignedat}
> $$
>

> ### 样本期望

> $$
> \begin{alignedat}{3}
> \mathrm{Exp} [\overline{\chi}] &= \mathrm{Exp} \left[ \dfrac{1}{n} \sum_{i = 1}^n \chi_i \right] = \overline{\chi} \\
> \mathrm{Var} [\overline{\chi}] &= \mathrm{Var} \left[ \dfrac{1}{n} \sum_{i = 1}^n \chi_i \right] = \dfrac{s^2}{n} = \dfrac{n - 1}{n^2} \tilde{s}^2 \\
>                \overline{\chi} &\sim  \mathrm{No} \left( \overline{\chi}, \dfrac{s^2}{n} \right) \\
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