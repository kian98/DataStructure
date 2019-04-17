#include <stack>
#include <iostream>

using namespace std;

// 利用栈寻找迷宫路径

// 使用二维数组表示迷宫
// 起点为(1,1)，终点为(8,8)
#define SIZE 10
#define MAX_ROW 10
#define MAX_COL 10
int maze[SIZE][SIZE] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
    1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
    1, 0, 1, 1, 1, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 1, 0, 0, 1,
    1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
    1, 1, 0, 0, 0, 0, 1, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

struct Node
{
    int row;
    int col;
};

void print_line()
{
    int i, j;
    for (i = 0; i < MAX_ROW; i++)
    {
        for (j = 0; j < MAX_COL; j++)
            if (maze[i][j] == 1)
            {
                cout.width(4);
                cout << "*";
            }
            else if (maze[i][j] >= 3)
            {
                cout.width(4);
                cout<<maze[i][j]-2;
            }
            else
            {
                cout.width(4);
                cout << "-";
            }
        cout << endl;
    }
}

void visit(Node p, int sign, stack<Node> &S)
{
    // visit()函数将经过的地方设为2
    // 压入当前所在结点，以及到达的结点
    S.push(p);
    switch (sign)
    {
    case 1:
        p.col++;
        S.push(p);
        maze[p.row][p.col] = 2;
        break; //向右
    case 2:
        p.row++;
        S.push(p);
        maze[p.row][p.col] = 2;
        break; //向下
    case 3:
        p.col--;
        S.push(p);
        maze[p.row][p.col] = 2;
        break; //向左
    case 4:
        p.row--;
        S.push(p);
        maze[p.row][p.col] = 2;
        break; //向上
    }
}

int main()
{
    print_line();
    Node p = Node{1, 1};
    maze[p.row][p.col] = 2; //遍历过的点设置为2
    stack<Node> S;
    S.push(p);
    while (!S.empty())
    {
        p = S.top();
        S.pop();
        cout<<p.row<<" "<<p.col<<endl;
        if (p.row == MAX_ROW - 2 && p.col == MAX_COL - 2)
            break;
        if (p.col + 1 < MAX_COL - 1 && maze[p.row][p.col + 1] == 0) //向右
        {
            visit(p, 1, S);
            continue;
        }
        if (p.row + 1 < MAX_ROW - 1 && maze[p.row + 1][p.col] == 0) //向下
        {
            visit(p, 2, S);
            continue;
        }
        if (p.col - 1 >= 1 && maze[p.row][p.col - 1] == 0) //向左
        {
            visit(p, 3, S);
            continue;
        }
        if (p.row - 1 >= 1 && maze[p.row - 1][p.col] == 0) //向上
        {
            visit(p, 4, S);
            continue;
        } //以上是对迷宫的四个方向进行操作
    }
    if (p.row == MAX_ROW - 2 && p.col == MAX_COL - 2) //是否为出口
    {
        int count = S.size() + 3; //为了与迷宫0,1,2的区别所以基数要以3开始
        cout << "(" << p.row << "," << p.col << ")" << endl;
        maze[p.row][p.col] = count;
        while (!S.empty()) //按照前驱进行查找
        {
            count--;
            p = S.top();
            S.pop();
            maze[p.row][p.col] = count;
            cout << "(" << p.row << "," << p.col << ")" << endl;
        }
        print_line();
    }
    else
    {
        cout<<"没有出路"<<endl;
    }
    return 0;
}