#!/bin/bash

OUT=$(echo "48.0000,2.0000->47.9960,2.0195" | $1 test2.csv)
(echo "$OUT" | awk 'BEGIN {ret=1} {d=$1 - 120.447; if (d < 0.005 && d > -0.005) { print "OK"; ret = 0; }} END {exit ret}') || echo "FAILED"
