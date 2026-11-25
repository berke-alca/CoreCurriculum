class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.days = age
        self.growthWeek = 0.0

    def grow(self):
        self.height += 0.8
        self.growthWeek += 0.8

    def age(self):
        self.days += 1

    def show(self):
        print(f"{self.name}: {self.height}cm, {self.days} days old\n")


print("=== Garden Plant Growth ===")
berkesPflanze = Plant("Rose", 25.0, 30)
berkesPflanze.show()
for a in range(1, 8):
    print(f"=== Day {a} ===")
    berkesPflanze.grow()
    berkesPflanze.age()
    berkesPflanze.show()
print(f"Growth this week: {berkesPflanze.growthWeek}cm")
