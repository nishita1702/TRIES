#include<iostream>
using namespace std;

struct trie
{
	int isword;
	trie *next[26];
};

trie *createnode()
{
	trie *nn=new trie();
	for(int i=0;i<26;i++)
	{
		nn->next[i]=NULL;
	}
	nn->isword=0;
	return nn;
}

void insert(trie *root, char *str)
{
	if(str[0]=='\0')
	{
		root->isword=1;
		return;
	}
	
	int alphabet=str[0]-'a';
	if(root->next[alphabet]==NULL)
	{
		root->next[alphabet]=createnode();
	}
	
	insert(root->next[alphabet],str+1);
	
	
}

int check(trie *root, char *str)
{
	if(str[0]=='\0')
	return root->isword;
	
	int alphabet=str[0]-'a';
	if(root->next[alphabet]==NULL)
	return 0;
	
	check(root->next[alphabet], str+1);
}

int main()
{
	trie *root=new trie();
	char *str="tree";
	insert(root, str );
	
	int result= check(root, "trie");
	cout<<result;
	
	return 0;
}
