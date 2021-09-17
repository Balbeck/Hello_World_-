# include "get_next_line.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

int	ft_read_fill_stock(char **stock, int fd, char *buf, int ret)
{
	char	*tmp;

	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	tmp = ft_strjoin(stock[fd], buf);
	free (stock[fd]);
	stock[fd] = tmp;
	tmp = NULL;
	return (ret);
}

ssize_t	ft_line_feeder(ssize_t ret, char **stock, int fd, char **line)
{
	char	*tmp;
	size_t	len_line;
	size_t	len_stock;

	len_line = ft_strlen(stock[fd], '\n');
	len_stock = ft_strlen(stock[fd], '\0') - len_line;
	if (ret == 0)
	{
		*line = ft_substr(stock[fd], 0, ft_strlen(stock[fd], '\0'));
		free (stock[fd]);
		stock[fd] = NULL;
		return (0);	
	}
	if (ret > 0)
	{
		*line = ft_substr(stock[fd], 0, len_line);
		tmp = ft_substr(stock[fd], (len_line + 1), len_stock + 1);
		free (stock[fd]);
		stock[fd] = tmp;
		return (1);
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		ret;
	static char	*stock[255];
	char		buf[BUFFER_SIZE + 1];

	ret = 1;
	if (read(fd, stock[fd], 0) == -1 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!stock[fd])
	{
		stock[fd] = (char *)malloc(sizeof(char) * 1);
		if (!stock[fd])
			return (-1);
		stock[fd][0] = '\0';
	}
	while (ret > 0 && ft_check(stock[fd]) !=1)
		ret = ft_read_fill_stock(stock, fd, buf, ret);
	ret = ft_line_feeder(ret, &(*stock), fd, line);
	if (ret == 1)
		return (1);
	if (ret == 0)
		return (0);
	return (-1);
}
