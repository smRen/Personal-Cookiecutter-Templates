.PHONY: configure build test run clean help

configure: ## Configure default cmake project debug with GCC and Ninja
	@cmake -S . --preset=gcc-ninja-debug-cxx
	@printf "\nProject configured for GCC and Ninja:\n"
	@ln -s build/debug/compile_commands.json
	@printf "Copied compile_commands.json to project root\n"

build: ## Compile project
	@cmake --build ./build/debug
	@printf "Program built\n"

test: ## Test project
	@ctest --test-dir ./build/debug/tests
	@printf "Program tested\n"

run: ## Run program
	@cd ./build/debug/src && ./main
	@printf "Program ran\n"

clean: ## Remove build related files
	@rm -rf ./build
	@unlink compile_commands.json
	@printf "Build files cleaned up\n"

.DEFAULT_GOAL :=
help :
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
