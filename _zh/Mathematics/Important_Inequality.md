---
layout:  zh_post
Topic :  收敛极限
Title :  重要不等式
Update:  2021-02-26T18:55:00+08@中国-广东-湛江+08
Author:  璀璨星辰
Link  :
---

### 幂函数不等式

$x^p \mathop{≤}\limits_{0≤x}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} p · x + q$

$x^p \mathop{≥}\limits_{0≤x}^{\left|p-\frac{1}{2}\right|>\frac{1}{2}} p · x + q$

| $p + q = 1$                                      | $\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} = p · (x^{p-1} - 1)$ | $f (x) = x^{p} - p · x + p - 1$                              | $0 ≤ x$               |                     | $x=1$                 |
| :----------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :-------------------- | :------------------ | :-------------------- |
| $\left| p - \dfrac{1}{2} \right| < \dfrac{1}{2}$ | $\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} = \mathop{0^+}\limits_{0<x<1};\mathop{0}\limits_{x=1};\mathop{0^-}\limits_{1<x}$ | $f (x) = \mathop{0^-}\limits_{0<x<1};\mathop{0}\limits_{x=1};\mathop{0^-}\limits_{1<x}$ | $x^p ≤ p · x + 1 - p$ | $x^{p} ≤ p · x + q$ | $x^{p} = p · x + q$   |
| $\left| p - \dfrac{1}{2} \right| > \dfrac{1}{2}$ | $\dfrac{\mathrm{d} f (x)}{\mathrm{d} x} = \mathop{0^-}\limits_{0<x<1};\mathop{0}\limits_{x=1};\mathop{0^+}\limits_{1<x}$ | $f (x) = \mathop{0^+}\limits_{0<x<1};\mathop{0}\limits_{x=1};\mathop{0^+}\limits_{1<x}$ | $x^p ≥ p · x + 1 - p$ | $x^{p} ≥ p · x + q$ | $[p < 0] ⇒ [ 0 < x ]$ |

### 互补项不等式

$x · y \mathop{≤}\limits_{0≤x,0≤y}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} p · x^{\frac{1}{p}} + q · y^{\frac{1}{q}}$

$x · y \mathop{≥}\limits_{0≤x,0≤y}^{\left|p-\frac{1}{2}\right|>\frac{1}{2}} p · x^{\frac{1}{p}} + q · y^{\frac{1}{q}}$

| $p + q = 1$                                      | $t ≡ \dfrac{u}{v}$                                       | $0 ≤ u, 0 ≤ v$                  | $x ≡ u^{p}, y ≡v^q$                                 | $u = x^{\frac{1}{p}} ≡ y^{\frac{1}{q}} = v$         |
| :----------------------------------------------- | :------------------------------------------------------- | :------------------------------ | --------------------------------------------------- | :-------------------------------------------------- |
| $\left| p - \dfrac{1}{2} \right| < \dfrac{1}{2}$ | $\left[ \dfrac{u}{v} \right]^{p} ≤ p · \dfrac{u}{v} + q$ | $u^{p} · v^{q} ≤ p · u + q · v$ | $x · y ≤ p · x^{\frac{1}{p}} + q · y^{\frac{1}{q}}$ | $x · y = p · x^{\frac{1}{p}} + q · y^{\frac{1}{q}}$ |
| $\left| p - \dfrac{1}{2} \right| > \dfrac{1}{2}$ | $\left[ \dfrac{u}{v} \right]^p ≥ p · \dfrac{u}{v} + q$   | $u^{p} · v^{q} ≥ p · u + q · v$ | $x · y ≥ p · x^{\frac{1}{p}} + q · y^{\frac{1}{q}}$ | $[p < 0] ⇒ [ 0 < x · y ]$                           |

### 向量积不等式

$\sum\limits_{i=0}^{n} x_i · y_i \mathop{≤}\limits_{0≤x_i,0≤y_i}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} · \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}$

$\sum\limits_{i=0}^{n} x_i · y_i \mathop{≥}\limits_{0≤x_i,0≤y_i}^{\left|p-\frac{1}{2}\right|>\frac{1}{2}} \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} · \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}$

