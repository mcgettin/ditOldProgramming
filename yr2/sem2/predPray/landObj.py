
class Land(object):

    def __init__(self,size=10):
        self.size=size
        self.grid=[[0]*size]*size

    def __str__(self):
        return "This is a {}x{} meter stretch of land".format(self.size,self.size)

    def __repr__(self):
        return self.__str__()
