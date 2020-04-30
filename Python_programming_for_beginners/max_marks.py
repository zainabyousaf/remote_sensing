
marks=[1,3,5,2,8,10,1]
max_marks=marks[0]
for i in range(6):
    if(max_marks<marks[i+1]):
        max_marks=marks[i+1]
print(max_marks)
