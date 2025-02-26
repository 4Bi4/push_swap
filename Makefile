CC			=	cc -I$(INCLUDE) -g3 # -Wall -Wextra -Werror -fsanitize=address 

NAME		=	push_swap
INCLUDE		=	include
SRCDIR		=	src/
OBJDIR		=	objs/
SRCS		=	$(SRCDIR)push_swap.c $(SRCDIR)utils_args.c $(SRCDIR)ft_split.c
OBJS		=	$(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

LIBFT		=	libft/

AR			=	ar rcs
RM			=	rm -f

BAR_STYLE	=	"###                "
BAR_SIZE	=	18

TOTAL_FILES	=	$(words $(SRCS))
CURRENT		=	0

all:		$(NAME)

#libft:		make -C $(LIBFT)

$(NAME):    $(OBJS)
			@echo "Creating objects... 🔨🪛"
			@make -C $(LIBFT) -s
			@$(CC) $(OBJS) -o $(NAME)
			@echo "Cooking up the program... 🍲🍳"
			@echo "✅ Done ✅"

$(OBJDIR)%.o: $(SRCDIR)%.c
			@mkdir -p $(OBJDIR)
			@$(CC) -c $< -o $@
			@$(call prog_bar)

prog_bar:
			@if [ -f $(PROG_BAR_FILE) ]; then CURRENT=$$(cat $(PROG_BAR_FILE)); else CURRENT=0; fi
			@$(eval CURRENT=$(shell echo $$(($(CURRENT)+1))))
			@echo $$(CURRENT) > $(PROG_BAR_FILE)
			@$(eval PERCENTAGE=$(shell echo $$(($(CURRENT)*100/$(TOTAL_FILES)))))
			@$(eval BAR_SIZE=$(shell echo $$(($(PERCENTAGE)*20/100))))
			@$(eval BAR_STYLE=$(shell printf "%-${BAR_SIZE}s" "#" | tr ' ' '#'))
			@echo -n "\r[$(BAR_STYLE)] $(PERCENTAGE)%%"
			@sleep 0.1

clean:
			@$(RM) $(OBJS)
			@rm -rf $(OBJDIR)
			@make -C $(LIBFT) clean -s
			@echo "Cleaning up... 🧹💨"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(EXEC)

re:			fclean all

.PHONY:        all lib clean fclean re bonus