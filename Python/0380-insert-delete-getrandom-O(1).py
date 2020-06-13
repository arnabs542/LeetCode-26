# Time:  O(1)
# Space: O(n)
from random import randint
class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._set = []
        self.getIndex = {}

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val in self.getIndex:
            return False;
        self._set.append(val)
        self.getIndex[val] = len(self._set) - 1
        return True

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val not in self.getIndex:
            return False
        # update index of the last element
        self.getIndex[self._set[-1]] = self.getIndex[val]
        # swap elements
        self._set[self.getIndex[val]], self._set[-1] = self._set[-1], self._set[self.getIndex[val]]

        self.getIndex.pop(val)
        self._set.pop()
        return True


    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        return self._set[randint(0, len(self._set) - 1)]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
