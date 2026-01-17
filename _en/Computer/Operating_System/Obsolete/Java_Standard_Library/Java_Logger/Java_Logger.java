/* Java_Logger.java
Author: BSS9395
Update: 2023-01-15T18:24:00+08@China-Shanghai+08
Design: Java Standard Library: Logger
*/

import java.io.IOException;
import java.util.Locale;
import java.util.ResourceBundle;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Java_Logger {
    static private Logger log = Logger.getLogger(Java_Logger.class.toString());

    static public void main(String[] args)
            throws IOException {
        // _Logger();
        _ResourceBundle();
    }
    static public void _Logger()
            throws IOException {
        log.addHandler(new FileHandler("log.xml"));
        log.setLevel(Level.FINE);

        log.finest("finest");
        log.finer("finer");
        log.fine("fine");
        log.config("config");
        log.info("info");
        log.warning("warning");
        log.severe("severe");
    }
    static public void _ResourceBundle() {
        ResourceBundle bundle = ResourceBundle.getBundle("lang", Locale.getDefault(Locale.Category.FORMAT));
        log.setResourceBundle(bundle);
        log.setLevel(Level.FINE);

        log.finest("finest");
        log.finer("finer");
        log.fine("fine");
        log.config("config");
        log.info("info");
        log.warning("warning");
        log.severe("severe");
    }
}