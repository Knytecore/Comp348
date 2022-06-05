# Importing math for Pi

import math  # importing math for the square root


class Shape:  # initial class
    Id = 0

    def __init__(self):  # constructor
        Shape.Id += 1

    def print(self):  # print method
        print(self.Id, ': ', end='')
        print(type(self).__name__, ', ', end='')  # printing the name of the class
        print('Perimeter: ', self.perimeter(), ', ', end='')
        print('Area: ', self.area(), )

    def perimeter(self):  # printing the perimeter
        return None

    def area(self):  # printing the area
        return None


class Circle(Shape):  # class Circle inherits from Shape
    def __init__(self, radius):
        super().__init__()
        self.radius = radius

    def perimeter(self):  # overriding the perimeter method inherited from Shape
        return 2 * math.pi * self.radius

    def area(self):  # overriding the area method inherited from Shape
        return math.pi * self.radius * self.radius


class Ellipse(Shape):  # Class Ellipse inherit from Shape
    def __init__(self, a, b):
        super().__init__()
        if a < b:  # Checking for the major and minor axes. If a is smaller than b, we switch them
            temp = b
            self.b = a
            self.a = temp
        else:
            self.a = a
            self.b = b

    def area(self):  # overriding the area method inherited from Shape
        if (math.pi * self.a * self.b) < 0:  # check if result is negative
            return None
        return math.pi * self.a * self.b

    def eccentricity(self):
        if ((self.a * self.a) - (self.b * self.b)) < 0:  # check if result is negative
            print('Linear Eccentricity ', end='')
            return None
        else:
            print('Linear Eccentricity ', end='')
            return math.sqrt((self.a * self.a) - (self.b * self.b))


class Rhombus(Shape):  # Class Rhombus inherits from Shape
    def __init__(self, p, q):
        super().__init__()
        self.p = p
        self.q = q

    def perimeter(self):  # overriding the perimeter method inherited from Shape
        return 2 * math.sqrt((self.p * self.p) + (self.q * self.q))

    def area(self):  # overriding the area method inherited from Shape
        if (self.p * self.q) / 2 < 0:  # check if result negative
            return None
        return (self.p * self.q) / 2

    def inradius(self):
        if ((self.p * self.q) / (
                2 * math.sqrt((self.p * self.p) + (self.q * self.q)))) < 0:  # checking if result is negative
            print('In-radius ', end='')
            return None
        else:
            print('In-radius ', end='')
            return (self.p * self.q) / (2 * math.sqrt((self.p * self.p) + (self.q * self.q)))


print('Q5')
print("")
# Shape form
Form1 = Shape()
Form1.print()

# Circle form
Form2 = Circle(3)
Form2.print()

# Ellipse form
Form3 = Ellipse(-1, 9)
Form3.print()
print(Form3.eccentricity())

# Rhombus form
Form4 = Rhombus(-1, 2)
Form4.print()
print(Form4.inradius())

print("")
print("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
print("Q6")
print("")

# Opening and printing the content of the list
lines = []  # will be used to store what is read in here
fo = open("test.txt", "r")
for line in fo:
    items = line.strip('\n').split(" ")
    print(items)  # printing what is in the text file
    lines.append(items)

print("")

# variables to keep track of the shapes present
ShapeCount = 0
CircleCount = 0
EllipseCount = 0
RhombusCount = 0

# Nested loop to read the content stored in the list and use it to create objects
for line in lines:
    for element in line:
        if element == 'shape':
            fo = Shape()
            fo.print()
            ShapeCount += 1
        elif element == 'rhombus':
            s = int(line[1])
            t = int(line[2])
            rhombus = Rhombus(s, t)
            if s * t < 0:
                print('ERROR : Invalid Rhombus')
            else:
                rhombus.print()
                print(rhombus.inradius())
            ShapeCount += 1
            RhombusCount += 1
        elif element == 'circle':
            r = int(line[1])
            circle = Circle(r)
            circle.print()
            ShapeCount += 1
            CircleCount += 1
        elif element == 'ellipse':
            c = int(line[1])
            d = int(line[2])
            ellipse = Ellipse(c, d)
            if c * d < 0:
                print('ERROR : Invalid Ellipse')
                ellipse.print()
            else:
                ellipse.print()
                print(ellipse.eccentricity())
            ShapeCount += 1
            EllipseCount += 1

print("")
print("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
# Q7
print("Q7")
print("")

# Store the information about the shapes and their count in a dictionary
Shapesdiction = {
    "Circle(s)": CircleCount,
    "Ellipse(s)": EllipseCount,
    "Rhombus(es)": RhombusCount,
    "Shape(s)": ShapeCount
}
print("Statistics")
print("")
for shape in Shapesdiction.keys():
    print(shape, ': ', Shapesdiction[shape], "\n")
