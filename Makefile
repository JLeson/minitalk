NAMECLIENT				=	client
NAMESERVER				=	server

LIBFTDIR				=	./libft/
SRCDIR					=	./src/
LIBDIR					=	./lib/
INCLUDEDIR				=	./include/

LIBFTNAME				=	libft.a
CLIENTSRCFILE			=	client.c
SERVERSRCFILE			=	server.c

SRCS					=	$(addprefix $(SRCDIR), $(SRCFILES))

CC						=	gcc
CFLAGS					=	-Wall -Wextra -Werror
RM						=	rm -f

all:					$(NAMECLIENT) $(NAMESERVER)

$(NAMECLIENT):			$(LIBDIR)$(LIBFTNAME) $(SRCDIR)$(CLIENTSRCFILE)
							$(CC) $(CFLAGS) $(SRCDIR)$(CLIENTSRCFILE) $(LIBDIR)$(LIBFTNAME) -I $(INCLUDEDIR) -o $(NAMECLIENT)

$(NAMESERVER):			$(LIBDIR)$(LIBFTNAME) $(SRCDIR)$(SERVERSRCFILE)
							$(CC) $(CFLAGS) $(SRCDIR)$(SERVERSRCFILE) $(LIBDIR)$(LIBFTNAME) -I $(INCLUDEDIR) -o $(NAMESERVER)

$(LIBDIR)$(LIBFTNAME):
							$(MAKE) -C $(LIBFTDIR)

clean:
							$(RM) $(NAMECLIENT)
							$(RM) $(NAMESERVER)

fclean:					clean
						$(MAKE) fclean -C $(LIBFTDIR)

re:						fclean all

.PHONY:					all clean fclean re

