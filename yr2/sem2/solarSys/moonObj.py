from sphereObj import Sphere
import math
import turtle

class Moon(Sphere):

    def __init__(self,planet=None,radius=10,mass=100,distance=4,veloX=0,veloY=0,name="moon",colour="grey"):
        super().__init__(radius,mass)
        self.turt=turtle.Turtle()
        self.planet=planet
        self.radius=radius
        self.mass=mass
        self.name=name
        self.colour=colour
        self.distance=distance
        self.dX=distance
        self.dY=0
        self.vX=veloX
        self.vY=veloY

        self.turt.up()
        self.turt.shape("circle")
        self.turt.shapesize(self.radius,self.radius,1)
        self.turt.color(self.colour)
        self.turt.goto(distance+planet.distance,0)
        #self.turt.dot(self.radius,self.colour)
        self.turt.down()

    def __str__(self):
        return "This is the moon '{}' orbiting '{}':\n   radius = {}\n   mass = {}\n   distance(from planet) = {}\n  " \
                        " velocity = {},{}\n   colour = {}\n"\
                        .format(self.nameself.planet.name,self.radius,self.mass,self.distance,self.vX,self.vY,self.colour)

    def __repr__(self):
        return self.__str__() 

    '''See where the formuli are implemented here'''
    def move(self,G,time,i):

        print("['{}']".format(self.name))
        if not i%3: self.turt.down()
        else:self.turt.up()

        aX=(G*self.planet.mass*(-self.dX))/(self.distance**3)
        aY=(G*self.planet.mass*(-self.dY))/(self.distance**3)

        print("{},{}".format(aX,aY))

        self.vX=(aX*time)+self.vX
        self.vY=(aY*time)+self.vY

        print("{},{}".format(self.vX,self.vY))
        
        self.dX+=(time*self.vX)
        self.dY+=(time*self.vY)

        self.distance=math.sqrt(self.dX**2+self.dY**2)

        print("{},{}\n{}\n".format(self.dX,self.dY,self.distance))
        
        self.turt.goto((self.dX+self.planet.dX),(self.dY+self.planet.dY))
        
