from animalObj import Animal

class Lion(Animal):

    def __init__(self,breed=5,life=20,food=4):
        super().__init__(breed,life)

        self.breedTime=breed
        self.lifeSpan=life
        self.starveTime=food

    def __str__(self):
        return "This is a Lion with {} days left to live".format(self.lifeSpan)

    def __repr__(self):
        return self.__str__()


