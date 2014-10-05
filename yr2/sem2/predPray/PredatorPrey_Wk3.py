#!/usr/bin/env python3

"""Predator-Prey Simulation
   four classes are defined: animal, predator, prey, and island where island is where the simulation is taking place,
   i.e. where the predator and prey interact (live). A list of predators and prey are instantiated, and
   then their breeding, eating, and dying are simulated.
"""
import random


class Island(object):
    """Island
       n X n grid where zero value indicates not occupied."""

    def __init__(self, gridSize, preyCnt=0, predatorCnt=0):
        '''Initialize grid to all 0's, then fill with animals
        '''

        # Make a dictionary of the numbers we want for each type. This will be used later to create both types in
        # one method.
        self.animal_numbers = {"Predator": predatorCnt, "Prey": preyCnt}

        self.gridSize = gridSize

        # This is a short way to create the grid using a 'list comprehension'. This creates a list
        # 0*n or [0 for i in range(n)] and duplicates this list within an outer list -
        # newList*n or [[0 for i in range(n)] for j in range(n)]
        self.grid = [[0 for i in range(self.gridSize)] for j in range(self.gridSize)]

        # We move the method to create the initial population of the island to the Island class as it is more
        # appropriate to have it here rather than as a stand-alone function.
        self.initAnimals(preyCnt, predatorCnt)

    def __str__(self):
        '''String representation for printing.
           (0,0) will be in the lower left corner.
        '''
        s = "\n"
        for j in range(self.gridSize - 1, -1, -1):  # print row size-1 first
            s += "{:^4}".format(j) + "| "
            for i in range(self.gridSize):  # each row starts at 0
                if not self.grid[i][j]:
                    # print a '.' for an empty space
                    s += "{:^4}".format(".")
                else:
                    # print the char X or O representing the animal
                    s += "{:^4}".format((str)(self.grid[i][j]))
            s += "\n"

        s += "{:^4}".format("----") * (self.gridSize + 1) + "\n"
        s += "{:^4}| ".format(" ")
        for i in range(self.gridSize):
            s += "{:^4}".format(i)
        s += "\n"
        return s

    def __repr__(self):
        return self.__str__()

    def initAnimals(self, preyCnt, predatorCnt):
        ''' Put some initial animals on the island'''

        # Iterate through the dictionary and make instances
        # 'k' is the class name - Predator or Prey, a key in the dictionary. Its associated value is the count
        # There is an element of uncertainty here. An ATTEMPT is made to create an animal each time but if the
        # space is already occupied then we pass on silently. This means that we could end up with fewer animals
        # then initially specified.

        for k in self.animal_numbers:
            for i in range(self.animal_numbers[k]):
                # Generate random integers for x & y. These must be valid grid locations.
                x = random.randint(0, self.gridSize - 1)
                y = random.randint(0, self.gridSize - 1)
                if not self.grid[x][y]:
                    # globals() returns a dictionary that represents the current global namespace.
                    # The keys of this dictionary are globally defined names, and each corresponding value is
                    # the value for that name. Thus, globals()[k](island=self, x=x, y=y) makes an instance of 'k'
                    # where k is a Predator or Prey. This trick avoids duplicating the code for predators and prey.
                    # We then add the animal to the grid.
                    self.grid[x][y] = globals()[k](self, x, y)

    def clearAllMovedFlags(self):
        ''' Animals have a moved flag to indicated they moved this turn.
        Clear that so we can do the next turn
        '''

        for x in range(self.gridSize):
            for y in range(self.gridSize):
                if isinstance(self.grid[x][y], Animal):
                    self.grid[x][y].moved = False


class Animal(object):
    ''' This is our generic animal class. We use this because most of the values and methods such as location,
    move, breed etc. are common to both predators and prey.
    '''

    def __init__(self, island, x=0, y=0, s="A"):
        '''Initialize the animals and their positions
        '''
        self.island = island
        self.name = s
        self.x = x
        self.y = y
        self.moved = False

    def __str__(self):
        return self.name

    def __repr__(self):
        return self.__str__()

    def updateState(self):
        '''Update state variables such as breed clock and starve clock, Prey only updates its local breed clock
        '''
        self.breedClock -= 1


    def checkGrid(self, typeLookingFor=int):
        ''' Look in the 8 directions from the animal's location
        and return the first location that presently has an object
        of the specified type. Return 0 if no such location exists
        '''
        result = 0

        # Animal.moveAttempts is a class variable, Its value is specified at the start of the program and doesn't
        # change.
        for i in range(Animal.moveAttempts):
            # We have a defined number attempts to move 1 space in a random direction
            x = self.x + random.randint(-1, 1)
            y = self.y + random.randint(-1, 1)
            if (not 0 <= x < self.island.gridSize) or (not 0 <= y < self.island.gridSize):
                # Must stay on the island (a valid grid ref)
                continue
            if isinstance(self.island.grid[x][y], typeLookingFor):
                result = (x, y)
                break
        return result


    def move(self):
        '''Move to an open, neighboring position '''
        if not self.moved:
            location = self.checkGrid(int)
            if location:
                print("{} ({},{}) -> ({},{})".format(self.name, self.x, self.y, location[0], location[1]))
                self.island.grid[self.x][self.y] = 0  # remove from current spot
                self.x = location[0]  # new coordinates
                self.y = location[1]
                self.island.grid[self.x][self.y] = self
                self.moved = True


    def breed(self):
        ''' Breed a new Animal.If there is room in one of the 8 locations place the new animal there.
        Otherwise you have to wait.'''
        if self.breedClock <= 0:
            location = self.checkGrid(int)
            if location:
                print("{} ({},{}) -> ({},{}) *".format(self.name, self.x, self.y, location[0], location[1]))
                self.breedClock = self.breedTime
                self.island.grid[location[0]][location[1]] = self.__class__(self.island, x=location[0], y=location[1])


