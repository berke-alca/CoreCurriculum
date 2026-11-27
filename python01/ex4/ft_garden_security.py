class Plant:
    def __init__(self, name, weight):
        self.name = name
        self._weight = weight

    def get_weight(self):
        return self._weight

    def set_weight(self, weight):
        if weight < 0:
            print(f"{self.name}: Error, weight can't be negative")
            print("Weight update rejected")
        else:
            self._weight = weight
            print(f"Weight updated: {weight}kg")

    def show(self):
        print(f"{self.name}: {self._weight}kg")


rose = Plant("Rose", 10.0)
rose.show()
rose.set_weight(15)
rose.set_weight(-3)
rose.show()
