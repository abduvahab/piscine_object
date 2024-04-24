NAME=bank
GCC = g++
CFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS= main.cpp Bank.cpp
OBJS=$(SRCS:.cpp=.o)# there is no space between ":"and ".cpp"

all:$(NAME)

$(NAME):$(OBJS)
	$(GCC) $(CFLAGS) $^ -o $@

.cpp.o:
		$(GCC) $(CFLAGS)  -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: clean fclean all

.PHONY: clean fclean re all 


