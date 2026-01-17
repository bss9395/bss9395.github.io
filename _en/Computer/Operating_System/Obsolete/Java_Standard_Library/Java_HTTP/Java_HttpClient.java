/* Java_HttpClient.java
Author: BSS9395
Update: 2023-03-23T14:32:00+08@China-Shanghai+08
Design: Java Standard Library: HttpClient
*/

import java.net.CookieHandler;
import java.net.CookieManager;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.time.Duration;

public class Java_HttpClient {
    static public void main(String[] argv)
        throws Exception {
        //_HttpClient();
        _CookieHandler();
    }
    static public void _HttpClient()
        throws Exception {
        HttpClient client = HttpClient.newBuilder()
                .version(HttpClient.Version.HTTP_2)
                .followRedirects(HttpClient.Redirect.NORMAL)
                .connectTimeout(Duration.ofSeconds(10))
                //.proxy(ProxySelector.of(new InetSocketAddress("106.15.93.22", 8080)))
                .build();
        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("http://www.baidu.com/"))
                .timeout(Duration.ofSeconds(10))
                .header("Content-Type", "text/html")
                .GET()
                .build();
        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
        System.out.printf("response.statusCode() = %s%n", response.statusCode());
        System.out.printf("response.headers()    = %s%n", response.headers());
        System.out.println("================================================================================");
        System.out.printf("%s", response.body());
    }
    static public void _CookieHandler() {
        CookieHandler.setDefault(new CookieManager());
        HttpClient client = HttpClient.newBuilder()
                .version(HttpClient.Version.HTTP_2)
                .followRedirects(HttpClient.Redirect.NORMAL)
                .connectTimeout(Duration.ofSeconds(10))
                .cookieHandler(CookieHandler.getDefault())
                .build();
        HttpRequest request_0 = HttpRequest.newBuilder()
                .timeout(Duration.ofSeconds(10))
                .uri(URI.create("http://localhost:8080/tomcat/login.jsp"))
                .header("Content-Type", "application/x-www-form-urlencoded")
                .POST(HttpRequest.BodyPublishers.ofString("name=bss9395&pass=password"))
                //.GET()
                .build();
        HttpRequest request_1 = HttpRequest.newBuilder()
                .timeout(Duration.ofSeconds(10))
                .uri(URI.create("http://localhost:8080/tomcat/secret.jsp"))
                .header("Content-Type", "text/html")
                .GET()
                .build();
        client.sendAsync(request_0, HttpResponse.BodyHandlers.ofString())
                .thenApply((response_0) -> {
                    return new Object[] {
                            response_0.statusCode(), response_0.body()
                    };
                }).thenAccept((response_0) -> {
                    System.out.printf("statusCode() = %s%n", response_0[0]);
                    System.out.printf("body()       = %s", response_0[1]);
                    System.out.println("================================================================================");
                    client.sendAsync(request_1, HttpResponse.BodyHandlers.ofString())
                            .thenAccept((response_1) -> {
                                System.out.printf("statusCode() = %s%n", response_1.statusCode());
                                System.out.printf("body()       = %s", response_1.body());
                            });
                });

        System.out.println("at the end.");
        while(true);
    }
}
