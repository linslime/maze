#pragma once
//随机构建迷宫，输入迷宫数组maze,纵坐标x,以及横坐标y，输出迷宫数组，
//其中0表示墙，1表示路径，2表示玩家，5表示路径
void CreateMaze(int** maze, int x, int y)
{
    int i, j;

    maze[x][y] = PATH;
    Sleep(10);
    GotoXY(POS_X + x, POS_Y + y * 2);
    printf("  ");
    //确保四个方向随机，而不再是固定的上下左右这种排列
    int direction[4][2] = { { 1,0 },{ -1,0 },{ 0,-1 },{ 0,1 } };
    for (i = 0; i < 4; i++)
    {
        int r = rand() % 4;
        int temp = direction[0][0];
        direction[0][0] = direction[r][0];
        direction[r][0] = temp;
        temp = direction[0][1];
        direction[0][1] = direction[r][1];
        direction[r][1] = temp;
    }
    //向四个方向开挖
    for (i = 0; i < 4; i++)
    {
        int dx = x;
        int dy = y;
        //控制挖的距离，由Rank来调整大小
        int range = 1 + (RANK == 0 ? 0 : rand() % RANK);
        while (range > 0)
        {
            //计算出将要访问到的坐标
            dx += direction[i][0];
            dy += direction[i][1];
            //排除掉回头路
            if (maze[dx][dy] == PATH)
            {
                break;
            }
            //判断是否挖穿路径
            int count = 0, k;
            for (j = dx - 1; j < dx + 2; j++)
            {
                for (k = dy - 1; k < dy + 2; k++)
                {
                    //abs(j - dx) + abs(k - dy) == 1 确保只判断九宫格的四个特定位置
                    if (abs(j - dx) + abs(k - dy) == 1 && maze[j][k] == PATH)
                    {
                        count++;
                    }
                }
            }
            //count大于1表明墙体会被挖穿，停止
            if (count > 1)
                break;
            //确保不会挖穿时，前进
            range -= 1;
            maze[dx][dy] = PATH;
            Sleep(0);
            GotoXY(POS_X + dx, POS_Y + dy * 2);
            printf("  ");
        }
        //没有挖穿危险，以此为节点递归
        if (range <= 0)
        {
            CreateMaze(maze, dx, dy);
        }
    }
}