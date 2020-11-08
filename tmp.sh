#!/bin/bash

for file in `ls ?.cpp`; do
   cp tmp.cpp "${file}"
done

exit 0	