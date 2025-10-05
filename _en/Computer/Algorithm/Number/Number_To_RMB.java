/* Number_To_RMB.java
Author: BSS9395
Update: 2022-12-26T22:30:00+08@China-Shanghai+08
Design: Number to RMB
*/

public class RMB {
    public static String[] _han = {
        "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"
    };
    public static String[] _integer_unit = {
        "", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿", "拾", "佰", "仟"
    };
    public static String[] _fraction_unit = {
        "角", "分"
    };

    public static void main(String[] args) {
        double number = 300000010.015;
        System.out.println(_Number_To_RMB(number));
    }

    public static String _Number_To_RMB(double number) {
        int integer_ = (int)number;
        int fraction_ = (int)((number - (int)number) * 100 + 0.5);
        String integer = String.format("%d", integer_);
        String fraction = String.format("%02d", fraction_);
        System.out.printf("%s.%s %n", integer, fraction);

        StringBuilder rmb = new StringBuilder();
        int zero = 0;
        int leng = integer.length();
        for(int i = 0; i < leng; i += 1) {
            int inte = (int)(integer.charAt(i) - '0');
            if(inte != 0) {
                rmb.append(0 < zero ? RMB._han[0] : "");
                rmb.append(RMB._han[inte] + RMB._integer_unit[leng - 1 - i]);
                zero = 0;
            } else {
                zero += 1;
                if ((leng - 1 - i) % 4 == 0 && zero < 4) {
                    rmb.append(RMB._integer_unit[leng - 1 - i]);
                }
            }
        }

        rmb.append("元");
        if (fraction_ == 0) {
            rmb.append("整");
            return rmb.toString();
        }

        zero = 0;
        leng = fraction.length();
        for(int i = 0; i < leng; i += 1) {
            int frac = (int)(fraction.charAt(i) - '0');
            if (frac != 0) {
                rmb.append(0 < zero ? RMB._han[0] : "");
                rmb.append(RMB._han[frac] + RMB._fraction_unit[i]);
                zero = 0;
            } else {
                zero += 1;
            }
        }

        return rmb.toString();
    }
}
