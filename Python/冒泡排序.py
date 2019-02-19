#Author guo
'''
越大的元素通过交换慢慢浮动到数列的顶端
'''
#最简单方式，循环套循环效率低
data_set=[9,1,22,31,45,31,6,2,11]
for j in range(len(data_set)-1):
    for i in range(len(data_set)-1):#出现问题
        if data_set[i]>data_set[i+1]:
            temp=data_set[i]
            data_set[i]=data_set[i+1]
            data_set[i+1]=temp

print(data_set)

#不用循环到后面的交换过的
data_set=[2,9,4,6,2,4,1,3,13,4,1]
for j in range(len(data_set)-1):
    for i in range(len(data_set)-j-1):
        if data_set[i]>data_set[i+1]:
            data_set[i],data_set[i+1]=data_set[i+1],data_set[i]

print(data_set)