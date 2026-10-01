import math

class Circle:
    def __init__(self, radius):
        self.radius = radius
    def calculate_area(self):
        area = math.pi * (self.radius ** 2)
        return round(area, 2)
    def calculate_perimeter(self):
        perimeter = 2 * math.pi * self.radius
        return round(perimeter, 2)

circle1 = Circle(5)
print(f"Area of circle: {circle1.calculate_area()}")
print(f"Perimeter of circle: {circle1.calculate_perimeter()}")
