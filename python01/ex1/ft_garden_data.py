class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def show(self):
        print(f"{self.name}: {self.height}cm, {self.age} days old")


print("=== Garden Plant Registry ===")
firPflanze = Plant("Rose", 25, 30)
secPflanze = Plant("Sunflower", 80, 45)
thirPflanze = Plant("Cactus", 125, 120)
firPflanze.show()
secPflanze.show()
thirPflanze.show()
