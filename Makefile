.POSIX:
CROSS	= 
CC		= $(CROSS)gcc
COMPILER_WARNING_FLAGS = -Wall -Wextra -Wconversion -Wdouble-promotion -Wnull-dereference -Wwrite-strings -Wformat=2 -Wcast-align=strict -Wswitch-enum -Wpedantic
# COMPILER_SANITIZERS = -fsanitize=undefined -fsanitize=bool -fsanitize=bounds-strict
COMPILER_OPTIMIZATION_LEVEL = -Og -g3
CFLAGS = $(COMPILER_WARNING_FLAGS) $(COMPILER_SANITIZERS) $(COMPILER_OPTIMIZATION_LEVEL)
LDFLAGS = 

# TODO: Debug build vs Release build
lin_pid_calculator.exe: lin_pid_calculator.o
	$(CC) $(LDLFLAGS) $< -o $@

lin_pid_calculator.o: lin_pid_calculator.c
	$(CC) -c $(CFLAGS) $<

reddit_test.exe: reddit_test.o
	$(CC) $(LDLFLAGS) $< -o $@

reddit_test.o: reddit_test.c
	$(CC) -c $(CFLAGS) $<

talkback.exe: talkback.o
	$(CC) $(LDLFLAGS) $< -o $@

talkback.o: talkback.c
	$(CC) -c $(CFLAGS) $<

hello.exe: hello.o
	$(CC) $(LDLFLAGS) $< -o $@

hello.o: hello.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm hello.exe hello.o talkback.o talkback.exe lin_pid_calculator.o lin_pid_calculator.exe
