__author__ = 'mark'

class Mammal(object):
    population = 0

    def __init__(self, age=0):
        self.age = age
        Mammal.population += 1

    def __str__(self):
        return "I am a mammal of age {} but I am also a ".format(self.age)

class Cat(Mammal):

    population = 0
    
    def __init__(self, name='Puss', age=0):
        self.name = name
        self.age = age
        self.lives = 9
        Mammal.__init__(self, age)
        Cat.population += 1

    def __str__(self):
        return Mammal.__str__(self) + "cat called {}".format(self.name)


class Dog(Mammal):

    population = 0

    def __init__(self, name='Wuff', age=0):
        self.__name = name
        self.__age = age
        Mammal.__init__(self, age)
        Dog.population += 1

    def __str__(self):
        return "{} is {} years old".format(self.__name, self.__age)

    def bark(self):
        return "{} says woof!".format(self.__name)

    @property
    def age(self):
        return self.__age

    @age.setter
    def age(self, age):
        self.__age = age
        print("I'm setting age to {} ...".format(self.__age))

    @property
    def name(self):
        return self.__name

    #age = property(fget=get_age, fset=set_age)

fido = Dog("fido", 2)
spot = Dog("spot", 3)

fido.age += 2
print(fido.name)
print(fido.age)

spot.bark()

dogs = []

for i in range(10):
    dogs.append(Dog("mutt"+str(i)))

