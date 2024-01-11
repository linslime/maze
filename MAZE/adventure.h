#pragma once
void adventure()
{
    system("cls");
    printframe();
    srand((unsigned)time(NULL));
    //申请数组空间
    int** Maze = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++)
    {
        Maze[i] = (int*)calloc(SIZE, sizeof(int));
    }
    //得到出口纵坐标

    int out;
    out = init(Maze);
    SqStack route;
    InitStack(&route);
    PosType start = { START_X,START_Y }, end = { out,SIZE - 2 };
    Maze[end.x][end.y] = WALL;
    GotoXY(POS_X + end.x, POS_Y + end.y * 2);
    printf("■");
    PosType monster[MONSTERNUM + 2];
    int num = 1;
    monster[0] = start;
    int i;
    int a, b;
    for (num = 0; num < MONSTERNUM + 1; num++)
    {
        if (num == MONSTERNUM)
        {
            monster[MONSTERNUM + 1] = end;
            Maze[end.x][end.y] = PATH;
            GotoXY(POS_X + monster[num + 1].x, POS_Y + monster[num + 1].y * 2);
            printf("  ");
        }
        else
        {
            while (1)
            {
                monster[num + 1].x = rand() % (SIZE - 4) + 2;
                monster[num + 1].y = rand() % (SIZE - 4) + 2;
                if (Maze[monster[num + 1].x][monster[num + 1].y] == PATH)
                {
                    Maze[monster[num + 1].x][monster[num + 1].y] = MONSTER;
                    Sleep(10);
                    GotoXY(POS_X + monster[num + 1].x, POS_Y + monster[num + 1].y * 2);
                    printf("●");
                    break;

                }
            }
        }
        if (num != MONSTERNUM)
        {
            GotoXY(45, 7);
            printf("第");
            printf("%2d", num + 1);
            printf("个怪兽已经出现      ");
            GotoXY(46, 7);
            printf("怪兽坐标为");
            printf("(%d,%d)    ", monster[num + 1].x, monster[num + 1].y);
            GotoXY(47, 7);
            printf("还有");
            printf("%d", MONSTERNUM - num - 1);
            printf("只怪兽未出现");
        }
        else if(num == MONSTERNUM)
        {
            GotoXY(45, 7);
            printf("怪兽已经全部击败        ");
            GotoXY(46, 7);
            printf("出口已经出现      ");
            GotoXY(47, 7);
            printf("出口坐标为：");
            printf("(%d,%d)", monster[num + 1].x, monster[num + 1].y);
        }
        
        k = 0;
        search(Maze, &route, monster[num], monster[num + 1]);
        printspace();
        for (a = 2; a < SIZE - 2; a++)
        {
            for (b = 2; b < SIZE - 2; b++)
            {
                if (Maze[a][b] == TRODDEN)
                {
                    GotoXY(POS_X + a, POS_Y + b * 2);
                    printf("  ");
                    Maze[a][b] = PATH;
                }
            }
        }
        ClearStack(&route);
    }
    GotoXY(48, 7);
    system("pause");
    system("cls");
}