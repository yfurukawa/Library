CC = g++
RM = rm -rf
AR = ar
INCLUDE = -I/usr/incude -I/usr/local/include
LIB_DIR = -L/usr/lib64 -L/usr/local/lib64
LIB = -lpthread -lrt
OPT = -O0 -g3 -Wall -fmessage-length=0 --input-charset=UTF-8 --exec-charset=UTF-8
AR_OPT = rcs
TARGET = a.out
TARGET_LIB = lib$(TARGET).a
include productionSources.mk

all: main.o $(TARGET_LIB)
	$(CC) $(INCLUDE) $(LIB_DIR) $(LIB) $(OPT) -o $(TARGET) main.o -l$(TARGET)

main.o: main.cpp
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c main.cpp

$(TARGET_LIB) lib: $(SRC:.cpp=.o)
	$(AR) $(AR_OPT) $(TARGET_LIB) $(SRC:.cpp=.o)
$(SRC:.cpp=.o): $(SRC)
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c $(SRC)

.PHONY: clean
clean:
	$(RM) *.o $(TARGET) $(TEST_TARGET) $(TARGET_LIB) gmon.out *.gc* *.xml *.exe *.txt *.log


TEST_TARGET = a.outTest
TEST_INCLUDE = -I../test -I.
TEST_LIB = -lgtest
TEST_OPT = -O0 -g3 -Wall -Wnon-virtual-dtor -Woverloaded-virtual -fmessage-length=0 --input-charset=UTF-8 --exec-charset=UTF-8
include testSources.mk
include testObjects.mk

test: $(SRC:.cpp=.o) $(TEST_OBJ)
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(TEST_OPT) -o $(TEST_TARGET) $(SRC:.cpp=.o) $(TEST_OBJ) $(LIB) $(TEST_LIB)

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(LIB) $(TEST_LIB) $(TEST_OPT) -c $(TEST_SRC)
