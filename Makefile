CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra 
GCOV = -fprofile-arcs -ftest-coverage -fPIC -pthread
TEST_FLAGS = -lgtest 
OUTNAME = tests
STLIB = viewer.a
UNIT = unit_tests

ifeq ($(OS), Darwin)
    LIBS := -lcheck 
	APPLICATION = FurryViewer2.app 
	OPEN = open $(APPLICATION)
else
    LIBS := -lgtest -lstdc++ -lcheck_pic -lrt -lpthread -lsubunit -lm -g
	APPLICATION = FurryViewer2
	OPEN = ./$(APPLICATION)
endif

install: clean
	mkdir build
	cd build && cmake ../View/CMakeLists.txt && make
	cp -rf build/FurryViewer2.app $(HOME)/Desktop/FurryViewer2.app

uninstall:
	rm -rf build
	rm -rf $(HOME)/Desktop/FurryViewer2.app

tests: $(STLIB)
	$(CC) $(CXXFLAGS) tests/test.cc $(STLIB) -o $(UNIT) $(LIBS)
	./$(UNIT)

gcov_report: tests
	mkdir report
	gcovr --html-details -o report/coverage.html
	open ./report/coverage.html

clean:
	rm -rf build ./*.o ./*.a ./a.out ./*.gcno ./*.gcda ./gcov_report *.info ./*.info tests
	
dist:
	mkdir ../dist
	cp -r ../src ../dist
	cp ../README.md ../dist
	tar -czvf dist.tar.gz ../dist
	rm -rf ../dist

dvi:
	doxygen Doxyfile
	open html/index.html