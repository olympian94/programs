FLAGS = -Wall

all: switchcases.s shortcircuiting.s

switchcases.s : switchcases.c
	gcc -S switchcases.c

shortcircuiting.s : shortcircuiting.c
	 gcc -S shortcircuiting.c


clean:
	rm *.s