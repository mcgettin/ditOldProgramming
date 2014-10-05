import turtle

class Wall(object):

    def __init__(self,x=100,y=0,height=100,width=5,friction=1):
        self.turt=turtle.Turtle()
        self.x=x
        self.y=y
        self.height=height
        self.width=width
        self.friction=friction

        self.turt.ht()
        self.turt.up()
        self.turt.goto(self.x,self.y)
        self.turt.pensize(self.width)
        self.turt.left(90)
        self.turt.forward(self.height)

    def __str__(self):
        return "This is a wall at pos ({},{}) at the base and of height {}".format(self.x,self.y,self.height)

    def __repr__(self):
        return self.__str__()

    def chkHit(self,objX,objY,direc):
        if direct: return (objX >= self.x and objY <= self.height and objY >= self.y)
        else: return (objX <= self.x and objY <= self.height and objY >= self.y)

    def rebound(self,objX,direct):
        objX=self.x
        direct=!direct
