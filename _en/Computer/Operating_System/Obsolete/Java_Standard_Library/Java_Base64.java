import java.util.Base64;

class Base64Util {
    private static final int _repeat = 5;
    public static String encode(String str) {
        byte[] data = str.getBytes();
        for(int x = 0; x < _repeat; x += 1) {
            data = Base64.getEncoder().encode(data);
        }
        return new String(data);
    }
    public static String decode(String str) {
        byte[] data = str.getBytes();
        for(int x = 0; x < _repeat; x += 1) {
            data = Base64.getDecoder().decode(data);
        }
        return new String(data);
    }
}

public class Java_Base64 {
    public static void main(String[] args) {
        // _Test_Base64();
        _Test_Base64Util();
    }

    public static void _Test_Base64() {
        String msg = "www.mldn.cn";

        byte[] enc = Base64.getEncoder().encode(msg.getBytes());
        System.out.println(new String(enc));

        byte[] res = Base64.getDecoder().decode(enc);
        System.out.println(new String(res));
    }

    public static void _Test_Base64Util() {
        String str = Base64Util.encode("www.mldn.cn");
        System.out.println(str);
        String out = Base64Util.decode(str);
        System.out.println(out);
    }
}
