
class Card(object):


    def __init__(self,val="Ace",su="Spades"):
        self.s=su
        self.v=val
        
                
    def __str__(self):
        return "{} of {}".format(self.v,self.s)


    def __repr__(self):
        return self.__str__()

    def __name__(self):
        return "Card"
