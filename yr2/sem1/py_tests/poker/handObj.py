from deckObj import Deck

class Hand(object):

    def __init__(self,dec): 
        amount=5
        self.own=[]
        #shuf=input("Shuffle deck first? ('y' for yes):")
        #if shuf is 'y': dec.deckShuf()

        for i in range(amount):
            self.__drawCard(dec)

    def __str__(self):
        return self.__prtHand()

    def __repr__(self):
        return self.__str__()

    def __drawCard(self,dec):
        self.own.append(dec.pile.pop())
        
            
    def returnHand(self,dec):
        try:
            while True:
                dec.pile.append(self.own.pop())
        except:
                pass


    def __prtHand(self):
        say="Your Hand:"
        for ca in self.own:
            say+="\n   "+ca.__str__()
        return say


    def sortHand(self,dec):
        done=0
        while not done:
            done=1
            for i in range(len(self.own)-1):
                tmp=self.own[i+1]
                if dec.value.index(tmp.v) >  dec.value.index(self.own[i].v):
                    done=0
                    self.own[i+1]=self.own[i]
                    self.own[i]=tmp
    
    
    def __valMatch(self):
        tally=1
        for i in range(len(self.own)-1):
            if self.own[i].v is self.own[i+1].v:
                tally+=1
        return tally

        
    def __hasStraight(self,dec):
        for i in range(len(self.own)-1):
            if dec.value.index(self.own[i].v) is not dec.value.index(self.own[i+1].v)+1:
                if i is 0 and (self.own[0].v is "Ace" and self.own[4].v is "2"): break
                return False
        return True

    def __hasFlush(self):
        su=self.own[0].s
        for ca in self.own:
            if ca.s is not su:
                return False
        return True

    def __hasPoker(self):
        return self.__valMatch() is 4 and self.own[1].v is self.own[2].v and self.own[2].v is self.own[3].v

    def __hasHouse(self):
        return self.__valMatch() is 4

    def __hasThree(self):
        if self.own[2].v is self.own[1].v and self.own[2].v is self.own[3].v:
            return True
        elif self.own[2].v is self.own[0].v and self.own[2].v is self.own[1].v:
            return True
        elif self.own[2].v is self.own[3].v and self.own[2].v is self.own[4].v:
            return True
        else:
            return False

    def __has2Pair(self):
         return self.__valMatch() is 3

    def __hasPair(self):
        return self.__valMatch() is 2
    
    def findTricks(self,dec):
        self.sortHand(dec)
        self.score=0

        if self.__hasFlush() and self.__hasStraight(dec):
            if self.own[0].v is "Ace":
                self.score=9
                return "You have a Royal Flush !"
            self.score=8
            return "You have a Straight Flush"

        if self.__hasPoker():
            self.score=7
            return "You have a 4 of a Kind"

        if self.__hasHouse():
            self.score=6
            return "You have a Full House"

        if self.__hasFlush():
            self.score=5
            return "You have a Flush"

        if self.__hasStraight(dec):
            self.score=4
            return "You have a Straight"

        if self.__hasThree():
            self.score=3
            return "You have a 3 of a Kind"

        if self.__has2Pair():
            self.score=2
            return "You have Two Pairs"

        if self.__hasPair():
            self.score=1
            return "You have a Pair"
        
        return "Nothing. {} high...".format(self.own[0].v)
        
