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
    curl "https://www.youtube.com/watch?v=$ID" 2>/dev/null | \
        # retrieved data is in HTML/JSON, but we use a simple regex to get the
        # number of views
        sed -n 's/\(.*\)"view_count":"\([^"]*\)"\(.*\)/\2/p' >>$ID.views

    # dump newline
    echo -e "\n" >>$ID.views
done
