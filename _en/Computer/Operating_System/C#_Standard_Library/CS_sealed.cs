/* CS_sealed.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# keyword: sealed
*/

using System;

class CS_sealed {
    public static void Main(string[] args) {
        Retangle retangle = new Retangle();
        Circle circle = new Circle();
        retangle._Area();
        circle._Area();
    }
    abstract class Area {
        public abstract void _Area();
    }
    class Retangle : Area {
        public double _width { get; set; } = 3.0;
        public double _height { get; set; } = 4.0;
        public sealed override void _Area() {
            Console.WriteLine("The area of retangle: {0}", _width * _height);
        }
    }
    sealed class Circle : Area {
        public const double _pi = 3.1415;
        public double _radius { get; set; } = 3.0;
        public override void _Area() {
            Console.WriteLine("The area of circle: {0}", _pi * _radius * _radius);
        }
    }
}
