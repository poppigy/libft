#include "libft.h"

static int	itoa_count(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static char	*itoa_string(int n, int b)
{
	char	*itoa;
	int		i;

	i = 0;
	itoa = ft_calloc(b + 1, sizeof(char));
	if (itoa == NULL)
		return (NULL);
	if (n < 0)
	{
		itoa[i] = '-';
		n *= -1;
		i++;
	}
	while (n > 9 && --b > 0)
	{
		itoa[b] = n % 10 + '0';
		n = n / 10;
	}
	if (n >= 0)
		itoa[i] = n + '0';
	return (itoa);
}

char		*ft_itoa(int n)
{
	char	*itoa;
	int		i;
	int		b;

	i = 0;
	if (n == -2147483648)
		return (ft_substr("-2147483648", 0, 11));
	b = itoa_count(n);
	itoa = itoa_string(n, b);
	return (itoa);
}
