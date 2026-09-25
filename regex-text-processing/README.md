# Regular Expression Text Processing

A Linux command-line exercise developed as part of my Systems Programming coursework. This project uses regular expressions to search a text dataset and extract different types of structured information.

## 🔍 What It Does

Regular expressions were used to identify and extract:

- Email-like patterns
- Lines containing numerical data
- Unix-style file paths
- Dates using `/` or `-` separators

## 🛠️ Tools & Concepts

- Linux
- Command Line
- Regular Expressions (Regex)
- `egrep`
- Pattern Matching
- Text Processing
- File Redirection
- Terminal Session Recording

## 💻 Example Patterns

### Email Addresses

```bash
egrep '[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}' datafile.txt
```

### Lines Containing Numbers

```bash
egrep '[0-9]' datafile.txt
```

### Unix-Style File Paths

```bash
egrep '(^|[[:space:]])(/[A-Za-z0-9._-]+)+' datafile.txt
```

### Dates

```bash
egrep '((0[1-9]|1[0-2])/(0[1-9]|[12][0-9]|3[01])/([0-9]{2}|[0-9]{4})|(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])-([0-9]{2}|[0-9]{4}))' datafile.txt
```

## 📚 What I Learned

This exercise strengthened my understanding of regular expressions and Linux command-line text processing. I practiced designing patterns for different data formats, filtering text files, redirecting command output, and working within a Linux terminal environment.

It also helped me understand how regular expressions can be used to locate and extract structured information from unstructured text.
