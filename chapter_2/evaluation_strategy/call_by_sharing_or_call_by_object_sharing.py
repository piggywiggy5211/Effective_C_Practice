def add_one(a: int):
    print(f" mem address before modify a = {hex(id(a))}")
    a += 1  # create new object
    print(f" mem address after modify a = {hex(id(a))}")


def add_element(l: list):
    print(f" mem address before modify l = {hex(id(l))}")
    l.append(4)  # modifies original list
    print(f" mem address after modify l = {hex(id(l))}")


a = 1
print(f"mem address a = {hex(id(a))}")
print(f"before call add_one a = {a}")
add_one(a)
print(f"after call add_one a = {a}")

main_list = [0, 1, 2, 3]
print(f"mem address main_list = {hex(id(main_list))}")
print(f"before call add_element main_list = {main_list}")
add_element(main_list)
print(f"before call add_element main_list = {main_list}")
