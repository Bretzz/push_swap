# define standard colors
BOLD 		:= \033[1m
YELLOW		:= \033[1;33m
LIGHT_RED 	:= \033[91m
LIGHT_GREEN := \033[92m
LIGHT_CYAN 	:= \033[96m
RESET 		:= \033[0m

DIR := $(shell pwd)
NAME := push_swap
CC := cc
CFLAGS := -Wall -Wextra -Werror

#source files (full path optional)
SRCS := main.c \
		pa.c pb.c ra.c rb.c rr.c \
		rra.c rrb.c rrr.c sa.c sb.c ss.c \
		list_utils.c more_list_utils.c checkers.c \
		algoritm.c best_rotator.c best_helpers.c handle_a.c mini_algo.c

#archive file names
ARS	:= libft/libft.a

#folders containing source files [*.c] 
VPATH = operations debugs_and_utils algoritm

EXE = nyaa
LIBFT_DIR := libft
OBJ_DIR := $(DIR)/obj
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
GIDEF =	"""$\
		\#default rules\n$\
		.gitignore\n$\
		.git\n$\
		.vscode\n$\
		**/temp\n$\
		**/obj\n$\
		**/resources\n$\
		**/a.out\n$\
		**/*.a\n$\
		**/tester.c\n$\
		\n$\
		\#added rules\n$\
		"""

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(DIR) -c $< -o $(OBJ_DIR)/$(notdir $@)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT_DIR):
	@echo "${BOLD}creating libft...${RESET}"
	@$(MAKE) -C $(LIBFT_DIR) | grep -q "Nothing to be done for" \
	&& echo "${YELLOW}libft is up to date.${RESET}" \
	|| true

$(NAME): $(LIBFT_DIR) $(OBJS)
	@echo "${BOLD}compiling $(NAME)...${RESET}"
	@echo "$(shell stat -c %Z $(OBJ_DIR)/*)" | grep -q "$(shell date +%s)" \
	&& ($(CC) $(CFLAGS) $(OBJ_DIR)/* $(ARS) -o $(NAME) \
	&& echo "${LIGHT_GREEN}DONE${RESET}") \
	|| echo "${YELLOW}$(NAME) is up to date.${RESET}"

$(EXE):
	@echo "${BOLD}compiling tester...${RESET}"
	@$(CC) main.c $(ARS) -I$(LIBFT_DIR) -o $(EXE)
	@echo "${LIGHT_GREEN}DONE${RESET}"

.gitignore:
	@touch .gitignore
	@cat .gitignore | grep -q "#default rules" || \
		echo $(GIDEF)"$$(cat .gitignore)" > .gitignore

show:
	@printf "NAME  		: $(NAME)\n"
	@printf "LIBFT		: $(DIR)/$(LIBFT_DIR)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "SRCS		:\n	$(SRCS)\n"
	@printf "OBJS		:\n	$(OBJS)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR) --quiet

fclean: clean
	@rm -f $(NAME) $(EXE)
	@$(MAKE) fclean -C $(LIBFT_DIR) --quiet

re: fclean all

.PHONY: all clean fclean re nyaa $(LIBFT_DIR) .gitignore show
