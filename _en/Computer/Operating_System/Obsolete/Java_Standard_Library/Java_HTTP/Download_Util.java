/* Download_util.java
Author: BSS9395
Update: 2023-03-08T22:48:00+08@China-Shanghai+08
Design: Download Util
*/
import java.io.InputStream;
import java.io.RandomAccessFile;
import java.net.HttpURLConnection;
import java.net.URL;

public class Download_Util {
    static class Download_Thread extends Thread {
        private String _rename = "";
        private String _path = "";
        private int _pos = 0;
        private int _size = 0;
        public int _length = 0;

        public Download_Thread(String rename, String path, int pos, int size) {
            _rename = rename;
            _path = path;
            _pos = pos;
            _size = size;
        }

        @Override
        public void run() {
            try {
                HttpURLConnection connection = Download_Util._Connect(_path);
                InputStream stream = connection.getInputStream();
                stream.skip(_pos);
                RandomAccessFile file = new RandomAccessFile(_rename, "rw");
                file.seek(_pos);

                byte[] buffer = new byte[1024];
                for(int count = 0; _length < _size && (count = stream.read(buffer)) != -1;) {
                    file.write(buffer, 0, count);
                    _length += count;
                }
                stream.close();
                file.close();
            } catch (Exception exception) {
                exception.printStackTrace();
            }

        }
    }

    static public String _accept =
        "  image/gif, image/jpeg, image/pjpeg, image/pjpeg" +
        ", application/x-shockwave-flash, application/xaml+xml" +
        ", application/vnd.ms-xpsdocument, application/x-ms-xbap" +
        ", application/x-ms-application, application/vnd.ms-excel" +
        ", application/vnd.ms-powerpoint, application/msword" +
        ", */*";
    static public String _language = "zh-CN";
    static public String _charset = "UTF-8";
    static HttpURLConnection _Connect(String path)
        throws Exception {
        URL url = new URL(path);
        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
        connection.setConnectTimeout(1000 * 5);
        connection.setRequestMethod("GET");
        connection.setRequestProperty("Accept", Download_Util._accept);
        connection.setRequestProperty("Accept-Language", Download_Util._language);
        connection.setRequestProperty("Charset", Download_Util._charset);
        connection.setRequestProperty("Connection", "Keep-Alive");
        return connection;
    }

    private String _path = "";
    private String _rename = "";
    private Download_Thread[] _threads;
    private int _file_size = 0;

    public Download_Util(String path, String rename, int threads) {
        _path = path;
        _rename = rename;
        _threads = new Download_Thread[threads];
    }

    public void _Download()
        throws Exception {
        System.out.println(_path);
        HttpURLConnection connection = Download_Util._Connect(_path);
        _file_size = connection.getContentLength();
        connection.disconnect();
        int part_size = _file_size / _threads.length + 1;
        RandomAccessFile file = new RandomAccessFile(_rename, "rw");
        file.setLength(_file_size);
        file.close();
        for(int i = 0; i < _threads.length; i += 1) {
            _threads[i] = new Download_Thread(_rename, _path,i * part_size, part_size);
            _threads[i].start();
        }
    }

    public double _Progress() {
        int total = 0;
        for(int i = 0; i < _threads.length; i += 1) {
            total += _threads[i]._length;
        }
        return ((double)total / (double)_file_size);
    }


    static public void main(String[] argv)
        throws Exception {
        Download_Util util = new Download_Util("http://www.galex.caltech.edu/media/images/glx2012-03r_img01.jpg", "ios.png", 4);
        util._Download();
        new Thread(() -> {
            try {
                while (util._Progress() < 1.0) {
                    System.out.printf("Completed: %f%n", util._Progress());
                    Thread.sleep(100);
                }
            }
            catch (Exception exception) {
                exception.printStackTrace();
            }
        }).start();

        System.out.println("at the end.");
    }
}
