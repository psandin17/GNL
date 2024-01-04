
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		check_line_end(char *buffer);
int		ft_strlen(char *str);
char	*get_line(char *line, char *buffer);
void	ft_clean_buff(char *buffer);

#endif
