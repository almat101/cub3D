#include "cube.h"

int is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}
char	*trim_whitespace(char *str)
{
	char	*end;

	while(is_space((unsigned char)*str))
		str++;
	if(*str == 0)
		return str;
	end = str + ft_strlen(str) - 1;
	while(end > str && is_space((unsigned char)*end))
		end--;
	end[1] = '\0';
	return str;
}
