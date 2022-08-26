#!/bin/bash
sourcePath="./"
targetPath="../user/"

files=$(find $sourcePath -name "*.c")

for f in $files
do
    ln ${sourcePath}${f} ${targetPath}${f}
done