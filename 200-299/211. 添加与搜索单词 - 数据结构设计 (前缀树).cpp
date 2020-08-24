#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/
// 用前缀树，正则表达式.用回溯进行匹配
class WordDictionary {
public:
    struct Trie{
        bool isEnd;
        Trie* next[26];
        Trie(){
            isEnd=false;
            for(int i=0;i<26;i++) next[i]=NULL;
        }
    };
    Trie* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n=word.length();
        Trie* node=root;
        for(int i=0;i<n;i++){
            int idx=word[i]-'a';
            if(node->next[idx]==NULL) node->next[idx]=new Trie();
            node=node->next[idx];
        }
        node->isEnd=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return subSearch(root, word);
    }
    bool subSearch(Trie* p, string word){
        if(p==NULL) return false;
        int n=word.length();
        for(int i=0;i<n;i++){
            if(word[i]=='.'){
                for(int j=0;j<26;j++){
                    if(subSearch(p->next[j], word.substr(i+1))) return true;
                }
                return false;
            }
            int idx=word[i]-'a';
            if(p->next[idx]==NULL) return false;
            p=p->next[idx];
        }
        return p->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */