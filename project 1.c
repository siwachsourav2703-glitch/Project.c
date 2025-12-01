#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char name[30];
    char phone[15];
} Contact;
Contact list[100];
int count = 0;
void add(), show(), search(), update(), del(), save(), load();
int main() {
    load();
    int choice;
    while (1) {
        printf("\n1. Add  2. Show  3. Search  4. Update  5. Delete  6. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        if (choice == 1) add();
        else if (choice == 2) show();
        else if (choice == 3) search();
        else if (choice == 4) update();
        else if (choice == 5) del();
        else if (choice == 6) { save(); break; }
        else printf("Wrong choice!\n");
    }
    return 0;
}
void add() {
    if (count >= 100) { printf("Full!\n"); return; }
    printf("Name: ");
    scanf(" %[^\n]", list[count].name);
    printf("Phone: ");
    scanf("%s", list[count].phone);
    count++;
    printf("Added!\n");
}
void show() {
    if (count == 0) { printf("Empty!\n"); return; }
    printf("\n--- Contacts ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i+1, list[i].name, list[i].phone);
    }
}
void search() {
    char name[30];
    printf("Search name: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < count; i++) {
        if (strcasecmp(list[i].name, name) == 0) {
            printf("Found: %s - %s\n", list[i].name, list[i].phone);
            return;
        }
    }
    printf("Not found!\n");
}
void update() {
    char name[30];
    printf("Enter name to update: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < count; i++) {
        if (strcasecmp(list[i].name, name) == 0) {
            printf("New phone: ");
            scanf("%s", list[i].phone);
            printf("Updated!\n");
            return;
        }
    }
    printf("Not found!\n");
}
void del() {
    char name[30];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < count; i++) {
        if (strcasecmp(list[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                list[j] = list[j + 1];
            }
            count--;
            printf("Deleted!\n");
            return;
        }
    }
    printf("Not found!\n");
}
void save() {
    FILE *f = fopen("data.txt", "w");
    fprintf(f, "%d\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(f, "%s\n%s\n", list[i].name, list[i].phone);
    }
    fclose(f);
}
void load() {
    FILE *f = fopen("data.txt", "r");
    if (!f) return;
    fscanf(f, "%d", &count);
    for (int i = 0; i < count; i++) {
        fscanf(f, " %[^\n]", list[i].name);
        fscanf(f, " %s", list[i].phone);
    }
    fclose(f);
}