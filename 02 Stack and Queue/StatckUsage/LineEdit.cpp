#include <stack>
#include <conio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

void saveLine(stack<char> &mem, string &lines)
{
    string temp;
    while (!mem.empty())
    {
        char c = mem.top();
        temp += c;
        mem.pop();
    }
    reverse(temp.begin(), temp.end());
    lines.append(temp);
}

void LineEdit()
{
    stack<char> mem;
    string lines;
    char ch;
    bool goon = true;
    while (ch = getchar())
    {
        switch (ch)
        {
        case '$':
            saveLine(mem, lines);
            goon = false;
            break;
        case '#':
            if (!mem.empty())
            {
                mem.pop();
            }
            break;
        case '@':
            while (!mem.empty())
                mem.pop();
            break;
        case '\n':
            mem.push('\n');
            saveLine(mem, lines);
            break;
        default:
            mem.push(ch);
            break;
        }
        if(!goon)break;
    }
    cout << lines << endl;
}

int main()
{
    LineEdit();
    return 0;
}