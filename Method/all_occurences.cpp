#include <bits/stdc++.h>
using namespace std;
int all_occurences(int nums[], int n, int k, int output[])
{
    if (n == 0)
    {
        return 0;
    }
    int ans = all_occurences(nums + 1, n - 1, k, output);
    if (nums[0] == k)
    {
        for (int i = ans - 1; i >= 0; i--)
        {
            output[i + 1] = output[i] + 1;
        }
        output[0] = 0;
        ans++;
    }
    else
    {
        for (int i = ans - 1; i >= 0; i--)
        {
            output[i] = output[i] + 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int *nums = new int[n];
    int *output = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    int size = all_occurences(nums, n, k, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }
    delete[] nums;
    delete[] output;
    return 0;
}
