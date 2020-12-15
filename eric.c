//written by eric, c code to get user input and keep looping when not in range or user enter string
int getInt(char *msg, int min, int max) 
{
	int result, stop = 0;
	do
	{
		printf(msg);
		stop = scanf("%d", &result);
		if (stop != 1) //user enter String, so scanf no return 1
		{
			int buffer = 0; //for clear buffer
			while ((buffer = getchar()) != '\n' && buffer != EOF);
		}
	} while (stop != 1 || result < min || result > max);
	
	return result;
}