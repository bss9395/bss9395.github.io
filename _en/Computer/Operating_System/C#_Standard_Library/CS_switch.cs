/* CS_switch.cs
Author: BSS9395
Update: 2022-05-31T15:11:00+08@China-Shanghai+08
Design: C# Keyword: switch
*/

using System;
using System.Collections.Generic;

class CS_switch {
    class Shape {

    }
    class Square : Shape {
        public double _side = 0.0;
    }
    class Circle : Shape {
        public double _radius = 0.0;
    }
    class Triangle : Shape {
        public double _height = 0.0;
    }
    public static void Main(String[] args) {
        _switch();
    }
    public static void _switch() {
        var shapes = new List<Shape>();
        shapes.Add(new Circle { _radius = 7.0 });
        shapes.Add(new Square { _side = 5.0 });
        shapes.Add(new Triangle { _height = 4.0 });
        shapes.Add((Square)null);

        foreach (var shape in shapes) {
            switch (shape) {
                case Circle circle:
                    Console.WriteLine($"1. a circle of radius {circle._radius}");
                    break;
                case Square square when square._side > 10:
                    Console.WriteLine($"2. a square of side {square._side}");
                    break;
                case Square square:
                    Console.WriteLine($"3. a square of side {square._side}");
                    break;
                case Triangle triangle:
                    Console.WriteLine($"4. a triangle of height {triangle._height}");
                    break;
                case null:
                    Console.WriteLine($"5. a null shape");
                    break;
                default:
                    throw new ArgumentException($"6. an unrecognized shape");
                    // break;
            }
        }
    }
}
