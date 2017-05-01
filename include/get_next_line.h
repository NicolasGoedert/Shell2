/*
** get_next_line.h for gnl in /home/nicolas94200/PSU/PSU_2016_minishell2/include
**
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
**
** Started on  Wed Mar 22 12:36:51 2017 goedert nicolas
** Last update Wed Mar 22 12:36:51 2017 goedert nicolas
*/

#ifndef READ_SIZE
# define READ_SIZE (1)
#endif /* !READ_SIZE */

# ifndef GET_NEXT_LINE_H_
#  define GET_NEXT_LINE_H_

typedef struct	s_struct
{
  char		*result;
  char		*buffer;
  int		count;
  int		i;
}		t_struct;

char		*my_strcat(char *dest, char *src);
int		check(char *buffer);
int		alloc_mem(char **buffer, char **save, char **result);
char		*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
