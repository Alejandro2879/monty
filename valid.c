#include "monty.h"
/**
 * valid - Check if the second argument is a number.
 * @token: String (argument) to check.
 * Return: 1 on fail, 0 on sucess.
 */
int valid(char *token)
{
	int iter = 0;

	if (!token)
		return (1);

	while (token[iter])
	{
		if (token[0] == '-')
		{
			if (!(token[1] >= 0 && token[1] <= 9) || !token[1])
				return (1);
			iter = 1;
			while (token[iter] >= '0' && token[iter] <= '9')
			{
				iter++;
				if (token[iter] == '\0')
					return (1);
			}
			return (0);
		}
		else
		{
			iter = 0;
			while(token[iter] >= '0' && token[iter] <= 9)
			{
				iter++;
				if (token[iter] == '\0')
					return (1);
			}
			return (0);
		}
	}
	return (0);
}
