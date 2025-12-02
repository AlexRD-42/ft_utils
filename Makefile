# Configuration ------------------------------- #
NAME = main
BONUS_NAME = main_bonus
BUILD_PATH = build
INC_PATH = includes
OBJ_PATH = $(BUILD_PATH)/obj
BIN = $(BUILD_PATH)/$(NAME)
VPATH = sources sources/utils 

# Files --------------------------------------- #
LIBS =
SRCS = 
BONUS_SRCS = 
OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

# Flags --------------------------------------- #
CC = clang
CFLAGS = -Wall -Wextra $(addprefix -I,$(INC_PATH)) -flto -fstrict-aliasing -pthread
LFLAGS =
DEBUG = -g -Wpedantic -Wcast-qual -Wfloat-equal -Wswitch-default -Wduplicated-branches -Wduplicated-cond -Wsign-conversion
# SANITIZERS = -fsanitize=address,undefined,leak -fno-omit-frame-pointer
SANITIZERS = -fsanitize=undefined -fno-omit-frame-pointer
FAST = -march=native -O3 -ffast-math

# Pattern Rule -------------------------------- #
$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

# Linking Rule -------------------------------- #
$(BIN): $(OBJS) | $(BUILD_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS) $(LFLAGS)

# Directory Rule ------------------------------ #
$(OBJ_PATH):
	@mkdir -p $@
$(BUILD_PATH):
	@mkdir -p $@

# Phonies ------------------------------------- #
all: $(BIN)

bonus: SRCS = $(BONUS_SRCS)
bonus: NAME = $(BONUS_NAME)
bonus: clean $(BIN)

debug: CFLAGS += $(DEBUG) $(SANITIZERS)
debug: clean $(BIN)

fast: CFLAGS += $(FAST)
fast: clean $(BIN)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(BUILD_PATH)/$(NAME) $(BUILD_PATH)/$(BONUS_NAME) 

re: fclean all

.PHONY: all clean fclean re fast debug bonus
