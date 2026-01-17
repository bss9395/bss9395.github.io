/* Java_ListCellRenderer.java
Author: BSS9395
Update: 2023-03-30T15:53:00+08@China-Shanghai+08
Design: Java Standard Library: ListCellRenderer
*/

import javax.swing.*;
import java.awt.*;
import java.awt.font.FontRenderContext;
import java.awt.geom.AffineTransform;
import java.awt.geom.Rectangle2D;

public class Java_ListCellRenderer {
    static class LCR_Panel extends JPanel implements ListCellRenderer<String> {
        public ImageIcon         _icon       = null;
        public String            _name       = null;
        public Color             _background = null;
        public Color             _foreground = null;
        public Font              _font       = new Font("Consola", Font.BOLD, 10);
        public FontRenderContext _context    = new FontRenderContext(new AffineTransform(), true, true);
        @Override
        public Component getListCellRendererComponent(JList<? extends String> list, String value, int index, boolean selected, boolean focus) {
            _icon       = new ImageIcon("avatars/" + value + ".svg.png");
            _name       = value;
            _background = (selected == true) ? list.getSelectionBackground() : list.getBackground();
            _foreground = (selected == true) ? list.getSelectionForeground() : list.getForeground();
            return this;
        }
        public void paintComponent(Graphics graphics) {
//            int width  = _icon.getIconWidth();
//            int height = _icon.getIconHeight();
            int width  = 32;
            int height = 32;
            graphics.setColor(_background);
            graphics.fillRect(0, 0, this.getWidth(), this.getHeight());
            graphics.setColor(_foreground);
            graphics.drawImage(_icon.getImage(), (this.getWidth() - width) / 2, 10, width, height,null);
            graphics.setFont(_font);
            Rectangle2D bounds = _font.getStringBounds(_name, _context);
            graphics.drawString(_name, (int) ((this.getWidth() - bounds.getWidth()) / 2), (int) (10 + height + bounds.getHeight()));
        }
        public Dimension getPreferredSize() {
            return new Dimension(60, 80);
        }
    }

    public String[] _langs = new String[] {
        "Facebook", "Line", "LinkedIn", "Pinterest", "QQ", "QZone", "Sina", "Twitter", "WeChat"
    };
    public JFrame _f_frame = new JFrame("Java ListCellRenderer");
    public JList<String> _l_langs = new JList<String>(_langs);
    public Java_ListCellRenderer() {
        _l_langs.setCellRenderer(new LCR_Panel());
        _f_frame.add(new JScrollPane(_l_langs));
        _f_frame.pack();
        _f_frame.setVisible(true);
        _f_frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    static public void main(String[] args) {
        new Java_ListCellRenderer();
    }
}
