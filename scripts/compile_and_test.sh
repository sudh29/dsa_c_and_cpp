#!/usr/bin/env bash

# Repository Root Directory
REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
TMP_BIN="/tmp/dsa_test_bin"

CC="${CC:-gcc}"
CXX="${CXX:-g++}"
CFLAGS="-std=c11 -Wall -Wextra -O2"
CXXFLAGS="-std=c++20 -Wall -Wextra -O2"

MODULES=(
    "0_basics"
    "1_array"
    "2_matrix"
    "3_string"
    "4_search_sort"
    "5_linklist"
    "6_binary_tree"
    "7_bst"
    "8_greedy"
    "9_backtracking"
    "10_stack_queues"
    "11_heap"
    "12_graph"
    "13_Trie"
    "14_dynamic_programming"
    "15_bit_manipulation"
)

# Allow targeting specific module: ./compile_and_test.sh 0_basics
if [ $# -gt 0 ]; then
    MODULES=("$@")
fi

TOTAL=0
PASSED=0
FAILED=0
FAILED_FILES=()

echo "=========================================================="
echo " Starting DSA C (C11) & C++ (C++20) Test Suite"
echo " Compiler: C: ${CC}, C++: ${CXX}"
echo " Root: ${REPO_ROOT}"
echo "=========================================================="

for mod in "${MODULES[@]}"; do
    MOD_PATH="${REPO_ROOT}/${mod}"
    if [ ! -d "${MOD_PATH}" ]; then
        echo "Module directory not found: ${MOD_PATH}"
        continue
    fi

    echo ""
    echo ">> Testing Module: ${mod}"
    MOD_COUNT=0
    MOD_PASS=0

    # Compile and test C files (.c)
    while IFS= read -r -d '' c_file; do
        TOTAL=$((TOTAL + 1))
        MOD_COUNT=$((MOD_COUNT + 1))
        if ${CC} ${CFLAGS} "${c_file}" -o "${TMP_BIN}" 2>/dev/null && "${TMP_BIN}" >/dev/null 2>&1; then
            PASSED=$((PASSED + 1))
            MOD_PASS=$((MOD_PASS + 1))
        else
            FAILED=$((FAILED + 1))
            FAILED_FILES+=("${c_file}")
            echo "   [FAIL] $(basename "${c_file}")"
        fi
    done < <(find "${MOD_PATH}" -maxdepth 1 -name "*.c" -print0 | sort -z)

    # Compile and test C++ files (.cpp)
    while IFS= read -r -d '' cpp_file; do
        TOTAL=$((TOTAL + 1))
        MOD_COUNT=$((MOD_COUNT + 1))
        if ${CXX} ${CXXFLAGS} "${cpp_file}" -o "${TMP_BIN}" 2>/dev/null && "${TMP_BIN}" >/dev/null 2>&1; then
            PASSED=$((PASSED + 1))
            MOD_PASS=$((MOD_PASS + 1))
        else
            FAILED=$((FAILED + 1))
            FAILED_FILES+=("${cpp_file}")
            echo "   [FAIL] $(basename "${cpp_file}")"
        fi
    done < <(find "${MOD_PATH}" -maxdepth 1 -name "*.cpp" -print0 | sort -z)

    echo "   Passed: ${MOD_PASS}/${MOD_COUNT}"
done

# Cleanup
rm -f "${TMP_BIN}"

echo ""
echo "=========================================================="
echo " Test Suite Summary:"
echo " Total files tested: ${TOTAL}"
echo " Passed:             ${PASSED}"
echo " Failed:             ${FAILED}"
echo "=========================================================="

if [ ${FAILED} -gt 0 ]; then
    echo "Failed files:"
    for f in "${FAILED_FILES[@]}"; do
        echo "  - $f"
    done
    exit 1
fi

echo " All tests passed successfully!"
exit 0
