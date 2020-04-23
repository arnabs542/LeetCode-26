// Time O(n)
// Space O(n)
class Solution {
public:
    bool isValid(string s) {
        const unordered_map<char, char> symbol_pair { {')','('}, {'}','{'}, {']','['} };
        // closing brackets
        stack<char> parantheses;

        for (const auto &c : s){
            const auto &it = symbol_pair.find(c);
            // constant iterator
            if (it == symbol_pair.cend()){
                // not a closing bracket
                parantheses.emplace(c);
                // push
            }
            else{
                // is a closing bracket
                if(parantheses.empty() || parantheses.top() != it->second){
                    return false;
                }
                parantheses.pop();
            }
        }

        return parantheses.empty();
    }
};


// Time O(n)
// Space O(n)
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> symbol_pair { {')','('}, {'}','{'}, {']','['} };
        // closing brackets
        stack<char> parantheses;

        for (const auto &c : s){
            auto it = symbol_pair.find(c);
            if (it == symbol_pair.end()){
                // not a closing bracket
                parantheses.push(c);
                // push
            }
            else{
                // is a closing bracket
                if(parantheses.empty() || parantheses.top() != symbol_pair[c]){
                    return false;
                }
                parantheses.pop();
            }
        }

        return parantheses.empty();
    }
};
