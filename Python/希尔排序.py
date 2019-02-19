#Author guo
'''
希尔排序是插入排序的一种
称缩小增量排序
序列分割为若干个子序列，分别进行直接插入排序
一次缩减增量再进行排序，带整个序列中增量足够小时，再对全体元素进行一次直接插入排序
由于直接插入排序在元素基本有序时，效率时很高的，希尔排序有更好的效率
'''

#d=3 d=2 d=1 逐级的把列表归序成大致排序顺序相等的情况
#再进行插入排序
#明确增量的取法 第一次增量d=count/2
#第二次count/4
#最后一次1
import random
#data_set=[9,1,22,31,45,31,6,2,11]
data_set=[random.randint(1,1000) for i in range(1000)]
print(data_set)
step=int(len(data_set)/2)
while step>=1:
    for i in range(len(data_set)-step):
        print(data_set[i],data_set[i+step])
        if data_set[i]>data_set[i+step]:
            data_set[i],data_set[i+step]=data_set[i+step],data_set[i]
    #print(data_set)
    step=int(step/2)

for i in range(len(data_set)):
    p=i
    while p>0 and data_set[p]<data_set[p-1]:#右边小于左边相邻值
        data_set[p],data_set[p-1]=data_set[p-1],data_set[p]#只判断一次的问题
        p=p-1#加入一个指针，循环递减，最后使其把前面的遍历完

print(data_set)