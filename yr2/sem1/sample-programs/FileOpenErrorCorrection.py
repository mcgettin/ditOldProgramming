# simple file example

#little snippet to repeatedly ask for a file to open for read
#continues to prompt until a file opens successfully
openedFile = False
while (not openedFile):
    fileName = raw_input("Open what file: ")
    try:
        inFile = open(fileName,"r")
        openedFile = True
    except IOError:
        print "File opening failed, try again "

# first let's mess with the file names:        
# make a new file, keep the extension but change the name
# so that it ends in "Rev". Thus textFile.txt => textFileRev.txt
fileParts = fileName.split(".")
outFile = open(fileParts[0]+"Rev."+fileParts[1],"w")

# now do something with the files:
# write each line in reverse word order
for line in inFile:
    words = line.split()    # split out individual words
    words.reverse()         # reverse the list of words
    for w in words:
        outFile.write(w)
        outFile.write(" ")  # put back space between words
    outFile.write("\n")      # tack carriage return onto end of line
        

inFile.close()
outFile.close()
    



