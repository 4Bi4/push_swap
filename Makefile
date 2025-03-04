CC			=	cc -I$(INCLUDE) -g3 -Wall -Wextra -Werror -fsanitize=address 

NAME		=	push_swap
INCLUDE		=	include
SRCDIR		=	src/
OBJDIR		=	objs/
SRCS		=	$(SRCDIR)push_swap.c $(SRCDIR)utils_args.c $(SRCDIR)utils_aux.c $(SRCDIR)moves.c
OBJS		=	$(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

LIBFT		=	src/libft/
LIBFT_A		=	$(LIBFT)libft.a

AR			=	ar rcs
RM			=	rm -f

all:		$(NAME)

$(NAME):    $(OBJS)
				@( \
					i=1; \
					while :; do \
						case $$i in \
							1) dots="." ;; \
							2) dots=".." ;; \
							3) dots="..."; i=0 ;; \
						esac; \
						printf "Creating libft%s\r" "$$dots"; \
						sleep 0.3; \
						i=$$((i + 1)); \
					done & \
					ANIM_PID=$$!; \
					make -C $(LIBFT) -s; \
					kill $$ANIM_PID; \
					printf "\n"; \
				)
				@echo "Creating objects 🔨🪛"
				@$(CC) $(OBJS) $(LIBFT_A) -o $(NAME)
				@echo "Cooking up the program 🍲🍳"
				@echo "✅ Done ✅"
				@$(RM) 

$(OBJDIR)%.o: $(SRCDIR)%.c
				@mkdir -p $(OBJDIR)
				@$(CC) -c $< -o $@

clean:
				@$(RM) $(OBJS)
				@rm -rf $(OBJDIR)
				@make -C $(LIBFT) clean -s
				@echo "Cleaning up... 🧹💨"

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(EXEC)
				@$(RM) $(PROG_BAR_FILE)

re:				fclean all

.PHONY:       	all lib clean fclean re bonus