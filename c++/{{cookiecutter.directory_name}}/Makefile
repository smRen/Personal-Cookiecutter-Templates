.PHONY: configure build test run clean help

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

.DEFAULT_GOAL :=
help :
	@echo "configure	Configure default cmake project debug with GCC and Ninja"
	@echo "build		Compile project"
	@echo "test		Run tests"
	@echo "run		Run main program"
	@echo "clean		Remove cmake related files"
