CXX = clang++
CXXFLAGS = -Wall -std=c++17

SRCS = test.cpp unique_pointer.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = driver

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
