##
## Makefile for zappy in /home/louaze_j
##
## Made by Jean-Baptiste Louazel
## Login   <louaze_j@epitech.net>
##
## Started on  Wed Jun 19 10:28:03 2013 Jean-Baptiste Louazel
## Last update Wed Jul  3 15:09:04 2013 julien fortin
##

CC			= gcc

RM			= rm -f

CFLAGS			+= -W -Wall -Wextra -Werror
CFLAGS			+= -I ./includes/
CFLAGS			+= -I ./includes/core/
CFLAGS			+= -I ./includes/game/
CFLAGS			+= -I ./includes/lib/
CFLAGS			+= -msse -msse2 -msse3 -mmmx -m3dnow -O3 -fomit-frame-pointer -frerun-loop-opt -fgcse  -g3

LDFLAGS			=

NAME			= zhappy

#
#sources
#
SRCS_DIR		= sources/

INIT_DIR		= init/
DEST_DIR		= destroy/

CORE_DIR		= core/
GAME_DIR		= game/
TEAMS_DIR		= teams/

LIB_DIR			= $(SRCS_DIR)library/
LIST_DIR		= list/
ERR_DIR			= errors/
NTW_DIR			= network/
STD_DIR			= std/
STR_DIR			= strings/
UNIX_DIR		= unix/

SRCS			= $(SRCS_DIR)main.c \
			$(SRCS_DIR)run.c \
			$(SRCS_DIR)server_loop.c \

SRCS_INIT       	= $(SRCS_DIR)$(INIT_DIR)init_server.c \
			$(SRCS_DIR)$(INIT_DIR)init_server_cmd.c \
			$(SRCS_DIR)$(INIT_DIR)init_server_io.c \
			$(SRCS_DIR)$(INIT_DIR)init_server_options.c \
			$(SRCS_DIR)$(INIT_DIR)init_game.c \
			$(SRCS_DIR)$(INIT_DIR)init_world.c \

SRCS_DEST        	= $(SRCS_DIR)$(DEST_DIR)server_destroy.c \
			$(SRCS_DIR)$(DEST_DIR)server_destroy_cmd.c \
			$(SRCS_DIR)$(DEST_DIR)server_destroy_io.c \

#sources/core
CORE_SRCS		= $(SRCS_DIR)$(CORE_DIR)server_accept.c \
			$(SRCS_DIR)$(CORE_DIR)server_listen.c \
                        $(SRCS_DIR)$(CORE_DIR)server_actions.c \
			$(SRCS_DIR)$(CORE_DIR)server_notif_player.c \

#sources/game
GAME_SRCS		= $(SRCS_DIR)$(GAME_DIR)team.c \
			$(SRCS_DIR)$(GAME_DIR)square.c \
			$(SRCS_DIR)$(GAME_DIR)player.c \
			$(SRCS_DIR)$(GAME_DIR)ressources.c \
			$(SRCS_DIR)$(GAME_DIR)player_avance.c \
			$(SRCS_DIR)$(GAME_DIR)player_droite.c \
			$(SRCS_DIR)$(GAME_DIR)player_gauche.c \
			$(SRCS_DIR)$(GAME_DIR)player_voir.c \
			$(SRCS_DIR)$(GAME_DIR)player_inventaire.c \
			$(SRCS_DIR)$(GAME_DIR)player_prend.c \


#
#library
#

LIB_SRCS		= $(LIB_DIR)$(LIST_DIR)list.c \
			$(LIB_DIR)$(LIST_DIR)list_push.c \
			$(LIB_DIR)$(LIST_DIR)list_pop.c \
			$(LIB_DIR)$(LIST_DIR)list_foreach.c \

LIB_SRCS		+= $(LIB_DIR)$(ERR_DIR)errors.c \

LIB_SRCS		+= $(LIB_DIR)$(NTW_DIR)my_socket.c \
			$(LIB_DIR)$(NTW_DIR)my_socket_client.c \
			$(LIB_DIR)$(NTW_DIR)my_socket_server.c \
			$(LIB_DIR)$(NTW_DIR)my_socket_func.c \

LIB_SRCS		+= $(LIB_DIR)$(STD_DIR)alloc.c \
			$(LIB_DIR)$(STD_DIR)const.c \

LIB_SRCS		+= $(LIB_DIR)$(UNIX_DIR)dup.c \
			$(LIB_DIR)$(UNIX_DIR)time.c \
			$(LIB_DIR)$(UNIX_DIR)file.c \

LIB_SRCS		+= $(LIB_DIR)$(STR_DIR)find.c \
			$(LIB_DIR)$(STR_DIR)cmp.c \
			$(LIB_DIR)$(STR_DIR)concat.c \
			$(LIB_DIR)$(STR_DIR)string_dup.c \
			$(LIB_DIR)$(STR_DIR)string_len.c \

OBJS			= $(SRCS:.c=.o) \
			$(SRCS_INIT:.c=.o) \
			$(SRCS_DEST:.c=.o) \
			$(CORE_SRCS:.c=.o) \
			$(GAME_SRCS:.c=.o) \
			$(TEAMS_SRCS:.c=.o) \
			$(LIB_SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean
