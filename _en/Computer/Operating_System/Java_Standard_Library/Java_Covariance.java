/* Java_Covariance.java
Author: BSS9395
Update: 2023-01-29T20:21:00+08@China-Shanghai+08
Design: Java Language Feature: Covariance
*/

import java.util.ArrayList;
import java.util.List;

public class Java_Covariance {
    static public class Canvas {
        public void _Draw_All(List<? extends Shape> shapes) {
            for(Shape shape : shapes) {
                shape._Draw(this);
            }
        }
    }
    static abstract public class Shape {
        abstract public void _Draw(Canvas canvas);
    }
    static public class Circle extends Shape {
        @Override
        public void _Draw(Canvas canvas) {
            System.out.printf("a circle on %s. %n", canvas);
        }
    }
    static public class Retangle extends Shape {
        @Override
        public void _Draw(Canvas canvas) {
            System.out.printf("a retangle on %s. %n", canvas);
        }
    }
    static public void main(String[] args) {
        List<Circle> shapes = new ArrayList<Circle>();
        shapes.add(new Circle());
        // shapes.add(new Retangle());

        Canvas canvas = new Canvas();
        canvas._Draw_All(shapes);
    }
}
