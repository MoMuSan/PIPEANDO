#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;

	s3 = (char *)calloc(strlen(s1) + strlen(s2) + 1, sizeof(char));
	if (!s3)
		return (NULL);
	s3 = strcat(s3, s1);
	s3 = strcat(s3, s2);
	return ((char *)s3);
}
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
	//int		start;
	int		row;

	row = 0;
	//start = 0;
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
	int acc;
	char *join;

    while (envp[i] != NULL)
    {
        //printf ("%s\n", envp[i]);
        if (strncmp(envp[i],var, 5) == 0)
		
			split = ft_split(&envp[i][5],':');  //le paso la dirección, porque le estoy especificando
												//la segunda coordenada (que se corresponde con el tamaño de PATH=)
		 
        i++;
    }
	i = 0;
	while (split[i] != NULL)
	{
		join = ft_strjoin(split[i], "/");
		join = ft_strjoin(join, argv[1]);
		acc = access(join, F_OK);
		if (acc == 0)
			execve(join, &argv[1], envp);
		i++;
	}
	printf("ARGC %d ARGV %s\n", argc, *argv);
	printf("Not found\n");
	return (0);
}