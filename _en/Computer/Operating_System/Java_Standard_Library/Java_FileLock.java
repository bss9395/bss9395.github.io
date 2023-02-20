/* Java_FileLock.java
Author: BSS9395
Update: 2023-02-12T16:44:00+08@China-Shanghai+08
Design: Java Standard Library: FileLock
*/
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.channels.FileChannel;
import java.nio.channels.FileLock;

public class Java_FileLock {
    static public void main(String[] args) {
        _FileLock();
    }
    static public void _FileLock() {
        try(FileChannel channel = new FileOutputStream("output.text").getChannel();) {
                FileLock lock = channel.tryLock();
                Thread.sleep(10000);
                lock.release();
        } catch(IOException exception) {
            exception.printStackTrace();
        } catch(InterruptedException exception) {
            exception.printStackTrace();
        }
    }
}
