#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    vector<Node*>v;

    Node(int data)
    {
        this->data=data;
    }
};

void printtree(Node*root)
{
    if(!root)
        return;
    cout<<root->data<<" -> ";
    for(int i=0;i<root->v.size();i++)
    {
        cout<<(root->v[i]->data)<<", ";
    }
    cout<<".";
    for(int i=0;i<root->v.size();i++)
    {
        printtree(root->v[i]);
    }
}

Node* input_tree()
{
   int x,n;
   cout<<"Enter Root";
   cin>>x;
   if(x==-1)
    return NULL;
   Node*root=new Node(x);
   cout<<"Enter no of child";
   cin>>n;
   for(int i=0;i<n;i++)
   {
       Node*temp=input_tree();
       root->v.push_back(temp);
   }
   return root;
}

int countofnodes(Node*root)
{
    if(!root)
        return 0;
    int ans=1;
    for(int i=0;i<root->v.size();i++)
    {
        ans+=countofnodes(root->v[i]);
    }
    return ans;
}
int max_intree(Node*root)
{
    int max_val=root->data,temp=0;
    for(int i=0;i<root->v.size();i++)
    {
        temp=max(max_intree(root->v[i]),temp);
    }
    max_val=max(max_val,temp);
    return max_val;
}

Node* level_wise_input()
{
    cout<<"root";
    int x;
    cin>>x;
    if(x==-1)
        return NULL;
    Node*root=new Node(x);
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node*temp=q.front();
        q.pop();
        cout<<"enter no of child";
        int n;cin>>n;
        for(int i=0;i<n;i++)
        {
            int y;
            cin>>y;
            Node*t=new Node(y);
            temp->v.push_back(t);
            q.push(t);
        }
    }
    return root;
}
int height(Node*root)
{
    if(!root)return 0;

    if(root->v.size()==0)
        return 1;
    int max_h=1;
    for(int i=0;i<root->v.size();i++)
    {
        max_h=max(max_h,1+height(root->v[i]));
    }
    return max_h;
}

Node*input_pep(int arr[],int n)
{
    Node*root=NULL;
    stack<Node*>s;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==-1)
            s.pop();
        else
        {
            Node*temp=new Node(arr[i]);
            if(s.size()>0)
            {
                s.top()->v.push_back(temp);
            }
            else
            {
                root=temp;
            }
            s.push(temp);
        }
    }
    return root;
}

void level_order_zigzag(Node*root)
{
    if(!root)
    return;
    stack<Node*>s1,s2;
    s1.push(root);
    int level=0;
    while(!s1.empty())
    {
        root=s1.top();
        s1.pop();
        cout<<root->data<<" ";
        
        if(level%2==0)
        {
            for(int i=0;i<root->v.size();i++)
            {
                s2.push(root->v[i]);
            }
        }
        else
        {
            for(int i=root->v.size()-1;i>=0;i--)
            {
                s2.push(root->v[i]);
            }
        }
        if(s1.size()==0)
        {
            s1.swap(s2);
            level++;
            cout<<" ";
        }
    }
}
Node* mirror(Node*root)
{
    if(!root)return root;
    
    for(int i=0;i<root->v.size();i++)
    {
        root->v[i]=mirror(root->v[i]);
    }
    for(int i=0;i<root->v.size()/2;i++)
    {
        Node*temp=root->v[i];
        root->v[i]=root->v[root->v.size()-1-i];
        root->v[root->v.size()-1-i]=temp;
    }
    return root;
}
Node*delete_leaf(Node*root)
{
    if(!root)return root;
    
    for(int i=0; i<root->v.size();i++)
    {
        if(root->v[i]->v.size()==0)
        {
            for(int j=i;j<root->v.size();j++)
            {
                root->v[j]=root->v[j+1];   
            }
            root->v.pop_back();
            i--;
        }
    }
    for(int i=0; i<root->v.size();i++)
    {
        root->v[i]=delete_leaf(root->v[i]);
    }
    return root;
}

Node*getend(Node*root)
{
    if(!root)
    return root;
    
    return root->v[root->v.size()-1];
}
Node*linearise(Node*root)
{
    for(int i=0;i<root->v.size();i++)
    {
        root->v[i]=linearise(root->v[i]);
    }
    while(root->v.size()>1)
    {
        Node*temp=root->v[root->v.size()-1];
        root->v.pop_back();
        Node*end=getend(root->v[root->v.size()-1]);
        end->v.push_back(temp);
    }
    return root;
}
bool find(Node*root,int k)
{
    if(!root)
    return false;
    
    if(root->data==k)
    return true;
    
    bool ans=false;
    for(int i=0;i<root->v.size();i++)
    {
        ans=(ans|find(root->v[i],k));   
    }
    return ans;
}

