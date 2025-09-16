NAME = warlock
CC = c++
FLAGS = -Werror -Wall -Wextra -std=c++98 -MMD
SRCS = main.cpp Warlock.cpp ASpell.cpp Fwoosh.cpp ATarget.cpp Dummy.cpp
OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@

$(OBJS_DIR)/%.o: %.cpp Makefile
	mkdir -p $(OBJS_DIR)
	$(CC) -c $< -o $@ $(FLAGS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re

