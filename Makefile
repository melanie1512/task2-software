api:
	python3 setup.py build_ext --inplace
	python3 example.py

test:
	g++ --std=c++14 sensor.cpp \
		test_example.cc	-I. \
		-o test_example -I/opt/homebrew/opt/googletest/include -L/opt/homebrew/opt/googletest/lib -lgtest -lgtest_main -pthread
	
cov:
	g++ --std=c++14 -fprofile-arcs -ftest-coverage -o my_test sensor.cpp test_example.cc -I/opt/homebrew/opt/googletest/include -L/opt/homebrew/opt/googletest/lib -lgtest -lgtest_main
	./my_test
	gcov -o . test_example.cpp
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out
	open out/index.html
