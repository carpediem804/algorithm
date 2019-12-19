#include <stdio.h>
#include <iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
node* front = NULL; //앞
node* back = NULL; //뒤
node* temp = NULL;
void push(int data) {
	
	if (back == NULL) { // 큐에 아무것도 없을때 
		back = new node();
		back->next = NULL;
		back->data = data;
		front = back;
	}
	else { //큐에 뭔가 있을 때 
		temp = new node();
		//cout << front->next << "\n";
		back->next = temp;//끝에 추가하는 것  front->next도 바뀐다잉 
		//cout << front->next << "\n";
		temp->data = data;
		temp->next = NULL;
		back = temp; //끝은 temp가 된다 
	}
	//cout << front->next << "\n";
}
void pop() {
	temp = front;
	if (front != NULL) {
		if (temp->next == NULL) { //front에만 원소가있다면
			front = NULL;
			back = NULL;
		}
		else {
			temp = temp->next;
			front = temp;
		}
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		//printf("i : %d\n", i);
		push(i);
	}
	while (1) {
		if (front->next == NULL) {
			break;
		}
		pop();
		push(front->data);
		if (front->next == NULL) {
			break;
		}
		pop();
	}
	printf("%d\n", front->data);
	return 0;
}