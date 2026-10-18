
//header aendern 

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	text_length;
	size_t	copy_length;
	size_t	counter;
	char	*new_text;

	text_length = ft_strlen(s);
	if (start >= text_length)
		return (ft_strdup(""));
	copy_length = text_length - start;
	if (copy_length > len)
		copy_length = len;
	new_text = malloc(copy_length + 1);
	if (!new_text)
		return (NULL);
	counter = 0;
	while (counter < copy_length)
	{
		new_text[counter] = s[start + counter];
		counter++;
	}
	new_text[counter] = '\0';
	return (new_text);
}
/*(int	main()
{
	char	*result;

	result = ft_substr("berkealca", 5, 4);
	printf("%s\n", result);
	free(result);
	return (0);
	//cc .\ft_substr.c .\ft_strlen.c .\ft_strdup.c
}	*/