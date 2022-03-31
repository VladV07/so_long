#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h> // ???
# include <stdio.h> // убрать 
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"

char	*get_next_line(int fd);

#endif