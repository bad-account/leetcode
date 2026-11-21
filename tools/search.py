import argparse
import json
from pathlib import Path

# Cesty relativně k umístění tohoto skriptu
TOOLS_DIR = Path(__file__).parent
REPO_ROOT = TOOLS_DIR.parent
METADATA_PATH = TOOLS_DIR / "metadata.json"
PROBLEMS_DIR_NAME = "problems"

DIFFICULTY_ORDER = {"Easy": 1, "Medium": 2, "Hard": 3}


def load_data():
    if not METADATA_PATH.exists():
        print(f"Chyba: Soubor {METADATA_PATH} nebyl nalezen.")
        return []
    with open(METADATA_PATH, "r", encoding="utf-8") as f:
        return json.load(f)


def main():
    parser = argparse.ArgumentParser(description="Vyhledávání a řazení LeetCode úloh")
    parser.add_argument("-d", "--difficulty", choices=["Easy", "Medium", "Hard"], help="Filtr podle obtížnosti")
    parser.add_argument("-t", "--tag", help="Filtr podle tagu (např. Array, Math, Tree)")
    parser.add_argument("-l", "--lang", help="Filtr podle jazyka (např. cpp, py, rs)")
    parser.add_argument("-s", "--sort", choices=["id", "title", "difficulty"], default="id", help="Řazení výsledků")
    parser.add_argument("-p", "--paths", action="store_true", help="Zobrazí relativní cesty ke složkám úloh")
    args = parser.parse_args()

    problems = load_data()

    # Filtrování
    if args.difficulty:
        problems = [p for p in problems if p["difficulty"].lower() == args.difficulty.lower()]
    if args.tag:
        problems = [p for p in problems if any(args.tag.lower() == t.lower() for t in p["tags"])]
    if args.lang:
        problems = [p for p in problems if any(args.lang.lower() == l.lower() for l in p["languages"])]

    # Řazení
    if args.sort == "id":
        problems.sort(key=lambda p: p["id"])
    elif args.sort == "title":
        problems.sort(key=lambda p: p["title"].lower())
    elif args.sort == "difficulty":
        problems.sort(key=lambda p: (DIFFICULTY_ORDER.get(p["difficulty"], 99), p["id"]))

    if not problems:
        print("Žádné úlohy neodpovídají zadaným filtrům.")
        return

    # Výpis výsledků
    if args.paths:
        for p in problems:
            folder_name = f"{p['id']}. {p['title']}"
            print(f"{PROBLEMS_DIR_NAME}/{folder_name}")
        return

    print(f"{'ID':<5} | {'Název':<45} | {'Obtížnost':<9} | {'Jazyky':<10} | {'Tagy'}")
    print("-" * 105)
    for p in problems:
        langs = ", ".join(p["languages"])
        tags = ", ".join(p["tags"])
        print(f"{p['id']:<5} | {p['title']:<45} | {p['difficulty']:<9} | {langs:<10} | {tags}")


if __name__ == "__main__":
    main()