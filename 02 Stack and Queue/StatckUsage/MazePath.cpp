#include <stack>
#include <iostream>

using namespace std;

// 利用栈寻找迷宫路径

// 使用二维数组表示迷宫
// 起点为(1,1)，终点为(9,9)
#define size 10
int maze[size][size] = {
    0,0,0,0,0,0,0,0,0,0,
    0,1,1,0,1,1,1,0,1,0,
    0,1,1,0,1,1,1,0,1,0,
    0,1,1,1,1,0,0,1,1,0,
    0,1,0,0,0,1,1,1,1,0,
    0,1,1,1,0,1,1,1,1,0,
    0,1,0,1,1,1,0,1,1,0,
    0,1,0,0,0,1,0,0,1,0,
    0,0,1,1,1,1,1,1,1,0,
    0,0,0,0,0,0,0,0,0,0
};

struct Node{
    int x;int y;
    int dir;
};

int main()
{
    stack<Node> s;
    int x = 1;
    int y = 1;
    int dir = 0; //dir表示下一步的方向，0~3分别为上右下左
    Node curNode = Node{x, y, dir};
    do
    {
        if(maze[x][y] == 1){
            int nextX,nextY;
            switch (dir)
            {
                case 0:
                    nextX = x;
                    nextY = y-1;
                    break;
                case 1:
                    nextX = x+1;
                    nextY = y;
                    break;
                case 2:
                    nextX = x;
                    nextY = y+1;
                    break;
                case 3:
                    nextX = x-1;
                    nextY = y;
                    break;
                case 4:
                    Node popNode = s.top();
                    s.pop();
                    maze[x][y] = 0;
                    x = popNode.x; y = popNode.y;
                    maze[x][y] = 1;
            }
        }
    } while (!s.empty());
    cout<<"No solution."<<endl;
    return 0;
}