
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

char menu(void);
char subMenu(void);
int initEmployee(eEmployee listEmployee[], int lenghtEmployee);
int findFreePosition(eEmployee listEmployee[], int lenghtEmployee);
int addEmployee(eEmployee listEmployee[], int lenghtEmployee, int id, char name[], char lastName[], float salary, int sector);
eEmployee newEmployee(int id, char name[], char lastName[], float salary, int sector);
int findEmpoyeeById(eEmployee listEmployee[], int lengthEmployee, int id);
int removeEmployee(eEmployee listEmployee[], int lengthEmployee, int id);
int sortEmployee(eEmployee listEmployee[], int lengthEmployee, int order);
void printEmployees(eEmployee listEmployee[], int lengthEmployee);
void printEmployee(eEmployee employee);
int validateArrayInitiated(eEmployee listEmployee[], int lengthEmployee);


