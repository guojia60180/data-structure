#Author guo
#选择最小的未分类的元素
#通过数组的最小的元素与第一个进行交换

data_set=[9,1,22,31,45,31,6,2,11]
#需要记录最小值的index

for j in range(len(data_set)):
    index =j
    for i in range(j,len(data_set)):
        if data_set[i]<data_set[index]:
            index=i
    data_set[j],data_set[index]=data_set[index],data_set[j]
    print(data_set)
print(data_set)