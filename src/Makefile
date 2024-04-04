CC = gcc
CFLAGS	=	-std=c11 -Wall -Werror -Wextra
BUILD_DIR = ./../build

door_struct:
		$(CC) $(CFLAGS) dmanager_module.c door_struct.h -o $(BUILD_DIR)/Quest_1

clean:
	rm -f *.o
	rm -f $(BUILD_DIR)/Quest_*