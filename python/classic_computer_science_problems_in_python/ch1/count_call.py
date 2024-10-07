def count_call(info):
    def wrapper(func):
        def func_caller():
            # using nonlocal does not work
            # calls is passed by value not
            # by reference probably
            #
            # nonlocal calls
            # calls += 1

            # even passing a dict
            #  this is not possible
            info["calls"] += 1

            return func()
        return func_caller

    return wrapper


def cc(func):
    def wrp():
        # pass by reference here and it should work
        def caller(calls):
            return func()

        return caller

    return wrp

if __name__ == "__main__":
    info  = {"calls": 0}
    rec = 0

    #@count_call(info)
    @cc
    def prepare():
        pass

    def recurse():
        global rec
        if rec == 5:
            return rec

        rec += 1
        return recurse()

    print(recurse())

    #print(f"calls: {info["calls"]}")
    #print(f"total: {recurse()}")


