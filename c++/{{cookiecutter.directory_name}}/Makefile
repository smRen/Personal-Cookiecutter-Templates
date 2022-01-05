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

run: ## Run program
	@cd ./build/debug/src && ./main

clean: ## Remove build related files
	@rm -rf ./build
	@unlink compile_commands.json
	@printf "Build files cleaned up\n"

.DEFAULT_GOAL :=
help :
	@printf "\nRun configure first then build\n-----------------------"
	@printf "\n\u001b[31m%s\u001b[0m\n" "Commands:"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[35m%-30s\033[0m %s\n", $$1, $$2}'
	@printf "\n"
