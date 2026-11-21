# LeetCode Solutions

A personal archive of my solutions to problems from [LeetCode](https://leetcode.com/). Solutions are written primarily in **C++**, while the repository structure is designed to seamlessly support additional programming languages (such as Python or Rust) in the future.

## Repository Structure

```text
leetcode/
├── problems/               # Problem directories (named exactly as on LeetCode)
│   └── 66. Plus One/
│       ├── main.cpp        # Source code of the solution
│       └── notes.md        # Optional notes on approach and time/space complexity
├── tools/                  # Utilities and metadata for managing and searching problems
│   ├── metadata.json       # Central metadata database (ID, title, difficulty, tags, languages)
│   └── search.py           # CLI script for filtering and sorting problems in the terminal
├── overview.md             # Summary overview of solved problems
├── LICENSE                 # Repository license
└── README.md               # Repository documentation
```

## Components Overview

* **`problems/`** – Contains individual problem directories formatted as `<ID>. <Problem Title>`. Each folder holds the solution source files (`main.cpp`, `main.py`, `main.rs`, etc.) and an optional `notes.md` file with personal notes.
* **`tools/metadata.json`** – A central JSON file storing structured metadata for all solved problems (`id`, `title`, `difficulty`, `tags`, `languages`). Acts as the single source of truth for local CLI utilities.
* **`tools/search.py`** – A zero-dependency Python 3 CLI tool for quickly filtering and sorting solved problems by tags, difficulty, or programming language directly from the terminal.
* **`overview.md`** – A high-level summary table of solved problems.

## Searching and Filtering (`search.py`)

Run the search script from the repository root using Python 3:

```bash
python tools/search.py [OPTIONS]
```

### Available Options

| Flag | Long Flag | Description | Example |
| :--- | :--- | :--- | :--- |
| `-d` | `--difficulty` | Filter by difficulty (`Easy`, `Medium`, `Hard`) | `-d Easy` |
| `-t` | `--tag` | Filter by a specific LeetCode topic tag | `-t Array` |
| `-l` | `--lang` | Filter by programming language (`cpp`, `py`, `rs`) | `-l cpp` |
| `-s` | `--sort` | Sort results by `id`, `title`, or `difficulty` (default: `id`) | `-s difficulty` |
| `-p` | `--paths` | Output only relative directory paths of matching problems | `-p` |

### Usage Examples

```bash
# List all solved problems sorted by ID
python tools/search.py

# Find all Easy problems tagged with Array
python tools/search.py -d Easy -t Array

# List all C++ solutions sorted by difficulty
python tools/search.py -l cpp -s difficulty

# Get only directory paths for problems tagged with String
python tools/search.py -t String -p
```

## Adding a New Problem

1. Create a new directory inside `problems/` using the exact problem title from LeetCode (e.g., `1. Two Sum`).
2. Add your solution file (e.g., `main.cpp`) and an optional `notes.md`.
3. Add a corresponding entry to `tools/metadata.json`.