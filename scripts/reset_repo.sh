#!/usr/bin/env bash
set -euo pipefail

CURRENT_BRANCH="$(git rev-parse --abbrev-ref HEAD 2>/dev/null || true)"
BASE_BRANCH="candidate/task-price-fix"
ORIGINAL_TAG="interview/original-candidate-task-price-fix"

if ! git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
    echo "Error: run this script inside a git repository."
    exit 1
fi

if [[ -z "${CURRENT_BRANCH}" || "${CURRENT_BRANCH}" == "HEAD" ]]; then
    echo "Error: could not determine current branch."
    exit 1
fi

if [[ "${CURRENT_BRANCH}" != candidate/* ]]; then
    echo "Error: current branch must match 'candidate/*'."
    exit 1
fi

if ! git show-ref --verify --quiet "refs/heads/${BASE_BRANCH}"; then
    echo "Error: base branch '${BASE_BRANCH}' does not exist."
    exit 1
fi

RESET_REF="${BASE_BRANCH}"
if git show-ref --verify --quiet "refs/tags/${ORIGINAL_TAG}"; then
    RESET_REF="${ORIGINAL_TAG}"
fi

git reset --hard "${RESET_REF}" >/dev/null

git clean -fdx >/dev/null

echo "Repository reset complete."
echo "Active branch: ${CURRENT_BRANCH}"
echo "Reset reference: ${RESET_REF}"