vector<int> find_path(Node*root,int k)
{   
    vector<int>ans;
    if(!root)
    return ans;
    
    ans.push_back(root->data);
    if(root->data==k)
    {
        return ans;
    }
    for(int i=0;i<root->v.size();i++)
    {
        if(root->v[i]->data==k)
        {
            ans.push_back(k);
            return ans;
        }
        vector<int>p=find_path(root->v[i],k);
        if(p[p.size()-1]==k)
        {
            for(int j=0;j<p.size();j++)
            ans.push_back(p[j]);
            return ans;
        }
    }
    return ans;
}

int lca(Node*root,int n1,int n2)
{
    vector<int>p1,p2;
    p1=find_path(root,n1);
    p2=find_path(root,n2);
    
    int i;
    for( i=0;i<p1.size()&&i<p2.size();i++)
    {
        if(p1[i]!=p2[i])
        break;
    }
    return p1[i-1];
}

bool issimilar(Node*root1,Node*root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    else if(root1==NULL || root2==NULL)
    return false;
    if(root1->v.size()!=root2->v.size())
    return false;
    
    bool ans=true;
    for(int i=0;i<root1->v.size();i++)
    {
        ans=ans&(issimilar(root1->v[i],root2->v[i]));
    }
    return ans;
}

bool ismirror(Node*root1,Node*root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    else if(root1==NULL || root2==NULL)
    return false;
    if(root1->v.size()!=root2->v.size())
    return false;
    bool ans=true;
    for(int i=0;i<root1->v.size();i++)
    {
        ans=ans&(issimilar(root1->v[i],root2->v[root2->v.size()-1-i]));
    }
    return ans;
}

bool issymmetric(Node*root1)
{
    return ismirror(root1,root1);
}

int pre=-1,succ=-1,s=0;
void find_ps(Node*root,int k)
{
    if(s==0)
    {
        if(root->data==k)
        s=1;
        else
        pre=root->data;
    }
    else if(s==1)
    {
        succ=root->data;
        s=2;
    }
    for(int i=0;i<root->v.size();i++)
    find_ps(root->v[i],k);
}

int ceil_p=INT_MAX,floor_p=INT_MIN;

void yetanotherfind(Node*root,int k)
{
    if(root->data>k && ceil_p>root->data)
    {
        ceil_p=root->data;
    }
    else if(root->data<k && floor_p<root->data)
    {
        floor_p=root->data;
    }
    for(int i=0;i<root->v.size();i++)
    yetanotherfind(root->v[i],k);
}

priority_queue <int, vector<int>, greater<int> > pq;
void kthlargest(Node*root,int k)
{
    if(pq.size()<k)
    {
        pq.push(root->data);
    }
    else
    {
        if(pq.top()<root->data)
        {
            pq.pop();
            pq.push(root->data);
        }
    }
    for(int i=0;i<root->v.size();i++)
    kthlargest(root->v[i],k);
}

Node*max_v;
int max_sum=0;
int max_sum_subtree(Node*root)
{
    int sum=0;
    
    for(int i=0;i<root->v.size();i++)
    {   
        int temp;
        temp=max_sum_subtree(root->v[i]);
        sum+=temp;
    }
    sum+=root->data;
    if(sum>max_sum)
    {
        max_v=root;
        max_sum=sum;
    }
    return sum;
}
priority_queue <int, vector<int>, greater<int> > dpq;
int diameter(Node*root)
{   
    if(root->v.size()==0)return 0;
    
    for(int i=0;i<root->v.size();i++)
    {
        int x=height(root->v[i]);
        if(dpq.size()<2)
        dpq.push(x);
        else if(dpq.top()<x)
        {   
            dpq.pop();
            dpq.push(x);
        }
    }
    int y1=dpq.top();
    dpq.pop();
    int y2=dpq.top();
    dpq.pop();
    int max_d=0;
    for(int i=0;i<root->v.size();i++)
    {
        max_d=(max_d,diameter(root->v[i]));
    }
    max_d=max(max_d,y1+y2);
}
int dia=0;
int alternate_diameter(Node*root)
{
    int h=-1,sh=-1;
    
    for(int i=0;i<root->v.size();i++)
    {
        int he=alternate_diameter(root->v[i]);
        if(he>h)
        {   
            sh=h;
            h=he;
        }
        else if(he>sh)
        {
            sh=he;
        }
    }
    if(h+sh+2>dia)
    {
        dia=h+sh+2;
    }
    h+=1;
    return h;
}

int main()
{
    Node*root1;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    root1=input_pep(arr,n);
    return 0;
}
