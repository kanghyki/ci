SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build
MAIN_CLASS = com.hyki.hi.Hi

all: compile

compile:
	@mkdir -p $(BUILD_DIR)
	find $(SRC_DIR) -name "*.java" | xargs javac -d $(BUILD_DIR)

run: compile
	java -cp $(BUILD_DIR) $(MAIN_CLASS)

clean:
	rm -rf $(BUILD_DIR)

re:
	make clean
	make all

.PHONY: all compile run clean re
