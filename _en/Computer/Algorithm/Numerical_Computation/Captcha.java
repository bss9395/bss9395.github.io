/* Captcha.java
Author: BSS9395
Update: 2023-05-05T22:19:00+08@China-Guangdong-Zhanjiang+08
Design: Captcha
*/

import java.awt.*;
import java.awt.font.FontRenderContext;
import java.awt.geom.AffineTransform;
import java.awt.geom.Arc2D;
import java.awt.geom.Rectangle2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Random;
import javax.imageio.ImageIO;

class Generator {
    static Random _random = new Random(System.currentTimeMillis());
    static public String _charset = "";
    static {
        _charset += "0123456789";
        _charset += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        _charset += "abcdefghijklmnopqrstuvwxyz";
    };
    static public int _Generate_Int(int min, int max) {
        return (min + _random.nextInt(max - min));
    }
    static public double _Generate_Double(double min, double max) {
        return (min + _random.nextDouble() * (max - min));
    }
    static public String _Generate_String(int length) {
        StringBuilder text = new StringBuilder(length);
        for(int i = 0; i < length; i += 1) {
            int index = _random.nextInt(_charset.length());
            text.append(_charset.charAt(index));
        }
        return text.toString();
    }
    static public Color _Generate_RGBA() {
        int red   = _Generate_Int(0, 256);
        int green = _Generate_Int(0, 256);
        int blue  = _Generate_Int(0, 256);
        int alpha = _Generate_Int(128, 256);
        return new Color(red, green, blue, alpha);
    }
}

