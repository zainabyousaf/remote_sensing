'''is the no you searched in an array is largest or not, first of all check
whether the no you entered to search is found in list or not. if not give
largest no, if yes print this is largest'''

def isLargest(List,s_no):
    L=List[0]
    for i in range(len(List)):
        if L<List[i]:
            L=List[i]
    found = False
    for i in List:
        if s_no == i:
            if s_no == L:
                print("this is largest")
                found =True
                break
            else:
                print(("largest is ", L))
                found=True
                break
    if(found==False):
        print("no found")

