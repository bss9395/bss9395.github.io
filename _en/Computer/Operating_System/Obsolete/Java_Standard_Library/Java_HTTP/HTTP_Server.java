/* HTTP_Server.java
Author: BSS9395
Update: 2023-0318T13:47:00+08@China-Shanghai+08
Design: HTTP Server
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

public class HTTP_Server {
    static class Client extends Thread {
        public Socket _client = null;
        public Client(Socket client) {
            _client = client;
        }
        @Override
        public void run() {
            try {
                BufferedReader input = new BufferedReader(new InputStreamReader(_client.getInputStream()));
                String line = null;
                while((line = input.readLine()) != null) {
                    System.out.println(line);
                }
                _client.shutdownInput();

                PrintStream output = new PrintStream(_client.getOutputStream());
                output.println("Hello, Client!");
                _client.shutdownOutput();
                _client.close();
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
    }

    static public String _server_ipv4 = "localhost";
    static public int _server_port = 30000;
    static public int _server_backlog = 100;

    public ServerSocket _server = null;
    public HTTP_Server(int port, int backlog) {
        try {
            _server = new ServerSocket(port, backlog);
            while(true) {
                Socket client = _server.accept();
                new Client(client).start();
            }
        } catch(Exception exception) {
            exception.printStackTrace();
        } finally {
            try {
                _server.close();
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
    }

    static public void main(String[] argv) {
        new HTTP_Server(HTTP_Server._server_port, HTTP_Server._server_backlog);
    }
}
