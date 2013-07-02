/*
** libmy_c_std.h for lib in /home/fortin_j/tek2/projects/zappy/fortin_j/core
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr 29 19:20:07 2013 julien fortin
** Last update Sun Jun 30 23:53:27 2013 julien fortin
*/

#ifndef	__LIBMY_C_STD_H__
#define	__LIBMY_C_STD_H__

#include	<stdlib.h>

void            *xcalloc(int, int);
void            *xfree(void **, size_t);

void            *deconst_cast(const void *);
const void      *const_cast(void *);

#endif
