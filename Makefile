
all:
	make -C libft/ fclean && make -C libft
	gcc -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	gcc -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	gcc -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

test:
	gcc -o test_gnl -g main.c get_next_line.c -I libft/includes -L libft/ -lft