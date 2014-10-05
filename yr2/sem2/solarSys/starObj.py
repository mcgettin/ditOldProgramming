from sphereObj import Sphere
import turtle
class Star(Sphere):

    def  __init__(self,radius=500,mass=15000,name="star",colour="yellow"):
        super().__init__(radius,mass)
        self.turt=turtle.Turtle()
        self.radius=radius
        self.mass=mass
        self.name=name
        self.colour=colour

        turtle.bgcolor('black') #bg color
        self.turt.shape("circle")
        self.turt.shapesize(self.radius,self.radius,1)
        self.turt.color(self.colour)
    
        
    def __str__(self):
         return "This is the star '{}':\n   radius = {}\n   mass = {}\n   colour = {}\n"\
                        .format(self.name,self.radius,self.mass,self.colour)

    def __repr__(self):
        return self.__str__()
