#!/usr/bin/env python

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
import sys, datetime, csv

if len(sys.argv) <= 1:
    print "Not enough parameters"
    exit(1)

# parse data
with open(sys.argv[1], "r") as f:
    lines = [str.strip(line) for line in f.readlines()]
    dates = []
    views = []
    for i in range(0, len(lines), 3):
        date = " ".join(str.split(lines[i])[1:4])
        dates.append(datetime.datetime.strptime(date, "%d %b %Y"))
        views.append(int(lines[i+1]))

# write to .csv
with open('data.csv', 'w') as f:
    csv.writer(f, delimiter=',').writerows(zip(dates, views))

plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%Y-%m-%d'))
plt.gca().xaxis.set_major_locator(mdates.WeekdayLocator())
plt.plot(dates, views)
plt.show()
