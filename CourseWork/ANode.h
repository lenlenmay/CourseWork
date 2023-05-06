#pragma once

template<typename Type>
class Node {
	Type* data;

public:
	Node* prev, * next;
	Node(Type* data);
};