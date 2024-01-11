void recursion(int** maze, SqStack* route, PosType nowpos, PosType End)
{
	int i;
	if (nowpos.x == End.x && nowpos.y == End.y)
	{
		GotoXY(45, 7);
		printf("第");
		printf("%d", roadnum);
		printf("条路已经被找到");
		GotoXY(46, 7);
		printf("已经找到");
		printf("%d", roadnum);
		printf("条路");
		if (StackLength(*route) < shortroad)
		{
			GotoXY(47, 7);
			printf("目前最短路径为第");
			printf("%d", roadnum);
			printf("条路");
			GotoXY(48, 7);
			printf("最短路径长度为");
			printf("%d", StackLength(*route));
			printf("步");
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
		printf("当前正在找第");
		printf("%d", roadnum);
		printf("条路");
		GotoXY(46, 7);
		printf("已经找到");
		printf("%d", roadnum - 1);
		printf("条路");
		
	}
	else
	{
		for (i = 0; i < 4; i++)       //遍历四个方向；
		{
			PosType temp;
			temp.x = nowpos.x + move[i].x;
			temp.y = nowpos.y + move[i].y;
			if (maze[temp.x][temp.y] == PATH) //判断这个位置可不可以走；
			{
				Push(route, temp); //将纵坐标y存入stack数组中；
				maze[temp.x][temp.y] = WALL; //用数组t,M记录这个位置已经走过了；
				GotoXY(POS_X + nowpos.x, POS_Y + nowpos.y * 2);
				Sleep(AUSPEED);
				printdirection(i);
				GotoXY(4 + (k) / 10, 91 + (k % 10) * 9);
				printf("->(%2d,%2d)", temp.x, temp.y);
				k++;
				GotoXY(POS_X + temp.x, POS_Y + temp.y * 2);
				printf("★");
				recursion(maze,route,temp,End);         //继续寻找下一个位置；
				maze[temp.x][temp.y] = PATH; //回溯之后需要将这个位置清空，表示这条路没有走过；
				Pop(route, &temp);			   //并且将这个位置从栈中去除；
				GetTop(*route, &nowpos);
				Sleep(AUSPEED);
				GotoXY(POS_X + temp.x, POS_Y + temp.y * 2);
				printf("XX");
				k--;
				GotoXY(4 + (k) / 10, 91 + (k % 10) * 9);
				printf("         ");
				GotoXY(POS_X + nowpos.x, POS_Y + nowpos.y * 2);
				printf("★");
			}
		}
	}
}


