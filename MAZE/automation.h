#pragma once
void automation()
{
    system("cls");
    printframe();
    srand((unsigned)time(NULL));
    //��������ռ�
    int** Maze = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++)
    {
        Maze[i] = (int*)calloc(SIZE, sizeof(int));
    }
    //�õ�����������
    
    int out;
    out = init(Maze);
    SqStack route;
    InitStack(&route);
    PosType start = { START_X,START_Y }, end = { out,SIZE - 2 };
    //��Ϸ��ʼ
    //system("cls");

    
    //getchar();
    //printf("%d" ,1);
    search(Maze, &route, start, end);
    Sleep(1500);
    system("cls");
    //maze();
    //printf("da");
    //StackTraverse(route);
    //getchar();
}