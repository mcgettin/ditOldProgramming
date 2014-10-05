import turtle
import math

class Ball(object):
    
    def __init__(self,dX=0,dY=0,vX=0,vY=0,radius=1,sticky=1,forw=True,colour='red'):
        self.turt=turtle.Turtle()
        self.dX=dX
        self.dY=dY
        self.vX=vX
        self.vY=vY
        self.radius=radius
        self.colour=colour
        self.forward=forw
        self.sticky=sticky

        #self.turt.ht()
        self.turt.shape("circle")
        self.turt.shapesize(self.radius/10,self.radius/10,1)
        self.turt.up()
        self.turt.goto(self.dX,self.dY)
        #self.turt.dot(self.radius,self.colour)
        self.turt.down()


    def __str__(self):
        return "This is a {} ball of radius {}".format(self.colour,self.radius)

    def __repr__(self):
        return self.__str__()


    def move(self,G,T):

        if (self.dY > 0):
            self.turt.goto(self.dX,self.dY)
            
        self.vY+=G*T
        if (G > 0): self.dY-=(self.vY*T)+(G*(T**2))/2
        else: self.dY+=(self.vY*T)+(G*(T**2))/2

        
        if (self.forward): self.dX+=self.vX*T
        else: self.dX-=self.vX*T

        #print("[X]\ndist: {}\nvelo: {}".format(self.dX,self.vX))        
        #print("[Y]\ndist: {}\nvelo: {}".format(self.dY,self.vY))

    def bounce(self,G):
        G*=-1
        self.dY=0
        self.turt.goto(self.dX,self.dY)
        self.vY/=self.sticky
        self.vX/=self.sticky
        self.turt.dot(self.radius,self.colour)
        return float(G)
        

    def peak(self,G):
        G*=-1
        self.vY=0
        #self.turt.dot(self.radius,self.colour)
        return float(G)
        
