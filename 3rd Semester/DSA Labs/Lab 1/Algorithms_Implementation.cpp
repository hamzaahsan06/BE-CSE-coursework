#include <iostream>
#include <cstring>
using namespace std;

int myLength(const char s[])
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

char *myConcatenate(char a[], char b[])
{
    int i = strlen(a);
    int j = strlen(b);

    int count = 0;
    while (count <= j)
    {
        a[i] = b[count];
        i = i + 1;
        count = count + 1;
    }
    return a;
}

char *mySubString(char s[], int ip, int len)
{
    int i = ip;
    int count = 0;

    char *dest = new char[len + 1];

    while (count < len)
    {
        dest[count] = s[i];
        count++;
        i++;
    }

    dest[count] = '\0';

    return dest;
}

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

int main()
{
    int choice = 0;

    while (choice != 5)
    {
        cout << "\n========== STRING OPERATIONS ==========" << endl;
        cout << "1- Find Length" << endl;
        cout << "2- Concatenate two character arrays" << endl;
        cout << "3- Find substring" << endl;
        cout << "4- Find pattern in given string" << endl;
        cout << "5- Exit" << endl;
        cout << "Select an option: \n> ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            char str[200];
            cout << "Write string\n> ";
            cin.getline(str, 200);
            cout << "The length of the string is: " << myLength(str) << endl;
            break;
        }
        case 2:
        {
            char s1[200];
            char s2[200];

            cout << "Enter first string: ";
            cin.getline(s1, 200);

            cout << "Enter second string: ";
            cin.getline(s2, 200);

            if (strlen(s1) + strlen(s2) < 200)
            {
                myConcatenate(s1, s2);
                cout << "Concatenated string = " << s1 << endl;
            }
            else
            {
                cout << "Error: Result would exceed buffer size!" << endl;
            }
            break;
        }
        case 3:
        {
            char s[200];
            int ip, len;

            cout << "Enter string: ";
            cin.getline(s, 200);

            cout << "Enter starting position (ip): ";
            cin >> ip;
            cin.ignore();
            cout << "Enter length: ";
            cin >> len;
            cin.ignore();

            char *result = mySubString(s, ip, len);

            cout << "Substring = " << result << endl;

            delete[] result;
            break;
        }
        case 4:
        {
            char T[200];
            char P[200];

            cout << "Enter text string T: ";
            cin.getline(T, 200);

            cout << "Enter pattern string P: ";
            cin.getline(P, 200);

            int found = index(T, P);

            if (found != -1)
                cout << "Pattern found at position: " << found << endl;
            else
                cout << "Pattern not found." << endl;

            break;
        }
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Choose correct option." << endl;
        }
    }

    return 0;
}