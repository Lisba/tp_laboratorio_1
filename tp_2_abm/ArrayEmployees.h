
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

int initEmployee(eEmployee* listEmployee, int lenghtEmployee);
int addEmployee(eEmployee listEmployee[], int lenghtEmployee, int id, char name[], char lastName[], float salary, int sector);
int findEmpoyeeById(eEmployee listEmployee[], int lengthEmployee, int id);
int removeEmployee(eEmployee listEmployee[], int lengthEmployee, int id);
int sortEmployees(eEmployee listEmployee[], int lengthEmployee, int order);
void printEmployees(eEmployee listEmployee[], int lengthEmployee);

char menu(void);
char subMenu(void);
int validateArrayInitiated(eEmployee listEmployee[], int lengthEmployee);
int findFreePosition(eEmployee listEmployee[], int lenghtEmployee);
eEmployee newEmployee(int id, char name[], char lastName[], float salary, int sector);
int loadEmployee(eEmployee listEmployee[], int lengthEmployee, int lastId);
void printEmployee(eEmployee employee);
void modifyEmployee(eEmployee listEmployee[], int lengthEmployee);
void infoEmployees(eEmployee* listEmployee, int lengthEmployee);

