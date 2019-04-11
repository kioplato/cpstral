// File: main.c

#include "list.h"

#include <stdlib.h>

void print_options() {
	printf("----------\n");
	printf("0. Quit.\n");
	printf("1. Head push integer.\n");
	printf("2. Tail push integer.\n");
	printf("3. Push integer.\n");
	printf("4. Head pop integer.\n");
	printf("5. Tail pop integer.\n");
	printf("6. Pop integer.\n");
	printf("7. Checkout integer.\n");
	printf("8. Move left.\n");
	printf("9. Move right.\n");
	printf("10. Move to head.\n");
	printf("11. Move to tail.\n");
	printf("12. Get # of items.\n");
	printf("13. Print list.\n");
	printf("----------\n");
}

// Define your print_data according to the data you are storing in the list.
// This is a test main file for integers.
void print_data(void *data) {
	printf("%d\n", *(int*)data);
}

int main() {
	List *list = (List *)malloc(sizeof(List));
	init_list(list);
	size_t option = 1;
	while (option != 0) {
		print_options();
		printf("Input choice: ");
		scanf("%lu", &option);
		if (option == 0) {
			printf("Quitting..\n");
			del_list(list, 1);
			free(list);
			list = NULL;
		}
		else if (option == 1) {
			printf("Pushing front..\n");
			int *number = (int*)malloc(sizeof(int));
			printf("Please input a number: ");
			scanf("%d", number);
			push_head(list, number);
		}
		else if (option == 2) {
			printf("Pushing back..\n");
			int *number = (int*)malloc(sizeof(int));
			printf("Please input a number: ");
			scanf("%d", number);
			push_back(list, number);
		}
		else if (option == 3) {
			printf("Pushing..\n");
			int *number = (int*)malloc(sizeof(int));
			printf("Please input a number: ");
			scanf("%d", number);
			push(list, number);
		}
		else if (option == 4) {
			printf("Popping front..\n");
			int *number = pop_head(list);
			if (number == NULL)
				printf("List is empty.\n");
			else
				printf("Popped integer is: %d\n", *number);
			if (number != NULL) free(number);
		}
		else if (option == 5) {
			printf("Popping back..\n");
			int *number = pop_back(list);
			if (number == NULL)
				printf("List is empty.\n");
			else
				printf("Popped integer is: %d\n", *number);
			if (number != NULL) free(number);
		}
		else if (option == 6) {
			printf("Popping..\n");
			int *number = pop(list);
			if (number == NULL)
				printf("List is empty.\n");
			else
				printf("Popped integer is: %d\n", *number);
			if (number != NULL) free(number);
		}
		else if (option == 7) {
			printf("Checking out..\n");
			int *number = checkout(list);
			if (number == NULL)
				printf("List is empty.\n");
			else
				printf("Checked out integer is: %d\n", *number);
		}
		else if (option == 8) {
			printf("Moving left..\n");
			int rv = mv_left(list);
			if (rv == -1)
				printf("List is empty.\n");
			else if (rv == -2)
				printf("Current node is first node.\n");
			else if (rv == 1)
				printf("Moved left.\n");
		}
		else if (option == 9) {
			printf("Moving right..\n");
			int rv = mv_right(list);
			if (rv == -1)
				printf("List is empty.\n");
			else if (rv == -2)
				printf("Current node is last node.\n");
			else if (rv == 1)
				printf("Moved right.\n");
		}
		else if (option == 10) {
			printf("Moving to head..\n");
			int rv = mv_head(list);
			if (rv == 1)
				printf("Moved to head.\n");
			else if (rv == -1)
				printf("List is empty.\n");
		}
		else if (option == 11) {
			printf("Moving to tail..\n");
			int rv = mv_tail(list);
			if (rv == 1)
				printf("Moved to tail.\n");
			else if (rv == -1)
				printf("List is empty.\n");
		}
		else if (option == 12) {
			printf("Getting # of items..\n");
			size_t n_items = get_n_items(list);
			printf("List has %lu items.\n", n_items);
		}
		else if (option == 13) {
			printf("Printing list..\n");
			print_list(list, print_data);
		} else {
			printf("Unknown option.\n");
		}
	}
}
