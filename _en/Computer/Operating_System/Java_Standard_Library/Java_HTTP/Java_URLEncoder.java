/* Java_URLEncoder.java
Author: BSS9395
Update: 2023-03-07T22:11:00+08@China-Shanghai+08
Design: Java Standard Library: URLEncoder
*/

import java.net.URLDecoder;
import java.net.URLEncoder;

public class Java_URLEncoder {
    static public void main(String[] args)
        throws Exception {
        _URLEncoder();
    }
    static public void _URLEncoder()
        throws Exception {
        String url = URLEncoder.encode("è­è²ÐÇ³½", "utf-8");
        System.out.println(url);

        String str = URLDecoder.decode(url, "utf-8");
        System.out.println(str);
    }
}
