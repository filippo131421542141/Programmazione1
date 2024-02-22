#include <iostream>
#include <cstdlib>
using namespace std;
struct albero
{
    int value;
    albero *dxChild;
    albero *sxChild;
};

albero * addElement(albero *& tree, int value){

    if (tree==nullptr)
    {
        tree=new albero;
        tree->value=value;
        tree->dxChild=nullptr;
        tree->sxChild=nullptr;    
    }else{
       if (tree->value > value)
        {
        tree->sxChild = addElement(tree->sxChild,value);
        }else{
        tree->dxChild = addElement(tree->dxChild,value);
    } 
    }
    
    return tree;
}

void riempiArray(int arr[],int dim){
    for (int i = 0; i < dim; i++)
    {
        arr[i]=rand()%10;
    }
    
}
void riempiAlbero(albero *& root, int * arr ,int dim){
    for (int i = 0; i < dim; i++)
    {
        addElement(root,arr[i]);
    }
    
}
void stampaAlbero(albero * radice, int spazio){
   if (radice != nullptr) {
    spazio ++;
    
    stampaAlbero(radice->dxChild, spazio);
 
    for (int i = 1; i < spazio; i++) {
        cout<<"\t";
    }
    cout<<radice->value<<"\n";
    
    stampaAlbero(radice->sxChild, spazio);
   }


}


albero* sumTree(albero* root1, albero* root2) {
  if (!root1 && !root2) return nullptr;
  if (!root1) return root2;
  if (!root2) return root1;

  root1->value += root2->value;

  root1->dxChild = sumTree(root1->dxChild, root2->dxChild);
  root1->sxChild = sumTree(root1->sxChild, root2->sxChild);

  return root1;
}

void helper(albero* t, albero*& result) {
    if (!t)
    {
        return;
    }else{
        helper(t->dxChild,result);
        addElement(result,t->value);
        helper(t->sxChild,result);
    }
}
albero * unionTree(albero * t1,albero * t2){
    albero * res=nullptr;
    if (t1!=nullptr && t2!=nullptr)
    {
        helper(t2,res);
        helper(t1,res);
    }
    return res;
}


int main(){
    const int dim1=3;
    const int dim2=2;
    int arr1[dim1];
    int arr2[dim2];
    albero * tree1=nullptr;
    albero * tree2=nullptr;

    riempiArray(arr1,dim1);
    riempiArray(arr2,dim2);

    riempiAlbero(tree1,arr1,dim1);
    riempiAlbero(tree2,arr2,dim2);

    stampaAlbero(tree1,0);
    cout << "-----------------------------------------------" << endl;
    stampaAlbero(tree2,0);

    albero * res=unionTree(tree1,tree2);
    cout << "-----------------------------------------------" << endl;
    
    stampaAlbero(res,0);

    return 0;
}