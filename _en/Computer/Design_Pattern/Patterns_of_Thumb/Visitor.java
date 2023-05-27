/* Visitor.java
Author: BSS9395
Update: 2023-05-27T15:47:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Visitor
*/

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;

abstract class AVisitor {
    abstract public void _Visit_Float(Float value);
    abstract public void _Visit_String(String value);
    abstract public void _Visit(Object value);
}

public class Visitor extends AVisitor {
    public void _Visit_Float(Float value) {
        System.out.println(value);
    }

    public void _Visit_String(String value) {
        System.out.println(value);
    }

    public void _Visit(Object object) {
        if (object instanceof Float) {
            _Visit_Float((Float)object);
        } else if(object instanceof String) {
            _Visit_String((String)object);
        } else if(object instanceof Collection) {
            Iterator iter = ((Collection)object).iterator();
            while(iter.hasNext()) {
                Object cell = iter.next();
                _Visit(cell);
            }
        }
    }

    public static void main(String[] args) {
        List list = new ArrayList();
        list.add(new Float(1.5));
        list.add(new String("abc"));
        List collection = new ArrayList();
        collection.add(new Float(2.5));
        collection.add(new String("def"));
        list.add(collection);

        AVisitor visitor = new Visitor();
        visitor._Visit(list);
    }
}
