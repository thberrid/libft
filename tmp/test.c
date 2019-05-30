#include <libft.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*str;
	int		ret;

	if (ac > 1)
	{
		str = NULL;
		fd = open(av[1], O_RDONLY);
		while ((ret = get_next_line(fd, &str)) > 0)
			ft_putendl(str);
		close(fd);
		if (ret < 0)
			ft_putendl("error");
	}
	else
		ft_putendl("no file");
	return (0);
}
