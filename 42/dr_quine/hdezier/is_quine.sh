#!/bin/sh
clang-3.6 $1 && ./a.out > test.c && diff test.c $1
