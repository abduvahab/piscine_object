NAME=train
GCC=c++
CFLAGS= -Wall -Wextra -Werror -std=c++98

SCRS= main.cpp event.cpp parsing.cpp rail.cpp train.cpp node.cpp

OBJS=${SCRS:.cpp=.o}

.cpp.o:
	$(GCC) $(CFLAGS) $< -c -o $@


all:$(NAME)

$(NAME):$(OBJS)
		$(GCC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean:clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean