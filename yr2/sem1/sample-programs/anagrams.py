# Anagram test

def areAnagrams(word1, word2):
    """Return true, if words are anagrams."""
    #2. Sort the words.
    word1_sorted = sorted(word1)    # sorted returns a sorted list
    word2_sorted = sorted(word2)

    #3. Check that the sorted words are identical.
    return word1_sorted == word2_sorted

print "Anagram Test"

# 1. Input two words.
twoWords = raw_input("Enter two words: ")
word1,word2 = twoWords.split()  # split the input string into a list of words

if areAnagrams(word1, word2):  # function returned True or False 
    print "The words are anagrams."
else:
    print "The words are not anagrams."
