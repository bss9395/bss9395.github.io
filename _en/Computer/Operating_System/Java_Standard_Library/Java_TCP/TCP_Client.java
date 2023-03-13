import java.io.*;
import java.net.Socket;
import java.nio.CharBuffer;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

public class TCP_Client {
    static class Send extends Thread {
        public Socket _client = null;
        public Send(Socket client) {
            _client = client;
        }

        @Override
        public void run() {
            try {
                OutputStream output = _client.getOutputStream();
                byte[] buffer = new byte[1024];
                for(int count = -1; 0 < (count = System.in.read(buffer, 0, buffer.length)); ) {
                    byte[] sink = new String(buffer, 0, count, Charset.forName(TCP_Client._encoding_source)).getBytes(TCP_Client._encoding_sink);
                    output.write(sink, 0, sink.length);
                }
                System.out.println("for(int count = -1; 0 < (count = System.in.read(buffer, 0, buffer.length)); ) {");
            } catch(Exception exception) {
                exception.printStackTrace();
            }
        }
    }
    static class Recv extends Thread {
        public Socket _client = null;
        public Recv(Socket client) {
            _client = client;
        }

        @Override
        public void run() {
            try {
                InputStream input = _client.getInputStream();
                byte[] buffer = new byte[1024];
                for(int count = -1; 0 < (count = input.read(buffer, 0, buffer.length)); ) {
                    System.out.print(new String(buffer, 0, count, Charset.forName(TCP_Client._encoding_sink)));
                }
                System.out.println("for(int count = -1; 0 < (count = input.read(buffer, 0, buffer.length)); ) {");
            } catch(Exception exception) {
                exception.printStackTrace();
            }
        }
    }

    static public String _encoding_source = "GBK";
    static public String _encoding_sink = "UTF-8";
    static public String _server_ipv4 = "127.0.0.1";
    static public int _server_port = 30000;
    public TCP_Client(String ipv4, int port)
        throws Exception {
        Socket client = new Socket(ipv4, port);
        new Send(client).start();
        new Recv(client).start();
    }
    static public void main(String[] args)
        throws Exception {
        new TCP_Client(TCP_Client._server_ipv4, TCP_Client._server_port);
    }
}
