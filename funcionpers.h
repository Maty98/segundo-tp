#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct
{   char nombre[50];
    int edad;
    int estado;
    int dni;
}ePersonas;
int menu();
/** \brief Muestra el menu principal
 */
 void ordenarPersonas (ePersonas[],int);
/** \brief Ordena alfabeticamente
 * \param Ciclo array de personas
 * \param  El tamaño del array
 */
 void iniciarPersonas(ePersonas[],int);
/** \brief Inicia los array que fueron cargados con basura anteriormente
 * \param Ciclo array de personas
 * \param El tamaño del array
 */
 void mostrarPersona (ePersonas);
/** \brief Muestra una sola persona
 * \param Persona a mostrar
 */
 void mostrarPersonas(ePersonas[],int);
/** \brief Muestra varias personas
 * \param Ciclo array de personas
 * \param El tamaño del array
 */
 int EspacioLibre(ePersonas[],int);
/** \brief Encuentra el primer espacio libre (es decir, estado==0)
 * \param Ciclo array de personas
 * \param El tamaño del array
 * \return Primer espacio libre encontrado
 */
 int busquedaPorDni(ePersonas[],int,int);
/** \brief Busca una persona segun su numero de DNI
 * \param Ciclo array de personas
 * \param El tamaño del array
 * \param DNI
 * \return Encuentra o no el DNI
 */
 void altaPersonas(ePersonas[],int);
/** \brief da de alta una persona en el sistema
 * \param Ciclo array de personas
 * \param El tamaño del array
 */
 void borrarPersona(ePersonas[],int);
/** \brief Da de baja una persona en sistema con el DNI (estado=2)
 * \param Ciclo array de personas
 * \param El tamaño del array
 */
void grafico(ePersonas[],int);
/** \brief Representa a las personas en un grafico
 * \param Ciclo array de personas
 * \param El tamaño del array
 */
#endif

