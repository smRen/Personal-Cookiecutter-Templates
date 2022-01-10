.PHONY: configure build test run clean help

configure: ## Configure default cmake project debug with GCC and Ninja
	@cmake -S . --preset=gcc-ninja-debug-cxx
	@printf "\033[32m\nProject configured for GCC and Ninja:\n\033[0m"
	@ln -s build/debug/compile_commands.json
	@printf "\033[32mCopied compile_commands.json to project root\n\033[0m\n"

build: ## Compile project
	@cmake --build ./build/debug
	@printf "\n\033[32mProgram built\n\033[0m\n"

test: ## Test project
	@GTEST_COLOR=1 ctest --test-dir ./build/debug/tests --verbose --output-on-failure

run: ## Run program
	@cd ./build/debug/src && ./main

clean: ## Remove build related files
	@rm -rf ./build
	@unlink compile_commands.json
	@printf "\n\033[32mBuild files cleaned up\n\033[0m\n"

.DEFAULT_GOAL :=
help :
	@printf "\nRun configure first then build\n-----------------------"
	@printf "\n\033[32m%s\033[0m\n" "Commands:"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[35m%-30s\033[0m %s\n", $$1, $$2}'
	@printf "\n"