| $p + q = 1$                                      | $u_i ≡ \dfrac{x_i}{\left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p}}, v_i ≡ \dfrac{y_i}{\left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}}$ | $0 ≤ x_i, 0 ≤ y_i$                                           | $x_i^{\frac{1}{p}} ≡ λ · y_i^{\frac{1}{q}}$                  |
| :----------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\left| p - \dfrac{1}{2} \right| < \dfrac{1}{2}$ | $\sum\limits_{i=0}^{n} \dfrac{x_i}{\left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p}} · \dfrac{y_i}{\left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}} ≤ p · \sum\limits_{i=0}^{n} \dfrac{x_i^{\frac{1}{p}}}{\sum\limits_{i=0}^{n} x_i^{\frac{1}{p}}} + q · \sum\limits_{i=0}^{n} \dfrac{y_i^{\frac{1}{q}}}{\sum\limits_{i=0}^{n} y_i^{\frac{1}{q}}} = 1$ | $\sum\limits_{i=0}^{n} x_i · y_i ≤ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} · \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}$ | $\sum\limits_{i=0}^{n} x_i · y_i = \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} · \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}$ |
| $\left| p - \dfrac{1}{2} \right| > \dfrac{1}{2}$ | $\sum\limits_{i=0}^{n} \dfrac{x_i}{\left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p}} · \dfrac{y_i}{\left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}} ≥ p · \sum\limits_{i=0}^{n} \dfrac{x_i^{\frac{1}{p}}}{\sum\limits_{i=0}^{n} x_i^{\frac{1}{p}}} + q · \sum\limits_{i=0}^{n} \dfrac{y_i^{\frac{1}{q}}}{\sum\limits_{i=0}^{n} y_i^{\frac{1}{q}}} = 1$ | $\sum\limits_{i=0}^{n} x_i · y_i ≥ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} · \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}$ | $[p < 0] ⇒ [ 0 < x_i · y_i ]$                                |

### 拓扑距不等式

$\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p} \mathop{≤}\limits_{0≤x_i,0≤y_i}^{\left|p- \frac{1}{2}\right|<\frac{1}{2}} \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p}$

$\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p} \mathop{≥}\limits_{0≤x_i,0≤y_i}^{\left|p-\frac{1}{2}\right|<\frac{1}{2}} \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p}$

| $⇓$  | $\dfrac{1}{p} + \dfrac{1}{q} = \dfrac{1}{p · q}$             | $⇒$  | $\sum\limits_{i=0}^{m} (x_{i} + y_{i})^{\frac{1}{p}} = \sum\limits_{i=0}^{m} x_{i} · (x_{i} + y_{i})^{\frac{1}{p} - 1} + \sum\limits_{i=0}^{m} y_{i} · (x_{i} + y_{i})^{\frac{1}{p} - 1}$ |
| :--: | :----------------------------------------------------------- | :--: | :----------------------------------------------------------- |
| $⇓$  | $\left| p - \dfrac{1}{2} \right| < \dfrac{1}{2}$             | $⇒$  | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p + q} ≤ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} · \left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{(\frac{1}{p} - 1) · \frac{1}{q}} \right]^{q} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p} · \left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{(\frac{1}{p} - 1) · \frac{1}{q}} \right]^{q}$ |
| $⇓$  | $\left( \dfrac{1}{p} - 1 \right) · \dfrac{1}{q} = \dfrac{1}{p}$ | $⇒$  | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^p ≤ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{q}} \right]^{q}$ |

| $p + q = 1$                                      | $(x_{i} + y_{i})^{\frac{1}{p}} = x_{i} · (x_{i} + y_{i})^{\frac{1}{p} - 1} + y_{i} · (x_{i} + y_{i})^{\frac{1}{p} - 1}$ | $x_i ≡ λ · y_i$                                              |
| :----------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| $\left| p - \dfrac{1}{2} \right| < \dfrac{1}{2}$ | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p} ≤ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p}$ | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p} = \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p}$ |
| $\left| p - \dfrac{1}{2} \right| > \dfrac{1}{2}$ | $\left[ \sum\limits_{i=0}^{n} (x_i + y_i)^{\frac{1}{p}} \right]^{p} ≥ \left[ \sum\limits_{i=0}^{n} x_i^{\frac{1}{p}} \right]^{p} + \left[ \sum\limits_{i=0}^{n} y_i^{\frac{1}{p}} \right]^{p}$ | $[p < 0] ⇒ [ 0 < x_i · y_i ]$                                |

