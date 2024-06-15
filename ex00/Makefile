NAME = btc
CC = c++
CFLAGS = -g -Wall -Werror -Wextra -std=c++98
SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
