---
layout:    zh_post
Topic:     概率统计
Title:     统计量
Revised:   2018-06-08 23:03:00 +08 @ 中国-新疆-乌鲁木齐 +06
Authors:   璀璨星辰
Resources:
---

> ### 统计量 $S_{tatistic}$

> $$
> \begin{alignedat}{3}
> S &= S [x_1, \cdots, x_n] \quad\Leftarrow\quad p (x_1, \cdots, x_n) = p_{x_1} (x_1) \cdots p_{x_n} (x_n) \\
> \end{alignedat}
> $$
>

> ### 样本均值

> $$
> \begin{alignedat}{3}
> \overline{x} &\xlongequal{\mathcal{Ungrouped}} \dfrac{x_1 + \cdots + x_n}{n} = \dfrac{1}{n} \sum_{i = 1}^n x_i \\
> \overline{x} &\xlongequal{\mathcal{Grouped}} \dfrac{\overline{x_1} \cdot f_1 + \cdots + \overline{x_n} \cdot f_n}{n} = \dfrac{1}{n} \sum_{i = 1}^n \overline{x_i} \cdot f_i \\
> \overline{x} &\sim  \mathrm{No} \left( \mu, \dfrac{\sigma^2}{n} \right) \\
> \end{alignedat}
> $$
>

> ### 样本方差

> $$
> \begin{alignedat}{3}
>         s^2 &\xlongequal{\mathcal{Ungrouped}} \dfrac{1}{n} \sum_{i = 1}^n (x_i - \overline{x})^2 \\
>         s^2 &\xlongequal{\mathcal{Grouped}} \dfrac{1}{n} \sum_{i = 1}^n (\overline{x_i} - \overline{x})^2 \cdot f_i \\
> \tilde{s}^2 &\xlongequal{\mathcal{Ungrouped}} \dfrac{1}{n - 1} \sum_{i = 1}^n (x_i - \overline{x})^2 = \dfrac{1}{n - 1} \left[ \sum_{ i = 1}^n x_i^2 - n \cdot \overline{x} \right] \\
> \tilde{s}^2 &\xlongequal{\mathcal{Grouped}} \dfrac{1}{n - 1} \sum_{i = 1}^n (\overline{x_i} - \overline{x})^2 \cdot f_i = \dfrac{1}{n - 1} \left[ \sum_{i = 1}^n \overline{x_i}^2 \cdot f_i - n \cdot \overline{x} \right] \\
> \end{alignedat}
> $$
>

> ### 样本期望

> $$
> \begin{alignedat}{3}
> \mathrm{Exp} [\overline{x}] &= \mathrm{Exp} \left[ \dfrac{1}{n} \sum_{i = 1}^n x_i \right] = \overline{x} \\
> \mathrm{Var} [\overline{x}] &= \mathrm{Var} \left[ \dfrac{1}{n} \sum_{i = 1}^n x_i \right] = \dfrac{s^2}{n} = \dfrac{n - 1}{n^2} \tilde{s}^2 \\
> \end{alignedat}
> $$
>

> ### 样本偏度 $\mathrm{Skew_{ness}}$

> $$
> \begin{alignedat}{3}
> \mathrm{Skew} &\xlongequal{\mathcal{Ungrouped}} \dfrac{\dfrac{1}{n} \sum\limits_{i = 1}^n (x_i - \overline{x})^3}{\left[ \dfrac{1}{n} \sum\limits_{i = 1}^n (x_i - \overline{x})^2 \right]^\frac{3}{2}} \\
> \mathrm{Skew} &\xlongequal{\mathcal{Grouped}} \dfrac{\dfrac{1}{n} \sum\limits_{i = 1}^n (\overline{x_i} - \overline{x})^3 \cdot f_i}{\left[ \dfrac{1}{n} \sum\limits_{i = 1}^n (\overline{x_i} - \overline{x})^2 \cdot f_i \right]^\frac{3}{2}}
> \end{alignedat}
> $$
>

> ### 样本峰度 $\mathrm{Kurt_{osis}}$

> $$
> \begin{alignedat}{3}
> \mathrm{Kurt} &\xlongequal{\mathcal{Ungrouped}} \dfrac{\dfrac{1}{n} \sum\limits_{i = 1}^n (x_i - \overline{x})^4}{\left[ \dfrac{1}{n} \sum\limits_{i = 1}^n (x_i - \overline{x})^2 \right]^2} - 3 \\
> \mathrm{Kurt} &\xlongequal{\mathcal{Grouped}} \dfrac{\dfrac{1}{n} \sum\limits_{i = 1}^n (\overline{x_i} - \overline{x})^4 \cdot f_i}{\left[ \dfrac{1}{n} \sum\limits_{i = 1}^n (\overline{x_i} - \overline{x})^2 \cdot f_i \right]^2} - 3 \\
> \end{alignedat}
> $$
>