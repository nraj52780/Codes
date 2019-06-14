#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
   public :
       char data;
       TrieNode* children[26];
       bool isTerminal;

       TrieNode(char data)
       {
           this->data=data;
           for(int i=0;i<26;i++)
            children[i]=NULL;

           isTerminal=false;
       }

};

class Trie{

   TrieNode *root;
   public:

    Trie()
    {
        root=new TrieNode('/0');
    }

    void insertWord(TrieNode *root, string word)
    {

        int n=word.length();
        TrieNode *temp=root;
        for(int i=0;i<n;i++)
        {
            int idx=word[i]-'a';
            if(!temp->children[idx])
                temp->children[idx]=new TrieNode(word[i]);

            temp=temp->children[idx];
        }
        temp->isTerminal=true;
    }

    bool search(TrieNode *root,string word)
    {
        int n=word.length();
        TrieNode *temp=root;
        for(int i=0;i<n;i++)
        {
            int idx=word[i]-'a';
            if(!temp->children[idx])
                return false;

            temp=temp->children[idx];
        }

        return temp->isTerminal==true;
    }
    void removeWord(TrieNode* root,string word)
    {
        if(word.length()==0)
        {
            root->isTerminal=false;
            return;
        }

        TrieNode *child;
        int idx=word[0]-'a';
        if(root->children[idx]!=NULL)
        {
            child=root->children[idx];
        }
        else return;

        removeWord(child,word.substr(1));
        if(child->isTerminal==false)
        {
            for(int i=0;i<26;i++)
            {
                if(child->children[i]!=NULL)
                    return;
            }
            delete child;
            root->children[idx]=NULL;
        }
    }
    // for users
    void insertWord(string word) {
        insertWord(root, word);
    }


    bool search(string word) {
        // Write your code here
        bool res=search(root,word);
        return res;
    }

    void removeWord(string word)
    {
        removeWord(root,word);

    }

};

int main() {
    Trie t;
	t.insertWord("and");
	t.insertWord("are");
	t.insertWord("dot");

	cout << t.search("and") << endl;
    t.removeWord("and");
	cout << t.search("and") << endl;
    cout << t.search("are") << endl;

}
