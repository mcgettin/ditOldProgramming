#!/usr/bin/python3
# highest mileage data
# from http://www.fueleconomy.gov/FEG/download.shtml

import urllib.request

DATA_URL = "https://www.dropbox.com/s/624fr7lfhdusa17/2008_FE_guide_ALL_rel_dates_nosalesforDOE-5-1-08.csv"

def createMileageList(epaFile):
    """Create a list of cars and mileage from epaFile."""
    # 2a create a mileage list and initialize it to empty
    mileageList = []

    for line in epaFile:              # 2b. get each line from the file
        if line[0:5] == 'CLASS' or\
                 'VAN' in line or\
                 'PICKUP' in line:   # errata: removed "if" that appeared in published version
            continue        #     skip pickups, vans and the header line
        lineList = line.split(',')           # 2bI. csv => split on comma
        # create tuple: (mileage, make, model)
        carTuple = (int(lineList[9]), lineList[1], lineList[2])
        mileageList.append(carTuple)         # 2bII. append tuple
    return mileageList

def findMaxMinMileage(mileageList, maxMileage, minMileage):
    """Make a list of cars with max and min mileage: list of car tuples."""
    maxMileageList = []
    minMileageList = []

    # 5. find max and min mileage cars; append them to the appropriate list
    #    carTuple[0] is item 0 of the tuple which is the mileage
    for carTuple in mileageList:
        if carTuple[0] == maxMileage:
            maxMileageList.append(carTuple)
        if carTuple[0] == minMileage:
            minMileageList.append(carTuple)

    return maxMileageList, minMileageList

def main():
    ##############################################
    # 1. open EPA data file
    try:
        #local_filename, headers = urllib.request.urlretrieve(DATA_URL)
        epaFile = open("epaData.csv", "r")

        print("EPA Car Mileage")

        # 2a create a mileage list
        mileageList = createMileageList(epaFile)

        # 3. find max and min mileage
        #    mileageList is a list of tuples (mileage, make, model)
        #    max(mileageList)[0] finds the max mileage tuple and extracts the mileage
        maxMileage = max(mileageList)[0]
        minMileage = min(mileageList)[0]

        print("Max and Min Mileage: ", maxMileage, minMileage)

        #4. create a list of all cars with max and min mileage: list of car tuples
        maxMileageList, minMileageList = \
                        findMaxMinMileage(mileageList,maxMileage,minMileage)

        print("Maximum Mileage Cars:")
        for carTuple in maxMileageList:
            print("  ", carTuple[1], carTuple[2])
        print("Minimum Mileage Cars: ")
        for carTuple in minMileageList:
            print("  ", carTuple[1], carTuple[2])

    except IOError as e:
        print ("Could not open file at {}.\nError was {}\nClosing Program.".format(DATA_URL, e))

if __name__ == "__main__":
    main()