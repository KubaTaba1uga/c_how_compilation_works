First let's consider dummy module. It's role is to do nothing besides being called from other module.
So to create sufficient testing scenarios we will need:
1. test_dummy_module_proper.c
2. dummy_module - this module is being called by caller module
3. caller_module - this module calls dummy module

Example 1 is all about showing that if test is properly configured, static variable in dummy_module can be incremented by caller_module.

Example 2 is all about showing that if test properly used we can manipulate static variable without consequences.

Example 3 is all about showing scenario where static variable duplication (caused by included .c file) leads to desynchronization in code.
There is one code in test file which is not incremented by caller_module and there is the other code which is. How is this possible? Wtf?
This is pretty easy to solve, each file just have it's own counter variable. `test_dummy_module_proper.c` has it's own counter and it's own
 increment counter function, so when it calls increment function dirtectly our let's call internal counter (one that belongs to `test_dummy_module_proper.c`) is being incremented. However all other code operates on different copy of counter and increment counter function (the good copy
 which should be called original, cause this is factual var in dummy_module), that's why calling function from caller module gives different output, because we have symbol duplicatoion which is solved by static keyword into two variasbles.
 called from

We need to exzamine how symbols look in selftest file and compare examples with each other.




