CXX = c++
WFLAGS = -Wall -Wextra -Wno-unused-parameter
CXXFLAGS = -std=c++11 -O2 -pedantic $(WFLAGS)
DIFF = diff -u
RM = rm -f

all: closest_point

closest_point: closest.cc main.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

closest_point_test: closest.cc test.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

test: closest_point_test
	closest_point_test > test.txt
	$(DIFF) test.ref test.txt && echo TEST PASSED || echo TEST FAILED

closest_point_perf: closest.cc perf.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

benchmark: closest_point_perf
	closest_point_perf 1000000

perf: benchmark

.PHONY: perf benchmark

clean:
	$(RM) closest_point closest_point_test closest_point_perf test.txt
