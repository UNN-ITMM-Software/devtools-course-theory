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

    echo "Writing to $filename"
    pandoc -t slidy --self-contained -c ./style/slidy.css $file -o $filename
	# -i incremental lists
done