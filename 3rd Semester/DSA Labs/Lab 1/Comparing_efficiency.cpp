#include <iostream>
#include <cstring>
#include <chrono>
using namespace std;
using namespace chrono;

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

            auto start = high_resolution_clock::now();
            int result = strlen(str);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);

            auto start1 = high_resolution_clock::now();
            int result1 = myLength(str);
            auto end1 = high_resolution_clock::now();
            auto duration1 = duration_cast<nanoseconds>(end1 - start1);

            cout << "A1:\n";
            cout << "Length = " << result1 << endl;
            cout << "Execution time: " << duration1.count()
                 << " nanoseconds\n";

            cout << "STL strlen():\n";
            cout << "Length = " << result << endl;
            cout << "Execution time: " << duration.count()
                 << " nanoseconds\n";

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
                auto start = high_resolution_clock::now();
                strcat(s1, s2);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<nanoseconds>(end - start);

                auto start1 = high_resolution_clock::now();
                myConcatenate(s1, s2);
                auto end1 = high_resolution_clock::now();
                auto duration1 = duration_cast<nanoseconds>(end1 - start1);

                cout << "A2:\n";
                cout << "Concatenated string = " << s1 << endl;
                cout << "Execution time: " << duration1.count()
                     << " nanoseconds\n";

                cout << "STL cat():\n";
                cout << "Concatenated string = " << s1 << endl;
                cout << "Execution time: " << duration.count()
                     << " nanoseconds\n";
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

            auto start1 = high_resolution_clock::now();
            char *result = mySubString(s, ip, len);
            auto end1 = high_resolution_clock::now();

            auto duration1 = duration_cast<nanoseconds>(end1 - start1);

            string str(s);

            auto start = high_resolution_clock::now();
            string result1 = str.substr(ip, len);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<nanoseconds>(end - start);

            cout << "A3:\n";
            cout << "Substring = " << result << endl;
            cout << "Execution time: " << duration1.count()
                 << " nanoseconds\n";

            cout << "STL substr():\n";
            cout << "Substring = " << result1 << endl;
            cout << "Execution time: " << duration.count()
                 << " nanoseconds\n";

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

            auto start1 = high_resolution_clock::now();
            int found = index(T, P);
            auto end1 = high_resolution_clock::now();

            auto duration1 = duration_cast<nanoseconds>(end1 - start1);

            string text(T);
            string pattern(P);

            auto start2 = high_resolution_clock::now();
            size_t stlFound = text.find(pattern);
            auto end2 = high_resolution_clock::now();

            auto duration2 = duration_cast<nanoseconds>(end2 - start2);

            cout << "A4:\n";

            if (found != -1)
                cout << "Pattern found at position: " << found << endl;
            else
                cout << "Pattern not found." << endl;

            cout << "Execution time: " << duration1.count()
                 << " nanoseconds\n";

            cout << "STL find():\n";

            if (stlFound != string::npos)
                cout << "Pattern found at position: " << stlFound << endl;
            else
                cout << "Pattern not found." << endl;

            cout << "Execution time: " << duration2.count()
                 << " nanoseconds\n";

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