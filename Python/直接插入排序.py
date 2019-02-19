#Author guo
#需要一个新的列表 或者分成两部分，一个是没排序的一部分是排序过的
#牺牲空间复杂度

data_set=[9,1,22,31,45,31,6,2,11]

for i in range(len(data_set)):
    p=i
    while p>0 and data_set[p]<data_set[p-1]:#右边小于左边相邻值
        data_set[p],data_set[p-1]=data_set[p-1],data_set[p]#只判断一次的问题
        p=p-1#加入一个指针，循环递减，最后使其把前面的遍历完
    print(data_set)
print(data_set)