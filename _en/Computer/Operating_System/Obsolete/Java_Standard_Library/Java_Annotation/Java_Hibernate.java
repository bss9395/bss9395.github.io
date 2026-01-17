/* Java_Hibernate.java
Author: BSS9395
Update: 2023-02-05T22:48:00+08@China-Shanghai+08
Design: Java Hibernate
*/

import javax.annotation.processing.AbstractProcessor;
import javax.annotation.processing.RoundEnvironment;
import javax.annotation.processing.SupportedAnnotationTypes;
import javax.annotation.processing.SupportedSourceVersion;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.Element;
import javax.lang.model.element.ElementKind;
import javax.lang.model.element.Name;
import javax.lang.model.element.TypeElement;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.lang.annotation.*;
import java.util.Set;

class Custom_Annotation {
    @Retention(RetentionPolicy.SOURCE)
    @Target(ElementType.TYPE)
    @Documented
    @interface Persistent {
        String _Table();
    }

    @Retention(RetentionPolicy.SOURCE)
    @Target(ElementType.FIELD)
    @Documented
    @interface ID {
        String _Column();

        String _Type();

        String _Generator();
    }

    @Retention(RetentionPolicy.SOURCE)
    @Target(ElementType.FIELD)
    @Documented
    @interface Property {
        String _Column();

        String _Type();
    }

    @SupportedSourceVersion(SourceVersion.RELEASE_17)
    @SupportedAnnotationTypes({"Custom_Annotation.Persistent", "Custom_Annotation.ID", "Custom_Annotation.Property"})
    static public class Annotation_Processor
            extends AbstractProcessor {
        @Override
        public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment environment) {
            System.out.println("public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment environment) {");

            PrintStream stream = null;
            try {
                for (Element element : environment.getElementsAnnotatedWith(Persistent.class)) {
                    Persistent persistent = element.getAnnotation(Persistent.class);
                    Name name = element.getSimpleName();
                    stream = new PrintStream(new FileOutputStream(String.format("%s.hbm.xml", name)));
                    stream.printf("<?xml version=\"1.0\"?>%n");
                    stream.printf("<!DOCTYPE hibernate-mapping PUBLIC%n");
                    stream.printf("	\"-//Hibernate/Hibernate Mapping DTD 3.0//EN\"%n");
                    stream.printf("	\"http://www.hibernate.org/dtd/hibernate-mapping-3.0.dtd\">%n");
                    stream.printf("<hibernate-mapping>%n");
                    stream.printf("	<class name=\"%s\" table=\"%s\">%n", element, persistent._Table());

                    for (Element enclosed : element.getEnclosedElements()) {
                        if (enclosed.getKind() == ElementKind.FIELD) {
                            ID id = enclosed.getAnnotation(ID.class);
                            if (id != null) {
                                stream.printf("        <id name=\"%s\" \"column=\"%s\" type=\"%s\">%n", enclosed.getSimpleName(), id._Column(), id._Type());
                                stream.printf("        <generator class=\"%s\"/>%n", id._Generator());
                                stream.printf("        </id>%n");
                            }

                            Property property = enclosed.getAnnotation(Property.class);
                            if (property != null) {
                                stream.printf("        <property name=\"%s\" column=\"%s\" type=\"%s\"/>%n", enclosed.getSimpleName(), property._Column(), property._Type());
                            }
                        }
                    }

                    stream.printf("	</class>%n");
                    stream.printf("</hibernate-mapping>%n");
                }
            } catch (FileNotFoundException exception) {
                exception.printStackTrace();
            } finally {
                if (stream != null) {
                    try {
                        stream.close();
                    } catch (Exception exception) {
                        exception.printStackTrace();
                    }
                }
            }
            return true;
        }
    }
}

@Custom_Annotation.Persistent(_Table = "person")
public class Java_Hibernate {
    @Custom_Annotation.ID(_Column = "person_id", _Type = "integer", _Generator = "identity")
    private int _id;
    @Custom_Annotation.Property(_Column = "person_name", _Type = "string")
    private String _name;
    @Custom_Annotation.Property(_Column = "person_age", _Type = "integer")
    private int _age;

    public Java_Hibernate() {

    }
    public Java_Hibernate(int id, String name, int age) {
        _id = id;
        _name = name;
        _age = age;
    }

    public void set_id(int id) {
        _id = id;
    }
    public int get_id() {
        return _id;
    }
    public void set_name(String name) {
        _name = name;
    }
    public String get_name() {
        return _name;
    }
    public void set_age(int age) {
        _age = age;
    }
    public int get_age() {
        return _age;
    }
}