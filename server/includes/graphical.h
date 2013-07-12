/*
** graphical.h for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Mon Jul  8 15:12:10 2013 louaze_j
** Last update Fri Jul 12 15:11:38 2013 louaze_j
*/

#ifndef		__GRAPHICAL_H__
#define		__GRAPHICAL_H__

#include	"server.h"
#include	"lib_socket.h"

typedef struct	s_graphical
{
  const t_io		*io;
  const t_socket	*socket;

  const char	*(*msz)(struct s_graphical *, const t_server *);
  const char	*(*bct)(struct s_graphical *, const t_server *, void *, void *);
  const char	*(*mct)(struct s_graphical *, const t_server *);
  const char	*(*tna)(struct s_graphical *, const t_server *, void *);
  const char	*(*pnw)(struct s_graphical *, const t_server *, void *);
  const char	*(*ppo)(struct s_graphical *, const t_server *, void *);
  const char	*(*plv)(struct s_graphical *, const t_server *, void *);
  const char	*(*pin)(struct s_graphical *, const t_server *, void *);
  const char	*(*pex)(struct s_graphical *, const t_server *); // NOK
  const char	*(*pbc)(struct s_graphical *, const t_server *); // NOK
  const char	*(*pic)(struct s_graphical *, const t_server *); // NOK
  const char	*(*pie)(struct s_graphical *, const t_server *); // NOK
  const char	*(*pfk)(struct s_graphical *, const t_server *); // NOK
  const char	*(*pdr)(struct s_graphical *, const t_server *); // NOK
  const char	*(*pgt)(struct s_graphical *, const t_server *); // NOK
  const char	*(*pdi)(struct s_graphical *, const t_server *); // NOK
  const char	*(*enw)(struct s_graphical *, const t_server *); // NOK
  const char	*(*eht)(struct s_graphical *, const t_server *); // NOK
  const char	*(*ebo)(struct s_graphical *, const t_server *); // NOK
  const char	*(*edi)(struct s_graphical *, const t_server *); // NOK
  const char	*(*sgt)(struct s_graphical *, const t_server *); // NOK
  const char	*(*sst)(struct s_graphical *, const t_server *); // NOK
  const char	*(*seg)(struct s_graphical *, const t_server *); // NOK
  const char	*(*smg)(struct s_graphical *, const t_server *); // NOK
  const char	*(*suc)(struct s_graphical *, const t_server *); // NOK
  const char	*(*sbp)(struct s_graphical *, const t_server *); // NOK
} t_graphical;

t_graphical	*new_graphical_client(const t_socket *);

void		_msz(t_graphical *);
void		_bct(t_graphical *);
void		_mct(t_graphical *);
void		_tna(t_graphical *);
void		_pnw(t_graphical *);
void		_ppo(t_graphical *);
void		_plv(t_graphical *);
void		_pin(t_graphical *);
/* void		_pex(t_graphical *);  */
/* void		_pbc(t_graphical *);  */
/* void		_pic(t_graphical *);  */
/* void		_pie(t_graphical *);  */
/* void		_pfk(t_graphical *);  */
/* void		_pdr(t_graphical *);  */
/* void		_pgt(t_graphical *);  */
/* void		_pdi(t_graphical *);  */
/* void		_enw(t_graphical *);  */
/* void		_eht(t_graphical *);  */
/* void		_ebo(t_graphical *);  */
/* void		_edi(t_graphical *);  */
/* void		_sgt(t_graphical *);  */
/* void		_sst(t_graphical *);  */
/* void		_seg(t_graphical *);  */
/* void		_smg(t_graphical *);  */
/* void		_suc(t_graphical *);  */
/* void		_sbp(t_graphical *);  */

#endif

