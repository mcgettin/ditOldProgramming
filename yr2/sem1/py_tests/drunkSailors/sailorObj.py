import random

class Sailor(object):

    def  __init__(self):
        self.x=2
        self.y=0
        self.drowned=False
        self.bar=False
        self.boat=False


    def __str__(self):
        if self.drowned:
            return "This sailor has drowned!"
        elif self.bar:
            return "This sailor has reurned to the bar!"
        elif self.boat:
            return "This sailor has returned to deck"
        else:
            return "This sailor is at position: ({},{})".format(self.x,self.y)

    def __repr__(self):
        return self.__str__()


    def walk(self):
        if self.drowned or self.bar or self.boat: pass
        
        direct=random.randint(0,9)
        if direct > 2:
            self.y+=1
        elif direct is 2:
            self.x-=1
        elif direct is 1:
            self.x+=1
        else:
            self.y-=1

        if self.x < 0 or self.x > 4:
            self.drowned=True
        elif self.y < 0:
            self.bar=True
        elif self.y is 19:
            self.boat=True

