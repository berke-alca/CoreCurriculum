# 🌱 Growing Code — Python Fundamentals Through Garden Data

My first Python project at **[42 Heilbronn](https://www.42heilbronn.de/)**.
After the C projects of the Common Core, this project introduces the core syntax and semantics of Python 3 through small community-garden scenarios.

---

## 📋 About the project

Each exercise is a single Python file that contains **only one function** (no main program, no top-level code).
The functions handle their own input and output and are imported and tested separately.

**Constraints**

- Python **3.10+**
- Code must pass the **flake8** linter
- **Type hints** required in exercise 7 and checked with **mypy**
- Only the functions listed for each exercise may be used

---

## 📂 Exercises

| Ex | File | Concept | Description |
|----|------|---------|-------------|
| 00 | `ft_hello_garden.py` | Functions, `print()` | Prints a welcome message |
| 01 | `ft_garden_name.py` | `input()`, variables, f-strings | Reads a garden name and prints a status |
| 02 | `ft_plot_area.py` | Type conversion with `int()` | Calculates the area of a rectangular plot |
| 03 | `ft_harvest_total.py` | Arithmetic | Sums the harvest of three days |
| 04 | `ft_plant_age.py` | `if` / `else` | Checks if a plant is ready to harvest |
| 05 | `ft_water_reminder.py` | Conditions | Reminds you to water the plants |
| 06 | `ft_count_harvest_iterative.py`<br>`ft_count_harvest_recursive.py` | Loops, recursion, helper functions | Counts the days until harvest, iteratively and recursively |
| 07 | `ft_seed_inventory.py` | Type hints, string methods, `if` / `elif` / `else` | Displays seed inventory in different units |

---

## 🗂️ Structure

```
.
├── ex0/ft_hello_garden.py
├── ex1/ft_garden_name.py
├── ex2/ft_plot_area.py
├── ex3/ft_harvest_total.py
├── ex4/ft_plant_age.py
├── ex5/ft_water_reminder.py
├── ex6/ft_count_harvest_iterative.py
├── ex6/ft_count_harvest_recursive.py
└── ex7/ft_seed_inventory.py
```

---

## ⚙️ Requirements

- Python 3.10 or newer
- flake8 and mypy

```bash
python3 -m pip install flake8 mypy
```

---

## ▶️ Usage

Each file only defines a function, so running it directly prints nothing.
Import the function and call it instead, from inside the exercise folder:

```bash
cd ex2
python3 -c "from ft_plot_area import ft_plot_area; ft_plot_area()"
```

```
Enter length: 5
Enter width: 3
Plot area: 15
```

Exercise 7 takes arguments:

```bash
cd ex7
python3 -c "from ft_seed_inventory import ft_seed_inventory; ft_seed_inventory('tomato', 15, 'packets')"
```

```
Tomato seeds: 15 packets available
```

> On Windows, use `python` instead of `python3`.

---

## ✅ Code quality

```bash
flake8 .
mypy ex7/ft_seed_inventory.py
```

---

## 🧠 What I learned

Coming from C, the biggest differences were:

- **No compilation.** The interpreter runs a file top to bottom, so no `main()` is needed.
- **Indentation is syntax.** Blocks are defined by indentation, not by `{}`.
- **No type declarations.** Variables are created by assignment; type hints are optional but checkable with mypy.
- **`input()` always returns a string.** It must be converted with `int()` before doing math.
- **Strings are objects.** They have built-in methods like `.capitalize()`, and they are compared with `==` instead of `strcmp`.
- **Importing runs the file.** Any top-level code executes on `import`, which is why each file contains only a function.
- **Recursion with helper functions.** A function that calls `input()` should not call itself, so the recursion happens in a separate helper.

---

## 👤 Author

**Berke** — student at 42 Heilbronn (`balca`)
GitHub: [berke-alca](https://github.com/berke-alca)