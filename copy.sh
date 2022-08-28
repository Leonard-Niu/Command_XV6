#!/bin/bash
sourcePath="/home/leonard/Documents/xv6/xv6-labs-2020/Command_XV6/"
targetPath="/home/leonard/Documents/xv6/xv6-labs-2020/user/"

files=$(find $sourcePath -name "*.[ch]")

for f in $files
do
    basef=$(basename $f)
    echo "src:"${sourcePath}${basef}
    echo "dst:"${targetPath}${basef}
    ln ${sourcePath}${basef} ${targetPath}${basef}
done