public class Captcha {
    static public void _Captcha(int _count) {
        Font              font       = new Font("Consola", Font.BOLD, 20);
        FontRenderContext context    = new FontRenderContext(new AffineTransform(), true, true);
        String            code       = Generator._Generate_String(_count);
        Rectangle2D[]     bounds     = new Rectangle2D[code.length()];
        double            max_width  = 0.0;
        double            max_height = 0.0;
        for(int i = 0; i < code.length(); i += 1) {
            bounds[i] = font.getStringBounds("" + code.charAt(i), context);
            System.out.printf("[%s, %s, %s, %s, %s, %s, %s]%n", bounds[i].getWidth(), bounds[i].getHeight(), -bounds[i].getY(), -bounds[i].getCenterY() * 2.0, bounds[i].getHeight() - (-bounds[i].getY()), (-bounds[i].getY()) - (-bounds[i].getCenterY() * 2.0), (-bounds[i].getY() - bounds[i].getHeight() / 2.0) * 2.0);
            if(max_width < bounds[i].getWidth()) {
                max_width = bounds[i].getWidth();
            }
            if(max_height < -bounds[i].getCenterY() * 2.0) {
                max_height = -bounds[i].getCenterY() * 2.0;
            }
        }

        BufferedImage image = new BufferedImage((int)(max_width * (_count * 2 + 1)), (int)(max_height * 3), BufferedImage.TYPE_INT_ARGB);
        System.out.printf("[%s, %s, %s, %s]%n", max_width, max_height, image.getWidth(), image.getHeight());

        Graphics2D graphics = image.createGraphics();
        graphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        graphics.setColor(new Color(255, 255,255, 255));
        graphics.fillRect(0, 0, image.getWidth(), image.getHeight());

        graphics.setColor(new Color(0, 0, 0, 255));
        for(int i = 0; i < _count * 10; i += 1) {
            int x_0 = Generator._Generate_Int(0, image.getWidth());
            int y_0 = Generator._Generate_Int(0, image.getHeight());
            int x_1 = Generator._Generate_Int(0, 10);
            int y_1 = Generator._Generate_Int(0, 10);
            graphics.drawLine(x_0, y_0, x_0 + x_1, y_0 + y_1);
        }

        for(int i = 0; i < code.length(); i += 1) {
            AffineTransform transform = new AffineTransform();
            transform.rotate(Generator._Generate_Double(-75.0, +75.0) / 180.0 * Math.PI);
            transform.translate(-bounds[i].getWidth() * 0.5, 0.0);
            graphics.setFont(font.deriveFont(transform));
            // graphics.setFont(font);
            graphics.setColor(Generator._Generate_RGBA());
            graphics.drawString("" + code.charAt(i), (float)(max_width * (i * 2 + 1) + max_width * 0.5), (float)(max_height * 2));
        }

        try {
            ImageIO.write(image, "png", new File("captcha.png"));
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    static public void _Seal(int diameter, double arc, String head, String waist, String foot) {
        BufferedImage image = new BufferedImage(diameter, diameter, BufferedImage.TYPE_INT_ARGB);
        Graphics2D graphics = image.createGraphics();

        ////////////////////////////////////////////////////////////////////////
        // note: background.
        graphics.setPaint(Color.WHITE);
        graphics.fillRect(0, 0, diameter, diameter);

        ////////////////////////////////////////////////////////////////////////
        // note: outer circle.
        double radius = diameter * 0.5;
        graphics.setPaint(Color.red);
        graphics.setStroke(new BasicStroke(4));
        Shape circle = new Arc2D.Double(2,2,(radius - 2) * 2,(radius - 2) * 2,0,360, Arc2D.OPEN);
        graphics.draw(circle);

        ////////////////////////////////////////////////////////////////////////
        // note: middle double lines.
        double deviation = arc * (Math.PI / 180.0) * 0.5 + Math.PI * 0.5;
        double chord     = (radius - 2) * Math.cos(deviation);
        double distance  = (radius - 2) * Math.sin(deviation);
        graphics.drawLine((int)(radius + chord), (int)(radius - distance), (int)(radius - chord), (int)(radius - distance));
        graphics.drawLine((int)(radius + chord), (int)(radius + distance), (int)(radius - chord), (int)(radius + distance));

        ////////////////////////////////////////////////////////////////////////
        // note: head string.
        Font        font   = new Font("楷体", Font.PLAIN,45);
        Rectangle2D bounds = font.getStringBounds(head, graphics.getFontRenderContext());
        double half   = bounds.getWidth() / head.length() * 0.5;
        double inner  = radius - bounds.getHeight();
        double radian = Math.asin(half / inner) * 2.0;
        double from = head.length() * radian * 0.5 - radian * 0.5;
        for(int i = 0; i < head.length(); i += 1) {
            double angle = from - radian * i;
            AffineTransform transform = new AffineTransform();
            transform.rotate(-angle);             // note: clock-wise rotation.
            transform.translate(-half, 0.0);
            graphics.setFont(font.deriveFont(transform));
            angle += Math.PI * 0.5;
            double x_0_5 = inner * Math.cos(angle);
            double y_1_5 = inner * Math.sin(angle);
            graphics.drawString("" + head.charAt(i), (float)(radius + x_0_5), (float)(radius - y_1_5));
        }

        ////////////////////////////////////////////////////////////////////////
        // note: waist string.
        font   = new Font("黑体", Font.BOLD, 35);
        bounds = font.getStringBounds(waist, graphics.getFontRenderContext());
        graphics.setFont(font);
        graphics.drawString(waist, (int)(radius - bounds.getCenterX()), (int)(radius - bounds.getCenterY()));

        ////////////////////////////////////////////////////////////////////////
        // note: foot string.
        font = new Font("宋体", Font.PLAIN,40);
        bounds = font.getStringBounds(foot, graphics.getFontRenderContext());
        graphics.setFont(font);
        graphics.drawString(foot, (int) (radius - bounds.getCenterX()), (int) (radius * 1.5 - bounds.getCenterY()));

        ////////////////////////////////////////////////////////////////////////

        try {
            ImageIO.write(image, "png", new File("seal.png"));
        }
        catch (IOException exception) {
            exception.printStackTrace();
        }
    }

    public static void main(String[] args) {
        _Captcha(5);
        // _Seal(700, 160.0, "中国授时天文台", "2023年05月06日 18时08分00秒 东八区", "时间戳专用章");
    }
}