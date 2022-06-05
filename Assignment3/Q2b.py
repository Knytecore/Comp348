# Question 2 b
def lucas_gen(n):
    n1,n2 = 2,1    #base cases
    for i in range(n):
        yield n1 #Using generator function
        n1,n2 = n2,n1+n2

def main():
    print("Please enter value of n: ") #prompt to determine size of sequence
    n = int(input())    #n is taken as an integer
    print(list(lucas_gen(n))) #calling defined function

if __name__ == '__main__':
    main()  #calling main function