struct Member{
   char name[20];
   char tel[20];
   char address[50];
};

int addMember(struct Member *arr, int cnt);
void printAll(struct Member *arr, int cnt);
int search(struct Member *arr, int cnt);
void edit(struct Member *arr, int cnt);
int del(struct Member *arr, int cnt);
int init(struct Member *arr, int cnt);
void stop(struct Member *arr, int cnt);
