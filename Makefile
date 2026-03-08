CC = cc
CCFLAGS = -Wall -Wextra

default:
	$(CC) $(CCFLAGS)  src/*.c -o basm

debug:
	$(CC) $(CCFLAGS) -g  -fsanitize=address -fno-omit-frame-pointer  -static-libasan src/*.c -o basm


clean:
	rm basm
