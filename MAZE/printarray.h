#pragma once
void printarray(int** Maze) {//���Թ��������Թ����飬��ӡ�Թ�
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (Maze[i][j] == PATH)
                printf("1");//��ʾ��· ���ڻ�ռ����λ������Ҫ�������ո�
            else if (Maze[i][j] == WALL)
                printf("0");//��ʾǽ��
            else if (Maze[i][j] == PLAYER)
                printf("2");//��ʾ���
            else
                printf("��"); //��ʾ����
        }
        printf("\n");
    }
}