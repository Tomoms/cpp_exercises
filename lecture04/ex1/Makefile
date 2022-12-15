CC = g++
CPPFLAGS = -O3 -march=native -Wall
OUT = out
SRC = src
OBJS = $(addprefix $(OUT)/, $(patsubst %.cpp, %.o, $(notdir $(wildcard src/*.cpp))))
DEPS = $(wildcard $(OBJS:%=%.d))
INCLUDE_DIRS = $(SRC)/include
INCLUDES = $(INCLUDE_DIRS:%=-I%)

quadratic_equation: $(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $@ $(INCLUDES)

$(OUT)/%.o: $(SRC)/%.cpp
	$(CC) -MD -MP -MF "$@.d" -c $(CPPFLAGS) $< -o $@ $(INCLUDES)

include $(DEPS)

clean:
	rm -r out/
	rm quadratic_equation

$(shell mkdir $(OUT))
