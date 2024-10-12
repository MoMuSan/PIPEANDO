#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (start >= (unsigned int)strlen(s))
		return (strdup(""));
	if (len > ((size_t)strlen(s) - (size_t)start))
		len = ((size_t)strlen(s) - (size_t)start);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[start] != '\0' && j < len)
	{
		sub[i] = s[start];
		start++;
		i++;
		j++;
	}
	sub[i] = '\0';
	return ((char *)sub);
}
static int	n_words(const char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (word);
}

static char	**free_me(const char *s, char c, char **ptr, int row)
{
	int	i;
	int	len;
	int	start;

	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i++] != c && (s[i] == '\0' || s[i] == c))
		{
			len = i - start;
			ptr[row] = ft_substr(s, start, len);
			if (!ptr[row])
			{
				while (row >= 0)
					free (ptr[row--]);
				free (ptr);
				return (NULL);
			}
			row++;
		}
	}
	ptr[row] = NULL;
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	int		start;
	int		row;

	row = 0;
	start = 0;
	ptr = (char **)malloc(((n_words(s, c)) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr = free_me(s, c, ptr, row);
	return (ptr);
}


int main(int argc, char *argv[], char *envp[])
{
    int i = 0;
    char var[6] = "PATH=";
    char **split;
    while (envp[i] != NULL)
    {
        //printf ("%s\n", envp[i]);
        if (strncmp(envp[i],var, 5) == 0)
			split = ft_split(&envp[i][5],':');  //le paso la dirección, porque le estoy especificando
												//la segunda coordenada (que se corresponde con el tamaño de PATH=) 
        i++;
    }
	printf("\n%s\n", *split);
	printf("ARGC %d ARGV %s\n", argc, *argv);
	//número de argumentos -- nombre del primer argumento (porque no he señalado ningún otro)


    return (0);
}
