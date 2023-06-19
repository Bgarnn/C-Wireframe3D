#include "fdf.h"

static int	ft_upper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static int	ft_prefix(char *str, int base_num)
{
	int	i;

	i = 0;
	if (str[i] == '0')
		i++;
	if ((base_num == 16) && (str[i] == 'X' || str[i] == 'x'))
		return (1);
	return (0);
}

static int	ft_value(char c, int base_num)
{
	char	*base_char;
	int		i;

	base_char= "0123456789ABCDEF";
	i = 0;
	while (i < base_num)
	{
		if ((base_char[i] == ft_upper(c)) || (base_char[i] == '\n'))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_isvalid(char *str, int base_num)
{
	size_t	i;
	size_t	digit;

	i = 0;
	digit = 0;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if ((base_num != 10) && !(ft_prefix(&str[i], base_num)))
		return (0);
	if ((base_num == 2) || (base_num == 16))
		i = i + 2;
	else if ((base_num == 10) && ((str[i] == '-') || (str[i] == '+')))
		i++;
	while (ft_value(str[i], base_num) >= 0)
	{
		i++;
		digit++;
	}
	if ((str[i] == '\0') || digit)
		return (1);
	else
		return (0);
}

int	ft_atoi_base(char *str, int base_num)
{
	unsigned long	result;
	size_t			i;

	result = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (ft_prefix(&str[i], base_num) == 0)
		return (0);
	i = i + 2;
	while (ft_value(str[i], base_num) >= 0)
	{
		result = (result * base_num) + (ft_value(str[i], base_num));
		i++;
	}
	return ((int)(result));
}