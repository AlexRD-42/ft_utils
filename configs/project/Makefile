# Configuration ------------------------------- #
NAME = main
VPATH = sources 
SRCS = main.c
LDLIBS = -pthread

# Defaults ------------------------------------ #
RM := rm -f
BUILD_PATH = build
INC_PATH = includes
OBJ_PATH = $(BUILD_PATH)/obj
BIN = $(BUILD_PATH)/$(NAME)
OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

# Flags --------------------------------------- #
CC = clang
CPPFLAGS = $(addprefix -I,$(INC_PATH))
CFLAGS = -Wall -Wextra -pthread
LDFLAGS =
DEBUG = -g -O1 -Wpedantic -Wcast-qual -Wfloat-equal -Wswitch-default -Wsign-conversion
ASAN = -fsanitize=address,undefined,leak -fno-omit-frame-pointer
TSAN = -fsanitize=thread -fno-omit-frame-pointer
FAST = -march=native -O3 -ffast-math -fstrict-aliasing

# Pattern Rules: Compilation ------------------ #
$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Linking
$(BIN): $(OBJS) | $(BUILD_PATH)	
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

# Directory
$(OBJ_PATH):
	@mkdir -p $@
$(BUILD_PATH):
	@mkdir -p $@

# Phonies ------------------------------------- #
all: $(BIN)

clean:
	$(RM) -r $(OBJ_PATH)

fclean:
	$(RM) -r $(BUILD_PATH)

re: fclean all

debug: CFLAGS += $(DEBUG)
debug: clean $(BIN)

asan: CFLAGS += $(DEBUG) $(ASAN)
asan: LDFLAGS += $(ASAN)
asan: clean $(BIN)

tsan: CFLAGS += $(DEBUG) $(TSAN)
tsan: LDFLAGS += $(TSAN)
tsan: clean $(BIN)

fast: CFLAGS += $(FAST)
fast: LDFLAGS += -flto
fast: clean $(BIN)

ffast: CFLAGS += $(FAST) -Ofast
ffast: LDFLAGS += -flto
ffast: clean $(BIN)

.PHONY: all clean fclean re debug asan tsan fast ffast
