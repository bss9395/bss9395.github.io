/* Java_Proxy.java
Author: BSS9395
Update: 2023-03-05T15:23:00+08@China-Shanghai+08
Design: Java Standard Library: Proxy
*/

import java.lang.reflect.*;

public class Java_Proxy {
    static interface Inter {
        void _Greet(String hello);
        void _Info(String info);
    }
    static class Imple implements Inter {
        @Override
        public void _Greet(String hello) {
            System.out.println(hello);
        }
        @Override
        public void _Info(String info) {
            System.out.println(info);
        }
    }
    static class Util {
        static public void _Beg() {
            System.out.printf("%s%s%s%n", "==========", "Beg", "==========");
        }
        static public void _End() {
            System.out.printf("%s%s%s%n", "==========", "End", "==========");
        }
    }

    static class Invocation implements InvocationHandler {
        private Object _target = null;
        private Invocation(Object target) {
            _target = target;
        }
        @Override
        public Object invoke(Object proxy, Method method, Object[] args)
            throws Exception {
            Util._Beg();
            Object result = method.invoke(_target, args);
            Util._End();
            return result;
        }
    }
    static class Proxy_Factory {
        static public Object getProxy(Object target) {
            Invocation invocation = new Invocation(target);
            return Proxy.newProxyInstance(target.getClass().getClassLoader(), target.getClass().getInterfaces(), invocation);
        }
    }

    static public void main(String[] args) {
        Inter inter = (Inter) Proxy_Factory.getProxy(new Imple());
        inter._Greet("Hello, World!");
        inter._Info("none");
    }
}
