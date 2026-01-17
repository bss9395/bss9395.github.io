

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class TCP_Server {
    static class Client extends Thread {
        public List<Socket> _clients = null;
        public Socket _client = null;
        public Client(List<Socket> clients, Socket client) {
            _clients = clients;
            _client = client;
            _clients.add(_client);
        }

        @Override
        public void run() {
            try {
                InputStream input = _client.getInputStream();
                byte[] buffer = new byte[1024];
                int count = -1;
                for(; 0 < (count = input.read(buffer, 0, buffer.length)); ) {
                    System.out.println(new String(buffer, 0, count, TCP_Server._encoding_sink));
                    for(Socket client: _clients) {
                        OutputStream output = client.getOutputStream();
                        output.write(buffer, 0, count);
                    }
                }
                System.out.printf("count = %s%n", count);
                System.out.println("for(int count = -1; 0 < (count = input.read(buffer, 0, buffer.length)); ) {");
            } catch (Exception exception) {
                exception.printStackTrace();
            } finally {
                try {
                    _client.close();
                    _clients.remove(_client);
                } catch(Exception exception) {
                    exception.printStackTrace();
                }
            }
        }
    }

    static public String _encoding_source = "GBK";
    static public String _encoding_sink = "UTF-8";
    static public int _server_port = 30000;
    static public int _server_backlog = 100;
    ServerSocket _server = null;
    List<Socket> _clients = Collections.synchronizedList(new ArrayList<Socket>());
    public TCP_Server() {
        try {
            _server = new ServerSocket(TCP_Server._server_port, TCP_Server._server_backlog);
            while (true) {
                Socket client = _server.accept();
                System.out.println("Socket client = server.accept();");
                new Client(_clients, client).start();
            }
        } catch(Exception exception) {
            exception.printStackTrace();
        } finally {
            try {
                for (Socket client : _clients) {
                    client.close();
                }
                _clients.clear();
                _server.close();
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
    }
    static public void main(String[] args)
        throws Exception {
        new TCP_Server();
    }
}
