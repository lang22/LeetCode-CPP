/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */
#include <iostream>
#include <vector>
#include <set>
#include <functional>
using namespace std;

// @lc code=start
class Solution {
public:
    int ds[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<char>> board;
    bool dfs(int i, int j, string word, int k){
        if(i < 0 || i == board.size() || j < 0 || j == board[0].size() || k > 10 || board[i][j] != word[k]){
            return false;
        }
        if(k == word.length()-1){
            return true;
        }
        char tmp = board[i][j]; // 暂存当前位置的符号
        board[i][j] = ' '; // 将已访问过的当前位置置空，防止后续递归再次返回该位置
        bool res = false;
        for(auto d : ds){ // 递归遍历当前位置的四个相邻位置
            if(dfs(i+d[0], j+d[1], word, k+1)){
                res = true;
                break;
            }
        }
        board[i][j] = tmp; // 归位
        return res;
    }
    vector<string> findWords(vector<vector<char>>& _board, vector<string>& words) {
        board = _board;
        vector<string> res;
        for(string word: words){
            bool flag = true;
            for(int i=0;i<board.size() && flag;++i){
                for(int j=0;j<board[0].size();++j){
                    if(dfs(i, j, word, 0)){
                        res.emplace_back(word);
                    }
                    if(!res.empty() && word == res.back()){
                        flag = false;
                        break;
                    } 
                }
                               
            }
             
        }
        return res;
    }
};
// @lc code=end
