class Clock(object):

    def __init__(self,hours=0,mins=0,sec=0):
        self.h=hours
        self.m=mins
        self.s=sec
    
    def realTime():
        import time
        clk=Clock((int)(time.strftime("%H")),(int)(time.strftime("%M")),(int)( time.strftime("%S")))
        return clk

    def strUpdate(self,strTime):
        part=strTime.strip("\n").split(":")
        self.h=(int)(part[0])
        self.m=(int)(part[1])
        self.s=(int)(part[2])
        
    def printClock(self):
        if self.h < 10:
            self.h = "0"+(str)(self.h)
        if self.m < 10:
            self.m = "0"+(str)(self.m)
        if self.s < 10:
            self.s = "0"+(str)(self.s)

        print("Time is: {}:{}:{}".format(self.h,self.m,self.s))

        self.h=(int)(self.h)
        self.m=(int)(self.m)
        self.s=(int)(self.s)

        
    def addClocks(self,other):
        clk=Clock()
        clk.h=self.h+other.h
        clk.m=self.m+other.m
        clk.s=self.s+other.s

        if clk.s >= 60:
            clk.s=clk.m%60
            clk.m+=1
        if clk.m >= 60:
            clk.m=clk.m%60
            clk.h+=1
        if clk.h >= 24:
            clk.h=clk.h%24
          
        return clk
            
