#include <iostream>
#include <vector>
using namespace std;
#include<queue>

typedef struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int v=0,TreeNode* l=NULL, TreeNode* r=NULL)
    {
        val = v;
        left=l;
        right=r;
    }
}TreeNode;

TreeNode * createTree(vector<int> &v) {
	if (v.empty()) {
		return NULL;
	}
	//使用逐层遍历的方式，生成树
	queue<TreeNode*>q;
	TreeNode* root = new TreeNode(v[0]);
	q.push(root);
	int idx = 1;//用以表示当前数组可用的元素下标
	while (!q.empty()&&idx<v.size()) {
		int cnt = q.size();
		for (int i = 1; i <= cnt; i++) {
			TreeNode* cur = q.front();
			q.pop();
			//判断左子树是否为空
			if (v[idx] != -1) {
				TreeNode* t = new TreeNode(v[idx]);
				cur->left = t;
				q.push(cur->left);
			}
			idx++;
			if (idx >= v.size()) {
				break;
			}
			//判断右子树是否为空
			if (v[idx] != -1) {
				TreeNode* t = new TreeNode(v[idx]);
				cur->right = t;
				q.push(cur->right);
			}
			idx++;
		}
	}
	return root;
}
void destroyTree(TreeNode* root)
{
	if(!root)
		return ;
	destroyTree(root->left);
	destroyTree(root->right);
	delete root;
}
bool isCompleteTree(TreeNode* root){
	queue <TreeNode*> s;
	s.push(root);
	while(!s.empty()){
		TreeNode* temp=s.front();
		if(temp->left==NULL&&temp->right!=NULL){
			return false;
		}
		else if(temp->left!=NULL&&temp->right!=NULL){
			s.pop();
			s.push(temp->left);
			s.push(temp->right);
		}
		else if(temp->right==NULL){
			s.pop();
			while(!s.empty()){
				temp=s.front();
				s.pop();
				if(temp->left!=NULL||temp->right!=NULL){
					return false;
				}
			}
			break;
			
		}
	}
	return true;
}
int main() {
    int num;
    cin >> num;
    vector<int>values(num);
    for(unsigned int i=0;i<num;i++)
        cin >> values[i];
    TreeNode* root = createTree(values);
    cout << isCompleteTree(root) << endl;
    destroyTree(root);
    return 0;
}

