# Importing math for Pi

import math


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

    def perimeter(self):
        return 2 * math.pi * self.radius

    def area(self):
        return math.pi * self.radius * self.radius


class Ellipse(Shape):  # Class Ellipse inherit from Shape
    def __init__(self, a, b):
        super().__init__()
        if (a < b):
            temp = b
            self.b = a
            self.a = temp
        else:
            self.a = a
            self.b = b

    def area(self):
        if (math.pi * self.a * self.b) < 0:#check if result is negative
            return None
        return math.pi * self.a * self.b

    def eccentricity(self):
        if ((self.a * self.a) - (self.b * self.b)) < 0:
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

    def perimeter(self):
        return 2 * math.sqrt((self.p * self.p) + (self.q * self.q))

    def area(self):
        if (self.p * self.q) / 2 <0:#check if result negative
            return None
        return (self.p * self.q) / 2

    def inradius(self):
        if ((self.p * self.q) / (2 * math.sqrt((self.p * self.p) + (self.q * self.q)))) < 0:#checking if result is negative
            print('In-radius ', end='')
            return None
        else:
            print('In-radius ', end='')
            return (self.p * self.q) / (2 * math.sqrt((self.p * self.p) + (self.q * self.q)))

# Shape form
Form1 = Shape()
Form1.print()

#Circle form
Form2 = Circle(3)
Form2.print()

#Ellipse form
Form3 = Ellipse(-1, 9)
Form3.print()
print(Form3.eccentricity())

#Rhombus form
Form4 = Rhombus(-1,2)
Form4.print()
print(Form4.inradius())
