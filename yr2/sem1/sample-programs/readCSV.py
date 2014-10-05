myFile = open("/home/mark/Dropbox-Personal/git/pydev1/pydev1/PPR-2013-Dublin.csv",'rU') # 1. open file for reading

rowCount = 0
for row in myFile:
	rowElements = row.split(',')[:-1]
	for cell in rowElements:
		print cell,"\t",
	print 
	rowCount += 1

print "Printed",rowCount,"rows."
myFile.close()
