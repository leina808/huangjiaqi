#include <stdio.h>
#include <string.h>

void startWords();
void addContact();
void searchNumber (char *);
void init();
int findNext();

typedef struct {
    char name[100];
    char phoneNumber[12];
} Contact;

Contact contacts[100];
// 0: busy 1: free
int isEmpty[100];

int main()
{
    init();
    while (1) {
        startWords();
            printf("%s", "pick a choice: \n");
        int in;
        scanf("%i",&in);
        // 
        switch(in) {
            case 1:
                printf("%s", "chose 1\n");
                addContact();
                break;
            case 2:
                printf("%s", "chose 2\n");
                fputs("Name: ", stdout);
                char name[100];
                fflush(stdin);
                fgets(name, 100, stdin);
                searchNumber(name);
                break;
            default: 
                break;
        }
        // if (in == 1) {
        // // a;
        // printf("%s", "chose 1\n");
        // addContact();
        // } else {
        //   if (in == 2) {
        //     printf("%s", "chose 2\n");
        //     fputs("Name: ", stdout);
        //     char name[100];
        //     fflush(stdin);
        //     fgets(name, 100, stdin);
        //     searchNumber(name);
        //   } else {
        //     if (in == 3) {
        //     printf("%s", "chose 3\n");
        //     }
        //   }
        // }
    }
    return 0;
}

void init() {
    // 把isEmpty数组里的元素全部初始化为0
    for (int i = 0; i < 100; ++i) {
        isEmpty[i] = 1;
    }
}

// ：查找一个空闲位
// 返回空闲位数组下标
int findNext() {
    for (int i = 0; i < 100; ++i) {
        if (isEmpty[i]) {
            isEmpty[i] = 0;
            return i;
        }
    }
}

voi//

// 选项1
void addContact() {
    Contact contact;
    // 请求联系人名字
    printf("%s", "Name: \n");
    fflush(stdin);
    fgets(contact.name, 15, stdin);
    // 请求联系人电话号码
    printf("Number: \n");
    fgets(contact.phoneNumber,12,stdin);
    // 添加到程序的内存
    // 寻找下一个空闲位
    int freeIdx = findNext();
    printf("pos: %i\n", freeIdx);
    contacts[freeIdx] = contact;
    fputs("succeeded!\n", stdout);
}

// 选项2
void searchNumber (char * name) {
    for (int i = 0; i < 100; ++i) {
        if (!strcmp(contacts[i].name, name)) {
            fputs(contacts[i].phoneNumber, stdout);
        return;
        }
    }
    fputs("\nNone\n", stdout);
}
