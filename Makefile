CXX=g++

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
TESTBIN_DIR = ./testbin

UNAME := $(shell uname)

PKGS =

#DEBUG_MODE =TRUE
ifdef DEBUG_MODE
DEFINES += -DDEBUG
CFLAGS += -g -ggdb -D_GLIBCXX_DEBUG
else
CFLAGS += -O3
endif

ifeq ($(UNAME), Darwin)
#add paths if developing on mac with macports
INCLUDE += -I 'opt/local/include'
TESTLDFLAGS += -L '/opt/local/lib'
endif

INCLUDE += -I $(INC_DIR)
CFLAGS += -Wall
LDFLAGS +=
TESTLDFLAGS += -lgtest -lgtest_main -lpthread
CPPFLAGS += -std=c++14
PROJ_NAME = proj3
TESTMANCALA_NAME = testmancala

MAIN_OBJ = $(OBJ_DIR)/main.o
TEST_OBJ = $(OBJ_DIR)/testmancala.o
PROJ_OBJ = $(OBJ_DIR)/MancalaBoard.o

all: directories test $(BIN_DIR)/$(PROJ_NAME)

test: $(TESTBIN_DIR)/$(TESTMANCALA_NAME)
	$(TESTBIN_DIR)/$(TESTMANCALA_NAME)

$(BIN_DIR)/$(PROJ_NAME): $(PROJ_OBJ) $(MAIN_OBJ)
	$(CXX) $(MAIN_OBJ) $(PROJ_OBJ) -o $(BIN_DIR)/$(PROJ_NAME) $(CFLAGS) $(CPPFLAGS) $(DEFINES) -L ./googletest/build/lib $(LDFLAGS)

$(TESTBIN_DIR)/$(TESTMANCALA_NAME): $(PROJ_OBJ) $(TEST_OBJ)
	$(CXX) $(PROJ_OBJS) $(TEST_OBJ) -o $(TESTBIN_DIR)/$(TESTMANCALA_NAME) $(CFLAGS) $(CPPFLAGS) $(DEFINES) -L ./googletest/build/lib $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(DEFINES) $(INCLUDE) -I ./googletest/googletest/include -c $< -o $@

.PHONY: directories
directories:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(TESTBIN_DIR)

clean::
	-rm $(OBJ_DIR)/*.o $(INC_DIR)/*.*~ $(SRC_DIR)/*.*~

.PHONY: clean
