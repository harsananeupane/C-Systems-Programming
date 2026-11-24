NR > 1 {
    cot = $1 % 360
    if (cot < 0)
        cot += 360
    printf "%10d\t%3d\n", $1, cot
}
