# SimpleNodeInTreeBenchmark
A project where I want to explore a trivial aproach to OOP nodes in a tree vs components (might be considered DOD).

## The Idea
I recently watched two talks about Data Oriented Design ( namely <https://youtu.be/rX0ItVEVjHc> and <https://youtu.be/yy8jQgmhbAU> ). So I was curious how much of a performance difference I could produce on current hardware with a trivial object oriented Node Tree (no pointer) vs a component based Tree.

## The Memory structures
See the `NCore.hpp` in NCore.

## The Result

### Example 1
On an AMD Ryzen 7 3700X limited to 4Ghz with 16 GB DDR4 memory at 3133Mhz Desktop PC with Windows 10.
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

### Example 2
On an AMD Ryzen 7 Pro 5850u with 16 GB on a Laptop with Pop OS 22.04 LTS
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
Update                                         100             1     23.2031 s 
                                        231.834 ms    231.695 ms    231.984 ms 
                                        738.905 us    669.026 us    850.222 us 
                                                                               

-------------------------------------------------------------------------------
Memory Aligned Global Matrix Update
-------------------------------------------------------------------------------
...
...............................................................................

benchmark name                       samples       iterations    est run time
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Update                                         100             1      11.693 s 
                                        112.188 ms    112.064 ms    112.345 ms 
                                        706.373 us    590.703 us    827.474 us 
                                                                               

===============================================================================
test cases: 3 | 3 passed
assertions: - none -
```
