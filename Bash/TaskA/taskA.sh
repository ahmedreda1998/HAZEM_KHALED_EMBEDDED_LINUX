#!/usr/bin/bash

declare dir=$1

function directories_creation () {
    mkdir $dir/txt
    mkdir $dir/jpg
    mkdir $dir/pdf
    mkdir $dir/mis
}

function main () {

directories_creation

# looping inside the main directory 
for file in $dir/* ; do
# checking if files still exists inside the main directory
if [ -f "$file" ]; then
    declare ext=${file##*.}
# putting file inside the sub-directories depending on its extension
case "${ext}" in
    txt)
        mv $file $dir/txt
    ;;
    jpg)
        mv $file $dir/jpg
    ;;
    pdf)
        mv $file $dir/pdf
    ;;
    *)
        mv $file $dir/mis
    ;;     
esac
fi

done
}

main





