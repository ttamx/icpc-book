# Stress test: gen takes a seed (mt19937 rng(atoi(argv[1]))),
# sol and brute read stdin. Stops at the first difference.
for((i=1;;i++)); do
    ./gen $i > in
    ./sol < in > out1
    ./brute < in > out2
    if ! cmp -s out1 out2; then
        echo "WA on seed $i"; cat in; break
    fi
    [ $((i%100)) -eq 0 ] && echo "$i ok"
done
