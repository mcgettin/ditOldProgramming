from ballObj import Ball
from wallObj import Wall

def main():

    G=-4
    Time=0.1

    floor=0

    #param:- turtle - dist_X - dist_Y - velocity_X - velocity_Y - radius - stickiness/friction
    b1=Ball(0,80,30,30,10,1)
    w1=Wall(200,0,400,2)
    i=0
    while not (b1.dY < 1 and b1.vY < 1 and b1.vX < 1): #i.e. while still has energy
        i+=1
        
        print("\n\n\n-------- {} ---------\n\n\n".format(i))
        
        if(b1.dY < floor): G=b1.bounce(G)
        if(b1.vY < floor): G=b1.peak(G)

      
        if w1.chkHit(b1.dX,b1.dY,b1.forward):
            b1.dX=w1.x
            b1.forward=not b1.forward
            b1.turt.goto(w1.x,b1.dY)
            b1.vY/=b1.sticky
            b1.vX/=b1.sticky
            b1.turt.dot(b1.radius,b1.colour)
            print(b1.forward)
        b1.move(G,Time)
        if i is 300:
            time=-0.05
if __name__ == "__main__":
    main()

