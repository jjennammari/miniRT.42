NAME = miniRT

# Tools
CC = cc
CFLAGS = -Wall -Werror -Wextra
GDB = -g
RM = rm -rf

# Directories
INCLUDE_DIR = ./include
BUILD_DIR = build
SRC_DIR = src

# Source files
FILES = main.c tuple.c

# Fullpath for source and objects
SRC := $(addprefix $(SRC_DIR)/,$(FILES))
OBJ := $(addprefix $(BUILD_DIR)/,$(FILES:.c=.o))

# Tests
TEST = test_miniRT
TEST_SRC_DIR = tests
TEST_BUILD_DIR = test_build
TEST_FILES = main.c tuple_test.c tuple.c
TEST_SRC := $(addprefix $(TEST_SRC_DIR)/,$(TEST_FILES))
TEST_OBJ := $(addprefix $(TEST_BUILD_DIR)/,$(TEST_FILES:.c=.o))

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

debug: CFLAGS += $(GDB)
debug: fclean all

test: $(TEST)

$(TEST): fclean $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) -o $(TEST)
	./$(TEST)
$(TEST): fclean

$(TEST_BUILD_DIR)/%.o: $(TEST_SRC_DIR)/%.c | $(TEST_BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(TEST_BUILD_DIR):
	mkdir -p $(TEST_BUILD_DIR)

clean:
	$(RM) $(BUILD_DIR) $(TEST_BUILD_DIR)

fclean: clean
	$(RM) $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re debug