SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build
MAIN_CLASS = com.hyki.hi.Hi

all: compile

generate-ast:
	@mkdir -p $(BUILD_DIR)
	javac src/com/hyki/tool/GenerateAst.java -d $(BUILD_DIR)
	java -cp $(BUILD_DIR) com.hyki.tool.GenerateAst $(SRC_DIR)/com/hyki/hi

ast-printer: compile
	java -cp build com.hyki.hi.AstPrinter

compile: generate-ast
	@mkdir -p $(BUILD_DIR)
	find $(SRC_DIR) -name "*.java" | xargs javac -d $(BUILD_DIR)

run: compile
	java -cp $(BUILD_DIR) $(MAIN_CLASS)

clean:
	rm -rf $(BUILD_DIR)

re:
	make clean
	make all

.PHONY: all generate-ast ast-printer compile run clean re
