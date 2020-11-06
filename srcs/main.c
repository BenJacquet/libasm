#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "../incs/libasm.h"

int main(int ac, char **av)
{
	int ret = 0;
	if (ac == 2)
	{
		char copy[ft_strlen(av[1])];
		char copy2[ft_strlen(av[1])];

		printf("\nSTRLEN TEST-----\n");
		printf("ft=%lu\n", ft_strlen(av[1]));
		printf("rl=%lu\n", strlen(av[1]));

		printf("\nSTRCPY TEST-----\n");
		printf("ft=%s\n", ft_strcpy(copy, av[1]));
		printf("rl=%s\n", strcpy(copy2, av[1]));

		printf("\nSTRDUP TEST-----\n");
		printf("ft_av[1]_dup=%s\n", ft_strdup(av[1]));
		printf("rl_av[1]_dup=%s\n", strdup(av[1]));

		printf("\nWRITE TEST-----STDIN\n");
		errno = 0;
		printf("\nft(%lu)\n", ft_write(1, av[1], ft_strlen(av[1])));
		printf("my_error=%s\n", (strerror(errno)));
		errno = 0;
		printf("\nrl(%lu)\n", write(1, av[1], ft_strlen(av[1])));
		printf("rl_error=%s\n", (strerror(errno)));

		printf("\nWRITE TEST-----FILE----Check files in directory\n");
		errno = 0;
		printf("\nft(%lu)\n", ft_write(open("write_ft.txt", (O_RDWR | O_CREAT), 0666), av[1], ft_strlen(av[1])));
		printf("my_error=%s\n", (strerror(errno)));
		errno = 0;
		printf("\nrl(%lu)\n", write(open("write_rl.txt", (O_RDWR | O_CREAT), 0666), av[1], ft_strlen(av[1])));
		printf("rl_error=%s\n", (strerror(errno)));

		printf("\nWRITE TEST-----BAD_FD\n");
		errno = 0;
		printf("\nft(%lu)\n", ft_write(-1, av[1], ft_strlen(av[1])));
		printf("my_error=%s\n", (strerror(errno)));
		errno = 0;
		printf("\nrl(%lu)\n", write(-1, av[1], ft_strlen(av[1])));
		printf("rl_error=%s\n", (strerror(errno)));
	}
	if (ac == 3)
	{
		char buff[4096 + 1];
		int fd = open(av[1], O_RDONLY);
		int fd2 = open(av[2], O_RDONLY);

		printf("\nSTRCMP TEST-----\n");
		printf("ft=%d\n", ft_strcmp(av[1], av[2]));
		printf("rl=%d\n", strcmp(av[1], av[2]));

		printf("\nREAD TEST-----\n");
		errno = 0;
		ret = ft_read(fd, buff, 4096);
		buff[ret] = '\0';
		printf("ft=(%d)| buffer=%s\n-----------------\n", ret, buff);
		printf("my_error=%s\n", (strerror(errno)));
		errno = 0;
		ret = read(fd2, buff, 4096);
		buff[ret] = '\0';
		printf("rl=(%d)| buffer=%s\n", ret, buff);
		printf("rl_error=%s\n", (strerror(errno)));
		close(fd);
		close(fd2);
	}
	return (0);
}