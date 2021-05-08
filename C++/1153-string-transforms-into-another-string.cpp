// Tags: Graph Google Premium
// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2)
            return true;
        unordered_map<char, char> transform;
        for (int i = 0; i < str1.length(); ++i) {
            if (transform.count(str1[i]) && transform[str1[i]] != str2[i])
                return false;
            transform[str1[i]] = str2[i];
        }
        return unordered_set<char>(str2.begin(), str2.end()).size() < 26;
    }
};
/*
1. Scan str1 and str2 at the same time, record the trasform mapping into
   a map.

2. If same character transforms to two different characters (can't have
   multiple outgoing edges), return false.

Transformation cases:
* Tranformation of linked list (a -> b -> c)
    eg str1 = "ab", str1 = "bc". Here we can do the tranformation from end to begin
    i.e. b -> c then a -> b
* Transformation of cycle (a -> c -> e -> a)
    eg str1 = "ace", str2 = "cea". Here we can use a tmp char first to break the cycle,
    then we can process same as in previous case
    i.e step 1: e -> tmp (f), c -> e, a -> c
        step 2: tmp (f) -> a

3. In the second case, there should be atleast one character that is unused to use it as the
   tmp for transformation. So, we also need to check if the number of used characters is < 26.
   (We just check this for str2 as if two different characters map to the same character, they
    can be combined into one group using one of them a tmp character.
    eg. str1 = "abcd", str2 = "bcdb"
        step 1: d -> tmp (a), c -> d, b -> c
        step 2: a -> b)

Note:
The problem is similar to 0205-isomorphic-strings with a catch that multiple characters
can map to same character (can have multiple incoming edges).
e.g. in str1 = "ac", str2 = "bb". we can transform both a and c to b.

If this was not the case, we'd have considered both these tranformation cases with the
approach of recording last positions.
*/
