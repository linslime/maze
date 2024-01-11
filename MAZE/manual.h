#pragma once
void manual()
{
    system("cls");
    printframe();
    srand((unsigned)time(NULL));
    //申请数组空间
    int** maze = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++)
    {
        maze[i] = (int*)calloc(SIZE, sizeof(int));
    }
    int out;
    int k = 0;
    int key;
    //int t = 0;
    out = init(maze);
    printmaze(maze);
    SqStack route;
    PosType nowpos = { START_X,START_Y }, end = { out,SIZE - 2 };
    PosType temp = nowpos;
    GotoXY(POS_X + nowpos.x, POS_Y + nowpos.y * 2);
    //Sleep(100);
    printf("★");
    GotoXY(4 + (k) / 10, 91 + (k % 10) * 9);
    printf("  (%2d,%2d)", temp.x, temp.y);
    k++;
    char move;
    while (nowpos.x != end.x || nowpos.y != end.y)
    {
        key = 1;
        move = _getch();
        switch (move)
        {
        case 'W':
        case 'w':
            temp.x--;
            break;
        case 'S':
        case 's':
            temp.x++;
            break;
        case 'A':
        case 'a':
            temp.y--;
            break;
        case 'D':
        case 'd':
            temp.y++;
            break;  //结束程序
        default:
            key = 0;
            break;
        }
        if (move == 27)
            break;
        if ((maze[temp.x][temp.y] == PATH || maze[temp.x][temp.y] == PLAYER) && key)
        {
            GotoXY(POS_X + nowpos.x, POS_Y + nowpos.y * 2);
            printf("  ");
            if (4 + (k) / 10 == 51)
                k += 10;
            GotoXY(4 + (k) / 10, 91 + (k % 10) * 9);
            printf("->(%2d,%2d)", temp.x, temp.y);
            k++;
            GotoXY(POS_X + temp.x, POS_Y + temp.y * 2);
            printf("★");
            nowpos = temp;
        }
        else if (maze[temp.x][temp.y] == WALL)
        {
            switch (move)
            {
            case 'W':
            case 'w':
                temp.x++;
                break;
            case 'S':
            case 's':
                temp.x--;
                break;
            case 'A':
            case 'a':
                temp.y++;
                break;
            case 'D':
            case 'd':
                temp.y--;
                break;  //结束程序
            default:
                break;
            }
        }
    }
    GotoXY(45, 7);
    system("puase");
    system("cls");
}