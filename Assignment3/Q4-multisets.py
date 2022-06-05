

class multiset:
    def __init__(self):
        self.__set = []

    def add_elem(self,elem):
        self.__set.append(elem)
    
    def remove_occurences(self, elem):
        for item in self.__set.copy():
            if(item == elem):
                self.__set.remove(item)

    def multiplicity(self, elem):
        count = 0
        for item in self.__set.copy():
            if(item == elem):
                count+=1
        return count
    
    def union(self, setcompare):
        lst = []
        for item in self.__set.copy():
            if item not in lst:
                count1 = self.multiplicity(item)
                count2 = setcompare.multiplicity(item)
                
                count = count1 if count2 < count1 else count2
                
                lst += [item for i in range(count)]

        for item in setcompare.set.copy():
            if item not in lst:
                count1 = self.multiplicity(item)
                count2 = setcompare.multiplicity(item)

                
                count = count1 if count2 < count1 else count2
                
                lst += [item for i in range(count)]
        self.__set = lst

    def add_list(self, listadd):
        self.__set += listadd

    def intersection(self, setcompare):
        lst = []
        for item in self.__set.copy():
            if item in setcompare.set:
                if item not in lst:
                    count1 = self.multiplicity(item)
                    count2 = setcompare.multiplicity(item)
                    
                    count = count1 if count1 < count2 else count2
                    
                    lst += [item for i in range(count)]
        self.__set = lst

    def difference(self, setcompare):
        for item in setcompare.set.copy():
            if item in self.set:
                self.__set.remove(item)

    @property
    def set(self):
        return self.__set

    def __str__(self):
        string = "{"
        for item in self.__set:
            string+= (str(item) + ",")

        string = string[:-1]
        string += "}"

        return string


list = [1,2,3]
a = multiset()
a.add_list(list)
print("Adding 1 to multiset",a)
a.add_elem(1)
print("New multiset:", a,"\n")

a.remove_occurences(1)
print("Removed all occurences of 1. New multiset: ",a,"\n")

list = [1,1,1,2,2,3]
a = multiset()
a.add_list(list)
print("Created a multiset with elements:", a)
print("List contains ",a.multiplicity(1), " 1s\n")

list = [1,2]
b = multiset()
b.add_list(list)
list = [2,2,3]
a = multiset()
a.add_list(list)
print("Union multiset", b, "to multiset",a)
a.union(b)
print("New Multiset:", a,"\n")

list = [1,1,2,2,3]
c = multiset()
c.add_list(list)
list = [2,2,2,3,4]
a = multiset()
a.add_list(list)
print("Intersection", c, "to multiset",a)
a.intersection(c)
print("New Multiset:", a,"\n")

list = [1,2,2,2]
c = multiset()
c.add_list(list)
list = [1,1,1,2,2,3]
a = multiset()
a.add_list(list)
print("Difference", a, "-",c)
a.difference(c)
print("New Multiset:", a)


