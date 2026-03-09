#!/usr/bin/env bash
set -euo pipefail

cmake -S . -B build
cmake --build build

echo "Discovered tests:"
ctest --test-dir build -N
echo

ctest --test-dir build --output-on-failure --verbose
