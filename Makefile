.PHONY: all test clean help

JOBS ?= $(shell nproc 2>/dev/null || echo 4)
STRICT ?= 0
MODULE ?=

ARGS := -j $(JOBS)
ifeq ($(STRICT),1)
	ARGS += --strict
endif
ifneq ($(MODULE),)
	ARGS += $(MODULE)
endif

all: test

test:
	@bash scripts/compile_and_test.sh $(ARGS)

clean:
	@rm -rf /tmp/dsa_test_suite.* /tmp/dsa_test_bin build bin *.o *.out
	@echo "Clean completed."

help:
	@echo "Available targets:"
	@echo "  make test [JOBS=N] [STRICT=1] [MODULE=name] - Compile and execute test suite"
	@echo "  make clean                                  - Remove temporary build artifacts"
	@echo "  make help                                   - Show this help message"
