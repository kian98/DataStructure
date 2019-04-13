#include <stack>
#include <string>
#include <iostream>

using namespace std;
// 使用栈判断输入的括号是否前后匹配

void checkSymbol(string str)
{
    stack<char> s;
    for(auto c = str.begin();c!=str.end();++c)
    {
        char ch = *c;
        if(ch == '{' || ch == '[' || ch=='(' ||ch=='<')
        {
            s.push(ch);
        }
        else
        {
            if(s.empty())
            {
                cout<<"Error input."<<endl;
                return;
            }
            switch (ch)
            {
                case '>':
                    if(s.top() != '<')
                    {
                        cout<< "Error input."<<endl;
                        return;
                    }else
                    {
                        s.pop();
                    }
                    break;
                case ']':
                    if(s.top() != '[')
                    {
                        cout<< "Error input."<<endl;
                        return;
                    }else
                    {
                        s.pop();
                    }
                    break;
                case ')':
                    if(s.top() != '(')
                    {
                        cout<< "Error input."<<endl;
                        return;
                    }else
                    {
                        s.pop();
                    }
                    break;
                case '}':
                    if(s.top() != '{')
                    {
                        cout<< "Error input."<<endl;
                        return;
                    }else
                    {
                        s.pop();
                    }
                    break;
                default:
                    continue;
                    break;
            }
        }
    }
    if(!s.empty())
    {
        cout<<"Error input."<<endl;
        return;
    }
    cout<<"Correct input."<<endl;
}

int main()
{
    string str;
    cin>>str;
    checkSymbol(str);
    return 0;
}