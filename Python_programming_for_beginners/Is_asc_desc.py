'''is given array is in ascendig or descending order or not'''
numbs=[]
size=int(input("enter size:  "))
for i in range(size):
         no=int(input("enter a no:  "))
         numbs.append(no)
asc=0
desc=0
for i in range(size-1):
    if numbs[i]>numbs[i+1]:
        desc=desc+1
    elif numbs[i]<numbs[i+1]:
        asc=asc+1

if desc ==0 or asc==0:
    print('true')
else:
    print('false')
