# ==============================================================================
# C++ Learning Project Template - Simple CMake Wrapper
# ==============================================================================
#
# This Makefile provides a beginner-friendly interface to the CMake build system.
# It handles common development tasks: building, running, testing, and cleaning.
#
# Prerequisites:
#   - CMake 3.20+
#   - C++ compiler with C++17 support
#   - Google Test (for unit tests)
#
# Quick Start:
#   make build      # Configure and build the project
#   make run        # Run the solution executable
#   make test       # Build and run unit tests
#   make clean      # Remove build artifacts
#
# ==============================================================================

# Declare phony targets (not actual files)
.PHONY: help build run test clean rebuild configure

# Default target when just running 'make'
.DEFAULT_GOAL := help

# ==============================================================================
# Configuration Variables
# ==============================================================================

# Build directory for out-of-source builds
BUILD_DIR := build

# CMake generator (adjust if needed: Ninja, "Unix Makefiles", etc.)
GENERATOR := "Unix Makefiles"

# Build type (Debug, Release, RelWithDebInfo, MinSizeRel)
BUILD_TYPE := Debug

# Executable and test target names (must match CMakeLists.txt)
MAIN_EXECUTABLE := solution_main
TEST_EXECUTABLE := solution_tests

# ==============================================================================
# Help Target
# ==============================================================================

help:
	@echo "==========================================="
	@echo " C++ Learning Project - Available Targets"
	@echo "==========================================="
	@echo ""
	@echo "  make build       Configure and build the project"
	@echo "  make run         Run the main solution executable"
	@echo "  make test        Build and run all unit tests"
	@echo "  make clean       Remove all build artifacts"
	@echo "  make rebuild     Clean then build from scratch"
	@echo "  make configure   Run CMake configuration only"
	@echo "  make help        Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make build && make run      # Build and run"
	@echo "  make test                    # Quick test cycle"
	@echo "  make rebuild test            # Fresh build + test"
	@echo ""

# ==============================================================================
# Build Targets
# ==============================================================================

configure:
	@echo "Configuring project with CMake..."
	@cmake -B $(BUILD_DIR) -G $(GENERATOR) -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)

build: configure
	@echo "Building project..."
	@cmake --build $(BUILD_DIR) --config $(BUILD_TYPE)
	@echo "Build complete. Executables in $(BUILD_DIR)/bin/"

rebuild: clean build

# ==============================================================================
# Run Targets
# ==============================================================================

run: build
	@echo "Running solution executable..."
	@./$(BUILD_DIR)/bin/$(MAIN_EXECUTABLE)

test: build
	@echo "Running tests..."
	@cd $(BUILD_DIR) && ctest --output-on-failure --verbose

# ==============================================================================
# Cleanup Targets
# ==============================================================================

clean:
	@echo "Cleaning build artifacts..."
	@rm -rf $(BUILD_DIR)
	@echo "Clean complete."
