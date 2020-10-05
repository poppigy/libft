#include "libft.h"

static int	limits_check(int atoi, int sign)
{
	if (atoi == -2147483648 && sign == -1)
		return (-2147483648);
	if (atoi < 0 && sign == -1)
		return (0);
	return (-1);
}

int			ft_atoi(const char *str)
{
	int atoi;
	int sign;

	sign = 1;
	atoi = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		atoi = atoi * 10 + *str - 48;
		str++;
		if (atoi < 0)
			return (limits_check(atoi, sign));
	}
	return (atoi * sign);
}
