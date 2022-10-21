/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:59:12 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/21 12:14:40 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

void test_alnum(void);
void test_alpha(void);
void test_ascii(void);
void test_digit(void);
void test_print(void);
void test_strlen(void);
void test_toupper(void);
void test_tolower(void);
void test_memset(void);
void test_strjoin(void);

int	main(void)
{
	test_alnum();
	test_alpha();
	test_ascii();
	test_digit();
	test_print();
	test_strlen();
	test_tolower();
	test_toupper();
	test_memset();
	test_strjoin();
}

void test_alnum(void)
{
	char test[3] = {'a', '8', '_'};
	int	i = 0;

	while (i < 3)
	{
		if (ft_isalnum(test[i]) != isalnum(test[i]))
		{
			printf("ft_isalnum(%c) = %i & isalnum(%c) = %i\n", test[i], ft_isalnum(test[i]), test[i], isalnum(test[i]));
			return ;
		}
		i++;
	}
	printf("ft_isalnum = OK\n");
}

void test_alpha(void)
{
	char test[3] = {'a', 'R', '9'};
	int	i = 0;

	while (i < 3)
	{
		if (ft_isalpha(test[i]) != isalpha(test[i]))
		{
			printf("ft_isalpha(%c) = %i & isalpha(%c) = %i\n", test[i], ft_isalpha(test[i]), test[i], isalpha(test[i]));
			return ;
		}
		i++;
	}
	printf("ft_isalpha = OK\n");
}

void test_ascii(void)
{
	char test[3] = {'a', '8', 128};
	int	i = 0;

	while (i < 3)
	{
		if (ft_isascii(test[i]) != isascii(test[i]))
		{
			printf("ft_isascii(%c) = %i & isascii(%c) = %i\n", test[i], ft_isascii(test[i]), test[i], isascii(test[i]));
			return ;
		}
		i++;
	}
	printf("ft_isascii = OK\n");
}

void test_digit(void)
{
	char test[2] = {'a', '8'};
	int	i = 0;

	while (i < 2)
	{
		if (ft_isdigit(test[i]) != isdigit(test[i]))
		{
			printf("ft_isdigit(%c) = %i & isdigit(%c) = %i\n", test[i], ft_isdigit(test[i]), test[i], isdigit(test[i]));
			return ;
		}
		i++;
	}
	printf("ft_isdigit = OK\n");
}

void test_print(void)
{
	char test[2] = {'a', 25};
	int	i = 0;

	while (i < 2)
	{
		if (ft_isprint(test[i]) != isprint(test[i]))
		{
			printf("ft_isprint(%c) = %i & isprint(%c) = %i\n", test[i], ft_isprint(test[i]), test[i], isprint(test[i]));
			return ;
		}
		i++;
	}
	printf("ft_isprint = OK\n");
}

void test_strlen(void)
{
	char *test[2] = {"123456", "xxx"};
	int	i = 0;

	while (i < 2)
	{
		if (ft_strlen(test[i]) != strlen(test[i]))
		{
			printf("ft_strlen(%s) = %lu & strlen(%s) = %lu\n", test[i], ft_strlen(test[i]), test[i], strlen(test[i]));
			return ;
		}
		i++;
	}
	printf("ft_strlen = OK\n");
}

void test_toupper(void)
{
	char test[2] = {'a', '8'};
	int	i = 0;

	while (i < 2)
	{
		if (ft_toupper(test[i]) != toupper(test[i]))
		{
			printf("ft_toupper(%c) = %c & toupper(%c) = %c\n", test[i], ft_toupper(test[i]), test[i], toupper(test[i]));
			return ;
		}
		i++;
	}
	printf("ft_toupper = OK\n");
}

void test_tolower(void)
{
	char test[2] = {'A', '?'};
	int	i = 0;

	while (i < 2)
	{
		if (ft_tolower(test[i]) != tolower(test[i]))
		{
			printf("ft_tolower(%c) = %c & tolower(%c) = %c\n", test[i], ft_tolower(test[i]), test[i], tolower(test[i]));
			return ;
		}
		i++;
	}
	printf("ft_tolower = OK\n");
}

void test_memset(void)
{
	char str[10];
	char str1[10];
	char test[2] = {'x', 'o'};
	int	test1[2] = {6, 3};
	int	i = 0;

	while (i < 2)
	{
		if (strncmp(ft_memset(str, test[i], test1[i]), memset(str1, test[i], test1[i]), test1[i]) != 0)
		{
			printf("ft_memset(str, %c, %i) = %s & memset(str1, %c, %i) = %s\n", test[i], test1[i], ft_memset(str, test[i], test1[i]), test[i], test1[i],  memset(str1, test[i], test1[i]));
			return ;
		}
		i++;
	}
	printf("ft_memset = OK\n");
}

void test_strjoin(void)
{
	char *s1 = malloc(25 * sizeof(char));
	char *s2 = "world";
	s1 = "Hello ";

	char *mine = ft_strjoin(s1, s2);
	char *test = strcat(s1, s2);
	if (ft_strncmp(mine, test, ft_strlen(mine)) != 0)
	{
		printf("ft_strjoin(%s, %s) = %s		expected = %s\n", s1, s2, mine, test);
		return ;
	}
	else if (&mine == &s1 || &mine == &s2)
	{
		printf("No new string was allocated\n");
	}
	printf("ft_strjoin = OK\n");
	free(s1);
	free(mine);
}