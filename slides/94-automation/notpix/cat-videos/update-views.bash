# this script is intended to be run by the cron utility for
# incremental update of the number of views of downloaded videos

# Edit the cron table:
# $ crontab -e

# Repeat every minute:
# */1 * * * * echo "hello" >>/tmp/hello-from-cron

# $1 = absolute path to directory with videos, downloaded by add-video.sh
cd $1

for DATASET in $(ls -1 -d */) # for each directory
do
    # strip the 'extension' (which is an upload date)
    ID=${DATASET%.*}

    # dump current time in UTC
    date -u +%c >>$ID.views

    # dump the number of views
    curl "https://gdata.youtube.com/feeds/api/videos/$ID?v=2&alt=json" | \
        # retrieved data is in JSON, but we use a simple regex to get
        # the number of views
        sed 's/\(.*\)"viewCount":"\([^"]*\)"\(.*\)/\2/' >>$ID.views

    # dump newline
    echo -e "\n" >>$ID.views
done
