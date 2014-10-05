from starObj import Star
from planetObj import Planet
from moonObj import Moon

G=0.1
Time=5


#optimised for my screen
s1=Star(10,15000,'Sol','yellow')

'''
change planets' initial config here
'''
p1=Planet(2, 1000, 250, 0, 2, 'p1', 'green')
m1=Moon(p1,1,100,40,0,1.6,'m1')

p2=Planet(3, 5000, 300, 0, 2, 'p2','blue')
p3=Planet(4, 9000, 500, 0, 1.63, 'p3','red')
p4=Planet(6, 49000, 700, 0, 1, 'p4','purple') 

for i in range(int(3000/Time)):
    
    print("\n\n\n-------- {} ---------\n\n\n".format(i+1))
    p1.move(G,s1.mass,Time)
    p2.move(G,s1.mass,Time)
    p3.move(G,s1.mass,Time)
    p4.move(G,s1.mass,Time)
    m1.move(G,Time,i)
    

