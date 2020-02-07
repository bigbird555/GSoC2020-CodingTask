CXX = c++
WFLAGS = -Wall -Wextra -Wno-unused-parameter
CXXFLAGS = -std=c++11 -pedantic $(WFLAGS)
RM = rm -f

all: closest_point

closest_point: closest.cc main.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) closest_point
