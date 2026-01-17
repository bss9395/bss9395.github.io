/* Java_UIManager.java
Author: BSS9395
Update: 1623-03-25T23:16:00+08@China-Shanghai+08
Design: Java Standard Library: UIManager
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.InputEvent;

public class Java_UIManager {
    static public String[] _colors = new String[] {
        "red", "green", "blue"
    };

    public JFrame _f_frame = new JFrame("Java Swing Components");

    public JMenuBar          _mb_menu      = new JMenuBar();
    public JMenu             _m_file       = new JMenu("File");
    public JMenuItem         _mi_new       = new JMenuItem("new", new ImageIcon("icons/add.png"));
    public JMenuItem         _mi_save      = new JMenuItem("save", new ImageIcon("icons/save.png"));
    public JMenuItem         _mi_exit      = new JMenuItem("exit", new ImageIcon("icons/clear.png"));
    public JMenu             _m_edit       = new JMenu("Edit");
    public JCheckBoxMenuItem _cbmi_wrap    = new JCheckBoxMenuItem("wrap");
    public JMenuItem         _mi_copy      = new JMenuItem("copy", new ImageIcon("icons/content_copy.png"));
    public JMenuItem         _mi_paste     = new JMenuItem("paste", new ImageIcon("icons/content_paste.png"));
    public JMenu             _m_format     = new JMenu("format");
    public JMenuItem         _mi_comment   = new JMenuItem("comment");
    public JMenuItem         _mi_uncomment = new JMenuItem("uncomment");

    public JPopupMenu           _pm_popup     = new JPopupMenu();
    public JRadioButtonMenuItem _rbmi_metal   = new JRadioButtonMenuItem("Metal", true);
    public JRadioButtonMenuItem _rbmi_nimbus  = new JRadioButtonMenuItem("Nimbus");
    public JRadioButtonMenuItem _rbmi_windows = new JRadioButtonMenuItem("Windows");
    public JRadioButtonMenuItem _rbmi_classic = new JRadioButtonMenuItem("Classic");
    public JRadioButtonMenuItem _rbmi_motif   = new JRadioButtonMenuItem("Motif");

    public JTextArea         _ta_area    = new JTextArea(8, 20);
    public JComboBox<String> _cb_colors  = new JComboBox<String>(_colors);
    public JRadioButton      _rb_male    = new JRadioButton("male", true);
    public JRadioButton      _rb_female  = new JRadioButton("female", false);
    public JCheckBox         _cb_married = new JCheckBox("married", false);

    public JTextField _tf_field = new JTextField(40);
    public JButton    _b_button = new JButton("Ok", new ImageIcon("icons/check.png"));
    public void init() {
        _f_frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ImageIcon image_icon = null;

        _mi_new.setAccelerator(KeyStroke.getKeyStroke('N',	InputEvent.CTRL_DOWN_MASK));
        _mi_new.addActionListener((event) -> {
            _ta_area.append("click _mi_new");
        });
        image_icon = (ImageIcon) _mi_new.getIcon();
        image_icon.setImage(image_icon.getImage().getScaledInstance(16, 16, Image.SCALE_DEFAULT));
        _mi_new.setIcon(image_icon);
        image_icon = (ImageIcon) _mi_save.getIcon();
        image_icon.setImage(image_icon.getImage().getScaledInstance(16, 16, Image.SCALE_DEFAULT));
        _mi_save.setIcon(image_icon);
        image_icon = (ImageIcon) _mi_exit.getIcon();
        image_icon.setImage(image_icon.getImage().getScaledInstance(16, 16, Image.SCALE_DEFAULT));
        _mi_exit.setIcon(image_icon);
        _m_file.add(_mi_new);
        _m_file.add(_mi_save);
        _m_file.add(_mi_exit);

        _m_edit.add(_cbmi_wrap);
        _m_edit.addSeparator();
        image_icon = (ImageIcon) _mi_copy.getIcon();
        image_icon.setImage(image_icon.getImage().getScaledInstance(16, 16, Image.SCALE_DEFAULT));
        _mi_copy.setIcon(image_icon);
        image_icon = (ImageIcon) _mi_paste.getIcon();
        image_icon.setImage(image_icon.getImage().getScaledInstance(16, 16, Image.SCALE_DEFAULT));
        _mi_paste.setIcon(image_icon);
        _m_edit.add(_mi_copy);
        _m_edit.add(_mi_paste);
        _mi_comment.setToolTipText("comment code");
        _m_format.add(_mi_comment);
        _m_format.add(_mi_uncomment);
        _m_edit.add(_m_format);

        _mb_menu.add(_m_file);
        _mb_menu.add(_m_edit);
        _f_frame.setJMenuBar(_mb_menu);

        ButtonGroup bg_style = new ButtonGroup();
        bg_style.add(_rbmi_metal);
        bg_style.add(_rbmi_nimbus);
        bg_style.add(_rbmi_windows);
        bg_style.add(_rbmi_classic);
        bg_style.add(_rbmi_motif);
        ActionListener listener = (event) -> {
            try {
                switch (event.getActionCommand()) {
                    case "Metal":
                        UIManager.setLookAndFeel("javax.swing.plaf.metal.MetalLookAndFeel");
                        break;
                    case "Nimbus":
                        UIManager.setLookAndFeel("javax.swing.plaf.nimbus.NimbusLookAndFeel");
                        break;
                    case "Windows":
                        UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
                        break;
                    case "Classic":
                        UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsClassicLookAndFeel");
                        break;
                    case "Motif":
                        UIManager.setLookAndFeel("com.sun.java.swing.plaf.motif.MotifLookAndFeel");
                        break;
                }
                SwingUtilities.updateComponentTreeUI(_f_frame.getContentPane());  // ¢Ú
                SwingUtilities.updateComponentTreeUI(_mb_menu);
                SwingUtilities.updateComponentTreeUI(_pm_popup);
            } catch(Exception exception) {
                exception.printStackTrace();
            }
        };
        _rbmi_metal.addActionListener(listener);
        _rbmi_nimbus.addActionListener(listener);
        _rbmi_windows.addActionListener(listener);
        _rbmi_classic.addActionListener(listener);
        _rbmi_motif.addActionListener(listener);
        _pm_popup.add(_rbmi_metal);
        _pm_popup.add(_rbmi_nimbus);
        _pm_popup.add(_rbmi_windows);
        _pm_popup.add(_rbmi_classic);
        _pm_popup.add(_rbmi_motif);
        _ta_area.setComponentPopupMenu(_pm_popup);


        Box b_vertical = Box.createVerticalBox();
        b_vertical.add(new JScrollPane(_ta_area));
        JPanel p_check = new JPanel();
        p_check.add(_cb_colors);
        ButtonGroup  bg_gender = new ButtonGroup();
        bg_gender.add(_rb_male);
        bg_gender.add(_rb_female);
        p_check.add(_rb_male);
        p_check.add(_rb_female);
        p_check.add(_cb_married);
        b_vertical.add(p_check);
        Box b_horizontal = Box.createHorizontalBox();
        b_horizontal.add(b_vertical);
        b_horizontal.add(new JList<String>(_colors));
        _f_frame.add(b_horizontal);

        JPanel p_bottom = new JPanel();
        p_bottom.add(_tf_field);
        image_icon = (ImageIcon) _b_button.getIcon();
        image_icon.setImage(image_icon.getImage().getScaledInstance(16, 16, Image.SCALE_DEFAULT));
        _b_button.setIcon(image_icon);
        p_bottom.add(_b_button);
        _f_frame.add(p_bottom, BorderLayout.SOUTH);
        _f_frame.pack();
        _f_frame.setVisible(true);
    }

    static public void main(String[] args) {
        // _UIManager();
        new Java_UIManager().init();
    }
    static public void _UIManager() {
        UIManager.LookAndFeelInfo[] lafs = UIManager.getInstalledLookAndFeels();
        for(UIManager.LookAndFeelInfo laf : lafs) {
            System.out.printf("%16s: %s%n", laf.getName(), laf);
        }
    }

}
