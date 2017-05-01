/*
** my_str_to_word_tab.c for wordtab in /home/nicolas94200/PSU_2016_minishell2/sources
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Tue Mar 21 12:21:47 2017 goedert nicolas
** Last update Tue Mar 21 12:21:47 2017 goedert nicolas
*/

#include "my_str_to_word_tab.h"
#include "minishell2.h"

int		characters(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 48 && str[i] <= 122)
        j++;
      i++;
      if (str[i] >= 97 && str[i] <= 57)
        j++;
      i++;
    }
  return (j);
}

int		distance(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if ((str[i] == ':') || (str[i] == ' '))
	j++;
      i++;
    }
  return (j + 1);
}

void		var(t_init *init)
{
  init->i = 0;
  init->j = 0;
  init->k = 0;
}

char		**my_str_to_word_tab(char *str, char **tab)
{
  t_init	*init;

  if ((init = malloc(sizeof(t_init))) == NULL)
    return (NULL);
  var(init);
  if ((tab = malloc(sizeof(char *) * (distance(str) + 1))) == NULL)
    return (NULL);
  while (str[init->i] != '\0')
    {
      if ((tab[init->j] = malloc(sizeof(char) * (characters(str) + 1))) == NULL)
	return (NULL);
      while ((str[init->i] != '\0') && (str[init->i] != ' ') &&
	     (str[init->i] != ':'))
	{
	  tab[init->j][init->k++] = str[init->i];
	  init->i++;
	}
      if (str[init->i] == ':' || str[init->i] == ' ')
	init->i++;
      tab[init->j][init->k] = '\0';
      init->k = 0;
      init->j++;
    }
  tab[init->j] = NULL;
  return (tab);
}

void		show_to_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != '\0')
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}
