
NR <= 2 { next }

{
    last = $1
    first = $2

    s1 = (NF >= 3 ? $3 : "--")
    s2 = (NF >= 4 ? $4 : "--")
    s3 = (NF >= 5 ? $5 : "--")

    if (NF < 5) {
        grade = "F"
        note = " (missing scores)"
    }
    else {
        avg = ($3 + $4 + $5) / 3

        if (avg >= 89.5)
            grade = "A"
        else if (avg >= 79.5)
            grade = "B"
        else if (avg >= 69.5)
            grade = "C"
        else if (avg >= 59.5)
	            grade = "D"
        else
            grade = "F"

        note = ""
    }

    printf "%-12s %-10s %3s %3s %3s %s%s\n", last, first, s1, s2, s3, grade, note
}
