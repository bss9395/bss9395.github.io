/* HTTP_Client.java
Author: BSS9395
Update: 2023-0318T13:47:00+08@China-Shanghai+08
Design: HTTP Client
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

public class HTTP_Client {
    static public String _server_ipv4 = "localhost";
    static public int _server_port = 30000;

    public Socket _client = null;
    public HTTP_Client(String server_ipv4, int server_port) {
        try {
            _client = new Socket(server_ipv4, server_port);
            PrintStream output = new PrintStream(_client.getOutputStream());
            output.println("Hello, Server!");
            _client.shutdownOutput();

            BufferedReader input = new BufferedReader(new InputStreamReader(_client.getInputStream()));
            String line = null;
            while((line = input.readLine()) != null) {
                System.out.println(line);
            }
            _client.shutdownInput();
            _client.close();
        } catch (Exception exception) {
            exception.printStackTrace();
        } finally {
            try {
                _client.close();
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
    }

    static public void main(String[] argv) {
        new HTTP_Client(HTTP_Client._server_ipv4, HTTP_Client._server_port);
    }
}
