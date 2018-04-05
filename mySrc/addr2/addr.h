struct Member{
   char name[20];
   char tel[20];
   char address[20];
   struct Member *next;
   struct Member *prev;  
};

void add();
struct Member* search(char *name);
void printA();
void printB();
//void addFree();

//void search();
//void edit();
//void del();
//void printall();

