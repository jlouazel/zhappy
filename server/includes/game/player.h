/*
** player.h for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jun 28 16:40:55 2013 louaze_j
<<<<<<< HEAD
** Last update Sun Jul 14 03:02:18 2013 louaze_j
=======
<<<<<<< HEAD
** Last update Sat Jul 13 14:32:35 2013 julien fortin
=======
** Last update Sat Jul 13 13:17:06 2013 louaze_j
>>>>>>> fa0803fdbc5d2dfe3a1bdfa2f0d8230b855f1b46
>>>>>>> 64699f4fcfe819ac00b3ad1811163884b187ac8f
*/

#ifndef __PLAYERS_H__
#define __PLAYERS_H__

#include	<stdbool.h>
#include	"list.h"
#include	"team.h"
#include	"server.h"
#include	"lib_socket.h"
#include	"edirections.h"
#include	"server_data_io.h"

#define	LVL_I(l)	(2 * l + 1)
#define	MY_ABS(x)	((x < 0) ? -x : x)
#define	ABS_X(x, w)	((x < 0) ? (w - MY_ABS(x)) : MY_ABS(x) % w)
#define	ABS_Y(y, h)	((y < 0) ? (h - MY_ABS(y)) : MY_ABS(y) % h)

#define DEFAULT_PID     0
#define DEFAULT_LVL     1
#define DEFAULT_LIFE    10
#define DEFAULT_X       50
#define DEFAULT_Y       50
#define DEFAULT_TIME    100
#define DEFAULT_NB_PL   1

typedef enum { PLAYER_STATUS_ALLOW, PLAYER_STATUS_NOT_ALLOW } t_status;

typedef struct s_team t_team;

typedef struct  s_player
{
  int			x;
  int			y;
  unsigned int		id;
  t_team		*team;
  t_status		status;
  unsigned int		level;
  e_direction		direction;
  unsigned int		inventory_tab[7];

  const t_io		*io;
  const t_socket	*socket;
  char			*packet;

  bool		(*is_allowed)(const struct s_player*);
  void		(*notify)(struct s_player*, const char*);
} t_player;

t_player        *create_player(const t_socket *);
void            delete_player(t_player *, const t_server *);

const char	*_player_advance(t_player*, const t_server*, void*); // OK
const char	*_player_right(t_player*, const t_server*, void*); // OK
const char	*_player_left(t_player*, const t_server*, void*);  // OK
const char	*_player_see(t_player*, const t_server*, void*);  // OK
const char	*_player_inventory(t_player*, const t_server*, void*); // OK
const char	*_player_take(t_player*, const t_server*, void*); // OK
const char	*_player_put(t_player*, const t_server*, void*); // OK
const char	*_player_broadcast(t_player*, const t_server*, void*);
const char	*_player_connect_nbr(t_player*, const t_server*, void*); // OK
const char	*_player_deport(t_player*, const t_server*, void*); // OK
const char	*_player_fork(t_player*, const t_server*, void*); // OK

int             _player_connect_nbr_int(const t_server*, void*);

#endif
