# Question 2 a
def lucas_reg(n):
    l=[] #creating list l
    #base cases
    if n >=1:
        l.append(2) #adding 2 at end of the list
    if n >=2:
        l.append(1) #adding 1 at end of the list
    n1=2
    n2=1

    for i in range(2,n): #for range between 2 and n
        n3 = n1+n2
        n1 = n2
        n2 = n3
        l.append(n3) #will add n3 to end of list

    return l # return list to display

def main():
    print("Please enter value of n: ") #prompt to determine size of sequence
    n = int(input())    #n is taken as an integer
    print(lucas_reg(n)) #calling defined function

if __name__ == '__main__':
    main()  #calling main function
