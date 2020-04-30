'''is an array is ordered or not'''
def isOrdered(numbs):
    asc=0
    desc=0
    for i in range(len(numbs)-1):
        if numbs[i]>numbs[i+1]:
            desc=desc+1
        elif numbs[i]<numbs[i+1]:
            asc=asc+1

    if desc ==0 or asc==0:
        return True
    else:
        return False
