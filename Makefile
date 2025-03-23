.POSIX:
CROSS	= 
CC		= $(CROSS)gcc
COMPILER_WARNING_FLAGS = -Wall -Wextra -Wconversion -Wdouble-promotion -Wnull-dereference -Wwrite-strings -Wformat=2 -Wcast-align=strict -Wswitch-enum -Wpedantic
COMPILER_SANITIZERS = -fsanitize=bool -fsanitize=undefined -fsanitize-trap
COMPILER_OPTIMIZATION_LEVEL = -Og -g3
COMPILER_OPTIMIZATION_LEVEL_SPEED = -O3
COMPILER_OPTIMIZATION_LEVEL_SPACE = -Os
CFLAGS = $(COMPILER_WARNING_FLAGS) $(COMPILER_SANITIZERS) $(COMPILER_OPTIMIZATION_LEVEL)
CFLAGS_FAST = $(COMPILER_WARNING_FLAGS) $(COMPILER_OPTIMIZATION_LEVEL_SPEED)
CFLAGS_SMALL = $(COMPILER_WARNING_FLAGS) $(COMPILER_OPTIMIZATION_LEVEL_SPACE)
LST_CFLAGS = $(COMPILER_WARNING_FLAGS) $(COMPILER_OPTIMIZATION_LEVEL)
LDFLAGS = 

# TODO: Debug build vs Release build
# leetcode_small.lst: leetcode_small.exe
# 	objdump -D $< > $@
# 
# leetcode_small.exe: leetcode_small.o
# 	$(CC) $(LDLFLAGS) $< -o $@
# 
# leetcode_small.o: leetcode.c
# 	$(CC) -c $(CFLAGS_SMALL) $< -o $@
# 
# leetcode_fast.lst: leetcode_fast.exe
# 	objdump -D $< > $@
# 
# leetcode_fast.exe: leetcode_fast.o
# 	$(CC) $(LDLFLAGS) $< -o $@
# 
# leetcode_fast.o: leetcode.c
# 	$(CC) -c $(CFLAGS_FAST) $< -o $@

leetcode.lst: leetcode.exe
	objdump -D $< > $@

leetcode.exe: leetcode.o
	$(CC) $(LDLFLAGS) $< -o $@

leetcode.o: leetcode.c
	$(CC) -c $(CFLAGS) $<
	cppcheck $<

# file_under_test.exe: file_under_test.o
# 	$(CC) $(LDLFLAGS) $< -o $@
# 
# file_under_test.o: file_under_test.c
# 	$(CC) -c $(CFLAGS) $<
# 
# lin_pid_calculator.exe: lin_pid_calculator.o
# 	$(CC) $(LDLFLAGS) $< -o $@
# 
# lin_pid_calculator.o: lin_pid_calculator.c
# 	$(CC) -c $(CFLAGS) $<
# 
# reddit_test.exe: reddit_test.o
# 	$(CC) $(LDLFLAGS) $< -o $@
# 
# reddit_test.o: reddit_test.c
# 	$(CC) -c $(CFLAGS) $<
# 
# talkback.exe: talkback.o
# 	$(CC) $(LDLFLAGS) $< -o $@
# 
# talkback.o: talkback.c
# 	$(CC) -c $(CFLAGS) $<
# 
# hello.exe: hello.o
# 	$(CC) $(LDLFLAGS) $< -o $@
# 
# hello.o: hello.c
# 	$(CC) -c $(CFLAGS) $<

clean:
	rm -f *.exe *.o *.lst
