

/*
Time: O(2^n)
Naive Bfs solution
For each position we have two choices - either accelerate or reverse. So we can keep tack of
all possible positions of the racecar after n instructions and return the smallest n such that
the target position is reached.

Futher observations reveal that there may be overlapping among intermediate states so we can
memoize visited state (each state is characterized by car position and speed.)
*/