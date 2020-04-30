'''students=[]
marks=[]
x = input('enter name: ')
y = input('enter marks: ')
while(y !=4000):
    x = input('enter name: ')
    y = input('enter marks: ')
    students.append(x)
    marks.append(y)
print(strdents)
print(marks)


for i in range(3):
    y = input("enter marks")
    marks.append(y)
for i in range(3):
    print(students[i],marks[i])
    #====================================
names=['zaini','sami','zaeem','suria']
marks=[12,13,16,20]
for i in range (len(names)):
    print(names[i],marks[i])

'''
marks=[1,2,3,4]
l_no=marks[0]
for i in range(4):
    if(l_no<marks[i+1]):
        l_no=marks[i+1]
print(l_no)