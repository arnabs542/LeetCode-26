// Tags: Design Amazon Premium Queue
// Time:  O(1) per move
// Space: O(s), s is the current length of the snake.
class SnakeGame {
    vector<vector<int>> food_;
    int height_, width_;
    int foodIdx;
    // can also use deque<vector<int>> snakeBody;
    // (each element represents a unit of body part with its coordinates)
    deque<int> snakeBody;
    // for searching body parts in O(1) time
    // (unordered_set doesn't support pair or vector as a key
    // therefore we encode row & col using a hash function)
    unordered_set<int> bodySet;
    int score;
    unordered_map<string, pair<int, int>> directions = {{"U", {-1, 0}}, {"L", {0, -1}},
                                                        {"R", {0, 1}}, {"D", {1, 0}}};
    // think of 2d matrix as a single long list of height*width elements
    int hash(int x, int y) {
        return x * width_ + y;
    }
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) 
        : height_{height},
        width_{width}, 
        food_(food), 
        foodIdx{0}, 
        snakeBody{0}, 
        bodySet{0}, 
        score{0} {
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        // case 0: game already over: do nothing
        if (score == -1)
            return -1;
        
        // compute new head
        // dehash and new add direction, then hash back
        int rowHead = snakeBody.front() / width_ + directions[direction].first;
        int colHead = snakeBody.front() % width_ + directions[direction].second;
        int head = hash(rowHead, colHead);
        
        // case 1: out of boundary or eating body
        // new head is legal to be in old tail's position, so remove tail from set
        bodySet.erase(snakeBody.back()); 
        if (rowHead < 0 || rowHead == height_ || colHead == width_ || colHead < 0 || bodySet.count(head))
            return score = -1;
        
        // add head to both set and deque
        bodySet.insert(head);
        snakeBody.push_front(head);
        
        // case2: eating food, keep tail, increase score, (add new head)
        if (foodIdx < food_.size() && food_[foodIdx][0] == rowHead && food_[foodIdx][1] == colHead) {
            ++foodIdx;
            bodySet.insert(snakeBody.back());
            return ++score;
        }
        
        // case3: normal move, (remove tail, add head)
        snakeBody.pop_back();
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */