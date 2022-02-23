
NAME = api
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FILES = mjson.c \
		main.c \
		get_Token.c \
		write_Callback.c \
		get_Data.c \
		parsing_Data.c \
		42labs_Populate.c \

INCLUDE = ft_api.h

RM = rm -f
OBJS = $(FILES:.c=.o)


all:	$(NAME) $(INCLUDE)

$(NAME):	$(OBJS)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -lcurl -ljson-c -lmysqlclient

clean:
		$(RM) $(OBJS)

fclean:
		${RM} ${NAME} ${OBJS}

re:		fclean all


.PHONY: clean fclean all re
