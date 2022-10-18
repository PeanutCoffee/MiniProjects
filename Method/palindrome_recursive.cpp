#include <bits/stdc++.h>
using namespace std;
bool palincheck(char s[], int start, int end)
{
    if (start == end || start > end) // start > end is given because in even size of string, the start index will go after end, and at one point it will return false, which would be incorrect
    {
        return true;
    }
    if (s[start] == s[end])
    {
        return palincheck(s, start + 1, end - 1);
    }
    return false;
}
bool is_palindrome(char s[])
{
    int len = strlen(s);
    if (len == 1)
    {
        return true;
    }
    return palincheck(s, 0, len - 1);
}
int main()
{
    char s[] = "";
    cin >> s;
    if (is_palindrome(s))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}
