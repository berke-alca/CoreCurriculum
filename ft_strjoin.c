
//header aendern
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{

    char *new_str;
    int laength_str1;
    int laength_str2;
    int full_laenght;
    int i;

    i = 0;
    laength_str1 = ft_strlen(s1);
    laength_str2 = ft_strlen(s2);
    full_laenght = ft_strlen(s1) + ft_strlen(s2);
    new_str = malloc(full_laenght + 1);
    if (!new_str)
		return (NULL);
    while (i < laength_str1)
	{
		new_str[i] = s1[i];
		i++;
	}
    i = 0;
    while(laength_str2 > 0)
    {
        new_str[laength_str1] = s2[i];
        laength_str2--;
        laength_str1 ++;
        i++;
    }
}
int main()
{

}