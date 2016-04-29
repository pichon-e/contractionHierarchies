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

#CFLAGS += -ansi -pedantic
CXXFLAGS = -std=c++11

NAME = server

SRCS = 	dijkstra.cc \
 		graph.cc \
 		dijkstra_test.cc

OBJS = $(SRCS:.cc=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re