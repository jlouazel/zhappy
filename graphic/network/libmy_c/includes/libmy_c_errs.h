/*
** my_errors.h for errors in /home/fortin_j/tek2/
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr  1 18:53:28 2013 julien fortin
** Last update Tue Apr 23 01:15:25 2013 julien fortin
*/

#ifndef	__MY_ERRORS_H__
#define	__MY_ERRORS_H__

const char      *get_error();

int		my_perror(const char *);
int		my_strerror(const char *);

void		xexit(const char *);

void		*xcalloc(int, int);
void		*xfree(void **);

#endif
