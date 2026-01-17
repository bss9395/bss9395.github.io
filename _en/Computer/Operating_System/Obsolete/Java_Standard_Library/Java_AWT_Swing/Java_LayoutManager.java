/* Java_LayoutManager.java
Author: BSS9395
Update: 2023-03-27T16:36:00+08@China-Shanghai+08
Design: Java Standard Library: LayoutManager
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import static java.awt.BorderLayout.BEFORE_LINE_BEGINS;
import static java.awt.BorderLayout.NORTH;

public class Java_LayoutManager {
    static public void main(String[] args) {
        // _FlowLayout();
        // _BorderLayout();
        // _GridLayout();
        _GridBagLayout();
        // _CardLayout();
        // _NullLayout();
        // _BoxLayout();
        // _BoxLayout_Glue_Strut_RigidArea();
    }
    static public void _FlowLayout() {
        Frame f_frame = new Frame("Java AWT FlowLayout");
        f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        f_frame.setLayout(new FlowLayout(FlowLayout.LEFT, 20, 5));
        for(int i = 0; i < 7; i += 1) {
            f_frame.add(new Button(String.format("Button_%d", i)));
        }
        f_frame.setPreferredSize(new Dimension(200, 200));
        f_frame.pack();
        f_frame.setVisible(true);
    }
    static public void _BorderLayout() {
        Frame f_frame = new Frame("Java AWT BorderLayout");
        f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        f_frame.setLayout(new BorderLayout(0, 0));
        f_frame.add(new Button("Center"), BorderLayout.CENTER);
        Panel p_panel = new Panel();
        p_panel.add(new TextField(40));
        p_panel.add(new Button("µ¥»÷ÎÒ"));
        f_frame.add(p_panel);

        f_frame.add(new Button("North"), NORTH);
        f_frame.add(new Button("West"), BorderLayout.WEST);
        f_frame.add(new Button("South"), BorderLayout.SOUTH);
        f_frame.add(new Button("East"), BorderLayout.EAST);
        f_frame.pack();
        f_frame.setVisible(true);
    }
    static public void _GridLayout() {
        String[] digits = new String[] {
                "0", "1", "2", "3", "4",
                "5", "6", "7", "8", "9",
                ".", "+", "-", "*", "/"
        };

        Frame f_frame = new Frame("Calculator");
        f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        Panel p_panel_0 = new Panel();
        p_panel_0.add(new TextField(40));
        f_frame.add(p_panel_0, NORTH);

        Panel p_panel_1 = new Panel();
        p_panel_1.setLayout(new GridLayout(3, 5, 4, 4));
        for(int i = 0; i < digits.length; i += 1) {
            p_panel_1.add(new Button(digits[i]));
        }
        f_frame.add(p_panel_1);

        f_frame.pack();
        f_frame.setVisible(true);
    }
    static public void _GridBagLayout() {
        Frame f_frame = new Frame("Java AWT GridBagLayout");
        f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        GridBagLayout layout = new GridBagLayout();
        GridBagConstraints constraints = new GridBagConstraints();
        f_frame.setLayout(layout);

        constraints.weightx = 1;
        constraints.fill = GridBagConstraints.BOTH;
        Button b_button_0 = new Button("button_0");
        layout.setConstraints(b_button_0, constraints);
        f_frame.add(b_button_0);

        Button b_button_1 = new Button("button_1");
        layout.setConstraints(b_button_1, constraints);
        f_frame.add(b_button_1);

        Button b_button_2 = new Button("button_2");
        layout.setConstraints(b_button_2, constraints);
        f_frame.add(b_button_2);

        Button b_button_3 = new Button("button_3");
        constraints.gridwidth = GridBagConstraints.REMAINDER;
        layout.setConstraints(b_button_3, constraints);
        f_frame.add(b_button_3);

        Button b_button_4 = new Button("button_4");
        layout.setConstraints(b_button_4, constraints);
        f_frame.add(b_button_4);

        Button b_button_5 = new Button("button_5");
        constraints.gridwidth = 2;
        layout.setConstraints(b_button_5, constraints);
        f_frame.add(b_button_5);

        Button b_button_6 = new Button("button_6");
        constraints.gridwidth = GridBagConstraints.REMAINDER;
        layout.setConstraints(b_button_6, constraints);
        f_frame.add(b_button_6);

        Button b_button_7 = new Button("button_7");
        constraints.gridwidth = 1;
        constraints.gridheight = 2;
        layout.setConstraints(b_button_7, constraints);
        f_frame.add(b_button_7);

        Button b_button_8 = new Button("button_8");
        constraints.gridwidth = GridBagConstraints.REMAINDER;
        constraints.gridheight = 1;
        layout.setConstraints(b_button_8, constraints);
        f_frame.add(b_button_8);

        Button b_button_9 = new Button("button_9");
        constraints.gridwidth = GridBagConstraints.REMAINDER;
        constraints.gridheight = 1;
        layout.setConstraints(b_button_9, constraints);
        f_frame.add(b_button_9);

        f_frame.pack();
        f_frame.setVisible(true);
    }
    static public void _CardLayout() {
        String[] ordinals = new String[] {
            "first", "second", "third", "fourth", "fifth", "sixth"
        };

        Frame f_frame = new Frame("Java AWT CardLayout");
        f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        Panel p_panel_card = new Panel();
        CardLayout layout = new CardLayout();
        p_panel_card.setLayout(layout);
        for(int i = 0; i < ordinals.length; i += 1) {
            p_panel_card.add(ordinals[i], new Button(ordinals[i]));
        }
        f_frame.add(p_panel_card);

        ActionListener listener = (event) -> {
            switch (event.getActionCommand()) {
                case "first":
                    layout.previous(p_panel_card);
                    break;
                case "previous":
                    layout.previous(p_panel_card);
                    break;
                case "next":
                    layout.next(p_panel_card);
                    break;
                case "last":
                    layout.last(p_panel_card);
                    break;
                case "third":
                    layout.show(p_panel_card, "third");
                    break;
            }
        };
        Panel p_panel_button = new Panel();
        Button b_button_0 = new Button("first");
        b_button_0.addActionListener(listener);
        p_panel_button.add(b_button_0);

        Button b_button_1 = new Button("previous");
        b_button_1.addActionListener(listener);
        p_panel_button.add(b_button_1);

        Button b_button_2 = new Button("next");
        b_button_2.addActionListener(listener);
        p_panel_button.add(b_button_2);

        Button b_button_3 = new Button("last");
        b_button_3.addActionListener(listener);
        p_panel_button.add(b_button_3);

        Button b_button_4 = new Button("third");
        b_button_4.addActionListener(listener);
        p_panel_button.add(b_button_4);

        f_frame.add(p_panel_button, BorderLayout.SOUTH);
        f_frame.pack();
        f_frame.setVisible(true);
    }
    static public void _NullLayout() {
        Frame f_frame = new Frame();
        f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        f_frame.setLayout(null);

        Button b_button_0 = new Button("button_0");
        b_button_0.setBounds(20, 30, 90, 28);
        f_frame.add(b_button_0);

        Button b_button_1 = new Button("button_1");
        b_button_1.setBounds(50, 45, 120, 35);
        f_frame.add(b_button_1);

        f_frame.setBounds(50, 50, 200, 100);
        // f_frame.pack();
        f_frame.setVisible(true);
    }
    static public void _BoxLayout() {
        Frame f_frame = new Frame("Java AWT BoxLayout");
        f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        Box horizontal = Box.createHorizontalBox();
        horizontal.add(new Button("button_0 horizontal"));
        horizontal.add(new Button("button_1 horizontal"));
        f_frame.add(horizontal, BorderLayout.NORTH);

        Box vertical = Box.createVerticalBox();
        vertical.add(new Button("button_0 vertical"));
        vertical.add(new Button("button_1 vertical"));
        f_frame.add(vertical);

        f_frame.pack();
        f_frame.setVisible(true);
    }
    static public void _BoxLayout_Glue_Strut_RigidArea() {
        Frame f_frame = new Frame("Java AWT BoxLayout_Glue_Strut_RigidArea");
        f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        Box horizontal = Box.createHorizontalBox();
        horizontal.add(new Button("button_0 horizontal"));
        horizontal.add(Box.createHorizontalGlue());
        horizontal.add(new Button("button_1 horizontal"));
        horizontal.add(Box.createHorizontalStrut(10));
        horizontal.add(new Button("button_2 horizontal"));
        f_frame.add(horizontal, BorderLayout.NORTH);

        Box vertical = Box.createVerticalBox();
        vertical.add(new Button("button_0 vertical"));
        vertical.add(Box.createVerticalGlue());
        vertical.add(new Button("button_1 vertical"));
        vertical.add(Box.createVerticalStrut(10));
        vertical.add(new Button("button_2 vertical"));
        f_frame.add(vertical);

        f_frame.pack();
        f_frame.setVisible(true);
    }
}
