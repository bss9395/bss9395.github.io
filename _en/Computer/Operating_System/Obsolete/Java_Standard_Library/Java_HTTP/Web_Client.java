/* Web_Client.java
Author: BSS9395
Update: 2023-03-23T21:29:00+08@China-Shanghai+08
Design: Web Client
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.WebSocket;
import java.util.concurrent.CompletionStage;

public class Web_Client {
    public Web_Client(String link) {
        WebSocket.Listener listener = new WebSocket.Listener() {
            @Override
            public void onOpen(WebSocket socket) {
                System.out.printf("[onOpen] %n");
                socket.request(1);
            }
            @Override
            public CompletionStage<?> onText(WebSocket socket, CharSequence data, boolean last) {
                System.out.printf("[onText] %s%n", data);
                socket.request(1);
                return null;
            }
        };
        HttpClient client = HttpClient.newHttpClient();
        client.newWebSocketBuilder()
                .buildAsync(URI.create(link), listener)
                .thenAccept((socket) -> {
                    try {
                        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
                        String line = null;
                        while ((line = reader.readLine()) != null) {
                            socket.sendText(line, true);
                        }
                    } catch(Exception exception) {
                        exception.printStackTrace();
                    }
                }).join();
    }

    static public String _link = "ws://localhost:8080/tomcat/WebServer";
    static public void main(String[] args) {
        new Web_Client(Web_Client._link);
    }
}
