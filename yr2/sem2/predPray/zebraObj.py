from animalObj import Animal

class Zebra(Animal):

    def __init__(self,breed=5,life=20):
        super().__init__(breed,life)

        self.breedTime=breed
        self.lifeSpan=life

    def __str__(self):
        return "This is a Zebra with {} days left to live".format(self.lifeSpan)

    def __repr__(self):
        return self.__str__()


    def move(self):
        
