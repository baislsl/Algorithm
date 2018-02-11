# Read from the file file.txt and print its transposed content to stdout.
#!/usr/bin/env bash

filename="file.txt"
declare -A matrix


y=0
x=0
while read -r line
do
    declare -a la
    read -a la <<< "${line}"
#    echo "la=${la[@]}"
    for idx in ${!la[@]}; do
        matrix[${y}, ${idx}]=${la[${idx}]}
        x=${idx}
    done
    y=$((y+1))
#    echo "read in line = ${line}"
done < "${filename}"
x=$(($x+1))
#echo "x=${x}"
#echo "matrix=${matrix[1, 1]}"

for((i=0;i<$x;i++)) do
    for((j=0;j<$y;j++)) do
        # echo "i=${i}, j=${j}"
        echo -n "${matrix[$j, $i]} "
    done
    echo ""
done

