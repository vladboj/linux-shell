EXEC = bin/final_executable
SRC_FILES = $(wildcard src/*.c)
OBJ_FILES = $(patsubst src/%.c, obj/%.o, $(SRC_FILES))

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	gcc $(OBJ_FILES) -o $(EXEC)

obj/%.o: src/%.c
	gcc -c -Iinclude $< -o $@

run:
	$(EXEC)

clean:
	rm -f $(OBJ_FILES) $(EXEC)

.PHONY: all run clean
