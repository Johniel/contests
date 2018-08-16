function gen(){
    outputFile=docs/$1.md
    mkdir -p $(dirname $outputFile)
    if [[ -f $1/README.md ]]; then
        cat $1/README.md > docs/$1.md
    else
        echo "# $1" > $outputFile
    fi

    echo >> $outputFile
    echo '## Codes' >> $outputFile

    filepaths=$(git ls-files $1)
    for filepath in ${filepaths[@]}; do
        filename=$(basename $filepath)
        if [[ $filename != "README.md" ]]; then
            extension="${filename##*.}"
            echo '```'$extension >> $outputFile
            cat $filepath >> $outputFile
            echo '```' >> $outputFile
        fi

    done
}

export -f gen

targets=$(git ls-files ./codeforces | xargs dirname | uniq)
for target in ${targets[@]}; do
    gen $target
done

targets=$(git ls-files ./atcoder | xargs dirname | uniq)
for target in ${targets[@]}; do
    gen $target
done
