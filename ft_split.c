static int	how_many_words(char const *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word_count++;
		i++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**new_arr;
	int		index_one;
	int		i;
	int		i2;

	i = 0;
	index_one = 0;
	new_arr = malloc(sizeof(char *) * (how_many_words(s, c) + 1));
	if (!new_arr)
		return (0);
	while (index_one < how_many_words(s, c))
	{
		while (s[i] == c)
			i++;
		i2 = i;
		while (s[i2] != c && s[i2] != '\0')
			i2++;
		new_arr[index_one] = ft_substr(s, i, i2 - i);
		if (!new_arr[index_one])
			return (0);
		index_one++;
		i = i2;
	}
	new_arr[index_one] = 0;
	return (new_arr);
}
