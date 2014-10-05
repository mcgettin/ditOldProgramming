class Animal(object):

	population = 0

	def __init__(self, name="Thing", position=(0,0)):
		self.isAlive = True
		self.position = position
		self.name = name

	def __str__(self):
		return "My name is "+self.name+" I am at position "+str(self.position[0])+","+str(self.position[1])

	def __repr__(self):
		return self.__str__()

	def move(self, pacesRight=0, pacesUp=0):
		self.position = (self.position[0]+pacesRight, self.position[1]+pacesUp)

	def speak(self):
		print( "I am a generic animal, I don't know how to speak")

	def die(self):
		if not self.isAlive:
			print (self.name+" is already dead.")
			return False
		self.isAlive = False
		return True
		
class Dog(Animal):
        def __init__(self, name="Skip", position=(0,0)):
                Animal.__init__(self, name, position)
                self.lives = 1
                Dog.population += 1
                Animal.population += 1

        def speak(self):
                print (self.name+" says Woof!")

        def die(self):
                if Animal.die(self):
                        Dog.population -= 1
                        Animal.population += 1
                        print (self.name+" is dead.")

class Cat(Animal):
	def __init__(self, name="Felix", position=(0,0)):
		Animal.__init__(self, name, position)
		self.lives = 9
		Cat.population += 1
		Animal.population += 1	

	def speak(self):
		print (self.name+" says Meioww!")

	def die(self):
		if Animal.die(self):
			self.lives -= 1
			if (self.lives <= 0):
				Cat.population -= 1
				Animal.population -= 1
				print (self.name+" is dead.")
			else:
				self.isAlive = True
				print (self.name+" has "+str(self.lives)+" left.")


class Parrot(Animal):
        def __init__(self,name="Polly", position=(0,0)):
                Animal.__init__(self,name,position)
                self.lives=1
                Parrot.population+=1
                Animal.population+=1

        def speak(self):
                rep=input("What should it say?: ")
                print("{} says:  BWWRRRAAAACCKKKKK...{}\t*whistle* *click*".format(self.name,rep))

        def die(self):
                if Animal.die(self):
                        Parrot.population-=1
                        Animal.population-=1
                        print(self.name+" is dead.")
