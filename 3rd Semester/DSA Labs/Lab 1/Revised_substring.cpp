#include <iostream>
#include <cstring>
using namespace std;

char *mySubString(char s[], int ip, int len)
{
    if (ip < 0 || len < 0 || (ip + len) > strlen(s))
    {
        return nullptr;
    }

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

int main()
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

    if (result != nullptr)
    {
        cout << "Substring = " << result << endl;
    }
    else
    {
        cout << "Length of substring is out of range." << endl;
    }

    delete[] result;

    return 0;
}
