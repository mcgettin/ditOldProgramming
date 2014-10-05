from starObj import Star
from planetObj import Planet

G=0.1
Time=5


#optimised for my screen
s1=Star(50,5000,'Sol','yellow')

'''
change planets' initial config here
'''
p1=Planet(.4,100,60,0,2.7,'p1','green')
p2=Planet(.9,500,120,0.8,2,'p2','blue') #starts off veering to the right
p3=Planet(1.5,900,300,0,1.05,'p3','red')
p4=Planet(1.2,2900,580,-0.3,0.65,'p4','purple') #starts off veering to the left

for i in range(int(2500/Time)):

    print("\n\n\n-------- {} ---------\n\n\n".format(i+1))
    p1.move(G,s1.mass,Time)
    p2.move(G,s1.mass,Time)
    p3.move(G,s1.mass,Time)
    p4.move(G,s1.mass,Time)
   

