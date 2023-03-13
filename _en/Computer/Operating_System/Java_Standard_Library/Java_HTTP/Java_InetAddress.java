/* Java_InetAddress.java
Author: BSS9395
Update: 2023-03-06T23:02:00+08@China-Shanghai+08
Design: Java Standard Library: InetAddress
*/

import java.net.InetAddress;

public class Java_InetAddress {
    static public void main(String[] args)
        throws Exception {
        _InetAddress();
    }
    static public void _InetAddress()
        throws Exception {
        InetAddress name = InetAddress.getByName("www.baidu.com");
        System.out.printf("%s, %s == %s%n", name.getHostName(), name.getHostAddress(), name.isReachable(2000));

        InetAddress addr = InetAddress.getByAddress(new byte[] {127, 0, 0, 1});
        System.out.printf("%s, %s == %s%n", addr.getHostName(), addr.getHostAddress(), addr.isReachable(2000));
    }
}
