#pragma once
int init(int** Maze)  //��ʼ���Թ��������Թ�����maze,���Թ��������Ϊ·�����ԣ�2��2��Ϊ��㣬�����Թ���������Թ�������
{
    int i;
    //����Χ����Ϊ·����ԭ��Ϊ�˷�ֹ��·ʱ�ڳ��߽磬ͬʱΪ�˱����Թ��������һȦǽ�屻�ڴ�
    Maze[2][2] = PLAYER;
    for (i = 0; i < SIZE; i++)
    {
        Maze[i][0] = PATH;
        Maze[0][i] = PATH;
        Maze[i][SIZE - 1] = PATH;
        Maze[SIZE - 1][i] = PATH;
    }
    printmaze(Maze);
    //�����Թ�����2��2��Ϊ���
    CreateMaze(Maze, 2, 2);
    //���Թ�����ںͳ��ڣ�������ҳ�ʼλ��
    Maze[2][2] = PLAYER;
    //�����㷨����ԣ�������һ�����ʲ��ڣ�L-3,L-2��������ʱ��ҪѰ�ҳ���
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
            //���س������ڵ�������
            return i;
        }
    }
}