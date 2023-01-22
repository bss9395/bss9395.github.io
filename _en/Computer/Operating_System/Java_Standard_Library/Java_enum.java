import java.awt.desktop.OpenFilesEvent;

public class Java_enum {
    enum Season {
        _spring("Spring"), _summer, _fall, _winter;

        private final String _name;
        private Season() {
            _name = "";
        }
        private Season(String name) {
            _name = name;
        }

        public String toString() {
            switch(this) {
                case _spring:
                    return "春天";
                case _summer:
                    return "夏天";
                case _fall:
                    return "秋天";
                case _winter:
                    return "冬天";
            }
            return "";
        }
    }

    enum Operation {
        _plus {
            public double _Evaluate(double lhs, double rhs) {
                return lhs + rhs;
            }
        },
        _minus {
            public double _Evaluate(double lhs, double rhs) {
                return lhs - rhs;
            }
        },
        _times {
            public double _Evaluate(double lhs, double rhs) {
                return lhs * rhs;
            }
        },
        _divide {
            public double _Evaluate(double lhs, double rhs) {
                return lhs / rhs;
            }
        };
        abstract public double _Evaluate(double lhs, double rhs);
    }

    public static void main(String[] args) {
        for (var season : Season.values()) {
            System.out.println(season);
        }

        Season summer = Enum.valueOf(Season.class, "_summer");
        System.out.println(summer);

        Season fall = Season.valueOf("_fall");
        System.out.println(fall);

        ////////////////////////////////

        System.out.println(Operation._plus._Evaluate(2, 3));
        System.out.println(Operation._minus._Evaluate(2, 3));
        System.out.println(Operation._times._Evaluate(2, 3));
        System.out.println(Operation._divide._Evaluate(2, 3));
    }
}
