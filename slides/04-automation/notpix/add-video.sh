# $1 = youtube video ID
# dependencies: youtube-dl, avconv (ffmpeg), ImageMagick (convert)

set -e # exit on error
set -u # disallow unset variables usage

mkdir -p cats
cd cats

# download video with the specified ID
youtube-dl https://www.youtube.com/watch?v=$1 -o "$1.%(upload_date)s.%(ext)s"

# retrieve the downloaded filename
FILENAME=$(ls -1 $1*)
# strip extension
DIR=${FILENAME%.*}

# create directory for video frames
mkdir $DIR

# transcode the downloaded file to .jpg images with resize
avconv -i $FILENAME -f image2 -s 320x240 $DIR/%07d.jpg
rm $FILENAME

# convert each image in the directory to grayscale
cd $DIR
for IMAGE in $(ls -1)
do
    convert -type Grayscale $IMAGE g$IMAGE
    rm $IMAGE
done
