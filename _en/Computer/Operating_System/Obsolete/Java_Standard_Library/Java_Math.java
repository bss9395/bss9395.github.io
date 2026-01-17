/* Java_Math.java
Author: BSS9395
Update: 2023-01-11T22:30:00+08@China-Shanghai+08
Design: Java Standard Library: Math
*/

public class Java_Math {
    static public void main(String[] args) {
        // _toRadians_toDegrees();
        // _sin_cos_tan_asin_acos_atan_sinh_cosh_tanh();
        // _ceil_floor_round();
        // _sqrt_cbrt();
        // _exp_pow_log_log10();
        // _abs_signum();
        // _min_max();
        // _nextDown_nextUp();
        _random();
    }
    static public void _toRadians_toDegrees() {
        System.out.println(Math.toRadians(90));
        System.out.println(Math.toDegrees(Math.PI));
    }
    static public void _sin_cos_tan_asin_acos_atan_sinh_cosh_tanh() {
        System.out.println(Math.sin(Math.PI / 2));
        System.out.println(Math.cos(Math.PI));
        System.out.println(Math.tan(Math.PI / 4));

        System.out.println(Math.asin(1));
        System.out.println(Math.acos(1));
        System.out.println(Math.atan(1));

        System.out.println(Math.sinh(1));
        System.out.println(Math.cosh(1));
        System.out.println(Math.tanh(1));
    }
    static public void _ceil_floor_round() {
        System.out.println(Math.ceil(1.5));
        System.out.println(Math.floor(1.5));
        System.out.println(Math.round(1.5));
    }
    static public void _sqrt_cbrt() {
        System.out.println(Math.sqrt(4));
        System.out.println(Math.hypot(3, 4));
        System.out.println(Math.cbrt(27));
    }
    static public void _exp_pow_log_log10() {
        System.out.println(Math.exp(1));
        System.out.println(Math.pow(3, 2));
        System.out.println(Math.log(Math.E));
        System.out.println(Math.log10(10));
    }
    static public void _abs_signum() {
        System.out.println(Math.abs(-4.5));
        System.out.println(Math.signum(-4.5));
    }
    static public void _min_max() {
        System.out.println(Math.min(1.2, 3.4));
        System.out.println(Math.max(2.3, 4.5));
    }
    static public void _nextDown_nextUp() {
        System.out.println(Math.nextDown(1.5));
        System.out.println(Math.nextUp(1.5));
    }
    static public void _random() {
        System.out.println(Math.random());
    }
}
