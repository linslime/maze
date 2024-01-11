void recursion(int** maze, SqStack* route, PosType nowpos, PosType End)
{
	int i;
	if (nowpos.x == End.x && nowpos.y == End.y)
	{
		GotoXY(45, 7);
		printf("��");
		printf("%d", roadnum);
		printf("��·�Ѿ����ҵ�");
		GotoXY(46, 7);
		printf("�Ѿ��ҵ�");
		printf("%d", roadnum);
		printf("��·");
		if (StackLength(*route) < shortroad)
		{
			GotoXY(47, 7);
			printf("Ŀǰ���·��Ϊ��");
			printf("%d", roadnum);
			printf("��·");
			GotoXY(48, 7);
			printf("���·������Ϊ");
			printf("%d", StackLength(*route));
			printf("��");
			shortroad = StackLength(*route);
			ClearStack(&minroute);
			StackTraverse(*route);
		}
		roadnum++;
		Sleep(1000);
		GotoXY(49, 7);
		//system("pause");
		GotoXY(49, 7);
		printf("                      ");
		GotoXY(45,7);
		printf("��ǰ�����ҵ�");
		printf("%d", roadnum);
		printf("��·");
		GotoXY(46, 7);
		printf("�Ѿ��ҵ�");
		printf("%d", roadnum - 1);
		printf("��·");
		
	}
	else
	{
		for (i = 0; i < 4; i++)       //�����ĸ�����
		{
			PosType temp;
			temp.x = nowpos.x + move[i].x;
			temp.y = nowpos.y + move[i].y;
			if (maze[temp.x][temp.y] == PATH) //�ж����λ�ÿɲ������ߣ�
			{
				Push(route, temp); //��������y����stack�����У�
				maze[temp.x][temp.y] = WALL; //������t,M��¼���λ���Ѿ��߹��ˣ�
				GotoXY(POS_X + nowpos.x, POS_Y + nowpos.y * 2);
				Sleep(AUSPEED);
				printdirection(i);
				GotoXY(4 + (k) / 10, 91 + (k % 10) * 9);
				printf("->(%2d,%2d)", temp.x, temp.y);
				k++;
				GotoXY(POS_X + temp.x, POS_Y + temp.y * 2);
				printf("��");
				recursion(maze,route,temp,End);         //����Ѱ����һ��λ�ã�
				maze[temp.x][temp.y] = PATH; //����֮����Ҫ�����λ����գ���ʾ����·û���߹���
				Pop(route, &temp);			   //���ҽ����λ�ô�ջ��ȥ����
				GetTop(*route, &nowpos);
				Sleep(AUSPEED);
				GotoXY(POS_X + temp.x, POS_Y + temp.y * 2);
				printf("XX");
				k--;
				GotoXY(4 + (k) / 10, 91 + (k % 10) * 9);
				printf("         ");
				GotoXY(POS_X + nowpos.x, POS_Y + nowpos.y * 2);
				printf("��");
			}
		}
	}
}


