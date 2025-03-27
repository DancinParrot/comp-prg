#!/bin/bash
for ((i = 1; i <= 100; i++)); do
  echo "$i"
  ../build/gen $i > int
  ../build/abc051_b < int > out1
  ../build/abc051_b_bf < int > out2
  diff -w out1 out2 || break
done
