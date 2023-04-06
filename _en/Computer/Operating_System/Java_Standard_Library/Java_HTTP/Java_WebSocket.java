/* Java_WebSocket.java
Author: BSS9395
Update: 2023-03-23T19:56:00+08@China-Shanghai+08
Design: Java Standard Library: WebSocket
*/

import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.WebSocket;
import java.util.concurrent.CompletionStage;

public class Java_WebSocket {
    static public void main(String[] argv)
        throws Exception {
        _WebSocket();
    }
    static public void _WebSocket()
        throws Exception {
        WebSocket.Listener listener = new WebSocket.Listener() {
            @Override
            public void onOpen(WebSocket socket) {
                System.out.printf("[onOpen] %n");
                socket.sendText("Hello, Server!", true);
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
        client.newWebSocketBuilder().buildAsync(URI.create("ws://localhost:8080/tomcat/WebSocket"), listener);
        Thread.sleep(3000);
    }
}
