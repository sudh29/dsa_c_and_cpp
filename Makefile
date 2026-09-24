.PHONY: all test clean help

all: test

test:
	@bash scripts/compile_and_test.sh

clean:
	@rm -rf /tmp/dsa_test_bin build bin *.o *.out
	@echo "Clean completed."

help:
	@echo "Available targets:"
	@echo "  make test   - Compile and execute all C (C11) and C++ (C++20) programs"
	@echo "  make clean  - Remove temporary build artifacts"
	@echo "  make help   - Show this help message"
