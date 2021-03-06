/*5.1(28). ??????????? ???????, ??????? ??????????? ???????? ??????,
 *?.?. ?????? ??????? ?????????? ?????????, ?????? - ????????????? ? ?.?.*/
#include <stdio.h>
#include <malloc.h>

#define _CRT_SECURE_NO_WARNINGS;

int get_number() {
	//??????????? ?????
	int number;
	//????????? ?????????? ??? ???????? ?????
	char c;
	//? ?????? ?????????? ????? ????? scanf() ??? ???? ?????? ?? ?????????
	while (1) {
		if (!scanf_s("%d", &number) || getchar() != '\n') {
			//??????? ????? ?? ????? ?????? ??? ?????
			while ((c = getchar()) != '\n' && c != EOF);
		}
		else return number;
	}
}
//????
struct Node {
	void *value;
	struct Node *next;
	struct Node *prev;
};
//??????. ???????? ?????? ??????, ?????? ? ????? ?????????????
struct List {
	size_t list_size;
	struct Node *head;
	struct Node *tail;
};

//??????? ??????
struct List* create_list() {
	struct List *tmp = (struct List*) malloc(sizeof(struct List));
	tmp->list_size = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	return tmp;
}

//????????? ? ????? ?????? ???????
void push_back(struct List *list, void *data) {
	struct Node *tmp = (struct Node*) malloc(sizeof(struct Node));
	tmp->value = data;
	tmp->next = NULL;
	tmp->prev = list->tail;

	if (list->tail) {
		list->tail->next = tmp;
	}
	list->tail = tmp;

	if (list->head == NULL) {
		list->head = tmp;
	}
	list->list_size++;
}

//?????? ??????
void print_list(struct Node *node) {
	void *tmp = node->value;
	printf("%d ", *((int*)tmp));
	if (node->next != NULL) {
		print_list(node->next);
	}
}
//???????? ?? ??????? ??????
int is_empty(struct List *list) {
	return list->list_size == 0 ? 1 : 0;
}
//?????????? ??????
void fill_list(struct List *list) {
	while (1)
	{
		char* data = (char*) malloc(sizeof(char) * 256);
		
		char isRepeat;
		printf("?????? ???????? ??????? ? ???????(Y/n)");
		scanf("%c", &isRepeat);
		if (isRepeat != 'Y' && isRepeat != 'y')
			break;
		printf("??????? ??????: ");
		scanf("%s", data);
		push_back(list, data);
	}
}

int main() {
	struct List *list = create_list();
	fill_list(list);

	if (!is_empty(list)) {
		printf("??????: \t\t\t\t");
		print_list(list->head);
	}
	return 0;
}
