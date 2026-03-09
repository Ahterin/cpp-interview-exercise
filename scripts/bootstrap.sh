#!/usr/bin/env bash
set -euo pipefail

cmake -S . -B build
cmake --build build

echo "Build finished successfully."
echo "Run checks with: ./scripts/run_checks.sh"
