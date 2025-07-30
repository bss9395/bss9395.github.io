/* Java_Singleton.java
Author: bss9395
Update: 2025-07-29T16:01:00+08@China-GuangDong-ZhanJiang+08
*/

class Color {
    private static Color _red = new Color("红色");
    private static Color _green = new Color("绿色");
    private static Color _blue = new Color("蓝色");
    public static Color _Instance(String color) {
        switch(color) {
            case "red":
                return _red;
            case "green":
                return _green;
            case "blue":
                return _blue;
        }
        return null;
    }

    private String _type = null;
    private Color(String type) {
        _type = type;
    }
    public String toString() {
        return _type;
    }
}

public class Java_Multiton {
    public static void main(String[] args) {
        Color color = Color._Instance("green");
        System.out.println(color);
    }
}
