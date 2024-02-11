class Car:
    # Constructor method to initialize attributes
    def __init__(self, make, model, year, mileage):
        self.make = make
        self.model = model
        self.year = year
        self.mileage = mileage

    # Method to set make
    def set_make(self, make):
        self.make = make

    # Method to get make
    def get_make(self):
        return self.make

    # Similarly, write methods to set and get other attributes
  
    def get_model(self):
        return self.model

# Creating an instance of the Car class
my_car = Car("Toyota", "Camry", 2020, 5000)

# Printing attribute values
print("Make:", my_car.get_make())
# Similarly, print other attribute values
print("Model :",my_car.get_model())