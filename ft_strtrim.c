#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		i;

	if (!s1 || (!s1 && !set))
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i > 0 && ft_strchr(set, s1[i - 1]))
		i--;
	if (i == 0)
	{
		trimmed = ft_calloc(i, sizeof(char));
		return (trimmed);
	}
	trimmed = ft_substr(s1, 0, i);
	return (trimmed);
}
