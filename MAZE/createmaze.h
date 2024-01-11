#pragma once
//��������Թ��������Թ�����maze,������x,�Լ�������y������Թ����飬
//����0��ʾǽ��1��ʾ·����2��ʾ��ң�5��ʾ·��
void CreateMaze(int** maze, int x, int y)
{
    int i, j;

    maze[x][y] = PATH;
    Sleep(10);
    GotoXY(POS_X + x, POS_Y + y * 2);
    printf("  ");
    //ȷ���ĸ�����������������ǹ̶�������������������
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
    //���ĸ�������
    for (i = 0; i < 4; i++)
    {
        int dx = x;
        int dy = y;
        //�����ڵľ��룬��Rank��������С
        int range = 1 + (RANK == 0 ? 0 : rand() % RANK);
        while (range > 0)
        {
            //�������Ҫ���ʵ�������
            dx += direction[i][0];
            dy += direction[i][1];
            //�ų�����ͷ·
            if (maze[dx][dy] == PATH)
            {
                break;
            }
            //�ж��Ƿ��ڴ�·��
            int count = 0, k;
            for (j = dx - 1; j < dx + 2; j++)
            {
                for (k = dy - 1; k < dy + 2; k++)
                {
                    //abs(j - dx) + abs(k - dy) == 1 ȷ��ֻ�жϾŹ�����ĸ��ض�λ��
                    if (abs(j - dx) + abs(k - dy) == 1 && maze[j][k] == PATH)
                    {
                        count++;
                    }
                }
            }
            //count����1����ǽ��ᱻ�ڴ���ֹͣ
            if (count > 1)
                break;
            //ȷ�������ڴ�ʱ��ǰ��
            range -= 1;
            maze[dx][dy] = PATH;
            Sleep(0);
            GotoXY(POS_X + dx, POS_Y + dy * 2);
            printf("  ");
        }
        //û���ڴ�Σ�գ��Դ�Ϊ�ڵ�ݹ�
        if (range <= 0)
        {
            CreateMaze(maze, dx, dy);
        }
    }
}