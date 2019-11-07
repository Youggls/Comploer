#include "LiteralASTNode.h"

LiteralASTNode::LiteralASTNode(char* content):AbstractASTNode(content,  ASTNodeType::literal) {
    
}

void LiteralASTNode::printInfo() {
    std::cout << "Literal: "<< this->getValue() << std::endl;
}

int LiteralASTNode::getValue() {
    return std::stoi(this->content);
}