class Prey(Animal):
    ''' This is the prey class which is a specialisation of animal.
    '''

    def __init__(self, island, x=0, y=0, s="O"):
        # Note this idiom for invoking the super class initializer. It could be considered more generic and therefore
        # slightly more elegant than the invoking this by the superclass name. Note that you don't need self with this.
        super().__init__(island, x, y, s)

        # breedClock is the local counter. It gets its initial value from breedTime which doesn't change.
        self.breedClock = Prey.breedTime

        # Keep track of overall population
        Prey.population += 1


class Predator(Animal):
    ''' This is the predator class, a specialisation of animal.
    '''

    def __init__(self, island, x=0, y=0, s="X"):
        super().__init__(island, x, y, s)
        # starveClock is the local counter. It gets its initial value from starveTime which doesn't change.
        self.starveClock = Predator.starveTime
        # breedClock is the local counter. It gets its initial value from breedTime which doesn't change.
        self.breedClock = Predator.breedTime

        # Keep track of overall population
        Predator.population += 1


    def updateState(self):
        '''Update state variables such as breed clock and starve clock, Prey only updates its local breed clock
        '''
        super().updateState()

        if self.starveClock <= 0:
            # Predator starves to death
            print("{} ({},{}) -> ***** +".format(self.name, self.x, self.y))
            self.island.grid[self.x][self.y] = 0
            Predator.population -= 1


    def eat(self):
        ''' Predator looks in one of the 8 adjacent locations for Prey. If found moves to that location,
        updates the starve clock, removes the Prey.
        '''
        if not self.moved:
            location = self.checkGrid(Prey)
            if location:
                print("{} ({},{}) -> ({},{}) +".format(self.name, self.x, self.y, location[0], location[1]))
                self.island.grid[self.x][self.y] = 0  # remove from current spot
                self.x = location[0]  # new coordinates
                self.y = location[1]
                self.island.grid[self.x][self.y] = self
                self.starveClock = Predator.starveTime
                self.moved = True
                Prey.population -= 1
            else:
                # Failure to eat
                self.starveClock -= 1


#
# The program runs from here
#

def main():
    ''' Main simulation. Sets defaults, runs event loop, plots at the end
    '''

    # Initial values. User can change these.
    PREDATOR_BREED_TIME = 6
    # No. of clock ticks or runs through the loop a predator must wait before it can breed
    PREY_BREED_TIME = 3
    # No. of clock ticks or runs through the loop a prey must wait before it can breed
    PREDATOR_STARVE_TIME = 3
    # Predator must eat within this no. of ticks or starve
    NUMBER_PREDATORS = 4
    # Initial no. of predators on the island
    NUMBER_PREY = 25
    # Initial no. of prey on the island
    GRID_SIZE = 25
    # Size of the island - it will be a square 2x2 grid
    CLOCK_TICKS = 20
    # No. of clock ticks or times we go around the main loop
    MOVE_ATTEMPTS = 10
    # No. of attempts to find an adjacent space to move/breed/eat

    # Class variables - these values apply to all objects of the class.
    Animal.moveAttempts = MOVE_ATTEMPTS
    Predator.breedTime = PREDATOR_BREED_TIME
    Predator.starveTime = PREDATOR_STARVE_TIME
    Prey.breedTime = PREY_BREED_TIME

    # Population class variables
    Predator.population = 0
    Prey.population = 0

    # Maintain lists of population cycles. Can be used later for graphing
    predator_list = []
    prey_list = []


    # Make an island
    myIsland = Island(GRID_SIZE, NUMBER_PREY, NUMBER_PREDATORS)


    # event loop.
    # For all the ticks, for every x,y location.
    # If there is an animal there, try eat, move, breed and clockTick
    for i in range(CLOCK_TICKS):
        print(myIsland)
        print("Predator population: {}, Prey population: {}".format(Predator.population, Prey.population))
        # important to clear all the moved flags!
        myIsland.clearAllMovedFlags()

        # Get everyone to move if possible.
        for x in range(GRID_SIZE):
            for y in range(GRID_SIZE):
                if isinstance(myIsland.grid[x][y], Animal):
                    animal = myIsland.grid[x][y]

                    # For now the only method that works is move(). We can of course 'run' the others even they don't
                    # DO anything (yet!)
                    if isinstance(animal, Predator):
                        animal.eat()
                    animal.move()
                    animal.breed()
                    animal.updateState()

        prey_list.append(Prey.population)
        predator_list.append(Predator.population)

        if Prey.population == 0:
            print("Lost Prey population, quitting...")
            break
        if Predator.population == 0:
            print("Lost Predator population, quitting...")
            break


    # State of the island at the end of the run
    print(myIsland)
    print("Ran for {} clock ticks. Predator population: {}, Prey population: {}".format(i + 1, Predator.population,
                                                                                        Prey.population))


if __name__ == "__main__":
    '''When the Python interpreter reads a source file, it executes all of the code found in it. Before
    executing the code, it will define a few special variables. For example, if the python interpreter
    is running that module (the source file) as the main program, it sets the special __name__ variable
    to have a value "__main__". If this file is being imported from another module, __name__ will be set
    to a different value. For example, this means that you can import to IDLE and run functions separately
    which may be useful for testing'''
    main()
