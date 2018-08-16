function gen(){
    echo "[GEN]" docs/$1.md
            
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

function index(){
    cp $1/README.md docs/$1/README.md
    echo  >> docs/$1/README.md
    echo "## Solutions" >> docs/$1/README.md
    filepaths=$(find docs/$1 | grep md | sort)
    for filepath in ${filepaths[@]}; do
        pref="docs/$1/"
        len=${#pref}
        text=${filepath:len:-3}
        if [[ "$text" != "README" ]]; then
            echo "+ ["$text"]("$text".md)" >> docs/$1/README.md
        fi
    done
}

cp README.md docs/README.md
echo "" >> docs/README.md
echo "## Solved Problems" >> docs/README.md

targets=$(git ls-files ./codeforces | xargs dirname | sort --unique)
for target in ${targets[@]}; do
    if [[ "$target" != "codeforces" ]]; then
        gen $target
    fi
done
index codeforces
echo "+ [codeforces](codeforces/README.md)" >> docs/README.md

targets=$(git ls-files ./atcoder | xargs dirname | sort --unique)
for target in ${targets[@]}; do
    if [[ "$target" != "atcoder" ]]; then
        gen $target
    fi
done
index atcoder
echo "+ [atcoder](atcoder/README.md)" >> docs/README.md
