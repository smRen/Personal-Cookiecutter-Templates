.PHONY: configure build test run clean

configure:
	cmake -S . --preset=gcc-ninja-debug-cxx

build:
	cmake --build ./build/debug

test:
	ctest --test-dir ./build/debug/tests

run:
	cd ./build/debug/src && ./main

clean:
	rm -rf ./build
