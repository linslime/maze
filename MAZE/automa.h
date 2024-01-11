#pragma once
void automa()
{
    system("cls");
    InitStack(&minroute);
    printframe();
    srand((unsigned)time(NULL));
    //申请数组空间
    int** Maze = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++)
    {
        Maze[i] = (int*)calloc(SIZE, sizeof(int));
    }
    //得到出口纵坐标
    k = 0;
    shortroad = 100000;
    roadnum = 1;
   
    int out;
    out = init(Maze);
    GotoXY(45, 7);
    printf("当前正在找第");
    printf("%d", roadnum);
    printf("条路");
    GotoXY(46, 7);
    printf("已经找到");
    printf("%d", roadnum - 1);
    printf("条路");
    SqStack route;
    InitStack(&route);
    PosType start = { START_X,START_Y }, end = { out,SIZE - 2 };
    Push(&route, start);
    Maze[start.x][start.y] = TRODDEN;
    GotoXY(POS_X + start.x, POS_Y + start.x * 2);
    Sleep(AUSPEED);
    printf("★");
    GotoXY(4 + (k) / 10, 91 + (k % 10) * 9);
    printf("  (%2d,%2d)", start.x, start.x);
    k++;
    recursion(Maze, &route, start, end);
    GotoXY(45, 7);
    printf("游戏结束            ");
    GotoXY(46, 7);
    printf("一共有");
    printf("%d", roadnum - 1);
    printf("条路    ");
    GotoXY(49, 7);
    printf("正在打印最短路径");
    printminroute();
    DestroyStack(&minroute);
    GotoXY(49, 7);
    printf("右图路径为最短路径");
    GotoXY(50, 7);
    system("pause");
    system("cls");
}