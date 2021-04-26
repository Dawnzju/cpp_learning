//
// Created by 安炳旭 on 2019-08-21.
//

#include <cstdio>

#define ElemType int
#define MAX_SIZE 50
//定义顺序表的结构体
typedef struct {
    ElemType data[MAX_SIZE];
    int length;
} SqList;

//2.2.3-1：从顺序表中删除最小值的元素并返回删除的值 出错则退出运行
bool deleteMinElem(SqList &list, int &value) {
    //返回值为value
    if (list.length == 0) {
        return false;
    }
    value = list.data[0];
    int index = 0;
    for (int i = 1; i < list.length; ++i) {
        if (list.data[i] < value) {
            index = i;
            value = list.data[i];
        }
    }

    //将最后一个元素放入 i位置的
    list.data[index] = list.data[list.length - 1];
    //线性表的长度减1
    list.length--;
    return true;
}

//2.2.3-2：将顺序表L的所有元素逆置
void reverseList(SqList &l) {
    //空表和长度为一的表不需要逆置
    if (l.length == 0 || l.length == 1) {
        return;
    }
    for (int i = 0, j = l.length - 1; i < j; i++, j--) {
        //交换两个元素
        int temp = l.data[i];
        l.data[i] = l.data[j];
        l.data[j] = temp;
    }

}

//2.2.3-3：删除所有值为x的元素
//方法1：虚拟构造一个新的数组 利用数组的随机访问 根据不等于X的元素 在原来数组的基础上构造新的数组
void deleteX_1(SqList &list, int value) {
    if (list.length == 0) {
        return;
    }
    int k = 0;//用于记录不等于x的元素个数 同时也是删除x后线性表的下标
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] != value) {
            list.data[k] = list.data[i];//将数据赋予 第k个位置的元素
            k++;//伪新数组的下标+1
        }
    }
    list.length = k;
}

//方法2：有几个等于X的元素 当前元素就向前移动几个
void deleteX_2(SqList &list, int value) {
    if (list.length == 0) {
        return;
    };
    int k = 0;
    int i = 0;
    while (i < list.length) {
        if (list.data[i] == value) {
            k++;//等于value元素的个数
        } else {
            list.data[i - k] = list.data[i];//当前元素迁移k个元素
        }
        i++;
    }
    list.length = list.length - k;
}

//2.2.3-4：删除有序的顺序表的值【s，t】的元素
bool deleteS_T(SqList &l, int s, int t) {
    if (s >= t) {
        return false;
    }
    if (l.length == 0) {
        return false;
    }
    if ((s >= l.data[0] && s <= l.data[l.length - 1]) && (t >= l.data[0] && t <= l.data[l.length - 1])) {
        //如果s和t都在数组值的范围内 时候删除元素
        //利用上面的方法 有种伪造数组的感觉
        int k = 0;
        for (int i = 0; i < l.length; ++i) {
            if (l.data[i] < s || l.data[i] > t) {
                l.data[k] = l.data[i];
                k++;
            }
        }
        l.length = k;
    }
    return true;
}


// 2.2.3-5:同4 四的方法可以删除有序的顺序表

// 2.2.3-6：从有序顺序表中展出所有其值重复的
// 方法和3异曲同工
bool delete_Same(SqList &list) {
    if (list.length == 0 || list.length == 1) {//长度为0或者1的时候 无重复元素
        return false;
    }
    int i, j;//i用于记录上一个不一样的元素的下标， j用于循环遍历 从数组的第二个元素（下标为1开始）
    for (i = 0, j = 1; j < list.length; ++j) {
        if (list.data[i] != list.data[j]) {
            list.data[++i] = list.data[j];//原理同3
        }

    }
    list.length = i + 1;//调整表长度 表长度至少为1个因为第一个元素肯定不同
    return true;
}

//2.2.3-7：合并两个有序顺序表（合并步骤归并排序的思想差不多）
bool mergeTwoList(SqList &list1, SqList &list2, SqList &list) {
    if (list1.length == 0 || list2.length == 0) {
        return false;
    }
    if (list1.length + list2.length > MAX_SIZE) {
        return false;
    }
    int index1 = 0;
    int index2 = 0;
    int index = 0;
    //将等长部分合并
    while (index1 < list1.length && index2 < list2.length) {
        if (list1.data[index1] <= list2.data[index2]) {
            list.data[index++] = list1.data[index1++];
        } else {
            list.data[index++] = list2.data[index2++];
        }
    }
    //将剩余部分合并
    while (index1 < list1.length) {
        list.data[index++] = list1.data[index1++];
    }
    while (index2 < list2.length) {
        list.data[index++] = list2.data[index2++];
    }
    list.length = index;
    return true;
}

