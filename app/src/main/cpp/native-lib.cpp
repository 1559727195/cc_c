#include <jni.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include<android/log.h>
#include <ostream>

using namespace std;
#define TAG "CC_C" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型


//void **allocMem(int base, int row, int line) {
//
//    LOGE("%d", row * sizeof(void *));
//    void **p = static_cast<void **>(malloc(row * sizeof(void *)));// 24 个字节
//    LOGE("p:%p", p);
//    LOGE("p.size:%d", sizeof(p));
//
//    //LOGE("p[0]:%p", *p);
//    //LOGE("p[1]:%p", *p + 1);
//    //LOGE("p[2]:%p", *p + 2);
////
////
//    //LOGE("p[0].size:%d", sizeof(*p));
//    //LOGE("p[1].size:%d", sizeof(*p + 1));
//    //LOGE("p[2].size:%d", sizeof(*p + 2));
//    // p包含3个
//
//
//
//    for (int i = 0; i < row; i++) {
//        p[i] = malloc(base * line);//16
//        LOGE("p[].location:%p", p[i]);
//        LOGE("p[].size:%d", sizeof(p[i]));
//    }
//
//    return p;
//
//}

#define  LENGTH  16

//void **allocMem(int base, int row, int line) {
//    void **p = static_cast<void **>(malloc(row * sizeof(void *)));
//    char (*array)[4 * 4] = static_cast<char (*)[4 * 4]>(malloc(base * row * line));
//
//    for (int i = 0; i < row; i++) {
//        p[i] = array++;
//        LOGE("p[].location:%p", p[i]);
//    }
//    return p;
//
//}


void allocMem(void ***p, int base, int row, int line) {
    *p = static_cast<void **>(malloc(row * sizeof(void *)));

    for (int i = 0; i < row; i++) {
        (*p)[i] = malloc(base * line);
    }
}


//int myCmp(int a, int b) {
//    if (a > b) return 1;
//    else if (a < b) return 0;
//    else return 0;
//}


void selectSort(int *p, int n, int (*myCmp)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (myCmp(p[i], p[j])) {
                p[i] = p[i] ^ p[j];
                p[j] = p[i] ^ p[j];
                p[i] = p[i] ^ p[j];
            }
        }
    }
}


typedef int (*PF)(int a, int b);

//PF pf = myCmp;


/*
int cmp (const void *a,const void *b) {
    return    *(int *)a - *(int *)b;

}
*/

struct In {
    int data;
    char str[100];
} s[100];

//int cmp (const void *a, const void *b) {
//    return   (*(In*)a).data > (*(In*)b).data ? 1: -1;
//
//}

//int myCmp(const void *a, const void *b) {
//    if (*(int *) a > *(int *) b) return 1;
//    else return -1;
//}


typedef struct {
    char name[30];//30
    float score;//6
} Stu;


int myCmp(const void *a, const void *b) {

    int cmp = strcmp(((Stu *) a)->name, ((Stu *) b)->name);

    if (cmp != 0) {
        return cmp;
    } else {
        return ((Stu *) a)->score - ((Stu *) b)->score;
    }
}

Stu stu[] = {{"aaa",  23.5},
             {"xxx",  45.6},
             {"bbb",  89},
             {"xxx",  23.4},
             {"yyy ", 100}};


void function0(int);

void function1(int);

void function2(int);


//char *strcpy(char *dest, char *src) {
//    char *tmp = dest;
//    while (*dest++ = *src++) {
//        return tmp;
//    }
//}


void foo(void) {
    char string[10], str1[10];
    int i;
    for (i = 0; i < 10; i++) {
        //str1[i] = 'a';
        //
        // }

        str1[i] = 'a';
    }
    //strcpy(string, str1);
    strcpy(string, str1);
    LOGE("%s", string);
}


int strCount(char *str1, char *str2) {
    int count = 0;
    while ((str1 = strstr(str1, str2)) != NULL) {
        count++;
        LOGE("截断之前%s\n", str1);
        str1 = str1 + strlen(str2);
        LOGE("截断之后%s\n", str1);
    }
    return count;
}





//void reverse(char *str) {
//    char *start = str;
//    char *end = start + strlen(str) - 1;
//    while (start < end) {
//        *start = *start ^ *end;
//        *end = *start ^ *end;
//        *start = *start ^ *end;
//        start++;
//        end--;
//    }
//}


void func(int n) {
    if (n) {
        func(n / 2);
    }
    LOGE("%d", n);
}


//char gbuf[1024];

void reverse(char *str, char *buf) {
    if (*str == '\0') {
        return;
    }
    reverse(str + 1, buf);
    strncat(buf, str, 1);
    //LOGE("%s\n",gbuf);
}


