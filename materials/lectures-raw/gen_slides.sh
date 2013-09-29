rootDir=`git rev-parse --show-cdup`
if [ "$rootDir" == "" ]; then
    rootDir="./"
fi

rawDir="$rootDir/materials/lectures-raw"
cd $rawDir

outDir="../../../devtools-course-html"

# Generating HTML
for file in *.md
do
    echo "Processing $file"
    filename=$(basename "$file")
    filename="${filename%.*}"
    filename="$outDir/$filename.html"

    if [ $file -nt $filename ]; then
        echo "Writing to $filename"
        pandoc -t slidy --self-contained -c ./style/slidy.css $file -o $filename
    else
        echo "Nothing new to generate..."
    fi
done