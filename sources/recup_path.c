/*
** recup_path.c for path in /home/nicolas94200/PSU_2016_minishell2/sources
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Tue Mar 21 12:23:56 2017 goedert nicolas
** Last update Tue Mar 21 12:23:56 2017 goedert nicolas
*/

#include "minishell2.h"
#include "my_str_to_word_tab.h"
#include "get_next_line.h"

char		*recup(char **env)
{
  char		*elem;
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (env[x] != NULL)
    {
      if (env[x][y] == 'P' && env[x][y + 1] == 'A' &&
	  env[x][y + 2] == 'T' && env [x][y + 3] == 'H')
	{
	  if ((elem = malloc(sizeof(char) * my_strlen(env[x]))) == NULL)
	    return (NULL);
	  elem = my_strcpy(elem, env[x]);
	}
      x++;
    }
  return (elem);
}
