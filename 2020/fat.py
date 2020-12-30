def fact(number): 
    if number < 1: 
        return 1 
    else: 
        return number*fact(number-1)  
Lnumber = 1 
while(Lnumber > 0):
    Lnumber = int(input("Input a integer number:\n"))
    print(fact(Lnumber)) 
