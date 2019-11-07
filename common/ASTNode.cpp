#include "ASTNode.h"

AbstractASTNode::AbstractASTNode() {
	this->child = NULL;
	this->parent = NULL;
	this->peer = NULL;
	this->content = "Initial stat";
}

AbstractASTNode::AbstractASTNode(ASTNodeType nodeType) {
    this->nodeType = nodeType;
}

AbstractASTNode::AbstractASTNode(char* content, ASTNodeType nodeType) {
	this->child = NULL;
	this->parent = NULL;
	this->peer = NULL;
	this->content = content;
	this->nodeType = nodeType;
}

void AbstractASTNode::addChildNode(AbstractASTNode* node) {
	this->child = node;
}

void AbstractASTNode::addPeerNode(AbstractASTNode* node) {
	this->peer = node;
}

AbstractASTNode* AbstractASTNode::getLastPeerNode()
{
	AbstractASTNode* t = this;
	while (t->peer != NULL)
	{
		t = t->peer;
	}
	return t;
}

void AbstractASTNode::__printTree(AbstractASTNode* node, int depth) {
	if (node == NULL) return;
	for (int i = 0; i < depth; i++) std::cout << " ";
	node->printInfo();
	AbstractASTNode::__printTree(node->child, depth + 1);
	AbstractASTNode* peer = node->peer;
	while (peer != NULL) {
		AbstractASTNode::__printTree(peer, depth);
		peer = peer->peer;
	}
}

void AbstractASTNode::printTree() {
	AbstractASTNode::__printTree(this, 0);
}
