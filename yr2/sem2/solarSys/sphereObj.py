class Sphere(object):

    def __init__(self,radius=1,mass=1):
        self.radius=radius
        self.mass=mass

    def __str__(self):
        return "This is a generic Sphere:\n   radius = {}\n   mass = {}\n".format(self.radius,self.mass)

    def __repr__(self):
        return self.__str__()
