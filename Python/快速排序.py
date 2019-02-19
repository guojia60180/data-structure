#Author guo
#通过一趟排序，把需要排序的部分分割成两个独立的部分，其中一部分所有数据比另外一部分的所有数据都要小
#按照此方法对两部分树分别进行快速排序，可以递归进行
#分治的思想

'''
[6,8,1,4,3,9]
1.选择6作为基准，右向左扫描，寻找到3，交换3,6
[3,8,1,4,6,9]
2.从左向右扫描，寻找基准数大的数，8，交换6,8
[3,6,1,4,8,9]
3.重复上述的过程，使得左边的数都比基准数小，右边的数都比基准数大
4.左右区间重复第二步，直到各区间只有一个数。
'''
def QuickSort(myList,start,end):
    #判断low是否小于high,如果为false,直接返回
    if start < end:
        i,j = start,end
        #设置基准数
        base = myList[i]

        while i < j:
            #如果列表后边的数,比基准数大或相等,则前移一位直到有比基准数小的数出现
            while (i < j) and (myList[j] >= base):
                j = j - 1

            #如找到,则把第j个元素赋值给第个元素i,此时表中i,j个元素相等
            myList[i] = myList[j]

            #同样的方式比较前半区
            while (i < j) and (myList[i] <= base):
                i = i + 1
            myList[j] = myList[i]
        #做完第一轮比较之后,列表被分成了两个半区,并且i=j,需要将这个数设置回base
        myList[i] = base

        #递归前后半区
        QuickSort(myList, start, i - 1)
        QuickSort(myList, j + 1, end)
    return myList

'''
1）设置两个变量i、j，排序开始的时候：i=0，j=N-1；
2）以第一个数组元素作为关键数据，赋值给key，即key=A[0]；
3）从j开始向前搜索，即由后开始向前搜索(j--)，找到第一个小于key的值A[j]，将A[j]和A[i]互换；
4）从i开始向后搜索，即由前开始向后搜索(i++)，找到第一个大于key的A[i]，将A[i]和A[j]互换；
5）重复第3、4步，直到i=j； (3,4步中，没找到符合条件的值，即3中A[j]不小于key,4中A[i]不大于key的时候改变j、i的值，使得j=j-1，i=i+1，直至找到为止。找到符合条件的值，进行交换的时候i， j指针位置不变。另外，i==j这一过程一定正好是i+或j-完成的时候，此时令循环结束）。'''
myList = [49,38,65,97,76,13,27,49]
print("Quick Sort: ")
QuickSort(myList,0,len(myList)-1)
print(myList)

'''
用栈实现非递归的快排程序

先说两句题外话，一般意义上的栈有两层含义，一层是后进先出的数据结构栈，一层是指函数的内存栈，归根结底，函数的内存栈的结构就是一个后进先出的栈。汇编代码中，调用一个函数的时候，修改的也是堆栈指针寄存器ESP，该寄存器保存的是函数局部栈的栈顶，另外一个寄存器EBP保存的是栈底。不知道与栈存储空间相对的堆存储空间，其组织结构是否也是一个完全二叉树呢？

高级语言将递归转换为迭代，用的也是栈，需要考虑两个问题:

1）栈里边保存什么？

2）迭代结束的条件是什么？

栈里边保存的当然是需要迭代的函数参数，结束条件也是跟需要迭代的参数有关。对于快速排序来说，迭代的参数是数组的上边界low和下边界high，迭代结束的条件是low == high。

'''
def quick_sort(array, l, r):
    if l >= r:
        return
    stack = []
    stack.append(l)
    stack.append(r)
    while stack:
        low = stack.pop(0)
        high = stack.pop(0)
        if high - low <= 0:
            continue
        x = array[high]
        i = low - 1
        for j in range(low, high):
            if array[j] <= x:
                i += 1
                array[i], array[j] = array[j], array[i]
        array[i + 1], array[high] = array[high], array[i + 1]
        stack.extend([low, i, i + 2, high])
