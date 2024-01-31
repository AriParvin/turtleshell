#include <stdio.h>
#include <string.h>
#include <malloc.h>

char	*ft_strtok(char *s, char *delim)
{
	static int	currIndex = 0;
	if(!s || !delim || s[currIndex] == '\0')
		return NULL;
	char		*token = (char *)malloc(sizeof(char)*100);
	if(token == '\0')
	       return NULL;	
	int		i = currIndex;
	int		k = 0;
	int		j = 0;

	while (s[i] != '\0')
	{
		j = 0;
		while (delim[j] != '\0'){
			if (s[i] != delim[j])
				token[k] = s[i];
			else goto It;
			j++;
		}
		i++;
		k++;
	}
It:
	token[i] = 0;
	currIndex = i+1;
	return token;
{
