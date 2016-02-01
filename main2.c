//#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd = 0;
	char *str;

	if ((get_next_line(fd, &str)))
		ft_putendl(str);
	return (0);
}
