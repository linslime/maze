#pragma once
void printarray(int** Maze) {//画迷宫，输入迷宫数组，打印迷宫
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (Maze[i][j] == PATH)
                printf("1");//表示道路 由于回占两个位置所以要有两个空格
            else if (Maze[i][j] == WALL)
                printf("0");//表示墙体
            else if (Maze[i][j] == PLAYER)
                printf("2");//表示玩家
            else
                printf("●"); //表示怪物
        }
        printf("\n");
    }
}