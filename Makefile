NAME = fractol
SRC = main utils/init hooks/keys utils/zoom sets/mandelbrot/index utils/color hooks/scroll sets/mandelbrot/utils utils/render sets/julia/index sets/julia/utils utils/error
SRCS = $(addsuffix .c, $(addprefix src/, $(SRC)))
OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))
MLX = MLX42/build/libmlx42.a
LIBFT = libft/libft.a

CODAM_FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LIBS = MLX42/build/libmlx42.a libft/libft.a
INCLUDES = -I $(CURDIR)/incl -I MLX42/include -I $(CURDIR)/libft

ifeq ($(shell uname -m),arm64)
LINKERS = -L/opt/homebrew/lib -lglfw -framework IOKit -framework Cocoa
else ifeq ($(shell uname -m),x86_64)
LINKERS = -lglfw3 -framework IOKit -framework Cocoa
endif


COLOR_INFO = \033[1;36m
COLOR_SUCCESS = \033[1;32m
COLOR_RESET = \033[0m

EMOJI_INFO = 🌈
EMOJI_SUCCESS = 🎉
EMOJI_CLEAN = 🧹
EMOJI_RUN = 🚀

all: create_folders $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@echo "$(COLOR_INFO)$(EMOJI_INFO)  Compiling $(NAME)...$(COLOR_RESET)"
	@cc $(OBJS) $(LIBS) $(INCLUDES) $(LINKERS) $(CODAM_FLAGS) -o $(NAME)
	@echo "$(COLOR_SUCCESS)$(EMOJI_SUCCESS)  Compilation completed!$(COLOR_RESET)"

build/%.o: src/%.c incl/fractol.h
	@tput reset
	@mkdir -p $(@D)
	@gcc $(INCLUDES) $(CODAM_FLAGS) -c $< -o $@

$(MLX):
	@echo "$(COLOR_INFO)$(EMOJI_INFO)  Initializing submodules...$(COLOR_RESET)"
	@git submodule update --init --recursive
	@echo "$(COLOR_INFO)$(EMOJI_INFO)  Building MLX42...$(COLOR_RESET)"
	@cmake -S MLX42 -B MLX42/build -DGLFW_FETCH=1 > /dev/null
	@cmake --build MLX42/build --parallel > /dev/null
	@echo "$(COLOR_SUCCESS)$(EMOJI_SUCCESS)  MLX42 built successfully!$(COLOR_RESET)"
	@$(MAKE) -C libft > /dev/null
	@echo "$(COLOR_SUCCESS)$(EMOJI_SUCCESS)  Libft built successfully!$(COLOR_RESET)"

create_folders:
	@mkdir -p $(dir $(OBJS))

clean:
	@echo "$(COLOR_INFO)$(EMOJI_CLEAN)  Cleaning up...$(COLOR_RESET)"
	@rm -rf MLX42/build
	@$(MAKE) -C libft clean > /dev/null
	@rm -rf build
	@echo "$(COLOR_SUCCESS)$(EMOJI_SUCCESS)  Cleaned up!$(COLOR_RESET)"

fclean: clean
	@echo "$(COLOR_INFO)$(EMOJI_CLEAN)  Removing executable...$(COLOR_RESET)"
	@$(MAKE) -C libft fclean > /dev/null
	@rm -f $(NAME)
	@echo "$(COLOR_SUCCESS)$(EMOJI_SUCCESS)  Executable removed!$(COLOR_RESET)"

run: $(NAME) $(MLX) $(LIBFT) $(OBJS)
	@echo "$(COLOR_INFO)$(EMOJI_RUN)  Compiled and started $(NAME)...$(COLOR_RESET)"
	@./$(NAME) 1

norm:
	@norminette $(SRCS) incl/fractol.h

re: fclean $(NAME)

module-update:
	@git submodule update --remote --merge

.PHONY: all clean fclean run re create_folders

.SILENT: all $(NAME) mlx clean fclean run re create_folders
