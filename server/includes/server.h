/*
** server.h for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sun Jul 14 21:48:55 2013 louaze_j
** Last update Sun Jul 14 21:49:16 2013 louaze_j
*/

#ifndef	__SERVERZAPPY_H__
#define	__SERVERZAPPY_H__

#define	ENTRY_PORT	6969
#define	MAX_FAIL_SELECT 42

#include	<stdbool.h>
#include	"server_data.h"

const t_server	*server_init(t_server*, int, const char**);
const t_server  *destroy_server(t_server*);

const t_cmd_graph	*init_server_cmd_graph();

const t_cmd_player	*init_server_cmd_player();
const t_cmd_player	*destroy_server_cmd_player(const t_cmd_player*);

const t_io      *init_server_io();
const t_io      *destroy_server_io(const t_io*);

const t_options	*init_server_options(int, const char**);
const t_options	*destroy_server_options(const t_options*);

const t_game    *init_game(const t_options*);

t_list		*server_extract_player_packet(t_player*);
t_list		*server_extract_graph_packet(const t_server*, t_graphical*);

t_player        *get_player_for_id(const t_server *, int);

bool		notify_graph(const t_server *, const char *);

int		server_loop(const t_server*);
int		run(const t_server*);

bool		server_graph_actions(const t_server*, fd_set*);

bool		server_exec_actions(const t_server*);

bool		server_disconnect_player(t_player*);
bool		server_disconnect_graph(const t_server*, t_graphical*);

bool		server_kick_player(const t_server*, t_player*);
bool            server_players_actions(const t_server*, fd_set*);

bool		server_listen_connection_queue(const t_server*, fd_set*);
bool            server_listen_player(const t_server *, fd_set *, int*);
bool            server_listen_graph(const t_server *, fd_set *, int*);

bool            server_will_notify_player(const t_server *, fd_set *, int*);
bool            server_will_notify_graph(const t_server *, fd_set *, int*);

bool		server_notify_player(const t_server *, fd_set*);
bool		server_notify_graph(const t_server *, fd_set*);

bool            server_get_auth_from_player(const t_server *, t_player *,
					    const char *, fd_set*);

void		server_accept(const t_server*, const fd_set*);

#endif
