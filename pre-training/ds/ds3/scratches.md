# Hash Table and Function
Hash function is used to calculate where will a certain data be stored in the hash table.
Why on earth would we use a hash table and function? Because a hash function can be used to find a data
that is located on the hash table without looping the whole hash table. This would be more effective when working 
with god-knows what big of a data because we don't need to iterate the hash table.

## Collision handling
There are a few types of collision handling 

### Linear Probing
Let a scenario where data1 is in the i-th index of the hash table and based on the same hashkey data2 should be addressed
to the same index. In this case, linear probing works by checking the i+1-th index of the hash table; if it is empty, then data2 will inhabit that index. If not, it will continue to probe the hash table and when it reaches the end of the hash table,
it will go to the 0th indexand continue until it finds an empty index.

### Chaining 
Let a scenario where a hash table is already packed with data, what chaining does is chain an index from the hash table to a 
certain amount of data. It's quite literally a linked list inside every index of the hash table. 
