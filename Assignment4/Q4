using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace Assignment4_348
{
    class Program
    {
        static void Main(string[] args)
        {
            // Rectangle test = Rectangle.Parse("Rectangle,4,10");
            // test.Print();
            // Console.WriteLine(test.GetPerimeter());
            // Console.WriteLine(test.GetArea());
            //
            // Circle test2 = Circle.Parse("Circle,10");
            // test2.Print();
            // Console.WriteLine(test2.GetPerimeter());
            // Console.WriteLine(test2.GetArea());
            
            Console.WriteLine("Q4 PART");
            Console.WriteLine();
            List<Shape> shapes = TextFileProcessor.Read(@"C:\Users\Lentzkie Sanon\RiderProjects\Q4\Q4\Shapes.txt");
            Console.WriteLine("The original list :");
            foreach (var line in shapes)
            {
                Console.WriteLine(line.ToString());
            }

            
            
            var orderByShape = from line in shapes orderby line.Name, line.GetArea() select line;
            Console.WriteLine("List ordered by shape name and area: ");
            foreach (var shape in orderByShape)
            {
                Console.WriteLine(shape.Name+ ": "+ shape.GetArea());
              
            }
            
            Console.WriteLine("List ordered by and perimeter only: ");
            var orderByPerimeter = from line in shapes orderby line.GetPerimeter() select line;
            foreach (var shape in orderByPerimeter)
            {
                Console.WriteLine(shape.Name+ ": "+ shape.GetPerimeter());
                
            }

            var myRectangle = from rectangle in shapes
                where rectangle.Name.Contains("Rectangle")
                select rectangle;
            
            Console.WriteLine("Summary information of rectangle");
            var avgPerimeterRectangle = myRectangle.Average(s => s.GetPerimeter());
            Console.WriteLine("Average perimeter: " +avgPerimeterRectangle);
            
            var avgAreaRectangle = myRectangle.Average(s => s.GetArea());
            Console.WriteLine("Average area: "+avgAreaRectangle);
            
            Console.WriteLine("Summary information of circle");
            var myCircle  = from circle in shapes
                where circle.Name.Contains("Circle")
                select circle;
            
            var avgPerimeterCircle = myCircle.Average(s => s.GetPerimeter());
            Console.WriteLine("Average perimeter: " +avgPerimeterCircle);
            
            var avgAreaCircle = myCircle.Average(s => s.GetArea());
            Console.WriteLine("Average area: "+avgAreaCircle);
            
            var avgPerimeter = shapes.Average(s => s.GetPerimeter());
            var avgArea = shapes.Average(s => s.GetArea());
            var totalShapes = shapes.Count;
            
            Console.WriteLine("Average perimeter of all shapes : "+ avgPerimeter);
            Console.WriteLine("Average area of all shapes : "+ avgArea);
            Console.WriteLine("Total shapes count : "+ totalShapes);










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

    public class TextFileProcessor
    {
        public static event EventHandler? LineRead;

        public static List<Shape> Read(String file)
        {
            List<Shape> shapes = new List<Shape>();
            string [] linesplit;
            var fileStream = File.OpenRead(file);
            StreamReader streamReader = new StreamReader(fileStream, Encoding.UTF8, true);
            
            String ?line;
            while ((line = streamReader.ReadLine()) != null)
            {
                linesplit = line.Split(",");
                if (linesplit[0].Equals("Rectangle")) {
                    Rectangle r = new Rectangle();
                    r = Rectangle.Parse(line);
                    shapes.Add(r);
                } else if (linesplit[0].Equals("Circle")) {
                    Circle c = new Circle();
                    c = Circle.Parse(line);
                    shapes.Add(c);
                }
                // Process line
                EventHandler ?handler = LineRead;
                //Console.WriteLine(line);
                handler?.Invoke(new Object(), new MyEventArgs(line));
            }

            return shapes;
        }
    }

    public class MyEventArgs : EventArgs
    {
        public string MyEventString { get; set; }

        public MyEventArgs(string myString)
        {
            this.MyEventString = myString;
        }
    }





}
