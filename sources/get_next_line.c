/*
** get_next_line.c for GNL in /home/nicolas94200/PSU_2016_minishell2/sources
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Tue Mar 21 12:21:08 2017 goedert nicolas
** Last update Tue Mar 21 12:21:08 2017 goedert nicolas
*/

#include "minishell2.h"
#include "get_next_line.h"

int		check(char *buffer)
{
  int		i;

  i = 0;
  while (buffer[i])
    {
      if (buffer[i] == '\n')
	return (1);
      i = i + 1;
    }
  return (0);
}

int		alloc_mem(char **buffer, char **save, char **result)
{
  if ((*buffer = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (0);
  if ((*result = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (0);
  if (*save == NULL)
    {
      if ((*save = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
	return (0);
    }
  return (1);
}

char		*get_next_line(const int fd)
{
  static char	*save;
  static int	rd;
  t_struct	stc;

  stc.i = 0;
  stc.count = 0;
  if ((alloc_mem(&stc.buffer, &save, &stc.result)) == 0)
    return (NULL);
  stc.result = my_strcat(stc.result, save);
  while (stc.i < READ_SIZE + 1)
    save[stc.i++] = '\0';
  stc.i = 0;
  while (check(stc.buffer) != 1)
    {
      if (((rd = read(fd, stc.buffer, READ_SIZE)) == -1) || rd == 0)
  	return (NULL);
      stc.buffer[rd] = '\0';
      stc.result = my_strcat(stc.result, stc.buffer);
    }
  while (stc.buffer[stc.count] && stc.buffer[stc.count] != '\n')
    stc.count = stc.count + 1;
  stc.count = stc.count + 1;
  while (stc.buffer[stc.count] != '\0')
    save[stc.i++] = stc.buffer[stc.count++];
  return (stc.result);
}
