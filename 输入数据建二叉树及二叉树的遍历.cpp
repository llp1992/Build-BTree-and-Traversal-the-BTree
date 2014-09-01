#include<iostream>
#include<cmath>
#include <conio.h>
#include<vector>

using namespace std;

static int value = 0;
static int Vmax ;
static int Vmin ;

struct tree
{
	int data;
	tree *left,*right;
};

class Btree
{
    static int n;
    static int m;
public:
    tree *root;
    Btree()
    {
        root=NULL;
    }
    void create_Btree(int);
    void Preorder(tree *);                  //先序遍历
    void display1() 
	{
		Preorder(root); cout<<endl;
	} 
}; 

int Btree::n=0;
int Btree::m=0;

//建议二叉树的函数
void Btree::create_Btree(int x)
{
	//建立新节点，新节点跟为输入数据，左右节点为空
    tree *newnode=new tree;
    newnode->data=x;
    newnode->right=newnode->left=NULL;
    if(root==NULL)
        root=newnode;
    else
    {
        tree *back;//存储叶节点
        tree *current=root;
		//一直寻找，直到找到没有子节点的叶节点
        while(current!=NULL)
        {
            back=current;
            if(current->data>x)
                current=current->left;
            else
                current=current->right;
        }
		//找到没有子节点的叶节点后根据大小将新建立的子节点连接到该子节点的左或右子节点
        if(back->data>x)
            back->left=newnode;
        else
            back->right=newnode;
    }
}

void Btree::Preorder(tree *temp)    //这是先序遍历二叉树，采用了递归的方法。
{
	int temp_value = 0;
	//递归先序遍历查找最大最小值
    if(temp!=NULL)
    {
		if(temp->data>Vmax)
		{
			Vmax = temp->data;
		}
		else if(temp->data<Vmin)
		{
			Vmin = temp->data;
		}
		temp_value = abs(Vmax-Vmin);
		if(temp_value>value)
		{
			value = temp_value;
		}
        cout<<temp->data<<endl;
        Preorder(temp->left);
        Preorder(temp->right);
    }
}

int main()
{
	vector<int> vec;
	Btree A;
	int a;
	while(cin>>a)
	{
		//要先push_back(a)再判断，否则最后一个跟回车混在一起，没有push进去
		vec.push_back(a);
		//判断回车跳出循环,getchar()只能读取一个字符
		if(getchar()==10)
		{
			break;
		}
	}
	int k = vec.size();
	for(int i = 0;i<vec.size();i++)
	{
		A.create_Btree(vec[i]);
	}
    cout<<endl;
	Vmax = vec[0];
	Vmin = vec[1];
    cout<<endl<<"先序遍历序列"<<endl;
	A.display1();
	cout<<"节点间最大值为：\n";
	cout<<value<<endl;
}