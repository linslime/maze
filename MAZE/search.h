#pragma once
void search(int** maze, SqStack* route, PosType Start, PosType End)
{

    
    PosType nowpos = Start;
    PosType temp = nowpos;
    int direction = 0;
    int i, j;
    //printf("%d" ,1);
    //printf("%d",StackLength(*route));
    //printf("%d",StackEmpty(*route));
    Push(route, Start);
    maze[nowpos.x][nowpos.y] = TRODDEN;
    GotoXY(POS_X + nowpos.x, POS_Y + nowpos.y * 2);
    Sleep(ADSPEED);
    printf("бя");
    GotoXY(4 + (k) / 10, 91 + (k % 10) * 9);
    printf("  (%2d,%2d)", temp.x, temp.y);
    k++;
    //printf("%d",StackLength(*route));
    //printf("%d",route->top->y);
    
    do
    {
        if (maze[nowpos.x + move[direction % 4].x][nowpos.y + move[direction % 4].y] == PATH || maze[nowpos.x + move[direction % 4].x][nowpos.y + move[direction % 4].y] == MONSTER)
        {
            temp.x = nowpos.x + move[direction % 4].x;
            temp.y = nowpos.y + move[direction % 4].y;
            //printf("%d",temp.x);
            Push(route, temp);
            maze[temp.x][temp.y] = TRODDEN;
            GotoXY(POS_X + nowpos.x, POS_Y + nowpos.y * 2);
            Sleep(ADSPEED);
            printdirection(direction % 4);
            GotoXY(4 + (k) / 10, 91 + (k % 10) * 9);
            printf("->(%2d,%2d)", temp.x, temp.y);
            k++;
            GotoXY(POS_X + temp.x, POS_Y + temp.y * 2);
            printf("бя");
            nowpos = temp;
            if (temp.x == End.x && temp.y == End.y)
            {
                break;
            }
          
           
        }
        else
        {
            if (!StackEmpty(*route) && !RouteBlind(maze, nowpos))
                direction++;
            else if (!StackEmpty(*route) && RouteBlind(maze, nowpos))
            {
                Pop(route, &temp);
                if (!StackEmpty(*route))
                {
                    GetTop(*route, &nowpos);
                    Sleep(ADSPEED);
                    GotoXY(POS_X + temp.x, POS_Y + temp.y * 2);
                    printf("  ");
                    k--;
                    GotoXY(4 + (k) / 10, 91 + (k % 10) * 9);
                    printf("         ");
                    GotoXY(POS_X + nowpos.x, POS_Y + nowpos.y * 2);
                    printf("бя");
                }
            }
        }

    } while (!StackEmpty(*route));
}