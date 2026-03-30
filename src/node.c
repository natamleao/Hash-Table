#include "node.h"
#include <stdio.h>
#include <stdlib.h>

/******************************************************* PRIVATE INTERFACE *******************************************************/

struct _node{
    int _index;
    int _value;
    struct _node *_next;
};

/******************************************************* PUBLIC INTERFACE ********************************************************/

Node* NodeCreate(int _index, int _value){
    Node *node_ = (Node*)malloc(sizeof(Node));
    if(!node_) return NULL;

    node_->_index = _index;          
    node_->_value = _value;
    node_->_next = NULL;

    return node_;
}

int NodeGetIndex(Node *node_){return node_->_index;}
int NodeGetValue(Node *node_){return node_->_value;}
Node* NodeGetNextNode(Node *node_) {
    if(!node_) return NULL;
    return node_->_next;
}
void NodeSetIndex(Node *node_, int _index){node_->_index = _index;}
void NodeSetValue(Node *node_, int _value){node_->_value = _value;}
void NodeSetNextNode(Node *node_, Node *_next) {
    if(!node_) return;
    node_->_next = _next;
}

void NodeDestroy(Node *node_) {
    if(node_) free(node_);                   
}

/*********************************************************************************************************************************/