#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <libft.h>

typedef struct		s_line
{
	unsigned char	header[4];
	unsigned char	name[132];
	unsigned char	size[4];
	unsigned char	sent[2048];
	unsigned char	champ[100];
}					t_line;

int		print_error(int i, char *file)
{
	if (i == 0)
	{
		write(1, "Can't read source file ", 23);
		write(1, file, ft_strlen(file));
		write(1, "\n", 1);
	}
	else
	{
		write(1, "Error: File ", 12);
		write(1, file, ft_strlen(file));
		if (i == 1)
			write(1, " is too small to be a champion\n", 31);
		else if (i == 2)
			write(1, " has an invalid header\n", 23);
		else if (i == 3)
			write(1, " has a code size that differ from what its header says\n"
				, 55);
		else if (i == 4)
			write(1, " has too large a code (993 bytes > 682 bytes)\n", 46);
	}
	return (0);
}

int		verif_header(unsigned char *header)
{
	if ((header[0] != 0) || (header[1] != 234) || (header[2] != 131)
		|| (header[3] != 243))
		return (0);
	return (1);
}

int		verif_size(unsigned char *size, unsigned long count)
{
	unsigned long	i;

	i = size[3] + size[2] * 256 + size[1] * 65536 + size[0] * 16777216;
	if (count != i)
		return (0);
	return (1);
}

int		verif(char *file, t_line line, unsigned long count)
{
	if (!(verif_header(line.header)))
		return (print_error(2, file));
	if (!(verif_size(line.size, count)))
		return (print_error(3, file));
	if (count > 682)
		return (print_error(4, file));
	return (1);
}

int		read_champ(int fd, char *file)
{
	t_line			line;
	int				ret;
	unsigned long	count;

	if (read(fd, line.header, 4) < 4)
		return (print_error(1, file));
	if (read(fd, line.name, 132) < 132)
		return (print_error(1, file));
	if (read(fd, line.size, 4) < 4)
		return (print_error(1, file));
	if (read(fd, line.sent, 2052) < 2052)
		return (print_error(1, file));
	count = 0;
	while ((ret = read(fd, line.champ, 100)) > 0)
		count += ret;
	if (!(verif(file, line, count)))
		return (0);
	return (1);
}

int		parsing_champ(char *file)
{
	int fd;
	int ret;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error(0, file);
		return (0);
	}
	else
	{
		ret = read_champ(fd, file);
		close(fd);
		if (!ret)
			return (0);
	}
	return (1);
}
