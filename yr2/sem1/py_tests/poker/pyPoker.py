from handObj import Hand
from deckObj import Deck

print("Welcome to Py Poker")
d1=Deck()
d1.deckShuf()

perNo=int(input("How many players? (2-6):"))
pl=[]
for i in range(perNo):
    pl.append(Hand(d1))
    pl[i].findTricks(d1)

opt=0
while opt is not 2:
    opt=int(input("\nInput int Choice:\n1. Options\n2. Exit\n"))
    
    if opt is 1:
        cH=input("\nCheck hands? ('y' for yes):")
        if cH is 'y':
            for per in pl:
                print("\nPlayer",pl.index(per)+1)
                print(per)
                input("[press ENTER]")

        cW=input("\nCheck winner? ('y' for yes):")
        if cW is 'y':    
            perNo=pl[0].score
            winner=0
            for per in pl:
                if per.score > perNo:
                    perNo=pl[i].score
                    winner=pl.index(per)


            print("Winner is player",winner+1)
    elif opt is 2: break
