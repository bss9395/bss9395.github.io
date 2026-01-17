/* Java_ImageIO.java
Author: BSS9395
Update: 2023-05-04T21:45:00+08@China-Guangdong-Zhanjiang+08
Design: Java Standard Library: ImageIO
*/

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class Java_ImageIO {
    static public void main(String[] args) throws Exception {
        // _getReaderFileSuffixes_getWriterFileSuffixes();
        _read_write();
    }
    static public void _getReaderFileSuffixes_getWriterFileSuffixes() {
        String[] reader = ImageIO.getReaderFileSuffixes();
        System.out.println("ImageIO.getReaderFileSuffixes();");
        for(int i = 0; i < reader.length; i += 1) {
            System.out.println(reader[i]);
        }

        String[] writer = ImageIO.getWriterFileSuffixes();
        System.out.println("ImageIO.getWriterFileSuffixes();");
        for(int i = 0; i < writer.length; i += 1) {
            System.out.println(writer[i]);
        }
    }

    static public void _read_write() throws Exception {
        Image image = ImageIO.read(new File("images/M31_96x96.jpg"));
        BufferedImage buffered = new BufferedImage(image.getWidth(null) * 2, image.getHeight(null) * 2, BufferedImage.TYPE_INT_ARGB);
        Graphics graphics = buffered.getGraphics();
        // graphics.drawImage(image, 0, 0, null);                                                                                     // note: not scaled.
        graphics.drawImage(image, 0, 0, buffered.getWidth(null), buffered.getHeight(null), null);  // note: scaled.
        ImageIO.write(buffered, "png", new File("Java_ImageIO.java.png"));
    }
}
