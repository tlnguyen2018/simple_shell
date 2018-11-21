#include "shell.h"

/**
 * print_str - prints a string to standard out
 *
 * @str: string to write out
 * Return: int of how many chars written
 */
int print_str(char *str)
{
	if (str == '\0')
		return (-1);
	return (write(STDOUT_FILENO, str, _strlen(str)));
}

/**
 * _strcat_dir - concatenates two strings including a slash
 *
 * @dest: first string
 * @src: second string
 * Return: dest which will have concatenated string
 */
char *_strcat_dir(char *dest, char *src)
{
	char *combine;
	int i, k = 0;

	combine = malloc(sizeof(char) * (_strlen(dest) + _strlen(src) + 2));
	if (combine == '\0')
		return (NULL);

	for (i = 0; i < _strlen(dest); i++)
		*(combine + k++) = *(dest + i);

	*(combine + k++) = '/';

	for (i = 0; i < _strlen(src); i++)
		*(combine + k++) = *(src + i);

	*(combine + k) = '\0';

	return (combine);
}

/**
 * _strlen - return length of a string
 * @s: char pointer for string to measure length
 * Return: length of string, n
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
 * *_strcmp - compares two string
 *
 * @s1: first string
 * @s2: second string
 * Return: int difference between s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	int index;

	for (index = 0; s1[index] != '\0' && s2[index] != '\0'; index++)
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
	}
	return (0);
}
/**
 * _atoi - convert into int value of string
 *
 * @s: pointer for string to parse
 * Return: int pulled from string, 0 if none
 */
int _atoi(char *s)
{
	int index = 0;
	int sign = 1;
	unsigned int number = 0;

	while (s[index] != '\0' && !(s[index] >= '0' && s[index] <= '9'))
	{
		if (s[index] == '-')
			sign = (sign * -1);
		index++;
	}
	for (; s[index] >= '0' && s[index] <= '9'; index++)
		number = (number * 10) + (s[index] - '0');
	return (number * sign);
}
