class Dog(object):

    dog_population = 0

    def __init__(self, name, age):
        self.__name = name
        self.__age = age
        Dog.dog_population += 1

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
    dogs.append(Dog("mutt"+str(i)), i)

