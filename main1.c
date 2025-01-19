#include <errno.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("t.txt", O_RDONLY | O_CREAT);
// 	if (fd < 0)
// 	{
// 		printf("\nmatsaybch\n");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }