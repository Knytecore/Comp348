# Question 1
def lucas(n):   #defining lucas function to find lucas numbers
    # base cases
    if n == 0:      #if n = 0, return 2
        return 2
    elif n == 1:    #if n = 1, return 1
        return 1
    else:           # recursive case
        return lucas(n - 1) + lucas(n - 2)

def main():
    print("Please enter value of n: ") #prompt to determine size of sequence
    n = int(input())    #n is taken as an integer
    for i in range(n-1):  #making a sequence of size n with i as contents
        print(lucas(i), end=' ') #displaying sequence on a single line
    print()

if __name__ == '__main__':
    main()  #calling main function