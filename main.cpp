
#include <iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
} List;

void getlistA(List *A, int n);//创建包含N个随机数的链表
void getlistB(List *B, int n);//创建包含N个随机数的链表
void showList(List *A);//显示链表内容
void deleteList(List *A);//销毁链表
void insertData(List *A, int x);//有序链表中插入包含数据x的节点
void insertData_reverse(List *A, int x);//有序链表中插入包含数据x的节点
void mergelist(List *A, List *B);//合并A与B，结果存于A中，使得A逆向有序且无重复元素。

int main() {
    int n, m;
    List *A, *B;
    A = new List;
    B = new List;
    A->next = B->next = nullptr;
    cout << "请输入链表A的数据规模n：" << endl;
    cin >> n;
    cout << "请输入链表B的数据规模m：" << endl;
    cin >> m;

    while (n > 0 && m > 0) {
        getlistA(A, n);//创建链表A
        getlistB(B, m);//创建链表B
        cout << "链表A:" << endl;
        showList(A);//显示A的源数据
        cout << "链表B:" << endl;
        showList(B);//显示B的源数据

        cout << "将链表A与B合并后：";

        mergelist(A, B);//将A与B合并，结果存于A，A逆向有序
        cout << "链表A:" << endl;
        showList(A);//显示处理后的链表A

        deleteList(A);//销毁链表A。此时不用销毁B，因为上述合并结束后，B已经为空
        cout << "请输入链表A的数据规模n：" << endl;
        cin >> n;
        cout << "请输入链表B的数据规模m：" << endl;
        cin >> m;

    }
}

void getlistA(List *A, int n) {
    int x, i;
    for (i = 0; i < n; i++) {
        x = rand() % 31;
        insertData(A, x);
    }
}

void getlistB(List *B, int n) {
    int x, i;
    for (i = 0; i < n; i++) {
        x = rand() % 31;
        insertData_reverse(B, x);
    }
}

void showList(List *A) {
    List *p = A->next;
    if (!p) {
        cout << "链表为空" << endl;
        return;
    }
    while (p) {
        printf("%3d", p->data);
        p = p->next;
    }
    printf("\n");
}

void deleteList(List *A) {
    List *p, *p2;
    p = A->next;
    A->next = nullptr;
    while (p) {
        p2 = p->next;
        delete p;
        p = p2;
    }
}

void insertData(List *A, int x) {
    List *p2, *p1, *q;
    p1 = A;
    p2 = p1->next;
    while (p2) {
        if (p2->data > x)
            break;
        else if (p2->data == x)
            return;
        else {
            p1 = p2;
            p2 = p2->next;
        }
    }
    q = new List;
    q->data = x;
    p1->next = q;
    q->next = p2;
}

void insertData_reverse(List *A, int x) {
    List *p2, *p1, *q;
    p1 = A;
    p2 = p1->next;
    while (p2) {
        if (p2->data < x)
            break;
        else if (p2->data == x)
            return;
        else {
            p1 = p2;
            p2 = p2->next;
        }
    }
    q = new List;
    q->data = x;
    p1->next = q;
    q->next = p2;
}

void mergelist(List *A, List *B) {

}