#pragma once
void printmaze(int** Maze) {//���Թ��������Թ����飬��ӡ�Թ�
    int i, j;
    //GotoXY(30,120);
    for (i = 0; i < SIZE; i++) {
        GotoXY(POS_X + i, POS_Y);
        for (j = 0; j < SIZE; j++) {
            if (Maze[i][j] == PATH)
                printf("  ");//��ʾ��· ���ڻ�ռ����λ������Ҫ�������ո�
            else if (Maze[i][j] == WALL)
            {

                printf("��");//��ʾǽ��
            }

            else if (Maze[i][j] == PLAYER)
                printf("��");//��ʾ���
            else
                printf("��"); //��ʾ����
        }
        printf("\n");
    }
}
