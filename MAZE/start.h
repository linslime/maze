#pragma once
void maze()
{
    full_screen();
    Hide();
    
    while (1) {
        GotoXY(20, 84);
        printf("*******(走迷宫)*******");
        GotoXY(22, 84);
        printf("======================");
        GotoXY(24, 84);
        printf("||   1. 自动 模式   ||");
        GotoXY(26, 84);
        printf("||   2. 普通 模式   ||");
        GotoXY(28, 84);
        printf("||   3. 冒险 模式   ||");
        GotoXY(30, 84);
        printf("||   4. 关闭 游戏   ||");
        GotoXY(32, 84);
        printf("======================");
        //system("cls"); //清屏
        char t;
        t = getch();
        switch (t) {
        case '1':
            automa();
           
            break;  
        case '2':
            manual();
           
            break;  
        case '3':
            adventure();
            
            break;  
        case '4':
            quit();
            break;  //结束程序
        default:
            break;
        }
    }
}