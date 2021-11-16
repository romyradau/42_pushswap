CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC_FILES = 1_main.c 2_create.c 3_stack.c 4_error.c 5_rank.c 6_small_stack.c 7_presort_algorithm.c 8_algorithm.c 9_algorithm_math.c 10_double_operations.c 10_single_operations.c
BONUS_FILES = bonus.c get_next_line_utils.c get_next_line.c 2_create.c 3_stack.c 4_error.c 5_rank.c 6_small_stack.c 7_presort_algorithm.c 8_algorithm.c 9_algorithm_math.c 10_double_operations.c 10_single_operations.c 
LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(SRC_FILES)
	$(CC) $(FLAGS) $(SRC_FILES) -L. $(LIBFT) -o $(NAME)

$(LIBFT): 
	make -C libft bonus

clean :
	make clean -C libft

fclean : clean
	make fclean -C libft
	rm -f $(NAME)
	rm -f checker

re : fclean all

.PHONY: all clean fclean re

bonus : $(LIBFT)
	$(CC) $(FLAGS) $(BONUS_FILES) -L. $(LIBFT) -o checker

valgrind :
	docker run -ti -v $(PWD):/test memory_leaks:0.1 bash -c "cd /test/; make && valgrind --leak-check=full ./push_swap 5 4 2 ; rm -f ./push_swap"
