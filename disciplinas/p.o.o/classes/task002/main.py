class Triangle:
    def __init__(self, sides):
        self.sides = sides

    def calculate_perimeter(self):
        return sum(self.sides)

    def biggest_side(self):
        return max(self.sides)

sides_inputs = input("Enter triangle measurements (separated by space):\n")
values = sides_inputs.split()
sides = [float(value) for value in values]

triangle1 = Triangle(sides)

print(f"The perimeter of the triangle above is: {triangle1.calculate_perimeter()}")
print(f"The biggesst side of the triangle above is: {triangle1.biggest_side()}")
