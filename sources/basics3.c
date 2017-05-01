/*
** basics3.c for basics in /home/nicolas94200/PSU_2016_minishell2/sources
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Tue Mar 21 12:16:11 2017 goedert nicolas
** Last update Tue Mar 21 12:16:11 2017 goedert nicolas
*/

#include "minishell2.h"
#include "get_next_line.h"
#include "my_str_to_word_tab.h"

char            *epur_str(char *str)
{
  t_init4       *init4;

  if ((init4 = malloc(sizeof(t_init4))) == NULL)
    return (NULL);
  if ((init4->new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  init4->i = 0;
  init4->j = 0;
  while ((str[init4->i] == 32) || (str[init4->i] == 9))
    init4->i++;
  epur_str2(init4, str);
  init4->new[init4->j] = '\0';
  if (init4->new[init4->i])
    if (init4->new[init4->j] == 32)
      init4->new[init4->j] = '\0';
  return (init4->new);
}
