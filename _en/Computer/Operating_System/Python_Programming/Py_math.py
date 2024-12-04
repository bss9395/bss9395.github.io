## Py_math.py
# Author: BSS9395
# Update: 2024-11-07T12:42:00+08@China-Guangdong-Zhanjiang+08

# python内置数学类函数库math，math库不支持复数类型。
import math

# 4个数学常数
def func_mathematical_constant():
    pi  = math.pi
    e   = math.e
    inf = math.inf
    nan = math.nan
    print(" pi  = ", pi)
    print(" e   = ", e )
    print(" inf = ", inf)
    print(" nan = ", nan)
    print("-inf = ", -inf)

# 16个数值函数
def func_numerical():
    a = math.fabs(-2.3)                               # |x|              # 返回x的绝对值
    b = math.fmod(4.5, 2.3)                           # x % y            # 返回x与y的模
    c = math.fsum([1.2, 2.3, 3.4, 4.5])               # x+y+...          # 浮点数精确求和
    d = math.ceil(-2.3)                               # ⌈x⌉              # 向上取整，返回不小于x的最小整数
    e = math.floor(-2.3)                              # ⌊x⌋              # 向下取整，返回不小于x的最大整数
    f = math.factorial(4)                             # x!               # 返回x的阶乘，如果x是小数或负数，返回ValueError
    g = math.gcd(20, 16)                              # GCD(x, y)        # 返回a与b的最大公约数
    h = math.frexp(4)                                 # x == m * 2^n     # 返回(m, n)，当x = 0时返回(0.0, 0)
    i = math.ldexp(2, 3)                              # x * 2^y          # 返回x * 2^y运算值，math.frexp(x)函数的反运算
    j, k = math.modf(-2.3)                                               # 返回x的小数和整数部分
    l = math.trunc(-2.3)                                                 # 返回x的整数部分
    m = math.copysign(-2.3, -3.4)                     # |x| * |y| / y    # 用数值y的正负号替换数值x的正负号
    n = math.isclose(2.31111111111, 2.31111111112)                       # 比较a和b的相似性，返回True或False
    o = math.isfinite(math.nan)                                          # 当x为无穷大，返回True，否则返回False
    p = math.isinf(math.nan)                                             # 当x为整数或负数无穷大，返回True，否则返回False
    q = math.isnan(math.inf)                                             # 当x是nan，返回True，否则返回False
    print(f"a = {a}")
    print(f"b = {b}")
    print(f"c = {c}")
    print(f"d = {d}")
    print(f"e = {e}")
    print(f"f = {f}")
    print(f"g = {g}")
    print(f"h = {h}")
    print(f"i = {i}")
    print(f"j = {j}, k = {k}")
    print(f"l = {l}")
    print(f"m = {m}")
    print(f"n = {n}")
    print(f"o = {o}")
    print(f"p = {p}")
    print(f"q = {q}")

# 16个幂对数函数
def func_logarithmic():
    a = math.pow(2, 3)      # x^y          # 返回x的y次幂
    b = math.exp(2)         # e^x          # 返回e的x次幂，e是自然对数
    c = math.expm1(2)       # e^x - 1      # 返回e的x次幂减1
    d = math.sqrt(5)        # √x          # 返回x的平方根
    e = math.log(10, 10)    # log_x(y)     # 返回x的对数值，只输入x时，返回自然对数ln(x)
    f = math.log1p(1.7)     # ln(1 + x)    # 返回1+x的自然对数值
    g = math.log2(2)        # log_2(x)     # 返回x的2对数值
    h = math.log10(10)      # log_10(x)    # 返回x的10对数值
    print(f"a = {a}")
    print(f"b = {b}")
    print(f"c = {c}")
    print(f"d = {d}")
    print(f"e = {e}")
    print(f"f = {f}")
    print(f"g = {g}")
    print(f"h = {h}")

# 16个三角函数
def func_trigonometric():
    a = math.degrees(math.pi)                        # 角度x的弧度值转角度值
    b = math.radians(90)                             # 弧度x的角度值转弧度值
    c = math.hypot(3, 4)         # √（x^x + y^y)    # 返回(x, y)坐标到原点(0, 0)的距离
    d = math.sin(math.pi / 2)    # sin(x)            # 返回x的正弦函数值，x是弧度值
    e = math.cos(0)              # cos(x)            # 返回x的余弦函数值，x是弧度值
    f = math.tan(math.pi / 4)    # tan(x)            # 返回x的正切函数值，x是弧度值
    g = math.asin(1)             # arcsin(x)         # 返回x的反正弦函数值
    h = math.acos(0)             # arccos(x)         # 返回x的反余弦函数值
    i = math.atan(1)             # arctan(x)         # 返回x的反正切函数值
    j = math.atan2(2, 2)         # arctan(x/y)       # 返回x/y的反正切函数值
    k = math.sinh(0)             # sinh(x)           # 返回x的双曲正弦函数值
    l = math.cosh(0)             # cosh(x)           # 返回x的双曲余弦函数值
    m = math.tanh(0)             # tanh(x)           # 返回x的双曲正切函数值
    n = math.asinh(0)            # arcsinh(x)        # 返回x的反双曲正弦函数值
    o = math.acosh(1)            # arccosh(x)        # 返回x的反双曲余弦函数值
    p = math.atanh(0)            # arctanh(x)        # 返回x的反双曲正切函数值
    print(f"a = {a}")
    print(f"b = {b}")
    print(f"c = {c}")
    print(f"d = {d}")
    print(f"e = {e}")
    print(f"f = {f}")
    print(f"g = {g}")
    print(f"h = {h}")
    print(f"i = {i}")
    print(f"j = {j}")
    print(f"k = {k}")
    print(f"l = {l}")
    print(f"m = {m}")
    print(f"n = {n}")
    print(f"o = {o}")
    print(f"p = {p}")

# 4个特殊函数
def func_special():
    a = math.erf(1)       # \dfrac{2}{\sqrt{pi}} \int_0^x e^{-t^2} \mathrm{d} t         # 高斯误差函数，应用于概率论、统计学等领域
    b = math.erfc(1)      # \dfrac{2}{\sqrt{pi}} \int_x^{\inf} e^{-t^2} \mathrm{d} t    # 余补高斯误差函数，math.erfc(x) = 1 - math.erf(x)
    c = math.gamma(1)     # \int_0^\inf x^{t - 1} e^{-x} \mathrm{d} x                   # 伽玛函数，欧拉第二积分函数
    d = math.lgamma(1)    # ln(gamma(x))                                                # 伽玛函数的自然对数
    print(f"a = {a}")
    print(f"b = {b}")
    print(f"c = {c}")
    print(f"d = {d}")

if __name__ == "__main__":
    # func_mathematical_constant()
    # func_numerical()
    # func_logarithmic()
    # func_trigonometric()
    func_special()
