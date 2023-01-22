import javax.swing.*;

public class Java_Method_Reference {
    @FunctionalInterface
    interface Converter {
        public Integer _Convert(String from);
    }

    @FunctionalInterface
    interface Extracter {
        public String _Extract(String str, int beg, int end);
    }

    @FunctionalInterface
    interface Maker {
        public JFrame _Make(String title);
    }

    public static void main(String[] args) {
        Converter converter_0 = (from) -> Integer.valueOf(from);
        System.out.println(converter_0._Convert("123"));

        Converter converter_1 = Integer::valueOf;
        System.out.println(converter_1._Convert("456"));

        Converter converter_2 = (from) -> "bss9395.github.com".indexOf(from);
        System.out.println(converter_2._Convert("git"));

        Converter converter_3 = "bss9395.github.com"::indexOf;
        System.out.println(converter_3._Convert("hub"));

        Extracter extracter_0 = (str, beg, end) -> str.substring(beg, end);
        System.out.println(extracter_0._Extract("bss9395.github.com", 8, 14));

        Extracter extracter_1 = String::substring;
        System.out.println(extracter_1._Extract("bss9395.github.com", 8, 14));

        Maker maker_0 = (title) -> new JFrame(title);
        JFrame frame_0 = maker_0._Make("新建窗口");
        System.out.println(frame_0);

        Maker maker_1 = JFrame::new;
        JFrame frame_1 = maker_1._Make("新建窗口");
        System.out.println(frame_1);
    }
}
