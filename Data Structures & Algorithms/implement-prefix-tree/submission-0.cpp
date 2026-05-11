
class TrieNode{
    public:
    TrieNode*child[26];
    bool isend;
    TrieNode(){
        for (int i=0;i<26;i++){
            child[i]=nullptr;
            isend=false;
        }
    }
};
class PrefixTree {
public:
    TrieNode *root=new TrieNode();
    PrefixTree() {
        
    }
    
    void insert(string word) {
        TrieNode*temp=root;
        int n=word.length();
        for (int i=0;i<n;i++){
            int ch=word[i]-'a';
            if (!temp->child[ch])temp->child[ch]=new TrieNode();
            
            temp=temp->child[ch];
        }
        temp->isend=true;
    }
    
    bool search(string word) {
        TrieNode*temp=root;
        int n=word.length();
        for (int i=0;i<n;i++){
            int ch=word[i]-'a';
            if (!temp->child[ch])return false;
            
            temp=temp->child[ch];
        }
        if (temp->isend==true)return true;
        
        return false;
    }
    
    bool startsWith(string word) {
        // return false;
        TrieNode*temp=root;
        int n=word.length();
        for (int i=0;i<n;i++){
            int ch=word[i]-'a';
            if (!temp->child[ch])return false;
            
            temp=temp->child[ch];
        }
        
        return true;
    }
};
