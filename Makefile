CC = cc
CCFLAGS = -Wall -Wextra

default:
	$(CC) $(CCFLAGS)  src/*.c -o basm

debug:
	$(CC) $(CCFLAGS) -g  -fsanitize=address -fno-omit-frame-pointer -static-libasan -DDEBUG src/*.c -o basm

fuzzing:
	afl-clang-fast src/*.c 


clean:
	rm basm
