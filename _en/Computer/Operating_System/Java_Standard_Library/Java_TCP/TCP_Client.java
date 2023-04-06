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
                    byte[] sink = new String(buffer, 0, count).getBytes(TCP_Client._encoding_sink);
                    output.write(sink, 0, sink.length);
                }
                System.out.println("for(int count = -1; 0 < (count = System.in.read(buffer, 0, buffer.length)); ) {");
            } catch(Exception exception) {
                exception.printStackTrace();
            } finally {
                try {
                    _client.shutdownOutput();
                } catch (Exception exception) {
                    exception.printStackTrace();
                }
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
                    System.out.print(new String(buffer, 0, count, TCP_Client._encoding_sink));
                }
                System.out.println("for(int count = -1; 0 < (count = input.read(buffer, 0, buffer.length)); ) {");
            } catch(Exception exception) {
                exception.printStackTrace();
            } finally {
                try {
                    _client.shutdownInput();
                } catch (Exception exception) {
                    exception.printStackTrace();
                }
            }
        }
    }

    static public String _encoding_source = "GBK";
    static public String _encoding_sink = "UTF-8";
    static public String _server_ipv4 = "localhost";
    static public int _server_port = 30000;
    Socket _client = null;
    public TCP_Client(String server_ipv4, int server_port)
        throws Exception {
        _client = new Socket(server_ipv4, server_port);
        Send send = new Send(_client);
        Recv recv = new Recv(_client);
        send.start(); recv.start();
        send.join();  recv.join();
        _client.close();
    }
    static public void main(String[] args)
        throws Exception {
        new TCP_Client(TCP_Client._server_ipv4, TCP_Client._server_port);
    }
}
