/* Java_Reference.java
Author: BSS9395
Update: 2023-01-06T21:55:00+08@China-Shanghai+08
Design: Java Standard Library: WeakReference, PhantomReference
*/


import java.lang.ref.PhantomReference;
import java.lang.ref.ReferenceQueue;
import java.lang.ref.WeakReference;

public class Java_Reference {
    static public void main(String[] args) {
        _WeakReference();
        // _PhantomReference();
    }
    static public void _WeakReference() {
        System.out.println("static public void _WeakReference() {");
        String str = new String("Weak");
        WeakReference<String> weak = new WeakReference<String>(str);
        str = null;
        System.out.println(weak.get());
        System.gc();
        System.runFinalization();
        System.out.println(weak.get());
    }
    static public void _PhantomReference() {
        System.out.println("static public void _PhantomReference() {");
        String str = new String("Phantom");
        ReferenceQueue<String> refer = new ReferenceQueue<String>();
        PhantomReference<String> phantom = new PhantomReference<String>(str, refer);
        str = null;
        System.out.println(phantom.get());
        System.gc();
        System.runFinalization();
        System.out.println(refer.poll() == phantom);
    }
}
