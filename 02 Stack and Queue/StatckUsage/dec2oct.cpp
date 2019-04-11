#include <stack>
#include <iostream>

using namespace std;
// 利用栈实现十进制转八进制
// 使用C++中的STL容器Stack

int dec2oct(int dec)
{
    stack<int> s;
    while (dec > 0)
    {
        s.push(dec % 8);
        dec /= 8;
    }
    int ans = 0;
    int temp = 1;
    while (!s.empty())
    {
        ans = ans * 10 + s.top();
        temp *= 10;
        s.pop();
    }
    return ans;
}

int main()
{
    int num;
    cin >> num;
    cout << dec2oct(num) << endl;
    return 0;
}