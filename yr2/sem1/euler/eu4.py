def bigPalin(small,big):
    num1=big
    num2=big
    max=0

    while num1 >= small:
        while num2 >= small:
            if(str(num1*num2)==str(num1*num2)[::-1]):
                if(max< num1*num2):
                    max=num1*num2
            num2-=1
        num1-=1
        num2=big
    return max

pal=bigPalin(100,999)
if(pal != 0): print(pal)
