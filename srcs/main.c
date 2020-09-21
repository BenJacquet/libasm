#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

size_t ft_strlen(const char *);
char *ft_strcpy(char *dst, char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fildes, const void *buff, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
char *ft_strdup(const char *s1);

int main(int ac, char **av)
{
	char new[4096 + 1];
	int ret = 0;
	int fd = open(av[1], O_RDONLY);
	int fd2 = open(av[1], O_RDONLY);

	char copy[ft_strlen(av[1])];
	char copy2[ft_strlen(av[1])];
	printf("\nSTRLEN TEST-----\n");
	printf("ft=%lu\n", ft_strlen(av[1]));
	printf("rl=%lu\n", strlen(av[1]));
	printf("\nSTRCMP TEST-----\n");
	printf("ft=%d\n", ft_strcmp(av[1], av[2]));
	printf("rl=%d\n", strcmp(av[1], av[2]));
	printf("\nSTRCPY TEST-----\n");
	printf("ft=%s\n", ft_strcpy(copy, av[1]));
	printf("rl=%s\n", strcpy(copy2, av[1]));
	printf("\nSTRDUP TEST-----\n");
	printf("ft_av[1]_dup=%s\n", ft_strdup(av[1]));
	printf("rl_av[1]_dup=%s\n", strdup(av[1]));
	printf("\nWRITE TEST-----\n");
	printf("\nft(%lu)\n", ft_write(1, av[1], ft_strlen(av[1])));
	printf("\nrl(%lu)\n", write(1, av[1], ft_strlen(av[1])));
	printf("my_error=%s\n", (strerror(errno)));
	printf("rl_error=%s\n", (strerror(errno)));
	printf("\nREAD TEST-----\n");
	ret = ft_read(fd, new, 4096);
	new[ret] = '\0';
	printf("ft=(%d)| buffer=%s\n-----------------\n", ret, new);
	ret = read(fd2, new, 4096);
	new[ret] = '\0';
	printf("rl=(%d)| buffer=%s\n", ret, new);
	printf("my_error=%s\n", (strerror(errno)));
	printf("rl_error=%s\n", (strerror(errno)));
	close(fd);
	close(fd2);
	return (0);
}