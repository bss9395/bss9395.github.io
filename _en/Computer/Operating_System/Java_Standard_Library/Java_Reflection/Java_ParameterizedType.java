/* Java_ParameterizedType.java
Author: BSS9395
Update: 2023-03-05T17:11:00+08@China-Shanghai+08
Design: Java Standard Library: ParameterizedType
*/

import java.lang.reflect.Field;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;
import java.util.Map;

public class Java_ParameterizedType {
    static public class Datum {
        public Map<String, Integer> _map;
    }

    static public void main(String[] args)
        throws Exception {
        // _getType();
        _ParameterizedType();
    }
    static public void _getType()
        throws Exception {
        Class<Datum> clazz = Datum.class;
        Field field = clazz.getDeclaredField("_map");

        Class<?> type = field.getType();
        System.out.println(type);
    }
    static public void _ParameterizedType()
        throws Exception {
        Class<Datum> clazz = Datum.class;
        Field field = clazz.getDeclaredField("_map");

        Type type = field.getGenericType();
        if(type instanceof ParameterizedType) {
            ParameterizedType para = (ParameterizedType) type;

            Type raw = para.getRawType();
            System.out.println(raw);

            Type[] args = para.getActualTypeArguments();
            for(int i = 0; i < args.length; i += 1) {
                System.out.println(args[i]);
            }
        }
    }
}
