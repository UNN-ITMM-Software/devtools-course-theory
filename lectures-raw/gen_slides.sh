outDir="../lectures-html"
currDir=`dirname $0`

# Generating HTML
for file in $currDir/*.md
do
    echo "Processing $file"
    filename=$(basename "$file")
    filename="${filename%.*}"
    filename="$currDir/$outDir/$filename.html"

    echo "Writing to $filename"
    #./Markdown.pl $file > $filename
    pandoc -t slidy --self-contained -c $currDir/style/slidy.css $file -o $filename
	# -i incremental lists
done