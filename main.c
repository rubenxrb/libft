#include "core.h"
#include <stdio.h>

int main()
{
	char *ptr = ft_strdup("this be a dup string");
	ft_putendl(ptr);
	ft_strdel(&ptr);
	ptr = ft_strdup("this be another str");
	printf("size of ptr '%zu'\n", ft_strlen(ptr));
	ft_putendl("cleaning string ptr");
	ft_bzero(ptr, ft_strlen(ptr));
	printf("size of ptr '%zu'\n", ft_strlen(ptr));
	ft_strdel(&ptr);
}
