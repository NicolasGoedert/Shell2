/*
** basics2.c for basics in /home/nicolas94200/PSU_2016_minishell2/sources
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Tue Mar 21 12:20:20 2017 goedert nicolas
** Last update Tue Mar 21 12:20:20 2017 goedert nicolas
*/

#include "minishell2.h"
#include "get_next_line.h"
#include "my_str_to_word_tab.h"

void		my_perror(char *str)
{
  my_putstr(str);
  exit(1);
}

char		*my_strstr(char *str, char *to_find)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == to_find[j])
	{
	  j++;
	}
      else
	j = 0;
      if (to_find[j] != '\0')
	{
	  j--;
	  i = i - j;
	  return (str + i);
	}
      i++;
    }
  return (NULL);
}

void	my_strncmp1(t_init1 *init1, char *s1, char *s2)
{
  init1->i = 0;
  init1->size1 = my_strlen(s1);
  init1->size2 = my_strlen(s2);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  t_init1	*init1;

  if ((init1 = malloc(sizeof(t_init1))) == NULL)
    return (0);
  my_strncmp1(init1, s1, s2);
  while ((init1->i <= init1->size1) || (init1->i <= init1->size2))
    {
      if (init1->i < n)
	{
	  if (s2[init1->i] == s1[init1->i])
	    init1->i++;
	  else
	    return (s1[init1->i] - s2[init1->i]);
	}
      else
	return (0);
    }
  return (0);
}

int		epur_str2(t_init4 *init4, char *str)
{
  while (str[init4->i])
    {
      if ((str[init4->i] == 32) || (str[init4->i] == 9))
      	{
      	  init4->new[init4->j] = 32;
      	  init4->j++;
      	  while ((str[init4->i] == 32) || (str[init4->i] == 9))
      	    init4->i++;
      	}
      init4->new[init4->j] = str[init4->i];
      init4->j++;
      init4->i++;
    }
  return (0);
}
