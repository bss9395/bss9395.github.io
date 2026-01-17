/* Java_Custom_Annotation.java
Author: BSS9395
Update: 2023-02-05T16:28:00+08@China-Shanghai+08
Design: Java Language Feature: Custom Annotation
*/

import java.lang.annotation.*;

public class Java_Custom_Annotation {
    @Retention(RetentionPolicy.RUNTIME)
    @Target(ElementType.TYPE)
    @Repeatable(ITags.class)
    public @interface ITag {
        String _version() default "version_1_0";
        String _id() default "1156";
    }

    @Retention(RetentionPolicy.RUNTIME)
    @Target(ElementType.TYPE)
    public @interface ITags {
        ITag[] value();
        //int _count() default 0;
    }

    @ITag(_version="version_3_0", _id="1157")
    @ITag(_version="version_11_0", _id="1111")
    static public class Base {

    }

    static public void main(String[] args) {
        _Custom();
    }
    static public void _Custom() {
        ITag[] tags = Base.class.getDeclaredAnnotationsByType(ITag.class);
        for(int i = 0; i < tags.length; i += 1) {
            System.out.printf("%s -> %s %n", tags[i]._version(), tags[i]._id());
        }

        ITags itags = Base.class.getDeclaredAnnotation(ITags.class);
        System.out.println(itags);
    }
}
