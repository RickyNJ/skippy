CXX = g++
CXXFLAGS = -Wall -Iinclude
LDFLAGS = -L/usr/local/lib -L. -lglfw -ldl
SRC = src/main.cpp src/glad.c
OUT = skippy 
TESTOUT = test 

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDFLAGS) -o $(OUT)

clean:
	rm -f $(OUT)

test:
	$(CXX) $(CXXFLAGS) $(TESTSRC) $(LDFLAGS) -o $(TESTOUT)
