
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

/** \brief  Inicializa el array de estructuras de forma que el campo isEmpty de cada posicion del array sea 1.
 *
 * \param listEmployee eEmployee* Array de estructuras a inicializar.
 * \param lenghtEmployee int Longitud del array de estructuras (cantidad de posiciones).
 * \return int Retorna un estado en caso de poder o no ejecutar la operacion.
 *
 */
int initEmployee(eEmployee* listEmployee, int lenghtEmployee);

/** \brief Agrega el nuevo empleado a la primera posicion disponible del array de estructuras.
 *
 * \param listEmployee[] eEmployee Array de estructuras a agregar nuevo empleado.
 * \param lenghtEmployee int Longitud del array de estructuras (cantidad de posiciones).
 * \param id int Numero ID disponible para asignar al nuevo empleado.
 * \param name[] char Nombre del nuevo empleado.
 * \param lastName[] char Apellido del nuevo empleado.
 * \param salary float Salario del nuevo empleado.
 * \param sector int Sector del nuevo empleado.
 * \return int Retorna un estado en caso de poder o no ejecutar la operacion.
 *
 */
int addEmployee(eEmployee listEmployee[], int lenghtEmployee, int id, char name[], char lastName[], float salary, int sector);

/** \brief Busca en el array de estructuras el empleado que coincida con el id pasado por parametro.
 *
 * \param listEmployee[] eEmployee Array de estructuras en el cual buscar el empleado.
 * \param lengthEmployee int Longitud del array de estructuras (cantidad de posiciones).
 * \param id int ID del empleado a buscar.
 * \return int Retorna el indice en el cual se encuentra el empledo buscado por ID o -1 en caso de no encontrarlo.
 *
 */
int findEmpoyeeById(eEmployee listEmployee[], int lengthEmployee, int id);

/** \brief Elimina el empleado con el id pasado por parametro.
 *
 * \param listEmployee[] eEmployee Array de estructuras del cual se eliminara el empleado.
 * \param lengthEmployee int Longitud del array de estructuras (cantidad de posiciones).
 * \param id int ID del empleado a eliminar.
 * \return int Retorna un estado en caso de poder o no ejecutar la operacion.
 *
 */
int removeEmployee(eEmployee listEmployee[], int lengthEmployee, int id);

/** \brief Ordena el array de estructuras de forma ascendente o descendente.
 *
 * \param listEmployee[] eEmployee Array de estructuras en el cual se ordenaran los empleados.
 * \param lengthEmployee int Longitud del array de estructuras (cantidad de posiciones).
 * \param order int Recibe 0 o 1 para ordenar de forma ascendente o descendente respectivamente.
 * \return int Retorna un estado en caso de poder o no ejecutar la operacion.
 *
 */
int sortEmployees(eEmployee listEmployee[], int lengthEmployee, int order);

/** \brief Imprime por pantalla todo el array de empleados pasado por parametro.
 *
 * \param listEmployee[] eEmployee Array de estructuras que se imprimira en pantalla.
 * \param lengthEmployee int Longitud del array de estructuras (cantidad de posiciones).
 * \return void No retorna nada.
 *
 */
void printEmployees(eEmployee listEmployee[], int lengthEmployee);

/** \brief Muestra un menu de opciones a elegir.
 *
 * \param void No recibe parametros.
 * \return int Opcion del menu elegida por el usuario.
 *
 */
int menu(void);

/** \brief Muestra un subMenu de opciones a elegir.
 *
 * \param void No recibe parametros.
 * \return int Opcion del subMenu elegida por el usuario.
 *
 */
int subMenu(void);

/** \brief Valida si el array de empleados pasado por parametro tiene algun empleado cargado o esta vacío.
 *
 * \param listEmployee[] eEmployee Array de estructuras a validar si esta o no inicializado.
 * \param lengthEmployee int Longitud del array de estructuras (cantidad de posiciones).
 * \return int Retorna un estado en caso de poder o no ejecutar la operacion.
 *
 */
int validateArrayInitiated(eEmployee listEmployee[], int lengthEmployee);

/** \brief Encuentra la primera posicion disponible del array pasado por parametro o informa si esta lleno.
 *
 * \param listEmployee[] eEmployee Array de estructuras en el cual se buscara una posicion libre.
 * \param lenghtEmployee int Longitud del array de estructuras (cantidad de posiciones).
 * \return int Retorna el indice de la primera posicion disponible encontrada.
 *
 */
int findFreePosition(eEmployee listEmployee[], int lenghtEmployee);

/** \brief Crea una estructura de empleado con los datos pasados por parametros.
 *
 * \param id int ID disponible para asignar al nuevo empleado.
 * \param name[] char Nombre del nuevo empleado.
 * \param lastName[] char Apellido del nuevo empleado.
 * \param salary float Salario del nuevo empleado.
 * \param sector int Sector del nuevo empleado.
 * \return eEmployee Retorna una estructura cargada con todos los valores pasados por parametro a la funcion.
 *
 */
eEmployee newEmployee(int id, char name[], char lastName[], float salary, int sector);

/** \brief Pide los datos para dar de alta un nuevo empleado y cargarlo al array de estructuras.
 *
 * \param listEmployee[] eEmployee Array de estructuras en el cual se cargaran los datos del nuevo empleado.
 * \param lengthEmployee int Longitud del array de estructuras (cantidad de posiciones).
 * \param lastId int ID disponible para asignar al nuevo empleado.
 * \return int Retorna un estado en caso de poder o no ejecutar la operacion.
 *
 */
int loadEmployee(eEmployee listEmployee[], int lengthEmployee, int lastId);

/** \brief Imprime por pantalla a un empleado pasado por parametro.
 *
 * \param employee eEmployee Empleado a imprimir por pantalla.
 * \return void No retorna nada.
 *
 */
void printEmployee(eEmployee employee);

/** \brief Modifica los valores deseados del empleado encontrado por ID.
 *
 * \param listEmployee[] eEmployee Array de estructuras del empleado a modificar.
 * \param lengthEmployee int Longitud del array de estructuras (cantidad de posiciones).
 * \return int Retorna un estado en caso de haber encontrado un empleado existente para modificar o no.
 *
 */
int modifyEmployee(eEmployee listEmployee[], int lengthEmployee);

/** \brief Muestra la suma total de salarios, el promedio de salarios y los empleados con salarios por encima del promedio.
 *
 * \param listEmployee eEmployee* Array de estructuras a analizar y mostrar sus informes.
 * \param lengthEmployee int Longitud del array de estructuras (cantidad de posiciones).
 * \return void No retorna nada.
 *
 */
void infoEmployees(eEmployee* listEmployee, int lengthEmployee);

