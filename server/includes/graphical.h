/*
** graphical.h for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Mon Jul  8 15:12:10 2013 louaze_j
** Last update Sun Jul 14 16:14:07 2013 louaze_j
*/

#ifndef		__GRAPHICAL_H__
#define		__GRAPHICAL_H__

#include	"server.h"
#include	"lib_socket.h"
#include	"eressources.h"
#include	"egg.h"

typedef struct	s_graphical
{
  unsigned int		id;
  const t_io		*io;
  const t_socket	*socket;
  char			*packet;

  void          (*notify)(struct s_graphical*, const char*);
} t_graphical;

t_graphical	*new_graphical_client(const t_socket *, unsigned int);

const char	*_graph_msz(t_graphical *, const t_server *, const char *);
const char	*_graph_bct(t_graphical *, const t_server *, const char *);
const char	*_graph_mct(t_graphical *, const t_server *, const char *);
const char	*_graph_tna(t_graphical *, const t_server *, const char *);
const char	*_graph_ppo(t_graphical *, const t_server *, const char *);
const char	*_graph_plv(t_graphical *, const t_server *, const char *);
const char	*_graph_pin(t_graphical *, const t_server *, const char *);
const char	*_graph_sgt(t_graphical *, const t_server *, const char *);
const char	*_graph_sst(t_graphical *, const t_server *, const char *);


const char	*msz(const t_server *); // OK
const char	*bct(const t_server *, int, int); // OK
const char	*mct(t_graphical *, const t_server *); // OK
const char	*tna(t_graphical *, const t_server *); // OK
const char	*ppo(const t_server *, int); // OK
const char	*plv(t_player *); // OK
const char	*pin(t_player *); // OK
const char	*pex(t_player *); // OK
const char	*pbc(t_player *); // OK
const char	*pic(t_player *, const t_server *); // OK
const char	*pie(t_player *); // OK
const char	*pfk(t_player *); // OK
const char	*pdr(t_player *, e_ressource); // OK
const char	*pgt(t_player *); // OK
const char	*pdi(t_player *); // OK
const char	*enw(t_player *, t_egg *); // OK
const char	*eht(t_egg *); // OK
const char	*ebo(t_egg *); // OK
const char	*edi(t_egg *); // OK
const char	*sgt(const t_server *); // OK
const char	*sst(const t_server *); // OK
const char	*seg(const char *); // OK
/* const char	*smg(t_graphical *, const t_server *); // NOK */
/* const char	*suc(t_graphical *, const t_server *); // NOK */
/* const char	*sbp(t_graphical *, const t_server *); // NOK */
/* const char	*pnw(t_player *); */

void		_welcome(t_graphical *, const t_server *);

#endif
