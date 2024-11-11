#include <stdbool.h>
#include <stdio.h>

// Define a union for item length
union item_length {
  int pages;
  float duration;
};

// Define a structure for a library item
struct Item {
  char name[100];
  bool is_book; // true if book, false if DVD
  union item_length length;
};

// Function to input item details
void input_item(struct Item *item) {
  printf("Enter item name: ");
  scanf("%s", (*item).name);

  printf("Is the item a book? (1 for Yes, 0 for No): ");
  scanf("%d", (int *)&(*item).is_book);

  if ((*item).is_book) {
    printf("Enter number of pages: ");
    scanf("%d", &(*item).length.pages);
  } else {
    printf("Enter duration in minutes: ");
    scanf("%f", &(*item).length.duration);
  }
}

// Function to display item details
void print_item(struct Item item) {
  printf("Item name: %s\n", item.name);
  if (item.is_book) {
    printf("Item type: Book\n");
    printf("Number of pages: %d\n", item.length.pages);
  } else {
    printf("Item type: DVD\n");
    printf("Duration: %.2f minutes\n", item.length.duration);
  }
}

int main() {
  struct Item item;

  input_item(&item);
  print_item(item);

  return 0;
}
