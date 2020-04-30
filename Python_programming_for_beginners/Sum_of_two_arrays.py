'''sum of two arays of equal size'''
C=[]
def SumOfArrays(List1,List2):
    '''It will add two arrays of same size'''
    for i in range(len(List1)):
        C.append(List1[i]+List2[i])
    if len(List1)==len(List2):
        print(C)
    else:
        print "invalid values, elements of two array should be of same"  
