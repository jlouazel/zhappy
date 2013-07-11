##
## Makefile for libmy in /home/fortin_j/libmy
##
## Made by julien fortin
## Login   <fortin_j@epitech.net>
##
## Started on  Wed Apr  3 13:28:29 2013 julien fortin
## Last update Sat Apr 27 22:06:09 2013 louaze_j
##

NAME	= libmy_c_$(HOSTTYPE).so
LINK	= libmy_c.so

CC	= gcc -g3
RM	= rm -f
LN	= ln -s

DIR	= ./sources

SRCS	= $(DIR)/my_time.c \
	$(DIR)/my_file.c \
	$(DIR)/unix/pipe.c \
	$(DIR)/unix/select.c \
	$(DIR)/unix/dup.c \
	$(DIR)/unix/fork.c \
	$(DIR)/strings/find.c \
	$(DIR)/strings/cmp.c \
	$(DIR)/strings/concat.c \
	$(DIR)/strings/string_dup.c \
	$(DIR)/strings/string_len.c \
	$(DIR)/errors/my_errors.c \
	$(DIR)/errors/my_free.c \
	$(DIR)/network/my_socket.c \
	$(DIR)/network/my_socket_client.c \
	$(DIR)/network/my_socket_server.c \
	$(DIR)/network/my_socket_func.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS  = -I./includes/ -I./includes/internal/
CFLAGS  += -fPIC
CFLAGS  += -Wall

LFLAGS  = -shared

.PHONY		: all clean fclean re
.SUFFIXES	: .c .o

$(LINK):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)
		$(RM) $(LINK)
		$(LN) $(NAME) $(LINK)
		@echo -e "\E[33;32mDONE\E[00;00m"
		@echo -n "export LD_LIBRARY_PATH="
		@echo `pwd` | tr ' ' '/'
		@echo -n "setenv LD_LIBRARY_PATH "
		@echo `pwd` | tr ' ' '/'

.c.o:
		$(CC) $(CFLAGS) -c $*.c -o $*.o

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LINK)

re: fclean all

all: $(LINK)
