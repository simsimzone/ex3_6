#include <stdio.h>
#include<math.h>

#define MAX_CHARS 1000

void reverse(char s [])
{
	int i, j;
	char temp;
	for (j = 0; s[j] != '\0'; j++);
	if (s[--j] == '\n')
		s[j--] = '\0';

	for (i = 0; i < j; i++)
	{
		temp = s[i];
		s[i] = s[j];
		s[j--] = temp;
	}
}

void itoa3(int n, char s [], int width)
{
	int i, sign;
	sign = n;
	i = 0;
	do
	{
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10)); //n will eventually be 0. 
	if (sign < 0)
		s[i++] = '-';
	while (i < width)
		s[i++] = ' ';

	s[i] = '\0';
	reverse(s);
}

//Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. 
//The third argument is a minimum field width; the converted number must be padded with 
//blanks on the left if necessary to make it wide enough.
void ex3_6()
{
	char s[MAX_CHARS];
	int n = -4125;
	itoa3(n, s, 6);
	printf("%s\n", s);
}

main()
{
	ex3_6();
	printf("\nPress ENTER to continue. . .\n");
	getchar();
}