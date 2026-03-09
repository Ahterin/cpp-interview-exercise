# C++ Interview Exercise

This repository contains a small C++ exercise focused on practical engineering work.

You do **not** need to finish everything.
Please explain your reasoning as you go.

## What we are interested in

- reading and understanding an existing codebase
- building the project
- running and inspecting unit tests
- reviewing the current implementation
- improving tests and/or implementation where needed
- working with the repository in a reasonable way

## Pricing rules

The final price depends on the user tier:

- Regular user: 0% discount
- Premium user: 10% discount
- VIP user: 20% discount

## Suggested workflow

1. Confirm (or switch to) the branch provided for you by the interviewer
2. Build the project
3. Run unit tests
4. Read the existing code
5. Identify missing scenarios or design issues
6. Add tests and improve the implementation if needed
7. Commit your changes

## Build

```bash
cmake -S . -B build
cmake --build build
```

Notes:
- Tests use GoogleTest.
- CMake requires a discoverable `GTest` package. Installing `GTest` is a setup precondition.

## Run tests

```bash
ctest --test-dir build --output-on-failure
```

List discovered test names:

```bash
ctest --test-dir build -N
```

Run a single test by name:

```bash
ctest --test-dir build -R '^PriceCalculatorTests\.RegularUserKeepsOriginalPrice$' --output-on-failure
```

Helper scripts:

```bash
./scripts/bootstrap.sh
./scripts/run_checks.sh
./scripts/reset_repo.sh
```

`./scripts/reset_repo.sh` is destructive: it resets the current `candidate/*` branch to its original interview start state and removes local untracked/ignored files.

## Notes

- If something in the code or documentation seems inconsistent, say so and continue with a reasonable assumption.
- The goal is not perfect syntax from memory, but practical engineering thinking.
- You may add tests, refactor code, or explain what you would change if you do not want to implement everything.
- It is completely fine to talk through your reasoning.
- Using AI tools, search engines, and online documentation is allowed.
- We want to see reasonable use of those tools and your own engineering judgment.
- You must be able to explain and defend every change you make.
