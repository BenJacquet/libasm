#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_write(int fildes, const void *buff, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);
char	*ft_malloc(const char *s1);

int		main(int ac, char **av)
{
	char	new[4096 + 1];
	int		ret = 0;
	int		fd = open(av[1], O_RDONLY);
	int		fd2 = open(av[1], O_RDONLY);

	int test_write = (0x2000003);
	int test_write_2 = ((2 << 24) | 3);
	int test_read = (0x2000000);
	if (ac >= 2)
	{
/*		char copy[ft_strlen(av[1])];
		char copy2[ft_strlen(av[1])];
		printf("av[1]_len=%d(vrai=%lu)\n", ft_strlen(av[1]), strlen(av[1]));
		printf("cmp_return=%d(vrai=%d)\n", ft_strcmp(av[1], av[2]), strcmp(av[1], av[2]));
		printf("av[1]_cpy=%s(vrai=%s)\n", ft_strcpy(copy, av[1]), strcpy(copy2, av[1]));
		printf("WRITE TEST-----\n");
		printf("(%d)", ft_write(1, av[1], ft_strlen(av[1])));*/
/*		printf("READ TEST-----\n");
		ret = ft_read(fd, new, 4096);
		new[ret] = '\0';
		printf("ft=(%d)| buffer=%s\n-----------------\n", ret, new);
		ret = read(fd2, new, 4096);
		new[ret] = '\0';
		printf("rl=(%d)| buffer=%s\n", ret, new);*/
/*		printf("rl_av[1]_dup=%s\n", strdup(av[1]));
		printf("ft_av[1]_dup=%s\n", ft_strdup(av[1]));*/
		char *new2 = ft_malloc(av[1]);
		new2[0] = 'a';
		new2[1] = '\0';
		printf("new2=%s\n", new2);
		//printf("ft_strdup:%s\n", ft_strdup(av[1]));
	}
	close(fd);
	close(fd2);
	return (0);
}