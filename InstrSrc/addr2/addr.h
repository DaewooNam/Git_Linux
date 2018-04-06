struct Member{
   char name[20];
   char tel[20];
   char address[30];
   struct Member *next;
   struct Member *prev;
};
void add();
struct Member* search(char *name);
void printA();
//void printD();
//void addrFree();
