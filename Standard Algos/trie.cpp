/*
 * File:   main.cpp
 * Author: monishg
 *
 * Created on October 20, 2012, 5:12 PM
 */

#include <iostream>
#include <stack>

using namespace std;

template <class ValueType, unsigned int NUM_CHILDREN>
class Node
{
public:
    char mChar;
    ValueType mValue;

    int mNumChildren;
    Node* mChildren;

    bool mIsSeen;
    bool mIsWord;

    Node() // : mNumChildren(0), mChildren(NULL), mChar(0), mValue(NULL), mIsWord(false), mIsSeen(false) {
    {
        mChar = mNumChildren = 0;
        mChildren = NULL;
        mIsWord = mIsSeen = false;
    }

    void initChildNodes()
    {
        if (this->mChildren == NULL)
            mChildren = new Node<ValueType, NUM_CHILDREN>[NUM_CHILDREN];
    }

    ~Node()
    {
        if(this->mChildren)
            delete[] this->mChildren;
    }
};

template <class ValueType, unsigned int DISTINCT_CHAR_COUNT>
class Trie
{
    Node<ValueType, DISTINCT_CHAR_COUNT>* mRoot;
public:

    Trie()
    {
        mRoot = new Node<ValueType, DISTINCT_CHAR_COUNT > ();
    }

    //inserts value in the trie for the given key

    void insert(string key, ValueType value)
    {
        Node<ValueType, DISTINCT_CHAR_COUNT>* curNode = mRoot;
        for (unsigned index = 0; index < key.length(); index++)
        {
            char aChar = tolower(key[index]);
            if(curNode->mChildren == NULL)
                curNode->initChildNodes();
            curNode = curNode->mChildren + (aChar - 'a');

            curNode->mChar = aChar;
            curNode->mNumChildren++;
            curNode->mIsSeen = true;
        }
        curNode->mValue = value;
        curNode->mIsWord = true;
    }

    //checks if the key exists in the trie

    bool doesExists(string key)
    {
        Node<ValueType, DISTINCT_CHAR_COUNT>* curNode = mRoot;
        for (unsigned index = 0; index < key.length(); index++)
        {
            char aChar = tolower(key[index]);
            if(curNode->mChildren == NULL)
                return false;
            curNode = curNode->mChildren + (aChar - 'a');
            if (curNode == NULL || !curNode->mIsSeen  )
                return false;
        }
        return curNode->mIsWord;
    }

    //assumes key exists and returns value for the key

    ValueType lookup(string key)
    {
        Node<ValueType, DISTINCT_CHAR_COUNT>* curNode = mRoot;
        for (unsigned index = 0; index < key.length(); index++)
        {
            char aChar = tolower(key[index]);
            if (curNode->mChildren + aChar - 'a' == NULL)
                throw "Key " + key + " does not exist in the trie.";
            else
                curNode = curNode->mChildren + aChar - 'a';
        }
        return curNode->mValue;
    }

    //frees up the dynamic memory

    ~Trie()
    {
        if(mRoot!= NULL)
            delete mRoot;
    }
};

int main()
{
    //create a trie with char set of a to z small case.
    const unsigned int num = 26;
    Trie<string, num > t;

    //add some values
    t.insert("monarch", "A nation's ruler or head of state usually by hereditary right");
    t.insert("a", "The 1st letter of the Roman alphabet");
    t.insert("Monday", "The second day of the week; the first working day");
    t.insert("monster", "An imaginary creature usually having various human and animal parts");
    t.insert("monopoly", "Exclusive control or possession of something");

    if (t.doesExists("Monday"))
        cout << t.lookup("Monday") <<endl;
    if (t.doesExists("monday"))
        cout << t.lookup("monday") <<endl;
    if (t.doesExists("a"))
        cout << t.lookup("a") <<endl;
    if (t.doesExists("abc"))
        cout << t.lookup("abc") <<endl;
    return 0;
}

