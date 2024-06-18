# SimpleNodeInTreeBenchmark
A project where I want to explore a trivial aproach to OOP nodes in a tree vs components (might be considered DOD).

## The Idea
I recently watched two talks about Data Oriented Design ( namely <https://youtu.be/rX0ItVEVjHc> and <https://youtu.be/yy8jQgmhbAU> ). So I was curious how much of a performance difference I could produce on current hardware with a trivial object oriented Node Tree (no pointer) vs a component based Tree.

## The Memory structures
See the `NCore.hpp` in NCore.

## The Result

### Example 1
On an AMD 3700X limited to 4Ghz with 16 GB DDR4 memory at 3133Mhz Desktop PC. 
```
...
-------------------------------------------------------------------------------
Dynamic Nodes Global Matrix Update
-------------------------------------------------------------------------------
...
...............................................................................

benchmark name                       samples       iterations    est run time
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Update                                         100             1     50.5169 s
                                        491.852 ms    491.377 ms    492.396 ms
                                        2.58196 ms    2.28915 ms    2.94532 ms


-------------------------------------------------------------------------------
Memory Aligned Global Matrix Update
-------------------------------------------------------------------------------
...
...............................................................................

benchmark name                       samples       iterations    est run time
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Update                                         100             1     22.0599 s
                                        216.172 ms    216.035 ms    216.369 ms
                                        832.344 us     606.83 us    1.14586 ms


===============================================================================
test cases: 3 | 3 passed
assertions: - none -
```
