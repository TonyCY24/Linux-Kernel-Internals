set datafile separator ","
set key autotitle columnhead
set xlabel "bucket"
set ylabel "count"
set terminal png size 1200,1600

set output "hash_distribution.png"
set multiplot layout 4,1 title "Hash Distribution Comparison"

set title "GOLDEN_RATIO_32 (0x61C88647)"
plot "hash_32.csv" using 1:2 with lines notitle

set title "0x80000000"
plot "hash_32.csv" using 1:3 with lines notitle

set title "0x12345678"
plot "hash_32.csv" using 1:4 with lines notitle

set title "0x54061094"
plot "hash_32.csv" using 1:5 with lines notitle

unset multiplot