
import turtle
import math

class Ball(object):
    
    def __init__(self,turt,dX=0,dY=0,vX=0,vY=0,radius=1,sticky=1,forw=True,colour='red'):
        self.dX=dX
        self.dY=dY
        self.vX=vX
        self.vY=vY
        self.radius=radius
        self.colour=colour
        self.forward=forw
        self.sticky=sticky
        turt.up()
        turt.goto(self.dX,self.dY)
        turt.dot(self.radius,self.colour)
        turt.down()


    def __str__(self):
        return "This is a {} ball of radius {}".format(self.colour,self.radius)

    def __repr__(self):
        return self.__str__()

    def move(self,turt,G,Time):

        if(self.dY >0):
            #turt.up()   #these few line are just for neat trailing graphics
            #turt.goto(self.dX,self.dY)
            #turt.dot(self.radius,'white')
            #turt.dot(self.radius/3,'black')
            pass
   
        #self.vY=math.sqrt(self.vY**2+2*G*self.dY)
        if(G > 0):
            self.vY+=G*Time
            self.dY-=(self.vY*Time)+(G*(Time**2))/2
        else:
            self.vY+=G*Time
            self.dY+=(self.vY*Time)+(G*(Time**2))/2

        if (self.forward): self.dX+=self.vX*Time
        else: self.dX-=self.vX*Time

        #print("dist: {}\nvelo: {}".format(self.dY,self.vY))        

        if (self.dY > 0):
            #turt.up()
            turt.goto(self.dX,self.dY)
            #turt.dot(self.radius,self.colour)        
    
    
def main():

    t=turtle.Turtle()

    G=-9.8
    Time=0.2

    t.ht() #hide arrow
    t.pos() #gives position
    t.speed(100) # how fast it writes
    turtle.bgcolor('white') #bg color

    '''
    t.up()
    t.right(90)
    t.forward(300)
    t.down()
    t.left(90)
    '''
    t.forward(400)
    t.backward(800)

    #param:- turtle - dist_X - dist_Y - velocity_X - velocity_Y - stickiness/friction
    b1=Ball(t,-200,80,10,40,8,1.25)
    i=0
    while not (b1.dY < 1 and b1.vY < 1 and b1.vX < 1):
        i+=1
        print("\n\n\n-------- {} ---------\n\n\n".format(i+1))
        b1.move(t,G,Time)
        if(b1.vY<=0):
            G*=-1
            b1.vY=0
            #t.dot(b1.radius,b1.colour)
        if(b1.dY <=0):
            G*=-1
            b1.dY=0
            t.goto(b1.dX,b1.dY)
            b1.vY/=b1.sticky
            b1.vX/=b1.sticky
            #t.dot(b1.radius,b1.colour)
        if(b1.dX >= 80 or b1.dX <= -80): b1.foward=not b1.forward

    t.dot(b1.radius,b1.colour)

        
if __name__ == "__main__":
    main()
