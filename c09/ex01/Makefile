SRC = srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o srcs/ft_swap.o

all: libft.a

%.o : %.c
	gcc -Wall -Wextra -Werror -c -o $@ $< -I./includes

libft.a: ${SRC}
	ar -rcs libft.a ${SRC}

clean:
	rm -f ${SRC}

fclean: clean
	rm -f libft.a

re: fclean all
