/* Java_URLConnection.java
Author: BSS9395
Update: 2023-03-10T22:47:00+08@China-Shanghai+08
Design: Java Standard Library: URLConnection
*/

import java.io.*;
import java.net.URL;
import java.net.URLConnection;
import java.nio.charset.StandardCharsets;
import java.util.List;
import java.util.Map;

/*
Chrome User-Agent, chrome://version/
*/
public class Java_URLConnection {
    static public String _HTTP_Get(String path, String param)
        throws Exception {
        if(param != null) {
            path += "?" + param;
        }
        URL url = new URL(path);
        URLConnection connection = url.openConnection();
        connection.setRequestProperty("Accept", "*/*");
        connection.setRequestProperty("Connection", "Keep-Alive");
        connection.setRequestProperty("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/111.0.0.0 Safari/537.36");
        connection.connect();

        System.out.println("===============================================================================");
        System.out.println(path);
        Map<String, List<String>> fields = connection.getHeaderFields();
        for(Map.Entry<String, List<String>> entry : fields.entrySet()) {
            System.out.printf("%s: %s%n", entry.getKey(), entry.getValue());
        }
        System.out.println("===============================================================================");

        InputStream stream = connection.getInputStream();
        byte[] content = stream.readAllBytes();
        return new String(content, 0, content.length, StandardCharsets.UTF_8);
    }

    static public String _HTTP_Post(String path, String param)
        throws Exception {
        URL url = new URL(path);
        URLConnection connection = url.openConnection();
        connection.setRequestProperty("Accept", "*/*");
        connection.setRequestProperty("Connection", "Keep-Alive");
        connection.setRequestProperty("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/111.0.0.0 Safari/537.36");
        connection.setDoOutput(true);
        connection.setDoInput(true);

        OutputStream output = connection.getOutputStream();
        output.write(param.getBytes(StandardCharsets.UTF_8));
        output.close();

        InputStream input = connection.getInputStream();
        byte[] content = input.readAllBytes();
        return new String(content, 0, content.length, StandardCharsets.UTF_8);
    }

    static public void main(String[] args)
        throws Exception {
        // _Get();
        _Post();
    }
    static public void _Get()
        throws Exception {
        String content = Java_URLConnection._HTTP_Get("https://www.baidu.com/", null);
        System.out.println(content);
    }
    static public void _Post()
        throws Exception {
        String content = Java_URLConnection._HTTP_Post("http://localhost:8080/tomcat/login.jsp", "name=bss9395&password=Pass");
        System.out.println(content);
    }
}
