#!/usr/bin/env python3
"""
C/C++ File Parity Checker for dsa_c_and_cpp repository.
Verifies that each problem in the repository has both a C (.c) and C++ (.cpp) implementation.
"""

import os
import sys
import argparse
import json
from collections import defaultdict

DEFAULT_MODULES = [
    "0_basics",
    "1_array",
    "2_matrix",
    "3_string",
    "4_search_sort",
    "5_linklist",
    "6_binary_tree",
    "7_bst",
    "8_greedy",
    "9_backtracking",
    "10_stack_queues",
    "11_heap",
    "12_graph",
    "13_Trie",
    "14_dynamic_programming",
    "15_bit_manipulation"
]

def scan_module(mod_path):
    stems = defaultdict(set)
    for entry in os.listdir(mod_path):
        full_path = os.path.join(mod_path, entry)
        if not os.path.isfile(full_path):
            continue
        if entry.endswith(".c"):
            stems[entry[:-2]].add("c")
        elif entry.endswith(".cpp"):
            stems[entry[:-4]].add("cpp")

    paired = sorted([s for s, exts in stems.items() if "c" in exts and "cpp" in exts])
    cpp_only = sorted([s for s, exts in stems.items() if exts == {"cpp"}])
    c_only = sorted([s for s, exts in stems.items() if exts == {"c"}])

    return {
        "total_problems": len(stems),
        "paired": paired,
        "cpp_only": cpp_only,
        "c_only": c_only
    }

def main():
    parser = argparse.ArgumentParser(description="Check C/C++ problem parity in dsa_c_and_cpp repository")
    parser.add_argument("--repo-root", default=".", help="Root path of the repository")
    parser.add_argument("--json", action="store_true", help="Output results as JSON")
    parser.add_argument("--details", action="store_true", help="Print missing files list")
    parser.add_argument("--strict", action="store_true", help="Exit with code 1 if any problem is unpaired")
    parser.add_argument("modules", nargs="*", default=DEFAULT_MODULES, help="Specific modules to check")

    args = parser.parse_args()
    root = os.path.abspath(args.repo_root)

    results = {}
    total_problems = 0
    total_paired = 0
    total_cpp_only = 0
    total_c_only = 0

    for mod in args.modules:
        mod_path = os.path.join(root, mod)
        if not os.path.isdir(mod_path):
            continue
        data = scan_module(mod_path)
        results[mod] = data

        total_problems += data["total_problems"]
        total_paired += len(data["paired"])
        total_cpp_only += len(data["cpp_only"])
        total_c_only += len(data["c_only"])

    parity_pct = (total_paired / total_problems * 100.0) if total_problems > 0 else 0.0

    if args.json:
        payload = {
            "summary": {
                "total_problems": total_problems,
                "paired": total_paired,
                "cpp_only": total_cpp_only,
                "c_only": total_c_only,
                "parity_percentage": round(parity_pct, 2)
            },
            "modules": results
        }
        print(json.dumps(payload, indent=2))
    else:
        print("=" * 72)
        print(" DSA C (C11) & C++ (C++20) Implementation Parity Audit")
        print(" Repository: " + root)
        print("=" * 72)
        header = f"{'Module':<25} | {'Total':^8} | {'Paired':^8} | {'CPP Only':^10} | {'C Only':^8} | {'Parity %':^8}"
        print(header)
        print("-" * 72)
        for mod, d in results.items():
            tot = d["total_problems"]
            p = len(d["paired"])
            cpp = len(d["cpp_only"])
            c = len(d["c_only"])
            pct = (p / tot * 100.0) if tot > 0 else 0.0
            print(f"{mod:<25} | {tot:^8} | {p:^8} | {cpp:^10} | {c:^8} | {pct:^8.1f}%")
        print("-" * 72)
        print(f"{'OVERALL':<25} | {total_problems:^8} | {total_paired:^8} | {total_cpp_only:^10} | {total_c_only:^8} | {parity_pct:^8.1f}%")
        print("=" * 72)

        if args.details:
            print("\nDetailed Gap Breakdown:")
            for mod, d in results.items():
                if d["cpp_only"] or d["c_only"]:
                    print(f"\n>> {mod}:")
                    if d["cpp_only"]:
                        print(f"   Missing C ({len(d['cpp_only'])}):")
                        for s in d["cpp_only"]:
                            print(f"     - {s}.c")
                    if d["c_only"]:
                        print(f"   Missing C++ ({len(d['c_only'])}):")
                        for s in d["c_only"]:
                            print(f"     - {s}.cpp")

    if args.strict and total_paired < total_problems:
        sys.exit(1)

    sys.exit(0)

if __name__ == "__main__":
    main()
