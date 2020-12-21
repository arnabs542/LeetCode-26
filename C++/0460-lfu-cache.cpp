// Tags: Amazon Design


/*
The main idea is to put all keys with the same frequency to a linked list
so the most recent one (at the tail) can be evicted.

minfreq is the smallest freqency so far
iters stores key's position in the linked list, key to list iterator
values stores key's value and freq, key to {value,freq}
keys stores key list for each freq, freq to key list
*/
