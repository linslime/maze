int direction(PosType now, PosType next)
{
    if (next.x - now.x == -1)
        return 0;
    if (next.x - now.x == 1)
        return 2;
    if (next.y - now.y == -1)
        return 1;
    if (next.y - now.y == 1)
        return 3;
}

void printminroute()
{
     k = 0;
     SElemType* p;
     p = minroute.base;
     while (p != minroute.top - 1)
     {
         GotoXY(POS_X + p->x, POS_Y + p->y * 2);
         printdirection(direction(*p, *(p + 1)));
         GotoXY(POS_X + (p + 1)->x, POS_Y + (p + 1)->y * 2);
         printf("бя");
         GotoXY(4 + (k) / 10, 91 + (k % 10) * 9);
         printf("->(%2d,%2d)", p->x, p->y);
         Sleep(AUSPEED * 15);
         k++;
         p++;
     }
     GotoXY(4 + (k) / 10, 91 + (k % 10) * 9);
     printf("->(%2d,%2d)", p->x, p->y);
}

