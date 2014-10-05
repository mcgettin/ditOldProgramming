import math

class Vector(object):

    def __init__(self,p1=0,p2=0):
        self.x=p1
        self.y=p2
        
    def __str__(self):
        return "vector: (0,0) , ({},{})".format(self.x,self.y)

    def __repr__(self):
        return self.__str__()

    def __add__(self,vect): #vector+vector
        return Vector(self.x+vect.x,self.y+vect.y)

    def __sub__(self,vect): #vector-vector
        return Vector(self.x-vect.x,self.y-vect.y)

    def __mul__(self,vect): #vector*vector
        return (self.x*vect.x)+(self.y*vect.y)
    
    def vMag(self): #rt(x^2 + y^2)
        return math.sqrt((self.x*self.x)+(self.y*self.y))
