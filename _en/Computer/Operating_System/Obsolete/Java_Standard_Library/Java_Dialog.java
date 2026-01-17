import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Java_Dialog {
    Frame  _f_frame    = new Frame("Java AWT Dialog");
    Dialog _d_model    = new Dialog(_f_frame, "model dialog", true);
    Dialog _d_nonmodel = new Dialog(_f_frame, "nonmodel dialog", false);
    Button _b_model    = new Button("make model dialog");
    Button _b_nonmodel = new Button("make nonmodel dialog");
    public Java_Dialog() {
        _f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        _d_model.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                _d_model.dispose();
            }
        });
        _d_nonmodel.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                _d_nonmodel.dispose();
            }
        });
        _d_model.setBounds(20, 30, 300, 400);
        _d_nonmodel.setBounds(20, 30, 300, 400);
        _b_model.addActionListener((event) -> {
            _d_model.setVisible(true);
        });
        _b_nonmodel.addActionListener((event) -> {
            _d_nonmodel.setVisible(true);
        });
        _f_frame.add(_b_model);
        _f_frame.add(_b_nonmodel, BorderLayout.SOUTH);
        _f_frame.pack();
        _f_frame.setVisible(true);
    }

    static public void main(String[] args) {
        new Java_Dialog();
    }
}