// 2.2.3-8: 互换一维数组中的两个顺序表
int changePos(int l[],int m,int n){
    int i=0,j=0,k=0;
    int tmp=0;
    
    for(;i<n;i++){
    tmp=l[m+n-1];
        for(j=m+n-1;j>0;j--){
            l[j]=l[j-1];
        }
        l[0]=tmp;
        
    }
    return 0;

}
// 2.2.3-9: 查找x，若找到，与后面的交换；若找不到，插入表中
int fun(int l[],int left,int right,int x){
    int i=0,j=0,k=0;
    int mid=(left+right)/2;
    if(left==right){
//      printf("%d\n",left);
        if(l[left]<x)return left;
        if(l[left]>x)return left-1;
    }
//  printf("%d\n",mid);
    if(l[mid]==x){
        return mid;
    }
    if(l[mid]<x){
        return fun(l,mid+1,right,x);
    }
    if(l[mid]>x){
        return fun(l,left,mid-1,x);
    }
}
void findReplace(int List[], int length, int x){

    if(x>=List[length-1]){
        List[length]=x;
    }else if(x<List[0]){
        for(int i=length;i>0;i--){
            List[i]=List[i-1];
        }
        List[0]=x;
    }else{
        int pos=fun(List,0,length-1,x);
        printf("%d\n",pos);
        if(List[pos]==x){
            int tmp=List[pos+1];
            List[pos+1]=x;
            List[pos]=tmp;
        }
        else{
            for(int j=length;j>pos+1;j--){
                List[j]=List[j-1];
            }
            List[pos+1]=x;
        }
    }

}
// 2.2.3-10 循环移动
int fun(int l[],int m,int n){
    int mid=(m+n)/2;
    for(int i=0;i<=(n-m)/2;i++){ // m+i<=n-i
        int tmp=l[n-i];
        l[n-i]=l[m+i];
        l[m+i]=tmp;
    }
    return 0;

}
// 2.2.3-12 寻找主元素
int findMain(int l[],int n){
    int tmp=l[0];
    int count=0;
    for(int i=0;i<n;i++){
        if(l[i]==tmp){
            count++;
        }else{
        if(count>0){
            count--;
        }else{
                count++;
                tmp=l[i];
            }
        }
    }
    count=0;
    for(int i=0;i<n;i++){
        if(l[i]==tmp){
            count++;
        }
    }
    if(count>n/2)return tmp;
    else return -1;
}

// 2.2.3-13 寻找最小正整数
int findMinInt(int l[],int n){
    int note[n]={0};
    int count = 0;
    int min = 100000;
    for(int i=0;i<n;i++){ // m+i<=n-i
        if(l[i]>0 && l[i]<=n)
        {
            note[l[i]-1]=1;
        }
        else if(l[i]>=n)
        {
            if(l[i]<min)
                min = l[i];
            count++;
        }
    }
    if(count ==n)
        return count-1;
    else
    {
        for(int i=0;i<n;i++)
        {
            if(note[i]==0)
                return i+1;
        }
    }
    return -1;

}
int main() {
    /*题目1测试*/
//    SqList l;
//    l.length = 4;
//    l.data[0] = 11;
//    l.data[1] = 41;
//    l.data[2] = 2;
//    l.data[3] = 31;
//    int value = -1;
//
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }
//    printf("\n");
//    deleteMinElem(l, value);
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }
//    printf("\nvalue:-->%d", value);


//    /*题目2测试*/
//    SqList l;
//    l.length = 1;
//    l.data[0] = 11;
//    l.data[1] = 41;
//    l.data[2] = 2;
//    l.data[3] = 31;
//    l.data[4] = 311;
//
//
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }
//    printf("\n");
//    reverseList(l);
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }


//    /*题目3测试*/
//    SqList l;
//    l.length = 5;
//    l.data[0] = 11;
//    l.data[1] = 11;
//    l.data[2] = 2;
//    l.data[3] = 11;
//    l.data[4] = 111;
//
//
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }
//    printf("\n");
//    deleteX_2(l, 11);
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }

//    /*题目4测试*/
//    SqList l;
//    l.length = 5;
//    l.data[0] = 1;
//    l.data[1] = 2;
//    l.data[2] = 31;
//    l.data[3] = 4;
//    l.data[4] = 5;
//
//
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }
//    printf("\n");
//    deleteS_T(l, 31, 31);
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }

//    /*题目6测试*/
//    SqList l;
//    l.length = 7;
//    l.data[0] = 1;
//    l.data[1] = 2;
//    l.data[2] = 2;
//    l.data[3] = 3;
//    l.data[4] = 5;
//    l.data[5] = 5;
//    l.data[6] = 5;
//
//
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }
//    printf("\n");
//    delete_Same(l);
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }
//    return 0;

    /*题目7测试*/
    // SqList l;
    // SqList l1;
    // SqList l2;
    // l1.length = 3;
    // l2.length = 2;
    // l1.data[0] = 1;
    // l1.data[1] = 10;
    // l1.data[2] = 1100;
    // l2.data[0] = 4;
    // l2.data[1] = 100;
    // mergeTwoList(l1, l2, l);


    // printf("\n");
    // for (int i = 0; i < l.length; ++i) {
    //     printf("%d\t", l.data[i]);
    // }

    /*题目8测试*/
    // int testData[] = {1,2,3,4,5,6,7,8,9,10};
    // changePos(testData, 3, 7);

    // printf("\n");
    // for (int i = 0; i < 10; ++i) {
    //     printf("%d\t", testData[i]);
    // }


    /*题目9测试*/

    // int List[7]={1,2,3,5,6,9,10};
    // int x=0;
    // scanf("%d",&x);
    // findReplace(List,7,x);
    // int i;
    // for(i=0;i<7;i++){
    //     printf("%d ",List[i]);
    // }

    /*题目10测试*/
    // int p=3;
    // int List[6]={1,2,3,4,5,6};
    // fun(List,0,p-1);
    // fun(List,p,5);
    // fun(List,0,5);
    // for(int i=0;i<6;i++){
    //     printf("%d ",List[i]);
    // }
    /*题目12测试*/
    // int p=3;
    // int List[]={1,0,1,0,2,1,1,4,1};
    // p=findMain(List,9);
    // printf("%d ",p);
    /*题目13测试*/
    int p=3;
    int List[6]={1,2,9,7,5,6};
    p = findMinInt(List,6);
    printf("%d \n",p);

    return 0;

}