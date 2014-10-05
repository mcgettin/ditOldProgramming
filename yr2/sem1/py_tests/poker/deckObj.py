
from cardObj import Card
from random import shuffle

class Deck(object):
    
    value=["2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"]
    suit=["Hearts","Diamonds","Spades","Clubs"]
    
    def __init__(self):
        self.pile=[]
        for s in self.suit:
            for v in self.value:
                self.pile.append(Card(v,s))

        
    def prtDeck(self):
        for c in reversed(self.pile):
            print(c)
      

    def deckShuf(self):
        try:
            no=int(input("Shuffle how many times?:"))
        except ValueError:
            no=1
        for i in range(no):
            shuffle(self.pile)


    def __str__(self):
        return "This is a {} of {} {}s".format(self.__name__(),len(self.pile),self.pile[0].__name__())

    def __repr__(self):
        return self.__str__()
    
    def __name__(self):
        return "Deck"