char gbuf[1024];

typedef struct node {
    int data;
    struct node *pre;
    struct node *next;
} Node;

Node *creatList() {
    Node *head = (Node *) malloc(sizeof(Node));
    Node *phead = head;
    Node *cur = NULL;
    phead->next = NULL;
    phead->pre = NULL;
    for (int i = 0; i < 3; i++) {
        cur = (Node *) malloc(sizeof(Node));
        cur->data = i;
        phead->next = cur;
        cur->pre = phead;
        phead = cur;
    }
    cur->next = head;
    head->pre = cur;
    return head;
}

void traverseList(Node *head) {
    Node *phead = head->next;
    while (phead != head) {
        LOGE("%d ", phead->data);
        phead = phead->next;
    }
}


void insertList(Node *head) {
    printf("intsert new node:");
    int data;
    scanf("%d", &data);
    Node *cur;
    cur = (Node *) malloc(sizeof(Node));
    cur->data = data;
    cur->next = head->next;
    cur->pre = head;
    head->next = cur;
    cur->next->pre = cur;
}


Node *searchList(Node *head, int find) {
    Node *pClock = head->next;

    Node *pAntiClock = head->pre;

    while (pAntiClock != pClock->pre) {
        if (pClock->data == find) {
            return pClock;
        }
        if (pAntiClock->data == find) {
            return pAntiClock;
        }
        if (pClock == pAntiClock) {
            return NULL;
        }

        pClock = pClock->next;
        pAntiClock = pAntiClock->pre;
    }
    return NULL;
}


/*Node *searchList(Node *head, int find) {
    Node *phead = head->next;
    while (phead != head) {
        if (phead->data == find)
            return phead;
    }
    return NULL;
}*/

//Node *searchList(Node *head, int find) {
//    Node *phead = head->next;
//    while (phead != head) {
//        if (phead->data == find) {
//            return phead;
//        }
//        phead = phead->next;
//    }
//    return NULL;
//}


void deleteList(Node *pfind) {
    if (pfind == NULL) {
        return;
    } else {
        pfind->pre->next = pfind->next;
        pfind->next->pre = pfind->pre;
        free(pfind);
    }
}

int lenList(Node *head) {
    int len = 0;
    Node *phead = head->next;
    while (phead != head) {
        len++;
        phead = phead->next;
    }
    return len;
}

//void sortList(Node *head, int n) {
//    Node *p, *q;
//    for (int i = 0; i < n - 1; i++) {
//        p = head->next;
//        q = p->next;
//        for (int j = 0; j < n - 1 - i; j++) {
//            if (p->data < q->data) {
//                p->data = p->data ^ q->data;
//                q->data = p->data ^ q->data;
//                p->data = p->data ^ q->data;
//            }
//            p = p->next;
//            q = q->next;
//        }
//    }
//}

void sortList(Node *head, int n) {
    Node *p, *q, *tmp;
    for (int i = 0; i < n - 1; i++) {
        p = head->next;
        q = p->next;
        for (int j = 0; j < n - 1 - i; j++) {
            if (p->data < q->data) {
                p->data = p->data ^ q->data;
                q->data = p->data ^ q->data;
                p->data = p->data ^ q->data;
            }
            p = p->next;
            q = q->next;
        }
    }
}


void destroyList(Node *head) {
    head->pre->next = NULL;
    Node *pre = head;
    while (head != NULL) {
        head = head->next;
        free(pre);
        pre = head;
    }
}


int AveInt(int, ...);

union Data {
    int i;        //表示不同类型的变量i，ch，f可以存放到同一段存储单元中
    char ch;
    float f;
} a = {16};


#define TOTAL 4

struct {
    char name[20];
    int num;
    char sex;
    char profession;
    union {
        float score;
        char course[20];
    } sc;

} bodys[TOTAL];


typedef struct s_block *t_block;

struct s_block {
    size_t size;//数据区大小
    t_block next;//指向下个块的指针
    int free;//是否是空闲块
    int padding;//填充4 字节，保证meta块长度为8的倍数
    char data[1];//这是个虚拟字段，表示数据块的第一个字节，长度不应计入meta
};

s_block *firstBlock;

t_block find_block(t_block *last, size_t size) {
    t_block b = firstBlock;
    while (b && !(b->free && b->size >= size)) {
        *last = b;

    }
}

#include <unistd.h>
#include <stdio.h>

int sum = 0;

void *adder(void *p) {
    int old = sum;
    for (int i = 0; i < 1000000; i++)  // 百万次
    {
        while (!__sync_bool_compare_and_swap(&sum, old, old + 1))  // 如果old等于sum, 就把old+1写入sum
        {
            old = sum; // 更新old
        }
    }

    return NULL;
}


