/* Java_Listener.java
Author: BSS9395
Update: 2023-02-05T18:35:00+08@China-Shanghai+08
Design: Java Listener
*/

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import java.lang.reflect.Field;

public class Java_Listener {
    @Retention(RetentionPolicy.RUNTIME)
    @Target(ElementType.FIELD)
    static public @interface Custom_Listener {
        Class<? extends ActionListener> _Listener();
    }

    static public class Listener_Installer {
        static public void _Process_Annotations(Object object) {
            try {
                for(Field field : object.getClass().getDeclaredFields()) {
                    field.setAccessible(true);
                    Custom_Listener listener = field.getAnnotation(Custom_Listener.class);
                    Object value = field.get(object);
                    if(listener != null && value != null && value instanceof AbstractButton) {
                        ActionListener actionListener = listener._Listener().getDeclaredConstructor().newInstance();
                        ((AbstractButton) value).addActionListener(actionListener);
                    }
                }
            } catch(Exception exception) {
                exception.printStackTrace();
            }
        }
    }

    ////////////////////////////////////

    static public class With_Annotation {
        static class Ok_Listener implements ActionListener {
            public void actionPerformed(ActionEvent event) {
                JOptionPane.showMessageDialog(null, "单击确认按钮");
            }
        }
        static class Cancel_Listener implements ActionListener {
            public void actionPerformed(ActionEvent event) {
                JOptionPane.showMessageDialog(null, "单击取消按钮");
            }
        }

        private JFrame _main = new JFrame("使用注解绑定事件监听器");
        @Custom_Listener(_Listener = Ok_Listener.class)
        private JButton _ok = new JButton("确定");
        @Custom_Listener(_Listener = Cancel_Listener.class)
        private JButton _cancel = new JButton("取消");

        public void _Initialize() {
            JPanel panel = new JPanel();
            panel.add(_ok);
            panel.add(_cancel);
            _main.add(panel);
            _main.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            _main.pack();
            _main.setVisible(true);
            Listener_Installer._Process_Annotations(this);
        }
        public With_Annotation() {
            super();
            _Initialize();
        }
    }

    static public void main(String[] args) {
        new With_Annotation();
    }
}
