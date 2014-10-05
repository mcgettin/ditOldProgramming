class Card(object):

    def validCard(self):
        suit=["Hearts","Diamonds","Spades","Clubs"]
        value=["2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"]
        if self.s in suit and self.v in value: return 1
        else:
            print("\ninvalid card. try again")
            self.v=input("value:")
            self.s=input("suit:")
            return 0

    
    def __init__(self,val="Ace",su="Spades"):
        self.s=su
        self.v=val
        valid=0
        while not valid:
            valid=self.validCard()
            
                
    def showCard(self):
        print("your card is the {} of {}".format(self.v,self.s))

    
