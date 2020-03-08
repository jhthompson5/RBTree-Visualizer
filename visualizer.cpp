#include <cmath>
#include <deque>
#include <string>
#include "RBTree.cpp"
using namespace std;

#define redNode(key) setRed << key << setDefault
#define setRed "\33[3" << 1 << ";4" << 9 << "m"
#define setDefault "\33[3" << 9 << ";4" << 9 << "m"

#define outputNode(n)        \
if(n->color==red){           \
    cout << redNode(n->Key); \
}                            \
else cout << n->Key;

template<class V, class K>
void Visualize(RBTree<V,K> t){
    if(t.root == nullptr ){
        cout << "Empty" << endl;
        return;
    }
    
    Node<V,K> *null = new Node<V,K>();
    null->value = -10;
    null->Key = -10;
    int size = t.Size();
    int numProcessed = 0;
    int MAX_WIDTH = 128;
    cout << string(MAX_WIDTH, '-') << endl;
    deque<Node<V,K>*> currRow;
    deque<Node<V,K>*> nextRow;
    nextRow.push_front(t.root);
    int curRow = 0;
    //cout << "size: " << size;
    while(numProcessed < size){
        //cout << "Row:" << curRow;
        curRow++;
        currRow = nextRow;
        nextRow.clear();
        int dispPosition = MAX_WIDTH/pow(2,curRow);
        if(dispPosition <= 0) dispPosition = 1;
        int rowLength = 0;
        for(Node<V,K>* node : currRow){
            if(rowLength>MAX_WIDTH) rowLength = MAX_WIDTH;
            int numSpaces = min(dispPosition,MAX_WIDTH-rowLength);
            int numDigits = 1;
            int valHold = node->value;
            while((valHold / 10) > 0){ numDigits++; valHold /= 10;}
            if(node!=null){
                if(node->left != nullptr){
                    nextRow.push_back(node->left);        
                }
                else nextRow.push_back(null);
                if(node->right != nullptr){
                    nextRow.push_back(node->right);
                }
                else nextRow.push_back(null);  
                if(numSpaces > numDigits){
                    cout << string(numSpaces-numDigits,' ');
                    outputNode(node);
                    cout << string(numSpaces, ' ');
                }
                else {
                    outputNode(node);
                    cout << " ";
                }
                numProcessed++;
            }
            else{    
                nextRow.push_back(null);
                nextRow.push_back(null);
                //numSpaces -= 1;
                if(numSpaces != 0) cout << string(numSpaces,' ') << string(numSpaces,' ');
            }
            rowLength += 2*numSpaces;
        }
        cout << endl;
    }
    cout << string(MAX_WIDTH, '-') << endl;;
}