'''give fibonocci no from recursion method'''
def fibr(x):
    if x <=2:
        return 1
    else:
        return fibr(x-1)+fibr(x-2)
#Mwethod two: fibonocci no by manually
def fibm(x):
    if(x <=2):
        return 1
    else:
        a=1
        b=1
        for i in range(x-1):
            n=a+b
            a=b
            b=n
    return n
