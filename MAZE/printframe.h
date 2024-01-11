#pragma once
void printframe()
{
	int i;
	GotoXY(2, 5);
	for (int i = 0; i < 90; i++)
	{
		printf("¡ö");
	}
	GotoXY(51, 5);
	for (int i = 0; i < 90; i++)
	{
		printf("¡ö");
	}
	GotoXY(43, 5);
	for (int i = 0; i < 42; i++)
	{
		printf("¡ö");
	}
	for (int i = 0; i < 50; i++)
	{
		GotoXY(2 + i, 5);
		printf("¡ö");
	}
	for (int i = 0; i < 50; i++)
	{
		GotoXY(2 + i, 87);
		printf("¡ö");
	}
	for (int i = 0; i < 50; i++)
	{
		GotoXY(2 + i, 185);
		printf("¡ö");
	}
	
}