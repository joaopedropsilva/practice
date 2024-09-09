def fibo(n):
    if n < 2:
        return n

    return fibo(n - 1) + fibo(n - 2)


def main():
    print(f'fibo(7): {fibo(7)}')


if __name__ == "__main__":
    main()

