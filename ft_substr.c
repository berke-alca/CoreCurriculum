
//header aendern 

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size_s;
	size_t	fake_len;
	size_t	i;
	char	*p;

	size_s = ft_strlen(s);
	if (start >= size_s)
		return (ft_strdup(""));
	fake_len = size_s - start;
	if (fake_len > len)
		fake_len = len;
	p = malloc(fake_len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < fake_len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*(int	main()
{
	char	*result;

	result = ft_substr("berkealca", 5, 4);
	printf("%s\n", result);
	free(result);
	return (0);
	//cc .\ft_substr.c .\ft_strlen.c .\ft_strdup.c
}
	*/