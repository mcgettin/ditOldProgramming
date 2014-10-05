__author__ = 'mark'

# ========== Start =================
# This imports the necessary module to enable us to treat a URL as a file
import urllib.request

# URL is just a variable which stores the url string of the data that we want
URL = "http://archive.ics.uci.edu/ml/machine-learning-databases/adult/adult.data"

# When we go looking for the url data we get back (i) the data itself which is stored in a file (called f,
# in this case) and some http headers which contain information about the call. These are stored as
# an object (called h in this case).
f, h = urllib.request.urlretrieve(URL)

# If you're curious as to what the headers contain, run this command.
print(h.as_string())

# If you run this you'll get the name of the temporary file containing your data.
# urllib.request.urlretrieve made the file for you automatically so you don't need to do this, it's just for info.
print(f)

# We now need to open the file, just as we would if it were permanently stored on our computer.
file = open(f, 'r')

# This is some simple code to show how to read each record in the file and count them.
# It's just to prove that we read each one without bothering to print the details.
count = 0
for row in file:
    count += 1

# This will give you the number of records in the file. It should be 32562.
print(count)

# ========== End ===================
