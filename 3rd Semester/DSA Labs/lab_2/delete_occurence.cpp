#include <iostream>
using namespace std;
#include <cstring>
#include "Insertion_and_deletion.cpp"

int index(char T[], char P[])
{
    int t = strlen(T);
    int p = strlen(P);

    int i = 0;
    int max = t - p + 1; // Finds the maximum starting index of T to search P

    while (i < max)
    {
        int j;

        for (j = 0; j < p; j++)
        {
            if (P[j] != T[i + j])
            {
                break; // Breaks if any one character of P differs from the corresponding character of T.
            }
        }

        if (j == p)
        {
            return i; // Returns index only when j reaches the length of P by incrementing and checking.
        }

        i++; // To check for the next possible starting index.
    }

    return -1; // While loop ends, which means P is not found.
}

char *del_all_occurence(char T[], char P[])
{
    int L = myLength(P);
    int ip = index(T, P);

    while (ip != -1)
    {
        T = del(T, ip, L);
        ip = index(T, P);
    }

    return T;
}

int main()
{
    char T[1000] = "The founder of our country was Quaid-e-Azam";
    char p[1000] = "and first Governor General ";

    cout << "Q1(a) Insertion Test:\n";
    cout << "Original T: " << T << "\n";

    char *Ins = ins(T, 12, p);
    cout << "Result T  : " << Ins << "\n\n";

    char T2[1000] = "Database Management Systems";

    cout << "Q1(b) Deletion Test:\n";
    cout << "Original T: " << T2 << "\n";

    char *Del = del(T2, 9, 10);
    cout << "Result T  : " << Del << "\n\n";

    char T3[1000] = "cat dog cat bird cat fish cat";
    char P3[100] = "cat";

    cout << "Q2 Delete All Occurrences Test:\n";
    cout << "Original String: " << T3 << endl;
    cout << "Pattern to delete: " << P3 << endl;

    char *result = del_all_occurence(T3, P3);
    cout << "Result T  : " << result << "\n\n";
    return 0;
}

/*
Output
Q1(a) Insertion Test:
Original T: The founder of our country was Quaid-e-Azam
Result T  : The founder and first Governor General of our country was Quaid-e-Azam

Q1(b) Deletion Test:
Original T: Database Management Systems
Result T  : Database  Systems

Q2 Delete All Occurrences Test:
Original String: cat dog cat bird cat fish cat
Pattern to delete: cat
Result T  :  dog  bird  fish

*/
