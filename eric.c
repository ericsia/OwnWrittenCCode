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

/*remember to free(variable); to reclaim memory*/
char* getText(char* msg)
{
	/*According the ISO IEC 7813 the cardholder name length must be 2 to 26 characters 
	including first name, last name and spaces*/

	/*if use char result[26] then it is local to getText(char* msg).
	After returns, that memory is reclaimed and can be used by other code.
	To fix gibberish you shall not return pointers to local variables,
	instead need to dynamically allocating a memory for return the result*/
	char* result = (char*)malloc(26 * sizeof(char));;
	int len;

	do
	{
		printf(msg);
		fgets(result, 26, stdin);
		/*fgets() small input last character in the array will be '\n'*/
		len = strlen(result);
		result[len - 1] = '\0';

	/*need to use result[0] to check if user don't enter anything*/
	} while (result[0] == ' ' || result[0] == NULL);

	
	return result;
}