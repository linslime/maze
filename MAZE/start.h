#pragma once
void maze()
{
    full_screen();
    Hide();
    
    while (1) {
        GotoXY(20, 84);
        printf("*******(���Թ�)*******");
        GotoXY(22, 84);
        printf("======================");
        GotoXY(24, 84);
        printf("||   1. �Զ� ģʽ   ||");
        GotoXY(26, 84);
        printf("||   2. ��ͨ ģʽ   ||");
        GotoXY(28, 84);
        printf("||   3. ð�� ģʽ   ||");
        GotoXY(30, 84);
        printf("||   4. �ر� ��Ϸ   ||");
        GotoXY(32, 84);
        printf("======================");
        //system("cls"); //����
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
            break;  //��������
        default:
            break;
        }
    }
}