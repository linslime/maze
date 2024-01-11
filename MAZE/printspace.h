void printspace()
{
	int i, j;
	for (int i = 0; i < 47; i++)
	{
		GotoXY(4 + i, 89);
		for (j = 0; j < 96; j++)
		{
			printf(" ");
		}
			
	}
}