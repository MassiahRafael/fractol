INC=/usr/include


INCLIB=$(INC)/../lib

CFLAGS= -I$(INC) -O3 -I.. -g

NAME= fractol
SRC = main.c
OBJ = $(SRC:%.c=%.o)
CC  = gcc

LFLAGS = -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	rm -f $(NAME) $(OBJ)

re: clean all
