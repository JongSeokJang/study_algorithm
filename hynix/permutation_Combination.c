#include <stdio.h>
 
#define MAX_STRING_LENGTH 10
 
int stackTop = 0;
char combinationStack[MAX_STRING_LENGTH];
 
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
void permutation(char *str, int l, int r)
{
    if (l == r)
    {
        printf("%s\n", str);
    }
    else
    {
        for (int i = l; i <= r; i++) 
        {
            swap((str+l), (str+i));
            permutation(str, l+1, r);
            swap((str+l), (str+i)); //backtrack
        }
    }
}
 
void push(char ch) 
{
    combinationStack[stackTop++] = ch;
    combinationStack[stackTop] = '\0';
}
 
void pop() 
{
    combinationStack[--stackTop] = '\0';
}
 
void combination(const char* str, int length, int offset, int k) 
{
    if (k == 0) 
    {
        printf("%s\n", combinationStack);
        return;
    }
    for (int i = offset; i <= length - k; ++i) 
    {
        push(str[i]);
        combination(str, length, i+1, k-1);
        pop();
    }
}
 
int main()
{
    int N, K, T;
    char str[MAX_STRING_LENGTH];
    scanf("%d", &T);
 
    for (int test_case = 1; test_case <= T; test_case++) 
    {
        scanf("%s%d%d", str, &N, &K);
        str[N] = 0;
        printf("#%d\n", test_case);
 
        permutation(str, 0, N-1);
        combination(str, N, 0, K);
    }
 
    return 0;
}
