from sailorObj import Sailor

mate=[]
for i in range(50):
    mate.append(Sailor())
    mate[i].walk()


while 1:
    done=1

    for i in range(50):
        if not (mate[i].bar or mate[i].boat or mate[i].drowned):
            done = 0
        mate[i].walk()

    if done is 1: break

dwn=0
drk=0
shp=0

for i in range(50):
    if mate[i].bar: drk+=1
    if mate[i].boat: shp+=1
    if mate[i].drowned: dwn+=1

print("Sailors drowned:",dwn)
print("Sailors drinking:",drk)
print("Sailors aboard:",shp)

if shp>=35:
    print("\nHooray, enough crew to set sail!")
else:
    print("\nDamn! Not enough crew to leave port!")
