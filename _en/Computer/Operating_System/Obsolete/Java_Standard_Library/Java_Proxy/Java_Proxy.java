/* Java_Proxy.java
Author: BSS9395
Update: 2023-03-22T21:10:00+08@China-Shanghai+08
Design: Java Standard Library: Proxy
*/

import java.io.*;
import java.net.*;

public class Java_Proxy {
    public Java_Proxy(String uri)
        throws Exception {
        URL url = new URL(uri);
        Proxy proxy = new Proxy(Proxy.Type.HTTP, new InetSocketAddress(Java_Proxy._proxy_ipv4, Java_Proxy._proxy_port));
        URLConnection connection = url.openConnection(proxy);
        connection.setConnectTimeout(5000);
        BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
        PrintStream print = new PrintStream("cached.data");
        String line = null;
        while((line = reader.readLine()) != null) {
            System.out.println(line);
            print.println(line);
        }
    }

    static public String _proxy_ipv4 = "106.15.93.22";
    static public int _proxy_port = 8080;
    static public void main(String[] argv)
        throws Exception {
        new Java_Proxy("http://www.baidu.com/");
    }
}
