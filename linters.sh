#!/bin/bash

#cpplint --filter=-legal/copyright task*.c | grep "Total errors found"

cpplint --filter=-legal/copyright,-readability/casting Task1.c Task2.c Task3.c tema2.c
clang-tidy-12  -checks='-*,cppcoreguidelines*' Task1.c Task2.c Task3.c tema2.c --
#clang-tidy-12 -header-filter='.*'  -checks='*,-llvmlibc-restrict-system-libc-headers,-clang-analyzer-security*' *.c --
#clang-tidy-12 -header-filter='.*'  -checks='*,-llvmlibc-restrict-system-libc-headers' *.c -- | grep warning:
