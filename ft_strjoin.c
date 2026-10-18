
//header aendern
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	laength_str1;
	size_t	full_laenght;
	size_t	i;

	i = 0;
	laength_str1 = ft_strlen(s1);
	full_laenght = laength_str1 + ft_strlen(s2);
	new_str = malloc(full_laenght + 1);
	if (!new_str)
		return (NULL);
	while (laength_str1 > i)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (full_laenght > i)
	{
		new_str[i] = s2[i - laength_str1];
		i++;
	}
	new_str[full_laenght] = '\0';
	return (new_str);
}

int main()
{

}