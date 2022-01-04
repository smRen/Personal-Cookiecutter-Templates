.PHONY: configure build test run clean

configure:
	cmake -S . --preset=gcc-ninja-debug-cxx && ln -s build/debug/compile_commands.json

build:
	cmake --build ./build/debug

test:
	ctest --test-dir ./build/debug/tests

run:
	cd ./build/debug/src && ./main

clean:
	rm -rf ./build
	unlink compile_commands.json
