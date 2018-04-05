typedef struct Member
{
 char name[20];
 char tel[20];
 char address[20];
 struct node *next;

}node;


int addMember(struct Member *arr,int cnt);
int searchMember(struct Member *arr, int cnt);
void modifyMember(struct Member *arr, int cnt);
int delMember(struct Member *arr, int cnt);
void printMember(struct Member *arr, int cnt);
int init(struct Member *arr, int cnt);
void stop(struct Member *arr, int cnt);
