#pragma once
void printframe()
{
	int i;
	GotoXY(2, 5);
	for (int i = 0; i < 90; i++)
	{
		printf("��");
	}
	GotoXY(51, 5);
	for (int i = 0; i < 90; i++)
	{
		printf("��");
	}
	GotoXY(43, 5);
	for (int i = 0; i < 42; i++)
	{
		printf("��");
	}
	for (int i = 0; i < 50; i++)
	{
		GotoXY(2 + i, 5);
		printf("��");
	}
	for (int i = 0; i < 50; i++)
	{
		GotoXY(2 + i, 87);
		printf("��");
	}
	for (int i = 0; i < 50; i++)
	{
		GotoXY(2 + i, 185);
		printf("��");
	}
	
}