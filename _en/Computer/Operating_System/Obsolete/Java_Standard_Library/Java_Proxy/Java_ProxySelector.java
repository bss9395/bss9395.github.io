/* Java_ProxySelector.java
Author: BSS9395
Update: 2023-03-22T21:37:00+08@China-Shanghai+08
Design: Java Standard Library: ProxySelector
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.*;
import java.util.ArrayList;
import java.util.List;

public class Java_ProxySelector {
    static class Proxy_Selector extends ProxySelector {
        @Override
        public List<Proxy> select(URI uri) {
            List<Proxy> proxies = new ArrayList<Proxy>();
            proxies.add(new Proxy(Proxy.Type.HTTP, new InetSocketAddress("106.15.93.22", 8080)));
            return proxies;
        }

        @Override
        public void connectFailed(URI uri, SocketAddress address, IOException exception) {
            System.err.printf("URI = %s, SocketAddress = %s, IOException = %s%n", uri, address, exception);
        }
    }

    public Java_ProxySelector(String uri)
        throws Exception {
        URL url = new URL(uri);
        ProxySelector.setDefault(new Proxy_Selector());
        URLConnection connection = url.openConnection();
        connection.setConnectTimeout(5000);
        BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
        PrintStream print = new PrintStream("cached.data");
        String line = null;
        while((line = reader.readLine()) != null) {
            System.out.println(line);
            print.println(line);
        }
    }

    static public void main(String[] argv)
        throws Exception {
        new Java_ProxySelector("http://www.baidu.com/");
    }
}
