/*
** my_time.c for myscript in /home/fortin_j/tek2/projects/my_script/myscript-2015s-2016-2017si-fortin_j
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sat Mar  2 23:30:55 2013 julien fortin
** Last update Wed Jun 19 15:45:52 2013 julien fortin
*/

#include	<stdlib.h>
#include	<time.h>
#include	"lib_errs.h"

const char		*get_current_time(void)
{
  char		*str;
  time_t        t;

  str = NULL;
  if ((time(&t)) == (time_t)-1)
    {
      my_perror("time");
      return (NULL);
    }
  if (!(str = ctime(&t)))
    {
      my_perror("ctime");
      return (NULL);
    }
  return (str);
}
