#pragma once
void automa()
{
    system("cls");
    InitStack(&minroute);
    printframe();
    srand((unsigned)time(NULL));
    //��������ռ�
    int** Maze = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++)
    {
        Maze[i] = (int*)calloc(SIZE, sizeof(int));
    }
    //�õ�����������
    k = 0;
    shortroad = 100000;
    roadnum = 1;
   
    int out;
    out = init(Maze);
    GotoXY(45, 7);
    printf("��ǰ�����ҵ�");
    printf("%d", roadnum);
    printf("��·");
    GotoXY(46, 7);
    printf("�Ѿ��ҵ�");
    printf("%d", roadnum - 1);
    printf("��·");
    SqStack route;
    InitStack(&route);
    PosType start = { START_X,START_Y }, end = { out,SIZE - 2 };
    Push(&route, start);
    Maze[start.x][start.y] = TRODDEN;
    GotoXY(POS_X + start.x, POS_Y + start.x * 2);
    Sleep(AUSPEED);
    printf("��");
    GotoXY(4 + (k) / 10, 91 + (k % 10) * 9);
    printf("  (%2d,%2d)", start.x, start.x);
    k++;
    recursion(Maze, &route, start, end);
    GotoXY(45, 7);
    printf("��Ϸ����            ");
    GotoXY(46, 7);
    printf("һ����");
    printf("%d", roadnum - 1);
    printf("��·    ");
    GotoXY(49, 7);
    printf("���ڴ�ӡ���·��");
    printminroute();
    DestroyStack(&minroute);
    GotoXY(49, 7);
    printf("��ͼ·��Ϊ���·��");
    GotoXY(50, 7);
    system("pause");
    system("cls");
}