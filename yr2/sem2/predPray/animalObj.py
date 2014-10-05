
class Animal(object):

    def __init__(self, breed=5,life=20):
        self.breedTime=breed
        self.lifeSpan=life

    def __str__(self):
        return "This is an Animal with {} days left to live".format(self.lifeSpan)

    def __repr__(self):
        return self.__str__()
