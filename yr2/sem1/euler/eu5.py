num=loop=20

found=0

while not found:
    found=1
    for i in range(loop):
        if(num%(i+1)):    
            found=0
            num+=1
            
            
print(num)
