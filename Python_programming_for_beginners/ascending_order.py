'''Ascending numbers'''
numbs=[]
size=int(input("enter size:  "))
for i in range(size):
         no=int(input("enter a no:  "))
         numbs.append(no)
for i in range(size):
    for j in range(i+1):   
        if(numbs[i]<numbs[j]):
            temp=numbs[i]
            numbs[i]=numbs[j]
            numbs[j]=temp
print("new array is: ", numbs)
