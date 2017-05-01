/*
** basics.c for basics in /home/nicolas94200/PSU_2016_minishell2/sources
**
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
**
** Started on  Tue Mar 21 12:20:05 2017 goedert nicolas
** Last update Tue Mar 21 12:20:05 2017 goedert nicolas
*/

#include "minishell2.h"
#include "get_next_line.h"
#include "my_str_to_word_tab.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char		*my_strcat(char *dest, char *src)
{
  int		x;
  int		y;
  char		*str;

  x = 0;
  y = 0;
  if ((str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2)))
      == NULL)
    return (NULL);
  while (dest[x])
    {
      str[x] = dest[x];
      x++;
    }
  while (src[y] != '\n' && src[y])
    {
      str[x] = src[y];
      x++;
      y++;
    }
  str[x] = '\0';
  return (str);
}
