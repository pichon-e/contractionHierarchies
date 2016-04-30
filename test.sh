#!/bin/bash

OUT=$(echo "-12.8946,45.1422->-12.7794,45.2274" | $1 data.csv)
(echo "$OUT" | awk 'BEGIN {ret=1} {d=$1 - 6630.65; if (d < 0.005 && d > -0.005) { print "OK"; ret = 0; }} END {exit ret}') || echo "FAILED"
