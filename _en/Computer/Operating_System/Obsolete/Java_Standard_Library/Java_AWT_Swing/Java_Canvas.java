/* Java_Canvas.java
Author: BSS9395
Update: 2023-05-02T22:45:00+08@China-Guangdong-Zhanjiang+08
Design: Java Standard Library: Canvas
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Random;

public class Java_Canvas {
    static class Board extends Canvas {
        static public String _shape_rectangle = "rectangle";
        static public String _shape_oval      = "oval";
        public String _shape = "";
        public Board() {
            this.setPreferredSize(new Dimension(250, 180));
        }
        public void _Paint(String shape) {
            _shape = shape;
            this.repaint();
        }

        @Override
        public void paint(Graphics graphics) {
            Random random = new Random();
            if(_shape.equals(_shape_rectangle)) {
                int width = 40;
                int height = 40;
                graphics.setColor(new Color(220, 100, 80));
                graphics.drawRect(random.nextInt(this.getWidth() - width), random.nextInt(this.getHeight() - height), width, height);
            } else if(_shape.equals(_shape_oval)) {
                int width = 50;
                int height = 40;
                graphics.setColor(new Color(80, 100, 200));
                graphics.fillOval(random.nextInt(this.getWidth() - width), random.nextInt(this.getHeight() - height), width, height);
            }
        }
    }

    public Frame  _f_frame     = new Frame("简单绘图");
    public Board  _board       = new Board();
    public Button _b_rectangle = new Button("绘制矩形");
    public Button _b_oval      = new Button("绘制椭圆形");
    public Java_Canvas() {
        Box b_center = Box.createVerticalBox();
        b_center.add(_board);
        Box b_button = Box.createHorizontalBox();
        b_button.add(_b_rectangle);
        b_button.add(_b_oval);
        b_center.add(b_button);
        _f_frame.add(b_center);
        _f_frame.pack();
        _f_frame.setVisible(true);

        _f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                System.exit(0);
            }
        });
        _b_rectangle.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                _board._Paint(Board._shape_rectangle);
            }
        });
        _b_oval.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                _board._Paint(Board._shape_oval);
            }
        });
    }
    static public void main(String[] args) {
        new Java_Canvas();
    }
}
