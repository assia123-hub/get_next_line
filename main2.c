
// #include <errno.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	int fd = open("text1.txt", O_RDONLY | O_CREAT , 0777);
// 	int fd1 = open("text2.txt", O_RDONLY | O_CREAT ,0777);
// 	int fd2 = open("text3.txt", O_RDONLY | O_CREAT, 0777);
// 	int fd3 = open("text4.txt", O_RDONLY | O_CREAT, 0777);
// 	printf("1 = %d\n2 = %d\n3 = %d\n4 = %d\n",fd, fd1, fd2, fd3);
// 	if (fd < 0 || fd1 < 0 || fd2 < 0 || fd3 < 0)
// 	{
// 		printf("\nmatsaybch\n");
// 		return (1);
// 	}

// 	// char *line;
// 	// while ((line = get_next_line(fd)) != NULL)
// 	// {
// 	// 	printf("%s", line);
// 	// 	free(line);
// 	// }
// 	// close(fd);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd3));
// 	printf("%s", get_next_line(fd3));
// 	printf("%s", get_next_line(fd3));
// 	printf("%s", get_next_line(fd3));
// 	printf("%s", get_next_line(fd3));
// 	printf("%s", get_next_line(fd3));
// 	printf("%s", get_next_line(fd3));
// 	printf("%s", get_next_line(fd3));
// 	close(fd);
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }

// int	main(void)
// {
// 	int fd[4];
// 	char *line;
// 	int i;
	
// 	fd[0] = open("text1.txt", O_RDONLY | O_CREAT, 0777);
// 	fd[1] = open("text2.txt", O_RDONLY | O_CREAT, 0777);
// 	fd[2] = open("text3.txt", O_RDONLY | O_CREAT, 0777);
// 	fd[3] = open("text4.txt", O_RDONLY | O_CREAT, 0777);
// 	printf("File descriptors:\n");
// 	for (i = 0; i < 4; i++)
// 	{
// 		printf("fd%d = %d\n", i + 1, fd[i]);
// 		if (fd[i] < 0)
// 		{
// 			printf("Error opening file %d: %s\n", i + 1, strerror(errno));
// 			while (--i >= 0)
// 				close(fd[i]);
// 			return (1);
// 		}
// 	}
// 	for (i = 0; i < 4; i++)
// 	{
// 		printf("\nContents of file %d:\n", i + 1);
// 		while ((line = get_next_line(fd[i])) != NULL)
// 		{
// 			printf("%s", line);
// 			free(line);
// 		}
// 		close(fd[i]);
// 	}

// 	return (0);
// }