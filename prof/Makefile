CC = g++

RM = rm -f

CFLAGS += -Wextra -Wall -Werror 
#CFLAGS += -ansi -pedantic
CFLAGS += -I. -std=c++11

LDFLAGS =

NAME = graph_test

$(NAME):
	g++ -std=c++11 graph.cc graph_test.cc

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
