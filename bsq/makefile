_OBJ := checkfile.o display.o filetosrcs.o findsq.o main.o split.o tools.o tools2.o topleft.o
OBJ := $(patsubst %,srcs/%,$(_OBJ))
NAME := bsq

all: $(NAME)


srcs/%.o: srcs/%.c includes/bsq.h
	gcc -Wall -Wextra -Werror -c -o $@ $< -I./includes


$(NAME) : $(OBJ)
	gcc  -Wall -Wextra -Werror -o $@ $^


clean:
	rm -f $(OBJ)


fclean:
	rm -f $(OBJ) $(NAME)


re: fclean all