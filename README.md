Output:

./1d
pp[0] points to value: 0
pp[0] points to value: 0x5646a589f2d0
pp[1] points to value: 10
pp[1] points to value: 0x5646a589f2f0
pp[2] points to value: 20
pp[2] points to value: 0x5646a589f310
pp[3] points to value: 30
pp[3] points to value: 0x5646a589f330
pp[4] points to value: 40
pp[4] points to value: 0x5646a589f350
pp[5] points to value: 0

./2d
  0   1   2   3 0x560b3b4fb2a0 0x560b3b4fb2c0
  4   5   6   7 0x560b3b4fb2a8 0x560b3b4fb2e0
  8   9  10  11 0x560b3b4fb2b0 0x560b3b4fb300

array_1d.c
Example representation.
pp (int**) ──┬──► [0x55a1f3c1e2a0] ──► int: 0
             ├──► [0x55a1f3c1e2c0] ──► int: 10
             ├──► [0x55a1f3c1e2e0] ──► int: 20
             ├──► [0x55a1f3c1e300] ──► int: 30
             └──► [0x55a1f3c1e320] ──► int: 40


pp:
Address:0x1234
value:0x5646a589f2d0 => it acts as the base address of the array.

So array is created from 0x5646a589f2d0 ... 0x5646a589f350

if you deference pp i.e *pp or *(pp+0) you get the base address of the array 0x5646a589f2d0.
*(pp+1) gives the send address of the array 0x5646a589f2f0.

If you want to geth the value, then you need to deference twice i.e **pp or **(pp+0) to get 0, **(pp+1) to get 10

0x5646a589f2d0 - 0x5646a589f2f0 = 0x20 = 32 bytes. actually it should be 8 bytes on 64 bit machine. i.e. size of each integer. But for the performace reasons it is 32.
Dont get confused!!! Samll allocations are rounded up to 32B


array_2d.c:



