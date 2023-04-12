//老鼠走迷宫，回溯法
#include<iostream>
#include<stack>
using namespace std;

//迷宫数组
// 1 是墙，0 是可以走的路，2 是已经走过的路，-1是错误路线，3表示最终正确的路线
int maze[10][12] = {1,1,1,1,1,1,1,1,1,1,1,1,
                    1,0,0,0,1,1,1,1,1,1,1,1,
                    1,1,1,0,1,1,0,0,0,0,1,1,
                    1,1,1,0,1,1,0,1,1,0,1,1,
                    1,1,1,0,0,0,0,1,1,0,1,1,
                    1,1,1,0,1,1,0,1,1,0,1,1,
                    1,1,1,0,1,1,0,1,1,0,1,1,
                    1,1,1,1,1,1,0,1,1,0,1,1,
                    1,1,0,0,0,0,0,0,1,0,0,1,
                    1,1,1,1,1,1,1,1,1,1,1,1};
const int exit_x = 8, exit_y = 10;  //设置出口
stack<int>path_x;   //记录老鼠的路线x
stack<int>path_y;   //记录老鼠的路线y
void fun(int x, int y);
void show_path();
int main() {
    //入口为（1，1）
    path_x.push(1);
    path_y.push(1);
    fun(1,1);
    show_path();
}

// 判断这个位置是否能走
bool judge(int x, int y) {
    if(maze[x][y] == 0) return true;
    return false;
}

//走迷宫
void fun(int x, int y) {    // 表示当前位置
    if(x == exit_x && y == exit_y)  return ;
    if(judge(x+1,y)) {  //如果上一格可以走
        path_x.push(x+1);
        path_y.push(y);
        maze[path_x.top()][path_y.top()] = 2;
    } else if(judge(x-1,y)) {  //如果下一格可以走
        path_x.push(x-1);
        path_y.push(y);
        maze[path_x.top()][path_y.top()] = 2;
    } else if(judge(x,y-1)) {  //如果左一格可以走
        path_x.push(x);
        path_y.push(y-1);
        maze[path_x.top()][path_y.top()] = 2;
    } else if(judge(x,y+1)) {  //如果右一格可以走
        path_x.push(x);
        path_y.push(y+1);
        maze[path_x.top()][path_y.top()] = 2;
    } else {  //都不能走（因为走过的路也不能走）
        maze[x][y] = -1;    //错误路线
        path_x.top();
        path_y.top();
        path_x.pop();
        path_y.pop();
    }
    fun(path_x.top(), path_y.top());
}

//显示最终路线
void show_path() {
    int x,y;
    while(!path_x.empty()) {
        x = path_x.top();
        y = path_y.top();
        maze[x][y] = 3; //3表示最终正确的路线
        path_x.pop();
        path_y.pop();
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 12; j++) {
            if(maze[i][j] == 1)         printf("1");
            else if(maze[i][j] == 3)    printf("*");
            else                        printf(" ");
        }
        putchar('\n');
    }
}