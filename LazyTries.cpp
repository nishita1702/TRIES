#include<iostream>
#include<cstring>
using namespace std;

struct trie
{
	int isword;
	trie *next[26];
	char suffix[100];
};

trie *createnode()
{
	trie *nn=new trie();
	for(int i=0;i<26;i++)
	{
		nn->next[i]=NULL;
	}
	nn->isword=0;
	nn->suffix[0] ='\0';
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
		trie *temp=new trie();
		root->next[alphabet]=temp;
		strcpy(temp->suffix,str+1);
		temp->isword=1;
		return;
		
	}
	else
	{
		trie *temp1=root->next[alphabet];
		insert(temp1,temp1->suffix);
		temp1->suffix[0]='\0';
		
		temp1->isword=0;
		
		
		insert(temp1, str+1);
	}
}
int check(trie *root, char *str)
{
	if(str[0]=='\0')
	return root->isword;
	
	int alphabet=str[0]-'a';
	if(root->next[alphabet]==NULL)
	{
		return 0;
	}
	trie *node=root->next[alphabet];
	if(node->suffix[0]!='\0')
	{
		if(strcmp(node->suffix,str+1)==0)
		return 1;
		else
		return 0;
	}
	return check(root->next[alphabet], str+1);
}
int main()
{
	trie *node=createnode();
	char *str="tree";
	insert(node,str);
	int result=check(node,"tree");
	cout<< result;
	return 0;
}
