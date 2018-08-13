# Fuzzy Match

Fuzzy matching calculated using Levenshtein distance.

## Running

Running the application using the shell script to search for the `<target>` word with a maximum Levenshtein `<distance>` (int). The `<distance>` is optional, and defaults to 1 (perfect match).

```bash
sh run.sh <target> <distance>
```

## Building

Compiling from source

```bash
make
```

Cleaning working directory

```bash
make clean
```

## Directory Structure

| Directory | Tracked | Description         |
| --------- | ------- | ------------------- |
| bin       | FALSE   | Executable binaries |
| build     | FALSE   | Object files        |
| include   | TRUE    | Header files        |
| lib       | TRUE    | Compiled libraries  |
| src       | TRUE    | C/C++ source files  |
| test      | TRUE    | Test files          |
