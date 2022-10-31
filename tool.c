#ifndef _tool_


#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

// 노드 타입 정의
typedef struct nodeTag {
    int v;
    struct nodeTag *next;
} nodeType;

// 노드 생성 - malloc() 함수로 공간을 확보한 뒤 v값을 넣어주고 생성된 공간의 주소를 돌려준다.
nodeType* createNode(int v) {
    nodeType *p;
    p = malloc(sizeof(nodeType));
    p->v = v;
    p->next = NULL;
    return p;
}

/*
void destroyNode(nodeType **node) {
    free(*node);
    *node = NULL;
}
*/

// 노드 추가 
void appendNode(nodeType **head, nodeType *newNode) {
    nodeType *ptr = *head;
    if(ptr == NULL) {
    	*head = newNode;
    }
    else {
    	while(ptr->next != NULL) {
    		ptr = ptr->next;
    	}
    	ptr->next = newNode;
    }
}

// 선택 위치에 노드 추가
void insertAfter(nodeType *ptr, nodeType *newNode) {
    newNode->next = ptr->next;
    ptr->next = newNode;
}

// 노드 가져오기 - 인덱스에 해당하는 노드를 가져옴
nodeType *getNode(nodeType *head, int index) {
    nodeType *ptr = head;
    while(ptr->next != NULL && index > 0) {
    	index--;
    	ptr = ptr->next;
    }
    return ptr;
}

// 노드 출력
void printList(nodeType *head) {
    nodeType *ptr = head;
    while(ptr != NULL) {
    	printf("%d\n", ptr->v);
    	ptr = ptr->next;
    }
}