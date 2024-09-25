def count_call(calls):
    def wrapper(func):
        def func_caller():
            # using nonlocal does not work
            # calls is passed by value not
            # by reference probably
            nonlocal calls
            calls += 1

            return func()
        return func_caller

    return wrapper


if __name__ == "__main__":
    calls = 0
    rec = 0

    @count_call(calls)
    def recurse():
        global rec
        if rec == 5:
            return rec

        rec += 1
        return recurse()

    print(f"calls: {calls}")
    print(f"total: {recurse()}")


