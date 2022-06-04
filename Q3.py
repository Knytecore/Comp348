# Question 3
def seq_to_set(sequence_in):
    mySet = []  #creating list
    for num in sequence_in:
        if num not in mySet: #taking care of repetitions
            mySet.append(num)   #adding numbers to end of list

    return mySet    #retun set

def main():
    mySet = seq_to_set(sequence)    # from list that allows repetition to set that does not allow them
    print(mySet)

if __name__ == '__main__':
    sequence = [5, 7, 10, 5, 2, 2, 3, 1, 5, 3, 3, 2]    #sequence to convert
    main()  #calling main function