CC = g++
CPPFLAGS = -O3 -march=native -Wall
OUT = out
SRC = src
OBJS = $(addprefix $(OUT)/, $(patsubst %.cpp, %.o, $(notdir $(wildcard src/*.cpp))))
INCLUDE_DIRS = $(SRC)/include
INCLUDES = $(INCLUDE_DIRS:%=-I%)

ex3: $(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $@ $(INCLUDES)

$(OUT)/%.o: $(SRC)/%.cpp
	$(CC) -c $(CPPFLAGS) $^ -o $@ $(INCLUDES)

clean:
	rm -r out/
	rm ex3

$(shell mkdir $(OUT))