#include <dlfcn.h>

//typedef int (*printf_func_pointer)(const char *__restrict, ...);
//
//
//void dynamic_call_function() {
//    char *dylib_path = "/usr/lib/libSystem.dylib";
//
//    void *handle = dlopen(dylib_path, RTLD_GLOBAL | RTLD_NOW);
//
//    if (handle == NULL) {
//        LOGE("%s\n", dlerror());
//    } else {
//        printf_func_pointer printf_func = static_cast<printf_func_pointer>(dlsym(handle,                 "printf"));
//        if (printf_func) {
//            int num = 100;
//            printf_func("Hello exchen.net %d\n", num);
//            printf_func("printf function address 0x%lx\n", printf_func);
//        }
//
//
//    }
//
//
//}


void main_dlfcn() {
//    dynamic_call_function();
}


int main() {
    main_dlfcn();












//    pthread_t threads[10];
//    for(int i = 0;i < 10; i++)
//    {
//        pthread_create(&threads[i], NULL, adder, NULL);
//    }
//
//    for(int i = 0; i < 10; i++)
//    {
//        pthread_join(threads[i], NULL);
//    }

//    LOGE("sum is %d\n",sum);





    //union Data a = {16};
//    union Data a = {.ch = 'j'};
//
//
//    int i;
//    //输入人员信息
//    LOGE("Input info: ");
//    for (i = 0; i < TOTAL; i++) {
//        strcpy(bodys[i].name, "hanxiao");
//        bodys[i].num = i;
//        bodys[i].sex = 'f';
//        if (i % 2 == 0) {
//            bodys[i].profession = 's';
//        } else
//            bodys[i].profession = 't';
//        if (bodys[i].profession == 's') { //如果是学生
//            bodys[i].sc.score = 89.5 + i;
//        } else { //如果是老师
//            strcpy(bodys[i].sc.course, "math");
//        }
//    }
//    //输出人员信息
//    LOGE("\nName\t\tNum\tSex\tProfession\tScore / Course\n");
//    for (i = 0; i < TOTAL; i++) {
//        if (bodys[i].profession == 's') { //如果是学生
//            LOGE("%s\t%d\t%c\t%c\t\t%f\n%d\n%d\n", bodys[i].name, bodys[i].num, bodys[i].sex,
//                 bodys[i].profession, bodys[i].sc.score, &(bodys[i].profession),
//                 &(bodys[i].sc.score));
//        } else { //如果是老师
//            LOGE("%s\t%d\t%c\t%c\t\t%s\n%d\n%d\n", bodys[i].name, bodys[i].num, bodys[i].sex,
//                 bodys[i].profession, bodys[i].sc.course, &(bodys[i].profession),
//                 &(bodys[i].sc.score));
//        }
//    }
//
//








//    union data a;
//    LOGE("%d,%d\n", sizeof(a), sizeof(union data));
//
//    a.n = 0x40;
//
//    LOGE("%x,%x,%hX\n", a.n, a.ch, a.m);
//    a.ch = '9';
//    LOGE("%x,%x,%hX\n", a.n, a.ch, a.m);
//
//    a.m = 0x2059;
//    LOGE("%x,%c,%hX\n", a.n, a.ch, a.m);
//    a.n = 0x3E25AD54;
//    LOGE("%x,%c,%hX\n", a.n, a.ch, a.m);


//    LOGE("%d/t", AveInt(2, 2, 3));
//    LOGE("%d/t", AveInt(4, 2, 6, 8));

//    Node *node = creatList();
//
//    traverseList(node);
//    Node *node1 = searchList(node, 1);
//    LOGE("%d\n", node1->next->data);
//    int len = lenList(node);
//    LOGE("%d\n", len);
//
//    sortList(node, 3);
//    traverseList(node);
//    destroyList(node);
    //deleteList(node1);
    //traverseList(node1);
    //traverseList(node1);
    return 0;
}

int AveInt(int v, ...) {
    int ReturnValue = 0;
    int i = v;
    va_list ap;
    va_start(ap, v);
    while (i > 0) {
        ReturnValue += va_arg(ap, int);
        i--;
    }
    va_end(ap);
    return ReturnValue /= v;
}


void function0(int a) { LOGE("You entered %d so function0 was called\n", a); }

void function1(int b) { LOGE("You entered %d so function1 was called\n", b); }

void function2(int c) { LOGE("You entered %d so function2 was called\n", c); }


extern "C" JNIEXPORT jstring JNICALL
Java_com_ywl5320_cc_1c_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    main();
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
