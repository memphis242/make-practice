.POSIX:
CROSS	= 
CC		= $(CROSS)gcc
COMPILER_WARNING_FLAGS = -Werror -Wall -Wextra -Wconversion -Wdouble-promotion -Wnull-dereference -Wwrite-strings -Wformat=2 -Wcast-align=strict -Wswitch-enum -Wpedantic
COMPILER_SANITIZERS = -fsanitize=undefined -fsanitize=bool -fsanitize=bounds-strict
COMPILER_OPTIMIZATION_LEVEL = -Og -g3
CFLAGS = $(COMPILER_WARNING_FLAGS) $(COMPILER_SANITIZERS) $(COMPILER_OPTIMIZATION_LEVEL)
LDFLAGS = 

# TODO: Debug build vs Release build
hello.exe: hello.o
	$(CC) $(LDLFLAGS) $< -o $@

hello.o: hello.c
	$(CC) -c $(CFLAGS) $<

talkback.exe: talkback.o
	$(CC) $(LDLFLAGS) $< -o $@

talkback.o: talkback.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm hello.exe hello.o talkback.o talkback.exe
