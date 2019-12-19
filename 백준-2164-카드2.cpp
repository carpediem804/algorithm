#include <stdio.h>
#include <iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
node* front = NULL; //��
node* back = NULL; //��
node* temp = NULL;
void push(int data) {
	
	if (back == NULL) { // ť�� �ƹ��͵� ������ 
		back = new node();
		back->next = NULL;
		back->data = data;
		front = back;
	}
	else { //ť�� ���� ���� �� 
		temp = new node();
		//cout << front->next << "\n";
		back->next = temp;//���� �߰��ϴ� ��  front->next�� �ٲ���� 
		//cout << front->next << "\n";
		temp->data = data;
		temp->next = NULL;
		back = temp; //���� temp�� �ȴ� 
	}
	//cout << front->next << "\n";
}
void pop() {
	temp = front;
	if (front != NULL) {
		if (temp->next == NULL) { //front���� ���Ұ��ִٸ�
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