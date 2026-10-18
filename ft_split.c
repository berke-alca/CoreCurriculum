
//header pruefen

char	**ft_split(char const *s, char c)
{
    char **new_arr;
    int index_one;
    int index_two;
    int i;
    int i2;

    i2 = 0;
    i = 0;
    index_one = 0;
    index_two = 0;

    while(s[i2] != '\0')
    {
        while(s[i] != c)
        {
            new_arr[index_one][index_two] = s[i];
            i++;
            index_two++;
    }
    index_one++;     
    }
    return new_arr;
}

int main()
{

}