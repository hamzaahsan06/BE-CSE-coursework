#include <iostream>
using namespace std;
#include <cstring>

int myLength(char s[])
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }

    return len;
}

char *MySubstring(char s[], int ip, int len)
{
    int i = ip;
    int count = 0;

    char *dest = new char[len + 1];

    while (count < len)
    {
        dest[count] = s[i];
        i++;
        count++;
    }

    dest[count] = '\0';

    return dest;
}

char *MyConcat(char a[], char b[])
{
    int i = myLength(a);
    int j = myLength(b);

    int count = 0;
    while (count <= j)
    {
        a[i] = b[count];
        i++;
        count++;
    }
    return a;
}

char *ins(char T[], int ip, char P[])
{
    char *temp1 = MySubstring(T, 0, ip);
    char *temp2 = MySubstring(T, ip, myLength(T) - ip + 1);

    MyConcat(temp1, P);
    MyConcat(temp1, temp2);

    T = temp1;

    return T;
}

char *del(char T[], int ip, int L)
{
    char *temp1 = MySubstring(T, 0, ip);
    char *temp2 = MySubstring(T, ip + L, myLength(T) - ip - L + 1);

    MyConcat(temp1, temp2);

    T = temp1;

    return T;
}