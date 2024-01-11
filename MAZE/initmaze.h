#pragma once
int init(int** Maze)  //初始化迷宫，输入迷宫数组maze,将迷宫最外层设为路径，以（2，2）为起点，创建迷宫，并输出迷宫纵坐标
{
    int i;
    //最外围层设为路径的原因，为了防止挖路时挖出边界，同时为了保护迷宫主体外的一圈墙体被挖穿
    Maze[2][2] = PLAYER;
    for (i = 0; i < SIZE; i++)
    {
        Maze[i][0] = PATH;
        Maze[0][i] = PATH;
        Maze[i][SIZE - 1] = PATH;
        Maze[SIZE - 1][i] = PATH;
    }
    printmaze(Maze);
    //创造迷宫，（2，2）为起点
    CreateMaze(Maze, 2, 2);
    //画迷宫的入口和出口，给出玩家初始位置
    Maze[2][2] = PLAYER;
    //由于算法随机性，出口有一定概率不在（L-3,L-2）处，此时需要寻找出口
    int num = 0;
    PosType space;
    while (1)
    {
        space.x = rand() % (SIZE - 4) + 2;
        space.y = rand() % (SIZE - 4) + 2;
        if (Maze[space.x][space.y] == WALL)
        {
            Maze[space.x][space.y] = PATH;
            Sleep(10);
            GotoXY(POS_X + space.x, POS_Y + space.y * 2);
            printf("  ");
            num++;

        }
        if (num == SPACE)
            break;
    }
    for (i = SIZE - 3; i >= 0; i--)
    {
        if (Maze[i][SIZE - 3] == PATH)
        {
            Maze[i][SIZE - 2] = PATH;
            Sleep(10);
            GotoXY(POS_X + i, POS_Y + (SIZE - 2) * 2);
            printf("  ");
            //返回出口所在的纵坐标
            return i;
        }
    }
}