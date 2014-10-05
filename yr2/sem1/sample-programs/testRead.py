'''This program illustrates the way data is acutally represented in files 
on the computer as opposed to the way users might preceive this by using 
and viewing text files and, possibly, ignoring and/or misunderstanding
that which is invisible (encodings that don't have a glyph or 'character' 
to represent them) or misunderstanding the fundamental difference between, 
for example, '1', 1 and 1.0. The first important concept is that files (and 
everthing else a computer deals with) are just a bunch of 1s and 0s which 
are often visualised (in a viewer) in hexadecimal for convenience and brevity,

In this context, everything that we preceive as a character, printable or 
not, is represented internally as a (somewhat arbitrary) number which can 
be expressed in binary, decimal, octal, hexadecimal or whatever you're 
having yourself. 

For a fuller understanding of this, the reader is encouraged to learn about 
text encoding systems. Start with the terms, ASCII, Unicode, UTF-8 and take 
it from there.

Things get a little trickier when we start representing things which are 
not modelled as 'characters' - integers, floats and boolean. We must now 
consider such arcana as 'endian-ness', word sizes (32-bit, 64-bit etc), 
floating point (IEEE 754) and more.

What this program does is to write this stuff to a file and read it back 
so that you can view the file in it's 'real' form using a hex viewer, and 
read it back and present the different types to your program in a more 
'logical' mannner.

Have fun!

Mark Foley
October 2013.   
'''

import struct
'''This module performs conversions between Python values and C structs 
represented as Python bytes objects. This can be used in handling binary 
data stored in files or from network connections, among other sources. 
It uses Format Strings as compact descriptions of the layout of the C 
structs and the intended conversion to/from Python values.
'''

UTF_RANGE = 55300
INT_RANGE = 300
FLOAT_RANGE = 10
'''UTF_RANGE is a constant that we can adjust to give us any number of 'characters'
from the uttf-8 character set. In utf-8 (Python's default encoding) characters 
are represented by 1 byte up to (realistically) 6 bytes. Good old-fashioned 
ASCII maps seamlessy to the first 127 utf-8 characters. Beyond that 2 and 
3-byte characters can represent prety muuch any character in any of the 
World's languuages. A value of 65536 gives us all of the 1- 2- and 3-byte 
representations.

INT_RANGE is the upper limit of a range of integers to represent.
FLOAT_RANGE is the upper limit range of the decimal portion of the float
that we want to represent, i.e 1.0 to 1.n where n
'''

fileHandle = open("randomstuff", "wb")

badEncoding = []

outString = "START_UTF_("+str(UTF_RANGE)+")"
fileHandle.write(outString.encode('utf-8'))

# Write out a representation of every character up to but not including UTF_RANGE
for i in range(UTF_RANGE):
	try:
		fileHandle.write(bytes(chr(i).encode('utf-8')))
	# Some unicode code points don't render properly. We handle that here
	# by making a list of the decimal representation of the offending code points. 
	except UnicodeEncodeError:
		badEncoding.append(i)
	
outString = "END_UTF_("+str(UTF_RANGE)+")"
fileHandle.write(outString.encode('utf-8'))

outString = "START_INT_("+str(INT_RANGE)+")"
fileHandle.write(outString.encode('utf-8'))

# Positive integers
for i in range(INT_RANGE):
	fileHandle.write(struct.pack("i",i))

# Negative integers
for i in range(INT_RANGE):
	fileHandle.write(struct.pack("i",i*-1))

outString = "END_INT_("+str(INT_RANGE)+")"
fileHandle.write(outString.encode('utf-8'))

outString = "START_FLOAT_("+str(FLOAT_RANGE)+")"
fileHandle.write(outString.encode('utf-8'))

# Posiitive floats
for i in range(FLOAT_RANGE):
	fileHandle.write(struct.pack("f",1.0+(i/FLOAT_RANGE)))

# Negative floats	
for i in range(FLOAT_RANGE):
	fileHandle.write(struct.pack("f",((1.0+(i/FLOAT_RANGE))*-1)))

outString = "END_FLOAT_("+str(FLOAT_RANGE)+")"
fileHandle.write(outString.encode('utf-8'))

fileHandle.write("START_BOOL".encode('utf-8'))

# A true and a false boolean
tf = True
fileHandle.write(struct.pack("?",tf))
tf = False
fileHandle.write(struct.pack("?",tf))

fileHandle.write("END_BOOL".encode('utf-8'))

# Write out details of any utf-8 character that we couldn't handle normally.
if len(badEncoding) > 0:
	outString = "START_BAD_CODES_("+str(len(badEncoding))+")"
	fileHandle.write(outString.encode('utf-8'))

for i in badEncoding:
	outString = "|"+str(i)+".."+str(hex(i)+"|")
	fileHandle.write(bytes(outString.encode('utf-8')))

if len(badEncoding) > 0:
	outString = "END_BAD_CODES_("+str(len(badEncoding))+")"
	fileHandle.write(outString.encode('utf-8'))

fileHandle.close()

'''Now let's try to read the file and print a string representation of its 
contents.
'''

fileHandle = open("randomstuff", "rb")
fileContent = fileHandle.read()

'''To deal with a binary file you have to understand its structure. On the 
assumption that we don't know much about this file, we are goung to take 
a 4-byte moving window (start with bytes 0-3, then 1-4, 2-5 etc.) along 
the file and attempt to interpret what it might be. We choose a 4-byte 
window as we're assuming a 32-bit (4x8bits) machine. We're also assuming 
little-endian-ness.
'''

printFile = open("randomstuff.txt", "w")

for i in range(len(fileContent)):
	try:
		print("Data at Position {} could represent: character '{}', integer {}, unsigned integer {}, float {}, bool {}". \
		format(i, struct.unpack_from("s", fileContent[i:i+4])[0], \
		struct.unpack_from("i", fileContent[i:i+4])[0], \
		struct.unpack_from("I", fileContent[i:i+4])[0], \
		struct.unpack_from("f", fileContent[i:i+4])[0], \
		struct.unpack_from("?", fileContent[i:i+4])[0]), file=printFile)
	except:
		print("Error found at {}".format(i), file=printFile)
	
print("{} bytes in file".format(len(fileContent)), file=printFile)

fileHandle.close()
