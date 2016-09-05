#!/bin/sh
clang $1 && ./a.out > test.c && diff test.c $1
