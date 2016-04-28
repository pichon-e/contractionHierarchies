##
 ## Makefile
 ##
 ## Made by Astek
 ## Login <astek@epitech.eu>
 ##
 ## Started on Fri Jan 28 11:52:30 2011 Astek
 ## Last update Wed Nov 27 17:09:04 2013 felix pescarmona
 ##

CC = g++

RM = rm -f

CFLAGS += -Wextra -Wall -Werror
#CFLAGS += -ansi -pedantic
CFLAGS += -I.

LDFLAGS =

NAME = server

SRCS = 	main.cpp \
 		test.cpp

OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re