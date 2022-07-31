
def Area(width=3.2, height=2.3):
    print("width == %f, height == %f" % (width, height))
    return (width * height)


print(Area())
print(Area(3.2))
print(Area(3.2, 2.3))
print(Area(height=2.3, width=3.2))
print(Area(3.2, height=2.3))
