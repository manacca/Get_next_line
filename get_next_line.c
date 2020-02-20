/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: manaccac <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 15:12:27 by manaccac     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 16:44:21 by manaccac    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strdel(char **todel)
{
	if (todel)
	{
		free(*todel);
		*todel = NULL;
	}
}

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*s;

	s = (unsigned char *)str;
	while (len-- > 0)
		*s++ = (unsigned char)c;
	return (s);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	str[0] = '\0';
	return (str);
}

int		ft_newline(char **str, char **line, int fd, int ret)
{
	char	*temp;
	int		l;

	l = 0;
	while ((str[fd][l] != '\n' && str[fd][l]))
		l++;
	free(*line);
	if (str[fd][l] == '\n')
	{
		*line = ft_substr(str[fd], 0, l);
		temp = ft_strdup(str[fd] + l + 1);
		free(str[fd]);
		str[fd] = temp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][l] == '\0')
	{
		if (ret == BUFFER_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[255];
	char		*buff;
	char		*temp;
	int			ret;

	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (fd < 0 || line == NULL)
		return (-1);
	*line = ft_strnew(0);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str[fd] = (str[fd] == NULL) ? ft_strnew(0) : str[fd];
		temp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	if (ret < 0)
		return (-1);
	return (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0')
			? 0 : ft_newline(str, line, fd, ret));
}
