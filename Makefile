CC = gcc
CFLAGS = -Wall -Wextra -g

#directories
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# final executable
TARGET = $(BIN_DIR)/Socket

# Object files
OBJECTS = $(OBJ_DIR)/SocketClient/main.o $(OBJ_DIR)/SocketUtil/SocketUtil.o $(OBJ_DIR)/SocketServer/main.o


$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)


$(OBJ_DIR)/SocketClient/main.o: SocketClient/main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/SocketServer/main.o: SocketServer/main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/SocketUtil/SocketUtil.o: SocketUtil/SocketUtil.c
	$(CC) $(CFLAGS) -c $< -o $@



clean:
	rm -f $(OBJ_DIR)/SocketClient/main.o
	rm -f $(OBJ_DIR)/SocketUtil/SocketUtil.o
	rm -f $(OBJ_DIR)/SocketServer/main.o
	rm -f $(TARGET)
