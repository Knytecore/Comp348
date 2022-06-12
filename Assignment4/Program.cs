using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment4_348
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello Camila");
            Rectangle test = Rectangle.Parse("Rectangle,4,10");
            test.Print();
            Console.WriteLine(test.GetPerimeter());
            Console.WriteLine(test.GetArea());

            Circle test2 = Circle.Parse("Circle,10");
            test2.Print();
            Console.WriteLine(test2.GetPerimeter());
            Console.WriteLine(test2.GetArea());

        }


    }

    public interface Shape
    {
        string Name
        {
            get
            {
                return this.GetType().Name;
            }
            set
            {
                this.Name = this.GetType().Name;
            }


        }
        double GetPerimeter();
        double GetArea();
    }

    public class Rectangle:Shape
    {
        double length;
        double width;
        string Name
        {
            get;
            set;


        }

        public Rectangle()
        {
            this.Name = "Rectangle";
            this.length = 10;
            this.width = 5;
        }

        public Rectangle(double length, double width)
        {
            this.Name = "Rectangle";
            this.length = length;
            this.width = width;
        }

        public double GetPerimeter()
        {
            return 2 * this.length + 2 * this.width;
        }

        public double GetArea()
        {
            return this.length * this.width;
        }

        public override String ToString()
        {
            return this.Name + "," + this.length + "," + this.width;
        }

        public static Rectangle Parse(String a)
        {
            string[] parameters = a.Split(',');
            String name = parameters[0];
            double length = Convert.ToDouble(parameters[1]);
            double width = Convert.ToDouble(parameters[2]);
            return new Rectangle(length, width);


        }
    }

    public partial class Circle:Shape
    {
        public double Radius;
        string Name
        {
            get;
            set;


        }

        public Circle()
        {
            this.Name = "Circle";
            this.Radius = 10;
        }

        public Circle(double Radius)
        {
            this.Name = "Circle";
            this.Radius = Radius;
        }

        public double GetPerimeter()
        {
            return 2* Math.PI * this.Radius;
        }

        public double GetArea()
        {
            return Math.PI * Math.Pow(this.Radius,2);
        }

        public override String ToString()
        {
            return this.Name + "," + this.Radius;
        }



    }

    public partial class Circle
    {
        public static Circle Parse(String a)
        {
            string[] parameters = a.Split(',');
            String name = parameters[0];
            double Radius = Convert.ToDouble(parameters[1]);
            return new Circle(Radius);


        }
    }

    public static class ShapeExtensions
    {
        public static void Print(this Shape a)
        {
            Console.WriteLine(a.ToString());
            
        }
    }





}
