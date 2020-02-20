/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: manaccac <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 13:57:09 by manaccac     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 18:35:36 by manaccac    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*str;

	str = (char*)s;
	len = 0;
	while (str[len])
		len++;
	if (c == '\0')
		return (str + len);
	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (i == len)
		return (0);
	else
		return (str + i);
}

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		y;
	char		*str;

	i = 0;
	y = 0;
	if (s1 && s2)
	{
		if (!(str = (char *)malloc(sizeof(*str) *
						((ft_strlen(s1) + ft_strlen(s2)) + 1))))
			return (0);
		while (s1 && s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (s2 && s2[y])
			str[i++] = s2[y++];
		str[i] = '\0';
		return (str);
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	if (!(copy = (char*)malloc((sizeof(char*) * (len + 1)))))
		return (0);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_lenght;
	size_t	i;

	str_lenght = ft_strlen(s);
	if ((str_lenght < start) || !s)
		len = 0;
	else if (str_lenght < (start + len))
		len = str_lenght - start;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len && s)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
