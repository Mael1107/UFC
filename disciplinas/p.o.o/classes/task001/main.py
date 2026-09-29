# class Car:
#     def __init__(self, m, y, c ):
#         self.model = m
#         self.year = y
#         self.color = c

#     def showCar(self):
#         return f"Model: {self.model}"

# civic = Car("Civic", 2010, "Black")

# print(civic.showCar)


class Person:
    def __init__(self, name, year_birth, tall, race):
        self.name = name
        self.year_birth = year_birth
        self.tall = tall
        self.race = race

    def greeting(self):
        return f"Hi, my name is Ismael, I'm {2026 - self.year_birth} years old, {self.tall} of tall and I'm {self.race}."

ismael = Person("Ismael", 2007, 1.82, "negão")

print(ismael.greeting())