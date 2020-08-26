
class MyClass1:
  def __init__(self):
    self.num1 = 1
    self.num2 = 3
    self.num3 = 3

  def __str__(self):
      rep = "num1: " + str(self.num1) + ", "
      rep += "num2: " + str(self.num2) + ", "
      rep += "num3: " + str(self.num3) + "\n"
      return rep

def myGenereator():
  myc1 = MyClass1()

  yield 1 
  yield "dsf"
  yield myc1
  yield myc1

generator1 = myGenereator()

generator1
print(type(generator1))

print( next(generator1) )
print( next(generator1) )
print( next(generator1).num2 )
print( next(generator1) )
