/* Java_Border.java
Author: BSS9395
Update: 2023-03-26T23:17:00+08@China-Shanghai+08
Design: Java Standard Library: Border
*/

import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;

public class Java_Border {
    public JFrame _f_frame = new JFrame("Java Border");
    public Java_Border() {
        _f_frame.setLayout(new GridLayout(2, 4));
        _f_frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Border bevel = BorderFactory.createBevelBorder(BevelBorder.RAISED, Color.RED, Color.GREEN, Color.BLUE, Color.GRAY);
        _f_frame.add(_Make_Panel("Bevel", bevel));

        Border line = BorderFactory.createLineBorder(Color.ORANGE, 10);
        _f_frame.add(_Make_Panel("Line", line));

        Border empty = BorderFactory.createEmptyBorder(20, 5, 10, 30);
        _f_frame.add(_Make_Panel("Empty", empty));

        Border etched = BorderFactory.createEtchedBorder(EtchedBorder.RAISED, Color.RED, Color.GREEN);
        _f_frame.add(_Make_Panel("Etched", etched));

        Border titled = BorderFactory.createTitledBorder(line, "Titled", TitledBorder.LEFT, TitledBorder.BOTTOM, new Font("Consola", Font.BOLD, 18), Color.BLUE);
        _f_frame.add(_Make_Panel("Titled", titled));

        Border matte = BorderFactory.createMatteBorder(20, 5, 10, 30, Color.GREEN);
        _f_frame.add(_Make_Panel("Matte", matte));

        Border compound = BorderFactory.createCompoundBorder(new LineBorder(Color.RED, 8), titled);
        _f_frame.add(_Make_Panel("Compound", compound));

        _f_frame.pack();
        _f_frame.setVisible(true);
    }
    public JPanel _Make_Panel(String content, Border border) {
        JPanel panel = new JPanel();
        panel.add(new JLabel(content));
        panel.setBorder(border);
        return panel;
    }

    static public void main(String[] args) {
        new Java_Border();
    }
}
