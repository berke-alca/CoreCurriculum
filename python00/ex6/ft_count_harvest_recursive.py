def count(day: int, days: int) -> None:
    if day > days:
        return
    print(f"Day {day}")
    count(day + 1, days)


def ft_count_harvest_recursive() -> None:
    days = int(input("Days until harvest: "))
    count(1, days)
    print("Harvest time!")
