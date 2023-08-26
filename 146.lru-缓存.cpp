/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 *
 * https://leetcode.cn/problems/lru-cache/description/
 *
 * algorithms
 * Medium (53.47%)
 * Likes:    2826
 * Dislikes: 0
 * Total Accepted:    515.9K
 * Total Submissions: 964.8K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
 * 
 * 实现 LRUCache 类：
 * 
 * 
 * 
 * 
 * LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 * void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组
 * key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
 * 
 * 
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * 输出
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * 解释
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // 缓存是 {1=1}
 * lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
 * lRUCache.get(1);    // 返回 1
 * lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
 * lRUCache.get(2);    // 返回 -1 (未找到)
 * lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
 * lRUCache.get(1);    // 返回 -1 (未找到)
 * lRUCache.get(3);    // 返回 3
 * lRUCache.get(4);    // 返回 4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= capacity <= 3000
 * 0 <= key <= 10000
 * 0 <= value <= 10^5
 * 最多调用 2 * 10^5 次 get 和 put
 * 
 * 
 */

// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) : cap_(capacity) { }
    
    int get(int key) {
      auto find = keyMap_.find(key);
      if (find == keyMap_.end()) {
        return -1;
      }
      auto pair = *(find->second);
      val_.erase(find->second);
      keyMap_[key] = val_.insert(val_.begin(), pair);
      return pair.second;

      ////std::cout << "get key: " << key << std::endl;
      //auto findIter = keyMap_.find(key);
      //if (findIter == keyMap_.end()) {
      //  return -1;
      //}
      //int value = findIter->second->second;
      ////std::cout << "get key: " << key << " value: " << value << std::endl;
      //put(key, value);
      //return value;
    }
    
    void put(int key, int value) {
      std::cout << "put key " << key << ", value " << value << endl;
      auto find = keyMap_.find(key);
      if (find != keyMap_.end()) {
        val_.erase(find->second);
      }
      
      if (val_.size() >= cap_) {
        //cout << val_.back().second << endl;
        keyMap_.erase(keyMap_.find(val_.back().first));
        val_.pop_back();
      }

      keyMap_[key] = val_.insert(val_.begin(), make_pair(key, value));
      return;

      // auto findIter = keyMap_.find(key);
      // if (findIter == keyMap_.end()) {
      //   if (val_.size() == cap_) {
      //     int curkey = val_.back().first;
      //     findIter = keyMap_.find(curkey);
      //   }
      // }
      // // 删除原有数据
      // if (findIter != keyMap_.end()) {
      //   val_.erase(findIter->second);
      //   keyMap_.erase(findIter);
      // }
      // // 插入新数据
      // val_.push_front(std::make_pair(key, value));
      // keyMap_[key] = val_.begin();

      //std::cout << "put" << std::endl;
      //for (auto val : val_) {
      //  //std::cout << val.first << " , " << val.second->second << std::endl;
      //  std::cout << val.first << " , " << val.second << std::endl;
      //}
    }

    int cap_ = 0;
    unordered_map<int, list<pair<int, int>>::iterator> keyMap_;
    list<pair<int, int>> val_;  // for key, value
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

