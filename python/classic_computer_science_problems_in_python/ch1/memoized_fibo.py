def memoize(func):
    memo = {0: 0, 1: 1}

    def memo_wrapper(value):
        if value not in memo:
            global n_calls
            n_calls += 1
            memo[value] = func(value)

        return memo[value]

    return memo_wrapper

@memoize
def fibo(n):
    if n < 2:
        return n

    return fibo(n - 1) + fibo(n - 2)


# returning a count value from here 
# will demand another param in the decorator
def memoize_and_count(func):
    calls = 0

    def memoize(**kwargs):
        value = kwargs["value"]
        memo = kwargs["memo"]
        n_calls = calls

        if value not in memo:
            n_calls += 1
            memo[value] = func(value=value, memo=memo)

        return memo[value]

    return memoize


@memoize_and_count
def test(**kwargs):
    value = kwargs["value"]
    memo = kwargs["memo"]

    return test(value=value - 1, memo=memo) + test(value=value - 2, memo=memo)


print(test(value=7, memo={0: 0, 1: 1}))

