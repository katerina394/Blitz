#include "StructAndFunctions.h"
#include<stack>
#include "math.h"
int InvertNumber(int x) {
    int res = 0, l, g, tmp = x;
    std::stack<int> s;
    while (tmp != 0) {
        s.push(tmp % 10);
        tmp /= 10;
    }
    for (int i=0; !s.empty(); i++) {
        res += s.top() * pow(10.0, i);
        s.pop();
    }
    return res;
}
char* MaxCommonPrefix(char** a, int n) {
    if (a == 0)
        throw 1;
    for (int i=0; i < n; i++)
        if (a[i] == 0)
            throw 1;
    bool f;
    char c;
    char*res = 0;
    int cn = 0;
    int *b = new int[n];
    for (int i=0; i < n; i++)
        for ( b[i]=0; a[i][b[i]] != 0;  b[i]++) {}
    int min = b[0];
    for (int k=0; k < n; k++)
        if ( b[k] < min)
            min = b[k];
    for (int j=0; j < min; j++) {
        c = a[0][j];
        f = true;
        for (int i=1; i < n; i++) {
            if (a[i][j] != c) {
                f = false;
                break;
            }
        }
        if (f == 1) {
            cn++;
            res = (char*)realloc(res, cn);
            res[cn-1] = c;
        } else {
            res = (char*)realloc(res, cn+1);
            res[cn] = 0;
            return res;
        }
    }
    res = (char*)realloc(res, cn+1);
    res[cn] = 0;
    return res;
}
CNode* InvertPairs(CNode* list) {
    if (list == 0)
        throw 1;
    CNode *temp = list, *tmp;
    list = list->next;
    while (temp->next->next != 0) {
        tmp = temp->next->next;
        temp->next->next = temp;
        if (tmp->next == 0) {
            temp->next = tmp;
            return list;
        }
        temp->next = tmp->next;
        temp = tmp;
        }
    tmp = temp->next->next;
    temp->next->next = temp;
    temp->next = tmp;
    return list;
}
int** SearchPairs(int *a, int n, int sum) {
    if ( (a == 0) || (n < 0) )
        throw 1;
    int** res = 0;
    int k = 0;
    for (int i=0; i < n; i++)
        for (int j=i+1; j < n; j++)
            if (a[i]+a[j] == sum) {
                k++;
                res = (int**)realloc(res, k*sizeof(int*));
                res[k-1] = new int[2];
                res[k-1][0] = a[i];
                res[k-1][1] = a[j];
            }
    return res;
}
