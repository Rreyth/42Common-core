#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open("nl", O_RDONLY);
	while (i != 2)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	close(fd);
	return (0);
}
